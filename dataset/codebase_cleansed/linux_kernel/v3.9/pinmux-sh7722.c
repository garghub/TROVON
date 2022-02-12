static int __init plat_pinmux_setup(void)
{
return sh_pfc_register("pfc-sh7722", NULL, 0);
}
