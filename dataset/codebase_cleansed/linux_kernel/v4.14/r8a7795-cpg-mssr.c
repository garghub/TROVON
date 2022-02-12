static int __init r8a7795_cpg_mssr_init(struct device *dev)
{
const struct rcar_gen3_cpg_pll_config *cpg_pll_config;
u32 cpg_mode;
int error;
error = rcar_rst_read_mode_pins(&cpg_mode);
if (error)
return error;
cpg_pll_config = &cpg_pll_configs[CPG_PLL_CONFIG_INDEX(cpg_mode)];
if (!cpg_pll_config->extal_div) {
dev_err(dev, "Prohibited setting (cpg_mode=0x%x)\n", cpg_mode);
return -EINVAL;
}
if (soc_device_match(r8a7795es1)) {
cpg_core_nullify_range(r8a7795_core_clks,
ARRAY_SIZE(r8a7795_core_clks),
R8A7795_CLK_S0D2, R8A7795_CLK_S0D12);
mssr_mod_nullify(r8a7795_mod_clks,
ARRAY_SIZE(r8a7795_mod_clks),
r8a7795es1_mod_nullify,
ARRAY_SIZE(r8a7795es1_mod_nullify));
mssr_mod_reparent(r8a7795_mod_clks,
ARRAY_SIZE(r8a7795_mod_clks),
r8a7795es1_mod_reparent,
ARRAY_SIZE(r8a7795es1_mod_reparent));
} else {
mssr_mod_nullify(r8a7795_mod_clks,
ARRAY_SIZE(r8a7795_mod_clks),
r8a7795es2_mod_nullify,
ARRAY_SIZE(r8a7795es2_mod_nullify));
}
return rcar_gen3_cpg_init(cpg_pll_config, CLK_EXTALR, cpg_mode);
}
