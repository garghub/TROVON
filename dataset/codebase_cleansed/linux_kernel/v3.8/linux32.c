asmlinkage ssize_t sys32_readahead(int fd, u32 pad0, u64 a2, u64 a3,
size_t count)
{
return sys_readahead(fd, merge_64(a2, a3), count);
}
asmlinkage long sys32_sync_file_range(int fd, int __pad,
unsigned long a2, unsigned long a3,
unsigned long a4, unsigned long a5,
int flags)
{
return sys_sync_file_range(fd,
merge_64(a2, a3), merge_64(a4, a5),
flags);
}
asmlinkage long sys32_fadvise64_64(int fd, int __pad,
unsigned long a2, unsigned long a3,
unsigned long a4, unsigned long a5,
int flags)
{
return sys_fadvise64_64(fd,
merge_64(a2, a3), merge_64(a4, a5),
flags);
}
asmlinkage long sys32_fallocate(int fd, int mode, unsigned offset_a2,
unsigned offset_a3, unsigned len_a4, unsigned len_a5)
{
return sys_fallocate(fd, mode, merge_64(offset_a2, offset_a3),
merge_64(len_a4, len_a5));
}
static int noinline __used
_sys32_clone(nabi_no_regargs struct pt_regs regs)
{
unsigned long clone_flags;
unsigned long newsp;
int __user *parent_tidptr, *child_tidptr;
clone_flags = regs.regs[4];
newsp = regs.regs[5];
if (!newsp)
newsp = regs.regs[29];
parent_tidptr = (int __user *) regs.regs[6];
child_tidptr = (int __user *) __dummy4;
return do_fork(clone_flags, newsp, 0,
parent_tidptr, child_tidptr);
}
asmlinkage long sys32_lookup_dcookie(u32 a0, u32 a1, char __user *buf,
size_t len)
{
return sys_lookup_dcookie(merge_64(a0, a1), buf, len);
}
