static u8 fuse_readb(struct tegra_fuse *fuse, unsigned int offset)
{
u32 val;
val = fuse->read(fuse, round_down(offset, 4));
val >>= (offset % 4) * 8;
val &= 0xff;
return val;
}
static ssize_t fuse_read(struct file *fd, struct kobject *kobj,
struct bin_attribute *attr, char *buf,
loff_t pos, size_t size)
{
struct device *dev = kobj_to_dev(kobj);
struct tegra_fuse *fuse = dev_get_drvdata(dev);
int i;
if (pos < 0 || pos >= attr->size)
return 0;
if (size > attr->size - pos)
size = attr->size - pos;
for (i = 0; i < size; i++)
buf[i] = fuse_readb(fuse, pos + i);
return i;
}
static int tegra_fuse_create_sysfs(struct device *dev, unsigned int size,
const struct tegra_fuse_info *info)
{
fuse_bin_attr.size = size;
return device_create_bin_file(dev, &fuse_bin_attr);
}
static int tegra_fuse_probe(struct platform_device *pdev)
{
void __iomem *base = fuse->base;
struct resource *res;
int err;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
fuse->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(fuse->base))
return PTR_ERR(fuse->base);
fuse->clk = devm_clk_get(&pdev->dev, "fuse");
if (IS_ERR(fuse->clk)) {
dev_err(&pdev->dev, "failed to get FUSE clock: %ld",
PTR_ERR(fuse->clk));
return PTR_ERR(fuse->clk);
}
platform_set_drvdata(pdev, fuse);
fuse->dev = &pdev->dev;
if (fuse->soc->probe) {
err = fuse->soc->probe(fuse);
if (err < 0)
return err;
}
if (tegra_fuse_create_sysfs(&pdev->dev, fuse->soc->info->size,
fuse->soc->info))
return -ENODEV;
iounmap(base);
return 0;
}
bool __init tegra_fuse_read_spare(unsigned int spare)
{
unsigned int offset = fuse->soc->info->spare + spare * 4;
return fuse->read_early(fuse, offset) & 1;
}
u32 __init tegra_fuse_read_early(unsigned int offset)
{
return fuse->read_early(fuse, offset);
}
int tegra_fuse_readl(unsigned long offset, u32 *value)
{
if (!fuse->read)
return -EPROBE_DEFER;
*value = fuse->read(fuse, offset);
return 0;
}
static void tegra_enable_fuse_clk(void __iomem *base)
{
u32 reg;
reg = readl_relaxed(base + 0x48);
reg |= 1 << 28;
writel(reg, base + 0x48);
reg = readl(base + 0x14);
reg |= 1 << 7;
writel(reg, base + 0x14);
}
static int __init tegra_init_fuse(void)
{
const struct of_device_id *match;
struct device_node *np;
struct resource regs;
tegra_init_apbmisc();
np = of_find_matching_node_and_match(NULL, tegra_fuse_match, &match);
if (!np) {
if (IS_ENABLED(CONFIG_ARM) && soc_is_tegra()) {
u8 chip = tegra_get_chip_id();
regs.start = 0x7000f800;
regs.end = 0x7000fbff;
regs.flags = IORESOURCE_MEM;
switch (chip) {
#ifdef CONFIG_ARCH_TEGRA_2x_SOC
case TEGRA20:
fuse->soc = &tegra20_fuse_soc;
break;
#endif
#ifdef CONFIG_ARCH_TEGRA_3x_SOC
case TEGRA30:
fuse->soc = &tegra30_fuse_soc;
break;
#endif
#ifdef CONFIG_ARCH_TEGRA_114_SOC
case TEGRA114:
fuse->soc = &tegra114_fuse_soc;
break;
#endif
#ifdef CONFIG_ARCH_TEGRA_124_SOC
case TEGRA124:
fuse->soc = &tegra124_fuse_soc;
break;
#endif
default:
pr_warn("Unsupported SoC: %02x\n", chip);
break;
}
} else {
return 0;
}
} else {
if (of_address_to_resource(np, 0, &regs) < 0) {
pr_err("failed to get FUSE register\n");
return -ENXIO;
}
fuse->soc = match->data;
}
np = of_find_matching_node(NULL, car_match);
if (np) {
void __iomem *base = of_iomap(np, 0);
if (base) {
tegra_enable_fuse_clk(base);
iounmap(base);
} else {
pr_err("failed to map clock registers\n");
return -ENXIO;
}
}
fuse->base = ioremap_nocache(regs.start, resource_size(&regs));
if (!fuse->base) {
pr_err("failed to map FUSE registers\n");
return -ENXIO;
}
fuse->soc->init(fuse);
pr_info("Tegra Revision: %s SKU: %d CPU Process: %d SoC Process: %d\n",
tegra_revision_name[tegra_sku_info.revision],
tegra_sku_info.sku_id, tegra_sku_info.cpu_process_id,
tegra_sku_info.soc_process_id);
pr_debug("Tegra CPU Speedo ID %d, SoC Speedo ID %d\n",
tegra_sku_info.cpu_speedo_id, tegra_sku_info.soc_speedo_id);
return 0;
}
