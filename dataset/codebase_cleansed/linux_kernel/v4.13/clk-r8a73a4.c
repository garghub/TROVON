static struct clk * __init
r8a73a4_cpg_register_clock(struct device_node *np, struct r8a73a4_cpg *cpg,
const char *name)
{
const struct clk_div_table *table = NULL;
const char *parent_name;
unsigned int shift, reg;
unsigned int mult = 1;
unsigned int div = 1;
if (!strcmp(name, "main")) {
u32 ckscr = clk_readl(cpg->reg + CPG_CKSCR);
switch ((ckscr >> 28) & 3) {
case 0:
parent_name = of_clk_get_parent_name(np, 0);
break;
case 1:
parent_name = of_clk_get_parent_name(np, 0);
div = 2;
break;
case 2:
parent_name = of_clk_get_parent_name(np, 1);
break;
case 3:
parent_name = of_clk_get_parent_name(np, 1);
div = 2;
break;
}
} else if (!strcmp(name, "pll0")) {
u32 value = clk_readl(cpg->reg + CPG_PLL0CR);
parent_name = "main";
mult = ((value >> 24) & 0x7f) + 1;
if (value & BIT(20))
div = 2;
} else if (!strcmp(name, "pll1")) {
u32 value = clk_readl(cpg->reg + CPG_PLL1CR);
parent_name = "main";
mult = ((value >> 24) & 0x7f) + 1;
if (value & BIT(7))
div = 2;
} else if (!strncmp(name, "pll2", 4)) {
u32 value, cr;
switch (name[4]) {
case 0:
cr = CPG_PLL2CR;
break;
case 's':
cr = CPG_PLL2SCR;
break;
case 'h':
cr = CPG_PLL2HCR;
break;
default:
return ERR_PTR(-EINVAL);
}
value = clk_readl(cpg->reg + cr);
switch ((value >> 5) & 7) {
case 0:
parent_name = "main";
div = 2;
break;
case 1:
parent_name = "extal2";
div = 2;
break;
case 3:
parent_name = "extal2";
div = 4;
break;
case 4:
parent_name = "main";
break;
case 5:
parent_name = "extal2";
break;
default:
pr_warn("%s: unexpected parent of %s\n", __func__,
name);
return ERR_PTR(-EINVAL);
}
mult = ((value >> 24) & 0x7f) + 1;
} else if (!strcmp(name, "z") || !strcmp(name, "z2")) {
u32 shift = 8;
parent_name = "pll0";
if (name[1] == '2') {
div = 2;
shift = 0;
}
div *= 32;
mult = 0x20 - ((clk_readl(cpg->reg + CPG_FRQCRC) >> shift)
& 0x1f);
} else {
struct div4_clk *c;
for (c = div4_clks; c->name; c++) {
if (!strcmp(name, c->name))
break;
}
if (!c->name)
return ERR_PTR(-EINVAL);
parent_name = "pll1";
table = div4_div_table;
reg = c->reg;
shift = c->shift;
}
if (!table) {
return clk_register_fixed_factor(NULL, name, parent_name, 0,
mult, div);
} else {
return clk_register_divider_table(NULL, name, parent_name, 0,
cpg->reg + reg, shift, 4, 0,
table, &cpg->lock);
}
}
static void __init r8a73a4_cpg_clocks_init(struct device_node *np)
{
struct r8a73a4_cpg *cpg;
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
clk = r8a73a4_cpg_register_clock(np, cpg, name);
if (IS_ERR(clk))
pr_err("%s: failed to register %s %s clock (%ld)\n",
__func__, np->name, name, PTR_ERR(clk));
else
cpg->data.clks[i] = clk;
}
of_clk_add_provider(np, of_clk_src_onecell_get, &cpg->data);
}
