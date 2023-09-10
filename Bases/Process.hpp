#ifndef PROCESS_H
#define PROCESS_H

class Process {
public:
    int pid;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    int completionTime;
    int remainingTime;
    int priority;
    static bool cmp_arrival(const Process* a, const Process* b);
    static bool cmp_burst(const Process* a, const Process* b);
    static bool cmp_prt(const Process* a, const Process* b);
    Process* Copy();
    Process(int pid, int arrivalTime, int burstTime, int priority)
        : pid(pid), arrivalTime(arrivalTime), burstTime(burstTime), remainingTime(burstTime), priority(priority), waitingTime(0), turnaroundTime(0), completionTime(0) {}
};

#endif