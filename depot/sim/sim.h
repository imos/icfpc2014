#ifndef SIM_SIM_H_
#define SIM_SIM_H_
#include <memory>
#include <vector>
#include <string>
#include "sim.h"

// Game map data
typedef vector<string> Maze;

class Game;

// Includes utilities
class Movement {
 public:
  virtual ~Movement() {}
  void SetRC(int r, int c) {
    r_ = r;
    c_ = c;
  }
  pair<int, int> GetRC() const { return std::make_pair(r_, c_); }
  void SetDirection(int d) { d_ = d; }
  int GetDirection() const { return d_; }
  void Initialize(int r, int c, int d) {
    initial_r = r;
    initial_c = c;
    initial_d = d;
    ResetPositionAndDirection();
  }
  void ResetPositionAndDirection() {
    r_ = initial_r;
    c_ = initial_c;
    d_ = initial_d;
  }

 private:
  int r_;
  int c_;
  int d_;  // direction
  int initial_r;
  int initial_c;
  int initial_d;
};

// Lambda-Man interface
class LambdaMan : public Movement {
 public:
  virtual void Init() = 0;
  virtual int Step() = 0;

 private:
};

// Ghost CPU interface
class Ghost : public Movement {
 public:
  void SetGame(Game* game) { game_ = game; }
  virtual int Step() = 0;

 private:
  Game* game_;
};

// To create a ghost class above
class GhostFactory {
 public:
  virtual ~GhostFactory() {}
  virtual Ghost* Create();
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

  // APIs for Ghost

 private:
  char GetSymbol(const pair<int, int>& rc) {
    return maze_[rc.first][rc.second];
  }
  void Eat(const pair<int, int>& rc) { maze_[rc.first][rc.second] = ' '; }

  vector<GhostFactory*> ghost_factories_;
  vector<std::unique_ptr<Ghost>> ghosts_;
  LambdaMan* lman_;
  // The current state of the world
  // NOTE: Only pills and power pills will be cosumed to be empty.
  //       Fruit and Lambda-Man symbols indicate their locations but not their
  // states.
  Maze maze_;
  vector<pair<int, int>> fruit_locations_;
  int total_pills_;
  int life_;
  int score_;
  int tick_;
};

#endif  // SIM_SIM_H_
