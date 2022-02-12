static void __init keystone_init(void)
{
struct device_node *node;
node = of_find_compatible_node(NULL, NULL, "ti,keystone-reset");
if (WARN_ON(!node))
pr_warn("ti,keystone-reset node undefined\n");
keystone_rstctrl = of_iomap(node, 0);
if (WARN_ON(!keystone_rstctrl))
pr_warn("ti,keystone-reset iomap error\n");
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
void keystone_restart(enum reboot_mode mode, const char *cmd)
{
u32 val;
BUG_ON(!keystone_rstctrl);
val = readl(keystone_rstctrl);
val &= PLL_RESET_WRITE_KEY_MASK;
val |= PLL_RESET_WRITE_KEY;
writel(val, keystone_rstctrl);
val = readl(keystone_rstctrl);
val &= ~PLL_RESET;
writel(val, keystone_rstctrl);
}
