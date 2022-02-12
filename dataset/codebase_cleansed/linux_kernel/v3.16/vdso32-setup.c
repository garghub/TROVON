static int __init vdso32_setup(char *s)
{
vdso32_enabled = simple_strtoul(s, NULL, 0);
if (vdso32_enabled > 1)
pr_warn("vdso32 values other than 0 and 1 are no longer allowed; vdso disabled\n");
return 1;
}
int __init sysenter_setup(void)
{
#ifdef CONFIG_COMPAT
if (vdso32_syscall())
selected_vdso32 = &vdso_image_32_syscall;
else
#endif
if (vdso32_sysenter())
selected_vdso32 = &vdso_image_32_sysenter;
else
selected_vdso32 = &vdso_image_32_int80;
init_vdso_image(selected_vdso32);
return 0;
}
static __init int ia32_binfmt_init(void)
{
register_sysctl_table(abi_root_table2);
return 0;
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
