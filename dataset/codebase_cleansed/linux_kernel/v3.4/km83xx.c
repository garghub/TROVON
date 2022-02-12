static void __init mpc83xx_km_setup_arch(void)
{
#ifdef CONFIG_QUICC_ENGINE
struct device_node *np;
#endif
if (ppc_md.progress)
ppc_md.progress("kmpbec83xx_setup_arch()", 0);
mpc83xx_setup_pci();
#ifdef CONFIG_QUICC_ENGINE
qe_reset();
np = of_find_node_by_name(NULL, "par_io");
if (np != NULL) {
par_io_init(np);
of_node_put(np);
for_each_node_by_name(np, "spi")
par_io_of_config(np);
for (np = NULL; (np = of_find_node_by_name(np, "ucc")) != NULL;)
par_io_of_config(np);
}
np = of_find_compatible_node(NULL, "network", "ucc_geth");
if (np != NULL) {
uint svid;
svid = mfspr(SPRN_SVR);
if (SVR_REV(svid) == 0x0021) {
struct device_node *np_par;
struct resource res;
void __iomem *base;
int ret;
np_par = of_find_node_by_name(NULL, "par_io");
if (np_par == NULL) {
printk(KERN_WARNING "%s couldn;t find par_io node\n",
__func__);
return;
}
ret = of_address_to_resource(np_par, 0, &res);
if (ret) {
printk(KERN_WARNING "%s couldn;t map par_io registers\n",
__func__);
return;
}
base = ioremap(res.start, resource_size(&res));
setbits32((base + 0xa8), 0x0c003000);
clrsetbits_be32((base + 0xac), 0xff0, 0xaa0);
iounmap(base);
of_node_put(np_par);
}
of_node_put(np);
}
#endif
}
static int __init mpc83xx_km_probe(void)
{
unsigned long node = of_get_flat_dt_root();
int i = 0;
while (board[i]) {
if (of_flat_dt_is_compatible(node, board[i]))
break;
i++;
}
return (board[i] != NULL);
}
