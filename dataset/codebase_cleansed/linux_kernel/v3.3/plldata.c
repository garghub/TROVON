static void __init c6455_setup_clocks(struct device_node *node)
{
struct pll_data *pll = &c6x_soc_pll1;
struct clk *sysclks = pll->sysclks;
pll->flags = PLL_HAS_PRE | PLL_HAS_MUL;
sysclks[2].flags |= FIXED_DIV_PLL;
sysclks[2].div = 3;
sysclks[3].flags |= FIXED_DIV_PLL;
sysclks[3].div = 6;
sysclks[4].div = PLLDIV4;
sysclks[5].div = PLLDIV5;
c6x_core_clk.parent = &sysclks[0];
c6x_i2c_clk.parent = &sysclks[3];
c6x_watchdog_clk.parent = &sysclks[3];
c6x_mdio_clk.parent = &sysclks[3];
c6x_clks_init(c6455_clks);
}
static void __init c6457_setup_clocks(struct device_node *node)
{
struct pll_data *pll = &c6x_soc_pll1;
struct clk *sysclks = pll->sysclks;
pll->flags = PLL_HAS_MUL | PLL_HAS_POST;
sysclks[1].flags |= FIXED_DIV_PLL;
sysclks[1].div = 1;
sysclks[2].flags |= FIXED_DIV_PLL;
sysclks[2].div = 3;
sysclks[3].flags |= FIXED_DIV_PLL;
sysclks[3].div = 6;
sysclks[4].div = PLLDIV4;
sysclks[5].div = PLLDIV5;
c6x_core_clk.parent = &sysclks[1];
c6x_i2c_clk.parent = &sysclks[3];
c6x_watchdog_clk.parent = &sysclks[5];
c6x_mdio_clk.parent = &sysclks[5];
c6x_clks_init(c6457_clks);
}
static void __init c6472_setup_clocks(struct device_node *node)
{
struct pll_data *pll = &c6x_soc_pll1;
struct clk *sysclks = pll->sysclks;
int i;
pll->flags = PLL_HAS_MUL;
for (i = 1; i <= 6; i++) {
sysclks[i].flags |= FIXED_DIV_PLL;
sysclks[i].div = 1;
}
sysclks[7].flags |= FIXED_DIV_PLL;
sysclks[7].div = 3;
sysclks[8].flags |= FIXED_DIV_PLL;
sysclks[8].div = 6;
sysclks[9].flags |= FIXED_DIV_PLL;
sysclks[9].div = 2;
sysclks[10].div = PLLDIV10;
c6x_core_clk.parent = &sysclks[get_coreid() + 1];
c6x_i2c_clk.parent = &sysclks[8];
c6x_watchdog_clk.parent = &sysclks[8];
c6x_mdio_clk.parent = &sysclks[5];
c6x_clks_init(c6472_clks);
}
static void __init c6474_setup_clocks(struct device_node *node)
{
struct pll_data *pll = &c6x_soc_pll1;
struct clk *sysclks = pll->sysclks;
pll->flags = PLL_HAS_MUL;
sysclks[7].flags |= FIXED_DIV_PLL;
sysclks[7].div = 1;
sysclks[9].flags |= FIXED_DIV_PLL;
sysclks[9].div = 3;
sysclks[10].flags |= FIXED_DIV_PLL;
sysclks[10].div = 6;
sysclks[11].div = PLLDIV11;
sysclks[12].flags |= FIXED_DIV_PLL;
sysclks[12].div = 2;
sysclks[13].div = PLLDIV13;
c6x_core_clk.parent = &sysclks[7];
c6x_i2c_clk.parent = &sysclks[10];
c6x_watchdog_clk.parent = &sysclks[10];
c6x_mcbsp1_clk.parent = &sysclks[10];
c6x_mcbsp2_clk.parent = &sysclks[10];
c6x_clks_init(c6474_clks);
}
void __init c64x_setup_clocks(void)
{
void (*__setup_clocks)(struct device_node *np);
struct pll_data *pll = &c6x_soc_pll1;
struct device_node *node;
const struct of_device_id *id;
int err;
u32 val;
node = of_find_matching_node(NULL, c6x_clkc_match);
if (!node)
return;
pll->base = of_iomap(node, 0);
if (!pll->base)
goto out;
err = of_property_read_u32(node, "clock-frequency", &val);
if (err || val == 0) {
pr_err("%s: no clock-frequency found! Using %dMHz\n",
node->full_name, (int)val / 1000000);
val = 25000000;
}
clkin1.rate = val;
err = of_property_read_u32(node, "ti,c64x+pll-bypass-delay", &val);
if (err)
val = 5000;
pll->bypass_delay = val;
err = of_property_read_u32(node, "ti,c64x+pll-reset-delay", &val);
if (err)
val = 30000;
pll->reset_delay = val;
err = of_property_read_u32(node, "ti,c64x+pll-lock-delay", &val);
if (err)
val = 30000;
pll->lock_delay = val;
id = of_match_node(c6x_clkc_match, node);
if (id && id->data) {
__setup_clocks = id->data;
__setup_clocks(node);
}
out:
of_node_put(node);
}
