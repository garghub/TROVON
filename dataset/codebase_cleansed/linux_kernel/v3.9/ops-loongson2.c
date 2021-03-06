static int loongson_pcibios_config_access(unsigned char access_type,
struct pci_bus *bus,
unsigned int devfn, int where,
u32 *data)
{
u32 busnum = bus->number;
u32 addr, type;
u32 dummy;
void *addrp;
int device = PCI_SLOT(devfn);
int function = PCI_FUNC(devfn);
int reg = where & ~3;
if (busnum == 0) {
#ifdef CONFIG_CS5536
if ((PCI_IDSEL_CS5536 == device) && (reg < PCI_MSR_CTRL)) {
switch (access_type) {
case PCI_ACCESS_READ:
*data = cs5536_pci_conf_read4(function, reg);
break;
case PCI_ACCESS_WRITE:
cs5536_pci_conf_write4(function, reg, *data);
break;
}
return 0;
}
#endif
if (device > MAX_DEV_NUM)
return -1;
addr = (1 << (device + ID_SEL_BEGIN)) | (function << 8) | reg;
type = 0;
} else {
addr = (busnum << 16) | (device << 11) | (function << 8) | reg;
type = 0x10000;
}
LOONGSON_PCICMD |= LOONGSON_PCICMD_MABORT_CLR | \
LOONGSON_PCICMD_MTABORT_CLR;
LOONGSON_PCIMAP_CFG = (addr >> 16) | type;
dummy = LOONGSON_PCIMAP_CFG;
mmiowb();
addrp = CFG_SPACE_REG(addr & 0xffff);
if (access_type == PCI_ACCESS_WRITE)
writel(cpu_to_le32(*data), addrp);
else
*data = le32_to_cpu(readl(addrp));
if (LOONGSON_PCICMD & (LOONGSON_PCICMD_MABORT_CLR |
LOONGSON_PCICMD_MTABORT_CLR)) {
LOONGSON_PCICMD |= (LOONGSON_PCICMD_MABORT_CLR |
LOONGSON_PCICMD_MTABORT_CLR);
return -1;
}
return 0;
}
static int loongson_pcibios_read(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
u32 data = 0;
if ((size == 2) && (where & 1))
return PCIBIOS_BAD_REGISTER_NUMBER;
else if ((size == 4) && (where & 3))
return PCIBIOS_BAD_REGISTER_NUMBER;
if (loongson_pcibios_config_access(PCI_ACCESS_READ, bus, devfn, where,
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
static int loongson_pcibios_write(struct pci_bus *bus, unsigned int devfn,
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
if (loongson_pcibios_config_access(PCI_ACCESS_READ, bus, devfn,
where, &data))
return -1;
if (size == 1)
data = (data & ~(0xff << ((where & 3) << 3))) |
(val << ((where & 3) << 3));
else if (size == 2)
data = (data & ~(0xffff << ((where & 3) << 3))) |
(val << ((where & 3) << 3));
}
if (loongson_pcibios_config_access(PCI_ACCESS_WRITE, bus, devfn, where,
&data))
return -1;
return PCIBIOS_SUCCESSFUL;
}
void _rdmsr(u32 msr, u32 *hi, u32 *lo)
{
struct pci_bus bus = {
.number = PCI_BUS_CS5536
};
u32 devfn = PCI_DEVFN(PCI_IDSEL_CS5536, 0);
unsigned long flags;
raw_spin_lock_irqsave(&msr_lock, flags);
loongson_pcibios_write(&bus, devfn, PCI_MSR_ADDR, 4, msr);
loongson_pcibios_read(&bus, devfn, PCI_MSR_DATA_LO, 4, lo);
loongson_pcibios_read(&bus, devfn, PCI_MSR_DATA_HI, 4, hi);
raw_spin_unlock_irqrestore(&msr_lock, flags);
}
void _wrmsr(u32 msr, u32 hi, u32 lo)
{
struct pci_bus bus = {
.number = PCI_BUS_CS5536
};
u32 devfn = PCI_DEVFN(PCI_IDSEL_CS5536, 0);
unsigned long flags;
raw_spin_lock_irqsave(&msr_lock, flags);
loongson_pcibios_write(&bus, devfn, PCI_MSR_ADDR, 4, msr);
loongson_pcibios_write(&bus, devfn, PCI_MSR_DATA_LO, 4, lo);
loongson_pcibios_write(&bus, devfn, PCI_MSR_DATA_HI, 4, hi);
raw_spin_unlock_irqrestore(&msr_lock, flags);
}
