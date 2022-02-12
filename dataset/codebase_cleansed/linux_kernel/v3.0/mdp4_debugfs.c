static int mdp4_offset_set(void *data, u64 val)
{
mdp4_debug_offset = (int)val;
return 0;
}
static int mdp4_offset_get(void *data, u64 *val)
{
*val = (u64)mdp4_debug_offset;
return 0;
}
static int mdp4_debugfs_release(struct inode *inode, struct file *file)
{
return 0;
}
static ssize_t mdp4_debugfs_write(
struct file *file,
const char __user *buff,
size_t count,
loff_t *ppos)
{
int cnt;
unsigned int data;
printk(KERN_INFO "%s: offset=%d count=%d *ppos=%d\n",
__func__, (int)mdp4_debug_offset, (int)count, (int)*ppos);
if (count > sizeof(mdp4_debug_buf))
return -EFAULT;
if (copy_from_user(mdp4_debug_buf, buff, count))
return -EFAULT;
mdp4_debug_buf[count] = 0;
cnt = sscanf(mdp4_debug_buf, "%x", &data);
if (cnt < 1) {
printk(KERN_ERR "%s: sscanf failed cnt=%d" , __func__, cnt);
return -EINVAL;
}
writel(&data, mdp4_base_addr + mdp4_debug_offset);
return 0;
}
static ssize_t mdp4_debugfs_read(
struct file *file,
char __user *buff,
size_t count,
loff_t *ppos)
{
int len = 0;
unsigned int data;
printk(KERN_INFO "%s: offset=%d count=%d *ppos=%d\n",
__func__, (int)mdp4_debug_offset, (int)count, (int)*ppos);
if (*ppos)
return 0;
data = readl(mdp4_base_addr + mdp4_debug_offset);
len = snprintf(mdp4_debug_buf, 4, "%x\n", data);
if (len > 0) {
if (len > count)
len = count;
if (copy_to_user(buff, mdp4_debug_buf, len))
return -EFAULT;
}
printk(KERN_INFO "%s: len=%d\n", __func__, len);
if (len < 0)
return 0;
*ppos += len;
return len;
}
int mdp4_debugfs_init(void)
{
struct dentry *dent = debugfs_create_dir("mdp4", NULL);
if (IS_ERR(dent)) {
printk(KERN_ERR "%s(%d): debugfs_create_dir fail, error %ld\n",
__FILE__, __LINE__, PTR_ERR(dent));
return -1;
}
if (debugfs_create_file("offset", 0644, dent, 0, &mdp4_offset_fops)
== NULL) {
printk(KERN_ERR "%s(%d): debugfs_create_file: offset fail\n",
__FILE__, __LINE__);
return -1;
}
if (debugfs_create_file("regs", 0644, dent, 0, &mdp4_debugfs_fops)
== NULL) {
printk(KERN_ERR "%s(%d): debugfs_create_file: regs fail\n",
__FILE__, __LINE__);
return -1;
}
mdp4_debug_offset = 0;
mdp4_base_addr = (ulong) msm_mdp_base;
return 0;
}
