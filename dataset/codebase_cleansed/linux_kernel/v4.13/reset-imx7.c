static struct imx7_src *to_imx7_src(struct reset_controller_dev *rcdev)
{
return container_of(rcdev, struct imx7_src, rcdev);
}
static int imx7_reset_set(struct reset_controller_dev *rcdev,
unsigned long id, bool assert)
{
struct imx7_src *imx7src = to_imx7_src(rcdev);
const struct imx7_src_signal *signal = &imx7_src_signals[id];
unsigned int value = 0;
switch (id) {
case IMX7_RESET_PCIEPHY:
if (!assert)
udelay(10);
break;
case IMX7_RESET_PCIE_CTRL_APPS_EN:
value = (assert) ? 0 : signal->bit;
break;
}
return regmap_update_bits(imx7src->regmap,
signal->offset, signal->bit, value);
}
static int imx7_reset_assert(struct reset_controller_dev *rcdev,
unsigned long id)
{
return imx7_reset_set(rcdev, id, true);
}
static int imx7_reset_deassert(struct reset_controller_dev *rcdev,
unsigned long id)
{
return imx7_reset_set(rcdev, id, false);
}
static int imx7_reset_probe(struct platform_device *pdev)
{
struct imx7_src *imx7src;
struct device *dev = &pdev->dev;
struct regmap_config config = { .name = "src" };
imx7src = devm_kzalloc(dev, sizeof(*imx7src), GFP_KERNEL);
if (!imx7src)
return -ENOMEM;
imx7src->regmap = syscon_node_to_regmap(dev->of_node);
if (IS_ERR(imx7src->regmap)) {
dev_err(dev, "Unable to get imx7-src regmap");
return PTR_ERR(imx7src->regmap);
}
regmap_attach_dev(dev, imx7src->regmap, &config);
imx7src->rcdev.owner = THIS_MODULE;
imx7src->rcdev.nr_resets = IMX7_RESET_NUM;
imx7src->rcdev.ops = &imx7_reset_ops;
imx7src->rcdev.of_node = dev->of_node;
return devm_reset_controller_register(dev, &imx7src->rcdev);
}
