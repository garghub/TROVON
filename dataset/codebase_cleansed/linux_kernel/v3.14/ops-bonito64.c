static int bonito64_pcibios_config_access(unsigned char access_type,
struct pci_bus *bus,
unsigned int devfn, int where,
u32 * data)
{
u32 busnum = bus->number;
u32 addr, type;
u32 dummy;
void *addrp;
int device = PCI_SLOT(devfn);
int function = PCI_FUNC(devfn);
int reg = where & ~3;
if (busnum == 0) {
if (device > MAX_DEV_NUM)
return -1;
addr = (1 << (device + ID_SEL_BEGIN)) | (function << 8) | reg;
type = 0;
} else {
addr = (busnum << 16) | (device << 11) | (function << 8) | reg;
type = 0x10000;
}
BONITO_PCICMD |= BONITO_PCICMD_MABORT_CLR | BONITO_PCICMD_MTABORT_CLR;
BONITO_PCIMAP_CFG = (addr >> 16) | type;
dummy = BONITO_PCIMAP_CFG;
mmiowb();
addrp = CFG_SPACE_REG(addr & 0xffff);
if (access_type == PCI_ACCESS_WRITE) {
writel(cpu_to_le32(*data), addrp);
while (BONITO_PCIMSTAT & 0xF);
} else {
*data = le32_to_cpu(readl(addrp));
}
if (BONITO_PCICMD & (BONITO_PCICMD_MABORT_CLR |
BONITO_PCICMD_MTABORT_CLR)) {
BONITO_PCICMD |= (BONITO_PCICMD_MABORT_CLR |
BONITO_PCICMD_MTABORT_CLR);
return -1;
}
return 0;
}
static int bonito64_pcibios_read(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 * val)
{
u32 data = 0;
if ((size == 2) && (where & 1))
return PCIBIOS_BAD_REGISTER_NUMBER;
else if ((size == 4) && (where & 3))
return PCIBIOS_BAD_REGISTER_NUMBER;
if (bonito64_pcibios_config_access(PCI_ACCESS_READ, bus, devfn, where,
&data))
return -1;
if (size == 1)
*val = (data >> ((where & 3) << 3)) & 0xff;
else if (size == 2)
*val = (data >> ((where & 3) << 3)) & 0xffff;
else
*val = data;
return PCIBIOS_SUCCESSFUL;
}
static int bonito64_pcibios_write(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
u32 data = 0;
if ((size == 2) && (where & 1))
return PCIBIOS_BAD_REGISTER_NUMBER;
else if ((size == 4) && (where & 3))
return PCIBIOS_BAD_REGISTER_NUMBER;
if (size == 4)
data = val;
else {
if (bonito64_pcibios_config_access(PCI_ACCESS_READ, bus, devfn,
where, &data))
return -1;
if (size == 1)
data = (data & ~(0xff << ((where & 3) << 3))) |
(val << ((where & 3) << 3));
else if (size == 2)
data = (data & ~(0xffff << ((where & 3) << 3))) |
(val << ((where & 3) << 3));
}
if (bonito64_pcibios_config_access(PCI_ACCESS_WRITE, bus, devfn, where,
&data))
return -1;
return PCIBIOS_SUCCESSFUL;
}
