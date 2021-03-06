static int tfp410_power_on(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = dev_get_drvdata(dssdev->dev);
int r;
if (dssdev->state == OMAP_DSS_DISPLAY_ACTIVE)
return 0;
omapdss_dpi_set_timings(dssdev, &dssdev->panel.timings);
omapdss_dpi_set_data_lines(dssdev, dssdev->phy.dpi.data_lines);
r = omapdss_dpi_display_enable(dssdev);
if (r)
goto err0;
if (gpio_is_valid(ddata->pd_gpio))
gpio_set_value_cansleep(ddata->pd_gpio, 1);
return 0;
err0:
return r;
}
static void tfp410_power_off(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = dev_get_drvdata(dssdev->dev);
if (dssdev->state != OMAP_DSS_DISPLAY_ACTIVE)
return;
if (gpio_is_valid(ddata->pd_gpio))
gpio_set_value_cansleep(ddata->pd_gpio, 0);
omapdss_dpi_display_disable(dssdev);
}
static int tfp410_probe(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata;
int r;
int i2c_bus_num;
ddata = devm_kzalloc(dssdev->dev, sizeof(*ddata), GFP_KERNEL);
if (!ddata)
return -ENOMEM;
dssdev->panel.timings = tfp410_default_timings;
ddata->dssdev = dssdev;
mutex_init(&ddata->lock);
if (dssdev->data) {
struct tfp410_platform_data *pdata = dssdev->data;
ddata->pd_gpio = pdata->power_down_gpio;
i2c_bus_num = pdata->i2c_bus_num;
} else {
ddata->pd_gpio = -1;
i2c_bus_num = -1;
}
if (gpio_is_valid(ddata->pd_gpio)) {
r = devm_gpio_request_one(dssdev->dev, ddata->pd_gpio,
GPIOF_OUT_INIT_LOW, "tfp410 pd");
if (r) {
dev_err(dssdev->dev, "Failed to request PD GPIO %d\n",
ddata->pd_gpio);
return r;
}
}
if (i2c_bus_num != -1) {
struct i2c_adapter *adapter;
adapter = i2c_get_adapter(i2c_bus_num);
if (!adapter) {
dev_err(dssdev->dev, "Failed to get I2C adapter, bus %d\n",
i2c_bus_num);
return -EPROBE_DEFER;
}
ddata->i2c_adapter = adapter;
}
dev_set_drvdata(dssdev->dev, ddata);
return 0;
}
static void __exit tfp410_remove(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = dev_get_drvdata(dssdev->dev);
mutex_lock(&ddata->lock);
if (ddata->i2c_adapter)
i2c_put_adapter(ddata->i2c_adapter);
dev_set_drvdata(dssdev->dev, NULL);
mutex_unlock(&ddata->lock);
}
static int tfp410_enable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = dev_get_drvdata(dssdev->dev);
int r;
mutex_lock(&ddata->lock);
r = tfp410_power_on(dssdev);
if (r == 0)
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
mutex_unlock(&ddata->lock);
return r;
}
static void tfp410_disable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = dev_get_drvdata(dssdev->dev);
mutex_lock(&ddata->lock);
tfp410_power_off(dssdev);
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
mutex_unlock(&ddata->lock);
}
static void tfp410_set_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = dev_get_drvdata(dssdev->dev);
mutex_lock(&ddata->lock);
omapdss_dpi_set_timings(dssdev, timings);
dssdev->panel.timings = *timings;
mutex_unlock(&ddata->lock);
}
static void tfp410_get_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = dev_get_drvdata(dssdev->dev);
mutex_lock(&ddata->lock);
*timings = dssdev->panel.timings;
mutex_unlock(&ddata->lock);
}
static int tfp410_check_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = dev_get_drvdata(dssdev->dev);
int r;
mutex_lock(&ddata->lock);
r = dpi_check_timings(dssdev, timings);
mutex_unlock(&ddata->lock);
return r;
}
static int tfp410_ddc_read(struct i2c_adapter *adapter,
unsigned char *buf, u16 count, u8 offset)
{
int r, retries;
for (retries = 3; retries > 0; retries--) {
struct i2c_msg msgs[] = {
{
.addr = DDC_ADDR,
.flags = 0,
.len = 1,
.buf = &offset,
}, {
.addr = DDC_ADDR,
.flags = I2C_M_RD,
.len = count,
.buf = buf,
}
};
r = i2c_transfer(adapter, msgs, 2);
if (r == 2)
return 0;
if (r != -EAGAIN)
break;
}
return r < 0 ? r : -EIO;
}
static int tfp410_read_edid(struct omap_dss_device *dssdev,
u8 *edid, int len)
{
struct panel_drv_data *ddata = dev_get_drvdata(dssdev->dev);
int r, l, bytes_read;
mutex_lock(&ddata->lock);
if (!ddata->i2c_adapter) {
r = -ENODEV;
goto err;
}
l = min(EDID_LENGTH, len);
r = tfp410_ddc_read(ddata->i2c_adapter, edid, l, 0);
if (r)
goto err;
bytes_read = l;
if (len > EDID_LENGTH && edid[0x7e] > 0) {
l = min(EDID_LENGTH, len - EDID_LENGTH);
r = tfp410_ddc_read(ddata->i2c_adapter, edid + EDID_LENGTH,
l, EDID_LENGTH);
if (r)
goto err;
bytes_read += l;
}
mutex_unlock(&ddata->lock);
return bytes_read;
err:
mutex_unlock(&ddata->lock);
return r;
}
static bool tfp410_detect(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = dev_get_drvdata(dssdev->dev);
unsigned char out;
int r;
mutex_lock(&ddata->lock);
if (!ddata->i2c_adapter)
goto out;
r = tfp410_ddc_read(ddata->i2c_adapter, &out, 1, 0);
mutex_unlock(&ddata->lock);
return r == 0;
out:
mutex_unlock(&ddata->lock);
return true;
}
static int __init tfp410_init(void)
{
return omap_dss_register_driver(&tfp410_driver);
}
static void __exit tfp410_exit(void)
{
omap_dss_unregister_driver(&tfp410_driver);
}
