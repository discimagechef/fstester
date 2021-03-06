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

#ifdef HAVE_SYS_STATVFS_H
#include <sys/statvfs.h>
#endif

#ifdef HAVE_SYS_MOUNT_H
#if defined(NEED_SYS_TYPES_H)
#include <sys/types.h>
#endif

#include <sys/mount.h>
#include <sys/param.h>
#endif

#if defined(__FreeBSD__)
#include <stdint.h>
#endif

#include "../../log.h"
#include "volume.h"

#if defined(__NetBSD__)
void NetBsdPrintStatvfsFlags(unsigned long flags)
{
    log_write("\tFlags:\n");

    if(flags & ST_RDONLY)
    {
        log_write("\t\tVolume is read-only.\n");
        flags -= ST_RDONLY;
    }

    if(flags & ST_NOSUID)
    {
        log_write("\t\tVolume ignores suid and sgid bits.\n");
        flags -= ST_NOSUID;
    }

    if(flags & ST_NODEV)
    {
        log_write("\t\tVolume disallows access to device special files.\n");
        flags -= ST_NODEV;
    }

    if(flags & ST_NOEXEC)
    {
        log_write("\t\tVolume disallows program execution.\n");
        flags -= ST_NOEXEC;
    }

    if(flags & ST_SYNCHRONOUS)
    {
        log_write("\t\tVolume writes are synced at once.\n");
        flags -= ST_SYNCHRONOUS;
    }

    if(flags & ST_NOATIME)
    {
        log_write("\t\tVolume does not update access times.\n");
        flags -= ST_NOATIME;
    }

    if(flags & ST_UNION)
    {
        log_write("\t\tVolume is a union.\n");
        flags -= ST_UNION;
    }

    if(flags & ST_ASYNC)
    {
        log_write("\t\tVolume is written asynchronously.\n");
        flags -= ST_ASYNC;
    }

    if(flags & ST_NOCOREDUMP)
    {
        log_write("\t\tVolume shall not have core dumps written.\n");
        flags -= ST_NOCOREDUMP;
    }

    if(flags & ST_RELATIME)
    {
        log_write("\t\tVolume only updates access time on changes.\n");
        flags -= ST_RELATIME;
    }

    if(flags & ST_IGNORE)
    {
        log_write("\t\tVolume does not appear in df.\n");
        flags -= ST_IGNORE;
    }

    if(flags & ST_SYMPERM)
    {
        log_write("\t\tVolume recognizes symbolic link permissions.\n");
        flags -= ST_SYMPERM;
    }

    if(flags & ST_NODEVMTIME)
    {
        log_write("\t\tVolume does not update modification times for devices.\n");
        flags -= ST_NODEVMTIME;
    }

    if(flags & ST_SOFTDEP)
    {
        log_write("\t\tVolume uses soft dependencies.\n");
        flags -= ST_SOFTDEP;
    }

    if(flags & ST_LOG)
    {
        log_write("\t\tVolume uses logging.\n");
        flags -= ST_LOG;
    }

    if(flags & ST_EXTATTR)
    {
        log_write("\t\tVolume has extended attributes enabled.\n");
        flags -= ST_EXTATTR;
    }

    if(flags & ST_EXRDONLY)
    {
        log_write("\t\tVolume is exported read-only.\n");
        flags -= ST_EXRDONLY;
    }

    if(flags & ST_EXPORTED)
    {
        log_write("\t\tVolume is exported.\n");
        flags -= ST_EXPORTED;
    }

    if(flags & ST_DEFEXPORTED)
    {
        log_write("\t\tVolume is exported to the world.\n");
        flags -= ST_DEFEXPORTED;
    }

    if(flags & ST_EXPORTANON)
    {
        log_write("\t\tVolume uses anon id.\n");
        flags -= ST_EXPORTANON;
    }

    if(flags & ST_EXKERB)
    {
        log_write("\t\tVolume is exported with Kerberos ID.\n");
        flags -= ST_EXKERB;
    }

    if(flags & ST_EXNORESPORT)
    {
        log_write("\t\tVolume export does not enforce reserved ports.\n");
        flags -= ST_EXNORESPORT;
    }

    if(flags & ST_EXPUBLIC)
    {
        log_write("\t\tVolume is exported publicly.\n");
        flags -= ST_EXPUBLIC;
    }

    if(flags & ST_LOCAL)
    {
        log_write("\t\tVolume is local.\n");
        flags -= ST_LOCAL;
    }

    if(flags & ST_QUOTA)
    {
        log_write("\t\tVolume has quotas enabled.\n");
        flags -= ST_QUOTA;
    }

    if(flags & ST_ROOTFS)
    {
        log_write("\t\tVolume is the root filesystem.\n");
        flags -= ST_ROOTFS;
    }

    if(flags & ST_DISCARD)
    {
        log_write("\t\tVolume is TRIMmed/DISCARDed.\n");
        flags -= ST_DISCARD;
    }

    if(flags & ST_AUTOMOUNTED)
    {
        log_write("\t\tVolume is automounted.\n");
        flags -= ST_AUTOMOUNTED;
    }

    if(flags) { log_write("\t\tRemaining flags: 0x%08lX\n", flags); }
}
#endif

