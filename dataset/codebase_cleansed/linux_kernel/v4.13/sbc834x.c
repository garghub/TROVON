static void __init sbc834x_setup_arch(void)
{
mpc83xx_setup_arch();
}
static int __init sbc834x_probe(void)
{
return of_machine_is_compatible("SBC834xE");
}
