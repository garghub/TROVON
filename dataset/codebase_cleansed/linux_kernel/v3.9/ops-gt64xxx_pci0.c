static int gt64xxx_pci0_pcibios_config_access(unsigned char access_type,
struct pci_bus *bus, unsigned int devfn, int where, u32 * data)
{
unsigned char busnum = bus->number;
u32 intr;
if ((busnum == 0) && (devfn >= PCI_DEVFN(31, 0)))
return -1;
GT_WRITE(GT_INTRCAUSE_OFS, ~(GT_INTRCAUSE_MASABORT0_BIT |
GT_INTRCAUSE_TARABORT0_BIT));
GT_WRITE(GT_PCI0_CFGADDR_OFS,
(busnum << GT_PCI0_CFGADDR_BUSNUM_SHF) |
(devfn << GT_PCI0_CFGADDR_FUNCTNUM_SHF) |
((where / 4) << GT_PCI0_CFGADDR_REGNUM_SHF) |
GT_PCI0_CFGADDR_CONFIGEN_BIT);
if (access_type == PCI_ACCESS_WRITE) {
if (busnum == 0 && PCI_SLOT(devfn) == 0) {
GT_WRITE(GT_PCI0_CFGDATA_OFS, *data);
} else
__GT_WRITE(GT_PCI0_CFGDATA_OFS, *data);
} else {
if (busnum == 0 && PCI_SLOT(devfn) == 0) {
*data = GT_READ(GT_PCI0_CFGDATA_OFS);
} else
*data = __GT_READ(GT_PCI0_CFGDATA_OFS);
}
intr = GT_READ(GT_INTRCAUSE_OFS);
if (intr & (GT_INTRCAUSE_MASABORT0_BIT | GT_INTRCAUSE_TARABORT0_BIT)) {
GT_WRITE(GT_INTRCAUSE_OFS, ~(GT_INTRCAUSE_MASABORT0_BIT |
GT_INTRCAUSE_TARABORT0_BIT));
return -1;
}
return 0;
}
static int gt64xxx_pci0_pcibios_read(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 * val)
{
u32 data = 0;
if (gt64xxx_pci0_pcibios_config_access(PCI_ACCESS_READ, bus, devfn,
where, &data))
return PCIBIOS_DEVICE_NOT_FOUND;
if (size == 1)
*val = (data >> ((where & 3) << 3)) & 0xff;
else if (size == 2)
*val = (data >> ((where & 3) << 3)) & 0xffff;
else
*val = data;
return PCIBIOS_SUCCESSFUL;
}
static int gt64xxx_pci0_pcibios_write(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
u32 data = 0;
if (size == 4)
data = val;
else {
if (gt64xxx_pci0_pcibios_config_access(PCI_ACCESS_READ, bus,
devfn, where, &data))
return PCIBIOS_DEVICE_NOT_FOUND;
if (size == 1)
data = (data & ~(0xff << ((where & 3) << 3))) |
(val << ((where & 3) << 3));
else if (size == 2)
data = (data & ~(0xffff << ((where & 3) << 3))) |
(val << ((where & 3) << 3));
}
if (gt64xxx_pci0_pcibios_config_access(PCI_ACCESS_WRITE, bus, devfn,
where, &data))
return PCIBIOS_DEVICE_NOT_FOUND;
return PCIBIOS_SUCCESSFUL;
}
