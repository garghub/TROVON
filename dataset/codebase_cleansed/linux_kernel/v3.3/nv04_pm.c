int
nv04_pm_clocks_get(struct drm_device *dev, struct nouveau_pm_level *perflvl)
{
int ret;
ret = nouveau_hw_get_clock(dev, PLL_CORE);
if (ret < 0)
return ret;
perflvl->core = ret;
ret = nouveau_hw_get_clock(dev, PLL_MEMORY);
if (ret < 0)
return ret;
perflvl->memory = ret;
return 0;
}
static int
calc_pll(struct drm_device *dev, u32 id, int khz, struct nv04_pm_clock *clk)
{
int ret;
ret = get_pll_limits(dev, id, &clk->pll);
if (ret)
return ret;
ret = nouveau_calc_pll_mnp(dev, &clk->pll, khz, &clk->calc);
if (!ret)
return -EINVAL;
return 0;
}
void *
nv04_pm_clocks_pre(struct drm_device *dev, struct nouveau_pm_level *perflvl)
{
struct nv04_pm_state *info;
int ret;
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return ERR_PTR(-ENOMEM);
ret = calc_pll(dev, PLL_CORE, perflvl->core, &info->core);
if (ret)
goto error;
if (perflvl->memory) {
ret = calc_pll(dev, PLL_MEMORY, perflvl->memory, &info->memory);
if (ret)
goto error;
}
return info;
error:
kfree(info);
return ERR_PTR(ret);
}
static void
prog_pll(struct drm_device *dev, struct nv04_pm_clock *clk)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
u32 reg = clk->pll.reg;
if (dev_priv->card_type >= NV_40)
reg += 4;
nouveau_hw_setpll(dev, reg, &clk->calc);
}
int
nv04_pm_clocks_set(struct drm_device *dev, void *pre_state)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_timer_engine *ptimer = &dev_priv->engine.timer;
struct nv04_pm_state *state = pre_state;
prog_pll(dev, &state->core);
if (state->memory.pll.reg) {
prog_pll(dev, &state->memory);
if (dev_priv->card_type < NV_30) {
if (dev_priv->card_type == NV_20)
nv_mask(dev, 0x1002c4, 0, 1 << 20);
nv_mask(dev, 0x1002c0, 0, 1 << 8);
}
}
ptimer->init(dev);
kfree(state);
return 0;
}
