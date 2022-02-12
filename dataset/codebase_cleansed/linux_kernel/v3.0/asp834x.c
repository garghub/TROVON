static void __init asp834x_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("asp834x_setup_arch()", 0);
mpc834x_usb_cfg();
}
static void __init asp834x_init_IRQ(void)
{
struct device_node *np;
np = of_find_node_by_type(NULL, "ipic");
if (!np)
return;
ipic_init(np, 0);
of_node_put(np);
ipic_set_default_priority();
}
static int __init asp8347_declare_of_platform_devices(void)
{
of_platform_bus_probe(NULL, asp8347_ids, NULL);
return 0;
}
static int __init asp834x_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "analogue-and-micro,asp8347e");
}
