static void __calc_pre_post_dividers(u32 div, u32 *pre, u32 *post)
{
u32 min_pre, temp_pre, old_err, err;
if (div >= 512) {
*pre = 8;
*post = 64;
} else if (div >= 64) {
min_pre = (div - 1) / 64 + 1;
old_err = 8;
for (temp_pre = 8; temp_pre >= min_pre; temp_pre--) {
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
} else if (div <= 8) {
*pre = div;
*post = 1;
} else {
*pre = 1;
*post = div;
}
}
static int cgr_enable(struct clk *clk)
{
u32 reg;
if (!clk->enable_reg)
return 0;
reg = __raw_readl(clk->enable_reg);
reg |= 3 << clk->enable_shift;
__raw_writel(reg, clk->enable_reg);
return 0;
}
static void cgr_disable(struct clk *clk)
{
u32 reg;
if (!clk->enable_reg)
return;
reg = __raw_readl(clk->enable_reg);
reg &= ~(3 << clk->enable_shift);
if (clk->enable_reg == MXC_CCM_CGR2 && clk->enable_shift == 8)
reg |= (1 << clk->enable_shift);
__raw_writel(reg, clk->enable_reg);
}
static unsigned long pll_ref_get_rate(void)
{
unsigned long ccmr;
unsigned int prcs;
ccmr = __raw_readl(MXC_CCM_CCMR);
prcs = (ccmr & MXC_CCM_CCMR_PRCS_MASK) >> MXC_CCM_CCMR_PRCS_OFFSET;
if (prcs == 0x1)
return CKIL_CLK_FREQ * 1024;
else
return clk_get_rate(&ckih_clk);
}
static unsigned long usb_pll_get_rate(struct clk *clk)
{
unsigned long reg;
reg = __raw_readl(MXC_CCM_UPCTL);
return mxc_decode_pll(reg, pll_ref_get_rate());
}
static unsigned long serial_pll_get_rate(struct clk *clk)
{
unsigned long reg;
reg = __raw_readl(MXC_CCM_SRPCTL);
return mxc_decode_pll(reg, pll_ref_get_rate());
}
static unsigned long mcu_pll_get_rate(struct clk *clk)
{
unsigned long reg, ccmr;
ccmr = __raw_readl(MXC_CCM_CCMR);
if (!(ccmr & MXC_CCM_CCMR_MPE) || (ccmr & MXC_CCM_CCMR_MDS))
return clk_get_rate(&ckih_clk);
reg = __raw_readl(MXC_CCM_MPCTL);
return mxc_decode_pll(reg, pll_ref_get_rate());
}
static int usb_pll_enable(struct clk *clk)
{
u32 reg;
reg = __raw_readl(MXC_CCM_CCMR);
reg |= MXC_CCM_CCMR_UPE;
__raw_writel(reg, MXC_CCM_CCMR);
udelay(80);
return 0;
}
static void usb_pll_disable(struct clk *clk)
{
u32 reg;
reg = __raw_readl(MXC_CCM_CCMR);
reg &= ~MXC_CCM_CCMR_UPE;
__raw_writel(reg, MXC_CCM_CCMR);
}
static int serial_pll_enable(struct clk *clk)
{
u32 reg;
reg = __raw_readl(MXC_CCM_CCMR);
reg |= MXC_CCM_CCMR_SPE;
__raw_writel(reg, MXC_CCM_CCMR);
udelay(80);
return 0;
}
static void serial_pll_disable(struct clk *clk)
{
u32 reg;
reg = __raw_readl(MXC_CCM_CCMR);
reg &= ~MXC_CCM_CCMR_SPE;
__raw_writel(reg, MXC_CCM_CCMR);
}
static unsigned long mcu_main_get_rate(struct clk *clk)
{
u32 pmcr0 = __raw_readl(MXC_CCM_PMCR0);
if ((pmcr0 & MXC_CCM_PMCR0_DFSUP1) == MXC_CCM_PMCR0_DFSUP1_SPLL)
return clk_get_rate(&serial_pll_clk);
else
return clk_get_rate(&mcu_pll_clk);
}
static unsigned long ahb_get_rate(struct clk *clk)
{
unsigned long max_pdf;
max_pdf = PDR0(MXC_CCM_PDR0_MAX_PODF_MASK,
MXC_CCM_PDR0_MAX_PODF_OFFSET);
return clk_get_rate(clk->parent) / (max_pdf + 1);
}
static unsigned long ipg_get_rate(struct clk *clk)
{
unsigned long ipg_pdf;
ipg_pdf = PDR0(MXC_CCM_PDR0_IPG_PODF_MASK,
MXC_CCM_PDR0_IPG_PODF_OFFSET);
return clk_get_rate(clk->parent) / (ipg_pdf + 1);
}
static unsigned long nfc_get_rate(struct clk *clk)
{
unsigned long nfc_pdf;
nfc_pdf = PDR0(MXC_CCM_PDR0_NFC_PODF_MASK,
MXC_CCM_PDR0_NFC_PODF_OFFSET);
return clk_get_rate(clk->parent) / (nfc_pdf + 1);
}
static unsigned long hsp_get_rate(struct clk *clk)
{
unsigned long hsp_pdf;
hsp_pdf = PDR0(MXC_CCM_PDR0_HSP_PODF_MASK,
MXC_CCM_PDR0_HSP_PODF_OFFSET);
return clk_get_rate(clk->parent) / (hsp_pdf + 1);
}
static unsigned long usb_get_rate(struct clk *clk)
{
unsigned long usb_pdf, usb_prepdf;
usb_pdf = PDR1(MXC_CCM_PDR1_USB_PODF_MASK,
MXC_CCM_PDR1_USB_PODF_OFFSET);
usb_prepdf = PDR1(MXC_CCM_PDR1_USB_PRDF_MASK,
MXC_CCM_PDR1_USB_PRDF_OFFSET);
return clk_get_rate(clk->parent) / (usb_prepdf + 1) / (usb_pdf + 1);
}
static unsigned long csi_get_rate(struct clk *clk)
{
u32 reg, pre, post;
reg = __raw_readl(MXC_CCM_PDR0);
pre = (reg & MXC_CCM_PDR0_CSI_PRDF_MASK) >>
MXC_CCM_PDR0_CSI_PRDF_OFFSET;
pre++;
post = (reg & MXC_CCM_PDR0_CSI_PODF_MASK) >>
MXC_CCM_PDR0_CSI_PODF_OFFSET;
post++;
return clk_get_rate(clk->parent) / (pre * post);
}
static unsigned long csi_round_rate(struct clk *clk, unsigned long rate)
{
u32 pre, post, parent = clk_get_rate(clk->parent);
u32 div = parent / rate;
if (parent % rate)
div++;
__calc_pre_post_dividers(div, &pre, &post);
return parent / (pre * post);
}
static int csi_set_rate(struct clk *clk, unsigned long rate)
{
u32 reg, div, pre, post, parent = clk_get_rate(clk->parent);
div = parent / rate;
if ((parent / div) != rate)
return -EINVAL;
__calc_pre_post_dividers(div, &pre, &post);
reg = __raw_readl(MXC_CCM_PDR0) &
~(MXC_CCM_PDR0_CSI_PODF_MASK | MXC_CCM_PDR0_CSI_PRDF_MASK);
reg |= (post - 1) << MXC_CCM_PDR0_CSI_PODF_OFFSET;
reg |= (pre - 1) << MXC_CCM_PDR0_CSI_PRDF_OFFSET;
__raw_writel(reg, MXC_CCM_PDR0);
return 0;
}
static unsigned long ssi1_get_rate(struct clk *clk)
{
unsigned long ssi1_pdf, ssi1_prepdf;
ssi1_pdf = PDR1(MXC_CCM_PDR1_SSI1_PODF_MASK,
MXC_CCM_PDR1_SSI1_PODF_OFFSET);
ssi1_prepdf = PDR1(MXC_CCM_PDR1_SSI1_PRE_PODF_MASK,
MXC_CCM_PDR1_SSI1_PRE_PODF_OFFSET);
return clk_get_rate(clk->parent) / (ssi1_prepdf + 1) / (ssi1_pdf + 1);
}
static unsigned long ssi2_get_rate(struct clk *clk)
{
unsigned long ssi2_pdf, ssi2_prepdf;
ssi2_pdf = PDR1(MXC_CCM_PDR1_SSI2_PODF_MASK,
MXC_CCM_PDR1_SSI2_PODF_OFFSET);
ssi2_prepdf = PDR1(MXC_CCM_PDR1_SSI2_PRE_PODF_MASK,
MXC_CCM_PDR1_SSI2_PRE_PODF_OFFSET);
return clk_get_rate(clk->parent) / (ssi2_prepdf + 1) / (ssi2_pdf + 1);
}
static unsigned long firi_get_rate(struct clk *clk)
{
unsigned long firi_pdf, firi_prepdf;
firi_pdf = PDR1(MXC_CCM_PDR1_FIRI_PODF_MASK,
MXC_CCM_PDR1_FIRI_PODF_OFFSET);
firi_prepdf = PDR1(MXC_CCM_PDR1_FIRI_PRE_PODF_MASK,
MXC_CCM_PDR1_FIRI_PRE_PODF_OFFSET);
return clk_get_rate(clk->parent) / (firi_prepdf + 1) / (firi_pdf + 1);
}
static unsigned long firi_round_rate(struct clk *clk, unsigned long rate)
{
u32 pre, post;
u32 parent = clk_get_rate(clk->parent);
u32 div = parent / rate;
if (parent % rate)
div++;
__calc_pre_post_dividers(div, &pre, &post);
return parent / (pre * post);
}
static int firi_set_rate(struct clk *clk, unsigned long rate)
{
u32 reg, div, pre, post, parent = clk_get_rate(clk->parent);
div = parent / rate;
if ((parent / div) != rate)
return -EINVAL;
__calc_pre_post_dividers(div, &pre, &post);
reg = __raw_readl(MXC_CCM_PDR1) &
~(MXC_CCM_PDR1_FIRI_PODF_MASK | MXC_CCM_PDR1_FIRI_PRE_PODF_MASK);
reg |= (pre - 1) << MXC_CCM_PDR1_FIRI_PRE_PODF_OFFSET;
reg |= (post - 1) << MXC_CCM_PDR1_FIRI_PODF_OFFSET;
__raw_writel(reg, MXC_CCM_PDR1);
return 0;
}
static unsigned long mbx_get_rate(struct clk *clk)
{
return clk_get_rate(clk->parent) / 2;
}
static unsigned long mstick1_get_rate(struct clk *clk)
{
unsigned long msti_pdf;
msti_pdf = PDR2(MXC_CCM_PDR2_MST1_PDF_MASK,
MXC_CCM_PDR2_MST1_PDF_OFFSET);
return clk_get_rate(clk->parent) / (msti_pdf + 1);
}
static unsigned long mstick2_get_rate(struct clk *clk)
{
unsigned long msti_pdf;
msti_pdf = PDR2(MXC_CCM_PDR2_MST2_PDF_MASK,
MXC_CCM_PDR2_MST2_PDF_OFFSET);
return clk_get_rate(clk->parent) / (msti_pdf + 1);
}
static unsigned long clk_ckih_get_rate(struct clk *clk)
{
return ckih_rate;
}
static unsigned long clk_ckil_get_rate(struct clk *clk)
{
return CKIL_CLK_FREQ;
}
int __init mx31_clocks_init(unsigned long fref)
{
u32 reg;
ckih_rate = fref;
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
reg = __raw_readl(MXC_CCM_CCMR);
if (!(reg & MXC_CCM_CCMR_CSCS))
if (clk_set_parent(&csi_clk, &usb_pll_clk))
pr_err("%s: error changing csi_clk parent\n", __func__);
__raw_writel((3 << 4), MXC_CCM_CGR0);
__raw_writel(0, MXC_CCM_CGR1);
__raw_writel((3 << 8) | (3 << 14) | (3 << 16)|
1 << 27 | 1 << 28,
MXC_CCM_CGR2);
__raw_writel(__raw_readl(MXC_CCM_CCMR) | (1 << 24), MXC_CCM_CCMR);
usb_pll_disable(&usb_pll_clk);
pr_info("Clock input source is %ld\n", clk_get_rate(&ckih_clk));
clk_enable(&gpt_clk);
clk_enable(&emi_clk);
clk_enable(&iim_clk);
clk_enable(&serial_pll_clk);
mx31_read_cpu_rev();
if (mx31_revision() >= IMX_CHIP_REVISION_2_0) {
reg = __raw_readl(MXC_CCM_PMCR1);
reg |= MXC_CCM_PMCR1_PLLRDIS | MXC_CCM_PMCR1_EMIRQ_EN;
__raw_writel(reg, MXC_CCM_PMCR1);
}
mxc_timer_init(&ipg_clk, MX31_IO_ADDRESS(MX31_GPT1_BASE_ADDR),
MX31_INT_GPT);
return 0;
}
