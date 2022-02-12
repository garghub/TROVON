static int __init plat_pinmux_setup(void)
{
return sh_pfc_register("pfc-sh7785", sh7785_pfc_resources,
ARRAY_SIZE(sh7785_pfc_resources));
}
