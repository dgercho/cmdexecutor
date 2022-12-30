#include "cmdexecutor/executor.hpp"
#include <iostream>

auto main() -> int
{
    auto exec = Executor();
    ExecutorResult result = exec.run_command("whoami");
    std::cout << "Output: " + result.get_result() << std::endl;
    std::cout << "Exit code: " + std::to_string(result.get_exit_code()) << std::endl;

    if(result.get_exit_code() != 0)
    {
        std::cout << "Error!";
    }

    return 0;
}