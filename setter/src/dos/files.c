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

#include <dos.h>
#include <stdio.h>
#include <string.h>

#if defined(__WATCOMC__)
#include <direct.h>
#elif defined(__DJGPP__)
#include <unistd.h>
#endif

#include "../include/defs.h"
#include "../log.h"
#include "dosdefs.h"

void MillionFiles(const char* path)
{
    char         driveNo = path[0] - '@';
    unsigned int rc;
    char         filename[9];
    unsigned int pos;
    int          handle;
    unsigned     total;

    if(driveNo > 32) driveNo -= 32;

    _dos_setdrive(driveNo, &total);
    chdir("\\");

    rc = __dos_mkdir("MILLION");

    if(rc)
    {
        log_write("Cannot create working directory.\n");
        return;
    }

    chdir("MILLION");

    log_write("Creating lots of files.\n");

    for(pos = 0; pos < 1000; pos++)
    {
        memset(filename, 0, 9);
        sprintf(filename, "%08d", pos);
        rc = _dos_creatnew(filename, 0, &handle);
        if(rc) break;

        _dos_close(handle);
    }

    log_write("\tCreated %d files\n", pos);
}
