static int berlin4ct_pinctrl_probe(struct platform_device *pdev)
{
const struct of_device_id *match =
of_match_device(berlin4ct_pinctrl_match, &pdev->dev);
struct regmap_config *rmconfig;
struct regmap *regmap;
struct resource *res;
void __iomem *base;
rmconfig = devm_kzalloc(&pdev->dev, sizeof(*rmconfig), GFP_KERNEL);
if (!rmconfig)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
rmconfig->reg_bits = 32,
rmconfig->val_bits = 32,
rmconfig->reg_stride = 4,
rmconfig->max_register = resource_size(res);
regmap = devm_regmap_init_mmio(&pdev->dev, base, rmconfig);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
return berlin_pinctrl_probe_regmap(pdev, match->data, regmap);
}
