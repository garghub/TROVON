static int ti_syscon_reset_assert(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct ti_syscon_reset_data *data = to_ti_syscon_reset_data(rcdev);
struct ti_syscon_reset_control *control;
unsigned int mask, value;
if (id >= data->nr_controls)
return -EINVAL;
control = &data->controls[id];
if (control->flags & ASSERT_NONE)
return -ENOTSUPP;
mask = BIT(control->assert_bit);
value = (control->flags & ASSERT_SET) ? mask : 0x0;
return regmap_update_bits(data->regmap, control->assert_offset, mask, value);
}
static int ti_syscon_reset_deassert(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct ti_syscon_reset_data *data = to_ti_syscon_reset_data(rcdev);
struct ti_syscon_reset_control *control;
unsigned int mask, value;
if (id >= data->nr_controls)
return -EINVAL;
control = &data->controls[id];
if (control->flags & DEASSERT_NONE)
return -ENOTSUPP;
mask = BIT(control->deassert_bit);
value = (control->flags & DEASSERT_SET) ? mask : 0x0;
return regmap_update_bits(data->regmap, control->deassert_offset, mask, value);
}
static int ti_syscon_reset_status(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct ti_syscon_reset_data *data = to_ti_syscon_reset_data(rcdev);
struct ti_syscon_reset_control *control;
unsigned int reset_state;
int ret;
if (id >= data->nr_controls)
return -EINVAL;
control = &data->controls[id];
if (control->flags & STATUS_NONE)
return -ENOTSUPP;
ret = regmap_read(data->regmap, control->status_offset, &reset_state);
if (ret)
return ret;
return (reset_state & BIT(control->status_bit)) &&
(control->flags & STATUS_SET);
}
static int ti_syscon_reset_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct ti_syscon_reset_data *data;
struct regmap *regmap;
const __be32 *list;
struct ti_syscon_reset_control *controls;
int size, nr_controls, i;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
regmap = syscon_node_to_regmap(np->parent);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
list = of_get_property(np, "ti,reset-bits", &size);
if (!list || (size / sizeof(*list)) % 7 != 0) {
dev_err(dev, "invalid DT reset description\n");
return -EINVAL;
}
nr_controls = (size / sizeof(*list)) / 7;
controls = devm_kzalloc(dev, nr_controls * sizeof(*controls), GFP_KERNEL);
if (!controls)
return -ENOMEM;
for (i = 0; i < nr_controls; i++) {
controls[i].assert_offset = be32_to_cpup(list++);
controls[i].assert_bit = be32_to_cpup(list++);
controls[i].deassert_offset = be32_to_cpup(list++);
controls[i].deassert_bit = be32_to_cpup(list++);
controls[i].status_offset = be32_to_cpup(list++);
controls[i].status_bit = be32_to_cpup(list++);
controls[i].flags = be32_to_cpup(list++);
}
data->rcdev.ops = &ti_syscon_reset_ops;
data->rcdev.owner = THIS_MODULE;
data->rcdev.of_node = np;
data->rcdev.nr_resets = nr_controls;
data->regmap = regmap;
data->controls = controls;
data->nr_controls = nr_controls;
platform_set_drvdata(pdev, data);
return devm_reset_controller_register(dev, &data->rcdev);
}
