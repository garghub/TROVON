static int sh4_pci_read(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
struct pci_channel *chan = bus->sysdata;
unsigned long flags;
u32 data;
raw_spin_lock_irqsave(&pci_config_lock, flags);
pci_write_reg(chan, CONFIG_CMD(bus, devfn, where), SH4_PCIPAR);
data = pci_read_reg(chan, SH4_PCIPDR);
raw_spin_unlock_irqrestore(&pci_config_lock, flags);
switch (size) {
case 1:
*val = (data >> ((where & 3) << 3)) & 0xff;
break;
case 2:
*val = (data >> ((where & 2) << 3)) & 0xffff;
break;
case 4:
*val = data;
break;
default:
return PCIBIOS_FUNC_NOT_SUPPORTED;
}
return PCIBIOS_SUCCESSFUL;
}
static int sh4_pci_write(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
struct pci_channel *chan = bus->sysdata;
unsigned long flags;
int shift;
u32 data;
raw_spin_lock_irqsave(&pci_config_lock, flags);
pci_write_reg(chan, CONFIG_CMD(bus, devfn, where), SH4_PCIPAR);
data = pci_read_reg(chan, SH4_PCIPDR);
raw_spin_unlock_irqrestore(&pci_config_lock, flags);
switch (size) {
case 1:
shift = (where & 3) << 3;
data &= ~(0xff << shift);
data |= ((val & 0xff) << shift);
break;
case 2:
shift = (where & 2) << 3;
data &= ~(0xffff << shift);
data |= ((val & 0xffff) << shift);
break;
case 4:
data = val;
break;
default:
return PCIBIOS_FUNC_NOT_SUPPORTED;
}
pci_write_reg(chan, data, SH4_PCIPDR);
return PCIBIOS_SUCCESSFUL;
}
