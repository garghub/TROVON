static int __init cats_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
if (dev->irq >= 255)
return -1;
if (dev->irq >= 128)
return dev->irq & 0x1f;
if (dev->irq >= 1 && dev->irq <= 4)
return irqmap_cats[dev->irq - 1];
if (dev->irq != 0)
printk("PCI: device %02x:%02x has unknown irq line %x\n",
dev->bus->number, dev->devfn, dev->irq);
return -1;
}
static int __init cats_pci_init(void)
{
if (machine_is_cats())
pci_common_init(&cats_pci);
return 0;
}
