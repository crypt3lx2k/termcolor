#include "termcolor_Eterm.h"

static termcolor colors[] = {
  TERMCOLOR_ENTRY("black"        ,  0,   0,   0,   0),
  TERMCOLOR_ENTRY("red"          ,  1, 204,   0,   0),
  TERMCOLOR_ENTRY("green"        ,  2,   0, 204,   0),
  TERMCOLOR_ENTRY("yellow"       ,  3, 204, 204,   0),
  TERMCOLOR_ENTRY("blue"         ,  4,   0,   0, 204),
  TERMCOLOR_ENTRY("magenta"      ,  5, 204,   0, 204),
  TERMCOLOR_ENTRY("cyan"         ,  6,   0, 204, 204),
  TERMCOLOR_ENTRY("white"        ,  7, 170, 170, 170),
  TERMCOLOR_ENTRY("brightblack"  ,  8,  51,  51,  51),
  TERMCOLOR_ENTRY("brightred"    ,  9, 255,   0,   0),
  TERMCOLOR_ENTRY("brightgreen"  , 10,   0, 255,   0),
  TERMCOLOR_ENTRY("brightyellow" , 11, 255, 255,   0),
  TERMCOLOR_ENTRY("brightblue"   , 12,   0,   0, 255),
  TERMCOLOR_ENTRY("brightmagenta", 13, 255,   0, 255),
  TERMCOLOR_ENTRY("brightcyan"   , 14,   0, 255, 255),
  TERMCOLOR_ENTRY("brightwhite"  , 15, 255, 255, 255),
};

/* Eterm */
termcolor Eterm_color (size_t n) {
  return colors[n];
}

/* Eterm-256color */
termcolor Eterm_256color_color (size_t n) {
  /* base colors */
  if (n < 16)
    return colors[n];

  /* non-gray 6x6x6 color cube */
  if (n < 232) {
    unsigned char steps[] = {0, 42, 85, 127, 170, 212};
    unsigned char r, g, b;
    unsigned char code = n - 16;

    b = code % 6;
    code -= b;
    code /= 6;

    g = code % 6;
    code -= g;
    code /= 6;

    r = code % 6;

    return TERMCOLOR(steps[r], steps[g], steps[b]);
  }

  /* grayscale ramp */
  if (n < 256) {
    unsigned char gray  = n - 232;
    unsigned char level = (gray * 10) + 8;

    return TERMCOLOR(level, level, level);
  }

  return TERMCOLOR(0, 0, 0);
}
