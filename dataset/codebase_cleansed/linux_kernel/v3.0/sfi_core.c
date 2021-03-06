static void __iomem * __ref sfi_map_memory(u64 phys, u32 size)
{
if (!phys || !size)
return NULL;
if (sfi_use_ioremap)
return ioremap_cache(phys, size);
else
return early_ioremap(phys, size);
}
static void __ref sfi_unmap_memory(void __iomem *virt, u32 size)
{
if (!virt || !size)
return;
if (sfi_use_ioremap)
iounmap(virt);
else
early_iounmap(virt, size);
}
static void sfi_print_table_header(unsigned long long pa,
struct sfi_table_header *header)
{
pr_info("%4.4s %llX, %04X (v%d %6.6s %8.8s)\n",
header->sig, pa,
header->len, header->rev, header->oem_id,
header->oem_table_id);
}
static int sfi_verify_table(struct sfi_table_header *table)
{
u8 checksum = 0;
u8 *puchar = (u8 *)table;
u32 length = table->len;
if (length > 0x100000) {
pr_err("Invalid table length 0x%x\n", length);
return -1;
}
while (length--)
checksum += *puchar++;
if (checksum) {
pr_err("Checksum %2.2X should be %2.2X\n",
table->csum, table->csum - checksum);
return -1;
}
return 0;
}
struct sfi_table_header *sfi_map_table(u64 pa)
{
struct sfi_table_header *th;
u32 length;
if (!TABLE_ON_PAGE(syst_pa, pa, sizeof(struct sfi_table_header)))
th = sfi_map_memory(pa, sizeof(struct sfi_table_header));
else
th = (void *)syst_va + (pa - syst_pa);
if (TABLE_ON_PAGE(th, th, th->len))
return th;
length = th->len;
if (!TABLE_ON_PAGE(syst_pa, pa, sizeof(struct sfi_table_header)))
sfi_unmap_memory(th, sizeof(struct sfi_table_header));
return sfi_map_memory(pa, length);
}
void sfi_unmap_table(struct sfi_table_header *th)
{
if (!TABLE_ON_PAGE(syst_va, th, th->len))
sfi_unmap_memory(th, TABLE_ON_PAGE(th, th, th->len) ?
sizeof(*th) : th->len);
}
static int sfi_table_check_key(struct sfi_table_header *th,
struct sfi_table_key *key)
{
if (strncmp(th->sig, key->sig, SFI_SIGNATURE_SIZE)
|| (key->oem_id && strncmp(th->oem_id,
key->oem_id, SFI_OEM_ID_SIZE))
|| (key->oem_table_id && strncmp(th->oem_table_id,
key->oem_table_id, SFI_OEM_TABLE_ID_SIZE)))
return -1;
return 0;
}
struct sfi_table_header *
__ref sfi_check_table(u64 pa, struct sfi_table_key *key)
{
struct sfi_table_header *th;
void *ret = NULL;
th = sfi_map_table(pa);
if (!th)
return ERR_PTR(-ENOMEM);
if (!key->sig) {
sfi_print_table_header(pa, th);
if (sfi_verify_table(th))
ret = ERR_PTR(-EINVAL);
} else {
if (!sfi_table_check_key(th, key))
return th;
}
sfi_unmap_table(th);
return ret;
}
struct sfi_table_header *sfi_get_table(struct sfi_table_key *key)
{
struct sfi_table_header *th;
u32 tbl_cnt, i;
tbl_cnt = SFI_GET_NUM_ENTRIES(syst_va, u64);
for (i = 0; i < tbl_cnt; i++) {
th = sfi_check_table(syst_va->pentry[i], key);
if (!IS_ERR(th) && th)
return th;
}
return NULL;
}
void sfi_put_table(struct sfi_table_header *th)
{
sfi_unmap_table(th);
}
int sfi_table_parse(char *signature, char *oem_id, char *oem_table_id,
sfi_table_handler handler)
{
struct sfi_table_header *table = NULL;
struct sfi_table_key key;
int ret = -EINVAL;
if (sfi_disabled || !handler || !signature)
goto exit;
key.sig = signature;
key.oem_id = oem_id;
key.oem_table_id = oem_table_id;
table = sfi_get_table(&key);
if (!table)
goto exit;
ret = handler(table);
sfi_put_table(table);
exit:
return ret;
}
static int __init sfi_parse_syst(void)
{
struct sfi_table_key key = SFI_ANY_KEY;
int tbl_cnt, i;
void *ret;
syst_va = sfi_map_memory(syst_pa, sizeof(struct sfi_table_simple));
if (!syst_va)
return -ENOMEM;
tbl_cnt = SFI_GET_NUM_ENTRIES(syst_va, u64);
for (i = 0; i < tbl_cnt; i++) {
ret = sfi_check_table(syst_va->pentry[i], &key);
if (IS_ERR(ret))
return PTR_ERR(ret);
}
return 0;
}
static __init int sfi_find_syst(void)
{
unsigned long offset, len;
void *start;
len = SFI_SYST_SEARCH_END - SFI_SYST_SEARCH_BEGIN;
start = sfi_map_memory(SFI_SYST_SEARCH_BEGIN, len);
if (!start)
return -1;
for (offset = 0; offset < len; offset += 16) {
struct sfi_table_header *syst_hdr;
syst_hdr = start + offset;
if (strncmp(syst_hdr->sig, SFI_SIG_SYST,
SFI_SIGNATURE_SIZE))
continue;
if (syst_hdr->len > PAGE_SIZE)
continue;
sfi_print_table_header(SFI_SYST_SEARCH_BEGIN + offset,
syst_hdr);
if (sfi_verify_table(syst_hdr))
continue;
if (!ON_SAME_PAGE(syst_pa, syst_pa + syst_hdr->len)) {
pr_info("SYST 0x%llx + 0x%x crosses page\n",
syst_pa, syst_hdr->len);
continue;
}
syst_pa = SFI_SYST_SEARCH_BEGIN + offset;
sfi_unmap_memory(start, len);
return 0;
}
sfi_unmap_memory(start, len);
return -1;
}
static ssize_t sfi_table_show(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t offset, size_t count)
{
struct sfi_table_attr *tbl_attr =
container_of(bin_attr, struct sfi_table_attr, attr);
struct sfi_table_header *th = NULL;
struct sfi_table_key key;
ssize_t cnt;
key.sig = tbl_attr->name;
key.oem_id = NULL;
key.oem_table_id = NULL;
if (strncmp(SFI_SIG_SYST, tbl_attr->name, SFI_SIGNATURE_SIZE)) {
th = sfi_get_table(&key);
if (!th)
return 0;
cnt = memory_read_from_buffer(buf, count, &offset,
th, th->len);
sfi_put_table(th);
} else
cnt = memory_read_from_buffer(buf, count, &offset,
syst_va, syst_va->header.len);
return cnt;
}
struct sfi_table_attr __init *sfi_sysfs_install_table(u64 pa)
{
struct sfi_table_attr *tbl_attr;
struct sfi_table_header *th;
int ret;
tbl_attr = kzalloc(sizeof(struct sfi_table_attr), GFP_KERNEL);
if (!tbl_attr)
return NULL;
th = sfi_map_table(pa);
if (!th || !th->sig[0]) {
kfree(tbl_attr);
return NULL;
}
sysfs_attr_init(&tbl_attr->attr.attr);
memcpy(tbl_attr->name, th->sig, SFI_SIGNATURE_SIZE);
tbl_attr->attr.size = 0;
tbl_attr->attr.read = sfi_table_show;
tbl_attr->attr.attr.name = tbl_attr->name;
tbl_attr->attr.attr.mode = 0400;
ret = sysfs_create_bin_file(tables_kobj,
&tbl_attr->attr);
if (ret) {
kfree(tbl_attr);
tbl_attr = NULL;
}
sfi_unmap_table(th);
return tbl_attr;
}
static int __init sfi_sysfs_init(void)
{
int tbl_cnt, i;
if (sfi_disabled)
return 0;
sfi_kobj = kobject_create_and_add("sfi", firmware_kobj);
if (!sfi_kobj)
return 0;
tables_kobj = kobject_create_and_add("tables", sfi_kobj);
if (!tables_kobj) {
kobject_put(sfi_kobj);
return 0;
}
sfi_sysfs_install_table(syst_pa);
tbl_cnt = SFI_GET_NUM_ENTRIES(syst_va, u64);
for (i = 0; i < tbl_cnt; i++)
sfi_sysfs_install_table(syst_va->pentry[i]);
sfi_acpi_sysfs_init();
kobject_uevent(sfi_kobj, KOBJ_ADD);
kobject_uevent(tables_kobj, KOBJ_ADD);
pr_info("SFI sysfs interfaces init success\n");
return 0;
}
void __init sfi_init(void)
{
if (!acpi_disabled)
disable_sfi();
if (sfi_disabled)
return;
pr_info("Simple Firmware Interface v0.81 http://simplefirmware.org\n");
if (sfi_find_syst() || sfi_parse_syst() || sfi_platform_init())
disable_sfi();
return;
}
void __init sfi_init_late(void)
{
int length;
if (sfi_disabled)
return;
length = syst_va->header.len;
sfi_unmap_memory(syst_va, sizeof(struct sfi_table_simple));
sfi_use_ioremap = 1;
syst_va = sfi_map_memory(syst_pa, length);
sfi_acpi_init();
}
