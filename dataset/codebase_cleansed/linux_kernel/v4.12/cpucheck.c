static int is_amd(void)
{
return cpu_vendor[0] == A32('A', 'u', 't', 'h') &&
cpu_vendor[1] == A32('e', 'n', 't', 'i') &&
cpu_vendor[2] == A32('c', 'A', 'M', 'D');
}
static int is_centaur(void)
{
return cpu_vendor[0] == A32('C', 'e', 'n', 't') &&
cpu_vendor[1] == A32('a', 'u', 'r', 'H') &&
cpu_vendor[2] == A32('a', 'u', 'l', 's');
}
static int is_transmeta(void)
{
return cpu_vendor[0] == A32('G', 'e', 'n', 'u') &&
cpu_vendor[1] == A32('i', 'n', 'e', 'T') &&
cpu_vendor[2] == A32('M', 'x', '8', '6');
}
static int is_intel(void)
{
return cpu_vendor[0] == A32('G', 'e', 'n', 'u') &&
cpu_vendor[1] == A32('i', 'n', 'e', 'I') &&
cpu_vendor[2] == A32('n', 't', 'e', 'l');
}
static int check_cpuflags(void)
{
u32 err;
int i;
err = 0;
for (i = 0; i < NCAPINTS; i++) {
err_flags[i] = req_flags[i] & ~cpu.flags[i];
if (err_flags[i])
err |= 1 << i;
}
return err;
}
int check_cpu(int *cpu_level_ptr, int *req_level_ptr, u32 **err_flags_ptr)
{
int err;
memset(&cpu.flags, 0, sizeof cpu.flags);
cpu.level = 3;
if (has_eflag(X86_EFLAGS_AC))
cpu.level = 4;
get_cpuflags();
err = check_cpuflags();
if (test_bit(X86_FEATURE_LM, cpu.flags))
cpu.level = 64;
if (err == 0x01 &&
!(err_flags[0] &
~((1 << X86_FEATURE_XMM)|(1 << X86_FEATURE_XMM2))) &&
is_amd()) {
u32 ecx = MSR_K7_HWCR;
u32 eax, edx;
asm("rdmsr" : "=a" (eax), "=d" (edx) : "c" (ecx));
eax &= ~(1 << 15);
asm("wrmsr" : : "a" (eax), "d" (edx), "c" (ecx));
get_cpuflags();
err = check_cpuflags();
} else if (err == 0x01 &&
!(err_flags[0] & ~(1 << X86_FEATURE_CX8)) &&
is_centaur() && cpu.model >= 6) {
u32 ecx = MSR_VIA_FCR;
u32 eax, edx;
asm("rdmsr" : "=a" (eax), "=d" (edx) : "c" (ecx));
eax |= (1<<1)|(1<<7);
asm("wrmsr" : : "a" (eax), "d" (edx), "c" (ecx));
set_bit(X86_FEATURE_CX8, cpu.flags);
err = check_cpuflags();
} else if (err == 0x01 && is_transmeta()) {
u32 ecx = 0x80860004;
u32 eax, edx;
u32 level = 1;
asm("rdmsr" : "=a" (eax), "=d" (edx) : "c" (ecx));
asm("wrmsr" : : "a" (~0), "d" (edx), "c" (ecx));
asm("cpuid"
: "+a" (level), "=d" (cpu.flags[0])
: : "ecx", "ebx");
asm("wrmsr" : : "a" (eax), "d" (edx), "c" (ecx));
err = check_cpuflags();
} else if (err == 0x01 &&
!(err_flags[0] & ~(1 << X86_FEATURE_PAE)) &&
is_intel() && cpu.level == 6 &&
(cpu.model == 9 || cpu.model == 13)) {
if (cmdline_find_option_bool("forcepae")) {
puts("WARNING: Forcing PAE in CPU flags\n");
set_bit(X86_FEATURE_PAE, cpu.flags);
err = check_cpuflags();
}
else {
puts("WARNING: PAE disabled. Use parameter 'forcepae' to enable at your own risk!\n");
}
}
if (!err)
err = check_knl_erratum();
if (err_flags_ptr)
*err_flags_ptr = err ? err_flags : NULL;
if (cpu_level_ptr)
*cpu_level_ptr = cpu.level;
if (req_level_ptr)
*req_level_ptr = req_level;
return (cpu.level < req_level || err) ? -1 : 0;
}
int check_knl_erratum(void)
{
if (!is_intel() ||
cpu.family != 6 ||
cpu.model != INTEL_FAM6_XEON_PHI_KNL)
return 0;
if (IS_ENABLED(CONFIG_X86_64) || IS_ENABLED(CONFIG_X86_PAE))
return 0;
puts("This 32-bit kernel can not run on this Xeon Phi x200\n"
"processor due to a processor erratum. Use a 64-bit\n"
"kernel, or enable PAE in this 32-bit kernel.\n\n");
return -1;
}
