#include <stdlib.h>
#include <string.h>

#include "termcolor_private.h"

/* number of colors available for currently active terminal. */
size_t termcolor_max_colors;

/* currently active terminal */
static termcolor_term terminal;

static termcolor_term termcolor_recognize (const char * name) {
  termcolor_term term;
  size_t name_len;

  if (name == NULL)
    return TERMCOLOR_TERM_UNKNOWN;

  name_len = strlen(name);

  for (term = TERMCOLOR_TERM_UNKNOWN; term < TERMCOLOR_TERM_LAST; term++) {
    const char * start = termcolor_terminals[term].name;
    const char * end;

    do {
      end = strchr(start, '|');

      if (end == NULL) {
        if (strcmp(start, name) == 0)
          return term;
      } else {
        size_t term_len = end - start;

        if (name_len == term_len && strncmp(start, name, term_len) == 0)
          return term;
      }

      start = end+1;
    } while (end != NULL);
  }

  return TERMCOLOR_TERM_UNKNOWN;
}

void termcolor_setup (const char * term) {
  if (term == NULL)
    term = getenv("TERM");

  terminal = termcolor_recognize(term);
  termcolor_max_colors =
    termcolor_terminals[terminal].max_colors;
}

termcolor termcolor_get (size_t n) {
  return termcolor_terminals[terminal].color(n);
}
