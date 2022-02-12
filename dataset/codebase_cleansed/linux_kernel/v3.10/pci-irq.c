void __init pcibios_irq_init(void)
{
}
void __init pcibios_fixup_irqs(void)
{
struct pci_dev *dev = NULL;
uint8_t line, pin;
for_each_pci_dev(dev) {
pci_read_config_byte(dev, PCI_INTERRUPT_PIN, &pin);
if (pin) {
dev->irq = pci_bus0_irq_routing[PCI_SLOT(dev->devfn)][pin - 1];
pci_write_config_byte(dev, PCI_INTERRUPT_LINE, dev->irq);
}
pci_read_config_byte(dev, PCI_INTERRUPT_LINE, &line);
}
}
void __init pcibios_penalize_isa_irq(int irq)
{
}
void pcibios_enable_irq(struct pci_dev *dev)
{
pci_write_config_byte(dev, PCI_INTERRUPT_LINE, dev->irq);
}
