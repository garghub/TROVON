static int psb_output_init(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
psb_intel_lvds_init(dev, &dev_priv->mode_dev);
psb_intel_sdvo_init(dev, SDVOB);
return 0;
}
static int psb_get_brightness(struct backlight_device *bd)
{
return psb_brightness;
}
static int psb_backlight_setup(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
unsigned long core_clock;
u16 bl_max_freq;
uint32_t value;
uint32_t blc_pwm_precision_factor;
if (!dev_priv->lvds_bl) {
dev_err(dev->dev, "Has no valid LVDS backlight info\n");
return -ENOENT;
}
bl_max_freq = dev_priv->lvds_bl->freq;
blc_pwm_precision_factor = PSB_BLC_PWM_PRECISION_FACTOR;
core_clock = dev_priv->core_freq;
value = (core_clock * MHz) / BLC_PWM_FREQ_CALC_CONSTANT;
value *= blc_pwm_precision_factor;
value /= bl_max_freq;
value /= blc_pwm_precision_factor;
if (value > (unsigned long long)PSB_BLC_MAX_PWM_REG_FREQ ||
value < (unsigned long long)PSB_BLC_MIN_PWM_REG_FREQ)
return -ERANGE;
else {
value &= PSB_BACKLIGHT_PWM_POLARITY_BIT_CLEAR;
REG_WRITE(BLC_PWM_CTL,
(value << PSB_BACKLIGHT_PWM_CTL_SHIFT) | (value));
}
return 0;
}
static int psb_set_brightness(struct backlight_device *bd)
{
struct drm_device *dev = bl_get_data(psb_backlight_device);
int level = bd->props.brightness;
if (level < 1)
level = 1;
psb_intel_lvds_set_brightness(dev, level);
psb_brightness = level;
return 0;
}
static int psb_backlight_init(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
int ret;
struct backlight_properties props;
memset(&props, 0, sizeof(struct backlight_properties));
props.max_brightness = 100;
props.type = BACKLIGHT_PLATFORM;
psb_backlight_device = backlight_device_register("psb-bl",
NULL, (void *)dev, &psb_ops, &props);
if (IS_ERR(psb_backlight_device))
return PTR_ERR(psb_backlight_device);
ret = psb_backlight_setup(dev);
if (ret < 0) {
backlight_device_unregister(psb_backlight_device);
psb_backlight_device = NULL;
return ret;
}
psb_backlight_device->props.brightness = 100;
psb_backlight_device->props.max_brightness = 100;
backlight_update_status(psb_backlight_device);
dev_priv->backlight_device = psb_backlight_device;
psb_lid_timer_init(dev_priv);
return 0;
}
static void psb_init_pm(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
u32 gating = PSB_RSGX32(PSB_CR_CLKGATECTL);
gating &= ~3;
gating |= 1;
PSB_WSGX32(gating, PSB_CR_CLKGATECTL);
PSB_RSGX32(PSB_CR_CLKGATECTL);
}
static int psb_save_display_registers(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc;
struct drm_connector *connector;
struct psb_state *regs = &dev_priv->regs.psb;
regs->saveDSPARB = PSB_RVDC32(DSPARB);
regs->saveDSPFW1 = PSB_RVDC32(DSPFW1);
regs->saveDSPFW2 = PSB_RVDC32(DSPFW2);
regs->saveDSPFW3 = PSB_RVDC32(DSPFW3);
regs->saveDSPFW4 = PSB_RVDC32(DSPFW4);
regs->saveDSPFW5 = PSB_RVDC32(DSPFW5);
regs->saveDSPFW6 = PSB_RVDC32(DSPFW6);
regs->saveCHICKENBIT = PSB_RVDC32(DSPCHICKENBIT);
drm_modeset_lock_all(dev);
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
if (drm_helper_crtc_in_use(crtc))
crtc->funcs->save(crtc);
}
list_for_each_entry(connector, &dev->mode_config.connector_list, head)
if (connector->funcs->save)
connector->funcs->save(connector);
drm_modeset_unlock_all(dev);
return 0;
}
static int psb_restore_display_registers(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct drm_crtc *crtc;
struct drm_connector *connector;
struct psb_state *regs = &dev_priv->regs.psb;
PSB_WVDC32(regs->saveDSPARB, DSPARB);
PSB_WVDC32(regs->saveDSPFW1, DSPFW1);
PSB_WVDC32(regs->saveDSPFW2, DSPFW2);
PSB_WVDC32(regs->saveDSPFW3, DSPFW3);
PSB_WVDC32(regs->saveDSPFW4, DSPFW4);
PSB_WVDC32(regs->saveDSPFW5, DSPFW5);
PSB_WVDC32(regs->saveDSPFW6, DSPFW6);
PSB_WVDC32(regs->saveCHICKENBIT, DSPCHICKENBIT);
PSB_WVDC32(0x80000000, VGACNTRL);
drm_modeset_lock_all(dev);
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head)
if (drm_helper_crtc_in_use(crtc))
crtc->funcs->restore(crtc);
list_for_each_entry(connector, &dev->mode_config.connector_list, head)
if (connector->funcs->restore)
connector->funcs->restore(connector);
drm_modeset_unlock_all(dev);
return 0;
}
static int psb_power_down(struct drm_device *dev)
{
return 0;
}
static int psb_power_up(struct drm_device *dev)
{
return 0;
}
static void psb_get_core_freq(struct drm_device *dev)
{
uint32_t clock;
struct pci_dev *pci_root = pci_get_bus_and_slot(0, 0);
struct drm_psb_private *dev_priv = dev->dev_private;
pci_write_config_dword(pci_root, 0xD0, 0xD0050300);
pci_read_config_dword(pci_root, 0xD4, &clock);
pci_dev_put(pci_root);
switch (clock & 0x07) {
case 0:
dev_priv->core_freq = 100;
break;
case 1:
dev_priv->core_freq = 133;
break;
case 2:
dev_priv->core_freq = 150;
break;
case 3:
dev_priv->core_freq = 178;
break;
case 4:
dev_priv->core_freq = 200;
break;
case 5:
case 6:
case 7:
dev_priv->core_freq = 266;
break;
default:
dev_priv->core_freq = 0;
}
}
static int psb_chip_setup(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
dev_priv->regmap = psb_regmap;
psb_get_core_freq(dev);
gma_intel_setup_gmbus(dev);
psb_intel_opregion_init(dev);
psb_intel_init_bios(dev);
return 0;
}
static void psb_chip_teardown(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
psb_lid_timer_takedown(dev_priv);
gma_intel_teardown_gmbus(dev);
}
