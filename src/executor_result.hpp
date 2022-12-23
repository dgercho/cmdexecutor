#pragma once
#include <string>

class ExecutorResult
{
public:
    ExecutorResult(std::string, std::string, int);
    auto get_stdout() -> std::string;
    auto get_stderr() -> std::string;
    auto get_exit_code() -> int;

private:
    std::string executor_stdout;
    std::string executor_stderr;
    int executor_exit_code;
};