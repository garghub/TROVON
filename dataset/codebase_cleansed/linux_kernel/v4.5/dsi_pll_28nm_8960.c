static bool pll_28nm_poll_for_ready(struct dsi_pll_28nm *pll_28nm,
int nb_tries, int timeout_us)
{
bool pll_locked = false;
u32 val;
while (nb_tries--) {
val = pll_read(pll_28nm->mmio + REG_DSI_28nm_8960_PHY_PLL_RDY);
pll_locked = !!(val & DSI_28nm_8960_PHY_PLL_RDY_PLL_RDY);
if (pll_locked)
break;
udelay(timeout_us);
}
DBG("DSI PLL is %slocked", pll_locked ? "" : "*not* ");
return pll_locked;
}
static int dsi_pll_28nm_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct msm_dsi_pll *pll = hw_clk_to_pll(hw);
struct dsi_pll_28nm *pll_28nm = to_pll_28nm(pll);
void __iomem *base = pll_28nm->mmio;
u32 val, temp, fb_divider;
DBG("rate=%lu, parent's=%lu", rate, parent_rate);
temp = rate / 10;
val = VCO_REF_CLK_RATE / 10;
fb_divider = (temp * VCO_PREF_DIV_RATIO) / val;
fb_divider = fb_divider / 2 - 1;
pll_write(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_1,
fb_divider & 0xff);
val = pll_read(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_2);
val |= (fb_divider >> 8) & 0x07;
pll_write(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_2,
val);
val = pll_read(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_3);
val |= (VCO_PREF_DIV_RATIO - 1) & 0x3f;
pll_write(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_3,
val);
pll_write(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_6,
0xf);
val = pll_read(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_8);
val |= 0x7 << 4;
pll_write(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_8,
val);
return 0;
}
static int dsi_pll_28nm_clk_is_enabled(struct clk_hw *hw)
{
struct msm_dsi_pll *pll = hw_clk_to_pll(hw);
struct dsi_pll_28nm *pll_28nm = to_pll_28nm(pll);
return pll_28nm_poll_for_ready(pll_28nm, POLL_MAX_READS,
POLL_TIMEOUT_US);
}
static unsigned long dsi_pll_28nm_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct msm_dsi_pll *pll = hw_clk_to_pll(hw);
struct dsi_pll_28nm *pll_28nm = to_pll_28nm(pll);
void __iomem *base = pll_28nm->mmio;
unsigned long vco_rate;
u32 status, fb_divider, temp, ref_divider;
VERB("parent_rate=%lu", parent_rate);
status = pll_read(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_0);
if (status & DSI_28nm_8960_PHY_PLL_CTRL_0_ENABLE) {
fb_divider = pll_read(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_1);
fb_divider &= 0xff;
temp = pll_read(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_2) & 0x07;
fb_divider = (temp << 8) | fb_divider;
fb_divider += 1;
ref_divider = pll_read(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_3);
ref_divider &= 0x3f;
ref_divider += 1;
vco_rate = (parent_rate / ref_divider) * fb_divider * 2;
} else {
vco_rate = 0;
}
DBG("returning vco rate = %lu", vco_rate);
return vco_rate;
}
static unsigned long clk_bytediv_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_bytediv *bytediv = to_clk_bytediv(hw);
unsigned int div;
div = pll_read(bytediv->reg) & 0xff;
return parent_rate / (div + 1);
}
static unsigned int get_vco_mul_factor(unsigned long byte_clk_rate)
{
unsigned long bit_mhz;
bit_mhz = (byte_clk_rate * 8) / 1000000;
if (bit_mhz < 125)
return 64;
else if (bit_mhz < 250)
return 32;
else if (bit_mhz < 600)
return 16;
else
return 8;
}
static long clk_bytediv_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
unsigned long best_parent;
unsigned int factor;
factor = get_vco_mul_factor(rate);
best_parent = rate * factor;
*prate = clk_hw_round_rate(clk_hw_get_parent(hw), best_parent);
return *prate / factor;
}
static int clk_bytediv_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_bytediv *bytediv = to_clk_bytediv(hw);
u32 val;
unsigned int factor;
factor = get_vco_mul_factor(rate);
val = pll_read(bytediv->reg);
val |= (factor - 1) & 0xff;
pll_write(bytediv->reg, val);
return 0;
}
static int dsi_pll_28nm_enable_seq(struct msm_dsi_pll *pll)
{
struct dsi_pll_28nm *pll_28nm = to_pll_28nm(pll);
struct device *dev = &pll_28nm->pdev->dev;
void __iomem *base = pll_28nm->mmio;
bool locked;
unsigned int bit_div, byte_div;
int max_reads = 1000, timeout_us = 100;
u32 val;
DBG("id=%d", pll_28nm->id);
val = pll_read(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_9);
byte_div = val + 1;
bit_div = byte_div / 8;
val = pll_read(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_8);
val &= ~0xf;
val |= (bit_div - 1);
pll_write(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_8, val);
pll_write(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_0,
DSI_28nm_8960_PHY_PLL_CTRL_0_ENABLE);
locked = pll_28nm_poll_for_ready(pll_28nm, max_reads, timeout_us);
if (unlikely(!locked))
dev_err(dev, "DSI PLL lock failed\n");
else
DBG("DSI PLL lock success");
return locked ? 0 : -EINVAL;
}
static void dsi_pll_28nm_disable_seq(struct msm_dsi_pll *pll)
{
struct dsi_pll_28nm *pll_28nm = to_pll_28nm(pll);
DBG("id=%d", pll_28nm->id);
pll_write(pll_28nm->mmio + REG_DSI_28nm_8960_PHY_PLL_CTRL_0, 0x00);
}
static void dsi_pll_28nm_save_state(struct msm_dsi_pll *pll)
{
struct dsi_pll_28nm *pll_28nm = to_pll_28nm(pll);
struct pll_28nm_cached_state *cached_state = &pll_28nm->cached_state;
void __iomem *base = pll_28nm->mmio;
cached_state->postdiv3 =
pll_read(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_10);
cached_state->postdiv2 =
pll_read(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_9);
cached_state->postdiv1 =
pll_read(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_8);
cached_state->vco_rate = clk_hw_get_rate(&pll->clk_hw);
}
static int dsi_pll_28nm_restore_state(struct msm_dsi_pll *pll)
{
struct dsi_pll_28nm *pll_28nm = to_pll_28nm(pll);
struct pll_28nm_cached_state *cached_state = &pll_28nm->cached_state;
void __iomem *base = pll_28nm->mmio;
int ret;
ret = dsi_pll_28nm_clk_set_rate(&pll->clk_hw,
cached_state->vco_rate, 0);
if (ret) {
dev_err(&pll_28nm->pdev->dev,
"restore vco rate failed. ret=%d\n", ret);
return ret;
}
pll_write(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_10,
cached_state->postdiv3);
pll_write(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_9,
cached_state->postdiv2);
pll_write(base + REG_DSI_28nm_8960_PHY_PLL_CTRL_8,
cached_state->postdiv1);
return 0;
}
static int dsi_pll_28nm_get_provider(struct msm_dsi_pll *pll,
struct clk **byte_clk_provider,
struct clk **pixel_clk_provider)
{
struct dsi_pll_28nm *pll_28nm = to_pll_28nm(pll);
if (byte_clk_provider)
*byte_clk_provider = pll_28nm->provided_clks[DSI_BYTE_PLL_CLK];
if (pixel_clk_provider)
*pixel_clk_provider =
pll_28nm->provided_clks[DSI_PIXEL_PLL_CLK];
return 0;
}
static void dsi_pll_28nm_destroy(struct msm_dsi_pll *pll)
{
struct dsi_pll_28nm *pll_28nm = to_pll_28nm(pll);
msm_dsi_pll_helper_unregister_clks(pll_28nm->pdev,
pll_28nm->clks, pll_28nm->num_clks);
}
static int pll_28nm_register(struct dsi_pll_28nm *pll_28nm)
{
char *clk_name, *parent_name, *vco_name;
struct clk_init_data vco_init = {
.parent_names = (const char *[]){ "pxo" },
.num_parents = 1,
.ops = &clk_ops_dsi_pll_28nm_vco,
};
struct device *dev = &pll_28nm->pdev->dev;
struct clk **clks = pll_28nm->clks;
struct clk **provided_clks = pll_28nm->provided_clks;
struct clk_bytediv *bytediv;
struct clk_init_data bytediv_init = { };
int ret, num = 0;
DBG("%d", pll_28nm->id);
bytediv = devm_kzalloc(dev, sizeof(*bytediv), GFP_KERNEL);
if (!bytediv)
return -ENOMEM;
vco_name = devm_kzalloc(dev, 32, GFP_KERNEL);
if (!vco_name)
return -ENOMEM;
parent_name = devm_kzalloc(dev, 32, GFP_KERNEL);
if (!parent_name)
return -ENOMEM;
clk_name = devm_kzalloc(dev, 32, GFP_KERNEL);
if (!clk_name)
return -ENOMEM;
pll_28nm->bytediv = bytediv;
snprintf(vco_name, 32, "dsi%dvco_clk", pll_28nm->id);
vco_init.name = vco_name;
pll_28nm->base.clk_hw.init = &vco_init;
clks[num++] = clk_register(dev, &pll_28nm->base.clk_hw);
bytediv->hw.init = &bytediv_init;
bytediv->reg = pll_28nm->mmio + REG_DSI_28nm_8960_PHY_PLL_CTRL_9;
snprintf(parent_name, 32, "dsi%dvco_clk", pll_28nm->id);
snprintf(clk_name, 32, "dsi%dpllbyte", pll_28nm->id);
bytediv_init.name = clk_name;
bytediv_init.ops = &clk_bytediv_ops;
bytediv_init.flags = CLK_SET_RATE_PARENT;
bytediv_init.parent_names = (const char * const *) &parent_name;
bytediv_init.num_parents = 1;
clks[num++] = provided_clks[DSI_BYTE_PLL_CLK] =
clk_register(dev, &bytediv->hw);
snprintf(clk_name, 32, "dsi%dpll", pll_28nm->id);
clks[num++] = provided_clks[DSI_PIXEL_PLL_CLK] =
clk_register_divider(dev, clk_name,
parent_name, 0, pll_28nm->mmio +
REG_DSI_28nm_8960_PHY_PLL_CTRL_10,
0, 8, 0, NULL);
pll_28nm->num_clks = num;
pll_28nm->clk_data.clk_num = NUM_PROVIDED_CLKS;
pll_28nm->clk_data.clks = provided_clks;
ret = of_clk_add_provider(dev->of_node,
of_clk_src_onecell_get, &pll_28nm->clk_data);
if (ret) {
dev_err(dev, "failed to register clk provider: %d\n", ret);
return ret;
}
return 0;
}
struct msm_dsi_pll *msm_dsi_pll_28nm_8960_init(struct platform_device *pdev,
int id)
{
struct dsi_pll_28nm *pll_28nm;
struct msm_dsi_pll *pll;
int ret;
if (!pdev)
return ERR_PTR(-ENODEV);
pll_28nm = devm_kzalloc(&pdev->dev, sizeof(*pll_28nm), GFP_KERNEL);
if (!pll_28nm)
return ERR_PTR(-ENOMEM);
pll_28nm->pdev = pdev;
pll_28nm->id = id + 1;
pll_28nm->mmio = msm_ioremap(pdev, "dsi_pll", "DSI_PLL");
if (IS_ERR_OR_NULL(pll_28nm->mmio)) {
dev_err(&pdev->dev, "%s: failed to map pll base\n", __func__);
return ERR_PTR(-ENOMEM);
}
pll = &pll_28nm->base;
pll->min_rate = VCO_MIN_RATE;
pll->max_rate = VCO_MAX_RATE;
pll->get_provider = dsi_pll_28nm_get_provider;
pll->destroy = dsi_pll_28nm_destroy;
pll->disable_seq = dsi_pll_28nm_disable_seq;
pll->save_state = dsi_pll_28nm_save_state;
pll->restore_state = dsi_pll_28nm_restore_state;
pll->en_seq_cnt = 1;
pll->enable_seqs[0] = dsi_pll_28nm_enable_seq;
ret = pll_28nm_register(pll_28nm);
if (ret) {
dev_err(&pdev->dev, "failed to register PLL: %d\n", ret);
return ERR_PTR(ret);
}
return pll;
}
