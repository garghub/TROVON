static void
cleanup(void)
{
if (!mmap_failed)
munmap(ehdr_curr, sb.st_size);
close(fd_map);
}
static void *mmap_file(char const *fname)
{
void *addr;
fd_map = open(fname, O_RDWR);
if (fd_map < 0 || fstat(fd_map, &sb) < 0) {
perror(fname);
fail_file();
}
if (!S_ISREG(sb.st_mode)) {
fprintf(stderr, "not a regular file: %s\n", fname);
fail_file();
}
addr = mmap(0, sb.st_size, PROT_READ|PROT_WRITE, MAP_SHARED,
fd_map, 0);
if (addr == MAP_FAILED) {
mmap_failed = 1;
fprintf(stderr, "Could not mmap file: %s\n", fname);
fail_file();
}
return addr;
}
static uint64_t r8be(const uint64_t *x)
{
return get_unaligned_be64(x);
}
static uint32_t rbe(const uint32_t *x)
{
return get_unaligned_be32(x);
}
static uint16_t r2be(const uint16_t *x)
{
return get_unaligned_be16(x);
}
static uint64_t r8le(const uint64_t *x)
{
return get_unaligned_le64(x);
}
static uint32_t rle(const uint32_t *x)
{
return get_unaligned_le32(x);
}
static uint16_t r2le(const uint16_t *x)
{
return get_unaligned_le16(x);
}
static void w8be(uint64_t val, uint64_t *x)
{
put_unaligned_be64(val, x);
}
static void wbe(uint32_t val, uint32_t *x)
{
put_unaligned_be32(val, x);
}
static void w2be(uint16_t val, uint16_t *x)
{
put_unaligned_be16(val, x);
}
static void w8le(uint64_t val, uint64_t *x)
{
put_unaligned_le64(val, x);
}
static void wle(uint32_t val, uint32_t *x)
{
put_unaligned_le32(val, x);
}
static void w2le(uint16_t val, uint16_t *x)
{
put_unaligned_le16(val, x);
}
static int compare_x86_table(const void *a, const void *b)
{
int32_t av = (int32_t)r(a);
int32_t bv = (int32_t)r(b);
if (av < bv)
return -1;
if (av > bv)
return 1;
return 0;
}
static void sort_x86_table(char *extab_image, int image_size)
{
int i;
i = 0;
while (i < image_size) {
uint32_t *loc = (uint32_t *)(extab_image + i);
w(r(loc) + i, loc);
i += 4;
}
qsort(extab_image, image_size / 8, 8, compare_x86_table);
i = 0;
while (i < image_size) {
uint32_t *loc = (uint32_t *)(extab_image + i);
w(r(loc) - i, loc);
i += 4;
}
}
static void
do_file(char const *const fname)
{
table_sort_t custom_sort;
Elf32_Ehdr *ehdr = mmap_file(fname);
ehdr_curr = ehdr;
switch (ehdr->e_ident[EI_DATA]) {
default:
fprintf(stderr, "unrecognized ELF data encoding %d: %s\n",
ehdr->e_ident[EI_DATA], fname);
fail_file();
break;
case ELFDATA2LSB:
r = rle;
r2 = r2le;
r8 = r8le;
w = wle;
w2 = w2le;
w8 = w8le;
break;
case ELFDATA2MSB:
r = rbe;
r2 = r2be;
r8 = r8be;
w = wbe;
w2 = w2be;
w8 = w8be;
break;
}
if (memcmp(ELFMAG, ehdr->e_ident, SELFMAG) != 0
|| r2(&ehdr->e_type) != ET_EXEC
|| ehdr->e_ident[EI_VERSION] != EV_CURRENT) {
fprintf(stderr, "unrecognized ET_EXEC file %s\n", fname);
fail_file();
}
custom_sort = NULL;
switch (r2(&ehdr->e_machine)) {
default:
fprintf(stderr, "unrecognized e_machine %d %s\n",
r2(&ehdr->e_machine), fname);
fail_file();
break;
case EM_386:
case EM_X86_64:
custom_sort = sort_x86_table;
break;
case EM_MIPS:
break;
}
switch (ehdr->e_ident[EI_CLASS]) {
default:
fprintf(stderr, "unrecognized ELF class %d %s\n",
ehdr->e_ident[EI_CLASS], fname);
fail_file();
break;
case ELFCLASS32:
if (r2(&ehdr->e_ehsize) != sizeof(Elf32_Ehdr)
|| r2(&ehdr->e_shentsize) != sizeof(Elf32_Shdr)) {
fprintf(stderr,
"unrecognized ET_EXEC file: %s\n", fname);
fail_file();
}
do32(ehdr, fname, custom_sort);
break;
case ELFCLASS64: {
Elf64_Ehdr *const ghdr = (Elf64_Ehdr *)ehdr;
if (r2(&ghdr->e_ehsize) != sizeof(Elf64_Ehdr)
|| r2(&ghdr->e_shentsize) != sizeof(Elf64_Shdr)) {
fprintf(stderr,
"unrecognized ET_EXEC file: %s\n", fname);
fail_file();
}
do64(ghdr, fname, custom_sort);
break;
}
}
cleanup();
}
int
main(int argc, char *argv[])
{
int n_error = 0;
int i;
if (argc < 2) {
fprintf(stderr, "usage: sortextable vmlinux...\n");
return 0;
}
for (i = 1; i < argc; i++) {
char *file = argv[i];
int const sjval = setjmp(jmpenv);
switch (sjval) {
default:
fprintf(stderr, "internal error: %s\n", file);
exit(1);
break;
case SJ_SETJMP:
fd_map = -1;
ehdr_curr = NULL;
mmap_failed = 1;
do_file(file);
break;
case SJ_FAIL:
++n_error;
break;
case SJ_SUCCEED:
break;
}
}
return !!n_error;
}
