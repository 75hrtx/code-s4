#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int bt;
	int wt;
	int tat;
	int pr;
	int pno;
} process;

int main() {
	int n;
	printf("Enter the total no of process: ");
	scanf("%d",&n);
	process*p=(process*)malloc(n*sizeof(process));
	
	printf("Enter the burst time and priority: \n");
	for(int i=0;i<n;i++) {
		printf("Process %d : ",i+1);
		scanf("%d %d",&p[i].bt,&p[i].pr);
		p[i].pno=i+1;
		p[i].wt=0;
	}
	
	for(int i=0;i<n-1;i++) {
		for(int j=i+1;j<n;j++) {
			if(p[i].pr > p[j].pr) {
				process temp = p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	// Calculate waiting time and turnaround time
	int Twt=0,Ttu=0;
	p[0].wt=0;
	for(int i=1;i<n;i++) {
		p[i].wt=p[i-1].wt+p[i-1].bt;
	}
	
	printf("\nProcess\tBurst Time\tWaiting Time\tCompletion Time\tTurnaround Time\n");
	for(int i=0;i<n;i++) {
		p[i].tat = p[i].bt+p[i].wt;
		Twt += p[i].wt;
		Ttu += p[i].tat;
		printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pno, p[i].bt, p[i].wt, p[i].wt + p[i].bt, p[i].tat);
	}
	
	printf("\nGantt Chart\n");
	for(int i=0;i<n;i++) {
		printf("p[%d]__",p[i].pno);
	}
	
	printf("\nAvg Waiting time: %.2f",(float)Twt/n);
	printf("\nAvg Turnaround time: %.2f",(float)Ttu/n);
	
	free(p);
	return 0;
}
