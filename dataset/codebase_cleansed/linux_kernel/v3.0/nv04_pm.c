int
nv04_pm_clock_get(struct drm_device *dev, u32 id)
{
return nouveau_hw_get_clock(dev, id);
}
void *
nv04_pm_clock_pre(struct drm_device *dev, struct nouveau_pm_level *perflvl,
u32 id, int khz)
{
struct nv04_pm_state *state;
int ret;
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (!state)
return ERR_PTR(-ENOMEM);
ret = get_pll_limits(dev, id, &state->pll);
if (ret) {
kfree(state);
return (ret == -ENOENT) ? NULL : ERR_PTR(ret);
}
ret = nouveau_calc_pll_mnp(dev, &state->pll, khz, &state->calc);
if (!ret) {
kfree(state);
return ERR_PTR(-EINVAL);
}
return state;
}
void
nv04_pm_clock_set(struct drm_device *dev, void *pre_state)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nv04_pm_state *state = pre_state;
u32 reg = state->pll.reg;
if (dev_priv->card_type >= NV_40)
reg += 4;
nouveau_hw_setpll(dev, reg, &state->calc);
if (dev_priv->card_type < NV_30 && reg == NV_PRAMDAC_MPLL_COEFF) {
if (dev_priv->card_type == NV_20)
nv_mask(dev, 0x1002c4, 0, 1 << 20);
nv_mask(dev, 0x1002c0, 0, 1 << 8);
}
kfree(state);
}
