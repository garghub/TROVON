static void dsmg600_power_off(void)
{
gpio_line_config(DSMG600_PO_GPIO, IXP4XX_GPIO_OUT);
gpio_line_set(DSMG600_PO_GPIO, IXP4XX_GPIO_HIGH);
}
static void dsmg600_power_handler(unsigned long data)
{
if (gpio_get_value(DSMG600_PB_GPIO)) {
if (power_button_countdown > 0)
power_button_countdown--;
} else {
if (power_button_countdown == 0) {
ctrl_alt_del();
gpio_line_set(DSMG600_LED_PWR_GPIO, IXP4XX_GPIO_LOW);
} else {
power_button_countdown = PBUTTON_HOLDDOWN_COUNT;
}
}
mod_timer(&dsmg600_power_timer, jiffies + msecs_to_jiffies(500));
}
static irqreturn_t dsmg600_reset_handler(int irq, void *dev_id)
{
machine_power_off();
return IRQ_HANDLED;
}
static void __init dsmg600_timer_init(void)
{
ixp4xx_timer_freq = DSMG600_FREQ;
ixp4xx_timer_init();
}
static void __init dsmg600_init(void)
{
ixp4xx_sys_init();
*IXP4XX_GPIO_GPCLKR = 0;
dsmg600_flash_resource.start = IXP4XX_EXP_BUS_BASE(0);
dsmg600_flash_resource.end =
IXP4XX_EXP_BUS_BASE(0) + ixp4xx_exp_bus_size - 1;
i2c_register_board_info(0, dsmg600_i2c_board_info,
ARRAY_SIZE(dsmg600_i2c_board_info));
(void)platform_device_register(&dsmg600_uart);
platform_add_devices(dsmg600_devices, ARRAY_SIZE(dsmg600_devices));
pm_power_off = dsmg600_power_off;
if (request_irq(gpio_to_irq(DSMG600_RB_GPIO), &dsmg600_reset_handler,
IRQF_DISABLED | IRQF_TRIGGER_LOW,
"DSM-G600 reset button", NULL) < 0) {
printk(KERN_DEBUG "Reset Button IRQ %d not available\n",
gpio_to_irq(DSMG600_RB_GPIO));
}
gpio_line_config(DSMG600_PB_GPIO, IXP4XX_GPIO_IN);
power_button_countdown = PBUTTON_HOLDDOWN_COUNT;
mod_timer(&dsmg600_power_timer, jiffies + msecs_to_jiffies(500));
}
