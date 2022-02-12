static int hi6220_peripheral_assert(struct reset_controller_dev *rc_dev,
unsigned long idx)
{
struct hi6220_reset_data *data = to_reset_data(rc_dev);
struct regmap *regmap = data->regmap;
u32 bank = idx >> 8;
u32 offset = idx & 0xff;
u32 reg = PERIPH_ASSERT_OFFSET + bank * 0x10;
return regmap_write(regmap, reg, BIT(offset));
}
static int hi6220_peripheral_deassert(struct reset_controller_dev *rc_dev,
unsigned long idx)
{
struct hi6220_reset_data *data = to_reset_data(rc_dev);
struct regmap *regmap = data->regmap;
u32 bank = idx >> 8;
u32 offset = idx & 0xff;
u32 reg = PERIPH_DEASSERT_OFFSET + bank * 0x10;
return regmap_write(regmap, reg, BIT(offset));
}
static int hi6220_media_assert(struct reset_controller_dev *rc_dev,
unsigned long idx)
{
struct hi6220_reset_data *data = to_reset_data(rc_dev);
struct regmap *regmap = data->regmap;
return regmap_write(regmap, SC_MEDIA_RSTEN, BIT(idx));
}
static int hi6220_media_deassert(struct reset_controller_dev *rc_dev,
unsigned long idx)
{
struct hi6220_reset_data *data = to_reset_data(rc_dev);
struct regmap *regmap = data->regmap;
return regmap_write(regmap, SC_MEDIA_RSTDIS, BIT(idx));
}
static int hi6220_reset_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device *dev = &pdev->dev;
enum hi6220_reset_ctrl_type type;
struct hi6220_reset_data *data;
struct regmap *regmap;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
type = (enum hi6220_reset_ctrl_type)of_device_get_match_data(dev);
regmap = syscon_node_to_regmap(np);
if (IS_ERR(regmap)) {
dev_err(dev, "failed to get reset controller regmap\n");
return PTR_ERR(regmap);
}
data->regmap = regmap;
data->rc_dev.of_node = np;
if (type == MEDIA) {
data->rc_dev.ops = &hi6220_media_reset_ops;
data->rc_dev.nr_resets = MEDIA_MAX_INDEX;
} else {
data->rc_dev.ops = &hi6220_peripheral_reset_ops;
data->rc_dev.nr_resets = PERIPH_MAX_INDEX;
}
return reset_controller_register(&data->rc_dev);
}
static int __init hi6220_reset_init(void)
{
return platform_driver_register(&hi6220_reset_driver);
}
