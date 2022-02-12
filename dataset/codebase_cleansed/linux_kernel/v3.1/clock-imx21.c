static int _clk_enable(struct clk *clk)
{
u32 reg;
reg = __raw_readl(clk->enable_reg);
reg |= 1 << clk->enable_shift;
__raw_writel(reg, clk->enable_reg);
return 0;
}
static void _clk_disable(struct clk *clk)
{
u32 reg;
reg = __raw_readl(clk->enable_reg);
reg &= ~(1 << clk->enable_shift);
__raw_writel(reg, clk->enable_reg);
}
static unsigned long _clk_generic_round_rate(struct clk *clk,
unsigned long rate,
u32 max_divisor)
{
u32 div;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
div = parent_rate / rate;
if (parent_rate % rate)
div++;
if (div > max_divisor)
div = max_divisor;
return parent_rate / div;
}
static int _clk_spll_enable(struct clk *clk)
{
u32 reg;
reg = __raw_readl(CCM_CSCR);
reg |= CCM_CSCR_SPEN;
__raw_writel(reg, CCM_CSCR);
while ((__raw_readl(CCM_SPCTL1) & CCM_SPCTL1_LF) == 0)
;
return 0;
}
static void _clk_spll_disable(struct clk *clk)
{
u32 reg;
reg = __raw_readl(CCM_CSCR);
reg &= ~CCM_CSCR_SPEN;
__raw_writel(reg, CCM_CSCR);
}
static unsigned long _clk_perclkx_round_rate(struct clk *clk,
unsigned long rate)
{
return _clk_generic_round_rate(clk, rate, 64);
}
static int _clk_perclkx_set_rate(struct clk *clk, unsigned long rate)
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
reg =
__raw_readl(CCM_PCDR1) & ~(CCM_PCDR1_PERDIV1_MASK <<
(clk->id << 3));
reg |= div << (clk->id << 3);
__raw_writel(reg, CCM_PCDR1);
return 0;
}
static unsigned long _clk_usb_recalc(struct clk *clk)
{
unsigned long usb_pdf;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
usb_pdf = (CSCR() & CCM_CSCR_USB_MASK) >> CCM_CSCR_USB_OFFSET;
return parent_rate / (usb_pdf + 1U);
}
static unsigned long _clk_usb_round_rate(struct clk *clk,
unsigned long rate)
{
return _clk_generic_round_rate(clk, rate, 8);
}
static int _clk_usb_set_rate(struct clk *clk, unsigned long rate)
{
u32 reg;
u32 div;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
div = parent_rate / rate;
if (div > 8 || div < 1 || ((parent_rate / div) != rate))
return -EINVAL;
div--;
reg = CSCR() & ~CCM_CSCR_USB_MASK;
reg |= div << CCM_CSCR_USB_OFFSET;
__raw_writel(reg, CCM_CSCR);
return 0;
}
static unsigned long _clk_ssix_recalc(struct clk *clk, unsigned long pdf)
{
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
pdf = (pdf < 2) ? 124UL : pdf;
return 2UL * parent_rate / pdf;
}
static unsigned long _clk_ssi1_recalc(struct clk *clk)
{
return _clk_ssix_recalc(clk,
(PCDR0() & CCM_PCDR0_SSI1BAUDDIV_MASK)
>> CCM_PCDR0_SSI1BAUDDIV_OFFSET);
}
static unsigned long _clk_ssi2_recalc(struct clk *clk)
{
return _clk_ssix_recalc(clk,
(PCDR0() & CCM_PCDR0_SSI2BAUDDIV_MASK) >>
CCM_PCDR0_SSI2BAUDDIV_OFFSET);
}
static unsigned long _clk_nfc_recalc(struct clk *clk)
{
unsigned long nfc_pdf;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
nfc_pdf = (PCDR0() & CCM_PCDR0_NFCDIV_MASK)
>> CCM_PCDR0_NFCDIV_OFFSET;
return parent_rate / (nfc_pdf + 1);
}
static unsigned long _clk_parent_round_rate(struct clk *clk, unsigned long rate)
{
return clk->parent->round_rate(clk->parent, rate);
}
static int _clk_parent_set_rate(struct clk *clk, unsigned long rate)
{
return clk->parent->set_rate(clk->parent, rate);
}
static unsigned long get_high_reference_clock_rate(struct clk *clk)
{
return external_high_reference;
}
static unsigned long get_low_reference_clock_rate(struct clk *clk)
{
return external_low_reference;
}
static unsigned long _clk_fpm_recalc(struct clk *clk)
{
return clk_get_rate(clk->parent) * 512;
}
static unsigned long get_mpll_clk(struct clk *clk)
{
uint32_t reg;
unsigned long ref_clk;
unsigned long mfi = 0, mfn = 0, mfd = 0, pdf = 0;
unsigned long long temp;
ref_clk = clk_get_rate(clk->parent);
reg = __raw_readl(CCM_MPCTL0);
pdf = (reg & CCM_MPCTL0_PD_MASK) >> CCM_MPCTL0_PD_OFFSET;
mfd = (reg & CCM_MPCTL0_MFD_MASK) >> CCM_MPCTL0_MFD_OFFSET;
mfi = (reg & CCM_MPCTL0_MFI_MASK) >> CCM_MPCTL0_MFI_OFFSET;
mfn = (reg & CCM_MPCTL0_MFN_MASK) >> CCM_MPCTL0_MFN_OFFSET;
mfi = (mfi <= 5) ? 5 : mfi;
temp = 2LL * ref_clk * mfn;
do_div(temp, mfd + 1);
temp = 2LL * ref_clk * mfi + temp;
do_div(temp, pdf + 1);
return (unsigned long)temp;
}
static unsigned long _clk_fclk_get_rate(struct clk *clk)
{
unsigned long parent_rate;
u32 div;
div = (CSCR() & CCM_CSCR_PRESC_MASK) >> CCM_CSCR_PRESC_OFFSET;
parent_rate = clk_get_rate(clk->parent);
return parent_rate / (div+1);
}
static unsigned long get_spll_clk(struct clk *clk)
{
uint32_t reg;
unsigned long ref_clk;
unsigned long mfi = 0, mfn = 0, mfd = 0, pdf = 0;
unsigned long long temp;
ref_clk = clk_get_rate(clk->parent);
reg = __raw_readl(CCM_SPCTL0);
pdf = (reg & CCM_SPCTL0_PD_MASK) >> CCM_SPCTL0_PD_OFFSET;
mfd = (reg & CCM_SPCTL0_MFD_MASK) >> CCM_SPCTL0_MFD_OFFSET;
mfi = (reg & CCM_SPCTL0_MFI_MASK) >> CCM_SPCTL0_MFI_OFFSET;
mfn = (reg & CCM_SPCTL0_MFN_MASK) >> CCM_SPCTL0_MFN_OFFSET;
mfi = (mfi <= 5) ? 5 : mfi;
temp = 2LL * ref_clk * mfn;
do_div(temp, mfd + 1);
temp = 2LL * ref_clk * mfi + temp;
do_div(temp, pdf + 1);
return (unsigned long)temp;
}
static unsigned long get_hclk_clk(struct clk *clk)
{
unsigned long rate;
unsigned long bclk_pdf;
bclk_pdf = (CSCR() & CCM_CSCR_BCLK_MASK)
>> CCM_CSCR_BCLK_OFFSET;
rate = clk_get_rate(clk->parent);
return rate / (bclk_pdf + 1);
}
static unsigned long get_ipg_clk(struct clk *clk)
{
unsigned long rate;
unsigned long ipg_pdf;
ipg_pdf = (CSCR() & CCM_CSCR_IPDIV) >> CCM_CSCR_IPDIV_OFFSET;
rate = clk_get_rate(clk->parent);
return rate / (ipg_pdf + 1);
}
static unsigned long _clk_perclkx_recalc(struct clk *clk)
{
unsigned long perclk_pdf;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
if (clk->id < 0 || clk->id > 3)
return 0;
perclk_pdf = (PCDR1() >> (clk->id << 3)) & CCM_PCDR1_PERDIV1_MASK;
return parent_rate / (perclk_pdf + 1);
}
static unsigned long _clk_clko_round_rate(struct clk *clk, unsigned long rate)
{
return _clk_generic_round_rate(clk, rate, 8);
}
static int _clk_clko_set_rate(struct clk *clk, unsigned long rate)
{
u32 reg;
u32 div;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
div = parent_rate / rate;
if (div > 8 || div < 1 || ((parent_rate / div) != rate))
return -EINVAL;
div--;
reg = __raw_readl(CCM_PCDR0);
if (clk->parent == &usb_clk[0]) {
reg &= ~CCM_PCDR0_48MDIV_MASK;
reg |= div << CCM_PCDR0_48MDIV_OFFSET;
}
__raw_writel(reg, CCM_PCDR0);
return 0;
}
static unsigned long _clk_clko_recalc(struct clk *clk)
{
u32 div = 0;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
if (clk->parent == &usb_clk[0])
div = __raw_readl(CCM_PCDR0) & CCM_PCDR0_48MDIV_MASK
>> CCM_PCDR0_48MDIV_OFFSET;
div++;
return parent_rate / div;
}
static int _clk_clko_set_parent(struct clk *clk, struct clk *parent)
{
u32 reg;
reg = __raw_readl(CCM_CCSR) & ~CCM_CCSR_CLKOSEL_MASK;
if (parent == &ckil_clk)
reg |= 0 << CCM_CCSR_CLKOSEL_OFFSET;
else if (parent == &fpm_clk)
reg |= 1 << CCM_CCSR_CLKOSEL_OFFSET;
else if (parent == &ckih_clk)
reg |= 2 << CCM_CCSR_CLKOSEL_OFFSET;
else if (parent == mpll_clk.parent)
reg |= 3 << CCM_CCSR_CLKOSEL_OFFSET;
else if (parent == spll_clk.parent)
reg |= 4 << CCM_CCSR_CLKOSEL_OFFSET;
else if (parent == &mpll_clk)
reg |= 5 << CCM_CCSR_CLKOSEL_OFFSET;
else if (parent == &spll_clk)
reg |= 6 << CCM_CCSR_CLKOSEL_OFFSET;
else if (parent == &fclk_clk)
reg |= 7 << CCM_CCSR_CLKOSEL_OFFSET;
else if (parent == &hclk_clk)
reg |= 8 << CCM_CCSR_CLKOSEL_OFFSET;
else if (parent == &ipg_clk)
reg |= 9 << CCM_CCSR_CLKOSEL_OFFSET;
else if (parent == &per_clk[0])
reg |= 0xA << CCM_CCSR_CLKOSEL_OFFSET;
else if (parent == &per_clk[1])
reg |= 0xB << CCM_CCSR_CLKOSEL_OFFSET;
else if (parent == &per_clk[2])
reg |= 0xC << CCM_CCSR_CLKOSEL_OFFSET;
else if (parent == &per_clk[3])
reg |= 0xD << CCM_CCSR_CLKOSEL_OFFSET;
else if (parent == &ssi_clk[0])
reg |= 0xE << CCM_CCSR_CLKOSEL_OFFSET;
else if (parent == &ssi_clk[1])
reg |= 0xF << CCM_CCSR_CLKOSEL_OFFSET;
else if (parent == &nfc_clk)
reg |= 0x10 << CCM_CCSR_CLKOSEL_OFFSET;
else if (parent == &usb_clk[0])
reg |= 0x14 << CCM_CCSR_CLKOSEL_OFFSET;
else if (parent == &clko_clk)
reg |= 0x15 << CCM_CCSR_CLKOSEL_OFFSET;
else
return -EINVAL;
__raw_writel(reg, CCM_CCSR);
return 0;
}
int __init mx21_clocks_init(unsigned long lref, unsigned long href)
{
u32 cscr;
external_low_reference = lref;
external_high_reference = href;
cscr = CSCR();
if (cscr & CCM_CSCR_MCU)
mpll_clk.parent = &ckih_clk;
else
mpll_clk.parent = &fpm_clk;
if (cscr & CCM_CSCR_SP)
spll_clk.parent = &ckih_clk;
else
spll_clk.parent = &fpm_clk;
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
__raw_writel(0, CCM_PCCR0);
__raw_writel(CCM_PCCR_GPT1_MASK, CCM_PCCR1);
spll_clk.disable(&spll_clk);
clk_enable(&per_clk[0]);
clk_enable(&gpio_clk);
#if defined(CONFIG_DEBUG_LL) && !defined(CONFIG_DEBUG_ICEDCC)
clk_enable(&uart_clk[0]);
#endif
mxc_timer_init(&gpt_clk[0], MX21_IO_ADDRESS(MX21_GPT1_BASE_ADDR),
MX21_INT_GPT1);
return 0;
}
