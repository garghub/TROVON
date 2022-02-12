static ssize_t bin_dir(struct file *file,
void __user *oldval, size_t oldlen, void __user *newval, size_t newlen)
{
return -ENOTDIR;
}
static ssize_t bin_string(struct file *file,
void __user *oldval, size_t oldlen, void __user *newval, size_t newlen)
{
ssize_t result, copied = 0;
if (oldval && oldlen) {
char __user *lastp;
loff_t pos = 0;
int ch;
result = vfs_read(file, oldval, oldlen, &pos);
if (result < 0)
goto out;
copied = result;
lastp = oldval + copied - 1;
result = -EFAULT;
if (get_user(ch, lastp))
goto out;
if (ch == '\n') {
result = -EFAULT;
if (put_user('\0', lastp))
goto out;
copied -= 1;
}
}
if (newval && newlen) {
loff_t pos = 0;
result = vfs_write(file, newval, newlen, &pos);
if (result < 0)
goto out;
}
result = copied;
out:
return result;
}
static ssize_t bin_intvec(struct file *file,
void __user *oldval, size_t oldlen, void __user *newval, size_t newlen)
{
ssize_t copied = 0;
char *buffer;
ssize_t result;
result = -ENOMEM;
buffer = kmalloc(BUFSZ, GFP_KERNEL);
if (!buffer)
goto out;
if (oldval && oldlen) {
unsigned __user *vec = oldval;
size_t length = oldlen / sizeof(*vec);
char *str, *end;
int i;
result = kernel_read(file, 0, buffer, BUFSZ - 1);
if (result < 0)
goto out_kfree;
str = buffer;
end = str + result;
*end++ = '\0';
for (i = 0; i < length; i++) {
unsigned long value;
value = simple_strtoul(str, &str, 10);
while (isspace(*str))
str++;
result = -EFAULT;
if (put_user(value, vec + i))
goto out_kfree;
copied += sizeof(*vec);
if (!isdigit(*str))
break;
}
}
if (newval && newlen) {
unsigned __user *vec = newval;
size_t length = newlen / sizeof(*vec);
char *str, *end;
int i;
str = buffer;
end = str + BUFSZ;
for (i = 0; i < length; i++) {
unsigned long value;
result = -EFAULT;
if (get_user(value, vec + i))
goto out_kfree;
str += scnprintf(str, end - str, "%lu\t", value);
}
result = kernel_write(file, buffer, str - buffer, 0);
if (result < 0)
goto out_kfree;
}
result = copied;
out_kfree:
kfree(buffer);
out:
return result;
}
static ssize_t bin_ulongvec(struct file *file,
void __user *oldval, size_t oldlen, void __user *newval, size_t newlen)
{
ssize_t copied = 0;
char *buffer;
ssize_t result;
result = -ENOMEM;
buffer = kmalloc(BUFSZ, GFP_KERNEL);
if (!buffer)
goto out;
if (oldval && oldlen) {
unsigned long __user *vec = oldval;
size_t length = oldlen / sizeof(*vec);
char *str, *end;
int i;
result = kernel_read(file, 0, buffer, BUFSZ - 1);
if (result < 0)
goto out_kfree;
str = buffer;
end = str + result;
*end++ = '\0';
for (i = 0; i < length; i++) {
unsigned long value;
value = simple_strtoul(str, &str, 10);
while (isspace(*str))
str++;
result = -EFAULT;
if (put_user(value, vec + i))
goto out_kfree;
copied += sizeof(*vec);
if (!isdigit(*str))
break;
}
}
if (newval && newlen) {
unsigned long __user *vec = newval;
size_t length = newlen / sizeof(*vec);
char *str, *end;
int i;
str = buffer;
end = str + BUFSZ;
for (i = 0; i < length; i++) {
unsigned long value;
result = -EFAULT;
if (get_user(value, vec + i))
goto out_kfree;
str += scnprintf(str, end - str, "%lu\t", value);
}
result = kernel_write(file, buffer, str - buffer, 0);
if (result < 0)
goto out_kfree;
}
result = copied;
out_kfree:
kfree(buffer);
out:
return result;
}
static ssize_t bin_uuid(struct file *file,
void __user *oldval, size_t oldlen, void __user *newval, size_t newlen)
{
ssize_t result, copied = 0;
if (oldval && oldlen) {
char buf[UUID_STRING_LEN + 1];
uuid_be uuid;
result = kernel_read(file, 0, buf, sizeof(buf) - 1);
if (result < 0)
goto out;
buf[result] = '\0';
result = -EIO;
if (uuid_be_to_bin(buf, &uuid))
goto out;
if (oldlen > 16)
oldlen = 16;
result = -EFAULT;
if (copy_to_user(oldval, &uuid, oldlen))
goto out;
copied = oldlen;
}
result = copied;
out:
return result;
}
static ssize_t bin_dn_node_address(struct file *file,
void __user *oldval, size_t oldlen, void __user *newval, size_t newlen)
{
ssize_t result, copied = 0;
if (oldval && oldlen) {
char buf[15], *nodep;
unsigned long area, node;
__le16 dnaddr;
result = kernel_read(file, 0, buf, sizeof(buf) - 1);
if (result < 0)
goto out;
buf[result] = '\0';
result = -EIO;
nodep = strchr(buf, '.');
if (!nodep)
goto out;
++nodep;
area = simple_strtoul(buf, NULL, 10);
node = simple_strtoul(nodep, NULL, 10);
result = -EIO;
if ((area > 63)||(node > 1023))
goto out;
dnaddr = cpu_to_le16((area << 10) | node);
result = -EFAULT;
if (put_user(dnaddr, (__le16 __user *)oldval))
goto out;
copied = sizeof(dnaddr);
}
if (newval && newlen) {
__le16 dnaddr;
char buf[15];
int len;
result = -EINVAL;
if (newlen != sizeof(dnaddr))
goto out;
result = -EFAULT;
if (get_user(dnaddr, (__le16 __user *)newval))
goto out;
len = scnprintf(buf, sizeof(buf), "%hu.%hu",
le16_to_cpu(dnaddr) >> 10,
le16_to_cpu(dnaddr) & 0x3ff);
result = kernel_write(file, buf, len, 0);
if (result < 0)
goto out;
}
result = copied;
out:
return result;
}
static const struct bin_table *get_sysctl(const int *name, int nlen, char *path)
{
const struct bin_table *table = &bin_root_table[0];
int ctl_name;
memcpy(path, "sys/", 4);
path += 4;
repeat:
if (!nlen)
return ERR_PTR(-ENOTDIR);
ctl_name = *name;
name++;
nlen--;
for ( ; table->convert; table++) {
int len = 0;
if (!table->ctl_name) {
#ifdef CONFIG_NET
struct net *net = current->nsproxy->net_ns;
struct net_device *dev;
dev = dev_get_by_index(net, ctl_name);
if (dev) {
len = strlen(dev->name);
memcpy(path, dev->name, len);
dev_put(dev);
}
#endif
} else if (ctl_name == table->ctl_name) {
len = strlen(table->procname);
memcpy(path, table->procname, len);
}
if (len) {
path += len;
if (table->child) {
*path++ = '/';
table = table->child;
goto repeat;
}
*path = '\0';
return table;
}
}
return ERR_PTR(-ENOTDIR);
}
static char *sysctl_getname(const int *name, int nlen, const struct bin_table **tablep)
{
char *tmp, *result;
result = ERR_PTR(-ENOMEM);
tmp = __getname();
if (tmp) {
const struct bin_table *table = get_sysctl(name, nlen, tmp);
result = tmp;
*tablep = table;
if (IS_ERR(table)) {
__putname(tmp);
result = ERR_CAST(table);
}
}
return result;
}
static ssize_t binary_sysctl(const int *name, int nlen,
void __user *oldval, size_t oldlen, void __user *newval, size_t newlen)
{
const struct bin_table *table = NULL;
struct vfsmount *mnt;
struct file *file;
ssize_t result;
char *pathname;
int flags;
pathname = sysctl_getname(name, nlen, &table);
result = PTR_ERR(pathname);
if (IS_ERR(pathname))
goto out;
if (oldval && oldlen && newval && newlen) {
flags = O_RDWR;
} else if (newval && newlen) {
flags = O_WRONLY;
} else if (oldval && oldlen) {
flags = O_RDONLY;
} else {
result = 0;
goto out_putname;
}
mnt = task_active_pid_ns(current)->proc_mnt;
file = file_open_root(mnt->mnt_root, mnt, pathname, flags, 0);
result = PTR_ERR(file);
if (IS_ERR(file))
goto out_putname;
result = table->convert(file, oldval, oldlen, newval, newlen);
fput(file);
out_putname:
__putname(pathname);
out:
return result;
}
static ssize_t binary_sysctl(const int *name, int nlen,
void __user *oldval, size_t oldlen, void __user *newval, size_t newlen)
{
return -ENOSYS;
}
static void deprecated_sysctl_warning(const int *name, int nlen)
{
int i;
if (name[0] == CTL_KERN && name[1] == KERN_VERSION)
return;
if (printk_ratelimit()) {
printk(KERN_INFO
"warning: process `%s' used the deprecated sysctl "
"system call with ", current->comm);
for (i = 0; i < nlen; i++)
printk(KERN_CONT "%d.", name[i]);
printk(KERN_CONT "\n");
}
return;
}
static void warn_on_bintable(const int *name, int nlen)
{
int i;
u32 hash = FNV32_OFFSET;
for (i = 0; i < nlen; i++)
hash = (hash ^ name[i]) * FNV32_PRIME;
hash %= WARN_ONCE_HASH_SIZE;
if (__test_and_set_bit(hash, warn_once_bitmap))
return;
deprecated_sysctl_warning(name, nlen);
}
static ssize_t do_sysctl(int __user *args_name, int nlen,
void __user *oldval, size_t oldlen, void __user *newval, size_t newlen)
{
int name[CTL_MAXNAME];
int i;
if (nlen < 0 || nlen > CTL_MAXNAME)
return -ENOTDIR;
for (i = 0; i < nlen; i++)
if (get_user(name[i], args_name + i))
return -EFAULT;
warn_on_bintable(name, nlen);
return binary_sysctl(name, nlen, oldval, oldlen, newval, newlen);
}
