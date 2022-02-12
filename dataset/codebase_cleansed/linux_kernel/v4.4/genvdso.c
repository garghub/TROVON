static void *map_vdso(const char *path, size_t *_size)
{
int fd;
struct stat stat;
void *addr;
const Elf32_Ehdr *ehdr;
fd = open(path, O_RDWR);
if (fd < 0) {
fprintf(stderr, "%s: Failed to open '%s': %s\n", program_name,
path, strerror(errno));
return NULL;
}
if (fstat(fd, &stat) != 0) {
fprintf(stderr, "%s: Failed to stat '%s': %s\n", program_name,
path, strerror(errno));
return NULL;
}
addr = mmap(NULL, stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd,
0);
if (addr == MAP_FAILED) {
fprintf(stderr, "%s: Failed to map '%s': %s\n", program_name,
path, strerror(errno));
return NULL;
}
ehdr = addr;
if (memcmp(ehdr->e_ident, ELFMAG, SELFMAG) != 0) {
fprintf(stderr, "%s: '%s' is not an ELF file\n", program_name,
path);
return NULL;
}
elf_class = ehdr->e_ident[EI_CLASS];
switch (elf_class) {
case ELFCLASS32:
case ELFCLASS64:
break;
default:
fprintf(stderr, "%s: '%s' has invalid ELF class\n",
program_name, path);
return NULL;
}
switch (ehdr->e_ident[EI_DATA]) {
case ELFDATA2LSB:
case ELFDATA2MSB:
need_swap = ehdr->e_ident[EI_DATA] != HOST_ORDER;
break;
default:
fprintf(stderr, "%s: '%s' has invalid ELF data order\n",
program_name, path);
return NULL;
}
if (swap_uint16(ehdr->e_machine) != EM_MIPS) {
fprintf(stderr,
"%s: '%s' has invalid ELF machine (expected EM_MIPS)\n",
program_name, path);
return NULL;
} else if (swap_uint16(ehdr->e_type) != ET_DYN) {
fprintf(stderr,
"%s: '%s' has invalid ELF type (expected ET_DYN)\n",
program_name, path);
return NULL;
}
*_size = stat.st_size;
return addr;
}
static bool patch_vdso(const char *path, void *vdso)
{
if (elf_class == ELFCLASS64)
return patch_vdso64(path, vdso);
else
return patch_vdso32(path, vdso);
}
static bool get_symbols(const char *path, void *vdso)
{
if (elf_class == ELFCLASS64)
return get_symbols64(path, vdso);
else
return get_symbols32(path, vdso);
}
int main(int argc, char **argv)
{
const char *dbg_vdso_path, *vdso_path, *out_path;
void *dbg_vdso, *vdso;
size_t dbg_vdso_size, vdso_size, i;
program_name = argv[0];
if (argc < 4 || argc > 5) {
fprintf(stderr,
"Usage: %s <debug VDSO> <stripped VDSO> <output file> [<name>]\n",
program_name);
return EXIT_FAILURE;
}
dbg_vdso_path = argv[1];
vdso_path = argv[2];
out_path = argv[3];
vdso_name = (argc > 4) ? argv[4] : "";
dbg_vdso = map_vdso(dbg_vdso_path, &dbg_vdso_size);
if (!dbg_vdso)
return EXIT_FAILURE;
vdso = map_vdso(vdso_path, &vdso_size);
if (!vdso)
return EXIT_FAILURE;
if (!patch_vdso(dbg_vdso_path, dbg_vdso))
return EXIT_FAILURE;
if (!patch_vdso(vdso_path, vdso))
return EXIT_FAILURE;
if (msync(dbg_vdso, dbg_vdso_size, MS_SYNC) != 0) {
fprintf(stderr, "%s: Failed to sync '%s': %s\n", program_name,
dbg_vdso_path, strerror(errno));
return EXIT_FAILURE;
} else if (msync(vdso, vdso_size, MS_SYNC) != 0) {
fprintf(stderr, "%s: Failed to sync '%s': %s\n", program_name,
vdso_path, strerror(errno));
return EXIT_FAILURE;
}
out_file = fopen(out_path, "w");
if (!out_file) {
fprintf(stderr, "%s: Failed to open '%s': %s\n", program_name,
out_path, strerror(errno));
return EXIT_FAILURE;
}
fprintf(out_file, "/* Automatically generated - do not edit */\n");
fprintf(out_file, "#include <linux/linkage.h>\n");
fprintf(out_file, "#include <linux/mm.h>\n");
fprintf(out_file, "#include <asm/vdso.h>\n");
fprintf(out_file,
"static unsigned char vdso_data[PAGE_ALIGN(%zu)] __page_aligned_data = {\n\t",
vdso_size);
for (i = 0; i < vdso_size; i++) {
if (!(i % 10))
fprintf(out_file, "\n\t");
fprintf(out_file, "0x%02x, ", ((unsigned char *)vdso)[i]);
}
fprintf(out_file, "\n};\n");
fprintf(out_file,
"static struct page *vdso_pages[PAGE_ALIGN(%zu) / PAGE_SIZE];\n",
vdso_size);
fprintf(out_file, "struct mips_vdso_image vdso_image%s%s = {\n",
(vdso_name[0]) ? "_" : "", vdso_name);
fprintf(out_file, "\t.data = vdso_data,\n");
fprintf(out_file, "\t.size = PAGE_ALIGN(%zu),\n", vdso_size);
fprintf(out_file, "\t.mapping = {\n");
fprintf(out_file, "\t\t.name = \"[vdso]\",\n");
fprintf(out_file, "\t\t.pages = vdso_pages,\n");
fprintf(out_file, "\t},\n");
if (!get_symbols(dbg_vdso_path, dbg_vdso)) {
unlink(out_path);
return EXIT_FAILURE;
}
fprintf(out_file, "};\n");
return EXIT_SUCCESS;
}
