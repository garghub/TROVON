static void write_pen_release(int val)
{
pen_release = val;
smp_wmb();
__cpuc_flush_dcache_area((void *)&pen_release, sizeof(pen_release));
outer_clean_range(__pa(&pen_release), __pa(&pen_release + 1));
}
static void __iomem *scu_base_addr(void)
{
return (void __iomem *)(S5P_VA_SCU);
}
void __cpuinit platform_secondary_init(unsigned int cpu)
{
gic_secondary_init(0);
write_pen_release(-1);
spin_lock(&boot_lock);
spin_unlock(&boot_lock);
}
int __cpuinit boot_secondary(unsigned int cpu, struct task_struct *idle)
{
unsigned long timeout;
spin_lock(&boot_lock);
write_pen_release(cpu);
gic_raise_softirq(cpumask_of(cpu), 1);
timeout = jiffies + (1 * HZ);
while (time_before(jiffies, timeout)) {
smp_rmb();
if (pen_release == -1)
break;
udelay(10);
}
spin_unlock(&boot_lock);
return pen_release != -1 ? -ENOSYS : 0;
}
void __init smp_init_cpus(void)
{
void __iomem *scu_base = scu_base_addr();
unsigned int i, ncores;
ncores = scu_base ? scu_get_core_count(scu_base) : 1;
if (ncores > NR_CPUS) {
printk(KERN_WARNING
"EXYNOS4: no. of cores (%d) greater than configured "
"maximum of %d - clipping\n",
ncores, NR_CPUS);
ncores = NR_CPUS;
}
for (i = 0; i < ncores; i++)
set_cpu_possible(i, true);
set_smp_cross_call(gic_raise_softirq);
}
void __init platform_smp_prepare_cpus(unsigned int max_cpus)
{
int i;
for (i = 0; i < max_cpus; i++)
set_cpu_present(i, true);
scu_enable(scu_base_addr());
__raw_writel(BSYM(virt_to_phys(exynos4_secondary_startup)), S5P_VA_SYSRAM);
}
