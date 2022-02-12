static int __init mpc834x_itx_declare_of_platform_devices(void)
{
mpc83xx_declare_of_platform_devices();
return of_platform_bus_probe(NULL, mpc834x_itx_ids, NULL);
}
static void __init mpc834x_itx_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("mpc834x_itx_setup_arch()", 0);
mpc83xx_setup_pci();
mpc834x_usb_cfg();
}
static int __init mpc834x_itx_probe(void)
{
return of_machine_is_compatible("MPC834xMITX");
}
