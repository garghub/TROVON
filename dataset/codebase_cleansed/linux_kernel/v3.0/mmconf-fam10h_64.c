static int __cpuinit cmp_range(const void *x1, const void *x2)
{
const struct range *r1 = x1;
const struct range *r2 = x2;
int start1, start2;
start1 = r1->start >> 32;
start2 = r2->start >> 32;
return start1 - start2;
}
static void __cpuinit get_fam10h_pci_mmconf_base(void)
{
int i;
unsigned bus;
unsigned slot;
int found;
u64 val;
u32 address;
u64 tom2;
u64 base = FAM10H_PCI_MMCONF_BASE;
int hi_mmio_num;
struct range range[8];
if (fam10h_pci_mmconf_base)
return;
if (!early_pci_allowed())
return;
found = 0;
for (i = 0; i < ARRAY_SIZE(pci_probes); i++) {
u32 id;
u16 device;
u16 vendor;
bus = pci_probes[i].bus;
slot = pci_probes[i].slot;
id = read_pci_config(bus, slot, 0, PCI_VENDOR_ID);
vendor = id & 0xffff;
device = (id>>16) & 0xffff;
if (pci_probes[i].vendor == vendor &&
pci_probes[i].device == device) {
found = 1;
break;
}
}
if (!found)
return;
address = MSR_K8_SYSCFG;
rdmsrl(address, val);
if (!(val & (1<<21))) {
tom2 = 1ULL << 32;
} else {
address = MSR_K8_TOP_MEM2;
rdmsrl(address, val);
tom2 = max(val & 0xffffff800000ULL, 1ULL << 32);
}
if (base <= tom2)
base = (tom2 + 2 * MMCONF_UNIT - 1) & MMCONF_MASK;
hi_mmio_num = 0;
for (i = 0; i < 8; i++) {
u32 reg;
u64 start;
u64 end;
reg = read_pci_config(bus, slot, 1, 0x80 + (i << 3));
if (!(reg & 3))
continue;
start = (u64)(reg & 0xffffff00) << 8;
reg = read_pci_config(bus, slot, 1, 0x84 + (i << 3));
end = ((u64)(reg & 0xffffff00) << 8) | 0xffff;
if (end < tom2)
continue;
range[hi_mmio_num].start = start;
range[hi_mmio_num].end = end;
hi_mmio_num++;
}
if (!hi_mmio_num)
goto out;
sort(range, hi_mmio_num, sizeof(struct range), cmp_range, NULL);
if (range[hi_mmio_num - 1].end < base)
goto out;
if (range[0].start > base + MMCONF_SIZE)
goto out;
base = (range[0].start & MMCONF_MASK) - MMCONF_UNIT;
if ((base > tom2) && BASE_VALID(base))
goto out;
base = (range[hi_mmio_num - 1].end + MMCONF_UNIT) & MMCONF_MASK;
if (BASE_VALID(base))
goto out;
for (i = 1; i < hi_mmio_num; i++) {
base = (range[i - 1].end + MMCONF_UNIT) & MMCONF_MASK;
val = range[i].start & MMCONF_MASK;
if (val >= base + MMCONF_SIZE && BASE_VALID(base))
goto out;
}
return;
out:
fam10h_pci_mmconf_base = base;
}
void __cpuinit fam10h_check_enable_mmcfg(void)
{
u64 val;
u32 address;
if (!(pci_probe & PCI_CHECK_ENABLE_AMD_MMCONF))
return;
address = MSR_FAM10H_MMIO_CONF_BASE;
rdmsrl(address, val);
if (val & FAM10H_MMIO_CONF_ENABLE) {
unsigned busnbits;
busnbits = (val >> FAM10H_MMIO_CONF_BUSRANGE_SHIFT) &
FAM10H_MMIO_CONF_BUSRANGE_MASK;
if (!acpi_pci_disabled || busnbits >= 8) {
u64 base = val & MMCONF_MASK;
if (!fam10h_pci_mmconf_base) {
fam10h_pci_mmconf_base = base;
return;
} else if (fam10h_pci_mmconf_base == base)
return;
}
}
get_fam10h_pci_mmconf_base();
if (!fam10h_pci_mmconf_base) {
pci_probe &= ~PCI_CHECK_ENABLE_AMD_MMCONF;
return;
}
printk(KERN_INFO "Enable MMCONFIG on AMD Family 10h\n");
val &= ~((FAM10H_MMIO_CONF_BASE_MASK<<FAM10H_MMIO_CONF_BASE_SHIFT) |
(FAM10H_MMIO_CONF_BUSRANGE_MASK<<FAM10H_MMIO_CONF_BUSRANGE_SHIFT));
val |= fam10h_pci_mmconf_base | (8 << FAM10H_MMIO_CONF_BUSRANGE_SHIFT) |
FAM10H_MMIO_CONF_ENABLE;
wrmsrl(address, val);
}
static int __init set_check_enable_amd_mmconf(const struct dmi_system_id *d)
{
pci_probe |= PCI_CHECK_ENABLE_AMD_MMCONF;
return 0;
}
void __ref check_enable_amd_mmconf_dmi(void)
{
dmi_check_system(mmconf_dmi_table);
}
