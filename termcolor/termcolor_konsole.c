#include "termcolor_konsole.h"

static termcolor colors[] = {
  TERMCOLOR_ENTRY("black"        ,  0,   0,   0,   0),
  TERMCOLOR_ENTRY("red"          ,  1, 178,  24,  24),
  TERMCOLOR_ENTRY("green"        ,  2,  24, 178,  24),
  TERMCOLOR_ENTRY("yellow"       ,  3, 178, 104,  24),
  TERMCOLOR_ENTRY("blue"         ,  4,  24,  24, 178),
  TERMCOLOR_ENTRY("magenta"      ,  5, 178,  24, 178),
  TERMCOLOR_ENTRY("cyan"         ,  6,  24, 178, 178),
  TERMCOLOR_ENTRY("white"        ,  7, 178, 178, 178),
  TERMCOLOR_ENTRY("brightblack"  ,  8, 104, 104, 104),
  TERMCOLOR_ENTRY("brightred"    ,  9, 255,  84,  84),
  TERMCOLOR_ENTRY("brightgreen"  , 10,  84, 255,  84),
  TERMCOLOR_ENTRY("brightyellow" , 11, 255, 255,  84),
  TERMCOLOR_ENTRY("brightblue"   , 12,  84,  84, 255),
  TERMCOLOR_ENTRY("brightmagenta", 13, 255,  84, 255),
  TERMCOLOR_ENTRY("brightcyan"   , 14,  84, 255, 255),
  TERMCOLOR_ENTRY("brightwhite"  , 15, 255, 255, 255)
};

/* konsole */
termcolor konsole_color (size_t n) {
  return colors[n];
}

/* konsole-256color */
termcolor konsole_256color_color (size_t n) {
  /* base colors */
  if (n < 16)
    return colors[n];

  /* non-gray 6x6x6 color cube */
  if (n < 232) {
    unsigned char r, g, b;
    unsigned char code = n - 16;

    b = code % 6;
    code -= b;
    code /= 6;

    g = code % 6;
    code -= g;
    code /= 6;

    r = code % 6;

    return TERMCOLOR (
        r ? (r * 40 + 55) : 0,
        g ? (g * 40 + 55) : 0,
        b ? (b * 40 + 55) : 0
    );
  }

  /* grayscale ramp */
  if (n < 256) {
    unsigned char gray  = n - 232;
    unsigned char level = (gray * 10) + 8;

    return TERMCOLOR(level, level, level);
  }

  return TERMCOLOR(0, 0, 0);
}
