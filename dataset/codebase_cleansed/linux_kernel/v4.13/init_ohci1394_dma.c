static inline void reg_write(const struct ohci *ohci, int offset, u32 data)
{
writel(data, ohci->registers + offset);
}
static inline u32 reg_read(const struct ohci *ohci, int offset)
{
return readl(ohci->registers + offset);
}
static inline u8 __init get_phy_reg(struct ohci *ohci, u8 addr)
{
int i;
u32 r;
reg_write(ohci, OHCI1394_PhyControl, (addr << 8) | 0x00008000);
for (i = 0; i < OHCI_LOOP_COUNT; i++) {
if (reg_read(ohci, OHCI1394_PhyControl) & 0x80000000)
break;
mdelay(1);
}
r = reg_read(ohci, OHCI1394_PhyControl);
return (r & 0x00ff0000) >> 16;
}
static inline void __init set_phy_reg(struct ohci *ohci, u8 addr, u8 data)
{
int i;
reg_write(ohci, OHCI1394_PhyControl, (addr << 8) | data | 0x00004000);
for (i = 0; i < OHCI_LOOP_COUNT; i++) {
if (!(reg_read(ohci, OHCI1394_PhyControl) & 0x00004000))
break;
mdelay(1);
}
}
static inline void __init init_ohci1394_soft_reset(struct ohci *ohci)
{
int i;
reg_write(ohci, OHCI1394_HCControlSet, OHCI1394_HCControl_softReset);
for (i = 0; i < OHCI_LOOP_COUNT; i++) {
if (!(reg_read(ohci, OHCI1394_HCControlSet)
& OHCI1394_HCControl_softReset))
break;
mdelay(1);
}
}
static inline void __init init_ohci1394_initialize(struct ohci *ohci)
{
u32 bus_options;
int num_ports, i;
bus_options = reg_read(ohci, OHCI1394_BusOptions);
bus_options |= 0x60000000;
bus_options &= ~0x00ff0000;
bus_options &= ~0x18000000;
reg_write(ohci, OHCI1394_BusOptions, bus_options);
reg_write(ohci, OHCI1394_NodeID, 0x0000ffc0);
reg_write(ohci, OHCI1394_HCControlSet,
OHCI1394_HCControl_postedWriteEnable);
reg_write(ohci, OHCI1394_LinkControlClear, 0xffffffff);
reg_write(ohci, OHCI1394_LinkControlSet,
OHCI1394_LinkControl_rcvPhyPkt);
reg_write(ohci, OHCI1394_LinkControlClear, 0x00000400);
reg_write(ohci, OHCI1394_IsoRecvIntMaskClear, 0xffffffff);
reg_write(ohci, OHCI1394_IsoRecvIntEventClear, 0xffffffff);
reg_write(ohci, OHCI1394_IsoXmitIntMaskClear, 0xffffffff);
reg_write(ohci, OHCI1394_IsoXmitIntEventClear, 0xffffffff);
reg_write(ohci, OHCI1394_AsReqFilterHiSet, 0x80000000);
reg_write(ohci, OHCI1394_ATRetries,
OHCI1394_MAX_AT_REQ_RETRIES |
(OHCI1394_MAX_AT_RESP_RETRIES<<4) |
(OHCI1394_MAX_PHYS_RESP_RETRIES<<8));
reg_write(ohci, OHCI1394_HCControlClear,
OHCI1394_HCControl_noByteSwapData);
reg_write(ohci, OHCI1394_HCControlSet, OHCI1394_HCControl_linkEnable);
num_ports = get_phy_reg(ohci, 2) & 0xf;
for (i = 0; i < num_ports; i++) {
unsigned int status;
set_phy_reg(ohci, 7, i);
status = get_phy_reg(ohci, 8);
if (status & 0x20)
set_phy_reg(ohci, 8, status & ~1);
}
}
static inline void __init init_ohci1394_wait_for_busresets(struct ohci *ohci)
{
int i, events;
for (i = 0; i < 9; i++) {
mdelay(200);
events = reg_read(ohci, OHCI1394_IntEventSet);
if (events & OHCI1394_busReset)
reg_write(ohci, OHCI1394_IntEventClear,
OHCI1394_busReset);
}
}
static inline void __init init_ohci1394_enable_physical_dma(struct ohci *ohci)
{
reg_write(ohci, OHCI1394_PhyReqFilterHiSet, 0xffffffff);
reg_write(ohci, OHCI1394_PhyReqFilterLoSet, 0xffffffff);
reg_write(ohci, OHCI1394_PhyUpperBound, 0xffff0000);
}
static inline void __init init_ohci1394_reset_and_init_dma(struct ohci *ohci)
{
init_ohci1394_soft_reset(ohci);
reg_write(ohci, OHCI1394_HCControlSet, OHCI1394_HCControl_LPS);
reg_write(ohci, OHCI1394_IntEventClear, 0xffffffff);
reg_write(ohci, OHCI1394_IntMaskClear, 0xffffffff);
mdelay(50);
init_ohci1394_initialize(ohci);
init_ohci1394_wait_for_busresets(ohci);
init_ohci1394_enable_physical_dma(ohci);
}
static inline void __init init_ohci1394_controller(int num, int slot, int func)
{
unsigned long ohci_base;
struct ohci ohci;
printk(KERN_INFO "init_ohci1394_dma: initializing OHCI-1394"
" at %02x:%02x.%x\n", num, slot, func);
ohci_base = read_pci_config(num, slot, func, PCI_BASE_ADDRESS_0+(0<<2))
& PCI_BASE_ADDRESS_MEM_MASK;
set_fixmap_nocache(FIX_OHCI1394_BASE, ohci_base);
ohci.registers = (void __iomem *)fix_to_virt(FIX_OHCI1394_BASE);
init_ohci1394_reset_and_init_dma(&ohci);
}
void __init init_ohci1394_dma_on_all_controllers(void)
{
int num, slot, func;
u32 class;
if (!early_pci_allowed())
return;
for (num = 0; num < 32; num++) {
for (slot = 0; slot < 32; slot++) {
for (func = 0; func < 8; func++) {
class = read_pci_config(num, slot, func,
PCI_CLASS_REVISION);
if (class == 0xffffffff)
continue;
if (class>>8 != PCI_CLASS_SERIAL_FIREWIRE_OHCI)
continue;
init_ohci1394_controller(num, slot, func);
break;
}
}
}
printk(KERN_INFO "init_ohci1394_dma: finished initializing OHCI DMA\n");
}
static int __init setup_ohci1394_dma(char *opt)
{
if (!strcmp(opt, "early"))
init_ohci1394_dma_early = 1;
return 0;
}
