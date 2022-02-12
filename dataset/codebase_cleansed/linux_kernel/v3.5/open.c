int do_truncate(struct dentry *dentry, loff_t length, unsigned int time_attrs,
struct file *filp)
{
int ret;
struct iattr newattrs;
if (length < 0)
return -EINVAL;
newattrs.ia_size = length;
newattrs.ia_valid = ATTR_SIZE | time_attrs;
if (filp) {
newattrs.ia_file = filp;
newattrs.ia_valid |= ATTR_FILE;
}
ret = should_remove_suid(dentry);
if (ret)
newattrs.ia_valid |= ret | ATTR_FORCE;
mutex_lock(&dentry->d_inode->i_mutex);
ret = notify_change(dentry, &newattrs);
mutex_unlock(&dentry->d_inode->i_mutex);
return ret;
}
static long do_sys_truncate(const char __user *pathname, loff_t length)
{
struct path path;
struct inode *inode;
int error;
error = -EINVAL;
if (length < 0)
goto out;
error = user_path(pathname, &path);
if (error)
goto out;
inode = path.dentry->d_inode;
error = -EISDIR;
if (S_ISDIR(inode->i_mode))
goto dput_and_out;
error = -EINVAL;
if (!S_ISREG(inode->i_mode))
goto dput_and_out;
error = mnt_want_write(path.mnt);
if (error)
goto dput_and_out;
error = inode_permission(inode, MAY_WRITE);
if (error)
goto mnt_drop_write_and_out;
error = -EPERM;
if (IS_APPEND(inode))
goto mnt_drop_write_and_out;
error = get_write_access(inode);
if (error)
goto mnt_drop_write_and_out;
error = break_lease(inode, O_WRONLY);
if (error)
goto put_write_and_out;
error = locks_verify_truncate(inode, NULL, length);
if (!error)
error = security_path_truncate(&path);
if (!error)
error = do_truncate(path.dentry, length, 0, NULL);
put_write_and_out:
put_write_access(inode);
mnt_drop_write_and_out:
mnt_drop_write(path.mnt);
dput_and_out:
path_put(&path);
out:
return error;
}
static long do_sys_ftruncate(unsigned int fd, loff_t length, int small)
{
struct inode * inode;
struct dentry *dentry;
struct file * file;
int error;
error = -EINVAL;
if (length < 0)
goto out;
error = -EBADF;
file = fget(fd);
if (!file)
goto out;
if (file->f_flags & O_LARGEFILE)
small = 0;
dentry = file->f_path.dentry;
inode = dentry->d_inode;
error = -EINVAL;
if (!S_ISREG(inode->i_mode) || !(file->f_mode & FMODE_WRITE))
goto out_putf;
error = -EINVAL;
if (small && length > MAX_NON_LFS)
goto out_putf;
error = -EPERM;
if (IS_APPEND(inode))
goto out_putf;
error = locks_verify_truncate(inode, file, length);
if (!error)
error = security_path_truncate(&file->f_path);
if (!error)
error = do_truncate(dentry, length, ATTR_MTIME|ATTR_CTIME, file);
out_putf:
fput(file);
out:
return error;
}
SYSCALL_DEFINE(truncate64)(const char __user * path, loff_t length)
{
return do_sys_truncate(path, length);
}
asmlinkage long SyS_truncate64(long path, loff_t length)
{
return SYSC_truncate64((const char __user *) path, length);
}
SYSCALL_DEFINE(ftruncate64)(unsigned int fd, loff_t length)
{
long ret = do_sys_ftruncate(fd, length, 0);
asmlinkage_protect(2, ret, fd, length);
return ret;
}
asmlinkage long SyS_ftruncate64(long fd, loff_t length)
{
return SYSC_ftruncate64((unsigned int) fd, length);
}
int do_fallocate(struct file *file, int mode, loff_t offset, loff_t len)
{
struct inode *inode = file->f_path.dentry->d_inode;
long ret;
if (offset < 0 || len <= 0)
return -EINVAL;
if (mode & ~(FALLOC_FL_KEEP_SIZE | FALLOC_FL_PUNCH_HOLE))
return -EOPNOTSUPP;
if ((mode & FALLOC_FL_PUNCH_HOLE) &&
!(mode & FALLOC_FL_KEEP_SIZE))
return -EOPNOTSUPP;
if (!(file->f_mode & FMODE_WRITE))
return -EBADF;
if (mode & FALLOC_FL_PUNCH_HOLE && IS_APPEND(inode))
return -EPERM;
if (IS_IMMUTABLE(inode))
return -EPERM;
ret = security_file_permission(file, MAY_WRITE);
if (ret)
return ret;
if (S_ISFIFO(inode->i_mode))
return -ESPIPE;
if (!S_ISREG(inode->i_mode) && !S_ISDIR(inode->i_mode))
return -ENODEV;
if (((offset + len) > inode->i_sb->s_maxbytes) || ((offset + len) < 0))
return -EFBIG;
if (!file->f_op->fallocate)
return -EOPNOTSUPP;
return file->f_op->fallocate(file, mode, offset, len);
}
SYSCALL_DEFINE(fallocate)(int fd, int mode, loff_t offset, loff_t len)
{
struct file *file;
int error = -EBADF;
file = fget(fd);
if (file) {
error = do_fallocate(file, mode, offset, len);
fput(file);
}
return error;
}
asmlinkage long SyS_fallocate(long fd, long mode, loff_t offset, loff_t len)
{
return SYSC_fallocate((int)fd, (int)mode, offset, len);
}
static int chmod_common(struct path *path, umode_t mode)
{
struct inode *inode = path->dentry->d_inode;
struct iattr newattrs;
int error;
error = mnt_want_write(path->mnt);
if (error)
return error;
mutex_lock(&inode->i_mutex);
error = security_path_chmod(path, mode);
if (error)
goto out_unlock;
newattrs.ia_mode = (mode & S_IALLUGO) | (inode->i_mode & ~S_IALLUGO);
newattrs.ia_valid = ATTR_MODE | ATTR_CTIME;
error = notify_change(path->dentry, &newattrs);
out_unlock:
mutex_unlock(&inode->i_mutex);
mnt_drop_write(path->mnt);
return error;
}
static int chown_common(struct path *path, uid_t user, gid_t group)
{
struct inode *inode = path->dentry->d_inode;
int error;
struct iattr newattrs;
kuid_t uid;
kgid_t gid;
uid = make_kuid(current_user_ns(), user);
gid = make_kgid(current_user_ns(), group);
newattrs.ia_valid = ATTR_CTIME;
if (user != (uid_t) -1) {
if (!uid_valid(uid))
return -EINVAL;
newattrs.ia_valid |= ATTR_UID;
newattrs.ia_uid = uid;
}
if (group != (gid_t) -1) {
if (!gid_valid(gid))
return -EINVAL;
newattrs.ia_valid |= ATTR_GID;
newattrs.ia_gid = gid;
}
if (!S_ISDIR(inode->i_mode))
newattrs.ia_valid |=
ATTR_KILL_SUID | ATTR_KILL_SGID | ATTR_KILL_PRIV;
mutex_lock(&inode->i_mutex);
error = security_path_chown(path, user, group);
if (!error)
error = notify_change(path->dentry, &newattrs);
mutex_unlock(&inode->i_mutex);
return error;
}
static inline int __get_file_write_access(struct inode *inode,
struct vfsmount *mnt)
{
int error;
error = get_write_access(inode);
if (error)
return error;
if (!special_file(inode->i_mode)) {
error = mnt_want_write(mnt);
if (error)
put_write_access(inode);
}
return error;
}
int open_check_o_direct(struct file *f)
{
if (f->f_flags & O_DIRECT) {
if (!f->f_mapping->a_ops ||
((!f->f_mapping->a_ops->direct_IO) &&
(!f->f_mapping->a_ops->get_xip_mem))) {
return -EINVAL;
}
}
return 0;
}
static struct file *do_dentry_open(struct dentry *dentry, struct vfsmount *mnt,
struct file *f,
int (*open)(struct inode *, struct file *),
const struct cred *cred)
{
static const struct file_operations empty_fops = {};
struct inode *inode;
int error;
f->f_mode = OPEN_FMODE(f->f_flags) | FMODE_LSEEK |
FMODE_PREAD | FMODE_PWRITE;
if (unlikely(f->f_flags & O_PATH))
f->f_mode = FMODE_PATH;
inode = dentry->d_inode;
if (f->f_mode & FMODE_WRITE) {
error = __get_file_write_access(inode, mnt);
if (error)
goto cleanup_file;
if (!special_file(inode->i_mode))
file_take_write(f);
}
f->f_mapping = inode->i_mapping;
f->f_path.dentry = dentry;
f->f_path.mnt = mnt;
f->f_pos = 0;
file_sb_list_add(f, inode->i_sb);
if (unlikely(f->f_mode & FMODE_PATH)) {
f->f_op = &empty_fops;
return f;
}
f->f_op = fops_get(inode->i_fop);
error = security_file_open(f, cred);
if (error)
goto cleanup_all;
error = break_lease(inode, f->f_flags);
if (error)
goto cleanup_all;
if (!open && f->f_op)
open = f->f_op->open;
if (open) {
error = open(inode, f);
if (error)
goto cleanup_all;
}
if ((f->f_mode & (FMODE_READ | FMODE_WRITE)) == FMODE_READ)
i_readcount_inc(inode);
f->f_flags &= ~(O_CREAT | O_EXCL | O_NOCTTY | O_TRUNC);
file_ra_state_init(&f->f_ra, f->f_mapping->host->i_mapping);
return f;
cleanup_all:
fops_put(f->f_op);
if (f->f_mode & FMODE_WRITE) {
put_write_access(inode);
if (!special_file(inode->i_mode)) {
file_reset_write(f);
mnt_drop_write(mnt);
}
}
file_sb_list_del(f);
f->f_path.dentry = NULL;
f->f_path.mnt = NULL;
cleanup_file:
dput(dentry);
mntput(mnt);
return ERR_PTR(error);
}
static struct file *__dentry_open(struct dentry *dentry, struct vfsmount *mnt,
struct file *f,
int (*open)(struct inode *, struct file *),
const struct cred *cred)
{
struct file *res = do_dentry_open(dentry, mnt, f, open, cred);
if (!IS_ERR(res)) {
int error = open_check_o_direct(f);
if (error) {
fput(res);
res = ERR_PTR(error);
}
} else {
put_filp(f);
}
return res;
}
struct file *lookup_instantiate_filp(struct nameidata *nd, struct dentry *dentry,
int (*open)(struct inode *, struct file *))
{
const struct cred *cred = current_cred();
if (IS_ERR(nd->intent.open.file))
goto out;
if (IS_ERR(dentry))
goto out_err;
nd->intent.open.file = __dentry_open(dget(dentry), mntget(nd->path.mnt),
nd->intent.open.file,
open, cred);
out:
return nd->intent.open.file;
out_err:
release_open_intent(nd);
nd->intent.open.file = ERR_CAST(dentry);
goto out;
}
struct file *nameidata_to_filp(struct nameidata *nd)
{
const struct cred *cred = current_cred();
struct file *filp;
filp = nd->intent.open.file;
if (filp->f_path.dentry != NULL) {
nd->intent.open.file = NULL;
} else {
struct file *res;
path_get(&nd->path);
res = do_dentry_open(nd->path.dentry, nd->path.mnt,
filp, NULL, cred);
if (!IS_ERR(res)) {
int error;
nd->intent.open.file = NULL;
BUG_ON(res != filp);
error = open_check_o_direct(filp);
if (error) {
fput(filp);
filp = ERR_PTR(error);
}
} else {
filp = res;
}
}
return filp;
}
struct file *dentry_open(struct dentry *dentry, struct vfsmount *mnt, int flags,
const struct cred *cred)
{
int error;
struct file *f;
validate_creds(cred);
BUG_ON(!mnt);
error = -ENFILE;
f = get_empty_filp();
if (f == NULL) {
dput(dentry);
mntput(mnt);
return ERR_PTR(error);
}
f->f_flags = flags;
return __dentry_open(dentry, mnt, f, NULL, cred);
}
static void __put_unused_fd(struct files_struct *files, unsigned int fd)
{
struct fdtable *fdt = files_fdtable(files);
__clear_open_fd(fd, fdt);
if (fd < files->next_fd)
files->next_fd = fd;
}
void put_unused_fd(unsigned int fd)
{
struct files_struct *files = current->files;
spin_lock(&files->file_lock);
__put_unused_fd(files, fd);
spin_unlock(&files->file_lock);
}
void fd_install(unsigned int fd, struct file *file)
{
struct files_struct *files = current->files;
struct fdtable *fdt;
spin_lock(&files->file_lock);
fdt = files_fdtable(files);
BUG_ON(fdt->fd[fd] != NULL);
rcu_assign_pointer(fdt->fd[fd], file);
spin_unlock(&files->file_lock);
}
static inline int build_open_flags(int flags, umode_t mode, struct open_flags *op)
{
int lookup_flags = 0;
int acc_mode;
if (!(flags & O_CREAT))
mode = 0;
op->mode = mode;
flags &= ~FMODE_NONOTIFY;
if (flags & __O_SYNC)
flags |= O_DSYNC;
if (flags & O_PATH) {
flags &= O_DIRECTORY | O_NOFOLLOW | O_PATH;
acc_mode = 0;
} else {
acc_mode = MAY_OPEN | ACC_MODE(flags);
}
op->open_flag = flags;
if (flags & O_TRUNC)
acc_mode |= MAY_WRITE;
if (flags & O_APPEND)
acc_mode |= MAY_APPEND;
op->acc_mode = acc_mode;
op->intent = flags & O_PATH ? 0 : LOOKUP_OPEN;
if (flags & O_CREAT) {
op->intent |= LOOKUP_CREATE;
if (flags & O_EXCL)
op->intent |= LOOKUP_EXCL;
}
if (flags & O_DIRECTORY)
lookup_flags |= LOOKUP_DIRECTORY;
if (!(flags & O_NOFOLLOW))
lookup_flags |= LOOKUP_FOLLOW;
return lookup_flags;
}
struct file *filp_open(const char *filename, int flags, umode_t mode)
{
struct open_flags op;
int lookup = build_open_flags(flags, mode, &op);
return do_filp_open(AT_FDCWD, filename, &op, lookup);
}
struct file *file_open_root(struct dentry *dentry, struct vfsmount *mnt,
const char *filename, int flags)
{
struct open_flags op;
int lookup = build_open_flags(flags, 0, &op);
if (flags & O_CREAT)
return ERR_PTR(-EINVAL);
if (!filename && (flags & O_DIRECTORY))
if (!dentry->d_inode->i_op->lookup)
return ERR_PTR(-ENOTDIR);
return do_file_open_root(dentry, mnt, filename, &op, lookup);
}
long do_sys_open(int dfd, const char __user *filename, int flags, umode_t mode)
{
struct open_flags op;
int lookup = build_open_flags(flags, mode, &op);
char *tmp = getname(filename);
int fd = PTR_ERR(tmp);
if (!IS_ERR(tmp)) {
fd = get_unused_fd_flags(flags);
if (fd >= 0) {
struct file *f = do_filp_open(dfd, tmp, &op, lookup);
if (IS_ERR(f)) {
put_unused_fd(fd);
fd = PTR_ERR(f);
} else {
fsnotify_open(f);
fd_install(fd, f);
}
}
putname(tmp);
}
return fd;
}
int filp_close(struct file *filp, fl_owner_t id)
{
int retval = 0;
if (!file_count(filp)) {
printk(KERN_ERR "VFS: Close: file count is 0\n");
return 0;
}
if (filp->f_op && filp->f_op->flush)
retval = filp->f_op->flush(filp, id);
if (likely(!(filp->f_mode & FMODE_PATH))) {
dnotify_flush(filp, id);
locks_remove_posix(filp, id);
}
fput(filp);
return retval;
}
int generic_file_open(struct inode * inode, struct file * filp)
{
if (!(filp->f_flags & O_LARGEFILE) && i_size_read(inode) > MAX_NON_LFS)
return -EOVERFLOW;
return 0;
}
int nonseekable_open(struct inode *inode, struct file *filp)
{
filp->f_mode &= ~(FMODE_LSEEK | FMODE_PREAD | FMODE_PWRITE);
return 0;
}
