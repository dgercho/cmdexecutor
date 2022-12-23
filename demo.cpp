#include "include/executor.hpp"
#include <iostream>

auto main() -> int
{
    auto exec = Executor();
    ExecutorResult result = exec.run_command("whoami");

    if(result.get_exit_code() == 0)
    {
        std::cout << "STDOUT: " + result.get_stdout() << std::endl;
    }
    else
    {
        std::cout << "STDERR: " + result.get_stderr() << std::endl;
    }

    return 0;
}