#include "RR.hpp"

void RR::Schedule() {
    int time = 0;
    SortProcessQueue();
    queue<Process*> ready_queue;
    Process* p;
    while (!processQueue.empty() || !ready_queue.empty()) {

        ready_filler(ready_queue, time, true);

        p = ready_queue.front();
        ready_queue.pop();

        if (p->remainingTime <= timeQuantum) {
            time += p->remainingTime;
            processOrder.push_back({p->pid, p->remainingTime});
            p->remainingTime = 0;
        } else {
            time += timeQuantum;
            p->remainingTime -= timeQuantum;
            processOrder.push_back({p->pid, timeQuantum}); 

            ready_filler(ready_queue, time);

            ready_queue.push(p);
        }

        if (p->remainingTime == 0) {
            p->completionTime = time;
            p->waitingTime = time - p->arrivalTime - p->burstTime;
            p->turnaroundTime = p->completionTime - p->arrivalTime;
        }
    }
}