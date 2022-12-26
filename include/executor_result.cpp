#include "executor_result.hpp"

ExecutorResult::ExecutorResult(std::string result, int result_exit_code) : executor_result(result), executor_exit_code(result_exit_code)
{
}

auto ExecutorResult::get_result() -> std::string
{
    return this->executor_result;
}

auto ExecutorResult::get_exit_code() -> int
{
    return this->executor_exit_code;
}