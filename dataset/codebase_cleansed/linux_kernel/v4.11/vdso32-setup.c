static int __init vdso32_setup(char *s)
{
vdso32_enabled = simple_strtoul(s, NULL, 0);
if (vdso32_enabled > 1) {
pr_warn("vdso32 values other than 0 and 1 are no longer allowed; vdso disabled\n");
vdso32_enabled = 0;
}
return 1;
}
int __init sysenter_setup(void)
{
init_vdso_image(&vdso_image_32);
return 0;
}
static __init int ia32_binfmt_init(void)
{
register_sysctl_table(abi_root_table2);
return 0;
}
