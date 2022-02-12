static inline u32 fuse_readl(unsigned long offset)
{
return readl(IO_TO_VIRT(TEGRA_FUSE_BASE + offset));
}
static inline void fuse_writel(u32 value, unsigned long offset)
{
writel(value, IO_TO_VIRT(TEGRA_FUSE_BASE + offset));
}
void tegra_init_fuse(void)
{
u32 reg = readl(IO_TO_VIRT(TEGRA_CLK_RESET_BASE + 0x48));
reg |= 1 << 28;
writel(reg, IO_TO_VIRT(TEGRA_CLK_RESET_BASE + 0x48));
pr_info("Tegra SKU: %d CPU Process: %d Core Process: %d\n",
tegra_sku_id(), tegra_cpu_process_id(),
tegra_core_process_id());
}
unsigned long long tegra_chip_uid(void)
{
unsigned long long lo, hi;
lo = fuse_readl(FUSE_UID_LOW);
hi = fuse_readl(FUSE_UID_HIGH);
return (hi << 32ull) | lo;
}
int tegra_sku_id(void)
{
int sku_id;
u32 reg = fuse_readl(FUSE_SKU_INFO);
sku_id = reg & 0xFF;
return sku_id;
}
int tegra_cpu_process_id(void)
{
int cpu_process_id;
u32 reg = fuse_readl(FUSE_SPARE_BIT);
cpu_process_id = (reg >> 6) & 3;
return cpu_process_id;
}
int tegra_core_process_id(void)
{
int core_process_id;
u32 reg = fuse_readl(FUSE_SPARE_BIT);
core_process_id = (reg >> 12) & 3;
return core_process_id;
}
