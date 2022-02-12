static int nec_8048_spi_send(struct spi_device *spi, unsigned char reg_addr,
unsigned char reg_data)
{
int ret = 0;
unsigned int cmd = 0, data = 0;
cmd = 0x0000 | reg_addr;
data = 0x0100 | reg_data;
data = (cmd << 16) | data;
ret = spi_write(spi, (unsigned char *)&data, 4);
if (ret)
pr_err("error in spi_write %x\n", data);
return ret;
}
static int init_nec_8048_wvga_lcd(struct spi_device *spi)
{
unsigned int i;
for (i = 0; i < (ARRAY_SIZE(nec_8048_init_seq) - 1); i++)
nec_8048_spi_send(spi, nec_8048_init_seq[i].addr,
nec_8048_init_seq[i].dat);
udelay(20);
nec_8048_spi_send(spi, nec_8048_init_seq[i].addr,
nec_8048_init_seq[i].dat);
return 0;
}
static int nec_8048_connect(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
int r;
if (omapdss_device_is_connected(dssdev))
return 0;
r = in->ops.dpi->connect(in, dssdev);
if (r)
return r;
return 0;
}
static void nec_8048_disconnect(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
if (!omapdss_device_is_connected(dssdev))
return;
in->ops.dpi->disconnect(in, dssdev);
}
static int nec_8048_enable(struct omap_dss_device *dssdev)
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
if (gpio_is_valid(ddata->res_gpio))
gpio_set_value_cansleep(ddata->res_gpio, 1);
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
return 0;
}
static void nec_8048_disable(struct omap_dss_device *dssdev)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
if (!omapdss_device_is_enabled(dssdev))
return;
if (gpio_is_valid(ddata->res_gpio))
gpio_set_value_cansleep(ddata->res_gpio, 0);
in->ops.dpi->disable(in);
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
}
static void nec_8048_set_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
ddata->videomode = *timings;
dssdev->panel.timings = *timings;
in->ops.dpi->set_timings(in, timings);
}
static void nec_8048_get_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
*timings = ddata->videomode;
}
static int nec_8048_check_timings(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct panel_drv_data *ddata = to_panel_data(dssdev);
struct omap_dss_device *in = ddata->in;
return in->ops.dpi->check_timings(in, timings);
}
static int nec_8048_probe_pdata(struct spi_device *spi)
{
const struct panel_nec_nl8048hl11_platform_data *pdata;
struct panel_drv_data *ddata = dev_get_drvdata(&spi->dev);
struct omap_dss_device *dssdev, *in;
pdata = dev_get_platdata(&spi->dev);
ddata->qvga_gpio = pdata->qvga_gpio;
ddata->res_gpio = pdata->res_gpio;
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
return 0;
}
static int nec_8048_probe(struct spi_device *spi)
{
struct panel_drv_data *ddata;
struct omap_dss_device *dssdev;
int r;
dev_dbg(&spi->dev, "%s\n", __func__);
spi->mode = SPI_MODE_0;
spi->bits_per_word = 32;
r = spi_setup(spi);
if (r < 0) {
dev_err(&spi->dev, "spi_setup failed: %d\n", r);
return r;
}
init_nec_8048_wvga_lcd(spi);
ddata = devm_kzalloc(&spi->dev, sizeof(*ddata), GFP_KERNEL);
if (ddata == NULL)
return -ENOMEM;
dev_set_drvdata(&spi->dev, ddata);
ddata->spi = spi;
if (dev_get_platdata(&spi->dev)) {
r = nec_8048_probe_pdata(spi);
if (r)
return r;
} else {
return -ENODEV;
}
if (gpio_is_valid(ddata->qvga_gpio)) {
r = devm_gpio_request_one(&spi->dev, ddata->qvga_gpio,
GPIOF_OUT_INIT_HIGH, "lcd QVGA");
if (r)
goto err_gpio;
}
if (gpio_is_valid(ddata->res_gpio)) {
r = devm_gpio_request_one(&spi->dev, ddata->res_gpio,
GPIOF_OUT_INIT_LOW, "lcd RES");
if (r)
goto err_gpio;
}
ddata->videomode = nec_8048_panel_timings;
dssdev = &ddata->dssdev;
dssdev->dev = &spi->dev;
dssdev->driver = &nec_8048_ops;
dssdev->type = OMAP_DISPLAY_TYPE_DPI;
dssdev->owner = THIS_MODULE;
dssdev->panel.timings = ddata->videomode;
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
static int nec_8048_remove(struct spi_device *spi)
{
struct panel_drv_data *ddata = dev_get_drvdata(&spi->dev);
struct omap_dss_device *dssdev = &ddata->dssdev;
struct omap_dss_device *in = ddata->in;
dev_dbg(&ddata->spi->dev, "%s\n", __func__);
omapdss_unregister_display(dssdev);
nec_8048_disable(dssdev);
nec_8048_disconnect(dssdev);
omap_dss_put_device(in);
return 0;
}
static int nec_8048_suspend(struct device *dev)
{
struct spi_device *spi = to_spi_device(dev);
nec_8048_spi_send(spi, 2, 0x01);
mdelay(40);
return 0;
}
static int nec_8048_resume(struct device *dev)
{
struct spi_device *spi = to_spi_device(dev);
spi_setup(spi);
nec_8048_spi_send(spi, 2, 0x00);
init_nec_8048_wvga_lcd(spi);
return 0;
}
