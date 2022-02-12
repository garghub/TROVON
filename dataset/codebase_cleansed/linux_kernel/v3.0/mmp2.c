void mmp2_clear_pmic_int(void)
{
unsigned long mfpr_pmic, data;
mfpr_pmic = APB_VIRT_BASE + 0x1e000 + 0x2c4;
data = __raw_readl(mfpr_pmic);
__raw_writel(data | (1 << 6), mfpr_pmic);
__raw_writel(data, mfpr_pmic);
}
static void __init mmp2_init_gpio(void)
{
int i;
__raw_writel(APBC_APBCLK | APBC_FNCLK, APBC_MMP2_GPIO);
for (i = 0; i < 6; i++)
__raw_writel(0xffffffff, APMASK(i));
pxa_init_gpio(IRQ_MMP2_GPIO, 0, 167, NULL);
}
void __init mmp2_init_irq(void)
{
mmp2_init_icu();
mmp2_init_gpio();
}
static void sdhc_clk_enable(struct clk *clk)
{
uint32_t clk_rst;
clk_rst = __raw_readl(clk->clk_rst);
clk_rst |= clk->enable_val;
__raw_writel(clk_rst, clk->clk_rst);
}
static void sdhc_clk_disable(struct clk *clk)
{
uint32_t clk_rst;
clk_rst = __raw_readl(clk->clk_rst);
clk_rst &= ~clk->enable_val;
__raw_writel(clk_rst, clk->clk_rst);
}
static int __init mmp2_init(void)
{
if (cpu_is_mmp2()) {
#ifdef CONFIG_CACHE_TAUROS2
tauros2_init();
#endif
mfp_init_base(MFPR_VIRT_BASE);
mfp_init_addr(mmp2_addr_map);
pxa_init_dma(IRQ_MMP2_DMA_RIQ, 16);
clkdev_add_table(ARRAY_AND_SIZE(mmp2_clkregs));
}
return 0;
}
static void __init mmp2_timer_init(void)
{
unsigned long clk_rst;
__raw_writel(APBC_APBCLK | APBC_RST, APBC_MMP2_TIMERS);
clk_rst = APBC_APBCLK | APBC_FNCLK | APBC_FNCLKSEL(1);
__raw_writel(clk_rst, APBC_MMP2_TIMERS);
timer_init(IRQ_MMP2_TIMER1);
}
