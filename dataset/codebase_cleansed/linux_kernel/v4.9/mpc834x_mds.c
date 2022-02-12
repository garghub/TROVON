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
bcsr_regs = ioremap(res.start, resource_size(&res));
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
mpc83xx_setup_arch();
mpc834xemds_usb_cfg();
}
static int __init mpc834x_mds_probe(void)
{
return of_machine_is_compatible("MPC834xMDS");
}
