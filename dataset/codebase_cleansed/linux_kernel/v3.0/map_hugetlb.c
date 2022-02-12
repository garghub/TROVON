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
addr = mmap(ADDR, LENGTH, PROTECTION, FLAGS, 0, 0);
if (addr == MAP_FAILED) {
perror("mmap");
exit(1);
}
printf("Returned address is %p\n", addr);
check_bytes(addr);
write_bytes(addr);
read_bytes(addr);
munmap(addr, LENGTH);
return 0;
}
