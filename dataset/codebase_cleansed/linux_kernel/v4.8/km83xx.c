static void quirk_mpc8360e_qe_enet10(void)
{
uint svid = mfspr(SPRN_SVR);
struct device_node *np_par;
struct resource res;
void __iomem *base;
int ret;
np_par = of_find_node_by_name(NULL, "par_io");
if (np_par == NULL) {
pr_warn("%s couldn;t find par_io node\n", __func__);
return;
}
ret = of_address_to_resource(np_par, 0, &res);
if (ret) {
pr_warn("%s couldn;t map par_io registers\n", __func__);
return;
}
base = ioremap(res.start, res.end - res.start + 1);
clrsetbits_be32((base + 0xa8), 0x0c00f000, 0x04005000);
clrsetbits_be32((base + 0xac), 0x0000cff0, 0x00004550);
if (SVR_REV(svid) == 0x0021) {
clrsetbits_be32((base + 0xac), 0x000000f0, 0x000000a0);
} else if (SVR_REV(svid) == 0x0020) {
setbits32((base + 0xa8), 0x00003000);
setbits32((base + 0xa8), 0x0c000000);
setbits32((base + 0xac), 0x0000c000);
}
iounmap(base);
of_node_put(np_par);
}
static void __init mpc83xx_km_setup_arch(void)
{
#ifdef CONFIG_QUICC_ENGINE
struct device_node *np;
#endif
if (ppc_md.progress)
ppc_md.progress("kmpbec83xx_setup_arch()", 0);
mpc83xx_setup_pci();
#ifdef CONFIG_QUICC_ENGINE
np = of_find_node_by_name(NULL, "par_io");
if (np != NULL) {
par_io_init(np);
of_node_put(np);
for_each_node_by_name(np, "spi")
par_io_of_config(np);
for_each_node_by_name(np, "ucc")
par_io_of_config(np);
np = of_find_compatible_node(NULL, "network", "ucc_geth");
if (np != NULL) {
quirk_mpc8360e_qe_enet10();
of_node_put(np);
}
}
#endif
}
static int __init mpc83xx_km_probe(void)
{
int i = 0;
while (board[i]) {
if (of_machine_is_compatible(board[i]))
break;
i++;
}
return (board[i] != NULL);
}
