static inline char *bfd_demangle(void __maybe_unused *v, const char *c, int i)
{
return cplus_demangle(c, i);
}
static inline char *bfd_demangle(void __maybe_unused *v,
const char __maybe_unused *c,
int __maybe_unused i)
{
return NULL;
}
static int elf_getphdrnum(Elf *elf, size_t *dst)
{
GElf_Ehdr gehdr;
GElf_Ehdr *ehdr;
ehdr = gelf_getehdr(elf, &gehdr);
if (!ehdr)
return -1;
*dst = ehdr->e_phnum;
return 0;
}
static int elf_getshdrstrndx(Elf *elf __maybe_unused, size_t *dst __maybe_unused)
{
pr_err("%s: update your libelf to > 0.140, this one lacks elf_getshdrstrndx().\n", __func__);
return -1;
}
static inline uint8_t elf_sym__type(const GElf_Sym *sym)
{
return GELF_ST_TYPE(sym->st_info);
}
static inline int elf_sym__is_function(const GElf_Sym *sym)
{
return (elf_sym__type(sym) == STT_FUNC ||
elf_sym__type(sym) == STT_GNU_IFUNC) &&
sym->st_name != 0 &&
sym->st_shndx != SHN_UNDEF;
}
static inline bool elf_sym__is_object(const GElf_Sym *sym)
{
return elf_sym__type(sym) == STT_OBJECT &&
sym->st_name != 0 &&
sym->st_shndx != SHN_UNDEF;
}
static inline int elf_sym__is_label(const GElf_Sym *sym)
{
return elf_sym__type(sym) == STT_NOTYPE &&
sym->st_name != 0 &&
sym->st_shndx != SHN_UNDEF &&
sym->st_shndx != SHN_ABS;
}
static bool elf_sym__is_a(GElf_Sym *sym, enum map_type type)
{
switch (type) {
case MAP__FUNCTION:
return elf_sym__is_function(sym);
case MAP__VARIABLE:
return elf_sym__is_object(sym);
default:
return false;
}
}
static inline const char *elf_sym__name(const GElf_Sym *sym,
const Elf_Data *symstrs)
{
return symstrs->d_buf + sym->st_name;
}
static inline const char *elf_sec__name(const GElf_Shdr *shdr,
const Elf_Data *secstrs)
{
return secstrs->d_buf + shdr->sh_name;
}
static inline int elf_sec__is_text(const GElf_Shdr *shdr,
const Elf_Data *secstrs)
{
return strstr(elf_sec__name(shdr, secstrs), "text") != NULL;
}
static inline bool elf_sec__is_data(const GElf_Shdr *shdr,
const Elf_Data *secstrs)
{
return strstr(elf_sec__name(shdr, secstrs), "data") != NULL;
}
static bool elf_sec__is_a(GElf_Shdr *shdr, Elf_Data *secstrs,
enum map_type type)
{
switch (type) {
case MAP__FUNCTION:
return elf_sec__is_text(shdr, secstrs);
case MAP__VARIABLE:
return elf_sec__is_data(shdr, secstrs);
default:
return false;
}
}
static size_t elf_addr_to_index(Elf *elf, GElf_Addr addr)
{
Elf_Scn *sec = NULL;
GElf_Shdr shdr;
size_t cnt = 1;
while ((sec = elf_nextscn(elf, sec)) != NULL) {
gelf_getshdr(sec, &shdr);
if ((addr >= shdr.sh_addr) &&
(addr < (shdr.sh_addr + shdr.sh_size)))
return cnt;
++cnt;
}
return -1;
}
Elf_Scn *elf_section_by_name(Elf *elf, GElf_Ehdr *ep,
GElf_Shdr *shp, const char *name, size_t *idx)
{
Elf_Scn *sec = NULL;
size_t cnt = 1;
if (!elf_rawdata(elf_getscn(elf, ep->e_shstrndx), NULL))
return NULL;
while ((sec = elf_nextscn(elf, sec)) != NULL) {
char *str;
gelf_getshdr(sec, shp);
str = elf_strptr(elf, ep->e_shstrndx, shp->sh_name);
if (str && !strcmp(name, str)) {
if (idx)
*idx = cnt;
return sec;
}
++cnt;
}
return NULL;
}
static bool want_demangle(bool is_kernel_sym)
{
return is_kernel_sym ? symbol_conf.demangle_kernel : symbol_conf.demangle;
}
static char *demangle_sym(struct dso *dso, int kmodule, const char *elf_name)
{
int demangle_flags = verbose ? (DMGL_PARAMS | DMGL_ANSI) : DMGL_NO_OPTS;
char *demangled = NULL;
if (!want_demangle(dso->kernel || kmodule))
return demangled;
demangled = bfd_demangle(NULL, elf_name, demangle_flags);
if (demangled == NULL)
demangled = java_demangle_sym(elf_name, JAVA_DEMANGLE_NORET);
else if (rust_is_mangled(demangled))
rust_demangle_sym(demangled);
return demangled;
}
int dso__synthesize_plt_symbols(struct dso *dso, struct symsrc *ss, struct map *map)
{
uint32_t nr_rel_entries, idx;
GElf_Sym sym;
u64 plt_offset;
GElf_Shdr shdr_plt;
struct symbol *f;
GElf_Shdr shdr_rel_plt, shdr_dynsym;
Elf_Data *reldata, *syms, *symstrs;
Elf_Scn *scn_plt_rel, *scn_symstrs, *scn_dynsym;
size_t dynsym_idx;
GElf_Ehdr ehdr;
char sympltname[1024];
Elf *elf;
int nr = 0, symidx, err = 0;
if (!ss->dynsym)
return 0;
elf = ss->elf;
ehdr = ss->ehdr;
scn_dynsym = ss->dynsym;
shdr_dynsym = ss->dynshdr;
dynsym_idx = ss->dynsym_idx;
if (scn_dynsym == NULL)
goto out_elf_end;
scn_plt_rel = elf_section_by_name(elf, &ehdr, &shdr_rel_plt,
".rela.plt", NULL);
if (scn_plt_rel == NULL) {
scn_plt_rel = elf_section_by_name(elf, &ehdr, &shdr_rel_plt,
".rel.plt", NULL);
if (scn_plt_rel == NULL)
goto out_elf_end;
}
err = -1;
if (shdr_rel_plt.sh_link != dynsym_idx)
goto out_elf_end;
if (elf_section_by_name(elf, &ehdr, &shdr_plt, ".plt", NULL) == NULL)
goto out_elf_end;
reldata = elf_getdata(scn_plt_rel, NULL);
if (reldata == NULL)
goto out_elf_end;
syms = elf_getdata(scn_dynsym, NULL);
if (syms == NULL)
goto out_elf_end;
scn_symstrs = elf_getscn(elf, shdr_dynsym.sh_link);
if (scn_symstrs == NULL)
goto out_elf_end;
symstrs = elf_getdata(scn_symstrs, NULL);
if (symstrs == NULL)
goto out_elf_end;
if (symstrs->d_size == 0)
goto out_elf_end;
nr_rel_entries = shdr_rel_plt.sh_size / shdr_rel_plt.sh_entsize;
plt_offset = shdr_plt.sh_offset;
if (shdr_rel_plt.sh_type == SHT_RELA) {
GElf_Rela pos_mem, *pos;
elf_section__for_each_rela(reldata, pos, pos_mem, idx,
nr_rel_entries) {
const char *elf_name = NULL;
char *demangled = NULL;
symidx = GELF_R_SYM(pos->r_info);
plt_offset += shdr_plt.sh_entsize;
gelf_getsym(syms, symidx, &sym);
elf_name = elf_sym__name(&sym, symstrs);
demangled = demangle_sym(dso, 0, elf_name);
if (demangled != NULL)
elf_name = demangled;
snprintf(sympltname, sizeof(sympltname),
"%s@plt", elf_name);
free(demangled);
f = symbol__new(plt_offset, shdr_plt.sh_entsize,
STB_GLOBAL, sympltname);
if (!f)
goto out_elf_end;
symbols__insert(&dso->symbols[map->type], f);
++nr;
}
} else if (shdr_rel_plt.sh_type == SHT_REL) {
GElf_Rel pos_mem, *pos;
elf_section__for_each_rel(reldata, pos, pos_mem, idx,
nr_rel_entries) {
const char *elf_name = NULL;
char *demangled = NULL;
symidx = GELF_R_SYM(pos->r_info);
plt_offset += shdr_plt.sh_entsize;
gelf_getsym(syms, symidx, &sym);
elf_name = elf_sym__name(&sym, symstrs);
demangled = demangle_sym(dso, 0, elf_name);
if (demangled != NULL)
elf_name = demangled;
snprintf(sympltname, sizeof(sympltname),
"%s@plt", elf_name);
free(demangled);
f = symbol__new(plt_offset, shdr_plt.sh_entsize,
STB_GLOBAL, sympltname);
if (!f)
goto out_elf_end;
symbols__insert(&dso->symbols[map->type], f);
++nr;
}
}
err = 0;
out_elf_end:
if (err == 0)
return nr;
pr_debug("%s: problems reading %s PLT info.\n",
__func__, dso->long_name);
return 0;
}
static int elf_read_build_id(Elf *elf, void *bf, size_t size)
{
int err = -1;
GElf_Ehdr ehdr;
GElf_Shdr shdr;
Elf_Data *data;
Elf_Scn *sec;
Elf_Kind ek;
void *ptr;
if (size < BUILD_ID_SIZE)
goto out;
ek = elf_kind(elf);
if (ek != ELF_K_ELF)
goto out;
if (gelf_getehdr(elf, &ehdr) == NULL) {
pr_err("%s: cannot get elf header.\n", __func__);
goto out;
}
do {
sec = elf_section_by_name(elf, &ehdr, &shdr,
".note.gnu.build-id", NULL);
if (sec)
break;
sec = elf_section_by_name(elf, &ehdr, &shdr,
".notes", NULL);
if (sec)
break;
sec = elf_section_by_name(elf, &ehdr, &shdr,
".note", NULL);
if (sec)
break;
return err;
} while (0);
data = elf_getdata(sec, NULL);
if (data == NULL)
goto out;
ptr = data->d_buf;
while (ptr < (data->d_buf + data->d_size)) {
GElf_Nhdr *nhdr = ptr;
size_t namesz = NOTE_ALIGN(nhdr->n_namesz),
descsz = NOTE_ALIGN(nhdr->n_descsz);
const char *name;
ptr += sizeof(*nhdr);
name = ptr;
ptr += namesz;
if (nhdr->n_type == NT_GNU_BUILD_ID &&
nhdr->n_namesz == sizeof("GNU")) {
if (memcmp(name, "GNU", sizeof("GNU")) == 0) {
size_t sz = min(size, descsz);
memcpy(bf, ptr, sz);
memset(bf + sz, 0, size - sz);
err = descsz;
break;
}
}
ptr += descsz;
}
out:
return err;
}
int filename__read_build_id(const char *filename, void *bf, size_t size)
{
int fd, err = -1;
Elf *elf;
if (size < BUILD_ID_SIZE)
goto out;
fd = open(filename, O_RDONLY);
if (fd < 0)
goto out;
elf = elf_begin(fd, PERF_ELF_C_READ_MMAP, NULL);
if (elf == NULL) {
pr_debug2("%s: cannot read %s ELF file.\n", __func__, filename);
goto out_close;
}
err = elf_read_build_id(elf, bf, size);
elf_end(elf);
out_close:
close(fd);
out:
return err;
}
int sysfs__read_build_id(const char *filename, void *build_id, size_t size)
{
int fd, err = -1;
if (size < BUILD_ID_SIZE)
goto out;
fd = open(filename, O_RDONLY);
if (fd < 0)
goto out;
while (1) {
char bf[BUFSIZ];
GElf_Nhdr nhdr;
size_t namesz, descsz;
if (read(fd, &nhdr, sizeof(nhdr)) != sizeof(nhdr))
break;
namesz = NOTE_ALIGN(nhdr.n_namesz);
descsz = NOTE_ALIGN(nhdr.n_descsz);
if (nhdr.n_type == NT_GNU_BUILD_ID &&
nhdr.n_namesz == sizeof("GNU")) {
if (read(fd, bf, namesz) != (ssize_t)namesz)
break;
if (memcmp(bf, "GNU", sizeof("GNU")) == 0) {
size_t sz = min(descsz, size);
if (read(fd, build_id, sz) == (ssize_t)sz) {
memset(build_id + sz, 0, size - sz);
err = 0;
break;
}
} else if (read(fd, bf, descsz) != (ssize_t)descsz)
break;
} else {
int n = namesz + descsz;
if (n > (int)sizeof(bf)) {
n = sizeof(bf);
pr_debug("%s: truncating reading of build id in sysfs file %s: n_namesz=%u, n_descsz=%u.\n",
__func__, filename, nhdr.n_namesz, nhdr.n_descsz);
}
if (read(fd, bf, n) != n)
break;
}
}
close(fd);
out:
return err;
}
int filename__read_debuglink(const char *filename, char *debuglink,
size_t size)
{
int fd, err = -1;
Elf *elf;
GElf_Ehdr ehdr;
GElf_Shdr shdr;
Elf_Data *data;
Elf_Scn *sec;
Elf_Kind ek;
fd = open(filename, O_RDONLY);
if (fd < 0)
goto out;
elf = elf_begin(fd, PERF_ELF_C_READ_MMAP, NULL);
if (elf == NULL) {
pr_debug2("%s: cannot read %s ELF file.\n", __func__, filename);
goto out_close;
}
ek = elf_kind(elf);
if (ek != ELF_K_ELF)
goto out_elf_end;
if (gelf_getehdr(elf, &ehdr) == NULL) {
pr_err("%s: cannot get elf header.\n", __func__);
goto out_elf_end;
}
sec = elf_section_by_name(elf, &ehdr, &shdr,
".gnu_debuglink", NULL);
if (sec == NULL)
goto out_elf_end;
data = elf_getdata(sec, NULL);
if (data == NULL)
goto out_elf_end;
strncpy(debuglink, data->d_buf, size);
err = 0;
out_elf_end:
elf_end(elf);
out_close:
close(fd);
out:
return err;
}
static int dso__swap_init(struct dso *dso, unsigned char eidata)
{
static unsigned int const endian = 1;
dso->needs_swap = DSO_SWAP__NO;
switch (eidata) {
case ELFDATA2LSB:
if (*(unsigned char const *)&endian != 1)
dso->needs_swap = DSO_SWAP__YES;
break;
case ELFDATA2MSB:
if (*(unsigned char const *)&endian != 0)
dso->needs_swap = DSO_SWAP__YES;
break;
default:
pr_err("unrecognized DSO data encoding %d\n", eidata);
return -EINVAL;
}
return 0;
}
static int decompress_kmodule(struct dso *dso, const char *name,
enum dso_binary_type type)
{
int fd = -1;
char tmpbuf[] = "/tmp/perf-kmod-XXXXXX";
struct kmod_path m;
if (type != DSO_BINARY_TYPE__SYSTEM_PATH_KMODULE_COMP &&
type != DSO_BINARY_TYPE__GUEST_KMODULE_COMP &&
type != DSO_BINARY_TYPE__BUILD_ID_CACHE)
return -1;
if (type == DSO_BINARY_TYPE__BUILD_ID_CACHE)
name = dso->long_name;
if (kmod_path__parse_ext(&m, name) || !m.comp)
return -1;
fd = mkstemp(tmpbuf);
if (fd < 0) {
dso->load_errno = errno;
goto out;
}
if (!decompress_to_file(m.ext, name, fd)) {
dso->load_errno = DSO_LOAD_ERRNO__DECOMPRESSION_FAILURE;
close(fd);
fd = -1;
}
unlink(tmpbuf);
out:
free(m.ext);
return fd;
}
bool symsrc__possibly_runtime(struct symsrc *ss)
{
return ss->dynsym || ss->opdsec;
}
bool symsrc__has_symtab(struct symsrc *ss)
{
return ss->symtab != NULL;
}
void symsrc__destroy(struct symsrc *ss)
{
zfree(&ss->name);
elf_end(ss->elf);
close(ss->fd);
}
bool __weak elf__needs_adjust_symbols(GElf_Ehdr ehdr)
{
return ehdr.e_type == ET_EXEC || ehdr.e_type == ET_REL;
}
int symsrc__init(struct symsrc *ss, struct dso *dso, const char *name,
enum dso_binary_type type)
{
int err = -1;
GElf_Ehdr ehdr;
Elf *elf;
int fd;
if (dso__needs_decompress(dso)) {
fd = decompress_kmodule(dso, name, type);
if (fd < 0)
return -1;
} else {
fd = open(name, O_RDONLY);
if (fd < 0) {
dso->load_errno = errno;
return -1;
}
}
elf = elf_begin(fd, PERF_ELF_C_READ_MMAP, NULL);
if (elf == NULL) {
pr_debug("%s: cannot read %s ELF file.\n", __func__, name);
dso->load_errno = DSO_LOAD_ERRNO__INVALID_ELF;
goto out_close;
}
if (gelf_getehdr(elf, &ehdr) == NULL) {
dso->load_errno = DSO_LOAD_ERRNO__INVALID_ELF;
pr_debug("%s: cannot get elf header.\n", __func__);
goto out_elf_end;
}
if (dso__swap_init(dso, ehdr.e_ident[EI_DATA])) {
dso->load_errno = DSO_LOAD_ERRNO__INTERNAL_ERROR;
goto out_elf_end;
}
if (dso->has_build_id && !symbol_conf.ignore_vmlinux_buildid) {
u8 build_id[BUILD_ID_SIZE];
if (elf_read_build_id(elf, build_id, BUILD_ID_SIZE) < 0) {
dso->load_errno = DSO_LOAD_ERRNO__CANNOT_READ_BUILDID;
goto out_elf_end;
}
if (!dso__build_id_equal(dso, build_id)) {
pr_debug("%s: build id mismatch for %s.\n", __func__, name);
dso->load_errno = DSO_LOAD_ERRNO__MISMATCHING_BUILDID;
goto out_elf_end;
}
}
ss->is_64_bit = (gelf_getclass(elf) == ELFCLASS64);
ss->symtab = elf_section_by_name(elf, &ehdr, &ss->symshdr, ".symtab",
NULL);
if (ss->symshdr.sh_type != SHT_SYMTAB)
ss->symtab = NULL;
ss->dynsym_idx = 0;
ss->dynsym = elf_section_by_name(elf, &ehdr, &ss->dynshdr, ".dynsym",
&ss->dynsym_idx);
if (ss->dynshdr.sh_type != SHT_DYNSYM)
ss->dynsym = NULL;
ss->opdidx = 0;
ss->opdsec = elf_section_by_name(elf, &ehdr, &ss->opdshdr, ".opd",
&ss->opdidx);
if (ss->opdshdr.sh_type != SHT_PROGBITS)
ss->opdsec = NULL;
if (dso->kernel == DSO_TYPE_USER)
ss->adjust_symbols = true;
else
ss->adjust_symbols = elf__needs_adjust_symbols(ehdr);
ss->name = strdup(name);
if (!ss->name) {
dso->load_errno = errno;
goto out_elf_end;
}
ss->elf = elf;
ss->fd = fd;
ss->ehdr = ehdr;
ss->type = type;
return 0;
out_elf_end:
elf_end(elf);
out_close:
close(fd);
return err;
}
static bool ref_reloc_sym_not_found(struct kmap *kmap)
{
return kmap && kmap->ref_reloc_sym && kmap->ref_reloc_sym->name &&
!kmap->ref_reloc_sym->unrelocated_addr;
}
static u64 ref_reloc(struct kmap *kmap)
{
if (kmap && kmap->ref_reloc_sym &&
kmap->ref_reloc_sym->unrelocated_addr)
return kmap->ref_reloc_sym->addr -
kmap->ref_reloc_sym->unrelocated_addr;
return 0;
}
void __weak arch__sym_update(struct symbol *s __maybe_unused,
GElf_Sym *sym __maybe_unused) { }
int dso__load_sym(struct dso *dso, struct map *map, struct symsrc *syms_ss,
struct symsrc *runtime_ss, int kmodule)
{
struct kmap *kmap = dso->kernel ? map__kmap(map) : NULL;
struct map_groups *kmaps = kmap ? map__kmaps(map) : NULL;
struct map *curr_map = map;
struct dso *curr_dso = dso;
Elf_Data *symstrs, *secstrs;
uint32_t nr_syms;
int err = -1;
uint32_t idx;
GElf_Ehdr ehdr;
GElf_Shdr shdr;
GElf_Shdr tshdr;
Elf_Data *syms, *opddata = NULL;
GElf_Sym sym;
Elf_Scn *sec, *sec_strndx;
Elf *elf;
int nr = 0;
bool remap_kernel = false, adjust_kernel_syms = false;
if (kmap && !kmaps)
return -1;
dso->symtab_type = syms_ss->type;
dso->is_64_bit = syms_ss->is_64_bit;
dso->rel = syms_ss->ehdr.e_type == ET_REL;
if (kmodule && syms_ss->symtab)
symbols__delete(&dso->symbols[map->type]);
if (!syms_ss->symtab) {
if (dso->kernel)
goto out_elf_end;
syms_ss->symtab = syms_ss->dynsym;
syms_ss->symshdr = syms_ss->dynshdr;
}
elf = syms_ss->elf;
ehdr = syms_ss->ehdr;
sec = syms_ss->symtab;
shdr = syms_ss->symshdr;
if (elf_section_by_name(runtime_ss->elf, &runtime_ss->ehdr, &tshdr,
".text", NULL))
dso->text_offset = tshdr.sh_addr - tshdr.sh_offset;
if (runtime_ss->opdsec)
opddata = elf_rawdata(runtime_ss->opdsec, NULL);
syms = elf_getdata(sec, NULL);
if (syms == NULL)
goto out_elf_end;
sec = elf_getscn(elf, shdr.sh_link);
if (sec == NULL)
goto out_elf_end;
symstrs = elf_getdata(sec, NULL);
if (symstrs == NULL)
goto out_elf_end;
sec_strndx = elf_getscn(runtime_ss->elf, runtime_ss->ehdr.e_shstrndx);
if (sec_strndx == NULL)
goto out_elf_end;
secstrs = elf_getdata(sec_strndx, NULL);
if (secstrs == NULL)
goto out_elf_end;
nr_syms = shdr.sh_size / shdr.sh_entsize;
memset(&sym, 0, sizeof(sym));
if (ref_reloc_sym_not_found(kmap)) {
elf_symtab__for_each_symbol(syms, nr_syms, idx, sym) {
const char *elf_name = elf_sym__name(&sym, symstrs);
if (strcmp(elf_name, kmap->ref_reloc_sym->name))
continue;
kmap->ref_reloc_sym->unrelocated_addr = sym.st_value;
map->reloc = kmap->ref_reloc_sym->addr -
kmap->ref_reloc_sym->unrelocated_addr;
break;
}
}
if (dso__is_vdso(dso))
map->reloc = map->start - dso->text_offset;
dso->adjust_symbols = runtime_ss->adjust_symbols || ref_reloc(kmap);
if (map->type == MAP__FUNCTION && (dso->kernel || kmodule)) {
remap_kernel = true;
adjust_kernel_syms = dso->adjust_symbols;
}
elf_symtab__for_each_symbol(syms, nr_syms, idx, sym) {
struct symbol *f;
const char *elf_name = elf_sym__name(&sym, symstrs);
char *demangled = NULL;
int is_label = elf_sym__is_label(&sym);
const char *section_name;
bool used_opd = false;
if (!is_label && !elf_sym__is_a(&sym, map->type))
continue;
if (ehdr.e_machine == EM_ARM || ehdr.e_machine == EM_AARCH64) {
if (elf_name[0] == '$' && strchr("adtx", elf_name[1])
&& (elf_name[2] == '\0' || elf_name[2] == '.'))
continue;
}
if (runtime_ss->opdsec && sym.st_shndx == runtime_ss->opdidx) {
u32 offset = sym.st_value - syms_ss->opdshdr.sh_addr;
u64 *opd = opddata->d_buf + offset;
sym.st_value = DSO__SWAP(dso, u64, *opd);
sym.st_shndx = elf_addr_to_index(runtime_ss->elf,
sym.st_value);
used_opd = true;
}
if (sym.st_shndx == SHN_ABS)
continue;
sec = elf_getscn(runtime_ss->elf, sym.st_shndx);
if (!sec)
goto out_elf_end;
gelf_getshdr(sec, &shdr);
if (is_label && !elf_sec__is_a(&shdr, secstrs, map->type))
continue;
section_name = elf_sec__name(&shdr, secstrs);
if ((ehdr.e_machine == EM_ARM) &&
(map->type == MAP__FUNCTION) &&
(sym.st_value & 1))
--sym.st_value;
if (dso->kernel || kmodule) {
char dso_name[PATH_MAX];
if (adjust_kernel_syms)
sym.st_value -= shdr.sh_addr - shdr.sh_offset;
if (strcmp(section_name,
(curr_dso->short_name +
dso->short_name_len)) == 0)
goto new_symbol;
if (strcmp(section_name, ".text") == 0) {
if (remap_kernel && dso->kernel) {
remap_kernel = false;
map->start = shdr.sh_addr +
ref_reloc(kmap);
map->end = map->start + shdr.sh_size;
map->pgoff = shdr.sh_offset;
map->map_ip = map__map_ip;
map->unmap_ip = map__unmap_ip;
if (kmaps) {
map__get(map);
map_groups__remove(kmaps, map);
map_groups__insert(kmaps, map);
map__put(map);
}
}
if (remap_kernel && kmodule) {
remap_kernel = false;
map->pgoff = shdr.sh_offset;
}
curr_map = map;
curr_dso = dso;
goto new_symbol;
}
if (!kmap)
goto new_symbol;
snprintf(dso_name, sizeof(dso_name),
"%s%s", dso->short_name, section_name);
curr_map = map_groups__find_by_name(kmaps, map->type, dso_name);
if (curr_map == NULL) {
u64 start = sym.st_value;
if (kmodule)
start += map->start + shdr.sh_offset;
curr_dso = dso__new(dso_name);
if (curr_dso == NULL)
goto out_elf_end;
curr_dso->kernel = dso->kernel;
curr_dso->long_name = dso->long_name;
curr_dso->long_name_len = dso->long_name_len;
curr_map = map__new2(start, curr_dso,
map->type);
dso__put(curr_dso);
if (curr_map == NULL) {
goto out_elf_end;
}
if (adjust_kernel_syms) {
curr_map->start = shdr.sh_addr +
ref_reloc(kmap);
curr_map->end = curr_map->start +
shdr.sh_size;
curr_map->pgoff = shdr.sh_offset;
} else {
curr_map->map_ip = identity__map_ip;
curr_map->unmap_ip = identity__map_ip;
}
curr_dso->symtab_type = dso->symtab_type;
map_groups__insert(kmaps, curr_map);
dsos__add(&map->groups->machine->dsos, curr_dso);
map__put(curr_map);
dso__set_loaded(curr_dso, map->type);
} else
curr_dso = curr_map->dso;
goto new_symbol;
}
if ((used_opd && runtime_ss->adjust_symbols)
|| (!used_opd && syms_ss->adjust_symbols)) {
pr_debug4("%s: adjusting symbol: st_value: %#" PRIx64 " "
"sh_addr: %#" PRIx64 " sh_offset: %#" PRIx64 "\n", __func__,
(u64)sym.st_value, (u64)shdr.sh_addr,
(u64)shdr.sh_offset);
sym.st_value -= shdr.sh_addr - shdr.sh_offset;
}
new_symbol:
demangled = demangle_sym(dso, kmodule, elf_name);
if (demangled != NULL)
elf_name = demangled;
f = symbol__new(sym.st_value, sym.st_size,
GELF_ST_BIND(sym.st_info), elf_name);
free(demangled);
if (!f)
goto out_elf_end;
arch__sym_update(f, &sym);
__symbols__insert(&curr_dso->symbols[curr_map->type], f, dso->kernel);
nr++;
}
if (nr > 0) {
symbols__fixup_end(&dso->symbols[map->type]);
symbols__fixup_duplicate(&dso->symbols[map->type]);
if (kmap) {
__map_groups__fixup_end(kmaps, map->type);
}
}
err = nr;
out_elf_end:
return err;
}
static int elf_read_maps(Elf *elf, bool exe, mapfn_t mapfn, void *data)
{
GElf_Phdr phdr;
size_t i, phdrnum;
int err;
u64 sz;
if (elf_getphdrnum(elf, &phdrnum))
return -1;
for (i = 0; i < phdrnum; i++) {
if (gelf_getphdr(elf, i, &phdr) == NULL)
return -1;
if (phdr.p_type != PT_LOAD)
continue;
if (exe) {
if (!(phdr.p_flags & PF_X))
continue;
} else {
if (!(phdr.p_flags & PF_R))
continue;
}
sz = min(phdr.p_memsz, phdr.p_filesz);
if (!sz)
continue;
err = mapfn(phdr.p_vaddr, sz, phdr.p_offset, data);
if (err)
return err;
}
return 0;
}
int file__read_maps(int fd, bool exe, mapfn_t mapfn, void *data,
bool *is_64_bit)
{
int err;
Elf *elf;
elf = elf_begin(fd, PERF_ELF_C_READ_MMAP, NULL);
if (elf == NULL)
return -1;
if (is_64_bit)
*is_64_bit = (gelf_getclass(elf) == ELFCLASS64);
err = elf_read_maps(elf, exe, mapfn, data);
elf_end(elf);
return err;
}
enum dso_type dso__type_fd(int fd)
{
enum dso_type dso_type = DSO__TYPE_UNKNOWN;
GElf_Ehdr ehdr;
Elf_Kind ek;
Elf *elf;
elf = elf_begin(fd, PERF_ELF_C_READ_MMAP, NULL);
if (elf == NULL)
goto out;
ek = elf_kind(elf);
if (ek != ELF_K_ELF)
goto out_end;
if (gelf_getclass(elf) == ELFCLASS64) {
dso_type = DSO__TYPE_64BIT;
goto out_end;
}
if (gelf_getehdr(elf, &ehdr) == NULL)
goto out_end;
if (ehdr.e_machine == EM_X86_64)
dso_type = DSO__TYPE_X32BIT;
else
dso_type = DSO__TYPE_32BIT;
out_end:
elf_end(elf);
out:
return dso_type;
}
static int copy_bytes(int from, off_t from_offs, int to, off_t to_offs, u64 len)
{
ssize_t r;
size_t n;
int err = -1;
char *buf = malloc(page_size);
if (buf == NULL)
return -1;
if (lseek(to, to_offs, SEEK_SET) != to_offs)
goto out;
if (lseek(from, from_offs, SEEK_SET) != from_offs)
goto out;
while (len) {
n = page_size;
if (len < n)
n = len;
r = read(from, buf, n);
if (r < 0)
goto out;
if (!r)
break;
n = r;
r = write(to, buf, n);
if (r < 0)
goto out;
if ((size_t)r != n)
goto out;
len -= n;
}
err = 0;
out:
free(buf);
return err;
}
static int kcore__open(struct kcore *kcore, const char *filename)
{
GElf_Ehdr *ehdr;
kcore->fd = open(filename, O_RDONLY);
if (kcore->fd == -1)
return -1;
kcore->elf = elf_begin(kcore->fd, ELF_C_READ, NULL);
if (!kcore->elf)
goto out_close;
kcore->elfclass = gelf_getclass(kcore->elf);
if (kcore->elfclass == ELFCLASSNONE)
goto out_end;
ehdr = gelf_getehdr(kcore->elf, &kcore->ehdr);
if (!ehdr)
goto out_end;
return 0;
out_end:
elf_end(kcore->elf);
out_close:
close(kcore->fd);
return -1;
}
static int kcore__init(struct kcore *kcore, char *filename, int elfclass,
bool temp)
{
kcore->elfclass = elfclass;
if (temp)
kcore->fd = mkstemp(filename);
else
kcore->fd = open(filename, O_WRONLY | O_CREAT | O_EXCL, 0400);
if (kcore->fd == -1)
return -1;
kcore->elf = elf_begin(kcore->fd, ELF_C_WRITE, NULL);
if (!kcore->elf)
goto out_close;
if (!gelf_newehdr(kcore->elf, elfclass))
goto out_end;
memset(&kcore->ehdr, 0, sizeof(GElf_Ehdr));
return 0;
out_end:
elf_end(kcore->elf);
out_close:
close(kcore->fd);
unlink(filename);
return -1;
}
static void kcore__close(struct kcore *kcore)
{
elf_end(kcore->elf);
close(kcore->fd);
}
static int kcore__copy_hdr(struct kcore *from, struct kcore *to, size_t count)
{
GElf_Ehdr *ehdr = &to->ehdr;
GElf_Ehdr *kehdr = &from->ehdr;
memcpy(ehdr->e_ident, kehdr->e_ident, EI_NIDENT);
ehdr->e_type = kehdr->e_type;
ehdr->e_machine = kehdr->e_machine;
ehdr->e_version = kehdr->e_version;
ehdr->e_entry = 0;
ehdr->e_shoff = 0;
ehdr->e_flags = kehdr->e_flags;
ehdr->e_phnum = count;
ehdr->e_shentsize = 0;
ehdr->e_shnum = 0;
ehdr->e_shstrndx = 0;
if (from->elfclass == ELFCLASS32) {
ehdr->e_phoff = sizeof(Elf32_Ehdr);
ehdr->e_ehsize = sizeof(Elf32_Ehdr);
ehdr->e_phentsize = sizeof(Elf32_Phdr);
} else {
ehdr->e_phoff = sizeof(Elf64_Ehdr);
ehdr->e_ehsize = sizeof(Elf64_Ehdr);
ehdr->e_phentsize = sizeof(Elf64_Phdr);
}
if (!gelf_update_ehdr(to->elf, ehdr))
return -1;
if (!gelf_newphdr(to->elf, count))
return -1;
return 0;
}
static int kcore__add_phdr(struct kcore *kcore, int idx, off_t offset,
u64 addr, u64 len)
{
GElf_Phdr phdr = {
.p_type = PT_LOAD,
.p_flags = PF_R | PF_W | PF_X,
.p_offset = offset,
.p_vaddr = addr,
.p_paddr = 0,
.p_filesz = len,
.p_memsz = len,
.p_align = page_size,
};
if (!gelf_update_phdr(kcore->elf, idx, &phdr))
return -1;
return 0;
}
static off_t kcore__write(struct kcore *kcore)
{
return elf_update(kcore->elf, ELF_C_WRITE);
}
static int kcore_copy__process_kallsyms(void *arg, const char *name, char type,
u64 start)
{
struct kcore_copy_info *kci = arg;
if (!symbol_type__is_a(type, MAP__FUNCTION))
return 0;
if (strchr(name, '[')) {
if (start > kci->last_module_symbol)
kci->last_module_symbol = start;
return 0;
}
if (!kci->first_symbol || start < kci->first_symbol)
kci->first_symbol = start;
if (!kci->last_symbol || start > kci->last_symbol)
kci->last_symbol = start;
if (!strcmp(name, "_stext")) {
kci->stext = start;
return 0;
}
if (!strcmp(name, "_etext")) {
kci->etext = start;
return 0;
}
return 0;
}
static int kcore_copy__parse_kallsyms(struct kcore_copy_info *kci,
const char *dir)
{
char kallsyms_filename[PATH_MAX];
scnprintf(kallsyms_filename, PATH_MAX, "%s/kallsyms", dir);
if (symbol__restricted_filename(kallsyms_filename, "/proc/kallsyms"))
return -1;
if (kallsyms__parse(kallsyms_filename, kci,
kcore_copy__process_kallsyms) < 0)
return -1;
return 0;
}
static int kcore_copy__process_modules(void *arg,
const char *name __maybe_unused,
u64 start)
{
struct kcore_copy_info *kci = arg;
if (!kci->first_module || start < kci->first_module)
kci->first_module = start;
return 0;
}
static int kcore_copy__parse_modules(struct kcore_copy_info *kci,
const char *dir)
{
char modules_filename[PATH_MAX];
scnprintf(modules_filename, PATH_MAX, "%s/modules", dir);
if (symbol__restricted_filename(modules_filename, "/proc/modules"))
return -1;
if (modules__parse(modules_filename, kci,
kcore_copy__process_modules) < 0)
return -1;
return 0;
}
static void kcore_copy__map(struct phdr_data *p, u64 start, u64 end, u64 pgoff,
u64 s, u64 e)
{
if (p->addr || s < start || s >= end)
return;
p->addr = s;
p->offset = (s - start) + pgoff;
p->len = e < end ? e - s : end - s;
}
static int kcore_copy__read_map(u64 start, u64 len, u64 pgoff, void *data)
{
struct kcore_copy_info *kci = data;
u64 end = start + len;
kcore_copy__map(&kci->kernel_map, start, end, pgoff, kci->stext,
kci->etext);
kcore_copy__map(&kci->modules_map, start, end, pgoff, kci->first_module,
kci->last_module_symbol);
return 0;
}
static int kcore_copy__read_maps(struct kcore_copy_info *kci, Elf *elf)
{
if (elf_read_maps(elf, true, kcore_copy__read_map, kci) < 0)
return -1;
return 0;
}
static int kcore_copy__calc_maps(struct kcore_copy_info *kci, const char *dir,
Elf *elf)
{
if (kcore_copy__parse_kallsyms(kci, dir))
return -1;
if (kcore_copy__parse_modules(kci, dir))
return -1;
if (kci->stext)
kci->stext = round_down(kci->stext, page_size);
else
kci->stext = round_down(kci->first_symbol, page_size);
if (kci->etext) {
kci->etext = round_up(kci->etext, page_size);
} else if (kci->last_symbol) {
kci->etext = round_up(kci->last_symbol, page_size);
kci->etext += page_size;
}
kci->first_module = round_down(kci->first_module, page_size);
if (kci->last_module_symbol) {
kci->last_module_symbol = round_up(kci->last_module_symbol,
page_size);
kci->last_module_symbol += page_size;
}
if (!kci->stext || !kci->etext)
return -1;
if (kci->first_module && !kci->last_module_symbol)
return -1;
return kcore_copy__read_maps(kci, elf);
}
static int kcore_copy__copy_file(const char *from_dir, const char *to_dir,
const char *name)
{
char from_filename[PATH_MAX];
char to_filename[PATH_MAX];
scnprintf(from_filename, PATH_MAX, "%s/%s", from_dir, name);
scnprintf(to_filename, PATH_MAX, "%s/%s", to_dir, name);
return copyfile_mode(from_filename, to_filename, 0400);
}
static int kcore_copy__unlink(const char *dir, const char *name)
{
char filename[PATH_MAX];
scnprintf(filename, PATH_MAX, "%s/%s", dir, name);
return unlink(filename);
}
static int kcore_copy__compare_fds(int from, int to)
{
char *buf_from;
char *buf_to;
ssize_t ret;
size_t len;
int err = -1;
buf_from = malloc(page_size);
buf_to = malloc(page_size);
if (!buf_from || !buf_to)
goto out;
while (1) {
ret = read(from, buf_from, page_size);
if (ret < 0)
goto out;
if (!ret)
break;
len = ret;
if (readn(to, buf_to, len) != (int)len)
goto out;
if (memcmp(buf_from, buf_to, len))
goto out;
}
err = 0;
out:
free(buf_to);
free(buf_from);
return err;
}
static int kcore_copy__compare_files(const char *from_filename,
const char *to_filename)
{
int from, to, err = -1;
from = open(from_filename, O_RDONLY);
if (from < 0)
return -1;
to = open(to_filename, O_RDONLY);
if (to < 0)
goto out_close_from;
err = kcore_copy__compare_fds(from, to);
close(to);
out_close_from:
close(from);
return err;
}
static int kcore_copy__compare_file(const char *from_dir, const char *to_dir,
const char *name)
{
char from_filename[PATH_MAX];
char to_filename[PATH_MAX];
scnprintf(from_filename, PATH_MAX, "%s/%s", from_dir, name);
scnprintf(to_filename, PATH_MAX, "%s/%s", to_dir, name);
return kcore_copy__compare_files(from_filename, to_filename);
}
int kcore_copy(const char *from_dir, const char *to_dir)
{
struct kcore kcore;
struct kcore extract;
size_t count = 2;
int idx = 0, err = -1;
off_t offset = page_size, sz, modules_offset = 0;
struct kcore_copy_info kci = { .stext = 0, };
char kcore_filename[PATH_MAX];
char extract_filename[PATH_MAX];
if (kcore_copy__copy_file(from_dir, to_dir, "kallsyms"))
return -1;
if (kcore_copy__copy_file(from_dir, to_dir, "modules"))
goto out_unlink_kallsyms;
scnprintf(kcore_filename, PATH_MAX, "%s/kcore", from_dir);
scnprintf(extract_filename, PATH_MAX, "%s/kcore", to_dir);
if (kcore__open(&kcore, kcore_filename))
goto out_unlink_modules;
if (kcore_copy__calc_maps(&kci, from_dir, kcore.elf))
goto out_kcore_close;
if (kcore__init(&extract, extract_filename, kcore.elfclass, false))
goto out_kcore_close;
if (!kci.modules_map.addr)
count -= 1;
if (kcore__copy_hdr(&kcore, &extract, count))
goto out_extract_close;
if (kcore__add_phdr(&extract, idx++, offset, kci.kernel_map.addr,
kci.kernel_map.len))
goto out_extract_close;
if (kci.modules_map.addr) {
modules_offset = offset + kci.kernel_map.len;
if (kcore__add_phdr(&extract, idx, modules_offset,
kci.modules_map.addr, kci.modules_map.len))
goto out_extract_close;
}
sz = kcore__write(&extract);
if (sz < 0 || sz > offset)
goto out_extract_close;
if (copy_bytes(kcore.fd, kci.kernel_map.offset, extract.fd, offset,
kci.kernel_map.len))
goto out_extract_close;
if (modules_offset && copy_bytes(kcore.fd, kci.modules_map.offset,
extract.fd, modules_offset,
kci.modules_map.len))
goto out_extract_close;
if (kcore_copy__compare_file(from_dir, to_dir, "modules"))
goto out_extract_close;
if (kcore_copy__compare_file(from_dir, to_dir, "kallsyms"))
goto out_extract_close;
err = 0;
out_extract_close:
kcore__close(&extract);
if (err)
unlink(extract_filename);
out_kcore_close:
kcore__close(&kcore);
out_unlink_modules:
if (err)
kcore_copy__unlink(to_dir, "modules");
out_unlink_kallsyms:
if (err)
kcore_copy__unlink(to_dir, "kallsyms");
return err;
}
int kcore_extract__create(struct kcore_extract *kce)
{
struct kcore kcore;
struct kcore extract;
size_t count = 1;
int idx = 0, err = -1;
off_t offset = page_size, sz;
if (kcore__open(&kcore, kce->kcore_filename))
return -1;
strcpy(kce->extract_filename, PERF_KCORE_EXTRACT);
if (kcore__init(&extract, kce->extract_filename, kcore.elfclass, true))
goto out_kcore_close;
if (kcore__copy_hdr(&kcore, &extract, count))
goto out_extract_close;
if (kcore__add_phdr(&extract, idx, offset, kce->addr, kce->len))
goto out_extract_close;
sz = kcore__write(&extract);
if (sz < 0 || sz > offset)
goto out_extract_close;
if (copy_bytes(kcore.fd, kce->offs, extract.fd, offset, kce->len))
goto out_extract_close;
err = 0;
out_extract_close:
kcore__close(&extract);
if (err)
unlink(kce->extract_filename);
out_kcore_close:
kcore__close(&kcore);
return err;
}
void kcore_extract__delete(struct kcore_extract *kce)
{
unlink(kce->extract_filename);
}
static int populate_sdt_note(Elf **elf, const char *data, size_t len,
struct list_head *sdt_notes)
{
const char *provider, *name;
struct sdt_note *tmp = NULL;
GElf_Ehdr ehdr;
GElf_Addr base_off = 0;
GElf_Shdr shdr;
int ret = -EINVAL;
union {
Elf64_Addr a64[NR_ADDR];
Elf32_Addr a32[NR_ADDR];
} buf;
Elf_Data dst = {
.d_buf = &buf, .d_type = ELF_T_ADDR, .d_version = EV_CURRENT,
.d_size = gelf_fsize((*elf), ELF_T_ADDR, NR_ADDR, EV_CURRENT),
.d_off = 0, .d_align = 0
};
Elf_Data src = {
.d_buf = (void *) data, .d_type = ELF_T_ADDR,
.d_version = EV_CURRENT, .d_size = dst.d_size, .d_off = 0,
.d_align = 0
};
tmp = (struct sdt_note *)calloc(1, sizeof(struct sdt_note));
if (!tmp) {
ret = -ENOMEM;
goto out_err;
}
INIT_LIST_HEAD(&tmp->note_list);
if (len < dst.d_size + 3)
goto out_free_note;
if (gelf_xlatetom(*elf, &dst, &src,
elf_getident(*elf, NULL)[EI_DATA]) == NULL) {
pr_err("gelf_xlatetom : %s\n", elf_errmsg(-1));
goto out_free_note;
}
provider = data + dst.d_size;
name = (const char *)memchr(provider, '\0', data + len - provider);
if (name++ == NULL)
goto out_free_note;
tmp->provider = strdup(provider);
if (!tmp->provider) {
ret = -ENOMEM;
goto out_free_note;
}
tmp->name = strdup(name);
if (!tmp->name) {
ret = -ENOMEM;
goto out_free_prov;
}
if (gelf_getclass(*elf) == ELFCLASS32) {
memcpy(&tmp->addr, &buf, 3 * sizeof(Elf32_Addr));
tmp->bit32 = true;
} else {
memcpy(&tmp->addr, &buf, 3 * sizeof(Elf64_Addr));
tmp->bit32 = false;
}
if (!gelf_getehdr(*elf, &ehdr)) {
pr_debug("%s : cannot get elf header.\n", __func__);
ret = -EBADF;
goto out_free_name;
}
if (elf_section_by_name(*elf, &ehdr, &shdr, SDT_BASE_SCN, NULL)) {
base_off = shdr.sh_offset;
if (base_off) {
if (tmp->bit32)
tmp->addr.a32[0] = tmp->addr.a32[0] + base_off -
tmp->addr.a32[1];
else
tmp->addr.a64[0] = tmp->addr.a64[0] + base_off -
tmp->addr.a64[1];
}
}
list_add_tail(&tmp->note_list, sdt_notes);
return 0;
out_free_name:
free(tmp->name);
out_free_prov:
free(tmp->provider);
out_free_note:
free(tmp);
out_err:
return ret;
}
static int construct_sdt_notes_list(Elf *elf, struct list_head *sdt_notes)
{
GElf_Ehdr ehdr;
Elf_Scn *scn = NULL;
Elf_Data *data;
GElf_Shdr shdr;
size_t shstrndx, next;
GElf_Nhdr nhdr;
size_t name_off, desc_off, offset;
int ret = 0;
if (gelf_getehdr(elf, &ehdr) == NULL) {
ret = -EBADF;
goto out_ret;
}
if (elf_getshdrstrndx(elf, &shstrndx) != 0) {
ret = -EBADF;
goto out_ret;
}
scn = elf_section_by_name(elf, &ehdr, &shdr, SDT_NOTE_SCN, NULL);
if (!scn) {
ret = -ENOENT;
goto out_ret;
}
if ((shdr.sh_type != SHT_NOTE) || (shdr.sh_flags & SHF_ALLOC)) {
ret = -ENOENT;
goto out_ret;
}
data = elf_getdata(scn, NULL);
for (offset = 0; (next = gelf_getnote(data, offset, &nhdr, &name_off,
&desc_off)) > 0; offset = next) {
if (nhdr.n_namesz == sizeof(SDT_NOTE_NAME) &&
!memcmp(data->d_buf + name_off, SDT_NOTE_NAME,
sizeof(SDT_NOTE_NAME))) {
if (nhdr.n_type != SDT_NOTE_TYPE)
goto out_ret;
ret = populate_sdt_note(&elf, ((data->d_buf) + desc_off),
nhdr.n_descsz, sdt_notes);
if (ret < 0)
goto out_ret;
}
}
if (list_empty(sdt_notes))
ret = -ENOENT;
out_ret:
return ret;
}
int get_sdt_note_list(struct list_head *head, const char *target)
{
Elf *elf;
int fd, ret;
fd = open(target, O_RDONLY);
if (fd < 0)
return -EBADF;
elf = elf_begin(fd, PERF_ELF_C_READ_MMAP, NULL);
if (!elf) {
ret = -EBADF;
goto out_close;
}
ret = construct_sdt_notes_list(elf, head);
elf_end(elf);
out_close:
close(fd);
return ret;
}
int cleanup_sdt_note_list(struct list_head *sdt_notes)
{
struct sdt_note *tmp, *pos;
int nr_free = 0;
list_for_each_entry_safe(pos, tmp, sdt_notes, note_list) {
list_del(&pos->note_list);
free(pos->name);
free(pos->provider);
free(pos);
nr_free++;
}
return nr_free;
}
int sdt_notes__get_count(struct list_head *start)
{
struct sdt_note *sdt_ptr;
int count = 0;
list_for_each_entry(sdt_ptr, start, note_list)
count++;
return count;
}
void symbol__elf_init(void)
{
elf_version(EV_CURRENT);
}
