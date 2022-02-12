static int __init urquell_devices_setup(void)
{
gpio_request(GPIO_FN_USB_OVC0, NULL);
gpio_request(GPIO_FN_USB_PENC0, NULL);
__raw_writew(__raw_readw(UBOARDREG(IRL2MSKR)) & ~0x00000001,
UBOARDREG(IRL2MSKR));
return platform_add_devices(urquell_devices,
ARRAY_SIZE(urquell_devices));
}
static void urquell_power_off(void)
{
__raw_writew(0xa5a5, UBOARDREG(SRSTR));
}
static void __init urquell_init_irq(void)
{
plat_irq_setup_pins(IRQ_MODE_IRL3210_MASK);
}
static int urquell_mode_pins(void)
{
return __raw_readw(UBOARDREG(MDSWMR));
}
static int urquell_clk_init(void)
{
struct clk *clk;
int ret;
if (test_mode_pin(MODE_PIN9))
return -EINVAL;
clk = clk_get(NULL, "extal");
if (!clk || IS_ERR(clk))
return PTR_ERR(clk);
ret = clk_set_rate(clk, 33333333);
clk_put(clk);
return ret;
}
static void __init urquell_setup(char **cmdline_p)
{
printk(KERN_INFO "Renesas Technology Corp. Urquell support.\n");
pm_power_off = urquell_power_off;
register_smp_ops(&shx3_smp_ops);
}
