static int nec_8048_bl_update_status(struct backlight_device *bl)
{
struct omap_dss_device *dssdev = dev_get_drvdata(&bl->dev);
int level;
if (!dssdev->set_backlight)
return -EINVAL;
if (bl->props.fb_blank == FB_BLANK_UNBLANK &&
bl->props.power == FB_BLANK_UNBLANK)
level = bl->props.brightness;
else
level = 0;
return dssdev->set_backlight(dssdev, level);
}
static int nec_8048_bl_get_brightness(struct backlight_device *bl)
{
if (bl->props.fb_blank == FB_BLANK_UNBLANK &&
bl->props.power == FB_BLANK_UNBLANK)
return bl->props.brightness;
return 0;
}
static int nec_8048_panel_probe(struct omap_dss_device *dssdev)
{
struct backlight_device *bl;
struct nec_8048_data *necd;
struct backlight_properties props;
int r;
dssdev->panel.timings = nec_8048_panel_timings;
necd = kzalloc(sizeof(*necd), GFP_KERNEL);
if (!necd)
return -ENOMEM;
dev_set_drvdata(&dssdev->dev, necd);
memset(&props, 0, sizeof(struct backlight_properties));
props.max_brightness = 255;
bl = backlight_device_register("nec-8048", &dssdev->dev, dssdev,
&nec_8048_bl_ops, &props);
if (IS_ERR(bl)) {
r = PTR_ERR(bl);
kfree(necd);
return r;
}
necd->bl = bl;
bl->props.fb_blank = FB_BLANK_UNBLANK;
bl->props.power = FB_BLANK_UNBLANK;
bl->props.max_brightness = dssdev->max_backlight_level;
bl->props.brightness = dssdev->max_backlight_level;
r = nec_8048_bl_update_status(bl);
if (r < 0)
dev_err(&dssdev->dev, "failed to set lcd brightness\n");
return 0;
}
static void nec_8048_panel_remove(struct omap_dss_device *dssdev)
{
struct nec_8048_data *necd = dev_get_drvdata(&dssdev->dev);
struct backlight_device *bl = necd->bl;
bl->props.power = FB_BLANK_POWERDOWN;
nec_8048_bl_update_status(bl);
backlight_device_unregister(bl);
kfree(necd);
}
static int nec_8048_panel_power_on(struct omap_dss_device *dssdev)
{
int r;
struct nec_8048_data *necd = dev_get_drvdata(&dssdev->dev);
struct backlight_device *bl = necd->bl;
if (dssdev->state == OMAP_DSS_DISPLAY_ACTIVE)
return 0;
omapdss_dpi_set_timings(dssdev, &dssdev->panel.timings);
omapdss_dpi_set_data_lines(dssdev, dssdev->phy.dpi.data_lines);
r = omapdss_dpi_display_enable(dssdev);
if (r)
goto err0;
if (dssdev->platform_enable) {
r = dssdev->platform_enable(dssdev);
if (r)
goto err1;
}
r = nec_8048_bl_update_status(bl);
if (r < 0)
dev_err(&dssdev->dev, "failed to set lcd brightness\n");
return 0;
err1:
omapdss_dpi_display_disable(dssdev);
err0:
return r;
}
static void nec_8048_panel_power_off(struct omap_dss_device *dssdev)
{
struct nec_8048_data *necd = dev_get_drvdata(&dssdev->dev);
struct backlight_device *bl = necd->bl;
if (dssdev->state != OMAP_DSS_DISPLAY_ACTIVE)
return;
bl->props.brightness = 0;
nec_8048_bl_update_status(bl);
if (dssdev->platform_disable)
dssdev->platform_disable(dssdev);
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
static int nec_8048_spi_suspend(struct spi_device *spi, pm_message_t mesg)
{
nec_8048_spi_send(spi, 2, 0x01);
mdelay(40);
return 0;
}
static int nec_8048_spi_resume(struct spi_device *spi)
{
spi_setup(spi);
nec_8048_spi_send(spi, 2, 0x00);
init_nec_8048_wvga_lcd(spi);
return 0;
}
