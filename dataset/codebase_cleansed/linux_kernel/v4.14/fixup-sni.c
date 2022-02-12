static inline int is_rm300_revd(void)
{
unsigned char csmsr = *(volatile unsigned char *)PCIMT_CSMSR;
return (csmsr & 0xa0) == 0x20;
}
int pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
switch (sni_brd_type) {
case SNI_BRD_PCI_TOWER_CPLUS:
if (slot == 4) {
while (dev && dev->bus->number != 1)
dev = dev->bus->self;
if (dev && dev->devfn >= PCI_DEVFN(4, 0))
slot = 5;
}
return irq_tab_pcit_cplus[slot][pin];
case SNI_BRD_PCI_TOWER:
return irq_tab_pcit[slot][pin];
case SNI_BRD_PCI_MTOWER:
if (is_rm300_revd())
return irq_tab_rm300d[slot][pin];
case SNI_BRD_PCI_DESKTOP:
return irq_tab_rm200[slot][pin];
case SNI_BRD_PCI_MTOWER_CPLUS:
return irq_tab_rm300e[slot][pin];
}
return 0;
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
