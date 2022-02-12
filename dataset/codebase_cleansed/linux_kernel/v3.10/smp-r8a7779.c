void __init r8a7779_register_twd(void)
{
twd_local_timer_register(&twd_local_timer);
}
static int r8a7779_platform_cpu_kill(unsigned int cpu)
{
struct r8a7779_pm_ch *ch = NULL;
int ret = -EIO;
cpu = cpu_logical_map(cpu);
if (cpu < ARRAY_SIZE(r8a7779_ch_cpu))
ch = r8a7779_ch_cpu[cpu];
if (ch)
ret = r8a7779_sysc_power_down(ch);
return ret ? ret : 1;
}
static int __cpuinit r8a7779_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
struct r8a7779_pm_ch *ch = NULL;
int ret = -EIO;
cpu = cpu_logical_map(cpu);
if (cpu < ARRAY_SIZE(r8a7779_ch_cpu))
ch = r8a7779_ch_cpu[cpu];
if (ch)
ret = r8a7779_sysc_power_up(ch);
return ret;
}
static void __init r8a7779_smp_prepare_cpus(unsigned int max_cpus)
{
scu_enable(shmobile_scu_base);
__raw_writel(__pa(shmobile_secondary_vector_scu), AVECR);
scu_power_mode(shmobile_scu_base, SCU_PM_NORMAL);
r8a7779_pm_init();
r8a7779_platform_cpu_kill(1);
r8a7779_platform_cpu_kill(2);
r8a7779_platform_cpu_kill(3);
}
static void __init r8a7779_smp_init_cpus(void)
{
shmobile_scu_base = IOMEM(R8A7779_SCU_BASE);
shmobile_smp_init_cpus(scu_get_core_count(shmobile_scu_base));
}
static int r8a7779_scu_psr_core_disabled(int cpu)
{
unsigned long mask = 3 << (cpu * 8);
if ((__raw_readl(shmobile_scu_base + 8) & mask) == mask)
return 1;
return 0;
}
static int r8a7779_cpu_kill(unsigned int cpu)
{
int k;
for (k = 0; k < 1000; k++) {
if (r8a7779_scu_psr_core_disabled(cpu))
return r8a7779_platform_cpu_kill(cpu);
mdelay(1);
}
return 0;
}
static void r8a7779_cpu_die(unsigned int cpu)
{
dsb();
flush_cache_all();
scu_power_mode(shmobile_scu_base, SCU_PM_POWEROFF);
while (1)
cpu_do_idle();
}
static int r8a7779_cpu_disable(unsigned int cpu)
{
return cpu == 0 ? -EPERM : 0;
}
