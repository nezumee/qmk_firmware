#ifndef KB_H
#define KB_H

#include "quantum.h"

#define LAYOUT_sofle( \
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05,  \
    L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15,  \
    L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25,  \
    L30, L31, L32, L33, L34, L35, L45, R40, R30, R31, R32, R33, R34, R35, \
              L40, L41, L42, L43, L44, R41, R42, R43, R44, R45  \
    ) \
  { \
	{ L00,		L01,	L02,	L03,	L04,	L05,	L44 },	\
	{ L10,		L11,	L12,	L13,	L14,	L15,	L43 },		\
	{ L20,		L21,	L22,	L23,	L24,	L25,	L42 },		\
	{ L30,		L31,	L32,	L33,	L34,	L35,	L40 },	\
	{ R00,		R01,	R02,	R03,	R04,	R05,	R41 },	\
	{ R10,		R11,	R12,	R13,	R14,	R15,	R42 },		\
	{ R20,		R21,	R22,	R23,	R24,	R25,	R43 },		\
	{ R30,		R31,	R32,	R33,	R34,	R35,	R44 },	\
  }

// 3x6+3 on Atreus with extra inner keys
#define LAYOUT_split_3x6_3_atreus_inner_keys( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
    ) \
  { \
	{ L00,		L01,	L02,	L03,	L04,	L05,	KC_NO },	\
	{ L10,		L11,	L12,	L13,	L14,	L15,	KC_LPRN },		\
	{ L20,		L21,	L22,	L23,	L24,	L25,	KC_NO },		\
	{ KC_NO,	KC_NO,	KC_NO,	L30,	L31,	L32,	KC_NO },	\
	{ R00,		R01,	R02,	R03,	R04,	R05,	KC_NO },	\
	{ R10,		R11,	R12,	R13,	R14,	R15,	KC_RPRN },		\
	{ R20,		R21,	R22,	R23,	R24,	R25,	KC_NO },		\
	{ R30,		R31,	R32,	KC_NO,	KC_NO,	KC_NO,	KC_NO},	\
  }

// 3x6+3 on Kyria layout on both sides, extra keys under ring and middle fingers - Barobord
#define LAYOUT_split_3x6_3_long_index_middle_columns( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  { \
	{ KC_NO,	KC_NO,	L02,	L03,	KC_NO,	KC_NO,	L32 },	\
	{ L00,		L01,	L12,	L13,	L04,	L05,	L31 },		\
	{ L10,		L11,	L22,	L23,	L14,	L15,	L30 },		\
	{ L20,		L21,	KC_LPRN,KC_RPRN,L24,	L25,	KC_NO },	\
  	{ KC_NO,	KC_NO,  R02,	R03,	KC_NO,	KC_NO,	R30},  \
	{ R00,		R01,   	R12,	R13,	R04,	R05,	R31 },  \
	{ R10,		R11,  	R22,	R23,	R14,	R15,	R32 },  \
	{ R20,		R21,	KC_DQUO,KC_QUOT,R24,	R25,	KC_NO }	\
  }

// 3x6+3 on Kyria layout on both sides, thumb shifted
#define LAYOUT_split_3x6_3( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  { \
	{ KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO },	\
	{ L00,		L01,	L02,	L03,	L04,	L05,	L32 },		\
	{ L10,		L11,	L12,	L13,	L14,	L15,	L31 },		\
	{ L20,		L21,	L22,	L23,	L24,	L25,	L30 },	\
  	{ KC_NO,	KC_NO,  KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO },  \
	{ R00,		R01,   	R02,	R03,	R04,	R05,	R30 },  \
	{ R10,		R11,  	R12,	R13,	R14,	R15,	R31 },  \
	{ R20,		R21,	R22,	R23,	R24,	R25,	R32 }	\
  }

// 3x6+3 on Kyria layout on both sides
#define LAYOUT_split_3x6_3_normal( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  { \
	{ KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	L32 },	\
	{ L00,		L01,	L02,	L03,	L04,	L05,	L31 },		\
	{ L10,		L11,	L12,	L13,	L14,	L15,	L30 },		\
	{ L20,		L21,	L22,	L23,	L24,	L25,	KC_NO },	\
  	{ KC_NO,	KC_NO,  KC_NO,	KC_NO,	KC_NO,	KC_NO,	R30},  \
	{ R00,		R01,   	R02,	R03,	R04,	R05,	R31 },  \
	{ R10,		R11,  	R12,	R13,	R14,	R15,	R32 },  \
	{ R20,		R21,	R22,	R23,	R24,	R25,	KC_NO }	\
  }
	
