struct file_system_type *get_filesystem(struct file_system_type *fs)
{
__module_get(fs->owner);
return fs;
}
void put_filesystem(struct file_system_type *fs)
{
module_put(fs->owner);
}
static struct file_system_type **find_filesystem(const char *name, unsigned len)
{
struct file_system_type **p;
for (p = &file_systems; *p; p = &(*p)->next)
if (strncmp((*p)->name, name, len) == 0 &&
!(*p)->name[len])
break;
return p;
}
int register_filesystem(struct file_system_type * fs)
{
int res = 0;
struct file_system_type ** p;
BUG_ON(strchr(fs->name, '.'));
if (fs->next)
return -EBUSY;
write_lock(&file_systems_lock);
p = find_filesystem(fs->name, strlen(fs->name));
if (*p)
res = -EBUSY;
else
*p = fs;
write_unlock(&file_systems_lock);
return res;
}
int unregister_filesystem(struct file_system_type * fs)
{
struct file_system_type ** tmp;
write_lock(&file_systems_lock);
tmp = &file_systems;
while (*tmp) {
if (fs == *tmp) {
*tmp = fs->next;
fs->next = NULL;
write_unlock(&file_systems_lock);
synchronize_rcu();
return 0;
}
tmp = &(*tmp)->next;
}
write_unlock(&file_systems_lock);
return -EINVAL;
}
static int fs_index(const char __user * __name)
{
struct file_system_type * tmp;
struct filename *name;
int err, index;
name = getname(__name);
err = PTR_ERR(name);
if (IS_ERR(name))
return err;
err = -EINVAL;
read_lock(&file_systems_lock);
for (tmp=file_systems, index=0 ; tmp ; tmp=tmp->next, index++) {
if (strcmp(tmp->name, name->name) == 0) {
err = index;
break;
}
}
read_unlock(&file_systems_lock);
putname(name);
return err;
}
static int fs_name(unsigned int index, char __user * buf)
{
struct file_system_type * tmp;
int len, res;
read_lock(&file_systems_lock);
for (tmp = file_systems; tmp; tmp = tmp->next, index--)
if (index <= 0 && try_module_get(tmp->owner))
break;
read_unlock(&file_systems_lock);
if (!tmp)
return -EINVAL;
len = strlen(tmp->name) + 1;
res = copy_to_user(buf, tmp->name, len) ? -EFAULT : 0;
put_filesystem(tmp);
return res;
}
static int fs_maxindex(void)
{
struct file_system_type * tmp;
int index;
read_lock(&file_systems_lock);
for (tmp = file_systems, index = 0 ; tmp ; tmp = tmp->next, index++)
;
read_unlock(&file_systems_lock);
return index;
}
int __init get_filesystem_list(char *buf)
{
int len = 0;
struct file_system_type * tmp;
read_lock(&file_systems_lock);
tmp = file_systems;
while (tmp && len < PAGE_SIZE - 80) {
len += sprintf(buf+len, "%s\t%s\n",
(tmp->fs_flags & FS_REQUIRES_DEV) ? "" : "nodev",
tmp->name);
tmp = tmp->next;
}
read_unlock(&file_systems_lock);
return len;
}
static int filesystems_proc_show(struct seq_file *m, void *v)
{
struct file_system_type * tmp;
read_lock(&file_systems_lock);
tmp = file_systems;
while (tmp) {
seq_printf(m, "%s\t%s\n",
(tmp->fs_flags & FS_REQUIRES_DEV) ? "" : "nodev",
tmp->name);
tmp = tmp->next;
}
read_unlock(&file_systems_lock);
return 0;
}
static int filesystems_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, filesystems_proc_show, NULL);
}
static int __init proc_filesystems_init(void)
{
proc_create("filesystems", 0, NULL, &filesystems_proc_fops);
return 0;
}
static struct file_system_type *__get_fs_type(const char *name, int len)
{
struct file_system_type *fs;
read_lock(&file_systems_lock);
fs = *(find_filesystem(name, len));
if (fs && !try_module_get(fs->owner))
fs = NULL;
read_unlock(&file_systems_lock);
return fs;
}
struct file_system_type *get_fs_type(const char *name)
{
struct file_system_type *fs;
const char *dot = strchr(name, '.');
int len = dot ? dot - name : strlen(name);
fs = __get_fs_type(name, len);
if (!fs && (request_module("fs-%.*s", len, name) == 0)) {
fs = __get_fs_type(name, len);
WARN_ONCE(!fs, "request_module fs-%.*s succeeded, but still no fs?\n", len, name);
}
if (dot && fs && !(fs->fs_flags & FS_HAS_SUBTYPE)) {
put_filesystem(fs);
fs = NULL;
}
return fs;
}
