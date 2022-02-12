SYSCALL_DEFINE(s390_fallocate)(int fd, int mode, loff_t offset,
u32 len_high, u32 len_low)
{
return sys_fallocate(fd, mode, offset, ((u64)len_high << 32) | len_low);
}
asmlinkage long SyS_s390_fallocate(long fd, long mode, loff_t offset,
long len_high, long len_low)
{
return SYSC_s390_fallocate((int) fd, (int) mode, offset,
(u32) len_high, (u32) len_low);
}
