static int hi6220_reset_assert(struct reset_controller_dev *rc_dev,
unsigned long idx)
{
struct hi6220_reset_data *data = to_reset_data(rc_dev);
int bank = idx >> 8;
int offset = idx & 0xff;
writel(BIT(offset), data->assert_base + (bank * 0x10));
return 0;
}
static int hi6220_reset_deassert(struct reset_controller_dev *rc_dev,
unsigned long idx)
{
struct hi6220_reset_data *data = to_reset_data(rc_dev);
int bank = idx >> 8;
int offset = idx & 0xff;
writel(BIT(offset), data->deassert_base + (bank * 0x10));
return 0;
}
static int hi6220_reset_probe(struct platform_device *pdev)
{
struct hi6220_reset_data *data;
struct resource *res;
void __iomem *src_base;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
src_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(src_base))
return PTR_ERR(src_base);
data->assert_base = src_base + ASSERT_OFFSET;
data->deassert_base = src_base + DEASSERT_OFFSET;
data->rc_dev.nr_resets = MAX_INDEX;
data->rc_dev.ops = &hi6220_reset_ops;
data->rc_dev.of_node = pdev->dev.of_node;
return reset_controller_register(&data->rc_dev);
}
static int __init hi6220_reset_init(void)
{
return platform_driver_register(&hi6220_reset_driver);
}
