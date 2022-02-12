static void h3100_lcd_power(int enable)
{
if (!gpio_request(H3XXX_EGPIO_LCD_ON, "LCD ON")) {
gpio_set_value(H3100_GPIO_LCD_3V_ON, enable);
gpio_direction_output(H3XXX_EGPIO_LCD_ON, enable);
gpio_free(H3XXX_EGPIO_LCD_ON);
} else {
pr_err("%s: can't request H3XXX_EGPIO_LCD_ON\n", __func__);
}
}
static void __init h3100_map_io(void)
{
h3xxx_map_io();
GAFR &= ~0x000001fb;
}
static int h3100_irda_set_power(struct device *dev, unsigned int state)
{
gpio_set_value(H3100_GPIO_IR_ON, state);
return 0;
}
static void h3100_irda_set_speed(struct device *dev, unsigned int speed)
{
gpio_set_value(H3100_GPIO_IR_FSEL, !(speed < 4000000));
}
static void __init h3100_mach_init(void)
{
h3xxx_init_gpio(h3100_default_gpio, ARRAY_SIZE(h3100_default_gpio));
h3xxx_mach_init();
sa11x0_register_lcd(&h3100_lcd_info);
sa11x0_register_irda(&h3100_irda_data);
}
