static void __init mpc836x_rdk_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("mpc836x_rdk_setup_arch()", 0);
mpc83xx_setup_pci();
}
static int __init mpc836x_rdk_probe(void)
{
return of_machine_is_compatible("fsl,mpc8360rdk");
}
