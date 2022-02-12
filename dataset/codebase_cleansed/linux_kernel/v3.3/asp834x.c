static void __init asp834x_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("asp834x_setup_arch()", 0);
mpc834x_usb_cfg();
}
static int __init asp834x_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "analogue-and-micro,asp8347e");
}
