#ifndef GHOST_AI_SAKICHOKUDAI_H_
#define GHOST_AI_SAKICHOKUDAI_H_

#include "ghost/ghost.h"

#include <glog/logging.h>

namespace ghost {

class sakichokudaiGhost : public Ghost {
  void Run() override {
    ResetTick();
pc000: if (Tick()) return;
    register_pc_ = 0;
    VLOG(3) << "[0] INT 1";
    INT1();
pc001: if (Tick()) return;
    register_pc_ = 1;
    VLOG(3) << "[1] MOV e,a";
    MOV(register_e_, register_a_);
pc002: if (Tick()) return;
    register_pc_ = 2;
    VLOG(3) << "[2] MOV f,b";
    MOV(register_f_, register_b_);
pc003: if (Tick()) return;
    register_pc_ = 3;
    VLOG(3) << "[3] mov g,[8]";
    MOV(register_g_, Memory(8));
pc004: if (Tick()) return;
    register_pc_ = 4;
    VLOG(3) << "[4] mov h,[9]";
    MOV(register_h_, Memory(9));
pc005: if (Tick()) return;
    register_pc_ = 5;
    VLOG(3) << "[5] mov [8],e";
    MOV(Memory(8), register_e_);
pc006: if (Tick()) return;
    register_pc_ = 6;
    VLOG(3) << "[6] mov [9],f";
    MOV(Memory(9), register_f_);
pc007: if (Tick()) return;
    register_pc_ = 7;
    VLOG(3) << "[7] add e,e";
    ADD(register_e_, register_e_);
pc008: if (Tick()) return;
    register_pc_ = 8;
    VLOG(3) << "[8] add e,e";
    ADD(register_e_, register_e_);
pc009: if (Tick()) return;
    register_pc_ = 9;
    VLOG(3) << "[9] sub e,g";
    SUB(register_e_, register_g_);
pc010: if (Tick()) return;
    register_pc_ = 10;
    VLOG(3) << "[10] sub e,g";
    SUB(register_e_, register_g_);
pc011: if (Tick()) return;
    register_pc_ = 11;
    VLOG(3) << "[11] sub e,g";
    SUB(register_e_, register_g_);
pc012: if (Tick()) return;
    register_pc_ = 12;
    VLOG(3) << "[12] add f,f";
    ADD(register_f_, register_f_);
pc013: if (Tick()) return;
    register_pc_ = 13;
    VLOG(3) << "[13] add f,f";
    ADD(register_f_, register_f_);
pc014: if (Tick()) return;
    register_pc_ = 14;
    VLOG(3) << "[14] sub f,h";
    SUB(register_f_, register_h_);
pc015: if (Tick()) return;
    register_pc_ = 15;
    VLOG(3) << "[15] sub f,h";
    SUB(register_f_, register_h_);
pc016: if (Tick()) return;
    register_pc_ = 16;
    VLOG(3) << "[16] sub f,h";
    SUB(register_f_, register_h_);
pc017: if (Tick()) return;
    register_pc_ = 17;
    VLOG(3) << "[17] INT 3";
    INT3();
pc018: if (Tick()) return;
    register_pc_ = 18;
    VLOG(3) << "[18] MOV [0],a";
    MOV(Memory(0), register_a_);
pc019: if (Tick()) return;
    register_pc_ = 19;
    VLOG(3) << "[19] INT 5";
    INT5();
pc020: if (Tick()) return;
    register_pc_ = 20;
    VLOG(3) << "[20] MOV g,a";
    MOV(register_g_, register_a_);
pc021: if (Tick()) return;
    register_pc_ = 21;
    VLOG(3) << "[21] MOV h,b";
    MOV(register_h_, register_b_);
pc022: if (Tick()) return;
    register_pc_ = 22;
    VLOG(3) << "[22] INT 3";
    INT3();
pc023: if (Tick()) return;
    register_pc_ = 23;
    VLOG(3) << "[23] INT 6";
    INT6();
pc024: if (Tick()) return;
    register_pc_ = 24;
    VLOG(3) << "[24] MOV [3],b";
    MOV(Memory(3), register_b_);
pc025: if (Tick()) return;
    register_pc_ = 25;
    VLOG(3) << "[25] ADD [3],2";
    ADD(Memory(3), 2);
pc026: if (Tick()) return;
    register_pc_ = 26;
    VLOG(3) << "[26] JLT init3,[3],4";
    if (JLT(Memory(3), 4)) goto pc028;
pc027: if (Tick()) return;
    register_pc_ = 27;
    VLOG(3) << "[27] SUB [3],4";
    SUB(Memory(3), 4);
    // Label: init3
pc028: if (Tick()) return;
    register_pc_ = 28;
    VLOG(3) << "[28] MOV [1],[3]";
    MOV(Memory(1), Memory(3));
pc029: if (Tick()) return;
    register_pc_ = 29;
    VLOG(3) << "[29] MOV c,0";
    MOV(register_c_, 0);
pc030: if (Tick()) return;
    register_pc_ = 30;
    VLOG(3) << "[30] MOV d,10";
    MOV(register_d_, 10);
pc031: if (Tick()) return;
    register_pc_ = 31;
    VLOG(3) << "[31] MOV a,g";
    MOV(register_a_, register_g_);
pc032: if (Tick()) return;
    register_pc_ = 32;
    VLOG(3) << "[32] MOV b,h";
    MOV(register_b_, register_h_);
pc033: if (Tick()) return;
    register_pc_ = 33;
    VLOG(3) << "[33] SUB b,1";
    SUB(register_b_, 1);
pc034: if (Tick()) return;
    register_pc_ = 34;
    VLOG(3) << "[34] INT 7";
    INT7();
pc035: if (Tick()) return;
    register_pc_ = 35;
    VLOG(3) << "[35] JEQ uplast,a,0";
    if (JEQ(register_a_, 0)) goto pc047;
pc036: if (Tick()) return;
    register_pc_ = 36;
    VLOG(3) << "[36] JEQ uplast,[3],0";
    if (JEQ(Memory(3), 0)) goto pc047;
pc037: if (Tick()) return;
    register_pc_ = 37;
    VLOG(3) << "[37] JGT up1,f,h";
    if (JGT(register_f_, register_h_)) goto pc039;
pc038: if (Tick()) return;
    register_pc_ = 38;
    VLOG(3) << "[38] ADD d,22";
    ADD(register_d_, 22);
    // Label: up1
pc039: if (Tick()) return;
    register_pc_ = 39;
    VLOG(3) << "[39] MOV a,[3]";
    MOV(register_a_, Memory(3));
pc040: if (Tick()) return;
    register_pc_ = 40;
    VLOG(3) << "[40] ADD a,0";
    ADD(register_a_, 0);
pc041: if (Tick()) return;
    register_pc_ = 41;
    VLOG(3) << "[41] AND a,1";
    AND(register_a_, 1);
pc042: if (Tick()) return;
    register_pc_ = 42;
    VLOG(3) << "[42] JEQ up2,a,0";
    if (JEQ(register_a_, 0)) goto pc044;
pc043: if (Tick()) return;
    register_pc_ = 43;
    VLOG(3) << "[43] ADD d,1";
    ADD(register_d_, 1);
    // Label: up2
pc044: if (Tick()) return;
    register_pc_ = 44;
    VLOG(3) << "[44] JLT uplast,d,c";
    if (JLT(register_d_, register_c_)) goto pc047;
pc045: if (Tick()) return;
    register_pc_ = 45;
    VLOG(3) << "[45] MOV [1],0";
    MOV(Memory(1), 0);
pc046: if (Tick()) return;
    register_pc_ = 46;
    VLOG(3) << "[46] MOV c,d";
    MOV(register_c_, register_d_);
    // Label: uplast
pc047: if (Tick()) return;
    register_pc_ = 47;
    VLOG(3) << "[47] MOV d,10";
    MOV(register_d_, 10);
pc048: if (Tick()) return;
    register_pc_ = 48;
    VLOG(3) << "[48] MOV a,g";
    MOV(register_a_, register_g_);
pc049: if (Tick()) return;
    register_pc_ = 49;
    VLOG(3) << "[49] MOV b,h";
    MOV(register_b_, register_h_);
pc050: if (Tick()) return;
    register_pc_ = 50;
    VLOG(3) << "[50] ADD b,1";
    ADD(register_b_, 1);
pc051: if (Tick()) return;
    register_pc_ = 51;
    VLOG(3) << "[51] INT 7";
    INT7();
pc052: if (Tick()) return;
    register_pc_ = 52;
    VLOG(3) << "[52] JEQ downlast,a,0";
    if (JEQ(register_a_, 0)) goto pc064;
pc053: if (Tick()) return;
    register_pc_ = 53;
    VLOG(3) << "[53] JEQ downlast,[3],2";
    if (JEQ(Memory(3), 2)) goto pc064;
pc054: if (Tick()) return;
    register_pc_ = 54;
    VLOG(3) << "[54] JLT down1,f,h";
    if (JLT(register_f_, register_h_)) goto pc056;
pc055: if (Tick()) return;
    register_pc_ = 55;
    VLOG(3) << "[55] ADD d,22";
    ADD(register_d_, 22);
    // Label: down1
pc056: if (Tick()) return;
    register_pc_ = 56;
    VLOG(3) << "[56] MOV a,[3]";
    MOV(register_a_, Memory(3));
pc057: if (Tick()) return;
    register_pc_ = 57;
    VLOG(3) << "[57] ADD a,2";
    ADD(register_a_, 2);
pc058: if (Tick()) return;
    register_pc_ = 58;
    VLOG(3) << "[58] AND a,1";
    AND(register_a_, 1);
pc059: if (Tick()) return;
    register_pc_ = 59;
    VLOG(3) << "[59] JEQ down2,a,0";
    if (JEQ(register_a_, 0)) goto pc061;
pc060: if (Tick()) return;
    register_pc_ = 60;
    VLOG(3) << "[60] ADD d,1";
    ADD(register_d_, 1);
    // Label: down2
pc061: if (Tick()) return;
    register_pc_ = 61;
    VLOG(3) << "[61] JLT downlast,d,c";
    if (JLT(register_d_, register_c_)) goto pc064;
pc062: if (Tick()) return;
    register_pc_ = 62;
    VLOG(3) << "[62] MOV [1],2";
    MOV(Memory(1), 2);
pc063: if (Tick()) return;
    register_pc_ = 63;
    VLOG(3) << "[63] MOV c,d";
    MOV(register_c_, register_d_);
    // Label: downlast
pc064: if (Tick()) return;
    register_pc_ = 64;
    VLOG(3) << "[64] MOV d,10";
    MOV(register_d_, 10);
pc065: if (Tick()) return;
    register_pc_ = 65;
    VLOG(3) << "[65] MOV a,g";
    MOV(register_a_, register_g_);
pc066: if (Tick()) return;
    register_pc_ = 66;
    VLOG(3) << "[66] MOV b,h";
    MOV(register_b_, register_h_);
pc067: if (Tick()) return;
    register_pc_ = 67;
    VLOG(3) << "[67] ADD a,1";
    ADD(register_a_, 1);
pc068: if (Tick()) return;
    register_pc_ = 68;
    VLOG(3) << "[68] INT 7";
    INT7();
pc069: if (Tick()) return;
    register_pc_ = 69;
    VLOG(3) << "[69] JEQ rightlast,a,0";
    if (JEQ(register_a_, 0)) goto pc081;
pc070: if (Tick()) return;
    register_pc_ = 70;
    VLOG(3) << "[70] JEQ rightlast,[3],1";
    if (JEQ(Memory(3), 1)) goto pc081;
pc071: if (Tick()) return;
    register_pc_ = 71;
    VLOG(3) << "[71] JLT right1,e,g";
    if (JLT(register_e_, register_g_)) goto pc073;
pc072: if (Tick()) return;
    register_pc_ = 72;
    VLOG(3) << "[72] ADD d,22";
    ADD(register_d_, 22);
    // Label: right1
pc073: if (Tick()) return;
    register_pc_ = 73;
    VLOG(3) << "[73] MOV a,[3]";
    MOV(register_a_, Memory(3));
pc074: if (Tick()) return;
    register_pc_ = 74;
    VLOG(3) << "[74] ADD a,1";
    ADD(register_a_, 1);
pc075: if (Tick()) return;
    register_pc_ = 75;
    VLOG(3) << "[75] AND a,1";
    AND(register_a_, 1);
pc076: if (Tick()) return;
    register_pc_ = 76;
    VLOG(3) << "[76] JEQ right2,a,0";
    if (JEQ(register_a_, 0)) goto pc078;
pc077: if (Tick()) return;
    register_pc_ = 77;
    VLOG(3) << "[77] ADD d,1";
    ADD(register_d_, 1);
    // Label: right2
pc078: if (Tick()) return;
    register_pc_ = 78;
    VLOG(3) << "[78] JLT rightlast,d,c";
    if (JLT(register_d_, register_c_)) goto pc081;
pc079: if (Tick()) return;
    register_pc_ = 79;
    VLOG(3) << "[79] MOV [1],1";
    MOV(Memory(1), 1);
pc080: if (Tick()) return;
    register_pc_ = 80;
    VLOG(3) << "[80] MOV c,d";
    MOV(register_c_, register_d_);
    // Label: rightlast
pc081: if (Tick()) return;
    register_pc_ = 81;
    VLOG(3) << "[81] MOV d,10";
    MOV(register_d_, 10);
pc082: if (Tick()) return;
    register_pc_ = 82;
    VLOG(3) << "[82] MOV a,g";
    MOV(register_a_, register_g_);
pc083: if (Tick()) return;
    register_pc_ = 83;
    VLOG(3) << "[83] MOV b,h";
    MOV(register_b_, register_h_);
pc084: if (Tick()) return;
    register_pc_ = 84;
    VLOG(3) << "[84] SUB a,1";
    SUB(register_a_, 1);
pc085: if (Tick()) return;
    register_pc_ = 85;
    VLOG(3) << "[85] INT 7";
    INT7();
pc086: if (Tick()) return;
    register_pc_ = 86;
    VLOG(3) << "[86] JEQ leftlast,a,0";
    if (JEQ(register_a_, 0)) goto pc098;
pc087: if (Tick()) return;
    register_pc_ = 87;
    VLOG(3) << "[87] JEQ leftlast,[3],3";
    if (JEQ(Memory(3), 3)) goto pc098;
pc088: if (Tick()) return;
    register_pc_ = 88;
    VLOG(3) << "[88] JGT left1,e,g";
    if (JGT(register_e_, register_g_)) goto pc090;
pc089: if (Tick()) return;
    register_pc_ = 89;
    VLOG(3) << "[89] ADD d,22";
    ADD(register_d_, 22);
    // Label: left1
pc090: if (Tick()) return;
    register_pc_ = 90;
    VLOG(3) << "[90] MOV a,[3]";
    MOV(register_a_, Memory(3));
pc091: if (Tick()) return;
    register_pc_ = 91;
    VLOG(3) << "[91] ADD a,3";
    ADD(register_a_, 3);
pc092: if (Tick()) return;
    register_pc_ = 92;
    VLOG(3) << "[92] AND a,1";
    AND(register_a_, 1);
pc093: if (Tick()) return;
    register_pc_ = 93;
    VLOG(3) << "[93] JEQ left2,a,0";
    if (JEQ(register_a_, 0)) goto pc095;
pc094: if (Tick()) return;
    register_pc_ = 94;
    VLOG(3) << "[94] ADD d,1";
    ADD(register_d_, 1);
    // Label: left2
pc095: if (Tick()) return;
    register_pc_ = 95;
    VLOG(3) << "[95] JLT leftlast,d,c";
    if (JLT(register_d_, register_c_)) goto pc098;
pc096: if (Tick()) return;
    register_pc_ = 96;
    VLOG(3) << "[96] MOV [1],3";
    MOV(Memory(1), 3);
pc097: if (Tick()) return;
    register_pc_ = 97;
    VLOG(3) << "[97] MOV c,d";
    MOV(register_c_, register_d_);
    // Label: leftlast
pc098: if (Tick()) return;
    register_pc_ = 98;
    VLOG(3) << "[98] MOV a,[1]";
    MOV(register_a_, Memory(1));
pc099: if (Tick()) return;
    register_pc_ = 99;
    VLOG(3) << "[99] INT 0";
    INT0();
pc100: if (Tick()) return;
    register_pc_ = 100;
    VLOG(3) << "[100] MOV d,[1]";
    MOV(register_d_, Memory(1));
pc101: if (Tick()) return;
    register_pc_ = 101;
    VLOG(3) << "[101] HLT";
    HLT();
  }
};

class sakichokudaiGhostFactory : public ::GhostFactory {
 public:
  virtual ~sakichokudaiGhostFactory() {}

  std::unique_ptr<::GhostInterface> Create() {
    return std::unique_ptr<::GhostInterface>(new sakichokudaiGhost());
  }
};

}  // namespace ghost

#endif  // GHOST_AI_SAKICHOKUDAI_H_
