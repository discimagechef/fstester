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
#include <mint/ostruct.h>
#include <stdio.h>
#include <string.h>

#include "../include/defs.h"
#include "../log.h"
#include "tostime.h"

void Timestamps(const char* path)
{
    char         driveNo = path[0] - 'A';
    unsigned int rc, wRc = 0, cRc = 0, tRc = 0;
    int          handle;
    char         message[300];
    int          i;
    _DOSTIME     timestamp;

    if(driveNo >= 32) driveNo -= 32;

    Dsetdrv(driveNo);
    Dsetpath("\\");

    rc = Dcreate("TIMES");

    if(rc != E_OK)
    {
        log_write("Cannot create working directory.\n");
        return;
    }

    Dsetpath("TIMES");

    log_write("Creating timestamped files.\n");

    for(i = 0; i < KNOWN_ATARI_TIMES; i++)
    {
        rc = Fcreate(atari_times[i].filename, 0);

        if(rc > 0)
        {
            memset(message, 0, 300);
            sprintf(message,
                    DATETIME_FORMAT,
                    YEAR(atari_times[i].date),
                    MONTH(atari_times[i].date),
                    DAY(atari_times[i].date),
                    HOUR(atari_times[i].time),
                    MINUTE(atari_times[i].time),
                    SECOND(atari_times[i].time),
                    atari_times[i].definition);

            timestamp.date = atari_times[i].date;
            timestamp.time = atari_times[i].time;

            wRc = Fwrite(handle, strlen(message), message);
            tRc = Fdatime(&timestamp, handle, 1);
            cRc = Fclose(handle);
        }

        log_write("\tFile name = \"%s\", rc = %d, wRc = %d, cRc = %d, tRc = %d\n",
                  atari_times[i].filename,
                  rc,
                  wRc,
                  cRc,
                  tRc);
    }
}
