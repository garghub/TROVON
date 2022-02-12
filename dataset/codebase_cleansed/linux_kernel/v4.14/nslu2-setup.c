static void nslu2_power_off(void)
{
gpio_direction_output(NSLU2_PO_GPIO, 1);
}
static irqreturn_t nslu2_power_handler(int irq, void *dev_id)
{
ctrl_alt_del();
return IRQ_HANDLED;
}
static irqreturn_t nslu2_reset_handler(int irq, void *dev_id)
{
machine_power_off();
return IRQ_HANDLED;
}
static int __init nslu2_gpio_init(void)
{
if (!machine_is_nslu2())
return 0;
return gpio_request(NSLU2_PO_GPIO, "power off");
}
static void __init nslu2_timer_init(void)
{
ixp4xx_timer_freq = NSLU2_FREQ;
ixp4xx_timer_init();
}
static void __init nslu2_init(void)
{
uint8_t __iomem *f;
int i;
ixp4xx_sys_init();
nslu2_flash_resource.start = IXP4XX_EXP_BUS_BASE(0);
nslu2_flash_resource.end =
IXP4XX_EXP_BUS_BASE(0) + ixp4xx_exp_bus_size - 1;
i2c_register_board_info(0, nslu2_i2c_board_info,
ARRAY_SIZE(nslu2_i2c_board_info));
(void)platform_device_register(&nslu2_uart);
platform_add_devices(nslu2_devices, ARRAY_SIZE(nslu2_devices));
pm_power_off = nslu2_power_off;
if (request_irq(gpio_to_irq(NSLU2_RB_GPIO), &nslu2_reset_handler,
IRQF_TRIGGER_LOW, "NSLU2 reset button", NULL) < 0) {
printk(KERN_DEBUG "Reset Button IRQ %d not available\n",
gpio_to_irq(NSLU2_RB_GPIO));
}
if (request_irq(gpio_to_irq(NSLU2_PB_GPIO), &nslu2_power_handler,
IRQF_TRIGGER_HIGH, "NSLU2 power button", NULL) < 0) {
printk(KERN_DEBUG "Power Button IRQ %d not available\n",
gpio_to_irq(NSLU2_PB_GPIO));
}
f = ioremap(IXP4XX_EXP_BUS_BASE(0), 0x40000);
if (f) {
for (i = 0; i < 6; i++)
#ifdef __ARMEB__
nslu2_plat_eth[0].hwaddr[i] = readb(f + 0x3FFB0 + i);
#else
nslu2_plat_eth[0].hwaddr[i] = readb(f + 0x3FFB0 + (i^3));
#endif
iounmap(f);
}
printk(KERN_INFO "NSLU2: Using MAC address %pM for port 0\n",
nslu2_plat_eth[0].hwaddr);
}
