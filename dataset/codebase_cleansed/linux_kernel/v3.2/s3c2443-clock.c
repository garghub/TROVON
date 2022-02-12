static int s3c2443_gate(void __iomem *reg, struct clk *clk, int enable)
{
u32 ctrlbit = clk->ctrlbit;
u32 con = __raw_readl(reg);
if (enable)
con |= ctrlbit;
else
con &= ~ctrlbit;
__raw_writel(con, reg);
return 0;
}
int s3c2443_clkcon_enable_h(struct clk *clk, int enable)
{
return s3c2443_gate(S3C2443_HCLKCON, clk, enable);
}
int s3c2443_clkcon_enable_p(struct clk *clk, int enable)
{
return s3c2443_gate(S3C2443_PCLKCON, clk, enable);
}
int s3c2443_clkcon_enable_s(struct clk *clk, int enable)
{
return s3c2443_gate(S3C2443_SCLKCON, clk, enable);
}
static unsigned long s3c2443_getrate_mdivclk(struct clk *clk)
{
unsigned long parent_rate = clk_get_rate(clk->parent);
unsigned long div = __raw_readl(S3C2443_CLKDIV0);
div &= S3C2443_CLKDIV0_EXTDIV_MASK;
div >>= (S3C2443_CLKDIV0_EXTDIV_SHIFT-1);
return parent_rate / (div + 1);
}
static unsigned long s3c2443_prediv_getrate(struct clk *clk)
{
unsigned long rate = clk_get_rate(clk->parent);
unsigned long clkdiv0 = __raw_readl(S3C2443_CLKDIV0);
clkdiv0 &= S3C2443_CLKDIV0_PREDIV_MASK;
clkdiv0 >>= S3C2443_CLKDIV0_PREDIV_SHIFT;
return rate / (clkdiv0 + 1);
}
static unsigned long s3c2443_armclk_roundrate(struct clk *clk,
unsigned long rate)
{
unsigned long parent = clk_get_rate(clk->parent);
unsigned long calc;
unsigned best = 256;
unsigned div;
int ptr;
if (!nr_armdiv)
return -EINVAL;
for (ptr = 0; ptr < nr_armdiv; ptr++) {
div = armdiv[ptr];
if (div) {
calc = (parent / div / 1000) * 1000;
if (calc <= rate && div < best)
best = div;
}
}
return parent / best;
}
static unsigned long s3c2443_armclk_getrate(struct clk *clk)
{
unsigned long rate = clk_get_rate(clk->parent);
unsigned long clkcon0;
int val;
if (!nr_armdiv || !armdivmask)
return -EINVAL;
clkcon0 = __raw_readl(S3C2443_CLKDIV0);
clkcon0 &= armdivmask;
val = clkcon0 >> S3C2443_CLKDIV0_ARMDIV_SHIFT;
return rate / armdiv[val];
}
static int s3c2443_armclk_setrate(struct clk *clk, unsigned long rate)
{
unsigned long parent = clk_get_rate(clk->parent);
unsigned long calc;
unsigned div;
unsigned best = 256;
int ptr;
int val = -1;
if (!nr_armdiv || !armdivmask)
return -EINVAL;
for (ptr = 0; ptr < nr_armdiv; ptr++) {
div = armdiv[ptr];
if (div) {
calc = (parent / div / 1000) * 1000;
if (calc <= rate && div < best) {
best = div;
val = ptr;
}
}
}
if (val >= 0) {
unsigned long clkcon0;
clkcon0 = __raw_readl(S3C2443_CLKDIV0);
clkcon0 &= ~armdivmask;
clkcon0 |= val << S3C2443_CLKDIV0_ARMDIV_SHIFT;
__raw_writel(clkcon0, S3C2443_CLKDIV0);
}
return (val == -1) ? -EINVAL : 0;
}
static inline unsigned long s3c2443_get_hdiv(unsigned long clkcon0)
{
clkcon0 &= S3C2443_CLKDIV0_HCLKDIV_MASK;
return clkcon0 + 1;
}
void __init_or_cpufreq s3c2443_common_setup_clocks(pll_fn get_mpll)
{
unsigned long epllcon = __raw_readl(S3C2443_EPLLCON);
unsigned long mpllcon = __raw_readl(S3C2443_MPLLCON);
unsigned long clkdiv0 = __raw_readl(S3C2443_CLKDIV0);
struct clk *xtal_clk;
unsigned long xtal;
unsigned long pll;
unsigned long fclk;
unsigned long hclk;
unsigned long pclk;
int ptr;
xtal_clk = clk_get(NULL, "xtal");
xtal = clk_get_rate(xtal_clk);
clk_put(xtal_clk);
pll = get_mpll(mpllcon, xtal);
clk_msysclk.clk.rate = pll;
fclk = clk_get_rate(&clk_armdiv);
hclk = s3c2443_prediv_getrate(&clk_prediv);
hclk /= s3c2443_get_hdiv(clkdiv0);
pclk = hclk / ((clkdiv0 & S3C2443_CLKDIV0_HALF_PCLK) ? 2 : 1);
s3c24xx_setup_clocks(fclk, hclk, pclk);
printk("CPU: MPLL %s %ld.%03ld MHz, cpu %ld.%03ld MHz, mem %ld.%03ld MHz, pclk %ld.%03ld MHz\n",
(mpllcon & S3C2443_PLLCON_OFF) ? "off":"on",
print_mhz(pll), print_mhz(fclk),
print_mhz(hclk), print_mhz(pclk));
for (ptr = 0; ptr < ARRAY_SIZE(clksrc_clks); ptr++)
s3c_set_clksrc(&clksrc_clks[ptr], true);
if (clk_get_rate(&clk_usb_bus_host.clk) != (48 * 1000 * 1000)) {
printk(KERN_INFO "Warning: USB host bus not at 48MHz\n");
clk_set_rate(&clk_usb_bus_host.clk, 48*1000*1000);
}
printk("CPU: EPLL %s %ld.%03ld MHz, usb-bus %ld.%03ld MHz\n",
(epllcon & S3C2443_PLLCON_OFF) ? "off":"on",
print_mhz(clk_get_rate(&clk_epll)),
print_mhz(clk_get_rate(&clk_usb_bus)));
}
void __init s3c2443_common_init_clocks(int xtal, pll_fn get_mpll,
unsigned int *divs, int nr_divs,
int divmask)
{
int ptr;
armdiv = divs;
nr_armdiv = nr_divs;
armdivmask = divmask;
clk_h.parent = &clk_prediv;
clk_p.parent = &clk_prediv;
clk_usb_bus.parent = &clk_usb_bus_host.clk;
clk_epll.parent = &clk_epllref.clk;
s3c24xx_register_baseclocks(xtal);
s3c24xx_register_clocks(clks, ARRAY_SIZE(clks));
for (ptr = 0; ptr < ARRAY_SIZE(clksrcs); ptr++)
s3c_register_clksrc(clksrcs[ptr], 1);
s3c_register_clksrc(clksrc_clks, ARRAY_SIZE(clksrc_clks));
s3c_register_clocks(init_clocks, ARRAY_SIZE(init_clocks));
s3c_register_clocks(init_clocks_off, ARRAY_SIZE(init_clocks_off));
s3c_disable_clocks(init_clocks_off, ARRAY_SIZE(init_clocks_off));
s3c2443_common_setup_clocks(get_mpll);
}
