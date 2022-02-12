static bool ch7017_read(struct intel_dvo_device *dvo, u8 addr, u8 *val)
{
struct i2c_msg msgs[] = {
{
.addr = dvo->slave_addr,
.flags = 0,
.len = 1,
.buf = &addr,
},
{
.addr = dvo->slave_addr,
.flags = I2C_M_RD,
.len = 1,
.buf = val,
}
};
return i2c_transfer(dvo->i2c_bus, msgs, 2) == 2;
}
static bool ch7017_write(struct intel_dvo_device *dvo, u8 addr, u8 val)
{
uint8_t buf[2] = { addr, val };
struct i2c_msg msg = {
.addr = dvo->slave_addr,
.flags = 0,
.len = 2,
.buf = buf,
};
return i2c_transfer(dvo->i2c_bus, &msg, 1) == 1;
}
static bool ch7017_init(struct intel_dvo_device *dvo,
struct i2c_adapter *adapter)
{
struct ch7017_priv *priv;
const char *str;
u8 val;
priv = kzalloc(sizeof(struct ch7017_priv), GFP_KERNEL);
if (priv == NULL)
return false;
dvo->i2c_bus = adapter;
dvo->dev_priv = priv;
if (!ch7017_read(dvo, CH7017_DEVICE_ID, &val))
goto fail;
switch (val) {
case CH7017_DEVICE_ID_VALUE:
str = "ch7017";
break;
case CH7018_DEVICE_ID_VALUE:
str = "ch7018";
break;
case CH7019_DEVICE_ID_VALUE:
str = "ch7019";
break;
default:
DRM_DEBUG_KMS("ch701x not detected, got %d: from %s "
"slave %d.\n",
val, adapter->name, dvo->slave_addr);
goto fail;
}
DRM_DEBUG_KMS("%s detected on %s, addr %d\n",
str, adapter->name, dvo->slave_addr);
return true;
fail:
kfree(priv);
return false;
}
static enum drm_connector_status ch7017_detect(struct intel_dvo_device *dvo)
{
return connector_status_connected;
}
static enum drm_mode_status ch7017_mode_valid(struct intel_dvo_device *dvo,
struct drm_display_mode *mode)
{
if (mode->clock > 160000)
return MODE_CLOCK_HIGH;
return MODE_OK;
}
static void ch7017_mode_set(struct intel_dvo_device *dvo,
const struct drm_display_mode *mode,
const struct drm_display_mode *adjusted_mode)
{
uint8_t lvds_pll_feedback_div, lvds_pll_vco_control;
uint8_t outputs_enable, lvds_control_2, lvds_power_down;
uint8_t horizontal_active_pixel_input;
uint8_t horizontal_active_pixel_output, vertical_active_line_output;
uint8_t active_input_line_output;
DRM_DEBUG_KMS("Registers before mode setting\n");
ch7017_dump_regs(dvo);
if (mode->clock < 100000) {
outputs_enable = CH7017_LVDS_CHANNEL_A | CH7017_CHARGE_PUMP_LOW;
lvds_pll_feedback_div = CH7017_LVDS_PLL_FEEDBACK_DEFAULT_RESERVED |
(2 << CH7017_LVDS_PLL_FEED_BACK_DIVIDER_SHIFT) |
(13 << CH7017_LVDS_PLL_FEED_FORWARD_DIVIDER_SHIFT);
lvds_pll_vco_control = CH7017_LVDS_PLL_VCO_DEFAULT_RESERVED |
(2 << CH7017_LVDS_PLL_VCO_SHIFT) |
(3 << CH7017_LVDS_PLL_POST_SCALE_DIV_SHIFT);
lvds_control_2 = (1 << CH7017_LOOP_FILTER_SHIFT) |
(0 << CH7017_PHASE_DETECTOR_SHIFT);
} else {
outputs_enable = CH7017_LVDS_CHANNEL_A | CH7017_CHARGE_PUMP_HIGH;
lvds_pll_feedback_div = CH7017_LVDS_PLL_FEEDBACK_DEFAULT_RESERVED |
(2 << CH7017_LVDS_PLL_FEED_BACK_DIVIDER_SHIFT) |
(3 << CH7017_LVDS_PLL_FEED_FORWARD_DIVIDER_SHIFT);
lvds_pll_feedback_div = 35;
lvds_control_2 = (3 << CH7017_LOOP_FILTER_SHIFT) |
(0 << CH7017_PHASE_DETECTOR_SHIFT);
if (1) {
outputs_enable |= CH7017_LVDS_CHANNEL_B;
lvds_pll_vco_control = CH7017_LVDS_PLL_VCO_DEFAULT_RESERVED |
(2 << CH7017_LVDS_PLL_VCO_SHIFT) |
(13 << CH7017_LVDS_PLL_POST_SCALE_DIV_SHIFT);
} else {
lvds_pll_vco_control = CH7017_LVDS_PLL_VCO_DEFAULT_RESERVED |
(1 << CH7017_LVDS_PLL_VCO_SHIFT) |
(13 << CH7017_LVDS_PLL_POST_SCALE_DIV_SHIFT);
}
}
horizontal_active_pixel_input = mode->hdisplay & 0x00ff;
vertical_active_line_output = mode->vdisplay & 0x00ff;
horizontal_active_pixel_output = mode->hdisplay & 0x00ff;
active_input_line_output = ((mode->hdisplay & 0x0700) >> 8) |
(((mode->vdisplay & 0x0700) >> 8) << 3);
lvds_power_down = CH7017_LVDS_POWER_DOWN_DEFAULT_RESERVED |
(mode->hdisplay & 0x0700) >> 8;
ch7017_dpms(dvo, false);
ch7017_write(dvo, CH7017_HORIZONTAL_ACTIVE_PIXEL_INPUT,
horizontal_active_pixel_input);
ch7017_write(dvo, CH7017_HORIZONTAL_ACTIVE_PIXEL_OUTPUT,
horizontal_active_pixel_output);
ch7017_write(dvo, CH7017_VERTICAL_ACTIVE_LINE_OUTPUT,
vertical_active_line_output);
ch7017_write(dvo, CH7017_ACTIVE_INPUT_LINE_OUTPUT,
active_input_line_output);
ch7017_write(dvo, CH7017_LVDS_PLL_VCO_CONTROL, lvds_pll_vco_control);
ch7017_write(dvo, CH7017_LVDS_PLL_FEEDBACK_DIV, lvds_pll_feedback_div);
ch7017_write(dvo, CH7017_LVDS_CONTROL_2, lvds_control_2);
ch7017_write(dvo, CH7017_OUTPUTS_ENABLE, outputs_enable);
ch7017_write(dvo, CH7017_LVDS_POWER_DOWN, lvds_power_down);
DRM_DEBUG_KMS("Registers after mode setting\n");
ch7017_dump_regs(dvo);
}
static void ch7017_dpms(struct intel_dvo_device *dvo, bool enable)
{
uint8_t val;
ch7017_read(dvo, CH7017_LVDS_POWER_DOWN, &val);
ch7017_write(dvo, CH7017_POWER_MANAGEMENT,
CH7017_DAC0_POWER_DOWN |
CH7017_DAC1_POWER_DOWN |
CH7017_DAC2_POWER_DOWN |
CH7017_DAC3_POWER_DOWN |
CH7017_TV_POWER_DOWN_EN);
if (enable) {
ch7017_write(dvo, CH7017_LVDS_POWER_DOWN,
val & ~CH7017_LVDS_POWER_DOWN_EN);
} else {
ch7017_write(dvo, CH7017_LVDS_POWER_DOWN,
val | CH7017_LVDS_POWER_DOWN_EN);
}
msleep(20);
}
static bool ch7017_get_hw_state(struct intel_dvo_device *dvo)
{
uint8_t val;
ch7017_read(dvo, CH7017_LVDS_POWER_DOWN, &val);
if (val & CH7017_LVDS_POWER_DOWN_EN)
return false;
else
return true;
}
static void ch7017_dump_regs(struct intel_dvo_device *dvo)
{
uint8_t val;
#define DUMP(reg) \
do { \
ch7017_read(dvo, reg, &val); \
DRM_DEBUG_KMS(#reg ": %02x\n", val); \
} while (0)
DUMP(CH7017_HORIZONTAL_ACTIVE_PIXEL_INPUT);
DUMP(CH7017_HORIZONTAL_ACTIVE_PIXEL_OUTPUT);
DUMP(CH7017_VERTICAL_ACTIVE_LINE_OUTPUT);
DUMP(CH7017_ACTIVE_INPUT_LINE_OUTPUT);
DUMP(CH7017_LVDS_PLL_VCO_CONTROL);
DUMP(CH7017_LVDS_PLL_FEEDBACK_DIV);
DUMP(CH7017_LVDS_CONTROL_2);
DUMP(CH7017_OUTPUTS_ENABLE);
DUMP(CH7017_LVDS_POWER_DOWN);
}
static void ch7017_destroy(struct intel_dvo_device *dvo)
{
struct ch7017_priv *priv = dvo->dev_priv;
if (priv) {
kfree(priv);
dvo->dev_priv = NULL;
}
}
