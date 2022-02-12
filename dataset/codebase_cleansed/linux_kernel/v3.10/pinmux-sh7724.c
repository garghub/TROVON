static int __init plat_pinmux_setup(void)
{
return sh_pfc_register("pfc-sh7724", sh7724_pfc_resources,
ARRAY_SIZE(sh7724_pfc_resources));
}
