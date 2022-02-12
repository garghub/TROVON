static inline void max197_set_unipolarity(struct max197_data *data, int channel)
{
data->ctrl_bytes[channel] &= ~MAX197_BIP;
}
static inline void max197_set_bipolarity(struct max197_data *data, int channel)
{
data->ctrl_bytes[channel] |= MAX197_BIP;
}
static inline void max197_set_half_range(struct max197_data *data, int channel)
{
data->ctrl_bytes[channel] &= ~MAX197_RNG;
}
static inline void max197_set_full_range(struct max197_data *data, int channel)
{
data->ctrl_bytes[channel] |= MAX197_RNG;
}
static inline bool max197_is_bipolar(struct max197_data *data, int channel)
{
return data->ctrl_bytes[channel] & MAX197_BIP;
}
static inline bool max197_is_full_range(struct max197_data *data, int channel)
{
return data->ctrl_bytes[channel] & MAX197_RNG;
}
static ssize_t max197_show_range(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct max197_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
int channel = attr->index;
bool is_min = attr->nr;
int range;
if (mutex_lock_interruptible(&data->lock))
return -ERESTARTSYS;
range = max197_is_full_range(data, channel) ?
data->limit : data->limit / 2;
if (is_min) {
if (max197_is_bipolar(data, channel))
range = -range;
else
range = 0;
}
mutex_unlock(&data->lock);
return sprintf(buf, "%d\n", range);
}
static ssize_t max197_store_range(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct max197_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
int channel = attr->index;
bool is_min = attr->nr;
long value;
int half = data->limit / 2;
int full = data->limit;
if (kstrtol(buf, 10, &value))
return -EINVAL;
if (is_min) {
if (value <= -full)
value = -full;
else if (value < 0)
value = -half;
else
value = 0;
} else {
if (value >= full)
value = full;
else
value = half;
}
if (mutex_lock_interruptible(&data->lock))
return -ERESTARTSYS;
if (value == 0) {
max197_set_unipolarity(data, channel);
} else if (value == -half) {
max197_set_bipolarity(data, channel);
max197_set_half_range(data, channel);
} else if (value == -full) {
max197_set_bipolarity(data, channel);
max197_set_full_range(data, channel);
} else if (value == half) {
max197_set_half_range(data, channel);
} else if (value == full) {
max197_set_full_range(data, channel);
}
mutex_unlock(&data->lock);
return count;
}
static ssize_t max197_show_input(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct max197_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int channel = attr->index;
s32 value;
int ret;
if (mutex_lock_interruptible(&data->lock))
return -ERESTARTSYS;
ret = data->pdata->convert(data->ctrl_bytes[channel]);
if (ret < 0) {
dev_err(dev, "conversion failed\n");
goto unlock;
}
value = ret;
if (data->scale) {
value *= MAX197_SCALE;
if (max197_is_full_range(data, channel))
value *= 2;
value /= 10000;
}
ret = sprintf(buf, "%d\n", value);
unlock:
mutex_unlock(&data->lock);
return ret;
}
static ssize_t max197_show_name(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct platform_device *pdev = to_platform_device(dev);
return sprintf(buf, "%s\n", pdev->name);
}
static int max197_probe(struct platform_device *pdev)
{
int ch, ret;
struct max197_data *data;
struct max197_platform_data *pdata = dev_get_platdata(&pdev->dev);
enum max197_chips chip = platform_get_device_id(pdev)->driver_data;
if (pdata == NULL) {
dev_err(&pdev->dev, "no platform data supplied\n");
return -EINVAL;
}
if (pdata->convert == NULL) {
dev_err(&pdev->dev, "no convert function supplied\n");
return -EINVAL;
}
data = devm_kzalloc(&pdev->dev, sizeof(struct max197_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->pdata = pdata;
mutex_init(&data->lock);
if (chip == max197) {
data->limit = MAX197_LIMIT;
data->scale = true;
} else {
data->limit = MAX199_LIMIT;
data->scale = false;
}
for (ch = 0; ch < MAX197_NUM_CH; ch++)
data->ctrl_bytes[ch] = (u8) ch;
platform_set_drvdata(pdev, data);
ret = sysfs_create_group(&pdev->dev.kobj, &max197_sysfs_group);
if (ret) {
dev_err(&pdev->dev, "sysfs create group failed\n");
return ret;
}
data->hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(data->hwmon_dev)) {
ret = PTR_ERR(data->hwmon_dev);
dev_err(&pdev->dev, "hwmon device register failed\n");
goto error;
}
return 0;
error:
sysfs_remove_group(&pdev->dev.kobj, &max197_sysfs_group);
return ret;
}
static int max197_remove(struct platform_device *pdev)
{
struct max197_data *data = platform_get_drvdata(pdev);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&pdev->dev.kobj, &max197_sysfs_group);
return 0;
}
