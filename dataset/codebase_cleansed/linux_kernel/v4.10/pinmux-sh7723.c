static int __init plat_pinmux_setup(void)
{
return sh_pfc_register("pfc-sh7723", sh7723_pfc_resources,
ARRAY_SIZE(sh7723_pfc_resources));
}
