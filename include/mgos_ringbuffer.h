/*
 * Copyright (c) 2019 Manfred Müller-Späth <fms1961@gmail.com>
 * All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __MGOS_RINGBUFFER_H_
#define __MGOS_RINGBUFFER_H_

#include "mgos_config.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    void* buffer;
    uint32_t count;
    uint32_t size;
    uint32_t pos;
} mgos_ring_buffer;

#if defined(__cplusplus)
extern "C" { // Make sure we have C-declarations in C++ programs
#endif

mgos_ring_buffer* mgos_ringbuffer_setup(uint32_t size);
mgos_ring_buffer* mgos_ringbuffer_free(mgos_ring_buffer* old_buf);
uint32_t mgos_ringbuffer_add(mgos_ring_buffer* buf, double value);
double mgos_ringbuffer_get_average(mgos_ring_buffer* buf);
bool mgos_ringbuffer_init(void);

#if defined(__cplusplus)
}
#endif

#endif /* __MGOS_RINGBUFFER_H_ */
