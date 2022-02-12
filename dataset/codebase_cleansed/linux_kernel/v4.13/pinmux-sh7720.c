static int __init plat_pinmux_setup(void)
{
return sh_pfc_register("pfc-sh7720", sh7720_pfc_resources,
ARRAY_SIZE(sh7720_pfc_resources));
}
