static void __init zoom_lcd_panel_init(void)
{
zoom_lcd_gpios[0].gpio = (omap_rev() > OMAP3430_REV_ES3_0) ?
LCD_PANEL_RESET_GPIO_PROD :
LCD_PANEL_RESET_GPIO_PILOT;
if (gpio_request_array(zoom_lcd_gpios, ARRAY_SIZE(zoom_lcd_gpios)))
pr_err("%s: Failed to get LCD GPIOs.\n", __func__);
}
static int zoom_panel_enable_lcd(struct omap_dss_device *dssdev)
{
return 0;
}
static void zoom_panel_disable_lcd(struct omap_dss_device *dssdev)
{
}
static int zoom_set_bl_intensity(struct omap_dss_device *dssdev, int level)
{
unsigned char c;
u8 mux_pwm, enb_pwm;
if (level > 100)
return -1;
twl_i2c_read_u8(TWL4030_MODULE_INTBR, &mux_pwm, TWL_INTBR_PMBR1);
twl_i2c_read_u8(TWL4030_MODULE_INTBR, &enb_pwm, TWL_INTBR_GPBR1);
if (level == 0) {
enb_pwm = enb_pwm & 0xF5;
mux_pwm = mux_pwm & 0xCF;
twl_i2c_write_u8(TWL4030_MODULE_INTBR,
enb_pwm, TWL_INTBR_GPBR1);
twl_i2c_write_u8(TWL4030_MODULE_INTBR,
mux_pwm, TWL_INTBR_PMBR1);
return 0;
}
if (!((enb_pwm & 0xA) && (mux_pwm & 0x30))) {
mux_pwm = mux_pwm | 0x30;
enb_pwm = enb_pwm | 0x0A;
twl_i2c_write_u8(TWL4030_MODULE_INTBR,
mux_pwm, TWL_INTBR_PMBR1);
twl_i2c_write_u8(TWL4030_MODULE_INTBR,
enb_pwm, TWL_INTBR_GPBR1);
}
c = ((50 * (100 - level)) / 100) + 1;
twl_i2c_write_u8(TWL4030_MODULE_PWM1, 0x7F, TWL_LED_PWMOFF);
twl_i2c_write_u8(TWL4030_MODULE_PWM1, c, TWL_LED_PWMON);
return 0;
}
void __init zoom_display_init(void)
{
omap_display_init(&zoom_dss_data);
spi_register_board_info(nec_8048_spi_board_info,
ARRAY_SIZE(nec_8048_spi_board_info));
zoom_lcd_panel_init();
}
