asmlinkage long sys32_truncate64(const char __user *filename,
unsigned long offset_low,
unsigned long offset_high)
{
return sys_truncate(filename, ((loff_t) offset_high << 32) | offset_low);
}
asmlinkage long sys32_ftruncate64(unsigned int fd, unsigned long offset_low,
unsigned long offset_high)
{
return sys_ftruncate(fd, ((loff_t) offset_high << 32) | offset_low);
}
static int cp_stat64(struct stat64 __user *ubuf, struct kstat *stat)
{
typeof(ubuf->st_uid) uid = 0;
typeof(ubuf->st_gid) gid = 0;
SET_UID(uid, from_kuid_munged(current_user_ns(), stat->uid));
SET_GID(gid, from_kgid_munged(current_user_ns(), stat->gid));
if (!access_ok(VERIFY_WRITE, ubuf, sizeof(struct stat64)) ||
__put_user(huge_encode_dev(stat->dev), &ubuf->st_dev) ||
__put_user(stat->ino, &ubuf->__st_ino) ||
__put_user(stat->ino, &ubuf->st_ino) ||
__put_user(stat->mode, &ubuf->st_mode) ||
__put_user(stat->nlink, &ubuf->st_nlink) ||
__put_user(uid, &ubuf->st_uid) ||
__put_user(gid, &ubuf->st_gid) ||
__put_user(huge_encode_dev(stat->rdev), &ubuf->st_rdev) ||
__put_user(stat->size, &ubuf->st_size) ||
__put_user(stat->atime.tv_sec, &ubuf->st_atime) ||
__put_user(stat->atime.tv_nsec, &ubuf->st_atime_nsec) ||
__put_user(stat->mtime.tv_sec, &ubuf->st_mtime) ||
__put_user(stat->mtime.tv_nsec, &ubuf->st_mtime_nsec) ||
__put_user(stat->ctime.tv_sec, &ubuf->st_ctime) ||
__put_user(stat->ctime.tv_nsec, &ubuf->st_ctime_nsec) ||
__put_user(stat->blksize, &ubuf->st_blksize) ||
__put_user(stat->blocks, &ubuf->st_blocks))
return -EFAULT;
return 0;
}
asmlinkage long sys32_stat64(const char __user *filename,
struct stat64 __user *statbuf)
{
struct kstat stat;
int ret = vfs_stat(filename, &stat);
if (!ret)
ret = cp_stat64(statbuf, &stat);
return ret;
}
asmlinkage long sys32_lstat64(const char __user *filename,
struct stat64 __user *statbuf)
{
struct kstat stat;
int ret = vfs_lstat(filename, &stat);
if (!ret)
ret = cp_stat64(statbuf, &stat);
return ret;
}
asmlinkage long sys32_fstat64(unsigned int fd, struct stat64 __user *statbuf)
{
struct kstat stat;
int ret = vfs_fstat(fd, &stat);
if (!ret)
ret = cp_stat64(statbuf, &stat);
return ret;
}
asmlinkage long sys32_fstatat(unsigned int dfd, const char __user *filename,
struct stat64 __user *statbuf, int flag)
{
struct kstat stat;
int error;
error = vfs_fstatat(dfd, filename, &stat, flag);
if (error)
return error;
return cp_stat64(statbuf, &stat);
}
asmlinkage long sys32_mmap(struct mmap_arg_struct32 __user *arg)
{
struct mmap_arg_struct32 a;
if (copy_from_user(&a, arg, sizeof(a)))
return -EFAULT;
if (a.offset & ~PAGE_MASK)
return -EINVAL;
return sys_mmap_pgoff(a.addr, a.len, a.prot, a.flags, a.fd,
a.offset>>PAGE_SHIFT);
}
asmlinkage long sys32_mprotect(unsigned long start, size_t len,
unsigned long prot)
{
return sys_mprotect(start, len, prot);
}
asmlinkage long sys32_waitpid(compat_pid_t pid, unsigned int __user *stat_addr,
int options)
{
return compat_sys_wait4(pid, stat_addr, options, NULL);
}
asmlinkage long sys32_pread(unsigned int fd, char __user *ubuf, u32 count,
u32 poslo, u32 poshi)
{
return sys_pread64(fd, ubuf, count,
((loff_t)AA(poshi) << 32) | AA(poslo));
}
asmlinkage long sys32_pwrite(unsigned int fd, const char __user *ubuf,
u32 count, u32 poslo, u32 poshi)
{
return sys_pwrite64(fd, ubuf, count,
((loff_t)AA(poshi) << 32) | AA(poslo));
}
asmlinkage long sys32_sendfile(int out_fd, int in_fd,
compat_off_t __user *offset, s32 count)
{
mm_segment_t old_fs = get_fs();
int ret;
off_t of;
if (offset && get_user(of, offset))
return -EFAULT;
set_fs(KERNEL_DS);
ret = sys_sendfile(out_fd, in_fd, offset ? (off_t __user *)&of : NULL,
count);
set_fs(old_fs);
if (offset && put_user(of, offset))
return -EFAULT;
return ret;
}
long sys32_kill(int pid, int sig)
{
return sys_kill(pid, sig);
}
long sys32_fadvise64_64(int fd, __u32 offset_low, __u32 offset_high,
__u32 len_low, __u32 len_high, int advice)
{
return sys_fadvise64_64(fd,
(((u64)offset_high)<<32) | offset_low,
(((u64)len_high)<<32) | len_low,
advice);
}
long sys32_vm86_warning(void)
{
struct task_struct *me = current;
static char lastcomm[sizeof(me->comm)];
if (strncmp(lastcomm, me->comm, sizeof(lastcomm))) {
compat_printk(KERN_INFO
"%s: vm86 mode not supported on 64 bit kernel\n",
me->comm);
strncpy(lastcomm, me->comm, sizeof(lastcomm));
}
return -ENOSYS;
}
long sys32_lookup_dcookie(u32 addr_low, u32 addr_high,
char __user *buf, size_t len)
{
return sys_lookup_dcookie(((u64)addr_high << 32) | addr_low, buf, len);
}
asmlinkage ssize_t sys32_readahead(int fd, unsigned off_lo, unsigned off_hi,
size_t count)
{
return sys_readahead(fd, ((u64)off_hi << 32) | off_lo, count);
}
asmlinkage long sys32_sync_file_range(int fd, unsigned off_low, unsigned off_hi,
unsigned n_low, unsigned n_hi, int flags)
{
return sys_sync_file_range(fd,
((u64)off_hi << 32) | off_low,
((u64)n_hi << 32) | n_low, flags);
}
asmlinkage long sys32_fadvise64(int fd, unsigned offset_lo, unsigned offset_hi,
size_t len, int advice)
{
return sys_fadvise64_64(fd, ((u64)offset_hi << 32) | offset_lo,
len, advice);
}
asmlinkage long sys32_fallocate(int fd, int mode, unsigned offset_lo,
unsigned offset_hi, unsigned len_lo,
unsigned len_hi)
{
return sys_fallocate(fd, mode, ((u64)offset_hi << 32) | offset_lo,
((u64)len_hi << 32) | len_lo);
}
asmlinkage long sys32_fanotify_mark(int fanotify_fd, unsigned int flags,
u32 mask_lo, u32 mask_hi,
int fd, const char __user *pathname)
{
return sys_fanotify_mark(fanotify_fd, flags,
((u64)mask_hi << 32) | mask_lo,
fd, pathname);
}
