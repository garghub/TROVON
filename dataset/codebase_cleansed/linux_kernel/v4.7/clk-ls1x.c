static int ls1x_pll_clk_enable(struct clk_hw *hw)
{
return 0;
}
static void ls1x_pll_clk_disable(struct clk_hw *hw)
{
}
static unsigned long ls1x_pll_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
u32 pll, rate;
pll = __raw_readl(LS1X_CLK_PLL_FREQ);
rate = 12 + (pll & 0x3f) + (((pll >> 8) & 0x3ff) >> 10);
rate *= OSC;
rate >>= 1;
return rate;
}
static struct clk *__init clk_register_pll(struct device *dev,
const char *name,
const char *parent_name,
unsigned long flags)
{
struct clk_hw *hw;
struct clk *clk;
struct clk_init_data init;
hw = kzalloc(sizeof(struct clk_hw), GFP_KERNEL);
if (!hw) {
pr_err("%s: could not allocate clk_hw\n", __func__);
return ERR_PTR(-ENOMEM);
}
init.name = name;
init.ops = &ls1x_pll_clk_ops;
init.flags = flags | CLK_IS_BASIC;
init.parent_names = (parent_name ? &parent_name : NULL);
init.num_parents = (parent_name ? 1 : 0);
hw->init = &init;
clk = clk_register(dev, hw);
if (IS_ERR(clk))
kfree(hw);
return clk;
}
void __init ls1x_clk_init(void)
{
struct clk *clk;
clk = clk_register_fixed_rate(NULL, "osc_33m_clk", NULL, 0, OSC);
clk_register_clkdev(clk, "osc_33m_clk", NULL);
clk = clk_register_pll(NULL, "pll_clk", "osc_33m_clk", 0);
clk_register_clkdev(clk, "pll_clk", NULL);
clk = clk_register_divider(NULL, "cpu_clk_div", "pll_clk",
CLK_GET_RATE_NOCACHE, LS1X_CLK_PLL_DIV,
DIV_CPU_SHIFT, DIV_CPU_WIDTH,
CLK_DIVIDER_ONE_BASED |
CLK_DIVIDER_ROUND_CLOSEST, &_lock);
clk_register_clkdev(clk, "cpu_clk_div", NULL);
clk = clk_register_mux(NULL, "cpu_clk", cpu_parents,
ARRAY_SIZE(cpu_parents),
CLK_SET_RATE_NO_REPARENT, LS1X_CLK_PLL_DIV,
BYPASS_CPU_SHIFT, BYPASS_CPU_WIDTH, 0, &_lock);
clk_register_clkdev(clk, "cpu_clk", NULL);
clk = clk_register_divider(NULL, "dc_clk_div", "pll_clk",
0, LS1X_CLK_PLL_DIV, DIV_DC_SHIFT,
DIV_DC_WIDTH, CLK_DIVIDER_ONE_BASED, &_lock);
clk_register_clkdev(clk, "dc_clk_div", NULL);
clk = clk_register_mux(NULL, "dc_clk", dc_parents,
ARRAY_SIZE(dc_parents),
CLK_SET_RATE_NO_REPARENT, LS1X_CLK_PLL_DIV,
BYPASS_DC_SHIFT, BYPASS_DC_WIDTH, 0, &_lock);
clk_register_clkdev(clk, "dc_clk", NULL);
clk = clk_register_divider(NULL, "ahb_clk_div", "pll_clk",
0, LS1X_CLK_PLL_DIV, DIV_DDR_SHIFT,
DIV_DDR_WIDTH, CLK_DIVIDER_ONE_BASED,
&_lock);
clk_register_clkdev(clk, "ahb_clk_div", NULL);
clk = clk_register_mux(NULL, "ahb_clk", ahb_parents,
ARRAY_SIZE(ahb_parents),
CLK_SET_RATE_NO_REPARENT, LS1X_CLK_PLL_DIV,
BYPASS_DDR_SHIFT, BYPASS_DDR_WIDTH, 0, &_lock);
clk_register_clkdev(clk, "ahb_clk", NULL);
clk_register_clkdev(clk, "stmmaceth", NULL);
clk = clk_register_fixed_factor(NULL, "apb_clk", "ahb_clk", 0, 1,
DIV_APB);
clk_register_clkdev(clk, "apb_clk", NULL);
clk_register_clkdev(clk, "ls1x_i2c", NULL);
clk_register_clkdev(clk, "ls1x_pwmtimer", NULL);
clk_register_clkdev(clk, "ls1x_spi", NULL);
clk_register_clkdev(clk, "ls1x_wdt", NULL);
clk_register_clkdev(clk, "serial8250", NULL);
}
