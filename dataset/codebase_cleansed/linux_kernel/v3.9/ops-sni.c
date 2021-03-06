static int set_config_address(unsigned int busno, unsigned int devfn, int reg)
{
if ((devfn > 255) || (reg > 255))
return PCIBIOS_BAD_REGISTER_NUMBER;
if (busno == 0 && devfn >= PCI_DEVFN(8, 0))
return PCIBIOS_DEVICE_NOT_FOUND;
*(volatile u32 *)PCIMT_CONFIG_ADDRESS =
((busno & 0xff) << 16) |
((devfn & 0xff) << 8) |
(reg & 0xfc);
return PCIBIOS_SUCCESSFUL;
}
static int pcimt_read(struct pci_bus *bus, unsigned int devfn, int reg,
int size, u32 * val)
{
int res;
if ((res = set_config_address(bus->number, devfn, reg)))
return res;
switch (size) {
case 1:
*val = inb(PCIMT_CONFIG_DATA + (reg & 3));
break;
case 2:
*val = inw(PCIMT_CONFIG_DATA + (reg & 2));
break;
case 4:
*val = inl(PCIMT_CONFIG_DATA);
break;
}
return 0;
}
static int pcimt_write(struct pci_bus *bus, unsigned int devfn, int reg,
int size, u32 val)
{
int res;
if ((res = set_config_address(bus->number, devfn, reg)))
return res;
switch (size) {
case 1:
outb(val, PCIMT_CONFIG_DATA + (reg & 3));
break;
case 2:
outw(val, PCIMT_CONFIG_DATA + (reg & 2));
break;
case 4:
outl(val, PCIMT_CONFIG_DATA);
break;
}
return 0;
}
static int pcit_set_config_address(unsigned int busno, unsigned int devfn, int reg)
{
if ((devfn > 255) || (reg > 255) || (busno > 255))
return PCIBIOS_BAD_REGISTER_NUMBER;
outl((1 << 31) | ((busno & 0xff) << 16) | ((devfn & 0xff) << 8) | (reg & 0xfc), 0xcf8);
return PCIBIOS_SUCCESSFUL;
}
static int pcit_read(struct pci_bus *bus, unsigned int devfn, int reg,
int size, u32 * val)
{
int res;
if (bus->number == 0) {
pcit_set_config_address(0, 0, 0x68);
outl(inl(0xcfc) | 0xc0000000, 0xcfc);
if ((res = pcit_set_config_address(0, devfn, 0)))
return res;
outl(0xffffffff, 0xcfc);
pcit_set_config_address(0, 0, 0x68);
if (inl(0xcfc) & 0x100000)
return PCIBIOS_DEVICE_NOT_FOUND;
}
if ((res = pcit_set_config_address(bus->number, devfn, reg)))
return res;
switch (size) {
case 1:
*val = inb(PCIMT_CONFIG_DATA + (reg & 3));
break;
case 2:
*val = inw(PCIMT_CONFIG_DATA + (reg & 2));
break;
case 4:
*val = inl(PCIMT_CONFIG_DATA);
break;
}
return 0;
}
static int pcit_write(struct pci_bus *bus, unsigned int devfn, int reg,
int size, u32 val)
{
int res;
if ((res = pcit_set_config_address(bus->number, devfn, reg)))
return res;
switch (size) {
case 1:
outb(val, PCIMT_CONFIG_DATA + (reg & 3));
break;
case 2:
outw(val, PCIMT_CONFIG_DATA + (reg & 2));
break;
case 4:
outl(val, PCIMT_CONFIG_DATA);
break;
}
return 0;
}
