static void mrst_lvds_set_power(struct drm_device *dev,
struct psb_intel_output *output, bool on)
{
u32 pp_status;
struct drm_psb_private *dev_priv = dev->dev_private;
if (!gma_power_begin(dev, true))
return;
if (on) {
REG_WRITE(PP_CONTROL, REG_READ(PP_CONTROL) |
POWER_TARGET_ON);
do {
pp_status = REG_READ(PP_STATUS);
} while ((pp_status & (PP_ON | PP_READY)) == PP_READY);
dev_priv->is_lvds_on = true;
if (dev_priv->ops->lvds_bl_power)
dev_priv->ops->lvds_bl_power(dev, true);
} else {
if (dev_priv->ops->lvds_bl_power)
dev_priv->ops->lvds_bl_power(dev, false);
REG_WRITE(PP_CONTROL, REG_READ(PP_CONTROL) &
~POWER_TARGET_ON);
do {
pp_status = REG_READ(PP_STATUS);
} while (pp_status & PP_ON);
dev_priv->is_lvds_on = false;
pm_request_idle(&dev->pdev->dev);
}
gma_power_end(dev);
}
static void mrst_lvds_dpms(struct drm_encoder *encoder, int mode)
{
struct drm_device *dev = encoder->dev;
struct psb_intel_output *output = enc_to_psb_intel_output(encoder);
if (mode == DRM_MODE_DPMS_ON)
mrst_lvds_set_power(dev, output, true);
else
mrst_lvds_set_power(dev, output, false);
}
static void mrst_lvds_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct psb_intel_mode_device *mode_dev =
enc_to_psb_intel_output(encoder)->mode_dev;
struct drm_device *dev = encoder->dev;
struct drm_psb_private *dev_priv = dev->dev_private;
u32 lvds_port;
uint64_t v = DRM_MODE_SCALE_FULLSCREEN;
if (!gma_power_begin(dev, true))
return;
lvds_port = (REG_READ(LVDS) &
(~LVDS_PIPEB_SELECT)) |
LVDS_PORT_EN |
LVDS_BORDER_EN;
if (mode_dev->panel_wants_dither || dev_priv->lvds_dither)
lvds_port |= MRST_PANEL_8TO6_DITHER_ENABLE;
REG_WRITE(LVDS, lvds_port);
drm_connector_property_get_value(
&enc_to_psb_intel_output(encoder)->base,
dev->mode_config.scaling_mode_property,
&v);
if (v == DRM_MODE_SCALE_NO_SCALE)
REG_WRITE(PFIT_CONTROL, 0);
else if (v == DRM_MODE_SCALE_ASPECT) {
if ((mode->vdisplay != adjusted_mode->crtc_vdisplay) ||
(mode->hdisplay != adjusted_mode->crtc_hdisplay)) {
if ((adjusted_mode->crtc_hdisplay * mode->vdisplay) ==
(mode->hdisplay * adjusted_mode->crtc_vdisplay))
REG_WRITE(PFIT_CONTROL, PFIT_ENABLE);
else if ((adjusted_mode->crtc_hdisplay *
mode->vdisplay) > (mode->hdisplay *
adjusted_mode->crtc_vdisplay))
REG_WRITE(PFIT_CONTROL, PFIT_ENABLE |
PFIT_SCALING_MODE_PILLARBOX);
else
REG_WRITE(PFIT_CONTROL, PFIT_ENABLE |
PFIT_SCALING_MODE_LETTERBOX);
} else
REG_WRITE(PFIT_CONTROL, PFIT_ENABLE);
} else
REG_WRITE(PFIT_CONTROL, PFIT_ENABLE);
gma_power_end(dev);
}
static void mrst_lvds_prepare(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct psb_intel_output *output = enc_to_psb_intel_output(encoder);
struct psb_intel_mode_device *mode_dev = output->mode_dev;
if (!gma_power_begin(dev, true))
return;
mode_dev->saveBLC_PWM_CTL = REG_READ(BLC_PWM_CTL);
mode_dev->backlight_duty_cycle = (mode_dev->saveBLC_PWM_CTL &
BACKLIGHT_DUTY_CYCLE_MASK);
mrst_lvds_set_power(dev, output, false);
gma_power_end(dev);
}
static u32 mrst_lvds_get_max_backlight(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
u32 ret;
if (gma_power_begin(dev, false)) {
ret = ((REG_READ(BLC_PWM_CTL) &
BACKLIGHT_MODULATION_FREQ_MASK) >>
BACKLIGHT_MODULATION_FREQ_SHIFT) * 2;
gma_power_end(dev);
} else
ret = ((dev_priv->saveBLC_PWM_CTL &
BACKLIGHT_MODULATION_FREQ_MASK) >>
BACKLIGHT_MODULATION_FREQ_SHIFT) * 2;
return ret;
}
static void mrst_lvds_commit(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct psb_intel_output *output = enc_to_psb_intel_output(encoder);
struct psb_intel_mode_device *mode_dev = output->mode_dev;
if (mode_dev->backlight_duty_cycle == 0)
mode_dev->backlight_duty_cycle =
mrst_lvds_get_max_backlight(dev);
mrst_lvds_set_power(dev, output, true);
}
static struct drm_display_mode *
mrst_lvds_get_configuration_mode(struct drm_device *dev)
{
struct drm_display_mode *mode = NULL;
struct drm_psb_private *dev_priv = dev->dev_private;
struct mrst_timing_info *ti = &dev_priv->gct_data.DTD;
if (dev_priv->vbt_data.size != 0x00) {
mode = kzalloc(sizeof(*mode), GFP_KERNEL);
if (!mode)
return NULL;
mode->hdisplay = (ti->hactive_hi << 8) | ti->hactive_lo;
mode->vdisplay = (ti->vactive_hi << 8) | ti->vactive_lo;
mode->hsync_start = mode->hdisplay + \
((ti->hsync_offset_hi << 8) | \
ti->hsync_offset_lo);
mode->hsync_end = mode->hsync_start + \
((ti->hsync_pulse_width_hi << 8) | \
ti->hsync_pulse_width_lo);
mode->htotal = mode->hdisplay + ((ti->hblank_hi << 8) | \
ti->hblank_lo);
mode->vsync_start = \
mode->vdisplay + ((ti->vsync_offset_hi << 4) | \
ti->vsync_offset_lo);
mode->vsync_end = \
mode->vsync_start + ((ti->vsync_pulse_width_hi << 4) | \
ti->vsync_pulse_width_lo);
mode->vtotal = mode->vdisplay + \
((ti->vblank_hi << 8) | ti->vblank_lo);
mode->clock = ti->pixel_clock * 10;
#if 0
printk(KERN_INFO "hdisplay is %d\n", mode->hdisplay);
printk(KERN_INFO "vdisplay is %d\n", mode->vdisplay);
printk(KERN_INFO "HSS is %d\n", mode->hsync_start);
printk(KERN_INFO "HSE is %d\n", mode->hsync_end);
printk(KERN_INFO "htotal is %d\n", mode->htotal);
printk(KERN_INFO "VSS is %d\n", mode->vsync_start);
printk(KERN_INFO "VSE is %d\n", mode->vsync_end);
printk(KERN_INFO "vtotal is %d\n", mode->vtotal);
printk(KERN_INFO "clock is %d\n", mode->clock);
#endif
} else
mode = drm_mode_duplicate(dev, &lvds_configuration_modes[2]);
drm_mode_set_name(mode);
drm_mode_set_crtcinfo(mode, 0);
return mode;
}
void mrst_lvds_init(struct drm_device *dev,
struct psb_intel_mode_device *mode_dev)
{
struct psb_intel_output *psb_intel_output;
struct drm_connector *connector;
struct drm_encoder *encoder;
struct drm_psb_private *dev_priv =
(struct drm_psb_private *) dev->dev_private;
struct edid *edid;
int ret = 0;
struct i2c_adapter *i2c_adap;
struct drm_display_mode *scan;
psb_intel_output = kzalloc(sizeof(struct psb_intel_output), GFP_KERNEL);
if (!psb_intel_output)
return;
psb_intel_output->mode_dev = mode_dev;
connector = &psb_intel_output->base;
encoder = &psb_intel_output->enc;
dev_priv->is_lvds_on = true;
drm_connector_init(dev, &psb_intel_output->base,
&psb_intel_lvds_connector_funcs,
DRM_MODE_CONNECTOR_LVDS);
drm_encoder_init(dev, &psb_intel_output->enc, &psb_intel_lvds_enc_funcs,
DRM_MODE_ENCODER_LVDS);
drm_mode_connector_attach_encoder(&psb_intel_output->base,
&psb_intel_output->enc);
psb_intel_output->type = INTEL_OUTPUT_LVDS;
drm_encoder_helper_add(encoder, &mrst_lvds_helper_funcs);
drm_connector_helper_add(connector,
&psb_intel_lvds_connector_helper_funcs);
connector->display_info.subpixel_order = SubPixelHorizontalRGB;
connector->interlace_allowed = false;
connector->doublescan_allowed = false;
drm_connector_attach_property(connector,
dev->mode_config.scaling_mode_property,
DRM_MODE_SCALE_FULLSCREEN);
drm_connector_attach_property(connector,
dev_priv->backlight_property,
BRIGHTNESS_MAX_LEVEL);
mode_dev->panel_wants_dither = false;
if (dev_priv->vbt_data.size != 0x00)
mode_dev->panel_wants_dither = (dev_priv->gct_data.
Panel_Port_Control & MRST_PANEL_8TO6_DITHER_ENABLE);
i2c_adap = i2c_get_adapter(dev_priv->ops->i2c_bus);
if (i2c_adap == NULL)
dev_err(dev->dev, "No ddc adapter available!\n");
if (i2c_adap) {
edid = drm_get_edid(connector, i2c_adap);
if (edid) {
drm_mode_connector_update_edid_property(connector,
edid);
ret = drm_add_edid_modes(connector, edid);
kfree(edid);
}
list_for_each_entry(scan, &connector->probed_modes, head) {
if (scan->type & DRM_MODE_TYPE_PREFERRED) {
mode_dev->panel_fixed_mode =
drm_mode_duplicate(dev, scan);
goto out;
}
}
}
mode_dev->panel_fixed_mode = mrst_lvds_get_configuration_mode(dev);
if (mode_dev->panel_fixed_mode) {
mode_dev->panel_fixed_mode->type |= DRM_MODE_TYPE_PREFERRED;
goto out;
}
if (!mode_dev->panel_fixed_mode) {
dev_err(dev->dev, "Found no modes on the lvds, ignoring the LVDS\n");
goto failed_find;
}
out:
drm_sysfs_connector_add(connector);
return;
failed_find:
dev_dbg(dev->dev, "No LVDS modes found, disabling.\n");
if (psb_intel_output->ddc_bus)
psb_intel_i2c_destroy(psb_intel_output->ddc_bus);
drm_encoder_cleanup(encoder);
drm_connector_cleanup(connector);
kfree(connector);
}
