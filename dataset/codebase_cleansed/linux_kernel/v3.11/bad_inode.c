static loff_t bad_file_llseek(struct file *file, loff_t offset, int whence)
{
return -EIO;
}
static ssize_t bad_file_read(struct file *filp, char __user *buf,
size_t size, loff_t *ppos)
{
return -EIO;
}
static ssize_t bad_file_write(struct file *filp, const char __user *buf,
size_t siz, loff_t *ppos)
{
return -EIO;
}
static ssize_t bad_file_aio_read(struct kiocb *iocb, const struct iovec *iov,
unsigned long nr_segs, loff_t pos)
{
return -EIO;
}
static ssize_t bad_file_aio_write(struct kiocb *iocb, const struct iovec *iov,
unsigned long nr_segs, loff_t pos)
{
return -EIO;
}
static int bad_file_readdir(struct file *file, struct dir_context *ctx)
{
return -EIO;
}
static unsigned int bad_file_poll(struct file *filp, poll_table *wait)
{
return POLLERR;
}
static long bad_file_unlocked_ioctl(struct file *file, unsigned cmd,
unsigned long arg)
{
return -EIO;
}
static long bad_file_compat_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
return -EIO;
}
static int bad_file_mmap(struct file *file, struct vm_area_struct *vma)
{
return -EIO;
}
static int bad_file_open(struct inode *inode, struct file *filp)
{
return -EIO;
}
static int bad_file_flush(struct file *file, fl_owner_t id)
{
return -EIO;
}
static int bad_file_release(struct inode *inode, struct file *filp)
{
return -EIO;
}
static int bad_file_fsync(struct file *file, loff_t start, loff_t end,
int datasync)
{
return -EIO;
}
static int bad_file_aio_fsync(struct kiocb *iocb, int datasync)
{
return -EIO;
}
static int bad_file_fasync(int fd, struct file *filp, int on)
{
return -EIO;
}
static int bad_file_lock(struct file *file, int cmd, struct file_lock *fl)
{
return -EIO;
}
static ssize_t bad_file_sendpage(struct file *file, struct page *page,
int off, size_t len, loff_t *pos, int more)
{
return -EIO;
}
static unsigned long bad_file_get_unmapped_area(struct file *file,
unsigned long addr, unsigned long len,
unsigned long pgoff, unsigned long flags)
{
return -EIO;
}
static int bad_file_check_flags(int flags)
{
return -EIO;
}
static int bad_file_flock(struct file *filp, int cmd, struct file_lock *fl)
{
return -EIO;
}
static ssize_t bad_file_splice_write(struct pipe_inode_info *pipe,
struct file *out, loff_t *ppos, size_t len,
unsigned int flags)
{
return -EIO;
}
static ssize_t bad_file_splice_read(struct file *in, loff_t *ppos,
struct pipe_inode_info *pipe, size_t len,
unsigned int flags)
{
return -EIO;
}
static int bad_inode_create (struct inode *dir, struct dentry *dentry,
umode_t mode, bool excl)
{
return -EIO;
}
static struct dentry *bad_inode_lookup(struct inode *dir,
struct dentry *dentry, unsigned int flags)
{
return ERR_PTR(-EIO);
}
static int bad_inode_link (struct dentry *old_dentry, struct inode *dir,
struct dentry *dentry)
{
return -EIO;
}
static int bad_inode_unlink(struct inode *dir, struct dentry *dentry)
{
return -EIO;
}
static int bad_inode_symlink (struct inode *dir, struct dentry *dentry,
const char *symname)
{
return -EIO;
}
static int bad_inode_mkdir(struct inode *dir, struct dentry *dentry,
umode_t mode)
{
return -EIO;
}
static int bad_inode_rmdir (struct inode *dir, struct dentry *dentry)
{
return -EIO;
}
static int bad_inode_mknod (struct inode *dir, struct dentry *dentry,
umode_t mode, dev_t rdev)
{
return -EIO;
}
static int bad_inode_rename (struct inode *old_dir, struct dentry *old_dentry,
struct inode *new_dir, struct dentry *new_dentry)
{
return -EIO;
}
static int bad_inode_readlink(struct dentry *dentry, char __user *buffer,
int buflen)
{
return -EIO;
}
static int bad_inode_permission(struct inode *inode, int mask)
{
return -EIO;
}
static int bad_inode_getattr(struct vfsmount *mnt, struct dentry *dentry,
struct kstat *stat)
{
return -EIO;
}
static int bad_inode_setattr(struct dentry *direntry, struct iattr *attrs)
{
return -EIO;
}
static int bad_inode_setxattr(struct dentry *dentry, const char *name,
const void *value, size_t size, int flags)
{
return -EIO;
}
static ssize_t bad_inode_getxattr(struct dentry *dentry, const char *name,
void *buffer, size_t size)
{
return -EIO;
}
static ssize_t bad_inode_listxattr(struct dentry *dentry, char *buffer,
size_t buffer_size)
{
return -EIO;
}
static int bad_inode_removexattr(struct dentry *dentry, const char *name)
{
return -EIO;
}
void make_bad_inode(struct inode *inode)
{
remove_inode_hash(inode);
inode->i_mode = S_IFREG;
inode->i_atime = inode->i_mtime = inode->i_ctime =
current_fs_time(inode->i_sb);
inode->i_op = &bad_inode_ops;
inode->i_fop = &bad_file_ops;
}
int is_bad_inode(struct inode *inode)
{
return (inode->i_op == &bad_inode_ops);
}
void iget_failed(struct inode *inode)
{
make_bad_inode(inode);
unlock_new_inode(inode);
iput(inode);
}
