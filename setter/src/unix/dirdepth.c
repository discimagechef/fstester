/****************************************************************************
Aaru Data Preservation Suite
-----------------------------------------------------------------------------

Filename       : dirdepth.c
Author(s)      : Natalia Portillo

--[ Description ] -----------------------------------------------------------

Contains common implementations for UNIX family and compatibles

--[ License ] ---------------------------------------------------------------
     This program is free software: you can redistribute it and/or modify
     it under the terms of the GNU General Public License as
     published by the Free Software Foundation, either version 3 of the
     License, or (at your option) any later version.

     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.

     You should have received a copy of the GNU General Public License
     along with this program.  If not, see <http://www.gnu.org/licenses/>.

-----------------------------------------------------------------------------
Copyright (C) 2011-2021 Natalia Portillo
*****************************************************************************/

#if defined(unix) || defined(UNIX) || defined(__unix) || defined(__unix__) || defined(__UNIX__)

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../include/defs.h"

void DirectoryDepth(const char* path)
{
    int  ret;
    char filename[9];
    long pos = 2;

    ret = chdir(path);

    if(ret)
    {
        printf("Error %d changing to specified path.\n", errno);
        return;
    }

    ret = mkdir("DEPTH", 0755);

    if(ret)
    {
        printf("Error %d creating working directory.\n", errno);
        return;
    }

    ret = chdir("DEPTH");

    if(ret)
    {
        printf("Error %d changing to working directory.\n", errno);
        return;
    }

    printf("Creating deepest directory tree.\n");

    while(!ret)
    {
        memset(&filename, 0, 9);
        sprintf(&filename, "%08ld", pos);
        ret = mkdir(filename, 0755);

        if(!ret) ret = chdir(filename);

        pos++;

        // This can continue until the disk fills, the kernel crashes, or some other nasty success
        if(pos >= 1000) break;
    }

    printf("\tCreated %ld levels of directory hierarchy\n", pos);
}

#endif
