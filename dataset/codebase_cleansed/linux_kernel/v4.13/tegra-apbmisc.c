u32 tegra_read_chipid(void)
{
return readl_relaxed(apbmisc_base + 4);
}
u8 tegra_get_chip_id(void)
{
if (!apbmisc_base) {
WARN(1, "Tegra Chip ID not yet available\n");
return 0;
}
return (tegra_read_chipid() >> 8) & 0xff;
}
u32 tegra_read_straps(void)
{
if (strapping_base)
return readl_relaxed(strapping_base);
else
return 0;
}
u32 tegra_read_ram_code(void)
{
u32 straps = tegra_read_straps();
if (long_ram_code)
straps &= PMC_STRAPPING_OPT_A_RAM_CODE_MASK_LONG;
else
straps &= PMC_STRAPPING_OPT_A_RAM_CODE_MASK_SHORT;
return straps >> PMC_STRAPPING_OPT_A_RAM_CODE_SHIFT;
}
void __init tegra_init_revision(void)
{
u32 id, chip_id, minor_rev;
int rev;
id = tegra_read_chipid();
chip_id = (id >> 8) & 0xff;
minor_rev = (id >> 16) & 0xf;
switch (minor_rev) {
case 1:
rev = TEGRA_REVISION_A01;
break;
case 2:
rev = TEGRA_REVISION_A02;
break;
case 3:
if (chip_id == TEGRA20 && (tegra_fuse_read_spare(18) ||
tegra_fuse_read_spare(19)))
rev = TEGRA_REVISION_A03p;
else
rev = TEGRA_REVISION_A03;
break;
case 4:
rev = TEGRA_REVISION_A04;
break;
default:
rev = TEGRA_REVISION_UNKNOWN;
}
tegra_sku_info.revision = rev;
tegra_sku_info.sku_id = tegra_fuse_read_early(FUSE_SKU_INFO);
}
void __init tegra_init_apbmisc(void)
{
struct resource apbmisc, straps;
struct device_node *np;
np = of_find_matching_node(NULL, apbmisc_match);
if (!np) {
if (IS_ENABLED(CONFIG_ARM) && soc_is_tegra()) {
apbmisc.start = 0x70000800;
apbmisc.end = 0x70000863;
apbmisc.flags = IORESOURCE_MEM;
if (tegra_get_chip_id() == TEGRA124) {
straps.start = 0x7000e864;
straps.end = 0x7000e867;
} else {
straps.start = 0x70000008;
straps.end = 0x7000000b;
}
straps.flags = IORESOURCE_MEM;
pr_warn("Using APBMISC region %pR\n", &apbmisc);
pr_warn("Using strapping options registers %pR\n",
&straps);
} else {
return;
}
} else {
if (of_address_to_resource(np, 0, &apbmisc) < 0) {
pr_err("failed to get APBMISC registers\n");
return;
}
if (of_address_to_resource(np, 1, &straps) < 0) {
pr_err("failed to get strapping options registers\n");
return;
}
}
apbmisc_base = ioremap_nocache(apbmisc.start, resource_size(&apbmisc));
if (!apbmisc_base)
pr_err("failed to map APBMISC registers\n");
strapping_base = ioremap_nocache(straps.start, resource_size(&straps));
if (!strapping_base)
pr_err("failed to map strapping options registers\n");
long_ram_code = of_property_read_bool(np, "nvidia,long-ram-code");
}
