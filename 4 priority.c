#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int bt;   // burst time
    int wt;   // waiting time
    int tat;  // turnaround time
    int pr;   // priority
    int pno;  // process number
} Process;

int main() {
    int n;
    printf("Enter the total no of processes: ");
    scanf("%d", &n);

    // Dynamically allocate memory for processes
    Process *p = (Process*)malloc(n * sizeof(Process));

    printf("Enter the Burst Time and Priority:\n");
    // Loop to read Burst Time and Priority together for each process
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &p[i].bt, &p[i].pr);  // Read both burst time and priority on the same line
        p[i].pno = i + 1;  // Assigning process number
        p[i].wt = 0;  // Initialize waiting time to 0
    }

    // Sort processes based on priority (ascending order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].pr > p[j].pr) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time
    int total_wt = 0, total_tat = 0;
    p[0].wt = 0; // First process has 0 waiting time
    for (int i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;  // Waiting time = previous process' waiting time + burst time
    }

    // Printing table headers
    printf("\nProcess\tBurst Time\tWaiting Time\tCompletion Time\tTurnaround Time\n");

    // Printing process details
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].bt + p[i].wt;  // Turnaround time = burst time + waiting time
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pno, p[i].bt, p[i].wt, p[i].wt + p[i].bt, p[i].tat);
    }

    // Display Gantt chart
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("p[%d]__", p[i].pno);
    }
    printf("\n");

    // Calculate and display average waiting time and turnaround time
    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);

    // Free dynamically allocated memory
    free(p);

    return 0;
}
