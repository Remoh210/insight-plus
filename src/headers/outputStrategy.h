#pragma once

#include "buffer.h"

namespace insight_plus
{
    class iOutputStrategy
    {
    public:
        virtual void writeOutput(Buffer& message) = 0;
        virtual ~iOutputStrategy() {}
    };
}