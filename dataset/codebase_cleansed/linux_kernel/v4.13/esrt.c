static struct esre_entry *to_entry(struct kobject *kobj)
{
return container_of(kobj, struct esre_entry, kobj);
}
static struct esre_attribute *to_attr(struct attribute *attr)
{
return container_of(attr, struct esre_attribute, attr);
}
static ssize_t esre_attr_show(struct kobject *kobj,
struct attribute *_attr, char *buf)
{
struct esre_entry *entry = to_entry(kobj);
struct esre_attribute *attr = to_attr(_attr);
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
return attr->show(entry, buf);
}
static ssize_t esre_fw_class_show(struct esre_entry *entry, char *buf)
{
char *str = buf;
efi_guid_to_str(&entry->esre.esre1->fw_class, str);
str += strlen(str);
str += sprintf(str, "\n");
return str - buf;
}
static void esre_release(struct kobject *kobj)
{
struct esre_entry *entry = to_entry(kobj);
list_del(&entry->list);
kfree(entry);
}
static int esre_create_sysfs_entry(void *esre, int entry_num)
{
struct esre_entry *entry;
entry = kzalloc(sizeof(*entry), GFP_KERNEL);
if (!entry)
return -ENOMEM;
entry->kobj.kset = esrt_kset;
if (esrt->fw_resource_version == 1) {
int rc = 0;
entry->esre.esre1 = esre;
rc = kobject_init_and_add(&entry->kobj, &esre1_ktype, NULL,
"entry%d", entry_num);
if (rc) {
kfree(entry);
return rc;
}
}
list_add_tail(&entry->list, &entry_list);
return 0;
}
static inline int esrt_table_exists(void)
{
if (!efi_enabled(EFI_CONFIG_TABLES))
return 0;
if (efi.esrt == EFI_INVALID_TABLE_ADDR)
return 0;
return 1;
}
static umode_t esrt_attr_is_visible(struct kobject *kobj,
struct attribute *attr, int n)
{
if (!esrt_table_exists())
return 0;
return attr->mode;
}
void __init efi_esrt_init(void)
{
void *va;
struct efi_system_resource_table tmpesrt;
struct efi_system_resource_entry_v1 *v1_entries;
size_t size, max, entry_size, entries_size;
efi_memory_desc_t md;
int rc;
phys_addr_t end;
pr_debug("esrt-init: loading.\n");
if (!esrt_table_exists())
return;
rc = efi_mem_desc_lookup(efi.esrt, &md);
if (rc < 0) {
pr_warn("ESRT header is not in the memory map.\n");
return;
}
max = efi_mem_desc_end(&md);
if (max < efi.esrt) {
pr_err("EFI memory descriptor is invalid. (esrt: %p max: %p)\n",
(void *)efi.esrt, (void *)max);
return;
}
size = sizeof(*esrt);
max -= efi.esrt;
if (max < size) {
pr_err("ESRT header doesn't fit on single memory map entry. (size: %zu max: %zu)\n",
size, max);
return;
}
va = early_memremap(efi.esrt, size);
if (!va) {
pr_err("early_memremap(%p, %zu) failed.\n", (void *)efi.esrt,
size);
return;
}
memcpy(&tmpesrt, va, sizeof(tmpesrt));
if (tmpesrt.fw_resource_version == 1) {
entry_size = sizeof (*v1_entries);
} else {
pr_err("Unsupported ESRT version %lld.\n",
tmpesrt.fw_resource_version);
return;
}
if (tmpesrt.fw_resource_count > 0 && max - size < entry_size) {
pr_err("ESRT memory map entry can only hold the header. (max: %zu size: %zu)\n",
max - size, entry_size);
goto err_memunmap;
}
if (tmpesrt.fw_resource_count > 128) {
pr_err("ESRT says fw_resource_count has very large value %d.\n",
tmpesrt.fw_resource_count);
goto err_memunmap;
}
entries_size = tmpesrt.fw_resource_count * entry_size;
if (max < size + entries_size) {
pr_err("ESRT does not fit on single memory map entry (size: %zu max: %zu)\n",
size, max);
goto err_memunmap;
}
early_memunmap(va, size);
size += entries_size;
va = early_memremap(efi.esrt, size);
if (!va) {
pr_err("early_memremap(%p, %zu) failed.\n", (void *)efi.esrt,
size);
return;
}
esrt_data = (phys_addr_t)efi.esrt;
esrt_data_size = size;
end = esrt_data + size;
pr_info("Reserving ESRT space from %pa to %pa.\n", &esrt_data, &end);
efi_mem_reserve(esrt_data, esrt_data_size);
pr_debug("esrt-init: loaded.\n");
err_memunmap:
early_memunmap(va, size);
}
static int __init register_entries(void)
{
struct efi_system_resource_entry_v1 *v1_entries = (void *)esrt->entries;
int i, rc;
if (!esrt_table_exists())
return 0;
for (i = 0; i < le32_to_cpu(esrt->fw_resource_count); i++) {
void *esre = NULL;
if (esrt->fw_resource_version == 1) {
esre = &v1_entries[i];
} else {
pr_err("Unsupported ESRT version %lld.\n",
esrt->fw_resource_version);
return -EINVAL;
}
rc = esre_create_sysfs_entry(esre, i);
if (rc < 0) {
pr_err("ESRT entry creation failed with error %d.\n",
rc);
return rc;
}
}
return 0;
}
static void cleanup_entry_list(void)
{
struct esre_entry *entry, *next;
list_for_each_entry_safe(entry, next, &entry_list, list) {
kobject_put(&entry->kobj);
}
}
static int __init esrt_sysfs_init(void)
{
int error;
pr_debug("esrt-sysfs: loading.\n");
if (!esrt_data || !esrt_data_size)
return -ENOSYS;
esrt = memremap(esrt_data, esrt_data_size, MEMREMAP_WB);
if (!esrt) {
pr_err("memremap(%pa, %zu) failed.\n", &esrt_data,
esrt_data_size);
return -ENOMEM;
}
esrt_kobj = kobject_create_and_add("esrt", efi_kobj);
if (!esrt_kobj) {
pr_err("Firmware table registration failed.\n");
error = -ENOMEM;
goto err;
}
error = sysfs_create_group(esrt_kobj, &esrt_attr_group);
if (error) {
pr_err("Sysfs attribute export failed with error %d.\n",
error);
goto err_remove_esrt;
}
esrt_kset = kset_create_and_add("entries", NULL, esrt_kobj);
if (!esrt_kset) {
pr_err("kset creation failed.\n");
error = -ENOMEM;
goto err_remove_group;
}
error = register_entries();
if (error)
goto err_cleanup_list;
pr_debug("esrt-sysfs: loaded.\n");
return 0;
err_cleanup_list:
cleanup_entry_list();
kset_unregister(esrt_kset);
err_remove_group:
sysfs_remove_group(esrt_kobj, &esrt_attr_group);
err_remove_esrt:
kobject_put(esrt_kobj);
err:
kfree(esrt);
esrt = NULL;
return error;
}
