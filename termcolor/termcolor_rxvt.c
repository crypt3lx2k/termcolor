#include "termcolor_rxvt.h"

static termcolor colors[] = {
  TERMCOLOR_ENTRY("black"        ,  0,   0,   0,   0),
  TERMCOLOR_ENTRY("red"          ,  1, 205,   0,   0),
  TERMCOLOR_ENTRY("green"        ,  2,   0, 205,   0),
  TERMCOLOR_ENTRY("yellow"       ,  3, 205, 205,   0),
  TERMCOLOR_ENTRY("blue"         ,  4,   0,   0, 205),
  TERMCOLOR_ENTRY("magenta"      ,  5, 205,   0, 205),
  TERMCOLOR_ENTRY("cyan"         ,  6,   0, 205, 205),
  TERMCOLOR_ENTRY("white"        ,  7, 229, 229, 229),
  TERMCOLOR_ENTRY("brightblack"  ,  8,  77,  77,  77),
  TERMCOLOR_ENTRY("brightred"    ,  9, 255,   0,   0),
  TERMCOLOR_ENTRY("brightgreen"  , 10,   0, 255,   0),
  TERMCOLOR_ENTRY("brightyellow" , 11, 255, 255,   0),
  TERMCOLOR_ENTRY("brightblue"   , 12,   0,   0, 255),
  TERMCOLOR_ENTRY("brightmagenta", 13, 255,   0, 255),
  TERMCOLOR_ENTRY("brightcyan"   , 14,   0, 255, 255),
  TERMCOLOR_ENTRY("brightwhite"  , 15, 255, 255, 255)
};

/* rxvt */
termcolor rxvt_color (size_t n) {
  return colors[n];
}

/* rxvt-16color */
termcolor rxvt_16color_color (size_t n) {
  return colors[n];
}

/* rxvt-88color */
termcolor rxvt_88color_color (size_t n) {
  /* base colors */
  if (n < 16)
    return colors[n];

  /* non-gray 4x4x4 color cube */
  if (n < 80) {
    unsigned char steps[] = {0, 139, 205, 255};
    unsigned char r, g, b;
    unsigned char code = n - 16;

    b = code % 4;
    code -= b;
    code /= 4;

    g = code % 4;
    code -= g;
    code /= 4;

    r = code % 4;

    return TERMCOLOR(steps[r], steps[g], steps[b]);
  }

  /* grayscale ramp */
  if (n < 88) {
    unsigned char gray  = n - 80;
    float level = (gray * 23.18181818) + 46.36363636;

    if (gray > 0)
      level += 23.18181818;

    return TERMCOLOR(level, level, level);
  }

  return TERMCOLOR(0, 0, 0);
}

/* rxvt-256color */
termcolor rxvt_256color_color (size_t n) {
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
