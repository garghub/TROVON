static void __iomem *scu_base_addr(void)
{
return (void __iomem *)0xf0000000;
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
unsigned int __init sh73a0_get_core_count(void)
{
void __iomem *scu_base = scu_base_addr();
#ifdef CONFIG_HAVE_ARM_TWD
twd_base = (void __iomem *)0xf0000600;
#endif
return scu_get_core_count(scu_base);
}
void __cpuinit sh73a0_secondary_init(unsigned int cpu)
{
gic_secondary_init(0);
}
int __cpuinit sh73a0_boot_secondary(unsigned int cpu)
{
modify_scu_cpu_psr(0, 3 << (cpu * 8));
if (((__raw_readw(__io(PSTR)) >> (4 * cpu)) & 3) == 3)
__raw_writel(1 << cpu, __io(WUPCR));
else
__raw_writel(1 << cpu, __io(SRESCR));
return 0;
}
void __init sh73a0_smp_prepare_cpus(void)
{
scu_enable(scu_base_addr());
__raw_writel(0, __io(APARMBAREA));
__raw_writel(__pa(shmobile_secondary_vector), __io(SBAR));
modify_scu_cpu_psr(0, 3 << (0 * 8));
}
