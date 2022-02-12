static u32 tegra30_fuse_read_early(struct tegra_fuse *fuse, unsigned int offset)
{
return readl_relaxed(fuse->base + FUSE_BEGIN + offset);
}
static u32 tegra30_fuse_read(struct tegra_fuse *fuse, unsigned int offset)
{
u32 value;
int err;
err = clk_prepare_enable(fuse->clk);
if (err < 0) {
dev_err(fuse->dev, "failed to enable FUSE clock: %d\n", err);
return 0;
}
value = readl_relaxed(fuse->base + FUSE_BEGIN + offset);
clk_disable_unprepare(fuse->clk);
return value;
}
static void __init tegra30_fuse_add_randomness(void)
{
u32 randomness[12];
randomness[0] = tegra_sku_info.sku_id;
randomness[1] = tegra_read_straps();
randomness[2] = tegra_read_chipid();
randomness[3] = tegra_sku_info.cpu_process_id << 16;
randomness[3] |= tegra_sku_info.soc_process_id;
randomness[4] = tegra_sku_info.cpu_speedo_id << 16;
randomness[4] |= tegra_sku_info.soc_speedo_id;
randomness[5] = tegra_fuse_read_early(FUSE_VENDOR_CODE);
randomness[6] = tegra_fuse_read_early(FUSE_FAB_CODE);
randomness[7] = tegra_fuse_read_early(FUSE_LOT_CODE_0);
randomness[8] = tegra_fuse_read_early(FUSE_LOT_CODE_1);
randomness[9] = tegra_fuse_read_early(FUSE_WAFER_ID);
randomness[10] = tegra_fuse_read_early(FUSE_X_COORDINATE);
randomness[11] = tegra_fuse_read_early(FUSE_Y_COORDINATE);
add_device_randomness(randomness, sizeof(randomness));
}
static void __init tegra30_fuse_init(struct tegra_fuse *fuse)
{
fuse->read_early = tegra30_fuse_read_early;
fuse->read = tegra30_fuse_read;
tegra_init_revision();
fuse->soc->speedo_init(&tegra_sku_info);
tegra30_fuse_add_randomness();
}
