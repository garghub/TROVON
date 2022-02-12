static int __init plat_pinmux_setup(void)
{
return sh_pfc_register("pfc-sh7722", sh7722_pfc_resources,
ARRAY_SIZE(sh7722_pfc_resources));
}
