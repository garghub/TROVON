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
#ifdef CONFIG_PCI
for_each_compatible_node(np, "pci", "fsl,mpc8349-pci")
mpc83xx_add_bridge(np);
#endif
#ifdef CONFIG_QUICC_ENGINE
qe_reset();
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
static int __init mpc832x_declare_of_platform_devices(void)
{
of_platform_bus_probe(NULL, mpc832x_ids, NULL);
return 0;
}
static void __init mpc832x_sys_init_IRQ(void)
{
struct device_node *np;
np = of_find_node_by_type(NULL, "ipic");
if (!np)
return;
ipic_init(np, 0);
ipic_set_default_priority();
of_node_put(np);
#ifdef CONFIG_QUICC_ENGINE
np = of_find_compatible_node(NULL, NULL, "fsl,qe-ic");
if (!np) {
np = of_find_node_by_type(NULL, "qeic");
if (!np)
return;
}
qe_ic_init(np, 0, qe_ic_cascade_low_ipic, qe_ic_cascade_high_ipic);
of_node_put(np);
#endif
}
static int __init mpc832x_sys_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "MPC832xMDS");
}
