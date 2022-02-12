static int __init plat_pinmux_setup(void)
{
return sh_pfc_register("pfc-shx3", shx3_pfc_resources,
ARRAY_SIZE(shx3_pfc_resources));
}
