static void __init sunxi_simple_gates_setup(struct device_node *node,
const int protected[],
int nprotected)
{
struct clk_onecell_data *clk_data;
const char *clk_parent, *clk_name;
struct property *prop;
struct resource res;
void __iomem *clk_reg;
void __iomem *reg;
const __be32 *p;
int number, i = 0, j;
u8 clk_bit;
u32 index;
reg = of_io_request_and_map(node, 0, of_node_full_name(node));
if (IS_ERR(reg))
return;
clk_parent = of_clk_get_parent_name(node, 0);
clk_data = kmalloc(sizeof(struct clk_onecell_data), GFP_KERNEL);
if (!clk_data)
goto err_unmap;
number = of_property_count_u32_elems(node, "clock-indices");
of_property_read_u32_index(node, "clock-indices", number - 1, &number);
clk_data->clks = kcalloc(number + 1, sizeof(struct clk *), GFP_KERNEL);
if (!clk_data->clks)
goto err_free_data;
of_property_for_each_u32(node, "clock-indices", prop, p, index) {
of_property_read_string_index(node, "clock-output-names",
i, &clk_name);
clk_reg = reg + 4 * (index / 32);
clk_bit = index % 32;
clk_data->clks[index] = clk_register_gate(NULL, clk_name,
clk_parent, 0,
clk_reg,
clk_bit,
0, &gates_lock);
i++;
if (IS_ERR(clk_data->clks[index])) {
WARN_ON(true);
continue;
}
for (j = 0; j < nprotected; j++)
if (protected[j] == index)
clk_prepare_enable(clk_data->clks[index]);
}
clk_data->clk_num = number + 1;
of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
return;
err_free_data:
kfree(clk_data);
err_unmap:
iounmap(reg);
of_address_to_resource(node, 0, &res);
release_mem_region(res.start, resource_size(&res));
}
static void __init sunxi_simple_gates_init(struct device_node *node)
{
sunxi_simple_gates_setup(node, NULL, 0);
}
static void __init sun4i_a10_ahb_init(struct device_node *node)
{
sunxi_simple_gates_setup(node, sun4i_a10_ahb_critical_clocks,
ARRAY_SIZE(sun4i_a10_ahb_critical_clocks));
}
static void __init sun4i_a10_dram_init(struct device_node *node)
{
sunxi_simple_gates_setup(node, sun4i_a10_dram_critical_clocks,
ARRAY_SIZE(sun4i_a10_dram_critical_clocks));
}
