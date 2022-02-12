static bool ivch_read(struct intel_dvo_device *dvo, int addr, uint16_t *data)
{
struct ivch_priv *priv = dvo->dev_priv;
struct i2c_adapter *adapter = dvo->i2c_bus;
u8 out_buf[1];
u8 in_buf[2];
struct i2c_msg msgs[] = {
{
.addr = dvo->slave_addr,
.flags = I2C_M_RD,
.len = 0,
},
{
.addr = 0,
.flags = I2C_M_NOSTART,
.len = 1,
.buf = out_buf,
},
{
.addr = dvo->slave_addr,
.flags = I2C_M_RD | I2C_M_NOSTART,
.len = 2,
.buf = in_buf,
}
};
out_buf[0] = addr;
if (i2c_transfer(adapter, msgs, 3) == 3) {
*data = (in_buf[1] << 8) | in_buf[0];
return true;
}
if (!priv->quiet) {
DRM_DEBUG_KMS("Unable to read register 0x%02x from "
"%s:%02x.\n",
addr, adapter->name, dvo->slave_addr);
}
return false;
}
static bool ivch_write(struct intel_dvo_device *dvo, int addr, uint16_t data)
{
struct ivch_priv *priv = dvo->dev_priv;
struct i2c_adapter *adapter = dvo->i2c_bus;
u8 out_buf[3];
struct i2c_msg msg = {
.addr = dvo->slave_addr,
.flags = 0,
.len = 3,
.buf = out_buf,
};
out_buf[0] = addr;
out_buf[1] = data & 0xff;
out_buf[2] = data >> 8;
if (i2c_transfer(adapter, &msg, 1) == 1)
return true;
if (!priv->quiet) {
DRM_DEBUG_KMS("Unable to write register 0x%02x to %s:%d.\n",
addr, adapter->name, dvo->slave_addr);
}
return false;
}
static bool ivch_init(struct intel_dvo_device *dvo,
struct i2c_adapter *adapter)
{
struct ivch_priv *priv;
uint16_t temp;
int i;
priv = kzalloc(sizeof(struct ivch_priv), GFP_KERNEL);
if (priv == NULL)
return false;
dvo->i2c_bus = adapter;
dvo->dev_priv = priv;
priv->quiet = true;
if (!ivch_read(dvo, VR00, &temp))
goto out;
priv->quiet = false;
if ((temp & VR00_BASE_ADDRESS_MASK) != dvo->slave_addr) {
DRM_DEBUG_KMS("ivch detect failed due to address mismatch "
"(%d vs %d)\n",
(temp & VR00_BASE_ADDRESS_MASK), dvo->slave_addr);
goto out;
}
ivch_read(dvo, VR20, &priv->width);
ivch_read(dvo, VR21, &priv->height);
for (i = 0; i < ARRAY_SIZE(backup_addresses); i++)
ivch_read(dvo, backup_addresses[i], priv->reg_backup + i);
ivch_dump_regs(dvo);
return true;
out:
kfree(priv);
return false;
}
static enum drm_connector_status ivch_detect(struct intel_dvo_device *dvo)
{
return connector_status_connected;
}
static enum drm_mode_status ivch_mode_valid(struct intel_dvo_device *dvo,
struct drm_display_mode *mode)
{
if (mode->clock > 112000)
return MODE_CLOCK_HIGH;
return MODE_OK;
}
static void ivch_reset(struct intel_dvo_device *dvo)
{
struct ivch_priv *priv = dvo->dev_priv;
int i;
DRM_DEBUG_KMS("Resetting the IVCH registers\n");
ivch_write(dvo, VR10, 0x0000);
for (i = 0; i < ARRAY_SIZE(backup_addresses); i++)
ivch_write(dvo, backup_addresses[i], priv->reg_backup[i]);
}
static void ivch_dpms(struct intel_dvo_device *dvo, bool enable)
{
int i;
uint16_t vr01, vr30, backlight;
ivch_reset(dvo);
if (!ivch_read(dvo, VR01, &vr01))
return;
if (enable)
backlight = 1;
else
backlight = 0;
ivch_write(dvo, VR80, backlight);
if (enable)
vr01 |= VR01_LCD_ENABLE | VR01_DVO_ENABLE;
else
vr01 &= ~(VR01_LCD_ENABLE | VR01_DVO_ENABLE);
ivch_write(dvo, VR01, vr01);
for (i = 0; i < 100; i++) {
if (!ivch_read(dvo, VR30, &vr30))
break;
if (((vr30 & VR30_PANEL_ON) != 0) == enable)
break;
udelay(1000);
}
udelay(16 * 1000);
}
static bool ivch_get_hw_state(struct intel_dvo_device *dvo)
{
uint16_t vr01;
ivch_reset(dvo);
if (!ivch_read(dvo, VR01, &vr01))
return false;
if (vr01 & VR01_LCD_ENABLE)
return true;
else
return false;
}
static void ivch_mode_set(struct intel_dvo_device *dvo,
const struct drm_display_mode *mode,
const struct drm_display_mode *adjusted_mode)
{
struct ivch_priv *priv = dvo->dev_priv;
uint16_t vr40 = 0;
uint16_t vr01 = 0;
uint16_t vr10;
ivch_reset(dvo);
vr10 = priv->reg_backup[ARRAY_SIZE(backup_addresses) - 1];
vr10 &= VR10_INTERFACE_DEPTH_MASK;
if (vr10 == VR10_INTERFACE_2X18 || vr10 == VR10_INTERFACE_1X18)
vr01 = VR01_DITHER_ENABLE;
vr40 = (VR40_STALL_ENABLE | VR40_VERTICAL_INTERP_ENABLE |
VR40_HORIZONTAL_INTERP_ENABLE);
if (mode->hdisplay != adjusted_mode->crtc_hdisplay ||
mode->vdisplay != adjusted_mode->crtc_vdisplay) {
uint16_t x_ratio, y_ratio;
vr01 |= VR01_PANEL_FIT_ENABLE;
vr40 |= VR40_CLOCK_GATING_ENABLE;
x_ratio = (((mode->hdisplay - 1) << 16) /
(adjusted_mode->crtc_hdisplay - 1)) >> 2;
y_ratio = (((mode->vdisplay - 1) << 16) /
(adjusted_mode->crtc_vdisplay - 1)) >> 2;
ivch_write(dvo, VR42, x_ratio);
ivch_write(dvo, VR41, y_ratio);
} else {
vr01 &= ~VR01_PANEL_FIT_ENABLE;
vr40 &= ~VR40_CLOCK_GATING_ENABLE;
}
vr40 &= ~VR40_AUTO_RATIO_ENABLE;
ivch_write(dvo, VR01, vr01);
ivch_write(dvo, VR40, vr40);
}
static void ivch_dump_regs(struct intel_dvo_device *dvo)
{
uint16_t val;
ivch_read(dvo, VR00, &val);
DRM_DEBUG_KMS("VR00: 0x%04x\n", val);
ivch_read(dvo, VR01, &val);
DRM_DEBUG_KMS("VR01: 0x%04x\n", val);
ivch_read(dvo, VR10, &val);
DRM_DEBUG_KMS("VR10: 0x%04x\n", val);
ivch_read(dvo, VR30, &val);
DRM_DEBUG_KMS("VR30: 0x%04x\n", val);
ivch_read(dvo, VR40, &val);
DRM_DEBUG_KMS("VR40: 0x%04x\n", val);
ivch_read(dvo, VR80, &val);
DRM_DEBUG_KMS("VR80: 0x%04x\n", val);
ivch_read(dvo, VR81, &val);
DRM_DEBUG_KMS("VR81: 0x%04x\n", val);
ivch_read(dvo, VR82, &val);
DRM_DEBUG_KMS("VR82: 0x%04x\n", val);
ivch_read(dvo, VR83, &val);
DRM_DEBUG_KMS("VR83: 0x%04x\n", val);
ivch_read(dvo, VR84, &val);
DRM_DEBUG_KMS("VR84: 0x%04x\n", val);
ivch_read(dvo, VR85, &val);
DRM_DEBUG_KMS("VR85: 0x%04x\n", val);
ivch_read(dvo, VR86, &val);
DRM_DEBUG_KMS("VR86: 0x%04x\n", val);
ivch_read(dvo, VR87, &val);
DRM_DEBUG_KMS("VR87: 0x%04x\n", val);
ivch_read(dvo, VR88, &val);
DRM_DEBUG_KMS("VR88: 0x%04x\n", val);
ivch_read(dvo, VR8E, &val);
DRM_DEBUG_KMS("VR8E: 0x%04x\n", val);
ivch_read(dvo, VR8F, &val);
DRM_DEBUG_KMS("VR8F: 0x%04x\n", val);
}
static void ivch_destroy(struct intel_dvo_device *dvo)
{
struct ivch_priv *priv = dvo->dev_priv;
if (priv) {
kfree(priv);
dvo->dev_priv = NULL;
}
}
