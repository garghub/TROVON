static bool nsec_valid(long nsec)
{
if (nsec == UTIME_OMIT || nsec == UTIME_NOW)
return true;
return nsec >= 0 && nsec <= 999999999;
}
static int utimes_common(struct path *path, struct timespec *times)
{
int error;
struct iattr newattrs;
struct inode *inode = path->dentry->d_inode;
error = mnt_want_write(path->mnt);
if (error)
goto out;
if (times && times[0].tv_nsec == UTIME_NOW &&
times[1].tv_nsec == UTIME_NOW)
times = NULL;
newattrs.ia_valid = ATTR_CTIME | ATTR_MTIME | ATTR_ATIME;
if (times) {
if (times[0].tv_nsec == UTIME_OMIT)
newattrs.ia_valid &= ~ATTR_ATIME;
else if (times[0].tv_nsec != UTIME_NOW) {
newattrs.ia_atime.tv_sec = times[0].tv_sec;
newattrs.ia_atime.tv_nsec = times[0].tv_nsec;
newattrs.ia_valid |= ATTR_ATIME_SET;
}
if (times[1].tv_nsec == UTIME_OMIT)
newattrs.ia_valid &= ~ATTR_MTIME;
else if (times[1].tv_nsec != UTIME_NOW) {
newattrs.ia_mtime.tv_sec = times[1].tv_sec;
newattrs.ia_mtime.tv_nsec = times[1].tv_nsec;
newattrs.ia_valid |= ATTR_MTIME_SET;
}
newattrs.ia_valid |= ATTR_TIMES_SET;
} else {
error = -EACCES;
if (IS_IMMUTABLE(inode))
goto mnt_drop_write_and_out;
if (!inode_owner_or_capable(inode)) {
error = inode_permission(inode, MAY_WRITE);
if (error)
goto mnt_drop_write_and_out;
}
}
mutex_lock(&inode->i_mutex);
error = notify_change(path->dentry, &newattrs);
mutex_unlock(&inode->i_mutex);
mnt_drop_write_and_out:
mnt_drop_write(path->mnt);
out:
return error;
}
long do_utimes(int dfd, const char __user *filename, struct timespec *times,
int flags)
{
int error = -EINVAL;
if (times && (!nsec_valid(times[0].tv_nsec) ||
!nsec_valid(times[1].tv_nsec))) {
goto out;
}
if (flags & ~AT_SYMLINK_NOFOLLOW)
goto out;
if (filename == NULL && dfd != AT_FDCWD) {
struct file *file;
if (flags & AT_SYMLINK_NOFOLLOW)
goto out;
file = fget(dfd);
error = -EBADF;
if (!file)
goto out;
error = utimes_common(&file->f_path, times);
fput(file);
} else {
struct path path;
int lookup_flags = 0;
if (!(flags & AT_SYMLINK_NOFOLLOW))
lookup_flags |= LOOKUP_FOLLOW;
error = user_path_at(dfd, filename, lookup_flags, &path);
if (error)
goto out;
error = utimes_common(&path, times);
path_put(&path);
}
out:
return error;
}
