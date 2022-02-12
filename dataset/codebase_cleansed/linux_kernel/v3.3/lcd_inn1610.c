static int innovator1610_panel_init(struct lcd_panel *panel,
struct omapfb_device *fbdev)
{
int r = 0;
if (gpio_request(14, "lcd_en0")) {
pr_err(MODULE_NAME ": can't request GPIO 14\n");
r = -1;
goto exit;
}
if (gpio_request(15, "lcd_en1")) {
pr_err(MODULE_NAME ": can't request GPIO 15\n");
gpio_free(14);
r = -1;
goto exit;
}
gpio_direction_output(14, 0);
gpio_direction_output(15, 0);
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
static unsigned long innovator1610_panel_get_caps(struct lcd_panel *panel)
{
return 0;
}
static int innovator1610_panel_probe(struct platform_device *pdev)
{
omapfb_register_panel(&innovator1610_panel);
return 0;
}
static int innovator1610_panel_remove(struct platform_device *pdev)
{
return 0;
}
static int innovator1610_panel_suspend(struct platform_device *pdev,
pm_message_t mesg)
{
return 0;
}
static int innovator1610_panel_resume(struct platform_device *pdev)
{
return 0;
}
