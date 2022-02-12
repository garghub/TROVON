static int sh73a0_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
unsigned int lcpu = cpu_logical_map(cpu);
if (((__raw_readl(PSTR) >> (4 * lcpu)) & 3) == 3)
__raw_writel(1 << lcpu, WUPCR);
else
__raw_writel(1 << lcpu, SRESCR);
return 0;
}
static void __init sh73a0_smp_prepare_cpus(unsigned int max_cpus)
{
__raw_writel(0, APARMBAREA);
__raw_writel(__pa(shmobile_boot_vector), SBAR);
shmobile_smp_scu_prepare_cpus(SH73A0_SCU_BASE, max_cpus);
}
