void __init fpu__init_check_bugs(void)
{
s32 fdiv_bug;
if (!boot_cpu_has(X86_FEATURE_FPU))
return;
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
