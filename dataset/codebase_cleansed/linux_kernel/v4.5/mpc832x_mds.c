static void __init mpc832x_sys_setup_arch(void)
{
struct device_node *np;
u8 __iomem *bcsr_regs = NULL;
if (ppc_md.progress)
ppc_md.progress("mpc832x_sys_setup_arch()", 0);
np = of_find_node_by_name(NULL, "bcsr");
if (np) {
struct resource res;
of_address_to_resource(np, 0, &res);
bcsr_regs = ioremap(res.start, resource_size(&res));
of_node_put(np);
}
mpc83xx_setup_pci();
#ifdef CONFIG_QUICC_ENGINE
if ((np = of_find_node_by_name(NULL, "par_io")) != NULL) {
par_io_init(np);
of_node_put(np);
for (np = NULL; (np = of_find_node_by_name(np, "ucc")) != NULL;)
par_io_of_config(np);
}
if ((np = of_find_compatible_node(NULL, "network", "ucc_geth"))
!= NULL){
#define BCSR8_FETH_RST 0x50
clrbits8(&bcsr_regs[8], BCSR8_FETH_RST);
udelay(1000);
setbits8(&bcsr_regs[8], BCSR8_FETH_RST);
iounmap(bcsr_regs);
of_node_put(np);
}
#endif
}
static int __init mpc832x_sys_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "MPC832xMDS");
}
