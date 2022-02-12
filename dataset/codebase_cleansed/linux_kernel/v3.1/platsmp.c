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
static void __cpuinit exynos4_gic_secondary_init(void)
{
void __iomem *dist_base = S5P_VA_GIC_DIST +
(EXYNOS4_GIC_BANK_OFFSET * smp_processor_id());
void __iomem *cpu_base = S5P_VA_GIC_CPU +
(EXYNOS4_GIC_BANK_OFFSET * smp_processor_id());
int i;
__raw_writel(0xffff0000, dist_base + GIC_DIST_ENABLE_CLEAR);
__raw_writel(0x0000ffff, dist_base + GIC_DIST_ENABLE_SET);
for (i = 0; i < 32; i += 4)
__raw_writel(0xa0a0a0a0, dist_base + GIC_DIST_PRI + i * 4 / 4);
__raw_writel(0xf0, cpu_base + GIC_CPU_PRIMASK);
__raw_writel(1, cpu_base + GIC_CPU_CTRL);
}
void __cpuinit platform_secondary_init(unsigned int cpu)
{
exynos4_gic_secondary_init();
write_pen_release(-1);
spin_lock(&boot_lock);
spin_unlock(&boot_lock);
set_cpu_online(cpu, true);
}
int __cpuinit boot_secondary(unsigned int cpu, struct task_struct *idle)
{
unsigned long timeout;
spin_lock(&boot_lock);
write_pen_release(cpu);
if (!(__raw_readl(S5P_ARM_CORE1_STATUS) & S5P_CORE_LOCAL_PWR_EN)) {
__raw_writel(S5P_CORE_LOCAL_PWR_EN,
S5P_ARM_CORE1_CONFIGURATION);
timeout = 10;
while ((__raw_readl(S5P_ARM_CORE1_STATUS)
& S5P_CORE_LOCAL_PWR_EN) != S5P_CORE_LOCAL_PWR_EN) {
if (timeout-- == 0)
break;
mdelay(1);
}
if (timeout == 0) {
printk(KERN_ERR "cpu1 power enable failed");
spin_unlock(&boot_lock);
return -ETIMEDOUT;
}
}
timeout = jiffies + (1 * HZ);
while (time_before(jiffies, timeout)) {
smp_rmb();
__raw_writel(BSYM(virt_to_phys(exynos4_secondary_startup)),
CPU1_BOOT_REG);
gic_raise_softirq(cpumask_of(cpu), 1);
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
scu_enable(scu_base_addr());
__raw_writel(BSYM(virt_to_phys(exynos4_secondary_startup)), S5P_VA_SYSRAM);
}
