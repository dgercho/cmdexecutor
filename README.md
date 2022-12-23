# CmdExecutor

Simple and lightweight cmd executor C++ library. Runs on Windows, Linux and MacOS.

## How does it works?
Using pipes by implementing the `popen` (or `_popen` for Windows) API call.

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