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
static int iio_hwmon_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct iio_hwmon_state *st;
struct sensor_device_attribute *a;
int ret, i;
int in_i = 1, temp_i = 1, curr_i = 1, humidity_i = 1;
enum iio_chan_type type;
struct iio_channel *channels;
const char *name = "iio_hwmon";
char *sname;
if (dev->of_node && dev->of_node->name)
name = dev->of_node->name;
channels = iio_channel_get_all(dev);
if (IS_ERR(channels))
return PTR_ERR(channels);
st = devm_kzalloc(dev, sizeof(*st), GFP_KERNEL);
if (st == NULL) {
ret = -ENOMEM;
goto error_release_channels;
}
st->channels = channels;
while (st->channels[st->num_channels].indio_dev)
st->num_channels++;
st->attrs = devm_kzalloc(dev,
sizeof(*st->attrs) * (st->num_channels + 1),
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
a->dev_attr.attr.name = devm_kasprintf(dev, GFP_KERNEL,
"in%d_input",
in_i++);
break;
case IIO_TEMP:
a->dev_attr.attr.name = devm_kasprintf(dev, GFP_KERNEL,
"temp%d_input",
temp_i++);
break;
case IIO_CURRENT:
a->dev_attr.attr.name = devm_kasprintf(dev, GFP_KERNEL,
"curr%d_input",
curr_i++);
break;
case IIO_HUMIDITYRELATIVE:
a->dev_attr.attr.name = devm_kasprintf(dev, GFP_KERNEL,
"humidity%d_input",
humidity_i++);
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
st->attr_group.attrs = st->attrs;
st->groups[0] = &st->attr_group;
sname = devm_kstrdup(dev, name, GFP_KERNEL);
if (!sname) {
ret = -ENOMEM;
goto error_release_channels;
}
strreplace(sname, '-', '_');
st->hwmon_dev = hwmon_device_register_with_groups(dev, sname, st,
st->groups);
if (IS_ERR(st->hwmon_dev)) {
ret = PTR_ERR(st->hwmon_dev);
goto error_release_channels;
}
platform_set_drvdata(pdev, st);
return 0;
error_release_channels:
iio_channel_release_all(channels);
return ret;
}
static int iio_hwmon_remove(struct platform_device *pdev)
{
struct iio_hwmon_state *st = platform_get_drvdata(pdev);
hwmon_device_unregister(st->hwmon_dev);
iio_channel_release_all(st->channels);
return 0;
}
