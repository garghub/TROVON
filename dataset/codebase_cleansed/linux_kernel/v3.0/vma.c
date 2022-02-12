static int __init init_vdso_vars(void)
{
int npages = (vdso_end - vdso_start + PAGE_SIZE - 1) / PAGE_SIZE;
int i;
vdso_size = npages << PAGE_SHIFT;
vdso_pages = kmalloc(sizeof(struct page *) * npages, GFP_KERNEL);
if (!vdso_pages)
goto oom;
for (i = 0; i < npages; i++) {
struct page *p;
p = alloc_page(GFP_KERNEL);
if (!p)
goto oom;
vdso_pages[i] = p;
copy_page(page_address(p), vdso_start + i*PAGE_SIZE);
}
return 0;
oom:
printk("Cannot allocate vdso\n");
vdso_enabled = 0;
return -ENOMEM;
}
static unsigned long vdso_addr(unsigned long start, unsigned len)
{
unsigned long addr, end;
unsigned offset;
end = (start + PMD_SIZE - 1) & PMD_MASK;
if (end >= TASK_SIZE_MAX)
end = TASK_SIZE_MAX;
end -= len;
offset = get_random_int() & (PTRS_PER_PTE - 1);
addr = start + (offset << PAGE_SHIFT);
if (addr >= end)
addr = end;
return addr;
}
int arch_setup_additional_pages(struct linux_binprm *bprm, int uses_interp)
{
struct mm_struct *mm = current->mm;
unsigned long addr;
int ret;
if (!vdso_enabled)
return 0;
down_write(&mm->mmap_sem);
addr = vdso_addr(mm->start_stack, vdso_size);
addr = get_unmapped_area(NULL, addr, vdso_size, 0, 0);
if (IS_ERR_VALUE(addr)) {
ret = addr;
goto up_fail;
}
current->mm->context.vdso = (void *)addr;
ret = install_special_mapping(mm, addr, vdso_size,
VM_READ|VM_EXEC|
VM_MAYREAD|VM_MAYWRITE|VM_MAYEXEC|
VM_ALWAYSDUMP,
vdso_pages);
if (ret) {
current->mm->context.vdso = NULL;
goto up_fail;
}
up_fail:
up_write(&mm->mmap_sem);
return ret;
}
static __init int vdso_setup(char *s)
{
vdso_enabled = simple_strtoul(s, NULL, 0);
return 0;
}