// Choc Zebra , right stripes
#define LAYOUT_split_3x6_3_stripes( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  { \
	{ KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO },	\
	{ L01,		L02,	L03,	L04,	L05,	KC_NO,	L32 },		\
	{ L11,		L12,	L13,	L14,	L15,	KC_NO,	L31 },		\
	{ L21,		L22,	L23,	L24,	L25,	KC_NO,	L30 },	\
  	{ KC_NO,	KC_NO,  KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO },  \
	{ R00,		R01,   	R02,	R03,	R04,	KC_NO,	R30 },  \
	{ R10,		R11,  	R12,	R13,	R14,	KC_NO,	R31 },  \
	{ R20,		R21,	R22,	R23,	R24,	KC_NO,	R32 }	\
  }

// Amber on Zebra
#define LAYOUT_split_3x6_3_amber( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  { \
	{ L01,		L02,	L03,	L04,	L05,	KC_NO,	KC_NO },	\
	{ L11,		L12,	L13,	L14,	L15,	KC_NO,	L31 },		\
	{ L21,		L22,	L23,	L24,	L25,	KC_NO,	L32 },		\
	{ KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	L30,	KC_NO },	\
	{ R04,		R03,	R02,	R01,	R00,	KC_NO,	KC_NO },	\
	{ R14,		R13,	R12,	R11,	R10,	KC_NO,	R31 },		\
	{ R24,		R23,	R22,	R21,	R20,	KC_NO,	R30 },		\
	{ KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	R32,	KC_NO },	\
  }

// Amber on Zebra (left only), right stripes all vertical
#define LAYOUT_split_3x6_3_amber_left_vertical_right( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  { \
	{ L01,		L02,	L03,	L04,	L05,	KC_NO,	KC_NO },	\
	{ L11,		L12,	L13,	L14,	L15,	KC_NO,	L31 },		\
	{ L21,		L22,	L23,	L24,	L25,	KC_NO,	L32 },		\
	{ KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	L30,	KC_NO },	\
  	{ KC_NO,	R00,   	R02,	R03,	R04,	KC_NO,	R01 },  \
	{ KC_NO,	R10,   	R12,	R13,	R14,	KC_NO,	R11 },  \
	{ KC_NO,	R20,  	R22,	R23,	R24,	KC_NO,	R21 },  \
	{ R30,		R31,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	R32 }	\
  }
  
// ZDM with choc right
#define LAYOUT_split_3x6_3_zdm_choc_right( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  { \
	{ KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO },	\
	{ L01,		L02,	L03,	L04,	L05,	L30,	L00 },  \
	{ L11,		L12,	L13,	L14,	L15,	L32,	L10 },  \
	{ L21,		L22,	L23,	L24,	L25,	L31,	L20	},  \
  	{ R30,		R20,   	R21,	R22,	R23,	R24,	R24 },  \
	{ R31,		R10,   	R11,	R12,	R13,	R14,	R14 },  \
	{ R32,		R00,  	R01,	R02,	R03,	R04,	R04 },  \
	{ KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	RESET }	\
  }

#define LAYOUT_split_3x6_3_zdm( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  { \
	{ KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO },	\
	{ L01,		L02,	L03,	L04,	L05,	L30,	L00 },  \
	{ L11,		L12,	L13,	L14,	L15,	L32,	L10 },  \
	{ L21,		L22,	L23,	L24,	L25,	L31,	L20	},  \
	{ R31,		R20,   	R21,	R22,	R23,	R24,	R24 },  \
	{ R30,		R10,   	R11,	R12,	R13,	R14,	R14 },  \
	{ R32,		R00,  	R01,	R02,	R03,	R04,	R04 },  \
	{ KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	RESET }	\
  }

#define LAYOUT_split_3x6_3_combination2( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  { \
	{ KC_NO,	KC_NO,	KC_NO,	L03,	L04,	L05,	KC_NO },	\
	{ L01,		L01,	L02,	L13,	L14,	L15,	KC_NO },  \
	{ L11,		L11,	L12,	L23,	L24,	L25,	KC_NO },  \
	{ L21,		L21,	L22,	KC_NO,	L30,	L31,	L32	},  \
	{ R32,		R20,   	R21,	R22,	R23,	R24,	R24 },  \
	{ R31,		R10,   	R11,	R12,	R13,	R14,	R14 },  \
	{ R30,		R00,  	R01,	R02,	R03,	R04,	R04 },  \
	{ KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	RESET }	\
  }

