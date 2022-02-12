static void acx565akm_transfer(struct acx565akm_device *md, int cmd,
const u8 *wbuf, int wlen, u8 *rbuf, int rlen)
{
struct spi_message m;
struct spi_transfer *x, xfer[5];
int r;
BUG_ON(md->spi == NULL);
spi_message_init(&m);
memset(xfer, 0, sizeof(xfer));
x = &xfer[0];
cmd &= 0xff;
x->tx_buf = &cmd;
x->bits_per_word = 9;
x->len = 2;
if (rlen > 1 && wlen == 0) {
x->bits_per_word = 10;
cmd <<= 1;
}
spi_message_add_tail(x, &m);
if (wlen) {
x++;
x->tx_buf = wbuf;
x->len = wlen;
x->bits_per_word = 9;
spi_message_add_tail(x, &m);
}
if (rlen) {
x++;
x->rx_buf = rbuf;
x->len = rlen;
spi_message_add_tail(x, &m);
}
r = spi_sync(md->spi, &m);
if (r < 0)
dev_dbg(&md->spi->dev, "spi_sync %d\n", r);
}
static inline void acx565akm_cmd(struct acx565akm_device *md, int cmd)
{
acx565akm_transfer(md, cmd, NULL, 0, NULL, 0);
}
static inline void acx565akm_write(struct acx565akm_device *md,
int reg, const u8 *buf, int len)
{
acx565akm_transfer(md, reg, buf, len, NULL, 0);
}
static inline void acx565akm_read(struct acx565akm_device *md,
int reg, u8 *buf, int len)
{
acx565akm_transfer(md, reg, NULL, 0, buf, len);
}
static void hw_guard_start(struct acx565akm_device *md, int guard_msec)
{
md->hw_guard_wait = msecs_to_jiffies(guard_msec);
md->hw_guard_end = jiffies + md->hw_guard_wait;
}
static void hw_guard_wait(struct acx565akm_device *md)
{
unsigned long wait = md->hw_guard_end - jiffies;
if ((long)wait > 0 && wait <= md->hw_guard_wait) {
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(wait);
}
}
static void set_sleep_mode(struct acx565akm_device *md, int on)
{
int cmd;
if (on)
cmd = MIPID_CMD_SLEEP_IN;
else
cmd = MIPID_CMD_SLEEP_OUT;
hw_guard_wait(md);
acx565akm_cmd(md, cmd);
hw_guard_start(md, 120);
}
static void set_display_state(struct acx565akm_device *md, int enabled)
{
int cmd = enabled ? MIPID_CMD_DISP_ON : MIPID_CMD_DISP_OFF;
acx565akm_cmd(md, cmd);
}
static int panel_enabled(struct acx565akm_device *md)
{
u32 disp_status;
int enabled;
acx565akm_read(md, MIPID_CMD_READ_DISP_STATUS, (u8 *)&disp_status, 4);
disp_status = __be32_to_cpu(disp_status);
enabled = (disp_status & (1 << 17)) && (disp_status & (1 << 10));
dev_dbg(&md->spi->dev,
"LCD panel %senabled by bootloader (status 0x%04x)\n",
enabled ? "" : "not ", disp_status);
return enabled;
}
static int panel_detect(struct acx565akm_device *md)
{
acx565akm_read(md, MIPID_CMD_READ_DISP_ID, md->display_id, 3);
dev_dbg(&md->spi->dev, "MIPI display ID: %02x%02x%02x\n",
md->display_id[0], md->display_id[1], md->display_id[2]);
switch (md->display_id[0]) {
case 0x10:
md->model = MIPID_VER_ACX565AKM;
md->name = "acx565akm";
md->has_bc = 1;
md->has_cabc = 1;
break;
case 0x29:
md->model = MIPID_VER_L4F00311;
md->name = "l4f00311";
break;
case 0x45:
md->model = MIPID_VER_LPH8923;
md->name = "lph8923";
break;
case 0x83:
md->model = MIPID_VER_LS041Y3;
md->name = "ls041y3";
break;
default:
md->name = "unknown";
dev_err(&md->spi->dev, "invalid display ID\n");
return -ENODEV;
}
md->revision = md->display_id[1];
dev_info(&md->spi->dev, "omapfb: %s rev %02x LCD detected\n",
md->name, md->revision);
return 0;
}
static void enable_backlight_ctrl(struct acx565akm_device *md, int enable)
{
u16 ctrl;
acx565akm_read(md, MIPID_CMD_READ_CTRL_DISP, (u8 *)&ctrl, 1);
if (enable) {
ctrl |= CTRL_DISP_BRIGHTNESS_CTRL_ON |
CTRL_DISP_BACKLIGHT_ON;
} else {
ctrl &= ~(CTRL_DISP_BRIGHTNESS_CTRL_ON |
CTRL_DISP_BACKLIGHT_ON);
}
ctrl |= 1 << 8;
acx565akm_write(md, MIPID_CMD_WRITE_CTRL_DISP, (u8 *)&ctrl, 2);
}
static void set_cabc_mode(struct acx565akm_device *md, unsigned mode)
{
u16 cabc_ctrl;
md->cabc_mode = mode;
if (!md->enabled)
return;
cabc_ctrl = 0;
acx565akm_read(md, MIPID_CMD_READ_CABC, (u8 *)&cabc_ctrl, 1);
cabc_ctrl &= ~3;
cabc_ctrl |= (1 << 8) | (mode & 3);
acx565akm_write(md, MIPID_CMD_WRITE_CABC, (u8 *)&cabc_ctrl, 2);
}
static unsigned get_cabc_mode(struct acx565akm_device *md)
{
return md->cabc_mode;
}
static unsigned get_hw_cabc_mode(struct acx565akm_device *md)
{
u8 cabc_ctrl;
acx565akm_read(md, MIPID_CMD_READ_CABC, &cabc_ctrl, 1);
return cabc_ctrl & 3;
}
static void acx565akm_set_brightness(struct acx565akm_device *md, int level)
{
int bv;
bv = level | (1 << 8);
acx565akm_write(md, MIPID_CMD_WRITE_DISP_BRIGHTNESS, (u8 *)&bv, 2);
if (level)
enable_backlight_ctrl(md, 1);
else
enable_backlight_ctrl(md, 0);
}
static int acx565akm_get_actual_brightness(struct acx565akm_device *md)
{
u8 bv;
acx565akm_read(md, MIPID_CMD_READ_DISP_BRIGHTNESS, &bv, 1);
return bv;
}
static int acx565akm_bl_update_status(struct backlight_device *dev)
{
struct acx565akm_device *md = dev_get_drvdata(&dev->dev);
int r;
int level;
dev_dbg(&md->spi->dev, "%s\n", __func__);
mutex_lock(&md->mutex);
if (dev->props.fb_blank == FB_BLANK_UNBLANK &&
dev->props.power == FB_BLANK_UNBLANK)
level = dev->props.brightness;
else
level = 0;
r = 0;
if (md->has_bc)
acx565akm_set_brightness(md, level);
else
r = -ENODEV;
mutex_unlock(&md->mutex);
return r;
}
static int acx565akm_bl_get_intensity(struct backlight_device *dev)
{
struct acx565akm_device *md = dev_get_drvdata(&dev->dev);
dev_dbg(&dev->dev, "%s\n", __func__);
if (!md->has_bc)
return -ENODEV;
if (dev->props.fb_blank == FB_BLANK_UNBLANK &&
dev->props.power == FB_BLANK_UNBLANK) {
if (md->has_bc)
return acx565akm_get_actual_brightness(md);
else
return dev->props.brightness;
}
return 0;
}
static ssize_t show_cabc_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct acx565akm_device *md = dev_get_drvdata(dev);
const char *mode_str;
int mode;
int len;
if (!md->has_cabc)
mode = 0;
else
mode = get_cabc_mode(md);
mode_str = "unknown";
if (mode >= 0 && mode < ARRAY_SIZE(cabc_modes))
mode_str = cabc_modes[mode];
len = snprintf(buf, PAGE_SIZE, "%s\n", mode_str);
return len < PAGE_SIZE - 1 ? len : PAGE_SIZE - 1;
}
static ssize_t store_cabc_mode(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct acx565akm_device *md = dev_get_drvdata(dev);
int i;
for (i = 0; i < ARRAY_SIZE(cabc_modes); i++) {
const char *mode_str = cabc_modes[i];
int cmp_len = strlen(mode_str);
if (count > 0 && buf[count - 1] == '\n')
count--;
if (count != cmp_len)
continue;
if (strncmp(buf, mode_str, cmp_len) == 0)
break;
}
if (i == ARRAY_SIZE(cabc_modes))
return -EINVAL;
if (!md->has_cabc && i != 0)
return -EINVAL;
mutex_lock(&md->mutex);
set_cabc_mode(md, i);
mutex_unlock(&md->mutex);
return count;
}
static ssize_t show_cabc_available_modes(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct acx565akm_device *md = dev_get_drvdata(dev);
int len;
int i;
if (!md->has_cabc)
return snprintf(buf, PAGE_SIZE, "%s\n", cabc_modes[0]);
for (i = 0, len = 0;
len < PAGE_SIZE && i < ARRAY_SIZE(cabc_modes); i++)
len += snprintf(&buf[len], PAGE_SIZE - len, "%s%s%s",
i ? " " : "", cabc_modes[i],
i == ARRAY_SIZE(cabc_modes) - 1 ? "\n" : "");
return len < PAGE_SIZE ? len : PAGE_SIZE - 1;
}
static int acx_get_recommended_bpp(struct omap_dss_device *dssdev)
{
return 16;
}
static struct panel_acx565akm_data *get_panel_data(struct omap_dss_device *dssdev)
{
return (struct panel_acx565akm_data *) dssdev->data;
}
static int acx_panel_probe(struct omap_dss_device *dssdev)
{
int r;
struct acx565akm_device *md = &acx_dev;
struct panel_acx565akm_data *panel_data = get_panel_data(dssdev);
struct backlight_device *bldev;
int max_brightness, brightness;
struct backlight_properties props;
dev_dbg(dssdev->dev, "%s\n", __func__);
if (!panel_data)
return -EINVAL;
dssdev->panel.timings = acx_panel_timings;
if (gpio_is_valid(panel_data->reset_gpio)) {
r = devm_gpio_request_one(dssdev->dev, panel_data->reset_gpio,
GPIOF_OUT_INIT_LOW, "lcd reset");
if (r)
return r;
}
if (gpio_is_valid(panel_data->reset_gpio))
gpio_set_value(panel_data->reset_gpio, 1);
msleep(5);
md->enabled = panel_enabled(md);
r = panel_detect(md);
if (r) {
dev_err(dssdev->dev, "%s panel detect error\n", __func__);
if (!md->enabled && gpio_is_valid(panel_data->reset_gpio))
gpio_set_value(panel_data->reset_gpio, 0);
return r;
}
mutex_lock(&acx_dev.mutex);
acx_dev.dssdev = dssdev;
mutex_unlock(&acx_dev.mutex);
if (!md->enabled) {
if (gpio_is_valid(panel_data->reset_gpio))
gpio_set_value(panel_data->reset_gpio, 0);
}
memset(&props, 0, sizeof(props));
props.fb_blank = FB_BLANK_UNBLANK;
props.power = FB_BLANK_UNBLANK;
props.type = BACKLIGHT_RAW;
bldev = backlight_device_register("acx565akm", &md->spi->dev,
md, &acx565akm_bl_ops, &props);
md->bl_dev = bldev;
if (md->has_cabc) {
r = sysfs_create_group(&bldev->dev.kobj, &bldev_attr_group);
if (r) {
dev_err(&bldev->dev,
"%s failed to create sysfs files\n", __func__);
backlight_device_unregister(bldev);
return r;
}
md->cabc_mode = get_hw_cabc_mode(md);
}
max_brightness = 255;
if (md->has_bc)
brightness = acx565akm_get_actual_brightness(md);
else
brightness = 0;
bldev->props.max_brightness = max_brightness;
bldev->props.brightness = brightness;
acx565akm_bl_update_status(bldev);
return 0;
}
static void acx_panel_remove(struct omap_dss_device *dssdev)
{
struct acx565akm_device *md = &acx_dev;
dev_dbg(dssdev->dev, "%s\n", __func__);
sysfs_remove_group(&md->bl_dev->dev.kobj, &bldev_attr_group);
backlight_device_unregister(md->bl_dev);
mutex_lock(&acx_dev.mutex);
acx_dev.dssdev = NULL;
mutex_unlock(&acx_dev.mutex);
}
static int acx_panel_power_on(struct omap_dss_device *dssdev)
{
struct acx565akm_device *md = &acx_dev;
struct panel_acx565akm_data *panel_data = get_panel_data(dssdev);
int r;
dev_dbg(dssdev->dev, "%s\n", __func__);
if (dssdev->state == OMAP_DSS_DISPLAY_ACTIVE)
return 0;
mutex_lock(&md->mutex);
omapdss_sdi_set_timings(dssdev, &dssdev->panel.timings);
omapdss_sdi_set_datapairs(dssdev, dssdev->phy.sdi.datapairs);
r = omapdss_sdi_display_enable(dssdev);
if (r) {
pr_err("%s sdi enable failed\n", __func__);
goto fail_unlock;
}
msleep(50);
if (gpio_is_valid(panel_data->reset_gpio))
gpio_set_value(panel_data->reset_gpio, 1);
if (md->enabled) {
dev_dbg(&md->spi->dev, "panel already enabled\n");
mutex_unlock(&md->mutex);
return 0;
}
msleep(120);
set_sleep_mode(md, 0);
md->enabled = 1;
msleep(5);
set_display_state(md, 1);
set_cabc_mode(md, md->cabc_mode);
mutex_unlock(&md->mutex);
return acx565akm_bl_update_status(md->bl_dev);
fail_unlock:
mutex_unlock(&md->mutex);
return r;
}
static void acx_panel_power_off(struct omap_dss_device *dssdev)
{
struct acx565akm_device *md = &acx_dev;
struct panel_acx565akm_data *panel_data = get_panel_data(dssdev);
dev_dbg(dssdev->dev, "%s\n", __func__);
if (dssdev->state != OMAP_DSS_DISPLAY_ACTIVE)
return;
mutex_lock(&md->mutex);
if (!md->enabled) {
mutex_unlock(&md->mutex);
return;
}
set_display_state(md, 0);
set_sleep_mode(md, 1);
md->enabled = 0;
msleep(50);
if (gpio_is_valid(panel_data->reset_gpio))
gpio_set_value(panel_data->reset_gpio, 0);
msleep(100);
omapdss_sdi_display_disable(dssdev);
mutex_unlock(&md->mutex);
}
static int acx_panel_enable(struct omap_dss_device *dssdev)
{
int r;
dev_dbg(dssdev->dev, "%s\n", __func__);
r = acx_panel_power_on(dssdev);
if (r)
return r;
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
return 0;
}
static void acx_panel_disable(struct omap_dss_device *dssdev)
{
dev_dbg(dssdev->dev, "%s\n", __func__);
acx_panel_power_off(dssdev);
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
}
static void acx_panel_set_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
omapdss_sdi_set_timings(dssdev, timings);
dssdev->panel.timings = *timings;
}
static int acx_panel_check_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
return 0;
}
static int acx565akm_spi_probe(struct spi_device *spi)
{
struct acx565akm_device *md = &acx_dev;
dev_dbg(&spi->dev, "%s\n", __func__);
spi->mode = SPI_MODE_3;
md->spi = spi;
mutex_init(&md->mutex);
dev_set_drvdata(&spi->dev, md);
omap_dss_register_driver(&acx_panel_driver);
return 0;
}
static int acx565akm_spi_remove(struct spi_device *spi)
{
struct acx565akm_device *md = dev_get_drvdata(&spi->dev);
dev_dbg(&md->spi->dev, "%s\n", __func__);
omap_dss_unregister_driver(&acx_panel_driver);
return 0;
}
