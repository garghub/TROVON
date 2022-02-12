static bool mdt_phdr_valid(const struct elf32_phdr *phdr)
{
if (phdr->p_type != PT_LOAD)
return false;
if ((phdr->p_flags & QCOM_MDT_TYPE_MASK) == QCOM_MDT_TYPE_HASH)
return false;
if (!phdr->p_memsz)
return false;
return true;
}
ssize_t qcom_mdt_get_size(const struct firmware *fw)
{
const struct elf32_phdr *phdrs;
const struct elf32_phdr *phdr;
const struct elf32_hdr *ehdr;
phys_addr_t min_addr = (phys_addr_t)ULLONG_MAX;
phys_addr_t max_addr = 0;
int i;
ehdr = (struct elf32_hdr *)fw->data;
phdrs = (struct elf32_phdr *)(ehdr + 1);
for (i = 0; i < ehdr->e_phnum; i++) {
phdr = &phdrs[i];
if (!mdt_phdr_valid(phdr))
continue;
if (phdr->p_paddr < min_addr)
min_addr = phdr->p_paddr;
if (phdr->p_paddr + phdr->p_memsz > max_addr)
max_addr = ALIGN(phdr->p_paddr + phdr->p_memsz, SZ_4K);
}
return min_addr < max_addr ? max_addr - min_addr : -EINVAL;
}
int qcom_mdt_load(struct device *dev, const struct firmware *fw,
const char *firmware, int pas_id, void *mem_region,
phys_addr_t mem_phys, size_t mem_size)
{
const struct elf32_phdr *phdrs;
const struct elf32_phdr *phdr;
const struct elf32_hdr *ehdr;
const struct firmware *seg_fw;
phys_addr_t mem_reloc;
phys_addr_t min_addr = (phys_addr_t)ULLONG_MAX;
phys_addr_t max_addr = 0;
size_t fw_name_len;
ssize_t offset;
char *fw_name;
bool relocate = false;
void *ptr;
int ret;
int i;
if (!fw || !mem_region || !mem_phys || !mem_size)
return -EINVAL;
ehdr = (struct elf32_hdr *)fw->data;
phdrs = (struct elf32_phdr *)(ehdr + 1);
fw_name_len = strlen(firmware);
if (fw_name_len <= 4)
return -EINVAL;
fw_name = kstrdup(firmware, GFP_KERNEL);
if (!fw_name)
return -ENOMEM;
ret = qcom_scm_pas_init_image(pas_id, fw->data, fw->size);
if (ret) {
dev_err(dev, "invalid firmware metadata\n");
goto out;
}
for (i = 0; i < ehdr->e_phnum; i++) {
phdr = &phdrs[i];
if (!mdt_phdr_valid(phdr))
continue;
if (phdr->p_flags & QCOM_MDT_RELOCATABLE)
relocate = true;
if (phdr->p_paddr < min_addr)
min_addr = phdr->p_paddr;
if (phdr->p_paddr + phdr->p_memsz > max_addr)
max_addr = ALIGN(phdr->p_paddr + phdr->p_memsz, SZ_4K);
}
if (relocate) {
ret = qcom_scm_pas_mem_setup(pas_id, mem_phys, max_addr - min_addr);
if (ret) {
dev_err(dev, "unable to setup relocation\n");
goto out;
}
mem_reloc = min_addr;
} else {
mem_reloc = mem_phys;
}
for (i = 0; i < ehdr->e_phnum; i++) {
phdr = &phdrs[i];
if (!mdt_phdr_valid(phdr))
continue;
offset = phdr->p_paddr - mem_reloc;
if (offset < 0 || offset + phdr->p_memsz > mem_size) {
dev_err(dev, "segment outside memory range\n");
ret = -EINVAL;
break;
}
ptr = mem_region + offset;
if (phdr->p_filesz) {
sprintf(fw_name + fw_name_len - 3, "b%02d", i);
ret = request_firmware(&seg_fw, fw_name, dev);
if (ret) {
dev_err(dev, "failed to load %s\n", fw_name);
break;
}
memcpy(ptr, seg_fw->data, seg_fw->size);
release_firmware(seg_fw);
}
if (phdr->p_memsz > phdr->p_filesz)
memset(ptr + phdr->p_filesz, 0, phdr->p_memsz - phdr->p_filesz);
}
out:
kfree(fw_name);
return ret;
}
