static int __init plat_pinmux_setup(void)
{
return sh_pfc_register("pfc-sh7203", sh7203_pfc_resources,
ARRAY_SIZE(sh7203_pfc_resources));
}
