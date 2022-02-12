static int gxbb_aoclk_do_reset(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct gxbb_aoclk_reset_controller *reset =
container_of(rcdev, struct gxbb_aoclk_reset_controller, reset);
return regmap_write(reset->regmap, AO_RTI_GEN_CNTL_REG0,
BIT(reset->data[id]));
}
static int gxbb_aoclkc_probe(struct platform_device *pdev)
{
struct gxbb_aoclk_reset_controller *rstc;
struct device *dev = &pdev->dev;
struct regmap *regmap;
int ret, clkid;
rstc = devm_kzalloc(dev, sizeof(*rstc), GFP_KERNEL);
if (!rstc)
return -ENOMEM;
regmap = syscon_node_to_regmap(of_get_parent(dev->of_node));
if (IS_ERR(regmap)) {
dev_err(dev, "failed to get regmap\n");
return -ENODEV;
}
rstc->regmap = regmap;
rstc->data = gxbb_aoclk_reset;
rstc->reset.ops = &gxbb_aoclk_reset_ops;
rstc->reset.nr_resets = ARRAY_SIZE(gxbb_aoclk_reset);
rstc->reset.of_node = dev->of_node;
ret = devm_reset_controller_register(dev, &rstc->reset);
for (clkid = 0; clkid < ARRAY_SIZE(gxbb_aoclk_gate); clkid++) {
gxbb_aoclk_gate[clkid]->regmap = regmap;
ret = devm_clk_hw_register(dev,
gxbb_aoclk_onecell_data.hws[clkid]);
if (ret)
return ret;
}
cec_32k_ao.regmap = regmap;
ret = devm_clk_hw_register(dev, &cec_32k_ao.hw);
if (ret)
return ret;
return of_clk_add_hw_provider(dev->of_node, of_clk_hw_onecell_get,
&gxbb_aoclk_onecell_data);
}
