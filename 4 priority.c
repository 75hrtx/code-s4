#include <stdio.h>

int main() {
	int n,b[20],w[20],t[20],pr[20],pi[20]; //burst time, waiting time, turnaround time
	float a=0,at=0; //avg waiting time, avg turnaround time
	int temp;
	
	printf("Enter the total no of processes: ");
	scanf("%d",&n);
	
	printf("Enter the process burst time: ");
	for(int i=0;i<n;i++) {
		printf("p[%d]: ",i+1);
		scanf("%d",&b[i]);
		printf("p[%d] Priority: ",i+1);
		scanf("%d",&pr[i]);
		pi[i]=i+1;
	}
	
	//sort based on priority
	for(int i=0;i<n-1;i++) {
		for(int j=i+1;j<n;j++) {
			if(pr[i] > pr[j]) {
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
				
				temp=pr[i];
				pr[i]=pr[j];
				pr[j]=temp;
				
				temp=pi[i];
				pi[i]=pi[j];
				pi[j]=temp;
			}
		}
	}
	
	w[0]=0;
	for(int i=1;i<n;i++) {
		w[i]=0;
		for(int j=0;j<i;j++)
			w[i]+=b[j];
	}
	printf("Gantt Chart\n");
	for(int k=0;k<n;k++) {
		printf("P[%d]__",pi[k]);
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
