static struct clk *sun8i_a23_apb0_register(struct device_node *node,
void __iomem *reg)
{
const char *clk_name = node->name;
const char *clk_parent;
struct clk *clk;
int ret;
clk_parent = of_clk_get_parent_name(node, 0);
if (!clk_parent)
return ERR_PTR(-EINVAL);
of_property_read_string(node, "clock-output-names", &clk_name);
clk = clk_register_divider(NULL, clk_name, clk_parent, 0, reg,
0, 2, CLK_DIVIDER_POWER_OF_TWO, NULL);
if (IS_ERR(clk))
return clk;
ret = of_clk_add_provider(node, of_clk_src_simple_get, clk);
if (ret)
goto err_unregister;
return clk;
err_unregister:
clk_unregister_divider(clk);
return ERR_PTR(ret);
}
static void sun8i_a23_apb0_setup(struct device_node *node)
{
void __iomem *reg;
struct resource res;
struct clk *clk;
reg = of_io_request_and_map(node, 0, of_node_full_name(node));
if (IS_ERR(reg)) {
if (PTR_ERR(reg) != -EINVAL)
pr_err("Could not get registers for a23-apb0-clk\n");
return;
}
clk = sun8i_a23_apb0_register(node, reg);
if (IS_ERR(clk))
goto err_unmap;
return;
err_unmap:
iounmap(reg);
of_address_to_resource(node, 0, &res);
release_mem_region(res.start, resource_size(&res));
}
static int sun8i_a23_apb0_clk_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct resource *r;
void __iomem *reg;
struct clk *clk;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(reg))
return PTR_ERR(reg);
clk = sun8i_a23_apb0_register(np, reg);
if (IS_ERR(clk))
return PTR_ERR(clk);
return 0;
}
