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
};
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
static void ivch_dpms(struct intel_dvo_device *dvo, int mode)
{
int i;
uint16_t vr01, vr30, backlight;
if (!ivch_read(dvo, VR01, &vr01))
return;
if (mode == DRM_MODE_DPMS_ON)
backlight = 1;
else
backlight = 0;
ivch_write(dvo, VR80, backlight);
if (mode == DRM_MODE_DPMS_ON)
vr01 |= VR01_LCD_ENABLE | VR01_DVO_ENABLE;
else
vr01 &= ~(VR01_LCD_ENABLE | VR01_DVO_ENABLE);
ivch_write(dvo, VR01, vr01);
for (i = 0; i < 100; i++) {
if (!ivch_read(dvo, VR30, &vr30))
break;
if (((vr30 & VR30_PANEL_ON) != 0) == (mode == DRM_MODE_DPMS_ON))
break;
udelay(1000);
}
udelay(16 * 1000);
}
static void ivch_mode_set(struct intel_dvo_device *dvo,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
uint16_t vr40 = 0;
uint16_t vr01;
vr01 = 0;
vr40 = (VR40_STALL_ENABLE | VR40_VERTICAL_INTERP_ENABLE |
VR40_HORIZONTAL_INTERP_ENABLE);
if (mode->hdisplay != adjusted_mode->hdisplay ||
mode->vdisplay != adjusted_mode->vdisplay) {
uint16_t x_ratio, y_ratio;
vr01 |= VR01_PANEL_FIT_ENABLE;
vr40 |= VR40_CLOCK_GATING_ENABLE;
x_ratio = (((mode->hdisplay - 1) << 16) /
(adjusted_mode->hdisplay - 1)) >> 2;
y_ratio = (((mode->vdisplay - 1) << 16) /
(adjusted_mode->vdisplay - 1)) >> 2;
ivch_write (dvo, VR42, x_ratio);
ivch_write (dvo, VR41, y_ratio);
} else {
vr01 &= ~VR01_PANEL_FIT_ENABLE;
vr40 &= ~VR40_CLOCK_GATING_ENABLE;
}
vr40 &= ~VR40_AUTO_RATIO_ENABLE;
ivch_write(dvo, VR01, vr01);
ivch_write(dvo, VR40, vr40);
ivch_dump_regs(dvo);
}
static void ivch_dump_regs(struct intel_dvo_device *dvo)
{
uint16_t val;
ivch_read(dvo, VR00, &val);
DRM_LOG_KMS("VR00: 0x%04x\n", val);
ivch_read(dvo, VR01, &val);
DRM_LOG_KMS("VR01: 0x%04x\n", val);
ivch_read(dvo, VR30, &val);
DRM_LOG_KMS("VR30: 0x%04x\n", val);
ivch_read(dvo, VR40, &val);
DRM_LOG_KMS("VR40: 0x%04x\n", val);
ivch_read(dvo, VR80, &val);
DRM_LOG_KMS("VR80: 0x%04x\n", val);
ivch_read(dvo, VR81, &val);
DRM_LOG_KMS("VR81: 0x%04x\n", val);
ivch_read(dvo, VR82, &val);
DRM_LOG_KMS("VR82: 0x%04x\n", val);
ivch_read(dvo, VR83, &val);
DRM_LOG_KMS("VR83: 0x%04x\n", val);
ivch_read(dvo, VR84, &val);
DRM_LOG_KMS("VR84: 0x%04x\n", val);
ivch_read(dvo, VR85, &val);
DRM_LOG_KMS("VR85: 0x%04x\n", val);
ivch_read(dvo, VR86, &val);
DRM_LOG_KMS("VR86: 0x%04x\n", val);
ivch_read(dvo, VR87, &val);
DRM_LOG_KMS("VR87: 0x%04x\n", val);
ivch_read(dvo, VR88, &val);
DRM_LOG_KMS("VR88: 0x%04x\n", val);
ivch_read(dvo, VR8E, &val);
DRM_LOG_KMS("VR8E: 0x%04x\n", val);
ivch_read(dvo, VR8F, &val);
DRM_LOG_KMS("VR8F: 0x%04x\n", val);
}
static void ivch_destroy(struct intel_dvo_device *dvo)
{
struct ivch_priv *priv = dvo->dev_priv;
if (priv) {
kfree(priv);
dvo->dev_priv = NULL;
}
}
