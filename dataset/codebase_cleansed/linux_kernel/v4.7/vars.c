static bool
validate_device_path(efi_char16_t *var_name, int match, u8 *buffer,
unsigned long len)
{
struct efi_generic_dev_path *node;
int offset = 0;
node = (struct efi_generic_dev_path *)buffer;
if (len < sizeof(*node))
return false;
while (offset <= len - sizeof(*node) &&
node->length >= sizeof(*node) &&
node->length <= len - offset) {
offset += node->length;
if ((node->type == EFI_DEV_END_PATH ||
node->type == EFI_DEV_END_PATH2) &&
node->sub_type == EFI_DEV_END_ENTIRE)
return true;
node = (struct efi_generic_dev_path *)(buffer + offset);
}
return false;
}
static bool
validate_boot_order(efi_char16_t *var_name, int match, u8 *buffer,
unsigned long len)
{
if ((len % 2) != 0)
return false;
return true;
}
static bool
validate_load_option(efi_char16_t *var_name, int match, u8 *buffer,
unsigned long len)
{
u16 filepathlength;
int i, desclength = 0, namelen;
namelen = ucs2_strnlen(var_name, EFI_VAR_NAME_LEN);
for (i = match; i < match+4; i++) {
if (var_name[i] > 127 ||
hex_to_bin(var_name[i] & 0xff) < 0)
return true;
}
if (namelen > match + 4)
return false;
if (len < 8)
return false;
filepathlength = buffer[4] | buffer[5] << 8;
desclength = ucs2_strsize((efi_char16_t *)(buffer + 6), len - 6) + 2;
if (!desclength)
return false;
if ((desclength + filepathlength + 6) > len)
return false;
return validate_device_path(var_name, match, buffer + desclength + 6,
filepathlength);
}
static bool
validate_uint16(efi_char16_t *var_name, int match, u8 *buffer,
unsigned long len)
{
if (len != 2)
return false;
return true;
}
static bool
validate_ascii_string(efi_char16_t *var_name, int match, u8 *buffer,
unsigned long len)
{
int i;
for (i = 0; i < len; i++) {
if (buffer[i] > 127)
return false;
if (buffer[i] == 0)
return true;
}
return false;
}
static bool
variable_matches(const char *var_name, size_t len, const char *match_name,
int *match)
{
for (*match = 0; ; (*match)++) {
char c = match_name[*match];
switch (c) {
case '*':
return true;
case '\0':
return (*match == len);
default:
if (*match < len && c == var_name[*match])
continue;
return false;
}
}
}
bool
efivar_validate(efi_guid_t vendor, efi_char16_t *var_name, u8 *data,
unsigned long data_size)
{
int i;
unsigned long utf8_size;
u8 *utf8_name;
utf8_size = ucs2_utf8size(var_name);
utf8_name = kmalloc(utf8_size + 1, GFP_KERNEL);
if (!utf8_name)
return false;
ucs2_as_utf8(utf8_name, var_name, utf8_size);
utf8_name[utf8_size] = '\0';
for (i = 0; variable_validate[i].name[0] != '\0'; i++) {
const char *name = variable_validate[i].name;
int match = 0;
if (efi_guidcmp(vendor, variable_validate[i].vendor))
continue;
if (variable_matches(utf8_name, utf8_size+1, name, &match)) {
if (variable_validate[i].validate == NULL)
break;
kfree(utf8_name);
return variable_validate[i].validate(var_name, match,
data, data_size);
}
}
kfree(utf8_name);
return true;
}
bool
efivar_variable_is_removable(efi_guid_t vendor, const char *var_name,
size_t len)
{
int i;
bool found = false;
int match = 0;
for (i = 0; variable_validate[i].name[0] != '\0'; i++) {
if (efi_guidcmp(variable_validate[i].vendor, vendor))
continue;
if (variable_matches(var_name, len,
variable_validate[i].name, &match)) {
found = true;
break;
}
}
return found;
}
static efi_status_t
check_var_size(u32 attributes, unsigned long size)
{
const struct efivar_operations *fops = __efivars->ops;
if (!fops->query_variable_store)
return EFI_UNSUPPORTED;
return fops->query_variable_store(attributes, size, false);
}
static efi_status_t
check_var_size_nonblocking(u32 attributes, unsigned long size)
{
const struct efivar_operations *fops = __efivars->ops;
if (!fops->query_variable_store)
return EFI_UNSUPPORTED;
return fops->query_variable_store(attributes, size, true);
}
static bool variable_is_present(efi_char16_t *variable_name, efi_guid_t *vendor,
struct list_head *head)
{
struct efivar_entry *entry, *n;
unsigned long strsize1, strsize2;
bool found = false;
strsize1 = ucs2_strsize(variable_name, 1024);
list_for_each_entry_safe(entry, n, head, list) {
strsize2 = ucs2_strsize(entry->var.VariableName, 1024);
if (strsize1 == strsize2 &&
!memcmp(variable_name, &(entry->var.VariableName),
strsize2) &&
!efi_guidcmp(entry->var.VendorGuid,
*vendor)) {
found = true;
break;
}
}
return found;
}
static unsigned long var_name_strnsize(efi_char16_t *variable_name,
unsigned long variable_name_size)
{
unsigned long len;
efi_char16_t c;
for (len = 2; len <= variable_name_size; len += sizeof(c)) {
c = variable_name[(len / sizeof(c)) - 1];
if (!c)
break;
}
return min(len, variable_name_size);
}
static void dup_variable_bug(efi_char16_t *str16, efi_guid_t *vendor_guid,
unsigned long len16)
{
size_t i, len8 = len16 / sizeof(efi_char16_t);
char *str8;
efivar_wq_enabled = false;
str8 = kzalloc(len8, GFP_KERNEL);
if (!str8)
return;
for (i = 0; i < len8; i++)
str8[i] = str16[i];
printk(KERN_WARNING "efivars: duplicate variable: %s-%pUl\n",
str8, vendor_guid);
kfree(str8);
}
int efivar_init(int (*func)(efi_char16_t *, efi_guid_t, unsigned long, void *),
void *data, bool duplicates, struct list_head *head)
{
const struct efivar_operations *ops = __efivars->ops;
unsigned long variable_name_size = 1024;
efi_char16_t *variable_name;
efi_status_t status;
efi_guid_t vendor_guid;
int err = 0;
variable_name = kzalloc(variable_name_size, GFP_KERNEL);
if (!variable_name) {
printk(KERN_ERR "efivars: Memory allocation failed.\n");
return -ENOMEM;
}
spin_lock_irq(&__efivars->lock);
do {
variable_name_size = 1024;
status = ops->get_next_variable(&variable_name_size,
variable_name,
&vendor_guid);
switch (status) {
case EFI_SUCCESS:
if (duplicates)
spin_unlock_irq(&__efivars->lock);
variable_name_size = var_name_strnsize(variable_name,
variable_name_size);
if (duplicates &&
variable_is_present(variable_name, &vendor_guid,
head)) {
dup_variable_bug(variable_name, &vendor_guid,
variable_name_size);
status = EFI_NOT_FOUND;
} else {
err = func(variable_name, vendor_guid,
variable_name_size, data);
if (err)
status = EFI_NOT_FOUND;
}
if (duplicates)
spin_lock_irq(&__efivars->lock);
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
spin_unlock_irq(&__efivars->lock);
kfree(variable_name);
return err;
}
void efivar_entry_add(struct efivar_entry *entry, struct list_head *head)
{
spin_lock_irq(&__efivars->lock);
list_add(&entry->list, head);
spin_unlock_irq(&__efivars->lock);
}
void efivar_entry_remove(struct efivar_entry *entry)
{
spin_lock_irq(&__efivars->lock);
list_del(&entry->list);
spin_unlock_irq(&__efivars->lock);
}
static void efivar_entry_list_del_unlock(struct efivar_entry *entry)
{
lockdep_assert_held(&__efivars->lock);
list_del(&entry->list);
spin_unlock_irq(&__efivars->lock);
}
int __efivar_entry_delete(struct efivar_entry *entry)
{
const struct efivar_operations *ops = __efivars->ops;
efi_status_t status;
lockdep_assert_held(&__efivars->lock);
status = ops->set_variable(entry->var.VariableName,
&entry->var.VendorGuid,
0, 0, NULL);
return efi_status_to_err(status);
}
int efivar_entry_delete(struct efivar_entry *entry)
{
const struct efivar_operations *ops = __efivars->ops;
efi_status_t status;
spin_lock_irq(&__efivars->lock);
status = ops->set_variable(entry->var.VariableName,
&entry->var.VendorGuid,
0, 0, NULL);
if (!(status == EFI_SUCCESS || status == EFI_NOT_FOUND)) {
spin_unlock_irq(&__efivars->lock);
return efi_status_to_err(status);
}
efivar_entry_list_del_unlock(entry);
return 0;
}
int efivar_entry_set(struct efivar_entry *entry, u32 attributes,
unsigned long size, void *data, struct list_head *head)
{
const struct efivar_operations *ops = __efivars->ops;
efi_status_t status;
efi_char16_t *name = entry->var.VariableName;
efi_guid_t vendor = entry->var.VendorGuid;
spin_lock_irq(&__efivars->lock);
if (head && efivar_entry_find(name, vendor, head, false)) {
spin_unlock_irq(&__efivars->lock);
return -EEXIST;
}
status = check_var_size(attributes, size + ucs2_strsize(name, 1024));
if (status == EFI_SUCCESS || status == EFI_UNSUPPORTED)
status = ops->set_variable(name, &vendor,
attributes, size, data);
spin_unlock_irq(&__efivars->lock);
return efi_status_to_err(status);
}
static int
efivar_entry_set_nonblocking(efi_char16_t *name, efi_guid_t vendor,
u32 attributes, unsigned long size, void *data)
{
const struct efivar_operations *ops = __efivars->ops;
unsigned long flags;
efi_status_t status;
if (!spin_trylock_irqsave(&__efivars->lock, flags))
return -EBUSY;
status = check_var_size_nonblocking(attributes,
size + ucs2_strsize(name, 1024));
if (status != EFI_SUCCESS) {
spin_unlock_irqrestore(&__efivars->lock, flags);
return -ENOSPC;
}
status = ops->set_variable_nonblocking(name, &vendor, attributes,
size, data);
spin_unlock_irqrestore(&__efivars->lock, flags);
return efi_status_to_err(status);
}
int efivar_entry_set_safe(efi_char16_t *name, efi_guid_t vendor, u32 attributes,
bool block, unsigned long size, void *data)
{
const struct efivar_operations *ops = __efivars->ops;
unsigned long flags;
efi_status_t status;
if (!ops->query_variable_store)
return -ENOSYS;
if (!block && ops->set_variable_nonblocking)
return efivar_entry_set_nonblocking(name, vendor, attributes,
size, data);
if (!block) {
if (!spin_trylock_irqsave(&__efivars->lock, flags))
return -EBUSY;
} else {
spin_lock_irqsave(&__efivars->lock, flags);
}
status = check_var_size(attributes, size + ucs2_strsize(name, 1024));
if (status != EFI_SUCCESS) {
spin_unlock_irqrestore(&__efivars->lock, flags);
return -ENOSPC;
}
status = ops->set_variable(name, &vendor, attributes, size, data);
spin_unlock_irqrestore(&__efivars->lock, flags);
return efi_status_to_err(status);
}
struct efivar_entry *efivar_entry_find(efi_char16_t *name, efi_guid_t guid,
struct list_head *head, bool remove)
{
struct efivar_entry *entry, *n;
int strsize1, strsize2;
bool found = false;
lockdep_assert_held(&__efivars->lock);
list_for_each_entry_safe(entry, n, head, list) {
strsize1 = ucs2_strsize(name, 1024);
strsize2 = ucs2_strsize(entry->var.VariableName, 1024);
if (strsize1 == strsize2 &&
!memcmp(name, &(entry->var.VariableName), strsize1) &&
!efi_guidcmp(guid, entry->var.VendorGuid)) {
found = true;
break;
}
}
if (!found)
return NULL;
if (remove) {
if (entry->scanning) {
entry->deleting = true;
} else
list_del(&entry->list);
}
return entry;
}
int efivar_entry_size(struct efivar_entry *entry, unsigned long *size)
{
const struct efivar_operations *ops = __efivars->ops;
efi_status_t status;
*size = 0;
spin_lock_irq(&__efivars->lock);
status = ops->get_variable(entry->var.VariableName,
&entry->var.VendorGuid, NULL, size, NULL);
spin_unlock_irq(&__efivars->lock);
if (status != EFI_BUFFER_TOO_SMALL)
return efi_status_to_err(status);
return 0;
}
int __efivar_entry_get(struct efivar_entry *entry, u32 *attributes,
unsigned long *size, void *data)
{
const struct efivar_operations *ops = __efivars->ops;
efi_status_t status;
lockdep_assert_held(&__efivars->lock);
status = ops->get_variable(entry->var.VariableName,
&entry->var.VendorGuid,
attributes, size, data);
return efi_status_to_err(status);
}
int efivar_entry_get(struct efivar_entry *entry, u32 *attributes,
unsigned long *size, void *data)
{
const struct efivar_operations *ops = __efivars->ops;
efi_status_t status;
spin_lock_irq(&__efivars->lock);
status = ops->get_variable(entry->var.VariableName,
&entry->var.VendorGuid,
attributes, size, data);
spin_unlock_irq(&__efivars->lock);
return efi_status_to_err(status);
}
int efivar_entry_set_get_size(struct efivar_entry *entry, u32 attributes,
unsigned long *size, void *data, bool *set)
{
const struct efivar_operations *ops = __efivars->ops;
efi_char16_t *name = entry->var.VariableName;
efi_guid_t *vendor = &entry->var.VendorGuid;
efi_status_t status;
int err;
*set = false;
if (efivar_validate(*vendor, name, data, *size) == false)
return -EINVAL;
spin_lock_irq(&__efivars->lock);
status = check_var_size(attributes, *size + ucs2_strsize(name, 1024));
if (status != EFI_SUCCESS) {
if (status != EFI_UNSUPPORTED) {
err = efi_status_to_err(status);
goto out;
}
if (*size > 65536) {
err = -ENOSPC;
goto out;
}
}
status = ops->set_variable(name, vendor, attributes, *size, data);
if (status != EFI_SUCCESS) {
err = efi_status_to_err(status);
goto out;
}
*set = true;
*size = 0;
status = ops->get_variable(entry->var.VariableName,
&entry->var.VendorGuid,
NULL, size, NULL);
if (status == EFI_NOT_FOUND)
efivar_entry_list_del_unlock(entry);
else
spin_unlock_irq(&__efivars->lock);
if (status && status != EFI_BUFFER_TOO_SMALL)
return efi_status_to_err(status);
return 0;
out:
spin_unlock_irq(&__efivars->lock);
return err;
}
void efivar_entry_iter_begin(void)
{
spin_lock_irq(&__efivars->lock);
}
void efivar_entry_iter_end(void)
{
spin_unlock_irq(&__efivars->lock);
}
int __efivar_entry_iter(int (*func)(struct efivar_entry *, void *),
struct list_head *head, void *data,
struct efivar_entry **prev)
{
struct efivar_entry *entry, *n;
int err = 0;
if (!prev || !*prev) {
list_for_each_entry_safe(entry, n, head, list) {
err = func(entry, data);
if (err)
break;
}
if (prev)
*prev = entry;
return err;
}
list_for_each_entry_safe_continue((*prev), n, head, list) {
err = func(*prev, data);
if (err)
break;
}
return err;
}
int efivar_entry_iter(int (*func)(struct efivar_entry *, void *),
struct list_head *head, void *data)
{
int err = 0;
efivar_entry_iter_begin();
err = __efivar_entry_iter(func, head, data, NULL);
efivar_entry_iter_end();
return err;
}
struct kobject *efivars_kobject(void)
{
if (!__efivars)
return NULL;
return __efivars->kobject;
}
void efivar_run_worker(void)
{
if (efivar_wq_enabled)
schedule_work(&efivar_work);
}
int efivars_register(struct efivars *efivars,
const struct efivar_operations *ops,
struct kobject *kobject)
{
spin_lock_init(&efivars->lock);
efivars->ops = ops;
efivars->kobject = kobject;
__efivars = efivars;
return 0;
}
int efivars_unregister(struct efivars *efivars)
{
int rv;
if (!__efivars) {
printk(KERN_ERR "efivars not registered\n");
rv = -EINVAL;
goto out;
}
if (__efivars != efivars) {
rv = -EINVAL;
goto out;
}
__efivars = NULL;
rv = 0;
out:
return rv;
}
