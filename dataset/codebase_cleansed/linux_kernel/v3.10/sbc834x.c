static void __init sbc834x_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("sbc834x_setup_arch()", 0);
mpc83xx_setup_pci();
}
static int __init sbc834x_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "SBC834xE");
}
