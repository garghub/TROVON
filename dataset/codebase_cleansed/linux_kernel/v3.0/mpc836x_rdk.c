static int __init mpc836x_rdk_declare_of_platform_devices(void)
{
return of_platform_bus_probe(NULL, mpc836x_rdk_ids, NULL);
}
static void __init mpc836x_rdk_setup_arch(void)
{
#ifdef CONFIG_PCI
struct device_node *np;
#endif
if (ppc_md.progress)
ppc_md.progress("mpc836x_rdk_setup_arch()", 0);
#ifdef CONFIG_PCI
for_each_compatible_node(np, "pci", "fsl,mpc8349-pci")
mpc83xx_add_bridge(np);
#endif
#ifdef CONFIG_QUICC_ENGINE
qe_reset();
#endif
}
static void __init mpc836x_rdk_init_IRQ(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "fsl,ipic");
if (!np)
return;
ipic_init(np, 0);
ipic_set_default_priority();
of_node_put(np);
#ifdef CONFIG_QUICC_ENGINE
np = of_find_compatible_node(NULL, NULL, "fsl,qe-ic");
if (!np)
return;
qe_ic_init(np, 0, qe_ic_cascade_low_ipic, qe_ic_cascade_high_ipic);
of_node_put(np);
#endif
}
static int __init mpc836x_rdk_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "fsl,mpc8360rdk");
}
