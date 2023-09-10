#include "Process.hpp"

bool Process::cmp_arrival(const Process* a, const Process* b)
{
    return a->arrivalTime < b->arrivalTime;
}

bool Process::cmp_burst(const Process* a, const Process* b)
{
    return a->burstTime < b->burstTime;
}

bool Process::cmp_prt(const Process* a, const Process* b)
{
    return a->priority < b->priority || (a->priority == b->priority && a->arrivalTime > b->arrivalTime);
}

Process* Process::Copy() {
    return new Process(pid, arrivalTime, burstTime, priority);
}