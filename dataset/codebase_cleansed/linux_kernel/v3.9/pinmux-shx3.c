static int __init shx3_pinmux_setup(void)
{
return sh_pfc_register("pfc-shx3", NULL, 0);
}
