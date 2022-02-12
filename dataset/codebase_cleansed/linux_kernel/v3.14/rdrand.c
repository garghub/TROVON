static int __init x86_rdrand_setup(char *s)
{
setup_clear_cpu_cap(X86_FEATURE_RDRAND);
return 1;
}
void x86_init_rdrand(struct cpuinfo_x86 *c)
{
#ifdef CONFIG_ARCH_RANDOM
unsigned long tmp;
int i, count, ok;
if (!cpu_has(c, X86_FEATURE_RDRAND))
return;
for (count = i = 0; i < RESEED_LOOP; i++) {
ok = rdrand_long(&tmp);
if (ok)
count++;
}
if (count != RESEED_LOOP)
clear_cpu_cap(c, X86_FEATURE_RDRAND);
#endif
}
