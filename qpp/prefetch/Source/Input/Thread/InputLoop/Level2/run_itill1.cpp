#ifndef run_cpp_cpp
#define run_cpp_cpp

#include "..\..\input_loop_thread.h"
#include "..\..\..\..\Core\start_process.h"
#include "..\..\..\..\Input\const_input.h"
#include "..\..\..\..\Output\stdout.h"

#define Parent InputLoopThread::ConsoleCommandFunction_Level2

void Parent::run_quiet(QString command)
{
    StartProcess::startProcess(command);
}

void Parent::run(QString command)
{
    using namespace Const_Input::Message;

    StdOut::printLine(TryingToRun1);
    StdOut::printLine(TryingToRun2 + command);

    run_quiet(command);
}

#endif
