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

#define INCL_DOSMISC
#define INCL_DOSFILEMGR

#include <os2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xattr.h"

#include "../../include/consts.h"
#include "../../include/defs.h"
#include "../../log.h"
#include "../os2defs.h"

void ExtendedAttributes(const char* path)
{
    char   drivePath[4];
    USHORT rc = 0, wRc = 0, cRc = 0;
    USHORT actionTaken = 0;
    HFILE  handle;
    char   message[300];
    EAOP   eap;
    USHORT driveNo = path[0] - '@';

    if(driveNo > 32) driveNo -= 32;

    rc = DosSelectDisk(driveNo);

    if(rc)
    {
        log_write("Cannot change to specified drive, not continuing.\n");
        return;
    }

    drivePath[0] = path[0];
    drivePath[1] = ':';
    drivePath[2] = '\\';
    drivePath[3] = 0;

    rc = DosChDir(drivePath, 0);

    if(rc)
    {
        log_write("Cannot change to specified path, not continuing.\n");
        return;
    }

    rc = DosMkDir("XATTRS", 0);

    if(rc)
    {
        log_write("Cannot create working directory.\n");
        return;
    }

    rc = DosChDir("XATTRS", 0);

    log_write("Creating files with extended attributes.\n");

    rc = DosOpen("COMMENTS",
                 &handle,
                 &actionTaken,
                 0,
                 FILE_NORMAL,
                 OPEN_ACTION_CREATE_IF_NEW | OPEN_ACTION_REPLACE_IF_EXISTS,
                 OPEN_FLAGS_NOINHERIT | OPEN_SHARE_DENYNONE | OPEN_ACCESS_READWRITE,
                 0);

    if(!rc)
    {
        eap.fpGEAList = NULL;
        eap.fpFEAList = (PFEALIST)&CommentsEA;
        eap.oError    = 0;
        memset(message, 0, 300);
        sprintf(message, "This files has an optional .COMMENTS EA\n");
        wRc = DosWrite(handle, message, strlen(message), &actionTaken);
        rc  = DosSetFileInfo(handle, 2, (PBYTE)&eap, sizeof(EAOP));
        cRc = DosClose(handle);
    }

    log_write("\tFile with comments = \"%s\", rc = %d, wRc = %d, cRc = %d\n", "COMMENTS", rc, wRc, cRc);

    rc = DosOpen("COMMENTS.CRT",
                 &handle,
                 &actionTaken,
                 0,
                 FILE_NORMAL,
                 OPEN_ACTION_CREATE_IF_NEW | OPEN_ACTION_REPLACE_IF_EXISTS,
                 OPEN_FLAGS_NOINHERIT | OPEN_SHARE_DENYNONE | OPEN_ACCESS_READWRITE,
                 0);

    if(!rc)
    {
        eap.fpGEAList = NULL;
        eap.fpFEAList = (PFEALIST)&CommentsEACritical;
        eap.oError    = 0;
        memset(message, 0, 300);
        sprintf(message, "This files has a critical .COMMENTS EA\n");
        wRc = DosWrite(handle, message, strlen(message), &actionTaken);
        rc  = DosSetFileInfo(handle, 2, (PBYTE)&eap, sizeof(EAOP));
        cRc = DosClose(handle);
    }

    log_write("\tFile with comments = \"%s\", rc = %d, wRc = %d, cRc = %d\n", "COMMENTS.CRT", rc, wRc, cRc);

    rc = DosOpen("ICON",
                 &handle,
                 &actionTaken,
                 0,
                 FILE_NORMAL,
                 OPEN_ACTION_CREATE_IF_NEW | OPEN_ACTION_REPLACE_IF_EXISTS,
                 OPEN_FLAGS_NOINHERIT | OPEN_SHARE_DENYNONE | OPEN_ACCESS_READWRITE,
                 0);

    if(!rc)
    {
        eap.fpGEAList = NULL;
        eap.fpFEAList = (PFEALIST)&IconEA;
        eap.oError    = 0;
        memset(message, 0, 300);
        sprintf(message, "This files has an optional .ICON EA\n");
        wRc = DosWrite(handle, message, strlen(message), &actionTaken);
        rc  = DosSetFileInfo(handle, 2, (PBYTE)&eap, sizeof(EAOP));
        cRc = DosClose(handle);
    }

    log_write("\tFile with icon = \"%s\", rc = %d, wRc = %d, cRc = %d\n", "ICON", rc, wRc, cRc);
}
