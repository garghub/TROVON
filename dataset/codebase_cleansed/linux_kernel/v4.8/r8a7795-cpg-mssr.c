static int __init r8a7795_cpg_mssr_init(struct device *dev)
{
const struct rcar_gen3_cpg_pll_config *cpg_pll_config;
u32 cpg_mode = rcar_gen3_read_mode_pins();
cpg_pll_config = &cpg_pll_configs[CPG_PLL_CONFIG_INDEX(cpg_mode)];
if (!cpg_pll_config->extal_div) {
dev_err(dev, "Prohibited setting (cpg_mode=0x%x)\n", cpg_mode);
return -EINVAL;
}
return rcar_gen3_cpg_init(cpg_pll_config, CLK_EXTALR);
}
