unsigned int __init scu_get_core_count(void __iomem *scu_base)
{
unsigned int ncores = __raw_readl(scu_base + SCU_CONFIG);
return (ncores & 0x03) + 1;
}
void scu_enable(void __iomem *scu_base)
{
u32 scu_ctrl;
#ifdef CONFIG_ARM_ERRATA_764369
if ((read_cpuid(CPUID_ID) & 0xff0ffff0) == 0x410fc090) {
scu_ctrl = __raw_readl(scu_base + 0x30);
if (!(scu_ctrl & 1))
__raw_writel(scu_ctrl | 0x1, scu_base + 0x30);
}
#endif
scu_ctrl = __raw_readl(scu_base + SCU_CTRL);
if (scu_ctrl & 1)
return;
scu_ctrl |= 1;
__raw_writel(scu_ctrl, scu_base + SCU_CTRL);
flush_cache_all();
}
int scu_power_mode(void __iomem *scu_base, unsigned int mode)
{
unsigned int val;
int cpu = cpu_logical_map(smp_processor_id());
if (mode > 3 || mode == 1 || cpu > 3)
return -EINVAL;
val = __raw_readb(scu_base + SCU_CPU_STATUS + cpu) & ~0x03;
val |= mode;
__raw_writeb(val, scu_base + SCU_CPU_STATUS + cpu);
return 0;
}
