static
u32 rproc_elf_get_boot_addr(struct rproc *rproc, const struct firmware *fw)
{
struct elf32_hdr *ehdr = (struct elf32_hdr *)fw->data;
return ehdr->e_entry;
}
static int
rproc_elf_load_segments(struct rproc *rproc, const struct firmware *fw)
{
struct device *dev = &rproc->dev;
struct elf32_hdr *ehdr;
struct elf32_phdr *phdr;
int i, ret = 0;
const u8 *elf_data = fw->data;
ehdr = (struct elf32_hdr *)elf_data;
phdr = (struct elf32_phdr *)(elf_data + ehdr->e_phoff);
for (i = 0; i < ehdr->e_phnum; i++, phdr++) {
u32 da = phdr->p_paddr;
u32 memsz = phdr->p_memsz;
u32 filesz = phdr->p_filesz;
u32 offset = phdr->p_offset;
void *ptr;
if (phdr->p_type != PT_LOAD)
continue;
dev_dbg(dev, "phdr: type %d da 0x%x memsz 0x%x filesz 0x%x\n",
phdr->p_type, da, memsz, filesz);
if (filesz > memsz) {
dev_err(dev, "bad phdr filesz 0x%x memsz 0x%x\n",
filesz, memsz);
ret = -EINVAL;
break;
}
if (offset + filesz > fw->size) {
dev_err(dev, "truncated fw: need 0x%x avail 0x%zx\n",
offset + filesz, fw->size);
ret = -EINVAL;
break;
}
ptr = rproc_da_to_va(rproc, da, memsz);
if (!ptr) {
dev_err(dev, "bad phdr da 0x%x mem 0x%x\n", da, memsz);
ret = -EINVAL;
break;
}
if (phdr->p_filesz)
memcpy(ptr, elf_data + phdr->p_offset, filesz);
if (memsz > filesz)
memset(ptr + filesz, 0, memsz - filesz);
}
return ret;
}
static struct elf32_shdr *
find_table(struct device *dev, struct elf32_hdr *ehdr, size_t fw_size)
{
struct elf32_shdr *shdr;
int i;
const char *name_table;
struct resource_table *table = NULL;
const u8 *elf_data = (void *)ehdr;
shdr = (struct elf32_shdr *)(elf_data + ehdr->e_shoff);
name_table = elf_data + shdr[ehdr->e_shstrndx].sh_offset;
for (i = 0; i < ehdr->e_shnum; i++, shdr++) {
u32 size = shdr->sh_size;
u32 offset = shdr->sh_offset;
if (strcmp(name_table + shdr->sh_name, ".resource_table"))
continue;
table = (struct resource_table *)(elf_data + offset);
if (offset + size > fw_size || offset + size < size) {
dev_err(dev, "resource table truncated\n");
return NULL;
}
if (sizeof(struct resource_table) > size) {
dev_err(dev, "header-less resource table\n");
return NULL;
}
if (table->ver != 1) {
dev_err(dev, "unsupported fw ver: %d\n", table->ver);
return NULL;
}
if (table->reserved[0] || table->reserved[1]) {
dev_err(dev, "non zero reserved bytes\n");
return NULL;
}
if (table->num * sizeof(table->offset[0]) +
sizeof(struct resource_table) > size) {
dev_err(dev, "resource table incomplete\n");
return NULL;
}
return shdr;
}
return NULL;
}
static struct resource_table *
rproc_elf_find_rsc_table(struct rproc *rproc, const struct firmware *fw,
int *tablesz)
{
struct elf32_hdr *ehdr;
struct elf32_shdr *shdr;
struct device *dev = &rproc->dev;
struct resource_table *table = NULL;
const u8 *elf_data = fw->data;
ehdr = (struct elf32_hdr *)elf_data;
shdr = find_table(dev, ehdr, fw->size);
if (!shdr)
return NULL;
table = (struct resource_table *)(elf_data + shdr->sh_offset);
*tablesz = shdr->sh_size;
return table;
}
static struct resource_table *
rproc_elf_find_loaded_rsc_table(struct rproc *rproc, const struct firmware *fw)
{
struct elf32_hdr *ehdr = (struct elf32_hdr *)fw->data;
struct elf32_shdr *shdr;
shdr = find_table(&rproc->dev, ehdr, fw->size);
if (!shdr)
return NULL;
return rproc_da_to_va(rproc, shdr->sh_addr, shdr->sh_size);
}
