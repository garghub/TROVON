struct clk *clk_get(struct device *dev, const char *id)
{
return NULL;
}
int clk_enable(struct clk *clk)
{
return 0;
}
void clk_disable(struct clk *clk)
{
}
void clk_put(struct clk *clk)
{
}
unsigned long clk_get_rate(struct clk *clk)
{
return MCF_CLK;
}
