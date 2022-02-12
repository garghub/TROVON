static void __init mpc830x_rdb_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("mpc830x_rdb_setup_arch()", 0);
mpc83xx_setup_pci();
mpc831x_usb_cfg();
}
static int __init mpc830x_rdb_probe(void)
{
return of_device_compatible_match(of_root, board);
}
