#pragma once
#include <string>
#include "executor_result.hpp"

class Executor
{
public:
    Executor();
    /* Execute a command. */
    auto run_command(std::string) -> ExecutorResult;
};