static int mddi_ext_lcd_on(struct platform_device *pdev)
{
return 0;
}
static int mddi_ext_lcd_off(struct platform_device *pdev)
{
return 0;
}
static int __init mddi_ext_lcd_probe(struct platform_device *pdev)
{
msm_fb_add_device(pdev);
return 0;
}
static int __init mddi_ext_lcd_init(void)
{
int ret;
struct msm_panel_info *pinfo;
ret = platform_driver_register(&this_driver);
if (!ret) {
pinfo = &mddi_ext_lcd_panel_data.panel_info;
pinfo->lcd.vsync_enable = FALSE;
pinfo->mddi.vdopkt = MDDI_DEFAULT_PRIM_PIX_ATTR;
ret = platform_device_register(&this_device);
if (ret)
platform_driver_unregister(&this_driver);
}
return ret;
}
