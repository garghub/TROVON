static long do_sys_name_to_handle(struct path *path,
struct file_handle __user *ufh,
int __user *mnt_id)
{
long retval;
struct file_handle f_handle;
int handle_dwords, handle_bytes;
struct file_handle *handle = NULL;
if (!path->mnt->mnt_sb->s_export_op ||
!path->mnt->mnt_sb->s_export_op->fh_to_dentry)
return -EOPNOTSUPP;
if (copy_from_user(&f_handle, ufh, sizeof(struct file_handle)))
return -EFAULT;
if (f_handle.handle_bytes > MAX_HANDLE_SZ)
return -EINVAL;
handle = kmalloc(sizeof(struct file_handle) + f_handle.handle_bytes,
GFP_KERNEL);
if (!handle)
return -ENOMEM;
handle_dwords = f_handle.handle_bytes >> 2;
retval = exportfs_encode_fh(path->dentry,
(struct fid *)handle->f_handle,
&handle_dwords, 0);
handle->handle_type = retval;
handle_bytes = handle_dwords * sizeof(u32);
handle->handle_bytes = handle_bytes;
if ((handle->handle_bytes > f_handle.handle_bytes) ||
(retval == 255) || (retval == -ENOSPC)) {
handle_bytes = 0;
retval = -EOVERFLOW;
} else
retval = 0;
if (copy_to_user(mnt_id, &path->mnt->mnt_id, sizeof(*mnt_id)) ||
copy_to_user(ufh, handle,
sizeof(struct file_handle) + handle_bytes))
retval = -EFAULT;
kfree(handle);
return retval;
}
static struct vfsmount *get_vfsmount_from_fd(int fd)
{
struct path path;
if (fd == AT_FDCWD) {
struct fs_struct *fs = current->fs;
spin_lock(&fs->lock);
path = fs->pwd;
mntget(path.mnt);
spin_unlock(&fs->lock);
} else {
int fput_needed;
struct file *file = fget_light(fd, &fput_needed);
if (!file)
return ERR_PTR(-EBADF);
path = file->f_path;
mntget(path.mnt);
fput_light(file, fput_needed);
}
return path.mnt;
}
static int vfs_dentry_acceptable(void *context, struct dentry *dentry)
{
return 1;
}
static int do_handle_to_path(int mountdirfd, struct file_handle *handle,
struct path *path)
{
int retval = 0;
int handle_dwords;
path->mnt = get_vfsmount_from_fd(mountdirfd);
if (IS_ERR(path->mnt)) {
retval = PTR_ERR(path->mnt);
goto out_err;
}
handle_dwords = handle->handle_bytes >> 2;
path->dentry = exportfs_decode_fh(path->mnt,
(struct fid *)handle->f_handle,
handle_dwords, handle->handle_type,
vfs_dentry_acceptable, NULL);
if (IS_ERR(path->dentry)) {
retval = PTR_ERR(path->dentry);
goto out_mnt;
}
return 0;
out_mnt:
mntput(path->mnt);
out_err:
return retval;
}
static int handle_to_path(int mountdirfd, struct file_handle __user *ufh,
struct path *path)
{
int retval = 0;
struct file_handle f_handle;
struct file_handle *handle = NULL;
if (!capable(CAP_DAC_READ_SEARCH)) {
retval = -EPERM;
goto out_err;
}
if (copy_from_user(&f_handle, ufh, sizeof(struct file_handle))) {
retval = -EFAULT;
goto out_err;
}
if ((f_handle.handle_bytes > MAX_HANDLE_SZ) ||
(f_handle.handle_bytes == 0)) {
retval = -EINVAL;
goto out_err;
}
handle = kmalloc(sizeof(struct file_handle) + f_handle.handle_bytes,
GFP_KERNEL);
if (!handle) {
retval = -ENOMEM;
goto out_err;
}
if (copy_from_user(handle, ufh,
sizeof(struct file_handle) +
f_handle.handle_bytes)) {
retval = -EFAULT;
goto out_handle;
}
retval = do_handle_to_path(mountdirfd, handle, path);
out_handle:
kfree(handle);
out_err:
return retval;
}
long do_handle_open(int mountdirfd,
struct file_handle __user *ufh, int open_flag)
{
long retval = 0;
struct path path;
struct file *file;
int fd;
retval = handle_to_path(mountdirfd, ufh, &path);
if (retval)
return retval;
fd = get_unused_fd_flags(open_flag);
if (fd < 0) {
path_put(&path);
return fd;
}
file = file_open_root(path.dentry, path.mnt, "", open_flag);
if (IS_ERR(file)) {
put_unused_fd(fd);
retval = PTR_ERR(file);
} else {
retval = fd;
fsnotify_open(file);
fd_install(fd, file);
}
path_put(&path);
return retval;
}
