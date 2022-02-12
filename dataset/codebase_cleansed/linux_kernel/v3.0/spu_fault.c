int spu_handle_mm_fault(struct mm_struct *mm, unsigned long ea,
unsigned long dsisr, unsigned *flt)
{
struct vm_area_struct *vma;
unsigned long is_write;
int ret;
if (mm == NULL)
return -EFAULT;
if (mm->pgd == NULL)
return -EFAULT;
down_read(&mm->mmap_sem);
ret = -EFAULT;
vma = find_vma(mm, ea);
if (!vma)
goto out_unlock;
if (ea < vma->vm_start) {
if (!(vma->vm_flags & VM_GROWSDOWN))
goto out_unlock;
if (expand_stack(vma, ea))
goto out_unlock;
}
is_write = dsisr & MFC_DSISR_ACCESS_PUT;
if (is_write) {
if (!(vma->vm_flags & VM_WRITE))
goto out_unlock;
} else {
if (dsisr & MFC_DSISR_ACCESS_DENIED)
goto out_unlock;
if (!(vma->vm_flags & (VM_READ | VM_EXEC)))
goto out_unlock;
}
ret = 0;
*flt = handle_mm_fault(mm, vma, ea, is_write ? FAULT_FLAG_WRITE : 0);
if (unlikely(*flt & VM_FAULT_ERROR)) {
if (*flt & VM_FAULT_OOM) {
ret = -ENOMEM;
goto out_unlock;
} else if (*flt & VM_FAULT_SIGBUS) {
ret = -EFAULT;
goto out_unlock;
}
BUG();
}
if (*flt & VM_FAULT_MAJOR)
current->maj_flt++;
else
current->min_flt++;
out_unlock:
up_read(&mm->mmap_sem);
return ret;
}
