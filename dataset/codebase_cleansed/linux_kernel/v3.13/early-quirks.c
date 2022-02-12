static void __init fix_hypertransport_config(int num, int slot, int func)
{
u32 htcfg;
htcfg = read_pci_config(num, slot, func, 0x68);
if (htcfg & (1 << 18)) {
printk(KERN_INFO "Detected use of extended apic ids "
"on hypertransport bus\n");
if ((htcfg & (1 << 17)) == 0) {
printk(KERN_INFO "Enabling hypertransport extended "
"apic interrupt broadcast\n");
printk(KERN_INFO "Note this is a bios bug, "
"please contact your hw vendor\n");
htcfg |= (1 << 17);
write_pci_config(num, slot, func, 0x68, htcfg);
}
}
}
static void __init via_bugs(int num, int slot, int func)
{
#ifdef CONFIG_GART_IOMMU
if ((max_pfn > MAX_DMA32_PFN || force_iommu) &&
!gart_iommu_aperture_allowed) {
printk(KERN_INFO
"Looks like a VIA chipset. Disabling IOMMU."
" Override with iommu=allowed\n");
gart_iommu_aperture_disabled = 1;
}
#endif
}
static int __init nvidia_hpet_check(struct acpi_table_header *header)
{
return 0;
}
static void __init nvidia_bugs(int num, int slot, int func)
{
#ifdef CONFIG_ACPI
#ifdef CONFIG_X86_IO_APIC
if (acpi_use_timer_override)
return;
if (acpi_table_parse(ACPI_SIG_HPET, nvidia_hpet_check)) {
acpi_skip_timer_override = 1;
printk(KERN_INFO "Nvidia board "
"detected. Ignoring ACPI "
"timer override.\n");
printk(KERN_INFO "If you got timer trouble "
"try acpi_use_timer_override\n");
}
#endif
#endif
}
static u32 __init ati_ixp4x0_rev(int num, int slot, int func)
{
u32 d;
u8 b;
b = read_pci_config_byte(num, slot, func, 0xac);
b &= ~(1<<5);
write_pci_config_byte(num, slot, func, 0xac, b);
d = read_pci_config(num, slot, func, 0x70);
d |= 1<<8;
write_pci_config(num, slot, func, 0x70, d);
d = read_pci_config(num, slot, func, 0x8);
d &= 0xff;
return d;
}
static void __init ati_bugs(int num, int slot, int func)
{
u32 d;
u8 b;
if (acpi_use_timer_override)
return;
d = ati_ixp4x0_rev(num, slot, func);
if (d < 0x82)
acpi_skip_timer_override = 1;
else {
outb(0x72, 0xcd6); b = inb(0xcd7);
if (!(b & 0x2))
acpi_skip_timer_override = 1;
}
if (acpi_skip_timer_override) {
printk(KERN_INFO "SB4X0 revision 0x%x\n", d);
printk(KERN_INFO "Ignoring ACPI timer override.\n");
printk(KERN_INFO "If you got timer trouble "
"try acpi_use_timer_override\n");
}
}
static u32 __init ati_sbx00_rev(int num, int slot, int func)
{
u32 d;
d = read_pci_config(num, slot, func, 0x8);
d &= 0xff;
return d;
}
static void __init ati_bugs_contd(int num, int slot, int func)
{
u32 d, rev;
rev = ati_sbx00_rev(num, slot, func);
if (rev >= 0x40)
acpi_fix_pin2_polarity = 1;
if (rev >= 0x39)
return;
if (acpi_use_timer_override)
return;
d = read_pci_config(num, slot, func, 0x64);
if (!(d & (1<<14)))
acpi_skip_timer_override = 1;
if (acpi_skip_timer_override) {
printk(KERN_INFO "SB600 revision 0x%x\n", rev);
printk(KERN_INFO "Ignoring ACPI timer override.\n");
printk(KERN_INFO "If you got timer trouble "
"try acpi_use_timer_override\n");
}
}
static void __init ati_bugs(int num, int slot, int func)
{
}
static void __init ati_bugs_contd(int num, int slot, int func)
{
}
static void __init intel_remapping_check(int num, int slot, int func)
{
u8 revision;
u16 device;
device = read_pci_config_16(num, slot, func, PCI_DEVICE_ID);
revision = read_pci_config_byte(num, slot, func, PCI_REVISION_ID);
if (revision == 0x13)
set_irq_remapping_broken();
else if ((device == 0x3405) &&
((revision == 0x12) ||
(revision == 0x22)))
set_irq_remapping_broken();
}
static u32 __init intel_stolen_base(int num, int slot, int func)
{
u32 base;
base = read_pci_config(num, slot, func, 0x5c);
base &= ~((1<<20) - 1);
return base;
}
static size_t __init gen3_stolen_size(int num, int slot, int func)
{
size_t stolen_size;
u16 gmch_ctrl;
gmch_ctrl = read_pci_config_16(0, 0, 0, I830_GMCH_CTRL);
switch (gmch_ctrl & I855_GMCH_GMS_MASK) {
case I855_GMCH_GMS_STOLEN_1M:
stolen_size = MB(1);
break;
case I855_GMCH_GMS_STOLEN_4M:
stolen_size = MB(4);
break;
case I855_GMCH_GMS_STOLEN_8M:
stolen_size = MB(8);
break;
case I855_GMCH_GMS_STOLEN_16M:
stolen_size = MB(16);
break;
case I855_GMCH_GMS_STOLEN_32M:
stolen_size = MB(32);
break;
case I915_GMCH_GMS_STOLEN_48M:
stolen_size = MB(48);
break;
case I915_GMCH_GMS_STOLEN_64M:
stolen_size = MB(64);
break;
case G33_GMCH_GMS_STOLEN_128M:
stolen_size = MB(128);
break;
case G33_GMCH_GMS_STOLEN_256M:
stolen_size = MB(256);
break;
case INTEL_GMCH_GMS_STOLEN_96M:
stolen_size = MB(96);
break;
case INTEL_GMCH_GMS_STOLEN_160M:
stolen_size = MB(160);
break;
case INTEL_GMCH_GMS_STOLEN_224M:
stolen_size = MB(224);
break;
case INTEL_GMCH_GMS_STOLEN_352M:
stolen_size = MB(352);
break;
default:
stolen_size = 0;
break;
}
return stolen_size;
}
static size_t __init gen6_stolen_size(int num, int slot, int func)
{
u16 gmch_ctrl;
gmch_ctrl = read_pci_config_16(num, slot, func, SNB_GMCH_CTRL);
gmch_ctrl >>= SNB_GMCH_GMS_SHIFT;
gmch_ctrl &= SNB_GMCH_GMS_MASK;
return gmch_ctrl << 25;
}
static inline size_t gen8_stolen_size(int num, int slot, int func)
{
u16 gmch_ctrl;
gmch_ctrl = read_pci_config_16(num, slot, func, SNB_GMCH_CTRL);
gmch_ctrl >>= BDW_GMCH_GMS_SHIFT;
gmch_ctrl &= BDW_GMCH_GMS_MASK;
return gmch_ctrl << 25;
}
static void __init intel_graphics_stolen(int num, int slot, int func)
{
size_t size;
int i;
u32 start;
u16 device, subvendor, subdevice;
device = read_pci_config_16(num, slot, func, PCI_DEVICE_ID);
subvendor = read_pci_config_16(num, slot, func,
PCI_SUBSYSTEM_VENDOR_ID);
subdevice = read_pci_config_16(num, slot, func, PCI_SUBSYSTEM_ID);
for (i = 0; i < ARRAY_SIZE(intel_stolen_ids); i++) {
if (intel_stolen_ids[i].device == device) {
stolen_size_fn stolen_size =
(stolen_size_fn)intel_stolen_ids[i].driver_data;
size = stolen_size(num, slot, func);
start = intel_stolen_base(num, slot, func);
if (size && start) {
e820_add_region(start, size, E820_RESERVED);
sanitize_e820_map(e820.map,
ARRAY_SIZE(e820.map),
&e820.nr_map);
}
return;
}
}
}
static int __init check_dev_quirk(int num, int slot, int func)
{
u16 class;
u16 vendor;
u16 device;
u8 type;
int i;
class = read_pci_config_16(num, slot, func, PCI_CLASS_DEVICE);
if (class == 0xffff)
return -1;
vendor = read_pci_config_16(num, slot, func, PCI_VENDOR_ID);
device = read_pci_config_16(num, slot, func, PCI_DEVICE_ID);
for (i = 0; early_qrk[i].f != NULL; i++) {
if (((early_qrk[i].vendor == PCI_ANY_ID) ||
(early_qrk[i].vendor == vendor)) &&
((early_qrk[i].device == PCI_ANY_ID) ||
(early_qrk[i].device == device)) &&
(!((early_qrk[i].class ^ class) &
early_qrk[i].class_mask))) {
if ((early_qrk[i].flags &
QFLAG_DONE) != QFLAG_DONE)
early_qrk[i].f(num, slot, func);
early_qrk[i].flags |= QFLAG_APPLIED;
}
}
type = read_pci_config_byte(num, slot, func,
PCI_HEADER_TYPE);
if (!(type & 0x80))
return -1;
return 0;
}
void __init early_quirks(void)
{
int slot, func;
if (!early_pci_allowed())
return;
for (slot = 0; slot < 32; slot++)
for (func = 0; func < 8; func++) {
if (check_dev_quirk(0, slot, func))
break;
}
}
