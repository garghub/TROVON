void __iomem *__pci_ioport_map(struct pci_dev *dev,
unsigned long port, unsigned int nr)
{
struct pci_controller *ctrl = dev->bus->sysdata;
unsigned long base = ctrl->io_map_base;
if (unlikely(!ctrl->io_map_base)) {
struct pci_bus *bus = dev->bus;
char name[8];
while (bus->parent)
bus = bus->parent;
ctrl->io_map_base = base = mips_io_port_base;
sprintf(name, "%04x:%02x", pci_domain_nr(bus), bus->number);
printk(KERN_WARNING "io_map_base of root PCI bus %s unset. "
"Trying to continue but you better\nfix this issue or "
"report it to linux-mips@linux-mips.org or your "
"vendor.\n", name);
#ifdef CONFIG_PCI_DOMAINS
panic("To avoid data corruption io_map_base MUST be set with "
"multiple PCI domains.");
#endif
}
return (void __iomem *) (ctrl->io_map_base + port);
}
void pci_iounmap(struct pci_dev *dev, void __iomem * addr)
{
iounmap(addr);
}
