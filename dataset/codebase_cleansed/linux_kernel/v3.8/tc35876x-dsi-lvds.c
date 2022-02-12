static int tc35876x_regw(struct i2c_client *client, u16 reg, u32 value)
{
int r;
u8 tx_data[] = {
(reg >> 8) & 0xff,
reg & 0xff,
value & 0xff,
(value >> 8) & 0xff,
(value >> 16) & 0xff,
(value >> 24) & 0xff,
};
struct i2c_msg msgs[] = {
{
.addr = client->addr,
.flags = 0,
.buf = tx_data,
.len = ARRAY_SIZE(tx_data),
},
};
r = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
if (r < 0) {
dev_err(&client->dev, "%s: reg 0x%04x val 0x%08x error %d\n",
__func__, reg, value, r);
return r;
}
if (r < ARRAY_SIZE(msgs)) {
dev_err(&client->dev, "%s: reg 0x%04x val 0x%08x msgs %d\n",
__func__, reg, value, r);
return -EAGAIN;
}
dev_dbg(&client->dev, "%s: reg 0x%04x val 0x%08x\n",
__func__, reg, value);
return 0;
}
static int tc35876x_regr(struct i2c_client *client, u16 reg, u32 *value)
{
int r;
u8 tx_data[] = {
(reg >> 8) & 0xff,
reg & 0xff,
};
u8 rx_data[4];
struct i2c_msg msgs[] = {
{
.addr = client->addr,
.flags = 0,
.buf = tx_data,
.len = ARRAY_SIZE(tx_data),
},
{
.addr = client->addr,
.flags = I2C_M_RD,
.buf = rx_data,
.len = ARRAY_SIZE(rx_data),
},
};
r = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
if (r < 0) {
dev_err(&client->dev, "%s: reg 0x%04x error %d\n", __func__,
reg, r);
return r;
}
if (r < ARRAY_SIZE(msgs)) {
dev_err(&client->dev, "%s: reg 0x%04x msgs %d\n", __func__,
reg, r);
return -EAGAIN;
}
*value = rx_data[0] << 24 | rx_data[1] << 16 |
rx_data[2] << 8 | rx_data[3];
dev_dbg(&client->dev, "%s: reg 0x%04x value 0x%08x\n", __func__,
reg, *value);
return 0;
}
void tc35876x_set_bridge_reset_state(struct drm_device *dev, int state)
{
struct tc35876x_platform_data *pdata;
if (WARN(!tc35876x_client, "%s called before probe", __func__))
return;
dev_dbg(&tc35876x_client->dev, "%s: state %d\n", __func__, state);
pdata = dev_get_platdata(&tc35876x_client->dev);
if (pdata->gpio_bridge_reset == -1)
return;
if (state) {
gpio_set_value_cansleep(pdata->gpio_bridge_reset, 0);
mdelay(10);
} else {
gpio_set_value_cansleep(pdata->gpio_bridge_reset, 0);
mdelay(20);
gpio_set_value_cansleep(pdata->gpio_bridge_reset, 1);
mdelay(40);
}
}
void tc35876x_configure_lvds_bridge(struct drm_device *dev)
{
struct i2c_client *i2c = tc35876x_client;
u32 ppi_lptxtimecnt;
u32 txtagocnt;
u32 txtasurecnt;
u32 id;
if (WARN(!tc35876x_client, "%s called before probe", __func__))
return;
dev_dbg(&tc35876x_client->dev, "%s\n", __func__);
if (!tc35876x_regr(i2c, IDREG, &id))
dev_info(&tc35876x_client->dev, "tc35876x ID 0x%08x\n", id);
else
dev_err(&tc35876x_client->dev, "Cannot read ID\n");
ppi_lptxtimecnt = 4;
txtagocnt = (5 * ppi_lptxtimecnt - 3) / 4;
txtasurecnt = 3 * ppi_lptxtimecnt / 2;
tc35876x_regw(i2c, PPI_TX_RX_TA, FLD_VAL(txtagocnt, 26, 16) |
FLD_VAL(txtasurecnt, 10, 0));
tc35876x_regw(i2c, PPI_LPTXTIMECNT, FLD_VAL(ppi_lptxtimecnt, 10, 0));
tc35876x_regw(i2c, PPI_D0S_CLRSIPOCOUNT, FLD_VAL(1, 5, 0));
tc35876x_regw(i2c, PPI_D1S_CLRSIPOCOUNT, FLD_VAL(1, 5, 0));
tc35876x_regw(i2c, PPI_D2S_CLRSIPOCOUNT, FLD_VAL(1, 5, 0));
tc35876x_regw(i2c, PPI_D3S_CLRSIPOCOUNT, FLD_VAL(1, 5, 0));
tc35876x_regw(i2c, PPI_LANEENABLE,
BIT(4) | BIT(3) | BIT(2) | BIT(1) | BIT(0));
tc35876x_regw(i2c, DSI_LANEENABLE,
BIT(4) | BIT(3) | BIT(2) | BIT(1) | BIT(0));
tc35876x_regw(i2c, PPI_STARTPPI, BIT(0));
tc35876x_regw(i2c, DSI_STARTDSI, BIT(0));
tc35876x_regw(i2c, LVPHY0, FLD_VAL(1, 20, 16) |
FLD_VAL(2, 15, 14) | FLD_VAL(6, 4, 0));
tc35876x_regw(i2c, VPCTRL, BIT(8) | BIT(5));
tc35876x_regw(i2c, HTIM1, FLD_VAL(40, 24, 16) | FLD_VAL(40, 8, 0));
tc35876x_regw(i2c, HTIM2, FLD_VAL(80, 24, 16) | FLD_VAL(1280, 10, 0));
tc35876x_regw(i2c, VTIM1, FLD_VAL(14, 23, 16) | FLD_VAL(10, 7, 0));
tc35876x_regw(i2c, VTIM2, FLD_VAL(14, 23, 16) | FLD_VAL(800, 10, 0));
tc35876x_regw(i2c, VFUEN, BIT(0));
tc35876x_regw(i2c, SYSRST, BIT(2));
tc35876x_regw(i2c, LVMX0003,
INPUT_MUX(INPUT_R5, INPUT_R4, INPUT_R3, INPUT_R2));
tc35876x_regw(i2c, LVMX0407,
INPUT_MUX(INPUT_G2, INPUT_R7, INPUT_R1, INPUT_R6));
tc35876x_regw(i2c, LVMX0811,
INPUT_MUX(INPUT_G1, INPUT_G0, INPUT_G4, INPUT_G3));
tc35876x_regw(i2c, LVMX1215,
INPUT_MUX(INPUT_B2, INPUT_G7, INPUT_G6, INPUT_G5));
tc35876x_regw(i2c, LVMX1619,
INPUT_MUX(INPUT_B4, INPUT_B3, INPUT_B1, INPUT_B0));
tc35876x_regw(i2c, LVMX2023,
INPUT_MUX(LOGIC_0, INPUT_B7, INPUT_B6, INPUT_B5));
tc35876x_regw(i2c, LVMX2427,
INPUT_MUX(INPUT_R0, INPUT_DE, INPUT_VSYNC, INPUT_HSYNC));
tc35876x_regw(i2c, LVCFG, BIT(0));
tc35876x_regw(i2c, DSI_INTCLR, FLD_MASK(31, 30) | FLD_MASK(22, 0));
}
static inline u16 calc_clkdiv(unsigned long baseclk, unsigned int f)
{
return (baseclk - f) / f;
}
static void tc35876x_brightness_init(struct drm_device *dev)
{
int ret;
u8 pwmctrl;
u16 clkdiv;
ret = intel_scu_ipc_ioread8(GPIOPWMCTRL, &pwmctrl);
if (ret || pwmctrl != 0x01) {
if (ret)
dev_err(&dev->pdev->dev, "GPIOPWMCTRL read failed\n");
else
dev_warn(&dev->pdev->dev, "GPIOPWMCTRL was not set to system clock (pwmctrl = 0x%02x)\n", pwmctrl);
ret = intel_scu_ipc_iowrite8(GPIOPWMCTRL, 0x01);
if (ret)
dev_err(&dev->pdev->dev, "GPIOPWMCTRL set failed\n");
}
clkdiv = calc_clkdiv(SYSTEMCLK, PWM_FREQUENCY);
ret = intel_scu_ipc_iowrite8(PWM0CLKDIV1, (clkdiv >> 8) & 0xff);
if (!ret)
ret = intel_scu_ipc_iowrite8(PWM0CLKDIV0, clkdiv & 0xff);
if (ret)
dev_err(&dev->pdev->dev, "PWM0CLKDIV set failed\n");
else
dev_dbg(&dev->pdev->dev, "PWM0CLKDIV set to 0x%04x (%d Hz)\n",
clkdiv, PWM_FREQUENCY);
}
void tc35876x_brightness_control(struct drm_device *dev, int level)
{
int ret;
u8 duty_val;
u8 panel_duty_val;
level = clamp(level, 0, MDFLD_DSI_BRIGHTNESS_MAX_LEVEL);
duty_val = level * 0x63 / MDFLD_DSI_BRIGHTNESS_MAX_LEVEL;
panel_duty_val = (2 * level - 100) * 0xA9 /
MDFLD_DSI_BRIGHTNESS_MAX_LEVEL + 0x56;
ret = intel_scu_ipc_iowrite8(PWM0DUTYCYCLE, duty_val);
if (ret)
dev_err(&tc35876x_client->dev, "%s: ipc write fail\n",
__func__);
if (cmi_lcd_i2c_client) {
ret = i2c_smbus_write_byte_data(cmi_lcd_i2c_client,
PANEL_PWM_MAX, panel_duty_val);
if (ret < 0)
dev_err(&cmi_lcd_i2c_client->dev, "%s: i2c write failed\n",
__func__);
}
}
void tc35876x_toshiba_bridge_panel_off(struct drm_device *dev)
{
struct tc35876x_platform_data *pdata;
if (WARN(!tc35876x_client, "%s called before probe", __func__))
return;
dev_dbg(&tc35876x_client->dev, "%s\n", __func__);
pdata = dev_get_platdata(&tc35876x_client->dev);
if (pdata->gpio_panel_bl_en != -1)
gpio_set_value_cansleep(pdata->gpio_panel_bl_en, 0);
if (pdata->gpio_panel_vadd != -1)
gpio_set_value_cansleep(pdata->gpio_panel_vadd, 0);
}
void tc35876x_toshiba_bridge_panel_on(struct drm_device *dev)
{
struct tc35876x_platform_data *pdata;
struct drm_psb_private *dev_priv = dev->dev_private;
if (WARN(!tc35876x_client, "%s called before probe", __func__))
return;
dev_dbg(&tc35876x_client->dev, "%s\n", __func__);
pdata = dev_get_platdata(&tc35876x_client->dev);
if (pdata->gpio_panel_vadd != -1) {
gpio_set_value_cansleep(pdata->gpio_panel_vadd, 1);
msleep(260);
}
if (cmi_lcd_i2c_client) {
int ret;
dev_dbg(&cmi_lcd_i2c_client->dev, "setting TCON\n");
ret = i2c_smbus_write_byte_data(cmi_lcd_i2c_client,
PANEL_ALLOW_DISTORT, 0x10);
if (ret < 0)
dev_err(&cmi_lcd_i2c_client->dev,
"i2c write failed (%d)\n", ret);
ret = i2c_smbus_write_byte_data(cmi_lcd_i2c_client,
PANEL_BYPASS_PWMI, 0);
if (ret < 0)
dev_err(&cmi_lcd_i2c_client->dev,
"i2c write failed (%d)\n", ret);
ret = i2c_smbus_write_byte_data(cmi_lcd_i2c_client,
PANEL_PWM_MIN, 0x35);
if (ret < 0)
dev_err(&cmi_lcd_i2c_client->dev,
"i2c write failed (%d)\n", ret);
}
if (pdata->gpio_panel_bl_en != -1)
gpio_set_value_cansleep(pdata->gpio_panel_bl_en, 1);
tc35876x_brightness_control(dev, dev_priv->brightness_adjusted);
}
static struct drm_display_mode *tc35876x_get_config_mode(struct drm_device *dev)
{
struct drm_display_mode *mode;
dev_dbg(&dev->pdev->dev, "%s\n", __func__);
mode = kzalloc(sizeof(*mode), GFP_KERNEL);
if (!mode)
return NULL;
mode->hdisplay = 1280;
mode->vdisplay = 800;
mode->hsync_start = 1360;
mode->hsync_end = 1400;
mode->htotal = 1440;
mode->vsync_start = 814;
mode->vsync_end = 824;
mode->vtotal = 838;
mode->clock = 33324 << 1;
dev_info(&dev->pdev->dev, "hdisplay(w) = %d\n", mode->hdisplay);
dev_info(&dev->pdev->dev, "vdisplay(h) = %d\n", mode->vdisplay);
dev_info(&dev->pdev->dev, "HSS = %d\n", mode->hsync_start);
dev_info(&dev->pdev->dev, "HSE = %d\n", mode->hsync_end);
dev_info(&dev->pdev->dev, "htotal = %d\n", mode->htotal);
dev_info(&dev->pdev->dev, "VSS = %d\n", mode->vsync_start);
dev_info(&dev->pdev->dev, "VSE = %d\n", mode->vsync_end);
dev_info(&dev->pdev->dev, "vtotal = %d\n", mode->vtotal);
dev_info(&dev->pdev->dev, "clock = %d\n", mode->clock);
drm_mode_set_name(mode);
drm_mode_set_crtcinfo(mode, 0);
mode->type |= DRM_MODE_TYPE_PREFERRED;
return mode;
}
static int tc35876x_get_panel_info(struct drm_device *dev, int pipe,
struct panel_info *pi)
{
if (!dev || !pi)
return -EINVAL;
pi->width_mm = DV1_PANEL_WIDTH;
pi->height_mm = DV1_PANEL_HEIGHT;
return 0;
}
static int tc35876x_bridge_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tc35876x_platform_data *pdata;
dev_info(&client->dev, "%s\n", __func__);
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_err(&client->dev, "%s: i2c_check_functionality() failed\n",
__func__);
return -ENODEV;
}
pdata = dev_get_platdata(&client->dev);
if (!pdata) {
dev_err(&client->dev, "%s: no platform data\n", __func__);
return -ENODEV;
}
if (pdata->gpio_bridge_reset != -1) {
gpio_request(pdata->gpio_bridge_reset, "tc35876x bridge reset");
gpio_direction_output(pdata->gpio_bridge_reset, 0);
}
if (pdata->gpio_panel_bl_en != -1) {
gpio_request(pdata->gpio_panel_bl_en, "tc35876x panel bl en");
gpio_direction_output(pdata->gpio_panel_bl_en, 0);
}
if (pdata->gpio_panel_vadd != -1) {
gpio_request(pdata->gpio_panel_vadd, "tc35876x panel vadd");
gpio_direction_output(pdata->gpio_panel_vadd, 0);
}
tc35876x_client = client;
return 0;
}
static int tc35876x_bridge_remove(struct i2c_client *client)
{
struct tc35876x_platform_data *pdata = dev_get_platdata(&client->dev);
dev_dbg(&client->dev, "%s\n", __func__);
if (pdata->gpio_bridge_reset != -1)
gpio_free(pdata->gpio_bridge_reset);
if (pdata->gpio_panel_bl_en != -1)
gpio_free(pdata->gpio_panel_bl_en);
if (pdata->gpio_panel_vadd != -1)
gpio_free(pdata->gpio_panel_vadd);
tc35876x_client = NULL;
return 0;
}
static int cmi_lcd_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
dev_info(&client->dev, "%s\n", __func__);
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_err(&client->dev, "%s: i2c_check_functionality() failed\n",
__func__);
return -ENODEV;
}
cmi_lcd_i2c_client = client;
return 0;
}
static int cmi_lcd_i2c_remove(struct i2c_client *client)
{
dev_dbg(&client->dev, "%s\n", __func__);
cmi_lcd_i2c_client = NULL;
return 0;
}
static int cmi_lcd_hack_create_device(void)
{
struct i2c_adapter *adapter;
struct i2c_client *client;
struct i2c_board_info info = {
.type = "cmi-lcd",
.addr = CMI_LCD_I2C_ADDR,
};
pr_debug("%s\n", __func__);
adapter = i2c_get_adapter(CMI_LCD_I2C_ADAPTER);
if (!adapter) {
pr_err("%s: i2c_get_adapter(%d) failed\n", __func__,
CMI_LCD_I2C_ADAPTER);
return -EINVAL;
}
client = i2c_new_device(adapter, &info);
if (!client) {
pr_err("%s: i2c_new_device() failed\n", __func__);
i2c_put_adapter(adapter);
return -EINVAL;
}
return 0;
}
void tc35876x_init(struct drm_device *dev)
{
int r;
dev_dbg(&dev->pdev->dev, "%s\n", __func__);
cmi_lcd_hack_create_device();
r = i2c_add_driver(&cmi_lcd_i2c_driver);
if (r < 0)
dev_err(&dev->pdev->dev,
"%s: i2c_add_driver() for %s failed (%d)\n",
__func__, cmi_lcd_i2c_driver.driver.name, r);
r = i2c_add_driver(&tc35876x_bridge_i2c_driver);
if (r < 0)
dev_err(&dev->pdev->dev,
"%s: i2c_add_driver() for %s failed (%d)\n",
__func__, tc35876x_bridge_i2c_driver.driver.name, r);
tc35876x_brightness_init(dev);
}
void tc35876x_exit(void)
{
pr_debug("%s\n", __func__);
i2c_del_driver(&tc35876x_bridge_i2c_driver);
if (cmi_lcd_i2c_client)
i2c_del_driver(&cmi_lcd_i2c_driver);
}
