#include "src/executor.hpp"
#include <iostream>

auto main() -> int
{
    auto exec = Executor();
    auto result = exec.run_command("whoami");
    std::cout << "STDOUT: " + result.get_stdout() << std::endl;
    std::cout << "STDERR: " + result.get_stderr() << std::endl;
    std::cout << "EXIT CODE: " + std::to_string(result.get_exit_code()) << std::endl;
    return 0;
}