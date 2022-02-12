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
static int r8a7779_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
struct r8a7779_pm_ch *ch = NULL;
unsigned int lcpu = cpu_logical_map(cpu);
int ret;
if (lcpu < ARRAY_SIZE(r8a7779_ch_cpu))
ch = r8a7779_ch_cpu[lcpu];
if (ch)
ret = r8a7779_sysc_power_up(ch);
else
ret = -EIO;
return ret;
}
static void __init r8a7779_smp_prepare_cpus(unsigned int max_cpus)
{
__raw_writel(__pa(shmobile_boot_vector), AVECR);
shmobile_boot_fn = virt_to_phys(shmobile_boot_scu);
shmobile_boot_arg = (unsigned long)shmobile_scu_base;
shmobile_scu_base = IOMEM(R8A7779_SCU_BASE);
shmobile_smp_scu_prepare_cpus(max_cpus);
r8a7779_pm_init();
r8a7779_platform_cpu_kill(1);
r8a7779_platform_cpu_kill(2);
r8a7779_platform_cpu_kill(3);
}
static int r8a7779_cpu_kill(unsigned int cpu)
{
if (shmobile_smp_scu_cpu_kill(cpu))
return r8a7779_platform_cpu_kill(cpu);
return 0;
}
static int r8a7779_cpu_disable(unsigned int cpu)
{
return cpu == 0 ? -EPERM : 0;
}
