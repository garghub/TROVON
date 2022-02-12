asmlinkage long
sys_mmap2(unsigned long addr, unsigned long len, unsigned long prot,
unsigned long flags, unsigned long fd, unsigned long pgoff)
{
return sys_mmap_pgoff(addr, len, prot, flags, fd, pgoff);
}
