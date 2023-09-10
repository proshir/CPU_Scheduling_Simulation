![CPUSchedulingAlgorithmsinOperatingSystems3](https://github.com/proshir/CPU_Scheduling_Simulation/assets/19504971/87b1a01a-a387-4ab9-962d-059c07d3a99a)

## Description
CPU scheduling is a critical aspect of optimizing computer system performance. This project explores four popular CPU scheduling algorithms: First Come First Serve (FCFS), Shortest Job First (SJF), Round Robin (RR), and Priority Scheduling. For each algorithm, a simulation in C++ is embedded for testing and analysis.

<b>FCFS (First Come First Serve):</b> This non-preemptive algorithm executes processes in the order they arrive, running each until completion.

<b>SJF (Shortest Job First):</b> Also non-preemptive, SJF prioritizes processes with the shortest estimated execution time. If multiple processes have the same estimate, the first to arrive runs first.

<b>RR (Round Robin):</b> RR allocates a time slice (quantum) to each process in a circular fashion. If a process doesn't finish within its quantum, the CPU switches to the next in line, ensuring fairness.

<b>Priority Scheduling:</b> Processes are assigned priorities, with the highest-priority process executed first. In case of ties, the process that arrived earlier takes precedence. This algorithm is preemptive.

The simulation outputs metrics like waiting time, turnaround time, and completion time for each algorithm. These metrics help evaluate efficiency and fairness, offering insights for optimizing the scheduling algorithm.

The project includes a sample dataset of processes and their attributes, generating outputs for each scheduling algorithm. The simulator provides accurate results and aids the selection of the most suitable algorithm based on specific system requirements.

## Building Instructions:
To build the simulator, use CMake. The output program can be found in the "build" directory.

This project enables a comprehensive understanding of CPU scheduling algorithms and offers a tool to assess their performance under various scenarios.

## Report
Certainly, it's great to know that there is a comprehensive report available in PDF format within the repository. This report likely contains detailed information on the project, its objectives, methodologies, and, most importantly, the results obtained from the CPU scheduling simulations. Users can refer to the "Report.pdf" file for in-depth insights and analysis of the project's findings.
