static int __init vdso_setup(char *s)
{
vdso_enabled = simple_strtoul(s, NULL, 0);
return 1;
}
int __init vsyscall_init(void)
{
void *syscall_page = (void *)get_zeroed_page(GFP_ATOMIC);
syscall_pages[0] = virt_to_page(syscall_page);
memcpy(syscall_page,
&vsyscall_trapa_start,
&vsyscall_trapa_end - &vsyscall_trapa_start);
return 0;
}
int arch_setup_additional_pages(struct linux_binprm *bprm, int uses_interp)
{
struct mm_struct *mm = current->mm;
unsigned long addr;
int ret;
if (down_write_killable(&mm->mmap_sem))
return -EINTR;
addr = get_unmapped_area(NULL, 0, PAGE_SIZE, 0, 0);
if (IS_ERR_VALUE(addr)) {
ret = addr;
goto up_fail;
}
ret = install_special_mapping(mm, addr, PAGE_SIZE,
VM_READ | VM_EXEC |
VM_MAYREAD | VM_MAYWRITE | VM_MAYEXEC,
syscall_pages);
if (unlikely(ret))
goto up_fail;
current->mm->context.vdso = (void *)addr;
up_fail:
up_write(&mm->mmap_sem);
return ret;
}
const char *arch_vma_name(struct vm_area_struct *vma)
{
if (vma->vm_mm && vma->vm_start == (long)vma->vm_mm->context.vdso)
return "[vdso]";
return NULL;
}
