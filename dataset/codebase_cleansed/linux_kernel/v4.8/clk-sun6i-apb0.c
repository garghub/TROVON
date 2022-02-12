static int sun6i_a31_apb0_clk_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
const char *clk_name = np->name;
const char *clk_parent;
struct resource *r;
void __iomem *reg;
struct clk *clk;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(reg))
return PTR_ERR(reg);
clk_parent = of_clk_get_parent_name(np, 0);
if (!clk_parent)
return -EINVAL;
of_property_read_string(np, "clock-output-names", &clk_name);
clk = clk_register_divider_table(&pdev->dev, clk_name, clk_parent,
0, reg, 0, 2, 0, sun6i_a31_apb0_divs,
NULL);
if (IS_ERR(clk))
return PTR_ERR(clk);
return of_clk_add_provider(np, of_clk_src_simple_get, clk);
}
