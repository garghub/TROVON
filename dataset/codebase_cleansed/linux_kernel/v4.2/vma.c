static int __init init_vdso(void)
{
struct page *um_vdso;
BUG_ON(vdso_end - vdso_start > PAGE_SIZE);
um_vdso_addr = task_size - PAGE_SIZE;
vdsop = kmalloc(sizeof(struct page *), GFP_KERNEL);
if (!vdsop)
goto oom;
um_vdso = alloc_page(GFP_KERNEL);
if (!um_vdso) {
kfree(vdsop);
goto oom;
}
copy_page(page_address(um_vdso), vdso_start);
*vdsop = um_vdso;
return 0;
oom:
printk(KERN_ERR "Cannot allocate vdso\n");
vdso_enabled = 0;
return -ENOMEM;
}
int arch_setup_additional_pages(struct linux_binprm *bprm, int uses_interp)
{
int err;
struct mm_struct *mm = current->mm;
if (!vdso_enabled)
return 0;
down_write(&mm->mmap_sem);
err = install_special_mapping(mm, um_vdso_addr, PAGE_SIZE,
VM_READ|VM_EXEC|
VM_MAYREAD|VM_MAYWRITE|VM_MAYEXEC,
vdsop);
up_write(&mm->mmap_sem);
return err;
}
