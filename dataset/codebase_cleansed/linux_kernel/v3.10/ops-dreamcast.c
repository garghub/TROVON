static int gapspci_config_access(unsigned char bus, unsigned int devfn)
{
return (bus == 0) && (devfn == 0);
}
static int gapspci_read(struct pci_bus *bus, unsigned int devfn, int where, int size, u32 *val)
{
*val = 0xffffffff;
if (!gapspci_config_access(bus->number, devfn))
return PCIBIOS_DEVICE_NOT_FOUND;
switch (size) {
case 1: *val = inb(GAPSPCI_BBA_CONFIG+where); break;
case 2: *val = inw(GAPSPCI_BBA_CONFIG+where); break;
case 4: *val = inl(GAPSPCI_BBA_CONFIG+where); break;
}
return PCIBIOS_SUCCESSFUL;
}
static int gapspci_write(struct pci_bus *bus, unsigned int devfn, int where, int size, u32 val)
{
if (!gapspci_config_access(bus->number, devfn))
return PCIBIOS_DEVICE_NOT_FOUND;
switch (size) {
case 1: outb(( u8)val, GAPSPCI_BBA_CONFIG+where); break;
case 2: outw((u16)val, GAPSPCI_BBA_CONFIG+where); break;
case 4: outl((u32)val, GAPSPCI_BBA_CONFIG+where); break;
}
return PCIBIOS_SUCCESSFUL;
}
