#pragma once

#include <vector>
#include <memory>

#include "filter.h"
#include "buffer.h"
#include "drawStrategy.h"
#include "outputStrategy.h"

/*
*   Usage:
*   static insight_plus::console my_log;
*   my_log.AddLog("Hello %d world", 123);
*   my_log.Draw("title");
*/ 

// Forward declarations
class ImGuiInputTextCallbackData;

namespace insight_plus
{
    class Console
    {
    public:
        Console()
        {
            AutoScroll = true;

            drawStrategy = nullptr;
            outputStrategy = nullptr;

            Clear();
        }

        void Clear()
        {
            Buf.clear();
            LineOffsets.clear();
            LineOffsets.push_back(0);
        }

        void AddLog(const char* fmt, ...);

        void ClearLog();
        void ExecCommand(const char* command_line);
        int TextEditCallback(ImGuiInputTextCallbackData* data);


        void SetDrawStrategy(std::unique_ptr<iDrawStrategy> StrategyIn) { drawStrategy = std::move(StrategyIn); }
        void SetOutputStrategy(std::unique_ptr<iOutputStrategy>&& StrategyIn) { outputStrategy = std::move(StrategyIn); }

        // TODO: Call before GLFW Init
        void Setup();
        // TODO: Call after GLFW swap
        void Draw();

        void ShutDown();

    private:
        void ShowConsole();

        void ShowConsole2();

        Buffer               Buf;
        //TextFilter           Filter;
        std::vector<int>     LineOffsets; // Index to lines offset. We maintain this with AddLog() calls.
        //bool                 AutoScroll;  // Keep scrolling if already at the bottom.

        char                     InputBuf[256];
        std::vector<char*>       Items;
        std::vector<const char*> Commands;
        std::vector<char*>       History;
        int                      HistoryPos;    // -1: new line, 0..History.Size-1 browsing history.
        TextFilter               Filter;
        bool                     AutoScroll;
        bool                     ScrollToBottom;

        std::unique_ptr<iDrawStrategy> drawStrategy;
        std::unique_ptr<iOutputStrategy> outputStrategy;
    };
}