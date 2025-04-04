#include "buffer.h"

#include <cstdarg>

namespace insight_plus
{
    char Buffer::EmptyString[1] = { 0 };

    int FormatStringV(char* buf, size_t buf_size, const char* fmt, va_list args)
    {
    int w = vsnprintf(buf, buf_size, fmt, args);

    if (buf == NULL)
        return w;
    if (w == -1 || w >= (int)buf_size)
        w = (int)buf_size - 1;
    buf[w] = 0;
    return w;
    }

    void Buffer::append(const char* str, const char* str_end)
    {
        int len = str_end ? (int)(str_end - str) : (int)strlen(str);
    
        // Add zero-terminator the first time
        const int write_off = (Buf.size() != 0) ? Buf.size() : 1;
        const int needed_sz = write_off + len;
        if (write_off + len >= Buf.capacity())
        {
            int new_capacity = Buf.capacity() * 2;
            Buf.reserve(needed_sz > new_capacity ? needed_sz : new_capacity);
        }
    
        Buf.resize(needed_sz);
        memcpy(&Buf[write_off - 1], str, (size_t)len);
        Buf[write_off - 1 + len] = 0;
    }
    
    void Buffer::appendf(const char* fmt, ...)
    {
        va_list args;
        va_start(args, fmt);
        appendfv(fmt, args);
        va_end(args);
    }
    
    // Helper: Text buffer for logging/accumulating text
    void Buffer::appendfv(const char* fmt, va_list args)
    {
        va_list args_copy;
        va_copy(args_copy, args);
    
        int len = FormatStringV(NULL, 0, fmt, args);
        if (len <= 0)
        {
            va_end(args_copy);
            return;
        }
    
        // Add zero-terminator the first time
        const int write_off = (Buf.size() != 0) ? Buf.size() : 1;
        const int needed_sz = write_off + len;
        if (write_off + len >= Buf.capacity())
        {
            int new_capacity = Buf.capacity() * 2;
            Buf.reserve(needed_sz > new_capacity ? needed_sz : new_capacity);
        }
    
        Buf.resize(needed_sz);
        FormatStringV(&Buf[write_off - 1], (size_t)len + 1, fmt, args_copy);
        va_end(args_copy);
    }
}