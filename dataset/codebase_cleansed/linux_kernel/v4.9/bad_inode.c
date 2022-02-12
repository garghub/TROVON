static int bad_file_open(struct inode *inode, struct file *filp)
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
static int bad_inode_rename2(struct inode *old_dir, struct dentry *old_dentry,
struct inode *new_dir, struct dentry *new_dentry,
unsigned int flags)
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
static ssize_t bad_inode_listxattr(struct dentry *dentry, char *buffer,
size_t buffer_size)
{
return -EIO;
}
void make_bad_inode(struct inode *inode)
{
remove_inode_hash(inode);
inode->i_mode = S_IFREG;
inode->i_atime = inode->i_mtime = inode->i_ctime =
current_time(inode);
inode->i_op = &bad_inode_ops;
inode->i_opflags &= ~IOP_XATTR;
inode->i_fop = &bad_file_ops;
}
bool is_bad_inode(struct inode *inode)
{
return (inode->i_op == &bad_inode_ops);
}
void iget_failed(struct inode *inode)
{
make_bad_inode(inode);
unlock_new_inode(inode);
iput(inode);
}
