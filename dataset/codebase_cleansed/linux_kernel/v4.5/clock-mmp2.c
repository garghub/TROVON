static void sdhc_clk_enable(struct clk *clk)
{
uint32_t clk_rst;
clk_rst = __raw_readl(clk->clk_rst);
clk_rst |= clk->enable_val;
__raw_writel(clk_rst, clk->clk_rst);
}
static void sdhc_clk_disable(struct clk *clk)
{
uint32_t clk_rst;
clk_rst = __raw_readl(clk->clk_rst);
clk_rst &= ~clk->enable_val;
__raw_writel(clk_rst, clk->clk_rst);
}
void __init mmp2_clk_init(phys_addr_t mpmu_phys, phys_addr_t apmu_phys,
phys_addr_t apbc_phys)
{
clkdev_add_table(ARRAY_AND_SIZE(mmp2_clkregs));
}
