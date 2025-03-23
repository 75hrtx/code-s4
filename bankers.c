#include <stdio.h>

int main() {
    int m, n, i, j, k, y, ind = 0;
    int alloc[20][20], max[20][20], avail[20], work[20], need[20][20];
    int finish[20], safeseq[20];
    printf("Enter the number of process and resources: ");
    scanf("%d%d", &n, &m);
    printf("Enter the allocation matrix\n");
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the max matrix\n");
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the available matrix: \n");
    for (i=0;i<m;i++) {
        scanf("%d",&avail[i]);
    }

    for (i=0;i<m;i++) {
        work[i] = avail[i];
    }
    for (i=0;i<n;i++) {
        finish[i] = 0;
    }

    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("Need matrix is : ");
    for (i=0;i<n;i++) {
        printf("\n");
        for (j=0;j<m;j++) {
            printf("%d ",need[i][j]);
        }
    }

    for (k=0;k<n;k++) {
        for (i=0;i<n;i++) {
            if (finish[i] == 0) {
                int flag = 0;
                for (j=0;j<m;j++) {
                    if (need[i][j] > work[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    safeseq[ind++] = i;
                    for (y=0;y<m;y++) {
                        work[y] += alloc[i][y];
                    }
                    finish[i]=1;
                }
            }
        }
    }

    printf("\nFollowing the safe seq\n");
    for (i=0;i<n;i++) {
        printf("P%d ", safeseq[i]);
    }
}
