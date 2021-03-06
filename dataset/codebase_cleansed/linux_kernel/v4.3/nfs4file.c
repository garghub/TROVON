static int
nfs4_file_open(struct inode *inode, struct file *filp)
{
struct nfs_open_context *ctx;
struct dentry *dentry = filp->f_path.dentry;
struct dentry *parent = NULL;
struct inode *dir;
unsigned openflags = filp->f_flags;
struct iattr attr;
int err;
dprintk("NFS: open file(%pd2)\n", dentry);
err = nfs_check_flags(openflags);
if (err)
return err;
if ((openflags & O_ACCMODE) == 3)
openflags--;
openflags &= ~(O_CREAT|O_EXCL);
parent = dget_parent(dentry);
dir = d_inode(parent);
ctx = alloc_nfs_open_context(filp->f_path.dentry, filp->f_mode);
err = PTR_ERR(ctx);
if (IS_ERR(ctx))
goto out;
attr.ia_valid = ATTR_OPEN;
if (openflags & O_TRUNC) {
attr.ia_valid |= ATTR_SIZE;
attr.ia_size = 0;
nfs_sync_inode(inode);
}
inode = NFS_PROTO(dir)->open_context(dir, ctx, openflags, &attr, NULL);
if (IS_ERR(inode)) {
err = PTR_ERR(inode);
switch (err) {
case -EPERM:
case -EACCES:
case -EDQUOT:
case -ENOSPC:
case -EROFS:
goto out_put_ctx;
default:
goto out_drop;
}
}
if (inode != d_inode(dentry))
goto out_drop;
nfs_set_verifier(dentry, nfs_save_change_attribute(dir));
nfs_file_set_open_context(filp, ctx);
nfs_fscache_open_file(inode, filp);
err = 0;
out_put_ctx:
put_nfs_open_context(ctx);
out:
dput(parent);
return err;
out_drop:
d_drop(dentry);
err = -EOPENSTALE;
goto out_put_ctx;
}
static int
nfs4_file_flush(struct file *file, fl_owner_t id)
{
struct inode *inode = file_inode(file);
dprintk("NFS: flush(%pD2)\n", file);
nfs_inc_stats(inode, NFSIOS_VFSFLUSH);
if ((file->f_mode & FMODE_WRITE) == 0)
return 0;
if (!nfs4_delegation_flush_on_close(inode))
return filemap_fdatawrite(file->f_mapping);
return vfs_fsync(file, 0);
}
static int
nfs4_file_fsync(struct file *file, loff_t start, loff_t end, int datasync)
{
int ret;
struct inode *inode = file_inode(file);
trace_nfs_fsync_enter(inode);
nfs_inode_dio_wait(inode);
do {
ret = filemap_write_and_wait_range(inode->i_mapping, start, end);
if (ret != 0)
break;
mutex_lock(&inode->i_mutex);
ret = nfs_file_fsync_commit(file, start, end, datasync);
if (!ret)
ret = pnfs_sync_inode(inode, !!datasync);
mutex_unlock(&inode->i_mutex);
start = 0;
end = LLONG_MAX;
} while (ret == -EAGAIN);
trace_nfs_fsync_exit(inode, ret);
return ret;
}
static loff_t nfs4_file_llseek(struct file *filep, loff_t offset, int whence)
{
loff_t ret;
switch (whence) {
case SEEK_HOLE:
case SEEK_DATA:
ret = nfs42_proc_llseek(filep, offset, whence);
if (ret != -ENOTSUPP)
return ret;
default:
return nfs_file_llseek(filep, offset, whence);
}
}
static long nfs42_fallocate(struct file *filep, int mode, loff_t offset, loff_t len)
{
struct inode *inode = file_inode(filep);
long ret;
if (!S_ISREG(inode->i_mode))
return -EOPNOTSUPP;
if ((mode != 0) && (mode != (FALLOC_FL_PUNCH_HOLE | FALLOC_FL_KEEP_SIZE)))
return -EOPNOTSUPP;
ret = inode_newsize_ok(inode, offset + len);
if (ret < 0)
return ret;
if (mode & FALLOC_FL_PUNCH_HOLE)
return nfs42_proc_deallocate(filep, offset, len);
return nfs42_proc_allocate(filep, offset, len);
}
