asmlinkage long ppc32_select(u32 n, compat_ulong_t __user *inp,
compat_ulong_t __user *outp, compat_ulong_t __user *exp,
compat_uptr_t tvp_x)
{
return compat_sys_select((int)n, inp, outp, exp, compat_ptr(tvp_x));
}
unsigned long compat_sys_mmap2(unsigned long addr, size_t len,
unsigned long prot, unsigned long flags,
unsigned long fd, unsigned long pgoff)
{
return sys_mmap(addr, len, prot, flags, fd, pgoff << 12);
}
compat_ssize_t compat_sys_pread64(unsigned int fd, char __user *ubuf, compat_size_t count,
u32 reg6, u32 poshi, u32 poslo)
{
return sys_pread64(fd, ubuf, count, ((loff_t)poshi << 32) | poslo);
}
compat_ssize_t compat_sys_pwrite64(unsigned int fd, const char __user *ubuf, compat_size_t count,
u32 reg6, u32 poshi, u32 poslo)
{
return sys_pwrite64(fd, ubuf, count, ((loff_t)poshi << 32) | poslo);
}
compat_ssize_t compat_sys_readahead(int fd, u32 r4, u32 offhi, u32 offlo, u32 count)
{
return sys_readahead(fd, ((loff_t)offhi << 32) | offlo, count);
}
asmlinkage int compat_sys_truncate64(const char __user * path, u32 reg4,
unsigned long high, unsigned long low)
{
return sys_truncate(path, (high << 32) | low);
}
asmlinkage long compat_sys_fallocate(int fd, int mode, u32 offhi, u32 offlo,
u32 lenhi, u32 lenlo)
{
return sys_fallocate(fd, mode, ((loff_t)offhi << 32) | offlo,
((loff_t)lenhi << 32) | lenlo);
}
asmlinkage int compat_sys_ftruncate64(unsigned int fd, u32 reg4, unsigned long high,
unsigned long low)
{
return sys_ftruncate(fd, (high << 32) | low);
}
long ppc32_fadvise64(int fd, u32 unused, u32 offset_high, u32 offset_low,
size_t len, int advice)
{
return sys_fadvise64(fd, (u64)offset_high << 32 | offset_low, len,
advice);
}
asmlinkage long compat_sys_sync_file_range2(int fd, unsigned int flags,
unsigned offset_hi, unsigned offset_lo,
unsigned nbytes_hi, unsigned nbytes_lo)
{
loff_t offset = ((loff_t)offset_hi << 32) | offset_lo;
loff_t nbytes = ((loff_t)nbytes_hi << 32) | nbytes_lo;
return sys_sync_file_range(fd, offset, nbytes, flags);
}
