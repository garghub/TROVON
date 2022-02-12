static void qube_raq_galileo_early_fixup(struct pci_dev *dev)
{
if (dev->devfn == PCI_DEVFN(0, 0) &&
(dev->class >> 8) == PCI_CLASS_MEMORY_OTHER) {
dev->class = (PCI_CLASS_BRIDGE_HOST << 8) | (dev->class & 0xff);
printk(KERN_INFO "Galileo: fixed bridge class\n");
}
}
static void qube_raq_via_bmIDE_fixup(struct pci_dev *dev)
{
unsigned short cfgword;
unsigned char lt;
pci_read_config_word(dev, PCI_COMMAND, &cfgword);
cfgword |= (PCI_COMMAND_FAST_BACK | PCI_COMMAND_MASTER);
pci_write_config_word(dev, PCI_COMMAND, cfgword);
pci_write_config_byte(dev, 0x40, 0xb);
pci_read_config_byte(dev, PCI_LATENCY_TIMER, &lt);
if (lt < 64)
pci_write_config_byte(dev, PCI_LATENCY_TIMER, 64);
pci_write_config_byte(dev, PCI_CACHE_LINE_SIZE, 8);
}
static void qube_raq_galileo_fixup(struct pci_dev *dev)
{
if (dev->devfn != PCI_DEVFN(0, 0))
return;
pci_write_config_byte(dev, PCI_LATENCY_TIMER, 64);
pci_write_config_byte(dev, PCI_CACHE_LINE_SIZE, 8);
printk(KERN_INFO "Galileo: revision %u\n", dev->revision);
#if 0
if (dev->revision >= 0x10) {
GT_WRITE(GT_PCI0_TOR_OFS, 0x4020);
} else if (dev->revision == 0x1 || dev->revision == 0x2)
#endif
{
signed int timeo;
timeo = GT_READ(GT_PCI0_TOR_OFS);
GT_WRITE(GT_PCI0_TOR_OFS,
(0xff << 16) |
(0xff << 8) |
0xff);
GT_WRITE(GT_INTRMASK_OFS, GT_INTR_RETRYCTR0_MSK | GT_READ(GT_INTRMASK_OFS));
}
}
static void qube_raq_via_board_id_fixup(struct pci_dev *dev)
{
u8 id;
int retval;
retval = pci_read_config_byte(dev, VIA_COBALT_BRD_ID_REG, &id);
if (retval) {
panic("Cannot read board ID");
return;
}
cobalt_board_id = VIA_COBALT_BRD_REG_to_ID(id);
printk(KERN_INFO "Cobalt board ID: %d\n", cobalt_board_id);
}
int __init pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
if (cobalt_board_id <= COBALT_BRD_ID_QUBE1)
return irq_tab_qube1[slot];
if (cobalt_board_id == COBALT_BRD_ID_RAQ2)
return irq_tab_raq2[slot];
return irq_tab_cobalt[slot];
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
