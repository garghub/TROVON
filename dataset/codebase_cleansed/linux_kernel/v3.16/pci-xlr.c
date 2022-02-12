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
static struct pci_dev *xls_get_pcie_link(const struct pci_dev *dev)
{
struct pci_bus *bus, *p;
bus = dev->bus;
for (p = bus->parent; p && p->number != 0; p = p->parent)
bus = p;
return p ? bus->self : NULL;
}
static int nlm_pci_link_to_irq(int link)
{
switch (link) {
case 0:
return PIC_PCIE_LINK0_IRQ;
case 1:
return PIC_PCIE_LINK1_IRQ;
case 2:
if (nlm_chip_is_xls_b())
return PIC_PCIE_XLSB0_LINK2_IRQ;
else
return PIC_PCIE_LINK2_IRQ;
case 3:
if (nlm_chip_is_xls_b())
return PIC_PCIE_XLSB0_LINK3_IRQ;
else
return PIC_PCIE_LINK3_IRQ;
}
WARN(1, "Unexpected link %d\n", link);
return 0;
}
static int get_irq_vector(const struct pci_dev *dev)
{
struct pci_dev *lnk;
int link;
if (!nlm_chip_is_xls())
return PIC_PCIX_IRQ;
lnk = xls_get_pcie_link(dev);
if (lnk == NULL)
return 0;
link = PCI_SLOT(lnk->devfn);
return nlm_pci_link_to_irq(link);
}
void arch_teardown_msi_irq(unsigned int irq)
{
}
int arch_setup_msi_irq(struct pci_dev *dev, struct msi_desc *desc)
{
struct msi_msg msg;
struct pci_dev *lnk;
int irq, ret;
u16 val;
if (!nlm_chip_is_xls())
return 1;
lnk = xls_get_pcie_link(dev);
if (lnk == NULL)
return 1;
pci_read_config_word(lnk, 0x50 + PCI_MSI_FLAGS, &val);
if ((val & PCI_MSI_FLAGS_ENABLE) == 0) {
val |= PCI_MSI_FLAGS_ENABLE;
pci_write_config_word(lnk, 0x50 + PCI_MSI_FLAGS, val);
}
irq = get_irq_vector(dev);
if (irq <= 0)
return 1;
msg.address_hi = MSI_ADDR_BASE_HI;
msg.address_lo = MSI_ADDR_BASE_LO |
MSI_ADDR_DEST_MODE_PHYSICAL |
MSI_ADDR_REDIRECTION_CPU;
msg.data = MSI_DATA_TRIGGER_EDGE |
MSI_DATA_LEVEL_ASSERT |
MSI_DATA_DELIVERY_FIXED;
ret = irq_set_msi_desc(irq, desc);
if (ret < 0)
return ret;
write_msi_msg(irq, &msg);
return 0;
}
static void xlr_pci_ack(struct irq_data *d)
{
uint64_t pcibase = nlm_mmio_base(NETLOGIC_IO_PCIX_OFFSET);
nlm_read_reg(pcibase, (0x140 >> 2));
}
static void xls_pcie_ack(struct irq_data *d)
{
uint64_t pciebase_le = nlm_mmio_base(NETLOGIC_IO_PCIE_1_OFFSET);
switch (d->irq) {
case PIC_PCIE_LINK0_IRQ:
nlm_write_reg(pciebase_le, (0x90 >> 2), 0xffffffff);
break;
case PIC_PCIE_LINK1_IRQ:
nlm_write_reg(pciebase_le, (0x94 >> 2), 0xffffffff);
break;
case PIC_PCIE_LINK2_IRQ:
nlm_write_reg(pciebase_le, (0x190 >> 2), 0xffffffff);
break;
case PIC_PCIE_LINK3_IRQ:
nlm_write_reg(pciebase_le, (0x194 >> 2), 0xffffffff);
break;
}
}
static void xls_pcie_ack_b(struct irq_data *d)
{
uint64_t pciebase_le = nlm_mmio_base(NETLOGIC_IO_PCIE_1_OFFSET);
switch (d->irq) {
case PIC_PCIE_LINK0_IRQ:
nlm_write_reg(pciebase_le, (0x90 >> 2), 0xffffffff);
break;
case PIC_PCIE_LINK1_IRQ:
nlm_write_reg(pciebase_le, (0x94 >> 2), 0xffffffff);
break;
case PIC_PCIE_XLSB0_LINK2_IRQ:
nlm_write_reg(pciebase_le, (0x190 >> 2), 0xffffffff);
break;
case PIC_PCIE_XLSB0_LINK3_IRQ:
nlm_write_reg(pciebase_le, (0x194 >> 2), 0xffffffff);
break;
}
}
int __init pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
return get_irq_vector(dev);
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
static int __init pcibios_init(void)
{
void (*extra_ack)(struct irq_data *);
int link, irq;
pci_set_flags(PCI_PROBE_ONLY);
pci_config_base = ioremap(DEFAULT_PCI_CONFIG_BASE, 16 << 20);
ioport_resource.start = 0;
ioport_resource.end = ~0;
set_io_port_base(CKSEG1);
nlm_pci_controller.io_map_base = CKSEG1;
pr_info("Registering XLR/XLS PCIX/PCIE Controller.\n");
register_pci_controller(&nlm_pci_controller);
if (!nlm_chip_is_xls()) {
nlm_set_pic_extra_ack(0, PIC_PCIX_IRQ, xlr_pci_ack);
} else {
if (nlm_chip_is_xls_b())
extra_ack = xls_pcie_ack_b;
else
extra_ack = xls_pcie_ack;
for (link = 0; link < 4; link++) {
irq = nlm_pci_link_to_irq(link);
nlm_set_pic_extra_ack(0, irq, extra_ack);
}
}
return 0;
}
