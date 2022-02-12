void exynos_restart(enum reboot_mode mode, const char *cmd)
{
struct device_node *np;
u32 val = 0x1;
void __iomem *addr = EXYNOS_SWRESET;
if (of_machine_is_compatible("samsung,exynos5440")) {
u32 status;
np = of_find_compatible_node(NULL, NULL, "samsung,exynos5440-clock");
addr = of_iomap(np, 0) + 0xbc;
status = __raw_readl(addr);
addr = of_iomap(np, 0) + 0xcc;
val = __raw_readl(addr);
val = (val & 0xffff0000) | (status & 0xffff);
}
__raw_writel(val, addr);
}
void __init exynos_cpuidle_init(void)
{
platform_device_register(&exynos_cpuidle);
}
void __init exynos_cpufreq_init(void)
{
platform_device_register_simple("exynos-cpufreq", -1, NULL, 0);
}
void __init exynos_init_late(void)
{
if (of_machine_is_compatible("samsung,exynos5440"))
return;
pm_genpd_poweroff_unused();
exynos_pm_init();
}
static int __init exynos_fdt_map_chipid(unsigned long node, const char *uname,
int depth, void *data)
{
struct map_desc iodesc;
__be32 *reg;
unsigned long len;
if (!of_flat_dt_is_compatible(node, "samsung,exynos4210-chipid") &&
!of_flat_dt_is_compatible(node, "samsung,exynos5440-clock"))
return 0;
reg = of_get_flat_dt_prop(node, "reg", &len);
if (reg == NULL || len != (sizeof(unsigned long) * 2))
return 0;
iodesc.pfn = __phys_to_pfn(be32_to_cpu(reg[0]));
iodesc.length = be32_to_cpu(reg[1]) - 1;
iodesc.virtual = (unsigned long)S5P_VA_CHIPID;
iodesc.type = MT_DEVICE;
iotable_init(&iodesc, 1);
return 1;
}
static void __init exynos_map_io(void)
{
if (soc_is_exynos4())
iotable_init(exynos4_iodesc, ARRAY_SIZE(exynos4_iodesc));
if (soc_is_exynos5())
iotable_init(exynos5_iodesc, ARRAY_SIZE(exynos5_iodesc));
if (soc_is_exynos4210()) {
if (samsung_rev() == EXYNOS4210_REV_0)
iotable_init(exynos4_iodesc0,
ARRAY_SIZE(exynos4_iodesc0));
else
iotable_init(exynos4_iodesc1,
ARRAY_SIZE(exynos4_iodesc1));
iotable_init(exynos4210_iodesc, ARRAY_SIZE(exynos4210_iodesc));
}
if (soc_is_exynos4212() || soc_is_exynos4412())
iotable_init(exynos4x12_iodesc, ARRAY_SIZE(exynos4x12_iodesc));
if (soc_is_exynos5250())
iotable_init(exynos5250_iodesc, ARRAY_SIZE(exynos5250_iodesc));
}
void __init exynos_init_io(void)
{
debug_ll_io_init();
of_scan_flat_dt(exynos_fdt_map_chipid, NULL);
s5p_init_cpu(S5P_VA_CHIPID);
exynos_map_io();
}
static int __init exynos_core_init(void)
{
return subsys_system_register(&exynos_subsys, NULL);
}
static int __init exynos4_l2x0_cache_init(void)
{
int ret;
ret = l2x0_of_init(L2_AUX_VAL, L2_AUX_MASK);
if (ret)
return ret;
if (IS_ENABLED(CONFIG_S5P_SLEEP)) {
l2x0_regs_phys = virt_to_phys(&l2x0_saved_regs);
clean_dcache_area(&l2x0_regs_phys, sizeof(unsigned long));
}
return 0;
}
static void __init exynos_dt_machine_init(void)
{
struct device_node *i2c_np;
const char *i2c_compat = "samsung,s3c2440-i2c";
unsigned int tmp;
int id;
if (soc_is_exynos5()) {
for_each_compatible_node(i2c_np, NULL, i2c_compat) {
if (of_device_is_available(i2c_np)) {
id = of_alias_get_id(i2c_np, "i2c");
if (id < 4) {
tmp = readl(EXYNOS5_SYS_I2C_CFG);
writel(tmp & ~(0x1 << id),
EXYNOS5_SYS_I2C_CFG);
}
}
}
}
exynos_cpuidle_init();
exynos_cpufreq_init();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
static void __init exynos_reserve(void)
{
#ifdef CONFIG_S5P_DEV_MFC
int i;
char *mfc_mem[] = {
"samsung,mfc-v5",
"samsung,mfc-v6",
"samsung,mfc-v7",
};
for (i = 0; i < ARRAY_SIZE(mfc_mem); i++)
if (of_scan_flat_dt(s5p_fdt_alloc_mfc_mem, mfc_mem[i]))
break;
#endif
}
