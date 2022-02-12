static int __init plat_pinmux_setup(void)
{
return sh_pfc_register("pfc-sh7720", NULL, 0);
}
