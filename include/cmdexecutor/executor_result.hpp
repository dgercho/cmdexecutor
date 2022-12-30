#pragma once
#include <string>

class ExecutorResult
{
public:
    ExecutorResult(std::string, int);
    /* Get command result. */
    auto get_result() -> std::string;
    /* Get exit code. */
    auto get_exit_code() -> int;

private:
    std::string executor_result;
    int executor_exit_code;
};