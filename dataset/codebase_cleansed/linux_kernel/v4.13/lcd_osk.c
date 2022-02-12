static int osk_panel_enable(struct lcd_panel *panel)
{
omap_cfg_reg(PWL);
omap_writeb(0x01, OMAP_PWL_CLK_ENABLE);
omap_writeb(0xFF, OMAP_PWL_ENABLE);
gpio_set_value(2, 1);
return 0;
}
static void osk_panel_disable(struct lcd_panel *panel)
{
omap_writeb(0x00, OMAP_PWL_ENABLE);
omap_writeb(0x00, OMAP_PWL_CLK_ENABLE);
gpio_set_value(2, 0);
}
static int osk_panel_probe(struct platform_device *pdev)
{
omapfb_register_panel(&osk_panel);
return 0;
}
