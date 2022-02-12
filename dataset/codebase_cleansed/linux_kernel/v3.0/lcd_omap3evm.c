static int omap3evm_panel_init(struct lcd_panel *panel,
struct omapfb_device *fbdev)
{
gpio_request(LCD_PANEL_LR, "LCD lr");
gpio_request(LCD_PANEL_UD, "LCD ud");
gpio_request(LCD_PANEL_INI, "LCD ini");
gpio_request(LCD_PANEL_RESB, "LCD resb");
gpio_request(LCD_PANEL_QVGA, "LCD qvga");
gpio_direction_output(LCD_PANEL_RESB, 1);
gpio_direction_output(LCD_PANEL_INI, 1);
gpio_direction_output(LCD_PANEL_QVGA, 0);
gpio_direction_output(LCD_PANEL_LR, 1);
gpio_direction_output(LCD_PANEL_UD, 1);
twl_i2c_write_u8(TWL4030_MODULE_LED, 0x11, TWL_LED_LEDEN);
twl_i2c_write_u8(TWL4030_MODULE_PWMA, 0x01, TWL_PWMA_PWMAON);
twl_i2c_write_u8(TWL4030_MODULE_PWMA, 0x02, TWL_PWMA_PWMAOFF);
bklight_level = 100;
return 0;
}
static void omap3evm_panel_cleanup(struct lcd_panel *panel)
{
gpio_free(LCD_PANEL_QVGA);
gpio_free(LCD_PANEL_RESB);
gpio_free(LCD_PANEL_INI);
gpio_free(LCD_PANEL_UD);
gpio_free(LCD_PANEL_LR);
}
static int omap3evm_panel_enable(struct lcd_panel *panel)
{
gpio_set_value(LCD_PANEL_ENABLE_GPIO, 0);
return 0;
}
static void omap3evm_panel_disable(struct lcd_panel *panel)
{
gpio_set_value(LCD_PANEL_ENABLE_GPIO, 1);
}
static unsigned long omap3evm_panel_get_caps(struct lcd_panel *panel)
{
return 0;
}
static int omap3evm_bklight_setlevel(struct lcd_panel *panel,
unsigned int level)
{
u8 c;
if ((level >= 0) && (level <= 100)) {
c = (125 * (100 - level)) / 100 + 2;
twl_i2c_write_u8(TWL4030_MODULE_PWMA, c, TWL_PWMA_PWMAOFF);
bklight_level = level;
}
return 0;
}
static unsigned int omap3evm_bklight_getlevel(struct lcd_panel *panel)
{
return bklight_level;
}
static unsigned int omap3evm_bklight_getmaxlevel(struct lcd_panel *panel)
{
return 100;
}
static int omap3evm_panel_probe(struct platform_device *pdev)
{
omapfb_register_panel(&omap3evm_panel);
return 0;
}
static int omap3evm_panel_remove(struct platform_device *pdev)
{
return 0;
}
static int omap3evm_panel_suspend(struct platform_device *pdev,
pm_message_t mesg)
{
return 0;
}
static int omap3evm_panel_resume(struct platform_device *pdev)
{
return 0;
}
static int __init omap3evm_panel_drv_init(void)
{
return platform_driver_register(&omap3evm_panel_driver);
}
static void __exit omap3evm_panel_drv_exit(void)
{
platform_driver_unregister(&omap3evm_panel_driver);
}
