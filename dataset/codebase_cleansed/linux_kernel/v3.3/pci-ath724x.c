static int ath724x_pci_read(struct pci_bus *bus, unsigned int devfn, int where,
int size, uint32_t *value)
{
unsigned long flags, addr, tval, mask;
if (devfn)
return PCIBIOS_DEVICE_NOT_FOUND;
if (where & (size - 1))
return PCIBIOS_BAD_REGISTER_NUMBER;
spin_lock_irqsave(&ath724x_pci_lock, flags);
switch (size) {
case 1:
addr = where & ~3;
mask = 0xff000000 >> ((where % 4) * 8);
tval = reg_read(ATH724X_PCI_DEV_BASE + addr);
tval = tval & ~mask;
*value = (tval >> ((4 - (where % 4))*8));
break;
case 2:
addr = where & ~3;
mask = 0xffff0000 >> ((where % 4)*8);
tval = reg_read(ATH724X_PCI_DEV_BASE + addr);
tval = tval & ~mask;
*value = (tval >> ((4 - (where % 4))*8));
break;
case 4:
*value = reg_read(ATH724X_PCI_DEV_BASE + where);
break;
default:
spin_unlock_irqrestore(&ath724x_pci_lock, flags);
return PCIBIOS_BAD_REGISTER_NUMBER;
}
spin_unlock_irqrestore(&ath724x_pci_lock, flags);
return PCIBIOS_SUCCESSFUL;
}
static int ath724x_pci_write(struct pci_bus *bus, unsigned int devfn, int where,
int size, uint32_t value)
{
unsigned long flags, tval, addr, mask;
if (devfn)
return PCIBIOS_DEVICE_NOT_FOUND;
if (where & (size - 1))
return PCIBIOS_BAD_REGISTER_NUMBER;
spin_lock_irqsave(&ath724x_pci_lock, flags);
switch (size) {
case 1:
addr = (ATH724X_PCI_DEV_BASE + where) & ~3;
mask = 0xff000000 >> ((where % 4)*8);
tval = reg_read(addr);
tval = tval & ~mask;
tval |= (value << ((4 - (where % 4))*8)) & mask;
reg_write(addr, tval);
break;
case 2:
addr = (ATH724X_PCI_DEV_BASE + where) & ~3;
mask = 0xffff0000 >> ((where % 4)*8);
tval = reg_read(addr);
tval = tval & ~mask;
tval |= (value << ((4 - (where % 4))*8)) & mask;
reg_write(addr, tval);
break;
case 4:
reg_write((ATH724X_PCI_DEV_BASE + where), value);
break;
default:
spin_unlock_irqrestore(&ath724x_pci_lock, flags);
return PCIBIOS_BAD_REGISTER_NUMBER;
}
spin_unlock_irqrestore(&ath724x_pci_lock, flags);
return PCIBIOS_SUCCESSFUL;
}
void ath724x_pci_add_data(struct ath724x_pci_data *data, int size)
{
pci_data = data;
pci_data_size = size;
}
int __init pcibios_map_irq(const struct pci_dev *dev, uint8_t slot, uint8_t pin)
{
unsigned int devfn = dev->devfn;
int irq = -1;
if (devfn > pci_data_size - 1)
return irq;
irq = pci_data[devfn].irq;
return irq;
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
unsigned int devfn = dev->devfn;
if (devfn > pci_data_size - 1)
return PCIBIOS_DEVICE_NOT_FOUND;
dev->dev.platform_data = pci_data[devfn].pdata;
return PCIBIOS_SUCCESSFUL;
}
static int __init ath724x_pcibios_init(void)
{
register_pci_controller(&ath724x_pci_controller);
return PCIBIOS_SUCCESSFUL;
}
