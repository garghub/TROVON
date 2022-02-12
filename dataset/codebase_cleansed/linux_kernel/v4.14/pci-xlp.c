static inline u32 pci_cfg_read_32bit(struct pci_bus *bus, unsigned int devfn,
int where)
{
u32 data;
u32 *cfgaddr;
where &= ~3;
if (cpu_is_xlp9xx()) {
if (bus->number == 0) {
if (PCI_SLOT(devfn) != 0 ||
!nlm_node_present(PCI_FUNC(devfn)))
return 0xffffffff;
} else if (bus->parent->number == 0) {
if (PCI_SLOT(devfn) == 0)
return 0xffffffff;
if (devfn == 44)
return 0xffffffff;
}
} else if (bus->number == 0 && PCI_SLOT(devfn) == 1 && where == 0x954) {
return 0xffffffff;
}
cfgaddr = (u32 *)(pci_config_base +
pci_cfg_addr(bus->number, devfn, where));
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
struct pci_dev *xlp_get_pcie_link(const struct pci_dev *dev)
{
struct pci_bus *bus, *p;
bus = dev->bus;
if (cpu_is_xlp9xx()) {
for (p = bus->parent; p && p->parent && p->parent->number != 0;
p = p->parent)
bus = p;
return (p && p->parent) ? bus->self : NULL;
} else {
for (p = bus->parent; p && p->number != 0; p = p->parent)
bus = p;
return p ? bus->self : NULL;
}
}
int xlp_socdev_to_node(const struct pci_dev *lnkdev)
{
if (cpu_is_xlp9xx())
return PCI_FUNC(lnkdev->bus->self->devfn);
else
return PCI_SLOT(lnkdev->devfn) / 8;
}
int pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
struct pci_dev *lnkdev;
int lnkfunc, node;
lnkdev = xlp_get_pcie_link(dev);
if (lnkdev == NULL)
return 0;
lnkfunc = PCI_FUNC(lnkdev->devfn);
node = xlp_socdev_to_node(lnkdev);
return nlm_irq_to_xirq(node, PIC_PCIE_LINK_LEGACY_IRQ(lnkfunc));
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
static void xlp_config_pci_bswap(int node, int link)
{
uint64_t nbubase, lnkbase;
u32 reg;
nbubase = nlm_get_bridge_regbase(node);
lnkbase = nlm_get_pcie_base(node, link);
if (cpu_is_xlp9xx()) {
reg = nlm_read_bridge_reg(nbubase,
BRIDGE_9XX_PCIEMEM_BASE0 + link);
nlm_write_pci_reg(lnkbase, PCIE_9XX_BYTE_SWAP_MEM_BASE, reg);
reg = nlm_read_bridge_reg(nbubase,
BRIDGE_9XX_PCIEMEM_LIMIT0 + link);
nlm_write_pci_reg(lnkbase,
PCIE_9XX_BYTE_SWAP_MEM_LIM, reg | 0xfff);
reg = nlm_read_bridge_reg(nbubase,
BRIDGE_9XX_PCIEIO_BASE0 + link);
nlm_write_pci_reg(lnkbase, PCIE_9XX_BYTE_SWAP_IO_BASE, reg);
reg = nlm_read_bridge_reg(nbubase,
BRIDGE_9XX_PCIEIO_LIMIT0 + link);
nlm_write_pci_reg(lnkbase,
PCIE_9XX_BYTE_SWAP_IO_LIM, reg | 0xfff);
} else {
reg = nlm_read_bridge_reg(nbubase, BRIDGE_PCIEMEM_BASE0 + link);
nlm_write_pci_reg(lnkbase, PCIE_BYTE_SWAP_MEM_BASE, reg);
reg = nlm_read_bridge_reg(nbubase,
BRIDGE_PCIEMEM_LIMIT0 + link);
nlm_write_pci_reg(lnkbase, PCIE_BYTE_SWAP_MEM_LIM, reg | 0xfff);
reg = nlm_read_bridge_reg(nbubase, BRIDGE_PCIEIO_BASE0 + link);
nlm_write_pci_reg(lnkbase, PCIE_BYTE_SWAP_IO_BASE, reg);
reg = nlm_read_bridge_reg(nbubase, BRIDGE_PCIEIO_LIMIT0 + link);
nlm_write_pci_reg(lnkbase, PCIE_BYTE_SWAP_IO_LIM, reg | 0xfff);
}
}
static inline void xlp_config_pci_bswap(int node, int link) {}
static int __init pcibios_init(void)
{
uint64_t pciebase;
int link, n;
u32 reg;
pci_set_flags(PCI_PROBE_ONLY);
pci_config_base = ioremap(XLP_DEFAULT_PCI_ECFG_BASE, 64 << 20);
ioport_resource.start = 0;
ioport_resource.end = ~0;
for (n = 0; n < NLM_NR_NODES; n++) {
if (!nlm_node_present(n))
continue;
for (link = 0; link < PCIE_NLINKS; link++) {
pciebase = nlm_get_pcie_base(n, link);
if (nlm_read_pci_reg(pciebase, 0) == 0xffffffff)
continue;
xlp_config_pci_bswap(n, link);
xlp_init_node_msi_irqs(n, link);
reg = nlm_read_pci_reg(pciebase, 0xf);
reg &= ~0x1ffu;
reg |= (1 << 8) | PIC_PCIE_LINK_LEGACY_IRQ(link);
nlm_write_pci_reg(pciebase, 0xf, reg);
pr_info("XLP PCIe: Link %d-%d initialized.\n", n, link);
}
}
set_io_port_base(CKSEG1);
nlm_pci_controller.io_map_base = CKSEG1;
register_pci_controller(&nlm_pci_controller);
pr_info("XLP PCIe Controller %pR%pR.\n", &nlm_pci_io_resource,
&nlm_pci_mem_resource);
return 0;
}
