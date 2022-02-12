asmlinkage long ppc32_select(u32 n, compat_ulong_t __user *inp,
compat_ulong_t __user *outp, compat_ulong_t __user *exp,
compat_uptr_t tvp_x)
{
return compat_sys_select((int)n, inp, outp, exp, compat_ptr(tvp_x));
}
long compat_sys_ipc(u32 call, u32 first, u32 second, u32 third, compat_uptr_t ptr,
u32 fifth)
{
int version;
version = call >> 16;
call &= 0xffff;
switch (call) {
case SEMTIMEDOP:
if (fifth)
return compat_sys_semtimedop((int)first,
compat_ptr(ptr), second,
compat_ptr(fifth));
case SEMOP:
return sys_semtimedop((int)first, compat_ptr(ptr), second,
NULL);
case SEMGET:
return sys_semget((int)first, (int)second, third);
case SEMCTL:
return compat_sys_semctl((int)first, (int)second, third,
compat_ptr(ptr));
case MSGSND:
return compat_sys_msgsnd((int)first, (int)second, third,
compat_ptr(ptr));
case MSGRCV:
return compat_sys_msgrcv((int)first, second, (int)fifth,
third, version, compat_ptr(ptr));
case MSGGET:
return sys_msgget((int)first, second);
case MSGCTL:
return compat_sys_msgctl((int)first, second, compat_ptr(ptr));
case SHMAT:
return compat_sys_shmat((int)first, second, third, version,
compat_ptr(ptr));
case SHMDT:
return sys_shmdt(compat_ptr(ptr));
case SHMGET:
return sys_shmget((int)first, second, third);
case SHMCTL:
return compat_sys_shmctl((int)first, second, compat_ptr(ptr));
default:
return -ENOSYS;
}
return -ENOSYS;
}
asmlinkage long compat_sys_sendfile_wrapper(u32 out_fd, u32 in_fd,
compat_off_t __user *offset, u32 count)
{
return compat_sys_sendfile((int)out_fd, (int)in_fd, offset, count);
}
asmlinkage long compat_sys_sendfile64_wrapper(u32 out_fd, u32 in_fd,
compat_loff_t __user *offset, u32 count)
{
return sys_sendfile((int)out_fd, (int)in_fd,
(off_t __user *)offset, count);
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
long ppc32_lookup_dcookie(u32 cookie_high, u32 cookie_low, char __user *buf,
size_t len)
{
return sys_lookup_dcookie((u64)cookie_high << 32 | cookie_low,
buf, len);
}
long ppc32_fadvise64(int fd, u32 unused, u32 offset_high, u32 offset_low,
size_t len, int advice)
{
return sys_fadvise64(fd, (u64)offset_high << 32 | offset_low, len,
advice);
}
asmlinkage long compat_sys_add_key(const char __user *_type,
const char __user *_description,
const void __user *_payload,
u32 plen,
u32 ringid)
{
return sys_add_key(_type, _description, _payload, plen, ringid);
}
asmlinkage long compat_sys_request_key(const char __user *_type,
const char __user *_description,
const char __user *_callout_info,
u32 destringid)
{
return sys_request_key(_type, _description, _callout_info, destringid);
}
asmlinkage long compat_sys_sync_file_range2(int fd, unsigned int flags,
unsigned offset_hi, unsigned offset_lo,
unsigned nbytes_hi, unsigned nbytes_lo)
{
loff_t offset = ((loff_t)offset_hi << 32) | offset_lo;
loff_t nbytes = ((loff_t)nbytes_hi << 32) | nbytes_lo;
return sys_sync_file_range(fd, offset, nbytes, flags);
}
asmlinkage long compat_sys_fanotify_mark(int fanotify_fd, unsigned int flags,
unsigned mask_hi, unsigned mask_lo,
int dfd, const char __user *pathname)
{
u64 mask = ((u64)mask_hi << 32) | mask_lo;
return sys_fanotify_mark(fanotify_fd, flags, mask, dfd, pathname);
}
