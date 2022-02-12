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
exynos_cpuidle_init();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
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
