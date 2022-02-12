static int titan_read_config(struct pci_bus *bus, unsigned int devfn, int reg,
int size, u32 * val)
{
uint32_t address, tmp;
int dev, busno, func;
busno = bus->number;
dev = PCI_SLOT(devfn);
func = PCI_FUNC(devfn);
address = (busno << 16) | (dev << 11) | (func << 8) |
(reg & 0xfc) | 0x80000000;
ocd_writel(address, TITAN_PCI_0_CONFIG_ADDRESS);
tmp = ocd_readl(TITAN_PCI_0_CONFIG_DATA) >> ((reg & 3) << 3);
switch (size) {
case 1:
tmp &= 0xff;
case 2:
tmp &= 0xffff;
}
*val = tmp;
return PCIBIOS_SUCCESSFUL;
}
static int titan_write_config(struct pci_bus *bus, unsigned int devfn, int reg,
int size, u32 val)
{
uint32_t address;
int dev, busno, func;
busno = bus->number;
dev = PCI_SLOT(devfn);
func = PCI_FUNC(devfn);
address = (busno << 16) | (dev << 11) | (func << 8) |
(reg & 0xfc) | 0x80000000;
ocd_writel(address, TITAN_PCI_0_CONFIG_ADDRESS);
switch (size) {
case 1:
ocd_writeb(val, TITAN_PCI_0_CONFIG_DATA + (~reg & 0x3));
break;
case 2:
ocd_writew(val, TITAN_PCI_0_CONFIG_DATA + (~reg & 0x2));
break;
case 4:
ocd_writel(val, TITAN_PCI_0_CONFIG_DATA);
break;
}
return PCIBIOS_SUCCESSFUL;
}
