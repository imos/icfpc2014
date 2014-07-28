#ifndef GHOST_AI_IWI6_H_
#define GHOST_AI_IWI6_H_

#include "ghost/ghost.h"

#include <glog/logging.h>

namespace ghost {

class iwi6Ghost : public Ghost {
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
    VLOG(3) << "[3] INT 3";
    INT3();
pc004: if (Tick()) return;
    register_pc_ = 4;
    VLOG(3) << "[4] MOV [0],a";
    MOV(Memory(0), register_a_);
pc005: if (Tick()) return;
    register_pc_ = 5;
    VLOG(3) << "[5] INT 5";
    INT5();
pc006: if (Tick()) return;
    register_pc_ = 6;
    VLOG(3) << "[6] MOV g,a";
    MOV(register_g_, register_a_);
pc007: if (Tick()) return;
    register_pc_ = 7;
    VLOG(3) << "[7] MOV h,b";
    MOV(register_h_, register_b_);
pc008: if (Tick()) return;
    register_pc_ = 8;
    VLOG(3) << "[8] INT 3";
    INT3();
pc009: if (Tick()) return;
    register_pc_ = 9;
    VLOG(3) << "[9] INT 6";
    INT6();
pc010: if (Tick()) return;
    register_pc_ = 10;
    VLOG(3) << "[10] MOV [3],b";
    MOV(Memory(3), register_b_);
pc011: if (Tick()) return;
    register_pc_ = 11;
    VLOG(3) << "[11] ADD [3],2";
    ADD(Memory(3), 2);
pc012: if (Tick()) return;
    register_pc_ = 12;
    VLOG(3) << "[12] JLT 14,[3],4";
    if (JLT(Memory(3), 4)) goto pc014;
pc013: if (Tick()) return;
    register_pc_ = 13;
    VLOG(3) << "[13] SUB [3],4";
    SUB(Memory(3), 4);
pc014: if (Tick()) return;
    register_pc_ = 14;
    VLOG(3) << "[14] MOV [1],[3]";
    MOV(Memory(1), Memory(3));
pc015: if (Tick()) return;
    register_pc_ = 15;
    VLOG(3) << "[15] MOV [4],0";
    MOV(Memory(4), 0);
pc016: if (Tick()) return;
    register_pc_ = 16;
    VLOG(3) << "[16] MOV [5],0";
    MOV(Memory(5), 0);
pc017: if (Tick()) return;
    register_pc_ = 17;
    VLOG(3) << "[17] MOV [6],e";
    MOV(Memory(6), register_e_);
pc018: if (Tick()) return;
    register_pc_ = 18;
    VLOG(3) << "[18] SUB [6],g";
    SUB(Memory(6), register_g_);
pc019: if (Tick()) return;
    register_pc_ = 19;
    VLOG(3) << "[19] JGT 22,e,g";
    if (JGT(register_e_, register_g_)) goto pc022;
pc020: if (Tick()) return;
    register_pc_ = 20;
    VLOG(3) << "[20] MOV [6],g";
    MOV(Memory(6), register_g_);
pc021: if (Tick()) return;
    register_pc_ = 21;
    VLOG(3) << "[21] SUB [6],e";
    SUB(Memory(6), register_e_);
pc022: if (Tick()) return;
    register_pc_ = 22;
    VLOG(3) << "[22] MOV [100],f";
    MOV(Memory(100), register_f_);
pc023: if (Tick()) return;
    register_pc_ = 23;
    VLOG(3) << "[23] SUB [100],h";
    SUB(Memory(100), register_h_);
pc024: if (Tick()) return;
    register_pc_ = 24;
    VLOG(3) << "[24] JGT 27,f,h";
    if (JGT(register_f_, register_h_)) goto pc027;
pc025: if (Tick()) return;
    register_pc_ = 25;
    VLOG(3) << "[25] MOV [100],h";
    MOV(Memory(100), register_h_);
pc026: if (Tick()) return;
    register_pc_ = 26;
    VLOG(3) << "[26] SUB [100],f";
    SUB(Memory(100), register_f_);
pc027: if (Tick()) return;
    register_pc_ = 27;
    VLOG(3) << "[27] ADD [6],[100]";
    ADD(Memory(6), Memory(100));
pc028: if (Tick()) return;
    register_pc_ = 28;
    VLOG(3) << "[28] MOV d,100";
    MOV(register_d_, 100);
pc029: if (Tick()) return;
    register_pc_ = 29;
    VLOG(3) << "[29] MOV a,g";
    MOV(register_a_, register_g_);
pc030: if (Tick()) return;
    register_pc_ = 30;
    VLOG(3) << "[30] MOV b,h";
    MOV(register_b_, register_h_);
pc031: if (Tick()) return;
    register_pc_ = 31;
    VLOG(3) << "[31] SUB b,1";
    SUB(register_b_, 1);
pc032: if (Tick()) return;
    register_pc_ = 32;
    VLOG(3) << "[32] INT 7";
    INT7();
pc033: if (Tick()) return;
    register_pc_ = 33;
    VLOG(3) << "[33] JEQ 54,a,0";
    if (JEQ(register_a_, 0)) goto pc054;
pc034: if (Tick()) return;
    register_pc_ = 34;
    VLOG(3) << "[34] JEQ 54,[3],0";
    if (JEQ(Memory(3), 0)) goto pc054;
pc035: if (Tick()) return;
    register_pc_ = 35;
    VLOG(3) << "[35] INT 3";
    INT3();
pc036: if (Tick()) return;
    register_pc_ = 36;
    VLOG(3) << "[36] MOV [100],a";
    MOV(Memory(100), register_a_);
pc037: if (Tick()) return;
    register_pc_ = 37;
    VLOG(3) << "[37] XOR [100],0";
    XOR(Memory(100), 0);
pc038: if (Tick()) return;
    register_pc_ = 38;
    VLOG(3) << "[38] AND [100],3";
    AND(Memory(100), 3);
pc039: if (Tick()) return;
    register_pc_ = 39;
    VLOG(3) << "[39] JGT 48,f,h";
    if (JGT(register_f_, register_h_)) goto pc048;
pc040: if (Tick()) return;
    register_pc_ = 40;
    VLOG(3) << "[40] JGT 45,[6],10";
    if (JGT(Memory(6), 10)) goto pc045;
pc041: if (Tick()) return;
    register_pc_ = 41;
    VLOG(3) << "[41] SUB d,20";
    SUB(register_d_, 20);
pc042: if (Tick()) return;
    register_pc_ = 42;
    VLOG(3) << "[42] INT 3";
    INT3();
pc043: if (Tick()) return;
    register_pc_ = 43;
    VLOG(3) << "[43] INT 6";
    INT6();
pc044: if (Tick()) return;
    register_pc_ = 44;
    VLOG(3) << "[44] JEQ 48,a,1";
    if (JEQ(register_a_, 1)) goto pc048;
pc045: if (Tick()) return;
    register_pc_ = 45;
    VLOG(3) << "[45] ADD d,40";
    ADD(register_d_, 40);
pc046: if (Tick()) return;
    register_pc_ = 46;
    VLOG(3) << "[46] ADD [100],h";
    ADD(Memory(100), register_h_);
pc047: if (Tick()) return;
    register_pc_ = 47;
    VLOG(3) << "[47] SUB [100],f";
    SUB(Memory(100), register_f_);
pc048: if (Tick()) return;
    register_pc_ = 48;
    VLOG(3) << "[48] JLT 54,d,[4]";
    if (JLT(register_d_, Memory(4))) goto pc054;
pc049: if (Tick()) return;
    register_pc_ = 49;
    VLOG(3) << "[49] JGT 51,d,[4]";
    if (JGT(register_d_, Memory(4))) goto pc051;
pc050: if (Tick()) return;
    register_pc_ = 50;
    VLOG(3) << "[50] JLT 54,[100],[5]";
    if (JLT(Memory(100), Memory(5))) goto pc054;
pc051: if (Tick()) return;
    register_pc_ = 51;
    VLOG(3) << "[51] MOV [1],0";
    MOV(Memory(1), 0);
pc052: if (Tick()) return;
    register_pc_ = 52;
    VLOG(3) << "[52] MOV [4],d";
    MOV(Memory(4), register_d_);
pc053: if (Tick()) return;
    register_pc_ = 53;
    VLOG(3) << "[53] MOV [5],[100]";
    MOV(Memory(5), Memory(100));
pc054: if (Tick()) return;
    register_pc_ = 54;
    VLOG(3) << "[54] MOV d,100";
    MOV(register_d_, 100);
pc055: if (Tick()) return;
    register_pc_ = 55;
    VLOG(3) << "[55] MOV a,g";
    MOV(register_a_, register_g_);
pc056: if (Tick()) return;
    register_pc_ = 56;
    VLOG(3) << "[56] MOV b,h";
    MOV(register_b_, register_h_);
pc057: if (Tick()) return;
    register_pc_ = 57;
    VLOG(3) << "[57] ADD a,1";
    ADD(register_a_, 1);
pc058: if (Tick()) return;
    register_pc_ = 58;
    VLOG(3) << "[58] INT 7";
    INT7();
pc059: if (Tick()) return;
    register_pc_ = 59;
    VLOG(3) << "[59] JEQ 80,a,0";
    if (JEQ(register_a_, 0)) goto pc080;
pc060: if (Tick()) return;
    register_pc_ = 60;
    VLOG(3) << "[60] JEQ 80,[3],1";
    if (JEQ(Memory(3), 1)) goto pc080;
pc061: if (Tick()) return;
    register_pc_ = 61;
    VLOG(3) << "[61] INT 3";
    INT3();
pc062: if (Tick()) return;
    register_pc_ = 62;
    VLOG(3) << "[62] MOV [100],a";
    MOV(Memory(100), register_a_);
pc063: if (Tick()) return;
    register_pc_ = 63;
    VLOG(3) << "[63] XOR [100],1";
    XOR(Memory(100), 1);
pc064: if (Tick()) return;
    register_pc_ = 64;
    VLOG(3) << "[64] AND [100],3";
    AND(Memory(100), 3);
pc065: if (Tick()) return;
    register_pc_ = 65;
    VLOG(3) << "[65] JLT 74,e,g";
    if (JLT(register_e_, register_g_)) goto pc074;
pc066: if (Tick()) return;
    register_pc_ = 66;
    VLOG(3) << "[66] JGT 71,[6],10";
    if (JGT(Memory(6), 10)) goto pc071;
pc067: if (Tick()) return;
    register_pc_ = 67;
    VLOG(3) << "[67] SUB d,20";
    SUB(register_d_, 20);
pc068: if (Tick()) return;
    register_pc_ = 68;
    VLOG(3) << "[68] INT 3";
    INT3();
pc069: if (Tick()) return;
    register_pc_ = 69;
    VLOG(3) << "[69] INT 6";
    INT6();
pc070: if (Tick()) return;
    register_pc_ = 70;
    VLOG(3) << "[70] JEQ 74,a,1";
    if (JEQ(register_a_, 1)) goto pc074;
pc071: if (Tick()) return;
    register_pc_ = 71;
    VLOG(3) << "[71] ADD d,40";
    ADD(register_d_, 40);
pc072: if (Tick()) return;
    register_pc_ = 72;
    VLOG(3) << "[72] ADD [100],e";
    ADD(Memory(100), register_e_);
pc073: if (Tick()) return;
    register_pc_ = 73;
    VLOG(3) << "[73] SUB [100],g";
    SUB(Memory(100), register_g_);
pc074: if (Tick()) return;
    register_pc_ = 74;
    VLOG(3) << "[74] JLT 80,d,[4]";
    if (JLT(register_d_, Memory(4))) goto pc080;
pc075: if (Tick()) return;
    register_pc_ = 75;
    VLOG(3) << "[75] JGT 77,d,[4]";
    if (JGT(register_d_, Memory(4))) goto pc077;
pc076: if (Tick()) return;
    register_pc_ = 76;
    VLOG(3) << "[76] JLT 80,[100],[5]";
    if (JLT(Memory(100), Memory(5))) goto pc080;
pc077: if (Tick()) return;
    register_pc_ = 77;
    VLOG(3) << "[77] MOV [1],1";
    MOV(Memory(1), 1);
pc078: if (Tick()) return;
    register_pc_ = 78;
    VLOG(3) << "[78] MOV [4],d";
    MOV(Memory(4), register_d_);
pc079: if (Tick()) return;
    register_pc_ = 79;
    VLOG(3) << "[79] MOV [5],[100]";
    MOV(Memory(5), Memory(100));
pc080: if (Tick()) return;
    register_pc_ = 80;
    VLOG(3) << "[80] MOV d,100";
    MOV(register_d_, 100);
pc081: if (Tick()) return;
    register_pc_ = 81;
    VLOG(3) << "[81] MOV a,g";
    MOV(register_a_, register_g_);
pc082: if (Tick()) return;
    register_pc_ = 82;
    VLOG(3) << "[82] MOV b,h";
    MOV(register_b_, register_h_);
pc083: if (Tick()) return;
    register_pc_ = 83;
    VLOG(3) << "[83] ADD b,1";
    ADD(register_b_, 1);
pc084: if (Tick()) return;
    register_pc_ = 84;
    VLOG(3) << "[84] INT 7";
    INT7();
pc085: if (Tick()) return;
    register_pc_ = 85;
    VLOG(3) << "[85] JEQ 106,a,0";
    if (JEQ(register_a_, 0)) goto pc106;
pc086: if (Tick()) return;
    register_pc_ = 86;
    VLOG(3) << "[86] JEQ 106,[3],2";
    if (JEQ(Memory(3), 2)) goto pc106;
pc087: if (Tick()) return;
    register_pc_ = 87;
    VLOG(3) << "[87] INT 3";
    INT3();
pc088: if (Tick()) return;
    register_pc_ = 88;
    VLOG(3) << "[88] MOV [100],a";
    MOV(Memory(100), register_a_);
pc089: if (Tick()) return;
    register_pc_ = 89;
    VLOG(3) << "[89] XOR [100],2";
    XOR(Memory(100), 2);
pc090: if (Tick()) return;
    register_pc_ = 90;
    VLOG(3) << "[90] AND [100],3";
    AND(Memory(100), 3);
pc091: if (Tick()) return;
    register_pc_ = 91;
    VLOG(3) << "[91] JLT 100,f,h";
    if (JLT(register_f_, register_h_)) goto pc100;
pc092: if (Tick()) return;
    register_pc_ = 92;
    VLOG(3) << "[92] JGT 97,[6],10";
    if (JGT(Memory(6), 10)) goto pc097;
pc093: if (Tick()) return;
    register_pc_ = 93;
    VLOG(3) << "[93] SUB d,20";
    SUB(register_d_, 20);
pc094: if (Tick()) return;
    register_pc_ = 94;
    VLOG(3) << "[94] INT 3";
    INT3();
pc095: if (Tick()) return;
    register_pc_ = 95;
    VLOG(3) << "[95] INT 6";
    INT6();
pc096: if (Tick()) return;
    register_pc_ = 96;
    VLOG(3) << "[96] JEQ 100,a,1";
    if (JEQ(register_a_, 1)) goto pc100;
pc097: if (Tick()) return;
    register_pc_ = 97;
    VLOG(3) << "[97] ADD d,40";
    ADD(register_d_, 40);
pc098: if (Tick()) return;
    register_pc_ = 98;
    VLOG(3) << "[98] ADD [100],f";
    ADD(Memory(100), register_f_);
pc099: if (Tick()) return;
    register_pc_ = 99;
    VLOG(3) << "[99] SUB [100],h";
    SUB(Memory(100), register_h_);
pc100: if (Tick()) return;
    register_pc_ = 100;
    VLOG(3) << "[100] JLT 106,d,[4]";
    if (JLT(register_d_, Memory(4))) goto pc106;
pc101: if (Tick()) return;
    register_pc_ = 101;
    VLOG(3) << "[101] JGT 103,d,[4]";
    if (JGT(register_d_, Memory(4))) goto pc103;
pc102: if (Tick()) return;
    register_pc_ = 102;
    VLOG(3) << "[102] JLT 106,[100],[5]";
    if (JLT(Memory(100), Memory(5))) goto pc106;
pc103: if (Tick()) return;
    register_pc_ = 103;
    VLOG(3) << "[103] MOV [1],2";
    MOV(Memory(1), 2);
pc104: if (Tick()) return;
    register_pc_ = 104;
    VLOG(3) << "[104] MOV [4],d";
    MOV(Memory(4), register_d_);
pc105: if (Tick()) return;
    register_pc_ = 105;
    VLOG(3) << "[105] MOV [5],[100]";
    MOV(Memory(5), Memory(100));
pc106: if (Tick()) return;
    register_pc_ = 106;
    VLOG(3) << "[106] MOV d,100";
    MOV(register_d_, 100);
pc107: if (Tick()) return;
    register_pc_ = 107;
    VLOG(3) << "[107] MOV a,g";
    MOV(register_a_, register_g_);
pc108: if (Tick()) return;
    register_pc_ = 108;
    VLOG(3) << "[108] MOV b,h";
    MOV(register_b_, register_h_);
pc109: if (Tick()) return;
    register_pc_ = 109;
    VLOG(3) << "[109] SUB a,1";
    SUB(register_a_, 1);
pc110: if (Tick()) return;
    register_pc_ = 110;
    VLOG(3) << "[110] INT 7";
    INT7();
pc111: if (Tick()) return;
    register_pc_ = 111;
    VLOG(3) << "[111] JEQ 132,a,0";
    if (JEQ(register_a_, 0)) goto pc132;
pc112: if (Tick()) return;
    register_pc_ = 112;
    VLOG(3) << "[112] JEQ 132,[3],3";
    if (JEQ(Memory(3), 3)) goto pc132;
pc113: if (Tick()) return;
    register_pc_ = 113;
    VLOG(3) << "[113] INT 3";
    INT3();
pc114: if (Tick()) return;
    register_pc_ = 114;
    VLOG(3) << "[114] MOV [100],a";
    MOV(Memory(100), register_a_);
pc115: if (Tick()) return;
    register_pc_ = 115;
    VLOG(3) << "[115] XOR [100],3";
    XOR(Memory(100), 3);
pc116: if (Tick()) return;
    register_pc_ = 116;
    VLOG(3) << "[116] AND [100],3";
    AND(Memory(100), 3);
pc117: if (Tick()) return;
    register_pc_ = 117;
    VLOG(3) << "[117] JGT 126,e,g";
    if (JGT(register_e_, register_g_)) goto pc126;
pc118: if (Tick()) return;
    register_pc_ = 118;
    VLOG(3) << "[118] JGT 123,[6],10";
    if (JGT(Memory(6), 10)) goto pc123;
pc119: if (Tick()) return;
    register_pc_ = 119;
    VLOG(3) << "[119] SUB d,20";
    SUB(register_d_, 20);
pc120: if (Tick()) return;
    register_pc_ = 120;
    VLOG(3) << "[120] INT 3";
    INT3();
pc121: if (Tick()) return;
    register_pc_ = 121;
    VLOG(3) << "[121] INT 6";
    INT6();
pc122: if (Tick()) return;
    register_pc_ = 122;
    VLOG(3) << "[122] JEQ 126,a,1";
    if (JEQ(register_a_, 1)) goto pc126;
pc123: if (Tick()) return;
    register_pc_ = 123;
    VLOG(3) << "[123] ADD d,40";
    ADD(register_d_, 40);
pc124: if (Tick()) return;
    register_pc_ = 124;
    VLOG(3) << "[124] ADD [100],g";
    ADD(Memory(100), register_g_);
pc125: if (Tick()) return;
    register_pc_ = 125;
    VLOG(3) << "[125] SUB [100],e";
    SUB(Memory(100), register_e_);
pc126: if (Tick()) return;
    register_pc_ = 126;
    VLOG(3) << "[126] JLT 132,d,[4]";
    if (JLT(register_d_, Memory(4))) goto pc132;
pc127: if (Tick()) return;
    register_pc_ = 127;
    VLOG(3) << "[127] JGT 129,d,[4]";
    if (JGT(register_d_, Memory(4))) goto pc129;
pc128: if (Tick()) return;
    register_pc_ = 128;
    VLOG(3) << "[128] JLT 132,[100],[5]";
    if (JLT(Memory(100), Memory(5))) goto pc132;
pc129: if (Tick()) return;
    register_pc_ = 129;
    VLOG(3) << "[129] MOV [1],3";
    MOV(Memory(1), 3);
pc130: if (Tick()) return;
    register_pc_ = 130;
    VLOG(3) << "[130] MOV [4],d";
    MOV(Memory(4), register_d_);
pc131: if (Tick()) return;
    register_pc_ = 131;
    VLOG(3) << "[131] MOV [5],[100]";
    MOV(Memory(5), Memory(100));
pc132: if (Tick()) return;
    register_pc_ = 132;
    VLOG(3) << "[132] MOV a,[1]";
    MOV(register_a_, Memory(1));
pc133: if (Tick()) return;
    register_pc_ = 133;
    VLOG(3) << "[133] INT 0";
    INT0();
pc134: if (Tick()) return;
    register_pc_ = 134;
    VLOG(3) << "[134] MOV d,[1]";
    MOV(register_d_, Memory(1));
pc135: if (Tick()) return;
    register_pc_ = 135;
    VLOG(3) << "[135] HLT";
    HLT();
  }
};

class iwi6GhostFactory : public ::GhostFactory {
 public:
  virtual ~iwi6GhostFactory() {}

  std::unique_ptr<::GhostInterface> Create() {
    return std::unique_ptr<::GhostInterface>(new iwi6Ghost());
  }
};

}  // namespace ghost

#endif  // GHOST_AI_IWI6_H_