/****************************************************************************
Aaru Data Preservation Suite
-----------------------------------------------------------------------------

Filename       : win32.h
Author(s)      : Natalia Portillo

Component      : fstester.setter.win32

--[ Description ] -----------------------------------------------------------

Contains 32-bit and 64-bit Windows declarations

--[ License ] ---------------------------------------------------------------
     This program is free software: you can redistribute it and/or modify
     it under the terms of the GNU General Public License as
     published by the Free Software Foundation, either version 3 of the
     License, or (at your option) any later version.

     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warraty of
     MERCHANTIBILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.

     You should have received a copy of the GNU General Public License
     along with this program.  If not, see <http://www.gnu.org/licenses/>.

-----------------------------------------------------------------------------
Copyright (C) 2011-2020 Natalia Portillo
*****************************************************************************/

#if defined(__WINDOWS__) || defined(__TOS_WIN__) || defined(__WIN32__) || defined(_WIN64) || defined(_WIN32) ||        \
    defined(__NT__)

#ifndef AARU_FSTESTER_SETTER_WIN32_H
#define AARU_FSTESTER_SETTER_WIN32_H

#include <windows.h>

#ifndef VER_PLATFORM_WIN32s
#define VER_PLATFORM_WIN32s 0
#endif

#ifndef VER_PLATFORM_WIN32_WINDOWS
#define VER_PLATFORM_WIN32_WINDOWS 1
#endif

#ifndef VER_PLATFORM_WIN32_NT
#define VER_PLATFORM_WIN32_NT 2
#endif

#ifndef FILE_CASE_PRESERVED_NAMES
#define FILE_CASE_PRESERVED_NAMES 0x00000002
#endif

#ifndef FILE_CASE_SENSITIVE_SEARCH
#define FILE_CASE_SENSITIVE_SEARCH 0x00000001
#endif

#ifndef FILE_DAX_VOLUME
#define FILE_DAX_VOLUME 0x20000000
#endif

#ifndef FILE_FILE_COMPRESSION
#define FILE_FILE_COMPRESSION 0x00000010
#endif

#ifndef FILE_NAMED_STREAMS
#define FILE_NAMED_STREAMS 0x00040000
#endif

#ifndef FILE_PERSISTENT_ACLS
#define FILE_PERSISTENT_ACLS 0x00000008
#endif

#ifndef FILE_READ_ONLY_VOLUME
#define FILE_READ_ONLY_VOLUME 0x00080000
#endif

#ifndef FILE_SEQUENTIAL_WRITE_ONCE
#define FILE_SEQUENTIAL_WRITE_ONCE 0x00100000
#endif

#ifndef FILE_SUPPORTS_ENCRYPTION
#define FILE_SUPPORTS_ENCRYPTION 0x00020000
#endif

#ifndef FILE_SUPPORTS_EXTENDED_ATTRIBUTES
#define FILE_SUPPORTS_EXTENDED_ATTRIBUTES 0x00800000
#endif

#ifndef FILE_SUPPORTS_HARD_LINKS
#define FILE_SUPPORTS_HARD_LINKS 0x00400000
#endif

#ifndef FILE_SUPPORTS_OBJECT_IDS
#define FILE_SUPPORTS_OBJECT_IDS 0x00010000
#endif

#ifndef FILE_SUPPORTS_OPEN_BY_FILE_ID
#define FILE_SUPPORTS_OPEN_BY_FILE_ID 0x01000000
#endif

#ifndef FILE_SUPPORTS_REPARSE_POINTS
#define FILE_SUPPORTS_REPARSE_POINTS 0x00000080
#endif

#ifndef FILE_SUPPORTS_SPARSE_FILES
#define FILE_SUPPORTS_SPARSE_FILES 0x00000040
#endif

#ifndef FILE_SUPPORTS_TRANSACTIONS
#define FILE_SUPPORTS_TRANSACTIONS 0x00200000
#endif

#ifndef FILE_SUPPORTS_USN_JOURNAL
#define FILE_SUPPORTS_USN_JOURNAL 0x02000000
#endif

