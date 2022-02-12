static irqreturn_t gpio_interrupt(int irq, void *ignored)
{
int state;
if (!ssb_chipco_irq_status(&ssb_bcm47xx.chipco,
SSB_CHIPCO_IRQ_GPIO))
return IRQ_NONE;
state = gpio_get_value(WGT634U_GPIO_RESET);
gpio_polarity(WGT634U_GPIO_RESET, state);
if (!state) {
printk(KERN_INFO "Reset button pressed");
ctrl_alt_del();
}
return IRQ_HANDLED;
}
static int __init wgt634u_init(void)
{
u8 *et0mac = ssb_bcm47xx.sprom.et0mac;
if (et0mac[0] == 0x00 &&
((et0mac[1] == 0x09 && et0mac[2] == 0x5b) ||
(et0mac[1] == 0x0f && et0mac[2] == 0xb5))) {
struct ssb_mipscore *mcore = &ssb_bcm47xx.mipscore;
printk(KERN_INFO "WGT634U machine detected.\n");
if (!request_irq(gpio_to_irq(WGT634U_GPIO_RESET),
gpio_interrupt, IRQF_SHARED,
"WGT634U GPIO", &ssb_bcm47xx.chipco)) {
gpio_direction_input(WGT634U_GPIO_RESET);
gpio_intmask(WGT634U_GPIO_RESET, 1);
ssb_chipco_irq_mask(&ssb_bcm47xx.chipco,
SSB_CHIPCO_IRQ_GPIO,
SSB_CHIPCO_IRQ_GPIO);
}
wgt634u_flash_data.width = mcore->flash_buswidth;
wgt634u_flash_resource.start = mcore->flash_window;
wgt634u_flash_resource.end = mcore->flash_window
+ mcore->flash_window_size
- 1;
return platform_add_devices(wgt634u_devices,
ARRAY_SIZE(wgt634u_devices));
} else
return -ENODEV;
}
