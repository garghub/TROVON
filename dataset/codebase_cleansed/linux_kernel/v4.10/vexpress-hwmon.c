static ssize_t vexpress_hwmon_label_show(struct device *dev,
struct device_attribute *dev_attr, char *buffer)
{
const char *label = of_get_property(dev->of_node, "label", NULL);
return snprintf(buffer, PAGE_SIZE, "%s\n", label);
}
static ssize_t vexpress_hwmon_u32_show(struct device *dev,
struct device_attribute *dev_attr, char *buffer)
{
struct vexpress_hwmon_data *data = dev_get_drvdata(dev);
int err;
u32 value;
err = regmap_read(data->reg, 0, &value);
if (err)
return err;
return snprintf(buffer, PAGE_SIZE, "%u\n", value /
to_sensor_dev_attr(dev_attr)->index);
}
static ssize_t vexpress_hwmon_u64_show(struct device *dev,
struct device_attribute *dev_attr, char *buffer)
{
struct vexpress_hwmon_data *data = dev_get_drvdata(dev);
int err;
u32 value_hi, value_lo;
err = regmap_read(data->reg, 0, &value_lo);
if (err)
return err;
err = regmap_read(data->reg, 1, &value_hi);
if (err)
return err;
return snprintf(buffer, PAGE_SIZE, "%llu\n",
div_u64(((u64)value_hi << 32) | value_lo,
to_sensor_dev_attr(dev_attr)->index));
}
static umode_t vexpress_hwmon_attr_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = kobj_to_dev(kobj);
struct device_attribute *dev_attr = container_of(attr,
struct device_attribute, attr);
if (dev_attr->show == vexpress_hwmon_label_show &&
!of_get_property(dev->of_node, "label", NULL))
return 0;
return attr->mode;
}
static int vexpress_hwmon_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct vexpress_hwmon_data *data;
const struct vexpress_hwmon_type *type;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
platform_set_drvdata(pdev, data);
match = of_match_device(vexpress_hwmon_of_match, &pdev->dev);
if (!match)
return -ENODEV;
type = match->data;
data->reg = devm_regmap_init_vexpress_config(&pdev->dev);
if (IS_ERR(data->reg))
return PTR_ERR(data->reg);
data->hwmon_dev = devm_hwmon_device_register_with_groups(&pdev->dev,
type->name, data, type->attr_groups);
return PTR_ERR_OR_ZERO(data->hwmon_dev);
}
