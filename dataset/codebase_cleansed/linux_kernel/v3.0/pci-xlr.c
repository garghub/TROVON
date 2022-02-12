static inline u32 pci_cfg_read_32bit(struct pci_bus *bus, unsigned int devfn,
int where)
{
u32 data;
u32 *cfgaddr;
cfgaddr = (u32 *)(pci_config_base +
pci_cfg_addr(bus->number, devfn, where & ~3));
data = *cfgaddr;
return cpu_to_le32(data);
}
static inline void pci_cfg_write_32bit(struct pci_bus *bus, unsigned int devfn,
int where, u32 data)
{
u32 *cfgaddr;
cfgaddr = (u32 *)(pci_config_base +
pci_cfg_addr(bus->number, devfn, where & ~3));
*cfgaddr = cpu_to_le32(data);
}
static int nlm_pcibios_read(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
u32 data;
if ((size == 2) && (where & 1))
return PCIBIOS_BAD_REGISTER_NUMBER;
else if ((size == 4) && (where & 3))
return PCIBIOS_BAD_REGISTER_NUMBER;
data = pci_cfg_read_32bit(bus, devfn, where);
if (size == 1)
*val = (data >> ((where & 3) << 3)) & 0xff;
else if (size == 2)
*val = (data >> ((where & 3) << 3)) & 0xffff;
else
*val = data;
return PCIBIOS_SUCCESSFUL;
}
static int nlm_pcibios_write(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
u32 data;
if ((size == 2) && (where & 1))
return PCIBIOS_BAD_REGISTER_NUMBER;
else if ((size == 4) && (where & 3))
return PCIBIOS_BAD_REGISTER_NUMBER;
data = pci_cfg_read_32bit(bus, devfn, where);
if (size == 1)
data = (data & ~(0xff << ((where & 3) << 3))) |
(val << ((where & 3) << 3));
else if (size == 2)
data = (data & ~(0xffff << ((where & 3) << 3))) |
(val << ((where & 3) << 3));
else
data = val;
pci_cfg_write_32bit(bus, devfn, where, data);
return PCIBIOS_SUCCESSFUL;
}
int __init pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
if (!nlm_chip_is_xls())
return PIC_PCIX_IRQ;
if (dev->bus->self == NULL)
return 0;
switch (dev->bus->self->devfn) {
case 0x0:
return PIC_PCIE_LINK0_IRQ;
case 0x8:
return PIC_PCIE_LINK1_IRQ;
case 0x10:
if (nlm_chip_is_xls_b())
return PIC_PCIE_XLSB0_LINK2_IRQ;
else
return PIC_PCIE_LINK2_IRQ;
case 0x18:
if (nlm_chip_is_xls_b())
return PIC_PCIE_XLSB0_LINK3_IRQ;
else
return PIC_PCIE_LINK3_IRQ;
}
WARN(1, "Unexpected devfn %d\n", dev->bus->self->devfn);
return 0;
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
static int __init pcibios_init(void)
{
pci_probe_only = 1;
pci_config_base = ioremap(DEFAULT_PCI_CONFIG_BASE, 16 << 20);
ioport_resource.start = 0;
ioport_resource.end = ~0;
set_io_port_base(CKSEG1);
nlm_pci_controller.io_map_base = CKSEG1;
pr_info("Registering XLR/XLS PCIX/PCIE Controller.\n");
register_pci_controller(&nlm_pci_controller);
return 0;
}
