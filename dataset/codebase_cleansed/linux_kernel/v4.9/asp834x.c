static void __init asp834x_setup_arch(void)
{
mpc83xx_setup_arch();
mpc834x_usb_cfg();
}
static int __init asp834x_probe(void)
{
return of_machine_is_compatible("analogue-and-micro,asp8347e");
}
