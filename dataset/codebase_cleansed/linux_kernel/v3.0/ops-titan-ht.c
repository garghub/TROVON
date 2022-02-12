static int titan_ht_config_read_dword(struct pci_bus *bus, unsigned int devfn,
int offset, u32 *val)
{
volatile uint32_t address;
int busno;
busno = bus->number;
address = (busno << 16) | (devfn << 8) | (offset & 0xfc) | 0x80000000;
if (busno != 0)
address |= 1;
*(volatile int32_t *) 0xfb0000f0 |= 0x2;
udelay(30);
*(volatile int32_t *) 0xfb0006f8 = address;
*(val) = *(volatile int32_t *) 0xfb0006fc;
udelay(30);
* (volatile int32_t *) 0xfb0000f0 |= 0x2;
return PCIBIOS_SUCCESSFUL;
}
static int titan_ht_config_read(struct pci_bus *bus, unsigned int devfn,
int offset, int size, u32 *val)
{
uint32_t dword;
titan_ht_config_read_dword(bus, devfn, offset, &dword);
dword >>= ((offset & 3) << 3);
dword &= (0xffffffffU >> ((4 - size) << 8));
return PCIBIOS_SUCCESSFUL;
}
static inline int titan_ht_config_write_dword(struct pci_bus *bus,
unsigned int devfn, int offset, u32 val)
{
volatile uint32_t address;
int busno;
busno = bus->number;
address = (busno << 16) | (devfn << 8) | (offset & 0xfc) | 0x80000000;
if (busno != 0)
address |= 1;
*(volatile int32_t *) 0xfb0000f0 |= 0x2;
udelay(30);
*(volatile int32_t *) 0xfb0006f8 = address;
*(volatile int32_t *) 0xfb0006fc = val;
udelay(30);
*(volatile int32_t *) 0xfb0000f0 |= 0x2;
return PCIBIOS_SUCCESSFUL;
}
static int titan_ht_config_write(struct pci_bus *bus, unsigned int devfn,
int offset, int size, u32 val)
{
uint32_t val1, val2, mask;
titan_ht_config_read_dword(bus, devfn, offset, &val2);
val1 = val << ((offset & 3) << 3);
mask = ~(0xffffffffU >> ((4 - size) << 8));
val2 &= ~(mask << ((offset & 3) << 8));
titan_ht_config_write_dword(bus, devfn, offset, val1 | val2);
return PCIBIOS_SUCCESSFUL;
}
