int __init debug_card_init(u32 addr, unsigned gpio)
{
int status;
smc91x_resources[0].start = addr + 0x300;
smc91x_resources[0].end = addr + 0x30f;
smc91x_resources[1].start = gpio_to_irq(gpio);
smc91x_resources[1].end = gpio_to_irq(gpio);
status = gpio_request(gpio, "SMC91x irq");
if (status < 0) {
printk(KERN_ERR "GPIO%d unavailable for smc91x IRQ\n", gpio);
return status;
}
gpio_direction_input(gpio);
led_resources[0].start = addr;
led_resources[0].end = addr + SZ_4K - 1;
return platform_add_devices(debug_devices, ARRAY_SIZE(debug_devices));
}