#if defined(__FreeBSD__)
void FreeBsdPrintStatfsFlags(uint64_t flags)
{
    log_write("\tFlags:\n");

    if(flags & MNT_RDONLY)
    {
        log_write("\t\tVolume is read-only.\n");
        flags -= MNT_RDONLY;
    }

    if(flags & MNT_NOEXEC)
    {
        log_write("\t\tVolume disallows program execution.\n");
        flags -= MNT_NOEXEC;
    }

    if(flags & MNT_NOSUID)
    {
        log_write("\t\tVolume ignores suid and sgid bits.\n");
        flags -= MNT_NOSUID;
    }

    if(flags & MNT_SYNCHRONOUS)
    {
        log_write("\t\tVolume writes are synced at once.\n");
        flags -= MNT_SYNCHRONOUS;
    }

    if(flags & MNT_ASYNC)
    {
        log_write("\t\tVolume is written asynchronously.\n");
        flags -= MNT_ASYNC;
    }

    if(flags & MNT_SOFTDEP)
    {
        log_write("\t\tVolume uses soft dependencies.\n");
        flags -= MNT_SOFTDEP;
    }

    if(flags & MNT_GJOURNAL)
    {
        log_write("\t\tVolume uses journaling with gjournal.\n");
        flags -= MNT_GJOURNAL;
    }

    if(flags & MNT_SUIDDIR)
    {
        log_write("\t\tVolume handles SUID in directories in a special way.\n");
        flags -= MNT_SUIDDIR;
    }

    if(flags & MNT_UNION)
    {
        log_write("\t\tVolume is a union.\n");
        flags -= MNT_UNION;
    }

    if(flags & MNT_NOSYMFOLLOW)
    {
        log_write("\t\tVolume does not follow symbolic links.\n");
        flags -= MNT_NOSYMFOLLOW;
    }

    if(flags & MNT_NOCLUSTERR)
    {
        log_write("\t\tVolume has read clustering disabled.\n");
        flags -= MNT_NOCLUSTERR;
    }

    if(flags & MNT_NOCLUSTERW)
    {
        log_write("\t\tVolume has write clustering disabled.\n");
        flags -= MNT_NOCLUSTERW;
    }

    if(flags & MNT_MULTILABEL)
    {
        log_write("\t\tVolume supports mandatory access control for individual objects.\n");
        flags -= MNT_MULTILABEL;
    }

    if(flags & MNT_ACLS)
    {
        log_write("\t\tVolume supports Access Control Lists.\n");
        flags -= MNT_ACLS;
    }

    if(flags & MNT_LOCAL)
    {
        log_write("\t\tVolume is local.\n");
        flags -= MNT_LOCAL;
    }

    if(flags & MNT_QUOTA)
    {
        log_write("\t\tVolume has quotas enabled.\n");
        flags -= MNT_QUOTA;
    }

    if(flags & MNT_ROOTFS)
    {
        log_write("\t\tVolume is the root filesystem.\n");
        flags -= MNT_ROOTFS;
    }

    if(flags & MNT_EXRDONLY)
    {
        log_write("\t\tVolume is exported read-only.\n");
        flags -= MNT_EXRDONLY;
    }

    if(flags & MNT_NOATIME)
    {
        log_write("\t\tVolume does not update access times.\n");
        flags -= MNT_NOATIME;
    }

    if(flags & MNT_USER)
    {
        log_write("\t\tVolume has been mounted by a user.\n");
        flags -= MNT_USER;
    }

    if(flags & MNT_EXPORTED)
    {
        log_write("\t\tVolume is exported.\n");
        flags -= MNT_EXPORTED;
    }

    if(flags & MNT_DEFEXPORTED)
    {
        log_write("\t\tVolume is exported to the world.\n");
        flags -= MNT_DEFEXPORTED;
    }

    if(flags & MNT_EXPORTANON)
    {
        log_write("\t\tVolume uses anon id.\n");
        flags -= MNT_EXPORTANON;
    }

    if(flags & MNT_EXKERB)
    {
        log_write("\t\tVolume is exported with Kerberos ID.\n");
        flags -= MNT_EXKERB;
    }

    if(flags & MNT_EXPUBLIC)
    {
        log_write("\t\tVolume is exported publicly.\n");
        flags -= MNT_EXPUBLIC;
    }

    if(flags & MNT_IGNORE)
    {
        log_write("\t\tVolume does not appear in df.\n");
        flags -= MNT_IGNORE;
    }

    if(flags & MNT_AUTOMOUNTED)
    {
        log_write("\t\tVolume is automounted.\n");
        flags -= MNT_AUTOMOUNTED;
    }

    if(flags & MNT_NFS4ACLS)
    {
        log_write("\t\tVolume supports NFS4 access control lists.\n");
        flags -= MNT_NFS4ACLS;
    }

    if(flags & MNT_SUJ)
    {
        log_write("\t\tVolume uses journaled soft updates.\n");
        flags -= MNT_SUJ;
    }

    if(flags & MNT_UNTRUSTED)
    {
        log_write("\t\tVolume's metadata is untrusted.\n");
        flags -= MNT_UNTRUSTED;
    }

    if(flags & MNT_VERIFIED)
    {
        log_write("\t\tVolume is verified.\n");
        flags -= MNT_VERIFIED;
    }

    if(flags) { log_write("\t\tRemaining flags: 0x%08lX\n", flags); }
}
#endif