#ifndef FILE_UNICODE_ON_DISK
#define FILE_UNICODE_ON_DISK 0x00000004
#endif

#ifndef FILE_VOLUME_IS_COMPRESSED
#define FILE_VOLUME_IS_COMPRESSED 0x00008000
#endif

#ifndef FILE_VOLUME_QUOTAS
#define FILE_VOLUME_QUOTAS 0x00000020
#endif

#ifndef FILE_ATTRIBUTE_ARCHIVE
#define FILE_ATTRIBUTE_ARCHIVE 0x00000020
#endif

#ifndef FILE_ATTRIBUTE_ENCRYPTED
#define FILE_ATTRIBUTE_ENCRYPTED 0x00004000
#endif

#ifndef FILE_ATTRIBUTE_HIDDEN
#define FILE_ATTRIBUTE_HIDDEN 0x00000002
#endif

#ifndef FILE_ATTRIBUTE_NORMAL
#define FILE_ATTRIBUTE_NORMAL 0x00000080
#endif

#ifndef FILE_ATTRIBUTE_OFFLINE
#define FILE_ATTRIBUTE_OFFLINE 0x00001000
#endif

#ifndef FILE_ATTRIBUTE_READONLY
#define FILE_ATTRIBUTE_READONLY 0x00000001
#endif

#ifndef FILE_ATTRIBUTE_SYSTEM
#define FILE_ATTRIBUTE_SYSTEM 0x00000004
#endif

#ifndef FILE_ATTRIBUTE_TEMPORARY
#define FILE_ATTRIBUTE_TEMPORARY 0x00000100
#endif

#ifndef FILE_ATTRIBUTE_COMPRESSED
#define FILE_ATTRIBUTE_COMPRESSED 0x00000800
#endif

#ifndef FSCTL_SET_COMPRESSION
#define FSCTL_SET_COMPRESSION 0x9C040
#endif

#ifndef FILE_RETURNS_CLEANUP_RESULT_INFO
#define FILE_RETURNS_CLEANUP_RESULT_INFO 0x00000200
#endif

#ifndef FILE_SUPPORTS_POSIX_UNLINK_RENAME
#define FILE_SUPPORTS_POSIX_UNLINK_RENAME 0x00000400
#endif

#ifndef COMPRESSION_FORMAT_DEFAULT
#define COMPRESSION_FORMAT_DEFAULT 1
#endif

const char *archivedAttributeText   = "This file has the archived attribute set.\n";
const char *encryptedAttributeText  = "This file is encrypted.\n";
const char *hiddenAttributeText     = "This file has the hidden attribute set.\n";
const char *noAttributeText         = "This file has no attribute set.\n";
const char *offlineAttributeText    = "This file is available offline.\n";
const char *readonlyAttributeText   = "This file has the read-only attribute set.\n";
const char *systemAttributeText     = "This file has the system attribute set.\n";
const char *temporaryAttributeText  = "This file is temporary.\n";
const char *compressedAttributeText = "This file is compressed.\n";
const char *tinyAdsText             = "This is a tiny Alternate Data Stream.\n";
const char *smallAdsText            = "This is a small Alternate Data Stream.\n";
const char *mediumAdsText           = "This is a medium Alternate Data Stream.\n";
const char *bigAdsText              = "This is a big Alternate Data Stream.\n";
const char *smallAdsRepeatText      = "This message repeats until almost 4KiB.\n";
const char *mediumAdsRepeatText     = "This message repeats until almost 64KiB.\n";
const char *bigAdsRepeatText        = "This message repeats until more than 64KiB.\n";

typedef struct _FILE_FULL_EA_INFORMATION
{
    ULONG  NextEntryOffset;
    UCHAR  Flags;
    UCHAR  EaNameLength;
    USHORT EaValueLength;
    CHAR   EaName[1];
} FILE_FULL_EA_INFORMATION, *PFILE_FULL_EA_INFORMATION;

#ifndef FILE_NEED_EA
#define FILE_NEED_EA 0x80
#endif

