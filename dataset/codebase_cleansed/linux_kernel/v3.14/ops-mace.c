static inline int mkaddr(struct pci_bus *bus, unsigned int devfn,
unsigned int reg)
{
return ((bus->number & 0xff) << 16) |
((devfn & 0xff) << 8) |
(reg & 0xfc);
}
static int
mace_pci_read_config(struct pci_bus *bus, unsigned int devfn,
int reg, int size, u32 *val)
{
u32 control = mace->pci.control;
mace->pci.control = control & ~MACEPCI_CONTROL_MAR_INT;
mace->pci.config_addr = mkaddr(bus, devfn, reg);
switch (size) {
case 1:
*val = mace->pci.config_data.b[(reg & 3) ^ 3];
break;
case 2:
*val = mace->pci.config_data.w[((reg >> 1) & 1) ^ 1];
break;
case 4:
*val = mace->pci.config_data.l;
break;
}
mace->pci.error &= ~MACEPCI_ERROR_MASTER_ABORT;
mace->pci.control = control;
if (bus->number == 0 && reg == 0x40 && size == 4 &&
(devfn == (1 << 3) || devfn == (2 << 3)))
*val |= 0x1000;
DPRINTK("read%d: reg=%08x,val=%02x\n", size * 8, reg, *val);
return PCIBIOS_SUCCESSFUL;
}
static int
mace_pci_write_config(struct pci_bus *bus, unsigned int devfn,
int reg, int size, u32 val)
{
mace->pci.config_addr = mkaddr(bus, devfn, reg);
switch (size) {
case 1:
mace->pci.config_data.b[(reg & 3) ^ 3] = val;
break;
case 2:
mace->pci.config_data.w[((reg >> 1) & 1) ^ 1] = val;
break;
case 4:
mace->pci.config_data.l = val;
break;
}
DPRINTK("write%d: reg=%08x,val=%02x\n", size * 8, reg, val);
return PCIBIOS_SUCCESSFUL;
}
