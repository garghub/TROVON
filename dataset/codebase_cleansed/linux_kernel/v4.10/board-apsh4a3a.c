static int __init apsh4a3a_devices_setup(void)
{
regulator_register_fixed(0, dummy_supplies, ARRAY_SIZE(dummy_supplies));
return platform_add_devices(apsh4a3a_devices,
ARRAY_SIZE(apsh4a3a_devices));
}
static int apsh4a3a_clk_init(void)
{
struct clk *clk;
int ret;
clk = clk_get(NULL, "extal");
if (IS_ERR(clk))
return PTR_ERR(clk);
ret = clk_set_rate(clk, 33333000);
clk_put(clk);
return ret;
}
static void __init apsh4a3a_setup(char **cmdline_p)
{
printk(KERN_INFO "Alpha Project AP-SH4A-3A support:\n");
}
static void __init apsh4a3a_init_irq(void)
{
plat_irq_setup_pins(IRQ_MODE_IRQ7654);
}
static int apsh4a3a_mode_pins(void)
{
int value = 0;
value &= ~MODE_PIN0;
value &= ~MODE_PIN1;
value &= ~MODE_PIN2;
value &= ~MODE_PIN3;
value |= MODE_PIN4;
value &= ~MODE_PIN5;
value |= MODE_PIN6;
value |= MODE_PIN7;
value |= MODE_PIN8;
value |= MODE_PIN9;
value |= MODE_PIN10;
value |= MODE_PIN11;
value |= MODE_PIN12;
value &= ~MODE_PIN13;
value |= MODE_PIN14;
return value;
}
