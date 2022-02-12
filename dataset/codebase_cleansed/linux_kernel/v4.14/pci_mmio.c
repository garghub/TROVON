static long get_pfn(unsigned long user_addr, unsigned long access,
unsigned long *pfn)
{
struct vm_area_struct *vma;
long ret;
down_read(&current->mm->mmap_sem);
ret = -EINVAL;
vma = find_vma(current->mm, user_addr);
if (!vma)
goto out;
ret = -EACCES;
if (!(vma->vm_flags & access))
goto out;
ret = follow_pfn(vma, user_addr, pfn);
out:
up_read(&current->mm->mmap_sem);
return ret;
}
