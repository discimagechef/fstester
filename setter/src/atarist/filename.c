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

#include <eti.h>
#include <mint/osbind.h>
#include <stdio.h>
#include <string.h>

#include "../include/consts.h"
#include "../include/defs.h"
#include "../log.h"

void Filenames(const char* path)
{
    char         driveNo = path[0] - 'A';
    unsigned int rc, wRc = 0, cRc = 0;
    int          handle;
    char         message[300];
    int          pos;

    if(driveNo >= 32) driveNo -= 32;

    Dsetdrv(driveNo);
    Dsetpath("\\");

    rc = Dcreate("FILENAME");

    if(rc != E_OK)
    {
        log_write("Cannot create working directory.\n");
        return;
    }

    Dsetpath("FILENAME");

    log_write("Creating files with different filenames.\n");

    for(pos = 0; filenames[pos]; pos++)
    {
        handle = Fcreate((char*)filenames[pos], 0);

        if(handle > 0)
        {
            memset(message, 0, 300);
            sprintf(message, FILENAME_FORMAT, filenames[pos]);
            wRc = Fwrite(handle, strlen(message), message);
            cRc = Fclose(handle);
        }

        log_write("\tFile name = \"%s\", rc = %d, wRc = %d, cRc = %d\n", filenames[pos], rc, wRc, cRc);
    }
}
