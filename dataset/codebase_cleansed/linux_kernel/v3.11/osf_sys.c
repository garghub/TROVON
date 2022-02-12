static int
osf_filldir(void *__buf, const char *name, int namlen, loff_t offset,
u64 ino, unsigned int d_type)
{
struct osf_dirent __user *dirent;
struct osf_dirent_callback *buf = (struct osf_dirent_callback *) __buf;
unsigned int reclen = ALIGN(NAME_OFFSET + namlen + 1, sizeof(u32));
unsigned int d_ino;
buf->error = -EINVAL;
if (reclen > buf->count)
return -EINVAL;
d_ino = ino;
if (sizeof(d_ino) < sizeof(ino) && d_ino != ino) {
buf->error = -EOVERFLOW;
return -EOVERFLOW;
}
if (buf->basep) {
if (put_user(offset, buf->basep))
goto Efault;
buf->basep = NULL;
}
dirent = buf->dirent;
if (put_user(d_ino, &dirent->d_ino) ||
put_user(namlen, &dirent->d_namlen) ||
put_user(reclen, &dirent->d_reclen) ||
copy_to_user(dirent->d_name, name, namlen) ||
put_user(0, dirent->d_name + namlen))
goto Efault;
dirent = (void __user *)dirent + reclen;
buf->dirent = dirent;
buf->count -= reclen;
return 0;
Efault:
buf->error = -EFAULT;
return -EFAULT;
}
static int
linux_to_osf_stat(struct kstat *lstat, struct osf_stat __user *osf_stat)
{
struct osf_stat tmp = { 0 };
tmp.st_dev = lstat->dev;
tmp.st_mode = lstat->mode;
tmp.st_nlink = lstat->nlink;
tmp.st_uid = from_kuid_munged(current_user_ns(), lstat->uid);
tmp.st_gid = from_kgid_munged(current_user_ns(), lstat->gid);
tmp.st_rdev = lstat->rdev;
tmp.st_ldev = lstat->rdev;
tmp.st_size = lstat->size;
tmp.st_uatime = lstat->atime.tv_nsec / 1000;
tmp.st_umtime = lstat->mtime.tv_nsec / 1000;
tmp.st_uctime = lstat->ctime.tv_nsec / 1000;
tmp.st_ino = lstat->ino;
tmp.st_atime = lstat->atime.tv_sec;
tmp.st_mtime = lstat->mtime.tv_sec;
tmp.st_ctime = lstat->ctime.tv_sec;
tmp.st_blksize = lstat->blksize;
tmp.st_blocks = lstat->blocks;
return copy_to_user(osf_stat, &tmp, sizeof(tmp)) ? -EFAULT : 0;
}
static int
linux_to_osf_statfs(struct kstatfs *linux_stat, struct osf_statfs __user *osf_stat,
unsigned long bufsiz)
{
struct osf_statfs tmp_stat;
tmp_stat.f_type = linux_stat->f_type;
tmp_stat.f_flags = 0;
tmp_stat.f_fsize = linux_stat->f_frsize;
tmp_stat.f_bsize = linux_stat->f_bsize;
tmp_stat.f_blocks = linux_stat->f_blocks;
tmp_stat.f_bfree = linux_stat->f_bfree;
tmp_stat.f_bavail = linux_stat->f_bavail;
tmp_stat.f_files = linux_stat->f_files;
tmp_stat.f_ffree = linux_stat->f_ffree;
tmp_stat.f_fsid = linux_stat->f_fsid;
if (bufsiz > sizeof(tmp_stat))
bufsiz = sizeof(tmp_stat);
return copy_to_user(osf_stat, &tmp_stat, bufsiz) ? -EFAULT : 0;
}
static int
linux_to_osf_statfs64(struct kstatfs *linux_stat, struct osf_statfs64 __user *osf_stat,
unsigned long bufsiz)
{
struct osf_statfs64 tmp_stat = { 0 };
tmp_stat.f_type = linux_stat->f_type;
tmp_stat.f_fsize = linux_stat->f_frsize;
tmp_stat.f_bsize = linux_stat->f_bsize;
tmp_stat.f_blocks = linux_stat->f_blocks;
tmp_stat.f_bfree = linux_stat->f_bfree;
tmp_stat.f_bavail = linux_stat->f_bavail;
tmp_stat.f_files = linux_stat->f_files;
tmp_stat.f_ffree = linux_stat->f_ffree;
tmp_stat.f_fsid = linux_stat->f_fsid;
if (bufsiz > sizeof(tmp_stat))
bufsiz = sizeof(tmp_stat);
return copy_to_user(osf_stat, &tmp_stat, bufsiz) ? -EFAULT : 0;
}
static int
osf_ufs_mount(const char *dirname, struct ufs_args __user *args, int flags)
{
int retval;
struct cdfs_args tmp;
struct filename *devname;
retval = -EFAULT;
if (copy_from_user(&tmp, args, sizeof(tmp)))
goto out;
devname = getname(tmp.devname);
retval = PTR_ERR(devname);
if (IS_ERR(devname))
goto out;
retval = do_mount(devname->name, dirname, "ext2", flags, NULL);
putname(devname);
out:
return retval;
}
static int
osf_cdfs_mount(const char *dirname, struct cdfs_args __user *args, int flags)
{
int retval;
struct cdfs_args tmp;
struct filename *devname;
retval = -EFAULT;
if (copy_from_user(&tmp, args, sizeof(tmp)))
goto out;
devname = getname(tmp.devname);
retval = PTR_ERR(devname);
if (IS_ERR(devname))
goto out;
retval = do_mount(devname->name, dirname, "iso9660", flags, NULL);
putname(devname);
out:
return retval;
}
static int
osf_procfs_mount(const char *dirname, struct procfs_args __user *args, int flags)
{
struct procfs_args tmp;
if (copy_from_user(&tmp, args, sizeof(tmp)))
return -EFAULT;
return do_mount("", dirname, "proc", flags, NULL);
}
static inline long
get_tv32(struct timeval *o, struct timeval32 __user *i)
{
return (!access_ok(VERIFY_READ, i, sizeof(*i)) ||
(__get_user(o->tv_sec, &i->tv_sec) |
__get_user(o->tv_usec, &i->tv_usec)));
}
static inline long
put_tv32(struct timeval32 __user *o, struct timeval *i)
{
return (!access_ok(VERIFY_WRITE, o, sizeof(*o)) ||
(__put_user(i->tv_sec, &o->tv_sec) |
__put_user(i->tv_usec, &o->tv_usec)));
}
static inline long
get_it32(struct itimerval *o, struct itimerval32 __user *i)
{
return (!access_ok(VERIFY_READ, i, sizeof(*i)) ||
(__get_user(o->it_interval.tv_sec, &i->it_interval.tv_sec) |
__get_user(o->it_interval.tv_usec, &i->it_interval.tv_usec) |
__get_user(o->it_value.tv_sec, &i->it_value.tv_sec) |
__get_user(o->it_value.tv_usec, &i->it_value.tv_usec)));
}
static inline long
put_it32(struct itimerval32 __user *o, struct itimerval *i)
{
return (!access_ok(VERIFY_WRITE, o, sizeof(*o)) ||
(__put_user(i->it_interval.tv_sec, &o->it_interval.tv_sec) |
__put_user(i->it_interval.tv_usec, &o->it_interval.tv_usec) |
__put_user(i->it_value.tv_sec, &o->it_value.tv_sec) |
__put_user(i->it_value.tv_usec, &o->it_value.tv_usec)));
}
static inline void
jiffies_to_timeval32(unsigned long jiffies, struct timeval32 *value)
{
value->tv_usec = (jiffies % HZ) * (1000000L / HZ);
value->tv_sec = jiffies / HZ;
}
static unsigned long
arch_get_unmapped_area_1(unsigned long addr, unsigned long len,
unsigned long limit)
{
struct vm_unmapped_area_info info;
info.flags = 0;
info.length = len;
info.low_limit = addr;
info.high_limit = limit;
info.align_mask = 0;
info.align_offset = 0;
return vm_unmapped_area(&info);
}
unsigned long
arch_get_unmapped_area(struct file *filp, unsigned long addr,
unsigned long len, unsigned long pgoff,
unsigned long flags)
{
unsigned long limit;
if (current->personality & ADDR_LIMIT_32BIT)
limit = 0x80000000;
else
limit = TASK_SIZE;
if (len > limit)
return -ENOMEM;
if (flags & MAP_FIXED)
return addr;
if (addr) {
addr = arch_get_unmapped_area_1 (PAGE_ALIGN(addr), len, limit);
if (addr != (unsigned long) -ENOMEM)
return addr;
}
addr = arch_get_unmapped_area_1 (PAGE_ALIGN(TASK_UNMAPPED_BASE),
len, limit);
if (addr != (unsigned long) -ENOMEM)
return addr;
addr = arch_get_unmapped_area_1 (PAGE_SIZE, len, limit);
return addr;
}
static int
osf_fix_iov_len(const struct iovec __user *iov, unsigned long count)
{
unsigned long i;
for (i = 0 ; i < count ; i++) {
int __user *iov_len_high = (int __user *)&iov[i].iov_len + 1;
if (put_user(0, iov_len_high))
return -EFAULT;
}
return 0;
}
