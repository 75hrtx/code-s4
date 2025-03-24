#include<stdio.h>

void wf(int b[],int m,int p[],int n) {
    int alloc[10];
    
    for(int i=0;i<n;i++)
        alloc[i]=-1;

    for(int i=0;i<n;i++) {
        int wf=-1;

        for(int j=0;j<m;j++) {
            if(b[j]>=p[i]) {
                if(wf==-1||b[j]>b[wf])
                    wf=j;
            }
        }

        if(wf!=-1) {
            alloc[i]=wf;
            b[wf]=p[i];
        }
    }

    printf("Process No.\tProcess Size\tBlock No.\n");
    for(int i=0;i<n;i++) {
        printf("%d\t\t%d\t\t",i+1,p[i]);
        if(alloc[i]!=-1)
            printf("%d\n",alloc[i]+1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int b[10];
    int p[10];
    int m,n;

    printf("Enter the no of memory blocks: ");
    scanf("%d",&m);

    printf("Enter the size of each memory block: \n");
    for(int i=0;i<m;i++) {
        scanf("%d",&b[i]);
    }

    printf("Enter the no of Process: ");
    scanf("%d",&n);

    printf("Enter the size of each processes: \n");
    for(int i=0;i<n;i++) {
        scanf("%d",&p[i]);
    }

    wf(b,m,p,n);

    return 0;
}
