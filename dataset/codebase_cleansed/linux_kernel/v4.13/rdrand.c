static int __init x86_rdrand_setup(char *s)
{
setup_clear_cpu_cap(X86_FEATURE_RDRAND);
setup_clear_cpu_cap(X86_FEATURE_RDSEED);
return 1;
}
void x86_init_rdrand(struct cpuinfo_x86 *c)
{
unsigned long tmp;
int i;
if (!cpu_has(c, X86_FEATURE_RDRAND))
return;
for (i = 0; i < SANITY_CHECK_LOOPS; i++) {
if (!rdrand_long(&tmp)) {
clear_cpu_cap(c, X86_FEATURE_RDRAND);
pr_warn_once("rdrand: disabled\n");
return;
}
}
}
