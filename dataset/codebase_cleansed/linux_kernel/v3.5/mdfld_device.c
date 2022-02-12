int mdfld_set_brightness(struct backlight_device *bd)
{
struct drm_device *dev =
(struct drm_device *)bl_get_data(mdfld_backlight_device);
struct drm_psb_private *dev_priv = dev->dev_private;
int level = bd->props.brightness;
DRM_DEBUG_DRIVER("backlight level set to %d\n", level);
if (level < BRIGHTNESS_MIN_LEVEL)
level = BRIGHTNESS_MIN_LEVEL;
if (gma_power_begin(dev, false)) {
u32 adjusted_level = 0;
adjusted_level = level * dev_priv->blc_adj2;
adjusted_level = adjusted_level / BLC_ADJUSTMENT_MAX;
dev_priv->brightness_adjusted = adjusted_level;
if (mdfld_get_panel_type(dev, 0) == TC35876X) {
if (dev_priv->dpi_panel_on[0] ||
dev_priv->dpi_panel_on[2])
tc35876x_brightness_control(dev,
dev_priv->brightness_adjusted);
} else {
if (dev_priv->dpi_panel_on[0])
mdfld_dsi_brightness_control(dev, 0,
dev_priv->brightness_adjusted);
}
if (dev_priv->dpi_panel_on[2])
mdfld_dsi_brightness_control(dev, 2,
dev_priv->brightness_adjusted);
gma_power_end(dev);
}
dev_priv->brightness = level;
return 0;
}
static int mdfld_get_brightness(struct backlight_device *bd)
{
struct drm_device *dev =
(struct drm_device *)bl_get_data(mdfld_backlight_device);
struct drm_psb_private *dev_priv = dev->dev_private;
DRM_DEBUG_DRIVER("brightness = 0x%x \n", dev_priv->brightness);
return dev_priv->brightness;
}
static int device_backlight_init(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = (struct drm_psb_private *)
dev->dev_private;
dev_priv->blc_adj1 = BLC_ADJUSTMENT_MAX;
dev_priv->blc_adj2 = BLC_ADJUSTMENT_MAX;
return 0;
}
static int mdfld_backlight_init(struct drm_device *dev)
{
struct backlight_properties props;
int ret = 0;
memset(&props, 0, sizeof(struct backlight_properties));
props.max_brightness = BRIGHTNESS_MAX_LEVEL;
props.type = BACKLIGHT_PLATFORM;
mdfld_backlight_device = backlight_device_register("mdfld-bl",
NULL, (void *)dev, &mdfld_ops, &props);
if (IS_ERR(mdfld_backlight_device))
return PTR_ERR(mdfld_backlight_device);
ret = device_backlight_init(dev);
if (ret)
return ret;
mdfld_backlight_device->props.brightness = BRIGHTNESS_MAX_LEVEL;
mdfld_backlight_device->props.max_brightness = BRIGHTNESS_MAX_LEVEL;
backlight_update_status(mdfld_backlight_device);
return 0;
}
struct backlight_device *mdfld_get_backlight_device(void)
{
#ifdef CONFIG_BACKLIGHT_CLASS_DEVICE
return mdfld_backlight_device;
#else
return NULL;
#endif
}
static int mdfld_save_display_registers(struct drm_device *dev, int pipenum)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct medfield_state *regs = &dev_priv->regs.mdfld;
struct psb_pipe *pipe = &dev_priv->regs.pipe[pipenum];
const struct psb_offset *map = &dev_priv->regmap[pipenum];
int i;
u32 *mipi_val;
u32 mipi_reg = MIPI;
switch (pipenum) {
case 0:
mipi_val = &regs->saveMIPI;
break;
case 1:
mipi_val = &regs->saveMIPI;
break;
case 2:
mipi_reg = MIPI_C;
mipi_val = &regs->saveMIPI_C;
break;
default:
DRM_ERROR("%s, invalid pipe number.\n", __func__);
return -EINVAL;
}
pipe->dpll = PSB_RVDC32(map->dpll);
pipe->fp0 = PSB_RVDC32(map->fp0);
pipe->conf = PSB_RVDC32(map->conf);
pipe->htotal = PSB_RVDC32(map->htotal);
pipe->hblank = PSB_RVDC32(map->hblank);
pipe->hsync = PSB_RVDC32(map->hsync);
pipe->vtotal = PSB_RVDC32(map->vtotal);
pipe->vblank = PSB_RVDC32(map->vblank);
pipe->vsync = PSB_RVDC32(map->vsync);
pipe->src = PSB_RVDC32(map->src);
pipe->stride = PSB_RVDC32(map->stride);
pipe->linoff = PSB_RVDC32(map->linoff);
pipe->tileoff = PSB_RVDC32(map->tileoff);
pipe->size = PSB_RVDC32(map->size);
pipe->pos = PSB_RVDC32(map->pos);
pipe->surf = PSB_RVDC32(map->surf);
pipe->cntr = PSB_RVDC32(map->cntr);
pipe->status = PSB_RVDC32(map->status);
for (i = 0; i < 256; i++)
pipe->palette[i] = PSB_RVDC32(map->palette + (i << 2));
if (pipenum == 1) {
regs->savePFIT_CONTROL = PSB_RVDC32(PFIT_CONTROL);
regs->savePFIT_PGM_RATIOS = PSB_RVDC32(PFIT_PGM_RATIOS);
regs->saveHDMIPHYMISCCTL = PSB_RVDC32(HDMIPHYMISCCTL);
regs->saveHDMIB_CONTROL = PSB_RVDC32(HDMIB_CONTROL);
return 0;
}
*mipi_val = PSB_RVDC32(mipi_reg);
return 0;
}
static int mdfld_restore_display_registers(struct drm_device *dev, int pipenum)
{
u32 temp = 0;
u32 device_ready_reg = DEVICE_READY_REG;
struct drm_psb_private *dev_priv = dev->dev_private;
struct mdfld_dsi_config *dsi_config = NULL;
struct medfield_state *regs = &dev_priv->regs.mdfld;
struct psb_pipe *pipe = &dev_priv->regs.pipe[pipenum];
const struct psb_offset *map = &dev_priv->regmap[pipenum];
u32 i;
u32 dpll;
u32 timeout = 0;
u32 mipi_reg = MIPI;
u32 dpll_val = pipe->dpll;
u32 mipi_val = regs->saveMIPI;
switch (pipenum) {
case 0:
dpll_val &= ~DPLL_VCO_ENABLE;
dsi_config = dev_priv->dsi_configs[0];
break;
case 1:
dpll_val &= ~DPLL_VCO_ENABLE;
break;
case 2:
mipi_reg = MIPI_C;
mipi_val = regs->saveMIPI_C;
dsi_config = dev_priv->dsi_configs[1];
break;
default:
DRM_ERROR("%s, invalid pipe number.\n", __func__);
return -EINVAL;
}
PSB_WVDC32(0x80000000, VGACNTRL);
if (pipenum == 1) {
PSB_WVDC32(dpll_val & ~DPLL_VCO_ENABLE, map->dpll);
PSB_RVDC32(map->dpll);
PSB_WVDC32(pipe->fp0, map->fp0);
} else {
dpll = PSB_RVDC32(map->dpll);
if (!(dpll & DPLL_VCO_ENABLE)) {
if (dpll & MDFLD_PWR_GATE_EN) {
dpll &= ~MDFLD_PWR_GATE_EN;
PSB_WVDC32(dpll, map->dpll);
udelay(500);
}
PSB_WVDC32(pipe->fp0, map->fp0);
PSB_WVDC32(dpll_val, map->dpll);
udelay(500);
dpll_val |= DPLL_VCO_ENABLE;
PSB_WVDC32(dpll_val, map->dpll);
PSB_RVDC32(map->dpll);
while (timeout < 20000 &&
!(PSB_RVDC32(map->conf) & PIPECONF_DSIPLL_LOCK)) {
udelay(150);
timeout++;
}
if (timeout == 20000) {
DRM_ERROR("%s, can't lock DSIPLL.\n",
__func__);
return -EINVAL;
}
}
}
PSB_WVDC32(pipe->htotal, map->htotal);
PSB_WVDC32(pipe->hblank, map->hblank);
PSB_WVDC32(pipe->hsync, map->hsync);
PSB_WVDC32(pipe->vtotal, map->vtotal);
PSB_WVDC32(pipe->vblank, map->vblank);
PSB_WVDC32(pipe->vsync, map->vsync);
PSB_WVDC32(pipe->src, map->src);
PSB_WVDC32(pipe->status, map->status);
PSB_WVDC32(pipe->stride, map->stride);
PSB_WVDC32(pipe->linoff, map->linoff);
PSB_WVDC32(pipe->tileoff, map->tileoff);
PSB_WVDC32(pipe->size, map->size);
PSB_WVDC32(pipe->pos, map->pos);
PSB_WVDC32(pipe->surf, map->surf);
if (pipenum == 1) {
for (i = 0; i < 256; i++)
PSB_WVDC32(pipe->palette[i], map->palette + (i << 2));
PSB_WVDC32(regs->savePFIT_CONTROL, PFIT_CONTROL);
PSB_WVDC32(regs->savePFIT_PGM_RATIOS, PFIT_PGM_RATIOS);
PSB_WVDC32(pipe->cntr & ~DISPLAY_PLANE_ENABLE, map->cntr);
return 0;
}
PSB_WVDC32(mipi_val, mipi_reg);
if (dsi_config)
mdfld_dsi_controller_init(dsi_config, pipenum);
if (in_atomic() || in_interrupt())
mdelay(20);
else
msleep(20);
PSB_WVDC32(pipe->cntr, map->cntr);
if (in_atomic() || in_interrupt())
mdelay(20);
else
msleep(20);
temp = REG_READ(mipi_reg);
temp |= LP_OUTPUT_HOLD_RELEASE;
REG_WRITE(mipi_reg, temp);
mdelay(1);
temp = REG_READ(device_ready_reg);
temp &= ~ULPS_MASK;
temp |= 0x3;
temp |= EXIT_ULPS_DEV_READY;
REG_WRITE(device_ready_reg, temp);
mdelay(1);
temp = REG_READ(device_ready_reg);
temp &= ~ULPS_MASK;
temp |= EXITING_ULPS;
REG_WRITE(device_ready_reg, temp);
mdelay(1);
PSB_WVDC32(pipe->conf, map->conf);
for (i = 0; i < 256; i++)
PSB_WVDC32(pipe->palette[i], map->palette + (i << 2));
return 0;
}
static int mdfld_save_registers(struct drm_device *dev)
{
mdfld_save_display_registers(dev, 0);
mdfld_save_display_registers(dev, 2);
mdfld_disable_crtc(dev, 0);
mdfld_disable_crtc(dev, 2);
return 0;
}
static int mdfld_restore_registers(struct drm_device *dev)
{
mdfld_restore_display_registers(dev, 2);
mdfld_restore_display_registers(dev, 0);
return 0;
}
static int mdfld_power_down(struct drm_device *dev)
{
return 0;
}
static int mdfld_power_up(struct drm_device *dev)
{
return 0;
}
static int mdfld_chip_setup(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
if (pci_enable_msi(dev->pdev))
dev_warn(dev->dev, "Enabling MSI failed!\n");
dev_priv->regmap = mdfld_regmap;
return mid_chip_setup(dev);
}
