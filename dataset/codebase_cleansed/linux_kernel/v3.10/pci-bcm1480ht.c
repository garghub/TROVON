static inline u32 READCFG32(u32 addr)
{
return *(u32 *)(ht_cfg_space + (addr&~3));
}
static inline void WRITECFG32(u32 addr, u32 data)
{
*(u32 *)(ht_cfg_space + (addr & ~3)) = data;
}
static int bcm1480ht_can_access(struct pci_bus *bus, int devfn)
{
u32 devno;
if (!(bcm1480ht_bus_status & (PCI_BUS_ENABLED | PCI_DEVICE_MODE)))
return 0;
if (bus->number == 0) {
devno = PCI_SLOT(devfn);
if (bcm1480ht_bus_status & PCI_DEVICE_MODE)
return 0;
}
return 1;
}
static int bcm1480ht_pcibios_read(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 * val)
{
u32 data = 0;
if ((size == 2) && (where & 1))
return PCIBIOS_BAD_REGISTER_NUMBER;
else if ((size == 4) && (where & 3))
return PCIBIOS_BAD_REGISTER_NUMBER;
if (bcm1480ht_can_access(bus, devfn))
data = READCFG32(CFGADDR(bus, devfn, where));
else
data = 0xFFFFFFFF;
if (size == 1)
*val = (data >> ((where & 3) << 3)) & 0xff;
else if (size == 2)
*val = (data >> ((where & 3) << 3)) & 0xffff;
else
*val = data;
return PCIBIOS_SUCCESSFUL;
}
static int bcm1480ht_pcibios_write(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
u32 cfgaddr = CFGADDR(bus, devfn, where);
u32 data = 0;
if ((size == 2) && (where & 1))
return PCIBIOS_BAD_REGISTER_NUMBER;
else if ((size == 4) && (where & 3))
return PCIBIOS_BAD_REGISTER_NUMBER;
if (!bcm1480ht_can_access(bus, devfn))
return PCIBIOS_BAD_REGISTER_NUMBER;
data = READCFG32(cfgaddr);
if (size == 1)
data = (data & ~(0xff << ((where & 3) << 3))) |
(val << ((where & 3) << 3));
else if (size == 2)
data = (data & ~(0xffff << ((where & 3) << 3))) |
(val << ((where & 3) << 3));
else
data = val;
WRITECFG32(cfgaddr, data);
return PCIBIOS_SUCCESSFUL;
}
static int bcm1480ht_pcibios_get_busno(void)
{
return 0;
}
static int __init bcm1480ht_pcibios_init(void)
{
ht_cfg_space = ioremap(A_BCM1480_PHYS_HT_CFG_MATCH_BITS, 16*1024*1024);
bcm1480ht_bus_status |= PCI_BUS_ENABLED;
ht_eoi_space = (unsigned long)
ioremap(A_BCM1480_PHYS_HT_SPECIAL_MATCH_BYTES,
4 * 1024 * 1024);
bcm1480ht_controller.io_map_base = (unsigned long)
ioremap(A_BCM1480_PHYS_HT_IO_MATCH_BYTES, 65536);
bcm1480ht_controller.io_map_base -= bcm1480ht_controller.io_offset;
register_pci_controller(&bcm1480ht_controller);
return 0;
}
