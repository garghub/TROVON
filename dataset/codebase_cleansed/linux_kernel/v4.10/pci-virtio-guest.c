int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
int pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
return ((pin + slot) % 4)+ MIPS_IRQ_PCIA;
}
static void pci_virtio_guest_write_config_addr(struct pci_bus *bus,
unsigned int devfn, int reg)
{
union pci_config_address pca = { .w = 0 };
pca.register_number = reg;
pca.devfn_number = devfn;
pca.bus_number = bus->number;
pca.enable_bit = 1;
outl(pca.w, PCI_CONFIG_ADDRESS);
}
static int pci_virtio_guest_write_config(struct pci_bus *bus,
unsigned int devfn, int reg, int size, u32 val)
{
pci_virtio_guest_write_config_addr(bus, devfn, reg);
switch (size) {
case 1:
outb(val, PCI_CONFIG_DATA + (reg & 3));
break;
case 2:
outw(val, PCI_CONFIG_DATA + (reg & 2));
break;
case 4:
outl(val, PCI_CONFIG_DATA);
break;
}
return PCIBIOS_SUCCESSFUL;
}
static int pci_virtio_guest_read_config(struct pci_bus *bus, unsigned int devfn,
int reg, int size, u32 *val)
{
pci_virtio_guest_write_config_addr(bus, devfn, reg);
switch (size) {
case 1:
*val = inb(PCI_CONFIG_DATA + (reg & 3));
break;
case 2:
*val = inw(PCI_CONFIG_DATA + (reg & 2));
break;
case 4:
*val = inl(PCI_CONFIG_DATA);
break;
}
return PCIBIOS_SUCCESSFUL;
}
static int __init pci_virtio_guest_setup(void)
{
pr_err("pci_virtio_guest_setup\n");
pci_set_flags(PCI_PROBE_ONLY);
pci_virtio_guest_controller.io_map_base = mips_io_port_base;
register_pci_controller(&pci_virtio_guest_controller);
return 0;
}
