static void vt8500_restart(enum reboot_mode mode, const char *cmd)
{
if (pmc_base)
writel(1, pmc_base + VT8500_PMSR_REG);
}
static void __init vt8500_map_io(void)
{
iotable_init(vt8500_io_desc, ARRAY_SIZE(vt8500_io_desc));
}
static void vt8500_power_off(void)
{
local_irq_disable();
writew(5, pmc_base + VT8500_HCR_REG);
asm("mcr p15, 0, %0, c7, c0, 4" : : "r" (0));
}
static void __init vt8500_init(void)
{
struct device_node *np;
#if defined(CONFIG_FB_VT8500) || defined(CONFIG_FB_WM8505)
struct device_node *fb;
void __iomem *gpio_base;
#endif
#ifdef CONFIG_FB_VT8500
fb = of_find_compatible_node(NULL, NULL, "via,vt8500-fb");
if (fb) {
np = of_find_compatible_node(NULL, NULL, "via,vt8500-gpio");
if (np) {
gpio_base = of_iomap(np, 0);
if (!gpio_base)
pr_err("%s: of_iomap(gpio_mux) failed\n",
__func__);
of_node_put(np);
} else {
gpio_base = ioremap(LEGACY_GPIO_BASE, 0x1000);
if (!gpio_base)
pr_err("%s: ioremap(legacy_gpio_mux) failed\n",
__func__);
}
if (gpio_base) {
writel(readl(gpio_base + VT8500_GPIO_MUX_REG) | 1,
gpio_base + VT8500_GPIO_MUX_REG);
iounmap(gpio_base);
} else
pr_err("%s: Could not remap GPIO mux\n", __func__);
of_node_put(fb);
}
#endif
#ifdef CONFIG_FB_WM8505
fb = of_find_compatible_node(NULL, NULL, "wm,wm8505-fb");
if (fb) {
np = of_find_compatible_node(NULL, NULL, "wm,wm8505-gpio");
if (!np)
np = of_find_compatible_node(NULL, NULL,
"wm,wm8650-gpio");
if (np) {
gpio_base = of_iomap(np, 0);
if (!gpio_base)
pr_err("%s: of_iomap(gpio_mux) failed\n",
__func__);
of_node_put(np);
} else {
gpio_base = ioremap(LEGACY_GPIO_BASE, 0x1000);
if (!gpio_base)
pr_err("%s: ioremap(legacy_gpio_mux) failed\n",
__func__);
}
if (gpio_base) {
writel(readl(gpio_base + VT8500_GPIO_MUX_REG) |
0x80000000, gpio_base + VT8500_GPIO_MUX_REG);
iounmap(gpio_base);
} else
pr_err("%s: Could not remap GPIO mux\n", __func__);
of_node_put(fb);
}
#endif
np = of_find_compatible_node(NULL, NULL, "via,vt8500-pmc");
if (np) {
pmc_base = of_iomap(np, 0);
if (!pmc_base)
pr_err("%s:of_iomap(pmc) failed\n", __func__);
of_node_put(np);
} else {
pmc_base = ioremap(LEGACY_PMC_BASE, 0x1000);
if (!pmc_base)
pr_err("%s:ioremap(power_off) failed\n", __func__);
}
if (pmc_base)
pm_power_off = &vt8500_power_off;
else
pr_err("%s: PMC Hibernation register could not be remapped, not enabling power off!\n", __func__);
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
