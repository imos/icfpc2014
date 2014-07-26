#ifndef SIM_SIM_H_
#define SIM_SIM_H_

#include <memory>
#include <string>
#include <vector>

#include "util/coordinate.h"

// Game map data
typedef vector<string> Maze;

class Game;

// Includes utilities
class Movement {
 public:
  virtual ~Movement() {}
  // Accessors
  Coordinate GetRC() const { return Coordinate(r_, c_); }
  Coordinate GetInitialRC() const { return Coordinate(initial_r_, initial_c_); }
  int GetDirection() const { return d_; }

  // Following are for internal use
  void SetRC(int r, int c) {
    r_ = r;
    c_ = c;
  }
  void SetDirection(int d) { d_ = d; }
  void Initialize(int r, int c, int d) {
    initial_r_ = r;
    initial_c_ = c;
    initial_d_ = d;
    ResetPositionAndDirection();
  }
  void ResetPositionAndDirection() {
    r_ = initial_r_;
    c_ = initial_c_;
    d_ = initial_d_;
  }
  bool CanMove(const Game& game, int d) const;
  bool Move();

 private:
  int r_;
  int c_;
  int d_;  // direction
  int initial_r_;
  int initial_c_;
  int initial_d_;
};

// Lambda-Man interface
class LambdaMan : public Movement {
 public:
  virtual void Init() = 0;
  virtual int Step() = 0;

 private:
};

// Ghost CPU interface
class GhostInterface : public Movement {
 public:
  GhostInterface() : game_(nullptr) {}

  void Init(Game* game, int ghost_index, int ghost_vitality) {
    game_ = game;
    ghost_index_ = ghost_index;
    ghost_vitality_ = ghost_vitality;
  }
  virtual int Step() = 0;

  int GetGhostIndex() { return ghost_index_; }
  int GetGhostVitality() { return ghost_vitality_; }

 protected:
  Game* game_;
  int ghost_index_;
  int ghost_vitality_;
};

// To create a ghost class above
class GhostFactory {
 public:
  virtual ~GhostFactory() {}
  virtual std::unique_ptr<GhostInterface> Create() = 0;
};

// Game Mechanics
class Game {
 public:
  // Configurations
  void AddGhostFactory(GhostFactory* ghost_factory) {
    ghost_factories_.push_back(ghost_factory);
  }
  void SetLambdaMan(LambdaMan* lman) { lman_ = lman; }
  void ParseMaze(std::istream& is);
  // Returns the final score
  int Start();
  
  char GetSymbol(const Coordinate& rc) const {
    return maze_[rc.first][rc.second];
  }
  char GetSymbolSafe(const Coordinate& rc, char out_of_area) const {
    if (rc.first < 0 || maze_.size() <= rc.first || rc.second < 0 ||
        maze_[rc.first].size() <= rc.second) {
      return out_of_area;
    }
    return GetSymbol(rc);
  }

  //////////////////////////////////////////////////////////////////////////////
  // APIs for Ghost
  //////////////////////////////////////////////////////////////////////////////
  Coordinate GetFirstLambdaManRC() {
    if (lman_ == nullptr) {
      return CoordinateUtil::Null();
    }
    return lman_->GetRC();
  }

  Coordinate GetSecondLambdaManRC() {
    // TODO(imos): Implement second lambda-man.
    return CoordinateUtil::Null();
  }

  Coordinate GetGhostInitialRC(int ghost_index) {
    if (ghost_index < 0 || ghosts_.size() <= ghost_index) {
      return CoordinateUtil::Null();
    }
    return ghosts_[ghost_index]->GetInitialRC();
  }

  Coordinate GetGhostRC(int ghost_index) {
    if (ghost_index < 0 || ghosts_.size() <= ghost_index) {
      return CoordinateUtil::Null();
    }
    return ghosts_[ghost_index]->GetRC();
  }

  int GetGhostVitality(int ghost_index) {
    if (ghost_index < 0 || ghosts_.size() <= ghost_index) {
      return -1;
    }
    return ghosts_[ghost_index]->GetGhostVitality();
  }

  int GetGhostDirection(int ghost_index) {
    if (ghost_index < 0 || ghosts_.size() <= ghost_index) {
      return -1;
    }
    return ghosts_[ghost_index]->GetDirection();
  }

 private:
  void Eat(const Coordinate& rc) { maze_[rc.first][rc.second] = ' '; }

  vector<GhostFactory*> ghost_factories_;
  vector<std::unique_ptr<GhostInterface>> ghosts_;
  LambdaMan* lman_;
  // The current state of the world
  // NOTE: Only pills and power pills will be cosumed to be empty.
  //       Fruit and Lambda-Man symbols indicate their locations but not their
  // states.
  Maze maze_;
  vector<Coordinate> fruit_locations_;
  int total_pills_;
  int life_;
  int score_;
  int tick_;
};

#endif  // SIM_SIM_H_
