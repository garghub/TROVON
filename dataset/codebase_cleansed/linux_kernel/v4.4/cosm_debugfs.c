static int cosm_log_buf_show(struct seq_file *s, void *unused)
{
void __iomem *log_buf_va;
int __iomem *log_buf_len_va;
struct cosm_device *cdev = s->private;
void *kva;
int size;
u64 aper_offset;
if (!cdev || !cdev->log_buf_addr || !cdev->log_buf_len)
goto done;
mutex_lock(&cdev->cosm_mutex);
switch (cdev->state) {
case MIC_BOOTING:
case MIC_ONLINE:
case MIC_SHUTTING_DOWN:
break;
default:
goto unlock;
}
aper_offset = (u64)cdev->log_buf_len - __START_KERNEL_map;
log_buf_len_va = cdev->hw_ops->aper(cdev)->va + aper_offset;
aper_offset = (u64)cdev->log_buf_addr - __START_KERNEL_map;
log_buf_va = cdev->hw_ops->aper(cdev)->va + aper_offset;
size = ioread32(log_buf_len_va);
kva = kmalloc(size, GFP_KERNEL);
if (!kva)
goto unlock;
memcpy_fromio(kva, log_buf_va, size);
seq_write(s, kva, size);
kfree(kva);
unlock:
mutex_unlock(&cdev->cosm_mutex);
done:
return 0;
}
static int cosm_log_buf_open(struct inode *inode, struct file *file)
{
return single_open(file, cosm_log_buf_show, inode->i_private);
}
static int cosm_force_reset_show(struct seq_file *s, void *pos)
{
struct cosm_device *cdev = s->private;
cosm_stop(cdev, true);
return 0;
}
static int cosm_force_reset_debug_open(struct inode *inode, struct file *file)
{
return single_open(file, cosm_force_reset_show, inode->i_private);
}
void cosm_create_debug_dir(struct cosm_device *cdev)
{
char name[16];
if (!cosm_dbg)
return;
scnprintf(name, sizeof(name), "mic%d", cdev->index);
cdev->dbg_dir = debugfs_create_dir(name, cosm_dbg);
if (!cdev->dbg_dir)
return;
debugfs_create_file("log_buf", 0444, cdev->dbg_dir, cdev, &log_buf_ops);
debugfs_create_file("force_reset", 0444, cdev->dbg_dir, cdev,
&force_reset_ops);
}
void cosm_delete_debug_dir(struct cosm_device *cdev)
{
if (!cdev->dbg_dir)
return;
debugfs_remove_recursive(cdev->dbg_dir);
}
void cosm_init_debugfs(void)
{
cosm_dbg = debugfs_create_dir(KBUILD_MODNAME, NULL);
if (!cosm_dbg)
pr_err("can't create debugfs dir\n");
}
void cosm_exit_debugfs(void)
{
debugfs_remove(cosm_dbg);
}
