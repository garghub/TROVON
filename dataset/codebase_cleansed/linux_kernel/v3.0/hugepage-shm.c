int main(void)
{
int shmid;
unsigned long i;
char *shmaddr;
if ((shmid = shmget(2, LENGTH,
SHM_HUGETLB | IPC_CREAT | SHM_R | SHM_W)) < 0) {
perror("shmget");
exit(1);
}
printf("shmid: 0x%x\n", shmid);
shmaddr = shmat(shmid, ADDR, SHMAT_FLAGS);
if (shmaddr == (char *)-1) {
perror("Shared memory attach failure");
shmctl(shmid, IPC_RMID, NULL);
exit(2);
}
printf("shmaddr: %p\n", shmaddr);
dprintf("Starting the writes:\n");
for (i = 0; i < LENGTH; i++) {
shmaddr[i] = (char)(i);
if (!(i % (1024 * 1024)))
dprintf(".");
}
dprintf("\n");
dprintf("Starting the Check...");
for (i = 0; i < LENGTH; i++)
if (shmaddr[i] != (char)i)
printf("\nIndex %lu mismatched\n", i);
dprintf("Done.\n");
if (shmdt((const void *)shmaddr) != 0) {
perror("Detach failure");
shmctl(shmid, IPC_RMID, NULL);
exit(3);
}
shmctl(shmid, IPC_RMID, NULL);
return 0;
}
