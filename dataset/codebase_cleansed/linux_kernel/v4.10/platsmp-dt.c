static void __init realview_smp_prepare_cpus(unsigned int max_cpus)
{
struct device_node *np;
void __iomem *scu_base;
struct regmap *map;
unsigned int ncores;
int i;
np = of_find_matching_node(NULL, realview_scu_match);
if (!np) {
pr_err("PLATSMP: No SCU base address\n");
return;
}
scu_base = of_iomap(np, 0);
of_node_put(np);
if (!scu_base) {
pr_err("PLATSMP: No SCU remap\n");
return;
}
scu_enable(scu_base);
ncores = scu_get_core_count(scu_base);
pr_info("SCU: %d cores detected\n", ncores);
for (i = 0; i < ncores; i++)
set_cpu_possible(i, true);
iounmap(scu_base);
np = of_find_matching_node(NULL, realview_syscon_match);
if (!np) {
pr_err("PLATSMP: No syscon match\n");
return;
}
map = syscon_node_to_regmap(np);
if (IS_ERR(map)) {
pr_err("PLATSMP: No syscon regmap\n");
return;
}
regmap_write(map, REALVIEW_SYS_FLAGSSET_OFFSET,
virt_to_phys(versatile_secondary_startup));
}
