static void tegra_fuse_enable_clk(void)
{
if (IS_ERR(fuse_clk))
fuse_clk = clk_get_sys(NULL, "fuse");
if (IS_ERR(fuse_clk))
return;
clk_prepare_enable(fuse_clk);
}
static void tegra_fuse_disable_clk(void)
{
if (IS_ERR(fuse_clk))
return;
clk_disable_unprepare(fuse_clk);
}
u32 tegra_fuse_readl(unsigned long offset)
{
return tegra_apb_readl(TEGRA_FUSE_BASE + offset);
}
bool tegra_spare_fuse(int bit)
{
bool ret;
tegra_fuse_enable_clk();
ret = tegra_fuse_readl(tegra_fuse_spare_bit + bit * 4);
tegra_fuse_disable_clk();
return ret;
}
static enum tegra_revision tegra_get_revision(u32 id)
{
u32 minor_rev = (id >> 16) & 0xf;
switch (minor_rev) {
case 1:
return TEGRA_REVISION_A01;
case 2:
return TEGRA_REVISION_A02;
case 3:
if (tegra_chip_id == TEGRA20 &&
(tegra_spare_fuse(18) || tegra_spare_fuse(19)))
return TEGRA_REVISION_A03p;
else
return TEGRA_REVISION_A03;
case 4:
return TEGRA_REVISION_A04;
default:
return TEGRA_REVISION_UNKNOWN;
}
}
static void tegra_get_process_id(void)
{
u32 reg;
tegra_fuse_enable_clk();
reg = tegra_fuse_readl(tegra_fuse_spare_bit);
tegra_cpu_process_id = (reg >> 6) & 3;
reg = tegra_fuse_readl(tegra_fuse_spare_bit);
tegra_core_process_id = (reg >> 12) & 3;
tegra_fuse_disable_clk();
}
u32 tegra_read_chipid(void)
{
return readl_relaxed(IO_ADDRESS(TEGRA_APB_MISC_BASE) + 0x804);
}
static void __init tegra20_fuse_init_randomness(void)
{
u32 randomness[2];
randomness[0] = tegra_fuse_readl(FUSE_UID_LOW);
randomness[1] = tegra_fuse_readl(FUSE_UID_HIGH);
add_device_randomness(randomness, sizeof(randomness));
}
static void __init tegra30_fuse_init_randomness(void)
{
u32 randomness[7];
randomness[0] = tegra_fuse_readl(FUSE_VENDOR_CODE);
randomness[1] = tegra_fuse_readl(FUSE_FAB_CODE);
randomness[2] = tegra_fuse_readl(FUSE_LOT_CODE_0);
randomness[3] = tegra_fuse_readl(FUSE_LOT_CODE_1);
randomness[4] = tegra_fuse_readl(FUSE_WAFER_ID);
randomness[5] = tegra_fuse_readl(FUSE_X_COORDINATE);
randomness[6] = tegra_fuse_readl(FUSE_Y_COORDINATE);
add_device_randomness(randomness, sizeof(randomness));
}
void __init tegra_init_fuse(void)
{
u32 id;
u32 randomness[5];
u32 reg = readl(IO_ADDRESS(TEGRA_CLK_RESET_BASE + 0x48));
reg |= 1 << 28;
writel(reg, IO_ADDRESS(TEGRA_CLK_RESET_BASE + 0x48));
reg = readl(IO_ADDRESS(TEGRA_CLK_RESET_BASE + 0x14));
reg |= 1 << 7;
writel(reg, IO_ADDRESS(TEGRA_CLK_RESET_BASE + 0x14));
fuse_clk = ERR_PTR(-EINVAL);
reg = tegra_fuse_readl(FUSE_SKU_INFO);
randomness[0] = reg;
tegra_sku_id = reg & 0xFF;
reg = tegra_apb_readl(TEGRA_APB_MISC_BASE + STRAP_OPT);
randomness[1] = reg;
tegra_bct_strapping = (reg & RAM_ID_MASK) >> RAM_CODE_SHIFT;
id = tegra_read_chipid();
randomness[2] = id;
tegra_chip_id = (id >> 8) & 0xff;
switch (tegra_chip_id) {
case TEGRA20:
tegra_fuse_spare_bit = TEGRA20_FUSE_SPARE_BIT;
tegra_init_speedo_data = &tegra20_init_speedo_data;
break;
case TEGRA30:
tegra_fuse_spare_bit = TEGRA30_FUSE_SPARE_BIT;
tegra_init_speedo_data = &tegra30_init_speedo_data;
break;
case TEGRA114:
tegra_init_speedo_data = &tegra114_init_speedo_data;
break;
default:
pr_warn("Tegra: unknown chip id %d\n", tegra_chip_id);
tegra_fuse_spare_bit = TEGRA20_FUSE_SPARE_BIT;
tegra_init_speedo_data = &tegra_get_process_id;
}
tegra_revision = tegra_get_revision(id);
tegra_init_speedo_data();
randomness[3] = (tegra_cpu_process_id << 16) | tegra_core_process_id;
randomness[4] = (tegra_cpu_speedo_id << 16) | tegra_soc_speedo_id;
add_device_randomness(randomness, sizeof(randomness));
switch (tegra_chip_id) {
case TEGRA20:
tegra20_fuse_init_randomness();
break;
case TEGRA30:
case TEGRA114:
default:
tegra30_fuse_init_randomness();
break;
}
pr_info("Tegra Revision: %s SKU: %d CPU Process: %d Core Process: %d\n",
tegra_revision_name[tegra_revision],
tegra_sku_id, tegra_cpu_process_id,
tegra_core_process_id);
}
