int __init pcibios_map_platform_irq(const struct pci_dev *pdev, u8 slot, u8 pin)
{
int irq = titan_irq_tab[slot];
printk("PCI: Mapping TITAN IRQ for slot %d, pin %c to irq %d\n",
slot, pin - 1 + 'A', irq);
return irq;
}
