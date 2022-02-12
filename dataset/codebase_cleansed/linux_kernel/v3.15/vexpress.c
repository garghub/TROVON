static ssize_t vexpress_hwmon_name_show(struct device *dev,
struct device_attribute *dev_attr, char *buffer)
{
struct vexpress_hwmon_data *data = dev_get_drvdata(dev);
return sprintf(buffer, "%s\n", data->name);
}
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
err = vexpress_config_read(data->func, 0, &value);
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
err = vexpress_config_read(data->func, 0, &value_lo);
if (err)
return err;
err = vexpress_config_read(data->func, 1, &value_hi);
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
int err;
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
data->name = type->name;
data->func = vexpress_config_func_get_by_dev(&pdev->dev);
if (!data->func)
return -ENODEV;
err = sysfs_create_groups(&pdev->dev.kobj, type->attr_groups);
if (err)
goto error;
data->hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto error;
}
return 0;
error:
sysfs_remove_group(&pdev->dev.kobj, match->data);
vexpress_config_func_put(data->func);
return err;
}
static int vexpress_hwmon_remove(struct platform_device *pdev)
{
struct vexpress_hwmon_data *data = platform_get_drvdata(pdev);
const struct of_device_id *match;
hwmon_device_unregister(data->hwmon_dev);
match = of_match_device(vexpress_hwmon_of_match, &pdev->dev);
sysfs_remove_group(&pdev->dev.kobj, match->data);
vexpress_config_func_put(data->func);
return 0;
}
