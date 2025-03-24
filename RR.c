#include <stdio.h>

int main() {
	int n,b[20],w[20],t[20],rem[20]; //burst time, waiting time, turnaround time, remaining burst time
	float a=0,at=0; //avg waiting time, avg turnaround time
	int q,time=0;
	
	printf("Enter the total no of processes: ");
	scanf("%d",&n);
	
	printf("Enter the process burst time: ");
	for(int i=0;i<n;i++) {
		printf("p[%d]: ",i+1);
		scanf("%d",&b[i]);
		rem[i]=b[i];
		w[i]=0;
	}
	
	printf("Enter the time quantum: ");
	scanf("%d",&q);
	
    printf("\nGantt Chart: \n");
	//RR scheduling
	int i=0;
	while(1) {
		int all_done=1;
		
		for(i=0;i<n;i++) {
			if(rem[i] > 0) {
				all_done=0;
				printf("P[%d]__",i+1);
				if(rem[i]>q) {
					time += q;
					rem[i] -= q;
				}
				else {
					time += rem[i];
					w[i] = time - b[i];
					rem[i] = 0;
				}
			}
		}
		if(all_done) break;
	}
	
	printf("\nProcess \tBurst time \tCompletion time \tWaiting timr\t \tTat\n");
	
	for(int i=0;i<n;i++) {
		t[i] = b[i]+w[i]; //tat=bt+wt
		a += w[i];	//awt= awt+wt
		at += t[i];	//att= at+tt
		printf("P[%d]\t\t %d \t%d \t%d \t%d\n",i+1,b[i],t[i],w[i],t[i]);
	}	
	printf("\nAvg Waiting time: %.2f",a/n);
	printf("\nAvg Tat time: %.2f",at/n); 
}
