#include <iostream>
#include "Bases/Process.hpp"
#include "FCFS/FCFS.hpp"
#include "RR/RR.hpp"
#include "TSJF/SJF.hpp"
#include "Priority/Priority.hpp"
using namespace std;

void CreateProcesses(vector<Process*>& processes, int number_processes) {
    Scheduler* temp = new Scheduler();
    temp->GenerateProcesses(number_processes);
    while(! temp->processQueue.empty()) {
        processes.push_back(temp->processQueue.front());
        temp->processQueue.pop();
    }
}

void CreateFCFS(vector<Process*>& processes)
{
    cout<<"---------FCFS---------\n";
    FCFS* sch = new FCFS();
    sch->AddProcesses(processes);
    sch->Schedule();
    cout << endl;
    cout << "FCFS Scheduling Results:" << endl;
    sch->PrintResults(processes.size());
    cout<<"----------------------\n";
}

void CreateSJG(vector<Process*>& processes)
{
    cout<<"---------SJF----------\n";
    SJF* sch = new SJF();
    sch->AddProcesses(processes);
    sch->Schedule();
    cout << endl;
    cout << "SJF Scheduling Results:" << endl;
    sch->PrintResults(processes.size());
    cout<<"----------------------\n";
}

void CreateRR(vector<Process*>& processes)
{
    cout<<"---------RR-----------\n";
    int timeQuantum;
    cout << "Enter the time quantum: ";
    cin >> timeQuantum;
    RR* sch = new RR(timeQuantum);
    sch->AddProcesses(processes);
    sch->Schedule();
    cout << endl;
    cout << "RR Scheduling Results:" << endl;
    sch->PrintResults(processes.size());
    cout<<"----------------------\n";
}

void CreatePriority(vector<Process*>& processes)
{
    cout<<"---------Priority-----------\n";
    Priority* sch = new Priority();
    sch->AddProcesses(processes);
    sch->Schedule();
    cout << endl;
    cout << "Priority (non-preemptive) Scheduling Results:" << endl;
    sch->PrintResults(processes.size());
    cout<<"--------------------------\n";
}

void CreateAll(vector<Process*>& processes)
{
    CreateFCFS(processes);
    CreateSJG(processes);
    CreateRR(processes);
    CreatePriority(processes);
}

void GetProcessesFC(vector<Process*>& processes, int number_processes) {
    Process* p;
    for(int i = 0; i < number_processes; i++)
	{
        int pid = i + 1;
        int arrivalTime;
        int burstTime ;
        int priority;
        cout<< "----------P"<<pid<<"----------\n";
		cout<<"Enter the arrival time of the process " << pid <<": ";
		cin>>arrivalTime;
		cout<<"Enter the burst time of the process " << pid <<": ";
		cin>>burstTime;
        cout<<"Enter the priority of the process "<< pid <<" [Small represents lower priority]: ";
		cin>>priority;
        p = new Process(pid, arrivalTime, burstTime, priority);
        processes.push_back(p);
	}
}

void Menu() {
     cout<<"------CPU Scheduling------\n";
    cout << "Enter number of processes: ";
    int number_processes;
    cin >> number_processes;
    cout << "Do you want to create random data for each process [y/n]?  ";
    char order_ran = 'y';
    cin >> order_ran;
    vector<Process*> processes;
    switch (order_ran)
    {
        case 'n':
            GetProcessesFC(processes, number_processes);
            break;
        default:
            CreateProcesses(processes, number_processes);
            break;
    }
    int algorithm = 1;
    cout<< "_____________________\n" 
        << "1. FCFS\n" 
        << "2. SJF\n" 
        << "3. RR\n" 
        << "4. Priority\n"
        << "5. All\n"
        << "Select the algorithm you want to schedule with[1-5]: ";
    cin >> algorithm;
    switch(algorithm)
    {
        case 1:
            CreateFCFS(processes);
            break;
        case 2:
            CreateSJG(processes);
            break;
        case 3:
            CreateRR(processes);
            break;
        case 4:
            CreatePriority(processes);
            break;
        case 5:
            CreateAll(processes);
    }
}

int main() {
    Menu();
    cout << "...Goodbye!...";
}
