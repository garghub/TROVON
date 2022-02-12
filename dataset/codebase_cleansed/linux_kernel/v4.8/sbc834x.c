static void __init sbc834x_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("sbc834x_setup_arch()", 0);
mpc83xx_setup_pci();
}
static int __init sbc834x_probe(void)
{
return of_machine_is_compatible("SBC834xE");
}
