void __init exynos_sysram_init(void)
{
struct device_node *node;
for_each_compatible_node(node, NULL, "samsung,exynos4210-sysram") {
if (!of_device_is_available(node))
continue;
sysram_base_addr = of_iomap(node, 0);
break;
}
for_each_compatible_node(node, NULL, "samsung,exynos4210-sysram-ns") {
if (!of_device_is_available(node))
continue;
sysram_ns_base_addr = of_iomap(node, 0);
break;
}
}
static void __init exynos_init_late(void)
{
if (of_machine_is_compatible("samsung,exynos5440"))
return;
exynos_pm_init();
}
static int __init exynos_fdt_map_chipid(unsigned long node, const char *uname,
int depth, void *data)
{
struct map_desc iodesc;
const __be32 *reg;
int len;
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
}
static void __init exynos_init_io(void)
{
debug_ll_io_init();
of_scan_flat_dt(exynos_fdt_map_chipid, NULL);
s5p_init_cpu(S5P_VA_CHIPID);
exynos_map_io();
}
void exynos_set_delayed_reset_assertion(bool enable)
{
if (of_machine_is_compatible("samsung,exynos4")) {
unsigned int tmp, core_id;
for (core_id = 0; core_id < num_possible_cpus(); core_id++) {
tmp = pmu_raw_readl(EXYNOS_ARM_CORE_OPTION(core_id));
if (enable)
tmp |= S5P_USE_DELAYED_RESET_ASSERTION;
else
tmp &= ~(S5P_USE_DELAYED_RESET_ASSERTION);
pmu_raw_writel(tmp, EXYNOS_ARM_CORE_OPTION(core_id));
}
}
}
static void exynos_map_pmu(void)
{
struct device_node *np;
np = of_find_matching_node(NULL, exynos_dt_pmu_match);
if (np)
pmu_base_addr = of_iomap(np, 0);
}
static void __init exynos_init_irq(void)
{
irqchip_init();
exynos_map_pmu();
}
static void __init exynos_dt_machine_init(void)
{
if (!IS_ENABLED(CONFIG_SMP))
exynos_sysram_init();
#if defined(CONFIG_SMP) && defined(CONFIG_ARM_EXYNOS_CPUIDLE)
if (of_machine_is_compatible("samsung,exynos4210") ||
of_machine_is_compatible("samsung,exynos3250"))
exynos_cpuidle.dev.platform_data = &cpuidle_coupled_exynos_data;
#endif
if (of_machine_is_compatible("samsung,exynos4210") ||
of_machine_is_compatible("samsung,exynos4212") ||
(of_machine_is_compatible("samsung,exynos4412") &&
of_machine_is_compatible("samsung,trats2")) ||
of_machine_is_compatible("samsung,exynos3250") ||
of_machine_is_compatible("samsung,exynos5250"))
platform_device_register(&exynos_cpuidle);
}
static void __init exynos_dt_fixup(void)
{
of_fdt_limit_memory(8);
}
