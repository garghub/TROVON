static int __init ext_uart_init(void)
{
if (!machine_is_voiceblue())
return -ENODEV;
voiceblue_ports[0].irq = gpio_to_irq(12);
voiceblue_ports[1].irq = gpio_to_irq(13);
voiceblue_ports[2].irq = gpio_to_irq(14);
voiceblue_ports[3].irq = gpio_to_irq(15);
serial_device.dev.platform_data = voiceblue_ports;
return platform_device_register(&serial_device);
}
static int panic_event(struct notifier_block *this, unsigned long event,
void *ptr)
{
if (test_and_set_bit(MACHINE_PANICED, &machine_state))
return NOTIFY_DONE;
omap_writeb(0x78, OMAP_LPG1_LCR);
omap_writeb(0x01, OMAP_LPG1_PMR);
return NOTIFY_DONE;
}
static int __init voiceblue_setup(void)
{
if (!machine_is_voiceblue())
return -ENODEV;
atomic_notifier_chain_register(&panic_notifier_list, &panic_block);
return 0;
}
void voiceblue_wdt_enable(void)
{
gpio_direction_output(0, 0);
gpio_set_value(0, 1);
gpio_set_value(0, 0);
wdt_gpio_state = 0;
}
void voiceblue_wdt_disable(void)
{
gpio_set_value(0, 0);
gpio_set_value(0, 1);
gpio_set_value(0, 0);
gpio_direction_input(0);
}
void voiceblue_wdt_ping(void)
{
if (test_bit(MACHINE_REBOOT, &machine_state))
return;
wdt_gpio_state = !wdt_gpio_state;
gpio_set_value(0, wdt_gpio_state);
}
static void voiceblue_restart(char mode, const char *cmd)
{
if (cpu_is_omap5912()) {
omap_writew(omap_readw(DPLL_CTL) & ~(1 << 4), DPLL_CTL);
omap_writew(0x8, ARM_RSTCT1);
}
set_bit(MACHINE_REBOOT, &machine_state);
voiceblue_wdt_enable();
while (1) ;
}
static void __init voiceblue_init(void)
{
omap_cfg_reg(UART1_TX);
omap_cfg_reg(UART1_RTS);
omap_cfg_reg(UART2_TX);
omap_cfg_reg(UART2_RTS);
omap_cfg_reg(UART3_TX);
omap_cfg_reg(UART3_RX);
gpio_request(0, "Watchdog");
gpio_request(7, "SMC91x reset");
gpio_direction_output(7, 1);
udelay(2);
gpio_set_value(7, 0);
mdelay(50);
gpio_request(8, "SMC91x irq");
gpio_request(6, "16C554 reset");
gpio_direction_output(6, 0);
gpio_request(12, "16C554 irq");
gpio_request(13, "16C554 irq");
gpio_request(14, "16C554 irq");
gpio_request(15, "16C554 irq");
irq_set_irq_type(gpio_to_irq(12), IRQ_TYPE_EDGE_RISING);
irq_set_irq_type(gpio_to_irq(13), IRQ_TYPE_EDGE_RISING);
irq_set_irq_type(gpio_to_irq(14), IRQ_TYPE_EDGE_RISING);
irq_set_irq_type(gpio_to_irq(15), IRQ_TYPE_EDGE_RISING);
voiceblue_smc91x_resources[1].start = gpio_to_irq(8);
voiceblue_smc91x_resources[1].end = gpio_to_irq(8);
platform_add_devices(voiceblue_devices, ARRAY_SIZE(voiceblue_devices));
omap_serial_init();
omap1_usb_init(&voiceblue_usb_config);
omap_register_i2c_bus(1, 100, NULL, 0);
omap_writeb(0x00, OMAP_LPG1_LCR);
omap_writeb(0x00, OMAP_LPG1_PMR);
}
