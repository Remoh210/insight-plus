#pragma once

#include <vector>

#include "filter.h"
#include "buffer.h"

/*
*   Usage:
*   static NxAppLog my_log;
*   my_log.AddLog("Hello %d world", 123);
*   my_log.Draw("title");
*/ 

namespace insight_plus
{
    class Console
    {
    public:
        Console()
        {
            AutoScroll = true;
            Clear();
        }

        void Clear()
        {
            Buf.clear();
            LineOffsets.clear();
            LineOffsets.push_back(0);
        }

        void AddLog(const char* fmt, ...);

        void Draw(const char* title, bool* p_open = NULL);

    private:
        Buffer     Buf;
        TextFilter     Filter;
        std::vector<int>     LineOffsets; // Index to lines offset. We maintain this with AddLog() calls.
        bool                 AutoScroll;  // Keep scrolling if already at the bottom.
    };
}