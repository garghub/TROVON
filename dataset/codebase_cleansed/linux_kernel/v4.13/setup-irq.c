void __weak pcibios_update_irq(struct pci_dev *dev, int irq)
{
dev_dbg(&dev->dev, "assigning IRQ %02d\n", irq);
pci_write_config_byte(dev, PCI_INTERRUPT_LINE, irq);
}
void pci_assign_irq(struct pci_dev *dev)
{
u8 pin;
u8 slot = -1;
int irq = 0;
struct pci_host_bridge *hbrg = pci_find_host_bridge(dev->bus);
if (!(hbrg->map_irq)) {
dev_dbg(&dev->dev, "runtime IRQ mapping not provided by arch\n");
return;
}
pci_read_config_byte(dev, PCI_INTERRUPT_PIN, &pin);
if (pin > 4)
pin = 1;
if (pin) {
if (hbrg->swizzle_irq)
slot = (*(hbrg->swizzle_irq))(dev, &pin);
irq = (*(hbrg->map_irq))(dev, slot, pin);
if (irq == -1)
irq = 0;
}
dev->irq = irq;
dev_dbg(&dev->dev, "assign IRQ: got %d\n", dev->irq);
pcibios_update_irq(dev, irq);
}
void pci_fixup_irqs(u8 (*swizzle)(struct pci_dev *, u8 *),
int (*map_irq)(const struct pci_dev *, u8, u8))
{
struct pci_dev *dev = NULL;
struct pci_host_bridge *hbrg = NULL;
for_each_pci_dev(dev) {
hbrg = pci_find_host_bridge(dev->bus);
hbrg->swizzle_irq = swizzle;
hbrg->map_irq = map_irq;
pci_assign_irq(dev);
hbrg->swizzle_irq = NULL;
hbrg->map_irq = NULL;
}
}
