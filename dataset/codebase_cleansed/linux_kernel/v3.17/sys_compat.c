static inline void
do_compat_cache_op(unsigned long start, unsigned long end, int flags)
{
struct mm_struct *mm = current->active_mm;
struct vm_area_struct *vma;
if (end < start || flags)
return;
down_read(&mm->mmap_sem);
vma = find_vma(mm, start);
if (vma && vma->vm_start < end) {
if (start < vma->vm_start)
start = vma->vm_start;
if (end > vma->vm_end)
end = vma->vm_end;
up_read(&mm->mmap_sem);
__flush_cache_user_range(start & PAGE_MASK, PAGE_ALIGN(end));
return;
}
up_read(&mm->mmap_sem);
}
long compat_arm_syscall(struct pt_regs *regs)
{
unsigned int no = regs->regs[7];
switch (no) {
case __ARM_NR_compat_cacheflush:
do_compat_cache_op(regs->regs[0], regs->regs[1], regs->regs[2]);
return 0;
case __ARM_NR_compat_set_tls:
current->thread.tp_value = regs->regs[0];
barrier();
asm ("msr tpidrro_el0, %0" : : "r" (regs->regs[0]));
return 0;
default:
return -ENOSYS;
}
}