// Zebra, left side with thumb at the bottom of the main block
#define LAYOUT_split_3x6_3_rightthumb( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  { \
	{ KC_NO,	KC_NO,	KC_NO,	L03,	L04,	L05,	KC_NO },	\
	{ L01,		L01,	L02,	L13,	L14,	L15,	KC_NO },  \
	{ L11,		L11,	L12,	L23,	L24,	L25,	KC_NO },  \
	{ L21,		L21,	L22,	KC_NO,	L30,	L31,	L32	},  \
	{ KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	RESET },	\
	{ R00,  	R01,	R02,	R03,	R04,	R04,	R30 },  \
	{ R10,   	R11,	R12,	R13,	R14,	R14,	R31	},  \
	{ R20,   	R21,	R22,	R23,	R24,	R24,	R32	}  \
  }

// Zebra, both sides with extra thumb column, left with spot keys
#define LAYOUT_split_3x6_3_spot( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  { \
	{ KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	L31 },	\
	{ L01,		L01,	L02,	L03,	L04,	L05,	L32 },  \
	{ L11,		L11,	L12,	L13,	L14,	L15,	L30	},  \
	{ L21,		L21,	L22,	L23,	L24,	L25,	KC_NO	},  \
	{ KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_MINS },	\
	{ R00,  	R01,	R02,	R03,	R04,	R04,	R30 },  \
	{ R10,   	R11,	R12,	R13,	R14,	R14,	R31	},  \
	{ R20,   	R21,	R22,	R23,	R24,	R24,	R32	}  \
  }

// Zebra, both sides with extra thumb column
#define LAYOUT_split_3x6_3_boththumb( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  { \
	{ KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO },	\
	{ L01,		L01,	L02,	L03,	L04,	L05,	L32 },  \
	{ L11,		L11,	L12,	L13,	L14,	L15,	L31	},  \
	{ L21,		L21,	L22,	L23,	L24,	L25,	L30	},  \
	{ KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	RESET },	\
	{ R00,  	R01,	R02,	R03,	R04,	R04,	R30 },  \
	{ R10,   	R11,	R12,	R13,	R14,	R14,	R31	},  \
	{ R20,   	R21,	R22,	R23,	R24,	R24,	R32	}  \
  }
  

#define LAYOUT_split_3x6_3_old( \
  L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
  L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
  L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
                      L30, L31, L32, R30, R31, R32 \
  ) \
  { \
	{ L01, 		L02,	L03,	L04,	L05,	KC_NO,	KC_NO },  \
	{ L11,		L12,	L13,	L14,	L15,	KC_NO,	KC_NO },  \
	{ L21,		L22,	L23,	L24,	L25,	KC_NO,	KC_NO },  \
	{ KC_NO,	KC_NO,	KC_NO,	L30,	L31,	KC_NO,	L32 },	\
	{ R00,   R01,	R02,	R03,	R04,	R05,	RESET },  \
	{ R10,   R11,	R12,	R13,	R14,	R15,	KC_NO },  \
	{ R20,   R21,	R22,	R23,	R24,	R25,	KC_NO },  \
	{ R31,   R32,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	R30 }	\
  }
  
  
#define KEYMAP_raw ( \
	L00, L01, L02, L03, L04, L05,	R00, R01, R02, R03, R04, R05,	\
	L10, L11, L12, L13,	L14, L15,	R10, R11, R12, R13,	R14, R15,	\
	L20, L21, L22, L23,	L24, L25,	R20, R21, R22, R23,	R24, R25,	\
	L30, L31, L32, L33,	L34, L35, 	R30, R31, R32, R33,	R34, R35, 	\
	          LM1, LM2, LM3, LM4,	RM1, RM2, RM3, RM4 \
) { \
	{ L00,   L01,	L02,	L03,	L04,	L05,	LM1 },  \
	{ L10,   L11,	L12,	L13,	L14,	L15,	LM2 },  \
	{ L20,   L21,	L22,	L23,	L24,	L25,	LM3 },  \
	{ L30,   L31,	L32,	L33,	L34,	L35,	LM4 },	\
	{ R00,   R01,	R02,	R03,	R04,	R05,	RM1 },  \
	{ R10,   R11,	R12,	R13,	R14,	R15,	RM2 },  \
	{ R20,   R21,	R22,	R23,	R24,	R25,	RM3 },  \
	{ R30,   R31,	R32,	R33,	R34,	R35,	RM4 }	\
}


#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MODS_CTRL_MASK  (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MODS_ALT_MASK  (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))
#define MODS_GUI_MASK  (MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)) 

#endif