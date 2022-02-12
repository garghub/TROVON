static int __init plat_pinmux_setup(void)
{
return register_pinmux(&sh7264_pinmux_info);
}
