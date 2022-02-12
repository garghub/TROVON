static void reg_init(struct sim_dev_reg *reg)
{
pci_direct_conf1.read(0, 1, reg->dev_func, reg->reg, 4,
&reg->sim_reg.value);
}
static void reg_read(struct sim_dev_reg *reg, u32 *value)
{
*value = reg->sim_reg.value;
}
static void reg_write(struct sim_dev_reg *reg, u32 value)
{
reg->sim_reg.value = (value & reg->sim_reg.mask) |
(reg->sim_reg.value & ~reg->sim_reg.mask);
}
static void sata_reg_init(struct sim_dev_reg *reg)
{
pci_direct_conf1.read(0, 1, PCI_DEVFN(14, 0), 0x10, 4,
&reg->sim_reg.value);
reg->sim_reg.value += 0x400;
}
static void ehci_reg_read(struct sim_dev_reg *reg, u32 *value)
{
reg_read(reg, value);
if (*value != reg->sim_reg.mask)
*value |= 0x100;
}
void sata_revid_init(struct sim_dev_reg *reg)
{
reg->sim_reg.value = 0x01060100;
reg->sim_reg.mask = 0;
}
static void sata_revid_read(struct sim_dev_reg *reg, u32 *value)
{
reg_read(reg, value);
}
static void reg_noirq_read(struct sim_dev_reg *reg, u32 *value)
{
*value = reg->sim_reg.value & 0xfff00ff;
}
static void __init init_sim_regs(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(bus1_fixups); i++) {
if (bus1_fixups[i].init)
bus1_fixups[i].init(&bus1_fixups[i]);
}
}
static inline void extract_bytes(u32 *value, int reg, int len)
{
uint32_t mask;
*value >>= ((reg & 3) * 8);
mask = 0xFFFFFFFF >> ((4 - len) * 8);
*value &= mask;
}
int bridge_read(unsigned int devfn, int reg, int len, u32 *value)
{
u32 av_bridge_base, av_bridge_limit;
int retval = 0;
switch (reg) {
case PCI_BASE_ADDRESS_0:
case PCI_BASE_ADDRESS_0 + 1:
case PCI_BASE_ADDRESS_0 + 2:
case PCI_BASE_ADDRESS_0 + 3:
*value = 0;
break;
case PCI_PRIMARY_BUS:
if (len == 4)
*value = 0x00010100;
break;
case PCI_SUBORDINATE_BUS:
*value = 1;
break;
case PCI_MEMORY_BASE:
case PCI_MEMORY_LIMIT:
pci_direct_conf1.read(0, 0, devfn,
PCI_BASE_ADDRESS_0, 4, &av_bridge_base);
av_bridge_limit = av_bridge_base + (512*MB - 1);
av_bridge_limit >>= 16;
av_bridge_limit &= 0xFFF0;
av_bridge_base >>= 16;
av_bridge_base &= 0xFFF0;
if (reg == PCI_MEMORY_LIMIT)
*value = av_bridge_limit;
else if (len == 2)
*value = av_bridge_base;
else
*value = (av_bridge_limit << 16) | av_bridge_base;
break;
case PCI_PREF_MEMORY_BASE:
*value = 0xFFF0;
break;
case PCI_PREF_MEMORY_LIMIT:
*value = 0x0;
break;
case PCI_IO_BASE:
*value = 0xF0;
break;
case PCI_IO_LIMIT:
*value = 0;
break;
default:
retval = 1;
}
return retval;
}
static int ce4100_bus1_read(unsigned int devfn, int reg, int len, u32 *value)
{
unsigned long flags;
int i;
for (i = 0; i < ARRAY_SIZE(bus1_fixups); i++) {
if (bus1_fixups[i].dev_func == devfn &&
bus1_fixups[i].reg == (reg & ~3) &&
bus1_fixups[i].read) {
raw_spin_lock_irqsave(&pci_config_lock, flags);
bus1_fixups[i].read(&(bus1_fixups[i]), value);
raw_spin_unlock_irqrestore(&pci_config_lock, flags);
extract_bytes(value, reg, len);
return 0;
}
}
return -1;
}
static int ce4100_conf_read(unsigned int seg, unsigned int bus,
unsigned int devfn, int reg, int len, u32 *value)
{
WARN_ON(seg);
if (bus == 1 && !ce4100_bus1_read(devfn, reg, len, value))
return 0;
if (bus == 0 && (PCI_DEVFN(1, 0) == devfn) &&
!bridge_read(devfn, reg, len, value))
return 0;
return pci_direct_conf1.read(seg, bus, devfn, reg, len, value);
}
static int ce4100_bus1_write(unsigned int devfn, int reg, int len, u32 value)
{
unsigned long flags;
int i;
for (i = 0; i < ARRAY_SIZE(bus1_fixups); i++) {
if (bus1_fixups[i].dev_func == devfn &&
bus1_fixups[i].reg == (reg & ~3) &&
bus1_fixups[i].write) {
raw_spin_lock_irqsave(&pci_config_lock, flags);
bus1_fixups[i].write(&(bus1_fixups[i]), value);
raw_spin_unlock_irqrestore(&pci_config_lock, flags);
return 0;
}
}
return -1;
}
static int ce4100_conf_write(unsigned int seg, unsigned int bus,
unsigned int devfn, int reg, int len, u32 value)
{
WARN_ON(seg);
if (bus == 1 && !ce4100_bus1_write(devfn, reg, len, value))
return 0;
if (bus == 0 && PCI_DEVFN(1, 0) == devfn &&
((reg & ~3) == PCI_BASE_ADDRESS_0))
return 0;
return pci_direct_conf1.write(seg, bus, devfn, reg, len, value);
}
int __init ce4100_pci_init(void)
{
init_sim_regs();
raw_pci_ops = &ce4100_pci_conf;
return 1;
}
