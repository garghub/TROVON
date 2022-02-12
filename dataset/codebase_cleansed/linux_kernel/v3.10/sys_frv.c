asmlinkage long sys_mmap2(unsigned long addr, unsigned long len,
unsigned long prot, unsigned long flags,
unsigned long fd, unsigned long pgoff)
{
if (pgoff & ((1 << (PAGE_SHIFT - 12)) - 1))
return -EINVAL;
return sys_mmap_pgoff(addr, len, prot, flags, fd,
pgoff >> (PAGE_SHIFT - 12));
}
