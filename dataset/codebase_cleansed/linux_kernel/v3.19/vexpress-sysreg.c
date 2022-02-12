static void __iomem *vexpress_sysreg_base(void)
{
if (!__vexpress_sysreg_base) {
struct device_node *node = of_find_compatible_node(NULL, NULL,
"arm,vexpress-sysreg");
__vexpress_sysreg_base = of_iomap(node, 0);
}
WARN_ON(!__vexpress_sysreg_base);
return __vexpress_sysreg_base;
}
static int vexpress_sysreg_get_master(void)
{
if (readl(vexpress_sysreg_base() + SYS_MISC) & SYS_MISC_MASTERSITE)
return VEXPRESS_SITE_DB2;
return VEXPRESS_SITE_DB1;
}
void vexpress_flags_set(u32 data)
{
writel(~0, vexpress_sysreg_base() + SYS_FLAGSCLR);
writel(data, vexpress_sysreg_base() + SYS_FLAGSSET);
}
unsigned int vexpress_get_mci_cardin(struct device *dev)
{
return readl(vexpress_sysreg_base() + SYS_MCI) & SYS_MCI_CARDIN;
}
u32 vexpress_get_procid(int site)
{
if (site == VEXPRESS_SITE_MASTER)
site = vexpress_sysreg_get_master();
return readl(vexpress_sysreg_base() + (site == VEXPRESS_SITE_DB1 ?
SYS_PROCID0 : SYS_PROCID1));
}
void __iomem *vexpress_get_24mhz_clock_base(void)
{
return vexpress_sysreg_base() + SYS_24MHZ;
}
void __init vexpress_sysreg_early_init(void __iomem *base)
{
__vexpress_sysreg_base = base;
vexpress_config_set_master(vexpress_sysreg_get_master());
}
static int vexpress_sysreg_probe(struct platform_device *pdev)
{
struct resource *mem;
void __iomem *base;
struct bgpio_chip *mmc_gpio_chip;
u32 dt_hbi;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem)
return -EINVAL;
base = devm_ioremap(&pdev->dev, mem->start, resource_size(mem));
if (!base)
return -ENOMEM;
vexpress_config_set_master(vexpress_sysreg_get_master());
if (of_property_read_u32(of_root, "arm,hbi", &dt_hbi) == 0) {
u32 id = vexpress_get_procid(VEXPRESS_SITE_MASTER);
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
mmc_gpio_chip->gc.ngpio = 2;
gpiochip_add(&mmc_gpio_chip->gc);
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
