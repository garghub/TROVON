static void fail(const char *fmt, ...)
{
va_list ap;
failed = 1;
fprintf(stderr, "%s: ", argv0);
va_start(ap, fmt);
vfprintf(stderr, fmt, ap);
va_end(ap);
exit(EXIT_FAILURE);
}
static void cleanup(void)
{
if (failed && outfile != NULL)
unlink(outfile);
}
static Elf32_Word read_elf_word(Elf32_Word word, bool swap)
{
return swap ? bswap_32(word) : word;
}
static Elf32_Half read_elf_half(Elf32_Half half, bool swap)
{
return swap ? bswap_16(half) : half;
}
static void write_elf_word(Elf32_Word val, Elf32_Word *dst, bool swap)
{
*dst = swap ? bswap_32(val) : val;
}
int main(int argc, char **argv)
{
const Elf32_Ehdr *inhdr;
bool clear_soft_float;
const char *infile;
Elf32_Word e_flags;
const void *inbuf;
struct stat stat;
void *outbuf;
bool swap;
int outfd;
int infd;
atexit(cleanup);
argv0 = argv[0];
if (argc != 3)
fail("Usage: %s [infile] [outfile]\n", argv[0]);
infile = argv[1];
outfile = argv[2];
infd = open(infile, O_RDONLY);
if (infd < 0)
fail("Cannot open %s: %s\n", infile, strerror(errno));
if (fstat(infd, &stat) != 0)
fail("Failed stat for %s: %s\n", infile, strerror(errno));
inbuf = mmap(NULL, stat.st_size, PROT_READ, MAP_PRIVATE, infd, 0);
if (inbuf == MAP_FAILED)
fail("Failed to map %s: %s\n", infile, strerror(errno));
close(infd);
inhdr = inbuf;
if (memcmp(&inhdr->e_ident, ELFMAG, SELFMAG) != 0)
fail("Not an ELF file\n");
if (inhdr->e_ident[EI_CLASS] != ELFCLASS32)
fail("Unsupported ELF class\n");
swap = inhdr->e_ident[EI_DATA] != HOST_ORDER;
if (read_elf_half(inhdr->e_type, swap) != ET_DYN)
fail("Not a shared object\n");
if (read_elf_half(inhdr->e_machine, swap) != EM_ARM)
fail("Unsupported architecture %#x\n", inhdr->e_machine);
e_flags = read_elf_word(inhdr->e_flags, swap);
if (EF_ARM_EABI_VERSION(e_flags) != EF_ARM_EABI_VER5) {
fail("Unsupported EABI version %#x\n",
EF_ARM_EABI_VERSION(e_flags));
}
if (e_flags & EF_ARM_ABI_FLOAT_HARD)
fail("Unexpected hard-float flag set in e_flags\n");
clear_soft_float = !!(e_flags & EF_ARM_ABI_FLOAT_SOFT);
outfd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
if (outfd < 0)
fail("Cannot open %s: %s\n", outfile, strerror(errno));
if (ftruncate(outfd, stat.st_size) != 0)
fail("Cannot truncate %s: %s\n", outfile, strerror(errno));
outbuf = mmap(NULL, stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED,
outfd, 0);
if (outbuf == MAP_FAILED)
fail("Failed to map %s: %s\n", outfile, strerror(errno));
close(outfd);
memcpy(outbuf, inbuf, stat.st_size);
if (clear_soft_float) {
Elf32_Ehdr *outhdr;
outhdr = outbuf;
e_flags &= ~EF_ARM_ABI_FLOAT_SOFT;
write_elf_word(e_flags, &outhdr->e_flags, swap);
}
if (msync(outbuf, stat.st_size, MS_SYNC) != 0)
fail("Failed to sync %s: %s\n", outfile, strerror(errno));
return EXIT_SUCCESS;
}
