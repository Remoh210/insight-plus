#pragma once

#include <vector>
#include <cassert>

namespace insight_plus
{
    struct Buffer
    {
        std::vector<char> Buf;
        static char EmptyString[1];
        
        inline char         operator[](int i) const { assert(Buf.data() != NULL); return Buf[i]; }
        const char*         begin() const           { return Buf.data() ? &Buf.front() : EmptyString; }
        const char*         end() const             { return Buf.data() ? &Buf.back() : EmptyString; } 
        int                 size() const            { return Buf.size() ? Buf.size() - 1 : 0; }
        bool                empty() const           { return Buf.size() <= 1; }
        void                clear()                 { Buf.clear(); }
        void                reserve(int capacity)   { Buf.reserve(capacity); }
        const char*         c_str() const           { return Buf.data() ? Buf.data() : EmptyString; }
        void      append(const char* str, const char* str_end = NULL);
        void      appendf(const char* fmt, ...);
        void      appendfv(const char* fmt, va_list args);
    };
}