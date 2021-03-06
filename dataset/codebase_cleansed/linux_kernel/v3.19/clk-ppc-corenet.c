static int cmux_set_parent(struct clk_hw *hw, u8 idx)
{
struct cmux_clk *clk = to_cmux_clk(hw);
u32 clksel;
clksel = ((idx / clocks_per_pll) << 2) + idx % clocks_per_pll;
if (clk->flags & CLKSEL_ADJUST)
clksel += 8;
clksel = (clksel & 0xf) << CLKSEL_SHIFT;
iowrite32be(clksel, clk->reg);
return 0;
}
static u8 cmux_get_parent(struct clk_hw *hw)
{
struct cmux_clk *clk = to_cmux_clk(hw);
u32 clksel;
clksel = ioread32be(clk->reg);
clksel = (clksel >> CLKSEL_SHIFT) & 0xf;
if (clk->flags & CLKSEL_ADJUST)
clksel -= 8;
clksel = (clksel >> 2) * clocks_per_pll + clksel % 4;
return clksel;
}
static void __init core_mux_init(struct device_node *np)
{
struct clk *clk;
struct clk_init_data init;
struct cmux_clk *cmux_clk;
struct device_node *node;
int rc, count, i;
u32 offset;
const char *clk_name;
const char **parent_names;
rc = of_property_read_u32(np, "reg", &offset);
if (rc) {
pr_err("%s: could not get reg property\n", np->name);
return;
}
count = of_property_count_strings(np, "clock-names");
if (count < 0) {
pr_err("%s: get clock count error\n", np->name);
return;
}
parent_names = kzalloc((sizeof(char *) * count), GFP_KERNEL);
if (!parent_names) {
pr_err("%s: could not allocate parent_names\n", __func__);
return;
}
for (i = 0; i < count; i++)
parent_names[i] = of_clk_get_parent_name(np, i);
cmux_clk = kzalloc(sizeof(struct cmux_clk), GFP_KERNEL);
if (!cmux_clk) {
pr_err("%s: could not allocate cmux_clk\n", __func__);
goto err_name;
}
cmux_clk->reg = of_iomap(np, 0);
if (!cmux_clk->reg) {
pr_err("%s: could not map register\n", __func__);
goto err_clk;
}
node = of_find_compatible_node(NULL, NULL, "fsl,p4080-clockgen");
if (node && (offset >= 0x80))
cmux_clk->flags = CLKSEL_ADJUST;
rc = of_property_read_string_index(np, "clock-output-names",
0, &clk_name);
if (rc) {
pr_err("%s: read clock names error\n", np->name);
goto err_clk;
}
init.name = clk_name;
init.ops = &cmux_ops;
init.parent_names = parent_names;
init.num_parents = count;
init.flags = 0;
cmux_clk->hw.init = &init;
clk = clk_register(NULL, &cmux_clk->hw);
if (IS_ERR(clk)) {
pr_err("%s: could not register clock\n", clk_name);
goto err_clk;
}
rc = of_clk_add_provider(np, of_clk_src_simple_get, clk);
if (rc) {
pr_err("Could not register clock provider for node:%s\n",
np->name);
goto err_clk;
}
goto err_name;
err_clk:
kfree(cmux_clk);
err_name:
kfree(parent_names);
}
static void __init core_pll_init(struct device_node *np)
{
u32 mult;
int i, rc, count;
const char *clk_name, *parent_name;
struct clk_onecell_data *onecell_data;
struct clk **subclks;
void __iomem *base;
base = of_iomap(np, 0);
if (!base) {
pr_err("clk-ppc: iomap error\n");
return;
}
mult = ioread32be(base);
if (mult & PLL_KILL) {
pr_debug("PLL:%s is disabled\n", np->name);
goto err_map;
}
mult = (mult >> 1) & 0x3f;
parent_name = of_clk_get_parent_name(np, 0);
if (!parent_name) {
pr_err("PLL: %s must have a parent\n", np->name);
goto err_map;
}
count = of_property_count_strings(np, "clock-output-names");
if (count < 0 || count > 4) {
pr_err("%s: clock is not supported\n", np->name);
goto err_map;
}
clocks_per_pll = count;
subclks = kzalloc(sizeof(struct clk *) * count, GFP_KERNEL);
if (!subclks) {
pr_err("%s: could not allocate subclks\n", __func__);
goto err_map;
}
onecell_data = kzalloc(sizeof(struct clk_onecell_data), GFP_KERNEL);
if (!onecell_data) {
pr_err("%s: could not allocate onecell_data\n", __func__);
goto err_clks;
}
for (i = 0; i < count; i++) {
rc = of_property_read_string_index(np, "clock-output-names",
i, &clk_name);
if (rc) {
pr_err("%s: could not get clock names\n", np->name);
goto err_cell;
}
if (count == 4)
subclks[i] = clk_register_fixed_factor(NULL, clk_name,
parent_name, 0, mult, 1 + i);
else
subclks[i] = clk_register_fixed_factor(NULL, clk_name,
parent_name, 0, mult, 1 << i);
if (IS_ERR(subclks[i])) {
pr_err("%s: could not register clock\n", clk_name);
goto err_cell;
}
}
onecell_data->clks = subclks;
onecell_data->clk_num = count;
rc = of_clk_add_provider(np, of_clk_src_onecell_get, onecell_data);
if (rc) {
pr_err("Could not register clk provider for node:%s\n",
np->name);
goto err_cell;
}
iounmap(base);
return;
err_cell:
kfree(onecell_data);
err_clks:
kfree(subclks);
err_map:
iounmap(base);
}
static void __init sysclk_init(struct device_node *node)
{
struct clk *clk;
const char *clk_name = node->name;
struct device_node *np = of_get_parent(node);
u32 rate;
if (!np) {
pr_err("ppc-clk: could not get parent node\n");
return;
}
if (of_property_read_u32(np, "clock-frequency", &rate)) {
of_node_put(node);
return;
}
of_property_read_string(np, "clock-output-names", &clk_name);
clk = clk_register_fixed_rate(NULL, clk_name, NULL, CLK_IS_ROOT, rate);
if (!IS_ERR(clk))
of_clk_add_provider(np, of_clk_src_simple_get, clk);
}
static int __init ppc_corenet_clk_probe(struct platform_device *pdev)
{
of_clk_init(clk_match);
return 0;
}
static int __init ppc_corenet_clk_init(void)
{
return platform_driver_register(&ppc_corenet_clk_driver);
}
