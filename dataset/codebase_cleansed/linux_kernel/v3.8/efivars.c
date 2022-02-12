static unsigned long
utf16_strnlen(efi_char16_t *s, size_t maxlength)
{
unsigned long length = 0;
while (*s++ != 0 && length < maxlength)
length++;
return length;
}
static inline unsigned long
utf16_strlen(efi_char16_t *s)
{
return utf16_strnlen(s, ~0UL);
}
static inline unsigned long
utf16_strsize(efi_char16_t *data, unsigned long maxlength)
{
return utf16_strnlen(data, maxlength/sizeof(efi_char16_t)) * sizeof(efi_char16_t);
}
static inline int
utf16_strncmp(const efi_char16_t *a, const efi_char16_t *b, size_t len)
{
while (1) {
if (len == 0)
return 0;
if (*a < *b)
return -1;
if (*a > *b)
return 1;
if (*a == 0)
return 0;
a++;
b++;
len--;
}
}
static bool
validate_device_path(struct efi_variable *var, int match, u8 *buffer,
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
validate_boot_order(struct efi_variable *var, int match, u8 *buffer,
unsigned long len)
{
if ((len % 2) != 0)
return false;
return true;
}
static bool
validate_load_option(struct efi_variable *var, int match, u8 *buffer,
unsigned long len)
{
u16 filepathlength;
int i, desclength = 0, namelen;
namelen = utf16_strnlen(var->VariableName, sizeof(var->VariableName));
for (i = match; i < match+4; i++) {
if (var->VariableName[i] > 127 ||
hex_to_bin(var->VariableName[i] & 0xff) < 0)
return true;
}
if (namelen > match + 4)
return false;
if (len < 8)
return false;
filepathlength = buffer[4] | buffer[5] << 8;
desclength = utf16_strsize((efi_char16_t *)(buffer + 6), len - 6) + 2;
if (!desclength)
return false;
if ((desclength + filepathlength + 6) > len)
return false;
return validate_device_path(var, match, buffer + desclength + 6,
filepathlength);
}
static bool
validate_uint16(struct efi_variable *var, int match, u8 *buffer,
unsigned long len)
{
if (len != 2)
return false;
return true;
}
static bool
validate_ascii_string(struct efi_variable *var, int match, u8 *buffer,
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
validate_var(struct efi_variable *var, u8 *data, unsigned long len)
{
int i;
u16 *unicode_name = var->VariableName;
for (i = 0; variable_validate[i].validate != NULL; i++) {
const char *name = variable_validate[i].name;
int match;
for (match = 0; ; match++) {
char c = name[match];
u16 u = unicode_name[match];
if (u > 127)
return true;
if (c == '*')
return variable_validate[i].validate(var,
match, data, len);
if (c != u)
break;
if (!c)
return variable_validate[i].validate(var,
match, data, len);
}
}
return true;
}
static efi_status_t
get_var_data_locked(struct efivars *efivars, struct efi_variable *var)
{
efi_status_t status;
var->DataSize = 1024;
status = efivars->ops->get_variable(var->VariableName,
&var->VendorGuid,
&var->Attributes,
&var->DataSize,
var->Data);
return status;
}
static efi_status_t
get_var_data(struct efivars *efivars, struct efi_variable *var)
{
efi_status_t status;
spin_lock(&efivars->lock);
status = get_var_data_locked(efivars, var);
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
if ((new_var->Attributes & ~EFI_VARIABLE_MASK) != 0 ||
validate_var(new_var, new_var->Data, new_var->DataSize) == false) {
printk(KERN_ERR "efivars: Malformed variable content\n");
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
static int efivarfs_file_open(struct inode *inode, struct file *file)
{
file->private_data = inode->i_private;
return 0;
}
static int efi_status_to_err(efi_status_t status)
{
int err;
switch (status) {
case EFI_INVALID_PARAMETER:
err = -EINVAL;
break;
case EFI_OUT_OF_RESOURCES:
err = -ENOSPC;
break;
case EFI_DEVICE_ERROR:
err = -EIO;
break;
case EFI_WRITE_PROTECTED:
err = -EROFS;
break;
case EFI_SECURITY_VIOLATION:
err = -EACCES;
break;
case EFI_NOT_FOUND:
err = -EIO;
break;
default:
err = -EINVAL;
}
return err;
}
static ssize_t efivarfs_file_write(struct file *file,
const char __user *userbuf, size_t count, loff_t *ppos)
{
struct efivar_entry *var = file->private_data;
struct efivars *efivars;
efi_status_t status;
void *data;
u32 attributes;
struct inode *inode = file->f_mapping->host;
unsigned long datasize = count - sizeof(attributes);
unsigned long newdatasize;
u64 storage_size, remaining_size, max_size;
ssize_t bytes = 0;
if (count < sizeof(attributes))
return -EINVAL;
if (copy_from_user(&attributes, userbuf, sizeof(attributes)))
return -EFAULT;
if (attributes & ~(EFI_VARIABLE_MASK))
return -EINVAL;
efivars = var->efivars;
spin_lock(&efivars->lock);
if (!efivars->ops->query_variable_info)
status = EFI_UNSUPPORTED;
else {
const struct efivar_operations *fops = efivars->ops;
status = fops->query_variable_info(attributes, &storage_size,
&remaining_size, &max_size);
}
spin_unlock(&efivars->lock);
if (status != EFI_SUCCESS) {
if (status != EFI_UNSUPPORTED)
return efi_status_to_err(status);
remaining_size = 65536;
}
if (datasize > remaining_size)
return -ENOSPC;
data = kmalloc(datasize, GFP_KERNEL);
if (!data)
return -ENOMEM;
if (copy_from_user(data, userbuf + sizeof(attributes), datasize)) {
bytes = -EFAULT;
goto out;
}
if (validate_var(&var->var, data, datasize) == false) {
bytes = -EINVAL;
goto out;
}
spin_lock(&efivars->lock);
status = efivars->ops->set_variable(var->var.VariableName,
&var->var.VendorGuid,
attributes, datasize,
data);
if (status != EFI_SUCCESS) {
spin_unlock(&efivars->lock);
kfree(data);
return efi_status_to_err(status);
}
bytes = count;
newdatasize = 0;
status = efivars->ops->get_variable(var->var.VariableName,
&var->var.VendorGuid,
NULL, &newdatasize,
NULL);
if (status == EFI_BUFFER_TOO_SMALL) {
spin_unlock(&efivars->lock);
mutex_lock(&inode->i_mutex);
i_size_write(inode, newdatasize + sizeof(attributes));
mutex_unlock(&inode->i_mutex);
} else if (status == EFI_NOT_FOUND) {
list_del(&var->list);
spin_unlock(&efivars->lock);
efivar_unregister(var);
drop_nlink(inode);
d_delete(file->f_dentry);
dput(file->f_dentry);
} else {
spin_unlock(&efivars->lock);
pr_warn("efivarfs: inconsistent EFI variable implementation? "
"status = %lx\n", status);
}
out:
kfree(data);
return bytes;
}
static ssize_t efivarfs_file_read(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct efivar_entry *var = file->private_data;
struct efivars *efivars = var->efivars;
efi_status_t status;
unsigned long datasize = 0;
u32 attributes;
void *data;
ssize_t size = 0;
spin_lock(&efivars->lock);
status = efivars->ops->get_variable(var->var.VariableName,
&var->var.VendorGuid,
&attributes, &datasize, NULL);
spin_unlock(&efivars->lock);
if (status != EFI_BUFFER_TOO_SMALL)
return efi_status_to_err(status);
data = kmalloc(datasize + sizeof(attributes), GFP_KERNEL);
if (!data)
return -ENOMEM;
spin_lock(&efivars->lock);
status = efivars->ops->get_variable(var->var.VariableName,
&var->var.VendorGuid,
&attributes, &datasize,
(data + sizeof(attributes)));
spin_unlock(&efivars->lock);
if (status != EFI_SUCCESS) {
size = efi_status_to_err(status);
goto out_free;
}
memcpy(data, &attributes, sizeof(attributes));
size = simple_read_from_buffer(userbuf, count, ppos,
data, datasize + sizeof(attributes));
out_free:
kfree(data);
return size;
}
static void efivarfs_evict_inode(struct inode *inode)
{
clear_inode(inode);
}
static struct inode *efivarfs_get_inode(struct super_block *sb,
const struct inode *dir, int mode, dev_t dev)
{
struct inode *inode = new_inode(sb);
if (inode) {
inode->i_ino = get_next_ino();
inode->i_mode = mode;
inode->i_atime = inode->i_mtime = inode->i_ctime = CURRENT_TIME;
switch (mode & S_IFMT) {
case S_IFREG:
inode->i_fop = &efivarfs_file_operations;
break;
case S_IFDIR:
inode->i_op = &efivarfs_dir_inode_operations;
inode->i_fop = &simple_dir_operations;
inc_nlink(inode);
break;
}
}
return inode;
}
static void efivarfs_hex_to_guid(const char *str, efi_guid_t *guid)
{
guid->b[0] = hex_to_bin(str[6]) << 4 | hex_to_bin(str[7]);
guid->b[1] = hex_to_bin(str[4]) << 4 | hex_to_bin(str[5]);
guid->b[2] = hex_to_bin(str[2]) << 4 | hex_to_bin(str[3]);
guid->b[3] = hex_to_bin(str[0]) << 4 | hex_to_bin(str[1]);
guid->b[4] = hex_to_bin(str[11]) << 4 | hex_to_bin(str[12]);
guid->b[5] = hex_to_bin(str[9]) << 4 | hex_to_bin(str[10]);
guid->b[6] = hex_to_bin(str[16]) << 4 | hex_to_bin(str[17]);
guid->b[7] = hex_to_bin(str[14]) << 4 | hex_to_bin(str[15]);
guid->b[8] = hex_to_bin(str[19]) << 4 | hex_to_bin(str[20]);
guid->b[9] = hex_to_bin(str[21]) << 4 | hex_to_bin(str[22]);
guid->b[10] = hex_to_bin(str[24]) << 4 | hex_to_bin(str[25]);
guid->b[11] = hex_to_bin(str[26]) << 4 | hex_to_bin(str[27]);
guid->b[12] = hex_to_bin(str[28]) << 4 | hex_to_bin(str[29]);
guid->b[13] = hex_to_bin(str[30]) << 4 | hex_to_bin(str[31]);
guid->b[14] = hex_to_bin(str[32]) << 4 | hex_to_bin(str[33]);
guid->b[15] = hex_to_bin(str[34]) << 4 | hex_to_bin(str[35]);
}
static int efivarfs_create(struct inode *dir, struct dentry *dentry,
umode_t mode, bool excl)
{
struct inode *inode;
struct efivars *efivars = &__efivars;
struct efivar_entry *var;
int namelen, i = 0, err = 0;
if (dentry->d_name.len < GUID_LEN + 2)
return -EINVAL;
inode = efivarfs_get_inode(dir->i_sb, dir, mode, 0);
if (!inode)
return -ENOMEM;
var = kzalloc(sizeof(struct efivar_entry), GFP_KERNEL);
if (!var) {
err = -ENOMEM;
goto out;
}
namelen = dentry->d_name.len - GUID_LEN - 1;
efivarfs_hex_to_guid(dentry->d_name.name + namelen + 1,
&var->var.VendorGuid);
for (i = 0; i < namelen; i++)
var->var.VariableName[i] = dentry->d_name.name[i];
var->var.VariableName[i] = '\0';
inode->i_private = var;
var->efivars = efivars;
var->kobj.kset = efivars->kset;
err = kobject_init_and_add(&var->kobj, &efivar_ktype, NULL, "%s",
dentry->d_name.name);
if (err)
goto out;
kobject_uevent(&var->kobj, KOBJ_ADD);
spin_lock(&efivars->lock);
list_add(&var->list, &efivars->list);
spin_unlock(&efivars->lock);
d_instantiate(dentry, inode);
dget(dentry);
out:
if (err) {
kfree(var);
iput(inode);
}
return err;
}
static int efivarfs_unlink(struct inode *dir, struct dentry *dentry)
{
struct efivar_entry *var = dentry->d_inode->i_private;
struct efivars *efivars = var->efivars;
efi_status_t status;
spin_lock(&efivars->lock);
status = efivars->ops->set_variable(var->var.VariableName,
&var->var.VendorGuid,
0, 0, NULL);
if (status == EFI_SUCCESS || status == EFI_NOT_FOUND) {
list_del(&var->list);
spin_unlock(&efivars->lock);
efivar_unregister(var);
drop_nlink(dentry->d_inode);
dput(dentry);
return 0;
}
spin_unlock(&efivars->lock);
return -EINVAL;
}
static int efivarfs_fill_super(struct super_block *sb, void *data, int silent)
{
struct inode *inode = NULL;
struct dentry *root;
struct efivar_entry *entry, *n;
struct efivars *efivars = &__efivars;
char *name;
efivarfs_sb = sb;
sb->s_maxbytes = MAX_LFS_FILESIZE;
sb->s_blocksize = PAGE_CACHE_SIZE;
sb->s_blocksize_bits = PAGE_CACHE_SHIFT;
sb->s_magic = EFIVARFS_MAGIC;
sb->s_op = &efivarfs_ops;
sb->s_time_gran = 1;
inode = efivarfs_get_inode(sb, NULL, S_IFDIR | 0755, 0);
if (!inode)
return -ENOMEM;
inode->i_op = &efivarfs_dir_inode_operations;
root = d_make_root(inode);
sb->s_root = root;
if (!root)
return -ENOMEM;
list_for_each_entry_safe(entry, n, &efivars->list, list) {
struct dentry *dentry, *root = efivarfs_sb->s_root;
unsigned long size = 0;
int len, i;
inode = NULL;
len = utf16_strlen(entry->var.VariableName);
name = kmalloc(len + 1 + GUID_LEN + 1, GFP_ATOMIC);
if (!name)
goto fail;
for (i = 0; i < len; i++)
name[i] = entry->var.VariableName[i] & 0xFF;
name[len] = '-';
efi_guid_unparse(&entry->var.VendorGuid, name + len + 1);
name[len+GUID_LEN+1] = '\0';
inode = efivarfs_get_inode(efivarfs_sb, root->d_inode,
S_IFREG | 0644, 0);
if (!inode)
goto fail_name;
dentry = d_alloc_name(root, name);
if (!dentry)
goto fail_inode;
kfree(name);
spin_lock(&efivars->lock);
efivars->ops->get_variable(entry->var.VariableName,
&entry->var.VendorGuid,
&entry->var.Attributes,
&size,
NULL);
spin_unlock(&efivars->lock);
mutex_lock(&inode->i_mutex);
inode->i_private = entry;
i_size_write(inode, size+4);
mutex_unlock(&inode->i_mutex);
d_add(dentry, inode);
}
return 0;
fail_inode:
iput(inode);
fail_name:
kfree(name);
fail:
return -ENOMEM;
}
static struct dentry *efivarfs_mount(struct file_system_type *fs_type,
int flags, const char *dev_name, void *data)
{
return mount_single(fs_type, flags, data, efivarfs_fill_super);
}
static void efivarfs_kill_sb(struct super_block *sb)
{
kill_litter_super(sb);
efivarfs_sb = NULL;
}
static int efi_pstore_open(struct pstore_info *psi)
{
struct efivars *efivars = psi->data;
spin_lock(&efivars->lock);
efivars->walk_entry = list_first_entry(&efivars->list,
struct efivar_entry, list);
return 0;
}
static int efi_pstore_close(struct pstore_info *psi)
{
struct efivars *efivars = psi->data;
spin_unlock(&efivars->lock);
return 0;
}
static ssize_t efi_pstore_read(u64 *id, enum pstore_type_id *type,
int *count, struct timespec *timespec,
char **buf, struct pstore_info *psi)
{
efi_guid_t vendor = LINUX_EFI_CRASH_GUID;
struct efivars *efivars = psi->data;
char name[DUMP_NAME_LEN];
int i;
int cnt;
unsigned int part, size;
unsigned long time;
while (&efivars->walk_entry->list != &efivars->list) {
if (!efi_guidcmp(efivars->walk_entry->var.VendorGuid,
vendor)) {
for (i = 0; i < DUMP_NAME_LEN; i++) {
name[i] = efivars->walk_entry->var.VariableName[i];
}
if (sscanf(name, "dump-type%u-%u-%d-%lu",
type, &part, &cnt, &time) == 4) {
*id = part;
*count = cnt;
timespec->tv_sec = time;
timespec->tv_nsec = 0;
} else if (sscanf(name, "dump-type%u-%u-%lu",
type, &part, &time) == 3) {
*id = part;
*count = 0;
timespec->tv_sec = time;
timespec->tv_nsec = 0;
} else {
efivars->walk_entry = list_entry(
efivars->walk_entry->list.next,
struct efivar_entry, list);
continue;
}
get_var_data_locked(efivars, &efivars->walk_entry->var);
size = efivars->walk_entry->var.DataSize;
*buf = kmalloc(size, GFP_KERNEL);
if (*buf == NULL)
return -ENOMEM;
memcpy(*buf, efivars->walk_entry->var.Data,
size);
efivars->walk_entry = list_entry(
efivars->walk_entry->list.next,
struct efivar_entry, list);
return size;
}
efivars->walk_entry = list_entry(efivars->walk_entry->list.next,
struct efivar_entry, list);
}
return 0;
}
static int efi_pstore_write(enum pstore_type_id type,
enum kmsg_dump_reason reason, u64 *id,
unsigned int part, int count, size_t size,
struct pstore_info *psi)
{
char name[DUMP_NAME_LEN];
efi_char16_t efi_name[DUMP_NAME_LEN];
efi_guid_t vendor = LINUX_EFI_CRASH_GUID;
struct efivars *efivars = psi->data;
int i, ret = 0;
u64 storage_space, remaining_space, max_variable_size;
efi_status_t status = EFI_NOT_FOUND;
spin_lock(&efivars->lock);
status = efivars->ops->query_variable_info(PSTORE_EFI_ATTRIBUTES,
&storage_space,
&remaining_space,
&max_variable_size);
if (status || remaining_space < size + DUMP_NAME_LEN * 2) {
spin_unlock(&efivars->lock);
*id = part;
return -ENOSPC;
}
sprintf(name, "dump-type%u-%u-%d-%lu", type, part, count,
get_seconds());
for (i = 0; i < DUMP_NAME_LEN; i++)
efi_name[i] = name[i];
efivars->ops->set_variable(efi_name, &vendor, PSTORE_EFI_ATTRIBUTES,
size, psi->buf);
spin_unlock(&efivars->lock);
if (size)
ret = efivar_create_sysfs_entry(efivars,
utf16_strsize(efi_name,
DUMP_NAME_LEN * 2),
efi_name, &vendor);
*id = part;
return ret;
}
static int efi_pstore_erase(enum pstore_type_id type, u64 id, int count,
struct timespec time, struct pstore_info *psi)
{
char name[DUMP_NAME_LEN];
efi_char16_t efi_name[DUMP_NAME_LEN];
char name_old[DUMP_NAME_LEN];
efi_char16_t efi_name_old[DUMP_NAME_LEN];
efi_guid_t vendor = LINUX_EFI_CRASH_GUID;
struct efivars *efivars = psi->data;
struct efivar_entry *entry, *found = NULL;
int i;
sprintf(name, "dump-type%u-%u-%d-%lu", type, (unsigned int)id, count,
time.tv_sec);
spin_lock(&efivars->lock);
for (i = 0; i < DUMP_NAME_LEN; i++)
efi_name[i] = name[i];
list_for_each_entry(entry, &efivars->list, list) {
get_var_data_locked(efivars, &entry->var);
if (efi_guidcmp(entry->var.VendorGuid, vendor))
continue;
if (utf16_strncmp(entry->var.VariableName, efi_name,
utf16_strlen(efi_name))) {
sprintf(name_old, "dump-type%u-%u-%lu", type,
(unsigned int)id, time.tv_sec);
for (i = 0; i < DUMP_NAME_LEN; i++)
efi_name_old[i] = name_old[i];
if (utf16_strncmp(entry->var.VariableName, efi_name_old,
utf16_strlen(efi_name_old)))
continue;
}
found = entry;
efivars->ops->set_variable(entry->var.VariableName,
&entry->var.VendorGuid,
PSTORE_EFI_ATTRIBUTES,
0, NULL);
break;
}
if (found)
list_del(&found->list);
spin_unlock(&efivars->lock);
if (found)
efivar_unregister(found);
return 0;
}
static int efi_pstore_open(struct pstore_info *psi)
{
return 0;
}
static int efi_pstore_close(struct pstore_info *psi)
{
return 0;
}
static ssize_t efi_pstore_read(u64 *id, enum pstore_type_id *type, int *count,
struct timespec *timespec,
char **buf, struct pstore_info *psi)
{
return -1;
}
static int efi_pstore_write(enum pstore_type_id type,
enum kmsg_dump_reason reason, u64 *id,
unsigned int part, int count, size_t size,
struct pstore_info *psi)
{
return 0;
}
static int efi_pstore_erase(enum pstore_type_id type, u64 id, int count,
struct timespec time, struct pstore_info *psi)
{
return 0;
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
if ((new_var->Attributes & ~EFI_VARIABLE_MASK) != 0 ||
validate_var(new_var, new_var->Data, new_var->DataSize) == false) {
printk(KERN_ERR "efivars: Malformed variable content\n");
return -EINVAL;
}
spin_lock(&efivars->lock);
list_for_each_entry_safe(search_efivar, n, &efivars->list, list) {
strsize1 = utf16_strsize(search_efivar->var.VariableName, 1024);
strsize2 = utf16_strsize(new_var->VariableName, 1024);
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
utf16_strsize(new_var->VariableName,
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
strsize1 = utf16_strsize(search_efivar->var.VariableName, 1024);
strsize2 = utf16_strsize(del_var->VariableName, 1024);
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
int i, short_name_size;
char *short_name;
struct efivar_entry *new_efivar;
short_name_size = variable_name_size / sizeof(efi_char16_t)
+ 1 + GUID_LEN + 1;
short_name = kzalloc(short_name_size, GFP_KERNEL);
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
kobject_put(efivars->kobject);
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
efivars->kobject = kobject_create_and_add("efivars", parent_kobj);
if (!efivars->kobject) {
pr_err("efivars: Subsystem registration failed.\n");
error = -ENOMEM;
kset_unregister(efivars->kset);
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
efivars->efi_pstore_info = efi_pstore_info;
efivars->efi_pstore_info.buf = kmalloc(4096, GFP_KERNEL);
if (efivars->efi_pstore_info.buf) {
efivars->efi_pstore_info.bufsize = 1024;
efivars->efi_pstore_info.data = efivars;
spin_lock_init(&efivars->efi_pstore_info.buf_lock);
pstore_register(&efivars->efi_pstore_info);
}
register_filesystem(&efivarfs_type);
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
if (!efi_enabled(EFI_RUNTIME_SERVICES))
return 0;
efi_kobj = kobject_create_and_add("efi", firmware_kobj);
if (!efi_kobj) {
printk(KERN_ERR "efivars: Firmware registration failed.\n");
return -ENOMEM;
}
ops.get_variable = efi.get_variable;
ops.set_variable = efi.set_variable;
ops.get_next_variable = efi.get_next_variable;
ops.query_variable_info = efi.query_variable_info;
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
if (efi_enabled(EFI_RUNTIME_SERVICES)) {
unregister_efivars(&__efivars);
kobject_put(efi_kobj);
}
}
