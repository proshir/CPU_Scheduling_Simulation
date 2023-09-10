#include "scheduler.hpp"



void Scheduler::GenerateProcesses(int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        int pid = i + 1;
        int arrivalTime = rand() % 15;
        int burstTime = rand() % 17 + 1;
        int priority = rand() % 10 + 1;
        Process* p = new Process(pid, arrivalTime, burstTime, priority);
        AddProcess(p);
        cout << "Generated process " << pid << " with arrival time " << arrivalTime << " and burst time " << burstTime << " and priority " << priority << endl;
    }
}

void Scheduler::AddProcesses(vector<Process*> processes) {
    for (auto process: processes) {
        AddProcess(process->Copy());
    }
}

void Scheduler::PrintResults(int processCount) {
    Process* p;
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    while (!all_processes.empty()) {
        p = all_processes.front();
        all_processes.pop();
        cout << "Process " << p->pid << "| Waiting Time: " << p->waitingTime << "| Turnaround Time: " << p->turnaroundTime << "| Completion Time: " << p->completionTime<<endl; 
        totalWaitingTime += p->waitingTime;
        totalTurnaroundTime += p->turnaroundTime;
    }
    cout<<endl;
    cout << "Average waiting time: " << float(totalWaitingTime) / processCount << endl;
    cout << "Average turnaround time: " << float(totalTurnaroundTime) / processCount << endl;

    cout << "Order of processes scheduled: [";
    for (int i = 0; i < processOrder.size(); i++) {
        cout << "Process " << processOrder[i].first << " for " << processOrder[i].second << "ms";
        if (i < processOrder.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void Scheduler::AddProcess(Process* p) {
    processQueue.push(p);
    all_processes.push(p);
}

void Scheduler::SortProcessQueue() {
    std::vector<Process*> v;
    while (!processQueue.empty()) {
        v.push_back(processQueue.front());
        processQueue.pop();
    }

    sort(v.begin(), v.end(), Process::cmp_arrival);
    for (Process* i : v) 
        processQueue.push(i);
}

void Scheduler::ready_filler(queue<Process*>& ready_queue, int& time, bool check) {
    Process* p;
    while(!processQueue.empty()) {
        p = processQueue.front();

        if (check && ready_queue.empty() && time < p->arrivalTime)
            time = p->arrivalTime;

        if (p->arrivalTime <= time) {
            processQueue.pop();
            ready_queue.push(p);
        } 
        else
            break;
    }
}

Process* Scheduler::GetMinReady(queue<Process*>& ready_queue, bool (*cmp_min)(const Process*, const Process*))
{
    Process* min_process = 0;
    std::vector<Process*> v;
    while (!ready_queue.empty()) {
        if (min_process == 0 || cmp_min(ready_queue.front(), min_process))
            min_process = ready_queue.front();
        v.push_back(ready_queue.front());
        ready_queue.pop();
    }
    for (Process* i : v)
        if (min_process != i)
            ready_queue.push(i);
    return min_process;
}