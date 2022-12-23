#pragma once
#include <string>

class ExecutorResult
{
public:
    ExecutorResult(std::string, std::string, int);
    /* Get stdout of command. */
    auto get_stdout() -> std::string;
    /* Get stderr of command. */
    auto get_stderr() -> std::string;
    /* Get exit code. */
    auto get_exit_code() -> int;

private:
    std::string executor_stdout;
    std::string executor_stderr;
    int executor_exit_code;
};