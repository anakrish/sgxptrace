// Copyright (c) Open Enclave SDK contributors.
// Licensed under the MIT License.

#ifndef _OE_INFERIOR_STATUS_H_
#define _OE_INFERIOR_STATUS_H_

#include <pthread.h>
#include <stdint.h>

typedef enum _oe_inferior_flags
{
    OE_INFERIOR_SINGLE_STEP = 0X1
} oe_inferior_flags_t;

int oe_track_inferior(pid_t pid);

int oe_untrack_inferior(pid_t pid);

int oe_get_inferior_flags(pid_t pid, int64_t* flags);

int oe_set_inferior_flags(pid_t pid, int64_t flags);

#endif
