static void modify_scu_cpu_psr(unsigned long set, unsigned long clr)
{
unsigned long tmp;
spin_lock(&scu_lock);
tmp = readl(scu_base + 8);
tmp &= ~clr;
tmp |= set;
writel(tmp, scu_base + 8);
spin_unlock(&scu_lock);
}
unsigned int __init emev2_get_core_count(void)
{
if (!scu_base) {
scu_base = ioremap(EMEV2_SCU_BASE, PAGE_SIZE);
emev2_clock_init();
}
WARN_ON_ONCE(!scu_base);
return scu_base ? scu_get_core_count(scu_base) : 1;
}
int emev2_platform_cpu_kill(unsigned int cpu)
{
return 0;
}
void __cpuinit emev2_secondary_init(unsigned int cpu)
{
gic_secondary_init(0);
}
int __cpuinit emev2_boot_secondary(unsigned int cpu)
{
cpu = cpu_logical_map(cpu);
modify_scu_cpu_psr(0, 3 << (cpu * 8));
emev2_set_boot_vector(__pa(shmobile_secondary_vector));
gic_raise_softirq(cpumask_of(cpu), 1);
return 0;
}
void __init emev2_smp_prepare_cpus(void)
{
int cpu = cpu_logical_map(0);
scu_enable(scu_base);
modify_scu_cpu_psr(0, 3 << (cpu * 8));
}
