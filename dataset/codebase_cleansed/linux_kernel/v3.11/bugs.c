static void __init check_fpu(void)
{
s32 fdiv_bug;
kernel_fpu_begin();
__asm__("fninit\n\t"
"fldl %1\n\t"
"fdivl %2\n\t"
"fmull %2\n\t"
"fldl %1\n\t"
"fsubp %%st,%%st(1)\n\t"
"fistpl %0\n\t"
"fwait\n\t"
"fninit"
: "=m" (*&fdiv_bug)
: "m" (*&x), "m" (*&y));
kernel_fpu_end();
if (fdiv_bug) {
set_cpu_bug(&boot_cpu_data, X86_BUG_FDIV);
pr_warn("Hmm, FPU with FDIV bug\n");
}
}
void __init check_bugs(void)
{
identify_boot_cpu();
#ifndef CONFIG_SMP
pr_info("CPU: ");
print_cpu_info(&boot_cpu_data);
#endif
if (boot_cpu_data.x86 < 4)
panic("Kernel requires i486+ for 'invlpg' and other features");
init_utsname()->machine[1] =
'0' + (boot_cpu_data.x86 > 6 ? 6 : boot_cpu_data.x86);
alternative_instructions();
if (cpu_has_fpu)
check_fpu();
}
