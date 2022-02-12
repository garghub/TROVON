static void __calc_pre_post_dividers(u32 div, u32 *pre, u32 *post,
u32 max_pre, u32 max_post)
{
if (div >= max_pre * max_post) {
*pre = max_pre;
*post = max_post;
} else if (div >= max_pre) {
u32 min_pre, temp_pre, old_err, err;
min_pre = DIV_ROUND_UP(div, max_post);
old_err = max_pre;
for (temp_pre = max_pre; temp_pre >= min_pre; temp_pre--) {
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
*post = DIV_ROUND_UP(div, *pre);
} else {
*pre = div;
*post = 1;
}
}
static void _clk_ccgr_setclk(struct clk *clk, unsigned mode)
{
u32 reg = __raw_readl(clk->enable_reg);
reg &= ~(MXC_CCM_CCGRx_CG_MASK << clk->enable_shift);
reg |= mode << clk->enable_shift;
__raw_writel(reg, clk->enable_reg);
}
static int _clk_ccgr_enable(struct clk *clk)
{
_clk_ccgr_setclk(clk, MXC_CCM_CCGRx_MOD_ON);
return 0;
}
static void _clk_ccgr_disable(struct clk *clk)
{
_clk_ccgr_setclk(clk, MXC_CCM_CCGRx_MOD_OFF);
}
static int _clk_ccgr_enable_inrun(struct clk *clk)
{
_clk_ccgr_setclk(clk, MXC_CCM_CCGRx_MOD_IDLE);
return 0;
}
static void _clk_ccgr_disable_inwait(struct clk *clk)
{
_clk_ccgr_setclk(clk, MXC_CCM_CCGRx_MOD_IDLE);
}
static inline u32 _get_mux(struct clk *parent, struct clk *m0,
struct clk *m1, struct clk *m2, struct clk *m3)
{
if (parent == m0)
return 0;
else if (parent == m1)
return 1;
else if (parent == m2)
return 2;
else if (parent == m3)
return 3;
else
BUG();
return -EINVAL;
}
static inline void __iomem *_mx51_get_pll_base(struct clk *pll)
{
if (pll == &pll1_main_clk)
return MX51_DPLL1_BASE;
else if (pll == &pll2_sw_clk)
return MX51_DPLL2_BASE;
else if (pll == &pll3_sw_clk)
return MX51_DPLL3_BASE;
else
BUG();
return NULL;
}
static inline void __iomem *_mx53_get_pll_base(struct clk *pll)
{
if (pll == &pll1_main_clk)
return MX53_DPLL1_BASE;
else if (pll == &pll2_sw_clk)
return MX53_DPLL2_BASE;
else if (pll == &pll3_sw_clk)
return MX53_DPLL3_BASE;
else if (pll == &mx53_pll4_sw_clk)
return MX53_DPLL4_BASE;
else
BUG();
return NULL;
}
static inline void __iomem *_get_pll_base(struct clk *pll)
{
if (cpu_is_mx51())
return _mx51_get_pll_base(pll);
else
return _mx53_get_pll_base(pll);
}
static unsigned long clk_pll_get_rate(struct clk *clk)
{
long mfi, mfn, mfd, pdf, ref_clk, mfn_abs;
unsigned long dp_op, dp_mfd, dp_mfn, dp_ctl, pll_hfsm, dbl;
void __iomem *pllbase;
s64 temp;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
pllbase = _get_pll_base(clk);
dp_ctl = __raw_readl(pllbase + MXC_PLL_DP_CTL);
pll_hfsm = dp_ctl & MXC_PLL_DP_CTL_HFSM;
dbl = dp_ctl & MXC_PLL_DP_CTL_DPDCK0_2_EN;
if (pll_hfsm == 0) {
dp_op = __raw_readl(pllbase + MXC_PLL_DP_OP);
dp_mfd = __raw_readl(pllbase + MXC_PLL_DP_MFD);
dp_mfn = __raw_readl(pllbase + MXC_PLL_DP_MFN);
} else {
dp_op = __raw_readl(pllbase + MXC_PLL_DP_HFS_OP);
dp_mfd = __raw_readl(pllbase + MXC_PLL_DP_HFS_MFD);
dp_mfn = __raw_readl(pllbase + MXC_PLL_DP_HFS_MFN);
}
pdf = dp_op & MXC_PLL_DP_OP_PDF_MASK;
mfi = (dp_op & MXC_PLL_DP_OP_MFI_MASK) >> MXC_PLL_DP_OP_MFI_OFFSET;
mfi = (mfi <= 5) ? 5 : mfi;
mfd = dp_mfd & MXC_PLL_DP_MFD_MASK;
mfn = mfn_abs = dp_mfn & MXC_PLL_DP_MFN_MASK;
if (mfn >= 0x04000000) {
mfn |= 0xFC000000;
mfn_abs = -mfn;
}
ref_clk = 2 * parent_rate;
if (dbl != 0)
ref_clk *= 2;
ref_clk /= (pdf + 1);
temp = (u64) ref_clk * mfn_abs;
do_div(temp, mfd + 1);
if (mfn < 0)
temp = -temp;
temp = (ref_clk * mfi) + temp;
return temp;
}
static int _clk_pll_set_rate(struct clk *clk, unsigned long rate)
{
u32 reg;
void __iomem *pllbase;
long mfi, pdf, mfn, mfd = 999999;
s64 temp64;
unsigned long quad_parent_rate;
unsigned long pll_hfsm, dp_ctl;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
pllbase = _get_pll_base(clk);
quad_parent_rate = 4 * parent_rate;
pdf = mfi = -1;
while (++pdf < 16 && mfi < 5)
mfi = rate * (pdf+1) / quad_parent_rate;
if (mfi > 15)
return -EINVAL;
pdf--;
temp64 = rate * (pdf+1) - quad_parent_rate * mfi;
do_div(temp64, quad_parent_rate/1000000);
mfn = (long)temp64;
dp_ctl = __raw_readl(pllbase + MXC_PLL_DP_CTL);
__raw_writel(dp_ctl | 0x1000L, pllbase + MXC_PLL_DP_CTL);
pll_hfsm = dp_ctl & MXC_PLL_DP_CTL_HFSM;
if (pll_hfsm == 0) {
reg = mfi << 4 | pdf;
__raw_writel(reg, pllbase + MXC_PLL_DP_OP);
__raw_writel(mfd, pllbase + MXC_PLL_DP_MFD);
__raw_writel(mfn, pllbase + MXC_PLL_DP_MFN);
} else {
reg = mfi << 4 | pdf;
__raw_writel(reg, pllbase + MXC_PLL_DP_HFS_OP);
__raw_writel(mfd, pllbase + MXC_PLL_DP_HFS_MFD);
__raw_writel(mfn, pllbase + MXC_PLL_DP_HFS_MFN);
}
return 0;
}
static int _clk_pll_enable(struct clk *clk)
{
u32 reg;
void __iomem *pllbase;
int i = 0;
pllbase = _get_pll_base(clk);
reg = __raw_readl(pllbase + MXC_PLL_DP_CTL);
if (reg & MXC_PLL_DP_CTL_UPEN)
return 0;
reg |= MXC_PLL_DP_CTL_UPEN;
__raw_writel(reg, pllbase + MXC_PLL_DP_CTL);
do {
reg = __raw_readl(pllbase + MXC_PLL_DP_CTL);
if (reg & MXC_PLL_DP_CTL_LRF)
break;
udelay(1);
} while (++i < MAX_DPLL_WAIT_TRIES);
if (i == MAX_DPLL_WAIT_TRIES) {
pr_err("MX5: pll locking failed\n");
return -EINVAL;
}
return 0;
}
static void _clk_pll_disable(struct clk *clk)
{
u32 reg;
void __iomem *pllbase;
pllbase = _get_pll_base(clk);
reg = __raw_readl(pllbase + MXC_PLL_DP_CTL) & ~MXC_PLL_DP_CTL_UPEN;
__raw_writel(reg, pllbase + MXC_PLL_DP_CTL);
}
static int _clk_pll1_sw_set_parent(struct clk *clk, struct clk *parent)
{
u32 reg, step;
reg = __raw_readl(MXC_CCM_CCSR);
if (parent == &pll1_main_clk) {
reg &= ~MXC_CCM_CCSR_PLL1_SW_CLK_SEL;
__raw_writel(reg, MXC_CCM_CCSR);
reg = __raw_readl(MXC_CCM_CCSR);
reg &= ~MXC_CCM_CCSR_STEP_SEL_MASK;
reg |= (MXC_CCM_CCSR_STEP_SEL_LP_APM <<
MXC_CCM_CCSR_STEP_SEL_OFFSET);
} else {
if (parent == &lp_apm_clk) {
step = MXC_CCM_CCSR_STEP_SEL_LP_APM;
} else if (parent == &pll2_sw_clk) {
step = MXC_CCM_CCSR_STEP_SEL_PLL2_DIVIDED;
} else if (parent == &pll3_sw_clk) {
step = MXC_CCM_CCSR_STEP_SEL_PLL3_DIVIDED;
} else
return -EINVAL;
reg &= ~MXC_CCM_CCSR_STEP_SEL_MASK;
reg |= (step << MXC_CCM_CCSR_STEP_SEL_OFFSET);
__raw_writel(reg, MXC_CCM_CCSR);
reg = __raw_readl(MXC_CCM_CCSR);
reg |= MXC_CCM_CCSR_PLL1_SW_CLK_SEL;
}
__raw_writel(reg, MXC_CCM_CCSR);
return 0;
}
static unsigned long clk_pll1_sw_get_rate(struct clk *clk)
{
u32 reg, div;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
reg = __raw_readl(MXC_CCM_CCSR);
if (clk->parent == &pll2_sw_clk) {
div = ((reg & MXC_CCM_CCSR_PLL2_PODF_MASK) >>
MXC_CCM_CCSR_PLL2_PODF_OFFSET) + 1;
} else if (clk->parent == &pll3_sw_clk) {
div = ((reg & MXC_CCM_CCSR_PLL3_PODF_MASK) >>
MXC_CCM_CCSR_PLL3_PODF_OFFSET) + 1;
} else
div = 1;
return parent_rate / div;
}
static int _clk_pll2_sw_set_parent(struct clk *clk, struct clk *parent)
{
u32 reg;
reg = __raw_readl(MXC_CCM_CCSR);
if (parent == &pll2_sw_clk)
reg &= ~MXC_CCM_CCSR_PLL2_SW_CLK_SEL;
else
reg |= MXC_CCM_CCSR_PLL2_SW_CLK_SEL;
__raw_writel(reg, MXC_CCM_CCSR);
return 0;
}
static int _clk_lp_apm_set_parent(struct clk *clk, struct clk *parent)
{
u32 reg;
if (parent == &osc_clk)
reg = __raw_readl(MXC_CCM_CCSR) & ~MXC_CCM_CCSR_LP_APM_SEL;
else
return -EINVAL;
__raw_writel(reg, MXC_CCM_CCSR);
return 0;
}
static unsigned long clk_cpu_get_rate(struct clk *clk)
{
u32 cacrr, div;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
cacrr = __raw_readl(MXC_CCM_CACRR);
div = (cacrr & MXC_CCM_CACRR_ARM_PODF_MASK) + 1;
return parent_rate / div;
}
static int clk_cpu_set_rate(struct clk *clk, unsigned long rate)
{
u32 reg, cpu_podf;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
cpu_podf = parent_rate / rate - 1;
reg = __raw_readl(MXC_CCM_CACRR);
reg &= ~MXC_CCM_CACRR_ARM_PODF_MASK;
reg |= cpu_podf << MXC_CCM_CACRR_ARM_PODF_OFFSET;
__raw_writel(reg, MXC_CCM_CACRR);
return 0;
}
static int _clk_periph_apm_set_parent(struct clk *clk, struct clk *parent)
{
u32 reg, mux;
int i = 0;
mux = _get_mux(parent, &pll1_sw_clk, &pll3_sw_clk, &lp_apm_clk, NULL);
reg = __raw_readl(MXC_CCM_CBCMR) & ~MXC_CCM_CBCMR_PERIPH_CLK_SEL_MASK;
reg |= mux << MXC_CCM_CBCMR_PERIPH_CLK_SEL_OFFSET;
__raw_writel(reg, MXC_CCM_CBCMR);
do {
reg = __raw_readl(MXC_CCM_CDHIPR);
if (!(reg & MXC_CCM_CDHIPR_PERIPH_CLK_SEL_BUSY))
break;
udelay(1);
} while (++i < MAX_DPLL_WAIT_TRIES);
if (i == MAX_DPLL_WAIT_TRIES) {
pr_err("MX5: Set parent for periph_apm clock failed\n");
return -EINVAL;
}
return 0;
}
static int _clk_main_bus_set_parent(struct clk *clk, struct clk *parent)
{
u32 reg;
reg = __raw_readl(MXC_CCM_CBCDR);
if (parent == &pll2_sw_clk)
reg &= ~MXC_CCM_CBCDR_PERIPH_CLK_SEL;
else if (parent == &periph_apm_clk)
reg |= MXC_CCM_CBCDR_PERIPH_CLK_SEL;
else
return -EINVAL;
__raw_writel(reg, MXC_CCM_CBCDR);
return 0;
}
static unsigned long clk_ahb_get_rate(struct clk *clk)
{
u32 reg, div;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
reg = __raw_readl(MXC_CCM_CBCDR);
div = ((reg & MXC_CCM_CBCDR_AHB_PODF_MASK) >>
MXC_CCM_CBCDR_AHB_PODF_OFFSET) + 1;
return parent_rate / div;
}
static int _clk_ahb_set_rate(struct clk *clk, unsigned long rate)
{
u32 reg, div;
unsigned long parent_rate;
int i = 0;
parent_rate = clk_get_rate(clk->parent);
div = parent_rate / rate;
if (div > 8 || div < 1 || ((parent_rate / div) != rate))
return -EINVAL;
reg = __raw_readl(MXC_CCM_CBCDR);
reg &= ~MXC_CCM_CBCDR_AHB_PODF_MASK;
reg |= (div - 1) << MXC_CCM_CBCDR_AHB_PODF_OFFSET;
__raw_writel(reg, MXC_CCM_CBCDR);
do {
reg = __raw_readl(MXC_CCM_CDHIPR);
if (!(reg & MXC_CCM_CDHIPR_AHB_PODF_BUSY))
break;
udelay(1);
} while (++i < MAX_DPLL_WAIT_TRIES);
if (i == MAX_DPLL_WAIT_TRIES) {
pr_err("MX5: clk_ahb_set_rate failed\n");
return -EINVAL;
}
return 0;
}
static unsigned long _clk_ahb_round_rate(struct clk *clk,
unsigned long rate)
{
u32 div;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
div = parent_rate / rate;
if (div > 8)
div = 8;
else if (div == 0)
div++;
return parent_rate / div;
}
static int _clk_max_enable(struct clk *clk)
{
u32 reg;
_clk_ccgr_enable(clk);
reg = __raw_readl(MXC_CCM_CLPCR);
if (cpu_is_mx51())
reg &= ~MX51_CCM_CLPCR_BYPASS_MAX_LPM_HS;
else if (cpu_is_mx53())
reg &= ~MX53_CCM_CLPCR_BYPASS_MAX_LPM_HS;
__raw_writel(reg, MXC_CCM_CLPCR);
return 0;
}
static void _clk_max_disable(struct clk *clk)
{
u32 reg;
_clk_ccgr_disable_inwait(clk);
reg = __raw_readl(MXC_CCM_CLPCR);
if (cpu_is_mx51())
reg |= MX51_CCM_CLPCR_BYPASS_MAX_LPM_HS;
else if (cpu_is_mx53())
reg &= ~MX53_CCM_CLPCR_BYPASS_MAX_LPM_HS;
__raw_writel(reg, MXC_CCM_CLPCR);
}
static unsigned long clk_ipg_get_rate(struct clk *clk)
{
u32 reg, div;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
reg = __raw_readl(MXC_CCM_CBCDR);
div = ((reg & MXC_CCM_CBCDR_IPG_PODF_MASK) >>
MXC_CCM_CBCDR_IPG_PODF_OFFSET) + 1;
return parent_rate / div;
}
static unsigned long clk_ipg_per_get_rate(struct clk *clk)
{
u32 reg, prediv1, prediv2, podf;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
if (clk->parent == &main_bus_clk || clk->parent == &lp_apm_clk) {
reg = __raw_readl(MXC_CCM_CBCDR);
prediv1 = ((reg & MXC_CCM_CBCDR_PERCLK_PRED1_MASK) >>
MXC_CCM_CBCDR_PERCLK_PRED1_OFFSET) + 1;
prediv2 = ((reg & MXC_CCM_CBCDR_PERCLK_PRED2_MASK) >>
MXC_CCM_CBCDR_PERCLK_PRED2_OFFSET) + 1;
podf = ((reg & MXC_CCM_CBCDR_PERCLK_PODF_MASK) >>
MXC_CCM_CBCDR_PERCLK_PODF_OFFSET) + 1;
return parent_rate / (prediv1 * prediv2 * podf);
} else if (clk->parent == &ipg_clk)
return parent_rate;
else
BUG();
}
static int _clk_ipg_per_set_parent(struct clk *clk, struct clk *parent)
{
u32 reg;
reg = __raw_readl(MXC_CCM_CBCMR);
reg &= ~MXC_CCM_CBCMR_PERCLK_LP_APM_CLK_SEL;
reg &= ~MXC_CCM_CBCMR_PERCLK_IPG_CLK_SEL;
if (parent == &ipg_clk)
reg |= MXC_CCM_CBCMR_PERCLK_IPG_CLK_SEL;
else if (parent == &lp_apm_clk)
reg |= MXC_CCM_CBCMR_PERCLK_LP_APM_CLK_SEL;
else if (parent != &main_bus_clk)
return -EINVAL;
__raw_writel(reg, MXC_CCM_CBCMR);
return 0;
}
static unsigned long clk_nfc_get_rate(struct clk *clk)
{
unsigned long rate;
u32 reg, div;
reg = __raw_readl(MXC_CCM_CBCDR);
div = ((reg & MXC_CCM_CBCDR_NFC_PODF_MASK) >>
MXC_CCM_CBCDR_NFC_PODF_OFFSET) + 1;
rate = clk_get_rate(clk->parent) / div;
WARN_ON(rate == 0);
return rate;
}
static unsigned long clk_nfc_round_rate(struct clk *clk,
unsigned long rate)
{
u32 div;
unsigned long parent_rate = clk_get_rate(clk->parent);
if (!rate)
return -EINVAL;
div = parent_rate / rate;
if (parent_rate % rate)
div++;
if (div > 8)
return -EINVAL;
return parent_rate / div;
}
static int clk_nfc_set_rate(struct clk *clk, unsigned long rate)
{
u32 reg, div;
div = clk_get_rate(clk->parent) / rate;
if (div == 0)
div++;
if (((clk_get_rate(clk->parent) / div) != rate) || (div > 8))
return -EINVAL;
reg = __raw_readl(MXC_CCM_CBCDR);
reg &= ~MXC_CCM_CBCDR_NFC_PODF_MASK;
reg |= (div - 1) << MXC_CCM_CBCDR_NFC_PODF_OFFSET;
__raw_writel(reg, MXC_CCM_CBCDR);
while (__raw_readl(MXC_CCM_CDHIPR) &
MXC_CCM_CDHIPR_NFC_IPG_INT_MEM_PODF_BUSY){
}
return 0;
}
static unsigned long get_high_reference_clock_rate(struct clk *clk)
{
return external_high_reference;
}
static unsigned long get_low_reference_clock_rate(struct clk *clk)
{
return external_low_reference;
}
static unsigned long get_oscillator_reference_clock_rate(struct clk *clk)
{
return oscillator_reference;
}
static unsigned long get_ckih2_reference_clock_rate(struct clk *clk)
{
return ckih2_reference;
}
static unsigned long clk_emi_slow_get_rate(struct clk *clk)
{
u32 reg, div;
reg = __raw_readl(MXC_CCM_CBCDR);
div = ((reg & MXC_CCM_CBCDR_EMI_PODF_MASK) >>
MXC_CCM_CBCDR_EMI_PODF_OFFSET) + 1;
return clk_get_rate(clk->parent) / div;
}
static unsigned long _clk_ddr_hf_get_rate(struct clk *clk)
{
unsigned long rate;
u32 reg, div;
reg = __raw_readl(MXC_CCM_CBCDR);
div = ((reg & MXC_CCM_CBCDR_DDR_PODF_MASK) >>
MXC_CCM_CBCDR_DDR_PODF_OFFSET) + 1;
rate = clk_get_rate(clk->parent) / div;
return rate;
}
static int clk_ipu_enable(struct clk *clk)
{
u32 reg;
_clk_ccgr_enable(clk);
reg = __raw_readl(MXC_CCM_CCDR);
reg &= ~MXC_CCM_CCDR_IPU_HS_MASK;
__raw_writel(reg, MXC_CCM_CCDR);
reg = __raw_readl(MXC_CCM_CLPCR);
reg &= ~MXC_CCM_CLPCR_BYPASS_IPU_LPM_HS;
__raw_writel(reg, MXC_CCM_CLPCR);
return 0;
}
static void clk_ipu_disable(struct clk *clk)
{
u32 reg;
_clk_ccgr_disable(clk);
reg = __raw_readl(MXC_CCM_CCDR);
reg |= MXC_CCM_CCDR_IPU_HS_MASK;
__raw_writel(reg, MXC_CCM_CCDR);
reg = __raw_readl(MXC_CCM_CLPCR);
reg |= MXC_CCM_CLPCR_BYPASS_IPU_LPM_HS;
__raw_writel(reg, MXC_CCM_CLPCR);
}
static int _clk_hsc_enable(struct clk *clk)
{
u32 reg;
_clk_ccgr_enable(clk);
reg = __raw_readl(MXC_CCM_CCDR);
reg &= ~MXC_CCM_CCDR_HSC_HS_MASK;
__raw_writel(reg, MXC_CCM_CCDR);
reg = __raw_readl(MXC_CCM_CLPCR);
reg &= ~MXC_CCM_CLPCR_BYPASS_HSC_LPM_HS;
__raw_writel(reg, MXC_CCM_CLPCR);
return 0;
}
static void _clk_hsc_disable(struct clk *clk)
{
u32 reg;
_clk_ccgr_disable(clk);
reg = __raw_readl(MXC_CCM_CCDR);
reg |= MXC_CCM_CCDR_HSC_HS_MASK;
__raw_writel(reg, MXC_CCM_CCDR);
reg = __raw_readl(MXC_CCM_CLPCR);
reg |= MXC_CCM_CLPCR_BYPASS_HSC_LPM_HS;
__raw_writel(reg, MXC_CCM_CLPCR);
}
static int clk_usb_phy1_set_parent(struct clk *clk, struct clk *parent)
{
u32 reg;
reg = __raw_readl(MXC_CCM_CSCMR1) & ~MXC_CCM_CSCMR1_USB_PHY_CLK_SEL;
if (parent == &pll3_sw_clk)
reg |= 1 << MXC_CCM_CSCMR1_USB_PHY_CLK_SEL_OFFSET;
__raw_writel(reg, MXC_CCM_CSCMR1);
return 0;
}
static int clk_esdhc3_set_parent(struct clk *clk, struct clk *parent)
{
u32 reg;
reg = __raw_readl(MXC_CCM_CSCMR1);
if (parent == &esdhc1_clk)
reg &= ~MXC_CCM_CSCMR1_ESDHC3_CLK_SEL;
else if (parent == &esdhc2_clk)
reg |= MXC_CCM_CSCMR1_ESDHC3_CLK_SEL;
else
return -EINVAL;
__raw_writel(reg, MXC_CCM_CSCMR1);
return 0;
}
static int clk_esdhc4_set_parent(struct clk *clk, struct clk *parent)
{
u32 reg;
reg = __raw_readl(MXC_CCM_CSCMR1);
if (parent == &esdhc1_clk)
reg &= ~MXC_CCM_CSCMR1_ESDHC4_CLK_SEL;
else if (parent == &esdhc2_clk)
reg |= MXC_CCM_CSCMR1_ESDHC4_CLK_SEL;
else
return -EINVAL;
__raw_writel(reg, MXC_CCM_CSCMR1);
return 0;
}
static int clk_esdhc2_mx53_set_parent(struct clk *clk, struct clk *parent)
{
u32 reg;
reg = __raw_readl(MXC_CCM_CSCMR1);
if (parent == &esdhc1_clk)
reg &= ~MXC_CCM_CSCMR1_ESDHC2_MSHC2_MX53_CLK_SEL;
else if (parent == &esdhc3_mx53_clk)
reg |= MXC_CCM_CSCMR1_ESDHC2_MSHC2_MX53_CLK_SEL;
else
return -EINVAL;
__raw_writel(reg, MXC_CCM_CSCMR1);
return 0;
}
static int clk_esdhc4_mx53_set_parent(struct clk *clk, struct clk *parent)
{
u32 reg;
reg = __raw_readl(MXC_CCM_CSCMR1);
if (parent == &esdhc1_clk)
reg &= ~MXC_CCM_CSCMR1_ESDHC4_CLK_SEL;
else if (parent == &esdhc3_mx53_clk)
reg |= MXC_CCM_CSCMR1_ESDHC4_CLK_SEL;
else
return -EINVAL;
__raw_writel(reg, MXC_CCM_CSCMR1);
return 0;
}
static void clk_tree_init(void)
{
u32 reg;
ipg_perclk.set_parent(&ipg_perclk, &lp_apm_clk);
reg = __raw_readl(MXC_CCM_CBCDR);
reg &= ~MXC_CCM_CBCDR_PERCLK_PRED1_MASK;
reg &= ~MXC_CCM_CBCDR_PERCLK_PRED2_MASK;
reg &= ~MXC_CCM_CBCDR_PERCLK_PODF_MASK;
reg |= (2 << MXC_CCM_CBCDR_PERCLK_PRED1_OFFSET);
__raw_writel(reg, MXC_CCM_CBCDR);
}
int __init mx51_clocks_init(unsigned long ckil, unsigned long osc,
unsigned long ckih1, unsigned long ckih2)
{
int i;
external_low_reference = ckil;
external_high_reference = ckih1;
ckih2_reference = ckih2;
oscillator_reference = osc;
for (i = 0; i < ARRAY_SIZE(mx51_lookups); i++)
clkdev_add(&mx51_lookups[i]);
clk_tree_init();
clk_enable(&cpu_clk);
clk_enable(&main_bus_clk);
clk_enable(&iim_clk);
mx51_revision();
clk_disable(&iim_clk);
mx51_display_revision();
clk_set_parent(&usb_phy1_clk, &osc_clk);
clk_set_parent(&usboh3_clk, &pll2_sw_clk);
clk_set_parent(&esdhc1_clk, &pll2_sw_clk);
clk_set_parent(&esdhc2_clk, &pll2_sw_clk);
clk_set_rate(&esdhc1_clk, 166250000);
clk_set_rate(&esdhc2_clk, 166250000);
mxc_timer_init(&gpt_clk, MX51_IO_ADDRESS(MX51_GPT1_BASE_ADDR),
MX51_MXC_INT_GPT);
return 0;
}
int __init mx53_clocks_init(unsigned long ckil, unsigned long osc,
unsigned long ckih1, unsigned long ckih2)
{
int i;
external_low_reference = ckil;
external_high_reference = ckih1;
ckih2_reference = ckih2;
oscillator_reference = osc;
for (i = 0; i < ARRAY_SIZE(mx53_lookups); i++)
clkdev_add(&mx53_lookups[i]);
clk_tree_init();
clk_set_parent(&uart_root_clk, &pll3_sw_clk);
clk_enable(&cpu_clk);
clk_enable(&main_bus_clk);
clk_enable(&iim_clk);
mx53_revision();
clk_disable(&iim_clk);
mx53_display_revision();
clk_set_parent(&esdhc1_clk, &pll2_sw_clk);
clk_set_parent(&esdhc3_mx53_clk, &pll2_sw_clk);
clk_set_rate(&esdhc1_clk, 200000000);
clk_set_rate(&esdhc3_mx53_clk, 200000000);
mxc_timer_init(&gpt_clk, MX53_IO_ADDRESS(MX53_GPT1_BASE_ADDR),
MX53_INT_GPT);
return 0;
}
