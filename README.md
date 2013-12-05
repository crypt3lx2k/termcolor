Termcolor is a simple MIT licensed database that provides terminal colors based
on a terminal name or the TERM environment variable.

If you obtained the source directly from github and not through a tarball then
there is no configure script in this directory. You may create a configure
script if you have the GNU autotools installed by running the command
$ autoreconf -fi

Compile with
$ ./configure && make && make install

Normal configure flags apply, to get a short summary of flags run
$ ./configure --help

Here is an example program that uses termcolor and ncurses to print the known
terminal colors to screen together with the RGB values.

```
#include <math.h>
#include <stdlib.h>

#include <unistd.h>

#include <curses.h>
#include <term.h>

#include "termcolor/termcolor.h"

#define UCHAR_DIFF(m, n) \
  ((m) < (n) ? (n) - (m) : (m) - (n))

#define SQUARE(x) ((x)*(x))

static double diff (termcolor a, termcolor b) {
  return sqrt (
    SQUARE(UCHAR_DIFF(a.r, b.r)) +
    SQUARE(UCHAR_DIFF(a.g, b.g)) +
    SQUARE(UCHAR_DIFF(a.b, b.b))
  );
}

static size_t closest (termcolor c) {
  size_t i;
  size_t best;
  double least_diff = INFINITY;

  for (i = 0; i < termcolor_max_colors; i++) {
    double d = diff(c, termcolor_get(i));

    if (d < least_diff) {
      least_diff = d;
      best = i;
    }
  }

  return best;
}

static size_t negative (termcolor c) {
  termcolor n;

  n.r = 255 - c.r;
  n.g = 255 - c.g;
  n.b = 255 - c.b;

  return closest(n);
}

int main (void) {
  size_t i;

  setupterm(NULL, STDOUT_FILENO, NULL);
  termcolor_setup(NULL);

  for (i = 0; i < termcolor_max_colors; i++) {
    termcolor c = termcolor_get(i);
    size_t n = negative(c);
    int j;

    putp(tparm(set_a_background, i));

    for (j = 0; j < columns-17; j++)
      putchar(' ');

    putp(tparm(set_a_foreground, n));
    printf("%3zu;rgb:#%02x/%02x/%02x",
           i, c.r, c.g, c.b);

    putp(exit_attribute_mode);
    putchar('\n');
  }

  return 0;
}
```

After termcolor and ncurses have been installed the example (saved as
example.c) may be compiled with
$ gcc example.c -ltermcolor -lcurses -lm -o example
and then ran with
$ ./example
