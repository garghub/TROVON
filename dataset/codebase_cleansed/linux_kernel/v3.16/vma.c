void __init init_vdso_image(const struct vdso_image *image)
{
int i;
int npages = (image->size) / PAGE_SIZE;
BUG_ON(image->size % PAGE_SIZE != 0);
for (i = 0; i < npages; i++)
image->text_mapping.pages[i] =
virt_to_page(image->data + i*PAGE_SIZE);
apply_alternatives((struct alt_instr *)(image->data + image->alt),
(struct alt_instr *)(image->data + image->alt +
image->alt_len));
}
static int __init init_vdso(void)
{
init_vdso_image(&vdso_image_64);
#ifdef CONFIG_X86_X32_ABI
init_vdso_image(&vdso_image_x32);
#endif
return 0;
}
static unsigned long vdso_addr(unsigned long start, unsigned len)
{
#ifdef CONFIG_X86_32
return 0;
#else
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
addr = PAGE_ALIGN(addr);
addr = align_vdso_addr(addr);
return addr;
#endif
}
static int map_vdso(const struct vdso_image *image, bool calculate_addr)
{
struct mm_struct *mm = current->mm;
struct vm_area_struct *vma;
unsigned long addr;
int ret = 0;
static struct page *no_pages[] = {NULL};
static struct vm_special_mapping vvar_mapping = {
.name = "[vvar]",
.pages = no_pages,
};
if (calculate_addr) {
addr = vdso_addr(current->mm->start_stack,
image->sym_end_mapping);
} else {
addr = 0;
}
down_write(&mm->mmap_sem);
addr = get_unmapped_area(NULL, addr, image->sym_end_mapping, 0, 0);
if (IS_ERR_VALUE(addr)) {
ret = addr;
goto up_fail;
}
current->mm->context.vdso = (void __user *)addr;
vma = _install_special_mapping(mm,
addr,
image->size,
VM_READ|VM_EXEC|
VM_MAYREAD|VM_MAYWRITE|VM_MAYEXEC,
&image->text_mapping);
if (IS_ERR(vma)) {
ret = PTR_ERR(vma);
goto up_fail;
}
vma = _install_special_mapping(mm,
addr + image->size,
image->sym_end_mapping - image->size,
VM_READ,
&vvar_mapping);
if (IS_ERR(vma)) {
ret = PTR_ERR(vma);
goto up_fail;
}
if (image->sym_vvar_page)
ret = remap_pfn_range(vma,
addr + image->sym_vvar_page,
__pa_symbol(&__vvar_page) >> PAGE_SHIFT,
PAGE_SIZE,
PAGE_READONLY);
if (ret)
goto up_fail;
#ifdef CONFIG_HPET_TIMER
if (hpet_address && image->sym_hpet_page) {
ret = io_remap_pfn_range(vma,
addr + image->sym_hpet_page,
hpet_address >> PAGE_SHIFT,
PAGE_SIZE,
pgprot_noncached(PAGE_READONLY));
if (ret)
goto up_fail;
}
#endif
up_fail:
if (ret)
current->mm->context.vdso = NULL;
up_write(&mm->mmap_sem);
return ret;
}
static int load_vdso32(void)
{
int ret;
if (vdso32_enabled != 1)
return 0;
ret = map_vdso(selected_vdso32, false);
if (ret)
return ret;
if (selected_vdso32->sym_VDSO32_SYSENTER_RETURN)
current_thread_info()->sysenter_return =
current->mm->context.vdso +
selected_vdso32->sym_VDSO32_SYSENTER_RETURN;
return 0;
}
int arch_setup_additional_pages(struct linux_binprm *bprm, int uses_interp)
{
if (!vdso64_enabled)
return 0;
return map_vdso(&vdso_image_64, true);
}
int compat_arch_setup_additional_pages(struct linux_binprm *bprm,
int uses_interp)
{
#ifdef CONFIG_X86_X32_ABI
if (test_thread_flag(TIF_X32)) {
if (!vdso64_enabled)
return 0;
return map_vdso(&vdso_image_x32, true);
}
#endif
return load_vdso32();
}
int arch_setup_additional_pages(struct linux_binprm *bprm, int uses_interp)
{
return load_vdso32();
}
static __init int vdso_setup(char *s)
{
vdso64_enabled = simple_strtoul(s, NULL, 0);
return 0;
}
