static inline int dw_hdmi_is_compatible(struct meson_dw_hdmi *dw_hdmi,
const char *compat)
{
return of_device_is_compatible(dw_hdmi->dev->of_node, compat);
}
static unsigned int dw_hdmi_top_read(struct meson_dw_hdmi *dw_hdmi,
unsigned int addr)
{
unsigned long flags;
unsigned int data;
spin_lock_irqsave(&reg_lock, flags);
writel(addr & 0xffff, dw_hdmi->hdmitx + HDMITX_TOP_ADDR_REG);
writel(addr & 0xffff, dw_hdmi->hdmitx + HDMITX_TOP_ADDR_REG);
data = readl(dw_hdmi->hdmitx + HDMITX_TOP_DATA_REG);
data = readl(dw_hdmi->hdmitx + HDMITX_TOP_DATA_REG);
spin_unlock_irqrestore(&reg_lock, flags);
return data;
}
static inline void dw_hdmi_top_write(struct meson_dw_hdmi *dw_hdmi,
unsigned int addr, unsigned int data)
{
unsigned long flags;
spin_lock_irqsave(&reg_lock, flags);
writel(addr & 0xffff, dw_hdmi->hdmitx + HDMITX_TOP_ADDR_REG);
writel(addr & 0xffff, dw_hdmi->hdmitx + HDMITX_TOP_ADDR_REG);
writel(data, dw_hdmi->hdmitx + HDMITX_TOP_DATA_REG);
spin_unlock_irqrestore(&reg_lock, flags);
}
static inline void dw_hdmi_top_write_bits(struct meson_dw_hdmi *dw_hdmi,
unsigned int addr,
unsigned int mask,
unsigned int val)
{
unsigned int data = dw_hdmi_top_read(dw_hdmi, addr);
data &= ~mask;
data |= val;
dw_hdmi_top_write(dw_hdmi, addr, data);
}
static unsigned int dw_hdmi_dwc_read(struct meson_dw_hdmi *dw_hdmi,
unsigned int addr)
{
unsigned long flags;
unsigned int data;
spin_lock_irqsave(&reg_lock, flags);
writel(addr & 0xffff, dw_hdmi->hdmitx + HDMITX_DWC_ADDR_REG);
writel(addr & 0xffff, dw_hdmi->hdmitx + HDMITX_DWC_ADDR_REG);
data = readl(dw_hdmi->hdmitx + HDMITX_DWC_DATA_REG);
data = readl(dw_hdmi->hdmitx + HDMITX_DWC_DATA_REG);
spin_unlock_irqrestore(&reg_lock, flags);
return data;
}
static inline void dw_hdmi_dwc_write(struct meson_dw_hdmi *dw_hdmi,
unsigned int addr, unsigned int data)
{
unsigned long flags;
spin_lock_irqsave(&reg_lock, flags);
writel(addr & 0xffff, dw_hdmi->hdmitx + HDMITX_DWC_ADDR_REG);
writel(addr & 0xffff, dw_hdmi->hdmitx + HDMITX_DWC_ADDR_REG);
writel(data, dw_hdmi->hdmitx + HDMITX_DWC_DATA_REG);
spin_unlock_irqrestore(&reg_lock, flags);
}
static inline void dw_hdmi_dwc_write_bits(struct meson_dw_hdmi *dw_hdmi,
unsigned int addr,
unsigned int mask,
unsigned int val)
{
unsigned int data = dw_hdmi_dwc_read(dw_hdmi, addr);
data &= ~mask;
data |= val;
dw_hdmi_dwc_write(dw_hdmi, addr, data);
}
static void meson_hdmi_phy_setup_mode(struct meson_dw_hdmi *dw_hdmi,
struct drm_display_mode *mode)
{
struct meson_drm *priv = dw_hdmi->priv;
unsigned int pixel_clock = mode->clock;
if (dw_hdmi_is_compatible(dw_hdmi, "amlogic,meson-gxl-dw-hdmi") ||
dw_hdmi_is_compatible(dw_hdmi, "amlogic,meson-gxm-dw-hdmi")) {
if (pixel_clock >= 371250) {
regmap_write(priv->hhi, HHI_HDMI_PHY_CNTL0, 0x333d3282);
regmap_write(priv->hhi, HHI_HDMI_PHY_CNTL3, 0x2136315b);
} else if (pixel_clock >= 297000) {
regmap_write(priv->hhi, HHI_HDMI_PHY_CNTL0, 0x33303382);
regmap_write(priv->hhi, HHI_HDMI_PHY_CNTL3, 0x2036315b);
} else if (pixel_clock >= 148500) {
regmap_write(priv->hhi, HHI_HDMI_PHY_CNTL0, 0x33303362);
regmap_write(priv->hhi, HHI_HDMI_PHY_CNTL3, 0x2016315b);
} else {
regmap_write(priv->hhi, HHI_HDMI_PHY_CNTL0, 0x33604142);
regmap_write(priv->hhi, HHI_HDMI_PHY_CNTL3, 0x0016315b);
}
} else if (dw_hdmi_is_compatible(dw_hdmi,
"amlogic,meson-gxbb-dw-hdmi")) {
if (pixel_clock >= 371250) {
regmap_write(priv->hhi, HHI_HDMI_PHY_CNTL0, 0x33353245);
regmap_write(priv->hhi, HHI_HDMI_PHY_CNTL3, 0x2100115b);
} else if (pixel_clock >= 297000) {
regmap_write(priv->hhi, HHI_HDMI_PHY_CNTL0, 0x33634283);
regmap_write(priv->hhi, HHI_HDMI_PHY_CNTL3, 0xb000115b);
} else {
regmap_write(priv->hhi, HHI_HDMI_PHY_CNTL0, 0x33632122);
regmap_write(priv->hhi, HHI_HDMI_PHY_CNTL3, 0x2000115b);
}
}
}
static inline void dw_hdmi_phy_reset(struct meson_dw_hdmi *dw_hdmi)
{
struct meson_drm *priv = dw_hdmi->priv;
regmap_update_bits(priv->hhi, HHI_HDMI_PHY_CNTL1, 0xf, 0xf);
mdelay(2);
regmap_update_bits(priv->hhi, HHI_HDMI_PHY_CNTL1, 0xf, 0xe);
mdelay(2);
}
static void dw_hdmi_set_vclk(struct meson_dw_hdmi *dw_hdmi,
struct drm_display_mode *mode)
{
struct meson_drm *priv = dw_hdmi->priv;
int vic = drm_match_cea_mode(mode);
unsigned int vclk_freq;
unsigned int venc_freq;
unsigned int hdmi_freq;
vclk_freq = mode->clock;
if (mode->flags & DRM_MODE_FLAG_DBLCLK)
vclk_freq *= 2;
venc_freq = vclk_freq;
hdmi_freq = vclk_freq;
if (meson_venc_hdmi_venc_repeat(vic))
venc_freq *= 2;
vclk_freq = max(venc_freq, hdmi_freq);
if (mode->flags & DRM_MODE_FLAG_DBLCLK)
venc_freq /= 2;
DRM_DEBUG_DRIVER("vclk:%d venc=%d hdmi=%d enci=%d\n",
vclk_freq, venc_freq, hdmi_freq,
priv->venc.hdmi_use_enci);
meson_vclk_setup(priv, MESON_VCLK_TARGET_HDMI, vclk_freq,
venc_freq, hdmi_freq, priv->venc.hdmi_use_enci);
}
static int dw_hdmi_phy_init(struct dw_hdmi *hdmi, void *data,
struct drm_display_mode *mode)
{
struct meson_dw_hdmi *dw_hdmi = (struct meson_dw_hdmi *)data;
struct meson_drm *priv = dw_hdmi->priv;
unsigned int wr_clk =
readl_relaxed(priv->io_base + _REG(VPU_HDMI_SETTING));
DRM_DEBUG_DRIVER("%d:\"%s\"\n", mode->base.id, mode->name);
regmap_update_bits(priv->hhi, HHI_HDMI_CLK_CNTL, 0xffff, 0x100);
regmap_update_bits(priv->hhi, HHI_MEM_PD_REG0, 0xff << 8, 0);
dw_hdmi_top_write(dw_hdmi, HDMITX_TOP_SW_RESET, 0);
dw_hdmi_top_write_bits(dw_hdmi, HDMITX_TOP_CLK_CNTL,
0x3, 0x3);
dw_hdmi_top_write_bits(dw_hdmi, HDMITX_TOP_CLK_CNTL,
0x3 << 4, 0x3 << 4);
dw_hdmi_top_write(dw_hdmi, HDMITX_TOP_BIST_CNTL, BIT(12));
dw_hdmi_top_write(dw_hdmi, HDMITX_TOP_TMDS_CLK_PTTN_01, 0x001f001f);
dw_hdmi_top_write(dw_hdmi, HDMITX_TOP_TMDS_CLK_PTTN_23, 0x001f001f);
dw_hdmi_top_write(dw_hdmi, HDMITX_TOP_TMDS_CLK_PTTN_CNTL, 0x1);
msleep(20);
dw_hdmi_top_write(dw_hdmi, HDMITX_TOP_TMDS_CLK_PTTN_CNTL, 0x2);
meson_hdmi_phy_setup_mode(dw_hdmi, mode);
regmap_update_bits(priv->hhi, HHI_HDMI_PHY_CNTL1,
0xffff << 16, 0x0390 << 16);
if (dw_hdmi_is_compatible(dw_hdmi, "amlogic,meson-gxl-dw-hdmi") ||
dw_hdmi_is_compatible(dw_hdmi, "amlogic,meson-gxm-dw-hdmi"))
regmap_update_bits(priv->hhi, HHI_HDMI_PHY_CNTL1,
BIT(17), 0);
else
regmap_update_bits(priv->hhi, HHI_HDMI_PHY_CNTL1,
BIT(17), BIT(17));
regmap_update_bits(priv->hhi, HHI_HDMI_PHY_CNTL1, 0xf, 0);
msleep(100);
dw_hdmi_phy_reset(dw_hdmi);
dw_hdmi_phy_reset(dw_hdmi);
dw_hdmi_phy_reset(dw_hdmi);
if (priv->venc.hdmi_use_enci)
writel_relaxed(0, priv->io_base + _REG(ENCI_VIDEO_EN));
else
writel_relaxed(0, priv->io_base + _REG(ENCP_VIDEO_EN));
writel_bits_relaxed(0x3, 0,
priv->io_base + _REG(VPU_HDMI_SETTING));
writel_bits_relaxed(0xf << 8, 0,
priv->io_base + _REG(VPU_HDMI_SETTING));
if (priv->venc.hdmi_use_enci)
writel_relaxed(1, priv->io_base + _REG(ENCI_VIDEO_EN));
else
writel_relaxed(1, priv->io_base + _REG(ENCP_VIDEO_EN));
writel_bits_relaxed(0xf << 8, wr_clk & (0xf << 8),
priv->io_base + _REG(VPU_HDMI_SETTING));
if (priv->venc.hdmi_use_enci)
writel_bits_relaxed(0x3, MESON_VENC_SOURCE_ENCI,
priv->io_base + _REG(VPU_HDMI_SETTING));
else
writel_bits_relaxed(0x3, MESON_VENC_SOURCE_ENCP,
priv->io_base + _REG(VPU_HDMI_SETTING));
return 0;
}
static void dw_hdmi_phy_disable(struct dw_hdmi *hdmi,
void *data)
{
struct meson_dw_hdmi *dw_hdmi = (struct meson_dw_hdmi *)data;
struct meson_drm *priv = dw_hdmi->priv;
DRM_DEBUG_DRIVER("\n");
regmap_write(priv->hhi, HHI_HDMI_PHY_CNTL0, 0);
}
static enum drm_connector_status dw_hdmi_read_hpd(struct dw_hdmi *hdmi,
void *data)
{
struct meson_dw_hdmi *dw_hdmi = (struct meson_dw_hdmi *)data;
return !!dw_hdmi_top_read(dw_hdmi, HDMITX_TOP_STAT0) ?
connector_status_connected : connector_status_disconnected;
}
static void dw_hdmi_setup_hpd(struct dw_hdmi *hdmi,
void *data)
{
struct meson_dw_hdmi *dw_hdmi = (struct meson_dw_hdmi *)data;
dw_hdmi_top_write(dw_hdmi, HDMITX_TOP_HPD_FILTER,
(0xa << 12) | 0xa0);
dw_hdmi_top_write(dw_hdmi, HDMITX_TOP_INTR_STAT_CLR,
HDMITX_TOP_INTR_HPD_RISE | HDMITX_TOP_INTR_HPD_FALL);
dw_hdmi_top_write_bits(dw_hdmi, HDMITX_TOP_INTR_MASKN,
HDMITX_TOP_INTR_HPD_RISE | HDMITX_TOP_INTR_HPD_FALL,
HDMITX_TOP_INTR_HPD_RISE | HDMITX_TOP_INTR_HPD_FALL);
}
static irqreturn_t dw_hdmi_top_irq(int irq, void *dev_id)
{
struct meson_dw_hdmi *dw_hdmi = dev_id;
u32 stat;
stat = dw_hdmi_top_read(dw_hdmi, HDMITX_TOP_INTR_STAT);
dw_hdmi_top_write(dw_hdmi, HDMITX_TOP_INTR_STAT_CLR, stat);
if (stat & (HDMITX_TOP_INTR_HPD_RISE | HDMITX_TOP_INTR_HPD_FALL)) {
dw_hdmi->irq_stat = stat;
return IRQ_WAKE_THREAD;
}
if (stat & 1)
return IRQ_NONE;
return IRQ_HANDLED;
}
static irqreturn_t dw_hdmi_top_thread_irq(int irq, void *dev_id)
{
struct meson_dw_hdmi *dw_hdmi = dev_id;
u32 stat = dw_hdmi->irq_stat;
if (stat & (HDMITX_TOP_INTR_HPD_RISE | HDMITX_TOP_INTR_HPD_FALL)) {
bool hpd_connected = false;
if (stat & HDMITX_TOP_INTR_HPD_RISE)
hpd_connected = true;
dw_hdmi_setup_rx_sense(dw_hdmi->dev, hpd_connected,
hpd_connected);
drm_helper_hpd_irq_event(dw_hdmi->encoder.dev);
}
return IRQ_HANDLED;
}
static enum drm_mode_status
dw_hdmi_mode_valid(struct drm_connector *connector,
const struct drm_display_mode *mode)
{
unsigned int vclk_freq;
unsigned int venc_freq;
unsigned int hdmi_freq;
int vic = drm_match_cea_mode(mode);
DRM_DEBUG_DRIVER("Modeline %d:\"%s\" %d %d %d %d %d %d %d %d %d %d 0x%x 0x%x\n",
mode->base.id, mode->name, mode->vrefresh, mode->clock,
mode->hdisplay, mode->hsync_start,
mode->hsync_end, mode->htotal,
mode->vdisplay, mode->vsync_start,
mode->vsync_end, mode->vtotal, mode->type, mode->flags);
if (!vic)
return MODE_BAD;
if (!meson_venc_hdmi_supported_vic(vic))
return MODE_BAD;
vclk_freq = mode->clock;
if (mode->flags & DRM_MODE_FLAG_DBLCLK)
vclk_freq *= 2;
venc_freq = vclk_freq;
hdmi_freq = vclk_freq;
if (meson_venc_hdmi_venc_repeat(vic))
venc_freq *= 2;
vclk_freq = max(venc_freq, hdmi_freq);
if (mode->flags & DRM_MODE_FLAG_DBLCLK)
venc_freq /= 2;
dev_dbg(connector->dev->dev, "%s: vclk:%d venc=%d hdmi=%d\n", __func__,
vclk_freq, venc_freq, hdmi_freq);
switch (vclk_freq) {
case 54000:
case 74250:
case 148500:
case 297000:
case 594000:
return MODE_OK;
}
return MODE_CLOCK_RANGE;
}
static void meson_venc_hdmi_encoder_destroy(struct drm_encoder *encoder)
{
drm_encoder_cleanup(encoder);
}
static int meson_venc_hdmi_encoder_atomic_check(struct drm_encoder *encoder,
struct drm_crtc_state *crtc_state,
struct drm_connector_state *conn_state)
{
return 0;
}
static void meson_venc_hdmi_encoder_disable(struct drm_encoder *encoder)
{
struct meson_dw_hdmi *dw_hdmi = encoder_to_meson_dw_hdmi(encoder);
struct meson_drm *priv = dw_hdmi->priv;
DRM_DEBUG_DRIVER("\n");
writel_bits_relaxed(0x3, 0,
priv->io_base + _REG(VPU_HDMI_SETTING));
writel_relaxed(0, priv->io_base + _REG(ENCI_VIDEO_EN));
writel_relaxed(0, priv->io_base + _REG(ENCP_VIDEO_EN));
}
static void meson_venc_hdmi_encoder_enable(struct drm_encoder *encoder)
{
struct meson_dw_hdmi *dw_hdmi = encoder_to_meson_dw_hdmi(encoder);
struct meson_drm *priv = dw_hdmi->priv;
DRM_DEBUG_DRIVER("%s\n", priv->venc.hdmi_use_enci ? "VENCI" : "VENCP");
if (priv->venc.hdmi_use_enci)
writel_relaxed(1, priv->io_base + _REG(ENCI_VIDEO_EN));
else
writel_relaxed(1, priv->io_base + _REG(ENCP_VIDEO_EN));
}
static void meson_venc_hdmi_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct meson_dw_hdmi *dw_hdmi = encoder_to_meson_dw_hdmi(encoder);
struct meson_drm *priv = dw_hdmi->priv;
int vic = drm_match_cea_mode(mode);
DRM_DEBUG_DRIVER("%d:\"%s\" vic %d\n",
mode->base.id, mode->name, vic);
if (!vic)
return;
meson_venc_hdmi_mode_set(priv, vic, mode);
dw_hdmi_set_vclk(dw_hdmi, mode);
writel_relaxed(0, priv->io_base + _REG(VPU_HDMI_FMT_CTRL));
}
static int meson_dw_hdmi_reg_read(void *context, unsigned int reg,
unsigned int *result)
{
*result = dw_hdmi_dwc_read(context, reg);
return 0;
}
static int meson_dw_hdmi_reg_write(void *context, unsigned int reg,
unsigned int val)
{
dw_hdmi_dwc_write(context, reg, val);
return 0;
}
static bool meson_hdmi_connector_is_available(struct device *dev)
{
struct device_node *ep, *remote;
ep = of_graph_get_endpoint_by_regs(dev->of_node, 1, 0);
if (!ep)
return false;
remote = of_graph_get_remote_port(ep);
if (remote) {
of_node_put(ep);
return true;
}
of_node_put(ep);
of_node_put(remote);
return false;
}
static int meson_dw_hdmi_bind(struct device *dev, struct device *master,
void *data)
{
struct platform_device *pdev = to_platform_device(dev);
struct meson_dw_hdmi *meson_dw_hdmi;
struct drm_device *drm = data;
struct meson_drm *priv = drm->dev_private;
struct dw_hdmi_plat_data *dw_plat_data;
struct drm_encoder *encoder;
struct resource *res;
int irq;
int ret;
DRM_DEBUG_DRIVER("\n");
if (!meson_hdmi_connector_is_available(dev)) {
dev_info(drm->dev, "HDMI Output connector not available\n");
return -ENODEV;
}
meson_dw_hdmi = devm_kzalloc(dev, sizeof(*meson_dw_hdmi),
GFP_KERNEL);
if (!meson_dw_hdmi)
return -ENOMEM;
meson_dw_hdmi->priv = priv;
meson_dw_hdmi->dev = dev;
dw_plat_data = &meson_dw_hdmi->dw_plat_data;
encoder = &meson_dw_hdmi->encoder;
meson_dw_hdmi->hdmitx_apb = devm_reset_control_get_exclusive(dev,
"hdmitx_apb");
if (IS_ERR(meson_dw_hdmi->hdmitx_apb)) {
dev_err(dev, "Failed to get hdmitx_apb reset\n");
return PTR_ERR(meson_dw_hdmi->hdmitx_apb);
}
meson_dw_hdmi->hdmitx_ctrl = devm_reset_control_get_exclusive(dev,
"hdmitx");
if (IS_ERR(meson_dw_hdmi->hdmitx_ctrl)) {
dev_err(dev, "Failed to get hdmitx reset\n");
return PTR_ERR(meson_dw_hdmi->hdmitx_ctrl);
}
meson_dw_hdmi->hdmitx_phy = devm_reset_control_get_exclusive(dev,
"hdmitx_phy");
if (IS_ERR(meson_dw_hdmi->hdmitx_phy)) {
dev_err(dev, "Failed to get hdmitx_phy reset\n");
return PTR_ERR(meson_dw_hdmi->hdmitx_phy);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
meson_dw_hdmi->hdmitx = devm_ioremap_resource(dev, res);
if (IS_ERR(meson_dw_hdmi->hdmitx))
return PTR_ERR(meson_dw_hdmi->hdmitx);
meson_dw_hdmi->hdmi_pclk = devm_clk_get(dev, "isfr");
if (IS_ERR(meson_dw_hdmi->hdmi_pclk)) {
dev_err(dev, "Unable to get HDMI pclk\n");
return PTR_ERR(meson_dw_hdmi->hdmi_pclk);
}
clk_prepare_enable(meson_dw_hdmi->hdmi_pclk);
meson_dw_hdmi->venci_clk = devm_clk_get(dev, "venci");
if (IS_ERR(meson_dw_hdmi->venci_clk)) {
dev_err(dev, "Unable to get venci clk\n");
return PTR_ERR(meson_dw_hdmi->venci_clk);
}
clk_prepare_enable(meson_dw_hdmi->venci_clk);
dw_plat_data->regm = devm_regmap_init(dev, NULL, meson_dw_hdmi,
&meson_dw_hdmi_regmap_config);
if (IS_ERR(dw_plat_data->regm))
return PTR_ERR(dw_plat_data->regm);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "Failed to get hdmi top irq\n");
return irq;
}
ret = devm_request_threaded_irq(dev, irq, dw_hdmi_top_irq,
dw_hdmi_top_thread_irq, IRQF_SHARED,
"dw_hdmi_top_irq", meson_dw_hdmi);
if (ret) {
dev_err(dev, "Failed to request hdmi top irq\n");
return ret;
}
drm_encoder_helper_add(encoder, &meson_venc_hdmi_encoder_helper_funcs);
ret = drm_encoder_init(drm, encoder, &meson_venc_hdmi_encoder_funcs,
DRM_MODE_ENCODER_TMDS, "meson_hdmi");
if (ret) {
dev_err(priv->dev, "Failed to init HDMI encoder\n");
return ret;
}
encoder->possible_crtcs = BIT(0);
DRM_DEBUG_DRIVER("encoder initialized\n");
regmap_update_bits(priv->hhi, HHI_HDMI_CLK_CNTL, 0xffff, 0x100);
regmap_update_bits(priv->hhi, HHI_MEM_PD_REG0, 0xff << 8, 0);
reset_control_reset(meson_dw_hdmi->hdmitx_apb);
reset_control_reset(meson_dw_hdmi->hdmitx_ctrl);
reset_control_reset(meson_dw_hdmi->hdmitx_phy);
writel_bits_relaxed(BIT(15), BIT(15),
meson_dw_hdmi->hdmitx + HDMITX_TOP_CTRL_REG);
writel_bits_relaxed(BIT(15), BIT(15),
meson_dw_hdmi->hdmitx + HDMITX_DWC_CTRL_REG);
dw_hdmi_top_write(meson_dw_hdmi, HDMITX_TOP_SW_RESET, 0);
msleep(20);
dw_hdmi_top_write(meson_dw_hdmi, HDMITX_TOP_CLK_CNTL, 0xff);
dw_hdmi_top_write(meson_dw_hdmi, HDMITX_TOP_INTR_STAT_CLR,
HDMITX_TOP_INTR_CORE);
dw_hdmi_top_write(meson_dw_hdmi, HDMITX_TOP_INTR_MASKN,
HDMITX_TOP_INTR_CORE);
dw_plat_data->mode_valid = dw_hdmi_mode_valid;
dw_plat_data->phy_ops = &meson_dw_hdmi_phy_ops;
dw_plat_data->phy_name = "meson_dw_hdmi_phy";
dw_plat_data->phy_data = meson_dw_hdmi;
dw_plat_data->input_bus_format = MEDIA_BUS_FMT_YUV8_1X24;
dw_plat_data->input_bus_encoding = V4L2_YCBCR_ENC_709;
ret = dw_hdmi_bind(pdev, encoder, &meson_dw_hdmi->dw_plat_data);
if (ret)
return ret;
DRM_DEBUG_DRIVER("HDMI controller initialized\n");
return 0;
}
static void meson_dw_hdmi_unbind(struct device *dev, struct device *master,
void *data)
{
dw_hdmi_unbind(dev);
}
static int meson_dw_hdmi_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &meson_dw_hdmi_ops);
}
static int meson_dw_hdmi_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &meson_dw_hdmi_ops);
return 0;
}
