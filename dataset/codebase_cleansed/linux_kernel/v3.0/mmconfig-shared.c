static __init void pci_mmconfig_remove(struct pci_mmcfg_region *cfg)
{
if (cfg->res.parent)
release_resource(&cfg->res);
list_del(&cfg->list);
kfree(cfg);
}
static __init void free_all_mmcfg(void)
{
struct pci_mmcfg_region *cfg, *tmp;
pci_mmcfg_arch_free();
list_for_each_entry_safe(cfg, tmp, &pci_mmcfg_list, list)
pci_mmconfig_remove(cfg);
}
static __init void list_add_sorted(struct pci_mmcfg_region *new)
{
struct pci_mmcfg_region *cfg;
list_for_each_entry(cfg, &pci_mmcfg_list, list) {
if (cfg->segment > new->segment ||
(cfg->segment == new->segment &&
cfg->start_bus >= new->start_bus)) {
list_add_tail(&new->list, &cfg->list);
return;
}
}
list_add_tail(&new->list, &pci_mmcfg_list);
}
pci_mmcfg_region *pci_mmconfig_lookup(int segment, int bus)
{
struct pci_mmcfg_region *cfg;
list_for_each_entry(cfg, &pci_mmcfg_list, list)
if (cfg->segment == segment &&
cfg->start_bus <= bus && bus <= cfg->end_bus)
return cfg;
return NULL;
}
static const char __init *pci_mmcfg_e7520(void)
{
u32 win;
raw_pci_ops->read(0, 0, PCI_DEVFN(0, 0), 0xce, 2, &win);
win = win & 0xf000;
if (win == 0x0000 || win == 0xf000)
return NULL;
if (pci_mmconfig_add(0, 0, 255, win << 16) == NULL)
return NULL;
return "Intel Corporation E7520 Memory Controller Hub";
}
static const char __init *pci_mmcfg_intel_945(void)
{
u32 pciexbar, mask = 0, len = 0;
raw_pci_ops->read(0, 0, PCI_DEVFN(0, 0), 0x48, 4, &pciexbar);
if (!(pciexbar & 1))
return NULL;
switch ((pciexbar >> 1) & 3) {
case 0:
mask = 0xf0000000U;
len = 0x10000000U;
break;
case 1:
mask = 0xf8000000U;
len = 0x08000000U;
break;
case 2:
mask = 0xfc000000U;
len = 0x04000000U;
break;
default:
return NULL;
}
if ((pciexbar & mask) & 0x0fffffffU)
return NULL;
if ((pciexbar & mask) >= 0xf0000000U)
return NULL;
if (pci_mmconfig_add(0, 0, (len >> 20) - 1, pciexbar & mask) == NULL)
return NULL;
return "Intel Corporation 945G/GZ/P/PL Express Memory Controller Hub";
}
static const char __init *pci_mmcfg_amd_fam10h(void)
{
u32 low, high, address;
u64 base, msr;
int i;
unsigned segnbits = 0, busnbits, end_bus;
if (!(pci_probe & PCI_CHECK_ENABLE_AMD_MMCONF))
return NULL;
address = MSR_FAM10H_MMIO_CONF_BASE;
if (rdmsr_safe(address, &low, &high))
return NULL;
msr = high;
msr <<= 32;
msr |= low;
if (!(msr & FAM10H_MMIO_CONF_ENABLE))
return NULL;
base = msr & (FAM10H_MMIO_CONF_BASE_MASK<<FAM10H_MMIO_CONF_BASE_SHIFT);
busnbits = (msr >> FAM10H_MMIO_CONF_BUSRANGE_SHIFT) &
FAM10H_MMIO_CONF_BUSRANGE_MASK;
if (!busnbits)
return NULL;
if (busnbits > 8) {
segnbits = busnbits - 8;
busnbits = 8;
}
end_bus = (1 << busnbits) - 1;
for (i = 0; i < (1 << segnbits); i++)
if (pci_mmconfig_add(i, 0, end_bus,
base + (1<<28) * i) == NULL) {
free_all_mmcfg();
return NULL;
}
return "AMD Family 10h NB";
}
static const char __init *pci_mmcfg_nvidia_mcp55(void)
{
int bus;
int mcp55_mmconf_found = 0;
static const u32 extcfg_regnum = 0x90;
static const u32 extcfg_regsize = 4;
static const u32 extcfg_enable_mask = 1<<31;
static const u32 extcfg_start_mask = 0xff<<16;
static const int extcfg_start_shift = 16;
static const u32 extcfg_size_mask = 0x3<<28;
static const int extcfg_size_shift = 28;
static const int extcfg_sizebus[] = {0x100, 0x80, 0x40, 0x20};
static const u32 extcfg_base_mask[] = {0x7ff8, 0x7ffc, 0x7ffe, 0x7fff};
static const int extcfg_base_lshift = 25;
if (!acpi_disabled || !list_empty(&pci_mmcfg_list) || mcp55_checked)
return NULL;
mcp55_checked = true;
for (bus = 0; bus < 256; bus++) {
u64 base;
u32 l, extcfg;
u16 vendor, device;
int start, size_index, end;
raw_pci_ops->read(0, bus, PCI_DEVFN(0, 0), 0, 4, &l);
vendor = l & 0xffff;
device = (l >> 16) & 0xffff;
if (PCI_VENDOR_ID_NVIDIA != vendor || 0x0369 != device)
continue;
raw_pci_ops->read(0, bus, PCI_DEVFN(0, 0), extcfg_regnum,
extcfg_regsize, &extcfg);
if (!(extcfg & extcfg_enable_mask))
continue;
size_index = (extcfg & extcfg_size_mask) >> extcfg_size_shift;
base = extcfg & extcfg_base_mask[size_index];
base <<= extcfg_base_lshift;
start = (extcfg & extcfg_start_mask) >> extcfg_start_shift;
end = start + extcfg_sizebus[size_index] - 1;
if (pci_mmconfig_add(0, start, end, base) == NULL)
continue;
mcp55_mmconf_found++;
}
if (!mcp55_mmconf_found)
return NULL;
return "nVidia MCP55";
}
static void __init pci_mmcfg_check_end_bus_number(void)
{
struct pci_mmcfg_region *cfg, *cfgx;
list_for_each_entry(cfg, &pci_mmcfg_list, list) {
if (cfg->end_bus < cfg->start_bus)
cfg->end_bus = 255;
if (cfg->list.next == &pci_mmcfg_list)
break;
cfgx = list_entry(cfg->list.next, typeof(*cfg), list);
if (cfg->end_bus >= cfgx->start_bus)
cfg->end_bus = cfgx->start_bus - 1;
}
}
static int __init pci_mmcfg_check_hostbridge(void)
{
u32 l;
u32 bus, devfn;
u16 vendor, device;
int i;
const char *name;
if (!raw_pci_ops)
return 0;
free_all_mmcfg();
for (i = 0; i < ARRAY_SIZE(pci_mmcfg_probes); i++) {
bus = pci_mmcfg_probes[i].bus;
devfn = pci_mmcfg_probes[i].devfn;
raw_pci_ops->read(0, bus, devfn, 0, 4, &l);
vendor = l & 0xffff;
device = (l >> 16) & 0xffff;
name = NULL;
if (pci_mmcfg_probes[i].vendor == vendor &&
pci_mmcfg_probes[i].device == device)
name = pci_mmcfg_probes[i].probe();
if (name)
printk(KERN_INFO PREFIX "%s with MMCONFIG support\n",
name);
}
pci_mmcfg_check_end_bus_number();
return !list_empty(&pci_mmcfg_list);
}
static void __init pci_mmcfg_insert_resources(void)
{
struct pci_mmcfg_region *cfg;
list_for_each_entry(cfg, &pci_mmcfg_list, list)
insert_resource(&iomem_resource, &cfg->res);
pci_mmcfg_resources_inserted = 1;
}
static acpi_status __init check_mcfg_resource(struct acpi_resource *res,
void *data)
{
struct resource *mcfg_res = data;
struct acpi_resource_address64 address;
acpi_status status;
if (res->type == ACPI_RESOURCE_TYPE_FIXED_MEMORY32) {
struct acpi_resource_fixed_memory32 *fixmem32 =
&res->data.fixed_memory32;
if (!fixmem32)
return AE_OK;
if ((mcfg_res->start >= fixmem32->address) &&
(mcfg_res->end < (fixmem32->address +
fixmem32->address_length))) {
mcfg_res->flags = 1;
return AE_CTRL_TERMINATE;
}
}
if ((res->type != ACPI_RESOURCE_TYPE_ADDRESS32) &&
(res->type != ACPI_RESOURCE_TYPE_ADDRESS64))
return AE_OK;
status = acpi_resource_to_address64(res, &address);
if (ACPI_FAILURE(status) ||
(address.address_length <= 0) ||
(address.resource_type != ACPI_MEMORY_RANGE))
return AE_OK;
if ((mcfg_res->start >= address.minimum) &&
(mcfg_res->end < (address.minimum + address.address_length))) {
mcfg_res->flags = 1;
return AE_CTRL_TERMINATE;
}
return AE_OK;
}
static acpi_status __init find_mboard_resource(acpi_handle handle, u32 lvl,
void *context, void **rv)
{
struct resource *mcfg_res = context;
acpi_walk_resources(handle, METHOD_NAME__CRS,
check_mcfg_resource, context);
if (mcfg_res->flags)
return AE_CTRL_TERMINATE;
return AE_OK;
}
static int __init is_acpi_reserved(u64 start, u64 end, unsigned not_used)
{
struct resource mcfg_res;
mcfg_res.start = start;
mcfg_res.end = end - 1;
mcfg_res.flags = 0;
acpi_get_devices("PNP0C01", find_mboard_resource, &mcfg_res, NULL);
if (!mcfg_res.flags)
acpi_get_devices("PNP0C02", find_mboard_resource, &mcfg_res,
NULL);
return mcfg_res.flags;
}
static int __init is_mmconf_reserved(check_reserved_t is_reserved,
struct pci_mmcfg_region *cfg, int with_e820)
{
u64 addr = cfg->res.start;
u64 size = resource_size(&cfg->res);
u64 old_size = size;
int valid = 0, num_buses;
while (!is_reserved(addr, addr + size, E820_RESERVED)) {
size >>= 1;
if (size < (16UL<<20))
break;
}
if (size >= (16UL<<20) || size == old_size) {
printk(KERN_INFO PREFIX "MMCONFIG at %pR reserved in %s\n",
&cfg->res,
with_e820 ? "E820" : "ACPI motherboard resources");
valid = 1;
if (old_size != size) {
cfg->end_bus = cfg->start_bus + ((size>>20) - 1);
num_buses = cfg->end_bus - cfg->start_bus + 1;
cfg->res.end = cfg->res.start +
PCI_MMCFG_BUS_OFFSET(num_buses) - 1;
snprintf(cfg->name, PCI_MMCFG_RESOURCE_NAME_LEN,
"PCI MMCONFIG %04x [bus %02x-%02x]",
cfg->segment, cfg->start_bus, cfg->end_bus);
printk(KERN_INFO PREFIX
"MMCONFIG for %04x [bus%02x-%02x] "
"at %pR (base %#lx) (size reduced!)\n",
cfg->segment, cfg->start_bus, cfg->end_bus,
&cfg->res, (unsigned long) cfg->address);
}
}
return valid;
}
static void __init pci_mmcfg_reject_broken(int early)
{
struct pci_mmcfg_region *cfg;
list_for_each_entry(cfg, &pci_mmcfg_list, list) {
int valid = 0;
if (!early && !acpi_disabled) {
valid = is_mmconf_reserved(is_acpi_reserved, cfg, 0);
if (valid)
continue;
else
printk(KERN_ERR FW_BUG PREFIX
"MMCONFIG at %pR not reserved in "
"ACPI motherboard resources\n",
&cfg->res);
}
if (raw_pci_ops)
valid = is_mmconf_reserved(e820_all_mapped, cfg, 1);
if (!valid)
goto reject;
}
return;
reject:
printk(KERN_INFO PREFIX "not using MMCONFIG\n");
free_all_mmcfg();
}
static int __init acpi_mcfg_check_entry(struct acpi_table_mcfg *mcfg,
struct acpi_mcfg_allocation *cfg)
{
int year;
if (cfg->address < 0xFFFFFFFF)
return 0;
if (!strcmp(mcfg->header.oem_id, "SGI"))
return 0;
if (mcfg->header.revision >= 1) {
if (dmi_get_date(DMI_BIOS_DATE, &year, NULL, NULL) &&
year >= 2010)
return 0;
}
printk(KERN_ERR PREFIX "MCFG region for %04x [bus %02x-%02x] at %#llx "
"is above 4GB, ignored\n", cfg->pci_segment,
cfg->start_bus_number, cfg->end_bus_number, cfg->address);
return -EINVAL;
}
static int __init pci_parse_mcfg(struct acpi_table_header *header)
{
struct acpi_table_mcfg *mcfg;
struct acpi_mcfg_allocation *cfg_table, *cfg;
unsigned long i;
int entries;
if (!header)
return -EINVAL;
mcfg = (struct acpi_table_mcfg *)header;
free_all_mmcfg();
entries = 0;
i = header->length - sizeof(struct acpi_table_mcfg);
while (i >= sizeof(struct acpi_mcfg_allocation)) {
entries++;
i -= sizeof(struct acpi_mcfg_allocation);
};
if (entries == 0) {
printk(KERN_ERR PREFIX "MMCONFIG has no entries\n");
return -ENODEV;
}
cfg_table = (struct acpi_mcfg_allocation *) &mcfg[1];
for (i = 0; i < entries; i++) {
cfg = &cfg_table[i];
if (acpi_mcfg_check_entry(mcfg, cfg)) {
free_all_mmcfg();
return -ENODEV;
}
if (pci_mmconfig_add(cfg->pci_segment, cfg->start_bus_number,
cfg->end_bus_number, cfg->address) == NULL) {
printk(KERN_WARNING PREFIX
"no memory for MCFG entries\n");
free_all_mmcfg();
return -ENOMEM;
}
}
return 0;
}
static void __init __pci_mmcfg_init(int early)
{
if ((pci_probe & PCI_PROBE_MMCONF) == 0)
return;
if (!early && !(pci_probe & PCI_PROBE_MASK & ~PCI_PROBE_MMCONF))
return;
if (known_bridge)
return;
if (early) {
if (pci_mmcfg_check_hostbridge())
known_bridge = 1;
}
if (!known_bridge)
acpi_sfi_table_parse(ACPI_SIG_MCFG, pci_parse_mcfg);
pci_mmcfg_reject_broken(early);
if (list_empty(&pci_mmcfg_list))
return;
if (pcibios_last_bus < 0) {
const struct pci_mmcfg_region *cfg;
list_for_each_entry(cfg, &pci_mmcfg_list, list) {
if (cfg->segment)
break;
pcibios_last_bus = cfg->end_bus;
}
}
if (pci_mmcfg_arch_init())
pci_probe = (pci_probe & ~PCI_PROBE_MASK) | PCI_PROBE_MMCONF;
else {
pci_mmcfg_resources_inserted = 1;
}
}
void __init pci_mmcfg_early_init(void)
{
__pci_mmcfg_init(1);
}
void __init pci_mmcfg_late_init(void)
{
__pci_mmcfg_init(0);
}
static int __init pci_mmcfg_late_insert_resources(void)
{
if ((pci_mmcfg_resources_inserted == 1) ||
(pci_probe & PCI_PROBE_MMCONF) == 0 ||
list_empty(&pci_mmcfg_list))
return 1;
pci_mmcfg_insert_resources();
return 0;
}
