#pragma once

namespace insight_plus
{
    class iDrawStrategy
    {
    public:
        virtual void Setup() = 0;
        virtual void Draw() = 0;
        virtual void Render() = 0;
        virtual ~iDrawStrategy() = default;
    };
}