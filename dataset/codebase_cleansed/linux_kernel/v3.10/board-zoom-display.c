static void __init zoom_lcd_panel_init(void)
{
zoom_lcd_data.res_gpio = (omap_rev() > OMAP3430_REV_ES3_0) ?
LCD_PANEL_RESET_GPIO_PROD :
LCD_PANEL_RESET_GPIO_PILOT;
}
void __init zoom_display_init(void)
{
omap_display_init(&zoom_dss_data);
spi_register_board_info(nec_8048_spi_board_info,
ARRAY_SIZE(nec_8048_spi_board_info));
zoom_lcd_panel_init();
}
