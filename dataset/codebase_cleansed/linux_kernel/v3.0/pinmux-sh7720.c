static int __init plat_pinmux_setup(void)
{
return register_pinmux(&sh7720_pinmux_info);
}
