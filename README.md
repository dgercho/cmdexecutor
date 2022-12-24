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
    add_subdirectory(include)
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
    if(result.get_exit_code() == 0)
    {
        std::cout << "STDOUT: " + result.get_stdout() << std::endl;
    }
    else
    {
        std::cout << "STDERR: " + result.get_stderr() << std::endl;
    }
```

For more information check the sample `demo.cpp` implementation.