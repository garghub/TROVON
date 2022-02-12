static int regmap_spmi_read(void *context,
const void *reg, size_t reg_size,
void *val, size_t val_size)
{
BUG_ON(reg_size != 2);
return spmi_ext_register_readl(context, *(u16 *)reg,
val, val_size);
}
static int regmap_spmi_gather_write(void *context,
const void *reg, size_t reg_size,
const void *val, size_t val_size)
{
BUG_ON(reg_size != 2);
return spmi_ext_register_writel(context, *(u16 *)reg, val, val_size);
}
static int regmap_spmi_write(void *context, const void *data,
size_t count)
{
BUG_ON(count < 2);
return regmap_spmi_gather_write(context, data, 2, data + 2, count - 2);
}
struct regmap *regmap_init_spmi(struct spmi_device *sdev,
const struct regmap_config *config)
{
return regmap_init(&sdev->dev, &regmap_spmi, sdev, config);
}
struct regmap *devm_regmap_init_spmi(struct spmi_device *sdev,
const struct regmap_config *config)
{
return devm_regmap_init(&sdev->dev, &regmap_spmi, sdev, config);
}
