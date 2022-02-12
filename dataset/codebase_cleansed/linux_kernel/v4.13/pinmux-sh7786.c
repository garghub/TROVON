static int __init plat_pinmux_setup(void)
{
return sh_pfc_register("pfc-sh7786", sh7786_pfc_resources,
ARRAY_SIZE(sh7786_pfc_resources));
}
