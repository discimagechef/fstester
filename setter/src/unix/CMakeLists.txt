# /****************************************************************************
# Aaru Data Preservation Suite
# -----------------------------------------------------------------------------
#
# Author(s)      : Natalia Portillo
#
# --[ License ] ---------------------------------------------------------------
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# -----------------------------------------------------------------------------
# Copyright (C) 2011-2021 Natalia Portillo
# *****************************************************************************/

if(NOT ${CMAKE_SYSTEM_NAME} MATCHES "Linux|Darwin" AND NOT ${CMAKE_SYSTEM_NAME} MATCHES "^(([^k].*)?BSD|DragonFly)$")
    return()
endif()

include(CheckIncludeFile)
include(CheckSymbolExists)
include(CheckStructHasMember)

CHECK_SYMBOL_EXISTS(statfs "sys/statfs.h" HAVE_SYS_STATFS)
CHECK_SYMBOL_EXISTS(statfs "sys/mount.h" HAVE_SYS_MOUNT)
CHECK_SYMBOL_EXISTS(statvfs "sys/statvfs.h" HAVE_SYS_STATVFS)
CHECK_SYMBOL_EXISTS(statfs "sys/vfs.h" HAVE_SYS_VFS)

if(${CMAKE_SYSTEM_NAME} MATCHES "OpenBSD")
    message("-- Forcing statfs in sys/mount.h due to OpenBSD")
    add_sub_definitions(HAVE_SYS_MOUNT_H)
    add_sub_definitions(NEED_SYS_TYPES_H)
    add_sub_definitions(USE_STATFS_FLAGS)
    set(HAVE_STATFS_TYPENAME 1)
    set(HAVE_STATFS_NAMEMAX 1)
    # Old Linux
elseif(HAVE_SYS_VFS)
    message("-- Found statfs in sys/vfs.h")
    add_sub_definitions(HAVE_SYS_VFS_H)
    CHECK_STRUCT_HAS_MEMBER("struct statfs" "f_namelen" "sys/vfs.h" HAVE_STATFS_NAMELEN)
    CHECK_STRUCT_HAS_MEMBER("struct statfs" "f_fstypename" "sys/vfs.h" HAVE_STATFS_TYPENAME)
    CHECK_STRUCT_HAS_MEMBER("struct statfs" "f_namemax" "sys/vfs.h" HAVE_STATFS_NAMEMAX)
    CHECK_STRUCT_HAS_MEMBER("struct statfs" "f_type" "sys/vfs.h" HAVE_STATFS_TYPE)
    CHECK_STRUCT_HAS_MEMBER("struct statfs" "f_flags" "sys/vfs.h" HAVE_STATFS_FLAGS)
    # Linux and FreeBSD
elseif(HAVE_SYS_STATFS)
    message("-- Found statfs in sys/statfs.h")
    add_sub_definitions(HAVE_SYS_STATFS_H)
    CHECK_STRUCT_HAS_MEMBER("struct statfs" "f_namelen" "sys/statfs.h" HAVE_STATFS_NAMELEN)
    CHECK_STRUCT_HAS_MEMBER("struct statfs" "f_fstypename" "sys/statfs.h" HAVE_STATFS_TYPENAME)
    CHECK_STRUCT_HAS_MEMBER("struct statfs" "f_namemax" "sys/statfs.h" HAVE_STATFS_NAMEMAX)
    CHECK_STRUCT_HAS_MEMBER("struct statfs" "f_type" "sys/statfs.h" HAVE_STATFS_TYPE)
    CHECK_STRUCT_HAS_MEMBER("struct statfs" "f_flags" "sys/statfs.h" HAVE_STATFS_FLAGS)
elseif(HAVE_SYS_MOUNT) # Darwin and most other BSDs
    message("-- Found statfs in sys/mount.h")
    add_sub_definitions(HAVE_SYS_MOUNT_H)
    CHECK_STRUCT_HAS_MEMBER("struct statfs" "f_namelen" "sys/mount.h" HAVE_STATFS_NAMELEN)
    CHECK_STRUCT_HAS_MEMBER("struct statfs" "f_fstypename" "sys/mount.h" HAVE_STATFS_TYPENAME)
    if(NOT ${CMAKE_SYSTEM_NAME} MATCHES "Darwin") # It's giving false positives sometimes
        CHECK_STRUCT_HAS_MEMBER("struct statfs" "f_namemax" "sys/mount.h" HAVE_STATFS_NAMEMAX)
    endif()
    CHECK_STRUCT_HAS_MEMBER("struct statfs" "f_type" "sys/mount.h" HAVE_STATFS_TYPE)
    CHECK_STRUCT_HAS_MEMBER("struct statfs" "f_flags" "sys/mount.h" HAVE_STATFS_FLAGS)
elseif(HAVE_SYS_STATVFS) # NetBSD >= 3.0
    message("-- Found statvfs in sys/statvfs.h")
    add_sub_definitions(HAVE_SYS_STATVFS_H)
    CHECK_STRUCT_HAS_MEMBER("struct statvfs" "f_namemax" "sys/statvfs.h" HAVE_STATFS_NAMEMAX)
    CHECK_STRUCT_HAS_MEMBER("struct statvfs" "f_fstypename" "sys/statvfs.h" HAVE_STATFS_TYPENAME)
    CHECK_STRUCT_HAS_MEMBER("struct statvfs" "f_type" "sys/statvfs.h" HAVE_STATFS_TYPE)
    CHECK_STRUCT_HAS_MEMBER("struct statvfs" "f_flags" "sys/statvfs.h" HAVE_STATFS_FLAGS)
endif()

if(HAVE_STATFS_NAMELEN)
    message("-- statfs has f_namelen member")
    add_sub_definitions(USE_STATFS_NAMELEN)
endif()

if(HAVE_STATFS_TYPENAME)
    message("-- statfs has f_fstypename member")
    add_sub_definitions(USE_STATFS_FTYPENAME)
endif()

if(HAVE_STATFS_NAMEMAX)
    message("-- statfs has f_namemax member")
    add_sub_definitions(USE_STATFS_NAMEMAX)
endif()

if(HAVE_STATFS_TYPE)
    message("-- statfs has f_type member")
    add_sub_definitions(USE_STATFS_TYPE)
endif()

if(HAVE_STATFS_FLAGS)
    message("-- statfs has f_flags member")
    add_sub_definitions(USE_STATFS_FLAGS)
endif()

add_subdirectory(darwin)
add_subdirectory(linux)
add_subdirectory(bsd)

# Needed to pass upper level definitions back down
add_sub_definitions()

# Even if empty it needs to be present
add_sub_libraries()

add_sources(attr.c deleted.c dirdepth.c filename.c files.c frag.c links.c os.c perms.c rsrcfork.c sparse.c time.c volume.c xattr.c time.h)
