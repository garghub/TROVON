void mmp2_clear_pmic_int(void)
{
void __iomem *mfpr_pmic;
unsigned long data;
mfpr_pmic = APB_VIRT_BASE + 0x1e000 + 0x2c4;
data = __raw_readl(mfpr_pmic);
__raw_writel(data | (1 << 6), mfpr_pmic);
__raw_writel(data, mfpr_pmic);
}
void __init mmp2_init_irq(void)
{
mmp2_init_icu();
#ifdef CONFIG_PM
icu_irq_chip.irq_set_wake = mmp2_set_wake;
#endif
}
static int __init mmp2_init(void)
{
if (cpu_is_mmp2()) {
#ifdef CONFIG_CACHE_TAUROS2
tauros2_init(0);
#endif
mfp_init_base(MFPR_VIRT_BASE);
mfp_init_addr(mmp2_addr_map);
pxa_init_dma(IRQ_MMP2_DMA_RIQ, 16);
mmp2_clk_init();
}
return 0;
}
void __init mmp2_timer_init(void)
{
unsigned long clk_rst;
__raw_writel(APBC_APBCLK | APBC_RST, APBC_TIMERS);
clk_rst = APBC_APBCLK | APBC_FNCLK | APBC_FNCLKSEL(1);
__raw_writel(clk_rst, APBC_TIMERS);
timer_init(IRQ_MMP2_TIMER1);
}
