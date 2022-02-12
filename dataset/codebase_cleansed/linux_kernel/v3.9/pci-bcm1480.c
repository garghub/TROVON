static inline u32 READCFG32(u32 addr)
{
return *(u32 *)(cfg_space + (addr&~3));
}
static inline void WRITECFG32(u32 addr, u32 data)
{
*(u32 *)(cfg_space + (addr & ~3)) = data;
}
int pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
if (pin == 0)
return -1;
return K_BCM1480_INT_PCI_INTA - 1 + pin;
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
static int bcm1480_pci_can_access(struct pci_bus *bus, int devfn)
{
u32 devno;
if (!(bcm1480_bus_status & (PCI_BUS_ENABLED | PCI_DEVICE_MODE)))
return 0;
if (bus->number == 0) {
devno = PCI_SLOT(devfn);
if (bcm1480_bus_status & PCI_DEVICE_MODE)
return 0;
else
return 1;
} else
return 1;
}
static int bcm1480_pcibios_read(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 * val)
{
u32 data = 0;
if ((size == 2) && (where & 1))
return PCIBIOS_BAD_REGISTER_NUMBER;
else if ((size == 4) && (where & 3))
return PCIBIOS_BAD_REGISTER_NUMBER;
if (bcm1480_pci_can_access(bus, devfn))
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
static int bcm1480_pcibios_write(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
u32 cfgaddr = CFGADDR(bus, devfn, where);
u32 data = 0;
if ((size == 2) && (where & 1))
return PCIBIOS_BAD_REGISTER_NUMBER;
else if ((size == 4) && (where & 3))
return PCIBIOS_BAD_REGISTER_NUMBER;
if (!bcm1480_pci_can_access(bus, devfn))
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
static int __init bcm1480_pcibios_init(void)
{
uint32_t cmdreg;
uint64_t reg;
pci_set_flags(PCI_PROBE_ONLY);
PCIBIOS_MIN_IO = 0x00008000UL;
PCIBIOS_MIN_MEM = 0x01000000UL;
ioport_resource.end = 0xffffffffUL;
iomem_resource.end = 0xffffffffUL;
cfg_space = ioremap(A_BCM1480_PHYS_PCI_CFG_MATCH_BITS, 16*1024*1024);
reg = __raw_readq(IOADDR(A_SCD_SYSTEM_CFG));
if (!(reg & M_BCM1480_SYS_PCI_HOST)) {
bcm1480_bus_status |= PCI_DEVICE_MODE;
} else {
cmdreg = READCFG32(CFGOFFSET(0, PCI_DEVFN(PCI_BRIDGE_DEVICE, 0),
PCI_COMMAND));
if (!(cmdreg & PCI_COMMAND_MASTER)) {
printk
("PCI: Skipping PCI probe. Bus is not initialized.\n");
iounmap(cfg_space);
return 1;
}
bcm1480_bus_status |= PCI_BUS_ENABLED;
}
cmdreg = READCFG32(CFGOFFSET(0, PCI_DEVFN(PCI_BRIDGE_DEVICE, 0), 0x40));
WRITECFG32(CFGOFFSET(0, PCI_DEVFN(PCI_BRIDGE_DEVICE, 0), 0x40),
cmdreg | 0x10);
cmdreg = READCFG32(CFGOFFSET(0, PCI_DEVFN(PCI_BRIDGE_DEVICE, 0), 0x40));
bcm1480_controller.io_map_base = (unsigned long)
ioremap(A_BCM1480_PHYS_PCI_IO_MATCH_BYTES, 65536);
bcm1480_controller.io_map_base -= bcm1480_controller.io_offset;
set_io_port_base(bcm1480_controller.io_map_base);
register_pci_controller(&bcm1480_controller);
#ifdef CONFIG_VGA_CONSOLE
take_over_console(&vga_con, 0, MAX_NR_CONSOLES-1, 1);
#endif
return 0;
}
