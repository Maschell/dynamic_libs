#ifndef _OS_TYPES_H_
#define _OS_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <gctypes.h>

typedef struct _OSCalendarTime {
  int32_t tm_sec;
  int32_t tm_min;
  int32_t tm_hour;
  int32_t tm_mday;
  int32_t tm_mon;
  int32_t tm_year;
} OSCalendarTime;

#ifdef __cplusplus
}
#endif

#endif
