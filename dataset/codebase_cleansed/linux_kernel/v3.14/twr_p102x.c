static void __init twr_p1025_pic_init(void)
{
struct mpic *mpic;
#ifdef CONFIG_QUICC_ENGINE
struct device_node *np;
#endif
mpic = mpic_alloc(NULL, 0, MPIC_BIG_ENDIAN |
MPIC_SINGLE_DEST_CPU,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
#ifdef CONFIG_QUICC_ENGINE
np = of_find_compatible_node(NULL, NULL, "fsl,qe-ic");
if (np) {
qe_ic_init(np, 0, qe_ic_cascade_low_mpic,
qe_ic_cascade_high_mpic);
of_node_put(np);
} else
pr_err("Could not find qe-ic node\n");
#endif
}
static void __init twr_p1025_setup_arch(void)
{
#ifdef CONFIG_QUICC_ENGINE
struct device_node *np;
#endif
if (ppc_md.progress)
ppc_md.progress("twr_p1025_setup_arch()", 0);
mpc85xx_smp_init();
fsl_pci_assign_primary();
#ifdef CONFIG_QUICC_ENGINE
mpc85xx_qe_init();
#if defined(CONFIG_UCC_GETH) || defined(CONFIG_SERIAL_QE)
if (machine_is(twr_p1025)) {
struct ccsr_guts __iomem *guts;
np = of_find_compatible_node(NULL, NULL, "fsl,p1021-guts");
if (np) {
guts = of_iomap(np, 0);
if (!guts)
pr_err("twr_p1025: could not map global utilities register\n");
else {
setbits32(&guts->pmuxcr, MPC85xx_PMUXCR_QE(0) |
MPC85xx_PMUXCR_QE(3) |
MPC85xx_PMUXCR_QE(9) |
MPC85xx_PMUXCR_QE(12));
iounmap(guts);
#if defined(CONFIG_SERIAL_QE)
par_io_config_pin(0, 18, 0, 0, 0, 0);
#endif
par_io_config_pin(1, 29, 1, 0, 0, 0);
par_io_data_set(1, 29, 0);
}
of_node_put(np);
}
}
#endif
#endif
pr_info("TWR-P1025 board from Freescale Semiconductor\n");
}
static int __init twr_p1025_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "fsl,TWR-P1025");
}
