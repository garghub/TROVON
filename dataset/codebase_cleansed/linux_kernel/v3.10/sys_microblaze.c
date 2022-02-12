asmlinkage long sys_mmap(unsigned long addr, unsigned long len,
unsigned long prot, unsigned long flags,
unsigned long fd, off_t pgoff)
{
if (pgoff & ~PAGE_MASK)
return -EINVAL;
return sys_mmap_pgoff(addr, len, prot, flags, fd, pgoff >> PAGE_SHIFT);
}
