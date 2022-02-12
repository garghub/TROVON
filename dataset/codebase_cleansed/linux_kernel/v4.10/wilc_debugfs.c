static ssize_t wilc_debug_level_read(struct file *file, char __user *userbuf, size_t count, loff_t *ppos)
{
char buf[128];
int res = 0;
if (*ppos > 0)
return 0;
res = scnprintf(buf, sizeof(buf), "Debug Level: %x\n", atomic_read(&WILC_DEBUG_LEVEL));
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
pr_info("%s, value (0x%08x) is out of range, stay previous flag (0x%08x)\n", __func__, flag, atomic_read(&WILC_DEBUG_LEVEL));
return -EINVAL;
}
atomic_set(&WILC_DEBUG_LEVEL, (int)flag);
if (flag == 0)
pr_info("Debug-level disabled\n");
else
pr_info("Debug-level enabled\n");
return count;
}
static int __init wilc_debugfs_init(void)
{
int i;
struct wilc_debugfs_info_t *info;
wilc_dir = debugfs_create_dir("wilc_wifi", NULL);
for (i = 0; i < ARRAY_SIZE(debugfs_info); i++) {
info = &debugfs_info[i];
debugfs_create_file(info->name,
info->perm,
wilc_dir,
&info->data,
&info->fops);
}
return 0;
}
static void __exit wilc_debugfs_remove(void)
{
debugfs_remove_recursive(wilc_dir);
}
