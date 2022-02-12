int psb_set_brightness(struct backlight_device *bd)
{
struct drm_device *dev = bl_get_data(psb_backlight_device);
int level = bd->props.brightness;
DRM_DEBUG_DRIVER("backlight level set to %d\n", level);
if (level < 1)
level = 1;
psb_intel_lvds_set_brightness(dev, level);
psb_brightness = level;
return 0;
}
int mrst_set_brightness(struct backlight_device *bd)
{
struct drm_device *dev = bl_get_data(psb_backlight_device);
struct drm_psb_private *dev_priv = dev->dev_private;
int level = bd->props.brightness;
u32 blc_pwm_ctl;
u32 max_pwm_blc;
DRM_DEBUG_DRIVER("backlight level set to %d\n", level);
if (level < 1)
level = 1;
if (gma_power_begin(dev, 0)) {
max_pwm_blc = REG_READ(BLC_PWM_CTL) >> 16;
blc_pwm_ctl = level * max_pwm_blc / 100;
blc_pwm_ctl = blc_pwm_ctl * dev_priv->blc_adj1;
blc_pwm_ctl = blc_pwm_ctl / 100;
blc_pwm_ctl = blc_pwm_ctl * dev_priv->blc_adj2;
blc_pwm_ctl = blc_pwm_ctl / 100;
if (blc_pol == BLC_POLARITY_INVERSE)
blc_pwm_ctl = max_pwm_blc - blc_pwm_ctl;
REG_WRITE(BLC_PWM_CTL2, (0x80000000 | REG_READ(BLC_PWM_CTL2)));
REG_WRITE(BLC_PWM_CTL, (max_pwm_blc << 16) | blc_pwm_ctl);
gma_power_end(dev);
}
psb_brightness = level;
return 0;
}
int psb_get_brightness(struct backlight_device *bd)
{
DRM_DEBUG_DRIVER("brightness = 0x%x\n", psb_brightness);
return psb_brightness;
}
static int device_backlight_init(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
unsigned long core_clock;
u16 bl_max_freq;
uint32_t value;
uint32_t blc_pwm_precision_factor;
if (IS_MRST(dev)) {
dev_priv->blc_adj1 = BLC_ADJUSTMENT_MAX;
dev_priv->blc_adj2 = BLC_ADJUSTMENT_MAX;
bl_max_freq = 256;
blc_pol = BLC_POLARITY_NORMAL;
blc_pwm_precision_factor = BLC_PWM_PRECISION_FACTOR;
} else {
if (!dev_priv->lvds_bl) {
DRM_ERROR("Has no valid LVDS backlight info\n");
return 1;
}
bl_max_freq = dev_priv->lvds_bl->freq;
blc_pol = dev_priv->lvds_bl->pol;
blc_pwm_precision_factor = PSB_BLC_PWM_PRECISION_FACTOR;
blc_brightnesscmd = dev_priv->lvds_bl->brightnesscmd;
blc_type = dev_priv->lvds_bl->type;
}
core_clock = dev_priv->core_freq;
value = (core_clock * MHz) / BLC_PWM_FREQ_CALC_CONSTANT;
value *= blc_pwm_precision_factor;
value /= bl_max_freq;
value /= blc_pwm_precision_factor;
if (gma_power_begin(dev, false)) {
if (IS_MRST(dev)) {
if (value > (unsigned long long)MRST_BLC_MAX_PWM_REG_FREQ)
return 2;
else {
REG_WRITE(BLC_PWM_CTL2,
(0x80000000 | REG_READ(BLC_PWM_CTL2)));
REG_WRITE(BLC_PWM_CTL, value | (value << 16));
}
} else {
if (value > (unsigned long long)PSB_BLC_MAX_PWM_REG_FREQ ||
value < (unsigned long long)PSB_BLC_MIN_PWM_REG_FREQ)
return 2;
else {
value &= PSB_BACKLIGHT_PWM_POLARITY_BIT_CLEAR;
REG_WRITE(BLC_PWM_CTL,
(value << PSB_BACKLIGHT_PWM_CTL_SHIFT) |
(value));
}
}
gma_power_end(dev);
}
return 0;
}
int psb_backlight_init(struct drm_device *dev)
{
#ifdef CONFIG_BACKLIGHT_CLASS_DEVICE
int ret = 0;
struct backlight_properties props;
memset(&props, 0, sizeof(struct backlight_properties));
props.max_brightness = 100;
props.type = BACKLIGHT_PLATFORM;
psb_backlight_device = backlight_device_register("psb-bl", NULL,
(void *)dev, &psb_ops, &props);
if (IS_ERR(psb_backlight_device))
return PTR_ERR(psb_backlight_device);
ret = device_backlight_init(dev);
if (ret < 0)
return ret;
psb_backlight_device->props.brightness = 100;
psb_backlight_device->props.max_brightness = 100;
backlight_update_status(psb_backlight_device);
#endif
return 0;
}
void psb_backlight_exit(void)
{
#ifdef CONFIG_BACKLIGHT_CLASS_DEVICE
psb_backlight_device->props.brightness = 0;
backlight_update_status(psb_backlight_device);
backlight_device_unregister(psb_backlight_device);
#endif
}
struct backlight_device *psb_get_backlight_device(void)
{
return psb_backlight_device;
}
