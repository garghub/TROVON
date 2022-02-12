static inline struct panel_sharp_ls037v7dw01_data
*get_panel_data(const struct omap_dss_device *dssdev)
{
return (struct panel_sharp_ls037v7dw01_data *) dssdev->data;
}
static int sharp_ls_panel_probe(struct omap_dss_device *dssdev)
{
struct panel_sharp_ls037v7dw01_data *pd = get_panel_data(dssdev);
int r;
if (!pd)
return -EINVAL;
dssdev->panel.timings = sharp_ls_timings;
if (gpio_is_valid(pd->mo_gpio)) {
r = devm_gpio_request_one(&dssdev->dev, pd->mo_gpio,
GPIOF_OUT_INIT_LOW, "lcd MO");
if (r)
return r;
}
if (gpio_is_valid(pd->lr_gpio)) {
r = devm_gpio_request_one(&dssdev->dev, pd->lr_gpio,
GPIOF_OUT_INIT_HIGH, "lcd LR");
if (r)
return r;
}
if (gpio_is_valid(pd->ud_gpio)) {
r = devm_gpio_request_one(&dssdev->dev, pd->ud_gpio,
GPIOF_OUT_INIT_HIGH, "lcd UD");
if (r)
return r;
}
if (gpio_is_valid(pd->resb_gpio)) {
r = devm_gpio_request_one(&dssdev->dev, pd->resb_gpio,
GPIOF_OUT_INIT_LOW, "lcd RESB");
if (r)
return r;
}
if (gpio_is_valid(pd->ini_gpio)) {
r = devm_gpio_request_one(&dssdev->dev, pd->ini_gpio,
GPIOF_OUT_INIT_LOW, "lcd INI");
if (r)
return r;
}
return 0;
}
static void __exit sharp_ls_panel_remove(struct omap_dss_device *dssdev)
{
}
static int sharp_ls_power_on(struct omap_dss_device *dssdev)
{
struct panel_sharp_ls037v7dw01_data *pd = get_panel_data(dssdev);
int r = 0;
if (dssdev->state == OMAP_DSS_DISPLAY_ACTIVE)
return 0;
omapdss_dpi_set_timings(dssdev, &dssdev->panel.timings);
omapdss_dpi_set_data_lines(dssdev, dssdev->phy.dpi.data_lines);
r = omapdss_dpi_display_enable(dssdev);
if (r)
goto err0;
msleep(50);
if (gpio_is_valid(pd->resb_gpio))
gpio_set_value_cansleep(pd->resb_gpio, 1);
if (gpio_is_valid(pd->ini_gpio))
gpio_set_value_cansleep(pd->ini_gpio, 1);
return 0;
err0:
return r;
}
static void sharp_ls_power_off(struct omap_dss_device *dssdev)
{
struct panel_sharp_ls037v7dw01_data *pd = get_panel_data(dssdev);
if (dssdev->state != OMAP_DSS_DISPLAY_ACTIVE)
return;
if (gpio_is_valid(pd->ini_gpio))
gpio_set_value_cansleep(pd->ini_gpio, 0);
if (gpio_is_valid(pd->resb_gpio))
gpio_set_value_cansleep(pd->resb_gpio, 0);
msleep(100);
omapdss_dpi_display_disable(dssdev);
}
static int sharp_ls_panel_enable(struct omap_dss_device *dssdev)
{
int r;
r = sharp_ls_power_on(dssdev);
dssdev->state = OMAP_DSS_DISPLAY_ACTIVE;
return r;
}
static void sharp_ls_panel_disable(struct omap_dss_device *dssdev)
{
sharp_ls_power_off(dssdev);
dssdev->state = OMAP_DSS_DISPLAY_DISABLED;
}
static int __init sharp_ls_panel_drv_init(void)
{
return omap_dss_register_driver(&sharp_ls_driver);
}
static void __exit sharp_ls_panel_drv_exit(void)
{
omap_dss_unregister_driver(&sharp_ls_driver);
}
