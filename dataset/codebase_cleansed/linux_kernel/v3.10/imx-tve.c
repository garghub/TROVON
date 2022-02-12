static void tve_lock(void *__tve)
{
struct imx_tve *tve = __tve;
spin_lock(&tve->lock);
}
static void tve_unlock(void *__tve)
{
struct imx_tve *tve = __tve;
spin_unlock(&tve->lock);
}
static void tve_enable(struct imx_tve *tve)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&tve->enable_lock, flags);
if (!tve->enabled) {
tve->enabled = 1;
clk_prepare_enable(tve->clk);
ret = regmap_update_bits(tve->regmap, TVE_COM_CONF_REG,
TVE_IPU_CLK_EN | TVE_EN,
TVE_IPU_CLK_EN | TVE_EN);
}
regmap_write(tve->regmap, TVE_STAT_REG, 0xffffffff);
if (tve->mode == TVE_MODE_VGA)
regmap_write(tve->regmap, TVE_INT_CONT_REG, 0);
else
regmap_write(tve->regmap, TVE_INT_CONT_REG,
TVE_CD_SM_IEN | TVE_CD_LM_IEN | TVE_CD_MON_END_IEN);
spin_unlock_irqrestore(&tve->enable_lock, flags);
}
static void tve_disable(struct imx_tve *tve)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&tve->enable_lock, flags);
if (tve->enabled) {
tve->enabled = 0;
ret = regmap_update_bits(tve->regmap, TVE_COM_CONF_REG,
TVE_IPU_CLK_EN | TVE_EN, 0);
clk_disable_unprepare(tve->clk);
}
spin_unlock_irqrestore(&tve->enable_lock, flags);
}
static int tve_setup_tvout(struct imx_tve *tve)
{
return -ENOTSUPP;
}
static int tve_setup_vga(struct imx_tve *tve)
{
unsigned int mask;
unsigned int val;
int ret;
ret = regmap_update_bits(tve->regmap, TVE_TVDAC0_CONT_REG,
TVE_TVDAC_GAIN_MASK, 0x0a);
ret = regmap_update_bits(tve->regmap, TVE_TVDAC1_CONT_REG,
TVE_TVDAC_GAIN_MASK, 0x0a);
ret = regmap_update_bits(tve->regmap, TVE_TVDAC2_CONT_REG,
TVE_TVDAC_GAIN_MASK, 0x0a);
mask = TVE_DATA_SOURCE_MASK | TVE_INP_VIDEO_FORM;
val = TVE_DATA_SOURCE_BUS2 | TVE_INP_YCBCR_444;
mask |= TVE_TV_STAND_MASK | TVE_P2I_CONV_EN;
val |= TVE_TV_STAND_HD_1080P30 | 0;
mask |= TVE_TV_OUT_MODE_MASK | TVE_SYNC_CH_0_EN;
val |= TVE_TV_OUT_RGB | TVE_SYNC_CH_0_EN;
ret = regmap_update_bits(tve->regmap, TVE_COM_CONF_REG, mask, val);
if (ret < 0) {
dev_err(tve->dev, "failed to set configuration: %d\n", ret);
return ret;
}
ret = regmap_update_bits(tve->regmap, TVE_TST_MODE_REG,
TVE_TVDAC_TEST_MODE_MASK, 1);
return 0;
}
static enum drm_connector_status imx_tve_connector_detect(
struct drm_connector *connector, bool force)
{
return connector_status_connected;
}
static void imx_tve_connector_destroy(struct drm_connector *connector)
{
}
static int imx_tve_connector_get_modes(struct drm_connector *connector)
{
struct imx_tve *tve = con_to_tve(connector);
struct edid *edid;
int ret = 0;
if (!tve->ddc)
return 0;
edid = drm_get_edid(connector, tve->ddc);
if (edid) {
drm_mode_connector_update_edid_property(connector, edid);
ret = drm_add_edid_modes(connector, edid);
kfree(edid);
}
return ret;
}
static int imx_tve_connector_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct imx_tve *tve = con_to_tve(connector);
unsigned long rate;
rate = clk_round_rate(tve->clk, 2000UL * mode->clock) / 2000;
if (rate == mode->clock)
return MODE_OK;
rate = clk_round_rate(tve->clk, 1000UL * mode->clock) / 1000;
if (rate == mode->clock)
return MODE_OK;
dev_warn(tve->dev, "ignoring mode %dx%d\n",
mode->hdisplay, mode->vdisplay);
return MODE_BAD;
}
static struct drm_encoder *imx_tve_connector_best_encoder(
struct drm_connector *connector)
{
struct imx_tve *tve = con_to_tve(connector);
return &tve->encoder;
}
static void imx_tve_encoder_dpms(struct drm_encoder *encoder, int mode)
{
struct imx_tve *tve = enc_to_tve(encoder);
int ret;
ret = regmap_update_bits(tve->regmap, TVE_COM_CONF_REG,
TVE_TV_OUT_MODE_MASK, TVE_TV_OUT_DISABLE);
if (ret < 0)
dev_err(tve->dev, "failed to disable TVOUT: %d\n", ret);
}
static bool imx_tve_encoder_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static void imx_tve_encoder_prepare(struct drm_encoder *encoder)
{
struct imx_tve *tve = enc_to_tve(encoder);
tve_disable(tve);
switch (tve->mode) {
case TVE_MODE_VGA:
imx_drm_crtc_panel_format_pins(encoder->crtc,
DRM_MODE_ENCODER_DAC, IPU_PIX_FMT_GBR24,
tve->hsync_pin, tve->vsync_pin);
break;
case TVE_MODE_TVOUT:
imx_drm_crtc_panel_format(encoder->crtc, DRM_MODE_ENCODER_TVDAC,
V4L2_PIX_FMT_YUV444);
break;
}
}
static void imx_tve_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct imx_tve *tve = enc_to_tve(encoder);
unsigned long rounded_rate;
unsigned long rate;
int div = 1;
int ret;
rate = 2000UL * mode->clock;
clk_set_rate(tve->clk, rate);
rounded_rate = clk_get_rate(tve->clk);
if (rounded_rate >= rate)
div = 2;
clk_set_rate(tve->di_clk, rounded_rate / div);
ret = clk_set_parent(tve->di_sel_clk, tve->di_clk);
if (ret < 0) {
dev_err(tve->dev, "failed to set di_sel parent to tve_di: %d\n",
ret);
}
if (tve->mode == TVE_MODE_VGA)
tve_setup_vga(tve);
else
tve_setup_tvout(tve);
}
static void imx_tve_encoder_commit(struct drm_encoder *encoder)
{
struct imx_tve *tve = enc_to_tve(encoder);
tve_enable(tve);
}
static void imx_tve_encoder_disable(struct drm_encoder *encoder)
{
struct imx_tve *tve = enc_to_tve(encoder);
tve_disable(tve);
}
static void imx_tve_encoder_destroy(struct drm_encoder *encoder)
{
}
static irqreturn_t imx_tve_irq_handler(int irq, void *data)
{
struct imx_tve *tve = data;
unsigned int val;
regmap_read(tve->regmap, TVE_STAT_REG, &val);
regmap_write(tve->regmap, TVE_STAT_REG, 0xffffffff);
return IRQ_HANDLED;
}
static unsigned long clk_tve_di_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct imx_tve *tve = container_of(hw, struct imx_tve, clk_hw_di);
unsigned int val;
int ret;
ret = regmap_read(tve->regmap, TVE_COM_CONF_REG, &val);
if (ret < 0)
return 0;
switch (val & TVE_DAC_SAMP_RATE_MASK) {
case TVE_DAC_DIV4_RATE:
return parent_rate / 4;
case TVE_DAC_DIV2_RATE:
return parent_rate / 2;
case TVE_DAC_FULL_RATE:
default:
return parent_rate;
}
return 0;
}
static long clk_tve_di_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
unsigned long div;
div = *prate / rate;
if (div >= 4)
return *prate / 4;
else if (div >= 2)
return *prate / 2;
else
return *prate;
}
static int clk_tve_di_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct imx_tve *tve = container_of(hw, struct imx_tve, clk_hw_di);
unsigned long div;
u32 val;
int ret;
div = parent_rate / rate;
if (div >= 4)
val = TVE_DAC_DIV4_RATE;
else if (div >= 2)
val = TVE_DAC_DIV2_RATE;
else
val = TVE_DAC_FULL_RATE;
ret = regmap_update_bits(tve->regmap, TVE_COM_CONF_REG, TVE_DAC_SAMP_RATE_MASK, val);
if (ret < 0) {
dev_err(tve->dev, "failed to set divider: %d\n", ret);
return ret;
}
return 0;
}
static int tve_clk_init(struct imx_tve *tve, void __iomem *base)
{
const char *tve_di_parent[1];
struct clk_init_data init = {
.name = "tve_di",
.ops = &clk_tve_di_ops,
.num_parents = 1,
.flags = 0,
};
tve_di_parent[0] = __clk_get_name(tve->clk);
init.parent_names = (const char **)&tve_di_parent;
tve->clk_hw_di.init = &init;
tve->di_clk = clk_register(tve->dev, &tve->clk_hw_di);
if (IS_ERR(tve->di_clk)) {
dev_err(tve->dev, "failed to register TVE output clock: %ld\n",
PTR_ERR(tve->di_clk));
return PTR_ERR(tve->di_clk);
}
return 0;
}
static int imx_tve_register(struct imx_tve *tve)
{
int ret;
tve->connector.funcs = &imx_tve_connector_funcs;
tve->encoder.funcs = &imx_tve_encoder_funcs;
tve->encoder.encoder_type = DRM_MODE_ENCODER_NONE;
tve->connector.connector_type = DRM_MODE_CONNECTOR_VGA;
drm_encoder_helper_add(&tve->encoder, &imx_tve_encoder_helper_funcs);
ret = imx_drm_add_encoder(&tve->encoder, &tve->imx_drm_encoder,
THIS_MODULE);
if (ret) {
dev_err(tve->dev, "adding encoder failed with %d\n", ret);
return ret;
}
drm_connector_helper_add(&tve->connector,
&imx_tve_connector_helper_funcs);
ret = imx_drm_add_connector(&tve->connector,
&tve->imx_drm_connector, THIS_MODULE);
if (ret) {
imx_drm_remove_encoder(tve->imx_drm_encoder);
dev_err(tve->dev, "adding connector failed with %d\n", ret);
return ret;
}
drm_mode_connector_attach_encoder(&tve->connector, &tve->encoder);
return 0;
}
static bool imx_tve_readable_reg(struct device *dev, unsigned int reg)
{
return (reg % 4 == 0) && (reg <= 0xdc);
}
const int of_get_tve_mode(struct device_node *np)
{
const char *bm;
int ret, i;
ret = of_property_read_string(np, "fsl,tve-mode", &bm);
if (ret < 0)
return ret;
for (i = 0; i < ARRAY_SIZE(imx_tve_modes); i++)
if (!strcasecmp(bm, imx_tve_modes[i]))
return i;
return -EINVAL;
}
static int imx_tve_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device_node *ddc_node;
struct imx_tve *tve;
struct resource *res;
void __iomem *base;
unsigned int val;
int irq;
int ret;
tve = devm_kzalloc(&pdev->dev, sizeof(*tve), GFP_KERNEL);
if (!tve)
return -ENOMEM;
tve->dev = &pdev->dev;
spin_lock_init(&tve->lock);
spin_lock_init(&tve->enable_lock);
ddc_node = of_parse_phandle(np, "ddc", 0);
if (ddc_node) {
tve->ddc = of_find_i2c_adapter_by_node(ddc_node);
of_node_put(ddc_node);
}
tve->mode = of_get_tve_mode(np);
if (tve->mode != TVE_MODE_VGA) {
dev_err(&pdev->dev, "only VGA mode supported, currently\n");
return -EINVAL;
}
if (tve->mode == TVE_MODE_VGA) {
struct pinctrl *pinctrl;
pinctrl = devm_pinctrl_get_select_default(&pdev->dev);
if (IS_ERR(pinctrl)) {
ret = PTR_ERR(pinctrl);
dev_warn(&pdev->dev, "failed to setup pinctrl: %d", ret);
return ret;
}
ret = of_property_read_u32(np, "fsl,hsync-pin", &tve->hsync_pin);
if (ret < 0) {
dev_err(&pdev->dev, "failed to get vsync pin\n");
return ret;
}
ret |= of_property_read_u32(np, "fsl,vsync-pin", &tve->vsync_pin);
if (ret < 0) {
dev_err(&pdev->dev, "failed to get vsync pin\n");
return ret;
}
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "failed to get memory region\n");
return -ENOENT;
}
base = devm_request_and_ioremap(&pdev->dev, res);
if (!base) {
dev_err(&pdev->dev, "failed to remap memory region\n");
return -ENOENT;
}
tve_regmap_config.lock_arg = tve;
tve->regmap = devm_regmap_init_mmio_clk(&pdev->dev, "tve", base,
&tve_regmap_config);
if (IS_ERR(tve->regmap)) {
dev_err(&pdev->dev, "failed to init regmap: %ld\n",
PTR_ERR(tve->regmap));
return PTR_ERR(tve->regmap);
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "failed to get irq\n");
return irq;
}
ret = devm_request_threaded_irq(&pdev->dev, irq, NULL,
imx_tve_irq_handler, IRQF_ONESHOT,
"imx-tve", tve);
if (ret < 0) {
dev_err(&pdev->dev, "failed to request irq: %d\n", ret);
return ret;
}
tve->dac_reg = devm_regulator_get(&pdev->dev, "dac");
if (!IS_ERR(tve->dac_reg)) {
regulator_set_voltage(tve->dac_reg, 2750000, 2750000);
ret = regulator_enable(tve->dac_reg);
if (ret)
return ret;
}
tve->clk = devm_clk_get(&pdev->dev, "tve");
if (IS_ERR(tve->clk)) {
dev_err(&pdev->dev, "failed to get high speed tve clock: %ld\n",
PTR_ERR(tve->clk));
return PTR_ERR(tve->clk);
}
tve->di_sel_clk = devm_clk_get(&pdev->dev, "di_sel");
if (IS_ERR(tve->di_sel_clk)) {
dev_err(&pdev->dev, "failed to get ipu di mux clock: %ld\n",
PTR_ERR(tve->di_sel_clk));
return PTR_ERR(tve->di_sel_clk);
}
ret = tve_clk_init(tve, base);
if (ret < 0)
return ret;
ret = regmap_read(tve->regmap, TVE_COM_CONF_REG, &val);
if (ret < 0) {
dev_err(&pdev->dev, "failed to read configuration register: %d\n", ret);
return ret;
}
if (val != 0x00100000) {
dev_err(&pdev->dev, "configuration register default value indicates this is not a TVEv2\n");
return -ENODEV;
};
ret = regmap_write(tve->regmap, TVE_CD_CONT_REG, 0);
ret = imx_tve_register(tve);
if (ret)
return ret;
ret = imx_drm_encoder_add_possible_crtcs(tve->imx_drm_encoder, np);
platform_set_drvdata(pdev, tve);
return 0;
}
static int imx_tve_remove(struct platform_device *pdev)
{
struct imx_tve *tve = platform_get_drvdata(pdev);
struct drm_connector *connector = &tve->connector;
struct drm_encoder *encoder = &tve->encoder;
drm_mode_connector_detach_encoder(connector, encoder);
imx_drm_remove_connector(tve->imx_drm_connector);
imx_drm_remove_encoder(tve->imx_drm_encoder);
if (!IS_ERR(tve->dac_reg))
regulator_disable(tve->dac_reg);
return 0;
}
