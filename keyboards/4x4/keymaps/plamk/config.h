#pragma once

#define MIDI_BASIC
#define MIDI_ADVANCED

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

// default but important
#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

#define TAPPING_FORCE_HOLD_PER_KEY

#define COMBO_COUNT 32
#define STATIC_LAYERSET 7
#define STRING_DELAY 20

#define CLIP_BLOCK_X 8
#define CLIP_BLOCK_Y 4
