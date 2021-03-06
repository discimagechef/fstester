# /****************************************************************************
# Aaru Data Preservation Suite
# -----------------------------------------------------------------------------
#
#     Author(s)      : Natalia Portillo
#
# --[ License ] ---------------------------------------------------------------
#      This program is free software: you can redistribute it and/or modify
#      it under the terms of the GNU General Public License as
#      published by the Free Software Foundation, either version 3 of the
#      License, or (at your option) any later version.
#
#      This program is distributed in the hope that it will be useful,
#      but WITHOUT ANY WARRANTY; without even the implied warranty of
#      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#      GNU General Public License for more details.
#
#      You should have received a copy of the GNU General Public License
#      along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# -----------------------------------------------------------------------------
# Copyright (C) 2011-2021 Natalia Portillo
# *****************************************************************************/

# Directory with main and log source files
MAINDIR  = ../../../src

# Directory with main platform source files
SRCDIR = ${MAINDIR}/unix

# Directory with subplatform source files
PLATDIR =${SRCDIR}/bsd

# Object files
OBJS	= ${MAINDIR}/log.o ${MAINDIR}/main.o ${SRCDIR}/attr.o ${SRCDIR}/dirdepth.o \
		  ${SRCDIR}/files.o ${SRCDIR}/links.o ${SRCDIR}/perms.o ${SRCDIR}/rsrcfork.o \
		  ${SRCDIR}/time.o ${SRCDIR}/volume.o ${SRCDIR}/xattr.o ${SRCDIR}/deleted.o \
		  ${SRCDIR}/filename.o ${SRCDIR}/frag.o ${SRCDIR}/os.o ${SRCDIR}/sparse.o \
		  ${PLATDIR}/attr.o ${PLATDIR}/volume.o ${PLATDIR}/xattr.o

# Source files
SOURCE	= ${MAINDIR}/log.c ${MAINDIR}/main.c ${SRCDIR}/attr.c ${SRCDIR}/dirdepth.c \
		  ${SRCDIR}/files.c ${SRCDIR}/links.c ${SRCDIR}/perms.c ${SRCDIR}/rsrcfork.c \
		  ${SRCDIR}/time.c ${SRCDIR}/volume.c ${SRCDIR}/xattr.c ${SRCDIR}/deleted.c \
		  ${SRCDIR}/filename.c ${SRCDIR}/frag.c ${SRCDIR}/os.c ${SRCDIR}/sparse.c \
		  ${PLATDIR}/attr.c ${PLATDIR}/volume.c ${PLATDIR}/xattr.c

# Header files
HEADER	= ${MAINDIR}/log.h ${MAINDIR}/main.h ${SRCDIR}/perms.h ${SRCDIR}/time.h \
		  ${SRCDIR}/volume.h ${PLATDIR}/attr.h ${PLATDIR}/bsd.h ${PLATDIR}/volume.h \
		  ${PLATDIR}/xattr.h

# Outfile
OUT	= fssetter

# Linker flags
LFLAGS	=

# Compiler flags. This needs the definitions on how to find statfs.h as there is no autodetection
# BSD 2.11 defines statfs to be in sys/mount.h
CFLAGS  = -DHAVE_SYS_MOUNT_H -DHAVE_STATFS_TYPENAME -DHAVE_STATFS_TYPE -DUSE_STATFS_NAMEMAX -DUSE_STATFS_FLAGS

all: fssetter

fssetter: ${OBJS}
	${CC} ${LFLAGS} ${OBJS} -o fssetter

.c.o:
	${CC} ${CFLAGS} -c ${.IMPSRC} -o ${.TARGET}

# clean house
clean:
	rm -f ${OBJS} ${OUT}
