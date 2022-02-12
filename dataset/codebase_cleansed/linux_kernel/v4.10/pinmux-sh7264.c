static int __init plat_pinmux_setup(void)
{
return sh_pfc_register("pfc-sh7264", sh7264_pfc_resources,
ARRAY_SIZE(sh7264_pfc_resources));
}
