static int armada510_init(struct armada_private *priv, struct device *dev)
{
priv->extclk[0] = devm_clk_get(dev, "ext_ref_clk_1");
if (IS_ERR(priv->extclk[0]) && PTR_ERR(priv->extclk[0]) == -ENOENT)
priv->extclk[0] = ERR_PTR(-EPROBE_DEFER);
return PTR_RET(priv->extclk[0]);
}
static int armada510_crtc_init(struct armada_crtc *dcrtc)
{
armada_updatel(0x20, (1 << 11) | 0xff, dcrtc->base + LCD_CFG_RDREG4F);
return 0;
}
static int armada510_crtc_compute_clock(struct armada_crtc *dcrtc,
const struct drm_display_mode *mode, uint32_t *sclk)
{
struct armada_private *priv = dcrtc->crtc.dev->dev_private;
struct clk *clk = priv->extclk[0];
int ret;
if (dcrtc->num == 1)
return -EINVAL;
if (IS_ERR(clk))
return PTR_ERR(clk);
if (dcrtc->clk != clk) {
ret = clk_prepare_enable(clk);
if (ret)
return ret;
dcrtc->clk = clk;
}
if (sclk) {
uint32_t rate, ref, div;
rate = mode->clock * 1000;
ref = clk_round_rate(clk, rate);
div = DIV_ROUND_UP(ref, rate);
if (div < 1)
div = 1;
clk_set_rate(clk, ref);
*sclk = div | SCLK_510_EXTCLK1;
}
return 0;
}
