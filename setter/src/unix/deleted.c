/****************************************************************************
Aaru Data Preservation Suite
-----------------------------------------------------------------------------

    Author(s)      : Natalia Portillo

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

#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../include/defs.h"
#include "../log.h"

void DeleteFiles(const char* path)
{
    char  filename[9];
    long  pos;
    FILE* h;
    int   ret;

    ret = chdir(path);

    if(ret)
    {
        log_write("Error %d changing to specified path.\n", errno);
        return;
    }

    ret = mkdir("DELETED", 0755);

    if(ret)
    {
        log_write("Error %d creating working directory.\n", errno);
        return;
    }

    ret = chdir("DELETED");

    if(ret)
    {
        log_write("Error %d changing to working directory.\n", errno);
        return;
    }

    log_write("Creating and deleting files.\n");

    for(pos = 0; pos < 64; pos++)
    {
        memset(filename, 0, 9);
        sprintf(filename, "%lX", pos);
        h = fopen(filename, "w+");
        if(h == NULL) { break; }

        fclose(h);
        unlink(filename);
    }
}
