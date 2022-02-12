static void __init exynos4_dt_machine_init(void)
{
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
static void __init exynos4_reserve(void)
{
#ifdef CONFIG_S5P_DEV_MFC
struct s5p_mfc_dt_meminfo mfc_mem;
mfc_mem.compatible = "samsung,mfc-v5";
if (of_scan_flat_dt(s5p_fdt_find_mfc_mem, &mfc_mem))
s5p_mfc_reserve_mem(mfc_mem.roff, mfc_mem.rsize, mfc_mem.loff,
mfc_mem.lsize);
#endif
}
