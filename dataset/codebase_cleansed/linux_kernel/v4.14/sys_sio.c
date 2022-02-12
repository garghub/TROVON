static void __init
sio_init_irq(void)
{
if (alpha_using_srm)
alpha_mv.device_interrupt = srm_device_interrupt;
init_i8259a_irqs();
common_init_isa_dma();
}
static inline void __init
alphabook1_init_arch(void)
{
screen_info.orig_y = 37;
screen_info.orig_video_cols = 100;
screen_info.orig_video_lines = 37;
lca_init_arch();
}
static void __init
sio_pci_route(void)
{
unsigned int orig_route_tab;
pci_bus_read_config_dword(pci_isa_hose->bus, PCI_DEVFN(7, 0), 0x60,
&orig_route_tab);
printk("%s: PIRQ original 0x%x new 0x%x\n", __func__,
orig_route_tab, alpha_mv.sys.sio.route_tab);
#if defined(ALPHA_RESTORE_SRM_SETUP)
saved_config.orig_route_tab = orig_route_tab;
#endif
pci_bus_write_config_dword(pci_isa_hose->bus, PCI_DEVFN(7, 0), 0x60,
alpha_mv.sys.sio.route_tab);
}
static unsigned int __init
sio_collect_irq_levels(void)
{
unsigned int level_bits = 0;
struct pci_dev *dev = NULL;
for_each_pci_dev(dev) {
if ((dev->class >> 16 == PCI_BASE_CLASS_BRIDGE) &&
(dev->class >> 8 != PCI_CLASS_BRIDGE_PCMCIA))
continue;
if (dev->irq)
level_bits |= (1 << dev->irq);
}
return level_bits;
}
static void __init
sio_fixup_irq_levels(unsigned int level_bits)
{
unsigned int old_level_bits;
old_level_bits = inb(0x4d0) | (inb(0x4d1) << 8);
level_bits |= (old_level_bits & 0x71ff);
outb((level_bits >> 0) & 0xff, 0x4d0);
outb((level_bits >> 8) & 0xff, 0x4d1);
}
static inline int
noname_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
static char irq_tab[][5] = {
{ 3, 3, 3, 3, 3},
{-1, -1, -1, -1, -1},
{ 2, 2, -1, -1, -1},
{-1, -1, -1, -1, -1},
{-1, -1, -1, -1, -1},
{ 0, 0, 2, 1, 0},
{ 1, 1, 0, 2, 1},
{ 2, 2, 1, 0, 2},
{ 0, 0, 0, 0, 0},
};
const long min_idsel = 6, max_idsel = 14, irqs_per_slot = 5;
int irq = COMMON_TABLE_LOOKUP, tmp;
tmp = __kernel_extbl(alpha_mv.sys.sio.route_tab, irq);
return irq >= 0 ? tmp : -1;
}
static inline int
p2k_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
static char irq_tab[][5] = {
{ 0, 0, -1, -1, -1},
{-1, -1, -1, -1, -1},
{ 1, 1, 2, 3, 0},
{ 2, 2, 3, 0, 1},
{-1, -1, -1, -1, -1},
{-1, -1, -1, -1, -1},
{ 3, 3, -1, -1, -1},
};
const long min_idsel = 6, max_idsel = 12, irqs_per_slot = 5;
int irq = COMMON_TABLE_LOOKUP, tmp;
tmp = __kernel_extbl(alpha_mv.sys.sio.route_tab, irq);
return irq >= 0 ? tmp : -1;
}
static inline void __init
noname_init_pci(void)
{
common_init_pci();
sio_pci_route();
sio_fixup_irq_levels(sio_collect_irq_levels());
if (pc873xx_probe() == -1) {
printk(KERN_ERR "Probing for PC873xx Super IO chip failed.\n");
} else {
printk(KERN_INFO "Found %s Super IO chip at 0x%x\n",
pc873xx_get_model(), pc873xx_get_base());
#if !defined(CONFIG_ALPHA_AVANTI)
pc873xx_enable_ide();
#endif
pc873xx_enable_epp19();
}
}
static inline void __init
alphabook1_init_pci(void)
{
struct pci_dev *dev;
unsigned char orig, config;
common_init_pci();
sio_pci_route();
dev = NULL;
while ((dev = pci_get_device(PCI_VENDOR_ID_NCR, PCI_ANY_ID, dev))) {
if (dev->device == PCI_DEVICE_ID_NCR_53C810
|| dev->device == PCI_DEVICE_ID_NCR_53C815
|| dev->device == PCI_DEVICE_ID_NCR_53C820
|| dev->device == PCI_DEVICE_ID_NCR_53C825) {
unsigned long io_port;
unsigned char ctest4;
io_port = dev->resource[0].start;
ctest4 = inb(io_port+0x21);
if (!(ctest4 & 0x80)) {
printk("AlphaBook1 NCR init: setting"
" burst disable\n");
outb(ctest4 | 0x80, io_port+0x21);
}
}
}
sio_fixup_irq_levels(0);
outb(0x0f, 0x3ce); orig = inb(0x3cf);
outb(0x0f, 0x3ce); outb(0x05, 0x3cf);
outb(0x0b, 0x3ce); config = inb(0x3cf);
if ((config & 0xc0) != 0xc0) {
printk("AlphaBook1 VGA init: setting 1Mb memory\n");
config |= 0xc0;
outb(0x0b, 0x3ce); outb(config, 0x3cf);
}
outb(0x0f, 0x3ce); outb(orig, 0x3cf);
}
void
sio_kill_arch(int mode)
{
#if defined(ALPHA_RESTORE_SRM_SETUP)
pci_bus_write_config_dword(pci_isa_hose->bus, PCI_DEVFN(7, 0), 0x60,
saved_config.orig_route_tab);
#endif
}
