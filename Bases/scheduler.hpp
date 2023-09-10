#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Process.hpp"
#include <cstdlib>
#include <ctime>
#include "iostream"
#include <vector>
#include "queue"
#include <algorithm>

using namespace std;

class Scheduler {
public:
    void AddProcess(Process* p);
    void AddProcesses(vector<Process*> processes);
    void GenerateProcesses(int n);
    void PrintResults(int processCount);
    void ready_filler(queue<Process*>& ready_queue, int& time, bool check=false);
    void SortProcessQueue();
    Process* GetMinReady(queue<Process*>& ready_queue,  bool (*cmp_min)(const Process*, const Process*));

    queue<Process*> all_processes;
    queue<Process*> processQueue;
    vector<pair<int, int>> processOrder;
};

#endif