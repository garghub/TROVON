static unsigned long get_rate_mpll(void)
{
ulong mpctl = __raw_readl(CRM_BASE + CCM_MPCTL);
return mxc_decode_pll(mpctl, 24000000);
}
static unsigned long get_rate_upll(void)
{
ulong mpctl = __raw_readl(CRM_BASE + CCM_UPCTL);
return mxc_decode_pll(mpctl, 24000000);
}
unsigned long get_rate_arm(struct clk *clk)
{
unsigned long cctl = readl(CRM_BASE + CCM_CCTL);
unsigned long rate = get_rate_mpll();
if (cctl & (1 << 14))
rate = (rate * 3) >> 2;
return rate / ((cctl >> 30) + 1);
}
static unsigned long get_rate_ahb(struct clk *clk)
{
unsigned long cctl = readl(CRM_BASE + CCM_CCTL);
return get_rate_arm(NULL) / (((cctl >> 28) & 0x3) + 1);
}
static unsigned long get_rate_ipg(struct clk *clk)
{
return get_rate_ahb(NULL) >> 1;
}
static unsigned long get_rate_per(int per)
{
unsigned long ofs = (per & 0x3) * 8;
unsigned long reg = per & ~0x3;
unsigned long val = (readl(CRM_BASE + CCM_PCDR0 + reg) >> ofs) & 0x3f;
unsigned long fref;
if (readl(CRM_BASE + 0x64) & (1 << per))
fref = get_rate_upll();
else
fref = get_rate_ahb(NULL);
return fref / (val + 1);
}
static unsigned long get_rate_uart(struct clk *clk)
{
return get_rate_per(15);
}
static unsigned long get_rate_ssi2(struct clk *clk)
{
return get_rate_per(14);
}
static unsigned long get_rate_ssi1(struct clk *clk)
{
return get_rate_per(13);
}
static unsigned long get_rate_i2c(struct clk *clk)
{
return get_rate_per(6);
}
static unsigned long get_rate_nfc(struct clk *clk)
{
return get_rate_per(8);
}
static unsigned long get_rate_gpt(struct clk *clk)
{
return get_rate_per(5);
}
static unsigned long get_rate_lcdc(struct clk *clk)
{
return get_rate_per(7);
}
static unsigned long get_rate_esdhc1(struct clk *clk)
{
return get_rate_per(3);
}
static unsigned long get_rate_esdhc2(struct clk *clk)
{
return get_rate_per(4);
}
static unsigned long get_rate_csi(struct clk *clk)
{
return get_rate_per(0);
}
static unsigned long get_rate_otg(struct clk *clk)
{
unsigned long cctl = readl(CRM_BASE + CCM_CCTL);
unsigned long rate = get_rate_upll();
return (cctl & (1 << 23)) ? 0 : rate / ((0x3F & (cctl >> 16)) + 1);
}
static int clk_cgcr_enable(struct clk *clk)
{
u32 reg;
reg = __raw_readl(clk->enable_reg);
reg |= 1 << clk->enable_shift;
__raw_writel(reg, clk->enable_reg);
return 0;
}
static void clk_cgcr_disable(struct clk *clk)
{
u32 reg;
reg = __raw_readl(clk->enable_reg);
reg &= ~(1 << clk->enable_shift);
__raw_writel(reg, clk->enable_reg);
}
int __init mx25_clocks_init(void)
{
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
__raw_writel((1 << 19), CRM_BASE + CCM_CGCR0);
__raw_writel((0xf << 16) | (3 << 26), CRM_BASE + CCM_CGCR1);
__raw_writel((1 << 5), CRM_BASE + CCM_CGCR2);
#if defined(CONFIG_DEBUG_LL) && !defined(CONFIG_DEBUG_ICEDCC)
clk_enable(&uart1_clk);
#endif
__raw_writel(__raw_readl(CRM_BASE+0x64) | (1 << 7) | (1 << 0),
CRM_BASE + 0x64);
__raw_writel(__raw_readl(CRM_BASE+0x64) & ~(1 << 5), CRM_BASE + 0x64);
clk_enable(&iim_clk);
imx_print_silicon_rev("i.MX25", mx25_revision());
clk_disable(&iim_clk);
mxc_timer_init(&gpt_clk, MX25_IO_ADDRESS(MX25_GPT1_BASE_ADDR), 54);
return 0;
}
