void elf_fdpic_arch_lay_out_mm(struct elf_fdpic_params *exec_params,
struct elf_fdpic_params *interp_params,
unsigned long *start_stack,
unsigned long *start_brk)
{
*start_stack = 0x02200000UL;
if (!(interp_params->flags & ELF_FDPIC_FLAG_PRESENT) &&
exec_params->hdr.e_type != ET_EXEC
) {
exec_params->load_addr = PAGE_SIZE;
*start_brk = 0x80000000UL;
}
else {
exec_params->load_addr = 0x02200000UL;
if ((exec_params->flags & ELF_FDPIC_FLAG_ARRANGEMENT) ==
ELF_FDPIC_FLAG_INDEPENDENT
) {
exec_params->flags &= ~ELF_FDPIC_FLAG_ARRANGEMENT;
exec_params->flags |= ELF_FDPIC_FLAG_CONSTDISP;
}
}
}
unsigned long arch_get_unmapped_area(struct file *filp, unsigned long addr, unsigned long len,
unsigned long pgoff, unsigned long flags)
{
struct vm_area_struct *vma;
struct vm_unmapped_area_info info;
if (len > TASK_SIZE)
return -ENOMEM;
if (flags & MAP_FIXED)
return addr;
if (addr) {
addr = PAGE_ALIGN(addr);
vma = find_vma(current->mm, addr);
if (TASK_SIZE - len >= addr &&
(!vma || addr + len <= vm_start_gap(vma)))
goto success;
}
info.flags = 0;
info.length = len;
info.low_limit = PAGE_SIZE;
info.high_limit = (current->mm->start_stack - 0x00200000);
info.align_mask = 0;
info.align_offset = 0;
addr = vm_unmapped_area(&info);
if (!(addr & ~PAGE_MASK))
goto success;
VM_BUG_ON(addr != -ENOMEM);
info.low_limit = PAGE_ALIGN(0x80000000);
info.high_limit = TASK_SIZE;
addr = vm_unmapped_area(&info);
if (!(addr & ~PAGE_MASK))
goto success;
VM_BUG_ON(addr != -ENOMEM);
#if 0
printk("[area] l=%lx (ENOMEM) f='%s'\n",
len, filp ? filp->f_path.dentry->d_name.name : "");
#endif
return -ENOMEM;
success:
#if 0
printk("[area] l=%lx ad=%lx f='%s'\n",
len, addr, filp ? filp->f_path.dentry->d_name.name : "");
#endif
return addr;
}
