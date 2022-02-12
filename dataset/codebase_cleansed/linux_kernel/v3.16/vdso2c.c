static void fail(const char *format, ...)
{
va_list ap;
va_start(ap, format);
fprintf(stderr, "Error: ");
vfprintf(stderr, format, ap);
unlink(outfilename);
exit(1);
va_end(ap);
}
static void go(void *addr, size_t len, FILE *outfile, const char *name)
{
Elf64_Ehdr *hdr = (Elf64_Ehdr *)addr;
if (hdr->e_ident[EI_CLASS] == ELFCLASS64) {
go64(addr, len, outfile, name);
} else if (hdr->e_ident[EI_CLASS] == ELFCLASS32) {
go32(addr, len, outfile, name);
} else {
fail("unknown ELF class\n");
}
}
int main(int argc, char **argv)
{
int fd;
off_t len;
void *addr;
FILE *outfile;
char *name, *tmp;
int namelen;
if (argc != 3) {
printf("Usage: vdso2c INPUT OUTPUT\n");
return 1;
}
name = strdup(argv[2]);
namelen = strlen(name);
if (namelen >= 3 && !strcmp(name + namelen - 3, ".so")) {
name = NULL;
} else {
tmp = strrchr(name, '/');
if (tmp)
name = tmp + 1;
tmp = strchr(name, '.');
if (tmp)
*tmp = '\0';
for (tmp = name; *tmp; tmp++)
if (*tmp == '-')
*tmp = '_';
}
fd = open(argv[1], O_RDONLY);
if (fd == -1)
err(1, "%s", argv[1]);
len = lseek(fd, 0, SEEK_END);
if (len == (off_t)-1)
err(1, "lseek");
addr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
if (addr == MAP_FAILED)
err(1, "mmap");
outfilename = argv[2];
outfile = fopen(outfilename, "w");
if (!outfile)
err(1, "%s", argv[2]);
go(addr, (size_t)len, outfile, name);
munmap(addr, len);
fclose(outfile);
return 0;
}
