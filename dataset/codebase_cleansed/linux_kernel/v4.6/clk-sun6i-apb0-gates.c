static int sun6i_a31_apb0_gates_clk_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct clk_onecell_data *clk_data;
const struct of_device_id *device;
const struct gates_data *data;
const char *clk_parent;
const char *clk_name;
struct resource *r;
void __iomem *reg;
int ngates;
int i;
int j = 0;
if (!np)
return -ENODEV;
device = of_match_device(sun6i_a31_apb0_gates_clk_dt_ids, &pdev->dev);
if (!device)
return -ENODEV;
data = device->data;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(reg))
return PTR_ERR(reg);
clk_parent = of_clk_get_parent_name(np, 0);
if (!clk_parent)
return -EINVAL;
clk_data = devm_kzalloc(&pdev->dev, sizeof(struct clk_onecell_data),
GFP_KERNEL);
if (!clk_data)
return -ENOMEM;
ngates = find_last_bit(data->mask, SUN6I_APB0_GATES_MAX_SIZE);
clk_data->clks = devm_kcalloc(&pdev->dev, (ngates + 1),
sizeof(struct clk *), GFP_KERNEL);
if (!clk_data->clks)
return -ENOMEM;
for_each_set_bit(i, data->mask, SUN6I_APB0_GATES_MAX_SIZE) {
of_property_read_string_index(np, "clock-output-names",
j, &clk_name);
clk_data->clks[i] = clk_register_gate(&pdev->dev, clk_name,
clk_parent, 0, reg, i,
0, NULL);
WARN_ON(IS_ERR(clk_data->clks[i]));
j++;
}
clk_data->clk_num = ngates + 1;
return of_clk_add_provider(np, of_clk_src_onecell_get, clk_data);
}
