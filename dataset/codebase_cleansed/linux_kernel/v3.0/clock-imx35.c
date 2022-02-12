static void calc_dividers(u32 div, u32 *pre, u32 *post, u32 maxpost)
{
u32 min_pre, temp_pre, old_err, err;
min_pre = (div - 1) / maxpost + 1;
old_err = 8;
for (temp_pre = 8; temp_pre >= min_pre; temp_pre--) {
if (div > (temp_pre * maxpost))
break;
if (div < (temp_pre * temp_pre))
continue;
err = div % temp_pre;
if (err == 0) {
*pre = temp_pre;
break;
}
err = temp_pre - err;
if (err < old_err) {
old_err = err;
*pre = temp_pre;
}
}
*post = (div + *pre - 1) / *pre;
}
static void calc_dividers_3_6(u32 div, u32 *pre, u32 *post)
{
if (div >= 512) {
*pre = 8;
*post = 64;
} else if (div >= 64) {
calc_dividers(div, pre, post, 64);
} else if (div <= 8) {
*pre = div;
*post = 1;
} else {
*pre = 1;
*post = div;
}
}
static void calc_dividers_3_3(u32 div, u32 *pre, u32 *post)
{
if (div >= 64) {
*pre = *post = 8;
} else if (div > 8) {
calc_dividers(div, pre, post, 8);
} else {
*pre = 1;
*post = div;
}
}
static unsigned long get_rate_mpll(void)
{
ulong mpctl = __raw_readl(CCM_BASE + CCM_MPCTL);
return mxc_decode_pll(mpctl, 24000000);
}
static unsigned long get_rate_ppll(void)
{
ulong ppctl = __raw_readl(CCM_BASE + CCM_PPCTL);
return mxc_decode_pll(ppctl, 24000000);
}
static unsigned long get_rate_arm(void)
{
unsigned long pdr0 = __raw_readl(CCM_BASE + CCM_PDR0);
struct arm_ahb_div *aad;
unsigned long fref = get_rate_mpll();
aad = &clk_consumer[(pdr0 >> 16) & 0xf];
if (aad->sel)
fref = fref * 3 / 4;
return fref / aad->arm;
}
static unsigned long get_rate_ahb(struct clk *clk)
{
unsigned long pdr0 = __raw_readl(CCM_BASE + CCM_PDR0);
struct arm_ahb_div *aad;
unsigned long fref = get_rate_arm();
aad = &clk_consumer[(pdr0 >> 16) & 0xf];
return fref / aad->ahb;
}
static unsigned long get_rate_ipg(struct clk *clk)
{
return get_rate_ahb(NULL) >> 1;
}
static unsigned long get_rate_uart(struct clk *clk)
{
unsigned long pdr3 = __raw_readl(CCM_BASE + CCM_PDR3);
unsigned long pdr4 = __raw_readl(CCM_BASE + CCM_PDR4);
unsigned long div = ((pdr4 >> 10) & 0x3f) + 1;
if (pdr3 & (1 << 14))
return get_rate_arm() / div;
else
return get_rate_ppll() / div;
}
static unsigned long get_rate_sdhc(struct clk *clk)
{
unsigned long pdr3 = __raw_readl(CCM_BASE + CCM_PDR3);
unsigned long div, rate;
if (pdr3 & (1 << 6))
rate = get_rate_arm();
else
rate = get_rate_ppll();
switch (clk->id) {
default:
case 0:
div = pdr3 & 0x3f;
break;
case 1:
div = (pdr3 >> 8) & 0x3f;
break;
case 2:
div = (pdr3 >> 16) & 0x3f;
break;
}
return rate / (div + 1);
}
static unsigned long get_rate_mshc(struct clk *clk)
{
unsigned long pdr1 = __raw_readl(CCM_BASE + CCM_PDR1);
unsigned long div1, div2, rate;
if (pdr1 & (1 << 7))
rate = get_rate_arm();
else
rate = get_rate_ppll();
div1 = (pdr1 >> 29) & 0x7;
div2 = (pdr1 >> 22) & 0x3f;
return rate / ((div1 + 1) * (div2 + 1));
}
static unsigned long get_rate_ssi(struct clk *clk)
{
unsigned long pdr2 = __raw_readl(CCM_BASE + CCM_PDR2);
unsigned long div1, div2, rate;
if (pdr2 & (1 << 6))
rate = get_rate_arm();
else
rate = get_rate_ppll();
switch (clk->id) {
default:
case 0:
div1 = pdr2 & 0x3f;
div2 = (pdr2 >> 24) & 0x7;
break;
case 1:
div1 = (pdr2 >> 8) & 0x3f;
div2 = (pdr2 >> 27) & 0x7;
break;
}
return rate / ((div1 + 1) * (div2 + 1));
}
static unsigned long get_rate_csi(struct clk *clk)
{
unsigned long pdr2 = __raw_readl(CCM_BASE + CCM_PDR2);
unsigned long rate;
if (pdr2 & (1 << 7))
rate = get_rate_arm();
else
rate = get_rate_ppll();
return rate / (((pdr2 >> 16) & 0x3f) + 1);
}
static unsigned long get_rate_otg(struct clk *clk)
{
unsigned long pdr4 = __raw_readl(CCM_BASE + CCM_PDR4);
unsigned long rate;
if (pdr4 & (1 << 9))
rate = get_rate_arm();
else
rate = get_rate_ppll();
return rate / (((pdr4 >> 22) & 0x3f) + 1);
}
static unsigned long get_rate_ipg_per(struct clk *clk)
{
unsigned long pdr0 = __raw_readl(CCM_BASE + CCM_PDR0);
unsigned long pdr4 = __raw_readl(CCM_BASE + CCM_PDR4);
unsigned long div;
if (pdr0 & (1 << 26)) {
div = (pdr4 >> 16) & 0x3f;
return get_rate_arm() / (div + 1);
} else {
div = (pdr0 >> 12) & 0x7;
return get_rate_ahb(NULL) / (div + 1);
}
}
static unsigned long get_rate_hsp(struct clk *clk)
{
unsigned long hsp_podf = (__raw_readl(CCM_BASE + CCM_PDR0) >> 20) & 0x03;
unsigned long fref = get_rate_mpll();
if (fref > 400 * 1000 * 1000) {
switch (hsp_podf) {
case 0:
return fref >> 2;
case 1:
return fref >> 3;
case 2:
return fref / 3;
}
} else {
switch (hsp_podf) {
case 0:
case 2:
return fref / 3;
case 1:
return fref / 6;
}
}
return 0;
}
static int clk_cgr_enable(struct clk *clk)
{
u32 reg;
reg = __raw_readl(clk->enable_reg);
reg |= 3 << clk->enable_shift;
__raw_writel(reg, clk->enable_reg);
return 0;
}
static void clk_cgr_disable(struct clk *clk)
{
u32 reg;
reg = __raw_readl(clk->enable_reg);
reg &= ~(3 << clk->enable_shift);
__raw_writel(reg, clk->enable_reg);
}
static int clk_dummy_enable(struct clk *clk)
{
return 0;
}
static void clk_dummy_disable(struct clk *clk)
{
}
static unsigned long get_rate_nfc(struct clk *clk)
{
unsigned long div1;
div1 = (__raw_readl(CCM_BASE + CCM_PDR4) >> 28) + 1;
return get_rate_ahb(NULL) / div1;
}
int __init mx35_clocks_init()
{
unsigned int cgr2 = 3 << 26, cgr3 = 0;
#if defined(CONFIG_DEBUG_LL) && !defined(CONFIG_DEBUG_ICEDCC)
cgr2 |= 3 << 16;
#endif
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
__raw_writel((3 << 18), CCM_BASE + CCM_CGR0);
__raw_writel((3 << 2) | (3 << 4) | (3 << 6) | (3 << 8) | (3 << 16),
CCM_BASE + CCM_CGR1);
if (!(__raw_readl(CCM_BASE + CCM_RCSR) & (3 << 10))) {
cgr2 |= 3 << 16 | 3 << 4;
cgr3 |= 3 << 2;
}
__raw_writel(cgr2, CCM_BASE + CCM_CGR2);
__raw_writel(cgr3, CCM_BASE + CCM_CGR3);
clk_enable(&iim_clk);
mx35_read_cpu_rev();
#ifdef CONFIG_MXC_USE_EPIT
epit_timer_init(&epit1_clk,
MX35_IO_ADDRESS(MX35_EPIT1_BASE_ADDR), MX35_INT_EPIT1);
#else
mxc_timer_init(&gpt_clk,
MX35_IO_ADDRESS(MX35_GPT1_BASE_ADDR), MX35_INT_GPT);
#endif
return 0;
}
