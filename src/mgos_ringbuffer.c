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

#include "mgos_ringbuffer.h"

mgos_ring_buffer* mgos_ringbuffer_setup(uint32_t size)
{
    mgos_ring_buffer* result = calloc(1, sizeof(mgos_ring_buffer));
    result->count = size;
    result->size = result->count * sizeof(double);
    result->pos = 0;
    result->buffer = calloc(1, result->size);
    return result;
}

mgos_ring_buffer* mgos_ringbuffer_free(mgos_ring_buffer* old_buf)
{
    free(old_buf->buffer);
    free(old_buf);
    return NULL;
}

uint32_t mgos_ringbuffer_add(mgos_ring_buffer* buf, double value)
{
    ((double*)buf->buffer)[buf->pos] = value;
    buf->pos = (buf->pos + 1) % (buf->count);
    return buf->pos;
}

double mgos_ringbuffer_get_average(mgos_ring_buffer* buf)
{
    double total = 0.0;

    for (uint32_t i = 0; i < buf->count; i++) {
        total += ((double*)buf->buffer)[i];
    }

    return total / buf->count;
}

bool mgos_ringbuffer_init(void)
{
  return true;
}