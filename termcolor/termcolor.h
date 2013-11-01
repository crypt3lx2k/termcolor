#ifndef TERMCOLOR_H
#define TERMCOLOR_H

#include <stddef.h>

typedef struct {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} termcolor;

/* sets the terminal based on name, if name is NULL then the
   name is taken from the TERM environment variable. */
extern void termcolor_setup (const char * term);

/* returns the n'th color from the terminal. */
extern termcolor termcolor_get (size_t n);

/* returns the number of colors termcolor thinks is available
   for the currently set terminal. */
extern size_t termcolor_max_colors;

#endif /* TERMCOLOR_H */
