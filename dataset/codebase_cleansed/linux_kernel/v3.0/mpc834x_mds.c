static int mpc834xemds_usb_cfg(void)
{
struct device_node *np;
void __iomem *bcsr_regs = NULL;
u8 bcsr5;
mpc834x_usb_cfg();
np = of_find_node_by_name(NULL, "bcsr");
if (np) {
struct resource res;
of_address_to_resource(np, 0, &res);
bcsr_regs = ioremap(res.start, res.end - res.start + 1);
of_node_put(np);
}
if (!bcsr_regs)
return -1;
bcsr5 = in_8(bcsr_regs + 5);
if (!(bcsr5 & BCSR5_INT_USB))
out_8(bcsr_regs + 5, (bcsr5 | BCSR5_INT_USB));
iounmap(bcsr_regs);
return 0;
}
static void __init mpc834x_mds_setup_arch(void)
{
#ifdef CONFIG_PCI
struct device_node *np;
#endif
if (ppc_md.progress)
ppc_md.progress("mpc834x_mds_setup_arch()", 0);
#ifdef CONFIG_PCI
for_each_compatible_node(np, "pci", "fsl,mpc8349-pci")
mpc83xx_add_bridge(np);
#endif
mpc834xemds_usb_cfg();
}
static void __init mpc834x_mds_init_IRQ(void)
{
struct device_node *np;
np = of_find_node_by_type(NULL, "ipic");
if (!np)
return;
ipic_init(np, 0);
ipic_set_default_priority();
}
static int __init mpc834x_declare_of_platform_devices(void)
{
of_platform_bus_probe(NULL, mpc834x_ids, NULL);
return 0;
}
static int __init mpc834x_mds_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "MPC834xMDS");
}
