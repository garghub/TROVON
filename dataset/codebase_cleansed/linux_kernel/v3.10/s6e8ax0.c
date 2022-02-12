static void s6e8ax0_regulator_enable(struct s6e8ax0 *lcd)
{
int ret = 0;
struct lcd_platform_data *pd = NULL;
pd = lcd->ddi_pd;
mutex_lock(&lcd->lock);
if (!lcd->enabled) {
ret = regulator_bulk_enable(ARRAY_SIZE(supplies), supplies);
if (ret)
goto out;
lcd->enabled = true;
}
msleep(pd->power_on_delay);
out:
mutex_unlock(&lcd->lock);
}
static void s6e8ax0_regulator_disable(struct s6e8ax0 *lcd)
{
int ret = 0;
mutex_lock(&lcd->lock);
if (lcd->enabled) {
ret = regulator_bulk_disable(ARRAY_SIZE(supplies), supplies);
if (ret)
goto out;
lcd->enabled = false;
}
out:
mutex_unlock(&lcd->lock);
}
static void s6e8ax0_panel_cond(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
static const unsigned char data_to_send[] = {
0xf8, 0x3d, 0x35, 0x00, 0x00, 0x00, 0x93, 0x00, 0x3c, 0x7d,
0x08, 0x27, 0x7d, 0x3f, 0x00, 0x00, 0x00, 0x20, 0x04, 0x08,
0x6e, 0x00, 0x00, 0x00, 0x02, 0x08, 0x08, 0x23, 0x23, 0xc0,
0xc8, 0x08, 0x48, 0xc1, 0x00, 0xc1, 0xff, 0xff, 0xc8
};
static const unsigned char data_to_send_panel_reverse[] = {
0xf8, 0x19, 0x35, 0x00, 0x00, 0x00, 0x93, 0x00, 0x3c, 0x7d,
0x08, 0x27, 0x7d, 0x3f, 0x00, 0x00, 0x00, 0x20, 0x04, 0x08,
0x6e, 0x00, 0x00, 0x00, 0x02, 0x08, 0x08, 0x23, 0x23, 0xc0,
0xc1, 0x01, 0x41, 0xc1, 0x00, 0xc1, 0xf6, 0xf6, 0xc1
};
if (lcd->dsim_dev->panel_reverse)
ops->cmd_write(lcd_to_master(lcd), MIPI_DSI_DCS_LONG_WRITE,
data_to_send_panel_reverse,
ARRAY_SIZE(data_to_send_panel_reverse));
else
ops->cmd_write(lcd_to_master(lcd), MIPI_DSI_DCS_LONG_WRITE,
data_to_send, ARRAY_SIZE(data_to_send));
}
static void s6e8ax0_display_cond(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
static const unsigned char data_to_send[] = {
0xf2, 0x80, 0x03, 0x0d
};
ops->cmd_write(lcd_to_master(lcd), MIPI_DSI_DCS_LONG_WRITE,
data_to_send, ARRAY_SIZE(data_to_send));
}
static void s6e8ax0_gamma_cond(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
unsigned int gamma = lcd->bd->props.brightness;
ops->cmd_write(lcd_to_master(lcd), MIPI_DSI_DCS_LONG_WRITE,
s6e8ax0_22_gamma_table[gamma],
GAMMA_TABLE_COUNT);
}
static void s6e8ax0_gamma_update(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
static const unsigned char data_to_send[] = {
0xf7, 0x03
};
ops->cmd_write(lcd_to_master(lcd),
MIPI_DSI_DCS_SHORT_WRITE_PARAM, data_to_send,
ARRAY_SIZE(data_to_send));
}
static void s6e8ax0_etc_cond1(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
static const unsigned char data_to_send[] = {
0xd1, 0xfe, 0x80, 0x00, 0x01, 0x0b, 0x00, 0x00, 0x40,
0x0d, 0x00, 0x00
};
ops->cmd_write(lcd_to_master(lcd), MIPI_DSI_DCS_LONG_WRITE,
data_to_send, ARRAY_SIZE(data_to_send));
}
static void s6e8ax0_etc_cond2(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
static const unsigned char data_to_send[] = {
0xb6, 0x0c, 0x02, 0x03, 0x32, 0xff, 0x44, 0x44, 0xc0,
0x00
};
ops->cmd_write(lcd_to_master(lcd), MIPI_DSI_DCS_LONG_WRITE,
data_to_send, ARRAY_SIZE(data_to_send));
}
static void s6e8ax0_etc_cond3(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
static const unsigned char data_to_send[] = {
0xe1, 0x10, 0x1c, 0x17, 0x08, 0x1d
};
ops->cmd_write(lcd_to_master(lcd), MIPI_DSI_DCS_LONG_WRITE,
data_to_send, ARRAY_SIZE(data_to_send));
}
static void s6e8ax0_etc_cond4(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
static const unsigned char data_to_send[] = {
0xe2, 0xed, 0x07, 0xc3, 0x13, 0x0d, 0x03
};
ops->cmd_write(lcd_to_master(lcd), MIPI_DSI_DCS_LONG_WRITE,
data_to_send, ARRAY_SIZE(data_to_send));
}
static void s6e8ax0_etc_cond5(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
static const unsigned char data_to_send[] = {
0xf4, 0xcf, 0x0a, 0x12, 0x10, 0x19, 0x33, 0x02
};
ops->cmd_write(lcd_to_master(lcd), MIPI_DSI_DCS_LONG_WRITE,
data_to_send, ARRAY_SIZE(data_to_send));
}
static void s6e8ax0_etc_cond6(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
static const unsigned char data_to_send[] = {
0xe3, 0x40
};
ops->cmd_write(lcd_to_master(lcd),
MIPI_DSI_DCS_SHORT_WRITE_PARAM,
data_to_send, ARRAY_SIZE(data_to_send));
}
static void s6e8ax0_etc_cond7(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
static const unsigned char data_to_send[] = {
0xe4, 0x00, 0x00, 0x14, 0x80, 0x00, 0x00, 0x00
};
ops->cmd_write(lcd_to_master(lcd), MIPI_DSI_DCS_LONG_WRITE,
data_to_send, ARRAY_SIZE(data_to_send));
}
static void s6e8ax0_elvss_set(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
static const unsigned char data_to_send[] = {
0xb1, 0x04, 0x00
};
ops->cmd_write(lcd_to_master(lcd), MIPI_DSI_DCS_LONG_WRITE,
data_to_send, ARRAY_SIZE(data_to_send));
}
static void s6e8ax0_elvss_nvm_set(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
static const unsigned char data_to_send[] = {
0xd9, 0x5c, 0x20, 0x0c, 0x0f, 0x41, 0x00, 0x10, 0x11,
0x12, 0xd1, 0x00, 0x00, 0x00, 0x00, 0x80, 0xcb, 0xed,
0x64, 0xaf
};
ops->cmd_write(lcd_to_master(lcd), MIPI_DSI_DCS_LONG_WRITE,
data_to_send, ARRAY_SIZE(data_to_send));
}
static void s6e8ax0_sleep_in(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
static const unsigned char data_to_send[] = {
0x10, 0x00
};
ops->cmd_write(lcd_to_master(lcd),
MIPI_DSI_DCS_SHORT_WRITE,
data_to_send, ARRAY_SIZE(data_to_send));
}
static void s6e8ax0_sleep_out(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
static const unsigned char data_to_send[] = {
0x11, 0x00
};
ops->cmd_write(lcd_to_master(lcd),
MIPI_DSI_DCS_SHORT_WRITE,
data_to_send, ARRAY_SIZE(data_to_send));
}
static void s6e8ax0_display_on(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
static const unsigned char data_to_send[] = {
0x29, 0x00
};
ops->cmd_write(lcd_to_master(lcd),
MIPI_DSI_DCS_SHORT_WRITE,
data_to_send, ARRAY_SIZE(data_to_send));
}
static void s6e8ax0_display_off(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
static const unsigned char data_to_send[] = {
0x28, 0x00
};
ops->cmd_write(lcd_to_master(lcd),
MIPI_DSI_DCS_SHORT_WRITE,
data_to_send, ARRAY_SIZE(data_to_send));
}
static void s6e8ax0_apply_level2_key(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
static const unsigned char data_to_send[] = {
0xf0, 0x5a, 0x5a
};
ops->cmd_write(lcd_to_master(lcd), MIPI_DSI_DCS_LONG_WRITE,
data_to_send, ARRAY_SIZE(data_to_send));
}
static void s6e8ax0_acl_on(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
static const unsigned char data_to_send[] = {
0xc0, 0x01
};
ops->cmd_write(lcd_to_master(lcd),
MIPI_DSI_DCS_SHORT_WRITE,
data_to_send, ARRAY_SIZE(data_to_send));
}
static void s6e8ax0_acl_off(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
static const unsigned char data_to_send[] = {
0xc0, 0x00
};
ops->cmd_write(lcd_to_master(lcd),
MIPI_DSI_DCS_SHORT_WRITE,
data_to_send, ARRAY_SIZE(data_to_send));
}
static void s6e8ax0_acl_ctrl_set(struct s6e8ax0 *lcd)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
static const unsigned char cutoff_50[] = {
0xc1, 0x47, 0x53, 0x13, 0x53, 0x00, 0x00, 0x02, 0xcf,
0x00, 0x00, 0x04, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x08, 0x0f, 0x16, 0x1d, 0x24, 0x2a, 0x31, 0x38,
0x3f, 0x46
};
static const unsigned char cutoff_45[] = {
0xc1, 0x47, 0x53, 0x13, 0x53, 0x00, 0x00, 0x02, 0xcf,
0x00, 0x00, 0x04, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x07, 0x0d, 0x13, 0x19, 0x1f, 0x25, 0x2b, 0x31,
0x37, 0x3d
};
static const unsigned char cutoff_40[] = {
0xc1, 0x47, 0x53, 0x13, 0x53, 0x00, 0x00, 0x02, 0xcf,
0x00, 0x00, 0x04, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x06, 0x0c, 0x11, 0x16, 0x1c, 0x21, 0x26, 0x2b,
0x31, 0x36
};
if (lcd->acl_enable) {
if (lcd->cur_acl == 0) {
if (lcd->gamma == 0 || lcd->gamma == 1) {
s6e8ax0_acl_off(lcd);
dev_dbg(&lcd->ld->dev,
"cur_acl=%d\n", lcd->cur_acl);
} else
s6e8ax0_acl_on(lcd);
}
switch (lcd->gamma) {
case 0:
s6e8ax0_acl_off(lcd);
lcd->cur_acl = 0;
break;
case 1 ... 3:
ops->cmd_write(lcd_to_master(lcd),
MIPI_DSI_DCS_LONG_WRITE,
cutoff_40,
ARRAY_SIZE(cutoff_40));
lcd->cur_acl = 40;
break;
case 4 ... 7:
ops->cmd_write(lcd_to_master(lcd),
MIPI_DSI_DCS_LONG_WRITE,
cutoff_45,
ARRAY_SIZE(cutoff_45));
lcd->cur_acl = 45;
break;
case 8 ... 10:
ops->cmd_write(lcd_to_master(lcd),
MIPI_DSI_DCS_LONG_WRITE,
cutoff_50,
ARRAY_SIZE(cutoff_50));
lcd->cur_acl = 50;
break;
default:
break;
}
} else {
s6e8ax0_acl_off(lcd);
lcd->cur_acl = 0;
dev_dbg(&lcd->ld->dev, "cur_acl = %d\n", lcd->cur_acl);
}
}
static void s6e8ax0_read_id(struct s6e8ax0 *lcd, u8 *mtp_id)
{
unsigned int ret;
unsigned int addr = 0xd1;
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
ret = ops->cmd_read(lcd_to_master(lcd),
MIPI_DSI_GENERIC_READ_REQUEST_1_PARAM,
addr, 3, mtp_id);
}
static int s6e8ax0_panel_init(struct s6e8ax0 *lcd)
{
s6e8ax0_apply_level2_key(lcd);
s6e8ax0_sleep_out(lcd);
msleep(1);
s6e8ax0_panel_cond(lcd);
s6e8ax0_display_cond(lcd);
s6e8ax0_gamma_cond(lcd);
s6e8ax0_gamma_update(lcd);
s6e8ax0_etc_cond1(lcd);
s6e8ax0_etc_cond2(lcd);
s6e8ax0_etc_cond3(lcd);
s6e8ax0_etc_cond4(lcd);
s6e8ax0_etc_cond5(lcd);
s6e8ax0_etc_cond6(lcd);
s6e8ax0_etc_cond7(lcd);
s6e8ax0_elvss_nvm_set(lcd);
s6e8ax0_elvss_set(lcd);
s6e8ax0_acl_ctrl_set(lcd);
s6e8ax0_acl_on(lcd);
msleep(lcd->ddi_pd->power_on_delay);
return 0;
}
static int s6e8ax0_update_gamma_ctrl(struct s6e8ax0 *lcd, int brightness)
{
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
ops->cmd_write(lcd_to_master(lcd), MIPI_DSI_DCS_LONG_WRITE,
s6e8ax0_22_gamma_table[brightness],
ARRAY_SIZE(s6e8ax0_22_gamma_table));
s6e8ax0_gamma_update(lcd);
lcd->gamma = brightness;
return 0;
}
static int s6e8ax0_gamma_ctrl(struct s6e8ax0 *lcd, int gamma)
{
s6e8ax0_update_gamma_ctrl(lcd, gamma);
return 0;
}
static int s6e8ax0_set_power(struct lcd_device *ld, int power)
{
struct s6e8ax0 *lcd = lcd_get_data(ld);
struct mipi_dsim_master_ops *ops = lcd_to_master_ops(lcd);
int ret = 0;
if (power != FB_BLANK_UNBLANK && power != FB_BLANK_POWERDOWN &&
power != FB_BLANK_NORMAL) {
dev_err(lcd->dev, "power value should be 0, 1 or 4.\n");
return -EINVAL;
}
if ((power == FB_BLANK_UNBLANK) && ops->set_blank_mode) {
if ((POWER_IS_ON(power) && POWER_IS_OFF(lcd->power))
|| (POWER_IS_ON(power) && POWER_IS_NRM(lcd->power))) {
ret = ops->set_blank_mode(lcd_to_master(lcd), power);
if (!ret && lcd->power != power)
lcd->power = power;
}
} else if ((power == FB_BLANK_POWERDOWN) && ops->set_early_blank_mode) {
if ((POWER_IS_OFF(power) && POWER_IS_ON(lcd->power)) ||
(POWER_IS_ON(lcd->power) && POWER_IS_NRM(power))) {
ret = ops->set_early_blank_mode(lcd_to_master(lcd),
power);
if (!ret && lcd->power != power)
lcd->power = power;
}
}
return ret;
}
static int s6e8ax0_get_power(struct lcd_device *ld)
{
struct s6e8ax0 *lcd = lcd_get_data(ld);
return lcd->power;
}
static int s6e8ax0_get_brightness(struct backlight_device *bd)
{
return bd->props.brightness;
}
static int s6e8ax0_set_brightness(struct backlight_device *bd)
{
int ret = 0, brightness = bd->props.brightness;
struct s6e8ax0 *lcd = bl_get_data(bd);
if (brightness < MIN_BRIGHTNESS ||
brightness > bd->props.max_brightness) {
dev_err(lcd->dev, "lcd brightness should be %d to %d.\n",
MIN_BRIGHTNESS, MAX_BRIGHTNESS);
return -EINVAL;
}
ret = s6e8ax0_gamma_ctrl(lcd, brightness);
if (ret) {
dev_err(&bd->dev, "lcd brightness setting failed.\n");
return -EIO;
}
return ret;
}
static void s6e8ax0_power_on(struct mipi_dsim_lcd_device *dsim_dev, int power)
{
struct s6e8ax0 *lcd = dev_get_drvdata(&dsim_dev->dev);
msleep(lcd->ddi_pd->power_on_delay);
if (power)
s6e8ax0_regulator_enable(lcd);
else
s6e8ax0_regulator_disable(lcd);
msleep(lcd->ddi_pd->reset_delay);
if (lcd->ddi_pd->reset)
lcd->ddi_pd->reset(lcd->ld);
msleep(5);
}
static void s6e8ax0_set_sequence(struct mipi_dsim_lcd_device *dsim_dev)
{
struct s6e8ax0 *lcd = dev_get_drvdata(&dsim_dev->dev);
s6e8ax0_panel_init(lcd);
s6e8ax0_display_on(lcd);
lcd->power = FB_BLANK_UNBLANK;
}
static int s6e8ax0_probe(struct mipi_dsim_lcd_device *dsim_dev)
{
struct s6e8ax0 *lcd;
int ret;
u8 mtp_id[3] = {0, };
lcd = devm_kzalloc(&dsim_dev->dev, sizeof(struct s6e8ax0), GFP_KERNEL);
if (!lcd) {
dev_err(&dsim_dev->dev, "failed to allocate s6e8ax0 structure.\n");
return -ENOMEM;
}
lcd->dsim_dev = dsim_dev;
lcd->ddi_pd = (struct lcd_platform_data *)dsim_dev->platform_data;
lcd->dev = &dsim_dev->dev;
mutex_init(&lcd->lock);
ret = devm_regulator_bulk_get(lcd->dev, ARRAY_SIZE(supplies), supplies);
if (ret) {
dev_err(lcd->dev, "Failed to get regulators: %d\n", ret);
return ret;
}
lcd->ld = lcd_device_register("s6e8ax0", lcd->dev, lcd,
&s6e8ax0_lcd_ops);
if (IS_ERR(lcd->ld)) {
dev_err(lcd->dev, "failed to register lcd ops.\n");
return PTR_ERR(lcd->ld);
}
lcd->bd = backlight_device_register("s6e8ax0-bl", lcd->dev, lcd,
&s6e8ax0_backlight_ops, NULL);
if (IS_ERR(lcd->bd)) {
dev_err(lcd->dev, "failed to register backlight ops.\n");
ret = PTR_ERR(lcd->bd);
goto err_backlight_register;
}
lcd->bd->props.max_brightness = MAX_BRIGHTNESS;
lcd->bd->props.brightness = MAX_BRIGHTNESS;
s6e8ax0_read_id(lcd, mtp_id);
if (mtp_id[0] == 0x00)
dev_err(lcd->dev, "read id failed\n");
dev_info(lcd->dev, "Read ID : %x, %x, %x\n",
mtp_id[0], mtp_id[1], mtp_id[2]);
if (mtp_id[2] == 0x33)
dev_info(lcd->dev,
"ID-3 is 0xff does not support dynamic elvss\n");
else
dev_info(lcd->dev,
"ID-3 is 0x%x support dynamic elvss\n", mtp_id[2]);
lcd->acl_enable = 1;
lcd->cur_acl = 0;
dev_set_drvdata(&dsim_dev->dev, lcd);
dev_dbg(lcd->dev, "probed s6e8ax0 panel driver.\n");
return 0;
err_backlight_register:
lcd_device_unregister(lcd->ld);
return ret;
}
static int s6e8ax0_suspend(struct mipi_dsim_lcd_device *dsim_dev)
{
struct s6e8ax0 *lcd = dev_get_drvdata(&dsim_dev->dev);
s6e8ax0_sleep_in(lcd);
msleep(lcd->ddi_pd->power_off_delay);
s6e8ax0_display_off(lcd);
s6e8ax0_regulator_disable(lcd);
return 0;
}
static int s6e8ax0_resume(struct mipi_dsim_lcd_device *dsim_dev)
{
struct s6e8ax0 *lcd = dev_get_drvdata(&dsim_dev->dev);
s6e8ax0_sleep_out(lcd);
msleep(lcd->ddi_pd->power_on_delay);
s6e8ax0_regulator_enable(lcd);
s6e8ax0_set_sequence(dsim_dev);
return 0;
}
static int s6e8ax0_init(void)
{
exynos_mipi_dsi_register_lcd_driver(&s6e8ax0_dsim_ddi_driver);
return 0;
}
static void s6e8ax0_exit(void)
{
return;
}
