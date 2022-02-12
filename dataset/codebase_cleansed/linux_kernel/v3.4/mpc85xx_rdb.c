void __init mpc85xx_rdb_pic_init(void)
{
struct mpic *mpic;
unsigned long root = of_get_flat_dt_root();
#ifdef CONFIG_QUICC_ENGINE
struct device_node *np;
#endif
if (of_flat_dt_is_compatible(root, "fsl,MPC85XXRDB-CAMP")) {
mpic = mpic_alloc(NULL, 0, MPIC_NO_RESET |
MPIC_BIG_ENDIAN |
MPIC_SINGLE_DEST_CPU,
0, 256, " OpenPIC ");
} else {
mpic = mpic_alloc(NULL, 0,
MPIC_BIG_ENDIAN |
MPIC_SINGLE_DEST_CPU,
0, 256, " OpenPIC ");
}
BUG_ON(mpic == NULL);
mpic_init(mpic);
#ifdef CONFIG_QUICC_ENGINE
np = of_find_compatible_node(NULL, NULL, "fsl,qe-ic");
if (np) {
qe_ic_init(np, 0, qe_ic_cascade_low_mpic,
qe_ic_cascade_high_mpic);
of_node_put(np);
} else
pr_err("%s: Could not find qe-ic node\n", __func__);
#endif
}
static void __init mpc85xx_rdb_setup_arch(void)
{
#if defined(CONFIG_PCI) || defined(CONFIG_QUICC_ENGINE)
struct device_node *np;
#endif
if (ppc_md.progress)
ppc_md.progress("mpc85xx_rdb_setup_arch()", 0);
#ifdef CONFIG_PCI
for_each_node_by_type(np, "pci") {
if (of_device_is_compatible(np, "fsl,mpc8548-pcie"))
fsl_add_bridge(np, 0);
}
#endif
mpc85xx_smp_init();
#ifdef CONFIG_QUICC_ENGINE
np = of_find_compatible_node(NULL, NULL, "fsl,qe");
if (!np) {
pr_err("%s: Could not find Quicc Engine node\n", __func__);
goto qe_fail;
}
qe_reset();
of_node_put(np);
np = of_find_node_by_name(NULL, "par_io");
if (np) {
struct device_node *ucc;
par_io_init(np);
of_node_put(np);
for_each_node_by_name(ucc, "ucc")
par_io_of_config(ucc);
}
#if defined(CONFIG_UCC_GETH) || defined(CONFIG_SERIAL_QE)
if (machine_is(p1025_rdb)) {
struct ccsr_guts __iomem *guts;
np = of_find_node_by_name(NULL, "global-utilities");
if (np) {
guts = of_iomap(np, 0);
if (!guts) {
pr_err("mpc85xx-rdb: could not map global utilities register\n");
} else {
setbits32(&guts->pmuxcr, MPC85xx_PMUXCR_QE(0) |
MPC85xx_PMUXCR_QE(3) |
MPC85xx_PMUXCR_QE(9) |
MPC85xx_PMUXCR_QE(12));
iounmap(guts);
}
of_node_put(np);
}
}
#endif
qe_fail:
#endif
printk(KERN_INFO "MPC85xx RDB board from Freescale Semiconductor\n");
}
static int __init p2020_rdb_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "fsl,P2020RDB"))
return 1;
return 0;
}
static int __init p1020_rdb_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "fsl,P1020RDB"))
return 1;
return 0;
}
static int __init p1020_rdb_pc_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "fsl,P1020RDB-PC");
}
static int __init p1021_rdb_pc_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "fsl,P1021RDB-PC"))
return 1;
return 0;
}
static int __init p2020_rdb_pc_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "fsl,P2020RDB-PC"))
return 1;
return 0;
}
static int __init p1025_rdb_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "fsl,P1025RDB");
}
static int __init p1020_mbg_pc_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "fsl,P1020MBG-PC");
}
static int __init p1020_utm_pc_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "fsl,P1020UTM-PC");
}
