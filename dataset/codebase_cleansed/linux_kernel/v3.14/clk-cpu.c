static unsigned long clk_cpu_recalc_rate(struct clk_hw *hwclk,
unsigned long parent_rate)
{
struct cpu_clk *cpuclk = to_cpu_clk(hwclk);
u32 reg, div;
reg = readl(cpuclk->reg_base + SYS_CTRL_CLK_DIVIDER_VALUE_OFFSET);
div = (reg >> (cpuclk->cpu * 8)) & SYS_CTRL_CLK_DIVIDER_MASK;
return parent_rate / div;
}
static long clk_cpu_round_rate(struct clk_hw *hwclk, unsigned long rate,
unsigned long *parent_rate)
{
u32 div;
div = *parent_rate / rate;
if (div == 0)
div = 1;
else if (div > 3)
div = 3;
return *parent_rate / div;
}
static int clk_cpu_set_rate(struct clk_hw *hwclk, unsigned long rate,
unsigned long parent_rate)
{
struct cpu_clk *cpuclk = to_cpu_clk(hwclk);
u32 reg, div;
u32 reload_mask;
div = parent_rate / rate;
reg = (readl(cpuclk->reg_base + SYS_CTRL_CLK_DIVIDER_VALUE_OFFSET)
& (~(SYS_CTRL_CLK_DIVIDER_MASK << (cpuclk->cpu * 8))))
| (div << (cpuclk->cpu * 8));
writel(reg, cpuclk->reg_base + SYS_CTRL_CLK_DIVIDER_VALUE_OFFSET);
reload_mask = 1 << (20 + cpuclk->cpu);
reg = readl(cpuclk->reg_base + SYS_CTRL_CLK_DIVIDER_CTRL_OFFSET)
| reload_mask;
writel(reg, cpuclk->reg_base + SYS_CTRL_CLK_DIVIDER_CTRL_OFFSET);
reg = readl(cpuclk->reg_base + SYS_CTRL_CLK_DIVIDER_CTRL_OFFSET)
| 1 << 24;
writel(reg, cpuclk->reg_base + SYS_CTRL_CLK_DIVIDER_CTRL_OFFSET);
udelay(1000);
reg &= ~(reload_mask | 1 << 24);
writel(reg, cpuclk->reg_base + SYS_CTRL_CLK_DIVIDER_CTRL_OFFSET);
udelay(1000);
return 0;
}
static void __init of_cpu_clk_setup(struct device_node *node)
{
struct cpu_clk *cpuclk;
void __iomem *clock_complex_base = of_iomap(node, 0);
int ncpus = 0;
struct device_node *dn;
if (clock_complex_base == NULL) {
pr_err("%s: clock-complex base register not set\n",
__func__);
return;
}
for_each_node_by_type(dn, "cpu")
ncpus++;
cpuclk = kzalloc(ncpus * sizeof(*cpuclk), GFP_KERNEL);
if (WARN_ON(!cpuclk))
goto cpuclk_out;
clks = kzalloc(ncpus * sizeof(*clks), GFP_KERNEL);
if (WARN_ON(!clks))
goto clks_out;
for_each_node_by_type(dn, "cpu") {
struct clk_init_data init;
struct clk *clk;
struct clk *parent_clk;
char *clk_name = kzalloc(5, GFP_KERNEL);
int cpu, err;
if (WARN_ON(!clk_name))
goto bail_out;
err = of_property_read_u32(dn, "reg", &cpu);
if (WARN_ON(err))
goto bail_out;
sprintf(clk_name, "cpu%d", cpu);
parent_clk = of_clk_get(node, 0);
cpuclk[cpu].parent_name = __clk_get_name(parent_clk);
cpuclk[cpu].clk_name = clk_name;
cpuclk[cpu].cpu = cpu;
cpuclk[cpu].reg_base = clock_complex_base;
cpuclk[cpu].hw.init = &init;
init.name = cpuclk[cpu].clk_name;
init.ops = &cpu_ops;
init.flags = 0;
init.parent_names = &cpuclk[cpu].parent_name;
init.num_parents = 1;
clk = clk_register(NULL, &cpuclk[cpu].hw);
if (WARN_ON(IS_ERR(clk)))
goto bail_out;
clks[cpu] = clk;
}
clk_data.clk_num = MAX_CPU;
clk_data.clks = clks;
of_clk_add_provider(node, of_clk_src_onecell_get, &clk_data);
return;
bail_out:
kfree(clks);
while(ncpus--)
kfree(cpuclk[ncpus].clk_name);
clks_out:
kfree(cpuclk);
cpuclk_out:
iounmap(clock_complex_base);
}
