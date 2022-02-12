static void __iomem *scu_base_addr(void)
{
return (void __iomem *)0xf0000000;
}
void __init r8a7779_register_twd(void)
{
twd_local_timer_register(&twd_local_timer);
}
static void modify_scu_cpu_psr(unsigned long set, unsigned long clr)
{
void __iomem *scu_base = scu_base_addr();
spin_lock(&scu_lock);
tmp = __raw_readl(scu_base + 8);
tmp &= ~clr;
tmp |= set;
spin_unlock(&scu_lock);
__raw_writel(tmp, scu_base + 8);
}
static unsigned int __init r8a7779_get_core_count(void)
{
void __iomem *scu_base = scu_base_addr();
return scu_get_core_count(scu_base);
}
static int r8a7779_platform_cpu_kill(unsigned int cpu)
{
struct r8a7779_pm_ch *ch = NULL;
int ret = -EIO;
cpu = cpu_logical_map(cpu);
modify_scu_cpu_psr(3 << (cpu * 8), 0);
if (cpu < ARRAY_SIZE(r8a7779_ch_cpu))
ch = r8a7779_ch_cpu[cpu];
if (ch)
ret = r8a7779_sysc_power_down(ch);
return ret ? ret : 1;
}
static int __maybe_unused r8a7779_cpu_kill(unsigned int cpu)
{
int k;
for (k = 0; k < 1000; k++) {
if (shmobile_cpu_is_dead(cpu))
return r8a7779_platform_cpu_kill(cpu);
mdelay(1);
}
return 0;
}
static void __cpuinit r8a7779_secondary_init(unsigned int cpu)
{
gic_secondary_init(0);
}
static int __cpuinit r8a7779_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
struct r8a7779_pm_ch *ch = NULL;
int ret = -EIO;
cpu = cpu_logical_map(cpu);
modify_scu_cpu_psr(0, 3 << (cpu * 8));
if (cpu < ARRAY_SIZE(r8a7779_ch_cpu))
ch = r8a7779_ch_cpu[cpu];
if (ch)
ret = r8a7779_sysc_power_up(ch);
return ret;
}
static void __init r8a7779_smp_prepare_cpus(unsigned int max_cpus)
{
int cpu = cpu_logical_map(0);
scu_enable(scu_base_addr());
__raw_writel(__pa(shmobile_secondary_vector), AVECR);
modify_scu_cpu_psr(0, 3 << (cpu * 8));
r8a7779_pm_init();
r8a7779_platform_cpu_kill(1);
r8a7779_platform_cpu_kill(2);
r8a7779_platform_cpu_kill(3);
}
static void __init r8a7779_smp_init_cpus(void)
{
unsigned int ncores = r8a7779_get_core_count();
shmobile_smp_init_cpus(ncores);
}
