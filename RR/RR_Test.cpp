#include <iostream>
#include <chrono>
#include "../Bases/Process.hpp"
#include "../Bases/scheduler.hpp"
#include "RR.hpp"

using namespace std;

int main() {
    int n, timeQuantum;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter the time quantum: ";
    cin >> timeQuantum;
    RR* rr = new RR(timeQuantum);
    rr->GenerateProcesses(n);
    rr->Schedule();
    cout << endl;
    cout << "RR Scheduling Results:" << endl;
    rr->PrintResults(n);
    return 0;
}
