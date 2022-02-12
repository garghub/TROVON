static u8 fuse_readb(const unsigned int offset)
{
u32 val;
val = fuse_readl(round_down(offset, 4));
val >>= (offset % 4) * 8;
val &= 0xff;
return val;
}
static ssize_t fuse_read(struct file *fd, struct kobject *kobj,
struct bin_attribute *attr, char *buf,
loff_t pos, size_t size)
{
int i;
if (pos < 0 || pos >= fuse_size)
return 0;
if (size > fuse_size - pos)
size = fuse_size - pos;
for (i = 0; i < size; i++)
buf[i] = fuse_readb(pos + i);
return i;
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
int tegra_fuse_readl(unsigned long offset, u32 *value)
{
if (!fuse_readl)
return -EPROBE_DEFER;
*value = fuse_readl(offset);
return 0;
}
int tegra_fuse_create_sysfs(struct device *dev, int size,
u32 (*readl)(const unsigned int offset))
{
if (fuse_size)
return -ENODEV;
fuse_bin_attr.size = size;
fuse_bin_attr.read = fuse_read;
fuse_size = size;
fuse_readl = readl;
return device_create_bin_file(dev, &fuse_bin_attr);
}
static int __init tegra_init_fuse(void)
{
struct device_node *np;
void __iomem *car_base;
if (!soc_is_tegra())
return 0;
tegra_init_apbmisc();
np = of_find_matching_node(NULL, car_match);
car_base = of_iomap(np, 0);
if (car_base) {
tegra_enable_fuse_clk(car_base);
iounmap(car_base);
} else {
pr_err("Could not enable fuse clk. ioremap tegra car failed.\n");
return -ENXIO;
}
if (tegra_get_chip_id() == TEGRA20)
tegra20_init_fuse_early();
else
tegra30_init_fuse_early();
pr_info("Tegra Revision: %s SKU: %d CPU Process: %d Core Process: %d\n",
tegra_revision_name[tegra_sku_info.revision],
tegra_sku_info.sku_id, tegra_sku_info.cpu_process_id,
tegra_sku_info.core_process_id);
pr_debug("Tegra CPU Speedo ID %d, Soc Speedo ID %d\n",
tegra_sku_info.cpu_speedo_id, tegra_sku_info.soc_speedo_id);
return 0;
}
