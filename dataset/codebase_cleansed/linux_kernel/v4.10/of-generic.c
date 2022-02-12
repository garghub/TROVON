static void dummy_smp_setup(void)
{
}
static void dummy_prepare_cpus(unsigned int max_cpus)
{
}
static void dummy_start_cpu(unsigned int cpu, unsigned long entry_point)
{
}
static unsigned int dummy_smp_processor_id(void)
{
return 0;
}
static void dummy_send_ipi(unsigned int cpu, unsigned int message)
{
}
static void sh_of_smp_probe(void)
{
struct device_node *np = 0;
const char *method = 0;
const struct of_cpu_method *m = __cpu_method_of_table;
pr_info("SH generic board support: scanning for cpus\n");
init_cpu_possible(cpumask_of(0));
while ((np = of_find_node_by_type(np, "cpu"))) {
const __be32 *cell = of_get_property(np, "reg", NULL);
u64 id = -1;
if (cell) id = of_read_number(cell, of_n_addr_cells(np));
if (id < NR_CPUS) {
if (!method)
of_property_read_string(np, "enable-method", &method);
set_cpu_possible(id, true);
set_cpu_present(id, true);
__cpu_number_map[id] = id;
__cpu_logical_map[id] = id;
}
}
if (!method) {
np = of_find_node_by_name(NULL, "cpus");
of_property_read_string(np, "enable-method", &method);
}
pr_info("CPU enable method: %s\n", method);
if (method)
for (; m->method; m++)
if (!strcmp(m->method, method)) {
register_smp_ops(m->ops);
return;
}
register_smp_ops(&dummy_smp_ops);
}
static void sh_of_smp_probe(void)
{
}
static void noop(void)
{
}
static int noopi(void)
{
return 0;
}
static void __init sh_of_mem_reserve(void)
{
early_init_fdt_reserve_self();
early_init_fdt_scan_reserved_mem();
}
static void __init sh_of_time_init(void)
{
pr_info("SH generic board support: scanning for clocksource devices\n");
clocksource_probe();
}
static void __init sh_of_setup(char **cmdline_p)
{
struct device_node *root;
#ifdef CONFIG_USE_BUILTIN_DTB
unflatten_and_copy_device_tree();
#else
unflatten_device_tree();
#endif
board_time_init = sh_of_time_init;
sh_mv.mv_name = "Unknown SH model";
root = of_find_node_by_path("/");
if (root) {
of_property_read_string(root, "model", &sh_mv.mv_name);
of_node_put(root);
}
sh_of_smp_probe();
}
static int sh_of_irq_demux(int irq)
{
return irq;
}
static void __init sh_of_init_irq(void)
{
pr_info("SH generic board support: scanning for interrupt controllers\n");
irqchip_init();
}
static int __init sh_of_clk_init(void)
{
#ifdef CONFIG_COMMON_CLK
pr_info("SH generic board support: scanning for clk providers\n");
of_clk_init(NULL);
#endif
return 0;
}
void __init arch_init_clk_ops(struct sh_clk_ops **ops, int idx)
{
}
void __init plat_irq_setup(void)
{
}
