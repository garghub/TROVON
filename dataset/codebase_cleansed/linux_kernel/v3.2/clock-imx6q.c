static unsigned long get_oscillator_reference_clock_rate(struct clk *clk)
{
return oscillator_reference;
}
static unsigned long get_high_reference_clock_rate(struct clk *clk)
{
return external_high_reference;
}
static unsigned long get_low_reference_clock_rate(struct clk *clk)
{
return external_low_reference;
}
static inline void __iomem *pll_get_reg_addr(struct clk *pll)
{
if (pll == &pll1_sys)
return PLL1_SYS;
else if (pll == &pll2_bus)
return PLL2_BUS;
else if (pll == &pll3_usb_otg)
return PLL3_USB_OTG;
else if (pll == &pll4_audio)
return PLL4_AUDIO;
else if (pll == &pll5_video)
return PLL5_VIDEO;
else if (pll == &pll6_mlb)
return PLL6_MLB;
else if (pll == &pll7_usb_host)
return PLL7_USB_HOST;
else if (pll == &pll8_enet)
return PLL8_ENET;
else
BUG();
return NULL;
}
static int pll_enable(struct clk *clk)
{
int timeout = 0x100000;
void __iomem *reg;
u32 val;
reg = pll_get_reg_addr(clk);
val = readl_relaxed(reg);
val &= ~BM_PLL_BYPASS;
val &= ~BM_PLL_POWER_DOWN;
if (clk == &pll3_usb_otg || clk == &pll7_usb_host)
val |= BM_PLL_POWER_DOWN;
writel_relaxed(val, reg);
while (!(readl_relaxed(reg) & BM_PLL_LOCK) && --timeout)
cpu_relax();
if (unlikely(!timeout))
return -EBUSY;
val = readl_relaxed(reg);
val |= BM_PLL_ENABLE;
writel_relaxed(val, reg);
return 0;
}
static void pll_disable(struct clk *clk)
{
void __iomem *reg;
u32 val;
reg = pll_get_reg_addr(clk);
val = readl_relaxed(reg);
val &= ~BM_PLL_ENABLE;
val |= BM_PLL_BYPASS;
val |= BM_PLL_POWER_DOWN;
if (clk == &pll3_usb_otg || clk == &pll7_usb_host)
val &= ~BM_PLL_POWER_DOWN;
writel_relaxed(val, reg);
}
static unsigned long pll1_sys_get_rate(struct clk *clk)
{
u32 div = (readl_relaxed(PLL1_SYS) & BM_PLL_SYS_DIV_SELECT) >>
BP_PLL_SYS_DIV_SELECT;
return clk_get_rate(clk->parent) * div / 2;
}
static int pll1_sys_set_rate(struct clk *clk, unsigned long rate)
{
u32 val, div;
if (rate < FREQ_650M || rate > FREQ_1300M)
return -EINVAL;
div = rate * 2 / clk_get_rate(clk->parent);
val = readl_relaxed(PLL1_SYS);
val &= ~BM_PLL_SYS_DIV_SELECT;
val |= div << BP_PLL_SYS_DIV_SELECT;
writel_relaxed(val, PLL1_SYS);
return 0;
}
static unsigned long pll8_enet_get_rate(struct clk *clk)
{
u32 div = (readl_relaxed(PLL8_ENET) & BM_PLL_ENET_DIV_SELECT) >>
BP_PLL_ENET_DIV_SELECT;
switch (div) {
case 0:
return 25000000;
case 1:
return 50000000;
case 2:
return 100000000;
case 3:
return 125000000;
}
return 0;
}
static int pll8_enet_set_rate(struct clk *clk, unsigned long rate)
{
u32 val, div;
switch (rate) {
case 25000000:
div = 0;
break;
case 50000000:
div = 1;
break;
case 100000000:
div = 2;
break;
case 125000000:
div = 3;
break;
default:
return -EINVAL;
}
val = readl_relaxed(PLL8_ENET);
val &= ~BM_PLL_ENET_DIV_SELECT;
val |= div << BP_PLL_ENET_DIV_SELECT;
writel_relaxed(val, PLL8_ENET);
return 0;
}
static unsigned long pll_av_get_rate(struct clk *clk)
{
void __iomem *reg = (clk == &pll4_audio) ? PLL4_AUDIO : PLL5_VIDEO;
unsigned long parent_rate = clk_get_rate(clk->parent);
u32 mfn = readl_relaxed(reg + PLL_NUM_OFFSET);
u32 mfd = readl_relaxed(reg + PLL_DENOM_OFFSET);
u32 div = (readl_relaxed(reg) & BM_PLL_AV_DIV_SELECT) >>
BP_PLL_AV_DIV_SELECT;
return (parent_rate * div) + ((parent_rate / mfd) * mfn);
}
static int pll_av_set_rate(struct clk *clk, unsigned long rate)
{
void __iomem *reg = (clk == &pll4_audio) ? PLL4_AUDIO : PLL5_VIDEO;
unsigned int parent_rate = clk_get_rate(clk->parent);
u32 val, div;
u32 mfn, mfd = 1000000;
s64 temp64;
if (rate < FREQ_650M || rate > FREQ_1300M)
return -EINVAL;
div = rate / parent_rate;
temp64 = (u64) (rate - div * parent_rate);
temp64 *= mfd;
do_div(temp64, parent_rate);
mfn = temp64;
val = readl_relaxed(reg);
val &= ~BM_PLL_AV_DIV_SELECT;
val |= div << BP_PLL_AV_DIV_SELECT;
writel_relaxed(val, reg);
writel_relaxed(mfn, reg + PLL_NUM_OFFSET);
writel_relaxed(mfd, reg + PLL_DENOM_OFFSET);
return 0;
}
static void __iomem *pll_get_div_reg_bit(struct clk *clk, u32 *bp, u32 *bm)
{
void __iomem *reg;
if (clk == &pll2_bus) {
reg = PLL2_BUS;
*bp = BP_PLL_BUS_DIV_SELECT;
*bm = BM_PLL_BUS_DIV_SELECT;
} else if (clk == &pll3_usb_otg) {
reg = PLL3_USB_OTG;
*bp = BP_PLL_USB_DIV_SELECT;
*bm = BM_PLL_USB_DIV_SELECT;
} else if (clk == &pll7_usb_host) {
reg = PLL7_USB_HOST;
*bp = BP_PLL_USB_DIV_SELECT;
*bm = BM_PLL_USB_DIV_SELECT;
} else {
BUG();
}
return reg;
}
static unsigned long pll_get_rate(struct clk *clk)
{
void __iomem *reg;
u32 div, bp, bm;
reg = pll_get_div_reg_bit(clk, &bp, &bm);
div = (readl_relaxed(reg) & bm) >> bp;
return (div == 1) ? clk_get_rate(clk->parent) * 22 :
clk_get_rate(clk->parent) * 20;
}
static int pll_set_rate(struct clk *clk, unsigned long rate)
{
void __iomem *reg;
u32 val, div, bp, bm;
if (rate == FREQ_528M)
div = 1;
else if (rate == FREQ_480M)
div = 0;
else
return -EINVAL;
reg = pll_get_div_reg_bit(clk, &bp, &bm);
val = readl_relaxed(reg);
val &= ~bm;
val |= div << bp;
writel_relaxed(val, reg);
return 0;
}
static unsigned long pfd_get_rate(struct clk *clk)
{
u64 tmp = (u64) clk_get_rate(clk->parent) * 18;
u32 frac, bp_frac;
if (apbh_dma_clk.usecount == 0)
apbh_dma_clk.enable(&apbh_dma_clk);
bp_frac = clk->enable_shift - 7;
frac = readl_relaxed(clk->enable_reg) >> bp_frac & PFD_FRAC_MASK;
do_div(tmp, frac);
return tmp;
}
static int pfd_set_rate(struct clk *clk, unsigned long rate)
{
u32 val, frac, bp_frac;
u64 tmp = (u64) clk_get_rate(clk->parent) * 18;
if (apbh_dma_clk.usecount == 0)
apbh_dma_clk.enable(&apbh_dma_clk);
tmp += rate / 2;
do_div(tmp, rate);
frac = tmp;
frac = (frac < 12) ? 12 : frac;
frac = (frac > 35) ? 35 : frac;
bp_frac = clk->enable_shift - 7;
val = readl_relaxed(clk->enable_reg);
val &= ~(PFD_FRAC_MASK << bp_frac);
val |= frac << bp_frac;
writel_relaxed(val, clk->enable_reg);
tmp = (u64) clk_get_rate(clk->parent) * 18;
do_div(tmp, frac);
if (apbh_dma_clk.usecount == 0)
apbh_dma_clk.disable(&apbh_dma_clk);
return 0;
}
static unsigned long pfd_round_rate(struct clk *clk, unsigned long rate)
{
u32 frac;
u64 tmp;
tmp = (u64) clk_get_rate(clk->parent) * 18;
tmp += rate / 2;
do_div(tmp, rate);
frac = tmp;
frac = (frac < 12) ? 12 : frac;
frac = (frac > 35) ? 35 : frac;
tmp = (u64) clk_get_rate(clk->parent) * 18;
do_div(tmp, frac);
return tmp;
}
static int pfd_enable(struct clk *clk)
{
u32 val;
if (apbh_dma_clk.usecount == 0)
apbh_dma_clk.enable(&apbh_dma_clk);
val = readl_relaxed(clk->enable_reg);
val &= ~(1 << clk->enable_shift);
writel_relaxed(val, clk->enable_reg);
if (apbh_dma_clk.usecount == 0)
apbh_dma_clk.disable(&apbh_dma_clk);
return 0;
}
static void pfd_disable(struct clk *clk)
{
u32 val;
if (apbh_dma_clk.usecount == 0)
apbh_dma_clk.enable(&apbh_dma_clk);
val = readl_relaxed(clk->enable_reg);
val |= 1 << clk->enable_shift;
writel_relaxed(val, clk->enable_reg);
if (apbh_dma_clk.usecount == 0)
apbh_dma_clk.disable(&apbh_dma_clk);
}
static unsigned long pll2_200m_get_rate(struct clk *clk)
{
return clk_get_rate(clk->parent) / 2;
}
static unsigned long pll3_120m_get_rate(struct clk *clk)
{
return clk_get_rate(clk->parent) / 4;
}
static unsigned long pll3_80m_get_rate(struct clk *clk)
{
return clk_get_rate(clk->parent) / 6;
}
static unsigned long pll3_60m_get_rate(struct clk *clk)
{
return clk_get_rate(clk->parent) / 8;
}
static int pll1_sw_clk_set_parent(struct clk *clk, struct clk *parent)
{
u32 val = readl_relaxed(CCSR);
if (parent == &pll1_sys) {
val &= ~BM_CCSR_PLL1_SW_SEL;
val &= ~BM_CCSR_STEP_SEL;
} else if (parent == &osc_clk) {
val |= BM_CCSR_PLL1_SW_SEL;
val &= ~BM_CCSR_STEP_SEL;
} else if (parent == &pll2_pfd_400m) {
val |= BM_CCSR_PLL1_SW_SEL;
val |= BM_CCSR_STEP_SEL;
} else {
return -EINVAL;
}
writel_relaxed(val, CCSR);
return 0;
}
static void calc_pred_podf_dividers(u32 div, u32 *pred, u32 *podf)
{
u32 min_pred, temp_pred, old_err, err;
if (div >= 512) {
*pred = 8;
*podf = 64;
} else if (div >= 8) {
min_pred = (div - 1) / 64 + 1;
old_err = 8;
for (temp_pred = 8; temp_pred >= min_pred; temp_pred--) {
err = div % temp_pred;
if (err == 0) {
*pred = temp_pred;
break;
}
err = temp_pred - err;
if (err < old_err) {
old_err = err;
*pred = temp_pred;
}
}
*podf = (div + *pred - 1) / *pred;
} else if (div < 8) {
*pred = div;
*podf = 1;
}
}
static int _clk_enable(struct clk *clk)
{
u32 reg;
reg = readl_relaxed(clk->enable_reg);
reg |= 0x3 << clk->enable_shift;
writel_relaxed(reg, clk->enable_reg);
return 0;
}
static void _clk_disable(struct clk *clk)
{
u32 reg;
reg = readl_relaxed(clk->enable_reg);
reg &= ~(0x3 << clk->enable_shift);
writel_relaxed(reg, clk->enable_reg);
}
static unsigned long ldb_di_clk_get_rate(struct clk *clk)
{
u32 val = readl_relaxed(CSCMR2);
val &= (clk == &ldb_di0_clk) ? BM_CSCMR2_LDB_DI0_IPU_DIV :
BM_CSCMR2_LDB_DI1_IPU_DIV;
if (val)
return clk_get_rate(clk->parent) / 7;
else
return clk_get_rate(clk->parent) * 2 / 7;
}
static int ldb_di_clk_set_rate(struct clk *clk, unsigned long rate)
{
unsigned long parent_rate = clk_get_rate(clk->parent);
u32 val = readl_relaxed(CSCMR2);
if (rate * 7 <= parent_rate + parent_rate / 20)
val |= BM_CSCMR2_LDB_DI0_IPU_DIV;
else
val &= ~BM_CSCMR2_LDB_DI0_IPU_DIV;
writel_relaxed(val, CSCMR2);
return 0;
}
static unsigned long ldb_di_clk_round_rate(struct clk *clk, unsigned long rate)
{
unsigned long parent_rate = clk_get_rate(clk->parent);
if (rate * 7 <= parent_rate + parent_rate / 20)
return parent_rate / 7;
else
return 2 * parent_rate / 7;
}
static unsigned long _clk_get_rate(struct clk *clk)
{
struct divider *d;
u32 val, pred, podf;
int i, num;
if (clk == &ldb_di0_clk || clk == &ldb_di1_clk)
return ldb_di_clk_get_rate(clk);
num = ARRAY_SIZE(dividers);
for (i = 0; i < num; i++)
if (dividers[i]->clk == clk) {
d = dividers[i];
break;
}
if (i == num)
return clk_get_rate(clk->parent);
val = readl_relaxed(d->reg);
pred = ((val & d->bm_pred) >> d->bp_pred) + 1;
podf = ((val & d->bm_podf) >> d->bp_podf) + 1;
return clk_get_rate(clk->parent) / (pred * podf);
}
static int clk_busy_wait(struct clk *clk)
{
int timeout = 0x100000;
u32 bm;
if (clk == &axi_clk)
bm = BM_CDHIPR_AXI_PODF_BUSY;
else if (clk == &ahb_clk)
bm = BM_CDHIPR_AHB_PODF_BUSY;
else if (clk == &mmdc_ch0_axi_clk)
bm = BM_CDHIPR_MMDC_CH0_PODF_BUSY;
else if (clk == &periph_clk)
bm = BM_CDHIPR_PERIPH_SEL_BUSY;
else if (clk == &arm_clk)
bm = BM_CDHIPR_ARM_PODF_BUSY;
else
return -EINVAL;
while ((readl_relaxed(CDHIPR) & bm) && --timeout)
cpu_relax();
if (unlikely(!timeout))
return -EBUSY;
return 0;
}
static int _clk_set_rate(struct clk *clk, unsigned long rate)
{
unsigned long parent_rate = clk_get_rate(clk->parent);
struct divider *d;
u32 val, div, max_div, pred = 0, podf;
int i, num;
if (clk == &ldb_di0_clk || clk == &ldb_di1_clk)
return ldb_di_clk_set_rate(clk, rate);
num = ARRAY_SIZE(dividers);
for (i = 0; i < num; i++)
if (dividers[i]->clk == clk) {
d = dividers[i];
break;
}
if (i == num)
return -EINVAL;
max_div = ((d->bm_pred >> d->bp_pred) + 1) *
((d->bm_podf >> d->bp_podf) + 1);
div = parent_rate / rate;
if (div == 0)
div++;
if ((parent_rate / div != rate) || div > max_div)
return -EINVAL;
if (d->bm_pred) {
calc_pred_podf_dividers(div, &pred, &podf);
} else {
pred = 1;
podf = div;
}
val = readl_relaxed(d->reg);
val &= ~(d->bm_pred | d->bm_podf);
val |= (pred - 1) << d->bp_pred | (podf - 1) << d->bp_podf;
writel_relaxed(val, d->reg);
if (clk == &axi_clk || clk == &ahb_clk ||
clk == &mmdc_ch0_axi_clk || clk == &arm_clk)
return clk_busy_wait(clk);
return 0;
}
static unsigned long _clk_round_rate(struct clk *clk, unsigned long rate)
{
unsigned long parent_rate = clk_get_rate(clk->parent);
u32 div = parent_rate / rate;
u32 div_max, pred = 0, podf;
struct divider *d;
int i, num;
if (clk == &ldb_di0_clk || clk == &ldb_di1_clk)
return ldb_di_clk_round_rate(clk, rate);
num = ARRAY_SIZE(dividers);
for (i = 0; i < num; i++)
if (dividers[i]->clk == clk) {
d = dividers[i];
break;
}
if (i == num)
return -EINVAL;
if (div == 0 || parent_rate % rate)
div++;
if (d->bm_pred) {
calc_pred_podf_dividers(div, &pred, &podf);
div = pred * podf;
} else {
div_max = (d->bm_podf >> d->bp_podf) + 1;
if (div > div_max)
div = div_max;
}
return parent_rate / div;
}
static int _clk_set_parent(struct clk *clk, struct clk *parent)
{
struct multiplexer *m;
int i, num;
u32 val;
num = ARRAY_SIZE(multiplexers);
for (i = 0; i < num; i++)
if (multiplexers[i]->clk == clk) {
m = multiplexers[i];
break;
}
if (i == num)
return -EINVAL;
i = 0;
while (m->parents[i]) {
if (parent == m->parents[i])
break;
i++;
}
if (!m->parents[i])
return -EINVAL;
val = readl_relaxed(m->reg);
val &= ~m->bm;
val |= i << m->bp;
writel_relaxed(val, m->reg);
if (clk == &periph_clk)
return clk_busy_wait(clk);
return 0;
}
static int pcie_clk_enable(struct clk *clk)
{
u32 val;
val = readl_relaxed(PLL8_ENET);
val |= BM_PLL_ENET_EN_PCIE;
writel_relaxed(val, PLL8_ENET);
return _clk_enable(clk);
}
static void pcie_clk_disable(struct clk *clk)
{
u32 val;
_clk_disable(clk);
val = readl_relaxed(PLL8_ENET);
val &= BM_PLL_ENET_EN_PCIE;
writel_relaxed(val, PLL8_ENET);
}
static int sata_clk_enable(struct clk *clk)
{
u32 val;
val = readl_relaxed(PLL8_ENET);
val |= BM_PLL_ENET_EN_SATA;
writel_relaxed(val, PLL8_ENET);
return _clk_enable(clk);
}
static void sata_clk_disable(struct clk *clk)
{
u32 val;
_clk_disable(clk);
val = readl_relaxed(PLL8_ENET);
val &= BM_PLL_ENET_EN_SATA;
writel_relaxed(val, PLL8_ENET);
}
int imx6q_set_lpm(enum mxc_cpu_pwr_mode mode)
{
u32 val = readl_relaxed(CLPCR);
val &= ~BM_CLPCR_LPM;
switch (mode) {
case WAIT_CLOCKED:
break;
case WAIT_UNCLOCKED:
val |= 0x1 << BP_CLPCR_LPM;
break;
case STOP_POWER_ON:
val |= 0x2 << BP_CLPCR_LPM;
break;
case WAIT_UNCLOCKED_POWER_OFF:
val |= 0x1 << BP_CLPCR_LPM;
val &= ~BM_CLPCR_VSTBY;
val &= ~BM_CLPCR_SBYOS;
val |= BM_CLPCR_BYP_MMDC_CH1_LPM_HS;
break;
case STOP_POWER_OFF:
val |= 0x2 << BP_CLPCR_LPM;
val |= 0x3 << BP_CLPCR_STBY_COUNT;
val |= BM_CLPCR_VSTBY;
val |= BM_CLPCR_SBYOS;
val |= BM_CLPCR_BYP_MMDC_CH1_LPM_HS;
break;
default:
return -EINVAL;
}
writel_relaxed(val, CLPCR);
return 0;
}
void __init imx6q_clock_map_io(void)
{
iotable_init(imx6q_clock_desc, ARRAY_SIZE(imx6q_clock_desc));
}
int __init mx6q_clocks_init(void)
{
struct device_node *np;
void __iomem *base;
int i, irq;
for_each_compatible_node(np, NULL, "fixed-clock") {
u32 rate;
if (of_property_read_u32(np, "clock-frequency", &rate))
continue;
if (of_device_is_compatible(np, "fsl,imx-ckil"))
external_low_reference = rate;
else if (of_device_is_compatible(np, "fsl,imx-ckih1"))
external_high_reference = rate;
else if (of_device_is_compatible(np, "fsl,imx-osc"))
oscillator_reference = rate;
}
for (i = 0; i < ARRAY_SIZE(lookups); i++)
clkdev_add(&lookups[i]);
writel_relaxed(0x3 << CG0 | 0x3 << CG1 | 0x3 << CG2, CCGR0);
writel_relaxed(0x3 << CG8 | 0x3 << CG9 | 0x3 << CG10, CCGR2);
writel_relaxed(0x3 << CG10 | 0x3 << CG12, CCGR3);
writel_relaxed(0x3 << CG4 | 0x3 << CG6 | 0x3 << CG7, CCGR4);
writel_relaxed(0x3 << CG0, CCGR5);
writel_relaxed(0, CCGR6);
writel_relaxed(0, CCGR7);
clk_enable(&uart_clk);
clk_enable(&mmdc_ch0_axi_clk);
clk_set_rate(&pll4_audio, FREQ_650M);
clk_set_rate(&pll5_video, FREQ_650M);
clk_set_parent(&ipu1_di0_clk, &ipu1_di0_pre_clk);
clk_set_parent(&ipu1_di0_pre_clk, &pll5_video);
clk_set_parent(&gpu3d_shader_clk, &pll2_pfd_594m);
clk_set_rate(&gpu3d_shader_clk, FREQ_594M);
clk_set_parent(&gpu3d_core_clk, &mmdc_ch0_axi_clk);
clk_set_rate(&gpu3d_core_clk, FREQ_528M);
clk_set_parent(&asrc_serial_clk, &pll3_usb_otg);
clk_set_rate(&asrc_serial_clk, 1500000);
clk_set_rate(&enfc_clk, 11000000);
clk_set_rate(&usdhc1_clk, 49500000);
clk_set_rate(&usdhc2_clk, 49500000);
clk_set_rate(&usdhc3_clk, 49500000);
clk_set_rate(&usdhc4_clk, 49500000);
np = of_find_compatible_node(NULL, NULL, "fsl,imx6q-gpt");
base = of_iomap(np, 0);
WARN_ON(!base);
irq = irq_of_parse_and_map(np, 0);
mxc_timer_init(&gpt_clk, base, irq);
return 0;
}
