#include <iostream>
#include <chrono>
#include "../Bases/Process.hpp"
#include "../Bases/scheduler.hpp"
#include "Priority.hpp"

using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    Priority* prt = new Priority();
    prt->GenerateProcesses(n);
    prt->Schedule();
    cout << endl;
    cout << "Priority (non-preemptive) Scheduling Results:" << endl;
    prt->PrintResults(n);
    return 0;
}
