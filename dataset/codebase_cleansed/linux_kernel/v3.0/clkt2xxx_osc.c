static int omap2_enable_osc_ck(struct clk *clk)
{
u32 pcc;
pcc = __raw_readl(prcm_clksrc_ctrl);
__raw_writel(pcc & ~OMAP_AUTOEXTCLKMODE_MASK, prcm_clksrc_ctrl);
return 0;
}
static void omap2_disable_osc_ck(struct clk *clk)
{
u32 pcc;
pcc = __raw_readl(prcm_clksrc_ctrl);
__raw_writel(pcc | OMAP_AUTOEXTCLKMODE_MASK, prcm_clksrc_ctrl);
}
unsigned long omap2_osc_clk_recalc(struct clk *clk)
{
return omap2xxx_get_apll_clkin() * omap2xxx_get_sysclkdiv();
}
