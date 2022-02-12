static ssize_t
efivar_guid_read(struct efivar_entry *entry, char *buf)
{
struct efi_variable *var = &entry->var;
char *str = buf;
if (!entry || !buf)
return 0;
efi_guid_to_str(&var->VendorGuid, str);
str += strlen(str);
str += sprintf(str, "\n");
return str - buf;
}
static ssize_t
efivar_attr_read(struct efivar_entry *entry, char *buf)
{
struct efi_variable *var = &entry->var;
char *str = buf;
if (!entry || !buf)
return -EINVAL;
var->DataSize = 1024;
if (efivar_entry_get(entry, &var->Attributes, &var->DataSize, var->Data))
return -EIO;
if (var->Attributes & EFI_VARIABLE_NON_VOLATILE)
str += sprintf(str, "EFI_VARIABLE_NON_VOLATILE\n");
if (var->Attributes & EFI_VARIABLE_BOOTSERVICE_ACCESS)
str += sprintf(str, "EFI_VARIABLE_BOOTSERVICE_ACCESS\n");
if (var->Attributes & EFI_VARIABLE_RUNTIME_ACCESS)
str += sprintf(str, "EFI_VARIABLE_RUNTIME_ACCESS\n");
if (var->Attributes & EFI_VARIABLE_HARDWARE_ERROR_RECORD)
str += sprintf(str, "EFI_VARIABLE_HARDWARE_ERROR_RECORD\n");
if (var->Attributes & EFI_VARIABLE_AUTHENTICATED_WRITE_ACCESS)
str += sprintf(str,
"EFI_VARIABLE_AUTHENTICATED_WRITE_ACCESS\n");
if (var->Attributes &
EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS)
str += sprintf(str,
"EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS\n");
if (var->Attributes & EFI_VARIABLE_APPEND_WRITE)
str += sprintf(str, "EFI_VARIABLE_APPEND_WRITE\n");
return str - buf;
}
static ssize_t
efivar_size_read(struct efivar_entry *entry, char *buf)
{
struct efi_variable *var = &entry->var;
char *str = buf;
if (!entry || !buf)
return -EINVAL;
var->DataSize = 1024;
if (efivar_entry_get(entry, &var->Attributes, &var->DataSize, var->Data))
return -EIO;
str += sprintf(str, "0x%lx\n", var->DataSize);
return str - buf;
}
static ssize_t
efivar_data_read(struct efivar_entry *entry, char *buf)
{
struct efi_variable *var = &entry->var;
if (!entry || !buf)
return -EINVAL;
var->DataSize = 1024;
if (efivar_entry_get(entry, &var->Attributes, &var->DataSize, var->Data))
return -EIO;
memcpy(buf, var->Data, var->DataSize);
return var->DataSize;
}
static inline int
sanity_check(struct efi_variable *var, efi_char16_t *name, efi_guid_t vendor,
unsigned long size, u32 attributes, u8 *data)
{
if (memcmp(name, var->VariableName, sizeof(var->VariableName)) ||
efi_guidcmp(vendor, var->VendorGuid)) {
printk(KERN_ERR "efivars: Cannot edit the wrong variable!\n");
return -EINVAL;
}
if ((size <= 0) || (attributes == 0)){
printk(KERN_ERR "efivars: DataSize & Attributes must be valid!\n");
return -EINVAL;
}
if ((attributes & ~EFI_VARIABLE_MASK) != 0 ||
efivar_validate(vendor, name, data, size) == false) {
printk(KERN_ERR "efivars: Malformed variable content\n");
return -EINVAL;
}
return 0;
}
static inline bool is_compat(void)
{
if (IS_ENABLED(CONFIG_COMPAT) && in_compat_syscall())
return true;
return false;
}
static void
copy_out_compat(struct efi_variable *dst, struct compat_efi_variable *src)
{
memcpy(dst->VariableName, src->VariableName, EFI_VAR_NAME_LEN);
memcpy(dst->Data, src->Data, sizeof(src->Data));
dst->VendorGuid = src->VendorGuid;
dst->DataSize = src->DataSize;
dst->Attributes = src->Attributes;
}
static ssize_t
efivar_store_raw(struct efivar_entry *entry, const char *buf, size_t count)
{
struct efi_variable *new_var, *var = &entry->var;
efi_char16_t *name;
unsigned long size;
efi_guid_t vendor;
u32 attributes;
u8 *data;
int err;
if (is_compat()) {
struct compat_efi_variable *compat;
if (count != sizeof(*compat))
return -EINVAL;
compat = (struct compat_efi_variable *)buf;
attributes = compat->Attributes;
vendor = compat->VendorGuid;
name = compat->VariableName;
size = compat->DataSize;
data = compat->Data;
err = sanity_check(var, name, vendor, size, attributes, data);
if (err)
return err;
copy_out_compat(&entry->var, compat);
} else {
if (count != sizeof(struct efi_variable))
return -EINVAL;
new_var = (struct efi_variable *)buf;
attributes = new_var->Attributes;
vendor = new_var->VendorGuid;
name = new_var->VariableName;
size = new_var->DataSize;
data = new_var->Data;
err = sanity_check(var, name, vendor, size, attributes, data);
if (err)
return err;
memcpy(&entry->var, new_var, count);
}
err = efivar_entry_set(entry, attributes, size, data, NULL);
if (err) {
printk(KERN_WARNING "efivars: set_variable() failed: status=%d\n", err);
return -EIO;
}
return count;
}
static ssize_t
efivar_show_raw(struct efivar_entry *entry, char *buf)
{
struct efi_variable *var = &entry->var;
struct compat_efi_variable *compat;
size_t size;
if (!entry || !buf)
return 0;
var->DataSize = 1024;
if (efivar_entry_get(entry, &entry->var.Attributes,
&entry->var.DataSize, entry->var.Data))
return -EIO;
if (is_compat()) {
compat = (struct compat_efi_variable *)buf;
size = sizeof(*compat);
memcpy(compat->VariableName, var->VariableName,
EFI_VAR_NAME_LEN);
memcpy(compat->Data, var->Data, sizeof(compat->Data));
compat->VendorGuid = var->VendorGuid;
compat->DataSize = var->DataSize;
compat->Attributes = var->Attributes;
} else {
size = sizeof(*var);
memcpy(buf, var, size);
}
return size;
}
static ssize_t efivar_attr_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct efivar_entry *var = to_efivar_entry(kobj);
struct efivar_attribute *efivar_attr = to_efivar_attr(attr);
ssize_t ret = -EIO;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if (efivar_attr->show) {
ret = efivar_attr->show(var, buf);
}
return ret;
}
static ssize_t efivar_attr_store(struct kobject *kobj, struct attribute *attr,
const char *buf, size_t count)
{
struct efivar_entry *var = to_efivar_entry(kobj);
struct efivar_attribute *efivar_attr = to_efivar_attr(attr);
ssize_t ret = -EIO;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if (efivar_attr->store)
ret = efivar_attr->store(var, buf, count);
return ret;
}
static void efivar_release(struct kobject *kobj)
{
struct efivar_entry *var = to_efivar_entry(kobj);
kfree(var);
}
static ssize_t efivar_create(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t pos, size_t count)
{
struct compat_efi_variable *compat = (struct compat_efi_variable *)buf;
struct efi_variable *new_var = (struct efi_variable *)buf;
struct efivar_entry *new_entry;
bool need_compat = is_compat();
efi_char16_t *name;
unsigned long size;
u32 attributes;
u8 *data;
int err;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if (need_compat) {
if (count != sizeof(*compat))
return -EINVAL;
attributes = compat->Attributes;
name = compat->VariableName;
size = compat->DataSize;
data = compat->Data;
} else {
if (count != sizeof(*new_var))
return -EINVAL;
attributes = new_var->Attributes;
name = new_var->VariableName;
size = new_var->DataSize;
data = new_var->Data;
}
if ((attributes & ~EFI_VARIABLE_MASK) != 0 ||
efivar_validate(new_var->VendorGuid, name, data,
size) == false) {
printk(KERN_ERR "efivars: Malformed variable content\n");
return -EINVAL;
}
new_entry = kzalloc(sizeof(*new_entry), GFP_KERNEL);
if (!new_entry)
return -ENOMEM;
if (need_compat)
copy_out_compat(&new_entry->var, compat);
else
memcpy(&new_entry->var, new_var, sizeof(*new_var));
err = efivar_entry_set(new_entry, attributes, size,
data, &efivar_sysfs_list);
if (err) {
if (err == -EEXIST)
err = -EINVAL;
goto out;
}
if (efivar_create_sysfs_entry(new_entry)) {
printk(KERN_WARNING "efivars: failed to create sysfs entry.\n");
kfree(new_entry);
}
return count;
out:
kfree(new_entry);
return err;
}
static ssize_t efivar_delete(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t pos, size_t count)
{
struct efi_variable *del_var = (struct efi_variable *)buf;
struct compat_efi_variable *compat;
struct efivar_entry *entry;
efi_char16_t *name;
efi_guid_t vendor;
int err = 0;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if (is_compat()) {
if (count != sizeof(*compat))
return -EINVAL;
compat = (struct compat_efi_variable *)buf;
name = compat->VariableName;
vendor = compat->VendorGuid;
} else {
if (count != sizeof(*del_var))
return -EINVAL;
name = del_var->VariableName;
vendor = del_var->VendorGuid;
}
if (efivar_entry_iter_begin())
return -EINTR;
entry = efivar_entry_find(name, vendor, &efivar_sysfs_list, true);
if (!entry)
err = -EINVAL;
else if (__efivar_entry_delete(entry))
err = -EIO;
if (err) {
efivar_entry_iter_end();
return err;
}
if (!entry->scanning) {
efivar_entry_iter_end();
efivar_unregister(entry);
} else
efivar_entry_iter_end();
return count;
}
static int
efivar_create_sysfs_entry(struct efivar_entry *new_var)
{
int short_name_size;
char *short_name;
unsigned long utf8_name_size;
efi_char16_t *variable_name = new_var->var.VariableName;
int ret;
utf8_name_size = ucs2_utf8size(variable_name);
short_name_size = utf8_name_size + 1 + EFI_VARIABLE_GUID_LEN + 1;
short_name = kmalloc(short_name_size, GFP_KERNEL);
if (!short_name)
return -ENOMEM;
ucs2_as_utf8(short_name, variable_name, short_name_size);
short_name[utf8_name_size] = '-';
efi_guid_to_str(&new_var->var.VendorGuid,
short_name + utf8_name_size + 1);
new_var->kobj.kset = efivars_kset;
ret = kobject_init_and_add(&new_var->kobj, &efivar_ktype,
NULL, "%s", short_name);
kfree(short_name);
if (ret)
return ret;
kobject_uevent(&new_var->kobj, KOBJ_ADD);
if (efivar_entry_add(new_var, &efivar_sysfs_list)) {
efivar_unregister(new_var);
return -EINTR;
}
return 0;
}
static int
create_efivars_bin_attributes(void)
{
struct bin_attribute *attr;
int error;
attr = kzalloc(sizeof(*attr), GFP_KERNEL);
if (!attr)
return -ENOMEM;
attr->attr.name = "new_var";
attr->attr.mode = 0200;
attr->write = efivar_create;
efivars_new_var = attr;
attr = kzalloc(sizeof(*attr), GFP_KERNEL);
if (!attr) {
error = -ENOMEM;
goto out_free;
}
attr->attr.name = "del_var";
attr->attr.mode = 0200;
attr->write = efivar_delete;
efivars_del_var = attr;
sysfs_bin_attr_init(efivars_new_var);
sysfs_bin_attr_init(efivars_del_var);
error = sysfs_create_bin_file(&efivars_kset->kobj, efivars_new_var);
if (error) {
printk(KERN_ERR "efivars: unable to create new_var sysfs file"
" due to error %d\n", error);
goto out_free;
}
error = sysfs_create_bin_file(&efivars_kset->kobj, efivars_del_var);
if (error) {
printk(KERN_ERR "efivars: unable to create del_var sysfs file"
" due to error %d\n", error);
sysfs_remove_bin_file(&efivars_kset->kobj, efivars_new_var);
goto out_free;
}
return 0;
out_free:
kfree(efivars_del_var);
efivars_del_var = NULL;
kfree(efivars_new_var);
efivars_new_var = NULL;
return error;
}
static int efivar_update_sysfs_entry(efi_char16_t *name, efi_guid_t vendor,
unsigned long name_size, void *data)
{
struct efivar_entry *entry = data;
if (efivar_entry_find(name, vendor, &efivar_sysfs_list, false))
return 0;
memcpy(entry->var.VariableName, name, name_size);
memcpy(&(entry->var.VendorGuid), &vendor, sizeof(efi_guid_t));
return 1;
}
static void efivar_update_sysfs_entries(struct work_struct *work)
{
struct efivar_entry *entry;
int err;
while (1) {
entry = kzalloc(sizeof(*entry), GFP_KERNEL);
if (!entry)
return;
err = efivar_init(efivar_update_sysfs_entry, entry,
false, &efivar_sysfs_list);
if (!err)
break;
efivar_create_sysfs_entry(entry);
}
kfree(entry);
}
static int efivars_sysfs_callback(efi_char16_t *name, efi_guid_t vendor,
unsigned long name_size, void *data)
{
struct efivar_entry *entry;
entry = kzalloc(sizeof(*entry), GFP_KERNEL);
if (!entry)
return -ENOMEM;
memcpy(entry->var.VariableName, name, name_size);
memcpy(&(entry->var.VendorGuid), &vendor, sizeof(efi_guid_t));
efivar_create_sysfs_entry(entry);
return 0;
}
static int efivar_sysfs_destroy(struct efivar_entry *entry, void *data)
{
int err = efivar_entry_remove(entry);
if (err)
return err;
efivar_unregister(entry);
return 0;
}
static void efivars_sysfs_exit(void)
{
int err;
err = __efivar_entry_iter(efivar_sysfs_destroy, &efivar_sysfs_list,
NULL, NULL);
if (err) {
pr_err("efivars: Failed to destroy sysfs entries\n");
return;
}
if (efivars_new_var)
sysfs_remove_bin_file(&efivars_kset->kobj, efivars_new_var);
if (efivars_del_var)
sysfs_remove_bin_file(&efivars_kset->kobj, efivars_del_var);
kfree(efivars_new_var);
kfree(efivars_del_var);
kset_unregister(efivars_kset);
}
int efivars_sysfs_init(void)
{
struct kobject *parent_kobj = efivars_kobject();
int error = 0;
if (!efi_enabled(EFI_RUNTIME_SERVICES))
return -ENODEV;
if (!parent_kobj)
return 0;
printk(KERN_INFO "EFI Variables Facility v%s %s\n", EFIVARS_VERSION,
EFIVARS_DATE);
efivars_kset = kset_create_and_add("vars", NULL, parent_kobj);
if (!efivars_kset) {
printk(KERN_ERR "efivars: Subsystem registration failed.\n");
return -ENOMEM;
}
efivar_init(efivars_sysfs_callback, NULL, true, &efivar_sysfs_list);
error = create_efivars_bin_attributes();
if (error) {
efivars_sysfs_exit();
return error;
}
INIT_WORK(&efivar_work, efivar_update_sysfs_entries);
return 0;
}
