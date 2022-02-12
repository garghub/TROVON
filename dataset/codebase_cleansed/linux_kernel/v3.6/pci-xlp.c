static inline u32 pci_cfg_read_32bit(struct pci_bus *bus, unsigned int devfn,
int where)
{
u32 data;
u32 *cfgaddr;
cfgaddr = (u32 *)(pci_config_base +
pci_cfg_addr(bus->number, devfn, where & ~3));
data = *cfgaddr;
return data;
}
static inline void pci_cfg_write_32bit(struct pci_bus *bus, unsigned int devfn,
int where, u32 data)
{
u32 *cfgaddr;
cfgaddr = (u32 *)(pci_config_base +
pci_cfg_addr(bus->number, devfn, where & ~3));
*cfgaddr = data;
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
static int get_irq_vector(const struct pci_dev *dev)
{
if (dev->bus->self == NULL)
return 0;
switch (dev->bus->self->devfn) {
case 0x8:
return PIC_PCIE_LINK_0_IRQ;
case 0x9:
return PIC_PCIE_LINK_1_IRQ;
case 0xa:
return PIC_PCIE_LINK_2_IRQ;
case 0xb:
return PIC_PCIE_LINK_3_IRQ;
}
WARN(1, "Unexpected devfn %d\n", dev->bus->self->devfn);
return 0;
}
int __init pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
return get_irq_vector(dev);
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
static int xlp_enable_pci_bswap(void)
{
uint64_t pciebase, sysbase;
int node, i;
u32 reg;
node = 0;
sysbase = nlm_get_bridge_regbase(node);
for (i = 0; i < 4; i++) {
pciebase = nlm_pcicfg_base(XLP_IO_PCIE_OFFSET(node, i));
if (nlm_read_pci_reg(pciebase, 0) == 0xffffffff)
continue;
reg = nlm_read_bridge_reg(sysbase, BRIDGE_PCIEMEM_BASE0 + i);
nlm_write_pci_reg(pciebase, PCIE_BYTE_SWAP_MEM_BASE, reg);
reg = nlm_read_bridge_reg(sysbase, BRIDGE_PCIEMEM_LIMIT0 + i);
nlm_write_pci_reg(pciebase, PCIE_BYTE_SWAP_MEM_LIM,
reg | 0xfff);
reg = nlm_read_bridge_reg(sysbase, BRIDGE_PCIEIO_BASE0 + i);
nlm_write_pci_reg(pciebase, PCIE_BYTE_SWAP_IO_BASE, reg);
reg = nlm_read_bridge_reg(sysbase, BRIDGE_PCIEIO_LIMIT0 + i);
nlm_write_pci_reg(pciebase, PCIE_BYTE_SWAP_IO_LIM, reg | 0xfff);
}
return 0;
}
static int __init pcibios_init(void)
{
pci_set_flags(PCI_PROBE_ONLY);
pci_config_base = ioremap(XLP_DEFAULT_PCI_ECFG_BASE, 64 << 20);
ioport_resource.start = 0;
ioport_resource.end = ~0;
xlp_enable_pci_bswap();
set_io_port_base(CKSEG1);
nlm_pci_controller.io_map_base = CKSEG1;
register_pci_controller(&nlm_pci_controller);
pr_info("XLP PCIe Controller %pR%pR.\n", &nlm_pci_io_resource,
&nlm_pci_mem_resource);
return 0;
}
