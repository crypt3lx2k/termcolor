#ifndef TERMCOLOR_PRIVATE_H
#define TERMCOLOR_PRIVATE_H

#include "termcolor.h"

/* creates a termcolor based on rgb values. */
#define TERMCOLOR(r, g, b)                      \
  ((termcolor) {(r), (g), (b)})

/* creates a termcolor with some metadata that's no
   longer used and is not present in the compiled code */
#define TERMCOLOR_ENTRY(name, number, r, g, b)  \
  TERMCOLOR((r), (g), (b))

/* vtable entry for global terminal list. */
typedef struct {
  /* a | separated list of TERM environment variable values
     that correspond to this terminal type. */
  const char * name;

  /* holds the amount of available colors for this terminal
     type. */
  size_t max_colors;

  /* a pointer to a function that returns the correct color
     entry given a color index for this terminal type. */
  termcolor (* const color) (size_t n);
} termcolor_term_entry;

/* initializer based on terminal name. */
#define TERMCOLOR_TERM_ENTRY(term, colors, names)       \
  {(names), (colors), (term##_color)}

/* list of every known terminal type. */
typedef enum {
  TERMCOLOR_TERM_UNKNOWN,

  TERMCOLOR_TERM_ATERM,

  TERMCOLOR_TERM_ETERM,
  TERMCOLOR_TERM_ETERM_256COLOR,

  TERMCOLOR_TERM_KONSOLE,
  TERMCOLOR_TERM_KONSOLE_256COLOR,

  TERMCOLOR_TERM_RXVT,
  TERMCOLOR_TERM_RXVT_16COLOR,
  TERMCOLOR_TERM_RXVT_88COLOR,
  TERMCOLOR_TERM_RXVT_256COLOR,

  TERMCOLOR_TERM_XTERM,
  TERMCOLOR_TERM_XTERM_16COLOR,
  TERMCOLOR_TERM_XTERM_88COLOR,
  TERMCOLOR_TERM_XTERM_256COLOR,

  TERMCOLOR_TERM_LAST
} termcolor_term;

/* vtable for every known terminal. */
extern termcolor_term_entry termcolor_terminals[];

/* declares the functions and variables for a terminal. */
#define TERMCOLOR_DECLARE(term) \
  extern termcolor term##_color(size_t n);

#endif /* TERMCOLOR_PRIVATE_H */
