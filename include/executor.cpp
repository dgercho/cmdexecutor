#include "executor.hpp"
#include <iostream>
#include <cstdio>
#include <array>

Executor::Executor() {}

auto Executor::run_command(std::string command) -> ExecutorResult
{
    int exit_code = 0;
    std::array<char, 256> buffer {};
    std::string result;
#ifdef _WIN32
    FILE *pipe = _popen((command+" 2>&1").c_str(), "r");
#else
    FILE *pipe = popen((command+" 2>&1").c_str(), "r");
#endif

    try {
        std::size_t bytesread;
        while ((bytesread = std::fread(buffer.data(), sizeof(buffer.at(0)), sizeof(buffer), pipe)) != 0) {
            result += std::string(buffer.data(), bytesread);
        }
    } catch (...) {
#ifdef _WIN32
        _pclose(pipe);
#else
        pclose(pipe);
#endif
        throw;
    }
#ifdef _WIN32
        exit_code = _pclose(pipe);
#else
        exit_code = pclose(pipe);
#endif
    auto command_result = ExecutorResult(result,exit_code);
    return command_result;
}