static int mic_intr_test(struct seq_file *s, void *unused)
{
struct mic_driver *mdrv = s->private;
struct mic_device *mdev = &mdrv->mdev;
mic_send_intr(mdev, 0);
msleep(1000);
mic_send_intr(mdev, 1);
msleep(1000);
mic_send_intr(mdev, 2);
msleep(1000);
mic_send_intr(mdev, 3);
msleep(1000);
return 0;
}
static int mic_intr_test_open(struct inode *inode, struct file *file)
{
return single_open(file, mic_intr_test, inode->i_private);
}
static int mic_intr_test_release(struct inode *inode, struct file *file)
{
return single_release(inode, file);
}
void __init mic_create_card_debug_dir(struct mic_driver *mdrv)
{
struct dentry *d;
if (!mic_dbg)
return;
mdrv->dbg_dir = debugfs_create_dir(mdrv->name, mic_dbg);
if (!mdrv->dbg_dir) {
dev_err(mdrv->dev, "Cant create dbg_dir %s\n", mdrv->name);
return;
}
d = debugfs_create_file("intr_test", 0444, mdrv->dbg_dir,
mdrv, &intr_test_ops);
if (!d) {
dev_err(mdrv->dev,
"Cant create dbg intr_test %s\n", mdrv->name);
return;
}
}
void mic_delete_card_debug_dir(struct mic_driver *mdrv)
{
if (!mdrv->dbg_dir)
return;
debugfs_remove_recursive(mdrv->dbg_dir);
}
void __init mic_init_card_debugfs(void)
{
mic_dbg = debugfs_create_dir(KBUILD_MODNAME, NULL);
if (!mic_dbg)
pr_err("can't create debugfs dir\n");
}
void mic_exit_card_debugfs(void)
{
debugfs_remove(mic_dbg);
}
