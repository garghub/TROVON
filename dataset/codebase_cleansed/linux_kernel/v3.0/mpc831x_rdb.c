static void __init mpc831x_rdb_setup_arch(void)
{
#ifdef CONFIG_PCI
struct device_node *np;
#endif
if (ppc_md.progress)
ppc_md.progress("mpc831x_rdb_setup_arch()", 0);
#ifdef CONFIG_PCI
for_each_compatible_node(np, "pci", "fsl,mpc8349-pci")
mpc83xx_add_bridge(np);
for_each_compatible_node(np, "pci", "fsl,mpc8314-pcie")
mpc83xx_add_bridge(np);
#endif
mpc831x_usb_cfg();
}
static void __init mpc831x_rdb_init_IRQ(void)
{
struct device_node *np;
np = of_find_node_by_type(NULL, "ipic");
if (!np)
return;
ipic_init(np, 0);
ipic_set_default_priority();
}
static int __init mpc831x_rdb_probe(void)
{
return of_flat_dt_match(of_get_flat_dt_root(), board);
}
static int __init declare_of_platform_devices(void)
{
of_platform_bus_probe(NULL, of_bus_ids, NULL);
return 0;
}
