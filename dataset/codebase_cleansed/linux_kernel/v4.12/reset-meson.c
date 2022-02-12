static int meson_reset_reset(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct meson_reset *data =
container_of(rcdev, struct meson_reset, rcdev);
unsigned int bank = id / BITS_PER_REG;
unsigned int offset = id % BITS_PER_REG;
void __iomem *reg_addr = data->reg_base + (bank << 2);
if (bank >= REG_COUNT)
return -EINVAL;
writel(BIT(offset), reg_addr);
return 0;
}
static int meson_reset_probe(struct platform_device *pdev)
{
struct meson_reset *data;
struct resource *res;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(data->reg_base))
return PTR_ERR(data->reg_base);
platform_set_drvdata(pdev, data);
data->rcdev.owner = THIS_MODULE;
data->rcdev.nr_resets = REG_COUNT * BITS_PER_REG;
data->rcdev.ops = &meson_reset_ops;
data->rcdev.of_node = pdev->dev.of_node;
return devm_reset_controller_register(&pdev->dev, &data->rcdev);
}
