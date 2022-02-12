static inline bool elf_is_elf_file(const struct elfhdr *ehdr)
{
return memcmp(ehdr->e_ident, ELFMAG, SELFMAG) == 0;
}
static uint64_t elf64_to_cpu(const struct elfhdr *ehdr, uint64_t value)
{
if (ehdr->e_ident[EI_DATA] == ELFDATA2LSB)
value = le64_to_cpu(value);
else if (ehdr->e_ident[EI_DATA] == ELFDATA2MSB)
value = be64_to_cpu(value);
return value;
}
static uint16_t elf16_to_cpu(const struct elfhdr *ehdr, uint16_t value)
{
if (ehdr->e_ident[EI_DATA] == ELFDATA2LSB)
value = le16_to_cpu(value);
else if (ehdr->e_ident[EI_DATA] == ELFDATA2MSB)
value = be16_to_cpu(value);
return value;
}
static uint32_t elf32_to_cpu(const struct elfhdr *ehdr, uint32_t value)
{
if (ehdr->e_ident[EI_DATA] == ELFDATA2LSB)
value = le32_to_cpu(value);
else if (ehdr->e_ident[EI_DATA] == ELFDATA2MSB)
value = be32_to_cpu(value);
return value;
}
static bool elf_is_ehdr_sane(const struct elfhdr *ehdr, size_t buf_len)
{
if (ehdr->e_phnum > 0 && ehdr->e_phentsize != sizeof(struct elf_phdr)) {
pr_debug("Bad program header size.\n");
return false;
} else if (ehdr->e_shnum > 0 &&
ehdr->e_shentsize != sizeof(struct elf_shdr)) {
pr_debug("Bad section header size.\n");
return false;
} else if (ehdr->e_ident[EI_VERSION] != EV_CURRENT ||
ehdr->e_version != EV_CURRENT) {
pr_debug("Unknown ELF version.\n");
return false;
}
if (ehdr->e_phoff > 0 && ehdr->e_phnum > 0) {
size_t phdr_size;
phdr_size = sizeof(struct elf_phdr) * ehdr->e_phnum;
if (ehdr->e_phoff + phdr_size < ehdr->e_phoff) {
pr_debug("Program headers at invalid location.\n");
return false;
} else if (ehdr->e_phoff + phdr_size > buf_len) {
pr_debug("Program headers truncated.\n");
return false;
}
}
if (ehdr->e_shoff > 0 && ehdr->e_shnum > 0) {
size_t shdr_size;
shdr_size = sizeof(struct elf_shdr) * ehdr->e_shnum;
if (ehdr->e_shoff + shdr_size < ehdr->e_shoff) {
pr_debug("Section headers at invalid location.\n");
return false;
} else if (ehdr->e_shoff + shdr_size > buf_len) {
pr_debug("Section headers truncated.\n");
return false;
}
}
return true;
}
static int elf_read_ehdr(const char *buf, size_t len, struct elfhdr *ehdr)
{
struct elfhdr *buf_ehdr;
if (len < sizeof(*buf_ehdr)) {
pr_debug("Buffer is too small to hold ELF header.\n");
return -ENOEXEC;
}
memset(ehdr, 0, sizeof(*ehdr));
memcpy(ehdr->e_ident, buf, sizeof(ehdr->e_ident));
if (!elf_is_elf_file(ehdr)) {
pr_debug("No ELF header magic.\n");
return -ENOEXEC;
}
if (ehdr->e_ident[EI_CLASS] != ELF_CLASS) {
pr_debug("Not a supported ELF class.\n");
return -ENOEXEC;
} else if (ehdr->e_ident[EI_DATA] != ELFDATA2LSB &&
ehdr->e_ident[EI_DATA] != ELFDATA2MSB) {
pr_debug("Not a supported ELF data format.\n");
return -ENOEXEC;
}
buf_ehdr = (struct elfhdr *) buf;
if (elf16_to_cpu(ehdr, buf_ehdr->e_ehsize) != sizeof(*buf_ehdr)) {
pr_debug("Bad ELF header size.\n");
return -ENOEXEC;
}
ehdr->e_type = elf16_to_cpu(ehdr, buf_ehdr->e_type);
ehdr->e_machine = elf16_to_cpu(ehdr, buf_ehdr->e_machine);
ehdr->e_version = elf32_to_cpu(ehdr, buf_ehdr->e_version);
ehdr->e_entry = elf_addr_to_cpu(ehdr, buf_ehdr->e_entry);
ehdr->e_phoff = elf_addr_to_cpu(ehdr, buf_ehdr->e_phoff);
ehdr->e_shoff = elf_addr_to_cpu(ehdr, buf_ehdr->e_shoff);
ehdr->e_flags = elf32_to_cpu(ehdr, buf_ehdr->e_flags);
ehdr->e_phentsize = elf16_to_cpu(ehdr, buf_ehdr->e_phentsize);
ehdr->e_phnum = elf16_to_cpu(ehdr, buf_ehdr->e_phnum);
ehdr->e_shentsize = elf16_to_cpu(ehdr, buf_ehdr->e_shentsize);
ehdr->e_shnum = elf16_to_cpu(ehdr, buf_ehdr->e_shnum);
ehdr->e_shstrndx = elf16_to_cpu(ehdr, buf_ehdr->e_shstrndx);
return elf_is_ehdr_sane(ehdr, len) ? 0 : -ENOEXEC;
}
static bool elf_is_phdr_sane(const struct elf_phdr *phdr, size_t buf_len)
{
if (phdr->p_offset + phdr->p_filesz < phdr->p_offset) {
pr_debug("ELF segment location wraps around.\n");
return false;
} else if (phdr->p_offset + phdr->p_filesz > buf_len) {
pr_debug("ELF segment not in file.\n");
return false;
} else if (phdr->p_paddr + phdr->p_memsz < phdr->p_paddr) {
pr_debug("ELF segment address wraps around.\n");
return false;
}
return true;
}
static int elf_read_phdr(const char *buf, size_t len, struct elf_info *elf_info,
int idx)
{
struct elf_phdr *phdr = (struct elf_phdr *) &elf_info->proghdrs[idx];
const char *pbuf;
struct elf_phdr *buf_phdr;
pbuf = buf + elf_info->ehdr->e_phoff + (idx * sizeof(*buf_phdr));
buf_phdr = (struct elf_phdr *) pbuf;
phdr->p_type = elf32_to_cpu(elf_info->ehdr, buf_phdr->p_type);
phdr->p_offset = elf_addr_to_cpu(elf_info->ehdr, buf_phdr->p_offset);
phdr->p_paddr = elf_addr_to_cpu(elf_info->ehdr, buf_phdr->p_paddr);
phdr->p_vaddr = elf_addr_to_cpu(elf_info->ehdr, buf_phdr->p_vaddr);
phdr->p_flags = elf32_to_cpu(elf_info->ehdr, buf_phdr->p_flags);
phdr->p_filesz = elf_addr_to_cpu(elf_info->ehdr, buf_phdr->p_filesz);
phdr->p_memsz = elf_addr_to_cpu(elf_info->ehdr, buf_phdr->p_memsz);
phdr->p_align = elf_addr_to_cpu(elf_info->ehdr, buf_phdr->p_align);
return elf_is_phdr_sane(phdr, len) ? 0 : -ENOEXEC;
}
static int elf_read_phdrs(const char *buf, size_t len,
struct elf_info *elf_info)
{
size_t phdr_size, i;
const struct elfhdr *ehdr = elf_info->ehdr;
phdr_size = sizeof(struct elf_phdr) * ehdr->e_phnum;
elf_info->proghdrs = kzalloc(phdr_size, GFP_KERNEL);
if (!elf_info->proghdrs)
return -ENOMEM;
for (i = 0; i < ehdr->e_phnum; i++) {
int ret;
ret = elf_read_phdr(buf, len, elf_info, i);
if (ret) {
kfree(elf_info->proghdrs);
elf_info->proghdrs = NULL;
return ret;
}
}
return 0;
}
static bool elf_is_shdr_sane(const struct elf_shdr *shdr, size_t buf_len)
{
bool size_ok;
if (shdr->sh_type == SHT_NULL)
return true;
switch (shdr->sh_type) {
case SHT_SYMTAB:
size_ok = shdr->sh_entsize == sizeof(Elf_Sym);
break;
case SHT_RELA:
size_ok = shdr->sh_entsize == sizeof(Elf_Rela);
break;
case SHT_DYNAMIC:
size_ok = shdr->sh_entsize == sizeof(Elf_Dyn);
break;
case SHT_REL:
size_ok = shdr->sh_entsize == sizeof(Elf_Rel);
break;
case SHT_NOTE:
case SHT_PROGBITS:
case SHT_HASH:
case SHT_NOBITS:
default:
size_ok = true;
break;
}
if (!size_ok) {
pr_debug("ELF section with wrong entry size.\n");
return false;
} else if (shdr->sh_addr + shdr->sh_size < shdr->sh_addr) {
pr_debug("ELF section address wraps around.\n");
return false;
}
if (shdr->sh_type != SHT_NOBITS) {
if (shdr->sh_offset + shdr->sh_size < shdr->sh_offset) {
pr_debug("ELF section location wraps around.\n");
return false;
} else if (shdr->sh_offset + shdr->sh_size > buf_len) {
pr_debug("ELF section not in file.\n");
return false;
}
}
return true;
}
static int elf_read_shdr(const char *buf, size_t len, struct elf_info *elf_info,
int idx)
{
struct elf_shdr *shdr = &elf_info->sechdrs[idx];
const struct elfhdr *ehdr = elf_info->ehdr;
const char *sbuf;
struct elf_shdr *buf_shdr;
sbuf = buf + ehdr->e_shoff + idx * sizeof(*buf_shdr);
buf_shdr = (struct elf_shdr *) sbuf;
shdr->sh_name = elf32_to_cpu(ehdr, buf_shdr->sh_name);
shdr->sh_type = elf32_to_cpu(ehdr, buf_shdr->sh_type);
shdr->sh_addr = elf_addr_to_cpu(ehdr, buf_shdr->sh_addr);
shdr->sh_offset = elf_addr_to_cpu(ehdr, buf_shdr->sh_offset);
shdr->sh_link = elf32_to_cpu(ehdr, buf_shdr->sh_link);
shdr->sh_info = elf32_to_cpu(ehdr, buf_shdr->sh_info);
shdr->sh_flags = elf_addr_to_cpu(ehdr, buf_shdr->sh_flags);
shdr->sh_size = elf_addr_to_cpu(ehdr, buf_shdr->sh_size);
shdr->sh_addralign = elf_addr_to_cpu(ehdr, buf_shdr->sh_addralign);
shdr->sh_entsize = elf_addr_to_cpu(ehdr, buf_shdr->sh_entsize);
return elf_is_shdr_sane(shdr, len) ? 0 : -ENOEXEC;
}
static int elf_read_shdrs(const char *buf, size_t len,
struct elf_info *elf_info)
{
size_t shdr_size, i;
shdr_size = sizeof(struct elf_shdr) * elf_info->ehdr->e_shnum;
elf_info->sechdrs = kzalloc(shdr_size, GFP_KERNEL);
if (!elf_info->sechdrs)
return -ENOMEM;
for (i = 0; i < elf_info->ehdr->e_shnum; i++) {
int ret;
ret = elf_read_shdr(buf, len, elf_info, i);
if (ret) {
kfree(elf_info->sechdrs);
elf_info->sechdrs = NULL;
return ret;
}
}
return 0;
}
int elf_read_from_buffer(const char *buf, size_t len, struct elfhdr *ehdr,
struct elf_info *elf_info)
{
int ret;
ret = elf_read_ehdr(buf, len, ehdr);
if (ret)
return ret;
elf_info->buffer = buf;
elf_info->ehdr = ehdr;
if (ehdr->e_phoff > 0 && ehdr->e_phnum > 0) {
ret = elf_read_phdrs(buf, len, elf_info);
if (ret)
return ret;
}
if (ehdr->e_shoff > 0 && ehdr->e_shnum > 0) {
ret = elf_read_shdrs(buf, len, elf_info);
if (ret) {
kfree(elf_info->proghdrs);
return ret;
}
}
return 0;
}
void elf_free_info(struct elf_info *elf_info)
{
kfree(elf_info->proghdrs);
kfree(elf_info->sechdrs);
memset(elf_info, 0, sizeof(*elf_info));
}
static int build_elf_exec_info(const char *buf, size_t len, struct elfhdr *ehdr,
struct elf_info *elf_info)
{
int i;
int ret;
ret = elf_read_from_buffer(buf, len, ehdr, elf_info);
if (ret)
return ret;
if (ehdr->e_type != ET_EXEC && ehdr->e_type != ET_DYN) {
pr_err("Not an ELF executable.\n");
goto error;
} else if (!elf_info->proghdrs) {
pr_err("No ELF program header.\n");
goto error;
}
for (i = 0; i < ehdr->e_phnum; i++) {
if (elf_info->proghdrs[i].p_type == PT_INTERP) {
pr_err("Requires an ELF interpreter.\n");
goto error;
}
}
return 0;
error:
elf_free_info(elf_info);
return -ENOEXEC;
}
static int elf64_probe(const char *buf, unsigned long len)
{
struct elfhdr ehdr;
struct elf_info elf_info;
int ret;
ret = build_elf_exec_info(buf, len, &ehdr, &elf_info);
if (ret)
return ret;
elf_free_info(&elf_info);
return elf_check_arch(&ehdr) ? 0 : -ENOEXEC;
}
static int elf_exec_load(struct kimage *image, struct elfhdr *ehdr,
struct elf_info *elf_info,
unsigned long *lowest_load_addr)
{
unsigned long base = 0, lowest_addr = UINT_MAX;
int ret;
size_t i;
struct kexec_buf kbuf = { .image = image, .buf_max = ppc64_rma_size,
.top_down = false };
for (i = 0; i < ehdr->e_phnum; i++) {
unsigned long load_addr;
size_t size;
const struct elf_phdr *phdr;
phdr = &elf_info->proghdrs[i];
if (phdr->p_type != PT_LOAD)
continue;
size = phdr->p_filesz;
if (size > phdr->p_memsz)
size = phdr->p_memsz;
kbuf.buffer = (void *) elf_info->buffer + phdr->p_offset;
kbuf.bufsz = size;
kbuf.memsz = phdr->p_memsz;
kbuf.buf_align = phdr->p_align;
kbuf.buf_min = phdr->p_paddr + base;
ret = kexec_add_buffer(&kbuf);
if (ret)
goto out;
load_addr = kbuf.mem;
if (load_addr < lowest_addr)
lowest_addr = load_addr;
}
ehdr->e_entry += base;
*lowest_load_addr = lowest_addr;
ret = 0;
out:
return ret;
}
static void *elf64_load(struct kimage *image, char *kernel_buf,
unsigned long kernel_len, char *initrd,
unsigned long initrd_len, char *cmdline,
unsigned long cmdline_len)
{
int ret;
unsigned int fdt_size;
unsigned long kernel_load_addr, purgatory_load_addr;
unsigned long initrd_load_addr = 0, fdt_load_addr;
void *fdt;
const void *slave_code;
struct elfhdr ehdr;
struct elf_info elf_info;
struct kexec_buf kbuf = { .image = image, .buf_min = 0,
.buf_max = ppc64_rma_size };
ret = build_elf_exec_info(kernel_buf, kernel_len, &ehdr, &elf_info);
if (ret)
goto out;
ret = elf_exec_load(image, &ehdr, &elf_info, &kernel_load_addr);
if (ret)
goto out;
pr_debug("Loaded the kernel at 0x%lx\n", kernel_load_addr);
ret = kexec_load_purgatory(image, 0, ppc64_rma_size, true,
&purgatory_load_addr);
if (ret) {
pr_err("Loading purgatory failed.\n");
goto out;
}
pr_debug("Loaded purgatory at 0x%lx\n", purgatory_load_addr);
if (initrd != NULL) {
kbuf.buffer = initrd;
kbuf.bufsz = kbuf.memsz = initrd_len;
kbuf.buf_align = PAGE_SIZE;
kbuf.top_down = false;
ret = kexec_add_buffer(&kbuf);
if (ret)
goto out;
initrd_load_addr = kbuf.mem;
pr_debug("Loaded initrd at 0x%lx\n", initrd_load_addr);
}
fdt_size = fdt_totalsize(initial_boot_params) * 2;
fdt = kmalloc(fdt_size, GFP_KERNEL);
if (!fdt) {
pr_err("Not enough memory for the device tree.\n");
ret = -ENOMEM;
goto out;
}
ret = fdt_open_into(initial_boot_params, fdt, fdt_size);
if (ret < 0) {
pr_err("Error setting up the new device tree.\n");
ret = -EINVAL;
goto out;
}
ret = setup_new_fdt(image, fdt, initrd_load_addr, initrd_len, cmdline);
if (ret)
goto out;
fdt_pack(fdt);
kbuf.buffer = fdt;
kbuf.bufsz = kbuf.memsz = fdt_size;
kbuf.buf_align = PAGE_SIZE;
kbuf.top_down = true;
ret = kexec_add_buffer(&kbuf);
if (ret)
goto out;
fdt_load_addr = kbuf.mem;
pr_debug("Loaded device tree at 0x%lx\n", fdt_load_addr);
slave_code = elf_info.buffer + elf_info.proghdrs[0].p_offset;
ret = setup_purgatory(image, slave_code, fdt, kernel_load_addr,
fdt_load_addr);
if (ret)
pr_err("Error setting up the purgatory.\n");
out:
elf_free_info(&elf_info);
return ret ? ERR_PTR(ret) : fdt;
}
