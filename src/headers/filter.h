#pragma once

#include <vector>


namespace insight_plus
{
    struct TextFilter
    {
        TextFilter(const char* default_filter = "");
        bool      Draw(const char* label = "Filter (inc,-exc)", float width = 0.0f);  // Helper calling InputText+Build
        bool      PassFilter(const char* text, const char* text_end = NULL) const;
        void      Build();
        void      Clear()          { InputBuf[0] = 0; Build(); }
        bool      IsActive() const { return !Filters.empty(); }

        struct TextRange
        {
            const char*     b;
            const char*     e;

            TextRange()                                { b = e = NULL; }
            TextRange(const char* _b, const char* _e)  { b = _b; e = _e; }
            bool  empty() const                        { return b == e; }
            void  split(char separator, std::vector<TextRange>* out) const;
        };
        char                    InputBuf[256];
        std::vector<TextRange>  Filters;
        int                     CountGrep;
    };
}