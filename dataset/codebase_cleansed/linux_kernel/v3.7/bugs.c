static int __init no_halt(char *s)
{
WARN_ONCE(1, "\"no-hlt\" is deprecated, please use \"idle=poll\"\n");
boot_cpu_data.hlt_works_ok = 0;
return 1;
}
static int __init no_387(char *s)
{
boot_cpu_data.hard_math = 0;
write_cr0(X86_CR0_TS | X86_CR0_EM | X86_CR0_MP | read_cr0());
return 1;
}
static void __init check_fpu(void)
{
s32 fdiv_bug;
if (!boot_cpu_data.hard_math) {
#ifndef CONFIG_MATH_EMULATION
pr_emerg("No coprocessor found and no math emulation present\n");
pr_emerg("Giving up\n");
for (;;) ;
#endif
return;
}
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
boot_cpu_data.fdiv_bug = fdiv_bug;
if (boot_cpu_data.fdiv_bug)
pr_warn("Hmm, FPU with FDIV bug\n");
}
static void __init check_hlt(void)
{
if (boot_cpu_data.x86 >= 5 || paravirt_enabled())
return;
pr_info("Checking 'hlt' instruction... ");
if (!boot_cpu_data.hlt_works_ok) {
pr_cont("disabled\n");
return;
}
halt();
halt();
halt();
halt();
pr_cont("OK\n");
}
static void __init check_popad(void)
{
#ifndef CONFIG_X86_POPAD_OK
int res, inp = (int) &res;
pr_info("Checking for popad bug... ");
__asm__ __volatile__(
"movl $12345678,%%eax; movl $0,%%edi; pusha; popa; movl (%%edx,%%edi),%%ecx "
: "=&a" (res)
: "d" (inp)
: "ecx", "edi");
if (res != 12345678)
pr_cont("Buggy\n");
else
pr_cont("OK\n");
#endif
}
static void __init check_config(void)
{
#if defined(CONFIG_X86_WP_WORKS_OK) || defined(CONFIG_X86_INVLPG) || \
defined(CONFIG_X86_BSWAP)
if (boot_cpu_data.x86 == 3)
panic("Kernel requires i486+ for 'invlpg' and other features");
#endif
}
void __init check_bugs(void)
{
identify_boot_cpu();
#ifndef CONFIG_SMP
pr_info("CPU: ");
print_cpu_info(&boot_cpu_data);
#endif
check_config();
check_hlt();
check_popad();
init_utsname()->machine[1] =
'0' + (boot_cpu_data.x86 > 6 ? 6 : boot_cpu_data.x86);
alternative_instructions();
check_fpu();
}
