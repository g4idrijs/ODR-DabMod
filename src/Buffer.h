/*
   Copyright (C) 2011
   Her Majesty the Queen in Right of Canada (Communications Research
   Center Canada)
 */
/*
   This file is part of ODR-DabMod.

   ODR-DabMod is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as
   published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   ODR-DabMod is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with ODR-DabMod.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BUFFER_H
#define BUFFER_H

#ifdef HAVE_CONFIG_H
#   include <config.h>
#endif

#include <unistd.h>

/* Buffer is a container for a byte array, that is memcpy'ed
 * on assignment and by the copy-constructor.
 *
 * The allocation/freeing of the data is handled internally.
 */
class Buffer {
    protected:
        /* Current length of the data in the Buffer */
        size_t len;

        /* Allocated size of the Buffer */
        size_t size;

        /* Pointer to the data. Memory allocation is entirely
         * handled by setLength.
         */
        void *data;

    public:
        Buffer(const Buffer& copy);
        Buffer(size_t len = 0, const void *data = NULL);
        ~Buffer();

        /* Resize the buffer, reallocate memory if needed */
        void setLength(size_t len);

        /* Replace the data in the Buffer by the new data given.
         * Reallocates memory if needed.
         */
        void setData(const void *data, size_t len);
        Buffer &operator=(const Buffer &copy);

        /* Concatenate the current data with the new data given.
         * Reallocates memory if needed.
         */
        void appendData(const void *data, size_t len);
        Buffer &operator+=(const Buffer &copy);

        size_t getLength() const { return len; }
        void *getData() const { return data; }
};

#endif // BUFFER_H

