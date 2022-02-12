static void __init qnap_ts209_pci_preinit(void)
{
int pin;
pin = QNAP_TS209_PCI_SLOT0_IRQ_PIN;
if (gpio_request(pin, "PCI Int1") == 0) {
if (gpio_direction_input(pin) == 0) {
irq_set_irq_type(gpio_to_irq(pin), IRQ_TYPE_LEVEL_LOW);
} else {
printk(KERN_ERR "qnap_ts209_pci_preinit failed to "
"set_irq_type pin %d\n", pin);
gpio_free(pin);
}
} else {
printk(KERN_ERR "qnap_ts209_pci_preinit failed to gpio_request "
"%d\n", pin);
}
pin = QNAP_TS209_PCI_SLOT1_IRQ_PIN;
if (gpio_request(pin, "PCI Int2") == 0) {
if (gpio_direction_input(pin) == 0) {
irq_set_irq_type(gpio_to_irq(pin), IRQ_TYPE_LEVEL_LOW);
} else {
printk(KERN_ERR "qnap_ts209_pci_preinit failed "
"to set_irq_type pin %d\n", pin);
gpio_free(pin);
}
} else {
printk(KERN_ERR "qnap_ts209_pci_preinit failed to gpio_request "
"%d\n", pin);
}
}
static int __init qnap_ts209_pci_map_irq(const struct pci_dev *dev, u8 slot,
u8 pin)
{
int irq;
irq = orion5x_pci_map_irq(dev, slot, pin);
if (irq != -1)
return irq;
switch (slot - QNAP_TS209_PCI_SLOT0_OFFS) {
case 0:
return gpio_to_irq(QNAP_TS209_PCI_SLOT0_IRQ_PIN);
case 1:
return gpio_to_irq(QNAP_TS209_PCI_SLOT1_IRQ_PIN);
default:
return -1;
}
}
static int __init qnap_ts209_pci_init(void)
{
if (machine_is_ts209())
pci_common_init(&qnap_ts209_pci);
return 0;
}
static void __init qnap_ts209_init(void)
{
orion5x_init();
orion5x_mpp_conf(ts209_mpp_modes);
mvebu_mbus_add_window_by_id(ORION_MBUS_DEVBUS_BOOT_TARGET,
ORION_MBUS_DEVBUS_BOOT_ATTR,
QNAP_TS209_NOR_BOOT_BASE,
QNAP_TS209_NOR_BOOT_SIZE);
platform_device_register(&qnap_ts209_nor_flash);
orion5x_ehci0_init();
orion5x_ehci1_init();
qnap_tsx09_find_mac_addr(QNAP_TS209_NOR_BOOT_BASE +
qnap_ts209_partitions[5].offset,
qnap_ts209_partitions[5].size);
orion5x_eth_init(&qnap_tsx09_eth_data);
orion5x_i2c_init();
orion5x_sata_init(&qnap_ts209_sata_data);
orion5x_uart0_init();
orion5x_uart1_init();
orion5x_xor_init();
platform_device_register(&qnap_ts209_button_device);
if (gpio_request(TS209_RTC_GPIO, "rtc") == 0) {
if (gpio_direction_input(TS209_RTC_GPIO) == 0)
qnap_ts209_i2c_rtc.irq = gpio_to_irq(TS209_RTC_GPIO);
else
gpio_free(TS209_RTC_GPIO);
}
if (qnap_ts209_i2c_rtc.irq == 0)
pr_warn("qnap_ts209_init: failed to get RTC IRQ\n");
i2c_register_board_info(0, &qnap_ts209_i2c_rtc, 1);
pm_power_off = qnap_tsx09_power_off;
}
