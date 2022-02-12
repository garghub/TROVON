int s5p_gatectrl(void __iomem *reg, struct clk *clk, int enable)
{
unsigned int ctrlbit = clk->ctrlbit;
u32 con;
con = __raw_readl(reg);
con = enable ? (con | ctrlbit) : (con & ~ctrlbit);
__raw_writel(con, reg);
return 0;
}
int s5p_epll_enable(struct clk *clk, int enable)
{
unsigned int ctrlbit = clk->ctrlbit;
unsigned int epll_con = __raw_readl(S5P_EPLL_CON) & ~ctrlbit;
if (enable)
__raw_writel(epll_con | ctrlbit, S5P_EPLL_CON);
else
__raw_writel(epll_con, S5P_EPLL_CON);
return 0;
}
unsigned long s5p_epll_get_rate(struct clk *clk)
{
return clk->rate;
}
int s5p_spdif_set_rate(struct clk *clk, unsigned long rate)
{
struct clk *pclk;
int ret;
pclk = clk_get_parent(clk);
if (IS_ERR(pclk))
return -EINVAL;
ret = pclk->ops->set_rate(pclk, rate);
clk_put(pclk);
return ret;
}
unsigned long s5p_spdif_get_rate(struct clk *clk)
{
struct clk *pclk;
int rate;
pclk = clk_get_parent(clk);
if (IS_ERR(pclk))
return -EINVAL;
rate = pclk->ops->get_rate(pclk);
clk_put(pclk);
return rate;
}
void __init s5p_register_clocks(unsigned long xtal_freq)
{
int ret;
clk_ext_xtal_mux.rate = xtal_freq;
ret = s3c24xx_register_clocks(s5p_clks, ARRAY_SIZE(s5p_clks));
if (ret > 0)
printk(KERN_ERR "Failed to register s5p clocks\n");
}
