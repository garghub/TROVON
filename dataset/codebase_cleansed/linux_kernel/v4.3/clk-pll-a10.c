static unsigned long clk_pll_recalc_rate(struct clk_hw *hwclk,
unsigned long parent_rate)
{
struct socfpga_pll *socfpgaclk = to_socfpga_clk(hwclk);
unsigned long divf, divq, reg;
unsigned long long vco_freq;
reg = readl(socfpgaclk->hw.reg + 0x4);
divf = (reg & SOCFPGA_PLL_DIVF_MASK) >> SOCFPGA_PLL_DIVF_SHIFT;
divq = (reg & SOCFPGA_PLL_DIVQ_MASK) >> SOCFPGA_PLL_DIVQ_SHIFT;
vco_freq = (unsigned long long)parent_rate * (divf + 1);
do_div(vco_freq, (1 + divq));
return (unsigned long)vco_freq;
}
static u8 clk_pll_get_parent(struct clk_hw *hwclk)
{
struct socfpga_pll *socfpgaclk = to_socfpga_clk(hwclk);
u32 pll_src;
pll_src = readl(socfpgaclk->hw.reg);
return (pll_src >> CLK_MGR_PLL_CLK_SRC_SHIFT) &
CLK_MGR_PLL_CLK_SRC_MASK;
}
static struct __init clk * __socfpga_pll_init(struct device_node *node,
const struct clk_ops *ops)
{
u32 reg;
struct clk *clk;
struct socfpga_pll *pll_clk;
const char *clk_name = node->name;
const char *parent_name[SOCFGPA_MAX_PARENTS];
struct clk_init_data init;
struct device_node *clkmgr_np;
int rc;
int i = 0;
of_property_read_u32(node, "reg", &reg);
pll_clk = kzalloc(sizeof(*pll_clk), GFP_KERNEL);
if (WARN_ON(!pll_clk))
return NULL;
clkmgr_np = of_find_compatible_node(NULL, NULL, "altr,clk-mgr");
clk_mgr_a10_base_addr = of_iomap(clkmgr_np, 0);
BUG_ON(!clk_mgr_a10_base_addr);
pll_clk->hw.reg = clk_mgr_a10_base_addr + reg;
of_property_read_string(node, "clock-output-names", &clk_name);
init.name = clk_name;
init.ops = ops;
init.flags = 0;
while (i < SOCFGPA_MAX_PARENTS && (parent_name[i] =
of_clk_get_parent_name(node, i)) != NULL)
i++;
init.num_parents = i;
init.parent_names = parent_name;
pll_clk->hw.hw.init = &init;
pll_clk->hw.bit_idx = SOCFPGA_PLL_EXT_ENA;
clk_pll_ops.enable = clk_gate_ops.enable;
clk_pll_ops.disable = clk_gate_ops.disable;
clk = clk_register(NULL, &pll_clk->hw.hw);
if (WARN_ON(IS_ERR(clk))) {
kfree(pll_clk);
return NULL;
}
rc = of_clk_add_provider(node, of_clk_src_simple_get, clk);
return clk;
}
void __init socfpga_a10_pll_init(struct device_node *node)
{
__socfpga_pll_init(node, &clk_pll_ops);
}
