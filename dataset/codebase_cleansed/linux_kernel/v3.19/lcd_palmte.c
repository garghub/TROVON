static int palmte_panel_init(struct lcd_panel *panel,
struct omapfb_device *fbdev)
{
return 0;
}
static void palmte_panel_cleanup(struct lcd_panel *panel)
{
}
static int palmte_panel_enable(struct lcd_panel *panel)
{
return 0;
}
static void palmte_panel_disable(struct lcd_panel *panel)
{
}
static unsigned long palmte_panel_get_caps(struct lcd_panel *panel)
{
return 0;
}
static int palmte_panel_probe(struct platform_device *pdev)
{
omapfb_register_panel(&palmte_panel);
return 0;
}
static int palmte_panel_remove(struct platform_device *pdev)
{
return 0;
}
static int palmte_panel_suspend(struct platform_device *pdev, pm_message_t mesg)
{
return 0;
}
static int palmte_panel_resume(struct platform_device *pdev)
{
return 0;
}
