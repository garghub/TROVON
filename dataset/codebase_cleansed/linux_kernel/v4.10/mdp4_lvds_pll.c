static struct mdp4_kms *get_kms(struct mdp4_lvds_pll *lvds_pll)
{
struct msm_drm_private *priv = lvds_pll->dev->dev_private;
return to_mdp4_kms(to_mdp_kms(priv->kms));
}
static const struct pll_rate *find_rate(unsigned long rate)
{
int i;
for (i = 1; i < ARRAY_SIZE(freqtbl); i++)
if (rate > freqtbl[i].rate)
return &freqtbl[i-1];
return &freqtbl[i-1];
}
static int mpd4_lvds_pll_enable(struct clk_hw *hw)
{
struct mdp4_lvds_pll *lvds_pll = to_mdp4_lvds_pll(hw);
struct mdp4_kms *mdp4_kms = get_kms(lvds_pll);
const struct pll_rate *pll_rate = find_rate(lvds_pll->pixclk);
int i;
DBG("pixclk=%lu (%lu)", lvds_pll->pixclk, pll_rate->rate);
if (WARN_ON(!pll_rate))
return -EINVAL;
mdp4_write(mdp4_kms, REG_MDP4_LCDC_LVDS_PHY_RESET, 0x33);
for (i = 0; pll_rate->conf[i].reg; i++)
mdp4_write(mdp4_kms, pll_rate->conf[i].reg, pll_rate->conf[i].val);
mdp4_write(mdp4_kms, REG_MDP4_LVDS_PHY_PLL_CTRL_0, 0x01);
while (!mdp4_read(mdp4_kms, REG_MDP4_LVDS_PHY_PLL_LOCKED))
cpu_relax();
return 0;
}
static void mpd4_lvds_pll_disable(struct clk_hw *hw)
{
struct mdp4_lvds_pll *lvds_pll = to_mdp4_lvds_pll(hw);
struct mdp4_kms *mdp4_kms = get_kms(lvds_pll);
DBG("");
mdp4_write(mdp4_kms, REG_MDP4_LVDS_PHY_CFG0, 0x0);
mdp4_write(mdp4_kms, REG_MDP4_LVDS_PHY_PLL_CTRL_0, 0x0);
}
static unsigned long mpd4_lvds_pll_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct mdp4_lvds_pll *lvds_pll = to_mdp4_lvds_pll(hw);
return lvds_pll->pixclk;
}
static long mpd4_lvds_pll_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
const struct pll_rate *pll_rate = find_rate(rate);
return pll_rate->rate;
}
static int mpd4_lvds_pll_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct mdp4_lvds_pll *lvds_pll = to_mdp4_lvds_pll(hw);
lvds_pll->pixclk = rate;
return 0;
}
struct clk *mpd4_lvds_pll_init(struct drm_device *dev)
{
struct mdp4_lvds_pll *lvds_pll;
struct clk *clk;
int ret;
lvds_pll = devm_kzalloc(dev->dev, sizeof(*lvds_pll), GFP_KERNEL);
if (!lvds_pll) {
ret = -ENOMEM;
goto fail;
}
lvds_pll->dev = dev;
lvds_pll->pll_hw.init = &pll_init;
clk = devm_clk_register(dev->dev, &lvds_pll->pll_hw);
if (IS_ERR(clk)) {
ret = PTR_ERR(clk);
goto fail;
}
return clk;
fail:
return ERR_PTR(ret);
}
