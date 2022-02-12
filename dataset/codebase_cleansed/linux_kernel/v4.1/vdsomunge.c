static void cleanup(void)
{
if (error_message_count > 0 && outfile != NULL)
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
if (argc != 3)
error(EXIT_FAILURE, 0, "Usage: %s [infile] [outfile]", argv[0]);
infile = argv[1];
outfile = argv[2];
infd = open(infile, O_RDONLY);
if (infd < 0)
error(EXIT_FAILURE, errno, "Cannot open %s", infile);
if (fstat(infd, &stat) != 0)
error(EXIT_FAILURE, errno, "Failed stat for %s", infile);
inbuf = mmap(NULL, stat.st_size, PROT_READ, MAP_PRIVATE, infd, 0);
if (inbuf == MAP_FAILED)
error(EXIT_FAILURE, errno, "Failed to map %s", infile);
close(infd);
inhdr = inbuf;
if (memcmp(&inhdr->e_ident, ELFMAG, SELFMAG) != 0)
error(EXIT_FAILURE, 0, "Not an ELF file");
if (inhdr->e_ident[EI_CLASS] != ELFCLASS32)
error(EXIT_FAILURE, 0, "Unsupported ELF class");
swap = inhdr->e_ident[EI_DATA] != HOST_ORDER;
if (read_elf_half(inhdr->e_type, swap) != ET_DYN)
error(EXIT_FAILURE, 0, "Not a shared object");
if (read_elf_half(inhdr->e_machine, swap) != EM_ARM) {
error(EXIT_FAILURE, 0, "Unsupported architecture %#x",
inhdr->e_machine);
}
e_flags = read_elf_word(inhdr->e_flags, swap);
if (EF_ARM_EABI_VERSION(e_flags) != EF_ARM_EABI_VER5) {
error(EXIT_FAILURE, 0, "Unsupported EABI version %#x",
EF_ARM_EABI_VERSION(e_flags));
}
if (e_flags & EF_ARM_ABI_FLOAT_HARD)
error(EXIT_FAILURE, 0,
"Unexpected hard-float flag set in e_flags");
clear_soft_float = !!(e_flags & EF_ARM_ABI_FLOAT_SOFT);
outfd = open(outfile, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
if (outfd < 0)
error(EXIT_FAILURE, errno, "Cannot open %s", outfile);
if (ftruncate(outfd, stat.st_size) != 0)
error(EXIT_FAILURE, errno, "Cannot truncate %s", outfile);
outbuf = mmap(NULL, stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED,
outfd, 0);
if (outbuf == MAP_FAILED)
error(EXIT_FAILURE, errno, "Failed to map %s", outfile);
close(outfd);
memcpy(outbuf, inbuf, stat.st_size);
if (clear_soft_float) {
Elf32_Ehdr *outhdr;
outhdr = outbuf;
e_flags &= ~EF_ARM_ABI_FLOAT_SOFT;
write_elf_word(e_flags, &outhdr->e_flags, swap);
}
if (msync(outbuf, stat.st_size, MS_SYNC) != 0)
error(EXIT_FAILURE, errno, "Failed to sync %s", outfile);
return EXIT_SUCCESS;
}
