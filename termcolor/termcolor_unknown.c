#include "termcolor_unknown.h"

static termcolor colors[] = {
  TERMCOLOR_ENTRY("black"  , 0,   0,   0,   0),
  TERMCOLOR_ENTRY("red"    , 1, 255,   0,   0),
  TERMCOLOR_ENTRY("green"  , 2,   0, 255,   0),
  TERMCOLOR_ENTRY("yellow" , 3, 255, 255,   0),
  TERMCOLOR_ENTRY("blue"   , 4,   0,   0, 255),
  TERMCOLOR_ENTRY("magenta", 5, 255,   0, 255),
  TERMCOLOR_ENTRY("cyan"   , 6,   0, 255, 255),
  TERMCOLOR_ENTRY("white"  , 7, 255, 255, 255)
};

termcolor unknown_color (size_t n) {
  return colors[n];
}
