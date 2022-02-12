int __init pcibios_map_platform_irq(struct pci_dev *pdev, u8 slot, u8 pin)
{
return irq_tab[slot];
}
