#ifndef KB_H
#define KB_H

#include "quantum.h"

#define LAYOUT_ortho_4x12( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b \
) \
{ \
	{ k00,	k02,	k04,	k06,	k08,	k0a },  \
	{ k01,	k03,	k05,	k07,	k09,	k0b },  \
	{ k10,	k12,	k14,	k16,	k18,	k1a },  \
	{ k11,	k13,	k15,	k17,	k19,	k1b },  \
	{ k20,	k22,	k24,	k26,	k28,	k2a },  \
	{ k21,	k23,	k25,	k27,	k29,	k2b },  \
	{ k30,	k32,	k34,	k36,	k38,	k3a },  \
	{ k31,	k33,	k35,	k37,	k39,	k3b }   \
}

#define LAYOUT LAYOUT_ortho_4x12

#endif