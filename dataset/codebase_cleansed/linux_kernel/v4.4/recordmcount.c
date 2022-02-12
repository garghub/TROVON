static void
cleanup(void)
{
if (!mmap_failed)
munmap(file_map, sb.st_size);
else
free(file_map);
file_map = NULL;
free(file_append);
file_append = NULL;
file_append_size = 0;
file_updated = 0;
}
static off_t
ulseek(int const fd, off_t const offset, int const whence)
{
switch (whence) {
case SEEK_SET:
file_ptr = file_map + offset;
break;
case SEEK_CUR:
file_ptr += offset;
break;
case SEEK_END:
file_ptr = file_map + (sb.st_size - offset);
break;
}
if (file_ptr < file_map) {
fprintf(stderr, "lseek: seek before file\n");
fail_file();
}
return file_ptr - file_map;
}
static size_t
uread(int const fd, void *const buf, size_t const count)
{
size_t const n = read(fd, buf, count);
if (n != count) {
perror("read");
fail_file();
}
return n;
}
static size_t
uwrite(int const fd, void const *const buf, size_t const count)
{
size_t cnt = count;
off_t idx = 0;
file_updated = 1;
if (file_ptr + count >= file_end) {
off_t aoffset = (file_ptr + count) - file_end;
if (aoffset > file_append_size) {
file_append = realloc(file_append, aoffset);
file_append_size = aoffset;
}
if (!file_append) {
perror("write");
fail_file();
}
if (file_ptr < file_end) {
cnt = file_end - file_ptr;
} else {
cnt = 0;
idx = aoffset - count;
}
}
if (cnt)
memcpy(file_ptr, buf, cnt);
if (cnt < count)
memcpy(file_append + idx, buf + cnt, count - cnt);
file_ptr += count;
return count;
}
static void *
umalloc(size_t size)
{
void *const addr = malloc(size);
if (addr == 0) {
fprintf(stderr, "malloc failed: %zu bytes\n", size);
fail_file();
}
return addr;
}
static int make_nop_x86(void *map, size_t const offset)
{
uint32_t *ptr;
unsigned char *op;
ptr = map + offset;
if (*ptr != 0)
return -1;
op = map + offset - 1;
if (*op != 0xe8)
return -1;
ulseek(fd_map, offset - 1, SEEK_SET);
uwrite(fd_map, ideal_nop, 5);
return 0;
}
static int make_nop_arm64(void *map, size_t const offset)
{
uint32_t *ptr;
ptr = map + offset;
if (*ptr != 0x94000000)
return -1;
ulseek(fd_map, offset, SEEK_SET);
uwrite(fd_map, ideal_nop, 4);
return 0;
}
static void *mmap_file(char const *fname)
{
fd_map = open(fname, O_RDONLY);
if (fd_map < 0 || fstat(fd_map, &sb) < 0) {
perror(fname);
fail_file();
}
if (!S_ISREG(sb.st_mode)) {
fprintf(stderr, "not a regular file: %s\n", fname);
fail_file();
}
file_map = mmap(0, sb.st_size, PROT_READ|PROT_WRITE, MAP_PRIVATE,
fd_map, 0);
mmap_failed = 0;
if (file_map == MAP_FAILED) {
mmap_failed = 1;
file_map = umalloc(sb.st_size);
uread(fd_map, file_map, sb.st_size);
}
close(fd_map);
file_end = file_map + sb.st_size;
return file_map;
}
static void write_file(const char *fname)
{
char tmp_file[strlen(fname) + 4];
size_t n;
if (!file_updated)
return;
sprintf(tmp_file, "%s.rc", fname);
fd_map = open(tmp_file, O_WRONLY | O_TRUNC | O_CREAT, sb.st_mode);
if (fd_map < 0) {
perror(fname);
fail_file();
}
n = write(fd_map, file_map, sb.st_size);
if (n != sb.st_size) {
perror("write");
fail_file();
}
if (file_append_size) {
n = write(fd_map, file_append, file_append_size);
if (n != file_append_size) {
perror("write");
fail_file();
}
}
close(fd_map);
if (rename(tmp_file, fname) < 0) {
perror(fname);
fail_file();
}
}
static uint64_t w8rev(uint64_t const x)
{
return ((0xff & (x >> (0 * 8))) << (7 * 8))
| ((0xff & (x >> (1 * 8))) << (6 * 8))
| ((0xff & (x >> (2 * 8))) << (5 * 8))
| ((0xff & (x >> (3 * 8))) << (4 * 8))
| ((0xff & (x >> (4 * 8))) << (3 * 8))
| ((0xff & (x >> (5 * 8))) << (2 * 8))
| ((0xff & (x >> (6 * 8))) << (1 * 8))
| ((0xff & (x >> (7 * 8))) << (0 * 8));
}
static uint32_t w4rev(uint32_t const x)
{
return ((0xff & (x >> (0 * 8))) << (3 * 8))
| ((0xff & (x >> (1 * 8))) << (2 * 8))
| ((0xff & (x >> (2 * 8))) << (1 * 8))
| ((0xff & (x >> (3 * 8))) << (0 * 8));
}
static uint32_t w2rev(uint16_t const x)
{
return ((0xff & (x >> (0 * 8))) << (1 * 8))
| ((0xff & (x >> (1 * 8))) << (0 * 8));
}
static uint64_t w8nat(uint64_t const x)
{
return x;
}
static uint32_t w4nat(uint32_t const x)
{
return x;
}
static uint32_t w2nat(uint16_t const x)
{
return x;
}
static int
is_mcounted_section_name(char const *const txtname)
{
return strcmp(".text", txtname) == 0 ||
strcmp(".ref.text", txtname) == 0 ||
strcmp(".sched.text", txtname) == 0 ||
strcmp(".spinlock.text", txtname) == 0 ||
strcmp(".irqentry.text", txtname) == 0 ||
strcmp(".kprobes.text", txtname) == 0 ||
strcmp(".text.unlikely", txtname) == 0;
}
static uint64_t MIPS64_r_sym(Elf64_Rel const *rp)
{
return w(((union mips_r_info){ .r_info = rp->r_info }).r_mips.r_sym);
}
static void MIPS64_r_info(Elf64_Rel *const rp, unsigned sym, unsigned type)
{
rp->r_info = ((union mips_r_info){
.r_mips = { .r_sym = w(sym), .r_type = type }
}).r_info;
}
static void
do_file(char const *const fname)
{
Elf32_Ehdr *const ehdr = mmap_file(fname);
unsigned int reltype = 0;
w = w4nat;
w2 = w2nat;
w8 = w8nat;
switch (ehdr->e_ident[EI_DATA]) {
static unsigned int const endian = 1;
default:
fprintf(stderr, "unrecognized ELF data encoding %d: %s\n",
ehdr->e_ident[EI_DATA], fname);
fail_file();
break;
case ELFDATA2LSB:
if (*(unsigned char const *)&endian != 1) {
w = w4rev;
w2 = w2rev;
w8 = w8rev;
}
break;
case ELFDATA2MSB:
if (*(unsigned char const *)&endian != 0) {
w = w4rev;
w2 = w2rev;
w8 = w8rev;
}
break;
}
if (memcmp(ELFMAG, ehdr->e_ident, SELFMAG) != 0
|| w2(ehdr->e_type) != ET_REL
|| ehdr->e_ident[EI_VERSION] != EV_CURRENT) {
fprintf(stderr, "unrecognized ET_REL file %s\n", fname);
fail_file();
}
gpfx = 0;
switch (w2(ehdr->e_machine)) {
default:
fprintf(stderr, "unrecognized e_machine %d %s\n",
w2(ehdr->e_machine), fname);
fail_file();
break;
case EM_386:
reltype = R_386_32;
rel_type_nop = R_386_NONE;
make_nop = make_nop_x86;
ideal_nop = ideal_nop5_x86_32;
mcount_adjust_32 = -1;
break;
case EM_ARM: reltype = R_ARM_ABS32;
altmcount = "__gnu_mcount_nc";
break;
case EM_AARCH64:
reltype = R_AARCH64_ABS64;
make_nop = make_nop_arm64;
rel_type_nop = R_AARCH64_NONE;
ideal_nop = ideal_nop4_arm64;
gpfx = '_';
break;
case EM_IA_64: reltype = R_IA64_IMM64; gpfx = '_'; break;
case EM_METAG: reltype = R_METAG_ADDR32;
altmcount = "_mcount_wrapper";
rel_type_nop = R_METAG_NONE;
is_fake_mcount32 = MIPS32_is_fake_mcount;
break;
case EM_MIPS: gpfx = '_'; break;
case EM_PPC: reltype = R_PPC_ADDR32; gpfx = '_'; break;
case EM_PPC64: reltype = R_PPC64_ADDR64; gpfx = '_'; break;
case EM_S390: gpfx = '_'; break;
case EM_SH: reltype = R_SH_DIR32; break;
case EM_SPARCV9: reltype = R_SPARC_64; gpfx = '_'; break;
case EM_X86_64:
make_nop = make_nop_x86;
ideal_nop = ideal_nop5_x86_64;
reltype = R_X86_64_64;
rel_type_nop = R_X86_64_NONE;
mcount_adjust_64 = -1;
break;
}
switch (ehdr->e_ident[EI_CLASS]) {
default:
fprintf(stderr, "unrecognized ELF class %d %s\n",
ehdr->e_ident[EI_CLASS], fname);
fail_file();
break;
case ELFCLASS32:
if (w2(ehdr->e_ehsize) != sizeof(Elf32_Ehdr)
|| w2(ehdr->e_shentsize) != sizeof(Elf32_Shdr)) {
fprintf(stderr,
"unrecognized ET_REL file: %s\n", fname);
fail_file();
}
if (w2(ehdr->e_machine) == EM_MIPS) {
reltype = R_MIPS_32;
is_fake_mcount32 = MIPS32_is_fake_mcount;
}
do32(ehdr, fname, reltype);
break;
case ELFCLASS64: {
Elf64_Ehdr *const ghdr = (Elf64_Ehdr *)ehdr;
if (w2(ghdr->e_ehsize) != sizeof(Elf64_Ehdr)
|| w2(ghdr->e_shentsize) != sizeof(Elf64_Shdr)) {
fprintf(stderr,
"unrecognized ET_REL file: %s\n", fname);
fail_file();
}
if (w2(ghdr->e_machine) == EM_S390) {
reltype = R_390_64;
mcount_adjust_64 = -14;
}
if (w2(ghdr->e_machine) == EM_MIPS) {
reltype = R_MIPS_64;
Elf64_r_sym = MIPS64_r_sym;
Elf64_r_info = MIPS64_r_info;
is_fake_mcount64 = MIPS64_is_fake_mcount;
}
do64(ghdr, fname, reltype);
break;
}
}
write_file(fname);
cleanup();
}
int
main(int argc, char *argv[])
{
const char ftrace[] = "/ftrace.o";
int ftrace_size = sizeof(ftrace) - 1;
int n_error = 0;
int c;
int i;
while ((c = getopt(argc, argv, "w")) >= 0) {
switch (c) {
case 'w':
warn_on_notrace_sect = 1;
break;
default:
fprintf(stderr, "usage: recordmcount [-w] file.o...\n");
return 0;
}
}
if ((argc - optind) < 1) {
fprintf(stderr, "usage: recordmcount [-w] file.o...\n");
return 0;
}
for (i = optind; i < argc; i++) {
char *file = argv[i];
int const sjval = setjmp(jmpenv);
int len;
len = strlen(file);
if (len >= ftrace_size &&
strcmp(file + (len - ftrace_size), ftrace) == 0)
continue;
switch (sjval) {
default:
fprintf(stderr, "internal error: %s\n", file);
exit(1);
break;
case SJ_SETJMP:
fd_map = -1;
mmap_failed = 1;
file_map = NULL;
file_ptr = NULL;
file_updated = 0;
do_file(file);
break;
case SJ_FAIL:
fprintf(stderr, "%s: failed\n", file);
++n_error;
break;
case SJ_SUCCEED:
break;
}
}
return !!n_error;
}
