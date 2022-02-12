void __weak pcibios_update_irq(struct pci_dev *dev, int irq)
{
dev_dbg(&dev->dev, "assigning IRQ %02d\n", irq);
pci_write_config_byte(dev, PCI_INTERRUPT_LINE, irq);
}
static void pdev_fixup_irq(struct pci_dev *dev,
u8 (*swizzle)(struct pci_dev *, u8 *),
int (*map_irq)(const struct pci_dev *, u8, u8))
{
u8 pin, slot;
int irq = 0;
pci_read_config_byte(dev, PCI_INTERRUPT_PIN, &pin);
if (pin > 4)
pin = 1;
if (pin != 0) {
slot = (*swizzle)(dev, &pin);
irq = (*map_irq)(dev, slot, pin);
if (irq == -1)
irq = 0;
}
dev->irq = irq;
dev_dbg(&dev->dev, "fixup irq: got %d\n", dev->irq);
pcibios_update_irq(dev, irq);
}
void pci_fixup_irqs(u8 (*swizzle)(struct pci_dev *, u8 *),
int (*map_irq)(const struct pci_dev *, u8, u8))
{
struct pci_dev *dev = NULL;
for_each_pci_dev(dev)
pdev_fixup_irq(dev, swizzle, map_irq);
}