typedef LONG NTSTATUS;

typedef struct _IO_STATUS_BLOCK
{
    union {
        NTSTATUS Status;
        PVOID    Pointer;
    } DUMMYUNIONNAME;
    PULONG Information;
} IO_STATUS_BLOCK, *PIO_STATUS_BLOCK;

#ifndef NTAPI
#define NTAPI __stdcall
#endif

NTSTATUS(NTAPI *NtSetEaFile)(HANDLE, PIO_STATUS_BLOCK, PVOID, ULONG);
NTSTATUS(NTAPI *NtQueryEaFile)(HANDLE, PIO_STATUS_BLOCK, PVOID, ULONG, BOOLEAN, PVOID, ULONG, PULONG, BOOLEAN);

#ifndef FSCTL_SET_SPARSE
#define FSCTL_SET_SPARSE 0x000900C4
#endif

#ifndef FSCTL_SET_ZERO_DATA
#define FSCTL_SET_ZERO_DATA 0x000900C8
#endif

#define FSCTL_SET_SPARSE_OLD 0x000980C4
#define FSCTL_SET_ZERO_DATA_OLD 0x000980C8

typedef struct _WINNT_FILE_ZERO_DATA_INFORMATION
{
    LARGE_INTEGER FileOffset;
    LARGE_INTEGER BeyondFinalZero;
} WINNT_FILE_ZERO_DATA_INFORMATION, *PWINNT_FILE_ZERO_DATA_INFORMATION;

unsigned char CommentsEA[72] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x33, 0x00, 0x2E, 0x43, 0x4F, 0x4D, 0x4D, 0x45, 0x4E, 0x54, 0x53, 0x00,
    0xFD, 0xFF, 0x2E, 0x00, 0x54, 0x68, 0x69, 0x73, 0x20, 0x45, 0x41, 0x20, 0x63, 0x6F, 0x6E, 0x74, 0x61, 0x69,
    0x6E, 0x73, 0x20, 0x63, 0x6F, 0x6D, 0x6D, 0x65, 0x6E, 0x74, 0x73, 0x20, 0x66, 0x6F, 0x72, 0x20, 0x57, 0x6F,
    0x72, 0x6B, 0x50, 0x6C, 0x61, 0x63, 0x65, 0x20, 0x53, 0x68, 0x65, 0x6C, 0x6C, 0x2E, 0x00, 0x00, 0x00, 0x00};

unsigned char CommentsEACritical[72] = {
    0x00, 0x00, 0x00, 0x00, 0x80, 0x09, 0x33, 0x00, 0x2E, 0x43, 0x4F, 0x4D, 0x4D, 0x45, 0x4E, 0x54, 0x53, 0x00,
    0xFD, 0xFF, 0x2E, 0x00, 0x54, 0x68, 0x69, 0x73, 0x20, 0x45, 0x41, 0x20, 0x63, 0x6F, 0x6E, 0x74, 0x61, 0x69,
    0x6E, 0x73, 0x20, 0x63, 0x6F, 0x6D, 0x6D, 0x65, 0x6E, 0x74, 0x73, 0x20, 0x66, 0x6F, 0x72, 0x20, 0x57, 0x6F,
    0x72, 0x6B, 0x50, 0x6C, 0x61, 0x63, 0x65, 0x20, 0x53, 0x68, 0x65, 0x6C, 0x6C, 0x2E, 0x00, 0x00, 0x00, 0x00};

