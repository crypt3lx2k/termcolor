AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I build-aux/m4

lib_LTLIBRARIES = libtermcolor.la

libtermcolor_la_SOURCES = termcolor/termcolor_aterm.c termcolor/termcolor_aterm.h termcolor/termcolor.c termcolor/termcolor_Eterm.c termcolor/termcolor_Eterm.h termcolor/termcolor_konsole.c termcolor/termcolor_konsole.h termcolor/termcolor_private.c termcolor/termcolor_private.h termcolor/termcolor_rxvt.c termcolor/termcolor_rxvt.h termcolor/termcolor_unknown.c termcolor/termcolor_unknown.h termcolor/termcolor_xterm.c termcolor/termcolor_xterm.h
nobase_libtermcolor_la_HEADERS = termcolor/termcolor.h
libtermcolor_ladir = $(includedir)

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = termcolor.pc
