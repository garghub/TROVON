char *__init __acpi_map_table(unsigned long phys, unsigned long size)
{
if (!phys || !size)
return NULL;
return early_ioremap(phys, size);
}
void __init __acpi_unmap_table(char *map, unsigned long size)
{
if (!map || !size)
return;
early_iounmap(map, size);
}
static int __init acpi_parse_madt(struct acpi_table_header *table)
{
struct acpi_table_madt *madt = NULL;
if (!boot_cpu_has(X86_FEATURE_APIC))
return -EINVAL;
madt = (struct acpi_table_madt *)table;
if (!madt) {
printk(KERN_WARNING PREFIX "Unable to map MADT\n");
return -ENODEV;
}
if (madt->address) {
acpi_lapic_addr = (u64) madt->address;
printk(KERN_DEBUG PREFIX "Local APIC address 0x%08x\n",
madt->address);
}
default_acpi_madt_oem_check(madt->header.oem_id,
madt->header.oem_table_id);
return 0;
}
static int acpi_register_lapic(int id, u32 acpiid, u8 enabled)
{
unsigned int ver = 0;
int cpu;
if (id >= MAX_LOCAL_APIC) {
printk(KERN_INFO PREFIX "skipped apicid that is too big\n");
return -EINVAL;
}
if (!enabled) {
++disabled_cpus;
return -EINVAL;
}
if (boot_cpu_physical_apicid != -1U)
ver = boot_cpu_apic_version;
cpu = generic_processor_info(id, ver);
if (cpu >= 0)
early_per_cpu(x86_cpu_to_acpiid, cpu) = acpiid;
return cpu;
}
static int __init
acpi_parse_x2apic(struct acpi_subtable_header *header, const unsigned long end)
{
struct acpi_madt_local_x2apic *processor = NULL;
int apic_id;
u8 enabled;
processor = (struct acpi_madt_local_x2apic *)header;
if (BAD_MADT_ENTRY(processor, end))
return -EINVAL;
acpi_table_print_madt_entry(header);
apic_id = processor->local_apic_id;
enabled = processor->lapic_flags & ACPI_MADT_ENABLED;
#ifdef CONFIG_X86_X2APIC
if (!apic->apic_id_valid(apic_id) && enabled)
printk(KERN_WARNING PREFIX "x2apic entry ignored\n");
else
acpi_register_lapic(apic_id, processor->uid, enabled);
#else
printk(KERN_WARNING PREFIX "x2apic entry ignored\n");
#endif
return 0;
}
static int __init
acpi_parse_lapic(struct acpi_subtable_header * header, const unsigned long end)
{
struct acpi_madt_local_apic *processor = NULL;
processor = (struct acpi_madt_local_apic *)header;
if (BAD_MADT_ENTRY(processor, end))
return -EINVAL;
acpi_table_print_madt_entry(header);
if (processor->id == 0xff)
return 0;
acpi_register_lapic(processor->id,
processor->processor_id,
processor->lapic_flags & ACPI_MADT_ENABLED);
return 0;
}
static int __init
acpi_parse_sapic(struct acpi_subtable_header *header, const unsigned long end)
{
struct acpi_madt_local_sapic *processor = NULL;
processor = (struct acpi_madt_local_sapic *)header;
if (BAD_MADT_ENTRY(processor, end))
return -EINVAL;
acpi_table_print_madt_entry(header);
acpi_register_lapic((processor->id << 8) | processor->eid,
processor->processor_id,
processor->lapic_flags & ACPI_MADT_ENABLED);
return 0;
}
static int __init
acpi_parse_lapic_addr_ovr(struct acpi_subtable_header * header,
const unsigned long end)
{
struct acpi_madt_local_apic_override *lapic_addr_ovr = NULL;
lapic_addr_ovr = (struct acpi_madt_local_apic_override *)header;
if (BAD_MADT_ENTRY(lapic_addr_ovr, end))
return -EINVAL;
acpi_table_print_madt_entry(header);
acpi_lapic_addr = lapic_addr_ovr->address;
return 0;
}
static int __init
acpi_parse_x2apic_nmi(struct acpi_subtable_header *header,
const unsigned long end)
{
struct acpi_madt_local_x2apic_nmi *x2apic_nmi = NULL;
x2apic_nmi = (struct acpi_madt_local_x2apic_nmi *)header;
if (BAD_MADT_ENTRY(x2apic_nmi, end))
return -EINVAL;
acpi_table_print_madt_entry(header);
if (x2apic_nmi->lint != 1)
printk(KERN_WARNING PREFIX "NMI not connected to LINT 1!\n");
return 0;
}
static int __init
acpi_parse_lapic_nmi(struct acpi_subtable_header * header, const unsigned long end)
{
struct acpi_madt_local_apic_nmi *lapic_nmi = NULL;
lapic_nmi = (struct acpi_madt_local_apic_nmi *)header;
if (BAD_MADT_ENTRY(lapic_nmi, end))
return -EINVAL;
acpi_table_print_madt_entry(header);
if (lapic_nmi->lint != 1)
printk(KERN_WARNING PREFIX "NMI not connected to LINT 1!\n");
return 0;
}
static void __init mp_override_legacy_irq(u8 bus_irq, u8 polarity, u8 trigger,
u32 gsi)
{
int ioapic;
int pin;
struct mpc_intsrc mp_irq;
if (bus_irq >= NR_IRQS_LEGACY) {
pr_warn("Invalid bus_irq %u for legacy override\n", bus_irq);
return;
}
ioapic = mp_find_ioapic(gsi);
if (ioapic < 0)
return;
pin = mp_find_ioapic_pin(ioapic, gsi);
if ((bus_irq == 0) && (trigger == 3))
trigger = 1;
mp_irq.type = MP_INTSRC;
mp_irq.irqtype = mp_INT;
mp_irq.irqflag = (trigger << 2) | polarity;
mp_irq.srcbus = MP_ISA_BUS;
mp_irq.srcbusirq = bus_irq;
mp_irq.dstapic = mpc_ioapic_id(ioapic);
mp_irq.dstirq = pin;
mp_save_irq(&mp_irq);
if (gsi < nr_legacy_irqs() && isa_irq_to_gsi[gsi] == gsi)
isa_irq_to_gsi[gsi] = ACPI_INVALID_GSI;
isa_irq_to_gsi[bus_irq] = gsi;
}
static int mp_config_acpi_gsi(struct device *dev, u32 gsi, int trigger,
int polarity)
{
#ifdef CONFIG_X86_MPPARSE
struct mpc_intsrc mp_irq;
struct pci_dev *pdev;
unsigned char number;
unsigned int devfn;
int ioapic;
u8 pin;
if (!acpi_ioapic)
return 0;
if (!dev || !dev_is_pci(dev))
return 0;
pdev = to_pci_dev(dev);
number = pdev->bus->number;
devfn = pdev->devfn;
pin = pdev->pin;
mp_irq.type = MP_INTSRC;
mp_irq.irqtype = mp_INT;
mp_irq.irqflag = (trigger == ACPI_EDGE_SENSITIVE ? 4 : 0x0c) |
(polarity == ACPI_ACTIVE_HIGH ? 1 : 3);
mp_irq.srcbus = number;
mp_irq.srcbusirq = (((devfn >> 3) & 0x1f) << 2) | ((pin - 1) & 3);
ioapic = mp_find_ioapic(gsi);
mp_irq.dstapic = mpc_ioapic_id(ioapic);
mp_irq.dstirq = mp_find_ioapic_pin(ioapic, gsi);
mp_save_irq(&mp_irq);
#endif
return 0;
}
static int __init
acpi_parse_ioapic(struct acpi_subtable_header * header, const unsigned long end)
{
struct acpi_madt_io_apic *ioapic = NULL;
struct ioapic_domain_cfg cfg = {
.type = IOAPIC_DOMAIN_DYNAMIC,
.ops = &mp_ioapic_irqdomain_ops,
};
ioapic = (struct acpi_madt_io_apic *)header;
if (BAD_MADT_ENTRY(ioapic, end))
return -EINVAL;
acpi_table_print_madt_entry(header);
if (ioapic->global_irq_base < nr_legacy_irqs())
cfg.type = IOAPIC_DOMAIN_LEGACY;
mp_register_ioapic(ioapic->id, ioapic->address, ioapic->global_irq_base,
&cfg);
return 0;
}
static void __init acpi_sci_ioapic_setup(u8 bus_irq, u16 polarity, u16 trigger, u32 gsi)
{
if (trigger == 0)
trigger = 3;
if (polarity == 0)
polarity = 3;
if (acpi_sci_flags & ACPI_MADT_TRIGGER_MASK)
trigger = (acpi_sci_flags & ACPI_MADT_TRIGGER_MASK) >> 2;
if (acpi_sci_flags & ACPI_MADT_POLARITY_MASK)
polarity = acpi_sci_flags & ACPI_MADT_POLARITY_MASK;
mp_override_legacy_irq(bus_irq, polarity, trigger, gsi);
acpi_penalize_sci_irq(bus_irq, trigger, polarity);
acpi_sci_override_gsi = gsi;
return;
}
static int __init
acpi_parse_int_src_ovr(struct acpi_subtable_header * header,
const unsigned long end)
{
struct acpi_madt_interrupt_override *intsrc = NULL;
intsrc = (struct acpi_madt_interrupt_override *)header;
if (BAD_MADT_ENTRY(intsrc, end))
return -EINVAL;
acpi_table_print_madt_entry(header);
if (intsrc->source_irq == acpi_gbl_FADT.sci_interrupt) {
acpi_sci_ioapic_setup(intsrc->source_irq,
intsrc->inti_flags & ACPI_MADT_POLARITY_MASK,
(intsrc->inti_flags & ACPI_MADT_TRIGGER_MASK) >> 2,
intsrc->global_irq);
return 0;
}
if (intsrc->source_irq == 0) {
if (acpi_skip_timer_override) {
printk(PREFIX "BIOS IRQ0 override ignored.\n");
return 0;
}
if ((intsrc->global_irq == 2) && acpi_fix_pin2_polarity
&& (intsrc->inti_flags & ACPI_MADT_POLARITY_MASK)) {
intsrc->inti_flags &= ~ACPI_MADT_POLARITY_MASK;
printk(PREFIX "BIOS IRQ0 pin2 override: forcing polarity to high active.\n");
}
}
mp_override_legacy_irq(intsrc->source_irq,
intsrc->inti_flags & ACPI_MADT_POLARITY_MASK,
(intsrc->inti_flags & ACPI_MADT_TRIGGER_MASK) >> 2,
intsrc->global_irq);
return 0;
}
static int __init
acpi_parse_nmi_src(struct acpi_subtable_header * header, const unsigned long end)
{
struct acpi_madt_nmi_source *nmi_src = NULL;
nmi_src = (struct acpi_madt_nmi_source *)header;
if (BAD_MADT_ENTRY(nmi_src, end))
return -EINVAL;
acpi_table_print_madt_entry(header);
return 0;
}
void __init acpi_pic_sci_set_trigger(unsigned int irq, u16 trigger)
{
unsigned int mask = 1 << irq;
unsigned int old, new;
old = inb(0x4d0) | (inb(0x4d1) << 8);
new = acpi_noirq ? old : 0;
switch (trigger) {
case 1:
new &= ~mask;
break;
case 3:
new |= mask;
break;
}
if (old == new)
return;
printk(PREFIX "setting ELCR to %04x (from %04x)\n", new, old);
outb(new, 0x4d0);
outb(new >> 8, 0x4d1);
}
int acpi_gsi_to_irq(u32 gsi, unsigned int *irqp)
{
int rc, irq, trigger, polarity;
if (acpi_irq_model == ACPI_IRQ_MODEL_PIC) {
*irqp = gsi;
return 0;
}
rc = acpi_get_override_irq(gsi, &trigger, &polarity);
if (rc == 0) {
trigger = trigger ? ACPI_LEVEL_SENSITIVE : ACPI_EDGE_SENSITIVE;
polarity = polarity ? ACPI_ACTIVE_LOW : ACPI_ACTIVE_HIGH;
irq = acpi_register_gsi(NULL, gsi, trigger, polarity);
if (irq >= 0) {
*irqp = irq;
return 0;
}
}
return -1;
}
int acpi_isa_irq_to_gsi(unsigned isa_irq, u32 *gsi)
{
if (isa_irq < nr_legacy_irqs() &&
isa_irq_to_gsi[isa_irq] != ACPI_INVALID_GSI) {
*gsi = isa_irq_to_gsi[isa_irq];
return 0;
}
return -1;
}
static int acpi_register_gsi_pic(struct device *dev, u32 gsi,
int trigger, int polarity)
{
#ifdef CONFIG_PCI
if (trigger == ACPI_LEVEL_SENSITIVE)
elcr_set_level_irq(gsi);
#endif
return gsi;
}
static int acpi_register_gsi_ioapic(struct device *dev, u32 gsi,
int trigger, int polarity)
{
int irq = gsi;
#ifdef CONFIG_X86_IO_APIC
int node;
struct irq_alloc_info info;
node = dev ? dev_to_node(dev) : NUMA_NO_NODE;
trigger = trigger == ACPI_EDGE_SENSITIVE ? 0 : 1;
polarity = polarity == ACPI_ACTIVE_HIGH ? 0 : 1;
ioapic_set_alloc_attr(&info, node, trigger, polarity);
mutex_lock(&acpi_ioapic_lock);
irq = mp_map_gsi_to_irq(gsi, IOAPIC_MAP_ALLOC, &info);
if (irq >= 0 && enable_update_mptable &&
acpi_gbl_FADT.sci_interrupt != gsi)
mp_config_acpi_gsi(dev, gsi, trigger, polarity);
mutex_unlock(&acpi_ioapic_lock);
#endif
return irq;
}
static void acpi_unregister_gsi_ioapic(u32 gsi)
{
#ifdef CONFIG_X86_IO_APIC
int irq;
mutex_lock(&acpi_ioapic_lock);
irq = mp_map_gsi_to_irq(gsi, 0, NULL);
if (irq > 0)
mp_unmap_irq(irq);
mutex_unlock(&acpi_ioapic_lock);
#endif
}
int acpi_register_gsi(struct device *dev, u32 gsi, int trigger, int polarity)
{
return __acpi_register_gsi(dev, gsi, trigger, polarity);
}
void acpi_unregister_gsi(u32 gsi)
{
if (__acpi_unregister_gsi)
__acpi_unregister_gsi(gsi);
}
static void __init acpi_set_irq_model_ioapic(void)
{
acpi_irq_model = ACPI_IRQ_MODEL_IOAPIC;
__acpi_register_gsi = acpi_register_gsi_ioapic;
__acpi_unregister_gsi = acpi_unregister_gsi_ioapic;
acpi_ioapic = 1;
}
static int acpi_map_cpu2node(acpi_handle handle, int cpu, int physid)
{
#ifdef CONFIG_ACPI_NUMA
int nid;
nid = acpi_get_node(handle);
if (nid != NUMA_NO_NODE) {
set_apicid_to_node(physid, nid);
numa_set_node(cpu, nid);
}
#endif
return 0;
}
int acpi_map_cpu(acpi_handle handle, phys_cpuid_t physid, u32 acpi_id,
int *pcpu)
{
int cpu;
cpu = acpi_register_lapic(physid, acpi_id, ACPI_MADT_ENABLED);
if (cpu < 0) {
pr_info(PREFIX "Unable to map lapic to logical cpu number\n");
return cpu;
}
acpi_processor_set_pdc(handle);
acpi_map_cpu2node(handle, cpu, physid);
*pcpu = cpu;
return 0;
}
int acpi_unmap_cpu(int cpu)
{
#ifdef CONFIG_ACPI_NUMA
set_apicid_to_node(per_cpu(x86_cpu_to_apicid, cpu), NUMA_NO_NODE);
#endif
per_cpu(x86_cpu_to_apicid, cpu) = -1;
set_cpu_present(cpu, false);
num_processors--;
return (0);
}
int acpi_register_ioapic(acpi_handle handle, u64 phys_addr, u32 gsi_base)
{
int ret = -ENOSYS;
#ifdef CONFIG_ACPI_HOTPLUG_IOAPIC
int ioapic_id;
u64 addr;
struct ioapic_domain_cfg cfg = {
.type = IOAPIC_DOMAIN_DYNAMIC,
.ops = &mp_ioapic_irqdomain_ops,
};
ioapic_id = acpi_get_ioapic_id(handle, gsi_base, &addr);
if (ioapic_id < 0) {
unsigned long long uid;
acpi_status status;
status = acpi_evaluate_integer(handle, METHOD_NAME__UID,
NULL, &uid);
if (ACPI_FAILURE(status)) {
acpi_handle_warn(handle, "failed to get IOAPIC ID.\n");
return -EINVAL;
}
ioapic_id = (int)uid;
}
mutex_lock(&acpi_ioapic_lock);
ret = mp_register_ioapic(ioapic_id, phys_addr, gsi_base, &cfg);
mutex_unlock(&acpi_ioapic_lock);
#endif
return ret;
}
int acpi_unregister_ioapic(acpi_handle handle, u32 gsi_base)
{
int ret = -ENOSYS;
#ifdef CONFIG_ACPI_HOTPLUG_IOAPIC
mutex_lock(&acpi_ioapic_lock);
ret = mp_unregister_ioapic(gsi_base);
mutex_unlock(&acpi_ioapic_lock);
#endif
return ret;
}
int acpi_ioapic_registered(acpi_handle handle, u32 gsi_base)
{
int ret = 0;
#ifdef CONFIG_ACPI_HOTPLUG_IOAPIC
mutex_lock(&acpi_ioapic_lock);
ret = mp_ioapic_registered(gsi_base);
mutex_unlock(&acpi_ioapic_lock);
#endif
return ret;
}
static int __init acpi_parse_sbf(struct acpi_table_header *table)
{
struct acpi_table_boot *sb = (struct acpi_table_boot *)table;
sbf_port = sb->cmos_index;
return 0;
}
static int __init acpi_parse_hpet(struct acpi_table_header *table)
{
struct acpi_table_hpet *hpet_tbl = (struct acpi_table_hpet *)table;
if (hpet_tbl->address.space_id != ACPI_SPACE_MEM) {
printk(KERN_WARNING PREFIX "HPET timers must be located in "
"memory.\n");
return -1;
}
hpet_address = hpet_tbl->address.address;
hpet_blockid = hpet_tbl->sequence;
if (!hpet_address) {
printk(KERN_WARNING PREFIX
"HPET id: %#x base: %#lx is invalid\n",
hpet_tbl->id, hpet_address);
return 0;
}
#ifdef CONFIG_X86_64
if (hpet_address == 0xfed0000000000000UL) {
if (!hpet_force_user) {
printk(KERN_WARNING PREFIX "HPET id: %#x "
"base: 0xfed0000000000000 is bogus\n "
"try hpet=force on the kernel command line to "
"fix it up to 0xfed00000.\n", hpet_tbl->id);
hpet_address = 0;
return 0;
}
printk(KERN_WARNING PREFIX
"HPET id: %#x base: 0xfed0000000000000 fixed up "
"to 0xfed00000.\n", hpet_tbl->id);
hpet_address >>= 32;
}
#endif
printk(KERN_INFO PREFIX "HPET id: %#x base: %#lx\n",
hpet_tbl->id, hpet_address);
#define HPET_RESOURCE_NAME_SIZE 9
hpet_res = alloc_bootmem(sizeof(*hpet_res) + HPET_RESOURCE_NAME_SIZE);
hpet_res->name = (void *)&hpet_res[1];
hpet_res->flags = IORESOURCE_MEM;
snprintf((char *)hpet_res->name, HPET_RESOURCE_NAME_SIZE, "HPET %u",
hpet_tbl->sequence);
hpet_res->start = hpet_address;
hpet_res->end = hpet_address + (1 * 1024) - 1;
return 0;
}
static __init int hpet_insert_resource(void)
{
if (!hpet_res)
return 1;
return insert_resource(&iomem_resource, hpet_res);
}
static int __init acpi_parse_fadt(struct acpi_table_header *table)
{
if (!(acpi_gbl_FADT.boot_flags & ACPI_FADT_LEGACY_DEVICES)) {
pr_debug("ACPI: no legacy devices present\n");
x86_platform.legacy.devices.pnpbios = 0;
}
if (acpi_gbl_FADT.header.revision >= FADT2_REVISION_ID &&
!(acpi_gbl_FADT.boot_flags & ACPI_FADT_8042) &&
x86_platform.legacy.i8042 != X86_LEGACY_I8042_PLATFORM_ABSENT) {
pr_debug("ACPI: i8042 controller is absent\n");
x86_platform.legacy.i8042 = X86_LEGACY_I8042_FIRMWARE_ABSENT;
}
if (acpi_gbl_FADT.boot_flags & ACPI_FADT_NO_CMOS_RTC) {
pr_debug("ACPI: not registering RTC platform device\n");
x86_platform.legacy.rtc = 0;
}
#ifdef CONFIG_X86_PM_TIMER
if (acpi_gbl_FADT.header.revision >= FADT2_REVISION_ID) {
if (acpi_gbl_FADT.xpm_timer_block.space_id !=
ACPI_ADR_SPACE_SYSTEM_IO)
return 0;
pmtmr_ioport = acpi_gbl_FADT.xpm_timer_block.address;
if (!pmtmr_ioport)
pmtmr_ioport = acpi_gbl_FADT.pm_timer_block;
} else {
pmtmr_ioport = acpi_gbl_FADT.pm_timer_block;
}
if (pmtmr_ioport)
printk(KERN_INFO PREFIX "PM-Timer IO Port: %#x\n",
pmtmr_ioport);
#endif
return 0;
}
static int __init early_acpi_parse_madt_lapic_addr_ovr(void)
{
int count;
if (!boot_cpu_has(X86_FEATURE_APIC))
return -ENODEV;
count = acpi_table_parse_madt(ACPI_MADT_TYPE_LOCAL_APIC_OVERRIDE,
acpi_parse_lapic_addr_ovr, 0);
if (count < 0) {
printk(KERN_ERR PREFIX
"Error parsing LAPIC address override entry\n");
return count;
}
register_lapic_address(acpi_lapic_addr);
return count;
}
static int __init acpi_parse_madt_lapic_entries(void)
{
int count;
int x2count = 0;
int ret;
struct acpi_subtable_proc madt_proc[2];
if (!boot_cpu_has(X86_FEATURE_APIC))
return -ENODEV;
count = acpi_table_parse_madt(ACPI_MADT_TYPE_LOCAL_SAPIC,
acpi_parse_sapic, MAX_LOCAL_APIC);
if (!count) {
memset(madt_proc, 0, sizeof(madt_proc));
madt_proc[0].id = ACPI_MADT_TYPE_LOCAL_APIC;
madt_proc[0].handler = acpi_parse_lapic;
madt_proc[1].id = ACPI_MADT_TYPE_LOCAL_X2APIC;
madt_proc[1].handler = acpi_parse_x2apic;
ret = acpi_table_parse_entries_array(ACPI_SIG_MADT,
sizeof(struct acpi_table_madt),
madt_proc, ARRAY_SIZE(madt_proc), MAX_LOCAL_APIC);
if (ret < 0) {
printk(KERN_ERR PREFIX
"Error parsing LAPIC/X2APIC entries\n");
return ret;
}
count = madt_proc[0].count;
x2count = madt_proc[1].count;
}
if (!count && !x2count) {
printk(KERN_ERR PREFIX "No LAPIC entries present\n");
return -ENODEV;
} else if (count < 0 || x2count < 0) {
printk(KERN_ERR PREFIX "Error parsing LAPIC entry\n");
return count;
}
x2count = acpi_table_parse_madt(ACPI_MADT_TYPE_LOCAL_X2APIC_NMI,
acpi_parse_x2apic_nmi, 0);
count = acpi_table_parse_madt(ACPI_MADT_TYPE_LOCAL_APIC_NMI,
acpi_parse_lapic_nmi, 0);
if (count < 0 || x2count < 0) {
printk(KERN_ERR PREFIX "Error parsing LAPIC NMI entry\n");
return count;
}
return 0;
}
static void __init mp_config_acpi_legacy_irqs(void)
{
int i;
struct mpc_intsrc mp_irq;
#ifdef CONFIG_EISA
mp_bus_id_to_type[MP_ISA_BUS] = MP_BUS_ISA;
#endif
set_bit(MP_ISA_BUS, mp_bus_not_pci);
pr_debug("Bus #%d is ISA\n", MP_ISA_BUS);
for (i = 0; i < nr_legacy_irqs(); i++) {
int ioapic, pin;
unsigned int dstapic;
int idx;
u32 gsi;
if (acpi_isa_irq_to_gsi(i, &gsi))
continue;
ioapic = mp_find_ioapic(gsi);
if (ioapic < 0)
continue;
pin = mp_find_ioapic_pin(ioapic, gsi);
dstapic = mpc_ioapic_id(ioapic);
for (idx = 0; idx < mp_irq_entries; idx++) {
struct mpc_intsrc *irq = mp_irqs + idx;
if (irq->srcbus == MP_ISA_BUS && irq->srcbusirq == i)
break;
if (irq->dstapic == dstapic && irq->dstirq == pin)
break;
}
if (idx != mp_irq_entries) {
printk(KERN_DEBUG "ACPI: IRQ%d used by override.\n", i);
continue;
}
mp_irq.type = MP_INTSRC;
mp_irq.irqflag = 0;
mp_irq.srcbus = MP_ISA_BUS;
mp_irq.dstapic = dstapic;
mp_irq.irqtype = mp_INT;
mp_irq.srcbusirq = i;
mp_irq.dstirq = pin;
mp_save_irq(&mp_irq);
}
}
static int __init acpi_parse_madt_ioapic_entries(void)
{
int count;
if (acpi_disabled || acpi_noirq)
return -ENODEV;
if (!boot_cpu_has(X86_FEATURE_APIC))
return -ENODEV;
if (skip_ioapic_setup) {
printk(KERN_INFO PREFIX "Skipping IOAPIC probe "
"due to 'noapic' option.\n");
return -ENODEV;
}
count = acpi_table_parse_madt(ACPI_MADT_TYPE_IO_APIC, acpi_parse_ioapic,
MAX_IO_APICS);
if (!count) {
printk(KERN_ERR PREFIX "No IOAPIC entries present\n");
return -ENODEV;
} else if (count < 0) {
printk(KERN_ERR PREFIX "Error parsing IOAPIC entry\n");
return count;
}
count = acpi_table_parse_madt(ACPI_MADT_TYPE_INTERRUPT_OVERRIDE,
acpi_parse_int_src_ovr, nr_irqs);
if (count < 0) {
printk(KERN_ERR PREFIX
"Error parsing interrupt source overrides entry\n");
return count;
}
if (!acpi_sci_override_gsi)
acpi_sci_ioapic_setup(acpi_gbl_FADT.sci_interrupt, 0, 0,
acpi_gbl_FADT.sci_interrupt);
mp_config_acpi_legacy_irqs();
count = acpi_table_parse_madt(ACPI_MADT_TYPE_NMI_SOURCE,
acpi_parse_nmi_src, nr_irqs);
if (count < 0) {
printk(KERN_ERR PREFIX "Error parsing NMI SRC entry\n");
return count;
}
return 0;
}
static inline int acpi_parse_madt_ioapic_entries(void)
{
return -1;
}
static void __init early_acpi_process_madt(void)
{
#ifdef CONFIG_X86_LOCAL_APIC
int error;
if (!acpi_table_parse(ACPI_SIG_MADT, acpi_parse_madt)) {
error = early_acpi_parse_madt_lapic_addr_ovr();
if (!error) {
acpi_lapic = 1;
smp_found_config = 1;
}
if (error == -EINVAL) {
printk(KERN_ERR PREFIX
"Invalid BIOS MADT, disabling ACPI\n");
disable_acpi();
}
}
#endif
}
static void __init acpi_process_madt(void)
{
#ifdef CONFIG_X86_LOCAL_APIC
int error;
if (!acpi_table_parse(ACPI_SIG_MADT, acpi_parse_madt)) {
error = acpi_parse_madt_lapic_entries();
if (!error) {
acpi_lapic = 1;
mutex_lock(&acpi_ioapic_lock);
error = acpi_parse_madt_ioapic_entries();
mutex_unlock(&acpi_ioapic_lock);
if (!error) {
acpi_set_irq_model_ioapic();
smp_found_config = 1;
}
}
if (error == -EINVAL) {
printk(KERN_ERR PREFIX
"Invalid BIOS MADT, disabling ACPI\n");
disable_acpi();
}
} else {
if (smp_found_config) {
printk(KERN_WARNING PREFIX
"No APIC-table, disabling MPS\n");
smp_found_config = 0;
}
}
if (acpi_lapic && acpi_ioapic)
printk(KERN_INFO "Using ACPI (MADT) for SMP configuration "
"information\n");
else if (acpi_lapic)
printk(KERN_INFO "Using ACPI for processor (LAPIC) "
"configuration information\n");
#endif
return;
}
static int __init disable_acpi_irq(const struct dmi_system_id *d)
{
if (!acpi_force) {
printk(KERN_NOTICE "%s detected: force use of acpi=noirq\n",
d->ident);
acpi_noirq_set();
}
return 0;
}
static int __init disable_acpi_pci(const struct dmi_system_id *d)
{
if (!acpi_force) {
printk(KERN_NOTICE "%s detected: force use of pci=noacpi\n",
d->ident);
acpi_disable_pci();
}
return 0;
}
static int __init dmi_disable_acpi(const struct dmi_system_id *d)
{
if (!acpi_force) {
printk(KERN_NOTICE "%s detected: acpi off\n", d->ident);
disable_acpi();
} else {
printk(KERN_NOTICE
"Warning: DMI blacklist says broken, but acpi forced\n");
}
return 0;
}
static int __init dmi_ignore_irq0_timer_override(const struct dmi_system_id *d)
{
if (!acpi_skip_timer_override) {
pr_notice("%s detected: Ignoring BIOS IRQ0 override\n",
d->ident);
acpi_skip_timer_override = 1;
}
return 0;
}
static void __init acpi_reduced_hw_init(void)
{
if (acpi_gbl_reduced_hardware) {
x86_init.timers.timer_init = x86_init_noop;
x86_init.irqs.pre_vector_init = x86_init_noop;
legacy_pic = &null_legacy_pic;
}
}
void __init acpi_boot_table_init(void)
{
dmi_check_system(acpi_dmi_table);
if (acpi_disabled)
return;
if (acpi_table_init()) {
disable_acpi();
return;
}
acpi_table_parse(ACPI_SIG_BOOT, acpi_parse_sbf);
if (acpi_blacklisted()) {
if (acpi_force) {
printk(KERN_WARNING PREFIX "acpi=force override\n");
} else {
printk(KERN_WARNING PREFIX "Disabling ACPI support\n");
disable_acpi();
return;
}
}
}
int __init early_acpi_boot_init(void)
{
if (acpi_disabled)
return 1;
early_acpi_process_madt();
acpi_reduced_hw_init();
return 0;
}
int __init acpi_boot_init(void)
{
dmi_check_system(acpi_dmi_table_late);
if (acpi_disabled)
return 1;
acpi_table_parse(ACPI_SIG_BOOT, acpi_parse_sbf);
acpi_table_parse(ACPI_SIG_FADT, acpi_parse_fadt);
acpi_process_madt();
acpi_table_parse(ACPI_SIG_HPET, acpi_parse_hpet);
if (IS_ENABLED(CONFIG_ACPI_BGRT))
acpi_table_parse(ACPI_SIG_BGRT, acpi_parse_bgrt);
if (!acpi_noirq)
x86_init.pci.init = pci_acpi_init;
return 0;
}
static int __init parse_acpi(char *arg)
{
if (!arg)
return -EINVAL;
if (strcmp(arg, "off") == 0) {
disable_acpi();
}
else if (strcmp(arg, "force") == 0) {
acpi_force = 1;
acpi_disabled = 0;
}
else if (strcmp(arg, "strict") == 0) {
acpi_strict = 1;
}
else if (strcmp(arg, "rsdt") == 0) {
acpi_gbl_do_not_use_xsdt = TRUE;
}
else if (strcmp(arg, "noirq") == 0) {
acpi_noirq_set();
}
else if (strcmp(arg, "copy_dsdt") == 0) {
acpi_gbl_copy_dsdt_locally = 1;
}
else if (strcmp(arg, "nocmcff") == 0) {
acpi_disable_cmcff = 1;
} else {
return -EINVAL;
}
return 0;
}
static int __init parse_pci(char *arg)
{
if (arg && strcmp(arg, "noacpi") == 0)
acpi_disable_pci();
return 0;
}
int __init acpi_mps_check(void)
{
#if defined(CONFIG_X86_LOCAL_APIC) && !defined(CONFIG_X86_MPPARSE)
if (acpi_disabled || acpi_noirq) {
printk(KERN_WARNING "MPS support code is not built-in.\n"
"Using acpi=off or acpi=noirq or pci=noacpi "
"may have problem\n");
return 1;
}
#endif
return 0;
}
static int __init parse_acpi_skip_timer_override(char *arg)
{
acpi_skip_timer_override = 1;
return 0;
}
static int __init parse_acpi_use_timer_override(char *arg)
{
acpi_use_timer_override = 1;
return 0;
}
static int __init setup_acpi_sci(char *s)
{
if (!s)
return -EINVAL;
if (!strcmp(s, "edge"))
acpi_sci_flags = ACPI_MADT_TRIGGER_EDGE |
(acpi_sci_flags & ~ACPI_MADT_TRIGGER_MASK);
else if (!strcmp(s, "level"))
acpi_sci_flags = ACPI_MADT_TRIGGER_LEVEL |
(acpi_sci_flags & ~ACPI_MADT_TRIGGER_MASK);
else if (!strcmp(s, "high"))
acpi_sci_flags = ACPI_MADT_POLARITY_ACTIVE_HIGH |
(acpi_sci_flags & ~ACPI_MADT_POLARITY_MASK);
else if (!strcmp(s, "low"))
acpi_sci_flags = ACPI_MADT_POLARITY_ACTIVE_LOW |
(acpi_sci_flags & ~ACPI_MADT_POLARITY_MASK);
else
return -EINVAL;
return 0;
}
int __acpi_acquire_global_lock(unsigned int *lock)
{
unsigned int old, new, val;
do {
old = *lock;
new = (((old & ~0x3) + 2) + ((old >> 1) & 0x1));
val = cmpxchg(lock, old, new);
} while (unlikely (val != old));
return (new < 3) ? -1 : 0;
}
int __acpi_release_global_lock(unsigned int *lock)
{
unsigned int old, new, val;
do {
old = *lock;
new = old & ~0x3;
val = cmpxchg(lock, old, new);
} while (unlikely (val != old));
return old & 0x1;
}
void __init arch_reserve_mem_area(acpi_physical_address addr, size_t size)
{
e820__range_add(addr, size, E820_TYPE_ACPI);
e820__update_table_print();
}
