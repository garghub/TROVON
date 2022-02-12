void vexpress_flags_set(u32 data)
{
static void __iomem *base;
if (!base) {
struct device_node *node = of_find_compatible_node(NULL, NULL,
"arm,vexpress-sysreg");
base = of_iomap(node, 0);
}
if (WARN_ON(!base))
return;
writel(~0, base + SYS_FLAGSCLR);
writel(data, base + SYS_FLAGSSET);
}
static int vexpress_sysreg_probe(struct platform_device *pdev)
{
struct resource *mem;
void __iomem *base;
struct gpio_chip *mmc_gpio_chip;
int master;
u32 dt_hbi;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem)
return -EINVAL;
base = devm_ioremap(&pdev->dev, mem->start, resource_size(mem));
if (!base)
return -ENOMEM;
master = readl(base + SYS_MISC) & SYS_MISC_MASTERSITE ?
VEXPRESS_SITE_DB2 : VEXPRESS_SITE_DB1;
vexpress_config_set_master(master);
if (of_property_read_u32(of_root, "arm,hbi", &dt_hbi) == 0) {
u32 id = readl(base + (master == VEXPRESS_SITE_DB1 ?
SYS_PROCID0 : SYS_PROCID1));
u32 hbi = (id >> SYS_PROCIDx_HBI_SHIFT) & SYS_HBI_MASK;
if (WARN_ON(dt_hbi != hbi))
dev_warn(&pdev->dev, "DT HBI (%x) is not matching hardware (%x)!\n",
dt_hbi, hbi);
}
mmc_gpio_chip = devm_kzalloc(&pdev->dev, sizeof(*mmc_gpio_chip),
GFP_KERNEL);
if (!mmc_gpio_chip)
return -ENOMEM;
bgpio_init(mmc_gpio_chip, &pdev->dev, 0x4, base + SYS_MCI,
NULL, NULL, NULL, NULL, 0);
mmc_gpio_chip->ngpio = 2;
gpiochip_add_data(mmc_gpio_chip, NULL);
return mfd_add_devices(&pdev->dev, PLATFORM_DEVID_AUTO,
vexpress_sysreg_cells,
ARRAY_SIZE(vexpress_sysreg_cells), mem, 0, NULL);
}
static int __init vexpress_sysreg_init(void)
{
struct device_node *node;
for_each_matching_node(node, vexpress_sysreg_match)
of_platform_device_create(node, NULL, NULL);
return platform_driver_register(&vexpress_sysreg_driver);
}