unsigned char IconEA[3516] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0xAE, 0x0D, 0x2E, 0x49, 0x43, 0x4F, 0x4E, 0x00, 0xF9, 0xFF, 0xAA, 0x0D, 0x42,
    0x41, 0x28, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x49, 0x1A, 0x00, 0x00, 0x00,
    0x10, 0x00, 0x10, 0x00, 0xDA, 0x01, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x20, 0x00, 0x40, 0x00, 0x01, 0x00, 0x01,
    0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x43, 0x49, 0x1A, 0x00, 0x00, 0x00, 0x10, 0x00, 0x10, 0x00, 0xDA, 0x02,
    0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x20, 0x00, 0x20, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F,
    0x3F, 0x80, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xFF, 0xFF, 0xFF, 0x00, 0x80, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00,
    0xFF, 0xFF, 0x00, 0x80, 0x80, 0x00, 0xFF, 0x00, 0xFF, 0x80, 0x00, 0x80, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0x00,
    0xFF, 0x00, 0xFF, 0x00, 0x00, 0x42, 0x41, 0x28, 0x00, 0x00, 0x00, 0xC6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x43, 0x49, 0x1A, 0x00, 0x00, 0x00, 0x10, 0x00, 0x10, 0x00, 0xDA, 0x04, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x20,
    0x00, 0x40, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x43, 0x49, 0x1A, 0x00, 0x00, 0x00,
    0x10, 0x00, 0x10, 0x00, 0xDA, 0x05, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x20, 0x00, 0x20, 0x00, 0x01, 0x00, 0x01,
    0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x42, 0x41, 0x28, 0x00, 0x00, 0x00, 0x14, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x43, 0x49, 0x1A, 0x00, 0x00, 0x00, 0x08, 0x00, 0x08, 0x00, 0x5A, 0x06, 0x00, 0x00, 0x0C, 0x00, 0x00,
    0x00, 0x10, 0x00, 0x20, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x43, 0x49, 0x1A, 0x00,
    0x00, 0x00, 0x08, 0x00, 0x08, 0x00, 0xDA, 0x06, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x10, 0x00, 0x10, 0x00, 0x01,
    0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x41, 0x28, 0x00, 0x00, 0x00, 0x62, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x43, 0x49, 0x1A, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x0A, 0x00, 0x1A, 0x07, 0x00, 0x00, 0x0C,
    0x00, 0x00, 0x00, 0x14, 0x00, 0x28, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x43, 0x49,
    0x1A, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x0A, 0x00, 0xBA, 0x07, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x14, 0x00, 0x14,
    0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x41, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x04, 0x00, 0x03, 0x43, 0x49, 0x1A, 0x00, 0x00, 0x00, 0x14, 0x00, 0x14, 0x00, 0x0A, 0x08, 0x00,
    0x00, 0x0C, 0x00, 0x00, 0x00, 0x28, 0x00, 0x50, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
    0x43, 0x49, 0x1A, 0x00, 0x00, 0x00, 0x14, 0x00, 0x14, 0x00, 0x8A, 0x0A, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x28,
    0x00, 0x28, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x3F, 0x3F, 0x80, 0x80, 0x80, 0xC0, 0xC0, 0xC0,
    0xFF, 0xFF, 0xFF, 0x00, 0x80, 0x80, 0x80, 0xA0, 0x80, 0x28, 0x50, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x80, 0x00, 0xD0,
    0xD8, 0xB0, 0xC0, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x8F, 0xFE, 0x3F, 0xFE, 0x0F, 0xF8, 0x3F, 0xFE, 0x0F, 0xF8, 0x3F, 0xFE, 0x0F, 0xF8, 0x3F, 0xFE, 0x00,
    0x00, 0x3F, 0xFF, 0x00, 0x00, 0x3F, 0xFF, 0x00, 0x00, 0x7F, 0xFF, 0x00, 0x00, 0x7F, 0xFF, 0x00, 0x00, 0x1F, 0xFE,
    0x00, 0x00, 0x0F, 0xFC, 0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00, 0x0F,
    0xF8, 0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00,
    0x0F, 0xF8, 0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00, 0x1F, 0xF8, 0x00, 0x00, 0x3F, 0xFC, 0x00,
    0x00, 0x7F, 0xFF, 0xFC, 0x7F, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x11, 0x22, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x31,
    0x22, 0x00, 0x00, 0x00, 0x00, 0x01, 0x31, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x31, 0x22, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x31, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x33, 0x12, 0x22, 0x22, 0x22, 0x22, 0x13,
    0x31, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x12, 0x22, 0x22, 0x22, 0x22, 0x13, 0x12, 0x22, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x11, 0x11, 0x11, 0x11, 0x11, 0x13, 0x12, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x13, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x12, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x21, 0x31, 0x11, 0x11, 0x11, 0x11, 0x31, 0x22, 0x22, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x21, 0x31, 0x22,
    0x22, 0x22, 0x21, 0x31, 0x22, 0x22, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x22, 0x00, 0x00, 0x00, 0x00, 0x01, 0x34, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x31,
    0x22, 0x00, 0x00, 0x00, 0x00, 0x01, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x41, 0x22, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x41, 0x22, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x44, 0x46, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x44, 0x41, 0x22, 0x00, 0x00, 0x00, 0x00, 0x01, 0x44, 0x44, 0x44,
    0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x41, 0x22, 0x00, 0x00, 0x00, 0x00, 0x01, 0x44, 0x46, 0x66, 0x66, 0x66, 0x66,
    0x66, 0x66, 0x44, 0x41, 0x22, 0x00, 0x00, 0x00, 0x00, 0x01, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
    0x41, 0x22, 0x00, 0x00, 0x00, 0x00, 0x01, 0x44, 0x46, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x44, 0x41, 0x22, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x41, 0x22, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x44, 0x46, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x44, 0x41, 0x22, 0x00, 0x00, 0x00, 0x00, 0x01, 0x44, 0x44,
    0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x41, 0x20, 0x00, 0x00, 0x00, 0x00, 0x01, 0x34, 0x44, 0x44, 0x44, 0x44,
    0x44, 0x44, 0x44, 0x44, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0xFC, 0x1F, 0xFC, 0x07, 0xF0, 0x1F, 0xFC, 0x07, 0xF0, 0x1F, 0xFC, 0x07,
    0xF0, 0x1F, 0xFC, 0x00, 0x00, 0x1F, 0xFC, 0x00, 0x00, 0x1F, 0xFE, 0x00, 0x00, 0x1F, 0xFE, 0x00, 0x00, 0x3F, 0xFE,
    0x00, 0x00, 0x1F, 0xFE, 0x00, 0x00, 0x0F, 0xFC, 0x00, 0x00, 0x07, 0xF8, 0x00, 0x00, 0x07, 0xF0, 0x00, 0x00, 0x07,
    0xF0, 0x00, 0x00, 0x07, 0xF0, 0x00, 0x00, 0x07, 0xF0, 0x00, 0x00, 0x07, 0xF0, 0x00, 0x00, 0x07, 0xF0, 0x00, 0x00,
    0x07, 0xF0, 0x00, 0x00, 0x07, 0xF0, 0x00, 0x00, 0x07, 0xF0, 0x00, 0x00, 0x07, 0xF0, 0x00, 0x00, 0x07, 0xF0, 0x00,
    0x00, 0x0F, 0xF0, 0x00, 0x00, 0x1F, 0xF8, 0x00, 0x00, 0x3F, 0xFC, 0x00, 0x00, 0x7F, 0xFF, 0xFC, 0x7F, 0xFF, 0xFF,
    0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xF8, 0x03, 0xE0, 0x03, 0x88, 0x0E, 0x20, 0x02, 0x08, 0x08, 0x20, 0x02, 0x88, 0x0A, 0x20, 0x02, 0x8F, 0xFA,
    0x20, 0x02, 0xC0, 0x06, 0x20, 0x01, 0x40, 0x04, 0x20, 0x01, 0x40, 0x04, 0x40, 0x01, 0x7F, 0xFC, 0x60, 0x01, 0x20,
    0x08, 0x10, 0x02, 0x20, 0x08, 0x08, 0x04, 0x00, 0x00, 0x08, 0x0B, 0xFF, 0xFF, 0x88, 0x0B, 0xFF, 0xFF, 0x88, 0x0B,
    0xFF, 0xFF, 0x88, 0x0B, 0x00, 0x03, 0x88, 0x0B, 0xFF, 0xFF, 0x88, 0x0B, 0x00, 0x03, 0x88, 0x0B, 0xFF, 0xFF, 0x88,
    0x0B, 0x00, 0x03, 0x88, 0x0B, 0xFF, 0xFF, 0x88, 0x0B, 0x00, 0x03, 0x88, 0x0B, 0xFF, 0xFF, 0x90, 0x0B, 0xFF, 0xFF,
    0xA0, 0x04, 0x00, 0x00, 0x40, 0x03, 0xFD, 0x7F, 0x80, 0x00, 0x02, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xED, 0x41, 0x00, 0x00, 0x3B, 0x00, 0x00, 0x00, 0x27, 0x09, 0x00, 0x00, 0xF5, 0x08, 0x00, 0x00, 0x1F, 0x09,
    0x00, 0x00, 0x4A, 0x09, 0x00, 0x00, 0x9F, 0x0A, 0x00, 0x00, 0xE3, 0x0A, 0x00, 0x00, 0xE4, 0x09, 0x00, 0x00, 0x02,
    0x0A, 0x00, 0x00, 0x29, 0x0A, 0x00, 0x00, 0x55, 0x0A, 0x00, 0x00, 0x72, 0x0A, 0x00, 0x00, 0x88, 0x0A, 0xFF, 0xFF,
    0x00, 0x00, 0xE7, 0xCF, 0xE5, 0x1C, 0xE7, 0xCF, 0x65, 0x00, 0xF0, 0x1F, 0xDD, 0x04, 0xF3, 0x9F, 0xF2, 0x03, 0xE0,
    0x0F, 0xC7, 0x04, 0xDF, 0xF7, 0x0B, 0x05, 0xDF, 0xF7, 0xF8, 0x04, 0xDF, 0xF7, 0x32, 0x04, 0xDF, 0xF7, 0xA8, 0x04,
    0xDF, 0xF7, 0x9E, 0x04, 0xDF, 0xF7, 0xBA, 0x04, 0xE0, 0x0F, 0x7A, 0x04, 0xFD, 0x7F, 0x85, 0x04, 0xFE, 0xFF, 0xFF,
    0x04, 0xFF, 0xFF, 0xDF, 0x04, 0xFF, 0xFF, 0x00, 0x00, 0xE7, 0xCF, 0x00, 0x1F, 0xE7, 0xCF, 0x00, 0x1F, 0xF0, 0x1F,
    0x00, 0x1F, 0xF3, 0x9F, 0x00, 0x1F, 0xE0, 0x0F, 0x00, 0x1F, 0xDF, 0xF7, 0x00, 0x1F, 0xDF, 0xF7, 0x00, 0x1F, 0xDF,
    0xF7, 0x00, 0x1F, 0xDF, 0xF7, 0x00, 0x1F, 0xDF, 0xF7, 0x00, 0x1F, 0xDF, 0xF7, 0x00, 0x7F, 0xE0, 0x0F, 0x00, 0x7F,
    0xFD, 0x7F, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x08, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x08, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x33, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x08, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x7F, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xF0,
    0x00, 0xE3, 0xF1, 0xF0, 0x00, 0xEB, 0xF5, 0xF1, 0x11, 0xE9, 0xE5, 0xF0, 0x00, 0xF4, 0x0B, 0xF0, 0x00, 0xF7, 0xFB,
    0xF0, 0x00, 0xFA, 0x17, 0xF1, 0x11, 0xFA, 0xD7, 0xF0, 0x00, 0xE0, 0x01, 0xF0, 0x0F, 0xDF, 0xFE, 0xF0, 0x00, 0xDF,
    0xFE, 0xFF, 0xFF, 0xDF, 0xFE, 0xF0, 0x00, 0xDF, 0xFE, 0xFF, 0xFF, 0xDF, 0xFE, 0xFF, 0xFF, 0xDF, 0xFE, 0xF0, 0x00,
    0xDF, 0xFE, 0xFF, 0xFF, 0xE0, 0x01, 0xFF, 0xFF, 0xFF, 0x5F, 0xFF, 0xFF, 0xFF, 0xBF, 0xF6, 0x66, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0xE3, 0xF1, 0xF0, 0x01, 0xEB, 0xF5, 0xF1, 0x11, 0xE9, 0xE5, 0xF0, 0x00, 0xF4, 0x0B,
    0xF0, 0x01, 0xF7, 0xFB, 0xF1, 0x11, 0xFA, 0x17, 0xF0, 0x00, 0xFA, 0xD7, 0xF0, 0x01, 0xE0, 0x01, 0xF1, 0x11, 0xDF,
    0xFE, 0xF0, 0x00, 0xDF, 0xFE, 0xF0, 0x01, 0xDF, 0xFE, 0xF1, 0x11, 0xDF, 0xFE, 0xF0, 0x00, 0xDF, 0xFE, 0xF0, 0x00,
    0xDF, 0xFE, 0xF0, 0x00, 0xDF, 0xFE, 0xF0, 0x00, 0xE0, 0x01, 0xF0, 0x00, 0xFF, 0x5F, 0xF1, 0x00, 0xFF, 0xBF, 0xF0,
    0x00, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88,
    0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x7F, 0xFF, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x88, 0x80, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF7, 0x33, 0x33, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x88, 0x00, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x7F,
    0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x80, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF7, 0x33, 0x33, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0x88, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x33, 0x7F, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x87, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF7, 0x33, 0x33,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x88, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x7F, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x33, 0x7F, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF7,
    0x33, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x77, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87, 0x08, 0x7F, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x33, 0x7F, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x88, 0x70, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xF7, 0x33, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88,
    0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x7F, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xF7, 0x33, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x88, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x88, 0x88, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x7F, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xF7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x04, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x66, 0x66, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x7F, 0xFF, 0xFF, 0xC3, 0xFF, 0xE1,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xFF, 0x81, 0xFF, 0x07, 0x00, 0x00, 0xFF, 0x03, 0xFF, 0x81, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x03, 0xFF, 0x81, 0xFF, 0xFF, 0x06, 0x60, 0xFF, 0x01, 0xFF, 0x01, 0xFF, 0x00, 0x37, 0x77, 0xFF, 0x00,
    0x00, 0x01, 0xFF, 0x77, 0x77, 0x77, 0xFF, 0x80, 0x00, 0x03, 0xFF, 0xEE, 0x00, 0x00, 0xFF, 0x80, 0x00, 0x03, 0xFF,
    0x33, 0x33, 0x33, 0xFF, 0x80, 0x00, 0x03, 0xFF, 0x00, 0x00, 0xEE, 0xFF, 0xC0, 0x00, 0x03, 0xFF, 0x00, 0x33, 0x33,
    0xFF, 0xC0, 0x00, 0x01, 0xFF, 0x33, 0x33, 0x33, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x0E, 0xEE, 0x00, 0xFE, 0x00, 0x00,
    0x00, 0x7F, 0x33, 0x33, 0x33, 0xFC, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x7F, 0x00,
    0x33, 0x33, 0xFC, 0x00, 0x00, 0x00, 0x7F, 0x33, 0x33, 0x33, 0xFC, 0x00, 0x00, 0x00, 0x7F, 0xEE, 0x0E, 0xEE, 0xFC,
    0x00, 0x00, 0x00, 0x7F, 0x33, 0x33, 0x33, 0xFC, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00,
    0x7F, 0x00, 0x33, 0x33, 0xFC, 0x00, 0x00, 0x00, 0x7F, 0x33, 0x33, 0x33, 0xFC, 0x00, 0x00, 0x00, 0x7F, 0x0E, 0xEE,
    0x0E, 0xFC, 0x00, 0x00, 0x00, 0x7F, 0x33, 0x33, 0x33, 0xFC, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0xFC, 0x00,
    0x00, 0x00, 0x7F, 0x40, 0x33, 0x33, 0xFC, 0x00, 0x00, 0x00, 0x7F, 0x33, 0x33, 0x33, 0xFC, 0x00, 0x00, 0x00, 0xFF,
    0x00, 0x0E, 0x00, 0xFC, 0x00, 0x00, 0x01, 0xFF, 0x33, 0x33, 0x33, 0xFE, 0x00, 0x00, 0x03, 0xFF, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0x87, 0xFF, 0xFF, 0xF0, 0x33, 0x33, 0xFF, 0xFF, 0x87, 0xFF, 0xFF, 0x33, 0x33, 0x33, 0xFF, 0xFF, 0xCF,
    0xFF, 0xFF, 0x00, 0x00, 0x04, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x33, 0x33, 0x33, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
    0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x5D, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x22, 0x20,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x12,
    0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x31, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x33,
    0x12, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x31, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x33, 0x12, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x33, 0x12, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x13, 0x33, 0x12, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x33, 0x12, 0x22, 0x22, 0x22, 0x22,
    0x22, 0x13, 0x33, 0x12, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x33, 0x12, 0x22, 0x22, 0x22,
    0x22, 0x22, 0x13, 0x31, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x33, 0x31, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x33, 0x31, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x31, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x33,
    0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x12, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13,
    0x31, 0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0x12, 0x22, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22,
    0x13, 0x33, 0x12, 0x22, 0x22, 0x22, 0x13, 0x33, 0x12, 0x22, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x12, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x13, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x43, 0x12, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x14, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x12, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x14, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x12, 0x20, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x14, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x12, 0x20, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x14, 0x44, 0x43, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44, 0x12, 0x20, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x44, 0x49, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x44, 0x44, 0x12, 0x20,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x12,
    0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x44, 0x43, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x44, 0x44,
    0x12, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x44, 0x49, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x44,
    0x44, 0x12, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
    0x44, 0x44, 0x12, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x44, 0x43, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x44, 0x44, 0x12, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x44, 0x49, 0x99, 0x99, 0x99, 0x99, 0x99,
    0x99, 0x99, 0x44, 0x44, 0x12, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
    0x44, 0x44, 0x44, 0x44, 0x44, 0x12, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x44, 0x44, 0x44, 0x44, 0x44,
    0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x44, 0x44, 0x44, 0x44,
    0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x43, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x33, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x33, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00};

