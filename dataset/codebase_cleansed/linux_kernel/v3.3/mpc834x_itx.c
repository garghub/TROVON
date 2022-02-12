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
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "MPC834xMITX");
}
