## Top level makefile for libgloss

ACLOCAL_AMFLAGS = -I . -I .. -I ../config

# Variables that will accumulate in subdirs.
bin_PROGRAMS =
check_PROGRAMS =
info_TEXINFOS =
CLEANFILES =
PHONY =

SUBDIRS = @subdirs@ .

srcroot = $(top_srcdir)/..
tooldir = $(exec_prefix)/$(target_alias)

multilibtooldir = $(tooldir)/lib$(MULTISUBDIR)
multilibtool_DATA =
multilibtool_LIBRARIES =

includetooldir = $(tooldir)/include
includetool_DATA =

includesystooldir = $(tooldir)/include/sys
includesystool_DATA =

AM_CPPFLAGS = -idirafter $(srcroot)/include

# A fake library so automake will generate rules for plain objects that we want
# to install (e.g. our crt0.o objects).
noinst_LIBRARIES = libobjs.a
libobjs_a_SOURCES =

## These are roughly topologically sorted in order to make porting more
## streamlined.
FLAGS_TO_PASS = \
	"CC=$(CC)" \
	"CFLAGS=$(CFLAGS)" \
	"CFLAGS_FOR_TARGET=$(CFLAGS_FOR_TARGET)" \
	"CCASFLAGS=$(CCASFLAGS)" \
	"AR=$(AR)" \
	"RANLIB=$(RANLIB)" \
	"AR_FLAGS=$(AR_FLAGS)" \
	"MAKEINFO=$(MAKEINFO)" \
	"AS=$(AS)" \
	"LD=$(LD)" \
	"TARGET_CFLAGS=$(TARGET_CFLAGS)" \
	"exec_prefix=$(exec_prefix)" \
	"prefix=$(prefix)" \
	"tooldir=$(tooldir)" \
	"infodir=$(infodir)" \
	"libdir=$(libdir)" \
	"top_toollibdir=$(toollibdir)" \
	"INSTALL=$(INSTALL)" \
	"INSTALL_PROGRAM=$(INSTALL_PROGRAM)" \
	"INSTALL_DATA=$(INSTALL_DATA)" \
	"DESTDIR=$(DESTDIR)"

include $(top_srcdir)/../multilib.am

TEXINFO_TEX = ../texinfo/texinfo.tex

if HAVE_DOC
include doc/Makefile.inc
endif
if CONFIG_AARCH64
include aarch64/Makefile.inc
endif
if CONFIG_ARC
include arc/Makefile.inc
endif
if CONFIG_ARM
include arm/Makefile.inc
endif
if CONFIG_BFIN
include bfin/Makefile.inc
endif
if CONFIG_CSKY
include csky/Makefile.inc
endif
if CONFIG_D30V
include d30v/Makefile.inc
endif
if CONFIG_IQ2000
include iq2000/Makefile.inc
endif
if CONFIG_LIBSYSBASE
include libsysbase/Makefile.inc
endif
if CONFIG_LIBNOSYS
include libnosys/Makefile.inc
endif
if CONFIG_LM32
include lm32/Makefile.inc
endif
if CONFIG_NIOS2
include nios2/Makefile.inc
endif
if CONFIG_RISCV
include riscv/Makefile.inc
endif
if CONFIG_WINCE
include wince/Makefile.inc
endif
if CONFIG_XTENSA
include xtensa/Makefile.inc
endif
