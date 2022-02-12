static int pll_get_rate_index(struct iproc_pll *pll, unsigned int target_rate)
{
int i;
for (i = 0; i < pll->num_vco_entries; i++)
if (target_rate == pll->vco_param[i].rate)
break;
if (i >= pll->num_vco_entries)
return -EINVAL;
return i;
}
static int get_kp(unsigned long ref_freq, enum kp_band kp_index)
{
int i;
if (ref_freq < ref_freq_table[0][0])
return -EINVAL;
for (i = 0; i < NUM_FREQ_BANDS; i++) {
if (ref_freq >= ref_freq_table[i][0] &&
ref_freq < ref_freq_table[i][1])
return kp_table[kp_index][i];
}
return -EINVAL;
}
static int pll_wait_for_lock(struct iproc_pll *pll)
{
int i;
const struct iproc_pll_ctrl *ctrl = pll->ctrl;
for (i = 0; i < LOCK_DELAY; i++) {
u32 val = readl(pll->status_base + ctrl->status.offset);
if (val & (1 << ctrl->status.shift))
return 0;
udelay(10);
}
return -EIO;
}
static void iproc_pll_write(const struct iproc_pll *pll, void __iomem *base,
const u32 offset, u32 val)
{
const struct iproc_pll_ctrl *ctrl = pll->ctrl;
writel(val, base + offset);
if (unlikely(ctrl->flags & IPROC_CLK_NEEDS_READ_BACK &&
(base == pll->status_base || base == pll->control_base)))
val = readl(base + offset);
}
static void __pll_disable(struct iproc_pll *pll)
{
const struct iproc_pll_ctrl *ctrl = pll->ctrl;
u32 val;
if (ctrl->flags & IPROC_CLK_PLL_ASIU) {
val = readl(pll->asiu_base + ctrl->asiu.offset);
val &= ~(1 << ctrl->asiu.en_shift);
iproc_pll_write(pll, pll->asiu_base, ctrl->asiu.offset, val);
}
if (ctrl->flags & IPROC_CLK_EMBED_PWRCTRL) {
val = readl(pll->control_base + ctrl->aon.offset);
val |= bit_mask(ctrl->aon.pwr_width) << ctrl->aon.pwr_shift;
iproc_pll_write(pll, pll->control_base, ctrl->aon.offset, val);
}
if (pll->pwr_base) {
val = readl(pll->pwr_base + ctrl->aon.offset);
val |= 1 << ctrl->aon.iso_shift;
iproc_pll_write(pll, pll->pwr_base, ctrl->aon.offset, val);
val &= ~(bit_mask(ctrl->aon.pwr_width) << ctrl->aon.pwr_shift);
iproc_pll_write(pll, pll->pwr_base, ctrl->aon.offset, val);
}
}
static int __pll_enable(struct iproc_pll *pll)
{
const struct iproc_pll_ctrl *ctrl = pll->ctrl;
u32 val;
if (ctrl->flags & IPROC_CLK_EMBED_PWRCTRL) {
val = readl(pll->control_base + ctrl->aon.offset);
val &= ~(bit_mask(ctrl->aon.pwr_width) << ctrl->aon.pwr_shift);
iproc_pll_write(pll, pll->control_base, ctrl->aon.offset, val);
}
if (pll->pwr_base) {
val = readl(pll->pwr_base + ctrl->aon.offset);
val |= bit_mask(ctrl->aon.pwr_width) << ctrl->aon.pwr_shift;
val &= ~(1 << ctrl->aon.iso_shift);
iproc_pll_write(pll, pll->pwr_base, ctrl->aon.offset, val);
}
if (ctrl->flags & IPROC_CLK_PLL_ASIU) {
val = readl(pll->asiu_base + ctrl->asiu.offset);
val |= (1 << ctrl->asiu.en_shift);
iproc_pll_write(pll, pll->asiu_base, ctrl->asiu.offset, val);
}
return 0;
}
static void __pll_put_in_reset(struct iproc_pll *pll)
{
u32 val;
const struct iproc_pll_ctrl *ctrl = pll->ctrl;
const struct iproc_pll_reset_ctrl *reset = &ctrl->reset;
val = readl(pll->control_base + reset->offset);
val &= ~(1 << reset->reset_shift | 1 << reset->p_reset_shift);
iproc_pll_write(pll, pll->control_base, reset->offset, val);
}
static void __pll_bring_out_reset(struct iproc_pll *pll, unsigned int kp,
unsigned int ka, unsigned int ki)
{
u32 val;
const struct iproc_pll_ctrl *ctrl = pll->ctrl;
const struct iproc_pll_reset_ctrl *reset = &ctrl->reset;
const struct iproc_pll_dig_filter_ctrl *dig_filter = &ctrl->dig_filter;
val = readl(pll->control_base + dig_filter->offset);
val &= ~(bit_mask(dig_filter->ki_width) << dig_filter->ki_shift |
bit_mask(dig_filter->kp_width) << dig_filter->kp_shift |
bit_mask(dig_filter->ka_width) << dig_filter->ka_shift);
val |= ki << dig_filter->ki_shift | kp << dig_filter->kp_shift |
ka << dig_filter->ka_shift;
iproc_pll_write(pll, pll->control_base, dig_filter->offset, val);
val = readl(pll->control_base + reset->offset);
val |= 1 << reset->reset_shift | 1 << reset->p_reset_shift;
iproc_pll_write(pll, pll->control_base, reset->offset, val);
}
static int pll_set_rate(struct iproc_clk *clk, unsigned int rate_index,
unsigned long parent_rate)
{
struct iproc_pll *pll = clk->pll;
const struct iproc_pll_vco_param *vco = &pll->vco_param[rate_index];
const struct iproc_pll_ctrl *ctrl = pll->ctrl;
int ka = 0, ki, kp, ret;
unsigned long rate = vco->rate;
u32 val;
enum kp_band kp_index;
unsigned long ref_freq;
if (vco->pdiv == 0)
ref_freq = parent_rate * 2;
else
ref_freq = parent_rate / vco->pdiv;
if (rate >= VCO_LOW && rate < VCO_HIGH) {
ki = 4;
kp_index = KP_BAND_MID;
} else if (rate >= VCO_HIGH && rate && rate < VCO_HIGH_HIGH) {
ki = 3;
kp_index = KP_BAND_HIGH;
} else if (rate >= VCO_HIGH_HIGH && rate < VCO_MAX) {
ki = 3;
kp_index = KP_BAND_HIGH_HIGH;
} else {
pr_err("%s: pll: %s has invalid rate: %lu\n", __func__,
clk->name, rate);
return -EINVAL;
}
kp = get_kp(ref_freq, kp_index);
if (kp < 0) {
pr_err("%s: pll: %s has invalid kp\n", __func__, clk->name);
return kp;
}
ret = __pll_enable(pll);
if (ret) {
pr_err("%s: pll: %s fails to enable\n", __func__, clk->name);
return ret;
}
__pll_put_in_reset(pll);
iproc_pll_write(pll, pll->control_base, ctrl->vco_ctrl.u_offset, 0);
val = readl(pll->control_base + ctrl->vco_ctrl.l_offset);
if (rate >= VCO_LOW && rate < VCO_MID)
val |= (1 << PLL_VCO_LOW_SHIFT);
if (rate < VCO_HIGH)
val &= ~(1 << PLL_VCO_HIGH_SHIFT);
else
val |= (1 << PLL_VCO_HIGH_SHIFT);
iproc_pll_write(pll, pll->control_base, ctrl->vco_ctrl.l_offset, val);
val = readl(pll->control_base + ctrl->ndiv_int.offset);
val &= ~(bit_mask(ctrl->ndiv_int.width) << ctrl->ndiv_int.shift);
val |= vco->ndiv_int << ctrl->ndiv_int.shift;
iproc_pll_write(pll, pll->control_base, ctrl->ndiv_int.offset, val);
if (ctrl->flags & IPROC_CLK_PLL_HAS_NDIV_FRAC) {
val = readl(pll->control_base + ctrl->ndiv_frac.offset);
val &= ~(bit_mask(ctrl->ndiv_frac.width) <<
ctrl->ndiv_frac.shift);
val |= vco->ndiv_frac << ctrl->ndiv_frac.shift;
iproc_pll_write(pll, pll->control_base, ctrl->ndiv_frac.offset,
val);
}
val = readl(pll->control_base + ctrl->pdiv.offset);
val &= ~(bit_mask(ctrl->pdiv.width) << ctrl->pdiv.shift);
val |= vco->pdiv << ctrl->pdiv.shift;
iproc_pll_write(pll, pll->control_base, ctrl->pdiv.offset, val);
__pll_bring_out_reset(pll, kp, ka, ki);
ret = pll_wait_for_lock(pll);
if (ret < 0) {
pr_err("%s: pll: %s failed to lock\n", __func__, clk->name);
return ret;
}
return 0;
}
static int iproc_pll_enable(struct clk_hw *hw)
{
struct iproc_clk *clk = to_iproc_clk(hw);
struct iproc_pll *pll = clk->pll;
return __pll_enable(pll);
}
static void iproc_pll_disable(struct clk_hw *hw)
{
struct iproc_clk *clk = to_iproc_clk(hw);
struct iproc_pll *pll = clk->pll;
const struct iproc_pll_ctrl *ctrl = pll->ctrl;
if (ctrl->flags & IPROC_CLK_AON)
return;
__pll_disable(pll);
}
static unsigned long iproc_pll_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct iproc_clk *clk = to_iproc_clk(hw);
struct iproc_pll *pll = clk->pll;
const struct iproc_pll_ctrl *ctrl = pll->ctrl;
u32 val;
u64 ndiv, ndiv_int, ndiv_frac;
unsigned int pdiv;
if (parent_rate == 0)
return 0;
val = readl(pll->status_base + ctrl->status.offset);
if ((val & (1 << ctrl->status.shift)) == 0) {
clk->rate = 0;
return 0;
}
val = readl(pll->control_base + ctrl->ndiv_int.offset);
ndiv_int = (val >> ctrl->ndiv_int.shift) &
bit_mask(ctrl->ndiv_int.width);
ndiv = ndiv_int << 20;
if (ctrl->flags & IPROC_CLK_PLL_HAS_NDIV_FRAC) {
val = readl(pll->control_base + ctrl->ndiv_frac.offset);
ndiv_frac = (val >> ctrl->ndiv_frac.shift) &
bit_mask(ctrl->ndiv_frac.width);
ndiv += ndiv_frac;
}
val = readl(pll->control_base + ctrl->pdiv.offset);
pdiv = (val >> ctrl->pdiv.shift) & bit_mask(ctrl->pdiv.width);
clk->rate = (ndiv * parent_rate) >> 20;
if (pdiv == 0)
clk->rate *= 2;
else
clk->rate /= pdiv;
return clk->rate;
}
static long iproc_pll_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
unsigned i;
struct iproc_clk *clk = to_iproc_clk(hw);
struct iproc_pll *pll = clk->pll;
if (rate == 0 || *parent_rate == 0 || !pll->vco_param)
return -EINVAL;
for (i = 0; i < pll->num_vco_entries; i++) {
if (rate <= pll->vco_param[i].rate)
break;
}
if (i == pll->num_vco_entries)
i--;
return pll->vco_param[i].rate;
}
static int iproc_pll_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct iproc_clk *clk = to_iproc_clk(hw);
struct iproc_pll *pll = clk->pll;
int rate_index, ret;
rate_index = pll_get_rate_index(pll, rate);
if (rate_index < 0)
return rate_index;
ret = pll_set_rate(clk, rate_index, parent_rate);
return ret;
}
static int iproc_clk_enable(struct clk_hw *hw)
{
struct iproc_clk *clk = to_iproc_clk(hw);
const struct iproc_clk_ctrl *ctrl = clk->ctrl;
struct iproc_pll *pll = clk->pll;
u32 val;
val = readl(pll->control_base + ctrl->enable.offset);
val &= ~(1 << ctrl->enable.enable_shift);
iproc_pll_write(pll, pll->control_base, ctrl->enable.offset, val);
val = readl(pll->control_base + ctrl->enable.offset);
val &= ~(1 << ctrl->enable.hold_shift);
iproc_pll_write(pll, pll->control_base, ctrl->enable.offset, val);
return 0;
}
static void iproc_clk_disable(struct clk_hw *hw)
{
struct iproc_clk *clk = to_iproc_clk(hw);
const struct iproc_clk_ctrl *ctrl = clk->ctrl;
struct iproc_pll *pll = clk->pll;
u32 val;
if (ctrl->flags & IPROC_CLK_AON)
return;
val = readl(pll->control_base + ctrl->enable.offset);
val |= 1 << ctrl->enable.enable_shift;
iproc_pll_write(pll, pll->control_base, ctrl->enable.offset, val);
}
static unsigned long iproc_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct iproc_clk *clk = to_iproc_clk(hw);
const struct iproc_clk_ctrl *ctrl = clk->ctrl;
struct iproc_pll *pll = clk->pll;
u32 val;
unsigned int mdiv;
if (parent_rate == 0)
return 0;
val = readl(pll->control_base + ctrl->mdiv.offset);
mdiv = (val >> ctrl->mdiv.shift) & bit_mask(ctrl->mdiv.width);
if (mdiv == 0)
mdiv = 256;
clk->rate = parent_rate / mdiv;
return clk->rate;
}
static long iproc_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
unsigned int div;
if (rate == 0 || *parent_rate == 0)
return -EINVAL;
if (rate == *parent_rate)
return *parent_rate;
div = DIV_ROUND_UP(*parent_rate, rate);
if (div < 2)
return *parent_rate;
if (div > 256)
div = 256;
return *parent_rate / div;
}
static int iproc_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct iproc_clk *clk = to_iproc_clk(hw);
const struct iproc_clk_ctrl *ctrl = clk->ctrl;
struct iproc_pll *pll = clk->pll;
u32 val;
unsigned int div;
if (rate == 0 || parent_rate == 0)
return -EINVAL;
div = DIV_ROUND_UP(parent_rate, rate);
if (div > 256)
return -EINVAL;
val = readl(pll->control_base + ctrl->mdiv.offset);
if (div == 256) {
val &= ~(bit_mask(ctrl->mdiv.width) << ctrl->mdiv.shift);
} else {
val &= ~(bit_mask(ctrl->mdiv.width) << ctrl->mdiv.shift);
val |= div << ctrl->mdiv.shift;
}
iproc_pll_write(pll, pll->control_base, ctrl->mdiv.offset, val);
clk->rate = parent_rate / div;
return 0;
}
static void iproc_pll_sw_cfg(struct iproc_pll *pll)
{
const struct iproc_pll_ctrl *ctrl = pll->ctrl;
if (ctrl->flags & IPROC_CLK_PLL_NEEDS_SW_CFG) {
u32 val;
val = readl(pll->control_base + ctrl->sw_ctrl.offset);
val |= BIT(ctrl->sw_ctrl.shift);
iproc_pll_write(pll, pll->control_base, ctrl->sw_ctrl.offset,
val);
}
}
void __init iproc_pll_clk_setup(struct device_node *node,
const struct iproc_pll_ctrl *pll_ctrl,
const struct iproc_pll_vco_param *vco,
unsigned int num_vco_entries,
const struct iproc_clk_ctrl *clk_ctrl,
unsigned int num_clks)
{
int i, ret;
struct clk *clk;
struct iproc_pll *pll;
struct iproc_clk *iclk;
struct clk_init_data init;
const char *parent_name;
if (WARN_ON(!pll_ctrl) || WARN_ON(!clk_ctrl))
return;
pll = kzalloc(sizeof(*pll), GFP_KERNEL);
if (WARN_ON(!pll))
return;
pll->clk_data.clk_num = num_clks;
pll->clk_data.clks = kcalloc(num_clks, sizeof(*pll->clk_data.clks),
GFP_KERNEL);
if (WARN_ON(!pll->clk_data.clks))
goto err_clk_data;
pll->clks = kcalloc(num_clks, sizeof(*pll->clks), GFP_KERNEL);
if (WARN_ON(!pll->clks))
goto err_clks;
pll->control_base = of_iomap(node, 0);
if (WARN_ON(!pll->control_base))
goto err_pll_iomap;
pll->pwr_base = of_iomap(node, 1);
if (pll_ctrl->flags & IPROC_CLK_PLL_ASIU) {
pll->asiu_base = of_iomap(node, 2);
if (WARN_ON(!pll->asiu_base))
goto err_asiu_iomap;
}
if (pll_ctrl->flags & IPROC_CLK_PLL_SPLIT_STAT_CTRL) {
pll->status_base = of_iomap(node, 2);
if (!pll->status_base)
goto err_status_iomap;
} else
pll->status_base = pll->control_base;
pll->ctrl = pll_ctrl;
iclk = &pll->clks[0];
iclk->pll = pll;
iclk->name = node->name;
init.name = node->name;
init.ops = &iproc_pll_ops;
init.flags = 0;
parent_name = of_clk_get_parent_name(node, 0);
init.parent_names = (parent_name ? &parent_name : NULL);
init.num_parents = (parent_name ? 1 : 0);
iclk->hw.init = &init;
if (vco) {
pll->num_vco_entries = num_vco_entries;
pll->vco_param = vco;
}
iproc_pll_sw_cfg(pll);
clk = clk_register(NULL, &iclk->hw);
if (WARN_ON(IS_ERR(clk)))
goto err_pll_register;
pll->clk_data.clks[0] = clk;
for (i = 1; i < num_clks; i++) {
const char *clk_name;
memset(&init, 0, sizeof(init));
parent_name = node->name;
ret = of_property_read_string_index(node, "clock-output-names",
i, &clk_name);
if (WARN_ON(ret))
goto err_clk_register;
iclk = &pll->clks[i];
iclk->name = clk_name;
iclk->pll = pll;
iclk->ctrl = &clk_ctrl[i];
init.name = clk_name;
init.ops = &iproc_clk_ops;
init.flags = 0;
init.parent_names = (parent_name ? &parent_name : NULL);
init.num_parents = (parent_name ? 1 : 0);
iclk->hw.init = &init;
clk = clk_register(NULL, &iclk->hw);
if (WARN_ON(IS_ERR(clk)))
goto err_clk_register;
pll->clk_data.clks[i] = clk;
}
ret = of_clk_add_provider(node, of_clk_src_onecell_get, &pll->clk_data);
if (WARN_ON(ret))
goto err_clk_register;
return;
err_clk_register:
for (i = 0; i < num_clks; i++)
clk_unregister(pll->clk_data.clks[i]);
err_pll_register:
if (pll->status_base != pll->control_base)
iounmap(pll->status_base);
err_status_iomap:
if (pll->asiu_base)
iounmap(pll->asiu_base);
err_asiu_iomap:
if (pll->pwr_base)
iounmap(pll->pwr_base);
iounmap(pll->control_base);
err_pll_iomap:
kfree(pll->clks);
err_clks:
kfree(pll->clk_data.clks);
err_clk_data:
kfree(pll);
}
