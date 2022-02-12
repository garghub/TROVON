static void h3600_lcd_power(int enable)
{
if (gpio_request(H3XXX_EGPIO_LCD_ON, "LCD power")) {
pr_err("%s: can't request H3XXX_EGPIO_LCD_ON\n", __func__);
goto err1;
}
if (gpio_request(H3600_EGPIO_LCD_PCI, "LCD control")) {
pr_err("%s: can't request H3XXX_EGPIO_LCD_PCI\n", __func__);
goto err2;
}
if (gpio_request(H3600_EGPIO_LCD_5V_ON, "LCD 5v")) {
pr_err("%s: can't request H3XXX_EGPIO_LCD_5V_ON\n", __func__);
goto err3;
}
if (gpio_request(H3600_EGPIO_LVDD_ON, "LCD 9v/-6.5v")) {
pr_err("%s: can't request H3600_EGPIO_LVDD_ON\n", __func__);
goto err4;
}
gpio_direction_output(H3XXX_EGPIO_LCD_ON, enable);
gpio_direction_output(H3600_EGPIO_LCD_PCI, enable);
gpio_direction_output(H3600_EGPIO_LCD_5V_ON, enable);
gpio_direction_output(H3600_EGPIO_LVDD_ON, enable);
gpio_free(H3600_EGPIO_LVDD_ON);
err4: gpio_free(H3600_EGPIO_LCD_5V_ON);
err3: gpio_free(H3600_EGPIO_LCD_PCI);
err2: gpio_free(H3XXX_EGPIO_LCD_ON);
err1: return;
}
static void __init h3600_map_io(void)
{
h3xxx_map_io();
}
static int h3600_irda_set_power(struct device *dev, unsigned int state)
{
gpio_set_value(H3600_EGPIO_IR_ON, state);
return 0;
}
static void h3600_irda_set_speed(struct device *dev, unsigned int speed)
{
gpio_set_value(H3600_EGPIO_IR_FSEL, !(speed < 4000000));
}
static int h3600_irda_startup(struct device *dev)
{
int err = gpio_request(H3600_EGPIO_IR_ON, "IrDA power");
if (err)
goto err1;
err = gpio_direction_output(H3600_EGPIO_IR_ON, 0);
if (err)
goto err2;
err = gpio_request(H3600_EGPIO_IR_FSEL, "IrDA fsel");
if (err)
goto err2;
err = gpio_direction_output(H3600_EGPIO_IR_FSEL, 0);
if (err)
goto err3;
return 0;
err3: gpio_free(H3600_EGPIO_IR_FSEL);
err2: gpio_free(H3600_EGPIO_IR_ON);
err1: return err;
}
static void h3600_irda_shutdown(struct device *dev)
{
gpio_free(H3600_EGPIO_IR_ON);
gpio_free(H3600_EGPIO_IR_FSEL);
}
static void __init h3600_mach_init(void)
{
h3xxx_init_gpio(h3600_default_gpio, ARRAY_SIZE(h3600_default_gpio));
h3xxx_mach_init();
sa11x0_register_lcd(&h3600_lcd_info);
sa11x0_register_irda(&h3600_irda_data);
}
