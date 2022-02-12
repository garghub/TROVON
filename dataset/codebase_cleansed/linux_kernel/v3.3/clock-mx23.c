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
static unsigned long pll_clk_get_rate(struct clk *clk)
{
return 480000000;
}
static int pll_clk_enable(struct clk *clk)
{
__raw_writel(BM_CLKCTRL_PLLCTRL0_POWER |
BM_CLKCTRL_PLLCTRL0_EN_USB_CLKS,
CLKCTRL_BASE_ADDR + HW_CLKCTRL_PLLCTRL0_SET);
udelay(10);
return 0;
}
static void pll_clk_disable(struct clk *clk)
{
__raw_writel(BM_CLKCTRL_PLLCTRL0_POWER |
BM_CLKCTRL_PLLCTRL0_EN_USB_CLKS,
CLKCTRL_BASE_ADDR + HW_CLKCTRL_PLLCTRL0_CLR);
}
static unsigned long rtc_clk_get_rate(struct clk *clk)
{
return clk_get_rate(clk->parent) / 768;
}
static unsigned long clk32k_clk_get_rate(struct clk *clk)
{
return clk->parent->get_rate(clk->parent) / 750;
}
static int cpu_clk_set_rate(struct clk *clk, unsigned long rate)
{
u32 reg, bm_busy, div_max, d, f, div, frac;
unsigned long diff, parent_rate, calc_rate;
int i;
parent_rate = clk_get_rate(clk->parent);
if (clk->parent == &ref_xtal_clk) {
div_max = BM_CLKCTRL_CPU_DIV_XTAL >> BP_CLKCTRL_CPU_DIV_XTAL;
bm_busy = BM_CLKCTRL_CPU_BUSY_REF_XTAL;
div = DIV_ROUND_UP(parent_rate, rate);
if (div == 0 || div > div_max)
return -EINVAL;
} else {
div_max = BM_CLKCTRL_CPU_DIV_CPU >> BP_CLKCTRL_CPU_DIV_CPU;
bm_busy = BM_CLKCTRL_CPU_BUSY_REF_CPU;
rate >>= PARENT_RATE_SHIFT;
parent_rate >>= PARENT_RATE_SHIFT;
diff = parent_rate;
div = frac = 1;
for (d = 1; d <= div_max; d++) {
f = parent_rate * 18 / d / rate;
if ((parent_rate * 18 / d) % rate)
f++;
if (f < 18 || f > 35)
continue;
calc_rate = parent_rate * 18 / f / d;
if (calc_rate > rate)
continue;
if (rate - calc_rate < diff) {
frac = f;
div = d;
diff = rate - calc_rate;
}
if (diff == 0)
break;
}
if (diff == parent_rate)
return -EINVAL;
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_FRAC);
reg &= ~BM_CLKCTRL_FRAC_CPUFRAC;
reg |= frac;
__raw_writel(reg, CLKCTRL_BASE_ADDR + HW_CLKCTRL_FRAC);
}
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_CPU);
reg &= ~BM_CLKCTRL_CPU_DIV_CPU;
reg |= div << BP_CLKCTRL_CPU_DIV_CPU;
__raw_writel(reg, CLKCTRL_BASE_ADDR + HW_CLKCTRL_CPU);
for (i = 10000; i; i--)
if (!(__raw_readl(CLKCTRL_BASE_ADDR +
HW_CLKCTRL_CPU) & bm_busy))
break;
if (!i) {
pr_err("%s: divider writing timeout\n", __func__);
return -ETIMEDOUT;
}
return 0;
}
static int clk_misc_init(void)
{
u32 reg;
int i;
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_CLKSEQ);
cpu_clk.parent = (reg & BM_CLKCTRL_CLKSEQ_BYPASS_CPU) ?
&ref_xtal_clk : &ref_cpu_clk;
emi_clk.parent = (reg & BM_CLKCTRL_CLKSEQ_BYPASS_EMI) ?
&ref_xtal_clk : &ref_emi_clk;
ssp_clk.parent = (reg & BM_CLKCTRL_CLKSEQ_BYPASS_SSP) ?
&ref_xtal_clk : &ref_io_clk;
gpmi_clk.parent = (reg & BM_CLKCTRL_CLKSEQ_BYPASS_GPMI) ?
&ref_xtal_clk : &ref_io_clk;
lcdif_clk.parent = (reg & BM_CLKCTRL_CLKSEQ_BYPASS_PIX) ?
&ref_xtal_clk : &ref_pix_clk;
__raw_writel(BM_CLKCTRL_CPU_DIV_XTAL_FRAC_EN,
CLKCTRL_BASE_ADDR + HW_CLKCTRL_CPU_CLR);
__raw_writel(BM_CLKCTRL_CPU_DIV_CPU_FRAC_EN,
CLKCTRL_BASE_ADDR + HW_CLKCTRL_CPU_CLR);
__raw_writel(BM_CLKCTRL_HBUS_DIV_FRAC_EN,
CLKCTRL_BASE_ADDR + HW_CLKCTRL_HBUS_CLR);
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_XBUS);
reg &= ~BM_CLKCTRL_XBUS_DIV_FRAC_EN;
__raw_writel(reg, CLKCTRL_BASE_ADDR + HW_CLKCTRL_XBUS);
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_SSP);
reg &= ~BM_CLKCTRL_SSP_DIV_FRAC_EN;
__raw_writel(reg, CLKCTRL_BASE_ADDR + HW_CLKCTRL_SSP);
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_GPMI);
reg &= ~BM_CLKCTRL_GPMI_DIV_FRAC_EN;
__raw_writel(reg, CLKCTRL_BASE_ADDR + HW_CLKCTRL_GPMI);
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_PIX);
reg &= ~BM_CLKCTRL_PIX_DIV_FRAC_EN;
__raw_writel(reg, CLKCTRL_BASE_ADDR + HW_CLKCTRL_PIX);
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_HBUS);
reg &= BM_CLKCTRL_HBUS_DIV;
reg |= 3 << BP_CLKCTRL_HBUS_DIV;
__raw_writel(reg, CLKCTRL_BASE_ADDR + HW_CLKCTRL_HBUS);
for (i = 10000; i; i--)
if (!(__raw_readl(CLKCTRL_BASE_ADDR +
HW_CLKCTRL_HBUS) & BM_CLKCTRL_HBUS_BUSY))
break;
if (!i) {
pr_err("%s: divider writing timeout\n", __func__);
return -ETIMEDOUT;
}
__raw_writel(BM_CLKCTRL_CPU_INTERRUPT_WAIT,
CLKCTRL_BASE_ADDR + HW_CLKCTRL_CPU_SET);
reg = __raw_readl(CLKCTRL_BASE_ADDR + HW_CLKCTRL_FRAC);
reg &= ~BM_CLKCTRL_FRAC_IOFRAC;
reg |= 30 << BP_CLKCTRL_FRAC_IOFRAC;
__raw_writel(reg, CLKCTRL_BASE_ADDR + HW_CLKCTRL_FRAC);
return 0;
}
int __init mx23_clocks_init(void)
{
clk_misc_init();
clk_set_parent(&ssp_clk, &ref_io_clk);
clk_prepare_enable(&cpu_clk);
clk_prepare_enable(&hbus_clk);
clk_prepare_enable(&xbus_clk);
clk_prepare_enable(&emi_clk);
clk_prepare_enable(&uart_clk);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
mxs_timer_init(&clk32k_clk, MX23_INT_TIMER0);
return 0;
}
