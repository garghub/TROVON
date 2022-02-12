static void cdv_disable_vga(struct drm_device *dev)
{
u8 sr1;
u32 vga_reg;
vga_reg = VGACNTRL;
outb(1, VGA_SR_INDEX);
sr1 = inb(VGA_SR_DATA);
outb(sr1 | 1<<5, VGA_SR_DATA);
udelay(300);
REG_WRITE(vga_reg, VGA_DISP_DISABLE);
REG_READ(vga_reg);
}
static int cdv_output_init(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
cdv_disable_vga(dev);
cdv_intel_crt_init(dev, &dev_priv->mode_dev);
cdv_intel_lvds_init(dev, &dev_priv->mode_dev);
if (REG_READ(SDVOB) & SDVO_DETECTED)
cdv_hdmi_init(dev, &dev_priv->mode_dev, SDVOB);
if (REG_READ(SDVOC) & SDVO_DETECTED)
cdv_hdmi_init(dev, &dev_priv->mode_dev, SDVOC);
return 0;
}
static int cdv_get_brightness(struct backlight_device *bd)
{
return cdv_brightness;
}
static int cdv_backlight_setup(struct drm_device *dev)
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
}
return 0;
}
static int cdv_set_brightness(struct backlight_device *bd)
{
int level = bd->props.brightness;
if (level < 1)
level = 1;
cdv_brightness = level;
return 0;
}
static int cdv_backlight_init(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
int ret;
struct backlight_properties props;
memset(&props, 0, sizeof(struct backlight_properties));
props.max_brightness = 100;
props.type = BACKLIGHT_PLATFORM;
cdv_backlight_device = backlight_device_register("psb-bl",
NULL, (void *)dev, &cdv_ops, &props);
if (IS_ERR(cdv_backlight_device))
return PTR_ERR(cdv_backlight_device);
ret = cdv_backlight_setup(dev);
if (ret < 0) {
backlight_device_unregister(cdv_backlight_device);
cdv_backlight_device = NULL;
return ret;
}
cdv_backlight_device->props.brightness = 100;
cdv_backlight_device->props.max_brightness = 100;
backlight_update_status(cdv_backlight_device);
dev_priv->backlight_device = cdv_backlight_device;
return 0;
}
static inline u32 CDV_MSG_READ32(uint port, uint offset)
{
int mcr = (0x10<<24) | (port << 16) | (offset << 8);
uint32_t ret_val = 0;
struct pci_dev *pci_root = pci_get_bus_and_slot(0, 0);
pci_write_config_dword(pci_root, 0xD0, mcr);
pci_read_config_dword(pci_root, 0xD4, &ret_val);
pci_dev_put(pci_root);
return ret_val;
}
static inline void CDV_MSG_WRITE32(uint port, uint offset, u32 value)
{
int mcr = (0x11<<24) | (port << 16) | (offset << 8) | 0xF0;
struct pci_dev *pci_root = pci_get_bus_and_slot(0, 0);
pci_write_config_dword(pci_root, 0xD4, value);
pci_write_config_dword(pci_root, 0xD0, mcr);
pci_dev_put(pci_root);
}
static void cdv_init_pm(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
u32 pwr_cnt;
int i;
dev_priv->apm_base = CDV_MSG_READ32(PSB_PUNIT_PORT,
PSB_APMBA) & 0xFFFF;
dev_priv->ospm_base = CDV_MSG_READ32(PSB_PUNIT_PORT,
PSB_OSPMBA) & 0xFFFF;
pwr_cnt = inl(dev_priv->apm_base + PSB_APM_CMD);
pwr_cnt &= ~PSB_PWRGT_GFX_MASK;
outl(pwr_cnt, dev_priv->apm_base + PSB_APM_CMD);
for (i = 0; i < 5; i++) {
u32 pwr_sts = inl(dev_priv->apm_base + PSB_APM_STS);
if ((pwr_sts & PSB_PWRGT_GFX_MASK) == 0)
break;
udelay(10);
}
pwr_cnt = inl(dev_priv->ospm_base + PSB_PM_SSC);
pwr_cnt &= ~CDV_PWRGT_DISPLAY_CNTR;
outl(pwr_cnt, dev_priv->ospm_base + PSB_PM_SSC);
for (i = 0; i < 5; i++) {
u32 pwr_sts = inl(dev_priv->ospm_base + PSB_PM_SSS);
if ((pwr_sts & CDV_PWRGT_DISPLAY_STS) == 0)
break;
udelay(10);
}
}
static int cdv_save_display_registers(struct drm_device *dev)
{
return 0;
}
static int cdv_restore_display_registers(struct drm_device *dev)
{
return 0;
}
static int cdv_power_down(struct drm_device *dev)
{
return 0;
}
static int cdv_power_up(struct drm_device *dev)
{
return 0;
}
static void cdv_get_core_freq(struct drm_device *dev)
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
default:
dev_priv->core_freq = 0;
}
}
static int cdv_chip_setup(struct drm_device *dev)
{
cdv_get_core_freq(dev);
gma_intel_opregion_init(dev);
psb_intel_init_bios(dev);
REG_WRITE(PORT_HOTPLUG_EN, 0);
REG_WRITE(PORT_HOTPLUG_STAT, REG_READ(PORT_HOTPLUG_STAT));
return 0;
}
