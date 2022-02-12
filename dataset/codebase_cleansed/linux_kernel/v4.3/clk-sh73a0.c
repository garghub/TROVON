static struct clk * __init
sh73a0_cpg_register_clock(struct device_node *np, struct sh73a0_cpg *cpg,
const char *name)
{
const struct clk_div_table *table = NULL;
unsigned int shift, reg, width;
const char *parent_name;
unsigned int mult = 1;
unsigned int div = 1;
if (!strcmp(name, "main")) {
u32 parent_idx = (clk_readl(cpg->reg + CPG_CKSCR) >> 28) & 3;
parent_name = of_clk_get_parent_name(np, parent_idx >> 1);
div = (parent_idx & 1) + 1;
} else if (!strncmp(name, "pll", 3)) {
void __iomem *enable_reg = cpg->reg;
u32 enable_bit = name[3] - '0';
parent_name = "main";
switch (enable_bit) {
case 0:
enable_reg += CPG_PLL0CR;
break;
case 1:
enable_reg += CPG_PLL1CR;
break;
case 2:
enable_reg += CPG_PLL2CR;
break;
case 3:
enable_reg += CPG_PLL3CR;
break;
default:
return ERR_PTR(-EINVAL);
}
if (clk_readl(cpg->reg + CPG_PLLECR) & BIT(enable_bit)) {
mult = ((clk_readl(enable_reg) >> 24) & 0x3f) + 1;
if (enable_bit == 1 || enable_bit == 2)
if (clk_readl(enable_reg) & BIT(20))
mult *= 2;
}
} else if (!strcmp(name, "dsi0phy") || !strcmp(name, "dsi1phy")) {
u32 phy_no = name[3] - '0';
void __iomem *dsi_reg = cpg->reg +
(phy_no ? CPG_DSI1PHYCR : CPG_DSI0PHYCR);
parent_name = phy_no ? "dsi1pck" : "dsi0pck";
mult = __raw_readl(dsi_reg);
if (!(mult & 0x8000))
mult = 1;
else
mult = (mult & 0x3f) + 1;
} else if (!strcmp(name, "z")) {
parent_name = "pll0";
table = z_div_table;
reg = CPG_FRQCRB;
shift = 24;
width = 5;
} else {
struct div4_clk *c;
for (c = div4_clks; c->name; c++) {
if (!strcmp(name, c->name)) {
parent_name = c->parent;
table = div4_div_table;
reg = c->reg;
shift = c->shift;
width = 4;
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
cpg->reg + reg, shift, width, 0,
table, &cpg->lock);
}
}
static void __init sh73a0_cpg_clocks_init(struct device_node *np)
{
struct sh73a0_cpg *cpg;
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
clk_writel(0x108, cpg->reg + CPG_SD0CKCR);
clk_writel(0x108, cpg->reg + CPG_SD1CKCR);
clk_writel(0x108, cpg->reg + CPG_SD2CKCR);
for (i = 0; i < num_clks; ++i) {
const char *name;
struct clk *clk;
of_property_read_string_index(np, "clock-output-names", i,
&name);
clk = sh73a0_cpg_register_clock(np, cpg, name);
if (IS_ERR(clk))
pr_err("%s: failed to register %s %s clock (%ld)\n",
__func__, np->name, name, PTR_ERR(clk));
else
cpg->data.clks[i] = clk;
}
of_clk_add_provider(np, of_clk_src_onecell_get, &cpg->data);
}
