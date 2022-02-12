static unsigned long
utf8_strlen(efi_char16_t *data, unsigned long maxlength)
{
unsigned long length = 0;
while (*data++ != 0 && length < maxlength)
length++;
return length;
}
static inline unsigned long
utf8_strsize(efi_char16_t *data, unsigned long maxlength)
{
return utf8_strlen(data, maxlength/sizeof(efi_char16_t)) * sizeof(efi_char16_t);
}
static efi_status_t
get_var_data(struct efivars *efivars, struct efi_variable *var)
{
efi_status_t status;
spin_lock(&efivars->lock);
var->DataSize = 1024;
status = efivars->ops->get_variable(var->VariableName,
&var->VendorGuid,
&var->Attributes,
&var->DataSize,
var->Data);
spin_unlock(&efivars->lock);
if (status != EFI_SUCCESS) {
printk(KERN_WARNING "efivars: get_variable() failed 0x%lx!\n",
status);
}
return status;
}
static ssize_t
efivar_guid_read(struct efivar_entry *entry, char *buf)
{
struct efi_variable *var = &entry->var;
char *str = buf;
if (!entry || !buf)
return 0;
efi_guid_unparse(&var->VendorGuid, str);
str += strlen(str);
str += sprintf(str, "\n");
return str - buf;
}
static ssize_t
efivar_attr_read(struct efivar_entry *entry, char *buf)
{
struct efi_variable *var = &entry->var;
char *str = buf;
efi_status_t status;
if (!entry || !buf)
return -EINVAL;
status = get_var_data(entry->efivars, var);
if (status != EFI_SUCCESS)
return -EIO;
if (var->Attributes & 0x1)
str += sprintf(str, "EFI_VARIABLE_NON_VOLATILE\n");
if (var->Attributes & 0x2)
str += sprintf(str, "EFI_VARIABLE_BOOTSERVICE_ACCESS\n");
if (var->Attributes & 0x4)
str += sprintf(str, "EFI_VARIABLE_RUNTIME_ACCESS\n");
return str - buf;
}
static ssize_t
efivar_size_read(struct efivar_entry *entry, char *buf)
{
struct efi_variable *var = &entry->var;
char *str = buf;
efi_status_t status;
if (!entry || !buf)
return -EINVAL;
status = get_var_data(entry->efivars, var);
if (status != EFI_SUCCESS)
return -EIO;
str += sprintf(str, "0x%lx\n", var->DataSize);
return str - buf;
}
static ssize_t
efivar_data_read(struct efivar_entry *entry, char *buf)
{
struct efi_variable *var = &entry->var;
efi_status_t status;
if (!entry || !buf)
return -EINVAL;
status = get_var_data(entry->efivars, var);
if (status != EFI_SUCCESS)
return -EIO;
memcpy(buf, var->Data, var->DataSize);
return var->DataSize;
}
static ssize_t
efivar_store_raw(struct efivar_entry *entry, const char *buf, size_t count)
{
struct efi_variable *new_var, *var = &entry->var;
struct efivars *efivars = entry->efivars;
efi_status_t status = EFI_NOT_FOUND;
if (count != sizeof(struct efi_variable))
return -EINVAL;
new_var = (struct efi_variable *)buf;
if (memcmp(new_var->VariableName, var->VariableName, sizeof(var->VariableName)) ||
efi_guidcmp(new_var->VendorGuid, var->VendorGuid)) {
printk(KERN_ERR "efivars: Cannot edit the wrong variable!\n");
return -EINVAL;
}
if ((new_var->DataSize <= 0) || (new_var->Attributes == 0)){
printk(KERN_ERR "efivars: DataSize & Attributes must be valid!\n");
return -EINVAL;
}
spin_lock(&efivars->lock);
status = efivars->ops->set_variable(new_var->VariableName,
&new_var->VendorGuid,
new_var->Attributes,
new_var->DataSize,
new_var->Data);
spin_unlock(&efivars->lock);
if (status != EFI_SUCCESS) {
printk(KERN_WARNING "efivars: set_variable() failed: status=%lx\n",
status);
return -EIO;
}
memcpy(&entry->var, new_var, count);
return count;
}
static ssize_t
efivar_show_raw(struct efivar_entry *entry, char *buf)
{
struct efi_variable *var = &entry->var;
efi_status_t status;
if (!entry || !buf)
return 0;
status = get_var_data(entry->efivars, var);
if (status != EFI_SUCCESS)
return -EIO;
memcpy(buf, var, sizeof(*var));
return sizeof(*var);
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
struct efivar_entry *var = container_of(kobj, struct efivar_entry, kobj);
kfree(var);
}
static inline void
efivar_unregister(struct efivar_entry *var)
{
kobject_put(&var->kobj);
}
static ssize_t efivar_create(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t pos, size_t count)
{
struct efi_variable *new_var = (struct efi_variable *)buf;
struct efivars *efivars = bin_attr->private;
struct efivar_entry *search_efivar, *n;
unsigned long strsize1, strsize2;
efi_status_t status = EFI_NOT_FOUND;
int found = 0;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
spin_lock(&efivars->lock);
list_for_each_entry_safe(search_efivar, n, &efivars->list, list) {
strsize1 = utf8_strsize(search_efivar->var.VariableName, 1024);
strsize2 = utf8_strsize(new_var->VariableName, 1024);
if (strsize1 == strsize2 &&
!memcmp(&(search_efivar->var.VariableName),
new_var->VariableName, strsize1) &&
!efi_guidcmp(search_efivar->var.VendorGuid,
new_var->VendorGuid)) {
found = 1;
break;
}
}
if (found) {
spin_unlock(&efivars->lock);
return -EINVAL;
}
status = efivars->ops->set_variable(new_var->VariableName,
&new_var->VendorGuid,
new_var->Attributes,
new_var->DataSize,
new_var->Data);
if (status != EFI_SUCCESS) {
printk(KERN_WARNING "efivars: set_variable() failed: status=%lx\n",
status);
spin_unlock(&efivars->lock);
return -EIO;
}
spin_unlock(&efivars->lock);
status = efivar_create_sysfs_entry(efivars,
utf8_strsize(new_var->VariableName,
1024),
new_var->VariableName,
&new_var->VendorGuid);
if (status) {
printk(KERN_WARNING "efivars: variable created, but sysfs entry wasn't.\n");
}
return count;
}
static ssize_t efivar_delete(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t pos, size_t count)
{
struct efi_variable *del_var = (struct efi_variable *)buf;
struct efivars *efivars = bin_attr->private;
struct efivar_entry *search_efivar, *n;
unsigned long strsize1, strsize2;
efi_status_t status = EFI_NOT_FOUND;
int found = 0;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
spin_lock(&efivars->lock);
list_for_each_entry_safe(search_efivar, n, &efivars->list, list) {
strsize1 = utf8_strsize(search_efivar->var.VariableName, 1024);
strsize2 = utf8_strsize(del_var->VariableName, 1024);
if (strsize1 == strsize2 &&
!memcmp(&(search_efivar->var.VariableName),
del_var->VariableName, strsize1) &&
!efi_guidcmp(search_efivar->var.VendorGuid,
del_var->VendorGuid)) {
found = 1;
break;
}
}
if (!found) {
spin_unlock(&efivars->lock);
return -EINVAL;
}
del_var->Attributes = 0;
del_var->DataSize = 0;
status = efivars->ops->set_variable(del_var->VariableName,
&del_var->VendorGuid,
del_var->Attributes,
del_var->DataSize,
del_var->Data);
if (status != EFI_SUCCESS) {
printk(KERN_WARNING "efivars: set_variable() failed: status=%lx\n",
status);
spin_unlock(&efivars->lock);
return -EIO;
}
list_del(&search_efivar->list);
spin_unlock(&efivars->lock);
efivar_unregister(search_efivar);
return count;
}
static ssize_t systab_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
char *str = buf;
if (!kobj || !buf)
return -EINVAL;
if (efi.mps != EFI_INVALID_TABLE_ADDR)
str += sprintf(str, "MPS=0x%lx\n", efi.mps);
if (efi.acpi20 != EFI_INVALID_TABLE_ADDR)
str += sprintf(str, "ACPI20=0x%lx\n", efi.acpi20);
if (efi.acpi != EFI_INVALID_TABLE_ADDR)
str += sprintf(str, "ACPI=0x%lx\n", efi.acpi);
if (efi.smbios != EFI_INVALID_TABLE_ADDR)
str += sprintf(str, "SMBIOS=0x%lx\n", efi.smbios);
if (efi.hcdp != EFI_INVALID_TABLE_ADDR)
str += sprintf(str, "HCDP=0x%lx\n", efi.hcdp);
if (efi.boot_info != EFI_INVALID_TABLE_ADDR)
str += sprintf(str, "BOOTINFO=0x%lx\n", efi.boot_info);
if (efi.uga != EFI_INVALID_TABLE_ADDR)
str += sprintf(str, "UGA=0x%lx\n", efi.uga);
return str - buf;
}
static int
efivar_create_sysfs_entry(struct efivars *efivars,
unsigned long variable_name_size,
efi_char16_t *variable_name,
efi_guid_t *vendor_guid)
{
int i, short_name_size = variable_name_size / sizeof(efi_char16_t) + 38;
char *short_name;
struct efivar_entry *new_efivar;
short_name = kzalloc(short_name_size + 1, GFP_KERNEL);
new_efivar = kzalloc(sizeof(struct efivar_entry), GFP_KERNEL);
if (!short_name || !new_efivar) {
kfree(short_name);
kfree(new_efivar);
return 1;
}
new_efivar->efivars = efivars;
memcpy(new_efivar->var.VariableName, variable_name,
variable_name_size);
memcpy(&(new_efivar->var.VendorGuid), vendor_guid, sizeof(efi_guid_t));
for (i=0; i < (int)(variable_name_size / sizeof(efi_char16_t)); i++) {
short_name[i] = variable_name[i] & 0xFF;
}
*(short_name + strlen(short_name)) = '-';
efi_guid_unparse(vendor_guid, short_name + strlen(short_name));
new_efivar->kobj.kset = efivars->kset;
i = kobject_init_and_add(&new_efivar->kobj, &efivar_ktype, NULL,
"%s", short_name);
if (i) {
kfree(short_name);
kfree(new_efivar);
return 1;
}
kobject_uevent(&new_efivar->kobj, KOBJ_ADD);
kfree(short_name);
short_name = NULL;
spin_lock(&efivars->lock);
list_add(&new_efivar->list, &efivars->list);
spin_unlock(&efivars->lock);
return 0;
}
static int
create_efivars_bin_attributes(struct efivars *efivars)
{
struct bin_attribute *attr;
int error;
attr = kzalloc(sizeof(*attr), GFP_KERNEL);
if (!attr)
return -ENOMEM;
attr->attr.name = "new_var";
attr->attr.mode = 0200;
attr->write = efivar_create;
attr->private = efivars;
efivars->new_var = attr;
attr = kzalloc(sizeof(*attr), GFP_KERNEL);
if (!attr) {
error = -ENOMEM;
goto out_free;
}
attr->attr.name = "del_var";
attr->attr.mode = 0200;
attr->write = efivar_delete;
attr->private = efivars;
efivars->del_var = attr;
sysfs_bin_attr_init(efivars->new_var);
sysfs_bin_attr_init(efivars->del_var);
error = sysfs_create_bin_file(&efivars->kset->kobj,
efivars->new_var);
if (error) {
printk(KERN_ERR "efivars: unable to create new_var sysfs file"
" due to error %d\n", error);
goto out_free;
}
error = sysfs_create_bin_file(&efivars->kset->kobj,
efivars->del_var);
if (error) {
printk(KERN_ERR "efivars: unable to create del_var sysfs file"
" due to error %d\n", error);
sysfs_remove_bin_file(&efivars->kset->kobj,
efivars->new_var);
goto out_free;
}
return 0;
out_free:
kfree(efivars->del_var);
efivars->del_var = NULL;
kfree(efivars->new_var);
efivars->new_var = NULL;
return error;
}
void unregister_efivars(struct efivars *efivars)
{
struct efivar_entry *entry, *n;
list_for_each_entry_safe(entry, n, &efivars->list, list) {
spin_lock(&efivars->lock);
list_del(&entry->list);
spin_unlock(&efivars->lock);
efivar_unregister(entry);
}
if (efivars->new_var)
sysfs_remove_bin_file(&efivars->kset->kobj, efivars->new_var);
if (efivars->del_var)
sysfs_remove_bin_file(&efivars->kset->kobj, efivars->del_var);
kfree(efivars->new_var);
kfree(efivars->del_var);
kset_unregister(efivars->kset);
}
int register_efivars(struct efivars *efivars,
const struct efivar_operations *ops,
struct kobject *parent_kobj)
{
efi_status_t status = EFI_NOT_FOUND;
efi_guid_t vendor_guid;
efi_char16_t *variable_name;
unsigned long variable_name_size = 1024;
int error = 0;
variable_name = kzalloc(variable_name_size, GFP_KERNEL);
if (!variable_name) {
printk(KERN_ERR "efivars: Memory allocation failed.\n");
return -ENOMEM;
}
spin_lock_init(&efivars->lock);
INIT_LIST_HEAD(&efivars->list);
efivars->ops = ops;
efivars->kset = kset_create_and_add("vars", NULL, parent_kobj);
if (!efivars->kset) {
printk(KERN_ERR "efivars: Subsystem registration failed.\n");
error = -ENOMEM;
goto out;
}
do {
variable_name_size = 1024;
status = ops->get_next_variable(&variable_name_size,
variable_name,
&vendor_guid);
switch (status) {
case EFI_SUCCESS:
efivar_create_sysfs_entry(efivars,
variable_name_size,
variable_name,
&vendor_guid);
break;
case EFI_NOT_FOUND:
break;
default:
printk(KERN_WARNING "efivars: get_next_variable: status=%lx\n",
status);
status = EFI_NOT_FOUND;
break;
}
} while (status != EFI_NOT_FOUND);
error = create_efivars_bin_attributes(efivars);
if (error)
unregister_efivars(efivars);
out:
kfree(variable_name);
return error;
}
static int __init
efivars_init(void)
{
int error = 0;
printk(KERN_INFO "EFI Variables Facility v%s %s\n", EFIVARS_VERSION,
EFIVARS_DATE);
if (!efi_enabled)
return 0;
efi_kobj = kobject_create_and_add("efi", firmware_kobj);
if (!efi_kobj) {
printk(KERN_ERR "efivars: Firmware registration failed.\n");
return -ENOMEM;
}
ops.get_variable = efi.get_variable;
ops.set_variable = efi.set_variable;
ops.get_next_variable = efi.get_next_variable;
error = register_efivars(&__efivars, &ops, efi_kobj);
if (error)
goto err_put;
error = sysfs_create_group(efi_kobj, &efi_subsys_attr_group);
if (error) {
printk(KERN_ERR
"efivars: Sysfs attribute export failed with error %d.\n",
error);
goto err_unregister;
}
return 0;
err_unregister:
unregister_efivars(&__efivars);
err_put:
kobject_put(efi_kobj);
return error;
}
static void __exit
efivars_exit(void)
{
if (efi_enabled) {
unregister_efivars(&__efivars);
kobject_put(efi_kobj);
}
}
