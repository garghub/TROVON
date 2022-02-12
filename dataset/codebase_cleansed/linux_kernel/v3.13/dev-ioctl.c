static int check_name(const char *name)
{
if (!strchr(name, '/'))
return -EINVAL;
return 0;
}
static int invalid_str(char *str, size_t size)
{
if (memchr(str, 0, size))
return 0;
return -EINVAL;
}
static int check_dev_ioctl_version(int cmd, struct autofs_dev_ioctl *param)
{
int err = 0;
if ((AUTOFS_DEV_IOCTL_VERSION_MAJOR != param->ver_major) ||
(AUTOFS_DEV_IOCTL_VERSION_MINOR < param->ver_minor)) {
AUTOFS_WARN("ioctl control interface version mismatch: "
"kernel(%u.%u), user(%u.%u), cmd(%d)",
AUTOFS_DEV_IOCTL_VERSION_MAJOR,
AUTOFS_DEV_IOCTL_VERSION_MINOR,
param->ver_major, param->ver_minor, cmd);
err = -EINVAL;
}
param->ver_major = AUTOFS_DEV_IOCTL_VERSION_MAJOR;
param->ver_minor = AUTOFS_DEV_IOCTL_VERSION_MINOR;
return err;
}
static struct autofs_dev_ioctl *copy_dev_ioctl(struct autofs_dev_ioctl __user *in)
{
struct autofs_dev_ioctl tmp;
if (copy_from_user(&tmp, in, sizeof(tmp)))
return ERR_PTR(-EFAULT);
if (tmp.size < sizeof(tmp))
return ERR_PTR(-EINVAL);
return memdup_user(in, tmp.size);
}
static inline void free_dev_ioctl(struct autofs_dev_ioctl *param)
{
kfree(param);
return;
}
static int validate_dev_ioctl(int cmd, struct autofs_dev_ioctl *param)
{
int err;
err = check_dev_ioctl_version(cmd, param);
if (err) {
AUTOFS_WARN("invalid device control module version "
"supplied for cmd(0x%08x)", cmd);
goto out;
}
if (param->size > sizeof(*param)) {
err = invalid_str(param->path, param->size - sizeof(*param));
if (err) {
AUTOFS_WARN(
"path string terminator missing for cmd(0x%08x)",
cmd);
goto out;
}
err = check_name(param->path);
if (err) {
AUTOFS_WARN("invalid path supplied for cmd(0x%08x)",
cmd);
goto out;
}
}
err = 0;
out:
return err;
}
static struct autofs_sb_info *autofs_dev_ioctl_sbi(struct file *f)
{
struct autofs_sb_info *sbi = NULL;
struct inode *inode;
if (f) {
inode = file_inode(f);
sbi = autofs4_sbi(inode->i_sb);
}
return sbi;
}
static int autofs_dev_ioctl_protover(struct file *fp,
struct autofs_sb_info *sbi,
struct autofs_dev_ioctl *param)
{
param->protover.version = sbi->version;
return 0;
}
static int autofs_dev_ioctl_protosubver(struct file *fp,
struct autofs_sb_info *sbi,
struct autofs_dev_ioctl *param)
{
param->protosubver.sub_version = sbi->sub_version;
return 0;
}
static int find_autofs_mount(const char *pathname,
struct path *res,
int test(struct path *path, void *data),
void *data)
{
struct path path;
int err = kern_path_mountpoint(AT_FDCWD, pathname, &path, 0);
if (err)
return err;
err = -ENOENT;
while (path.dentry == path.mnt->mnt_root) {
if (path.dentry->d_sb->s_magic == AUTOFS_SUPER_MAGIC) {
if (test(&path, data)) {
path_get(&path);
*res = path;
err = 0;
break;
}
}
if (!follow_up(&path))
break;
}
path_put(&path);
return err;
}
static int test_by_dev(struct path *path, void *p)
{
return path->dentry->d_sb->s_dev == *(dev_t *)p;
}
static int test_by_type(struct path *path, void *p)
{
struct autofs_info *ino = autofs4_dentry_ino(path->dentry);
return ino && ino->sbi->type & *(unsigned *)p;
}
static int autofs_dev_ioctl_open_mountpoint(const char *name, dev_t devid)
{
int err, fd;
fd = get_unused_fd_flags(O_CLOEXEC);
if (likely(fd >= 0)) {
struct file *filp;
struct path path;
err = find_autofs_mount(name, &path, test_by_dev, &devid);
if (err)
goto out;
filp = dentry_open(&path, O_RDONLY, current_cred());
path_put(&path);
if (IS_ERR(filp)) {
err = PTR_ERR(filp);
goto out;
}
fd_install(fd, filp);
}
return fd;
out:
put_unused_fd(fd);
return err;
}
static int autofs_dev_ioctl_openmount(struct file *fp,
struct autofs_sb_info *sbi,
struct autofs_dev_ioctl *param)
{
const char *path;
dev_t devid;
int err, fd;
if (!param->openmount.devid)
return -EINVAL;
param->ioctlfd = -1;
path = param->path;
devid = new_decode_dev(param->openmount.devid);
err = 0;
fd = autofs_dev_ioctl_open_mountpoint(path, devid);
if (unlikely(fd < 0)) {
err = fd;
goto out;
}
param->ioctlfd = fd;
out:
return err;
}
static int autofs_dev_ioctl_closemount(struct file *fp,
struct autofs_sb_info *sbi,
struct autofs_dev_ioctl *param)
{
return sys_close(param->ioctlfd);
}
static int autofs_dev_ioctl_ready(struct file *fp,
struct autofs_sb_info *sbi,
struct autofs_dev_ioctl *param)
{
autofs_wqt_t token;
token = (autofs_wqt_t) param->ready.token;
return autofs4_wait_release(sbi, token, 0);
}
static int autofs_dev_ioctl_fail(struct file *fp,
struct autofs_sb_info *sbi,
struct autofs_dev_ioctl *param)
{
autofs_wqt_t token;
int status;
token = (autofs_wqt_t) param->fail.token;
status = param->fail.status ? param->fail.status : -ENOENT;
return autofs4_wait_release(sbi, token, status);
}
static int autofs_dev_ioctl_setpipefd(struct file *fp,
struct autofs_sb_info *sbi,
struct autofs_dev_ioctl *param)
{
int pipefd;
int err = 0;
if (param->setpipefd.pipefd == -1)
return -EINVAL;
pipefd = param->setpipefd.pipefd;
mutex_lock(&sbi->wq_mutex);
if (!sbi->catatonic) {
mutex_unlock(&sbi->wq_mutex);
return -EBUSY;
} else {
struct file *pipe = fget(pipefd);
if (!pipe) {
err = -EBADF;
goto out;
}
if (autofs_prepare_pipe(pipe) < 0) {
err = -EPIPE;
fput(pipe);
goto out;
}
sbi->oz_pgrp = task_pgrp_nr(current);
sbi->pipefd = pipefd;
sbi->pipe = pipe;
sbi->catatonic = 0;
}
out:
mutex_unlock(&sbi->wq_mutex);
return err;
}
static int autofs_dev_ioctl_catatonic(struct file *fp,
struct autofs_sb_info *sbi,
struct autofs_dev_ioctl *param)
{
autofs4_catatonic_mode(sbi);
return 0;
}
static int autofs_dev_ioctl_timeout(struct file *fp,
struct autofs_sb_info *sbi,
struct autofs_dev_ioctl *param)
{
unsigned long timeout;
timeout = param->timeout.timeout;
param->timeout.timeout = sbi->exp_timeout / HZ;
sbi->exp_timeout = timeout * HZ;
return 0;
}
static int autofs_dev_ioctl_requester(struct file *fp,
struct autofs_sb_info *sbi,
struct autofs_dev_ioctl *param)
{
struct autofs_info *ino;
struct path path;
dev_t devid;
int err = -ENOENT;
if (param->size <= sizeof(*param)) {
err = -EINVAL;
goto out;
}
devid = sbi->sb->s_dev;
param->requester.uid = param->requester.gid = -1;
err = find_autofs_mount(param->path, &path, test_by_dev, &devid);
if (err)
goto out;
ino = autofs4_dentry_ino(path.dentry);
if (ino) {
err = 0;
autofs4_expire_wait(path.dentry);
spin_lock(&sbi->fs_lock);
param->requester.uid = from_kuid_munged(current_user_ns(), ino->uid);
param->requester.gid = from_kgid_munged(current_user_ns(), ino->gid);
spin_unlock(&sbi->fs_lock);
}
path_put(&path);
out:
return err;
}
static int autofs_dev_ioctl_expire(struct file *fp,
struct autofs_sb_info *sbi,
struct autofs_dev_ioctl *param)
{
struct vfsmount *mnt;
int how;
how = param->expire.how;
mnt = fp->f_path.mnt;
return autofs4_do_expire_multi(sbi->sb, mnt, sbi, how);
}
static int autofs_dev_ioctl_askumount(struct file *fp,
struct autofs_sb_info *sbi,
struct autofs_dev_ioctl *param)
{
param->askumount.may_umount = 0;
if (may_umount(fp->f_path.mnt))
param->askumount.may_umount = 1;
return 0;
}
static int autofs_dev_ioctl_ismountpoint(struct file *fp,
struct autofs_sb_info *sbi,
struct autofs_dev_ioctl *param)
{
struct path path;
const char *name;
unsigned int type;
unsigned int devid, magic;
int err = -ENOENT;
if (param->size <= sizeof(*param)) {
err = -EINVAL;
goto out;
}
name = param->path;
type = param->ismountpoint.in.type;
param->ismountpoint.out.devid = devid = 0;
param->ismountpoint.out.magic = magic = 0;
if (!fp || param->ioctlfd == -1) {
if (autofs_type_any(type))
err = kern_path_mountpoint(AT_FDCWD,
name, &path, LOOKUP_FOLLOW);
else
err = find_autofs_mount(name, &path,
test_by_type, &type);
if (err)
goto out;
devid = new_encode_dev(path.dentry->d_sb->s_dev);
err = 0;
if (path.mnt->mnt_root == path.dentry) {
err = 1;
magic = path.dentry->d_sb->s_magic;
}
} else {
dev_t dev = sbi->sb->s_dev;
err = find_autofs_mount(name, &path, test_by_dev, &dev);
if (err)
goto out;
devid = new_encode_dev(dev);
err = have_submounts(path.dentry);
if (follow_down_one(&path))
magic = path.dentry->d_sb->s_magic;
}
param->ismountpoint.out.devid = devid;
param->ismountpoint.out.magic = magic;
path_put(&path);
out:
return err;
}
static ioctl_fn lookup_dev_ioctl(unsigned int cmd)
{
static struct {
int cmd;
ioctl_fn fn;
} _ioctls[] = {
{cmd_idx(AUTOFS_DEV_IOCTL_VERSION_CMD), NULL},
{cmd_idx(AUTOFS_DEV_IOCTL_PROTOVER_CMD),
autofs_dev_ioctl_protover},
{cmd_idx(AUTOFS_DEV_IOCTL_PROTOSUBVER_CMD),
autofs_dev_ioctl_protosubver},
{cmd_idx(AUTOFS_DEV_IOCTL_OPENMOUNT_CMD),
autofs_dev_ioctl_openmount},
{cmd_idx(AUTOFS_DEV_IOCTL_CLOSEMOUNT_CMD),
autofs_dev_ioctl_closemount},
{cmd_idx(AUTOFS_DEV_IOCTL_READY_CMD),
autofs_dev_ioctl_ready},
{cmd_idx(AUTOFS_DEV_IOCTL_FAIL_CMD),
autofs_dev_ioctl_fail},
{cmd_idx(AUTOFS_DEV_IOCTL_SETPIPEFD_CMD),
autofs_dev_ioctl_setpipefd},
{cmd_idx(AUTOFS_DEV_IOCTL_CATATONIC_CMD),
autofs_dev_ioctl_catatonic},
{cmd_idx(AUTOFS_DEV_IOCTL_TIMEOUT_CMD),
autofs_dev_ioctl_timeout},
{cmd_idx(AUTOFS_DEV_IOCTL_REQUESTER_CMD),
autofs_dev_ioctl_requester},
{cmd_idx(AUTOFS_DEV_IOCTL_EXPIRE_CMD),
autofs_dev_ioctl_expire},
{cmd_idx(AUTOFS_DEV_IOCTL_ASKUMOUNT_CMD),
autofs_dev_ioctl_askumount},
{cmd_idx(AUTOFS_DEV_IOCTL_ISMOUNTPOINT_CMD),
autofs_dev_ioctl_ismountpoint}
};
unsigned int idx = cmd_idx(cmd);
return (idx >= ARRAY_SIZE(_ioctls)) ? NULL : _ioctls[idx].fn;
}
static int _autofs_dev_ioctl(unsigned int command, struct autofs_dev_ioctl __user *user)
{
struct autofs_dev_ioctl *param;
struct file *fp;
struct autofs_sb_info *sbi;
unsigned int cmd_first, cmd;
ioctl_fn fn = NULL;
int err = 0;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
cmd_first = _IOC_NR(AUTOFS_DEV_IOCTL_IOC_FIRST);
cmd = _IOC_NR(command);
if (_IOC_TYPE(command) != _IOC_TYPE(AUTOFS_DEV_IOCTL_IOC_FIRST) ||
cmd - cmd_first >= AUTOFS_DEV_IOCTL_IOC_COUNT) {
return -ENOTTY;
}
param = copy_dev_ioctl(user);
if (IS_ERR(param))
return PTR_ERR(param);
err = validate_dev_ioctl(command, param);
if (err)
goto out;
if (cmd == AUTOFS_DEV_IOCTL_VERSION_CMD)
goto done;
fn = lookup_dev_ioctl(cmd);
if (!fn) {
AUTOFS_WARN("unknown command 0x%08x", command);
return -ENOTTY;
}
fp = NULL;
sbi = NULL;
if (cmd != AUTOFS_DEV_IOCTL_OPENMOUNT_CMD &&
cmd != AUTOFS_DEV_IOCTL_CLOSEMOUNT_CMD) {
fp = fget(param->ioctlfd);
if (!fp) {
if (cmd == AUTOFS_DEV_IOCTL_ISMOUNTPOINT_CMD)
goto cont;
err = -EBADF;
goto out;
}
sbi = autofs_dev_ioctl_sbi(fp);
if (!sbi || sbi->magic != AUTOFS_SBI_MAGIC) {
err = -EINVAL;
fput(fp);
goto out;
}
if (!autofs4_oz_mode(sbi) &&
cmd != AUTOFS_DEV_IOCTL_CATATONIC_CMD) {
err = -EACCES;
fput(fp);
goto out;
}
}
cont:
err = fn(fp, sbi, param);
if (fp)
fput(fp);
done:
if (err >= 0 && copy_to_user(user, param, AUTOFS_DEV_IOCTL_SIZE))
err = -EFAULT;
out:
free_dev_ioctl(param);
return err;
}
static long autofs_dev_ioctl(struct file *file, uint command, ulong u)
{
int err;
err = _autofs_dev_ioctl(command, (struct autofs_dev_ioctl __user *) u);
return (long) err;
}
static long autofs_dev_ioctl_compat(struct file *file, uint command, ulong u)
{
return (long) autofs_dev_ioctl(file, command, (ulong) compat_ptr(u));
}
int autofs_dev_ioctl_init(void)
{
int r;
r = misc_register(&_autofs_dev_ioctl_misc);
if (r) {
AUTOFS_ERROR("misc_register failed for control device");
return r;
}
return 0;
}
void autofs_dev_ioctl_exit(void)
{
misc_deregister(&_autofs_dev_ioctl_misc);
return;
}
