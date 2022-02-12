static void __init enp2611_timer_init(void)
{
ixp2000_init_time(50 * 1000 * 1000);
}
void __init enp2611_map_io(void)
{
ixp2000_map_io();
iotable_init(enp2611_io_desc, ARRAY_SIZE(enp2611_io_desc));
}
static int enp2611_pci_setup(int nr, struct pci_sys_data *sys)
{
sys->mem_offset = 0xe0000000;
ixp2000_pci_setup(nr, sys);
return 1;
}
static void __init enp2611_pci_preinit(void)
{
ixp2000_reg_write(IXP2000_PCI_ADDR_EXT, 0x00100000);
ixp2000_pci_preinit();
pcibios_setup("firmware");
}
static inline int enp2611_pci_valid_device(struct pci_bus *bus,
unsigned int devfn)
{
if (bus->number == 0x01 && devfn == 0x10)
return 0;
return 1;
}
static int enp2611_pci_read_config(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *value)
{
if (enp2611_pci_valid_device(bus, devfn))
return ixp2000_pci_read_config(bus, devfn, where, size, value);
return PCIBIOS_DEVICE_NOT_FOUND;
}
static int enp2611_pci_write_config(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 value)
{
if (enp2611_pci_valid_device(bus, devfn))
return ixp2000_pci_write_config(bus, devfn, where, size, value);
return PCIBIOS_DEVICE_NOT_FOUND;
}
static struct pci_bus * __init enp2611_pci_scan_bus(int nr,
struct pci_sys_data *sys)
{
return pci_scan_bus(sys->busnr, &enp2611_pci_ops, sys);
}
static int __init enp2611_pci_map_irq(const struct pci_dev *dev, u8 slot,
u8 pin)
{
int irq;
if (dev->bus->number == 0 && PCI_SLOT(dev->devfn) == 0) {
irq = IRQ_IXP2000_PCIA;
} else if (dev->bus->number == 0 && PCI_SLOT(dev->devfn) == 1) {
irq = IRQ_IXP2000_PCIB;
} else if (dev->bus->number == 0 && PCI_SLOT(dev->devfn) == 4) {
irq = -1;
} else if (dev->bus->number == 1 && PCI_SLOT(dev->devfn) == 0) {
irq = IRQ_IXP2000_PCIA;
} else if (dev->bus->number == 1 && PCI_SLOT(dev->devfn) == 1) {
irq = IRQ_IXP2000_PCIB;
} else {
printk(KERN_ERR "enp2611_pci_map_irq() called for unknown "
"device PCI:%d:%d:%d\n", dev->bus->number,
PCI_SLOT(dev->devfn), PCI_FUNC(dev->devfn));
irq = -1;
}
return irq;
}
int __init enp2611_pci_init(void)
{
if (machine_is_enp2611())
pci_common_init(&enp2611_pci);
return 0;
}
static void __init enp2611_init_machine(void)
{
platform_add_devices(enp2611_devices, ARRAY_SIZE(enp2611_devices));
ixp2000_uart_init();
}
