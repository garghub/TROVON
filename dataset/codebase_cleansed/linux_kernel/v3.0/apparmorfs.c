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
static void __init aafs_remove(const char *name)
{
struct dentry *dentry;
dentry = lookup_one_len(name, aa_fs_dentry, strlen(name));
if (!IS_ERR(dentry)) {
securityfs_remove(dentry);
dput(dentry);
}
}
static int __init aafs_create(const char *name, int mask,
const struct file_operations *fops)
{
struct dentry *dentry;
dentry = securityfs_create_file(name, S_IFREG | mask, aa_fs_dentry,
NULL, fops);
return IS_ERR(dentry) ? PTR_ERR(dentry) : 0;
}
void __init aa_destroy_aafs(void)
{
if (aa_fs_dentry) {
aafs_remove(".remove");
aafs_remove(".replace");
aafs_remove(".load");
securityfs_remove(aa_fs_dentry);
aa_fs_dentry = NULL;
}
}
int __init aa_create_aafs(void)
{
int error;
if (!apparmor_initialized)
return 0;
if (aa_fs_dentry) {
AA_ERROR("%s: AppArmor securityfs already exists\n", __func__);
return -EEXIST;
}
aa_fs_dentry = securityfs_create_dir("apparmor", NULL);
if (IS_ERR(aa_fs_dentry)) {
error = PTR_ERR(aa_fs_dentry);
aa_fs_dentry = NULL;
goto error;
}
error = aafs_create(".load", 0640, &aa_fs_profile_load);
if (error)
goto error;
error = aafs_create(".replace", 0640, &aa_fs_profile_replace);
if (error)
goto error;
error = aafs_create(".remove", 0640, &aa_fs_profile_remove);
if (error)
goto error;
aa_info_message("AppArmor Filesystem Enabled");
return 0;
error:
aa_destroy_aafs();
AA_ERROR("Error creating AppArmor securityfs\n");
return error;
}
