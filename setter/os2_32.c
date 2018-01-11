/****************************************************************************
The Disc Image Chef
-----------------------------------------------------------------------------

Filename       : os2_32.c
Author(s)      : Natalia Portillo

Component      : fstester.setter.os2

--[ Description ] -----------------------------------------------------------

Contains 32-bit OS/2 code

--[ License ] ---------------------------------------------------------------
     This program is free software: you can redistribute it and/or modify
     it under the terms of the GNU General Public License as
     published by the Free Software Foundation, either version 3 of the
     License, or (at your option) any later version.

     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warraty of
     MERCHANTIBILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.

     You should have received a copy of the GNU General Public License
     along with this program.  If not, see <http://www.gnu.org/licenses/>.

-----------------------------------------------------------------------------
Copyright (C) 2011-2018 Natalia Portillo
*****************************************************************************/

#if (defined(__I386__) || defined (__i386__) || defined (__THW_INTEL) || defined (_M_IX86)) && (defined(__OS2__) || defined (__os2__))

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define INCL_DOSMISC
#define INCL_DOSFILEMGR
#include <os2.h>

#include "defs.h"
#include "os2_16.h"
#include "dosos2.h"
#include "consts.h"

void GetOsInfo()
{
    // TODO: Implement
}

void GetVolumeInfo(const char *path, size_t *clusterSize)
{
    // TODO: Implement
}

void FileAttributes(const char *path)
{
    // TODO: Implement
}

void FilePermissions(const char *path)
{
   /* Do nothing, not supported by target operating system */
}

void ExtendedAttributes(const char *path)
{
   /* Do nothing, not supported by target operating system */
}

void ResourceFork(const char *path)
{
   /* Do nothing, not supported by target operating system */
}

void Filenames(const char *path)
{
    // TODO: Implement
}

#define DATETIME_FORMAT "This file is dated %04d/%02d/%02d %02d:%02d:%02d for %s\n"

void Timestamps(const char *path)
{
    // TODO: Implement
}

void DirectoryDepth(const char *path)
{
    // TODO: Implement
}

void Fragmentation(const char *path, size_t clusterSize)
{
    // TODO: Implement
}

void Sparse(const char *path)
{
   /* Do nothing, not supported by target operating system */
}

void MillionFiles(const char *path)
{
    // TODO: Implement
}

void DeleteFiles(const char *path)
{
    // TODO: Implement
}
#endif
