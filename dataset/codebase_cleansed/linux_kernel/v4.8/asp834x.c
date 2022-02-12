static void __init asp834x_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("asp834x_setup_arch()", 0);
mpc834x_usb_cfg();
}
static int __init asp834x_probe(void)
{
return of_machine_is_compatible("analogue-and-micro,asp8347e");
}
