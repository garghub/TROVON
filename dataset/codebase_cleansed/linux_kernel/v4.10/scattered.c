void init_scattered_cpuid_features(struct cpuinfo_x86 *c)
{
u32 max_level;
u32 regs[4];
const struct cpuid_bit *cb;
for (cb = cpuid_bits; cb->feature; cb++) {
max_level = cpuid_eax(cb->level & 0xffff0000);
if (max_level < cb->level ||
max_level > (cb->level | 0xffff))
continue;
cpuid_count(cb->level, cb->sub_leaf, &regs[CPUID_EAX],
&regs[CPUID_EBX], &regs[CPUID_ECX],
&regs[CPUID_EDX]);
if (regs[cb->reg] & (1 << cb->bit))
set_cpu_cap(c, cb->feature);
}
}
u32 get_scattered_cpuid_leaf(unsigned int level, unsigned int sub_leaf,
enum cpuid_regs_idx reg)
{
const struct cpuid_bit *cb;
u32 cpuid_val = 0;
for (cb = cpuid_bits; cb->feature; cb++) {
if (level > cb->level)
continue;
if (level < cb->level)
break;
if (reg == cb->reg && sub_leaf == cb->sub_leaf) {
if (cpu_has(&boot_cpu_data, cb->feature))
cpuid_val |= BIT(cb->bit);
}
}
return cpuid_val;
}
