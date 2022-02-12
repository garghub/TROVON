static int __init plat_pinmux_setup(void)
{
return sh_pfc_register("pfc-sh7757", sh7757_pfc_resources,
ARRAY_SIZE(sh7757_pfc_resources));
}
