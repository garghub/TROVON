static unsigned long clk_sspll_recalc(struct clk *clk)
{
int pll;
unsigned long mult = 0, prediv = 1, postdiv = 1;
unsigned long ref = OSC_FREQ_ONCHIP, ret;
u32 tmp;
if (WARN_ON(!clk->pll_data))
return clk->rate;
if (!clk_ctrl_regs) {
void __iomem *tmp;
tmp = ioremap(TNETV107X_CLOCK_CONTROL_BASE, SZ_4K);
if (WARN(!tmp, "failed ioremap for clock control regs\n"))
return clk->parent ? clk->parent->rate : 0;
for (pll = 0; pll < N_PLLS; pll++)
sspll_regs[pll] = tmp + sspll_regs_base[pll];
clk_ctrl_regs = tmp;
}
pll = clk->pll_data->num;
tmp = __raw_readl(&clk_ctrl_regs->pll_bypass);
if (!(tmp & bypass_mask[pll])) {
mult = __raw_readl(&sspll_regs[pll]->mult_factor);
prediv = __raw_readl(&sspll_regs[pll]->pre_div) + 1;
postdiv = __raw_readl(&sspll_regs[pll]->post_div) + 1;
}
tmp = __raw_readl(clk->pll_data->base + PLLCTL);
if (tmp & PLLCTL_CLKMODE)
ref = pll_ext_freq[pll];
clk->pll_data->input_rate = ref;
tmp = __raw_readl(clk->pll_data->base + PLLCTL);
if (!(tmp & PLLCTL_PLLEN))
return ref;
ret = ref;
if (mult)
ret += ((unsigned long long)ref * mult) / 256;
ret /= (prediv * postdiv);
return ret;
}
static void tnetv107x_watchdog_reset(struct platform_device *pdev)
{
struct wdt_regs __iomem *regs;
regs = ioremap(pdev->resource[0].start, SZ_4K);
__raw_writel(0x7777, &regs->disable_lock);
__raw_writel(0xcccc, &regs->disable_lock);
__raw_writel(0xdddd, &regs->disable_lock);
__raw_writel(0, &regs->disable);
__raw_writel(0x5a5a, &regs->prescale_lock);
__raw_writel(0xa5a5, &regs->prescale_lock);
__raw_writel(0, &regs->prescale);
__raw_writel(0x6666, &regs->change_lock);
__raw_writel(0xbbbb, &regs->change_lock);
__raw_writel(1, &regs->change);
__raw_writel(0x7777, &regs->disable_lock);
__raw_writel(0xcccc, &regs->disable_lock);
__raw_writel(0xdddd, &regs->disable_lock);
__raw_writel(1, &regs->disable);
__raw_writel(0x5555, &regs->kick_lock);
__raw_writel(0xaaaa, &regs->kick_lock);
__raw_writel(1, &regs->kick);
}
void tnetv107x_restart(char mode, const char *cmd)
{
tnetv107x_watchdog_reset(&tnetv107x_wdt_device);
}
void __init tnetv107x_init(void)
{
davinci_common_init(&tnetv107x_soc_info);
}
