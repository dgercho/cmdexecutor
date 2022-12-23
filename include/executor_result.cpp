#include "executor_result.hpp"

ExecutorResult::ExecutorResult(std::string result_stdout, std::string result_stderr, int result_exit_code) : executor_stdout(result_stdout), executor_stderr(result_stderr), executor_exit_code(result_exit_code)
{
}

auto ExecutorResult::get_stdout() -> std::string
{
    return this->executor_stdout;
}

auto ExecutorResult::get_stderr() -> std::string
{
    return this->executor_stderr;
}

auto ExecutorResult::get_exit_code() -> int
{
    return this->executor_exit_code;
}