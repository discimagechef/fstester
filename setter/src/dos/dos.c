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

#if defined(__WATCOMC__)
#include <i86.h>
#include <stdlib.h>
#include <string.h>
#elif defined(__TURBOC__) || defined(_MSC_VER) || defined(__ZTC__)
#include <dos.h>
#include <io.h>
#include <stdlib.h>
#include <string.h>
#endif

#include "dosdefs.h"

unsigned int _dos_getdiskfree_ex(unsigned int drive, struct diskfree_ex_t* diskspace)
{
#if defined(__WATCOMC__) || defined(__TURBOC__) || defined(_MSC_VER) || defined(__ZTC__)
    char                  drivePath[4];
    union REGS            regs;
    struct SREGS          sregs;
    struct diskfree_ex_t* copy;

    copy = malloc(sizeof(struct diskfree_ex_t));

    if(!copy)
    {
        errno = ENOMEM;
        return -1;
    }

    memcpy(copy, diskspace, sizeof(struct diskfree_ex_t));

    drivePath[0] = (drive & 0xFF) + '@';
    drivePath[1] = ':';
    drivePath[2] = '\\';
    drivePath[3] = 0;

    regs.x.ax = 0x7303;
    sregs.ds  = FP_SEG(drivePath);
    regs.x.dx = FP_OFF(drivePath);
    sregs.es  = FP_SEG(copy);
    regs.x.di = FP_OFF(copy);
    regs.x.cx = sizeof(struct diskfree_ex_t);

    int86x(0x21, &regs, &regs, &sregs);

    if(regs.h.al == 0 && !regs.x.cflag)
    {
        free(copy);
        errno = ENOSYS;
        return -1;
    }
    else if(regs.x.cflag)
    {
        free(copy);
        errno     = EINVAL;
        _doserrno = regs.x.ax;
        return -1;
    }

    memcpy(diskspace, copy, sizeof(struct diskfree_ex_t));

    free(copy);
    errno     = 0;
    _doserrno = regs.x.ax;

    return 0;
#elif defined(__DJGPP__)
    return _djgpp_getdiskfree_ex(drive, diskspace);
#else
    errno = ENOSYS;
    return -1;
#endif
}

#ifdef OLD_BORLAND
unsigned _dos_write(int handle, void far* buf, unsigned len, unsigned* nwritten)
{
    int ret;

    ret = _write(handle, buf, len);

    if(ret == -1)
    {
        errno = EBADF;
        return _doserrno;
    }

    *nwritten = ret;

    return 0;
}

unsigned _dos_creat(const char* path, int attrib, int* handlep)
{
    int ret;

    ret = _creat(path, attrib);

    if(ret == -1)
    {
        *handlep = 0;
        return _doserrno;
    }

    *handlep = ret;

    return 0;
}

unsigned _dos_creatnew(const char* path, int attrib, int* handlep)
{
    int ret;

    ret = creatnew(path, attrib);

    if(ret == -1)
    {
        *handlep = 0;
        return _doserrno;
    }

    *handlep = ret;

    return 0;
}
#endif
