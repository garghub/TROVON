static irqreturn_t gpio_interrupt(int irq, void *ignored)
{
int state;
if (!ssb_chipco_irq_status(&bcm47xx_bus.ssb.chipco,
SSB_CHIPCO_IRQ_GPIO))
return IRQ_NONE;
state = gpio_get_value(WGT634U_GPIO_RESET);
ssb_gpio_polarity(&bcm47xx_bus.ssb, 1 << WGT634U_GPIO_RESET,
state ? 1 << WGT634U_GPIO_RESET : 0);
if (!state) {
printk(KERN_INFO "Reset button pressed");
ctrl_alt_del();
}
return IRQ_HANDLED;
}
static int __init wgt634u_init(void)
{
u8 *et0mac;
if (bcm47xx_bus_type != BCM47XX_BUS_TYPE_SSB)
return -ENODEV;
et0mac = bcm47xx_bus.ssb.sprom.et0mac;
if (et0mac[0] == 0x00 &&
((et0mac[1] == 0x09 && et0mac[2] == 0x5b) ||
(et0mac[1] == 0x0f && et0mac[2] == 0xb5))) {
struct ssb_mipscore *mcore = &bcm47xx_bus.ssb.mipscore;
printk(KERN_INFO "WGT634U machine detected.\n");
if (!request_irq(gpio_to_irq(WGT634U_GPIO_RESET),
gpio_interrupt, IRQF_SHARED,
"WGT634U GPIO", &bcm47xx_bus.ssb.chipco)) {
gpio_direction_input(WGT634U_GPIO_RESET);
ssb_gpio_intmask(&bcm47xx_bus.ssb,
1 << WGT634U_GPIO_RESET,
1 << WGT634U_GPIO_RESET);
ssb_chipco_irq_mask(&bcm47xx_bus.ssb.chipco,
SSB_CHIPCO_IRQ_GPIO,
SSB_CHIPCO_IRQ_GPIO);
}
wgt634u_flash_data.width = mcore->pflash.buswidth;
wgt634u_flash_resource.start = mcore->pflash.window;
wgt634u_flash_resource.end = mcore->pflash.window
+ mcore->pflash.window_size
- 1;
return platform_add_devices(wgt634u_devices,
ARRAY_SIZE(wgt634u_devices));
} else
return -ENODEV;
}
