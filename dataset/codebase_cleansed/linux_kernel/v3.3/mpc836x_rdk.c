static void __init mpc836x_rdk_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("mpc836x_rdk_setup_arch()", 0);
mpc83xx_setup_pci();
#ifdef CONFIG_QUICC_ENGINE
qe_reset();
#endif
}
static int __init mpc836x_rdk_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "fsl,mpc8360rdk");
}
