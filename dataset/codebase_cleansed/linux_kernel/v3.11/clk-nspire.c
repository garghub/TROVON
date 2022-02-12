static void nspire_clkinfo_cx(u32 val, struct nspire_clk_info *clk)
{
if (EXTRACT(val, FIXED_BASE))
clk->base_clock = 48 * MHZ;
else
clk->base_clock = 6 * EXTRACT(val, CX_BASE) * MHZ;
clk->base_cpu_ratio = EXTRACT(val, BASE_CPU) * EXTRACT(val, CX_UNKNOWN);
clk->base_ahb_ratio = clk->base_cpu_ratio * (EXTRACT(val, CPU_AHB) + 1);
}
static void nspire_clkinfo_classic(u32 val, struct nspire_clk_info *clk)
{
if (EXTRACT(val, FIXED_BASE))
clk->base_clock = 27 * MHZ;
else
clk->base_clock = (300 - 6 * EXTRACT(val, CLASSIC_BASE)) * MHZ;
clk->base_cpu_ratio = EXTRACT(val, BASE_CPU) * 2;
clk->base_ahb_ratio = clk->base_cpu_ratio * (EXTRACT(val, CPU_AHB) + 1);
}
static void __init nspire_ahbdiv_setup(struct device_node *node,
void (*get_clkinfo)(u32, struct nspire_clk_info *))
{
u32 val;
void __iomem *io;
struct clk *clk;
const char *clk_name = node->name;
const char *parent_name;
struct nspire_clk_info info;
io = of_iomap(node, 0);
if (!io)
return;
val = readl(io);
iounmap(io);
get_clkinfo(val, &info);
of_property_read_string(node, "clock-output-names", &clk_name);
parent_name = of_clk_get_parent_name(node, 0);
clk = clk_register_fixed_factor(NULL, clk_name, parent_name, 0,
1, info.base_ahb_ratio);
if (!IS_ERR(clk))
of_clk_add_provider(node, of_clk_src_simple_get, clk);
}
static void __init nspire_ahbdiv_setup_cx(struct device_node *node)
{
nspire_ahbdiv_setup(node, nspire_clkinfo_cx);
}
static void __init nspire_ahbdiv_setup_classic(struct device_node *node)
{
nspire_ahbdiv_setup(node, nspire_clkinfo_classic);
}
static void __init nspire_clk_setup(struct device_node *node,
void (*get_clkinfo)(u32, struct nspire_clk_info *))
{
u32 val;
void __iomem *io;
struct clk *clk;
const char *clk_name = node->name;
struct nspire_clk_info info;
io = of_iomap(node, 0);
if (!io)
return;
val = readl(io);
iounmap(io);
get_clkinfo(val, &info);
of_property_read_string(node, "clock-output-names", &clk_name);
clk = clk_register_fixed_rate(NULL, clk_name, NULL, CLK_IS_ROOT,
info.base_clock);
if (!IS_ERR(clk))
of_clk_add_provider(node, of_clk_src_simple_get, clk);
else
return;
pr_info("TI-NSPIRE Base: %uMHz CPU: %uMHz AHB: %uMHz\n",
info.base_clock / MHZ,
info.base_clock / info.base_cpu_ratio / MHZ,
info.base_clock / info.base_ahb_ratio / MHZ);
}
static void __init nspire_clk_setup_cx(struct device_node *node)
{
nspire_clk_setup(node, nspire_clkinfo_cx);
}
static void __init nspire_clk_setup_classic(struct device_node *node)
{
nspire_clk_setup(node, nspire_clkinfo_classic);
}
