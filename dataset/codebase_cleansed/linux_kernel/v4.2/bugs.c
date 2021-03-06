static void __init check_fpu(void)
{
u32 cr0_saved;
s32 fdiv_bug;
cr0_saved = read_cr0();
write_cr0(cr0_saved & ~X86_CR0_TS);
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
write_cr0(cr0_saved);
if (fdiv_bug) {
set_cpu_bug(&boot_cpu_data, X86_BUG_FDIV);
pr_warn("Hmm, FPU with FDIV bug\n");
}
}
void __init fpu__init_check_bugs(void)
{
if (cpu_has_fpu)
check_fpu();
}
