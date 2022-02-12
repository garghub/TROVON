static inline struct sfi_table_header *acpi_to_sfi_th(
struct acpi_table_header *th)
{
return (struct sfi_table_header *)th;
}
static inline struct acpi_table_header *sfi_to_acpi_th(
struct sfi_table_header *th)
{
return (struct acpi_table_header *)th;
}
static int __init sfi_acpi_parse_xsdt(struct sfi_table_header *th)
{
struct sfi_table_key key = SFI_ANY_KEY;
int tbl_cnt, i;
void *ret;
xsdt_va = (struct acpi_table_xsdt *)th;
tbl_cnt = XSDT_GET_NUM_ENTRIES(xsdt_va, u64);
for (i = 0; i < tbl_cnt; i++) {
ret = sfi_check_table(xsdt_va->table_offset_entry[i], &key);
if (IS_ERR(ret)) {
disable_sfi();
return -1;
}
}
return 0;
}
int __init sfi_acpi_init(void)
{
struct sfi_table_key xsdt_key = { .sig = SFI_SIG_XSDT };
sfi_table_parse(SFI_SIG_XSDT, NULL, NULL, sfi_acpi_parse_xsdt);
xsdt_va = (struct acpi_table_xsdt *)sfi_get_table(&xsdt_key);
return 0;
}
static struct acpi_table_header *sfi_acpi_get_table(struct sfi_table_key *key)
{
u32 tbl_cnt, i;
void *ret;
tbl_cnt = XSDT_GET_NUM_ENTRIES(xsdt_va, u64);
for (i = 0; i < tbl_cnt; i++) {
ret = sfi_check_table(xsdt_va->table_offset_entry[i], key);
if (!IS_ERR(ret) && ret)
return sfi_to_acpi_th(ret);
}
return NULL;
}
static void sfi_acpi_put_table(struct acpi_table_header *table)
{
sfi_put_table(acpi_to_sfi_th(table));
}
int sfi_acpi_table_parse(char *signature, char *oem_id, char *oem_table_id,
int(*handler)(struct acpi_table_header *))
{
struct acpi_table_header *table = NULL;
struct sfi_table_key key;
int ret = 0;
if (sfi_disabled)
return -1;
key.sig = signature;
key.oem_id = oem_id;
key.oem_table_id = oem_table_id;
table = sfi_acpi_get_table(&key);
if (!table)
return -EINVAL;
ret = handler(table);
sfi_acpi_put_table(table);
return ret;
}
static ssize_t sfi_acpi_table_show(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t offset, size_t count)
{
struct sfi_table_attr *tbl_attr =
container_of(bin_attr, struct sfi_table_attr, attr);
struct acpi_table_header *th = NULL;
struct sfi_table_key key;
ssize_t cnt;
key.sig = tbl_attr->name;
key.oem_id = NULL;
key.oem_table_id = NULL;
th = sfi_acpi_get_table(&key);
if (!th)
return 0;
cnt = memory_read_from_buffer(buf, count, &offset,
th, th->length);
sfi_acpi_put_table(th);
return cnt;
}
void __init sfi_acpi_sysfs_init(void)
{
u32 tbl_cnt, i;
struct sfi_table_attr *tbl_attr;
tbl_cnt = XSDT_GET_NUM_ENTRIES(xsdt_va, u64);
for (i = 0; i < tbl_cnt; i++) {
tbl_attr =
sfi_sysfs_install_table(xsdt_va->table_offset_entry[i]);
tbl_attr->attr.read = sfi_acpi_table_show;
}
return;
}
