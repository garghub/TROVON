static int clk_pccr_enable(struct clk *clk)
{
unsigned long reg;
if (!clk->enable_reg)
return 0;
reg = __raw_readl(clk->enable_reg);
reg |= 1 << clk->enable_shift;
__raw_writel(reg, clk->enable_reg);
return 0;
}
static void clk_pccr_disable(struct clk *clk)
{
unsigned long reg;
if (!clk->enable_reg)
return;
reg = __raw_readl(clk->enable_reg);
reg &= ~(1 << clk->enable_shift);
__raw_writel(reg, clk->enable_reg);
}
static int clk_spll_enable(struct clk *clk)
{
unsigned long reg;
reg = __raw_readl(CCM_CSCR);
reg |= CCM_CSCR_SPEN;
__raw_writel(reg, CCM_CSCR);
while (!(__raw_readl(CCM_SPCTL1) & CCM_SPCTL1_LF));
return 0;
}
static void clk_spll_disable(struct clk *clk)
{
unsigned long reg;
reg = __raw_readl(CCM_CSCR);
reg &= ~CCM_CSCR_SPEN;
__raw_writel(reg, CCM_CSCR);
}
static int clk_cpu_set_parent(struct clk *clk, struct clk *parent)
{
int cscr = __raw_readl(CCM_CSCR);
if (clk->parent == parent)
return 0;
if (mx27_revision() >= IMX_CHIP_REVISION_2_0) {
if (parent == &mpll_main1_clk) {
cscr |= CCM_CSCR_ARM_SRC;
} else {
if (parent == &mpll_main2_clk)
cscr &= ~CCM_CSCR_ARM_SRC;
else
return -EINVAL;
}
__raw_writel(cscr, CCM_CSCR);
clk->parent = parent;
return 0;
}
return -ENODEV;
}
static unsigned long round_rate_cpu(struct clk *clk, unsigned long rate)
{
int div;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
div = parent_rate / rate;
if (parent_rate % rate)
div++;
if (div > 4)
div = 4;
return parent_rate / div;
}
static int set_rate_cpu(struct clk *clk, unsigned long rate)
{
unsigned int div;
uint32_t reg;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
div = parent_rate / rate;
if (div > 4 || div < 1 || ((parent_rate / div) != rate))
return -EINVAL;
div--;
reg = __raw_readl(CCM_CSCR);
if (mx27_revision() >= IMX_CHIP_REVISION_2_0) {
reg &= ~(3 << 12);
reg |= div << 12;
reg &= ~(CCM_CSCR_FPM | CCM_CSCR_SPEN);
__raw_writel(reg | CCM_CSCR_UPDATE_DIS, CCM_CSCR);
} else {
printk(KERN_ERR "Can't set CPU frequency!\n");
}
return 0;
}
static unsigned long round_rate_per(struct clk *clk, unsigned long rate)
{
u32 div;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
div = parent_rate / rate;
if (parent_rate % rate)
div++;
if (div > 64)
div = 64;
return parent_rate / div;
}
static int set_rate_per(struct clk *clk, unsigned long rate)
{
u32 reg;
u32 div;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
if (clk->id < 0 || clk->id > 3)
return -EINVAL;
div = parent_rate / rate;
if (div > 64 || div < 1 || ((parent_rate / div) != rate))
return -EINVAL;
div--;
reg = __raw_readl(CCM_PCDR1) & ~(0x3f << (clk->id << 3));
reg |= div << (clk->id << 3);
__raw_writel(reg, CCM_PCDR1);
return 0;
}
static unsigned long get_rate_usb(struct clk *clk)
{
unsigned long usb_pdf;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
usb_pdf = (__raw_readl(CCM_CSCR) >> 28) & 0x7;
return parent_rate / (usb_pdf + 1U);
}
static unsigned long get_rate_ssix(struct clk *clk, unsigned long pdf)
{
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
if (mx27_revision() >= IMX_CHIP_REVISION_2_0)
pdf += 4;
else
pdf = (pdf < 2) ? 124UL : pdf;
return 2UL * parent_rate / pdf;
}
static unsigned long get_rate_ssi1(struct clk *clk)
{
return get_rate_ssix(clk, (__raw_readl(CCM_PCDR0) >> 16) & 0x3f);
}
static unsigned long get_rate_ssi2(struct clk *clk)
{
return get_rate_ssix(clk, (__raw_readl(CCM_PCDR0) >> 26) & 0x3f);
}
static unsigned long get_rate_nfc(struct clk *clk)
{
unsigned long nfc_pdf;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
if (mx27_revision() >= IMX_CHIP_REVISION_2_0)
nfc_pdf = (__raw_readl(CCM_PCDR0) >> 6) & 0xf;
else
nfc_pdf = (__raw_readl(CCM_PCDR0) >> 12) & 0xf;
return parent_rate / (nfc_pdf + 1);
}
static unsigned long get_rate_vpu(struct clk *clk)
{
unsigned long vpu_pdf;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
if (mx27_revision() >= IMX_CHIP_REVISION_2_0) {
vpu_pdf = (__raw_readl(CCM_PCDR0) >> 10) & 0x3f;
vpu_pdf += 4;
} else {
vpu_pdf = (__raw_readl(CCM_PCDR0) >> 8) & 0xf;
vpu_pdf = (vpu_pdf < 2) ? 124 : vpu_pdf;
}
return 2UL * parent_rate / vpu_pdf;
}
static unsigned long round_rate_parent(struct clk *clk, unsigned long rate)
{
return clk->parent->round_rate(clk->parent, rate);
}
static unsigned long get_rate_parent(struct clk *clk)
{
return clk_get_rate(clk->parent);
}
static int set_rate_parent(struct clk *clk, unsigned long rate)
{
return clk->parent->set_rate(clk->parent, rate);
}
static unsigned long get_rate_high_reference(struct clk *clk)
{
return external_high_reference;
}
static unsigned long get_rate_low_reference(struct clk *clk)
{
return external_low_reference;
}
static unsigned long get_rate_fpm(struct clk *clk)
{
return clk_get_rate(clk->parent) * 1024;
}
static unsigned long get_rate_mpll(struct clk *clk)
{
return mxc_decode_pll(__raw_readl(CCM_MPCTL0),
clk_get_rate(clk->parent));
}
static unsigned long get_rate_mpll_main(struct clk *clk)
{
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
if (mx27_revision() >= IMX_CHIP_REVISION_2_0 && clk->id == 1)
return 2UL * parent_rate / 3UL;
return parent_rate;
}
static unsigned long get_rate_spll(struct clk *clk)
{
uint32_t reg;
unsigned long rate;
rate = clk_get_rate(clk->parent);
reg = __raw_readl(CCM_SPCTL0);
if (mx27_revision() >= IMX_CHIP_REVISION_2_0)
__raw_writel(reg, CCM_SPCTL0);
return mxc_decode_pll(reg, rate);
}
static unsigned long get_rate_cpu(struct clk *clk)
{
u32 div;
unsigned long rate;
if (mx27_revision() >= IMX_CHIP_REVISION_2_0)
div = (__raw_readl(CCM_CSCR) >> 12) & 0x3;
else
div = (__raw_readl(CCM_CSCR) >> 13) & 0x7;
rate = clk_get_rate(clk->parent);
return rate / (div + 1);
}
static unsigned long get_rate_ahb(struct clk *clk)
{
unsigned long rate, bclk_pdf;
if (mx27_revision() >= IMX_CHIP_REVISION_2_0)
bclk_pdf = (__raw_readl(CCM_CSCR) >> 8) & 0x3;
else
bclk_pdf = (__raw_readl(CCM_CSCR) >> 9) & 0xf;
rate = clk_get_rate(clk->parent);
return rate / (bclk_pdf + 1);
}
static unsigned long get_rate_ipg(struct clk *clk)
{
unsigned long rate, ipg_pdf;
if (mx27_revision() >= IMX_CHIP_REVISION_2_0)
return clk_get_rate(clk->parent);
else
ipg_pdf = (__raw_readl(CCM_CSCR) >> 8) & 1;
rate = clk_get_rate(clk->parent);
return rate / (ipg_pdf + 1);
}
static unsigned long get_rate_per(struct clk *clk)
{
unsigned long perclk_pdf, parent_rate;
parent_rate = clk_get_rate(clk->parent);
if (clk->id < 0 || clk->id > 3)
return 0;
perclk_pdf = (__raw_readl(CCM_PCDR1) >> (clk->id << 3)) & 0x3f;
return parent_rate / (perclk_pdf + 1);
}
static void __init to2_adjust_clocks(void)
{
unsigned long cscr = __raw_readl(CCM_CSCR);
if (mx27_revision() >= IMX_CHIP_REVISION_2_0) {
if (cscr & CCM_CSCR_ARM_SRC)
cpu_clk.parent = &mpll_main1_clk;
if (!(cscr & CCM_CSCR_SSI2))
ssi1_clk.parent = &spll_clk;
if (!(cscr & CCM_CSCR_SSI1))
ssi1_clk.parent = &spll_clk;
if (!(cscr & CCM_CSCR_VPU))
vpu_clk.parent = &spll_clk;
} else {
cpu_clk.parent = &mpll_clk;
cpu_clk.set_parent = NULL;
cpu_clk.round_rate = NULL;
cpu_clk.set_rate = NULL;
ahb_clk.parent = &mpll_clk;
per1_clk.parent = &mpll_clk;
per2_clk.parent = &mpll_clk;
per3_clk.parent = &mpll_clk;
per4_clk.parent = &mpll_clk;
ssi1_clk.parent = &mpll_clk;
ssi2_clk.parent = &mpll_clk;
vpu_clk.parent = &mpll_clk;
}
}
int __init mx27_clocks_init(unsigned long fref)
{
u32 cscr = __raw_readl(CCM_CSCR);
external_high_reference = fref;
if (cscr & CCM_CSCR_MCU)
mpll_clk.parent = &ckih_clk;
else
mpll_clk.parent = &fpm_clk;
if (cscr & CCM_CSCR_SP)
spll_clk.parent = &ckih_clk;
else
spll_clk.parent = &fpm_clk;
to2_adjust_clocks();
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
__raw_writel(0, CCM_PCCR0);
__raw_writel((1 << 10) | (1 << 19), CCM_PCCR1);
spll_clk.disable(&spll_clk);
clk_enable(&per1_clk);
clk_enable(&gpio_clk);
clk_enable(&emi_clk);
clk_enable(&iim_clk);
#if defined(CONFIG_DEBUG_LL) && !defined(CONFIG_DEBUG_ICEDCC)
clk_enable(&uart1_clk);
#endif
mxc_timer_init(&gpt1_clk, MX27_IO_ADDRESS(MX27_GPT1_BASE_ADDR),
MX27_INT_GPT1);
return 0;
}
