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

#ifndef AARU_FSTESTER_SETTER_SRC_WIN32_ATTR_H_
#define AARU_FSTESTER_SETTER_SRC_WIN32_ATTR_H_

#include <windows.h>

#include "win32.h"

const char* compressedAttributeText = "This file is compressed.\n";

typedef struct
{
    char  filename[9];
    char  description[128];
    DWORD attr;
} win32_attr_tests_t;

#define KNOWN_WIN32_ATTRS 64

static const win32_attr_tests_t win32_attrs[KNOWN_WIN32_ATTRS] = {
    {"________", "File with no attributes", FILE_ATTRIBUTE_NORMAL},
    {"_______T", "Temporary file", FILE_ATTRIBUTE_TEMPORARY},
    {"______S_", "File with system attribute", FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_SYSTEM},
    {"______ST",
     "Temporary file with system attribute",
     FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"_____R__", "File with read-only attribute", FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_READONLY},
    {"_____R_T",
     "Temporary file with read-only attribute",
     FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_TEMPORARY},
    {"_____RS_",
     "File with system and read-only attributes",
     FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM},
    {"_____RST",
     "Temporary file with system and read-only attributes",
     FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"____O___", "File is available offline", FILE_ATTRIBUTE_OFFLINE},
    {"____O__T", "Temporary file that is available offline", FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_TEMPORARY},
    {"____O_S_",
     "File with system attribute that is available offline",
     FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_SYSTEM},
    {"____O_ST",
     "Temporary file with system attribute that is available offline",
     FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"____OR__",
     "File with read-only attribute that is available offline",
     FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY},
    {"____OR_T",
     "Temporary file with read-only attribute that is available offline",
     FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_TEMPORARY},
    {"____ORS_",
     "File with system and read-only attribute that is available offline",
     FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM},
    {"____ORST",
     "Temporary file with system and read-only attribute that is available offline",
     FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"___H____", "File with hidden attribute", FILE_ATTRIBUTE_HIDDEN},
    {"___H___T", "Temporary file with hidden attribute", FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_TEMPORARY},
    {"___H__S_", "File with system and hidden attributes", FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM},
    {"___H__ST",
     "Temporary file with system and hidden attributes",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"___H_R__", "File with system and read-only attributes", FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY},
    {"___H_R_T",
     "Temporary file with system and read-only attributes",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_TEMPORARY},
    {"___H_RS_",
     "File with hidden, system and read-only attributes",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM},
    {"___H_RST",
     "Temporary file with hidden, system and read-only attributes",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"___HO___",
     "File with hidden attribute that is available offline",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE},
    {"___HO__T",
     "Temporary file with hidden attribute that is available offline",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_TEMPORARY},
    {"___HO_S_",
     "File with hidden and system attributes that is available offline",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_SYSTEM},
    {"___HO_ST",
     "Temporary file with hidden and system attribute that is available offline",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"___HOR__",
     "File with hidden and read-only attributes that is available offline",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY},
    {"___HOR_T",
     "Temporary file with hidden and read-only attributes that is available offline",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_TEMPORARY},
    {"___HORS_",
     "File with hidden, read-only and system attributes that is available offline",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM},
    {"___HORST",
     "Temporary file with hidden, read-only and system attributes that is available offline",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM |
         FILE_ATTRIBUTE_TEMPORARY},
    {"__A_____", "File with archived attribute", FILE_ATTRIBUTE_ARCHIVE},
    {"__A____T", "Temporary file with archived attribute", FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_TEMPORARY},
    {"__A___S_", "File with system and archived attributes", FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_SYSTEM},
    {"__A___ST",
     "Temporary file with archived and system attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"__A__R__", "File with read-only and archived attributes", FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_READONLY},
    {"__A__R_T",
     "Temporary file with archive and read-only attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_TEMPORARY},
    {"__A__RS_",
     "File with read-only and archived attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM},
    {"__A__RST",
     "Temporary file with read-only and archived attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"__A_O___", "File with archived attribute is available offline", FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_OFFLINE},
    {"__A_O__T",
     "Temporary file with archive attribute that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_TEMPORARY},
    {"__A_O_S_",
     "File with system and archive attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_SYSTEM},
    {"__A_O_ST",
     "Temporary file with system and archive attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"__A_OR__",
     "File with read-only and archive attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY},
    {"__A_OR_T",
     "Temporary file with read-only and archive attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_TEMPORARY},
    {"__A_ORS_",
     "File with system, read-only and archive attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM},
    {"__A_ORST",
     "Temporary file with system, read-only and archive attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM |
         FILE_ATTRIBUTE_TEMPORARY},
    {"__AH____", "File with hidden and archived attributes", FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN},
    {"__AH___T",
     "Temporary file with archive and hidden attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_TEMPORARY},
    {"__AH__S_",
     "File with system, archive and hidden attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM},
    {"__AH__ST",
     "Temporary file with system, archive and hidden attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"__AH_R__",
     "File with read-only, hidden and archive attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY},
    {"__AH_R_T",
     "Temporary file with read-only, hidden and archive attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_TEMPORARY},
    {"__AH_RS_",
     "File with system, read-only, hidden and archive attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM},
    {"__AH_RST",
     "Temporary file with read-only, hidden and archive attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM |
         FILE_ATTRIBUTE_TEMPORARY},
    {"__AHO___",
     "File with hidden and archived attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE},
    {"__AHO__T",
     "Temporary file with archive and hidden attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_TEMPORARY},
    {"__AHO_S_",
     "File with system, archive and hidden attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_SYSTEM},
    {"__AHO_ST",
     "Temporary file with system, archive and hidden attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_SYSTEM |
         FILE_ATTRIBUTE_TEMPORARY},
    {"__AHOR__",
     "File with read-only, hidden and archive attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY},
    {"__AHOR_T",
     "Temporary file with read-only, hidden and archive attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY |
         FILE_ATTRIBUTE_TEMPORARY},
    {"__AHORS_",
     "File with system, read-only, hidden and archive attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY |
         FILE_ATTRIBUTE_SYSTEM},
    {"__AHORST",
     "File with all attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY |
         FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
};

static const win32_attr_tests_t encrypted_win32_attrs[KNOWN_WIN32_ATTRS] = {
    {"E_______", "Encrypted file with no attributes", FILE_ATTRIBUTE_NORMAL},
    {"E______T", "Encrypted temporary file file", FILE_ATTRIBUTE_TEMPORARY},
    {"E_____S_", "Encrypted file with system attribute", FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_SYSTEM},
    {"E_____ST",
     "Encrypted temporary file file with system attribute",
     FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"E____R__", "Encrypted file with read-only attribute", FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_READONLY},
    {"E____R_T",
     "Encrypted temporary file file with read-only attribute",
     FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_TEMPORARY},
    {"E____RS_",
     "Encrypted file with system and read-only attributes",
     FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM},
    {"E____RST",
     "Encrypted temporary file file with system and read-only attributes",
     FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"E___O___", "Encrypted file is available offline", FILE_ATTRIBUTE_OFFLINE},
    {"E___O__T",
     "Encrypted temporary file file that is available offline",
     FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_TEMPORARY},
    {"E___O_S_",
     "Encrypted file with system attribute that is available offline",
     FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_SYSTEM},
    {"E___O_ST",
     "Encrypted temporary file file with system attribute that is available offline",
     FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"E___OR__",
     "Encrypted file with read-only attribute that is available offline",
     FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY},
    {"E___OR_T",
     "Encrypted temporary file file with read-only attribute that is available offline",
     FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_TEMPORARY},
    {"E___ORS_",
     "Encrypted file with system and read-only attribute that is available offline",
     FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM},
    {"E___ORST",
     "Encrypted temporary file file with system and read-only attribute that is available offline",
     FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"E__H____", "Encrypted file with hidden attribute", FILE_ATTRIBUTE_HIDDEN},
    {"E__H___T",
     "Encrypted temporary file file with hidden attribute",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_TEMPORARY},
    {"E__H__S_", "Encrypted file with system and hidden attributes", FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM},
    {"E__H__ST",
     "Encrypted temporary file file with system and hidden attributes",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"E__H_R__",
     "Encrypted file with system and read-only attributes",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY},
    {"E__H_R_T",
     "Encrypted temporary file file with system and read-only attributes",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_TEMPORARY},
    {"E__H_RS_",
     "Encrypted file with hidden, system and read-only attributes",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM},
    {"E__H_RST",
     "Encrypted temporary file file with hidden, system and read-only attributes",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"E__HO___",
     "Encrypted file with hidden attribute that is available offline",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE},
    {"E__HO__T",
     "Encrypted temporary file file with hidden attribute that is available offline",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_TEMPORARY},
    {"E__HO_S_",
     "Encrypted file with hidden and system attributes that is available offline",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_SYSTEM},
    {"E__HO_ST",
     "Encrypted temporary file file with hidden and system attribute that is available offline",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"E__HOR__",
     "Encrypted file with hidden and read-only attributes that is available offline",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY},
    {"E__HOR_T",
     "Encrypted temporary file file with hidden and read-only attributes that is available offline",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_TEMPORARY},
    {"E__HORS_",
     "Encrypted file with hidden, read-only and system attributes that is available offline",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM},
    {"E__HORST",
     "Encrypted temporary file file with hidden, read-only and system attributes that is available offline",
     FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM |
         FILE_ATTRIBUTE_TEMPORARY},
    {"E_A_____", "Encrypted file with archived attribute", FILE_ATTRIBUTE_ARCHIVE},
    {"E_A____T",
     "Encrypted temporary file file with archived attribute",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_TEMPORARY},
    {"E_A___S_", "Encrypted file with system and archived attributes", FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_SYSTEM},
    {"E_A___ST",
     "Encrypted temporary file file with archived and system attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"E_A__R__",
     "Encrypted file with read-only and archived attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_READONLY},
    {"E_A__R_T",
     "Encrypted temporary file file with archive and read-only attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_TEMPORARY},
    {"E_A__RS_",
     "Encrypted file with read-only and archived attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM},
    {"E_A__RST",
     "Encrypted temporary file file with read-only and archived attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"E_A_O___",
     "Encrypted file with archived attribute is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_OFFLINE},
    {"E_A_O__T",
     "Encrypted temporary file file with archive attribute that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_TEMPORARY},
    {"E_A_O_S_",
     "Encrypted file with system and archive attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_SYSTEM},
    {"E_A_O_ST",
     "Encrypted temporary file file with system and archive attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"E_A_OR__",
     "Encrypted file with read-only and archive attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY},
    {"E_A_OR_T",
     "Encrypted temporary file file with read-only and archive attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_TEMPORARY},
    {"E_A_ORS_",
     "Encrypted file with system, read-only and archive attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM},
    {"E_A_ORST",
     "Encrypted temporary file file with system, read-only and archive attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM |
         FILE_ATTRIBUTE_TEMPORARY},
    {"E_AH____", "Encrypted file with hidden and archived attributes", FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN},
    {"E_AH___T",
     "Encrypted temporary file file with archive and hidden attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_TEMPORARY},
    {"E_AH__S_",
     "Encrypted file with system, archive and hidden attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM},
    {"E_AH__ST",
     "Encrypted temporary file file with system, archive and hidden attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
    {"E_AH_R__",
     "Encrypted file with read-only, hidden and archive attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY},
    {"E_AH_R_T",
     "Encrypted temporary file file with read-only, hidden and archive attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_TEMPORARY},
    {"E_AH_RS_",
     "Encrypted file with system, read-only, hidden and archive attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM},
    {"E_AH_RST",
     "Encrypted temporary file file with read-only, hidden and archive attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM |
         FILE_ATTRIBUTE_TEMPORARY},
    {"E_AHO___",
     "Encrypted file with hidden and archived attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE},
    {"E_AHO__T",
     "Encrypted temporary file file with archive and hidden attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_TEMPORARY},
    {"E_AHO_S_",
     "Encrypted file with system, archive and hidden attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_SYSTEM},
    {"E_AHO_ST",
     "Encrypted temporary file file with system, archive and hidden attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_SYSTEM |
         FILE_ATTRIBUTE_TEMPORARY},
    {"E_AHOR__",
     "Encrypted file with read-only, hidden and archive attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY},
    {"E_AHOR_T",
     "Encrypted temporary file file with read-only, hidden and archive attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY |
         FILE_ATTRIBUTE_TEMPORARY},
    {"E_AHORS_",
     "Encrypted file with system, read-only, hidden and archive attributes that is available offline",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY |
         FILE_ATTRIBUTE_SYSTEM},
    {"E_AHORST",
     "Encrypted file with all attributes",
     FILE_ATTRIBUTE_ARCHIVE | FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_OFFLINE | FILE_ATTRIBUTE_READONLY |
         FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_TEMPORARY},
};

BOOL(WINAPI* WinNtEncryptFileA)(LPCSTR);

#ifndef FSCTL_SET_COMPRESSION
#define FSCTL_SET_COMPRESSION 0x9C040
#endif

#ifndef COMPRESSION_FORMAT_DEFAULT
#define COMPRESSION_FORMAT_DEFAULT 1
#endif

#endif // AARU_FSTESTER_SETTER_SRC_WIN32_ATTR_H_
