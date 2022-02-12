static void check_bytes(char *addr)
{
printf("First hex is %x\n", *((unsigned int *)addr));
}
static void write_bytes(char *addr)
{
unsigned long i;
for (i = 0; i < LENGTH; i++)
*(addr + i) = (char)i;
}
static void read_bytes(char *addr)
{
unsigned long i;
check_bytes(addr);
for (i = 0; i < LENGTH; i++)
if (*(addr + i) != (char)i) {
printf("Mismatch at %lu\n", i);
break;
}
}
int main(void)
{
void *addr;
int fd;
fd = open(FILE_NAME, O_CREAT | O_RDWR, 0755);
if (fd < 0) {
perror("Open failed");
exit(1);
}
addr = mmap(ADDR, LENGTH, PROTECTION, FLAGS, fd, 0);
if (addr == MAP_FAILED) {
perror("mmap");
unlink(FILE_NAME);
exit(1);
}
printf("Returned address is %p\n", addr);
check_bytes(addr);
write_bytes(addr);
read_bytes(addr);
munmap(addr, LENGTH);
close(fd);
unlink(FILE_NAME);
return 0;
}
