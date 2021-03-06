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

#include <stdio.h>
#include <string.h>

#include "../include/defs.h"

void MillionFiles(const char* path)
{
    char  filename[16];
    int   pos;
    FILE* h;
    int   ret;

    printf("\nPlease insert the \"FILES\" disk.\n");
    printf("Press Y to continue,\n");
    printf("any other key exits.\n");
    ret = getchar();

    if(ret != 'Y' && ret != 'y') return;

    printf("Creating lots of files.\n");

    for(pos = 0; pos < 300; pos++)
    {
        memset(filename, 0, 16);
        sprintf(filename, "%08d", pos);

        h = fopen(filename, "w");
        if(h == NULL) break;

        // Needed or some systems do not create empty files at all.
        fprintf(h, "%s\n", filename);
        fclose(h);
    }

    printf("\tCreated %d files\n\n", pos);
}
