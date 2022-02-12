static void __init rd88f5182_pci_preinit(void)
{
int pin;
pin = RD88F5182_PCI_SLOT0_IRQ_A_PIN;
if (gpio_request(pin, "PCI IntA") == 0) {
if (gpio_direction_input(pin) == 0) {
irq_set_irq_type(gpio_to_irq(pin), IRQ_TYPE_LEVEL_LOW);
} else {
printk(KERN_ERR "rd88f5182_pci_preinit failed to "
"set_irq_type pin %d\n", pin);
gpio_free(pin);
}
} else {
printk(KERN_ERR "rd88f5182_pci_preinit failed to request gpio %d\n", pin);
}
pin = RD88F5182_PCI_SLOT0_IRQ_B_PIN;
if (gpio_request(pin, "PCI IntB") == 0) {
if (gpio_direction_input(pin) == 0) {
irq_set_irq_type(gpio_to_irq(pin), IRQ_TYPE_LEVEL_LOW);
} else {
printk(KERN_ERR "rd88f5182_pci_preinit failed to "
"set_irq_type pin %d\n", pin);
gpio_free(pin);
}
} else {
printk(KERN_ERR "rd88f5182_pci_preinit failed to gpio_request %d\n", pin);
}
}
static int __init rd88f5182_pci_map_irq(const struct pci_dev *dev, u8 slot,
u8 pin)
{
int irq;
irq = orion5x_pci_map_irq(dev, slot, pin);
if (irq != -1)
return irq;
switch (slot - RD88F5182_PCI_SLOT0_OFFS) {
case 0:
if (pin == 1)
return gpio_to_irq(RD88F5182_PCI_SLOT0_IRQ_A_PIN);
else
return gpio_to_irq(RD88F5182_PCI_SLOT0_IRQ_B_PIN);
default:
return -1;
}
}
static int __init rd88f5182_pci_init(void)
{
if (machine_is_rd88f5182())
pci_common_init(&rd88f5182_pci);
return 0;
}
static void __init rd88f5182_init(void)
{
orion5x_init();
orion5x_mpp_conf(rd88f5182_mpp_modes);
orion5x_ehci0_init();
orion5x_ehci1_init();
orion5x_eth_init(&rd88f5182_eth_data);
orion5x_i2c_init();
orion5x_sata_init(&rd88f5182_sata_data);
orion5x_uart0_init();
orion5x_xor_init();
mvebu_mbus_add_window_by_id(ORION_MBUS_DEVBUS_BOOT_TARGET,
ORION_MBUS_DEVBUS_BOOT_ATTR,
RD88F5182_NOR_BOOT_BASE,
RD88F5182_NOR_BOOT_SIZE);
mvebu_mbus_add_window_by_id(ORION_MBUS_DEVBUS_TARGET(1),
ORION_MBUS_DEVBUS_ATTR(1),
RD88F5182_NOR_BASE,
RD88F5182_NOR_SIZE);
platform_device_register(&rd88f5182_nor_flash);
platform_device_register(&rd88f5182_gpio_leds);
i2c_register_board_info(0, &rd88f5182_i2c_rtc, 1);
}
