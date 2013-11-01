#include "termcolor_aterm.h"

static termcolor colors[] = {
  TERMCOLOR_ENTRY("black"        ,  0,   0,   0,   0),
  TERMCOLOR_ENTRY("red"          ,  1, 205,   0,   0),
  TERMCOLOR_ENTRY("green"        ,  2,   0, 205,   0),
  TERMCOLOR_ENTRY("yellow"       ,  3, 205, 205,   0),
  TERMCOLOR_ENTRY("blue"         ,  4,   0,   0, 205),
  TERMCOLOR_ENTRY("magenta"      ,  5, 205,   0, 205),
  TERMCOLOR_ENTRY("cyan"         ,  6,   0, 205, 205),
  TERMCOLOR_ENTRY("white"        ,  7, 250, 239, 215),
  TERMCOLOR_ENTRY("brightblack"  ,  8,  64,  64,  64),
  TERMCOLOR_ENTRY("brightred"    ,  9, 255,   0,   0),
  TERMCOLOR_ENTRY("brightgreen"  , 10,   0, 255,   0),
  TERMCOLOR_ENTRY("brightyellow" , 11, 255, 255,   0),
  TERMCOLOR_ENTRY("brightblue"   , 12,   0,   0, 255),
  TERMCOLOR_ENTRY("brightmagenta", 13, 255,   0, 255),
  TERMCOLOR_ENTRY("brightcyan"   , 14,   0, 255, 255),
  TERMCOLOR_ENTRY("brightwhite"  , 15, 255, 255, 255)
};

/* aterm */
termcolor aterm_color (size_t n) {
  return colors[n];
}
