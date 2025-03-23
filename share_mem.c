#include <stdio.h>
#include <sys/shm.h>

int main() {
    key_t key = 12345;
    printf("Writing to Shared Memory (Key = %ld)\n", (long)key);

    int shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget failed");
        return 1;
    }

    void *shmad = shmat(shmid, NULL, 0);
    if (shmad == (void *)-1) {
        perror("shmat failed");
        return 1;
    }

    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);

    *((int *)shmad) = n;

    printf("Write '%d' to SHM complete.\n", n);
    return 0;
}
