int __init pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
if (slot == 30)
return internal_func_irqs[PCI_FUNC(dev->devfn)];
return irq_tab_mpc30x[slot];
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
