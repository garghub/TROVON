static int __init plat_pinmux_setup(void)
{
return register_pinmux(&sh7734_pinmux_info);
}
