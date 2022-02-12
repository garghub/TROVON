static void __init mpc836x_rdk_setup_arch(void)
{
mpc83xx_setup_arch();
}
static int __init mpc836x_rdk_probe(void)
{
return of_machine_is_compatible("fsl,mpc8360rdk");
}
