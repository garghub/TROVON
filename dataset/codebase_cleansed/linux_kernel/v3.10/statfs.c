static int flags_by_mnt(int mnt_flags)
{
int flags = 0;
if (mnt_flags & MNT_READONLY)
flags |= ST_RDONLY;
if (mnt_flags & MNT_NOSUID)
flags |= ST_NOSUID;
if (mnt_flags & MNT_NODEV)
flags |= ST_NODEV;
if (mnt_flags & MNT_NOEXEC)
flags |= ST_NOEXEC;
if (mnt_flags & MNT_NOATIME)
flags |= ST_NOATIME;
if (mnt_flags & MNT_NODIRATIME)
flags |= ST_NODIRATIME;
if (mnt_flags & MNT_RELATIME)
flags |= ST_RELATIME;
return flags;
}
static int flags_by_sb(int s_flags)
{
int flags = 0;
if (s_flags & MS_SYNCHRONOUS)
flags |= ST_SYNCHRONOUS;
if (s_flags & MS_MANDLOCK)
flags |= ST_MANDLOCK;
return flags;
}
static int calculate_f_flags(struct vfsmount *mnt)
{
return ST_VALID | flags_by_mnt(mnt->mnt_flags) |
flags_by_sb(mnt->mnt_sb->s_flags);
}
static int statfs_by_dentry(struct dentry *dentry, struct kstatfs *buf)
{
int retval;
if (!dentry->d_sb->s_op->statfs)
return -ENOSYS;
memset(buf, 0, sizeof(*buf));
retval = security_sb_statfs(dentry);
if (retval)
return retval;
retval = dentry->d_sb->s_op->statfs(dentry, buf);
if (retval == 0 && buf->f_frsize == 0)
buf->f_frsize = buf->f_bsize;
return retval;
}
int vfs_statfs(struct path *path, struct kstatfs *buf)
{
int error;
error = statfs_by_dentry(path->dentry, buf);
if (!error)
buf->f_flags = calculate_f_flags(path->mnt);
return error;
}
int user_statfs(const char __user *pathname, struct kstatfs *st)
{
struct path path;
int error;
unsigned int lookup_flags = LOOKUP_FOLLOW|LOOKUP_AUTOMOUNT;
retry:
error = user_path_at(AT_FDCWD, pathname, lookup_flags, &path);
if (!error) {
error = vfs_statfs(&path, st);
path_put(&path);
if (retry_estale(error, lookup_flags)) {
lookup_flags |= LOOKUP_REVAL;
goto retry;
}
}
return error;
}
int fd_statfs(int fd, struct kstatfs *st)
{
struct fd f = fdget(fd);
int error = -EBADF;
if (f.file) {
error = vfs_statfs(&f.file->f_path, st);
fdput(f);
}
return error;
}
static int do_statfs_native(struct kstatfs *st, struct statfs __user *p)
{
struct statfs buf;
if (sizeof(buf) == sizeof(*st))
memcpy(&buf, st, sizeof(*st));
else {
if (sizeof buf.f_blocks == 4) {
if ((st->f_blocks | st->f_bfree | st->f_bavail |
st->f_bsize | st->f_frsize) &
0xffffffff00000000ULL)
return -EOVERFLOW;
if (st->f_files != -1 &&
(st->f_files & 0xffffffff00000000ULL))
return -EOVERFLOW;
if (st->f_ffree != -1 &&
(st->f_ffree & 0xffffffff00000000ULL))
return -EOVERFLOW;
}
buf.f_type = st->f_type;
buf.f_bsize = st->f_bsize;
buf.f_blocks = st->f_blocks;
buf.f_bfree = st->f_bfree;
buf.f_bavail = st->f_bavail;
buf.f_files = st->f_files;
buf.f_ffree = st->f_ffree;
buf.f_fsid = st->f_fsid;
buf.f_namelen = st->f_namelen;
buf.f_frsize = st->f_frsize;
buf.f_flags = st->f_flags;
memset(buf.f_spare, 0, sizeof(buf.f_spare));
}
if (copy_to_user(p, &buf, sizeof(buf)))
return -EFAULT;
return 0;
}
static int do_statfs64(struct kstatfs *st, struct statfs64 __user *p)
{
struct statfs64 buf;
if (sizeof(buf) == sizeof(*st))
memcpy(&buf, st, sizeof(*st));
else {
buf.f_type = st->f_type;
buf.f_bsize = st->f_bsize;
buf.f_blocks = st->f_blocks;
buf.f_bfree = st->f_bfree;
buf.f_bavail = st->f_bavail;
buf.f_files = st->f_files;
buf.f_ffree = st->f_ffree;
buf.f_fsid = st->f_fsid;
buf.f_namelen = st->f_namelen;
buf.f_frsize = st->f_frsize;
buf.f_flags = st->f_flags;
memset(buf.f_spare, 0, sizeof(buf.f_spare));
}
if (copy_to_user(p, &buf, sizeof(buf)))
return -EFAULT;
return 0;
}
int vfs_ustat(dev_t dev, struct kstatfs *sbuf)
{
struct super_block *s = user_get_super(dev);
int err;
if (!s)
return -EINVAL;
err = statfs_by_dentry(s->s_root, sbuf);
drop_super(s);
return err;
}
