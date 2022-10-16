#pragma once

/* Beginning of the block of notes that have feedback: C2, MIDI 48 */
#define CLIP_BLOCK_INITIAL_NOTE 48
#define CLIP_BLOCK_INITIAL_KEY MI_C

/* Size of the block of MIDI notes used to represent the session clips.
Default is 8 tracks by 4 clips */
#define CLIP_BLOCK_X 8
#define CLIP_BLOCK_Y 4
#define CLIP_BLOCK_SIZE (128-CLIP_BLOCK_INITIAL_NOTE)

/* Stores the last velocity of each note sent to the keyboard. */
extern char indicators[];

extern const uint8_t ableton_colors[];
