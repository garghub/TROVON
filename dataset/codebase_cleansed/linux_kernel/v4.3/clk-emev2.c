static void __init emev2_smu_write(unsigned long value, int offs)
{
BUG_ON(!smu_base || (offs >= PAGE_SIZE));
writel_relaxed(value, smu_base + offs);
}
static void __init emev2_smu_init(void)
{
struct device_node *np;
np = of_find_matching_node(NULL, smu_id);
BUG_ON(!np);
smu_base = of_iomap(np, 0);
BUG_ON(!smu_base);
of_node_put(np);
emev2_smu_write(0, STI_CLKSEL);
emev2_smu_write(1, STI_RSTCTRL);
emev2_smu_write(2, USIAU0_RSTCTRL);
emev2_smu_write(2, USIBU1_RSTCTRL);
emev2_smu_write(2, USIBU2_RSTCTRL);
emev2_smu_write(2, USIBU3_RSTCTRL);
emev2_smu_write(1, IIC0_RSTCTRL);
emev2_smu_write(1, IIC1_RSTCTRL);
}
static void __init emev2_smu_clkdiv_init(struct device_node *np)
{
u32 reg[2];
struct clk *clk;
const char *parent_name = of_clk_get_parent_name(np, 0);
if (WARN_ON(of_property_read_u32_array(np, "reg", reg, 2)))
return;
if (!smu_base)
emev2_smu_init();
clk = clk_register_divider(NULL, np->name, parent_name, 0,
smu_base + reg[0], reg[1], 8, 0, &lock);
of_clk_add_provider(np, of_clk_src_simple_get, clk);
clk_register_clkdev(clk, np->name, NULL);
pr_debug("## %s %s %p\n", __func__, np->name, clk);
}
static void __init emev2_smu_gclk_init(struct device_node *np)
{
u32 reg[2];
struct clk *clk;
const char *parent_name = of_clk_get_parent_name(np, 0);
if (WARN_ON(of_property_read_u32_array(np, "reg", reg, 2)))
return;
if (!smu_base)
emev2_smu_init();
clk = clk_register_gate(NULL, np->name, parent_name, 0,
smu_base + reg[0], reg[1], 0, &lock);
of_clk_add_provider(np, of_clk_src_simple_get, clk);
clk_register_clkdev(clk, np->name, NULL);
pr_debug("## %s %s %p\n", __func__, np->name, clk);
}
