asmlinkage int sys_cacheflush(unsigned long addr, unsigned long len,
unsigned int op)
{
struct vm_area_struct *vma;
if (len == 0)
return 0;
if (op)
return -EINVAL;
if (addr + len < addr)
return -EFAULT;
vma = find_vma(current->mm, addr);
if (vma == NULL || addr < vma->vm_start || addr + len > vma->vm_end)
return -EFAULT;
flush_cache_range(vma, addr, addr + len);
return 0;
}
asmlinkage int sys_getpagesize(void)
{
return PAGE_SIZE;
}
