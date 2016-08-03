/****************************************************************************
 * Copyright (C) 2015
 * by Dimok
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any
 * damages arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any
 * purpose, including commercial applications, and to alter it and
 * redistribute it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you
 * must not claim that you wrote the original software. If you use
 * this software in a product, an acknowledgment in the product
 * documentation would be appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and
 * must not be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source
 * distribution.
 ***************************************************************************/
#ifndef __FS_FUNCTIONS_H_
#define __FS_FUNCTIONS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <gctypes.h>

/* FS defines and types */
#define FS_MAX_LOCALPATH_SIZE           511
#define FS_MAX_MOUNTPATH_SIZE           128
#define FS_MAX_FULLPATH_SIZE            (FS_MAX_LOCALPATH_SIZE + FS_MAX_MOUNTPATH_SIZE)
#define FS_MAX_ARGPATH_SIZE             FS_MAX_FULLPATH_SIZE

#define FS_STATUS_OK                    0
#define FS_RET_UNSUPPORTED_CMD          0x0400
#define FS_RET_NO_ERROR                 0x0000
#define FS_RET_ALL_ERROR                (unsigned int)(-1)

#define FS_STAT_FLAG_IS_DIRECTORY       0x80000000

/* max length of file/dir name */
#define FS_MAX_ENTNAME_SIZE             256

#define FS_SOURCETYPE_EXTERNAL          0
#define FS_SOURCETYPE_HFIO              1
#define FS_SOURCETYPE_HFIO              1

#define FS_STATUS_OK                    0
#define FS_STATUS_EXISTS	            -5
#define FS_STATUS_STORAGE_FULL			-12
#define FS_STATUS_JOURNAL_FULL			-13

#define FS_MOUNT_SOURCE_SIZE            0x300
#define FS_CLIENT_SIZE                  0x1700
#define FS_CMD_BLOCK_SIZE               0xA80

typedef struct
{
    uint32_t flag;
    uint32_t permission;
    uint32_t owner_id;
    uint32_t group_id;
    uint32_t size;
    uint32_t alloc_size;
    uint64_t quota_size;
    uint32_t ent_id;
    uint64_t ctime;
    uint64_t mtime;
    uint8_t attributes[48];
} __attribute__((packed)) FSStat;

typedef struct
{
    FSStat      stat;
    char        name[FS_MAX_ENTNAME_SIZE];
} FSDirEntry;

void InitFSFunctionPointers(void);

extern int (* FSInit)(void);
extern int (* FSShutdown)(void);
extern int (* FSAddClientEx)(void *pClient, int unk_zero_param, int errHandling);
extern int (* FSDelClient)(void *pClient);
extern void (* FSInitCmdBlock)(void *pCmd);
extern int (* FSGetMountSource)(void *pClient, void *pCmd, int type, void *source, int errHandling);

extern int (* FSMount)(void *pClient, void *pCmd, void *source, char *target, uint32_t bytes, int errHandling);
extern int (* FSUnmount)(void *pClient, void *pCmd, const char *target, int errHandling);
extern int (* FSRename)(void *pClient, void *pCmd, const char *oldPath, const char *newPath, int error);
extern int (* FSRenameAsync)(void *pClient, void *pCmd, const char *oldPath, const char *newPath, int error, void *asyncParams);
extern int (* FSRemove)(void *pClient, void *pCmd, const char *path, int error);
extern int (* FSRemoveAsync)(void *pClient, void *pCmd, const char *path, int error, void *asyncParams);

extern int (* FSGetStat)(void *pClient, void *pCmd, const char *path, FSStat *stats, int errHandling);
extern int (* FSGetStatAsync)(void *pClient, void *pCmd, const char *path, void *stats, int error, void *asyncParams);
extern int (* FSRename)(void *pClient, void *pCmd, const char *oldPath, const char *newPath, int error);
extern int (* FSRenameAsync)(void *pClient, void *pCmd, const char *oldPath, const char *newPath, int error, void *asyncParams);
extern int (* FSRemove)(void *pClient, void *pCmd, const char *path, int error);
extern int (* FSRemoveAsync)(void *pClient, void *pCmd, const char *path, int error, void *asyncParams);
extern int (* FSFlushQuota)(void *pClient, void *pCmd, const char* path, int error);
extern int (* FSFlushQuotaAsync)(void *pClient, void *pCmd, const char *path, int error, void *asyncParams);
extern int (* FSGetFreeSpaceSize)(void *pClient, void *pCmd, const char *path, uint64_t *returnedFreeSize, int error);
extern int (* FSGetFreeSpaceSizeAsync)(void *pClient, void *pCmd, const char *path, uint64_t *returnedFreeSize, int error, void *asyncParams);
extern int (* FSRollbackQuota)(void *pClient, void *pCmd, const char *path, int error);
extern int (* FSRollbackQuotaAsync)(void *pClient, void *pCmd, const char *path, int error, void *asyncParams);

extern int (* FSOpenDir)(void *pClient, void *pCmd, const char *path, int *dh, int errHandling);
extern int (* FSOpenDirAsync)(void *pClient, void* pCmd, const char *path, int *handle, int error, void *asyncParams);
extern int (* FSReadDir)(void *pClient, void *pCmd, int dh, FSDirEntry *dir_entry, int errHandling);
extern int (* FSRewindDir)(void *pClient, void *pCmd, int dh, int errHandling);
extern int (* FSCloseDir)(void *pClient, void *pCmd, int dh, int errHandling);
extern int (* FSChangeDir)(void *pClient, void *pCmd, const char *path, int errHandling);
extern int (* FSChangeDirAsync)(void *pClient, void *pCmd, const char *path, int error, void *asyncParams);
extern int (* FSMakeDir)(void *pClient, void *pCmd, const char *path, int errHandling);
extern int (* FSMakeDirAsync)(void *pClient, void *pCmd, const char *path, int error, void *asyncParams);

extern int (* FSOpenFile)(void *pClient, void *pCmd, const char *path, const char *mode, int *fd, int errHandling);
extern int (* FSOpenFileAsync)(void *pClient, void *pCmd, const char *path, const char *mode, int *handle, int error, const void *asyncParams);
extern int (* FSReadFile)(void *pClient, void *pCmd, void *buffer, int size, int count, int fd, int flag, int errHandling);
extern int (* FSCloseFile)(void *pClient, void *pCmd, int fd, int errHandling);

extern int (* FSFlushFile)(void *pClient, void *pCmd, int fd, int error);
extern int (* FSTruncateFile)(void *pClient, void *pCmd, int fd, int error);
extern int (* FSGetStatFile)(void *pClient, void *pCmd, int fd, void *buffer, int error);
extern int (* FSSetPosFile)(void *pClient, void *pCmd, int fd, int pos, int error);
extern int (* FSWriteFile)(void *pClient, void *pCmd, const void *source, int block_size, int block_count, int fd, int flag, int error);

extern int (* FSBindMount)(void *pClient, void *pCmd, char *source, char *target, int error);
extern int (* FSBindUnmount)(void *pClient, void *pCmd, char *target, int error);

extern int (* FSMakeQuota)( void *pClient, void *pCmd, const char *path,u32 mode, u64 size, int errHandling);
extern int (* FSMakeQuotaAsync)(void *pClient, void *pCmd, const char *path,u32 mode, u64 size, int errHandling,const void  *asyncParams);


#ifdef __cplusplus
}
#endif

#endif // __FS_FUNCTIONS_H_
