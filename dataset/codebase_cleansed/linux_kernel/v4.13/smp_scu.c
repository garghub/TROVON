unsigned int __init scu_get_core_count(void __iomem *scu_base)
{
unsigned int ncores = readl_relaxed(scu_base + SCU_CONFIG);
return (ncores & 0x03) + 1;
}
void scu_enable(void __iomem *scu_base)
{
u32 scu_ctrl;
#ifdef CONFIG_ARM_ERRATA_764369
if ((read_cpuid_id() & 0xff0ffff0) == 0x410fc090) {
scu_ctrl = readl_relaxed(scu_base + 0x30);
if (!(scu_ctrl & 1))
writel_relaxed(scu_ctrl | 0x1, scu_base + 0x30);
}
#endif
scu_ctrl = readl_relaxed(scu_base + SCU_CTRL);
if (scu_ctrl & SCU_ENABLE)
return;
scu_ctrl |= SCU_ENABLE;
if ((read_cpuid_id() & 0xff0ffff0) == 0x410fc090 &&
(read_cpuid_id() & 0x00f0000f) >= 0x00200000)
scu_ctrl |= SCU_STANDBY_ENABLE;
writel_relaxed(scu_ctrl, scu_base + SCU_CTRL);
flush_cache_all();
}
int scu_power_mode(void __iomem *scu_base, unsigned int mode)
{
unsigned int val;
int cpu = MPIDR_AFFINITY_LEVEL(cpu_logical_map(smp_processor_id()), 0);
if (mode > 3 || mode == 1 || cpu > 3)
return -EINVAL;
val = readb_relaxed(scu_base + SCU_CPU_STATUS + cpu) & ~0x03;
val |= mode;
writeb_relaxed(val, scu_base + SCU_CPU_STATUS + cpu);
return 0;
}
