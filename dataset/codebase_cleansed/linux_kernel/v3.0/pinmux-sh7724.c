static int __init plat_pinmux_setup(void)
{
return register_pinmux(&sh7724_pinmux_info);
}
