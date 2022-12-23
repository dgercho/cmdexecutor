#pragma once
#include <string>
#include "executor_result.hpp"

class Executor
{
public:
    Executor();
    auto run_command(std::string) -> ExecutorResult;
};