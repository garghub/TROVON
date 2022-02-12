static int __init vdso_setup(char *s)
{
vdso_enabled = simple_strtoul(s, NULL, 0);
if (vdso_enabled > 1)
pr_warn("vdso32 values other than 0 and 1 are no longer allowed; vdso disabled\n");
return 1;
}
void syscall32_cpu_init(void)
{
wrmsrl_safe(MSR_IA32_SYSENTER_CS, (u64)__KERNEL_CS);
wrmsrl_safe(MSR_IA32_SYSENTER_ESP, 0ULL);
wrmsrl_safe(MSR_IA32_SYSENTER_EIP, (u64)ia32_sysenter_target);
wrmsrl(MSR_CSTAR, ia32_cstar_target);
}
void enable_sep_cpu(void)
{
int cpu = get_cpu();
struct tss_struct *tss = &per_cpu(init_tss, cpu);
if (!boot_cpu_has(X86_FEATURE_SEP)) {
put_cpu();
return;
}
tss->x86_tss.ss1 = __KERNEL_CS;
tss->x86_tss.sp1 = sizeof(struct tss_struct) + (unsigned long) tss;
wrmsr(MSR_IA32_SYSENTER_CS, __KERNEL_CS, 0);
wrmsr(MSR_IA32_SYSENTER_ESP, tss->x86_tss.sp1, 0);
wrmsr(MSR_IA32_SYSENTER_EIP, (unsigned long) ia32_sysenter_target, 0);
put_cpu();
}
int __init sysenter_setup(void)
{
char *vdso32_start, *vdso32_end;
int npages, i;
#ifdef CONFIG_COMPAT
if (vdso32_syscall()) {
vdso32_start = vdso32_syscall_start;
vdso32_end = vdso32_syscall_end;
vdso32_pages = vdso32_syscall_pages;
} else
#endif
if (vdso32_sysenter()) {
vdso32_start = vdso32_sysenter_start;
vdso32_end = vdso32_sysenter_end;
vdso32_pages = vdso32_sysenter_pages;
} else {
vdso32_start = vdso32_int80_start;
vdso32_end = vdso32_int80_end;
vdso32_pages = vdso32_int80_pages;
}
npages = ((vdso32_end - vdso32_start) + PAGE_SIZE - 1) / PAGE_SIZE;
vdso32_size = npages << PAGE_SHIFT;
for (i = 0; i < npages; i++)
vdso32_pages[i] = virt_to_page(vdso32_start + i*PAGE_SIZE);
patch_vdso32(vdso32_start, vdso32_size);
return 0;
}
int arch_setup_additional_pages(struct linux_binprm *bprm, int uses_interp)
{
struct mm_struct *mm = current->mm;
unsigned long addr;
int ret = 0;
struct vm_area_struct *vma;
static struct page *no_pages[] = {NULL};
#ifdef CONFIG_X86_X32_ABI
if (test_thread_flag(TIF_X32))
return x32_setup_additional_pages(bprm, uses_interp);
#endif
if (vdso_enabled != 1)
return 0;
down_write(&mm->mmap_sem);
addr = get_unmapped_area(NULL, 0, vdso32_size + VDSO_OFFSET(VDSO_PREV_PAGES), 0, 0);
if (IS_ERR_VALUE(addr)) {
ret = addr;
goto up_fail;
}
addr += VDSO_OFFSET(VDSO_PREV_PAGES);
current->mm->context.vdso = (void *)addr;
ret = install_special_mapping(mm,
addr,
vdso32_size,
VM_READ|VM_EXEC|
VM_MAYREAD|VM_MAYWRITE|VM_MAYEXEC,
vdso32_pages);
if (ret)
goto up_fail;
vma = _install_special_mapping(mm,
addr - VDSO_OFFSET(VDSO_PREV_PAGES),
VDSO_OFFSET(VDSO_PREV_PAGES),
VM_READ,
no_pages);
if (IS_ERR(vma)) {
ret = PTR_ERR(vma);
goto up_fail;
}
ret = remap_pfn_range(vma,
addr - VDSO_OFFSET(VDSO_VVAR_PAGE),
__pa_symbol(&__vvar_page) >> PAGE_SHIFT,
PAGE_SIZE,
PAGE_READONLY);
if (ret)
goto up_fail;
#ifdef CONFIG_HPET_TIMER
if (hpet_address) {
ret = io_remap_pfn_range(vma,
addr - VDSO_OFFSET(VDSO_HPET_PAGE),
hpet_address >> PAGE_SHIFT,
PAGE_SIZE,
pgprot_noncached(PAGE_READONLY));
if (ret)
goto up_fail;
}
#endif
current_thread_info()->sysenter_return =
VDSO32_SYMBOL(addr, SYSENTER_RETURN);
up_fail:
if (ret)
current->mm->context.vdso = NULL;
up_write(&mm->mmap_sem);
return ret;
}
static __init int ia32_binfmt_init(void)
{
register_sysctl_table(abi_root_table2);
return 0;
}
const char *arch_vma_name(struct vm_area_struct *vma)
{
if (vma->vm_mm && vma->vm_start == (long)vma->vm_mm->context.vdso)
return "[vdso]";
return NULL;
}
struct vm_area_struct *get_gate_vma(struct mm_struct *mm)
{
return NULL;
}
int in_gate_area(struct mm_struct *mm, unsigned long addr)
{
return 0;
}
int in_gate_area_no_mm(unsigned long addr)
{
return 0;
}
