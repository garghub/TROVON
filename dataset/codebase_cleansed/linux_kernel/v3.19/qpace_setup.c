static void qpace_show_cpuinfo(struct seq_file *m)
{
struct device_node *root;
const char *model = "";
root = of_find_node_by_path("/");
if (root)
model = of_get_property(root, "model", NULL);
seq_printf(m, "machine\t\t: CHRP %s\n", model);
of_node_put(root);
}
static void qpace_progress(char *s, unsigned short hex)
{
printk("*** %04x : %s\n", hex, s ? s : "");
}
static int __init qpace_publish_devices(void)
{
int node;
of_platform_bus_probe(NULL, qpace_bus_ids, NULL);
for_each_online_node(node) {
if (cbe_get_cpu_mic_tm_regs(cbe_node_to_cpu(node)) == NULL)
continue;
platform_device_register_simple("cbe-mic", node, NULL, 0);
}
return 0;
}
static void __init qpace_setup_arch(void)
{
#ifdef CONFIG_SPU_BASE
spu_priv1_ops = &spu_priv1_mmio_ops;
spu_management_ops = &spu_management_of_ops;
#endif
cbe_regs_init();
#ifdef CONFIG_CBE_RAS
cbe_ras_init();
#endif
#ifdef CONFIG_SMP
smp_init_cell();
#endif
loops_per_jiffy = 50000000;
cbe_pervasive_init();
#ifdef CONFIG_DUMMY_CONSOLE
conswitchp = &dummy_con;
#endif
}
static int __init qpace_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (!of_flat_dt_is_compatible(root, "IBM,QPACE"))
return 0;
hpte_init_native();
pm_power_off = rtas_power_off;
return 1;
}
