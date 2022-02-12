static int __init r8a7790_cpg_mssr_init(struct device *dev)
{
const struct rcar_gen2_cpg_pll_config *cpg_pll_config;
u32 cpg_mode;
int error;
error = rcar_rst_read_mode_pins(&cpg_mode);
if (error)
return error;
cpg_pll_config = &cpg_pll_configs[CPG_PLL_CONFIG_INDEX(cpg_mode)];
return rcar_gen2_cpg_init(cpg_pll_config, 2, cpg_mode);
}
