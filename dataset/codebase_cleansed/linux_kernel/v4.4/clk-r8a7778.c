static struct clk * __init
r8a7778_cpg_register_clock(struct device_node *np, struct r8a7778_cpg *cpg,
const char *name)
{
if (!strcmp(name, "plla")) {
return clk_register_fixed_factor(NULL, "plla",
of_clk_get_parent_name(np, 0), 0,
r8a7778_rates[cpg_mode_rates].plla_mult, 1);
} else if (!strcmp(name, "pllb")) {
return clk_register_fixed_factor(NULL, "pllb",
of_clk_get_parent_name(np, 0), 0,
r8a7778_rates[cpg_mode_rates].pllb_mult, 1);
} else {
unsigned int i;
for (i = 0; i < ARRAY_SIZE(r8a7778_divs); i++) {
if (!strcmp(name, r8a7778_divs[i].name)) {
return clk_register_fixed_factor(NULL,
r8a7778_divs[i].name,
"plla", 0, 1,
r8a7778_divs[i].div[cpg_mode_divs]);
}
}
}
return ERR_PTR(-EINVAL);
}
static void __init r8a7778_cpg_clocks_init(struct device_node *np)
{
struct r8a7778_cpg *cpg;
struct clk **clks;
unsigned int i;
int num_clks;
num_clks = of_property_count_strings(np, "clock-output-names");
if (num_clks < 0) {
pr_err("%s: failed to count clocks\n", __func__);
return;
}
cpg = kzalloc(sizeof(*cpg), GFP_KERNEL);
clks = kcalloc(num_clks, sizeof(*clks), GFP_KERNEL);
if (cpg == NULL || clks == NULL) {
return;
}
spin_lock_init(&cpg->lock);
cpg->data.clks = clks;
cpg->data.clk_num = num_clks;
cpg->reg = of_iomap(np, 0);
if (WARN_ON(cpg->reg == NULL))
return;
for (i = 0; i < num_clks; ++i) {
const char *name;
struct clk *clk;
of_property_read_string_index(np, "clock-output-names", i,
&name);
clk = r8a7778_cpg_register_clock(np, cpg, name);
if (IS_ERR(clk))
pr_err("%s: failed to register %s %s clock (%ld)\n",
__func__, np->name, name, PTR_ERR(clk));
else
cpg->data.clks[i] = clk;
}
of_clk_add_provider(np, of_clk_src_onecell_get, &cpg->data);
cpg_mstp_add_clk_domain(np);
}
void __init r8a7778_clocks_init(u32 mode)
{
BUG_ON(!(mode & BIT(19)));
cpg_mode_rates = (!!(mode & BIT(18)) << 2) |
(!!(mode & BIT(12)) << 1) |
(!!(mode & BIT(11)));
cpg_mode_divs = (!!(mode & BIT(2)) << 1) |
(!!(mode & BIT(1)));
of_clk_init(NULL);
}
