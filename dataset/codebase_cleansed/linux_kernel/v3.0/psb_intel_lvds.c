static u32 psb_intel_lvds_get_max_backlight(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
u32 retVal;
if (gma_power_begin(dev, false)) {
retVal = ((REG_READ(BLC_PWM_CTL) &
BACKLIGHT_MODULATION_FREQ_MASK) >>
BACKLIGHT_MODULATION_FREQ_SHIFT) * 2;
gma_power_end(dev);
} else
retVal = ((dev_priv->saveBLC_PWM_CTL &
BACKLIGHT_MODULATION_FREQ_MASK) >>
BACKLIGHT_MODULATION_FREQ_SHIFT) * 2;
return retVal;
}
static int psb_lvds_i2c_set_brightness(struct drm_device *dev,
unsigned int level)
{
struct drm_psb_private *dev_priv =
(struct drm_psb_private *)dev->dev_private;
struct psb_intel_i2c_chan *lvds_i2c_bus = dev_priv->lvds_i2c_bus;
u8 out_buf[2];
unsigned int blc_i2c_brightness;
struct i2c_msg msgs[] = {
{
.addr = lvds_i2c_bus->slave_addr,
.flags = 0,
.len = 2,
.buf = out_buf,
}
};
blc_i2c_brightness = BRIGHTNESS_MASK & ((unsigned int)level *
BRIGHTNESS_MASK /
BRIGHTNESS_MAX_LEVEL);
if (dev_priv->lvds_bl->pol == BLC_POLARITY_INVERSE)
blc_i2c_brightness = BRIGHTNESS_MASK - blc_i2c_brightness;
out_buf[0] = dev_priv->lvds_bl->brightnesscmd;
out_buf[1] = (u8)blc_i2c_brightness;
if (i2c_transfer(&lvds_i2c_bus->adapter, msgs, 1) == 1) {
DRM_DEBUG("I2C set brightness.(command, value) (%d, %d)\n",
dev_priv->lvds_bl->brightnesscmd,
blc_i2c_brightness);
return 0;
}
DRM_ERROR("I2C transfer error\n");
return -1;
}
static int psb_lvds_pwm_set_brightness(struct drm_device *dev, int level)
{
struct drm_psb_private *dev_priv =
(struct drm_psb_private *)dev->dev_private;
u32 max_pwm_blc;
u32 blc_pwm_duty_cycle;
max_pwm_blc = psb_intel_lvds_get_max_backlight(dev);
BUG_ON((max_pwm_blc & PSB_BLC_MAX_PWM_REG_FREQ) == 0);
blc_pwm_duty_cycle = level * max_pwm_blc / BRIGHTNESS_MAX_LEVEL;
if (dev_priv->lvds_bl->pol == BLC_POLARITY_INVERSE)
blc_pwm_duty_cycle = max_pwm_blc - blc_pwm_duty_cycle;
blc_pwm_duty_cycle &= PSB_BACKLIGHT_PWM_POLARITY_BIT_CLEAR;
REG_WRITE(BLC_PWM_CTL,
(max_pwm_blc << PSB_BACKLIGHT_PWM_CTL_SHIFT) |
(blc_pwm_duty_cycle));
return 0;
}
void psb_intel_lvds_set_brightness(struct drm_device *dev, int level)
{
struct drm_psb_private *dev_priv =
(struct drm_psb_private *)dev->dev_private;
DRM_DEBUG("backlight level is %d\n", level);
if (!dev_priv->lvds_bl) {
DRM_ERROR("NO LVDS Backlight Info\n");
return;
}
if (dev_priv->lvds_bl->type == BLC_I2C_TYPE)
psb_lvds_i2c_set_brightness(dev, level);
else
psb_lvds_pwm_set_brightness(dev, level);
}
static void psb_intel_lvds_set_backlight(struct drm_device *dev, int level)
{
struct drm_psb_private *dev_priv = dev->dev_private;
u32 blc_pwm_ctl;
if (gma_power_begin(dev, false)) {
blc_pwm_ctl =
REG_READ(BLC_PWM_CTL) & ~BACKLIGHT_DUTY_CYCLE_MASK;
REG_WRITE(BLC_PWM_CTL,
(blc_pwm_ctl |
(level << BACKLIGHT_DUTY_CYCLE_SHIFT)));
gma_power_end(dev);
} else {
blc_pwm_ctl = dev_priv->saveBLC_PWM_CTL &
~BACKLIGHT_DUTY_CYCLE_MASK;
dev_priv->saveBLC_PWM_CTL = (blc_pwm_ctl |
(level << BACKLIGHT_DUTY_CYCLE_SHIFT));
}
}
static void psb_intel_lvds_set_power(struct drm_device *dev,
struct psb_intel_output *output, bool on)
{
u32 pp_status;
if (!gma_power_begin(dev, true))
return;
if (on) {
REG_WRITE(PP_CONTROL, REG_READ(PP_CONTROL) |
POWER_TARGET_ON);
do {
pp_status = REG_READ(PP_STATUS);
} while ((pp_status & PP_ON) == 0);
psb_intel_lvds_set_backlight(dev,
output->
mode_dev->backlight_duty_cycle);
} else {
psb_intel_lvds_set_backlight(dev, 0);
REG_WRITE(PP_CONTROL, REG_READ(PP_CONTROL) &
~POWER_TARGET_ON);
do {
pp_status = REG_READ(PP_STATUS);
} while (pp_status & PP_ON);
}
gma_power_end(dev);
}
static void psb_intel_lvds_encoder_dpms(struct drm_encoder *encoder, int mode)
{
struct drm_device *dev = encoder->dev;
struct psb_intel_output *output = enc_to_psb_intel_output(encoder);
if (mode == DRM_MODE_DPMS_ON)
psb_intel_lvds_set_power(dev, output, true);
else
psb_intel_lvds_set_power(dev, output, false);
}
static void psb_intel_lvds_save(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct drm_psb_private *dev_priv =
(struct drm_psb_private *)dev->dev_private;
struct psb_intel_output *psb_intel_output =
to_psb_intel_output(connector);
struct psb_intel_lvds_priv *lvds_priv =
(struct psb_intel_lvds_priv *)psb_intel_output->dev_priv;
lvds_priv->savePP_ON = REG_READ(LVDSPP_ON);
lvds_priv->savePP_OFF = REG_READ(LVDSPP_OFF);
lvds_priv->saveLVDS = REG_READ(LVDS);
lvds_priv->savePP_CONTROL = REG_READ(PP_CONTROL);
lvds_priv->savePP_CYCLE = REG_READ(PP_CYCLE);
lvds_priv->saveBLC_PWM_CTL = REG_READ(BLC_PWM_CTL);
lvds_priv->savePFIT_CONTROL = REG_READ(PFIT_CONTROL);
lvds_priv->savePFIT_PGM_RATIOS = REG_READ(PFIT_PGM_RATIOS);
dev_priv->backlight_duty_cycle = (dev_priv->saveBLC_PWM_CTL &
BACKLIGHT_DUTY_CYCLE_MASK);
if (dev_priv->backlight_duty_cycle == 0)
dev_priv->backlight_duty_cycle =
psb_intel_lvds_get_max_backlight(dev);
DRM_DEBUG("(0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x)\n",
lvds_priv->savePP_ON,
lvds_priv->savePP_OFF,
lvds_priv->saveLVDS,
lvds_priv->savePP_CONTROL,
lvds_priv->savePP_CYCLE,
lvds_priv->saveBLC_PWM_CTL);
}
static void psb_intel_lvds_restore(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
u32 pp_status;
struct psb_intel_output *psb_intel_output =
to_psb_intel_output(connector);
struct psb_intel_lvds_priv *lvds_priv =
(struct psb_intel_lvds_priv *)psb_intel_output->dev_priv;
DRM_DEBUG("(0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x)\n",
lvds_priv->savePP_ON,
lvds_priv->savePP_OFF,
lvds_priv->saveLVDS,
lvds_priv->savePP_CONTROL,
lvds_priv->savePP_CYCLE,
lvds_priv->saveBLC_PWM_CTL);
REG_WRITE(BLC_PWM_CTL, lvds_priv->saveBLC_PWM_CTL);
REG_WRITE(PFIT_CONTROL, lvds_priv->savePFIT_CONTROL);
REG_WRITE(PFIT_PGM_RATIOS, lvds_priv->savePFIT_PGM_RATIOS);
REG_WRITE(LVDSPP_ON, lvds_priv->savePP_ON);
REG_WRITE(LVDSPP_OFF, lvds_priv->savePP_OFF);
REG_WRITE(PP_CYCLE, lvds_priv->savePP_CYCLE);
REG_WRITE(PP_CONTROL, lvds_priv->savePP_CONTROL);
REG_WRITE(LVDS, lvds_priv->saveLVDS);
if (lvds_priv->savePP_CONTROL & POWER_TARGET_ON) {
REG_WRITE(PP_CONTROL, REG_READ(PP_CONTROL) |
POWER_TARGET_ON);
do {
pp_status = REG_READ(PP_STATUS);
} while ((pp_status & PP_ON) == 0);
} else {
REG_WRITE(PP_CONTROL, REG_READ(PP_CONTROL) &
~POWER_TARGET_ON);
do {
pp_status = REG_READ(PP_STATUS);
} while (pp_status & PP_ON);
}
}
int psb_intel_lvds_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct psb_intel_output *psb_intel_output =
to_psb_intel_output(connector);
struct drm_display_mode *fixed_mode =
psb_intel_output->mode_dev->panel_fixed_mode;
PSB_DEBUG_ENTRY("\n");
if (psb_intel_output->type == INTEL_OUTPUT_MIPI2)
fixed_mode = psb_intel_output->mode_dev->panel_fixed_mode2;
if (mode->flags & DRM_MODE_FLAG_DBLSCAN)
return MODE_NO_DBLESCAN;
if (mode->flags & DRM_MODE_FLAG_INTERLACE)
return MODE_NO_INTERLACE;
if (fixed_mode) {
if (mode->hdisplay > fixed_mode->hdisplay)
return MODE_PANEL;
if (mode->vdisplay > fixed_mode->vdisplay)
return MODE_PANEL;
}
return MODE_OK;
}
bool psb_intel_lvds_mode_fixup(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct psb_intel_mode_device *mode_dev =
enc_to_psb_intel_output(encoder)->mode_dev;
struct drm_device *dev = encoder->dev;
struct psb_intel_crtc *psb_intel_crtc =
to_psb_intel_crtc(encoder->crtc);
struct drm_encoder *tmp_encoder;
struct drm_display_mode *panel_fixed_mode = mode_dev->panel_fixed_mode;
struct psb_intel_output *psb_intel_output =
enc_to_psb_intel_output(encoder);
PSB_DEBUG_ENTRY("type = 0x%x, pipe = %d.\n",
psb_intel_output->type, psb_intel_crtc->pipe);
if (psb_intel_output->type == INTEL_OUTPUT_MIPI2)
panel_fixed_mode = mode_dev->panel_fixed_mode2;
if (!IS_MRST(dev) && psb_intel_crtc->pipe == 0) {
printk(KERN_ERR "Can't support LVDS on pipe A\n");
return false;
}
if (IS_MRST(dev) && psb_intel_crtc->pipe != 0) {
printk(KERN_ERR "Must use PIPE A\n");
return false;
}
list_for_each_entry(tmp_encoder, &dev->mode_config.encoder_list,
head) {
if (tmp_encoder != encoder
&& tmp_encoder->crtc == encoder->crtc) {
printk(KERN_ERR "Can't enable LVDS and another "
"encoder on the same pipe\n");
return false;
}
}
if (panel_fixed_mode != NULL) {
adjusted_mode->hdisplay = panel_fixed_mode->hdisplay;
adjusted_mode->hsync_start = panel_fixed_mode->hsync_start;
adjusted_mode->hsync_end = panel_fixed_mode->hsync_end;
adjusted_mode->htotal = panel_fixed_mode->htotal;
adjusted_mode->vdisplay = panel_fixed_mode->vdisplay;
adjusted_mode->vsync_start = panel_fixed_mode->vsync_start;
adjusted_mode->vsync_end = panel_fixed_mode->vsync_end;
adjusted_mode->vtotal = panel_fixed_mode->vtotal;
adjusted_mode->clock = panel_fixed_mode->clock;
drm_mode_set_crtcinfo(adjusted_mode,
CRTC_INTERLACE_HALVE_V);
}
return true;
}
void psb_intel_lvds_prepare(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct psb_intel_output *output = enc_to_psb_intel_output(encoder);
struct psb_intel_mode_device *mode_dev = output->mode_dev;
PSB_DEBUG_ENTRY("\n");
if (!gma_power_begin(dev, true))
return;
mode_dev->saveBLC_PWM_CTL = REG_READ(BLC_PWM_CTL);
mode_dev->backlight_duty_cycle = (mode_dev->saveBLC_PWM_CTL &
BACKLIGHT_DUTY_CYCLE_MASK);
psb_intel_lvds_set_power(dev, output, false);
gma_power_end(dev);
}
void psb_intel_lvds_commit(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
struct psb_intel_output *output = enc_to_psb_intel_output(encoder);
struct psb_intel_mode_device *mode_dev = output->mode_dev;
PSB_DEBUG_ENTRY("\n");
if (mode_dev->backlight_duty_cycle == 0)
mode_dev->backlight_duty_cycle =
psb_intel_lvds_get_max_backlight(dev);
psb_intel_lvds_set_power(dev, output, true);
}
static void psb_intel_lvds_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct psb_intel_mode_device *mode_dev =
enc_to_psb_intel_output(encoder)->mode_dev;
struct drm_device *dev = encoder->dev;
u32 pfit_control;
if (mode->hdisplay != adjusted_mode->hdisplay ||
mode->vdisplay != adjusted_mode->vdisplay)
pfit_control = (PFIT_ENABLE | VERT_AUTO_SCALE |
HORIZ_AUTO_SCALE | VERT_INTERP_BILINEAR |
HORIZ_INTERP_BILINEAR);
else
pfit_control = 0;
if (mode_dev->panel_wants_dither)
pfit_control |= PANEL_8TO6_DITHER_ENABLE;
REG_WRITE(PFIT_CONTROL, pfit_control);
}
static enum drm_connector_status psb_intel_lvds_detect(struct drm_connector
*connector, bool force)
{
return connector_status_connected;
}
static int psb_intel_lvds_get_modes(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct psb_intel_output *psb_intel_output =
to_psb_intel_output(connector);
struct psb_intel_mode_device *mode_dev =
psb_intel_output->mode_dev;
int ret = 0;
ret = psb_intel_ddc_get_modes(psb_intel_output);
if (ret)
return ret;
connector->display_info.min_vfreq = 0;
connector->display_info.max_vfreq = 200;
connector->display_info.min_hfreq = 0;
connector->display_info.max_hfreq = 200;
if (mode_dev->panel_fixed_mode != NULL) {
struct drm_display_mode *mode =
drm_mode_duplicate(dev, mode_dev->panel_fixed_mode);
drm_mode_probed_add(connector, mode);
return 1;
}
return 0;
}
void psb_intel_lvds_destroy(struct drm_connector *connector)
{
struct psb_intel_output *psb_intel_output =
to_psb_intel_output(connector);
if (psb_intel_output->ddc_bus)
psb_intel_i2c_destroy(psb_intel_output->ddc_bus);
drm_sysfs_connector_remove(connector);
drm_connector_cleanup(connector);
kfree(connector);
}
int psb_intel_lvds_set_property(struct drm_connector *connector,
struct drm_property *property,
uint64_t value)
{
struct drm_encoder *pEncoder = connector->encoder;
PSB_DEBUG_ENTRY("\n");
if (!strcmp(property->name, "scaling mode") && pEncoder) {
struct psb_intel_crtc *pPsbCrtc =
to_psb_intel_crtc(pEncoder->crtc);
uint64_t curValue;
PSB_DEBUG_ENTRY("scaling mode\n");
if (!pPsbCrtc)
goto set_prop_error;
switch (value) {
case DRM_MODE_SCALE_FULLSCREEN:
break;
case DRM_MODE_SCALE_NO_SCALE:
break;
case DRM_MODE_SCALE_ASPECT:
break;
default:
goto set_prop_error;
}
if (drm_connector_property_get_value(connector,
property,
&curValue))
goto set_prop_error;
if (curValue == value)
goto set_prop_done;
if (drm_connector_property_set_value(connector,
property,
value))
goto set_prop_error;
if (pPsbCrtc->saved_mode.hdisplay != 0 &&
pPsbCrtc->saved_mode.vdisplay != 0) {
if (!drm_crtc_helper_set_mode(pEncoder->crtc,
&pPsbCrtc->saved_mode,
pEncoder->crtc->x,
pEncoder->crtc->y,
pEncoder->crtc->fb))
goto set_prop_error;
}
} else if (!strcmp(property->name, "backlight") && pEncoder) {
PSB_DEBUG_ENTRY("backlight\n");
if (drm_connector_property_set_value(connector,
property,
value))
goto set_prop_error;
else {
#ifdef CONFIG_BACKLIGHT_CLASS_DEVICE
struct backlight_device bd;
bd.props.brightness = value;
psb_set_brightness(&bd);
#endif
}
} else if (!strcmp(property->name, "DPMS") && pEncoder) {
struct drm_encoder_helper_funcs *pEncHFuncs
= pEncoder->helper_private;
PSB_DEBUG_ENTRY("DPMS\n");
pEncHFuncs->dpms(pEncoder, value);
}
set_prop_done:
return 0;
set_prop_error:
return -1;
}
static void psb_intel_lvds_enc_destroy(struct drm_encoder *encoder)
{
drm_encoder_cleanup(encoder);
}
void psb_intel_lvds_init(struct drm_device *dev,
struct psb_intel_mode_device *mode_dev)
{
struct psb_intel_output *psb_intel_output;
struct psb_intel_lvds_priv *lvds_priv;
struct drm_connector *connector;
struct drm_encoder *encoder;
struct drm_display_mode *scan;
struct drm_crtc *crtc;
struct drm_psb_private *dev_priv =
(struct drm_psb_private *)dev->dev_private;
u32 lvds;
int pipe;
psb_intel_output = kzalloc(sizeof(struct psb_intel_output), GFP_KERNEL);
if (!psb_intel_output)
return;
lvds_priv = kzalloc(sizeof(struct psb_intel_lvds_priv), GFP_KERNEL);
if (!lvds_priv) {
kfree(psb_intel_output);
DRM_DEBUG("LVDS private allocation error\n");
return;
}
psb_intel_output->dev_priv = lvds_priv;
psb_intel_output->mode_dev = mode_dev;
connector = &psb_intel_output->base;
encoder = &psb_intel_output->enc;
drm_connector_init(dev, &psb_intel_output->base,
&psb_intel_lvds_connector_funcs,
DRM_MODE_CONNECTOR_LVDS);
drm_encoder_init(dev, &psb_intel_output->enc,
&psb_intel_lvds_enc_funcs,
DRM_MODE_ENCODER_LVDS);
drm_mode_connector_attach_encoder(&psb_intel_output->base,
&psb_intel_output->enc);
psb_intel_output->type = INTEL_OUTPUT_LVDS;
drm_encoder_helper_add(encoder, &psb_intel_lvds_helper_funcs);
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
psb_intel_output->i2c_bus = psb_intel_i2c_create(dev,
GPIOB,
"LVDSBLC_B");
if (!psb_intel_output->i2c_bus) {
dev_printk(KERN_ERR,
&dev->pdev->dev, "I2C bus registration failed.\n");
goto failed_blc_i2c;
}
psb_intel_output->i2c_bus->slave_addr = 0x2C;
dev_priv->lvds_i2c_bus = psb_intel_output->i2c_bus;
psb_intel_output->ddc_bus = psb_intel_i2c_create(dev,
GPIOC,
"LVDSDDC_C");
if (!psb_intel_output->ddc_bus) {
dev_printk(KERN_ERR, &dev->pdev->dev,
"DDC bus registration " "failed.\n");
goto failed_ddc;
}
psb_intel_ddc_get_modes(psb_intel_output);
list_for_each_entry(scan, &connector->probed_modes, head) {
if (scan->type & DRM_MODE_TYPE_PREFERRED) {
mode_dev->panel_fixed_mode =
drm_mode_duplicate(dev, scan);
goto out;
}
}
if (mode_dev->vbt_mode)
mode_dev->panel_fixed_mode =
drm_mode_duplicate(dev, mode_dev->vbt_mode);
if (!mode_dev->panel_fixed_mode)
if (dev_priv->lfp_lvds_vbt_mode)
mode_dev->panel_fixed_mode =
drm_mode_duplicate(dev,
dev_priv->lfp_lvds_vbt_mode);
lvds = REG_READ(LVDS);
pipe = (lvds & LVDS_PIPEB_SELECT) ? 1 : 0;
crtc = psb_intel_get_crtc_from_pipe(dev, pipe);
if (crtc && (lvds & LVDS_PORT_EN)) {
mode_dev->panel_fixed_mode =
psb_intel_crtc_mode_get(dev, crtc);
if (mode_dev->panel_fixed_mode) {
mode_dev->panel_fixed_mode->type |=
DRM_MODE_TYPE_PREFERRED;
goto out;
}
}
if (!mode_dev->panel_fixed_mode) {
DRM_DEBUG
("Found no modes on the lvds, ignoring the LVDS\n");
goto failed_find;
}
out:
drm_sysfs_connector_add(connector);
PSB_DEBUG_ENTRY("hdisplay = %d\n",
mode_dev->panel_fixed_mode->hdisplay);
PSB_DEBUG_ENTRY(" vdisplay = %d\n",
mode_dev->panel_fixed_mode->vdisplay);
PSB_DEBUG_ENTRY(" hsync_start = %d\n",
mode_dev->panel_fixed_mode->hsync_start);
PSB_DEBUG_ENTRY(" hsync_end = %d\n",
mode_dev->panel_fixed_mode->hsync_end);
PSB_DEBUG_ENTRY(" htotal = %d\n",
mode_dev->panel_fixed_mode->htotal);
PSB_DEBUG_ENTRY(" vsync_start = %d\n",
mode_dev->panel_fixed_mode->vsync_start);
PSB_DEBUG_ENTRY(" vsync_end = %d\n",
mode_dev->panel_fixed_mode->vsync_end);
PSB_DEBUG_ENTRY(" vtotal = %d\n",
mode_dev->panel_fixed_mode->vtotal);
PSB_DEBUG_ENTRY(" clock = %d\n",
mode_dev->panel_fixed_mode->clock);
return;
failed_find:
if (psb_intel_output->ddc_bus)
psb_intel_i2c_destroy(psb_intel_output->ddc_bus);
failed_ddc:
if (psb_intel_output->i2c_bus)
psb_intel_i2c_destroy(psb_intel_output->i2c_bus);
failed_blc_i2c:
drm_encoder_cleanup(encoder);
drm_connector_cleanup(connector);
kfree(connector);
}
