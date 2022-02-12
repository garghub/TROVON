static int __init r8a7791_cpg_mssr_init(struct device *dev)
{
const struct rcar_gen2_cpg_pll_config *cpg_pll_config;
struct device_node *np = dev->of_node;
unsigned int i;
u32 cpg_mode;
int error;
error = rcar_rst_read_mode_pins(&cpg_mode);
if (error)
return error;
cpg_pll_config = &cpg_pll_configs[CPG_PLL_CONFIG_INDEX(cpg_mode)];
if (of_device_is_compatible(np, "renesas,r8a7793-cpg-mssr")) {
for (i = 0; i < ARRAY_SIZE(r8a7791_core_clks); i++)
if (r8a7791_core_clks[i].id == R8A7791_CLK_ZG) {
r8a7791_core_clks[i].div = 5;
break;
}
}
return rcar_gen2_cpg_init(cpg_pll_config, 2, cpg_mode);
}
