void clk_pxa2xx_cken_enable(struct clk *clk)
{
CKEN |= 1 << clk->cken;
}
void clk_pxa2xx_cken_disable(struct clk *clk)
{
CKEN &= ~(1 << clk->cken);
}
static int pxa2xx_clock_suspend(void)
{
saved_cken = CKEN;
return 0;
}
static void pxa2xx_clock_resume(void)
{
CKEN = saved_cken;
}
