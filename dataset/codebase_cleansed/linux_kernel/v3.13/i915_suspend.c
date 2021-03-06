static u8 i915_read_indexed(struct drm_device *dev, u16 index_port, u16 data_port, u8 reg)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE8(index_port, reg);
return I915_READ8(data_port);
}
static u8 i915_read_ar(struct drm_device *dev, u16 st01, u8 reg, u16 palette_enable)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_READ8(st01);
I915_WRITE8(VGA_AR_INDEX, palette_enable | reg);
return I915_READ8(VGA_AR_DATA_READ);
}
static void i915_write_ar(struct drm_device *dev, u16 st01, u8 reg, u8 val, u16 palette_enable)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_READ8(st01);
I915_WRITE8(VGA_AR_INDEX, palette_enable | reg);
I915_WRITE8(VGA_AR_DATA_WRITE, val);
}
static void i915_write_indexed(struct drm_device *dev, u16 index_port, u16 data_port, u8 reg, u8 val)
{
struct drm_i915_private *dev_priv = dev->dev_private;
I915_WRITE8(index_port, reg);
I915_WRITE8(data_port, val);
}
static void i915_save_vga(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int i;
u16 cr_index, cr_data, st01;
dev_priv->regfile.saveVGA0 = I915_READ(VGA0);
dev_priv->regfile.saveVGA1 = I915_READ(VGA1);
dev_priv->regfile.saveVGA_PD = I915_READ(VGA_PD);
dev_priv->regfile.saveVGACNTRL = I915_READ(i915_vgacntrl_reg(dev));
dev_priv->regfile.saveDACMASK = I915_READ8(VGA_DACMASK);
dev_priv->regfile.saveMSR = I915_READ8(VGA_MSR_READ);
if (dev_priv->regfile.saveMSR & VGA_MSR_CGA_MODE) {
cr_index = VGA_CR_INDEX_CGA;
cr_data = VGA_CR_DATA_CGA;
st01 = VGA_ST01_CGA;
} else {
cr_index = VGA_CR_INDEX_MDA;
cr_data = VGA_CR_DATA_MDA;
st01 = VGA_ST01_MDA;
}
i915_write_indexed(dev, cr_index, cr_data, 0x11,
i915_read_indexed(dev, cr_index, cr_data, 0x11) &
(~0x80));
for (i = 0; i <= 0x24; i++)
dev_priv->regfile.saveCR[i] =
i915_read_indexed(dev, cr_index, cr_data, i);
dev_priv->regfile.saveCR[0x11] &= ~0x80;
I915_READ8(st01);
dev_priv->regfile.saveAR_INDEX = I915_READ8(VGA_AR_INDEX);
for (i = 0; i <= 0x14; i++)
dev_priv->regfile.saveAR[i] = i915_read_ar(dev, st01, i, 0);
I915_READ8(st01);
I915_WRITE8(VGA_AR_INDEX, dev_priv->regfile.saveAR_INDEX);
I915_READ8(st01);
for (i = 0; i < 9; i++)
dev_priv->regfile.saveGR[i] =
i915_read_indexed(dev, VGA_GR_INDEX, VGA_GR_DATA, i);
dev_priv->regfile.saveGR[0x10] =
i915_read_indexed(dev, VGA_GR_INDEX, VGA_GR_DATA, 0x10);
dev_priv->regfile.saveGR[0x11] =
i915_read_indexed(dev, VGA_GR_INDEX, VGA_GR_DATA, 0x11);
dev_priv->regfile.saveGR[0x18] =
i915_read_indexed(dev, VGA_GR_INDEX, VGA_GR_DATA, 0x18);
for (i = 0; i < 8; i++)
dev_priv->regfile.saveSR[i] =
i915_read_indexed(dev, VGA_SR_INDEX, VGA_SR_DATA, i);
}
static void i915_restore_vga(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int i;
u16 cr_index, cr_data, st01;
I915_WRITE(i915_vgacntrl_reg(dev), dev_priv->regfile.saveVGACNTRL);
I915_WRITE(VGA0, dev_priv->regfile.saveVGA0);
I915_WRITE(VGA1, dev_priv->regfile.saveVGA1);
I915_WRITE(VGA_PD, dev_priv->regfile.saveVGA_PD);
POSTING_READ(VGA_PD);
udelay(150);
I915_WRITE8(VGA_MSR_WRITE, dev_priv->regfile.saveMSR);
if (dev_priv->regfile.saveMSR & VGA_MSR_CGA_MODE) {
cr_index = VGA_CR_INDEX_CGA;
cr_data = VGA_CR_DATA_CGA;
st01 = VGA_ST01_CGA;
} else {
cr_index = VGA_CR_INDEX_MDA;
cr_data = VGA_CR_DATA_MDA;
st01 = VGA_ST01_MDA;
}
for (i = 0; i < 7; i++)
i915_write_indexed(dev, VGA_SR_INDEX, VGA_SR_DATA, i,
dev_priv->regfile.saveSR[i]);
i915_write_indexed(dev, cr_index, cr_data, 0x11, dev_priv->regfile.saveCR[0x11]);
for (i = 0; i <= 0x24; i++)
i915_write_indexed(dev, cr_index, cr_data, i, dev_priv->regfile.saveCR[i]);
for (i = 0; i < 9; i++)
i915_write_indexed(dev, VGA_GR_INDEX, VGA_GR_DATA, i,
dev_priv->regfile.saveGR[i]);
i915_write_indexed(dev, VGA_GR_INDEX, VGA_GR_DATA, 0x10,
dev_priv->regfile.saveGR[0x10]);
i915_write_indexed(dev, VGA_GR_INDEX, VGA_GR_DATA, 0x11,
dev_priv->regfile.saveGR[0x11]);
i915_write_indexed(dev, VGA_GR_INDEX, VGA_GR_DATA, 0x18,
dev_priv->regfile.saveGR[0x18]);
I915_READ8(st01);
for (i = 0; i <= 0x14; i++)
i915_write_ar(dev, st01, i, dev_priv->regfile.saveAR[i], 0);
I915_READ8(st01);
I915_WRITE8(VGA_AR_INDEX, dev_priv->regfile.saveAR_INDEX | 0x20);
I915_READ8(st01);
I915_WRITE8(VGA_DACMASK, dev_priv->regfile.saveDACMASK);
}
static void i915_save_display(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long flags;
if (INTEL_INFO(dev)->gen <= 4)
dev_priv->regfile.saveDSPARB = I915_READ(DSPARB);
if (!drm_core_check_feature(dev, DRIVER_MODESET))
i915_save_display_reg(dev);
spin_lock_irqsave(&dev_priv->backlight.lock, flags);
if (HAS_PCH_SPLIT(dev)) {
dev_priv->regfile.savePP_CONTROL = I915_READ(PCH_PP_CONTROL);
dev_priv->regfile.saveBLC_PWM_CTL = I915_READ(BLC_PWM_PCH_CTL1);
dev_priv->regfile.saveBLC_PWM_CTL2 = I915_READ(BLC_PWM_PCH_CTL2);
dev_priv->regfile.saveBLC_CPU_PWM_CTL = I915_READ(BLC_PWM_CPU_CTL);
dev_priv->regfile.saveBLC_CPU_PWM_CTL2 = I915_READ(BLC_PWM_CPU_CTL2);
if (HAS_PCH_IBX(dev) || HAS_PCH_CPT(dev))
dev_priv->regfile.saveLVDS = I915_READ(PCH_LVDS);
} else if (IS_VALLEYVIEW(dev)) {
dev_priv->regfile.savePP_CONTROL = I915_READ(PP_CONTROL);
dev_priv->regfile.savePFIT_PGM_RATIOS = I915_READ(PFIT_PGM_RATIOS);
dev_priv->regfile.saveBLC_PWM_CTL =
I915_READ(VLV_BLC_PWM_CTL(PIPE_A));
dev_priv->regfile.saveBLC_HIST_CTL =
I915_READ(VLV_BLC_HIST_CTL(PIPE_A));
dev_priv->regfile.saveBLC_PWM_CTL2 =
I915_READ(VLV_BLC_PWM_CTL2(PIPE_A));
dev_priv->regfile.saveBLC_PWM_CTL_B =
I915_READ(VLV_BLC_PWM_CTL(PIPE_B));
dev_priv->regfile.saveBLC_HIST_CTL_B =
I915_READ(VLV_BLC_HIST_CTL(PIPE_B));
dev_priv->regfile.saveBLC_PWM_CTL2_B =
I915_READ(VLV_BLC_PWM_CTL2(PIPE_B));
} else {
dev_priv->regfile.savePP_CONTROL = I915_READ(PP_CONTROL);
dev_priv->regfile.savePFIT_PGM_RATIOS = I915_READ(PFIT_PGM_RATIOS);
dev_priv->regfile.saveBLC_PWM_CTL = I915_READ(BLC_PWM_CTL);
dev_priv->regfile.saveBLC_HIST_CTL = I915_READ(BLC_HIST_CTL);
if (INTEL_INFO(dev)->gen >= 4)
dev_priv->regfile.saveBLC_PWM_CTL2 = I915_READ(BLC_PWM_CTL2);
if (IS_MOBILE(dev) && !IS_I830(dev))
dev_priv->regfile.saveLVDS = I915_READ(LVDS);
}
spin_unlock_irqrestore(&dev_priv->backlight.lock, flags);
if (!IS_I830(dev) && !IS_845G(dev) && !HAS_PCH_SPLIT(dev))
dev_priv->regfile.savePFIT_CONTROL = I915_READ(PFIT_CONTROL);
if (HAS_PCH_SPLIT(dev)) {
dev_priv->regfile.savePP_ON_DELAYS = I915_READ(PCH_PP_ON_DELAYS);
dev_priv->regfile.savePP_OFF_DELAYS = I915_READ(PCH_PP_OFF_DELAYS);
dev_priv->regfile.savePP_DIVISOR = I915_READ(PCH_PP_DIVISOR);
} else {
dev_priv->regfile.savePP_ON_DELAYS = I915_READ(PP_ON_DELAYS);
dev_priv->regfile.savePP_OFF_DELAYS = I915_READ(PP_OFF_DELAYS);
dev_priv->regfile.savePP_DIVISOR = I915_READ(PP_DIVISOR);
}
if (I915_HAS_FBC(dev)) {
if (HAS_PCH_SPLIT(dev)) {
dev_priv->regfile.saveDPFC_CB_BASE = I915_READ(ILK_DPFC_CB_BASE);
} else if (IS_GM45(dev)) {
dev_priv->regfile.saveDPFC_CB_BASE = I915_READ(DPFC_CB_BASE);
} else {
dev_priv->regfile.saveFBC_CFB_BASE = I915_READ(FBC_CFB_BASE);
dev_priv->regfile.saveFBC_LL_BASE = I915_READ(FBC_LL_BASE);
dev_priv->regfile.saveFBC_CONTROL2 = I915_READ(FBC_CONTROL2);
dev_priv->regfile.saveFBC_CONTROL = I915_READ(FBC_CONTROL);
}
}
if (!drm_core_check_feature(dev, DRIVER_MODESET))
i915_save_vga(dev);
}
static void i915_restore_display(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
u32 mask = 0xffffffff;
unsigned long flags;
if (INTEL_INFO(dev)->gen <= 4)
I915_WRITE(DSPARB, dev_priv->regfile.saveDSPARB);
if (!drm_core_check_feature(dev, DRIVER_MODESET))
i915_restore_display_reg(dev);
spin_lock_irqsave(&dev_priv->backlight.lock, flags);
if (INTEL_INFO(dev)->gen >= 4 && !HAS_PCH_SPLIT(dev))
I915_WRITE(BLC_PWM_CTL2, dev_priv->regfile.saveBLC_PWM_CTL2);
if (drm_core_check_feature(dev, DRIVER_MODESET))
mask = ~LVDS_PORT_EN;
if (HAS_PCH_IBX(dev) || HAS_PCH_CPT(dev))
I915_WRITE(PCH_LVDS, dev_priv->regfile.saveLVDS & mask);
else if (INTEL_INFO(dev)->gen <= 4 && IS_MOBILE(dev) && !IS_I830(dev))
I915_WRITE(LVDS, dev_priv->regfile.saveLVDS & mask);
if (!IS_I830(dev) && !IS_845G(dev) && !HAS_PCH_SPLIT(dev))
I915_WRITE(PFIT_CONTROL, dev_priv->regfile.savePFIT_CONTROL);
if (HAS_PCH_SPLIT(dev)) {
I915_WRITE(BLC_PWM_PCH_CTL1, dev_priv->regfile.saveBLC_PWM_CTL);
I915_WRITE(BLC_PWM_PCH_CTL2, dev_priv->regfile.saveBLC_PWM_CTL2);
I915_WRITE(BLC_PWM_CPU_CTL2, dev_priv->regfile.saveBLC_CPU_PWM_CTL2);
I915_WRITE(BLC_PWM_CPU_CTL, dev_priv->regfile.saveBLC_CPU_PWM_CTL);
I915_WRITE(PCH_PP_ON_DELAYS, dev_priv->regfile.savePP_ON_DELAYS);
I915_WRITE(PCH_PP_OFF_DELAYS, dev_priv->regfile.savePP_OFF_DELAYS);
I915_WRITE(PCH_PP_DIVISOR, dev_priv->regfile.savePP_DIVISOR);
I915_WRITE(PCH_PP_CONTROL, dev_priv->regfile.savePP_CONTROL);
I915_WRITE(RSTDBYCTL,
dev_priv->regfile.saveMCHBAR_RENDER_STANDBY);
} else if (IS_VALLEYVIEW(dev)) {
I915_WRITE(VLV_BLC_PWM_CTL(PIPE_A),
dev_priv->regfile.saveBLC_PWM_CTL);
I915_WRITE(VLV_BLC_HIST_CTL(PIPE_A),
dev_priv->regfile.saveBLC_HIST_CTL);
I915_WRITE(VLV_BLC_PWM_CTL2(PIPE_A),
dev_priv->regfile.saveBLC_PWM_CTL2);
I915_WRITE(VLV_BLC_PWM_CTL(PIPE_B),
dev_priv->regfile.saveBLC_PWM_CTL);
I915_WRITE(VLV_BLC_HIST_CTL(PIPE_B),
dev_priv->regfile.saveBLC_HIST_CTL);
I915_WRITE(VLV_BLC_PWM_CTL2(PIPE_B),
dev_priv->regfile.saveBLC_PWM_CTL2);
} else {
I915_WRITE(PFIT_PGM_RATIOS, dev_priv->regfile.savePFIT_PGM_RATIOS);
I915_WRITE(BLC_PWM_CTL, dev_priv->regfile.saveBLC_PWM_CTL);
I915_WRITE(BLC_HIST_CTL, dev_priv->regfile.saveBLC_HIST_CTL);
I915_WRITE(PP_ON_DELAYS, dev_priv->regfile.savePP_ON_DELAYS);
I915_WRITE(PP_OFF_DELAYS, dev_priv->regfile.savePP_OFF_DELAYS);
I915_WRITE(PP_DIVISOR, dev_priv->regfile.savePP_DIVISOR);
I915_WRITE(PP_CONTROL, dev_priv->regfile.savePP_CONTROL);
}
spin_unlock_irqrestore(&dev_priv->backlight.lock, flags);
intel_disable_fbc(dev);
if (I915_HAS_FBC(dev)) {
if (HAS_PCH_SPLIT(dev)) {
I915_WRITE(ILK_DPFC_CB_BASE, dev_priv->regfile.saveDPFC_CB_BASE);
} else if (IS_GM45(dev)) {
I915_WRITE(DPFC_CB_BASE, dev_priv->regfile.saveDPFC_CB_BASE);
} else {
I915_WRITE(FBC_CFB_BASE, dev_priv->regfile.saveFBC_CFB_BASE);
I915_WRITE(FBC_LL_BASE, dev_priv->regfile.saveFBC_LL_BASE);
I915_WRITE(FBC_CONTROL2, dev_priv->regfile.saveFBC_CONTROL2);
I915_WRITE(FBC_CONTROL, dev_priv->regfile.saveFBC_CONTROL);
}
}
if (!drm_core_check_feature(dev, DRIVER_MODESET))
i915_restore_vga(dev);
else
i915_redisable_vga(dev);
}
int i915_save_state(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int i;
if (INTEL_INFO(dev)->gen <= 4)
pci_read_config_byte(dev->pdev, LBB,
&dev_priv->regfile.saveLBB);
mutex_lock(&dev->struct_mutex);
i915_save_display(dev);
if (!drm_core_check_feature(dev, DRIVER_MODESET)) {
if (HAS_PCH_SPLIT(dev)) {
dev_priv->regfile.saveDEIER = I915_READ(DEIER);
dev_priv->regfile.saveDEIMR = I915_READ(DEIMR);
dev_priv->regfile.saveGTIER = I915_READ(GTIER);
dev_priv->regfile.saveGTIMR = I915_READ(GTIMR);
dev_priv->regfile.saveFDI_RXA_IMR = I915_READ(_FDI_RXA_IMR);
dev_priv->regfile.saveFDI_RXB_IMR = I915_READ(_FDI_RXB_IMR);
dev_priv->regfile.saveMCHBAR_RENDER_STANDBY =
I915_READ(RSTDBYCTL);
dev_priv->regfile.savePCH_PORT_HOTPLUG = I915_READ(PCH_PORT_HOTPLUG);
} else {
dev_priv->regfile.saveIER = I915_READ(IER);
dev_priv->regfile.saveIMR = I915_READ(IMR);
}
}
intel_disable_gt_powersave(dev);
if (INTEL_INFO(dev)->gen < 7)
dev_priv->regfile.saveCACHE_MODE_0 = I915_READ(CACHE_MODE_0);
dev_priv->regfile.saveMI_ARB_STATE = I915_READ(MI_ARB_STATE);
for (i = 0; i < 16; i++) {
dev_priv->regfile.saveSWF0[i] = I915_READ(SWF00 + (i << 2));
dev_priv->regfile.saveSWF1[i] = I915_READ(SWF10 + (i << 2));
}
for (i = 0; i < 3; i++)
dev_priv->regfile.saveSWF2[i] = I915_READ(SWF30 + (i << 2));
mutex_unlock(&dev->struct_mutex);
return 0;
}
int i915_restore_state(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int i;
if (INTEL_INFO(dev)->gen <= 4)
pci_write_config_byte(dev->pdev, LBB,
dev_priv->regfile.saveLBB);
mutex_lock(&dev->struct_mutex);
i915_gem_restore_fences(dev);
i915_restore_display(dev);
if (!drm_core_check_feature(dev, DRIVER_MODESET)) {
if (HAS_PCH_SPLIT(dev)) {
I915_WRITE(DEIER, dev_priv->regfile.saveDEIER);
I915_WRITE(DEIMR, dev_priv->regfile.saveDEIMR);
I915_WRITE(GTIER, dev_priv->regfile.saveGTIER);
I915_WRITE(GTIMR, dev_priv->regfile.saveGTIMR);
I915_WRITE(_FDI_RXA_IMR, dev_priv->regfile.saveFDI_RXA_IMR);
I915_WRITE(_FDI_RXB_IMR, dev_priv->regfile.saveFDI_RXB_IMR);
I915_WRITE(PCH_PORT_HOTPLUG, dev_priv->regfile.savePCH_PORT_HOTPLUG);
} else {
I915_WRITE(IER, dev_priv->regfile.saveIER);
I915_WRITE(IMR, dev_priv->regfile.saveIMR);
}
}
if (INTEL_INFO(dev)->gen < 7)
I915_WRITE(CACHE_MODE_0, dev_priv->regfile.saveCACHE_MODE_0 |
0xffff0000);
I915_WRITE(MI_ARB_STATE, dev_priv->regfile.saveMI_ARB_STATE | 0xffff0000);
for (i = 0; i < 16; i++) {
I915_WRITE(SWF00 + (i << 2), dev_priv->regfile.saveSWF0[i]);
I915_WRITE(SWF10 + (i << 2), dev_priv->regfile.saveSWF1[i]);
}
for (i = 0; i < 3; i++)
I915_WRITE(SWF30 + (i << 2), dev_priv->regfile.saveSWF2[i]);
mutex_unlock(&dev->struct_mutex);
intel_i2c_reset(dev);
return 0;
}
