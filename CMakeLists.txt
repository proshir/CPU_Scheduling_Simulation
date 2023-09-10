cmake_minimum_required(VERSION 3.0.0)
project(CPU_Scheduling VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(CPU_Scheduling 
    Bases/Process.cpp
    Bases/scheduler.cpp
    FCFS/FCFS.cpp
    #FCFS/FCFS_Test.cpp
    TSJF/SJF.cpp
    #TSJF/SJF_Test.cpp
    RR/RR.cpp
    #RR/RR_Test.cpp
    Priority/Priority.cpp
    #Priority/Priority_Test.cpp
    main.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
