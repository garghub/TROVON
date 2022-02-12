static char *aa_simple_write_to_buffer(int op, const char __user *userbuf,
size_t alloc_size, size_t copy_size,
loff_t *pos)
{
char *data;
BUG_ON(copy_size > alloc_size);
if (*pos != 0)
return ERR_PTR(-ESPIPE);
if (!aa_may_manage_policy(op))
return ERR_PTR(-EACCES);
data = kvmalloc(alloc_size);
if (data == NULL)
return ERR_PTR(-ENOMEM);
if (copy_from_user(data, userbuf, copy_size)) {
kvfree(data);
return ERR_PTR(-EFAULT);
}
return data;
}
static ssize_t profile_load(struct file *f, const char __user *buf, size_t size,
loff_t *pos)
{
char *data;
ssize_t error;
data = aa_simple_write_to_buffer(OP_PROF_LOAD, buf, size, size, pos);
error = PTR_ERR(data);
if (!IS_ERR(data)) {
error = aa_replace_profiles(data, size, PROF_ADD);
kvfree(data);
}
return error;
}
static ssize_t profile_replace(struct file *f, const char __user *buf,
size_t size, loff_t *pos)
{
char *data;
ssize_t error;
data = aa_simple_write_to_buffer(OP_PROF_REPL, buf, size, size, pos);
error = PTR_ERR(data);
if (!IS_ERR(data)) {
error = aa_replace_profiles(data, size, PROF_REPLACE);
kvfree(data);
}
return error;
}
static ssize_t profile_remove(struct file *f, const char __user *buf,
size_t size, loff_t *pos)
{
char *data;
ssize_t error;
data = aa_simple_write_to_buffer(OP_PROF_RM, buf, size + 1, size, pos);
error = PTR_ERR(data);
if (!IS_ERR(data)) {
data[size] = 0;
error = aa_remove_profiles(data, size);
kvfree(data);
}
return error;
}
static int aa_fs_seq_show(struct seq_file *seq, void *v)
{
struct aa_fs_entry *fs_file = seq->private;
if (!fs_file)
return 0;
switch (fs_file->v_type) {
case AA_FS_TYPE_BOOLEAN:
seq_printf(seq, "%s\n", fs_file->v.boolean ? "yes" : "no");
break;
case AA_FS_TYPE_STRING:
seq_printf(seq, "%s\n", fs_file->v.string);
break;
case AA_FS_TYPE_U64:
seq_printf(seq, "%#08lx\n", fs_file->v.u64);
break;
default:
break;
}
return 0;
}
static int aa_fs_seq_open(struct inode *inode, struct file *file)
{
return single_open(file, aa_fs_seq_show, inode->i_private);
}
static int __init aafs_create_file(struct aa_fs_entry *fs_file,
struct dentry *parent)
{
int error = 0;
fs_file->dentry = securityfs_create_file(fs_file->name,
S_IFREG | fs_file->mode,
parent, fs_file,
fs_file->file_ops);
if (IS_ERR(fs_file->dentry)) {
error = PTR_ERR(fs_file->dentry);
fs_file->dentry = NULL;
}
return error;
}
static int __init aafs_create_dir(struct aa_fs_entry *fs_dir,
struct dentry *parent)
{
int error;
struct aa_fs_entry *fs_file;
fs_dir->dentry = securityfs_create_dir(fs_dir->name, parent);
if (IS_ERR(fs_dir->dentry)) {
error = PTR_ERR(fs_dir->dentry);
fs_dir->dentry = NULL;
goto failed;
}
for (fs_file = fs_dir->v.files; fs_file->name; ++fs_file) {
if (fs_file->v_type == AA_FS_TYPE_DIR)
error = aafs_create_dir(fs_file, fs_dir->dentry);
else
error = aafs_create_file(fs_file, fs_dir->dentry);
if (error)
goto failed;
}
return 0;
failed:
return error;
}
static void __init aafs_remove_file(struct aa_fs_entry *fs_file)
{
if (!fs_file->dentry)
return;
securityfs_remove(fs_file->dentry);
fs_file->dentry = NULL;
}
static void __init aafs_remove_dir(struct aa_fs_entry *fs_dir)
{
struct aa_fs_entry *fs_file;
for (fs_file = fs_dir->v.files; fs_file->name; ++fs_file) {
if (fs_file->v_type == AA_FS_TYPE_DIR)
aafs_remove_dir(fs_file);
else
aafs_remove_file(fs_file);
}
aafs_remove_file(fs_dir);
}
void __init aa_destroy_aafs(void)
{
aafs_remove_dir(&aa_fs_entry);
}
static int __init aa_create_aafs(void)
{
int error;
if (!apparmor_initialized)
return 0;
if (aa_fs_entry.dentry) {
AA_ERROR("%s: AppArmor securityfs already exists\n", __func__);
return -EEXIST;
}
error = aafs_create_dir(&aa_fs_entry, NULL);
if (error)
goto error;
aa_info_message("AppArmor Filesystem Enabled");
return 0;
error:
aa_destroy_aafs();
AA_ERROR("Error creating AppArmor securityfs\n");
return error;
}
