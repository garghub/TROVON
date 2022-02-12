static int firmware_map_add_entry(u64 start, u64 end,
const char *type,
struct firmware_map_entry *entry)
{
BUG_ON(start > end);
entry->start = start;
entry->end = end;
entry->type = type;
INIT_LIST_HEAD(&entry->list);
kobject_init(&entry->kobj, &memmap_ktype);
list_add_tail(&entry->list, &map_entries);
return 0;
}
static int add_sysfs_fw_map_entry(struct firmware_map_entry *entry)
{
static int map_entries_nr;
static struct kset *mmap_kset;
if (!mmap_kset) {
mmap_kset = kset_create_and_add("memmap", NULL, firmware_kobj);
if (!mmap_kset)
return -ENOMEM;
}
entry->kobj.kset = mmap_kset;
if (kobject_add(&entry->kobj, NULL, "%d", map_entries_nr++))
kobject_put(&entry->kobj);
return 0;
}
int __meminit firmware_map_add_hotplug(u64 start, u64 end, const char *type)
{
struct firmware_map_entry *entry;
entry = kzalloc(sizeof(struct firmware_map_entry), GFP_ATOMIC);
if (!entry)
return -ENOMEM;
firmware_map_add_entry(start, end, type, entry);
add_sysfs_fw_map_entry(entry);
return 0;
}
int __init firmware_map_add_early(u64 start, u64 end, const char *type)
{
struct firmware_map_entry *entry;
entry = alloc_bootmem(sizeof(struct firmware_map_entry));
if (WARN_ON(!entry))
return -ENOMEM;
return firmware_map_add_entry(start, end, type, entry);
}
static ssize_t start_show(struct firmware_map_entry *entry, char *buf)
{
return snprintf(buf, PAGE_SIZE, "0x%llx\n",
(unsigned long long)entry->start);
}
static ssize_t end_show(struct firmware_map_entry *entry, char *buf)
{
return snprintf(buf, PAGE_SIZE, "0x%llx\n",
(unsigned long long)entry->end);
}
static ssize_t type_show(struct firmware_map_entry *entry, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n", entry->type);
}
static ssize_t memmap_attr_show(struct kobject *kobj,
struct attribute *attr, char *buf)
{
struct firmware_map_entry *entry = to_memmap_entry(kobj);
struct memmap_attribute *memmap_attr = to_memmap_attr(attr);
return memmap_attr->show(entry, buf);
}
static int __init memmap_init(void)
{
struct firmware_map_entry *entry;
list_for_each_entry(entry, &map_entries, list)
add_sysfs_fw_map_entry(entry);
return 0;
}
