static void fail(const char *format, ...)
{
va_list ap;
va_start(ap, format);
fprintf(stderr, "Error: ");
vfprintf(stderr, format, ap);
if (outfilename)
unlink(outfilename);
exit(1);
va_end(ap);
}
static void go(void *raw_addr, size_t raw_len,
void *stripped_addr, size_t stripped_len,
FILE *outfile, const char *name)
{
Elf64_Ehdr *hdr = (Elf64_Ehdr *)raw_addr;
if (hdr->e_ident[EI_CLASS] == ELFCLASS64) {
go64(raw_addr, raw_len, stripped_addr, stripped_len,
outfile, name);
} else if (hdr->e_ident[EI_CLASS] == ELFCLASS32) {
go32(raw_addr, raw_len, stripped_addr, stripped_len,
outfile, name);
} else {
fail("unknown ELF class\n");
}
}
static void map_input(const char *name, void **addr, size_t *len, int prot)
{
off_t tmp_len;
int fd = open(name, O_RDONLY);
if (fd == -1)
err(1, "%s", name);
tmp_len = lseek(fd, 0, SEEK_END);
if (tmp_len == (off_t)-1)
err(1, "lseek");
*len = (size_t)tmp_len;
*addr = mmap(NULL, tmp_len, prot, MAP_PRIVATE, fd, 0);
if (*addr == MAP_FAILED)
err(1, "mmap");
close(fd);
}
int main(int argc, char **argv)
{
size_t raw_len, stripped_len;
void *raw_addr, *stripped_addr;
FILE *outfile;
char *name, *tmp;
int namelen;
if (argc != 4) {
printf("Usage: vdso2c RAW_INPUT STRIPPED_INPUT OUTPUT\n");
return 1;
}
name = strdup(argv[3]);
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
map_input(argv[1], &raw_addr, &raw_len, PROT_READ);
map_input(argv[2], &stripped_addr, &stripped_len, PROT_READ);
outfilename = argv[3];
outfile = fopen(outfilename, "w");
if (!outfile)
err(1, "%s", argv[2]);
go(raw_addr, raw_len, stripped_addr, stripped_len, outfile, name);
munmap(raw_addr, raw_len);
munmap(stripped_addr, stripped_len);
fclose(outfile);
return 0;
}
