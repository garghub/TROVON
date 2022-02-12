static struct clk * __init
r8a7740_cpg_register_clock(struct device_node *np, struct r8a7740_cpg *cpg,
const char *name)
{
const struct clk_div_table *table = NULL;
const char *parent_name;
unsigned int shift, reg;
unsigned int mult = 1;
unsigned int div = 1;
if (!strcmp(name, "r")) {
switch (cpg_mode & (BIT(2) | BIT(1))) {
case BIT(1) | BIT(2):
parent_name = of_clk_get_parent_name(np, 0);
div = 2048;
break;
case BIT(2):
parent_name = of_clk_get_parent_name(np, 0);
div = 1024;
break;
default:
parent_name = of_clk_get_parent_name(np, 2);
break;
}
} else if (!strcmp(name, "system")) {
parent_name = of_clk_get_parent_name(np, 0);
if (cpg_mode & BIT(1))
div = 2;
} else if (!strcmp(name, "pllc0")) {
u32 value = clk_readl(cpg->reg + CPG_FRQCRC);
parent_name = "system";
mult = ((value >> 24) & 0x7f) + 1;
} else if (!strcmp(name, "pllc1")) {
u32 value = clk_readl(cpg->reg + CPG_FRQCRA);
parent_name = "system";
mult = ((value >> 24) & 0x7f) + 1;
div = 2;
} else if (!strcmp(name, "pllc2")) {
u32 value = clk_readl(cpg->reg + CPG_PLLC2CR);
parent_name = "system";
mult = ((value >> 24) & 0x3f) + 1;
} else if (!strcmp(name, "usb24s")) {
u32 value = clk_readl(cpg->reg + CPG_USBCKCR);
if (value & BIT(7))
parent_name = of_clk_get_parent_name(np, 1);
else
parent_name = "system";
if (!(value & BIT(6)))
div = 2;
} else {
struct div4_clk *c;
for (c = div4_clks; c->name; c++) {
if (!strcmp(name, c->name)) {
parent_name = "pllc1";
table = div4_div_table;
reg = c->reg;
shift = c->shift;
break;
}
}
if (!c->name)
return ERR_PTR(-EINVAL);
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
static void __init r8a7740_cpg_clocks_init(struct device_node *np)
{
struct r8a7740_cpg *cpg;
struct clk **clks;
unsigned int i;
int num_clks;
if (of_property_read_u32(np, "renesas,mode", &cpg_mode))
pr_warn("%s: missing renesas,mode property\n", __func__);
num_clks = of_property_count_strings(np, "clock-output-names");
if (num_clks < 0) {
pr_err("%s: failed to count clocks\n", __func__);
return;
}
cpg = kzalloc(sizeof(*cpg), GFP_KERNEL);
clks = kzalloc(num_clks * sizeof(*clks), GFP_KERNEL);
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
clk = r8a7740_cpg_register_clock(np, cpg, name);
if (IS_ERR(clk))
pr_err("%s: failed to register %s %s clock (%ld)\n",
__func__, np->name, name, PTR_ERR(clk));
else
cpg->data.clks[i] = clk;
}
of_clk_add_provider(np, of_clk_src_onecell_get, &cpg->data);
}
