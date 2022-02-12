static void nas100d_power_off(void)
{
gpio_direction_output(NAS100D_PO_GPIO, 1);
}
static void nas100d_power_handler(unsigned long data)
{
if (gpio_get_value(NAS100D_PB_GPIO)) {
if (power_button_countdown > 0)
power_button_countdown--;
} else {
if (power_button_countdown == 0) {
ctrl_alt_del();
gpio_set_value(NAS100D_LED_PWR_GPIO, 0);
} else {
power_button_countdown = PBUTTON_HOLDDOWN_COUNT;
}
}
mod_timer(&nas100d_power_timer, jiffies + msecs_to_jiffies(500));
}
static irqreturn_t nas100d_reset_handler(int irq, void *dev_id)
{
machine_power_off();
return IRQ_HANDLED;
}
static int __init nas100d_gpio_init(void)
{
if (!machine_is_nas100d())
return 0;
gpio_request(NAS100D_PO_GPIO, "power off");
gpio_request(NAS100D_PB_GPIO, "power button");
gpio_direction_input(NAS100D_PB_GPIO);
power_button_countdown = PBUTTON_HOLDDOWN_COUNT;
mod_timer(&nas100d_power_timer, jiffies + msecs_to_jiffies(500));
return 0;
}
static void __init nas100d_init(void)
{
uint8_t __iomem *f;
int i;
ixp4xx_sys_init();
*IXP4XX_GPIO_GPCLKR = 0;
nas100d_flash_resource.start = IXP4XX_EXP_BUS_BASE(0);
nas100d_flash_resource.end =
IXP4XX_EXP_BUS_BASE(0) + ixp4xx_exp_bus_size - 1;
i2c_register_board_info(0, nas100d_i2c_board_info,
ARRAY_SIZE(nas100d_i2c_board_info));
(void)platform_device_register(&nas100d_uart);
platform_add_devices(nas100d_devices, ARRAY_SIZE(nas100d_devices));
pm_power_off = nas100d_power_off;
if (request_irq(gpio_to_irq(NAS100D_RB_GPIO), &nas100d_reset_handler,
IRQF_TRIGGER_LOW, "NAS100D reset button", NULL) < 0) {
printk(KERN_DEBUG "Reset Button IRQ %d not available\n",
gpio_to_irq(NAS100D_RB_GPIO));
}
f = ioremap(IXP4XX_EXP_BUS_BASE(0), 0x1000000);
if (f) {
for (i = 0; i < 6; i++)
#ifdef __ARMEB__
nas100d_plat_eth[0].hwaddr[i] = readb(f + 0xFC0FD8 + i);
#else
nas100d_plat_eth[0].hwaddr[i] = readb(f + 0xFC0FD8 + (i^3));
#endif
iounmap(f);
}
printk(KERN_INFO "NAS100D: Using MAC address %pM for port 0\n",
nas100d_plat_eth[0].hwaddr);
}
