#include <iostream>
#include <chrono>
#include "../Bases/Process.hpp"
#include "../Bases/scheduler.hpp"
#include "FCFS.hpp"

using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    FCFS* fcfs = new FCFS();
    fcfs->GenerateProcesses(n);
    fcfs->Schedule();
    cout << endl;
    cout << "FCFS Scheduling Results:" << endl;
    fcfs->PrintResults(n);
    return 0;
}
