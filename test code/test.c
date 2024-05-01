#include<stdio.h>

struct process {
    int pid;
    int at;
    int bt;
    int wt;
    int ct;
    int tat;
};

int main() {
    int num_process;

    printf("Enter the number of processes:");
    scanf("%d", &num_process);

    struct process p[num_process];

    printf("Enter the Process ID, Arrival Time, and Burst Time of each process.\n");
    for (int i = 0; i < num_process; i++) {
        printf("Process %d: \n", i + 1);
        printf("Enter the Process ID: ");
        scanf("%d", &p[i].pid);
        printf("Enter the Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Enter the Burst Time: ");
        scanf("%d", &p[i].bt);
    }

   

    for (int i = 0; i < num_process; i++) {
        for (int j = 0; j < num_process - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Calculating completion time, turnaround time, and waiting time
    int temp = p[0].bt;
    p[0].ct = p[0].bt;
    p[0].tat = p[0].ct - p[0].at;
    for (int i = 1; i < num_process; i++) {
        p[i].ct = temp + p[i].bt;
        temp = p[i].ct;
        p[i].tat = p[i].ct - p[i].at; 
        p[i].wt = p[i].tat - p[i].bt;
    }

    int totalTAT = 0, totalWT = 0;
    for (int i = 0; i < num_process; i++) {
        totalTAT += p[i].tat;
        totalWT += p[i].wt;
    }

    // Calculating average turnaround time and average waiting time
    float avgTAT = (float)totalTAT / num_process;
    float avgWT = (float)totalWT / num_process;

    
    printf("\nProcess ID  Arrival Time  Burst Time  Completion Time  Turnaround Time  Waiting Time\n");
    for (int i = 0; i < num_process; i++) {
        printf("%9d%14d%12d%16d%16d%14d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

   
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT);
    printf("Average Waiting Time: %.2f\n", avgWT);

    return 0;
}
