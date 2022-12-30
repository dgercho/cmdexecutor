# CmdExecutor
Simple and lightweight cmd executor C++ library. Runs on Windows, Linux and macOS.

[![Windows CI](https://github.com/dgercho/cmdexecutor/actions/workflows/msvc.yml/badge.svg?branch=main)](https://github.com/dgercho/cmdexecutor/actions/workflows/msvc.yml)

## How does it works?
Using pipes by implementing the `popen` (or `_popen` for Windows) function.

Please note that this project **won't work** for UWF (Universal Windows Platform) applications:
> Pipe functionality is not available to UWP apps.

[Click here for more information](https://learn.microsoft.com/en-us/cpp/cppcx/crt-functions-not-supported-in-universal-windows-platform-apps?view=msvc-170)

## How to use the library?
First, copy the `include` folder to your project. Note that this library uses CMake.
To include with CMake, just add those lines to youe CMake project:

```
    ...
    include_directories(include)
    add_subdirectory(include/cmdexecutor)

    // add_executable(...)
    target_link_libraries(YourProject PRIVATE CmdExecutor)
```

After including the library to your project, Let's run a simple command:

```
    auto exec = Executor();
    ExecutorResult result = exec.run_command("whoami");
```

We can check also the exit code of our execution:

```
    std::cout << "Output: " + result.get_result() << std::endl;
    std::cout << "Exit code: " + std::string(result.get_exit_code()) << std::endl;
```

For more information check the sample `demo.cpp` implementation.