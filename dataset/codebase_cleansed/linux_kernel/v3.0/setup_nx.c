static int __init noexec_setup(char *str)
{
if (!str)
return -EINVAL;
if (!strncmp(str, "on", 2)) {
disable_nx = 0;
} else if (!strncmp(str, "off", 3)) {
disable_nx = 1;
}
x86_configure_nx();
return 0;
}
void __cpuinit x86_configure_nx(void)
{
if (cpu_has_nx && !disable_nx)
__supported_pte_mask |= _PAGE_NX;
else
__supported_pte_mask &= ~_PAGE_NX;
}
void __init x86_report_nx(void)
{
if (!cpu_has_nx) {
printk(KERN_NOTICE "Notice: NX (Execute Disable) protection "
"missing in CPU!\n");
} else {
#if defined(CONFIG_X86_64) || defined(CONFIG_X86_PAE)
if (disable_nx) {
printk(KERN_INFO "NX (Execute Disable) protection: "
"disabled by kernel command line option\n");
} else {
printk(KERN_INFO "NX (Execute Disable) protection: "
"active\n");
}
#else
printk(KERN_NOTICE "Notice: NX (Execute Disable) protection "
"cannot be enabled: non-PAE kernel!\n");
#endif
}
}
