static inline u32 READCFG32(u32 addr)
{
return *(u32 *) (cfg_space + (addr & ~3));
}
static inline void WRITECFG32(u32 addr, u32 data)
{
*(u32 *) (cfg_space + (addr & ~3)) = data;
}
int pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
return dev->irq;
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
static int sb1250_pci_can_access(struct pci_bus *bus, int devfn)
{
u32 devno;
if (!(sb1250_bus_status & (PCI_BUS_ENABLED | PCI_DEVICE_MODE)))
return 0;
if (bus->number == 0) {
devno = PCI_SLOT(devfn);
if (devno == LDT_BRIDGE_DEVICE)
return (sb1250_bus_status & LDT_BUS_ENABLED) != 0;
else if (sb1250_bus_status & PCI_DEVICE_MODE)
return 0;
else
return 1;
} else
return 1;
}
static int sb1250_pcibios_read(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 * val)
{
u32 data = 0;
if ((size == 2) && (where & 1))
return PCIBIOS_BAD_REGISTER_NUMBER;
else if ((size == 4) && (where & 3))
return PCIBIOS_BAD_REGISTER_NUMBER;
if (sb1250_pci_can_access(bus, devfn))
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
static int sb1250_pcibios_write(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
u32 cfgaddr = CFGADDR(bus, devfn, where);
u32 data = 0;
if ((size == 2) && (where & 1))
return PCIBIOS_BAD_REGISTER_NUMBER;
else if ((size == 4) && (where & 3))
return PCIBIOS_BAD_REGISTER_NUMBER;
if (!sb1250_pci_can_access(bus, devfn))
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
static int __init sb1250_pcibios_init(void)
{
void __iomem *io_map_base;
uint32_t cmdreg;
uint64_t reg;
pci_set_flags(PCI_PROBE_ONLY);
PCIBIOS_MIN_IO = 0x00008000UL;
PCIBIOS_MIN_MEM = 0x01000000UL;
ioport_resource.end = 0x01ffffffUL;
iomem_resource.end = 0xffffffffUL;
cfg_space =
ioremap(A_PHYS_LDTPCI_CFG_MATCH_BITS, 16 * 1024 * 1024);
reg = __raw_readq(IOADDR(A_SCD_SYSTEM_CFG));
if (!(reg & M_SYS_PCI_HOST)) {
sb1250_bus_status |= PCI_DEVICE_MODE;
} else {
cmdreg =
READCFG32(CFGOFFSET
(0, PCI_DEVFN(PCI_BRIDGE_DEVICE, 0),
PCI_COMMAND));
if (!(cmdreg & PCI_COMMAND_MASTER)) {
printk
("PCI: Skipping PCI probe. Bus is not initialized.\n");
iounmap(cfg_space);
return 0;
}
sb1250_bus_status |= PCI_BUS_ENABLED;
}
io_map_base = ioremap(A_PHYS_LDTPCI_IO_MATCH_BYTES, 1024 * 1024);
sb1250_controller.io_map_base = (unsigned long)io_map_base;
set_io_port_base((unsigned long)io_map_base);
#ifdef CONFIG_SIBYTE_HAS_LDT
cmdreg = READCFG32(CFGOFFSET(0, PCI_DEVFN(LDT_BRIDGE_DEVICE, 0),
PCI_COMMAND));
if (cmdreg & PCI_COMMAND_MASTER) {
sb1250_bus_status |= LDT_BUS_ENABLED;
ldt_eoi_space = (unsigned long)
ioremap(A_PHYS_LDT_SPECIAL_MATCH_BYTES,
4 * 1024 * 1024);
}
#endif
register_pci_controller(&sb1250_controller);
#ifdef CONFIG_VGA_CONSOLE
console_lock();
do_take_over_console(&vga_con, 0, MAX_NR_CONSOLES - 1, 1);
console_unlock();
#endif
return 0;
}
