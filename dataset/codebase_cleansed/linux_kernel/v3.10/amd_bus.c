static struct pci_root_info __init *find_pci_root_info(int node, int link)
{
struct pci_root_info *info;
list_for_each_entry(info, &pci_root_infos, list)
if (info->node == node && info->link == link)
return info;
return NULL;
}
static void __init set_mp_bus_range_to_node(int min_bus, int max_bus, int node)
{
#ifdef CONFIG_NUMA
int j;
for (j = min_bus; j <= max_bus; j++)
set_mp_bus_to_node(j, node);
#endif
}
static int __init early_fill_mp_bus_info(void)
{
int i;
unsigned bus;
unsigned slot;
int node;
int link;
int def_node;
int def_link;
struct pci_root_info *info;
u32 reg;
u64 start;
u64 end;
struct range range[RANGE_NUM];
u64 val;
u32 address;
bool found;
struct resource fam10h_mmconf_res, *fam10h_mmconf;
u64 fam10h_mmconf_start;
u64 fam10h_mmconf_end;
if (!early_pci_allowed())
return -1;
found = false;
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
found = true;
break;
}
}
if (!found)
return 0;
for (i = 0; i < 4; i++) {
int min_bus;
int max_bus;
reg = read_pci_config(bus, slot, 1, 0xe0 + (i << 2));
if ((reg & 7) != 3)
continue;
min_bus = (reg >> 16) & 0xff;
max_bus = (reg >> 24) & 0xff;
node = (reg >> 4) & 0x07;
set_mp_bus_range_to_node(min_bus, max_bus, node);
link = (reg >> 8) & 0x03;
info = alloc_pci_root_info(min_bus, max_bus, node, link);
}
reg = read_pci_config(bus, slot, 0, 0x60);
def_node = (reg >> 8) & 0x07;
reg = read_pci_config(bus, slot, 0, 0x64);
def_link = (reg >> 8) & 0x03;
memset(range, 0, sizeof(range));
add_range(range, RANGE_NUM, 0, 0, 0xffff + 1);
for (i = 0; i < 4; i++) {
reg = read_pci_config(bus, slot, 1, 0xc0 + (i << 3));
if (!(reg & 3))
continue;
start = reg & 0xfff000;
reg = read_pci_config(bus, slot, 1, 0xc4 + (i << 3));
node = reg & 0x07;
link = (reg >> 4) & 0x03;
end = (reg & 0xfff000) | 0xfff;
info = find_pci_root_info(node, link);
if (!info)
continue;
printk(KERN_DEBUG "node %d link %d: io port [%llx, %llx]\n",
node, link, start, end);
if (end > 0xffff)
end = 0xffff;
update_res(info, start, end, IORESOURCE_IO, 1);
subtract_range(range, RANGE_NUM, start, end + 1);
}
info = find_pci_root_info(def_node, def_link);
if (info) {
for (i = 0; i < RANGE_NUM; i++) {
if (!range[i].end)
continue;
update_res(info, range[i].start, range[i].end - 1,
IORESOURCE_IO, 1);
}
}
memset(range, 0, sizeof(range));
end = cap_resource((0xfdULL<<32) - 1);
end++;
add_range(range, RANGE_NUM, 0, 0, end);
address = MSR_K8_TOP_MEM1;
rdmsrl(address, val);
end = (val & 0xffffff800000ULL);
printk(KERN_INFO "TOM: %016llx aka %lldM\n", end, end>>20);
if (end < (1ULL<<32))
subtract_range(range, RANGE_NUM, 0, end);
fam10h_mmconf = amd_get_mmconfig_range(&fam10h_mmconf_res);
if (fam10h_mmconf) {
printk(KERN_DEBUG "Fam 10h mmconf %pR\n", fam10h_mmconf);
fam10h_mmconf_start = fam10h_mmconf->start;
fam10h_mmconf_end = fam10h_mmconf->end;
subtract_range(range, RANGE_NUM, fam10h_mmconf_start,
fam10h_mmconf_end + 1);
} else {
fam10h_mmconf_start = 0;
fam10h_mmconf_end = 0;
}
for (i = 0; i < 8; i++) {
reg = read_pci_config(bus, slot, 1, 0x80 + (i << 3));
if (!(reg & 3))
continue;
start = reg & 0xffffff00;
start <<= 8;
reg = read_pci_config(bus, slot, 1, 0x84 + (i << 3));
node = reg & 0x07;
link = (reg >> 4) & 0x03;
end = (reg & 0xffffff00);
end <<= 8;
end |= 0xffff;
info = find_pci_root_info(node, link);
if (!info)
continue;
printk(KERN_DEBUG "node %d link %d: mmio [%llx, %llx]",
node, link, start, end);
if (fam10h_mmconf_end) {
int changed = 0;
u64 endx = 0;
if (start >= fam10h_mmconf_start &&
start <= fam10h_mmconf_end) {
start = fam10h_mmconf_end + 1;
changed = 1;
}
if (end >= fam10h_mmconf_start &&
end <= fam10h_mmconf_end) {
end = fam10h_mmconf_start - 1;
changed = 1;
}
if (start < fam10h_mmconf_start &&
end > fam10h_mmconf_end) {
endx = fam10h_mmconf_start - 1;
update_res(info, start, endx, IORESOURCE_MEM, 0);
subtract_range(range, RANGE_NUM, start,
endx + 1);
printk(KERN_CONT " ==> [%llx, %llx]", start, endx);
start = fam10h_mmconf_end + 1;
changed = 1;
}
if (changed) {
if (start <= end) {
printk(KERN_CONT " %s [%llx, %llx]", endx ? "and" : "==>", start, end);
} else {
printk(KERN_CONT "%s\n", endx?"":" ==> none");
continue;
}
}
}
update_res(info, cap_resource(start), cap_resource(end),
IORESOURCE_MEM, 1);
subtract_range(range, RANGE_NUM, start, end + 1);
printk(KERN_CONT "\n");
}
address = MSR_K8_SYSCFG;
rdmsrl(address, val);
if (val & (1<<21)) {
address = MSR_K8_TOP_MEM2;
rdmsrl(address, val);
end = (val & 0xffffff800000ULL);
printk(KERN_INFO "TOM2: %016llx aka %lldM\n", end, end>>20);
subtract_range(range, RANGE_NUM, 1ULL<<32, end);
}
info = find_pci_root_info(def_node, def_link);
if (info) {
for (i = 0; i < RANGE_NUM; i++) {
if (!range[i].end)
continue;
update_res(info, cap_resource(range[i].start),
cap_resource(range[i].end - 1),
IORESOURCE_MEM, 1);
}
}
list_for_each_entry(info, &pci_root_infos, list) {
int busnum;
struct pci_root_res *root_res;
busnum = info->busn.start;
printk(KERN_DEBUG "bus: %pR on node %x link %x\n",
&info->busn, info->node, info->link);
list_for_each_entry(root_res, &info->resources, list)
printk(KERN_DEBUG "bus: %02x %pR\n",
busnum, &root_res->res);
}
return 0;
}
static void __cpuinit enable_pci_io_ecs(void *unused)
{
u64 reg;
rdmsrl(MSR_AMD64_NB_CFG, reg);
if (!(reg & ENABLE_CF8_EXT_CFG)) {
reg |= ENABLE_CF8_EXT_CFG;
wrmsrl(MSR_AMD64_NB_CFG, reg);
}
}
static int __cpuinit amd_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
int cpu = (long)hcpu;
switch (action) {
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
smp_call_function_single(cpu, enable_pci_io_ecs, NULL, 0);
break;
default:
break;
}
return NOTIFY_OK;
}
static void __init pci_enable_pci_io_ecs(void)
{
#ifdef CONFIG_AMD_NB
unsigned int i, n;
for (n = i = 0; !n && amd_nb_bus_dev_ranges[i].dev_limit; ++i) {
u8 bus = amd_nb_bus_dev_ranges[i].bus;
u8 slot = amd_nb_bus_dev_ranges[i].dev_base;
u8 limit = amd_nb_bus_dev_ranges[i].dev_limit;
for (; slot < limit; ++slot) {
u32 val = read_pci_config(bus, slot, 3, 0);
if (!early_is_amd_nb(val))
continue;
val = read_pci_config(bus, slot, 3, 0x8c);
if (!(val & (ENABLE_CF8_EXT_CFG >> 32))) {
val |= ENABLE_CF8_EXT_CFG >> 32;
write_pci_config(bus, slot, 3, 0x8c, val);
}
++n;
}
}
#endif
}
static int __init pci_io_ecs_init(void)
{
int cpu;
if (boot_cpu_data.x86 < 0x10)
return 0;
if (early_pci_allowed())
pci_enable_pci_io_ecs();
register_cpu_notifier(&amd_cpu_notifier);
for_each_online_cpu(cpu)
amd_cpu_notify(&amd_cpu_notifier, (unsigned long)CPU_ONLINE,
(void *)(long)cpu);
pci_probe |= PCI_HAS_IO_ECS;
return 0;
}
static int __init amd_postcore_init(void)
{
if (boot_cpu_data.x86_vendor != X86_VENDOR_AMD)
return 0;
early_fill_mp_bus_info();
pci_io_ecs_init();
return 0;
}
