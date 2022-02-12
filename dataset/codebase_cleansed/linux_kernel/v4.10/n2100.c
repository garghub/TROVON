static void __init n2100_timer_init(void)
{
iop_init_time(198000000);
}
void __init n2100_map_io(void)
{
iop3xx_map_io();
iotable_init(n2100_io_desc, ARRAY_SIZE(n2100_io_desc));
}
static int __init
n2100_pci_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
int irq;
if (PCI_SLOT(dev->devfn) == 1) {
irq = IRQ_IOP32X_XINT0;
} else if (PCI_SLOT(dev->devfn) == 2) {
irq = IRQ_IOP32X_XINT3;
} else if (PCI_SLOT(dev->devfn) == 3) {
irq = IRQ_IOP32X_XINT2;
} else if (PCI_SLOT(dev->devfn) == 4 && pin == 1) {
irq = IRQ_IOP32X_XINT1;
} else if (PCI_SLOT(dev->devfn) == 4 && pin == 2) {
irq = IRQ_IOP32X_XINT0;
} else if (PCI_SLOT(dev->devfn) == 4 && pin == 3) {
irq = IRQ_IOP32X_XINT2;
} else if (PCI_SLOT(dev->devfn) == 5) {
irq = IRQ_IOP32X_XINT3;
} else {
printk(KERN_ERR "n2100_pci_map_irq() called for unknown "
"device PCI:%d:%d:%d\n", dev->bus->number,
PCI_SLOT(dev->devfn), PCI_FUNC(dev->devfn));
irq = -1;
}
return irq;
}
static void n2100_fixup_r8169(struct pci_dev *dev)
{
if (dev->bus->number == 0 &&
(dev->devfn == PCI_DEVFN(1, 0) ||
dev->devfn == PCI_DEVFN(2, 0)))
dev->broken_parity_status = 1;
}
static int __init n2100_pci_init(void)
{
if (machine_is_n2100())
pci_common_init(&n2100_pci);
return 0;
}
static void n2100_power_off(void)
{
local_irq_disable();
*IOP3XX_IDBR0 = 0xc0;
*IOP3XX_ICR0 = 0xe9;
mdelay(1);
*IOP3XX_IDBR0 = 0x08;
*IOP3XX_ICR0 = 0xe8;
mdelay(1);
*IOP3XX_IDBR0 = 0x01;
*IOP3XX_ICR0 = 0xea;
while (1)
;
}
static void n2100_restart(enum reboot_mode mode, const char *cmd)
{
int ret;
ret = gpio_direction_output(N2100_HARDWARE_RESET, 0);
if (ret) {
pr_crit("could not drive reset GPIO low\n");
return;
}
while (1)
;
}
static void power_button_poll(unsigned long dummy)
{
if (gpio_get_value(N2100_POWER_BUTTON) == 0) {
ctrl_alt_del();
return;
}
power_button_poll_timer.expires = jiffies + (HZ / 10);
add_timer(&power_button_poll_timer);
}
static int __init n2100_request_gpios(void)
{
int ret;
if (!machine_is_n2100())
return 0;
ret = gpio_request(N2100_HARDWARE_RESET, "reset");
if (ret)
pr_err("could not request reset GPIO\n");
ret = gpio_request(N2100_POWER_BUTTON, "power");
if (ret)
pr_err("could not request power GPIO\n");
else {
ret = gpio_direction_input(N2100_POWER_BUTTON);
if (ret)
pr_err("could not set power GPIO as input\n");
}
init_timer(&power_button_poll_timer);
power_button_poll_timer.function = power_button_poll;
power_button_poll_timer.expires = jiffies + (HZ / 10);
add_timer(&power_button_poll_timer);
return 0;
}
static void __init n2100_init_machine(void)
{
register_iop32x_gpio();
platform_device_register(&iop3xx_i2c0_device);
platform_device_register(&n2100_flash_device);
platform_device_register(&n2100_serial_device);
platform_device_register(&iop3xx_dma_0_channel);
platform_device_register(&iop3xx_dma_1_channel);
i2c_register_board_info(0, n2100_i2c_devices,
ARRAY_SIZE(n2100_i2c_devices));
pm_power_off = n2100_power_off;
}
