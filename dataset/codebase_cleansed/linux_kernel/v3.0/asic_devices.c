static __init int check_forcefamily(unsigned char forced_family[2])
{
const char *p;
forced_family[0] = '\0';
forced_family[1] = '\0';
strncpy(cmdline, arcs_cmdline, COMMAND_LINE_SIZE - 1);
p = strstr(cmdline, FORCEFAMILY_PARAM);
if (p && (p != cmdline) && (*(p - 1) != ' '))
p = strstr(p, " " FORCEFAMILY_PARAM "=");
if (p) {
p += strlen(FORCEFAMILY_PARAM "=");
if (*p == '\0' || *(p + 1) == '\0' ||
(*(p + 2) != '\0' && *(p + 2) != ' '))
pr_err(FORCEFAMILY_PARAM " must be exactly two "
"characters long, ignoring value\n");
else {
forced_family[0] = *p;
forced_family[1] = *(p + 1);
}
}
return 0;
}
static __init noinline void platform_set_family(void)
{
unsigned char forced_family[2];
unsigned short bootldr_family;
if (check_forcefamily(forced_family) == 0)
bootldr_family = BOOTLDRFAMILY(forced_family[0],
forced_family[1]);
else {
#ifdef CONFIG_BOOTLOADER_DRIVER
bootldr_family = (unsigned short) kbldr_GetSWFamily();
#else
#if defined(CONFIG_BOOTLOADER_FAMILY)
bootldr_family = (unsigned short) BOOTLDRFAMILY(
CONFIG_BOOTLOADER_FAMILY[0],
CONFIG_BOOTLOADER_FAMILY[1]);
#else
#error "Unknown Bootloader Family"
#endif
#endif
}
pr_info("Bootloader Family = 0x%04X\n", bootldr_family);
switch (bootldr_family) {
case BOOTLDRFAMILY('R', '1'):
platform_family = FAMILY_1500;
break;
case BOOTLDRFAMILY('4', '4'):
platform_family = FAMILY_4500;
break;
case BOOTLDRFAMILY('4', '6'):
platform_family = FAMILY_4600;
break;
case BOOTLDRFAMILY('A', '1'):
platform_family = FAMILY_4600VZA;
break;
case BOOTLDRFAMILY('8', '5'):
platform_family = FAMILY_8500;
break;
case BOOTLDRFAMILY('R', '2'):
platform_family = FAMILY_8500RNG;
break;
case BOOTLDRFAMILY('8', '6'):
platform_family = FAMILY_8600;
break;
case BOOTLDRFAMILY('B', '1'):
platform_family = FAMILY_8600VZB;
break;
case BOOTLDRFAMILY('E', '1'):
platform_family = FAMILY_1500VZE;
break;
case BOOTLDRFAMILY('F', '1'):
platform_family = FAMILY_1500VZF;
break;
case BOOTLDRFAMILY('8', '7'):
platform_family = FAMILY_8700;
break;
default:
platform_family = -1;
}
}
unsigned int platform_get_family(void)
{
return platform_family;
}
enum asic_type platform_get_asic(void)
{
return asic;
}
static void __init set_register_map(unsigned long phys_base,
const struct register_map *map)
{
asic_phy_base = phys_base;
_asic_register_map = *map;
register_map_virtualize(&_asic_register_map);
asic_base = (unsigned long)ioremap_nocache(phys_base, ASIC_IO_SIZE);
}
void __init configure_platform(void)
{
platform_set_family();
switch (platform_family) {
case FAMILY_1500:
case FAMILY_1500VZE:
case FAMILY_1500VZF:
platform_features = FFS_CAPABLE;
asic = ASIC_CALLIOPE;
set_register_map(CALLIOPE_IO_BASE, &calliope_register_map);
if (platform_family == FAMILY_1500VZE) {
gp_resources = non_dvr_vze_calliope_resources;
pr_info("Platform: 1500/Vz Class E - "
"CALLIOPE, NON_DVR_CAPABLE\n");
} else if (platform_family == FAMILY_1500VZF) {
gp_resources = non_dvr_vzf_calliope_resources;
pr_info("Platform: 1500/Vz Class F - "
"CALLIOPE, NON_DVR_CAPABLE\n");
} else {
gp_resources = non_dvr_calliope_resources;
pr_info("Platform: 1500/RNG100 - CALLIOPE, "
"NON_DVR_CAPABLE\n");
}
break;
case FAMILY_4500:
platform_features = FFS_CAPABLE | PCIE_CAPABLE |
DISPLAY_CAPABLE;
asic = ASIC_ZEUS;
set_register_map(ZEUS_IO_BASE, &zeus_register_map);
gp_resources = non_dvr_zeus_resources;
pr_info("Platform: 4500 - ZEUS, NON_DVR_CAPABLE\n");
break;
case FAMILY_4600:
{
unsigned int chipversion = 0;
platform_features = FFS_CAPABLE | DISPLAY_CAPABLE;
set_register_map(CRONUS_IO_BASE, &cronus_register_map);
chipversion = asic_read(chipver3) << 24;
chipversion |= asic_read(chipver2) << 16;
chipversion |= asic_read(chipver1) << 8;
chipversion |= asic_read(chipver0);
if ((chipversion == CRONUS_10) || (chipversion == CRONUS_11))
asic = ASIC_CRONUS;
else
asic = ASIC_CRONUSLITE;
gp_resources = non_dvr_cronuslite_resources;
pr_info("Platform: 4600 - %s, NON_DVR_CAPABLE, "
"chipversion=0x%08X\n",
(asic == ASIC_CRONUS) ? "CRONUS" : "CRONUS LITE",
chipversion);
break;
}
case FAMILY_4600VZA:
platform_features = FFS_CAPABLE | DISPLAY_CAPABLE;
asic = ASIC_CRONUS;
set_register_map(CRONUS_IO_BASE, &cronus_register_map);
gp_resources = non_dvr_cronus_resources;
pr_info("Platform: Vz Class A - CRONUS, NON_DVR_CAPABLE\n");
break;
case FAMILY_8500:
case FAMILY_8500RNG:
platform_features = DVR_CAPABLE | PCIE_CAPABLE |
DISPLAY_CAPABLE;
asic = ASIC_ZEUS;
set_register_map(ZEUS_IO_BASE, &zeus_register_map);
gp_resources = dvr_zeus_resources;
pr_info("Platform: 8500/RNG200 - ZEUS, DVR_CAPABLE\n");
break;
case FAMILY_8600:
case FAMILY_8600VZB:
platform_features = DVR_CAPABLE | PCIE_CAPABLE |
DISPLAY_CAPABLE;
asic = ASIC_CRONUS;
set_register_map(CRONUS_IO_BASE, &cronus_register_map);
gp_resources = dvr_cronus_resources;
pr_info("Platform: 8600/Vz Class B - CRONUS, "
"DVR_CAPABLE\n");
break;
case FAMILY_8700:
platform_features = FFS_CAPABLE | PCIE_CAPABLE;
asic = ASIC_GAIA;
set_register_map(GAIA_IO_BASE, &gaia_register_map);
gp_resources = dvr_gaia_resources;
pr_info("Platform: 8700 - GAIA, DVR_CAPABLE\n");
break;
default:
pr_crit("Platform: UNKNOWN PLATFORM\n");
break;
}
switch (asic) {
case ASIC_ZEUS:
phys_to_dma_offset = 0x30000000;
break;
case ASIC_CALLIOPE:
phys_to_dma_offset = 0x10000000;
break;
case ASIC_CRONUSLITE:
case ASIC_CRONUS:
phys_to_dma_offset = 0x10000000;
break;
default:
phys_to_dma_offset = 0x00000000;
break;
}
}
void __init platform_alloc_bootmem(void)
{
int i;
int total = 0;
pmem_setup_resource();
for (i = 0; gp_resources[i].flags != 0; i++) {
int size = gp_resources[i].end - gp_resources[i].start + 1;
if ((gp_resources[i].start != 0) &&
((gp_resources[i].flags & IORESOURCE_MEM) != 0)) {
reserve_bootmem(dma_to_phys(gp_resources[i].start),
size, 0);
total += gp_resources[i].end -
gp_resources[i].start + 1;
pr_info("reserve resource %s at %08x (%u bytes)\n",
gp_resources[i].name, gp_resources[i].start,
gp_resources[i].end -
gp_resources[i].start + 1);
}
}
for (i = 0; gp_resources[i].flags != 0; i++) {
int size = gp_resources[i].end - gp_resources[i].start + 1;
if ((gp_resources[i].start == 0) &&
((gp_resources[i].flags & IORESOURCE_MEM) != 0)) {
void *mem = alloc_bootmem_pages(size);
if (mem == NULL)
pr_err("Unable to allocate bootmem pages "
"for %s\n", gp_resources[i].name);
else {
gp_resources[i].start =
phys_to_dma(virt_to_phys(mem));
gp_resources[i].end =
gp_resources[i].start + size - 1;
total += size;
pr_info("allocate resource %s at %08x "
"(%u bytes)\n",
gp_resources[i].name,
gp_resources[i].start, size);
}
}
}
pr_info("Total Platform driver memory allocation: 0x%08x\n", total);
for (i = 0; gp_resources[i].flags != 0; i++) {
if ((gp_resources[i].start != 0) &&
((gp_resources[i].flags & IORESOURCE_IO) != 0)) {
pr_info("reserved platform resource %s at %08x\n",
gp_resources[i].name, gp_resources[i].start);
}
}
}
static int __init early_param_pmemaddr(char *p)
{
pmemaddr = (unsigned long)simple_strtoul(p, NULL, 0);
return 0;
}
static int __init early_param_pmemlen(char *p)
{
#if 0
pmemlen = (unsigned long)simple_strtoul(p, NULL, 0);
#else
pmemlen = 0x20000;
#endif
return 0;
}
static void __init pmem_setup_resource(void)
{
struct resource *resource;
resource = asic_resource_get("DiagPersistentMemory");
if (resource && pmemaddr && pmemlen) {
resource->start = phys_to_dma(pmemaddr - 0x80000000);
resource->end = resource->start + pmemlen - 1;
pr_info("persistent memory: start=0x%x end=0x%x\n",
resource->start, resource->end);
}
}
struct resource *asic_resource_get(const char *name)
{
int i;
for (i = 0; gp_resources[i].flags != 0; i++) {
if (strcmp(gp_resources[i].name, name) == 0)
return &gp_resources[i];
}
return NULL;
}
void platform_release_memory(void *ptr, int size)
{
unsigned long addr;
unsigned long end;
addr = ((unsigned long)ptr + (PAGE_SIZE - 1)) & PAGE_MASK;
end = ((unsigned long)ptr + size) & PAGE_MASK;
for (; addr < end; addr += PAGE_SIZE) {
ClearPageReserved(virt_to_page(__va(addr)));
init_page_count(virt_to_page(__va(addr)));
free_page((unsigned long)__va(addr));
}
}
int platform_supports_dvr(void)
{
return (platform_features & DVR_CAPABLE) != 0;
}
int platform_supports_ffs(void)
{
return (platform_features & FFS_CAPABLE) != 0;
}
int platform_supports_pcie(void)
{
return (platform_features & PCIE_CAPABLE) != 0;
}
int platform_supports_display(void)
{
return (platform_features & DISPLAY_CAPABLE) != 0;
}
