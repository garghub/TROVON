int pcibios_plat_dev_init(struct pci_dev *dev)
{
return PCIBIOS_SUCCESSFUL;
}
int pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
#if !defined(CONFIG_PMC_MSP7120_GW) && !defined(CONFIG_PMC_MSP7120_EVAL)
printk(KERN_WARNING "PCI: unknown board, no PCI IRQs assigned.\n");
#endif
printk(KERN_WARNING "PCI: irq_tab returned %d for slot=%d pin=%d\n",
irq_tab[slot][pin], slot, pin);
return irq_tab[slot][pin];
}
