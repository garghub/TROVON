static int sun6i_a31_apb0_gates_clk_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct clk_onecell_data *clk_data;
const char *clk_parent;
const char *clk_name;
struct resource *r;
void __iomem *reg;
int gate_id;
int ngates;
int i;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(reg))
return PTR_ERR(reg);
clk_parent = of_clk_get_parent_name(np, 0);
if (!clk_parent)
return -EINVAL;
ngates = of_property_count_strings(np, "clock-output-names");
if (ngates < 0)
return ngates;
if (!ngates || ngates > SUN6I_APB0_GATES_MAX_SIZE)
return -EINVAL;
clk_data = devm_kzalloc(&pdev->dev, sizeof(struct clk_onecell_data),
GFP_KERNEL);
if (!clk_data)
return -ENOMEM;
clk_data->clks = devm_kzalloc(&pdev->dev,
SUN6I_APB0_GATES_MAX_SIZE *
sizeof(struct clk *),
GFP_KERNEL);
if (!clk_data->clks)
return -ENOMEM;
for (i = 0; i < ngates; i++) {
of_property_read_string_index(np, "clock-output-names",
i, &clk_name);
gate_id = i;
of_property_read_u32_index(np, "clock-indices", i, &gate_id);
WARN_ON(gate_id >= SUN6I_APB0_GATES_MAX_SIZE);
if (gate_id >= SUN6I_APB0_GATES_MAX_SIZE)
continue;
clk_data->clks[gate_id] = clk_register_gate(&pdev->dev,
clk_name,
clk_parent, 0,
reg, gate_id,
0, NULL);
WARN_ON(IS_ERR(clk_data->clks[gate_id]));
}
clk_data->clk_num = ngates;
return of_clk_add_provider(np, of_clk_src_onecell_get, clk_data);
}
