static int __init plat_pinmux_setup(void)
{
return sh_pfc_register("pfc-sh7785", NULL, 0);
}
