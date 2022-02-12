static struct menf21bmc_hwmon *menf21bmc_hwmon_update(struct device *dev)
{
int i;
int val;
struct menf21bmc_hwmon *drv_data = dev_get_drvdata(dev);
struct menf21bmc_hwmon *data_ret = drv_data;
if (time_after(jiffies, drv_data->last_update + HZ)
|| !drv_data->valid) {
for (i = 0; i < BMC_VOLT_COUNT; i++) {
val = i2c_smbus_read_word_data(drv_data->i2c_client,
IDX_TO_VOLT_INP_CMD(i));
if (val < 0) {
data_ret = ERR_PTR(val);
goto abort;
}
drv_data->in_val[i] = val;
}
drv_data->last_update = jiffies;
drv_data->valid = true;
}
abort:
return data_ret;
}
static int menf21bmc_hwmon_get_volt_limits(struct menf21bmc_hwmon *drv_data)
{
int i, val;
for (i = 0; i < BMC_VOLT_COUNT; i++) {
val = i2c_smbus_read_word_data(drv_data->i2c_client,
IDX_TO_VOLT_MIN_CMD(i));
if (val < 0)
return val;
drv_data->in_min[i] = val;
val = i2c_smbus_read_word_data(drv_data->i2c_client,
IDX_TO_VOLT_MAX_CMD(i));
if (val < 0)
return val;
drv_data->in_max[i] = val;
}
return 0;
}
static ssize_t
show_label(struct device *dev, struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
return sprintf(buf, "%s\n", input_names[attr->index]);
}
static ssize_t
show_in(struct device *dev, struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct menf21bmc_hwmon *drv_data = menf21bmc_hwmon_update(dev);
if (IS_ERR(drv_data))
return PTR_ERR(drv_data);
return sprintf(buf, "%d\n", drv_data->in_val[attr->index]);
}
static ssize_t
show_min(struct device *dev, struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct menf21bmc_hwmon *drv_data = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", drv_data->in_min[attr->index]);
}
static ssize_t
show_max(struct device *dev, struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct menf21bmc_hwmon *drv_data = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", drv_data->in_max[attr->index]);
}
static int menf21bmc_hwmon_probe(struct platform_device *pdev)
{
int ret;
struct menf21bmc_hwmon *drv_data;
struct i2c_client *i2c_client = to_i2c_client(pdev->dev.parent);
struct device *hwmon_dev;
drv_data = devm_kzalloc(&pdev->dev, sizeof(struct menf21bmc_hwmon),
GFP_KERNEL);
if (!drv_data)
return -ENOMEM;
drv_data->i2c_client = i2c_client;
ret = menf21bmc_hwmon_get_volt_limits(drv_data);
if (ret) {
dev_err(&pdev->dev, "failed to read sensor limits");
return ret;
}
hwmon_dev = devm_hwmon_device_register_with_groups(&pdev->dev,
"menf21bmc", drv_data,
menf21bmc_hwmon_groups);
if (IS_ERR(hwmon_dev))
return PTR_ERR(hwmon_dev);
dev_info(&pdev->dev, "MEN 14F021P00 BMC hwmon device enabled");
return 0;
}
