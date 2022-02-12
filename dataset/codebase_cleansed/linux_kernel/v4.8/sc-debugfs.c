static ssize_t sc_prefetch_read(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
bool enabled = bc_prefetch_is_enabled();
char buf[3];
buf[0] = enabled ? 'Y' : 'N';
buf[1] = '\n';
buf[2] = 0;
return simple_read_from_buffer(user_buf, count, ppos, buf, 2);
}
static ssize_t sc_prefetch_write(struct file *file,
const char __user *user_buf,
size_t count, loff_t *ppos)
{
char buf[32];
ssize_t buf_size;
bool enabled;
int err;
buf_size = min(count, sizeof(buf) - 1);
if (copy_from_user(buf, user_buf, buf_size))
return -EFAULT;
buf[buf_size] = '\0';
err = strtobool(buf, &enabled);
if (err)
return err;
if (enabled)
bc_prefetch_enable();
else
bc_prefetch_disable();
return count;
}
static int __init sc_debugfs_init(void)
{
struct dentry *dir, *file;
if (!mips_debugfs_dir)
return -ENODEV;
dir = debugfs_create_dir("l2cache", mips_debugfs_dir);
if (IS_ERR(dir))
return PTR_ERR(dir);
file = debugfs_create_file("prefetch", S_IRUGO | S_IWUSR, dir,
NULL, &sc_prefetch_fops);
if (!file)
return -ENOMEM;
return 0;
}
