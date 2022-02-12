static int coda_ioctl_permission(struct inode *inode, int mask)
{
return (mask & MAY_EXEC) ? -EACCES : 0;
}
static long coda_pioctl(struct file *filp, unsigned int cmd,
unsigned long user_data)
{
struct path path;
int error;
struct PioctlData data;
struct inode *inode = filp->f_dentry->d_inode;
struct inode *target_inode = NULL;
struct coda_inode_info *cnp;
if (copy_from_user(&data, (void __user *)user_data, sizeof(data)))
return -EINVAL;
if (data.follow)
error = user_path(data.path, &path);
else
error = user_lpath(data.path, &path);
if (error)
return error;
target_inode = path.dentry->d_inode;
if (target_inode->i_sb != inode->i_sb) {
error = -EINVAL;
goto out;
}
cnp = ITOC(target_inode);
error = venus_pioctl(inode->i_sb, &(cnp->c_fid), cmd, &data);
out:
path_put(&path);
return error;
}
