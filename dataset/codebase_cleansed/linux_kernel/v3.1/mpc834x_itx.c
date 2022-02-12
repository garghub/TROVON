static int __init mpc834x_itx_declare_of_platform_devices(void)
{
return of_platform_bus_probe(NULL, mpc834x_itx_ids, NULL);
}
static void __init mpc834x_itx_setup_arch(void)
{
#ifdef CONFIG_PCI
struct device_node *np;
#endif
if (ppc_md.progress)
ppc_md.progress("mpc834x_itx_setup_arch()", 0);
#ifdef CONFIG_PCI
for_each_compatible_node(np, "pci", "fsl,mpc8349-pci")
mpc83xx_add_bridge(np);
#endif
mpc834x_usb_cfg();
}
static void __init mpc834x_itx_init_IRQ(void)
{
struct device_node *np;
np = of_find_node_by_type(NULL, "ipic");
if (!np)
return;
ipic_init(np, 0);
ipic_set_default_priority();
}
static int __init mpc834x_itx_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "MPC834xMITX");
}
