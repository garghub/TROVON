static int mrst_device_ident(struct drm_device *dev)
{
if (devtype)
return devtype;
if (dmi_match(DMI_PRODUCT_NAME, "OakTrail") ||
dmi_match(DMI_PRODUCT_NAME, "OakTrail platform"))
return DEVICE_OAKTRAIL;
#if defined(CONFIG_X86_MRST)
if (dmi_match(DMI_PRODUCT_NAME, "MM") ||
dmi_match(DMI_PRODUCT_NAME, "MM 10"))
return DEVICE_MOORESTOWN_MM;
if (mrst_identify_cpu())
return DEVICE_MOORESTOWN;
#endif
return DEVICE_OAKTRAIL;
}
static int mrst_output_init(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
if (dev_priv->iLVDS_enable)
mrst_lvds_init(dev, &dev_priv->mode_dev);
else
dev_err(dev->dev, "DSI is not supported\n");
if (dev_priv->hdmi_priv)
mrst_hdmi_init(dev, &dev_priv->mode_dev);
return 0;
}
static int mrst_set_brightness(struct backlight_device *bd)
{
struct drm_device *dev = bl_get_data(mrst_backlight_device);
struct drm_psb_private *dev_priv = dev->dev_private;
int level = bd->props.brightness;
u32 blc_pwm_ctl;
u32 max_pwm_blc;
if (level < 1)
level = 1;
if (gma_power_begin(dev, 0)) {
max_pwm_blc = REG_READ(BLC_PWM_CTL) >> 16;
blc_pwm_ctl = level * max_pwm_blc / 100;
blc_pwm_ctl = blc_pwm_ctl * dev_priv->blc_adj1;
blc_pwm_ctl = blc_pwm_ctl / 100;
blc_pwm_ctl = blc_pwm_ctl * dev_priv->blc_adj2;
blc_pwm_ctl = blc_pwm_ctl / 100;
REG_WRITE(BLC_PWM_CTL2, (0x80000000 | REG_READ(BLC_PWM_CTL2)));
REG_WRITE(BLC_PWM_CTL, (max_pwm_blc << 16) | blc_pwm_ctl);
gma_power_end(dev);
}
mrst_brightness = level;
return 0;
}
static int mrst_get_brightness(struct backlight_device *bd)
{
return mrst_brightness;
}
static int device_backlight_init(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
unsigned long core_clock;
u16 bl_max_freq;
uint32_t value;
uint32_t blc_pwm_precision_factor;
dev_priv->blc_adj1 = BLC_ADJUSTMENT_MAX;
dev_priv->blc_adj2 = BLC_ADJUSTMENT_MAX;
bl_max_freq = 256;
blc_pwm_precision_factor = BLC_PWM_PRECISION_FACTOR;
core_clock = dev_priv->core_freq;
value = (core_clock * MHz) / BLC_PWM_FREQ_CALC_CONSTANT;
value *= blc_pwm_precision_factor;
value /= bl_max_freq;
value /= blc_pwm_precision_factor;
if (value > (unsigned long long)MRST_BLC_MAX_PWM_REG_FREQ)
return -ERANGE;
if (gma_power_begin(dev, false)) {
REG_WRITE(BLC_PWM_CTL2, (0x80000000 | REG_READ(BLC_PWM_CTL2)));
REG_WRITE(BLC_PWM_CTL, value | (value << 16));
gma_power_end(dev);
}
return 0;
}
int mrst_backlight_init(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
int ret;
struct backlight_properties props;
memset(&props, 0, sizeof(struct backlight_properties));
props.max_brightness = 100;
props.type = BACKLIGHT_PLATFORM;
mrst_backlight_device = backlight_device_register("mrst-bl",
NULL, (void *)dev, &mrst_ops, &props);
if (IS_ERR(mrst_backlight_device))
return PTR_ERR(mrst_backlight_device);
ret = device_backlight_init(dev);
if (ret < 0) {
backlight_device_unregister(mrst_backlight_device);
return ret;
}
mrst_backlight_device->props.brightness = 100;
mrst_backlight_device->props.max_brightness = 100;
backlight_update_status(mrst_backlight_device);
dev_priv->backlight_device = mrst_backlight_device;
return 0;
}
static void mrst_init_pm(struct drm_device *dev)
{
}
static int mrst_save_display_registers(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
int i;
u32 pp_stat;
dev_priv->saveDSPARB = PSB_RVDC32(DSPARB);
dev_priv->saveDSPFW1 = PSB_RVDC32(DSPFW1);
dev_priv->saveDSPFW2 = PSB_RVDC32(DSPFW2);
dev_priv->saveDSPFW3 = PSB_RVDC32(DSPFW3);
dev_priv->saveDSPFW4 = PSB_RVDC32(DSPFW4);
dev_priv->saveDSPFW5 = PSB_RVDC32(DSPFW5);
dev_priv->saveDSPFW6 = PSB_RVDC32(DSPFW6);
dev_priv->saveCHICKENBIT = PSB_RVDC32(DSPCHICKENBIT);
dev_priv->savePIPEACONF = PSB_RVDC32(PIPEACONF);
dev_priv->savePIPEASRC = PSB_RVDC32(PIPEASRC);
dev_priv->saveFPA0 = PSB_RVDC32(MRST_FPA0);
dev_priv->saveFPA1 = PSB_RVDC32(MRST_FPA1);
dev_priv->saveDPLL_A = PSB_RVDC32(MRST_DPLL_A);
dev_priv->saveHTOTAL_A = PSB_RVDC32(HTOTAL_A);
dev_priv->saveHBLANK_A = PSB_RVDC32(HBLANK_A);
dev_priv->saveHSYNC_A = PSB_RVDC32(HSYNC_A);
dev_priv->saveVTOTAL_A = PSB_RVDC32(VTOTAL_A);
dev_priv->saveVBLANK_A = PSB_RVDC32(VBLANK_A);
dev_priv->saveVSYNC_A = PSB_RVDC32(VSYNC_A);
dev_priv->saveBCLRPAT_A = PSB_RVDC32(BCLRPAT_A);
dev_priv->saveDSPACNTR = PSB_RVDC32(DSPACNTR);
dev_priv->saveDSPASTRIDE = PSB_RVDC32(DSPASTRIDE);
dev_priv->saveDSPAADDR = PSB_RVDC32(DSPABASE);
dev_priv->saveDSPASURF = PSB_RVDC32(DSPASURF);
dev_priv->saveDSPALINOFF = PSB_RVDC32(DSPALINOFF);
dev_priv->saveDSPATILEOFF = PSB_RVDC32(DSPATILEOFF);
dev_priv->saveDSPACURSOR_CTRL = PSB_RVDC32(CURACNTR);
dev_priv->saveDSPACURSOR_BASE = PSB_RVDC32(CURABASE);
dev_priv->saveDSPACURSOR_POS = PSB_RVDC32(CURAPOS);
for (i = 0; i < 256; i++)
dev_priv->save_palette_a[i] = PSB_RVDC32(PALETTE_A + (i << 2));
if (dev_priv->hdmi_priv)
mrst_hdmi_save(dev);
dev_priv->savePERF_MODE = PSB_RVDC32(MRST_PERF_MODE);
dev_priv->savePP_CONTROL = PSB_RVDC32(PP_CONTROL);
dev_priv->savePFIT_PGM_RATIOS = PSB_RVDC32(PFIT_PGM_RATIOS);
dev_priv->savePFIT_AUTO_RATIOS = PSB_RVDC32(PFIT_AUTO_RATIOS);
dev_priv->saveBLC_PWM_CTL = PSB_RVDC32(BLC_PWM_CTL);
dev_priv->saveBLC_PWM_CTL2 = PSB_RVDC32(BLC_PWM_CTL2);
dev_priv->saveLVDS = PSB_RVDC32(LVDS);
dev_priv->savePFIT_CONTROL = PSB_RVDC32(PFIT_CONTROL);
dev_priv->savePP_ON_DELAYS = PSB_RVDC32(LVDSPP_ON);
dev_priv->savePP_OFF_DELAYS = PSB_RVDC32(LVDSPP_OFF);
dev_priv->savePP_DIVISOR = PSB_RVDC32(PP_CYCLE);
dev_priv->saveOV_OVADD = PSB_RVDC32(OV_OVADD);
dev_priv->saveOV_OGAMC0 = PSB_RVDC32(OV_OGAMC0);
dev_priv->saveOV_OGAMC1 = PSB_RVDC32(OV_OGAMC1);
dev_priv->saveOV_OGAMC2 = PSB_RVDC32(OV_OGAMC2);
dev_priv->saveOV_OGAMC3 = PSB_RVDC32(OV_OGAMC3);
dev_priv->saveOV_OGAMC4 = PSB_RVDC32(OV_OGAMC4);
dev_priv->saveOV_OGAMC5 = PSB_RVDC32(OV_OGAMC5);
dev_priv->saveHISTOGRAM_INT_CONTROL_REG =
PSB_RVDC32(HISTOGRAM_INT_CONTROL);
dev_priv->saveHISTOGRAM_LOGIC_CONTROL_REG =
PSB_RVDC32(HISTOGRAM_LOGIC_CONTROL);
dev_priv->savePWM_CONTROL_LOGIC = PSB_RVDC32(PWM_CONTROL_LOGIC);
if (dev_priv->iLVDS_enable) {
PSB_WVDC32(0, PP_CONTROL);
do {
pp_stat = PSB_RVDC32(PP_STATUS);
} while (pp_stat & 0x80000000);
PSB_WVDC32(0x58000000, DSPACNTR);
PSB_WVDC32(0, DSPASURF);
msleep(4);
PSB_WVDC32(0x0, PIPEACONF);
msleep(8);
PSB_WVDC32(0, MRST_DPLL_A);
}
return 0;
}
static int mrst_restore_display_registers(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
u32 pp_stat;
int i;
PSB_WVDC32(dev_priv->saveDSPARB, DSPARB);
PSB_WVDC32(dev_priv->saveDSPFW1, DSPFW1);
PSB_WVDC32(dev_priv->saveDSPFW2, DSPFW2);
PSB_WVDC32(dev_priv->saveDSPFW3, DSPFW3);
PSB_WVDC32(dev_priv->saveDSPFW4, DSPFW4);
PSB_WVDC32(dev_priv->saveDSPFW5, DSPFW5);
PSB_WVDC32(dev_priv->saveDSPFW6, DSPFW6);
PSB_WVDC32(dev_priv->saveCHICKENBIT, DSPCHICKENBIT);
PSB_WVDC32(0x80000000, VGACNTRL);
PSB_WVDC32(dev_priv->saveFPA0, MRST_FPA0);
PSB_WVDC32(dev_priv->saveFPA1, MRST_FPA1);
PSB_WVDC32(dev_priv->saveDPLL_A, MRST_DPLL_A);
DRM_UDELAY(150);
PSB_WVDC32(dev_priv->saveHTOTAL_A, HTOTAL_A);
PSB_WVDC32(dev_priv->saveHBLANK_A, HBLANK_A);
PSB_WVDC32(dev_priv->saveHSYNC_A, HSYNC_A);
PSB_WVDC32(dev_priv->saveVTOTAL_A, VTOTAL_A);
PSB_WVDC32(dev_priv->saveVBLANK_A, VBLANK_A);
PSB_WVDC32(dev_priv->saveVSYNC_A, VSYNC_A);
PSB_WVDC32(dev_priv->savePIPEASRC, PIPEASRC);
PSB_WVDC32(dev_priv->saveBCLRPAT_A, BCLRPAT_A);
PSB_WVDC32(dev_priv->savePERF_MODE, MRST_PERF_MODE);
if (dev_priv->iLVDS_enable)
PSB_WVDC32(dev_priv->savePIPEACONF, PIPEACONF);
PSB_WVDC32(dev_priv->saveDSPALINOFF, DSPALINOFF);
PSB_WVDC32(dev_priv->saveDSPASTRIDE, DSPASTRIDE);
PSB_WVDC32(dev_priv->saveDSPATILEOFF, DSPATILEOFF);
PSB_WVDC32(dev_priv->saveDSPACNTR, DSPACNTR);
PSB_WVDC32(dev_priv->saveDSPASURF, DSPASURF);
PSB_WVDC32(dev_priv->saveDSPACURSOR_CTRL, CURACNTR);
PSB_WVDC32(dev_priv->saveDSPACURSOR_POS, CURAPOS);
PSB_WVDC32(dev_priv->saveDSPACURSOR_BASE, CURABASE);
for (i = 0; i < 256; i++)
PSB_WVDC32(dev_priv->save_palette_a[i], PALETTE_A + (i << 2));
if (dev_priv->hdmi_priv)
mrst_hdmi_restore(dev);
if (dev_priv->iLVDS_enable) {
PSB_WVDC32(dev_priv->saveBLC_PWM_CTL2, BLC_PWM_CTL2);
PSB_WVDC32(dev_priv->saveLVDS, LVDS);
PSB_WVDC32(dev_priv->savePFIT_CONTROL, PFIT_CONTROL);
PSB_WVDC32(dev_priv->savePFIT_PGM_RATIOS, PFIT_PGM_RATIOS);
PSB_WVDC32(dev_priv->savePFIT_AUTO_RATIOS, PFIT_AUTO_RATIOS);
PSB_WVDC32(dev_priv->saveBLC_PWM_CTL, BLC_PWM_CTL);
PSB_WVDC32(dev_priv->savePP_ON_DELAYS, LVDSPP_ON);
PSB_WVDC32(dev_priv->savePP_OFF_DELAYS, LVDSPP_OFF);
PSB_WVDC32(dev_priv->savePP_DIVISOR, PP_CYCLE);
PSB_WVDC32(dev_priv->savePP_CONTROL, PP_CONTROL);
}
do {
pp_stat = PSB_RVDC32(PP_STATUS);
} while (pp_stat & 0x08000000);
do {
pp_stat = PSB_RVDC32(PP_STATUS);
} while (pp_stat & 0x10000000);
PSB_WVDC32(dev_priv->saveOV_OVADD, OV_OVADD);
PSB_WVDC32(dev_priv->saveOV_OGAMC0, OV_OGAMC0);
PSB_WVDC32(dev_priv->saveOV_OGAMC1, OV_OGAMC1);
PSB_WVDC32(dev_priv->saveOV_OGAMC2, OV_OGAMC2);
PSB_WVDC32(dev_priv->saveOV_OGAMC3, OV_OGAMC3);
PSB_WVDC32(dev_priv->saveOV_OGAMC4, OV_OGAMC4);
PSB_WVDC32(dev_priv->saveOV_OGAMC5, OV_OGAMC5);
PSB_WVDC32(dev_priv->saveHISTOGRAM_INT_CONTROL_REG,
HISTOGRAM_INT_CONTROL);
PSB_WVDC32(dev_priv->saveHISTOGRAM_LOGIC_CONTROL_REG,
HISTOGRAM_LOGIC_CONTROL);
PSB_WVDC32(dev_priv->savePWM_CONTROL_LOGIC, PWM_CONTROL_LOGIC);
return 0;
}
static int mrst_power_down(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
u32 pwr_mask ;
u32 pwr_sts;
pwr_mask = PSB_PWRGT_DISPLAY_MASK;
outl(pwr_mask, dev_priv->ospm_base + PSB_PM_SSC);
while (true) {
pwr_sts = inl(dev_priv->ospm_base + PSB_PM_SSS);
if ((pwr_sts & pwr_mask) == pwr_mask)
break;
else
udelay(10);
}
return 0;
}
static int mrst_power_up(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
u32 pwr_mask = PSB_PWRGT_DISPLAY_MASK;
u32 pwr_sts, pwr_cnt;
pwr_cnt = inl(dev_priv->ospm_base + PSB_PM_SSC);
pwr_cnt &= ~pwr_mask;
outl(pwr_cnt, (dev_priv->ospm_base + PSB_PM_SSC));
while (true) {
pwr_sts = inl(dev_priv->ospm_base + PSB_PM_SSS);
if ((pwr_sts & pwr_mask) == 0)
break;
else
udelay(10);
}
return 0;
}
static void mrst_lvds_cache_bl(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
intel_scu_ipc_ioread8(0x28, &(dev_priv->saveBKLTCNT));
intel_scu_ipc_ioread8(0x29, &(dev_priv->saveBKLTREQ));
intel_scu_ipc_ioread8(0x2A, &(dev_priv->saveBKLTBRTL));
}
static void mrst_mm_bl_power(struct drm_device *dev, bool on)
{
struct drm_psb_private *dev_priv = dev->dev_private;
if (on) {
intel_scu_ipc_iowrite8(0x2A, dev_priv->saveBKLTBRTL);
intel_scu_ipc_iowrite8(0x28, dev_priv->saveBKLTCNT);
intel_scu_ipc_iowrite8(0x29, dev_priv->saveBKLTREQ);
} else {
intel_scu_ipc_iowrite8(0x2A, 0);
intel_scu_ipc_iowrite8(0x28, 0);
intel_scu_ipc_iowrite8(0x29, 0);
}
}
static void oaktrail_teardown(struct drm_device *dev)
{
mrst_hdmi_teardown(dev);
}
static int mrst_chip_setup(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
switch (mrst_device_ident(dev)) {
case DEVICE_OAKTRAIL:
dev_priv->ops = &oaktrail_chip_ops;
mrst_hdmi_setup(dev);
return mid_chip_setup(dev);
#if defined(CONFIG_X86_MRST)
case DEVICE_MOORESTOWN_MM:
mrst_lvds_cache_bl(dev);
dev_priv->ops = &mrst_mm_chip_ops;
return mid_chip_setup(dev);
case DEVICE_MOORESTOWN:
return mid_chip_setup(dev);
#endif
default:
dev_err(dev->dev, "unsupported device type.\n");
return -ENODEV;
}
}
