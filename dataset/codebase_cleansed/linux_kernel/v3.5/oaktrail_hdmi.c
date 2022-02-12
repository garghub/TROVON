static void oaktrail_hdmi_audio_enable(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct oaktrail_hdmi_dev *hdmi_dev = dev_priv->hdmi_priv;
HDMI_WRITE(HDMI_HCR, 0x67);
HDMI_READ(HDMI_HCR);
HDMI_WRITE(0x51a8, 0x10);
HDMI_READ(0x51a8);
HDMI_WRITE(HDMI_AUDIO_CTRL, 0x1);
HDMI_READ(HDMI_AUDIO_CTRL);
}
static void oaktrail_hdmi_audio_disable(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct oaktrail_hdmi_dev *hdmi_dev = dev_priv->hdmi_priv;
HDMI_WRITE(0x51a8, 0x0);
HDMI_READ(0x51a8);
HDMI_WRITE(HDMI_AUDIO_CTRL, 0x0);
HDMI_READ(HDMI_AUDIO_CTRL);
HDMI_WRITE(HDMI_HCR, 0x47);
HDMI_READ(HDMI_HCR);
}
static void oaktrail_hdmi_dpms(struct drm_encoder *encoder, int mode)
{
static int dpms_mode = -1;
struct drm_device *dev = encoder->dev;
struct drm_psb_private *dev_priv = dev->dev_private;
struct oaktrail_hdmi_dev *hdmi_dev = dev_priv->hdmi_priv;
u32 temp;
if (dpms_mode == mode)
return;
if (mode != DRM_MODE_DPMS_ON)
temp = 0x0;
else
temp = 0x99;
dpms_mode = mode;
HDMI_WRITE(HDMI_VIDEO_REG, temp);
}
static int oaktrail_hdmi_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
if (mode->clock > 165000)
return MODE_CLOCK_HIGH;
if (mode->clock < 20000)
return MODE_CLOCK_LOW;
if (mode->flags & DRM_MODE_FLAG_DBLSCAN)
return MODE_NO_DBLESCAN;
return MODE_OK;
}
static bool oaktrail_hdmi_mode_fixup(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static enum drm_connector_status
oaktrail_hdmi_detect(struct drm_connector *connector, bool force)
{
enum drm_connector_status status;
struct drm_device *dev = connector->dev;
struct drm_psb_private *dev_priv = dev->dev_private;
struct oaktrail_hdmi_dev *hdmi_dev = dev_priv->hdmi_priv;
u32 temp;
temp = HDMI_READ(HDMI_HSR);
DRM_DEBUG_KMS("HDMI_HSR %x\n", temp);
if ((temp & HDMI_DETECT_HDP) != 0)
status = connector_status_connected;
else
status = connector_status_disconnected;
return status;
}
static int oaktrail_hdmi_get_modes(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct drm_psb_private *dev_priv = dev->dev_private;
struct i2c_adapter *i2c_adap;
struct edid *edid;
struct drm_display_mode *mode, *t;
int i = 0, ret = 0;
i2c_adap = i2c_get_adapter(3);
if (i2c_adap == NULL) {
DRM_ERROR("No ddc adapter available!\n");
edid = (struct edid *)raw_edid;
} else {
edid = (struct edid *)raw_edid;
}
if (edid) {
drm_mode_connector_update_edid_property(connector, edid);
ret = drm_add_edid_modes(connector, edid);
connector->display_info.raw_edid = NULL;
}
list_for_each_entry_safe(mode, t, &connector->probed_modes, head) {
if ((mode->hdisplay * mode->vdisplay * 4) >= dev_priv->vram_stolen_size) {
i++;
drm_mode_remove(connector, mode);
}
}
return ret - i;
}
static void oaktrail_hdmi_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = encoder->dev;
oaktrail_hdmi_audio_enable(dev);
return;
}
static void oaktrail_hdmi_destroy(struct drm_connector *connector)
{
return;
}
static void oaktrail_hdmi_enc_destroy(struct drm_encoder *encoder)
{
drm_encoder_cleanup(encoder);
}
void oaktrail_hdmi_init(struct drm_device *dev,
struct psb_intel_mode_device *mode_dev)
{
struct psb_intel_encoder *psb_intel_encoder;
struct psb_intel_connector *psb_intel_connector;
struct drm_connector *connector;
struct drm_encoder *encoder;
psb_intel_encoder = kzalloc(sizeof(struct psb_intel_encoder), GFP_KERNEL);
if (!psb_intel_encoder)
return;
psb_intel_connector = kzalloc(sizeof(struct psb_intel_connector), GFP_KERNEL);
if (!psb_intel_connector)
goto failed_connector;
connector = &psb_intel_connector->base;
encoder = &psb_intel_encoder->base;
drm_connector_init(dev, connector,
&oaktrail_hdmi_connector_funcs,
DRM_MODE_CONNECTOR_DVID);
drm_encoder_init(dev, encoder,
&oaktrail_hdmi_enc_funcs,
DRM_MODE_ENCODER_TMDS);
psb_intel_connector_attach_encoder(psb_intel_connector,
psb_intel_encoder);
psb_intel_encoder->type = INTEL_OUTPUT_HDMI;
drm_encoder_helper_add(encoder, &oaktrail_hdmi_helper_funcs);
drm_connector_helper_add(connector, &oaktrail_hdmi_connector_helper_funcs);
connector->display_info.subpixel_order = SubPixelHorizontalRGB;
connector->interlace_allowed = false;
connector->doublescan_allowed = false;
drm_sysfs_connector_add(connector);
return;
failed_connector:
kfree(psb_intel_encoder);
}
void oaktrail_hdmi_setup(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct pci_dev *pdev;
struct oaktrail_hdmi_dev *hdmi_dev;
int ret;
pdev = pci_get_device(PCI_VENDOR_ID_INTEL, 0x080d, NULL);
if (!pdev)
return;
hdmi_dev = kzalloc(sizeof(struct oaktrail_hdmi_dev), GFP_KERNEL);
if (!hdmi_dev) {
dev_err(dev->dev, "failed to allocate memory\n");
goto out;
}
ret = pci_enable_device(pdev);
if (ret) {
dev_err(dev->dev, "failed to enable hdmi controller\n");
goto free;
}
hdmi_dev->mmio = pci_resource_start(pdev, 0);
hdmi_dev->mmio_len = pci_resource_len(pdev, 0);
hdmi_dev->regs = ioremap(hdmi_dev->mmio, hdmi_dev->mmio_len);
if (!hdmi_dev->regs) {
dev_err(dev->dev, "failed to map hdmi mmio\n");
goto free;
}
hdmi_dev->dev = pdev;
pci_set_drvdata(pdev, hdmi_dev);
ret = oaktrail_hdmi_i2c_init(hdmi_dev->dev);
if (ret)
dev_err(dev->dev, "HDMI I2C initialization failed\n");
dev_priv->hdmi_priv = hdmi_dev;
oaktrail_hdmi_audio_disable(dev);
return;
free:
kfree(hdmi_dev);
out:
return;
}
void oaktrail_hdmi_teardown(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct oaktrail_hdmi_dev *hdmi_dev = dev_priv->hdmi_priv;
struct pci_dev *pdev;
if (hdmi_dev) {
pdev = hdmi_dev->dev;
pci_set_drvdata(pdev, NULL);
oaktrail_hdmi_i2c_exit(pdev);
iounmap(hdmi_dev->regs);
kfree(hdmi_dev);
pci_dev_put(pdev);
}
}
void oaktrail_hdmi_save(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct oaktrail_hdmi_dev *hdmi_dev = dev_priv->hdmi_priv;
struct psb_state *regs = &dev_priv->regs.psb;
struct psb_pipe *pipeb = &dev_priv->regs.pipe[1];
int i;
hdmi_dev->saveDPLL_CTRL = PSB_RVDC32(DPLL_CTRL);
hdmi_dev->saveDPLL_DIV_CTRL = PSB_RVDC32(DPLL_DIV_CTRL);
hdmi_dev->saveDPLL_ADJUST = PSB_RVDC32(DPLL_ADJUST);
hdmi_dev->saveDPLL_UPDATE = PSB_RVDC32(DPLL_UPDATE);
hdmi_dev->saveDPLL_CLK_ENABLE = PSB_RVDC32(DPLL_CLK_ENABLE);
pipeb->conf = PSB_RVDC32(PIPEBCONF);
pipeb->src = PSB_RVDC32(PIPEBSRC);
pipeb->htotal = PSB_RVDC32(HTOTAL_B);
pipeb->hblank = PSB_RVDC32(HBLANK_B);
pipeb->hsync = PSB_RVDC32(HSYNC_B);
pipeb->vtotal = PSB_RVDC32(VTOTAL_B);
pipeb->vblank = PSB_RVDC32(VBLANK_B);
pipeb->vsync = PSB_RVDC32(VSYNC_B);
hdmi_dev->savePCH_PIPEBCONF = PSB_RVDC32(PCH_PIPEBCONF);
hdmi_dev->savePCH_PIPEBSRC = PSB_RVDC32(PCH_PIPEBSRC);
hdmi_dev->savePCH_HTOTAL_B = PSB_RVDC32(PCH_HTOTAL_B);
hdmi_dev->savePCH_HBLANK_B = PSB_RVDC32(PCH_HBLANK_B);
hdmi_dev->savePCH_HSYNC_B = PSB_RVDC32(PCH_HSYNC_B);
hdmi_dev->savePCH_VTOTAL_B = PSB_RVDC32(PCH_VTOTAL_B);
hdmi_dev->savePCH_VBLANK_B = PSB_RVDC32(PCH_VBLANK_B);
hdmi_dev->savePCH_VSYNC_B = PSB_RVDC32(PCH_VSYNC_B);
pipeb->cntr = PSB_RVDC32(DSPBCNTR);
pipeb->stride = PSB_RVDC32(DSPBSTRIDE);
pipeb->addr = PSB_RVDC32(DSPBBASE);
pipeb->surf = PSB_RVDC32(DSPBSURF);
pipeb->linoff = PSB_RVDC32(DSPBLINOFF);
pipeb->tileoff = PSB_RVDC32(DSPBTILEOFF);
regs->saveDSPBCURSOR_CTRL = PSB_RVDC32(CURBCNTR);
regs->saveDSPBCURSOR_BASE = PSB_RVDC32(CURBBASE);
regs->saveDSPBCURSOR_POS = PSB_RVDC32(CURBPOS);
for (i = 0; i < 256; i++)
pipeb->palette[i] = PSB_RVDC32(PALETTE_B + (i << 2));
}
void oaktrail_hdmi_restore(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct oaktrail_hdmi_dev *hdmi_dev = dev_priv->hdmi_priv;
struct psb_state *regs = &dev_priv->regs.psb;
struct psb_pipe *pipeb = &dev_priv->regs.pipe[1];
int i;
PSB_WVDC32(hdmi_dev->saveDPLL_CTRL, DPLL_CTRL);
PSB_WVDC32(hdmi_dev->saveDPLL_DIV_CTRL, DPLL_DIV_CTRL);
PSB_WVDC32(hdmi_dev->saveDPLL_ADJUST, DPLL_ADJUST);
PSB_WVDC32(hdmi_dev->saveDPLL_UPDATE, DPLL_UPDATE);
PSB_WVDC32(hdmi_dev->saveDPLL_CLK_ENABLE, DPLL_CLK_ENABLE);
DRM_UDELAY(150);
PSB_WVDC32(pipeb->src, PIPEBSRC);
PSB_WVDC32(pipeb->htotal, HTOTAL_B);
PSB_WVDC32(pipeb->hblank, HBLANK_B);
PSB_WVDC32(pipeb->hsync, HSYNC_B);
PSB_WVDC32(pipeb->vtotal, VTOTAL_B);
PSB_WVDC32(pipeb->vblank, VBLANK_B);
PSB_WVDC32(pipeb->vsync, VSYNC_B);
PSB_WVDC32(hdmi_dev->savePCH_PIPEBSRC, PCH_PIPEBSRC);
PSB_WVDC32(hdmi_dev->savePCH_HTOTAL_B, PCH_HTOTAL_B);
PSB_WVDC32(hdmi_dev->savePCH_HBLANK_B, PCH_HBLANK_B);
PSB_WVDC32(hdmi_dev->savePCH_HSYNC_B, PCH_HSYNC_B);
PSB_WVDC32(hdmi_dev->savePCH_VTOTAL_B, PCH_VTOTAL_B);
PSB_WVDC32(hdmi_dev->savePCH_VBLANK_B, PCH_VBLANK_B);
PSB_WVDC32(hdmi_dev->savePCH_VSYNC_B, PCH_VSYNC_B);
PSB_WVDC32(pipeb->conf, PIPEBCONF);
PSB_WVDC32(hdmi_dev->savePCH_PIPEBCONF, PCH_PIPEBCONF);
PSB_WVDC32(pipeb->linoff, DSPBLINOFF);
PSB_WVDC32(pipeb->stride, DSPBSTRIDE);
PSB_WVDC32(pipeb->tileoff, DSPBTILEOFF);
PSB_WVDC32(pipeb->cntr, DSPBCNTR);
PSB_WVDC32(pipeb->surf, DSPBSURF);
PSB_WVDC32(regs->saveDSPBCURSOR_CTRL, CURBCNTR);
PSB_WVDC32(regs->saveDSPBCURSOR_POS, CURBPOS);
PSB_WVDC32(regs->saveDSPBCURSOR_BASE, CURBBASE);
for (i = 0; i < 256; i++)
PSB_WVDC32(pipeb->palette[i], PALETTE_B + (i << 2));
}
