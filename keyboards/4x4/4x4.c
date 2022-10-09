#include "4x4.h"

const unsigned char SX = 16;
const unsigned char SY = 16;
const unsigned char LX = 210/11;
const unsigned char LY = 30/3;

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {	0,	2,	16+0,	16+2,	32+0,	32+2	},
  {	1,	3,	16+1,	16+3,	32+1,	32+3	},
  {	7,	5,	16+7,	16+5,	32+7,	32+5	},
  {	6,	4,	16+6,	16+4,	32+6,	32+4	},
  {	8,	10,	16+8,	16+10,	32+8,	32+10	},
  {	9,	11,	16+9,	16+11,	32+9,	32+11	},
  {	15,	13,	16+15,	16+13,	32+15,	32+13	},
  {	14,	12,	16+14,	16+12,	32+14,	32+12	}
}, {
  // LED Index to Physical Position
  { SX + 0*LX,  SY + 0*LY },	{ SX + 1*LX,  SY + 0*LY },	{ SX + 2*LX,  SY + 0*LY },	{ SX + 3*LX,  SY + 0*LY },	
  { SX + 3*LX,  SY + 1*LY },	{ SX + 2*LX,  SY + 1*LY },	{ SX + 1*LX,  SY + 1*LY },	{ SX + 0*LX,  SY + 1*LY },	
  { SX + 0*LX,  SY + 2*LY },	{ SX + 1*LX,  SY + 2*LY },	{ SX + 2*LX,  SY + 2*LY },	{ SX + 3*LX,  SY + 2*LY },	
  { SX + 3*LX,  SY + 3*LY },	{ SX + 2*LX,  SY + 3*LY },	{ SX + 1*LX,  SY + 3*LY },	{ SX + 0*LX,  SY + 3*LY },	

  { SX + 4*LX,  SY + 0*LY },	{ SX + 5*LX,  SY + 0*LY },	{ SX + 6*LX,  SY + 0*LY },	{ SX + 7*LX,  SY + 0*LY },	
  { SX + 7*LX,  SY + 1*LY },	{ SX + 6*LX,  SY + 1*LY },	{ SX + 5*LX,  SY + 1*LY },	{ SX + 4*LX,  SY + 1*LY },	
  { SX + 4*LX,  SY + 2*LY },	{ SX + 5*LX,  SY + 2*LY },	{ SX + 6*LX,  SY + 2*LY },	{ SX + 7*LX,  SY + 2*LY },	
  { SX + 7*LX,  SY + 3*LY },	{ SX + 6*LX,  SY + 3*LY },	{ SX + 5*LX,  SY + 3*LY },	{ SX + 4*LX,  SY + 3*LY },	

  { SX + 8*LX,  SY + 0*LY },	{ SX + 9*LX,  SY + 0*LY },	{ SX + 10*LX,  SY + 0*LY },	{ SX + 11*LX,  SY + 0*LY },	
  { SX + 11*LX,  SY + 1*LY },	{ SX + 10*LX,  SY + 1*LY },	{ SX + 9*LX,  SY + 1*LY },	{ SX + 8*LX,  SY + 1*LY },	
  { SX + 8*LX,  SY + 2*LY },	{ SX + 9*LX,  SY + 2*LY },	{ SX + 10*LX,  SY + 2*LY },	{ SX + 11*LX,  SY + 2*LY },	
  { SX + 11*LX,  SY + 3*LY },	{ SX + 10*LX,  SY + 3*LY },	{ SX + 9*LX,  SY + 3*LY },	{ SX + 8*LX,  SY + 3*LY }
}, {
  // LED Index to Flag
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,

  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,

  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4
} };
