static void __iomem *scu_base_addr(void)
{
return (void __iomem *)0xf0000000;
}
void __init sh73a0_register_twd(void)
{
twd_local_timer_register(&twd_local_timer);
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
if (((__raw_readl(PSTR) >> (4 * cpu)) & 3) == 3)
__raw_writel(1 << cpu, WUPCR);
else
__raw_writel(1 << cpu, SRESCR);
return 0;
}
static void __init sh73a0_smp_prepare_cpus(unsigned int max_cpus)
{
scu_enable(scu_base_addr());
__raw_writel(0, APARMBAREA);
__raw_writel(__pa(sh73a0_secondary_vector), SBAR);
scu_power_mode(scu_base_addr(), SCU_PM_NORMAL);
}
static void __init sh73a0_smp_init_cpus(void)
{
unsigned int ncores = sh73a0_get_core_count();
shmobile_smp_init_cpus(ncores);
}
static int sh73a0_cpu_kill(unsigned int cpu)
{
int k;
u32 pstr;
for (k = 0; k < 1000; k++) {
pstr = (__raw_readl(PSTR) >> (4 * cpu)) & 3;
if (pstr == PSTR_SHUTDOWN_MODE)
return 1;
mdelay(1);
}
return 0;
}
static void sh73a0_cpu_die(unsigned int cpu)
{
dsb();
flush_cache_all();
scu_power_mode(scu_base_addr(), SCU_PM_POWEROFF);
cpu_do_idle();
}
