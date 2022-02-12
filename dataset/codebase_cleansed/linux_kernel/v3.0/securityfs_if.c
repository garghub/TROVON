static int tomoyo_open(struct inode *inode, struct file *file)
{
const int key = ((u8 *) file->f_path.dentry->d_inode->i_private)
- ((u8 *) NULL);
return tomoyo_open_control(key, file);
}
static int tomoyo_release(struct inode *inode, struct file *file)
{
return tomoyo_close_control(file);
}
static unsigned int tomoyo_poll(struct file *file, poll_table *wait)
{
return tomoyo_poll_control(file, wait);
}
static ssize_t tomoyo_read(struct file *file, char __user *buf, size_t count,
loff_t *ppos)
{
return tomoyo_read_control(file, buf, count);
}
static ssize_t tomoyo_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
return tomoyo_write_control(file, buf, count);
}
static void __init tomoyo_create_entry(const char *name, const mode_t mode,
struct dentry *parent, const u8 key)
{
securityfs_create_file(name, mode, parent, ((u8 *) NULL) + key,
&tomoyo_operations);
}
static int __init tomoyo_initerface_init(void)
{
struct dentry *tomoyo_dir;
if (current_cred()->security != &tomoyo_kernel_domain)
return 0;
tomoyo_dir = securityfs_create_dir("tomoyo", NULL);
tomoyo_create_entry("query", 0600, tomoyo_dir,
TOMOYO_QUERY);
tomoyo_create_entry("domain_policy", 0600, tomoyo_dir,
TOMOYO_DOMAINPOLICY);
tomoyo_create_entry("exception_policy", 0600, tomoyo_dir,
TOMOYO_EXCEPTIONPOLICY);
tomoyo_create_entry("self_domain", 0400, tomoyo_dir,
TOMOYO_SELFDOMAIN);
tomoyo_create_entry(".domain_status", 0600, tomoyo_dir,
TOMOYO_DOMAIN_STATUS);
tomoyo_create_entry(".process_status", 0600, tomoyo_dir,
TOMOYO_PROCESS_STATUS);
tomoyo_create_entry("meminfo", 0600, tomoyo_dir,
TOMOYO_MEMINFO);
tomoyo_create_entry("profile", 0600, tomoyo_dir,
TOMOYO_PROFILE);
tomoyo_create_entry("manager", 0600, tomoyo_dir,
TOMOYO_MANAGER);
tomoyo_create_entry("version", 0400, tomoyo_dir,
TOMOYO_VERSION);
return 0;
}
