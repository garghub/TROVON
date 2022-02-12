int iterate_dir(struct file *file, struct dir_context *ctx)
{
struct inode *inode = file_inode(file);
bool shared = false;
int res = -ENOTDIR;
if (file->f_op->iterate_shared)
shared = true;
else if (!file->f_op->iterate)
goto out;
res = security_file_permission(file, MAY_READ);
if (res)
goto out;
if (shared) {
inode_lock_shared(inode);
} else {
res = down_write_killable(&inode->i_rwsem);
if (res)
goto out;
}
res = -ENOENT;
if (!IS_DEADDIR(inode)) {
ctx->pos = file->f_pos;
if (shared)
res = file->f_op->iterate_shared(file, ctx);
else
res = file->f_op->iterate(file, ctx);
file->f_pos = ctx->pos;
fsnotify_access(file);
file_accessed(file);
}
if (shared)
inode_unlock_shared(inode);
else
inode_unlock(inode);
out:
return res;
}
static int fillonedir(struct dir_context *ctx, const char *name, int namlen,
loff_t offset, u64 ino, unsigned int d_type)
{
struct readdir_callback *buf =
container_of(ctx, struct readdir_callback, ctx);
struct old_linux_dirent __user * dirent;
unsigned long d_ino;
if (buf->result)
return -EINVAL;
d_ino = ino;
if (sizeof(d_ino) < sizeof(ino) && d_ino != ino) {
buf->result = -EOVERFLOW;
return -EOVERFLOW;
}
buf->result++;
dirent = buf->dirent;
if (!access_ok(VERIFY_WRITE, dirent,
(unsigned long)(dirent->d_name + namlen + 1) -
(unsigned long)dirent))
goto efault;
if ( __put_user(d_ino, &dirent->d_ino) ||
__put_user(offset, &dirent->d_offset) ||
__put_user(namlen, &dirent->d_namlen) ||
__copy_to_user(dirent->d_name, name, namlen) ||
__put_user(0, dirent->d_name + namlen))
goto efault;
return 0;
efault:
buf->result = -EFAULT;
return -EFAULT;
}
static int filldir(struct dir_context *ctx, const char *name, int namlen,
loff_t offset, u64 ino, unsigned int d_type)
{
struct linux_dirent __user * dirent;
struct getdents_callback *buf =
container_of(ctx, struct getdents_callback, ctx);
unsigned long d_ino;
int reclen = ALIGN(offsetof(struct linux_dirent, d_name) + namlen + 2,
sizeof(long));
buf->error = -EINVAL;
if (reclen > buf->count)
return -EINVAL;
d_ino = ino;
if (sizeof(d_ino) < sizeof(ino) && d_ino != ino) {
buf->error = -EOVERFLOW;
return -EOVERFLOW;
}
dirent = buf->previous;
if (dirent) {
if (signal_pending(current))
return -EINTR;
if (__put_user(offset, &dirent->d_off))
goto efault;
}
dirent = buf->current_dir;
if (__put_user(d_ino, &dirent->d_ino))
goto efault;
if (__put_user(reclen, &dirent->d_reclen))
goto efault;
if (copy_to_user(dirent->d_name, name, namlen))
goto efault;
if (__put_user(0, dirent->d_name + namlen))
goto efault;
if (__put_user(d_type, (char __user *) dirent + reclen - 1))
goto efault;
buf->previous = dirent;
dirent = (void __user *)dirent + reclen;
buf->current_dir = dirent;
buf->count -= reclen;
return 0;
efault:
buf->error = -EFAULT;
return -EFAULT;
}
static int filldir64(struct dir_context *ctx, const char *name, int namlen,
loff_t offset, u64 ino, unsigned int d_type)
{
struct linux_dirent64 __user *dirent;
struct getdents_callback64 *buf =
container_of(ctx, struct getdents_callback64, ctx);
int reclen = ALIGN(offsetof(struct linux_dirent64, d_name) + namlen + 1,
sizeof(u64));
buf->error = -EINVAL;
if (reclen > buf->count)
return -EINVAL;
dirent = buf->previous;
if (dirent) {
if (signal_pending(current))
return -EINTR;
if (__put_user(offset, &dirent->d_off))
goto efault;
}
dirent = buf->current_dir;
if (__put_user(ino, &dirent->d_ino))
goto efault;
if (__put_user(0, &dirent->d_off))
goto efault;
if (__put_user(reclen, &dirent->d_reclen))
goto efault;
if (__put_user(d_type, &dirent->d_type))
goto efault;
if (copy_to_user(dirent->d_name, name, namlen))
goto efault;
if (__put_user(0, dirent->d_name + namlen))
goto efault;
buf->previous = dirent;
dirent = (void __user *)dirent + reclen;
buf->current_dir = dirent;
buf->count -= reclen;
return 0;
efault:
buf->error = -EFAULT;
return -EFAULT;
}
static int compat_fillonedir(struct dir_context *ctx, const char *name,
int namlen, loff_t offset, u64 ino,
unsigned int d_type)
{
struct compat_readdir_callback *buf =
container_of(ctx, struct compat_readdir_callback, ctx);
struct compat_old_linux_dirent __user *dirent;
compat_ulong_t d_ino;
if (buf->result)
return -EINVAL;
d_ino = ino;
if (sizeof(d_ino) < sizeof(ino) && d_ino != ino) {
buf->result = -EOVERFLOW;
return -EOVERFLOW;
}
buf->result++;
dirent = buf->dirent;
if (!access_ok(VERIFY_WRITE, dirent,
(unsigned long)(dirent->d_name + namlen + 1) -
(unsigned long)dirent))
goto efault;
if ( __put_user(d_ino, &dirent->d_ino) ||
__put_user(offset, &dirent->d_offset) ||
__put_user(namlen, &dirent->d_namlen) ||
__copy_to_user(dirent->d_name, name, namlen) ||
__put_user(0, dirent->d_name + namlen))
goto efault;
return 0;
efault:
buf->result = -EFAULT;
return -EFAULT;
}
static int compat_filldir(struct dir_context *ctx, const char *name, int namlen,
loff_t offset, u64 ino, unsigned int d_type)
{
struct compat_linux_dirent __user * dirent;
struct compat_getdents_callback *buf =
container_of(ctx, struct compat_getdents_callback, ctx);
compat_ulong_t d_ino;
int reclen = ALIGN(offsetof(struct compat_linux_dirent, d_name) +
namlen + 2, sizeof(compat_long_t));
buf->error = -EINVAL;
if (reclen > buf->count)
return -EINVAL;
d_ino = ino;
if (sizeof(d_ino) < sizeof(ino) && d_ino != ino) {
buf->error = -EOVERFLOW;
return -EOVERFLOW;
}
dirent = buf->previous;
if (dirent) {
if (signal_pending(current))
return -EINTR;
if (__put_user(offset, &dirent->d_off))
goto efault;
}
dirent = buf->current_dir;
if (__put_user(d_ino, &dirent->d_ino))
goto efault;
if (__put_user(reclen, &dirent->d_reclen))
goto efault;
if (copy_to_user(dirent->d_name, name, namlen))
goto efault;
if (__put_user(0, dirent->d_name + namlen))
goto efault;
if (__put_user(d_type, (char __user *) dirent + reclen - 1))
goto efault;
buf->previous = dirent;
dirent = (void __user *)dirent + reclen;
buf->current_dir = dirent;
buf->count -= reclen;
return 0;
efault:
buf->error = -EFAULT;
return -EFAULT;
}
