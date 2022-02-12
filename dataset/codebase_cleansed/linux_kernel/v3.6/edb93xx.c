static void __init edb93xx_register_flash(void)
{
if (machine_is_edb9307() || machine_is_edb9312() ||
machine_is_edb9315()) {
ep93xx_register_flash(4, EP93XX_CS6_PHYS_BASE, SZ_32M);
} else {
ep93xx_register_flash(2, EP93XX_CS6_PHYS_BASE, SZ_16M);
}
}
static void __init edb93xx_register_i2c(void)
{
if (machine_is_edb9302a() || machine_is_edb9307a() ||
machine_is_edb9315a()) {
ep93xx_register_i2c(&edb93xx_i2c_gpio_data,
edb93xxa_i2c_board_info,
ARRAY_SIZE(edb93xxa_i2c_board_info));
} else if (machine_is_edb9302() || machine_is_edb9307()
|| machine_is_edb9312() || machine_is_edb9315()) {
ep93xx_register_i2c(&edb93xx_i2c_gpio_data,
edb93xx_i2c_board_info,
ARRAY_SIZE(edb93xx_i2c_board_info));
}
}
static int edb93xx_cs4271_hw_setup(struct spi_device *spi)
{
return gpio_request_one(EP93XX_GPIO_LINE_EGPIO6,
GPIOF_OUT_INIT_HIGH, spi->modalias);
}
static void edb93xx_cs4271_hw_cleanup(struct spi_device *spi)
{
gpio_free(EP93XX_GPIO_LINE_EGPIO6);
}
static void edb93xx_cs4271_hw_cs_control(struct spi_device *spi, int value)
{
gpio_set_value(EP93XX_GPIO_LINE_EGPIO6, value);
}
static void __init edb93xx_register_spi(void)
{
if (machine_is_edb9301() || machine_is_edb9302())
edb93xx_cs4271_data.gpio_nreset = EP93XX_GPIO_LINE_EGPIO1;
else if (machine_is_edb9302a() || machine_is_edb9307a())
edb93xx_cs4271_data.gpio_nreset = EP93XX_GPIO_LINE_H(2);
else if (machine_is_edb9315a())
edb93xx_cs4271_data.gpio_nreset = EP93XX_GPIO_LINE_EGPIO14;
ep93xx_register_spi(&edb93xx_spi_info, edb93xx_spi_board_info,
ARRAY_SIZE(edb93xx_spi_board_info));
}
static int __init edb93xx_has_audio(void)
{
return (machine_is_edb9301() || machine_is_edb9302() ||
machine_is_edb9302a() || machine_is_edb9307a() ||
machine_is_edb9315a());
}
static void __init edb93xx_register_i2s(void)
{
if (edb93xx_has_audio()) {
ep93xx_register_i2s();
platform_device_register(&edb93xx_audio_device);
}
}
static void __init edb93xx_register_pwm(void)
{
if (machine_is_edb9301() ||
machine_is_edb9302() || machine_is_edb9302a()) {
ep93xx_register_pwm(0, 1);
} else if (machine_is_edb9307() || machine_is_edb9307a()) {
ep93xx_register_pwm(1, 0);
} else {
ep93xx_register_pwm(1, 1);
}
}
static int __init edb93xx_has_fb(void)
{
return machine_is_edb9307() || machine_is_edb9307a() ||
machine_is_edb9312() || machine_is_edb9315() ||
machine_is_edb9315a();
}
static void __init edb93xx_register_fb(void)
{
if (!edb93xx_has_fb())
return;
if (machine_is_edb9307a() || machine_is_edb9315a())
edb93xxfb_info.flags |= EP93XXFB_USE_SDCSN0;
else
edb93xxfb_info.flags |= EP93XXFB_USE_SDCSN3;
ep93xx_register_fb(&edb93xxfb_info);
}
static int __init edb93xx_has_ide(void)
{
return machine_is_edb9312() || machine_is_edb9315() ||
machine_is_edb9315a();
}
static void __init edb93xx_register_ide(void)
{
if (!edb93xx_has_ide())
return;
ep93xx_register_ide();
}
static void __init edb93xx_init_machine(void)
{
ep93xx_init_devices();
edb93xx_register_flash();
ep93xx_register_eth(&edb93xx_eth_data, 1);
edb93xx_register_i2c();
edb93xx_register_spi();
edb93xx_register_i2s();
edb93xx_register_pwm();
edb93xx_register_fb();
edb93xx_register_ide();
}
