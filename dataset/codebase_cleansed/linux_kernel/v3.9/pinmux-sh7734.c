static int __init plat_pinmux_setup(void)
{
return sh_pfc_register("pfc-sh7734", sh7734_pfc_resources,
ARRAY_SIZE(sh7734_pfc_resources));
}
