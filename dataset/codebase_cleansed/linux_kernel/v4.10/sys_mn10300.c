asmlinkage long old_mmap(unsigned long addr, unsigned long len,
unsigned long prot, unsigned long flags,
unsigned long fd, unsigned long offset)
{
if (offset & ~PAGE_MASK)
return -EINVAL;
return sys_mmap_pgoff(addr, len, prot, flags, fd, offset >> PAGE_SHIFT);
}
