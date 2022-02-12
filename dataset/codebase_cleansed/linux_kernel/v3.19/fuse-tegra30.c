u32 tegra30_fuse_readl(const unsigned int offset)
{
u32 val;
if (fuse_clk)
clk_prepare_enable(fuse_clk);
val = readl_relaxed(fuse_base + FUSE_BEGIN + offset);
if (fuse_clk)
clk_disable_unprepare(fuse_clk);
return val;
}
static int tegra30_fuse_probe(struct platform_device *pdev)
{
const struct of_device_id *of_dev_id;
of_dev_id = of_match_device(tegra30_fuse_of_match, &pdev->dev);
if (!of_dev_id)
return -ENODEV;
fuse_clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(fuse_clk)) {
dev_err(&pdev->dev, "missing clock");
return PTR_ERR(fuse_clk);
}
platform_set_drvdata(pdev, NULL);
if (tegra_fuse_create_sysfs(&pdev->dev, fuse_info->size,
tegra30_fuse_readl))
return -ENODEV;
dev_dbg(&pdev->dev, "loaded\n");
return 0;
}
static int __init tegra30_fuse_init(void)
{
return platform_driver_register(&tegra30_fuse_driver);
}
static void __init tegra30_fuse_add_randomness(void)
{
u32 randomness[12];
randomness[0] = tegra_sku_info.sku_id;
randomness[1] = tegra_read_straps();
randomness[2] = tegra_read_chipid();
randomness[3] = tegra_sku_info.cpu_process_id << 16;
randomness[3] |= tegra_sku_info.core_process_id;
randomness[4] = tegra_sku_info.cpu_speedo_id << 16;
randomness[4] |= tegra_sku_info.soc_speedo_id;
randomness[5] = tegra30_fuse_readl(FUSE_VENDOR_CODE);
randomness[6] = tegra30_fuse_readl(FUSE_FAB_CODE);
randomness[7] = tegra30_fuse_readl(FUSE_LOT_CODE_0);
randomness[8] = tegra30_fuse_readl(FUSE_LOT_CODE_1);
randomness[9] = tegra30_fuse_readl(FUSE_WAFER_ID);
randomness[10] = tegra30_fuse_readl(FUSE_X_COORDINATE);
randomness[11] = tegra30_fuse_readl(FUSE_Y_COORDINATE);
add_device_randomness(randomness, sizeof(randomness));
}
static void __init legacy_fuse_init(void)
{
switch (tegra_get_chip_id()) {
case TEGRA30:
fuse_info = &tegra30_info;
break;
case TEGRA114:
fuse_info = &tegra114_info;
break;
case TEGRA124:
fuse_info = &tegra124_info;
break;
default:
return;
}
fuse_base = ioremap(TEGRA_FUSE_BASE, TEGRA_FUSE_SIZE);
}
bool __init tegra30_spare_fuse(int spare_bit)
{
u32 offset = fuse_info->spare_bit + spare_bit * 4;
return tegra30_fuse_readl(offset) & 1;
}
void __init tegra30_init_fuse_early(void)
{
struct device_node *np;
const struct of_device_id *of_match;
np = of_find_matching_node_and_match(NULL, tegra30_fuse_of_match,
&of_match);
if (np) {
fuse_base = of_iomap(np, 0);
fuse_info = (struct tegra_fuse_info *)of_match->data;
} else
legacy_fuse_init();
if (!fuse_base) {
pr_warn("fuse DT node missing and unknown chip id: 0x%02x\n",
tegra_get_chip_id());
return;
}
tegra_init_revision();
speedo_tbl[fuse_info->speedo_idx](&tegra_sku_info);
tegra30_fuse_add_randomness();
}