#define DATETIME_FORMAT "This file is dated %s for %s\r"
#define MAXDATETIME "60056/05/28 05:36:11"
#define MINDATETIME "1601/01/01 00:00:00"
#define Y2KDATETIME "2000/01/01 00:00:00"
#define Y1KDATETIME "1999/12/31 23:59:59"
#define MAXTIMESTAMP 0xFFFFFFFF
#define MINTIMESTAMP 0x00000000
#define TIMESTAMP_HI 0x01BF53EB
#define Y2KTIMESTAMP_LO 0x256D4000
#define Y1KTIMESTAMP_LO 0x24D4A980

typedef struct _WIN_OSVERSIONINFOA
{
    DWORD dwOSVersionInfoSize;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwPlatformId;
    CHAR  szCSDVersion[128]; // Maintenance string for PSS usage
} WIN_OSVERSIONINFOA, *WIN_POSVERSIONINFOA, *WIN_LPOSVERSIONINFOA;

typedef WIN_OSVERSIONINFOA   WIN_OSVERSIONINFO;
typedef WIN_POSVERSIONINFOA  WIN_POSVERSIONINFO;
typedef WIN_LPOSVERSIONINFOA WIN_LPOSVERSIONINFO;

BOOL(WINAPI *WinNtCreateHardLinkA)(LPCSTR, LPCSTR, LPSECURITY_ATTRIBUTES);
BOOL(WINAPI *WinNtCreateSymbolicLinkA)(LPCSTR, LPCSTR, DWORD);
BOOL(WINAPI *WinNtEncryptFileA)(LPCSTR);
BOOL(WINAPI *WinGetVersionExA)(WIN_LPOSVERSIONINFOA);
BOOL(WINAPI *WinGetDiskFreeSpaceExA)(LPCSTR, PULARGE_INTEGER, PULARGE_INTEGER, PULARGE_INTEGER);

#endif

#endif
