#include "filter.h"

// Third party headers
#include <imgui_internal.h>

namespace insight_plus
{
    // Helper: Parse and apply text filters. In format "aaaaa[,bbbb][,ccccc]"
    TextFilter::TextFilter(const char* default_filter)
    {
        if (default_filter)
        {
            ImStrncpy(InputBuf, default_filter, IM_ARRAYSIZE(InputBuf));
            Build();
        }
        else
        {
            InputBuf[0] = 0;
            CountGrep = 0;
        }
    }

    bool TextFilter::Draw(const char* label, float width)
    {
        if (width != 0.0f)
            ImGui::SetNextItemWidth(width);
        bool value_changed = ImGui::InputText(label, InputBuf, IM_ARRAYSIZE(InputBuf));
        if (value_changed)
            Build();
        return value_changed;
    }

    void TextFilter::TextRange::split(char separator, std::vector<TextRange>* out) const
    {
        out->resize(0);
        const char* wb = b;
        const char* we = wb;
        while (we < e)
        {
            if (*we == separator)
            {
                out->push_back(TextRange(wb, we));
                wb = we + 1;
            }
            we++;
        }
        if (wb != we)
            out->push_back(TextRange(wb, we));
    }

    void TextFilter::Build()
    {
        Filters.resize(0);
        TextRange input_range(InputBuf, InputBuf + strlen(InputBuf));
        input_range.split(',', &Filters);

        CountGrep = 0;
        for (int i = 0; i != Filters.size(); i++)
        {
            TextRange& f = Filters[i];
            while (f.b < f.e && ImCharIsBlankA(f.b[0]))
                f.b++;
            while (f.e > f.b && ImCharIsBlankA(f.e[-1]))
                f.e--;
            if (f.empty())
                continue;
            if (Filters[i].b[0] != '-')
                CountGrep += 1;
        }
    }

    bool TextFilter::PassFilter(const char* text, const char* text_end) const
    {
        if (Filters.empty())
            return true;

        if (text == NULL)
            text = "";

        for (int i = 0; i != Filters.size(); i++)
        {
            const TextRange& f = Filters[i];
            if (f.empty())
                continue;
            if (f.b[0] == '-')
            {
                // Subtract
                if (ImStristr(text, text_end, f.b + 1, f.e) != NULL)
                    return false;
            }
            else
            {
                // Grep
                if (ImStristr(text, text_end, f.b, f.e) != NULL)
                    return true;
            }
        }

        // Implicit * grep
        if (CountGrep == 0)
            return true;

        return false;
    }
}