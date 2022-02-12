static int fnic_trace_ctrl_open(struct inode *inode, struct file *filp)
{
filp->private_data = inode->i_private;
return 0;
}
static ssize_t fnic_trace_ctrl_read(struct file *filp,
char __user *ubuf,
size_t cnt, loff_t *ppos)
{
char buf[64];
int len;
len = sprintf(buf, "%u\n", fnic_tracing_enabled);
return simple_read_from_buffer(ubuf, cnt, ppos, buf, len);
}
static ssize_t fnic_trace_ctrl_write(struct file *filp,
const char __user *ubuf,
size_t cnt, loff_t *ppos)
{
char buf[64];
unsigned long val;
int ret;
if (cnt >= sizeof(buf))
return -EINVAL;
if (copy_from_user(&buf, ubuf, cnt))
return -EFAULT;
buf[cnt] = 0;
ret = kstrtoul(buf, 10, &val);
if (ret < 0)
return ret;
fnic_tracing_enabled = val;
(*ppos)++;
return cnt;
}
static int fnic_trace_debugfs_open(struct inode *inode,
struct file *file)
{
fnic_dbgfs_t *fnic_dbg_prt;
fnic_dbg_prt = kzalloc(sizeof(fnic_dbgfs_t), GFP_KERNEL);
if (!fnic_dbg_prt)
return -ENOMEM;
fnic_dbg_prt->buffer = vmalloc((3*(trace_max_pages * PAGE_SIZE)));
if (!fnic_dbg_prt->buffer) {
kfree(fnic_dbg_prt);
return -ENOMEM;
}
memset((void *)fnic_dbg_prt->buffer, 0,
(3*(trace_max_pages * PAGE_SIZE)));
fnic_dbg_prt->buffer_len = fnic_get_trace_data(fnic_dbg_prt);
file->private_data = fnic_dbg_prt;
return 0;
}
static loff_t fnic_trace_debugfs_lseek(struct file *file,
loff_t offset,
int howto)
{
fnic_dbgfs_t *fnic_dbg_prt = file->private_data;
loff_t pos = -1;
switch (howto) {
case 0:
pos = offset;
break;
case 1:
pos = file->f_pos + offset;
break;
case 2:
pos = fnic_dbg_prt->buffer_len + offset;
}
return (pos < 0 || pos > fnic_dbg_prt->buffer_len) ?
-EINVAL : (file->f_pos = pos);
}
static ssize_t fnic_trace_debugfs_read(struct file *file,
char __user *ubuf,
size_t nbytes,
loff_t *pos)
{
fnic_dbgfs_t *fnic_dbg_prt = file->private_data;
int rc = 0;
rc = simple_read_from_buffer(ubuf, nbytes, pos,
fnic_dbg_prt->buffer,
fnic_dbg_prt->buffer_len);
return rc;
}
static int fnic_trace_debugfs_release(struct inode *inode,
struct file *file)
{
fnic_dbgfs_t *fnic_dbg_prt = file->private_data;
vfree(fnic_dbg_prt->buffer);
kfree(fnic_dbg_prt);
return 0;
}
int fnic_trace_debugfs_init(void)
{
int rc = -1;
fnic_trace_debugfs_root = debugfs_create_dir("fnic", NULL);
if (!fnic_trace_debugfs_root) {
printk(KERN_DEBUG "Cannot create debugfs root\n");
return rc;
}
fnic_trace_enable = debugfs_create_file("tracing_enable",
S_IFREG|S_IRUGO|S_IWUSR,
fnic_trace_debugfs_root,
NULL, &fnic_trace_ctrl_fops);
if (!fnic_trace_enable) {
printk(KERN_DEBUG "Cannot create trace_enable file"
" under debugfs");
return rc;
}
fnic_trace_debugfs_file = debugfs_create_file("trace",
S_IFREG|S_IRUGO|S_IWUSR,
fnic_trace_debugfs_root,
NULL,
&fnic_trace_debugfs_fops);
if (!fnic_trace_debugfs_file) {
printk(KERN_DEBUG "Cannot create trace file under debugfs");
return rc;
}
rc = 0;
return rc;
}
void fnic_trace_debugfs_terminate(void)
{
if (fnic_trace_debugfs_file) {
debugfs_remove(fnic_trace_debugfs_file);
fnic_trace_debugfs_file = NULL;
}
if (fnic_trace_enable) {
debugfs_remove(fnic_trace_enable);
fnic_trace_enable = NULL;
}
if (fnic_trace_debugfs_root) {
debugfs_remove(fnic_trace_debugfs_root);
fnic_trace_debugfs_root = NULL;
}
}
