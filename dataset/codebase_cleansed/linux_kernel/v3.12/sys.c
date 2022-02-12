ssize_t sys32_readahead(int fd, u32 offset_lo, u32 offset_hi, u32 count)
{
return sys_readahead(fd, ((loff_t)offset_hi << 32) | offset_lo, count);
}
int sys32_fadvise64_64(int fd, u32 offset_lo, u32 offset_hi,
u32 len_lo, u32 len_hi, int advice)
{
return sys_fadvise64_64(fd, ((loff_t)offset_hi << 32) | offset_lo,
((loff_t)len_hi << 32) | len_lo, advice);
}
