asmlinkage long sys_arm_fadvise64_64(int fd, int advice,
loff_t offset, loff_t len)
{
return sys_fadvise64_64(fd, offset, len, advice);
}
