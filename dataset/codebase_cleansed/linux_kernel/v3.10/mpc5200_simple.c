static void __init mpc5200_simple_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("mpc5200_simple_setup_arch()", 0);
mpc52xx_map_common_devices();
mpc5200_setup_xlb_arbiter();
mpc52xx_setup_pci();
}
static int __init mpc5200_simple_probe(void)
{
return of_flat_dt_match(of_get_flat_dt_root(), board);
}
