//
// Created by claunia on 14/3/21.
//

#ifndef SETTER_SRC_DARWIN_DARWIN_H_
#define SETTER_SRC_DARWIN_DARWIN_H_

#include <sys/types.h>

void DarwinGetOsInfo(void);
void DarwinPrintStatfsFlags(u_int32_t flags);
void DarwinResourceFork(const char* path);
void DarwinFileAttributes(const char* path);
void DarwinExtendedAttributes(const char* path);
void DarwinVolumeAttributes(const char* path);
int  DarwinSparse(const char* path);

#endif // SETTER_SRC_DARWIN_DARWIN_H_
