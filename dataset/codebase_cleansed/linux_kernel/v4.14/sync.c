static int __sync_filesystem(struct super_block *sb, int wait)
{
if (wait)
sync_inodes_sb(sb);
else
writeback_inodes_sb(sb, WB_REASON_SYNC);
if (sb->s_op->sync_fs)
sb->s_op->sync_fs(sb, wait);
return __sync_blockdev(sb->s_bdev, wait);
}
int sync_filesystem(struct super_block *sb)
{
int ret;
WARN_ON(!rwsem_is_locked(&sb->s_umount));
if (sb_rdonly(sb))
return 0;
ret = __sync_filesystem(sb, 0);
if (ret < 0)
return ret;
return __sync_filesystem(sb, 1);
}
static void sync_inodes_one_sb(struct super_block *sb, void *arg)
{
if (!sb_rdonly(sb))
sync_inodes_sb(sb);
}
static void sync_fs_one_sb(struct super_block *sb, void *arg)
{
if (!sb_rdonly(sb) && sb->s_op->sync_fs)
sb->s_op->sync_fs(sb, *(int *)arg);
}
static void fdatawrite_one_bdev(struct block_device *bdev, void *arg)
{
filemap_fdatawrite(bdev->bd_inode->i_mapping);
}
static void fdatawait_one_bdev(struct block_device *bdev, void *arg)
{
filemap_fdatawait_keep_errors(bdev->bd_inode->i_mapping);
}
static void do_sync_work(struct work_struct *work)
{
int nowait = 0;
iterate_supers(sync_inodes_one_sb, &nowait);
iterate_supers(sync_fs_one_sb, &nowait);
iterate_bdevs(fdatawrite_one_bdev, NULL);
iterate_supers(sync_inodes_one_sb, &nowait);
iterate_supers(sync_fs_one_sb, &nowait);
iterate_bdevs(fdatawrite_one_bdev, NULL);
printk("Emergency Sync complete\n");
kfree(work);
}
void emergency_sync(void)
{
struct work_struct *work;
work = kmalloc(sizeof(*work), GFP_ATOMIC);
if (work) {
INIT_WORK(work, do_sync_work);
schedule_work(work);
}
}
int vfs_fsync_range(struct file *file, loff_t start, loff_t end, int datasync)
{
struct inode *inode = file->f_mapping->host;
if (!file->f_op->fsync)
return -EINVAL;
if (!datasync && (inode->i_state & I_DIRTY_TIME)) {
spin_lock(&inode->i_lock);
inode->i_state &= ~I_DIRTY_TIME;
spin_unlock(&inode->i_lock);
mark_inode_dirty_sync(inode);
}
return file->f_op->fsync(file, start, end, datasync);
}
int vfs_fsync(struct file *file, int datasync)
{
return vfs_fsync_range(file, 0, LLONG_MAX, datasync);
}
static int do_fsync(unsigned int fd, int datasync)
{
struct fd f = fdget(fd);
int ret = -EBADF;
if (f.file) {
ret = vfs_fsync(f.file, datasync);
fdput(f);
}
return ret;
}
