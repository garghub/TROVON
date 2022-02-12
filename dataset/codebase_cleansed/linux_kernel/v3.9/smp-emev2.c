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
static unsigned int __init emev2_get_core_count(void)
{
if (!scu_base) {
scu_base = ioremap(EMEV2_SCU_BASE, PAGE_SIZE);
emev2_clock_init();
}
WARN_ON_ONCE(!scu_base);
return scu_base ? scu_get_core_count(scu_base) : 1;
}
static int emev2_platform_cpu_kill(unsigned int cpu)
{
return 0;
}
static int __maybe_unused emev2_cpu_kill(unsigned int cpu)
{
int k;
for (k = 0; k < 1000; k++) {
if (shmobile_cpu_is_dead(cpu))
return emev2_platform_cpu_kill(cpu);
mdelay(1);
}
return 0;
}
static void __cpuinit emev2_secondary_init(unsigned int cpu)
{
gic_secondary_init(0);
}
static int __cpuinit emev2_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
cpu = cpu_logical_map(cpu);
modify_scu_cpu_psr(0, 3 << (cpu * 8));
emev2_set_boot_vector(__pa(shmobile_secondary_vector));
arch_send_wakeup_ipi_mask(cpumask_of(cpu));
return 0;
}
static void __init emev2_smp_prepare_cpus(unsigned int max_cpus)
{
int cpu = cpu_logical_map(0);
scu_enable(scu_base);
modify_scu_cpu_psr(0, 3 << (cpu * 8));
}
static void __init emev2_smp_init_cpus(void)
{
unsigned int ncores = emev2_get_core_count();
shmobile_smp_init_cpus(ncores);
}
