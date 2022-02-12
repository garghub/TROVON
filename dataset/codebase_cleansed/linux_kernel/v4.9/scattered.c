void init_scattered_cpuid_features(struct cpuinfo_x86 *c)
{
u32 max_level;
u32 regs[4];
const struct cpuid_bit *cb;
static const struct cpuid_bit cpuid_bits[] = {
{ X86_FEATURE_INTEL_PT, CR_EBX,25, 0x00000007, 0 },
{ X86_FEATURE_AVX512_4VNNIW, CR_EDX, 2, 0x00000007, 0 },
{ X86_FEATURE_AVX512_4FMAPS, CR_EDX, 3, 0x00000007, 0 },
{ X86_FEATURE_APERFMPERF, CR_ECX, 0, 0x00000006, 0 },
{ X86_FEATURE_EPB, CR_ECX, 3, 0x00000006, 0 },
{ X86_FEATURE_HW_PSTATE, CR_EDX, 7, 0x80000007, 0 },
{ X86_FEATURE_CPB, CR_EDX, 9, 0x80000007, 0 },
{ X86_FEATURE_PROC_FEEDBACK, CR_EDX,11, 0x80000007, 0 },
{ 0, 0, 0, 0, 0 }
};
for (cb = cpuid_bits; cb->feature; cb++) {
max_level = cpuid_eax(cb->level & 0xffff0000);
if (max_level < cb->level ||
max_level > (cb->level | 0xffff))
continue;
cpuid_count(cb->level, cb->sub_leaf, &regs[CR_EAX],
&regs[CR_EBX], &regs[CR_ECX], &regs[CR_EDX]);
if (regs[cb->reg] & (1 << cb->bit))
set_cpu_cap(c, cb->feature);
}
}
