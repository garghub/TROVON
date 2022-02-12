static inline struct map_attribute *to_map_attr(struct attribute *attr)
{
return container_of(attr, struct map_attribute, attr);
}
static ssize_t type_show(struct efi_runtime_map_entry *entry, char *buf)
{
return snprintf(buf, PAGE_SIZE, "0x%x\n", entry->md.type);
}
static inline struct efi_runtime_map_entry *to_map_entry(struct kobject *kobj)
{
return container_of(kobj, struct efi_runtime_map_entry, kobj);
}
static ssize_t map_attr_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct efi_runtime_map_entry *entry = to_map_entry(kobj);
struct map_attribute *map_attr = to_map_attr(attr);
return map_attr->show(entry, buf);
}
static void map_release(struct kobject *kobj)
{
struct efi_runtime_map_entry *entry;
entry = to_map_entry(kobj);
kfree(entry);
}
static struct efi_runtime_map_entry *
add_sysfs_runtime_map_entry(struct kobject *kobj, int nr)
{
int ret;
struct efi_runtime_map_entry *entry;
if (!map_kset) {
map_kset = kset_create_and_add("runtime-map", NULL, kobj);
if (!map_kset)
return ERR_PTR(-ENOMEM);
}
entry = kzalloc(sizeof(*entry), GFP_KERNEL);
if (!entry) {
kset_unregister(map_kset);
return entry;
}
memcpy(&entry->md, efi_runtime_map + nr * efi_memdesc_size,
sizeof(efi_memory_desc_t));
kobject_init(&entry->kobj, &map_ktype);
entry->kobj.kset = map_kset;
ret = kobject_add(&entry->kobj, NULL, "%d", nr);
if (ret) {
kobject_put(&entry->kobj);
kset_unregister(map_kset);
return ERR_PTR(ret);
}
return entry;
}
int efi_get_runtime_map_size(void)
{
return nr_efi_runtime_map * efi_memdesc_size;
}
int efi_get_runtime_map_desc_size(void)
{
return efi_memdesc_size;
}
int efi_runtime_map_copy(void *buf, size_t bufsz)
{
size_t sz = efi_get_runtime_map_size();
if (sz > bufsz)
sz = bufsz;
memcpy(buf, efi_runtime_map, sz);
return 0;
}
void efi_runtime_map_setup(void *map, int nr_entries, u32 desc_size)
{
efi_runtime_map = map;
nr_efi_runtime_map = nr_entries;
efi_memdesc_size = desc_size;
}
int __init efi_runtime_map_init(struct kobject *efi_kobj)
{
int i, j, ret = 0;
struct efi_runtime_map_entry *entry;
if (!efi_runtime_map)
return 0;
map_entries = kzalloc(nr_efi_runtime_map * sizeof(entry), GFP_KERNEL);
if (!map_entries) {
ret = -ENOMEM;
goto out;
}
for (i = 0; i < nr_efi_runtime_map; i++) {
entry = add_sysfs_runtime_map_entry(efi_kobj, i);
if (IS_ERR(entry)) {
ret = PTR_ERR(entry);
goto out_add_entry;
}
*(map_entries + i) = entry;
}
return 0;
out_add_entry:
for (j = i - 1; j > 0; j--) {
entry = *(map_entries + j);
kobject_put(&entry->kobj);
}
if (map_kset)
kset_unregister(map_kset);
out:
return ret;
}
