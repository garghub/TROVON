static int
nfs4_file_open(struct inode *inode, struct file *filp)
{
struct nfs_open_context *ctx;
struct dentry *dentry = filp->f_path.dentry;
struct dentry *parent = NULL;
struct inode *dir;
unsigned openflags = filp->f_flags;
struct iattr attr;
int opened = 0;
int err;
dprintk("NFS: open file(%pd2)\n", dentry);
if ((openflags & O_ACCMODE) == 3)
openflags--;
openflags &= ~(O_CREAT|O_EXCL);
parent = dget_parent(dentry);
dir = parent->d_inode;
ctx = alloc_nfs_open_context(filp->f_path.dentry, filp->f_mode);
err = PTR_ERR(ctx);
if (IS_ERR(ctx))
goto out;
attr.ia_valid = ATTR_OPEN;
if (openflags & O_TRUNC) {
attr.ia_valid |= ATTR_SIZE;
attr.ia_size = 0;
nfs_wb_all(inode);
}
inode = NFS_PROTO(dir)->open_context(dir, ctx, openflags, &attr, &opened);
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
if (inode != dentry->d_inode)
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
nfs4_file_fsync(struct file *file, loff_t start, loff_t end, int datasync)
{
int ret;
struct inode *inode = file_inode(file);
do {
ret = filemap_write_and_wait_range(inode->i_mapping, start, end);
if (ret != 0)
break;
mutex_lock(&inode->i_mutex);
ret = nfs_file_fsync_commit(file, start, end, datasync);
if (!ret)
ret = pnfs_layoutcommit_inode(inode, true);
mutex_unlock(&inode->i_mutex);
start = 0;
end = LLONG_MAX;
} while (ret == -EAGAIN);
return ret;
}
