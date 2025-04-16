#pragma once

// TODO: Impement smth similar to UFUNCTION(exec)
class iCommand {
public:
    virtual ~iCommand() {}
    virtual void Execute() const = 0;
};