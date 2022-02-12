static int gemini_reset(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct gemini_reset *gr = to_gemini_reset(rcdev);
return regmap_write(gr->map,
GEMINI_GLOBAL_SOFT_RESET,
BIT(GEMINI_RESET_CPU1) | BIT(id));
}
static int gemini_reset_status(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct gemini_reset *gr = to_gemini_reset(rcdev);
u32 val;
int ret;
ret = regmap_read(gr->map, GEMINI_GLOBAL_SOFT_RESET, &val);
if (ret)
return ret;
return !!(val & BIT(id));
}
static int gemini_reset_probe(struct platform_device *pdev)
{
struct gemini_reset *gr;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
int ret;
gr = devm_kzalloc(dev, sizeof(*gr), GFP_KERNEL);
if (!gr)
return -ENOMEM;
gr->map = syscon_node_to_regmap(np);
if (IS_ERR(gr->map)) {
ret = PTR_ERR(gr->map);
dev_err(dev, "unable to get regmap (%d)", ret);
return ret;
}
gr->rcdev.owner = THIS_MODULE;
gr->rcdev.nr_resets = 32;
gr->rcdev.ops = &gemini_reset_ops;
gr->rcdev.of_node = pdev->dev.of_node;
ret = devm_reset_controller_register(&pdev->dev, &gr->rcdev);
if (ret)
return ret;
dev_info(dev, "registered Gemini reset controller\n");
return 0;
}
