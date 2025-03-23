#include <stdio.h>
int main()  {
    int n,bt[20],wt[20],tat[20],i,j;
    float avwt = 0, avtat = 0;
 
    printf("Enter Total Number of processes (max 20) : ");
    scanf("%d", &n);
    
    printf("\nEnter Process Burst Time\n");
    for(i=0;i<n;i++) {
        printf("P[%d] : ",i+1);
        scanf("%d",&bt[i]);
    }
    wt[0]=0;
    for(i=1;i<n;i++) {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
    
    printf("Gantt chart: \n");
    for(int k =0;k<n;k++) {
        printf("P[%d] __ ",k+1);
    }
    printf("\n\n Process \tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];  // Turnaround Time = Burst Time + Waiting Time
        avwt += wt[i];  // Sum of Waiting Times
        avtat += tat[i]; // Sum of Turnaround Times

        printf("P[%d] \t\t%d \t\t%d \t\t%d \t\t%d\n", i+1, bt[i], tat[i], wt[i], tat[i]);
    }

    
    printf("\nAverage Waiting Time: %.2f", avwt/n);
    printf("\nAverage Turnaround Time: %.2f\n", avtat/n);
    
    return 0;
}
