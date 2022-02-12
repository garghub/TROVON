static unsigned int __init micro9_detect_bootwidth(void)
{
u32 v;
v = __raw_readl(EP93XX_SYSCON_SYSCFG);
if (v & EP93XX_SYSCON_SYSCFG_LCSN7)
return 4;
else
return 2;
}
static void __init micro9_register_flash(void)
{
unsigned int width;
if (machine_is_micro9())
width = 4;
else if (machine_is_micro9m() || machine_is_micro9s())
width = micro9_detect_bootwidth();
else
width = 0;
if (width)
ep93xx_register_flash(width, EP93XX_CS1_PHYS_BASE, SZ_64M);
}
static void __init micro9_init_machine(void)
{
ep93xx_init_devices();
ep93xx_register_eth(&micro9_eth_data, 1);
micro9_register_flash();
}
