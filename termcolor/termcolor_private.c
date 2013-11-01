#include "termcolor_unknown.h"

#include "termcolor_aterm.h"
#include "termcolor_Eterm.h"
#include "termcolor_konsole.h"
#include "termcolor_rxvt.h"
#include "termcolor_xterm.h"

termcolor_term_entry termcolor_terminals[] = {
  TERMCOLOR_TERM_ENTRY(unknown, 8, "undefined"),

  TERMCOLOR_TERM_ENTRY(aterm, 16, "aterm"),

  TERMCOLOR_TERM_ENTRY(Eterm, 8,
                       "Eterm" "|"
                       "Eterm-color"),
  TERMCOLOR_TERM_ENTRY(Eterm_256color, 256,
                       "Eterm-256color"),

  TERMCOLOR_TERM_ENTRY(konsole, 8,
                       "konsole"),
  TERMCOLOR_TERM_ENTRY(konsole_256color, 256,
                       "konsole-256color"),

  TERMCOLOR_TERM_ENTRY(rxvt, 8,
                       "rxvt"               "|"
                       "rxvt-color"         "|"
                       "rxvt-cygwin"        "|"
                       "rxvt-cygwin-native" "|"
                       "rxvt-xpm"           "|"
                       "mrxvt"),
  TERMCOLOR_TERM_ENTRY(rxvt_16color, 16,
                       "rxvt-16color"),
  TERMCOLOR_TERM_ENTRY(rxvt_88color, 88,
                       "rxvt-88color" "|"
                       "rxvt-unicode"),
  TERMCOLOR_TERM_ENTRY(rxvt_256color, 256,
                       "rxvt-256color" "|"
                       "rxvt-unicode-256color"),

  TERMCOLOR_TERM_ENTRY(xterm, 8,
                       /* eterm is emacs built-in console,
                          apparently it uses the same colors
                          as xterm. */
                       "eterm-color"     "|"
                       "nxterm"          "|"
                       "xterm"           "|"
                       "xterm-1002"      "|"
                       "xterm-1003"      "|"
                       "xterm-8bit"      "|"
                       "xterm-basic"     "|"
                       "xterm-color"     "|"
                       "xterm-hp"        "|"
                       "xterm-new"       "|"
                       "xterm-nic"       "|"
                       "xterm-noapp"     "|"
                       "xterm-pcolor"    "|"
                       "xterm-sco"       "|"
                       "xterm-sun"       "|"
                       "xterm-utf8"      "|"
                       "xterm-vt220"     "|"
                       "xterm-xf86-v32"  "|"
                       "xterm-xf86-v33"  "|"
                       "xterm-xf86-v333" "|"
                       "xterm-xf86-v40"  "|"
                       "xterm-xf86-v43"  "|"
                       "xterm-xfree86"   "|"
                       "xterm-xi"),
  TERMCOLOR_TERM_ENTRY(xterm_16color, 16,
                       "xterm-16color"),
  TERMCOLOR_TERM_ENTRY(xterm_88color, 88,
                       "xterm-88color"),
  TERMCOLOR_TERM_ENTRY(xterm_256color, 256,
                       "xterm-256color" "|"
                       /* terminfo claims these are
                          ``... with 256 xterm colors''. */
                       "gnome-256color" "|"
                       "putty-256color" "|"
                       "vte-256color")
};