#if defined(__DragonFly__)
void DragonFlyPrintStatfsFlags(int flags)
{
    log_write("\tFlags:\n");

    if(flags & MNT_RDONLY)
    {
        log_write("\t\tVolume is read-only.\n");
        flags -= MNT_RDONLY;
    }

    if(flags & MNT_SYNCHRONOUS)
    {
        log_write("\t\tVolume writes are synced at once.\n");
        flags -= MNT_SYNCHRONOUS;
    }

    if(flags & MNT_NOEXEC)
    {
        log_write("\t\tVolume disallows program execution.\n");
        flags -= MNT_NOEXEC;
    }

    if(flags & MNT_NOSUID)
    {
        log_write("\t\tVolume ignores suid and sgid bits.\n");
        flags -= MNT_NOSUID;
    }

    if(flags & MNT_NODEV)
    {
        log_write("\t\tVolume disallows access to device special files.\n");
        flags -= MNT_NODEV;
    }

    if(flags & MNT_AUTOMOUNTED)
    {
        log_write("\t\tVolume is automounted.\n");
        flags -= MNT_AUTOMOUNTED;
    }

    if(flags & MNT_ASYNC)
    {
        log_write("\t\tVolume is written asynchronously.\n");
        flags -= MNT_ASYNC;
    }

    if(flags & MNT_SUIDDIR)
    {
        log_write("\t\tVolume handles SUID in directories in a special way.\n");
        flags -= MNT_SUIDDIR;
    }

    if(flags & MNT_SOFTDEP)
    {
        log_write("\t\tVolume uses soft dependencies.\n");
        flags -= MNT_SOFTDEP;
    }

    if(flags & MNT_NOSYMFOLLOW)
    {
        log_write("\t\tVolume does not follow symbolic links.\n");
        flags -= MNT_NOSYMFOLLOW;
    }

    if(flags & MNT_TRIM)
    {
        log_write("\t\tVolume is TRIMmed/DISCARDed.\n");
        flags -= MNT_TRIM;
    }

    if(flags & MNT_NOATIME)
    {
        log_write("\t\tVolume does not update access times.\n");
        flags -= MNT_NOATIME;
    }

    if(flags & MNT_NOCLUSTERR)
    {
        log_write("\t\tVolume has read clustering disabled.\n");
        flags -= MNT_NOCLUSTERR;
    }

    if(flags & MNT_NOCLUSTERW)
    {
        log_write("\t\tVolume has write clustering disabled.\n");
        flags -= MNT_NOCLUSTERW;
    }

    if(flags & MNT_EXRDONLY)
    {
        log_write("\t\tVolume is exported read-only.\n");
        flags -= MNT_EXRDONLY;
    }

    if(flags & MNT_EXPORTED)
    {
        log_write("\t\tVolume is exported.\n");
        flags -= MNT_EXPORTED;
    }

    if(flags & MNT_DEFEXPORTED)
    {
        log_write("\t\tVolume is exported to the world.\n");
        flags -= MNT_DEFEXPORTED;
    }

    if(flags & MNT_EXPORTANON)
    {
        log_write("\t\tVolume uses anon id.\n");
        flags -= MNT_EXPORTANON;
    }

    if(flags & MNT_EXKERB)
    {
        log_write("\t\tVolume is exported with Kerberos ID.\n");
        flags -= MNT_EXKERB;
    }

    if(flags & MNT_EXPUBLIC)
    {
        log_write("\t\tVolume is exported publicly.\n");
        flags -= MNT_EXPUBLIC;
    }

    if(flags & MNT_LOCAL)
    {
        log_write("\t\tVolume is local.\n");
        flags -= MNT_LOCAL;
    }

    if(flags & MNT_QUOTA)
    {
        log_write("\t\tVolume has quotas enabled.\n");
        flags -= MNT_QUOTA;
    }

    if(flags & MNT_ROOTFS)
    {
        log_write("\t\tVolume is the root filesystem.\n");
        flags -= MNT_ROOTFS;
    }

    if(flags & MNT_USER)
    {
        log_write("\t\tVolume has been mounted by a user.\n");
        flags -= MNT_USER;
    }

    if(flags & MNT_IGNORE)
    {
        log_write("\t\tVolume does not appear in df.\n");
        flags -= MNT_IGNORE;
    }

    if(flags) { log_write("\t\tRemaining flags: 0x%08lX\n", flags); }
}
#endif
