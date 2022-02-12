static void __init cpu8815_map_io(void)
{
iotable_init(cpu8815_io_desc, ARRAY_SIZE(cpu8815_io_desc));
}
static void cpu8815_restart(char mode, const char *cmd)
{
void __iomem *srcbase = ioremap(NOMADIK_SRC_BASE, SZ_4K);
writel(1, srcbase + 0x18);
}
static void __init cpu8815_timer_init_of(void)
{
struct device_node *mtu;
void __iomem *base;
int irq;
u32 src_cr;
nomadik_clk_init();
mtu = of_find_node_by_path("/mtu0");
if (!mtu)
return;
base = of_iomap(mtu, 0);
if (WARN_ON(!base))
return;
irq = irq_of_parse_and_map(mtu, 0);
pr_info("Remapped MTU @ %p, irq: %d\n", base, irq);
src_cr = readl(base);
src_cr &= SRC_CR_INIT_MASK;
src_cr |= SRC_CR_INIT_VAL;
writel(src_cr, base);
nmdk_timer_init(base, irq);
}
static int __init cpu8815_eth_init(void)
{
struct device_node *eth;
int gpio, irq, err;
eth = of_find_node_by_path("/usb-s8815/ethernet-gpio");
if (!eth) {
pr_info("could not find any ethernet GPIO\n");
return 0;
}
gpio = of_get_gpio(eth, 0);
err = gpio_request(gpio, "eth_irq");
if (err) {
pr_info("failed to request ethernet GPIO\n");
return -ENODEV;
}
err = gpio_direction_input(gpio);
if (err) {
pr_info("failed to set ethernet GPIO as input\n");
return -ENODEV;
}
irq = gpio_to_irq(gpio);
pr_info("enabled USB-S8815 ethernet GPIO %d, IRQ %d\n", gpio, irq);
return 0;
}
static int __init cpu8815_mmcsd_init(void)
{
struct device_node *cdbias;
int gpio, err;
cdbias = of_find_node_by_path("/usb-s8815/mmcsd-gpio");
if (!cdbias) {
pr_info("could not find MMC/SD card detect bias node\n");
return 0;
}
gpio = of_get_gpio(cdbias, 0);
if (gpio < 0) {
pr_info("could not obtain MMC/SD card detect bias GPIO\n");
return 0;
}
err = gpio_request(gpio, "card detect bias");
if (err) {
pr_info("failed to request card detect bias GPIO %d\n", gpio);
return -ENODEV;
}
err = gpio_direction_output(gpio, 0);
if (err){
pr_info("failed to set GPIO %d as output, low\n", gpio);
return err;
}
pr_info("enabled USB-S8815 CD bias GPIO %d, low\n", gpio);
return 0;
}
static void __init cpu8815_init_of(void)
{
#ifdef CONFIG_CACHE_L2X0
l2x0_of_init(0x00730249, 0xfe000fff);
#endif
pinctrl_register_mappings(nhk8815_pinmap, ARRAY_SIZE(nhk8815_pinmap));
of_platform_populate(NULL, of_default_bus_match_table,
cpu8815_auxdata_lookup, NULL);
}
