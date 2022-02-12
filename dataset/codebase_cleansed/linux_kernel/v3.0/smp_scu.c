unsigned int __init scu_get_core_count(void __iomem *scu_base)
{
unsigned int ncores = __raw_readl(scu_base + SCU_CONFIG);
return (ncores & 0x03) + 1;
}
void __init scu_enable(void __iomem *scu_base)
{
u32 scu_ctrl;
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
int cpu = smp_processor_id();
if (mode > 3 || mode == 1 || cpu > 3)
return -EINVAL;
val = __raw_readb(scu_base + SCU_CPU_STATUS + cpu) & ~0x03;
val |= mode;
__raw_writeb(val, scu_base + SCU_CPU_STATUS + cpu);
return 0;
}
