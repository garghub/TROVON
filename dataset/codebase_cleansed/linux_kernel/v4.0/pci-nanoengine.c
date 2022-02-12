static void __iomem *nanoengine_pci_map_bus(struct pci_bus *bus,
unsigned int devfn, int where)
{
if (bus->number != 0 || (devfn >> 3) != 0)
return NULL;
return (void __iomem *)NANO_PCI_CONFIG_SPACE_VIRT +
((bus->number << 16) | (devfn << 8) | (where & ~3));
}
static int __init pci_nanoengine_map_irq(const struct pci_dev *dev, u8 slot,
u8 pin)
{
return NANOENGINE_IRQ_GPIO_PCI;
}
static int __init pci_nanoengine_setup_resources(struct pci_sys_data *sys)
{
if (request_resource(&ioport_resource, &pci_io_ports)) {
printk(KERN_ERR "PCI: unable to allocate io port region\n");
return -EBUSY;
}
if (request_resource(&iomem_resource, &pci_non_prefetchable_memory)) {
release_resource(&pci_io_ports);
printk(KERN_ERR "PCI: unable to allocate non prefetchable\n");
return -EBUSY;
}
if (request_resource(&iomem_resource, &pci_prefetchable_memory)) {
release_resource(&pci_io_ports);
release_resource(&pci_non_prefetchable_memory);
printk(KERN_ERR "PCI: unable to allocate prefetchable\n");
return -EBUSY;
}
pci_add_resource_offset(&sys->resources, &pci_io_ports, sys->io_offset);
pci_add_resource_offset(&sys->resources,
&pci_non_prefetchable_memory, sys->mem_offset);
pci_add_resource_offset(&sys->resources,
&pci_prefetchable_memory, sys->mem_offset);
return 1;
}
int __init pci_nanoengine_setup(int nr, struct pci_sys_data *sys)
{
int ret = 0;
pcibios_min_io = 0;
pcibios_min_mem = 0;
if (nr == 0) {
sys->mem_offset = NANO_PCI_MEM_RW_PHYS;
sys->io_offset = 0x400;
ret = pci_nanoengine_setup_resources(sys);
GPDR = (GPDR & ~GPIO_MBREQ) | GPIO_MBGNT;
GAFR |= GPIO_MBGNT | GPIO_MBREQ;
TUCR |= TUCR_MBGPIO;
}
return ret;
}
static int __init nanoengine_pci_init(void)
{
if (machine_is_nanoengine())
pci_common_init(&nanoengine_pci);
return 0;
}
