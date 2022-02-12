int main(int argc, char *argv[])
{
unsigned long long vmlinux_size, vmlinux_load_addr, vmlinuz_load_addr;
struct stat sb;
if (argc != 3) {
fprintf(stderr, "Usage: %s <pathname> <vmlinux_load_addr>\n",
argv[0]);
return EXIT_FAILURE;
}
if (stat(argv[1], &sb) == -1) {
perror("stat");
return EXIT_FAILURE;
}
errno = 0;
if (sscanf(argv[2], "%llx", &vmlinux_load_addr) != 1) {
if (errno != 0)
perror("sscanf");
else
fprintf(stderr, "No matching characters\n");
return EXIT_FAILURE;
}
vmlinux_size = (uint64_t)sb.st_size;
vmlinuz_load_addr = vmlinux_load_addr + vmlinux_size;
vmlinuz_load_addr += (16 - vmlinux_size % 16);
printf("0x%llx\n", vmlinuz_load_addr);
return EXIT_SUCCESS;
}
