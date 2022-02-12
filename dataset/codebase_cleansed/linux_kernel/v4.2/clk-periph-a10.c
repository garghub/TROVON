static unsigned long clk_periclk_recalc_rate(struct clk_hw *hwclk,
unsigned long parent_rate)
{
struct socfpga_periph_clk *socfpgaclk = to_socfpga_periph_clk(hwclk);
u32 div;
if (socfpgaclk->fixed_div) {
div = socfpgaclk->fixed_div;
} else if (socfpgaclk->div_reg) {
div = readl(socfpgaclk->div_reg) >> socfpgaclk->shift;
div &= div_mask(socfpgaclk->width);
div += 1;
} else {
div = ((readl(socfpgaclk->hw.reg) & 0x7ff) + 1);
}
return parent_rate / div;
}
static u8 clk_periclk_get_parent(struct clk_hw *hwclk)
{
struct socfpga_periph_clk *socfpgaclk = to_socfpga_periph_clk(hwclk);
u32 clk_src;
clk_src = readl(socfpgaclk->hw.reg);
if (streq(hwclk->init->name, SOCFPGA_MPU_FREE_CLK) ||
streq(hwclk->init->name, SOCFPGA_NOC_FREE_CLK) ||
streq(hwclk->init->name, SOCFPGA_SDMMC_FREE_CLK))
return (clk_src >> CLK_MGR_FREE_SHIFT) &
CLK_MGR_FREE_MASK;
else
return 0;
}
static __init void __socfpga_periph_init(struct device_node *node,
const struct clk_ops *ops)
{
u32 reg;
struct clk *clk;
struct socfpga_periph_clk *periph_clk;
const char *clk_name = node->name;
const char *parent_name;
struct clk_init_data init;
int rc;
u32 fixed_div;
u32 div_reg[3];
of_property_read_u32(node, "reg", &reg);
periph_clk = kzalloc(sizeof(*periph_clk), GFP_KERNEL);
if (WARN_ON(!periph_clk))
return;
periph_clk->hw.reg = clk_mgr_a10_base_addr + reg;
rc = of_property_read_u32_array(node, "div-reg", div_reg, 3);
if (!rc) {
periph_clk->div_reg = clk_mgr_a10_base_addr + div_reg[0];
periph_clk->shift = div_reg[1];
periph_clk->width = div_reg[2];
} else {
periph_clk->div_reg = NULL;
}
rc = of_property_read_u32(node, "fixed-divider", &fixed_div);
if (rc)
periph_clk->fixed_div = 0;
else
periph_clk->fixed_div = fixed_div;
of_property_read_string(node, "clock-output-names", &clk_name);
init.name = clk_name;
init.ops = ops;
init.flags = 0;
parent_name = of_clk_get_parent_name(node, 0);
init.num_parents = 1;
init.parent_names = &parent_name;
periph_clk->hw.hw.init = &init;
clk = clk_register(NULL, &periph_clk->hw.hw);
if (WARN_ON(IS_ERR(clk))) {
kfree(periph_clk);
return;
}
rc = of_clk_add_provider(node, of_clk_src_simple_get, clk);
if (rc < 0) {
pr_err("Could not register clock provider for node:%s\n",
clk_name);
goto err_clk;
}
return;
err_clk:
clk_unregister(clk);
}
void __init socfpga_a10_periph_init(struct device_node *node)
{
__socfpga_periph_init(node, &periclk_ops);
}
