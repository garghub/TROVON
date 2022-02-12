static int innovator1610_panel_init(struct lcd_panel *panel,
struct omapfb_device *fbdev)
{
int r = 0;
if (gpio_request_one(14, GPIOF_OUT_INIT_LOW, "lcd_en0")) {
pr_err(MODULE_NAME ": can't request GPIO 14\n");
r = -1;
goto exit;
}
if (gpio_request_one(15, GPIOF_OUT_INIT_LOW, "lcd_en1")) {
pr_err(MODULE_NAME ": can't request GPIO 15\n");
gpio_free(14);
r = -1;
goto exit;
}
exit:
return r;
}
static void innovator1610_panel_cleanup(struct lcd_panel *panel)
{
gpio_free(15);
gpio_free(14);
}
static int innovator1610_panel_enable(struct lcd_panel *panel)
{
gpio_set_value(14, 1);
gpio_set_value(15, 1);
return 0;
}
static void innovator1610_panel_disable(struct lcd_panel *panel)
{
gpio_set_value(14, 0);
gpio_set_value(15, 0);
}
static int innovator1610_panel_probe(struct platform_device *pdev)
{
omapfb_register_panel(&innovator1610_panel);
return 0;
}
