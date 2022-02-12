static void edb7211_lcd_power_set(struct plat_lcd_data *pd, unsigned int power)
{
if (power) {
gpio_set_value(EDB7211_LCDEN, 1);
udelay(100);
gpio_set_value(EDB7211_LCD_DC_DC_EN, 1);
} else {
gpio_set_value(EDB7211_LCD_DC_DC_EN, 0);
udelay(100);
gpio_set_value(EDB7211_LCDEN, 0);
}
}
static void __init edb7211_reserve(void)
{
memblock_reserve(PHYS_OFFSET, VIDEORAM_SIZE);
}
static void __init
fixup_edb7211(struct tag *tags, char **cmdline)
{
memblock_add(0xc0000000, SZ_8M);
memblock_add(0xc1000000, SZ_8M);
}
static void __init edb7211_init_late(void)
{
gpio_request_array(edb7211_gpios, ARRAY_SIZE(edb7211_gpios));
platform_device_register(&edb7211_flash_pdev);
platform_device_register_data(NULL, "platform-lcd", 0,
&edb7211_lcd_power_pdata,
sizeof(edb7211_lcd_power_pdata));
platform_device_register_simple("clps711x-pwm", PLATFORM_DEVID_NONE,
&clps711x_pwm_res, 1);
pwm_add_table(edb7211_pwm_lookup, ARRAY_SIZE(edb7211_pwm_lookup));
platform_device_register_data(&platform_bus, "pwm-backlight", 0,
&pwm_bl_pdata, sizeof(pwm_bl_pdata));
platform_device_register_simple("video-clps711x", 0, NULL, 0);
platform_device_register_simple("cs89x0", 0, edb7211_cs8900_resource,
ARRAY_SIZE(edb7211_cs8900_resource));
platform_device_register_data(NULL, "i2c-gpio", 0,
&edb7211_i2c_pdata,
sizeof(edb7211_i2c_pdata));
}
