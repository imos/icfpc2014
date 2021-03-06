#ifndef GHOST_AI_FICKLE_H_
#define GHOST_AI_FICKLE_H_

#include "ghost/ghost.h"

#include <glog/logging.h>

namespace ghost {

class fickleGhost : public Ghost {
  void Run() override {
    ResetTick();
pc000: if (Tick()) return;
    register_pc_ = 0;
    VLOG(3) << "[0] MOV a,255";
    MOV(register_a_, 255);
pc001: if (Tick()) return;
    register_pc_ = 1;
    VLOG(3) << "[1] MOV b,0";
    MOV(register_b_, 0);
pc002: if (Tick()) return;
    register_pc_ = 2;
    VLOG(3) << "[2] MOV c,255";
    MOV(register_c_, 255);
pc003: if (Tick()) return;
    register_pc_ = 3;
    VLOG(3) << "[3] INC c";
    INC(register_c_);
pc004: if (Tick()) return;
    register_pc_ = 4;
    VLOG(3) << "[4] JGT 7,[c],a";
    if (JGT(Memory(register_c_), register_a_)) goto pc007;
pc005: if (Tick()) return;
    register_pc_ = 5;
    VLOG(3) << "[5] MOV a,[c]";
    MOV(register_a_, Memory(register_c_));
pc006: if (Tick()) return;
    register_pc_ = 6;
    VLOG(3) << "[6] MOV b,c";
    MOV(register_b_, register_c_);
pc007: if (Tick()) return;
    register_pc_ = 7;
    VLOG(3) << "[7] JLT 3,c,3";
    if (JLT(register_c_, 3)) goto pc003;
pc008: if (Tick()) return;
    register_pc_ = 8;
    VLOG(3) << "[8] MOV a,b";
    MOV(register_a_, register_b_);
pc009: if (Tick()) return;
    register_pc_ = 9;
    VLOG(3) << "[9] INT 0";
    INT0();
pc010: if (Tick()) return;
    register_pc_ = 10;
    VLOG(3) << "[10] INT 3";
    INT3();
pc011: if (Tick()) return;
    register_pc_ = 11;
    VLOG(3) << "[11] INT 6";
    INT6();
pc012: if (Tick()) return;
    register_pc_ = 12;
    VLOG(3) << "[12] INC [b]";
    INC(Memory(register_b_));
pc013: if (Tick()) return;
    register_pc_ = 13;
    VLOG(3) << "[13] HLT";
    HLT();
  }
};

class fickleGhostFactory : public ::GhostFactory {
 public:
  virtual ~fickleGhostFactory() {}

  std::unique_ptr<::GhostInterface> Create() {
    return std::unique_ptr<::GhostInterface>(new fickleGhost());
  }
};

}  // namespace ghost

#endif  // GHOST_AI_FICKLE_H_
