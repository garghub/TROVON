static int sh5pci_read(struct pci_bus *bus, unsigned int devfn, int where,
int size, u32 *val)
{
SH5PCI_WRITE(PAR, CONFIG_CMD(bus, devfn, where));
switch (size) {
case 1:
*val = (u8)SH5PCI_READ_BYTE(PDR + (where & 3));
break;
case 2:
*val = (u16)SH5PCI_READ_SHORT(PDR + (where & 2));
break;
case 4:
*val = SH5PCI_READ(PDR);
break;
}
return PCIBIOS_SUCCESSFUL;
}
static int sh5pci_write(struct pci_bus *bus, unsigned int devfn, int where,
int size, u32 val)
{
SH5PCI_WRITE(PAR, CONFIG_CMD(bus, devfn, where));
switch (size) {
case 1:
SH5PCI_WRITE_BYTE(PDR + (where & 3), (u8)val);
break;
case 2:
SH5PCI_WRITE_SHORT(PDR + (where & 2), (u16)val);
break;
case 4:
SH5PCI_WRITE(PDR, val);
break;
}
return PCIBIOS_SUCCESSFUL;
}
