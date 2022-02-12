static struct clk * __init
r8a7779_cpg_register_clock(struct device_node *np, struct r8a7779_cpg *cpg,
const struct cpg_clk_config *config,
unsigned int plla_mult, const char *name)
{
const char *parent_name = "plla";
unsigned int mult = 1;
unsigned int div = 1;
if (!strcmp(name, "plla")) {
parent_name = of_clk_get_parent_name(np, 0);
mult = plla_mult;
} else if (!strcmp(name, "z")) {
div = config->z_div;
mult = config->z_mult;
} else if (!strcmp(name, "zs") || !strcmp(name, "s")) {
div = config->zs_and_s_div;
} else if (!strcmp(name, "s1")) {
div = config->s1_div;
} else if (!strcmp(name, "p")) {
div = config->p_div;
} else if (!strcmp(name, "b") || !strcmp(name, "out")) {
div = config->b_and_out_div;
} else {
return ERR_PTR(-EINVAL);
}
return clk_register_fixed_factor(NULL, name, parent_name, 0, mult, div);
}
static void __init r8a7779_cpg_clocks_init(struct device_node *np)
{
const struct cpg_clk_config *config;
struct r8a7779_cpg *cpg;
struct clk **clks;
unsigned int i, plla_mult;
int num_clks;
u32 mode;
if (rcar_rst_read_mode_pins(&mode))
return;
num_clks = of_property_count_strings(np, "clock-output-names");
if (num_clks < 0) {
pr_err("%s: failed to count clocks\n", __func__);
return;
}
cpg = kzalloc(sizeof(*cpg), GFP_KERNEL);
clks = kzalloc(CPG_NUM_CLOCKS * sizeof(*clks), GFP_KERNEL);
if (cpg == NULL || clks == NULL) {
return;
}
spin_lock_init(&cpg->lock);
cpg->data.clks = clks;
cpg->data.clk_num = num_clks;
config = &cpg_clk_configs[CPG_CLK_CONFIG_INDEX(mode)];
plla_mult = cpg_plla_mult[CPG_PLLA_MULT_INDEX(mode)];
for (i = 0; i < num_clks; ++i) {
const char *name;
struct clk *clk;
of_property_read_string_index(np, "clock-output-names", i,
&name);
clk = r8a7779_cpg_register_clock(np, cpg, config,
plla_mult, name);
if (IS_ERR(clk))
pr_err("%s: failed to register %s %s clock (%ld)\n",
__func__, np->name, name, PTR_ERR(clk));
else
cpg->data.clks[i] = clk;
}
of_clk_add_provider(np, of_clk_src_onecell_get, &cpg->data);
cpg_mstp_add_clk_domain(np);
}
