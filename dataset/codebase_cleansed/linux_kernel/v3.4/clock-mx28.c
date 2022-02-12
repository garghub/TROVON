int mxs_saif_clkmux_select(unsigned int clkmux)
{
if (clkmux > 0x3)
return -EINVAL;
spin_lock(&clkmux_lock);
__raw_writel(BM_DIGCTL_CTRL_SAIF_CLKMUX,
DIGCTRL_BASE_ADDR + HW_DIGCTL_CTRL + MXS_CLR_ADDR);
__raw_writel(clkmux << BP_DIGCTL_CTRL_SAIF_CLKMUX,
DIGCTRL_BASE_ADDR + HW_DIGCTL_CTRL + MXS_SET_ADDR);
spin_unlock(&clkmux_lock);
return 0;
}
static int _raw_clk_enable(struct clk *clk)
{
u32 reg;
if (clk->enable_reg) {
reg = __raw_readl(clk->enable_reg);
reg &= ~(1 << clk->enable_shift);
__raw_writel(reg, clk->enable_reg);
}
return 0;
}
static void _raw_clk_disable(struct clk *clk)
{
u32 reg;
if (clk->enable_reg) {
reg = __raw_readl(clk->enable_reg);
reg |= 1 << clk->enable_shift;
__raw_writel(reg, clk->enable_reg);
}
}
static unsigned long ref_xtal_clk_get_rate(struct clk *clk)
{
return 24000000;
}
static unsigned long pll0_clk_get_rate(struct clk *clk)
{
return 480000000;
}
static unsigned long pll1_clk_get_rate(struct clk *clk)
{
return 480000000;
}
static unsigned long pll2_clk_get_rate(struct clk *clk)
{
return 50000000;
}
static unsigned long lradc_clk_get_rate(struct clk *clk)
{
return clk_get_rate(clk->parent) / 16;
}
static unsigned long rtc_clk_get_rate(struct clk *clk)
{
return clk_get_rate(clk->parent) / 768;
}
static unsigned long clk32k_clk_get_rate(struct clk *clk)
{
return clk->parent->get_rate(clk->parent) / 750;
}
static unsigned long spdif_clk_get_rate(struct clk *clk)
{
return clk_get_rate(clk->parent) / 4;
}
static int clk_misc_init(void)
{
u32 reg;
int ret;
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_CLKSEQ);
cpu_clk.parent = (reg & BM_CLKCTRL_CLKSEQ_BYPASS_CPU) ?
&ref_xtal_clk : &ref_cpu_clk;
emi_clk.parent = (reg & BM_CLKCTRL_CLKSEQ_BYPASS_EMI) ?
&ref_xtal_clk : &ref_emi_clk;
ssp0_clk.parent = (reg & BM_CLKCTRL_CLKSEQ_BYPASS_SSP0) ?
&ref_xtal_clk : &ref_io0_clk;
ssp1_clk.parent = (reg & BM_CLKCTRL_CLKSEQ_BYPASS_SSP1) ?
&ref_xtal_clk : &ref_io0_clk;
ssp2_clk.parent = (reg & BM_CLKCTRL_CLKSEQ_BYPASS_SSP2) ?
&ref_xtal_clk : &ref_io1_clk;
ssp3_clk.parent = (reg & BM_CLKCTRL_CLKSEQ_BYPASS_SSP3) ?
&ref_xtal_clk : &ref_io1_clk;
lcdif_clk.parent = (reg & BM_CLKCTRL_CLKSEQ_BYPASS_DIS_LCDIF) ?
&ref_xtal_clk : &ref_pix_clk;
gpmi_clk.parent = (reg & BM_CLKCTRL_CLKSEQ_BYPASS_GPMI) ?
&ref_xtal_clk : &ref_gpmi_clk;
saif0_clk.parent = (reg & BM_CLKCTRL_CLKSEQ_BYPASS_SAIF0) ?
&ref_xtal_clk : &pll0_clk;
saif1_clk.parent = (reg & BM_CLKCTRL_CLKSEQ_BYPASS_SAIF1) ?
&ref_xtal_clk : &pll0_clk;
__raw_writel(BM_CLKCTRL_CPU_DIV_XTAL_FRAC_EN,
CLKCTRL_BASE_ADDR + HW_CLKCTRL_CPU_CLR);
__raw_writel(BM_CLKCTRL_CPU_DIV_CPU_FRAC_EN,
CLKCTRL_BASE_ADDR + HW_CLKCTRL_CPU_CLR);
__raw_writel(BM_CLKCTRL_HBUS_DIV_FRAC_EN,
CLKCTRL_BASE_ADDR + HW_CLKCTRL_HBUS_CLR);
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_XBUS);
reg &= ~BM_CLKCTRL_XBUS_DIV_FRAC_EN;
__raw_writel(reg, CLKCTRL_BASE_ADDR + HW_CLKCTRL_XBUS);
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_SSP0);
reg &= ~BM_CLKCTRL_SSP0_DIV_FRAC_EN;
__raw_writel(reg, CLKCTRL_BASE_ADDR + HW_CLKCTRL_SSP0);
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_SSP1);
reg &= ~BM_CLKCTRL_SSP1_DIV_FRAC_EN;
__raw_writel(reg, CLKCTRL_BASE_ADDR + HW_CLKCTRL_SSP1);
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_SSP2);
reg &= ~BM_CLKCTRL_SSP2_DIV_FRAC_EN;
__raw_writel(reg, CLKCTRL_BASE_ADDR + HW_CLKCTRL_SSP2);
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_SSP3);
reg &= ~BM_CLKCTRL_SSP3_DIV_FRAC_EN;
__raw_writel(reg, CLKCTRL_BASE_ADDR + HW_CLKCTRL_SSP3);
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_GPMI);
reg &= ~BM_CLKCTRL_GPMI_DIV_FRAC_EN;
__raw_writel(reg, CLKCTRL_BASE_ADDR + HW_CLKCTRL_GPMI);
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_DIS_LCDIF);
reg &= ~BM_CLKCTRL_DIS_LCDIF_DIV_FRAC_EN;
__raw_writel(reg, CLKCTRL_BASE_ADDR + HW_CLKCTRL_DIS_LCDIF);
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_SAIF0);
reg |= BM_CLKCTRL_SAIF0_DIV_FRAC_EN;
__raw_writel(reg, CLKCTRL_BASE_ADDR + HW_CLKCTRL_SAIF0);
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_SAIF1);
reg |= BM_CLKCTRL_SAIF1_DIV_FRAC_EN;
__raw_writel(reg, CLKCTRL_BASE_ADDR + HW_CLKCTRL_SAIF1);
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_HBUS);
reg &= BM_CLKCTRL_HBUS_DIV;
reg |= 3 << BP_CLKCTRL_HBUS_DIV;
__raw_writel(reg, CLKCTRL_BASE_ADDR + HW_CLKCTRL_HBUS);
ret = mxs_clkctrl_timeout(HW_CLKCTRL_HBUS, BM_CLKCTRL_HBUS_ASM_BUSY);
__raw_writel(BM_CLKCTRL_CPU_INTERRUPT_WAIT,
CLKCTRL_BASE_ADDR + HW_CLKCTRL_CPU_SET);
if (!machine_is_m28evk()) {
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_ENET);
reg &= ~BM_CLKCTRL_ENET_SLEEP;
reg |= BM_CLKCTRL_ENET_CLK_OUT_EN;
__raw_writel(reg, CLKCTRL_BASE_ADDR + HW_CLKCTRL_ENET);
}
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_FRAC0);
reg &= ~BM_CLKCTRL_FRAC0_IO0FRAC;
reg |= 30 << BP_CLKCTRL_FRAC0_IO0FRAC;
__raw_writel(reg, CLKCTRL_BASE_ADDR + HW_CLKCTRL_FRAC0);
return ret;
}
int __init mx28_clocks_init(void)
{
clk_misc_init();
clk_set_parent(&ssp0_clk, &ref_io0_clk);
clk_set_parent(&ssp1_clk, &ref_io0_clk);
clk_set_parent(&ssp2_clk, &ref_io1_clk);
clk_set_parent(&ssp3_clk, &ref_io1_clk);
clk_prepare_enable(&cpu_clk);
clk_prepare_enable(&hbus_clk);
clk_prepare_enable(&xbus_clk);
clk_prepare_enable(&emi_clk);
clk_prepare_enable(&uart_clk);
clk_set_parent(&lcdif_clk, &ref_pix_clk);
clk_set_parent(&saif0_clk, &pll0_clk);
clk_set_parent(&saif1_clk, &pll0_clk);
clk_set_rate(&saif0_clk, 24000000);
clk_set_rate(&saif1_clk, 24000000);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
mxs_timer_init(&clk32k_clk, MX28_INT_TIMER0);
return 0;
}
