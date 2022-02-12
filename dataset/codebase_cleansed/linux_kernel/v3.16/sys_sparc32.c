asmlinkage long sys32_truncate64(const char __user * path, unsigned long high, unsigned long low)
{
if ((int)high < 0)
return -EINVAL;
else
return sys_truncate(path, (high << 32) | low);
}
asmlinkage long sys32_ftruncate64(unsigned int fd, unsigned long high, unsigned long low)
{
if ((int)high < 0)
return -EINVAL;
else
return sys_ftruncate(fd, (high << 32) | low);
}
static int cp_compat_stat64(struct kstat *stat,
struct compat_stat64 __user *statbuf)
{
int err;
err = put_user(huge_encode_dev(stat->dev), &statbuf->st_dev);
err |= put_user(stat->ino, &statbuf->st_ino);
err |= put_user(stat->mode, &statbuf->st_mode);
err |= put_user(stat->nlink, &statbuf->st_nlink);
err |= put_user(from_kuid_munged(current_user_ns(), stat->uid), &statbuf->st_uid);
err |= put_user(from_kgid_munged(current_user_ns(), stat->gid), &statbuf->st_gid);
err |= put_user(huge_encode_dev(stat->rdev), &statbuf->st_rdev);
err |= put_user(0, (unsigned long __user *) &statbuf->__pad3[0]);
err |= put_user(stat->size, &statbuf->st_size);
err |= put_user(stat->blksize, &statbuf->st_blksize);
err |= put_user(0, (unsigned int __user *) &statbuf->__pad4[0]);
err |= put_user(0, (unsigned int __user *) &statbuf->__pad4[4]);
err |= put_user(stat->blocks, &statbuf->st_blocks);
err |= put_user(stat->atime.tv_sec, &statbuf->st_atime);
err |= put_user(stat->atime.tv_nsec, &statbuf->st_atime_nsec);
err |= put_user(stat->mtime.tv_sec, &statbuf->st_mtime);
err |= put_user(stat->mtime.tv_nsec, &statbuf->st_mtime_nsec);
err |= put_user(stat->ctime.tv_sec, &statbuf->st_ctime);
err |= put_user(stat->ctime.tv_nsec, &statbuf->st_ctime_nsec);
err |= put_user(0, &statbuf->__unused4);
err |= put_user(0, &statbuf->__unused5);
return err;
}
asmlinkage long compat_sys_stat64(const char __user * filename,
struct compat_stat64 __user *statbuf)
{
struct kstat stat;
int error = vfs_stat(filename, &stat);
if (!error)
error = cp_compat_stat64(&stat, statbuf);
return error;
}
asmlinkage long compat_sys_lstat64(const char __user * filename,
struct compat_stat64 __user *statbuf)
{
struct kstat stat;
int error = vfs_lstat(filename, &stat);
if (!error)
error = cp_compat_stat64(&stat, statbuf);
return error;
}
asmlinkage long compat_sys_fstat64(unsigned int fd,
struct compat_stat64 __user * statbuf)
{
struct kstat stat;
int error = vfs_fstat(fd, &stat);
if (!error)
error = cp_compat_stat64(&stat, statbuf);
return error;
}
asmlinkage long compat_sys_fstatat64(unsigned int dfd,
const char __user *filename,
struct compat_stat64 __user * statbuf, int flag)
{
struct kstat stat;
int error;
error = vfs_fstatat(dfd, filename, &stat, flag);
if (error)
return error;
return cp_compat_stat64(&stat, statbuf);
}
asmlinkage compat_ssize_t sys32_pread64(unsigned int fd,
char __user *ubuf,
compat_size_t count,
unsigned long poshi,
unsigned long poslo)
{
return sys_pread64(fd, ubuf, count, (poshi << 32) | poslo);
}
asmlinkage compat_ssize_t sys32_pwrite64(unsigned int fd,
char __user *ubuf,
compat_size_t count,
unsigned long poshi,
unsigned long poslo)
{
return sys_pwrite64(fd, ubuf, count, (poshi << 32) | poslo);
}
asmlinkage long compat_sys_readahead(int fd,
unsigned long offhi,
unsigned long offlo,
compat_size_t count)
{
return sys_readahead(fd, (offhi << 32) | offlo, count);
}
long compat_sys_fadvise64(int fd,
unsigned long offhi,
unsigned long offlo,
compat_size_t len, int advice)
{
return sys_fadvise64_64(fd, (offhi << 32) | offlo, len, advice);
}
long compat_sys_fadvise64_64(int fd,
unsigned long offhi, unsigned long offlo,
unsigned long lenhi, unsigned long lenlo,
int advice)
{
return sys_fadvise64_64(fd,
(offhi << 32) | offlo,
(lenhi << 32) | lenlo,
advice);
}
long sys32_sync_file_range(unsigned int fd, unsigned long off_high, unsigned long off_low, unsigned long nb_high, unsigned long nb_low, unsigned int flags)
{
return sys_sync_file_range(fd,
(off_high << 32) | off_low,
(nb_high << 32) | nb_low,
flags);
}
asmlinkage long compat_sys_fallocate(int fd, int mode, u32 offhi, u32 offlo,
u32 lenhi, u32 lenlo)
{
return sys_fallocate(fd, mode, ((loff_t)offhi << 32) | offlo,
((loff_t)lenhi << 32) | lenlo);
}
