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
ret = notify_change(dentry, &newattrs, NULL);
mutex_unlock(&dentry->d_inode->i_mutex);
return ret;
}
long vfs_truncate(struct path *path, loff_t length)
{
struct inode *inode;
long error;
inode = path->dentry->d_inode;
if (S_ISDIR(inode->i_mode))
return -EISDIR;
if (!S_ISREG(inode->i_mode))
return -EINVAL;
error = mnt_want_write(path->mnt);
if (error)
goto out;
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
error = security_path_truncate(path);
if (!error)
error = do_truncate(path->dentry, length, 0, NULL);
put_write_and_out:
put_write_access(inode);
mnt_drop_write_and_out:
mnt_drop_write(path->mnt);
out:
return error;
}
static long do_sys_truncate(const char __user *pathname, loff_t length)
{
unsigned int lookup_flags = LOOKUP_FOLLOW;
struct path path;
int error;
if (length < 0)
return -EINVAL;
retry:
error = user_path_at(AT_FDCWD, pathname, lookup_flags, &path);
if (!error) {
error = vfs_truncate(&path, length);
path_put(&path);
}
if (retry_estale(error, lookup_flags)) {
lookup_flags |= LOOKUP_REVAL;
goto retry;
}
return error;
}
static long do_sys_ftruncate(unsigned int fd, loff_t length, int small)
{
struct inode *inode;
struct dentry *dentry;
struct fd f;
int error;
error = -EINVAL;
if (length < 0)
goto out;
error = -EBADF;
f = fdget(fd);
if (!f.file)
goto out;
if (f.file->f_flags & O_LARGEFILE)
small = 0;
dentry = f.file->f_path.dentry;
inode = dentry->d_inode;
error = -EINVAL;
if (!S_ISREG(inode->i_mode) || !(f.file->f_mode & FMODE_WRITE))
goto out_putf;
error = -EINVAL;
if (small && length > MAX_NON_LFS)
goto out_putf;
error = -EPERM;
if (IS_APPEND(inode))
goto out_putf;
sb_start_write(inode->i_sb);
error = locks_verify_truncate(inode, f.file, length);
if (!error)
error = security_path_truncate(&f.file->f_path);
if (!error)
error = do_truncate(dentry, length, ATTR_MTIME|ATTR_CTIME, f.file);
sb_end_write(inode->i_sb);
out_putf:
fdput(f);
out:
return error;
}
int do_fallocate(struct file *file, int mode, loff_t offset, loff_t len)
{
struct inode *inode = file_inode(file);
long ret;
if (offset < 0 || len <= 0)
return -EINVAL;
if (mode & ~(FALLOC_FL_KEEP_SIZE | FALLOC_FL_PUNCH_HOLE |
FALLOC_FL_COLLAPSE_RANGE | FALLOC_FL_ZERO_RANGE))
return -EOPNOTSUPP;
if ((mode & (FALLOC_FL_PUNCH_HOLE | FALLOC_FL_ZERO_RANGE)) ==
(FALLOC_FL_PUNCH_HOLE | FALLOC_FL_ZERO_RANGE))
return -EOPNOTSUPP;
if ((mode & FALLOC_FL_PUNCH_HOLE) &&
!(mode & FALLOC_FL_KEEP_SIZE))
return -EOPNOTSUPP;
if ((mode & FALLOC_FL_COLLAPSE_RANGE) &&
(mode & ~FALLOC_FL_COLLAPSE_RANGE))
return -EINVAL;
if (!(file->f_mode & FMODE_WRITE))
return -EBADF;
if ((mode & ~FALLOC_FL_KEEP_SIZE) && IS_APPEND(inode))
return -EPERM;
if (IS_IMMUTABLE(inode))
return -EPERM;
if (IS_SWAPFILE(inode))
return -ETXTBSY;
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
sb_start_write(inode->i_sb);
ret = file->f_op->fallocate(file, mode, offset, len);
sb_end_write(inode->i_sb);
return ret;
}
static int chmod_common(struct path *path, umode_t mode)
{
struct inode *inode = path->dentry->d_inode;
struct inode *delegated_inode = NULL;
struct iattr newattrs;
int error;
error = mnt_want_write(path->mnt);
if (error)
return error;
retry_deleg:
mutex_lock(&inode->i_mutex);
error = security_path_chmod(path, mode);
if (error)
goto out_unlock;
newattrs.ia_mode = (mode & S_IALLUGO) | (inode->i_mode & ~S_IALLUGO);
newattrs.ia_valid = ATTR_MODE | ATTR_CTIME;
error = notify_change(path->dentry, &newattrs, &delegated_inode);
out_unlock:
mutex_unlock(&inode->i_mutex);
if (delegated_inode) {
error = break_deleg_wait(&delegated_inode);
if (!error)
goto retry_deleg;
}
mnt_drop_write(path->mnt);
return error;
}
static int chown_common(struct path *path, uid_t user, gid_t group)
{
struct inode *inode = path->dentry->d_inode;
struct inode *delegated_inode = NULL;
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
retry_deleg:
mutex_lock(&inode->i_mutex);
error = security_path_chown(path, uid, gid);
if (!error)
error = notify_change(path->dentry, &newattrs, &delegated_inode);
mutex_unlock(&inode->i_mutex);
if (delegated_inode) {
error = break_deleg_wait(&delegated_inode);
if (!error)
goto retry_deleg;
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
static int do_dentry_open(struct file *f,
int (*open)(struct inode *, struct file *),
const struct cred *cred)
{
static const struct file_operations empty_fops = {};
struct inode *inode;
int error;
f->f_mode = OPEN_FMODE(f->f_flags) | FMODE_LSEEK |
FMODE_PREAD | FMODE_PWRITE;
path_get(&f->f_path);
inode = f->f_inode = f->f_path.dentry->d_inode;
f->f_mapping = inode->i_mapping;
if (unlikely(f->f_flags & O_PATH)) {
f->f_mode = FMODE_PATH;
f->f_op = &empty_fops;
return 0;
}
if (f->f_mode & FMODE_WRITE && !special_file(inode->i_mode)) {
error = get_write_access(inode);
if (unlikely(error))
goto cleanup_file;
error = __mnt_want_write(f->f_path.mnt);
if (unlikely(error)) {
put_write_access(inode);
goto cleanup_file;
}
f->f_mode |= FMODE_WRITER;
}
if (S_ISREG(inode->i_mode))
f->f_mode |= FMODE_ATOMIC_POS;
f->f_op = fops_get(inode->i_fop);
if (unlikely(WARN_ON(!f->f_op))) {
error = -ENODEV;
goto cleanup_all;
}
error = security_file_open(f, cred);
if (error)
goto cleanup_all;
error = break_lease(inode, f->f_flags);
if (error)
goto cleanup_all;
if (!open)
open = f->f_op->open;
if (open) {
error = open(inode, f);
if (error)
goto cleanup_all;
}
if ((f->f_mode & (FMODE_READ | FMODE_WRITE)) == FMODE_READ)
i_readcount_inc(inode);
if ((f->f_mode & FMODE_READ) &&
likely(f->f_op->read || f->f_op->aio_read || f->f_op->read_iter))
f->f_mode |= FMODE_CAN_READ;
if ((f->f_mode & FMODE_WRITE) &&
likely(f->f_op->write || f->f_op->aio_write || f->f_op->write_iter))
f->f_mode |= FMODE_CAN_WRITE;
f->f_flags &= ~(O_CREAT | O_EXCL | O_NOCTTY | O_TRUNC);
file_ra_state_init(&f->f_ra, f->f_mapping->host->i_mapping);
return 0;
cleanup_all:
fops_put(f->f_op);
if (f->f_mode & FMODE_WRITER) {
put_write_access(inode);
__mnt_drop_write(f->f_path.mnt);
}
cleanup_file:
path_put(&f->f_path);
f->f_path.mnt = NULL;
f->f_path.dentry = NULL;
f->f_inode = NULL;
return error;
}
int finish_open(struct file *file, struct dentry *dentry,
int (*open)(struct inode *, struct file *),
int *opened)
{
int error;
BUG_ON(*opened & FILE_OPENED);
file->f_path.dentry = dentry;
error = do_dentry_open(file, open, current_cred());
if (!error)
*opened |= FILE_OPENED;
return error;
}
int finish_no_open(struct file *file, struct dentry *dentry)
{
file->f_path.dentry = dentry;
return 1;
}
struct file *dentry_open(const struct path *path, int flags,
const struct cred *cred)
{
int error;
struct file *f;
validate_creds(cred);
BUG_ON(!path->mnt);
f = get_empty_filp();
if (!IS_ERR(f)) {
f->f_flags = flags;
error = vfs_open(path, f, cred);
if (!error) {
error = open_check_o_direct(f);
if (error) {
fput(f);
f = ERR_PTR(error);
}
} else {
put_filp(f);
f = ERR_PTR(error);
}
}
return f;
}
int vfs_open(const struct path *path, struct file *filp,
const struct cred *cred)
{
struct inode *inode = path->dentry->d_inode;
if (inode->i_op->dentry_open)
return inode->i_op->dentry_open(path->dentry, filp, cred);
else {
filp->f_path = *path;
return do_dentry_open(filp, NULL, cred);
}
}
static inline int build_open_flags(int flags, umode_t mode, struct open_flags *op)
{
int lookup_flags = 0;
int acc_mode;
if (flags & (O_CREAT | __O_TMPFILE))
op->mode = (mode & S_IALLUGO) | S_IFREG;
else
op->mode = 0;
flags &= ~FMODE_NONOTIFY & ~O_CLOEXEC;
if (flags & __O_SYNC)
flags |= O_DSYNC;
if (flags & __O_TMPFILE) {
if ((flags & O_TMPFILE_MASK) != O_TMPFILE)
return -EINVAL;
acc_mode = MAY_OPEN | ACC_MODE(flags);
if (!(acc_mode & MAY_WRITE))
return -EINVAL;
} else if (flags & O_PATH) {
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
op->lookup_flags = lookup_flags;
return 0;
}
struct file *file_open_name(struct filename *name, int flags, umode_t mode)
{
struct open_flags op;
int err = build_open_flags(flags, mode, &op);
return err ? ERR_PTR(err) : do_filp_open(AT_FDCWD, name, &op);
}
struct file *filp_open(const char *filename, int flags, umode_t mode)
{
struct filename name = {.name = filename};
return file_open_name(&name, flags, mode);
}
struct file *file_open_root(struct dentry *dentry, struct vfsmount *mnt,
const char *filename, int flags)
{
struct open_flags op;
int err = build_open_flags(flags, 0, &op);
if (err)
return ERR_PTR(err);
if (flags & O_CREAT)
return ERR_PTR(-EINVAL);
if (!filename && (flags & O_DIRECTORY))
if (!dentry->d_inode->i_op->lookup)
return ERR_PTR(-ENOTDIR);
return do_file_open_root(dentry, mnt, filename, &op);
}
long do_sys_open(int dfd, const char __user *filename, int flags, umode_t mode)
{
struct open_flags op;
int fd = build_open_flags(flags, mode, &op);
struct filename *tmp;
if (fd)
return fd;
tmp = getname(filename);
if (IS_ERR(tmp))
return PTR_ERR(tmp);
fd = get_unused_fd_flags(flags);
if (fd >= 0) {
struct file *f = do_filp_open(dfd, tmp, &op);
if (IS_ERR(f)) {
put_unused_fd(fd);
fd = PTR_ERR(f);
} else {
fsnotify_open(f);
fd_install(fd, f);
}
}
putname(tmp);
return fd;
}
int filp_close(struct file *filp, fl_owner_t id)
{
int retval = 0;
if (!file_count(filp)) {
printk(KERN_ERR "VFS: Close: file count is 0\n");
return 0;
}
if (filp->f_op->flush)
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
