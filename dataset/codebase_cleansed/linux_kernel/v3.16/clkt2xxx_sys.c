u32 omap2xxx_get_sysclkdiv(void)
{
u32 div;
div = readl_relaxed(prcm_clksrc_ctrl);
div &= OMAP_SYSCLKDIV_MASK;
div >>= OMAP_SYSCLKDIV_SHIFT;
return div;
}
unsigned long omap2xxx_sys_clk_recalc(struct clk_hw *clk,
unsigned long parent_rate)
{
return parent_rate / omap2xxx_get_sysclkdiv();
}
