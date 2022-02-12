static void __init exynos5_dt_map_io(void)
{
unsigned long root = of_get_flat_dt_root();
exynos_init_io(NULL, 0);
if (of_flat_dt_is_compatible(root, "samsung,exynos5250"))
s3c24xx_init_clocks(24000000);
}
static void __init exynos5_dt_machine_init(void)
{
struct device_node *i2c_np;
const char *i2c_compat = "samsung,s3c2440-i2c";
unsigned int tmp;
for_each_compatible_node(i2c_np, NULL, i2c_compat) {
if (of_device_is_available(i2c_np)) {
if (of_alias_get_id(i2c_np, "i2c") < 4) {
tmp = readl(EXYNOS5_SYS_I2C_CFG);
writel(tmp & ~(0x1 << of_alias_get_id(i2c_np, "i2c")),
EXYNOS5_SYS_I2C_CFG);
}
}
}
if (of_machine_is_compatible("samsung,exynos5250"))
of_platform_populate(NULL, of_default_bus_match_table,
exynos5250_auxdata_lookup, NULL);
else if (of_machine_is_compatible("samsung,exynos5440"))
of_platform_populate(NULL, of_default_bus_match_table,
exynos5440_auxdata_lookup, NULL);
}
static void __init exynos5_reserve(void)
{
#ifdef CONFIG_S5P_DEV_MFC
struct s5p_mfc_dt_meminfo mfc_mem;
mfc_mem.compatible = "samsung,mfc-v6";
if (of_scan_flat_dt(s5p_fdt_find_mfc_mem, &mfc_mem))
s5p_mfc_reserve_mem(mfc_mem.roff, mfc_mem.rsize, mfc_mem.loff,
mfc_mem.lsize);
#endif
}
