static bool h3100_lcd_request(void)
{
static bool h3100_lcd_ok;
int rc;
if (h3100_lcd_ok)
return true;
rc = gpio_request_array(h3100_lcd_gpio, ARRAY_SIZE(h3100_lcd_gpio));
if (rc)
pr_err("%s: can't request GPIOs\n", __func__);
else
h3100_lcd_ok = true;
return h3100_lcd_ok;
}
static void h3100_lcd_power(int enable)
{
if (!h3100_lcd_request())
return;
gpio_set_value(H3100_GPIO_LCD_3V_ON, enable);
gpio_set_value(H3XXX_EGPIO_LCD_ON, enable);
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
static int h3100_irda_startup(struct device *dev)
{
return gpio_request_array(h3100_irda_gpio, sizeof(h3100_irda_gpio));
}
static void h3100_irda_shutdown(struct device *dev)
{
return gpio_free_array(h3100_irda_gpio, sizeof(h3100_irda_gpio));
}
static void __init h3100_mach_init(void)
{
h3xxx_mach_init();
sa11x0_register_lcd(&h3100_lcd_info);
sa11x0_register_irda(&h3100_irda_data);
}
