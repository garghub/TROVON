static int efi_pstore_open(struct pstore_info *psi)
{
psi->data = NULL;
return 0;
}
static int efi_pstore_close(struct pstore_info *psi)
{
psi->data = NULL;
return 0;
}
static inline u64 generic_id(unsigned long timestamp,
unsigned int part, int count)
{
return ((u64) timestamp * 100 + part) * 1000 + count;
}
static int efi_pstore_read_func(struct efivar_entry *entry,
struct pstore_record *record)
{
efi_guid_t vendor = LINUX_EFI_CRASH_GUID;
char name[DUMP_NAME_LEN], data_type;
int i;
int cnt;
unsigned int part;
unsigned long time, size;
if (efi_guidcmp(entry->var.VendorGuid, vendor))
return 0;
for (i = 0; i < DUMP_NAME_LEN; i++)
name[i] = entry->var.VariableName[i];
if (sscanf(name, "dump-type%u-%u-%d-%lu-%c",
&record->type, &part, &cnt, &time, &data_type) == 5) {
record->id = generic_id(time, part, cnt);
record->part = part;
record->count = cnt;
record->time.tv_sec = time;
record->time.tv_nsec = 0;
if (data_type == 'C')
record->compressed = true;
else
record->compressed = false;
record->ecc_notice_size = 0;
} else if (sscanf(name, "dump-type%u-%u-%d-%lu",
&record->type, &part, &cnt, &time) == 4) {
record->id = generic_id(time, part, cnt);
record->part = part;
record->count = cnt;
record->time.tv_sec = time;
record->time.tv_nsec = 0;
record->compressed = false;
record->ecc_notice_size = 0;
} else if (sscanf(name, "dump-type%u-%u-%lu",
&record->type, &part, &time) == 3) {
record->id = generic_id(time, part, 0);
record->part = part;
record->count = 0;
record->time.tv_sec = time;
record->time.tv_nsec = 0;
record->compressed = false;
record->ecc_notice_size = 0;
} else
return 0;
entry->var.DataSize = 1024;
__efivar_entry_get(entry, &entry->var.Attributes,
&entry->var.DataSize, entry->var.Data);
size = entry->var.DataSize;
memcpy(record->buf, entry->var.Data,
(size_t)min_t(unsigned long, EFIVARS_DATA_SIZE_MAX, size));
return size;
}
static void efi_pstore_scan_sysfs_enter(struct efivar_entry *pos,
struct efivar_entry *next,
struct list_head *head)
{
pos->scanning = true;
if (&next->list != head)
next->scanning = true;
}
static inline int __efi_pstore_scan_sysfs_exit(struct efivar_entry *entry,
bool turn_off_scanning)
{
if (entry->deleting) {
list_del(&entry->list);
efivar_entry_iter_end();
efivar_unregister(entry);
if (efivar_entry_iter_begin())
return -EINTR;
} else if (turn_off_scanning)
entry->scanning = false;
return 0;
}
static int efi_pstore_scan_sysfs_exit(struct efivar_entry *pos,
struct efivar_entry *next,
struct list_head *head, bool stop)
{
int ret = __efi_pstore_scan_sysfs_exit(pos, true);
if (ret)
return ret;
if (stop)
ret = __efi_pstore_scan_sysfs_exit(next, &next->list != head);
return ret;
}
static int efi_pstore_sysfs_entry_iter(struct pstore_record *record)
{
struct efivar_entry **pos = (struct efivar_entry **)&record->psi->data;
struct efivar_entry *entry, *n;
struct list_head *head = &efivar_sysfs_list;
int size = 0;
int ret;
if (!*pos) {
list_for_each_entry_safe(entry, n, head, list) {
efi_pstore_scan_sysfs_enter(entry, n, head);
size = efi_pstore_read_func(entry, record);
ret = efi_pstore_scan_sysfs_exit(entry, n, head,
size < 0);
if (ret)
return ret;
if (size)
break;
}
*pos = n;
return size;
}
list_for_each_entry_safe_from((*pos), n, head, list) {
efi_pstore_scan_sysfs_enter((*pos), n, head);
size = efi_pstore_read_func((*pos), record);
ret = efi_pstore_scan_sysfs_exit((*pos), n, head, size < 0);
if (ret)
return ret;
if (size)
break;
}
*pos = n;
return size;
}
static ssize_t efi_pstore_read(struct pstore_record *record)
{
ssize_t size;
record->buf = kzalloc(EFIVARS_DATA_SIZE_MAX, GFP_KERNEL);
if (!record->buf)
return -ENOMEM;
if (efivar_entry_iter_begin()) {
size = -EINTR;
goto out;
}
size = efi_pstore_sysfs_entry_iter(record);
efivar_entry_iter_end();
out:
if (size <= 0) {
kfree(record->buf);
record->buf = NULL;
}
return size;
}
static int efi_pstore_write(struct pstore_record *record)
{
char name[DUMP_NAME_LEN];
efi_char16_t efi_name[DUMP_NAME_LEN];
efi_guid_t vendor = LINUX_EFI_CRASH_GUID;
int i, ret = 0;
record->time.tv_sec = get_seconds();
record->time.tv_nsec = 0;
record->id = generic_id(record->time.tv_sec, record->part,
record->count);
snprintf(name, sizeof(name), "dump-type%u-%u-%d-%lu-%c",
record->type, record->part, record->count,
record->time.tv_sec, record->compressed ? 'C' : 'D');
for (i = 0; i < DUMP_NAME_LEN; i++)
efi_name[i] = name[i];
ret = efivar_entry_set_safe(efi_name, vendor, PSTORE_EFI_ATTRIBUTES,
!pstore_cannot_block_path(record->reason),
record->size, record->psi->buf);
if (record->reason == KMSG_DUMP_OOPS)
efivar_run_worker();
return ret;
}
static int efi_pstore_erase_func(struct efivar_entry *entry, void *data)
{
struct pstore_erase_data *ed = data;
efi_guid_t vendor = LINUX_EFI_CRASH_GUID;
efi_char16_t efi_name_old[DUMP_NAME_LEN];
efi_char16_t *efi_name = ed->name;
unsigned long ucs2_len = ucs2_strlen(ed->name);
char name_old[DUMP_NAME_LEN];
int i;
if (efi_guidcmp(entry->var.VendorGuid, vendor))
return 0;
if (ucs2_strncmp(entry->var.VariableName,
efi_name, (size_t)ucs2_len)) {
snprintf(name_old, sizeof(name_old), "dump-type%u-%u-%lu",
ed->record->type, ed->record->part,
ed->record->time.tv_sec);
for (i = 0; i < DUMP_NAME_LEN; i++)
efi_name_old[i] = name_old[i];
if (ucs2_strncmp(entry->var.VariableName, efi_name_old,
ucs2_strlen(efi_name_old)))
return 0;
}
if (entry->scanning) {
entry->deleting = true;
} else
list_del(&entry->list);
__efivar_entry_delete(entry);
return 1;
}
static int efi_pstore_erase(struct pstore_record *record)
{
struct pstore_erase_data edata;
struct efivar_entry *entry = NULL;
char name[DUMP_NAME_LEN];
efi_char16_t efi_name[DUMP_NAME_LEN];
int found, i;
snprintf(name, sizeof(name), "dump-type%u-%u-%d-%lu",
record->type, record->part, record->count,
record->time.tv_sec);
for (i = 0; i < DUMP_NAME_LEN; i++)
efi_name[i] = name[i];
edata.record = record;
edata.name = efi_name;
if (efivar_entry_iter_begin())
return -EINTR;
found = __efivar_entry_iter(efi_pstore_erase_func, &efivar_sysfs_list, &edata, &entry);
if (found && !entry->scanning) {
efivar_entry_iter_end();
efivar_unregister(entry);
} else
efivar_entry_iter_end();
return 0;
}
static __init int efivars_pstore_init(void)
{
if (!efi_enabled(EFI_RUNTIME_SERVICES))
return 0;
if (!efivars_kobject())
return 0;
if (efivars_pstore_disable)
return 0;
efi_pstore_info.buf = kmalloc(4096, GFP_KERNEL);
if (!efi_pstore_info.buf)
return -ENOMEM;
efi_pstore_info.bufsize = 1024;
spin_lock_init(&efi_pstore_info.buf_lock);
if (pstore_register(&efi_pstore_info)) {
kfree(efi_pstore_info.buf);
efi_pstore_info.buf = NULL;
efi_pstore_info.bufsize = 0;
}
return 0;
}
static __exit void efivars_pstore_exit(void)
{
if (!efi_pstore_info.bufsize)
return;
pstore_unregister(&efi_pstore_info);
kfree(efi_pstore_info.buf);
efi_pstore_info.buf = NULL;
efi_pstore_info.bufsize = 0;
}
