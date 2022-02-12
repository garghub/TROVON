static int lb035q02_write_reg(struct spi_device *spi, u8 reg, u16 val)
{
struct spi_message msg;
struct spi_transfer index_xfer = {
.len = 3,
.cs_change = 1,
};
struct spi_transfer value_xfer = {
.len = 3,
};
u8 buffer[16];
spi_message_init(&msg);
buffer[0] = 0x70;
buffer[1] = 0x00;
buffer[2] = reg & 0x7f;
index_xfer.tx_buf = buffer;
spi_message_add_tail(&index_xfer, &msg);
buffer[4] = 0x72;
buffer[5] = val >> 8;
buffer[6] = val;
value_xfer.tx_buf = buffer + 4;
spi_message_add_tail(&value_xfer, &msg);
return spi_sync(spi, &msg);
}
static void init_lb035q02_panel(struct spi_device *spi)
{
lb035q02_write_reg(spi, 0x01, 0x6300);
lb035q02_write_reg(spi, 0x02, 0x0200);
lb035q02_write_reg(spi, 0x03, 0x0177);
lb035q02_write_reg(spi, 0x04, 0x04c7);
lb035q02_write_reg(spi, 0x05, 0xffc0);
lb035q02_write_reg(spi, 0x06, 0xe806);
lb035q02_write_reg(spi, 0x0a, 0x4008);
lb035q02_write_reg(spi, 0x0b, 0x0000);
lb035q02_write_reg(spi, 0x0d, 0x0030);
lb035q02_write_reg(spi, 0x0e, 0x2800);
lb035q02_write_reg(spi, 0x0f, 0x0000);
lb035q02_write_reg(spi, 0x16, 0x9f80);
lb035q02_write_reg(spi, 0x17, 0x0a0f);
lb035q02_write_reg(spi, 0x1e, 0x00c1);
lb035q02_write_reg(spi, 0x30, 0x0300);
lb035q02_write_reg(spi, 0x31, 0x0007);
lb035q02_write_reg(spi, 0x32, 0x0000);
lb035q02_write_reg(spi, 0x33, 0x0000);
lb035q02_write_reg(spi, 0x34, 0x0707);
lb035q02_write_reg(spi, 0x35, 0x0004);
lb035q02_write_reg(spi, 0x36, 0x0302);
lb035q02_write_reg(spi, 0x37, 0x0202);
lb035q02_write_reg(spi, 0x3a, 0x0a0d);
lb035q02_write_reg(spi, 0x3b, 0x0806);
}
static int lb035q02_connect(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
if (omapdss_device_is_connected(dssdev))
return 0;
r = in->ops.dpi->connect(in, dssdev);
if (r)
return r;
init_lb035q02_panel(ddata->spi);
return 0;
}
static void lb035q02_disconnect(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
if (!omapdss_device_is_connected(dssdev))
return;
in->ops.dpi->disconnect(in, dssdev);
}
static int lb035q02_enable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
if (!omapdss_device_is_connected(dssdev))
return -ENODEV;
if (omapdss_device_is_enabled(dssdev))
return 0;
in->ops.dpi->set_data_lines(in, ddata->data_lines);
in->ops.dpi->set_timings(in, &ddata->videomode);
r = in->ops.dpi->enable(in);
if (r)
return r;
if (gpio_is_valid(ddata->enable_gpio))
gpio_set_value_cansleep(ddata->enable_gpio, 1);
if (gpio_is_valid(ddata->backlight_gpio))
gpio_set_value_cansleep(ddata->backlight_gpio, 1);
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
return 0;
}
static void lb035q02_disable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
if (!omapdss_device_is_enabled(dssdev))
return;
if (gpio_is_valid(ddata->enable_gpio))
gpio_set_value_cansleep(ddata->enable_gpio, 0);
if (gpio_is_valid(ddata->backlight_gpio))
gpio_set_value_cansleep(ddata->backlight_gpio, 0);
in->ops.dpi->disable(in);
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
}
static void lb035q02_set_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
ddata->videomode = *timings;
dssdev->panel.timings = *timings;
in->ops.dpi->set_timings(in, timings);
}
static void lb035q02_get_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
*timings = ddata->videomode;
}
static int lb035q02_check_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
return in->ops.dpi->check_timings(in, timings);
}
static int lb035q02_probe_pdata(struct spi_device *spi)
{
const struct panel_lb035q02_platform_data *pdata;
struct panel_drv_data *ddata = dev_get_drvdata(&spi->dev);
struct omap_dss_device *dssdev, *in;
pdata = dev_get_platdata(&spi->dev);
in = omap_dss_find_output(pdata->source);
if (in == NULL) {
dev_err(&spi->dev, "failed to find video source '%s'\n",
pdata->source);
return -EPROBE_DEFER;
}
ddata->in = in;
ddata->data_lines = pdata->data_lines;
dssdev = &ddata->dssdev;
dssdev->name = pdata->name;
ddata->enable_gpio = pdata->enable_gpio;
ddata->backlight_gpio = pdata->backlight_gpio;
return 0;
}
static int lb035q02_panel_spi_probe(struct spi_device *spi)
{
struct panel_drv_data *ddata;
struct omap_dss_device *dssdev;
int r;
ddata = devm_kzalloc(&spi->dev, sizeof(*ddata), GFP_KERNEL);
if (ddata == NULL)
return -ENOMEM;
dev_set_drvdata(&spi->dev, ddata);
ddata->spi = spi;
if (dev_get_platdata(&spi->dev)) {
r = lb035q02_probe_pdata(spi);
if (r)
return r;
} else {
return -ENODEV;
}
if (gpio_is_valid(ddata->enable_gpio)) {
r = devm_gpio_request_one(&spi->dev, ddata->enable_gpio,
GPIOF_OUT_INIT_LOW, "panel enable");
if (r)
goto err_gpio;
}
if (gpio_is_valid(ddata->backlight_gpio)) {
r = devm_gpio_request_one(&spi->dev, ddata->backlight_gpio,
GPIOF_OUT_INIT_LOW, "panel backlight");
if (r)
goto err_gpio;
}
ddata->videomode = lb035q02_timings;
dssdev = &ddata->dssdev;
dssdev->dev = &spi->dev;
dssdev->driver = &lb035q02_ops;
dssdev->type = OMAP_DISPLAY_TYPE_DPI;
dssdev->owner = THIS_MODULE;
dssdev->panel.timings = ddata->videomode;
dssdev->phy.dpi.data_lines = ddata->data_lines;
r = omapdss_register_display(dssdev);
if (r) {
dev_err(&spi->dev, "Failed to register panel\n");
goto err_reg;
}
return 0;
err_reg:
err_gpio:
omap_dss_put_device(ddata->in);
return r;
}
static int lb035q02_panel_spi_remove(struct spi_device *spi)
{
struct panel_drv_data *ddata = dev_get_drvdata(&spi->dev);
struct omap_dss_device *dssdev = &ddata->dssdev;
struct omap_dss_device *in = ddata->in;
omapdss_unregister_display(dssdev);
lb035q02_disable(dssdev);
lb035q02_disconnect(dssdev);
omap_dss_put_device(in);
return 0;
}
