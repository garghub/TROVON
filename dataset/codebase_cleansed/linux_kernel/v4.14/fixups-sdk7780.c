int pcibios_map_platform_irq(const struct pci_dev *pdev, u8 slot, u8 pin)
{
return sdk7780_irq_tab[pin-1][slot];
}
