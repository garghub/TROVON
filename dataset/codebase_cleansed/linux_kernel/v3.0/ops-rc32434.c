static inline int config_access(unsigned char access_type,
struct pci_bus *bus, unsigned int devfn,
unsigned char where, u32 *data)
{
unsigned int slot = PCI_SLOT(devfn);
u8 func = PCI_FUNC(devfn);
PCI_CFG_SET(bus->number, slot, func, where);
rc32434_sync();
if (access_type == PCI_ACCESS_WRITE)
rc32434_pci->pcicfgd = *data;
else
*data = rc32434_pci->pcicfgd;
rc32434_sync();
return 0;
}
static int read_config_byte(struct pci_bus *bus, unsigned int devfn,
int where, u8 *val)
{
u32 data;
int ret;
ret = config_access(PCI_ACCESS_READ, bus, devfn, where, &data);
*val = (data >> ((where & 3) << 3)) & 0xff;
return ret;
}
static int read_config_word(struct pci_bus *bus, unsigned int devfn,
int where, u16 *val)
{
u32 data;
int ret;
ret = config_access(PCI_ACCESS_READ, bus, devfn, where, &data);
*val = (data >> ((where & 3) << 3)) & 0xffff;
return ret;
}
static int read_config_dword(struct pci_bus *bus, unsigned int devfn,
int where, u32 *val)
{
int ret;
int delay = 1;
if (bus->number == 0 && PCI_SLOT(devfn) > 21)
return 0;
retry:
ret = config_access(PCI_ACCESS_READ, bus, devfn, where, val);
if (where == PCI_VENDOR_ID) {
if (ret == 0xffffffff || ret == 0x00000000 ||
ret == 0x0000ffff || ret == 0xffff0000) {
if (delay > 4)
return 0;
delay *= 2;
msleep(delay);
goto retry;
}
}
return ret;
}
static int
write_config_byte(struct pci_bus *bus, unsigned int devfn, int where,
u8 val)
{
u32 data = 0;
if (config_access(PCI_ACCESS_READ, bus, devfn, where, &data))
return -1;
data = (data & ~(0xff << ((where & 3) << 3))) |
(val << ((where & 3) << 3));
if (config_access(PCI_ACCESS_WRITE, bus, devfn, where, &data))
return -1;
return PCIBIOS_SUCCESSFUL;
}
static int
write_config_word(struct pci_bus *bus, unsigned int devfn, int where,
u16 val)
{
u32 data = 0;
if (config_access(PCI_ACCESS_READ, bus, devfn, where, &data))
return -1;
data = (data & ~(0xffff << ((where & 3) << 3))) |
(val << ((where & 3) << 3));
if (config_access(PCI_ACCESS_WRITE, bus, devfn, where, &data))
return -1;
return PCIBIOS_SUCCESSFUL;
}
static int
write_config_dword(struct pci_bus *bus, unsigned int devfn, int where,
u32 val)
{
if (config_access(PCI_ACCESS_WRITE, bus, devfn, where, &val))
return -1;
return PCIBIOS_SUCCESSFUL;
}
static int pci_config_read(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
switch (size) {
case 1:
return read_config_byte(bus, devfn, where, (u8 *) val);
case 2:
return read_config_word(bus, devfn, where, (u16 *) val);
default:
return read_config_dword(bus, devfn, where, val);
}
}
static int pci_config_write(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
switch (size) {
case 1:
return write_config_byte(bus, devfn, where, (u8) val);
case 2:
return write_config_word(bus, devfn, where, (u16) val);
default:
return write_config_dword(bus, devfn, where, val);
}
}
