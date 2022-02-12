static void __iomem *scu_base_addr(void)
{
return (void __iomem *)0xf0000000;
}
void __init sh73a0_register_twd(void)
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
static unsigned int __init sh73a0_get_core_count(void)
{
void __iomem *scu_base = scu_base_addr();
return scu_get_core_count(scu_base);
}
static void __cpuinit sh73a0_secondary_init(unsigned int cpu)
{
gic_secondary_init(0);
}
static int __cpuinit sh73a0_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
cpu = cpu_logical_map(cpu);
modify_scu_cpu_psr(0, 3 << (cpu * 8));
if (((__raw_readl(PSTR) >> (4 * cpu)) & 3) == 3)
__raw_writel(1 << cpu, WUPCR);
else
__raw_writel(1 << cpu, SRESCR);
return 0;
}
static void __init sh73a0_smp_prepare_cpus(unsigned int max_cpus)
{
int cpu = cpu_logical_map(0);
scu_enable(scu_base_addr());
__raw_writel(0, APARMBAREA);
__raw_writel(__pa(shmobile_secondary_vector), SBAR);
modify_scu_cpu_psr(0, 3 << (cpu * 8));
}
static void __init sh73a0_smp_init_cpus(void)
{
unsigned int ncores = sh73a0_get_core_count();
shmobile_smp_init_cpus(ncores);
}
static int __maybe_unused sh73a0_cpu_kill(unsigned int cpu)
{
int k;
for (k = 0; k < 1000; k++) {
if (shmobile_cpu_is_dead(cpu))
return 1;
mdelay(1);
}
return 0;
}
