static int fixed_bar_cap(struct pci_bus *bus, unsigned int devfn)
{
int pos;
u32 pcie_cap = 0, cap_data;
pos = PCIE_CAP_OFFSET;
if (!raw_pci_ext_ops)
return 0;
while (pos) {
if (raw_pci_ext_ops->read(pci_domain_nr(bus), bus->number,
devfn, pos, 4, &pcie_cap))
return 0;
if (PCI_EXT_CAP_ID(pcie_cap) == 0x0000 ||
PCI_EXT_CAP_ID(pcie_cap) == 0xffff)
break;
if (PCI_EXT_CAP_ID(pcie_cap) == PCI_EXT_CAP_ID_VNDR) {
raw_pci_ext_ops->read(pci_domain_nr(bus), bus->number,
devfn, pos + 4, 4, &cap_data);
if ((cap_data & 0xffff) == PCIE_VNDR_CAP_ID_FIXED_BAR)
return pos;
}
pos = PCI_EXT_CAP_NEXT(pcie_cap);
}
return 0;
}
static int pci_device_update_fixed(struct pci_bus *bus, unsigned int devfn,
int reg, int len, u32 val, int offset)
{
u32 size;
unsigned int domain, busnum;
int bar = (reg - PCI_BASE_ADDRESS_0) >> 2;
domain = pci_domain_nr(bus);
busnum = bus->number;
if (val == ~0 && len == 4) {
unsigned long decode;
raw_pci_ext_ops->read(domain, busnum, devfn,
offset + 8 + (bar * 4), 4, &size);
if (size) {
decode = size - 1;
decode |= decode >> 1;
decode |= decode >> 2;
decode |= decode >> 4;
decode |= decode >> 8;
decode |= decode >> 16;
decode++;
decode = ~(decode - 1);
} else {
decode = 0;
}
return raw_pci_ext_ops->write(domain, busnum, devfn, reg, 4,
decode);
}
return raw_pci_ext_ops->write(domain, busnum, devfn, reg, len, val);
}
static bool type1_access_ok(unsigned int bus, unsigned int devfn, int reg)
{
if (reg >= 0x100 || reg == PCI_STATUS || reg == PCI_HEADER_TYPE)
return false;
if (bus == 0 && (devfn == PCI_DEVFN(2, 0)
|| devfn == PCI_DEVFN(0, 0)
|| devfn == PCI_DEVFN(3, 0)))
return true;
return false;
}
static int pci_read(struct pci_bus *bus, unsigned int devfn, int where,
int size, u32 *value)
{
if (type1_access_ok(bus->number, devfn, where))
return pci_direct_conf1.read(pci_domain_nr(bus), bus->number,
devfn, where, size, value);
return raw_pci_ext_ops->read(pci_domain_nr(bus), bus->number,
devfn, where, size, value);
}
static int pci_write(struct pci_bus *bus, unsigned int devfn, int where,
int size, u32 value)
{
int offset;
if (where == PCI_ROM_ADDRESS)
return 0;
offset = fixed_bar_cap(bus, devfn);
if (offset &&
(where >= PCI_BASE_ADDRESS_0 && where <= PCI_BASE_ADDRESS_5)) {
return pci_device_update_fixed(bus, devfn, where, size, value,
offset);
}
if (type1_access_ok(bus->number, devfn, where))
return pci_direct_conf1.write(pci_domain_nr(bus), bus->number,
devfn, where, size, value);
return raw_pci_ext_ops->write(pci_domain_nr(bus), bus->number, devfn,
where, size, value);
}
static int intel_mid_pci_irq_enable(struct pci_dev *dev)
{
struct irq_alloc_info info;
int polarity;
int ret;
u8 gsi;
if (dev->irq_managed && dev->irq > 0)
return 0;
ret = pci_read_config_byte(dev, PCI_INTERRUPT_LINE, &gsi);
if (ret < 0) {
dev_warn(&dev->dev, "Failed to read interrupt line: %d\n", ret);
return ret;
}
switch (intel_mid_identify_cpu()) {
case INTEL_MID_CPU_CHIP_TANGIER:
polarity = IOAPIC_POL_HIGH;
if (gsi == 0) {
if (dev->device == PCI_DEVICE_ID_INTEL_MRFLD_HSU)
return -EBUSY;
if (dev->device != PCI_DEVICE_ID_INTEL_MRFLD_MMC)
return 0;
}
break;
default:
polarity = IOAPIC_POL_LOW;
break;
}
ioapic_set_alloc_attr(&info, dev_to_node(&dev->dev), 1, polarity);
ret = mp_map_gsi_to_irq(gsi, IOAPIC_MAP_ALLOC, &info);
if (ret < 0)
return ret;
dev->irq = ret;
dev->irq_managed = 1;
return 0;
}
static void intel_mid_pci_irq_disable(struct pci_dev *dev)
{
if (!mp_should_keep_irq(&dev->dev) && dev->irq_managed &&
dev->irq > 0) {
mp_unmap_irq(dev->irq);
dev->irq_managed = 0;
}
}
int __init intel_mid_pci_init(void)
{
pr_info("Intel MID platform detected, using MID PCI ops\n");
pci_mmcfg_late_init();
pcibios_enable_irq = intel_mid_pci_irq_enable;
pcibios_disable_irq = intel_mid_pci_irq_disable;
pci_root_ops = intel_mid_pci_ops;
pci_soc_mode = 1;
return 1;
}
static void pci_d3delay_fixup(struct pci_dev *dev)
{
if (!pci_soc_mode)
return;
if (type1_access_ok(dev->bus->number, dev->devfn, PCI_DEVICE_ID))
return;
dev->d3_delay = 0;
}
static void mid_power_off_one_device(struct pci_dev *dev)
{
u16 pmcsr;
pci_read_config_word(dev, dev->pm_cap + PCI_PM_CTRL, &pmcsr);
dev->current_state = (pci_power_t __force)(pmcsr & PCI_PM_CTRL_STATE_MASK);
pci_set_power_state(dev, PCI_D3hot);
}
static void mid_power_off_devices(struct pci_dev *dev)
{
int id;
if (!pci_soc_mode)
return;
id = intel_mid_pwr_get_lss_id(dev);
if (id < 0)
return;
mid_power_off_one_device(dev);
}
static void pci_fixed_bar_fixup(struct pci_dev *dev)
{
unsigned long offset;
u32 size;
int i;
if (!pci_soc_mode)
return;
if (dev->cfg_size < PCIE_CAP_OFFSET + 4)
return;
offset = fixed_bar_cap(dev->bus, dev->devfn);
if (!offset || PCI_DEVFN(2, 0) == dev->devfn ||
PCI_DEVFN(2, 2) == dev->devfn)
return;
for (i = 0; i < PCI_ROM_RESOURCE; i++) {
pci_read_config_dword(dev, offset + 8 + (i * 4), &size);
dev->resource[i].end = dev->resource[i].start + size - 1;
dev->resource[i].flags |= IORESOURCE_PCI_FIXED;
}
}
