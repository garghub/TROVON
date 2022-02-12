static int __init vdso_init(void)
{
struct hexagon_vdso *vdso;
vdso_page = alloc_page(GFP_KERNEL);
if (!vdso_page)
panic("Cannot allocate vdso");
vdso = vmap(&vdso_page, 1, 0, PAGE_KERNEL);
if (!vdso)
panic("Cannot map vdso");
clear_page(vdso);
vdso->rt_signal_trampoline[0] = __rt_sigtramp_template[0];
vdso->rt_signal_trampoline[1] = __rt_sigtramp_template[1];
vunmap(vdso);
return 0;
}
int arch_setup_additional_pages(struct linux_binprm *bprm, int uses_interp)
{
int ret;
unsigned long vdso_base;
struct mm_struct *mm = current->mm;
down_write(&mm->mmap_sem);
vdso_base = STACK_TOP;
vdso_base = get_unmapped_area(NULL, vdso_base, PAGE_SIZE, 0, 0);
if (IS_ERR_VALUE(vdso_base)) {
ret = vdso_base;
goto up_fail;
}
ret = install_special_mapping(mm, vdso_base, PAGE_SIZE,
VM_READ|VM_EXEC|
VM_MAYREAD|VM_MAYWRITE|VM_MAYEXEC|
VM_ALWAYSDUMP,
&vdso_page);
if (ret)
goto up_fail;
mm->context.vdso = (void *)vdso_base;
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
