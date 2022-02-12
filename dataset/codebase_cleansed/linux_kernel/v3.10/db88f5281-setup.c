static void db88f5281_7seg_event(unsigned long data)
{
static int count = 0;
writel(0, db88f5281_7seg + (count << 4));
count = (count + 1) & 7;
mod_timer(&db88f5281_timer, jiffies + 2 * HZ);
}
static int __init db88f5281_7seg_init(void)
{
if (machine_is_db88f5281()) {
db88f5281_7seg = ioremap(DB88F5281_7SEG_BASE,
DB88F5281_7SEG_SIZE);
if (!db88f5281_7seg) {
printk(KERN_ERR "Failed to ioremap db88f5281_7seg\n");
return -EIO;
}
setup_timer(&db88f5281_timer, db88f5281_7seg_event, 0);
mod_timer(&db88f5281_timer, jiffies + 2 * HZ);
}
return 0;
}
void __init db88f5281_pci_preinit(void)
{
int pin;
pin = DB88F5281_PCI_SLOT0_IRQ_PIN;
if (gpio_request(pin, "PCI Int1") == 0) {
if (gpio_direction_input(pin) == 0) {
irq_set_irq_type(gpio_to_irq(pin), IRQ_TYPE_LEVEL_LOW);
} else {
printk(KERN_ERR "db88f5281_pci_preinit failed to "
"set_irq_type pin %d\n", pin);
gpio_free(pin);
}
} else {
printk(KERN_ERR "db88f5281_pci_preinit failed to gpio_request %d\n", pin);
}
pin = DB88F5281_PCI_SLOT1_SLOT2_IRQ_PIN;
if (gpio_request(pin, "PCI Int2") == 0) {
if (gpio_direction_input(pin) == 0) {
irq_set_irq_type(gpio_to_irq(pin), IRQ_TYPE_LEVEL_LOW);
} else {
printk(KERN_ERR "db88f5281_pci_preinit failed "
"to set_irq_type pin %d\n", pin);
gpio_free(pin);
}
} else {
printk(KERN_ERR "db88f5281_pci_preinit failed to gpio_request %d\n", pin);
}
}
static int __init db88f5281_pci_map_irq(const struct pci_dev *dev, u8 slot,
u8 pin)
{
int irq;
irq = orion5x_pci_map_irq(dev, slot, pin);
if (irq != -1)
return irq;
switch (slot - DB88F5281_PCI_SLOT0_OFFS) {
case 0:
return gpio_to_irq(DB88F5281_PCI_SLOT0_IRQ_PIN);
case 1:
case 2:
return gpio_to_irq(DB88F5281_PCI_SLOT1_SLOT2_IRQ_PIN);
default:
return -1;
}
}
static int __init db88f5281_pci_init(void)
{
if (machine_is_db88f5281())
pci_common_init(&db88f5281_pci);
return 0;
}
static void __init db88f5281_init(void)
{
orion5x_init();
orion5x_mpp_conf(db88f5281_mpp_modes);
writel(0, MPP_DEV_CTRL);
orion5x_ehci0_init();
orion5x_eth_init(&db88f5281_eth_data);
orion5x_i2c_init();
orion5x_uart0_init();
orion5x_uart1_init();
mvebu_mbus_add_window("devbus-boot", DB88F5281_NOR_BOOT_BASE,
DB88F5281_NOR_BOOT_SIZE);
platform_device_register(&db88f5281_boot_flash);
mvebu_mbus_add_window("devbus-cs0", DB88F5281_7SEG_BASE,
DB88F5281_7SEG_SIZE);
mvebu_mbus_add_window("devbus-cs1", DB88F5281_NOR_BASE,
DB88F5281_NOR_SIZE);
platform_device_register(&db88f5281_nor_flash);
mvebu_mbus_add_window("devbus-cs2", DB88F5281_NAND_BASE,
DB88F5281_NAND_SIZE);
platform_device_register(&db88f5281_nand_flash);
i2c_register_board_info(0, &db88f5281_i2c_rtc, 1);
}
