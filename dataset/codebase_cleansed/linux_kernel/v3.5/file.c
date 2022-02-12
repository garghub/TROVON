static int ext4_release_file(struct inode *inode, struct file *filp)
{
if (ext4_test_inode_state(inode, EXT4_STATE_DA_ALLOC_CLOSE)) {
ext4_alloc_da_blocks(inode);
ext4_clear_inode_state(inode, EXT4_STATE_DA_ALLOC_CLOSE);
}
if ((filp->f_mode & FMODE_WRITE) &&
(atomic_read(&inode->i_writecount) == 1) &&
!EXT4_I(inode)->i_reserved_data_blocks)
{
down_write(&EXT4_I(inode)->i_data_sem);
ext4_discard_preallocations(inode);
up_write(&EXT4_I(inode)->i_data_sem);
}
if (is_dx(inode) && filp->private_data)
ext4_htree_free_dir_info(filp->private_data);
return 0;
}
static void ext4_aiodio_wait(struct inode *inode)
{
wait_queue_head_t *wq = ext4_ioend_wq(inode);
wait_event(*wq, (atomic_read(&EXT4_I(inode)->i_aiodio_unwritten) == 0));
}
static int
ext4_unaligned_aio(struct inode *inode, const struct iovec *iov,
unsigned long nr_segs, loff_t pos)
{
struct super_block *sb = inode->i_sb;
int blockmask = sb->s_blocksize - 1;
size_t count = iov_length(iov, nr_segs);
loff_t final_size = pos + count;
if (pos >= inode->i_size)
return 0;
if ((pos & blockmask) || (final_size & blockmask))
return 1;
return 0;
}
static ssize_t
ext4_file_write(struct kiocb *iocb, const struct iovec *iov,
unsigned long nr_segs, loff_t pos)
{
struct inode *inode = iocb->ki_filp->f_path.dentry->d_inode;
int unaligned_aio = 0;
ssize_t ret;
if (!(ext4_test_inode_flag(inode, EXT4_INODE_EXTENTS))) {
struct ext4_sb_info *sbi = EXT4_SB(inode->i_sb);
size_t length = iov_length(iov, nr_segs);
if ((pos > sbi->s_bitmap_maxbytes ||
(pos == sbi->s_bitmap_maxbytes && length > 0)))
return -EFBIG;
if (pos + length > sbi->s_bitmap_maxbytes) {
nr_segs = iov_shorten((struct iovec *)iov, nr_segs,
sbi->s_bitmap_maxbytes - pos);
}
} else if (unlikely((iocb->ki_filp->f_flags & O_DIRECT) &&
!is_sync_kiocb(iocb))) {
unaligned_aio = ext4_unaligned_aio(inode, iov, nr_segs, pos);
}
if (unaligned_aio) {
static unsigned long unaligned_warn_time;
if (printk_timed_ratelimit(&unaligned_warn_time, 60*60*24*HZ))
ext4_msg(inode->i_sb, KERN_WARNING,
"Unaligned AIO/DIO on inode %ld by %s; "
"performance will be poor.",
inode->i_ino, current->comm);
mutex_lock(ext4_aio_mutex(inode));
ext4_aiodio_wait(inode);
}
ret = generic_file_aio_write(iocb, iov, nr_segs, pos);
if (unaligned_aio)
mutex_unlock(ext4_aio_mutex(inode));
return ret;
}
static int ext4_file_mmap(struct file *file, struct vm_area_struct *vma)
{
struct address_space *mapping = file->f_mapping;
if (!mapping->a_ops->readpage)
return -ENOEXEC;
file_accessed(file);
vma->vm_ops = &ext4_file_vm_ops;
vma->vm_flags |= VM_CAN_NONLINEAR;
return 0;
}
static int ext4_file_open(struct inode * inode, struct file * filp)
{
struct super_block *sb = inode->i_sb;
struct ext4_sb_info *sbi = EXT4_SB(inode->i_sb);
struct ext4_inode_info *ei = EXT4_I(inode);
struct vfsmount *mnt = filp->f_path.mnt;
struct path path;
char buf[64], *cp;
if (unlikely(!(sbi->s_mount_flags & EXT4_MF_MNTDIR_SAMPLED) &&
!(sb->s_flags & MS_RDONLY))) {
sbi->s_mount_flags |= EXT4_MF_MNTDIR_SAMPLED;
memset(buf, 0, sizeof(buf));
path.mnt = mnt;
path.dentry = mnt->mnt_root;
cp = d_path(&path, buf, sizeof(buf));
if (!IS_ERR(cp)) {
strlcpy(sbi->s_es->s_last_mounted, cp,
sizeof(sbi->s_es->s_last_mounted));
ext4_mark_super_dirty(sb);
}
}
if (sbi->s_journal && !ei->jinode && (filp->f_mode & FMODE_WRITE)) {
struct jbd2_inode *jinode = jbd2_alloc_inode(GFP_KERNEL);
spin_lock(&inode->i_lock);
if (!ei->jinode) {
if (!jinode) {
spin_unlock(&inode->i_lock);
return -ENOMEM;
}
ei->jinode = jinode;
jbd2_journal_init_jbd_inode(ei->jinode, inode);
jinode = NULL;
}
spin_unlock(&inode->i_lock);
if (unlikely(jinode != NULL))
jbd2_free_inode(jinode);
}
return dquot_file_open(inode, filp);
}
loff_t ext4_llseek(struct file *file, loff_t offset, int origin)
{
struct inode *inode = file->f_mapping->host;
loff_t maxbytes;
if (!(ext4_test_inode_flag(inode, EXT4_INODE_EXTENTS)))
maxbytes = EXT4_SB(inode->i_sb)->s_bitmap_maxbytes;
else
maxbytes = inode->i_sb->s_maxbytes;
return generic_file_llseek_size(file, offset, origin, maxbytes);
}
