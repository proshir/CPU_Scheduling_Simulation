#include <iostream>
#include <chrono>
#include "../Bases/Process.hpp"
#include "../Bases/scheduler.hpp"
#include "SJF.hpp"

using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    SJF* sjf = new SJF();
    sjf->GenerateProcesses(n);
    sjf->Schedule();
    cout << endl;
    cout << "SJF Scheduling Results:" << endl;
    sjf->PrintResults(n);
    return 0;
}
