u32 omap2xxx_get_sysclkdiv(void)
{
u32 div;
div = __raw_readl(prcm_clksrc_ctrl);
div &= OMAP_SYSCLKDIV_MASK;
div >>= OMAP_SYSCLKDIV_SHIFT;
return div;
}
unsigned long omap2xxx_sys_clk_recalc(struct clk *clk)
{
return clk->parent->rate / omap2xxx_get_sysclkdiv();
}
