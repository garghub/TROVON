static bool check_need_swap(int file_endian)
{
const int data = 1;
u8 *check = (u8 *)&data;
int host_endian;
if (check[0] == 1)
host_endian = ELFDATA2LSB;
else
host_endian = ELFDATA2MSB;
return host_endian != file_endian;
}
static int read_build_id(void *note_data, size_t note_len, void *bf,
size_t size, bool need_swap)
{
struct {
u32 n_namesz;
u32 n_descsz;
u32 n_type;
} *nhdr;
void *ptr;
ptr = note_data;
while (ptr < (note_data + note_len)) {
const char *name;
size_t namesz, descsz;
nhdr = ptr;
if (need_swap) {
nhdr->n_namesz = bswap_32(nhdr->n_namesz);
nhdr->n_descsz = bswap_32(nhdr->n_descsz);
nhdr->n_type = bswap_32(nhdr->n_type);
}
namesz = NOTE_ALIGN(nhdr->n_namesz);
descsz = NOTE_ALIGN(nhdr->n_descsz);
ptr += sizeof(*nhdr);
name = ptr;
ptr += namesz;
if (nhdr->n_type == NT_GNU_BUILD_ID &&
nhdr->n_namesz == sizeof("GNU")) {
if (memcmp(name, "GNU", sizeof("GNU")) == 0) {
size_t sz = min(size, descsz);
memcpy(bf, ptr, sz);
memset(bf + sz, 0, size - sz);
return 0;
}
}
ptr += descsz;
}
return -1;
}
int filename__read_debuglink(const char *filename __maybe_unused,
char *debuglink __maybe_unused,
size_t size __maybe_unused)
{
return -1;
}
int filename__read_build_id(const char *filename, void *bf, size_t size)
{
FILE *fp;
int ret = -1;
bool need_swap = false;
u8 e_ident[EI_NIDENT];
size_t buf_size;
void *buf;
int i;
fp = fopen(filename, "r");
if (fp == NULL)
return -1;
if (fread(e_ident, sizeof(e_ident), 1, fp) != 1)
goto out;
if (memcmp(e_ident, ELFMAG, SELFMAG) ||
e_ident[EI_VERSION] != EV_CURRENT)
goto out;
need_swap = check_need_swap(e_ident[EI_DATA]);
fseek(fp, 0, SEEK_SET);
if (e_ident[EI_CLASS] == ELFCLASS32) {
Elf32_Ehdr ehdr;
Elf32_Phdr *phdr;
if (fread(&ehdr, sizeof(ehdr), 1, fp) != 1)
goto out;
if (need_swap) {
ehdr.e_phoff = bswap_32(ehdr.e_phoff);
ehdr.e_phentsize = bswap_16(ehdr.e_phentsize);
ehdr.e_phnum = bswap_16(ehdr.e_phnum);
}
buf_size = ehdr.e_phentsize * ehdr.e_phnum;
buf = malloc(buf_size);
if (buf == NULL)
goto out;
fseek(fp, ehdr.e_phoff, SEEK_SET);
if (fread(buf, buf_size, 1, fp) != 1)
goto out_free;
for (i = 0, phdr = buf; i < ehdr.e_phnum; i++, phdr++) {
void *tmp;
if (need_swap) {
phdr->p_type = bswap_32(phdr->p_type);
phdr->p_offset = bswap_32(phdr->p_offset);
phdr->p_filesz = bswap_32(phdr->p_filesz);
}
if (phdr->p_type != PT_NOTE)
continue;
buf_size = phdr->p_filesz;
tmp = realloc(buf, buf_size);
if (tmp == NULL)
goto out_free;
buf = tmp;
fseek(fp, phdr->p_offset, SEEK_SET);
if (fread(buf, buf_size, 1, fp) != 1)
goto out_free;
ret = read_build_id(buf, buf_size, bf, size, need_swap);
if (ret == 0)
ret = size;
break;
}
} else {
Elf64_Ehdr ehdr;
Elf64_Phdr *phdr;
if (fread(&ehdr, sizeof(ehdr), 1, fp) != 1)
goto out;
if (need_swap) {
ehdr.e_phoff = bswap_64(ehdr.e_phoff);
ehdr.e_phentsize = bswap_16(ehdr.e_phentsize);
ehdr.e_phnum = bswap_16(ehdr.e_phnum);
}
buf_size = ehdr.e_phentsize * ehdr.e_phnum;
buf = malloc(buf_size);
if (buf == NULL)
goto out;
fseek(fp, ehdr.e_phoff, SEEK_SET);
if (fread(buf, buf_size, 1, fp) != 1)
goto out_free;
for (i = 0, phdr = buf; i < ehdr.e_phnum; i++, phdr++) {
void *tmp;
if (need_swap) {
phdr->p_type = bswap_32(phdr->p_type);
phdr->p_offset = bswap_64(phdr->p_offset);
phdr->p_filesz = bswap_64(phdr->p_filesz);
}
if (phdr->p_type != PT_NOTE)
continue;
buf_size = phdr->p_filesz;
tmp = realloc(buf, buf_size);
if (tmp == NULL)
goto out_free;
buf = tmp;
fseek(fp, phdr->p_offset, SEEK_SET);
if (fread(buf, buf_size, 1, fp) != 1)
goto out_free;
ret = read_build_id(buf, buf_size, bf, size, need_swap);
if (ret == 0)
ret = size;
break;
}
}
out_free:
free(buf);
out:
fclose(fp);
return ret;
}
int sysfs__read_build_id(const char *filename, void *build_id, size_t size)
{
int fd;
int ret = -1;
struct stat stbuf;
size_t buf_size;
void *buf;
fd = open(filename, O_RDONLY);
if (fd < 0)
return -1;
if (fstat(fd, &stbuf) < 0)
goto out;
buf_size = stbuf.st_size;
buf = malloc(buf_size);
if (buf == NULL)
goto out;
if (read(fd, buf, buf_size) != (ssize_t) buf_size)
goto out_free;
ret = read_build_id(buf, buf_size, build_id, size, false);
out_free:
free(buf);
out:
close(fd);
return ret;
}
int symsrc__init(struct symsrc *ss, struct dso *dso __maybe_unused,
const char *name,
enum dso_binary_type type)
{
int fd = open(name, O_RDONLY);
if (fd < 0)
return -1;
ss->name = strdup(name);
if (!ss->name)
goto out_close;
ss->type = type;
return 0;
out_close:
close(fd);
return -1;
}
bool symsrc__possibly_runtime(struct symsrc *ss __maybe_unused)
{
return true;
}
bool symsrc__has_symtab(struct symsrc *ss __maybe_unused)
{
return false;
}
void symsrc__destroy(struct symsrc *ss)
{
free(ss->name);
close(ss->fd);
}
int dso__synthesize_plt_symbols(struct dso *dso __maybe_unused,
struct symsrc *ss __maybe_unused,
struct map *map __maybe_unused,
symbol_filter_t filter __maybe_unused)
{
return 0;
}
int dso__load_sym(struct dso *dso, struct map *map __maybe_unused,
struct symsrc *ss,
struct symsrc *runtime_ss __maybe_unused,
symbol_filter_t filter __maybe_unused,
int kmodule __maybe_unused)
{
unsigned char *build_id[BUILD_ID_SIZE];
if (filename__read_build_id(ss->name, build_id, BUILD_ID_SIZE) > 0) {
dso__set_build_id(dso, build_id);
return 1;
}
return 0;
}
int file__read_maps(int fd __maybe_unused, bool exe __maybe_unused,
mapfn_t mapfn __maybe_unused, void *data __maybe_unused,
bool *is_64_bit __maybe_unused)
{
return -1;
}
void symbol__elf_init(void)
{
}
