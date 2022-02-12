static int gxbb_aoclk_do_reset(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct gxbb_aoclk_reset_controller *reset =
container_of(rcdev, struct gxbb_aoclk_reset_controller, reset);
writel(BIT(reset->data[id]), reset->base);
return 0;
}
static int gxbb_aoclkc_probe(struct platform_device *pdev)
{
struct resource *res;
void __iomem *base;
int ret, clkid;
struct device *dev = &pdev->dev;
struct gxbb_aoclk_reset_controller *rstc;
rstc = devm_kzalloc(dev, sizeof(*rstc), GFP_KERNEL);
if (!rstc)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
rstc->base = base;
rstc->data = gxbb_aoclk_reset;
rstc->reset.ops = &gxbb_aoclk_reset_ops;
rstc->reset.nr_resets = ARRAY_SIZE(gxbb_aoclk_reset);
rstc->reset.of_node = dev->of_node;
ret = devm_reset_controller_register(dev, &rstc->reset);
for (clkid = 0; clkid < gxbb_aoclk_onecell_data.num; clkid++) {
gxbb_aoclk_gate[clkid]->reg = base;
ret = devm_clk_hw_register(dev,
gxbb_aoclk_onecell_data.hws[clkid]);
if (ret)
return ret;
}
return of_clk_add_hw_provider(dev->of_node, of_clk_hw_onecell_get,
&gxbb_aoclk_onecell_data);
}
