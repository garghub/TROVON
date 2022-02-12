static inline struct panel_nec_nl8048_data
*get_panel_data(const struct omap_dss_device *dssdev)
{
return (struct panel_nec_nl8048_data *) dssdev->data;
}
static int nec_8048_panel_probe(struct omap_dss_device *dssdev)
{
struct panel_nec_nl8048_data *pd = get_panel_data(dssdev);
int r;
if (!pd)
return -EINVAL;
dssdev->panel.timings = nec_8048_panel_timings;
if (gpio_is_valid(pd->qvga_gpio)) {
r = devm_gpio_request_one(&dssdev->dev, pd->qvga_gpio,
GPIOF_OUT_INIT_HIGH, "lcd QVGA");
if (r)
return r;
}
if (gpio_is_valid(pd->res_gpio)) {
r = devm_gpio_request_one(&dssdev->dev, pd->res_gpio,
GPIOF_OUT_INIT_LOW, "lcd RES");
if (r)
return r;
}
return 0;
}
static void nec_8048_panel_remove(struct omap_dss_device *dssdev)
{
}
static int nec_8048_panel_power_on(struct omap_dss_device *dssdev)
{
struct panel_nec_nl8048_data *pd = get_panel_data(dssdev);
int r;
if (dssdev->state == OMAP_DSS_DISPLAY_ACTIVE)
return 0;
omapdss_dpi_set_timings(dssdev, &dssdev->panel.timings);
omapdss_dpi_set_data_lines(dssdev, dssdev->phy.dpi.data_lines);
r = omapdss_dpi_display_enable(dssdev);
if (r)
goto err0;
if (gpio_is_valid(pd->res_gpio))
gpio_set_value_cansleep(pd->res_gpio, 1);
return 0;
err0:
return r;
}
static void nec_8048_panel_power_off(struct omap_dss_device *dssdev)
{
struct panel_nec_nl8048_data *pd = get_panel_data(dssdev);
if (dssdev->state != OMAP_DSS_DISPLAY_ACTIVE)
return;
if (gpio_is_valid(pd->res_gpio))
gpio_set_value_cansleep(pd->res_gpio, 0);
omapdss_dpi_display_disable(dssdev);
}
static int nec_8048_panel_enable(struct omap_dss_device *dssdev)
{
int r;
r = nec_8048_panel_power_on(dssdev);
if (r)
return r;
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
return 0;
}
static void nec_8048_panel_disable(struct omap_dss_device *dssdev)
{
nec_8048_panel_power_off(dssdev);
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
}
static int nec_8048_recommended_bpp(struct omap_dss_device *dssdev)
{
return 16;
}
static int nec_8048_spi_send(struct spi_device *spi, unsigned char reg_addr,
unsigned char reg_data)
{
int ret = 0;
unsigned int cmd = 0, data = 0;
cmd = 0x0000 | reg_addr;
data = 0x0100 | reg_data ;
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
static int nec_8048_spi_probe(struct spi_device *spi)
{
spi->mode = SPI_MODE_0;
spi->bits_per_word = 32;
spi_setup(spi);
init_nec_8048_wvga_lcd(spi);
return omap_dss_register_driver(&nec_8048_driver);
}
static int nec_8048_spi_remove(struct spi_device *spi)
{
omap_dss_unregister_driver(&nec_8048_driver);
return 0;
}
static int nec_8048_spi_suspend(struct device *dev)
{
struct spi_device *spi = to_spi_device(dev);
nec_8048_spi_send(spi, 2, 0x01);
mdelay(40);
return 0;
}
static int nec_8048_spi_resume(struct device *dev)
{
struct spi_device *spi = to_spi_device(dev);
spi_setup(spi);
nec_8048_spi_send(spi, 2, 0x00);
init_nec_8048_wvga_lcd(spi);
return 0;
}
