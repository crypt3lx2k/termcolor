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
#include <stdio.h>
#include <unistd.h>

#include <curses.h>
#include <term.h>

#include <termcolor/termcolor.h>

#define SQUARE(x) ((x)*(x))
#define DIFF(x, y) ((x) > (y) ? (x) - (y) : (y) - (x))

static double compare (termcolor a, termcolor b) {
  return sqrt(SQUARE(DIFF(a.r, b.r)) +
	      SQUARE(DIFF(a.g, b.g)) +
	      SQUARE(DIFF(a.b, b.b)));
}

static int closest (termcolor c) {
  int i;
  int closest = 0;
  double min_diff = INFINITY;

  for (i = 0; i < max_colors; i++) {
    termcolor a = termcolor_get(i);
    double diff = compare(a, c);

    if (diff < min_diff) {
      min_diff = diff;
      closest = i;
    }
  }

  return closest;
}

static int negative (termcolor c) {
  termcolor n = (termcolor) {
    255 - c.r,
    255 - c.g,
    255 - c.b
  };

  return closest(n);
}

int main(void) {
  int i;

  setupterm(NULL, STDOUT_FILENO, NULL);
  termcolor_setup(NULL);

  for (i = 0; i < max_colors; i++) {
    int j;
    char * color = tparm(set_a_background, i);
    putp(color);

    for (j = 0; j < columns-17; j++)
      putchar(' ');

    termcolor c = termcolor_get(i);
    color = tparm(set_a_foreground, negative(c));
    putp(color);
    printf("%3d;rgb:#%02x/%02x/%02x", i, c.r, c.g, c.b);

    putp(exit_attribute_mode);
    putchar('\n');
  }

  return 0;
}
```
