static irqreturn_t nb0916_lcdcaseoff_handler(int irq, void *dev_id)
{
if (gpio_get_value(GPI_LCD_CASE_OFF))
gpio_set_value(GPO_LCD_EN, 1);
else
gpio_set_value(GPO_LCD_EN, 0);
return IRQ_HANDLED;
}
static irqreturn_t nb0916_overheat_handler(int irq, void *dev_id)
{
machine_halt();
return IRQ_HANDLED;
}
int __init mach_nb0916_init(void)
{
i2c_register_board_info(0, puv3_i2c_devices,
ARRAY_SIZE(puv3_i2c_devices));
platform_device_register_simple("PKUnity-v3-I2C", -1,
puv3_i2c_resources, ARRAY_SIZE(puv3_i2c_resources));
pwm_add_table(nb0916_pwm_lookup, ARRAY_SIZE(nb0916_pwm_lookup));
platform_device_register_data(NULL, "pwm-backlight", -1,
&nb0916_backlight_data, sizeof(nb0916_backlight_data));
platform_device_register_data(NULL, "gpio-keys", -1,
&nb0916_gpio_button_data, sizeof(nb0916_gpio_button_data));
platform_device_register_resndata(NULL, "physmap-flash", -1,
&physmap_flash_resource, 1,
&physmap_flash_data, sizeof(physmap_flash_data));
if (request_irq(gpio_to_irq(GPI_LCD_CASE_OFF),
&nb0916_lcdcaseoff_handler,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
"NB0916 lcd case off", NULL) < 0) {
printk(KERN_DEBUG "LCD-Case-OFF IRQ %d not available\n",
gpio_to_irq(GPI_LCD_CASE_OFF));
}
if (request_irq(gpio_to_irq(GPI_OTP_INT), &nb0916_overheat_handler,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
"NB0916 overheating protection", NULL) < 0) {
printk(KERN_DEBUG "Overheating Protection IRQ %d not available\n",
gpio_to_irq(GPI_OTP_INT));
}
return 0;
}
