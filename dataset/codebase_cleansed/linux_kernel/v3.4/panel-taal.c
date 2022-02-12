static void free_regulators(struct panel_regulator *regulators, int n)
{
int i;
for (i = 0; i < n; i++) {
regulator_disable(regulators[n - i - 1].regulator);
regulator_put(regulators[n - i - 1].regulator);
}
}
static int init_regulators(struct omap_dss_device *dssdev,
struct panel_regulator *regulators, int n)
{
int r, i, v;
for (i = 0; i < n; i++) {
struct regulator *reg;
reg = regulator_get(&dssdev->dev, regulators[i].name);
if (IS_ERR(reg)) {
dev_err(&dssdev->dev, "failed to get regulator %s\n",
regulators[i].name);
r = PTR_ERR(reg);
goto err;
}
v = regulator_get_voltage(reg);
if (v < regulators[i].min_uV || v > regulators[i].max_uV) {
r = regulator_set_voltage(reg, regulators[i].min_uV,
regulators[i].max_uV);
if (r) {
dev_err(&dssdev->dev,
"failed to set regulator %s voltage\n",
regulators[i].name);
regulator_put(reg);
goto err;
}
}
r = regulator_enable(reg);
if (r) {
dev_err(&dssdev->dev, "failed to enable regulator %s\n",
regulators[i].name);
regulator_put(reg);
goto err;
}
regulators[i].regulator = reg;
}
return 0;
err:
free_regulators(regulators, i);
return r;
}
static inline struct nokia_dsi_panel_data
*get_panel_data(const struct omap_dss_device *dssdev)
{
return (struct nokia_dsi_panel_data *) dssdev->data;
}
static void hw_guard_start(struct taal_data *td, int guard_msec)
{
td->hw_guard_wait = msecs_to_jiffies(guard_msec);
td->hw_guard_end = jiffies + td->hw_guard_wait;
}
static void hw_guard_wait(struct taal_data *td)
{
unsigned long wait = td->hw_guard_end - jiffies;
if ((long)wait > 0 && wait <= td->hw_guard_wait) {
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(wait);
}
}
static int taal_dcs_read_1(struct taal_data *td, u8 dcs_cmd, u8 *data)
{
int r;
u8 buf[1];
r = dsi_vc_dcs_read(td->dssdev, td->channel, dcs_cmd, buf, 1);
if (r < 0)
return r;
*data = buf[0];
return 0;
}
static int taal_dcs_write_0(struct taal_data *td, u8 dcs_cmd)
{
return dsi_vc_dcs_write(td->dssdev, td->channel, &dcs_cmd, 1);
}
static int taal_dcs_write_1(struct taal_data *td, u8 dcs_cmd, u8 param)
{
u8 buf[2];
buf[0] = dcs_cmd;
buf[1] = param;
return dsi_vc_dcs_write(td->dssdev, td->channel, buf, 2);
}
static int taal_sleep_in(struct taal_data *td)
{
u8 cmd;
int r;
hw_guard_wait(td);
cmd = MIPI_DCS_ENTER_SLEEP_MODE;
r = dsi_vc_dcs_write_nosync(td->dssdev, td->channel, &cmd, 1);
if (r)
return r;
hw_guard_start(td, 120);
if (td->panel_config->sleep.sleep_in)
msleep(td->panel_config->sleep.sleep_in);
return 0;
}
static int taal_sleep_out(struct taal_data *td)
{
int r;
hw_guard_wait(td);
r = taal_dcs_write_0(td, MIPI_DCS_EXIT_SLEEP_MODE);
if (r)
return r;
hw_guard_start(td, 120);
if (td->panel_config->sleep.sleep_out)
msleep(td->panel_config->sleep.sleep_out);
return 0;
}
static int taal_get_id(struct taal_data *td, u8 *id1, u8 *id2, u8 *id3)
{
int r;
r = taal_dcs_read_1(td, DCS_GET_ID1, id1);
if (r)
return r;
r = taal_dcs_read_1(td, DCS_GET_ID2, id2);
if (r)
return r;
r = taal_dcs_read_1(td, DCS_GET_ID3, id3);
if (r)
return r;
return 0;
}
static int taal_set_addr_mode(struct taal_data *td, u8 rotate, bool mirror)
{
int r;
u8 mode;
int b5, b6, b7;
r = taal_dcs_read_1(td, MIPI_DCS_GET_ADDRESS_MODE, &mode);
if (r)
return r;
switch (rotate) {
default:
case 0:
b7 = 0;
b6 = 0;
b5 = 0;
break;
case 1:
b7 = 0;
b6 = 1;
b5 = 1;
break;
case 2:
b7 = 1;
b6 = 1;
b5 = 0;
break;
case 3:
b7 = 1;
b6 = 0;
b5 = 1;
break;
}
if (mirror)
b6 = !b6;
mode &= ~((1<<7) | (1<<6) | (1<<5));
mode |= (b7 << 7) | (b6 << 6) | (b5 << 5);
return taal_dcs_write_1(td, MIPI_DCS_SET_ADDRESS_MODE, mode);
}
static int taal_set_update_window(struct taal_data *td,
u16 x, u16 y, u16 w, u16 h)
{
int r;
u16 x1 = x;
u16 x2 = x + w - 1;
u16 y1 = y;
u16 y2 = y + h - 1;
u8 buf[5];
buf[0] = MIPI_DCS_SET_COLUMN_ADDRESS;
buf[1] = (x1 >> 8) & 0xff;
buf[2] = (x1 >> 0) & 0xff;
buf[3] = (x2 >> 8) & 0xff;
buf[4] = (x2 >> 0) & 0xff;
r = dsi_vc_dcs_write_nosync(td->dssdev, td->channel, buf, sizeof(buf));
if (r)
return r;
buf[0] = MIPI_DCS_SET_PAGE_ADDRESS;
buf[1] = (y1 >> 8) & 0xff;
buf[2] = (y1 >> 0) & 0xff;
buf[3] = (y2 >> 8) & 0xff;
buf[4] = (y2 >> 0) & 0xff;
r = dsi_vc_dcs_write_nosync(td->dssdev, td->channel, buf, sizeof(buf));
if (r)
return r;
dsi_vc_send_bta_sync(td->dssdev, td->channel);
return r;
}
static void taal_queue_esd_work(struct omap_dss_device *dssdev)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
if (td->esd_interval > 0)
queue_delayed_work(td->workqueue, &td->esd_work,
msecs_to_jiffies(td->esd_interval));
}
static void taal_cancel_esd_work(struct omap_dss_device *dssdev)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
cancel_delayed_work(&td->esd_work);
}
static void taal_queue_ulps_work(struct omap_dss_device *dssdev)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
if (td->ulps_timeout > 0)
queue_delayed_work(td->workqueue, &td->ulps_work,
msecs_to_jiffies(td->ulps_timeout));
}
static void taal_cancel_ulps_work(struct omap_dss_device *dssdev)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
cancel_delayed_work(&td->ulps_work);
}
static int taal_enter_ulps(struct omap_dss_device *dssdev)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
struct nokia_dsi_panel_data *panel_data = get_panel_data(dssdev);
int r;
if (td->ulps_enabled)
return 0;
taal_cancel_ulps_work(dssdev);
r = _taal_enable_te(dssdev, false);
if (r)
goto err;
disable_irq(gpio_to_irq(panel_data->ext_te_gpio));
omapdss_dsi_display_disable(dssdev, false, true);
td->ulps_enabled = true;
return 0;
err:
dev_err(&dssdev->dev, "enter ULPS failed");
taal_panel_reset(dssdev);
td->ulps_enabled = false;
taal_queue_ulps_work(dssdev);
return r;
}
static int taal_exit_ulps(struct omap_dss_device *dssdev)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
struct nokia_dsi_panel_data *panel_data = get_panel_data(dssdev);
int r;
if (!td->ulps_enabled)
return 0;
r = omapdss_dsi_display_enable(dssdev);
if (r) {
dev_err(&dssdev->dev, "failed to enable DSI\n");
goto err1;
}
omapdss_dsi_vc_enable_hs(dssdev, td->channel, true);
r = _taal_enable_te(dssdev, true);
if (r) {
dev_err(&dssdev->dev, "failed to re-enable TE");
goto err2;
}
enable_irq(gpio_to_irq(panel_data->ext_te_gpio));
taal_queue_ulps_work(dssdev);
td->ulps_enabled = false;
return 0;
err2:
dev_err(&dssdev->dev, "failed to exit ULPS");
r = taal_panel_reset(dssdev);
if (!r) {
enable_irq(gpio_to_irq(panel_data->ext_te_gpio));
td->ulps_enabled = false;
}
err1:
taal_queue_ulps_work(dssdev);
return r;
}
static int taal_wake_up(struct omap_dss_device *dssdev)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
if (td->ulps_enabled)
return taal_exit_ulps(dssdev);
taal_cancel_ulps_work(dssdev);
taal_queue_ulps_work(dssdev);
return 0;
}
static int taal_bl_update_status(struct backlight_device *dev)
{
struct omap_dss_device *dssdev = dev_get_drvdata(&dev->dev);
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
int r;
int level;
if (dev->props.fb_blank == FB_BLANK_UNBLANK &&
dev->props.power == FB_BLANK_UNBLANK)
level = dev->props.brightness;
else
level = 0;
dev_dbg(&dssdev->dev, "update brightness to %d\n", level);
mutex_lock(&td->lock);
if (td->enabled) {
dsi_bus_lock(dssdev);
r = taal_wake_up(dssdev);
if (!r)
r = taal_dcs_write_1(td, DCS_BRIGHTNESS, level);
dsi_bus_unlock(dssdev);
} else {
r = 0;
}
mutex_unlock(&td->lock);
return r;
}
static int taal_bl_get_intensity(struct backlight_device *dev)
{
if (dev->props.fb_blank == FB_BLANK_UNBLANK &&
dev->props.power == FB_BLANK_UNBLANK)
return dev->props.brightness;
return 0;
}
static void taal_get_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
*timings = dssdev->panel.timings;
}
static void taal_get_resolution(struct omap_dss_device *dssdev,
u16 *xres, u16 *yres)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
if (td->rotate == 0 || td->rotate == 2) {
*xres = dssdev->panel.timings.x_res;
*yres = dssdev->panel.timings.y_res;
} else {
*yres = dssdev->panel.timings.x_res;
*xres = dssdev->panel.timings.y_res;
}
}
static ssize_t taal_num_errors_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
u8 errors;
int r;
mutex_lock(&td->lock);
if (td->enabled) {
dsi_bus_lock(dssdev);
r = taal_wake_up(dssdev);
if (!r)
r = taal_dcs_read_1(td, DCS_READ_NUM_ERRORS, &errors);
dsi_bus_unlock(dssdev);
} else {
r = -ENODEV;
}
mutex_unlock(&td->lock);
if (r)
return r;
return snprintf(buf, PAGE_SIZE, "%d\n", errors);
}
static ssize_t taal_hw_revision_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
u8 id1, id2, id3;
int r;
mutex_lock(&td->lock);
if (td->enabled) {
dsi_bus_lock(dssdev);
r = taal_wake_up(dssdev);
if (!r)
r = taal_get_id(td, &id1, &id2, &id3);
dsi_bus_unlock(dssdev);
} else {
r = -ENODEV;
}
mutex_unlock(&td->lock);
if (r)
return r;
return snprintf(buf, PAGE_SIZE, "%02x.%02x.%02x\n", id1, id2, id3);
}
static ssize_t show_cabc_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
const char *mode_str;
int mode;
int len;
mode = td->cabc_mode;
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
struct omap_dss_device *dssdev = to_dss_device(dev);
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
int i;
int r;
for (i = 0; i < ARRAY_SIZE(cabc_modes); i++) {
if (sysfs_streq(cabc_modes[i], buf))
break;
}
if (i == ARRAY_SIZE(cabc_modes))
return -EINVAL;
mutex_lock(&td->lock);
if (td->enabled) {
dsi_bus_lock(dssdev);
if (!td->cabc_broken) {
r = taal_wake_up(dssdev);
if (r)
goto err;
r = taal_dcs_write_1(td, DCS_WRITE_CABC, i);
if (r)
goto err;
}
dsi_bus_unlock(dssdev);
}
td->cabc_mode = i;
mutex_unlock(&td->lock);
return count;
err:
dsi_bus_unlock(dssdev);
mutex_unlock(&td->lock);
return r;
}
static ssize_t show_cabc_available_modes(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int len;
int i;
for (i = 0, len = 0;
len < PAGE_SIZE && i < ARRAY_SIZE(cabc_modes); i++)
len += snprintf(&buf[len], PAGE_SIZE - len, "%s%s%s",
i ? " " : "", cabc_modes[i],
i == ARRAY_SIZE(cabc_modes) - 1 ? "\n" : "");
return len < PAGE_SIZE ? len : PAGE_SIZE - 1;
}
static ssize_t taal_store_esd_interval(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
unsigned long t;
int r;
r = strict_strtoul(buf, 10, &t);
if (r)
return r;
mutex_lock(&td->lock);
taal_cancel_esd_work(dssdev);
td->esd_interval = t;
if (td->enabled)
taal_queue_esd_work(dssdev);
mutex_unlock(&td->lock);
return count;
}
static ssize_t taal_show_esd_interval(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
unsigned t;
mutex_lock(&td->lock);
t = td->esd_interval;
mutex_unlock(&td->lock);
return snprintf(buf, PAGE_SIZE, "%u\n", t);
}
static ssize_t taal_store_ulps(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
unsigned long t;
int r;
r = strict_strtoul(buf, 10, &t);
if (r)
return r;
mutex_lock(&td->lock);
if (td->enabled) {
dsi_bus_lock(dssdev);
if (t)
r = taal_enter_ulps(dssdev);
else
r = taal_wake_up(dssdev);
dsi_bus_unlock(dssdev);
}
mutex_unlock(&td->lock);
if (r)
return r;
return count;
}
static ssize_t taal_show_ulps(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
unsigned t;
mutex_lock(&td->lock);
t = td->ulps_enabled;
mutex_unlock(&td->lock);
return snprintf(buf, PAGE_SIZE, "%u\n", t);
}
static ssize_t taal_store_ulps_timeout(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
unsigned long t;
int r;
r = strict_strtoul(buf, 10, &t);
if (r)
return r;
mutex_lock(&td->lock);
td->ulps_timeout = t;
if (td->enabled) {
dsi_bus_lock(dssdev);
r = taal_wake_up(dssdev);
dsi_bus_unlock(dssdev);
}
mutex_unlock(&td->lock);
if (r)
return r;
return count;
}
static ssize_t taal_show_ulps_timeout(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct omap_dss_device *dssdev = to_dss_device(dev);
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
unsigned t;
mutex_lock(&td->lock);
t = td->ulps_timeout;
mutex_unlock(&td->lock);
return snprintf(buf, PAGE_SIZE, "%u\n", t);
}
static void taal_hw_reset(struct omap_dss_device *dssdev)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
struct nokia_dsi_panel_data *panel_data = get_panel_data(dssdev);
if (panel_data->reset_gpio == -1)
return;
gpio_set_value(panel_data->reset_gpio, 1);
if (td->panel_config->reset_sequence.high)
udelay(td->panel_config->reset_sequence.high);
gpio_set_value(panel_data->reset_gpio, 0);
if (td->panel_config->reset_sequence.low)
udelay(td->panel_config->reset_sequence.low);
gpio_set_value(panel_data->reset_gpio, 1);
if (td->panel_config->sleep.hw_reset)
msleep(td->panel_config->sleep.hw_reset);
}
static int taal_probe(struct omap_dss_device *dssdev)
{
struct backlight_properties props;
struct taal_data *td;
struct backlight_device *bldev = NULL;
struct nokia_dsi_panel_data *panel_data = get_panel_data(dssdev);
struct panel_config *panel_config = NULL;
int r, i;
dev_dbg(&dssdev->dev, "probe\n");
if (!panel_data || !panel_data->name) {
r = -EINVAL;
goto err;
}
for (i = 0; i < ARRAY_SIZE(panel_configs); i++) {
if (strcmp(panel_data->name, panel_configs[i].name) == 0) {
panel_config = &panel_configs[i];
break;
}
}
if (!panel_config) {
r = -EINVAL;
goto err;
}
dssdev->panel.config = OMAP_DSS_LCD_TFT;
dssdev->panel.timings = panel_config->timings;
dssdev->panel.dsi_pix_fmt = OMAP_DSS_DSI_FMT_RGB888;
td = kzalloc(sizeof(*td), GFP_KERNEL);
if (!td) {
r = -ENOMEM;
goto err;
}
td->dssdev = dssdev;
td->panel_config = panel_config;
td->esd_interval = panel_data->esd_interval;
td->ulps_enabled = false;
td->ulps_timeout = panel_data->ulps_timeout;
mutex_init(&td->lock);
atomic_set(&td->do_update, 0);
r = init_regulators(dssdev, panel_config->regulators,
panel_config->num_regulators);
if (r)
goto err_reg;
td->workqueue = create_singlethread_workqueue("taal_esd");
if (td->workqueue == NULL) {
dev_err(&dssdev->dev, "can't create ESD workqueue\n");
r = -ENOMEM;
goto err_wq;
}
INIT_DELAYED_WORK_DEFERRABLE(&td->esd_work, taal_esd_work);
INIT_DELAYED_WORK(&td->ulps_work, taal_ulps_work);
dev_set_drvdata(&dssdev->dev, td);
taal_hw_reset(dssdev);
if (panel_data->use_dsi_backlight) {
memset(&props, 0, sizeof(struct backlight_properties));
props.max_brightness = 255;
props.type = BACKLIGHT_RAW;
bldev = backlight_device_register(dev_name(&dssdev->dev),
&dssdev->dev, dssdev, &taal_bl_ops, &props);
if (IS_ERR(bldev)) {
r = PTR_ERR(bldev);
goto err_bl;
}
td->bldev = bldev;
bldev->props.fb_blank = FB_BLANK_UNBLANK;
bldev->props.power = FB_BLANK_UNBLANK;
bldev->props.brightness = 255;
taal_bl_update_status(bldev);
}
if (panel_data->use_ext_te) {
int gpio = panel_data->ext_te_gpio;
r = gpio_request_one(gpio, GPIOF_IN, "taal irq");
if (r) {
dev_err(&dssdev->dev, "GPIO request failed\n");
goto err_gpio;
}
r = request_irq(gpio_to_irq(gpio), taal_te_isr,
IRQF_TRIGGER_RISING,
"taal vsync", dssdev);
if (r) {
dev_err(&dssdev->dev, "IRQ request failed\n");
gpio_free(gpio);
goto err_irq;
}
INIT_DELAYED_WORK_DEFERRABLE(&td->te_timeout_work,
taal_te_timeout_work_callback);
dev_dbg(&dssdev->dev, "Using GPIO TE\n");
}
r = omap_dsi_request_vc(dssdev, &td->channel);
if (r) {
dev_err(&dssdev->dev, "failed to get virtual channel\n");
goto err_req_vc;
}
r = omap_dsi_set_vc_id(dssdev, td->channel, TCH);
if (r) {
dev_err(&dssdev->dev, "failed to set VC_ID\n");
goto err_vc_id;
}
r = sysfs_create_group(&dssdev->dev.kobj, &taal_attr_group);
if (r) {
dev_err(&dssdev->dev, "failed to create sysfs files\n");
goto err_vc_id;
}
return 0;
err_vc_id:
omap_dsi_release_vc(dssdev, td->channel);
err_req_vc:
if (panel_data->use_ext_te)
free_irq(gpio_to_irq(panel_data->ext_te_gpio), dssdev);
err_irq:
if (panel_data->use_ext_te)
gpio_free(panel_data->ext_te_gpio);
err_gpio:
if (bldev != NULL)
backlight_device_unregister(bldev);
err_bl:
destroy_workqueue(td->workqueue);
err_wq:
free_regulators(panel_config->regulators, panel_config->num_regulators);
err_reg:
kfree(td);
err:
return r;
}
static void __exit taal_remove(struct omap_dss_device *dssdev)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
struct nokia_dsi_panel_data *panel_data = get_panel_data(dssdev);
struct backlight_device *bldev;
dev_dbg(&dssdev->dev, "remove\n");
sysfs_remove_group(&dssdev->dev.kobj, &taal_attr_group);
omap_dsi_release_vc(dssdev, td->channel);
if (panel_data->use_ext_te) {
int gpio = panel_data->ext_te_gpio;
free_irq(gpio_to_irq(gpio), dssdev);
gpio_free(gpio);
}
bldev = td->bldev;
if (bldev != NULL) {
bldev->props.power = FB_BLANK_POWERDOWN;
taal_bl_update_status(bldev);
backlight_device_unregister(bldev);
}
taal_cancel_ulps_work(dssdev);
taal_cancel_esd_work(dssdev);
destroy_workqueue(td->workqueue);
taal_hw_reset(dssdev);
free_regulators(td->panel_config->regulators,
td->panel_config->num_regulators);
kfree(td);
}
static int taal_power_on(struct omap_dss_device *dssdev)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
u8 id1, id2, id3;
int r;
r = omapdss_dsi_display_enable(dssdev);
if (r) {
dev_err(&dssdev->dev, "failed to enable DSI\n");
goto err0;
}
taal_hw_reset(dssdev);
omapdss_dsi_vc_enable_hs(dssdev, td->channel, false);
r = taal_sleep_out(td);
if (r)
goto err;
r = taal_get_id(td, &id1, &id2, &id3);
if (r)
goto err;
if (td->panel_config->type == PANEL_TAAL &&
(id2 == 0x00 || id2 == 0xff || id2 == 0x81))
td->cabc_broken = true;
r = taal_dcs_write_1(td, DCS_BRIGHTNESS, 0xff);
if (r)
goto err;
r = taal_dcs_write_1(td, DCS_CTRL_DISPLAY,
(1<<2) | (1<<5));
if (r)
goto err;
r = taal_dcs_write_1(td, MIPI_DCS_SET_PIXEL_FORMAT,
MIPI_DCS_PIXEL_FMT_24BIT);
if (r)
goto err;
r = taal_set_addr_mode(td, td->rotate, td->mirror);
if (r)
goto err;
if (!td->cabc_broken) {
r = taal_dcs_write_1(td, DCS_WRITE_CABC, td->cabc_mode);
if (r)
goto err;
}
r = taal_dcs_write_0(td, MIPI_DCS_SET_DISPLAY_ON);
if (r)
goto err;
r = _taal_enable_te(dssdev, td->te_enabled);
if (r)
goto err;
r = dsi_enable_video_output(dssdev, td->channel);
if (r)
goto err;
td->enabled = 1;
if (!td->intro_printed) {
dev_info(&dssdev->dev, "%s panel revision %02x.%02x.%02x\n",
td->panel_config->name, id1, id2, id3);
if (td->cabc_broken)
dev_info(&dssdev->dev,
"old Taal version, CABC disabled\n");
td->intro_printed = true;
}
omapdss_dsi_vc_enable_hs(dssdev, td->channel, true);
return 0;
err:
dev_err(&dssdev->dev, "error while enabling panel, issuing HW reset\n");
taal_hw_reset(dssdev);
omapdss_dsi_display_disable(dssdev, true, false);
err0:
return r;
}
static void taal_power_off(struct omap_dss_device *dssdev)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
int r;
dsi_disable_video_output(dssdev, td->channel);
r = taal_dcs_write_0(td, MIPI_DCS_SET_DISPLAY_OFF);
if (!r)
r = taal_sleep_in(td);
if (r) {
dev_err(&dssdev->dev,
"error disabling panel, issuing HW reset\n");
taal_hw_reset(dssdev);
}
omapdss_dsi_display_disable(dssdev, true, false);
td->enabled = 0;
}
static int taal_panel_reset(struct omap_dss_device *dssdev)
{
dev_err(&dssdev->dev, "performing LCD reset\n");
taal_power_off(dssdev);
taal_hw_reset(dssdev);
return taal_power_on(dssdev);
}
static int taal_enable(struct omap_dss_device *dssdev)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
int r;
dev_dbg(&dssdev->dev, "enable\n");
mutex_lock(&td->lock);
if (dssdev->state != OMAP_DSS_DISPLAY_DISABLED) {
r = -EINVAL;
goto err;
}
dsi_bus_lock(dssdev);
r = taal_power_on(dssdev);
dsi_bus_unlock(dssdev);
if (r)
goto err;
taal_queue_esd_work(dssdev);
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
mutex_unlock(&td->lock);
return 0;
err:
dev_dbg(&dssdev->dev, "enable failed\n");
mutex_unlock(&td->lock);
return r;
}
static void taal_disable(struct omap_dss_device *dssdev)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
dev_dbg(&dssdev->dev, "disable\n");
mutex_lock(&td->lock);
taal_cancel_ulps_work(dssdev);
taal_cancel_esd_work(dssdev);
dsi_bus_lock(dssdev);
if (dssdev->state == OMAP_DSS_DISPLAY_ACTIVE) {
int r;
r = taal_wake_up(dssdev);
if (!r)
taal_power_off(dssdev);
}
dsi_bus_unlock(dssdev);
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
mutex_unlock(&td->lock);
}
static int taal_suspend(struct omap_dss_device *dssdev)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
int r;
dev_dbg(&dssdev->dev, "suspend\n");
mutex_lock(&td->lock);
if (dssdev->state != OMAP_DSS_DISPLAY_ACTIVE) {
r = -EINVAL;
goto err;
}
taal_cancel_ulps_work(dssdev);
taal_cancel_esd_work(dssdev);
dsi_bus_lock(dssdev);
r = taal_wake_up(dssdev);
if (!r)
taal_power_off(dssdev);
dsi_bus_unlock(dssdev);
dssdev->state = OMAP_DSS_DISPLAY_SUSPENDED;
mutex_unlock(&td->lock);
return 0;
err:
mutex_unlock(&td->lock);
return r;
}
static int taal_resume(struct omap_dss_device *dssdev)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
int r;
dev_dbg(&dssdev->dev, "resume\n");
mutex_lock(&td->lock);
if (dssdev->state != OMAP_DSS_DISPLAY_SUSPENDED) {
r = -EINVAL;
goto err;
}
dsi_bus_lock(dssdev);
r = taal_power_on(dssdev);
dsi_bus_unlock(dssdev);
if (r) {
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
} else {
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
taal_queue_esd_work(dssdev);
}
mutex_unlock(&td->lock);
return r;
err:
mutex_unlock(&td->lock);
return r;
}
static void taal_framedone_cb(int err, void *data)
{
struct omap_dss_device *dssdev = data;
dev_dbg(&dssdev->dev, "framedone, err %d\n", err);
dsi_bus_unlock(dssdev);
}
static irqreturn_t taal_te_isr(int irq, void *data)
{
struct omap_dss_device *dssdev = data;
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
int old;
int r;
old = atomic_cmpxchg(&td->do_update, 1, 0);
if (old) {
cancel_delayed_work(&td->te_timeout_work);
r = omap_dsi_update(dssdev, td->channel, taal_framedone_cb,
dssdev);
if (r)
goto err;
}
return IRQ_HANDLED;
err:
dev_err(&dssdev->dev, "start update failed\n");
dsi_bus_unlock(dssdev);
return IRQ_HANDLED;
}
static void taal_te_timeout_work_callback(struct work_struct *work)
{
struct taal_data *td = container_of(work, struct taal_data,
te_timeout_work.work);
struct omap_dss_device *dssdev = td->dssdev;
dev_err(&dssdev->dev, "TE not received for 250ms!\n");
atomic_set(&td->do_update, 0);
dsi_bus_unlock(dssdev);
}
static int taal_update(struct omap_dss_device *dssdev,
u16 x, u16 y, u16 w, u16 h)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
struct nokia_dsi_panel_data *panel_data = get_panel_data(dssdev);
int r;
dev_dbg(&dssdev->dev, "update %d, %d, %d x %d\n", x, y, w, h);
mutex_lock(&td->lock);
dsi_bus_lock(dssdev);
r = taal_wake_up(dssdev);
if (r)
goto err;
if (!td->enabled) {
r = 0;
goto err;
}
r = taal_set_update_window(td, 0, 0,
td->panel_config->timings.x_res,
td->panel_config->timings.y_res);
if (r)
goto err;
if (td->te_enabled && panel_data->use_ext_te) {
schedule_delayed_work(&td->te_timeout_work,
msecs_to_jiffies(250));
atomic_set(&td->do_update, 1);
} else {
r = omap_dsi_update(dssdev, td->channel, taal_framedone_cb,
dssdev);
if (r)
goto err;
}
mutex_unlock(&td->lock);
return 0;
err:
dsi_bus_unlock(dssdev);
mutex_unlock(&td->lock);
return r;
}
static int taal_sync(struct omap_dss_device *dssdev)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
dev_dbg(&dssdev->dev, "sync\n");
mutex_lock(&td->lock);
dsi_bus_lock(dssdev);
dsi_bus_unlock(dssdev);
mutex_unlock(&td->lock);
dev_dbg(&dssdev->dev, "sync done\n");
return 0;
}
static int _taal_enable_te(struct omap_dss_device *dssdev, bool enable)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
struct nokia_dsi_panel_data *panel_data = get_panel_data(dssdev);
int r;
if (enable)
r = taal_dcs_write_1(td, MIPI_DCS_SET_TEAR_ON, 0);
else
r = taal_dcs_write_0(td, MIPI_DCS_SET_TEAR_OFF);
if (!panel_data->use_ext_te)
omapdss_dsi_enable_te(dssdev, enable);
if (td->panel_config->sleep.enable_te)
msleep(td->panel_config->sleep.enable_te);
return r;
}
static int taal_enable_te(struct omap_dss_device *dssdev, bool enable)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
int r;
mutex_lock(&td->lock);
if (td->te_enabled == enable)
goto end;
dsi_bus_lock(dssdev);
if (td->enabled) {
r = taal_wake_up(dssdev);
if (r)
goto err;
r = _taal_enable_te(dssdev, enable);
if (r)
goto err;
}
td->te_enabled = enable;
dsi_bus_unlock(dssdev);
end:
mutex_unlock(&td->lock);
return 0;
err:
dsi_bus_unlock(dssdev);
mutex_unlock(&td->lock);
return r;
}
static int taal_get_te(struct omap_dss_device *dssdev)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
int r;
mutex_lock(&td->lock);
r = td->te_enabled;
mutex_unlock(&td->lock);
return r;
}
static int taal_rotate(struct omap_dss_device *dssdev, u8 rotate)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
int r;
dev_dbg(&dssdev->dev, "rotate %d\n", rotate);
mutex_lock(&td->lock);
if (td->rotate == rotate)
goto end;
dsi_bus_lock(dssdev);
if (td->enabled) {
r = taal_wake_up(dssdev);
if (r)
goto err;
r = taal_set_addr_mode(td, rotate, td->mirror);
if (r)
goto err;
}
td->rotate = rotate;
dsi_bus_unlock(dssdev);
end:
mutex_unlock(&td->lock);
return 0;
err:
dsi_bus_unlock(dssdev);
mutex_unlock(&td->lock);
return r;
}
static u8 taal_get_rotate(struct omap_dss_device *dssdev)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
int r;
mutex_lock(&td->lock);
r = td->rotate;
mutex_unlock(&td->lock);
return r;
}
static int taal_mirror(struct omap_dss_device *dssdev, bool enable)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
int r;
dev_dbg(&dssdev->dev, "mirror %d\n", enable);
mutex_lock(&td->lock);
if (td->mirror == enable)
goto end;
dsi_bus_lock(dssdev);
if (td->enabled) {
r = taal_wake_up(dssdev);
if (r)
goto err;
r = taal_set_addr_mode(td, td->rotate, enable);
if (r)
goto err;
}
td->mirror = enable;
dsi_bus_unlock(dssdev);
end:
mutex_unlock(&td->lock);
return 0;
err:
dsi_bus_unlock(dssdev);
mutex_unlock(&td->lock);
return r;
}
static bool taal_get_mirror(struct omap_dss_device *dssdev)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
int r;
mutex_lock(&td->lock);
r = td->mirror;
mutex_unlock(&td->lock);
return r;
}
static int taal_run_test(struct omap_dss_device *dssdev, int test_num)
{
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
u8 id1, id2, id3;
int r;
mutex_lock(&td->lock);
if (!td->enabled) {
r = -ENODEV;
goto err1;
}
dsi_bus_lock(dssdev);
r = taal_wake_up(dssdev);
if (r)
goto err2;
r = taal_dcs_read_1(td, DCS_GET_ID1, &id1);
if (r)
goto err2;
r = taal_dcs_read_1(td, DCS_GET_ID2, &id2);
if (r)
goto err2;
r = taal_dcs_read_1(td, DCS_GET_ID3, &id3);
if (r)
goto err2;
dsi_bus_unlock(dssdev);
mutex_unlock(&td->lock);
return 0;
err2:
dsi_bus_unlock(dssdev);
err1:
mutex_unlock(&td->lock);
return r;
}
static int taal_memory_read(struct omap_dss_device *dssdev,
void *buf, size_t size,
u16 x, u16 y, u16 w, u16 h)
{
int r;
int first = 1;
int plen;
unsigned buf_used = 0;
struct taal_data *td = dev_get_drvdata(&dssdev->dev);
if (size < w * h * 3)
return -ENOMEM;
mutex_lock(&td->lock);
if (!td->enabled) {
r = -ENODEV;
goto err1;
}
size = min(w * h * 3,
dssdev->panel.timings.x_res *
dssdev->panel.timings.y_res * 3);
dsi_bus_lock(dssdev);
r = taal_wake_up(dssdev);
if (r)
goto err2;
if (size % 2)
plen = 1;
else
plen = 2;
taal_set_update_window(td, x, y, w, h);
r = dsi_vc_set_max_rx_packet_size(dssdev, td->channel, plen);
if (r)
goto err2;
while (buf_used < size) {
u8 dcs_cmd = first ? 0x2e : 0x3e;
first = 0;
r = dsi_vc_dcs_read(dssdev, td->channel, dcs_cmd,
buf + buf_used, size - buf_used);
if (r < 0) {
dev_err(&dssdev->dev, "read error\n");
goto err3;
}
buf_used += r;
if (r < plen) {
dev_err(&dssdev->dev, "short read\n");
break;
}
if (signal_pending(current)) {
dev_err(&dssdev->dev, "signal pending, "
"aborting memory read\n");
r = -ERESTARTSYS;
goto err3;
}
}
r = buf_used;
err3:
dsi_vc_set_max_rx_packet_size(dssdev, td->channel, 1);
err2:
dsi_bus_unlock(dssdev);
err1:
mutex_unlock(&td->lock);
return r;
}
static void taal_ulps_work(struct work_struct *work)
{
struct taal_data *td = container_of(work, struct taal_data,
ulps_work.work);
struct omap_dss_device *dssdev = td->dssdev;
mutex_lock(&td->lock);
if (dssdev->state != OMAP_DSS_DISPLAY_ACTIVE || !td->enabled) {
mutex_unlock(&td->lock);
return;
}
dsi_bus_lock(dssdev);
taal_enter_ulps(dssdev);
dsi_bus_unlock(dssdev);
mutex_unlock(&td->lock);
}
static void taal_esd_work(struct work_struct *work)
{
struct taal_data *td = container_of(work, struct taal_data,
esd_work.work);
struct omap_dss_device *dssdev = td->dssdev;
struct nokia_dsi_panel_data *panel_data = get_panel_data(dssdev);
u8 state1, state2;
int r;
mutex_lock(&td->lock);
if (!td->enabled) {
mutex_unlock(&td->lock);
return;
}
dsi_bus_lock(dssdev);
r = taal_wake_up(dssdev);
if (r) {
dev_err(&dssdev->dev, "failed to exit ULPS\n");
goto err;
}
r = taal_dcs_read_1(td, MIPI_DCS_GET_DIAGNOSTIC_RESULT, &state1);
if (r) {
dev_err(&dssdev->dev, "failed to read Taal status\n");
goto err;
}
r = taal_sleep_out(td);
if (r) {
dev_err(&dssdev->dev, "failed to run Taal self-diagnostics\n");
goto err;
}
r = taal_dcs_read_1(td, MIPI_DCS_GET_DIAGNOSTIC_RESULT, &state2);
if (r) {
dev_err(&dssdev->dev, "failed to read Taal status\n");
goto err;
}
if (!((state1 ^ state2) & (1 << 6))) {
dev_err(&dssdev->dev, "LCD self diagnostics failed\n");
goto err;
}
if (td->te_enabled && panel_data->use_ext_te) {
r = taal_dcs_write_1(td, MIPI_DCS_SET_TEAR_ON, 0);
if (r)
goto err;
}
dsi_bus_unlock(dssdev);
taal_queue_esd_work(dssdev);
mutex_unlock(&td->lock);
return;
err:
dev_err(&dssdev->dev, "performing LCD reset\n");
taal_panel_reset(dssdev);
dsi_bus_unlock(dssdev);
taal_queue_esd_work(dssdev);
mutex_unlock(&td->lock);
}
static int __init taal_init(void)
{
omap_dss_register_driver(&taal_driver);
return 0;
}
static void __exit taal_exit(void)
{
omap_dss_unregister_driver(&taal_driver);
}
