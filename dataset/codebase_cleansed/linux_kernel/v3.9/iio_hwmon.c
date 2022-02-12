static ssize_t iio_hwmon_read_val(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int result;
int ret;
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
struct iio_hwmon_state *state = dev_get_drvdata(dev);
ret = iio_read_channel_processed(&state->channels[sattr->index],
&result);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", result);
}
static ssize_t show_name(struct device *dev, struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "iio_hwmon\n");
}
static int iio_hwmon_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct iio_hwmon_state *st;
struct sensor_device_attribute *a;
int ret, i;
int in_i = 1, temp_i = 1, curr_i = 1;
enum iio_chan_type type;
struct iio_channel *channels;
channels = iio_channel_get_all(dev);
if (IS_ERR(channels))
return PTR_ERR(channels);
st = devm_kzalloc(dev, sizeof(*st), GFP_KERNEL);
if (st == NULL)
return -ENOMEM;
st->channels = channels;
while (st->channels[st->num_channels].indio_dev)
st->num_channels++;
st->attrs = devm_kzalloc(dev,
sizeof(*st->attrs) * (st->num_channels + 2),
GFP_KERNEL);
if (st->attrs == NULL) {
ret = -ENOMEM;
goto error_release_channels;
}
for (i = 0; i < st->num_channels; i++) {
a = devm_kzalloc(dev, sizeof(*a), GFP_KERNEL);
if (a == NULL) {
ret = -ENOMEM;
goto error_release_channels;
}
sysfs_attr_init(&a->dev_attr.attr);
ret = iio_get_channel_type(&st->channels[i], &type);
if (ret < 0)
goto error_release_channels;
switch (type) {
case IIO_VOLTAGE:
a->dev_attr.attr.name = kasprintf(GFP_KERNEL,
"in%d_input",
in_i++);
break;
case IIO_TEMP:
a->dev_attr.attr.name = kasprintf(GFP_KERNEL,
"temp%d_input",
temp_i++);
break;
case IIO_CURRENT:
a->dev_attr.attr.name = kasprintf(GFP_KERNEL,
"curr%d_input",
curr_i++);
break;
default:
ret = -EINVAL;
goto error_release_channels;
}
if (a->dev_attr.attr.name == NULL) {
ret = -ENOMEM;
goto error_release_channels;
}
a->dev_attr.show = iio_hwmon_read_val;
a->dev_attr.attr.mode = S_IRUGO;
a->index = i;
st->attrs[i] = &a->dev_attr.attr;
}
st->attrs[st->num_channels] = &dev_attr_name.attr;
st->attr_group.attrs = st->attrs;
platform_set_drvdata(pdev, st);
ret = sysfs_create_group(&dev->kobj, &st->attr_group);
if (ret < 0)
goto error_release_channels;
st->hwmon_dev = hwmon_device_register(dev);
if (IS_ERR(st->hwmon_dev)) {
ret = PTR_ERR(st->hwmon_dev);
goto error_remove_group;
}
return 0;
error_remove_group:
sysfs_remove_group(&dev->kobj, &st->attr_group);
error_release_channels:
iio_channel_release_all(st->channels);
return ret;
}
static int iio_hwmon_remove(struct platform_device *pdev)
{
struct iio_hwmon_state *st = platform_get_drvdata(pdev);
hwmon_device_unregister(st->hwmon_dev);
sysfs_remove_group(&pdev->dev.kobj, &st->attr_group);
iio_channel_release_all(st->channels);
return 0;
}
