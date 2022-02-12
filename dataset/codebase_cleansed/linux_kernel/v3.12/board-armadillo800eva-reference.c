static void __init eva_clock_init(void)
{
struct clk *system = clk_get(NULL, "system_clk");
struct clk *xtal1 = clk_get(NULL, "extal1");
struct clk *usb24s = clk_get(NULL, "usb24s");
struct clk *fsibck = clk_get(NULL, "fsibck");
if (IS_ERR(system) ||
IS_ERR(xtal1) ||
IS_ERR(usb24s) ||
IS_ERR(fsibck)) {
pr_err("armadillo800eva board clock init failed\n");
goto clock_error;
}
clk_set_rate(xtal1, 24000000);
clk_set_parent(usb24s, system);
clk_set_rate(fsibck, 12288000);
clock_error:
if (!IS_ERR(system))
clk_put(system);
if (!IS_ERR(xtal1))
clk_put(xtal1);
if (!IS_ERR(usb24s))
clk_put(usb24s);
if (!IS_ERR(fsibck))
clk_put(fsibck);
}
static void __init eva_init(void)
{
r8a7740_clock_init(MD_CK0 | MD_CK2);
eva_clock_init();
r8a7740_meram_workaround();
#ifdef CONFIG_CACHE_L2X0
l2x0_init(IOMEM(0xf0002000), 0x40440000, 0x82000fff);
#endif
r8a7740_add_standard_devices_dt();
r8a7740_pm_init();
}
static void eva_restart(enum reboot_mode mode, const char *cmd)
{
writel(1 << 31, RESCNT2);
}
