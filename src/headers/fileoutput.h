#pragma once 

#include "buffer.h"

#include "outputStrategy.h"

// TODO: Implement file output strategy

namespace insight_plus
{
    class FileOutStrategy : public iOutputStrategy
    {
    public:
        void writeOutput(Buffer& message) override;
    };
}