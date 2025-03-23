#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
int main()
{
    key_t key = 12345;
    printf("Reading from Shared Memory (Key = %d)\n",key);
    int shmid = shmget(key, sizeof(int), 0666);
    printf("shmid:\t%d\n", shmid);
    if (shmid == -1)
    {
        printf("Error accessing shared memory Failure.\n");
        exit(0);
    }

    void *shmad = shmat(shmid, NULL, 0);
    printf("shmad:\t%p\n", shmad);
    int n = *((int *)shmad);
    printf("\nRead '%d' from SHM complete.\n", n);
    shmdt(shmad);
    shmctl(shmid, IPC_RMID, 0);
    printf("SHM destroyed.\n\n");
    long int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }
    printf("fact(%d) = %ld\n\n", n, res);
    return 0;
}
