void __init sh73a0_register_twd(void)
{
twd_local_timer_register(&twd_local_timer);
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
scu_enable(shmobile_scu_base);
__raw_writel(0, APARMBAREA);
__raw_writel(__pa(shmobile_secondary_vector_scu), SBAR);
scu_power_mode(shmobile_scu_base, SCU_PM_NORMAL);
}
static void __init sh73a0_smp_init_cpus(void)
{
shmobile_scu_base = IOMEM(SH73A0_SCU_BASE);
shmobile_smp_init_cpus(scu_get_core_count(shmobile_scu_base));
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
scu_power_mode(shmobile_scu_base, SCU_PM_POWEROFF);
cpu_do_idle();
}
static int sh73a0_cpu_disable(unsigned int cpu)
{
return 0;
}
