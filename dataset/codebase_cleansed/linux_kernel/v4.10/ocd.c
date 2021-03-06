void ocd_enable(struct task_struct *child)
{
u32 dc;
if (child)
pr_debug("ocd_enable: child=%s [%u]\n",
child->comm, child->pid);
else
pr_debug("ocd_enable (no child)\n");
if (!child || !test_and_set_tsk_thread_flag(child, TIF_DEBUG)) {
spin_lock(&ocd_lock);
ocd_count++;
dc = ocd_read(DC);
dc |= (1 << OCD_DC_MM_BIT) | (1 << OCD_DC_DBE_BIT);
ocd_write(DC, dc);
spin_unlock(&ocd_lock);
}
}
void ocd_disable(struct task_struct *child)
{
u32 dc;
if (!child)
pr_debug("ocd_disable (no child)\n");
else if (test_tsk_thread_flag(child, TIF_DEBUG))
pr_debug("ocd_disable: child=%s [%u]\n",
child->comm, child->pid);
if (!child || test_and_clear_tsk_thread_flag(child, TIF_DEBUG)) {
spin_lock(&ocd_lock);
ocd_count--;
WARN_ON(ocd_count < 0);
if (ocd_count <= 0) {
dc = ocd_read(DC);
dc &= ~((1 << OCD_DC_MM_BIT) | (1 << OCD_DC_DBE_BIT));
ocd_write(DC, dc);
}
spin_unlock(&ocd_lock);
}
}
static int ocd_DC_get(void *data, u64 *val)
{
*val = ocd_read(DC);
return 0;
}
static int ocd_DC_set(void *data, u64 val)
{
ocd_write(DC, val);
return 0;
}
static int ocd_DS_get(void *data, u64 *val)
{
*val = ocd_read(DS);
return 0;
}
static int ocd_count_get(void *data, u64 *val)
{
*val = ocd_count;
return 0;
}
static void ocd_debugfs_init(void)
{
struct dentry *root;
root = debugfs_create_dir("ocd", NULL);
if (IS_ERR(root) || !root)
goto err_root;
ocd_debugfs_root = root;
ocd_debugfs_DC = debugfs_create_file("DC", S_IRUSR | S_IWUSR,
root, NULL, &fops_DC);
if (!ocd_debugfs_DC)
goto err_DC;
ocd_debugfs_DS = debugfs_create_file("DS", S_IRUSR, root,
NULL, &fops_DS);
if (!ocd_debugfs_DS)
goto err_DS;
ocd_debugfs_count = debugfs_create_file("count", S_IRUSR, root,
NULL, &fops_count);
if (!ocd_debugfs_count)
goto err_count;
return;
err_count:
debugfs_remove(ocd_debugfs_DS);
err_DS:
debugfs_remove(ocd_debugfs_DC);
err_DC:
debugfs_remove(ocd_debugfs_root);
err_root:
printk(KERN_WARNING "OCD: Failed to create debugfs entries\n");
}
static inline void ocd_debugfs_init(void)
{
}
static int __init ocd_init(void)
{
spin_lock_init(&ocd_lock);
ocd_debugfs_init();
return 0;
}
