static ssize_t reg_show_name(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct userspace_consumer_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", data->name);
}
static ssize_t reg_show_state(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct userspace_consumer_data *data = dev_get_drvdata(dev);
if (data->enabled)
return sprintf(buf, "enabled\n");
return sprintf(buf, "disabled\n");
}
static ssize_t reg_set_state(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct userspace_consumer_data *data = dev_get_drvdata(dev);
bool enabled;
int ret;
if (sysfs_streq(buf, "enabled\n") || sysfs_streq(buf, "1"))
enabled = true;
else if (sysfs_streq(buf, "disabled\n") || sysfs_streq(buf, "0"))
enabled = false;
else {
dev_err(dev, "Configuring invalid mode\n");
return count;
}
mutex_lock(&data->lock);
if (enabled != data->enabled) {
if (enabled)
ret = regulator_bulk_enable(data->num_supplies,
data->supplies);
else
ret = regulator_bulk_disable(data->num_supplies,
data->supplies);
if (ret == 0)
data->enabled = enabled;
else
dev_err(dev, "Failed to configure state: %d\n", ret);
}
mutex_unlock(&data->lock);
return count;
}
static int regulator_userspace_consumer_probe(struct platform_device *pdev)
{
struct regulator_userspace_consumer_data *pdata;
struct userspace_consumer_data *drvdata;
int ret;
pdata = dev_get_platdata(&pdev->dev);
if (!pdata)
return -EINVAL;
drvdata = devm_kzalloc(&pdev->dev,
sizeof(struct userspace_consumer_data),
GFP_KERNEL);
if (drvdata == NULL)
return -ENOMEM;
drvdata->name = pdata->name;
drvdata->num_supplies = pdata->num_supplies;
drvdata->supplies = pdata->supplies;
mutex_init(&drvdata->lock);
ret = devm_regulator_bulk_get(&pdev->dev, drvdata->num_supplies,
drvdata->supplies);
if (ret) {
dev_err(&pdev->dev, "Failed to get supplies: %d\n", ret);
return ret;
}
ret = sysfs_create_group(&pdev->dev.kobj, &attr_group);
if (ret != 0)
return ret;
if (pdata->init_on) {
ret = regulator_bulk_enable(drvdata->num_supplies,
drvdata->supplies);
if (ret) {
dev_err(&pdev->dev,
"Failed to set initial state: %d\n", ret);
goto err_enable;
}
}
drvdata->enabled = pdata->init_on;
platform_set_drvdata(pdev, drvdata);
return 0;
err_enable:
sysfs_remove_group(&pdev->dev.kobj, &attr_group);
return ret;
}
static int regulator_userspace_consumer_remove(struct platform_device *pdev)
{
struct userspace_consumer_data *data = platform_get_drvdata(pdev);
sysfs_remove_group(&pdev->dev.kobj, &attr_group);
if (data->enabled)
regulator_bulk_disable(data->num_supplies, data->supplies);
return 0;
}
