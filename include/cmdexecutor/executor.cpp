#ifdef _WIN32
#define popen _popen
#define pclose _pclose
#endif

#include "executor.hpp"
#include <iostream>
#include <cstdio>
#include <array>
#include <vector>

Executor::Executor() {}

constexpr int BUFFER_SIZE = 1024 * 16;
auto Executor::run_command(std::string command) -> ExecutorResult
{
    // Setup buffer and output vector.
    std::array<uint8_t, BUFFER_SIZE> buffer {};
    std::vector<uint8_t> output{0};

    //Run command using pipe
    FILE *pipe = popen((command+" 2>&1").c_str(), "r");

    //Read execution output
    try {
        std::size_t bytesread = 0;
        while ((bytesread = std::fread(buffer.data(), sizeof(buffer.at(0)), sizeof(buffer), pipe)) != 0) {
            output.reserve(output.size() + bytesread);
            output.insert(output.end(), buffer.begin(), buffer.end());
            buffer = {0};
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }

    auto command_result = ExecutorResult(std::string(output.begin(),output.end()),pclose(pipe));
    return command_result;
}