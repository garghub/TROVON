static void __init iq80331_timer_init(void)
{
if (*IOP3XX_ATURID >= 0xa)
iop_init_time(333000000);
else
iop_init_time(266000000);
}
static int __init
iq80331_pci_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
int irq;
if (slot == 1 && pin == 1) {
irq = IRQ_IOP33X_XINT1;
} else if (slot == 1 && pin == 2) {
irq = IRQ_IOP33X_XINT2;
} else if (slot == 1 && pin == 3) {
irq = IRQ_IOP33X_XINT3;
} else if (slot == 1 && pin == 4) {
irq = IRQ_IOP33X_XINT0;
} else if (slot == 2) {
irq = IRQ_IOP33X_XINT2;
} else {
printk(KERN_ERR "iq80331_pci_map_irq() called for unknown "
"device PCI:%d:%d:%d\n", dev->bus->number,
PCI_SLOT(dev->devfn), PCI_FUNC(dev->devfn));
irq = -1;
}
return irq;
}
static int __init iq80331_pci_init(void)
{
if ((iop3xx_get_init_atu() == IOP3XX_INIT_ATU_ENABLE) &&
machine_is_iq80331())
pci_common_init(&iq80331_pci);
return 0;
}
static void __init iq80331_init_machine(void)
{
platform_device_register_simple("gpio-iop", 0,
iq80331_gpio_res,
ARRAY_SIZE(iq80331_gpio_res));
platform_device_register(&iop3xx_i2c0_device);
platform_device_register(&iop3xx_i2c1_device);
platform_device_register(&iop33x_uart0_device);
platform_device_register(&iop33x_uart1_device);
platform_device_register(&iq80331_flash_device);
platform_device_register(&iop3xx_dma_0_channel);
platform_device_register(&iop3xx_dma_1_channel);
platform_device_register(&iop3xx_aau_channel);
}
