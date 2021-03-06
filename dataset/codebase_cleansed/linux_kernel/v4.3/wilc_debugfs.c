static ssize_t wilc_debug_level_read(struct file *file, char __user *userbuf, size_t count, loff_t *ppos)
{
char buf[128];
int res = 0;
if (*ppos > 0)
return 0;
res = scnprintf(buf, sizeof(buf), "Debug Level: %x\n", atomic_read(&DEBUG_LEVEL));
return simple_read_from_buffer(userbuf, count, ppos, buf, res);
}
static ssize_t wilc_debug_level_write(struct file *filp, const char __user *buf,
size_t count, loff_t *ppos)
{
int flag = 0;
int ret;
ret = kstrtouint_from_user(buf, count, 16, &flag);
if (ret)
return ret;
if (flag > DBG_LEVEL_ALL) {
printk("%s, value (0x%08x) is out of range, stay previous flag (0x%08x)\n", __func__, flag, atomic_read(&DEBUG_LEVEL));
return -EINVAL;
}
atomic_set(&DEBUG_LEVEL, (int)flag);
if (flag == 0)
printk("Debug-level disabled\n");
else
printk("Debug-level enabled\n");
return count;
}
static ssize_t wilc_debug_region_read(struct file *file, char __user *userbuf, size_t count, loff_t *ppos)
{
char buf[128];
int res = 0;
if (*ppos > 0)
return 0;
res = scnprintf(buf, sizeof(buf), "Debug region: %x\n", atomic_read(&REGION));
return simple_read_from_buffer(userbuf, count, ppos, buf, res);
}
static ssize_t wilc_debug_region_write(struct file *filp, const char *buf, size_t count, loff_t *ppos)
{
char buffer[128] = {};
int flag;
if (count > sizeof(buffer))
return -EINVAL;
if (copy_from_user(buffer, buf, count)) {
return -EFAULT;
}
flag = buffer[0] - '0';
if (flag > DBG_REGION_ALL) {
printk("%s, value (0x%08x) is out of range, stay previous flag (0x%08x)\n", __func__, flag, atomic_read(&REGION));
return -EFAULT;
}
atomic_set(&REGION, (int)flag);
printk("new debug-region is %x\n", atomic_read(&REGION));
return count;
}
int wilc_debugfs_init(void)
{
int i;
struct dentry *debugfs_files;
struct wilc_debugfs_info_t *info;
wilc_dir = debugfs_create_dir("wilc_wifi", NULL);
if (wilc_dir == ERR_PTR(-ENODEV)) {
printk("ERR, kernel has built without debugfs support\n");
return 0;
}
if (!wilc_dir) {
printk("ERR, debugfs create dir\n");
return -1;
}
for (i = 0; i < ARRAY_SIZE(debugfs_info); i++) {
info = &debugfs_info[i];
debugfs_files = debugfs_create_file(info->name,
info->perm,
wilc_dir,
&info->data,
&info->fops);
if (!debugfs_files) {
printk("ERR fail to create the debugfs file, %s\n", info->name);
debugfs_remove_recursive(wilc_dir);
return -1;
}
}
return 0;
}
void wilc_debugfs_remove(void)
{
debugfs_remove_recursive(wilc_dir);
}
