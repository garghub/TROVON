static void __init iq80321_timer_init(void)
{
iop_init_time(200000000);
}
void __init iq80321_map_io(void)
{
iop3xx_map_io();
iotable_init(iq80321_io_desc, ARRAY_SIZE(iq80321_io_desc));
}
static int __init
iq80321_pci_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
int irq;
if ((slot == 2 || slot == 6) && pin == 1) {
irq = IRQ_IOP32X_XINT2;
} else if ((slot == 2 || slot == 6) && pin == 2) {
irq = IRQ_IOP32X_XINT3;
} else if ((slot == 2 || slot == 6) && pin == 3) {
irq = IRQ_IOP32X_XINT0;
} else if ((slot == 2 || slot == 6) && pin == 4) {
irq = IRQ_IOP32X_XINT1;
} else if (slot == 4 || slot == 8) {
irq = IRQ_IOP32X_XINT0;
} else {
printk(KERN_ERR "iq80321_pci_map_irq() called for unknown "
"device PCI:%d:%d:%d\n", dev->bus->number,
PCI_SLOT(dev->devfn), PCI_FUNC(dev->devfn));
irq = -1;
}
return irq;
}
static int __init iq80321_pci_init(void)
{
if ((iop3xx_get_init_atu() == IOP3XX_INIT_ATU_ENABLE) &&
machine_is_iq80321())
pci_common_init(&iq80321_pci);
return 0;
}
static void __init iq80321_init_machine(void)
{
platform_device_register(&iop3xx_i2c0_device);
platform_device_register(&iop3xx_i2c1_device);
platform_device_register(&iq80321_flash_device);
platform_device_register(&iq80321_serial_device);
platform_device_register(&iop3xx_dma_0_channel);
platform_device_register(&iop3xx_dma_1_channel);
platform_device_register(&iop3xx_aau_channel);
}
