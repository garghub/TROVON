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
static void iio_hwmon_free_attrs(struct iio_hwmon_state *st)
{
int i;
struct sensor_device_attribute *a;
for (i = 0; i < st->num_channels; i++)
if (st->attrs[i]) {
a = to_sensor_dev_attr(
container_of(st->attrs[i],
struct device_attribute,
attr));
kfree(a);
}
}
static int __devinit iio_hwmon_probe(struct platform_device *pdev)
{
struct iio_hwmon_state *st;
struct sensor_device_attribute *a;
int ret, i;
int in_i = 1, temp_i = 1, curr_i = 1;
enum iio_chan_type type;
st = kzalloc(sizeof(*st), GFP_KERNEL);
if (st == NULL) {
ret = -ENOMEM;
goto error_ret;
}
st->channels = iio_channel_get_all(dev_name(&pdev->dev));
if (IS_ERR(st->channels)) {
ret = PTR_ERR(st->channels);
goto error_free_state;
}
while (st->channels[st->num_channels].indio_dev)
st->num_channels++;
st->attrs = kzalloc(sizeof(st->attrs) * (st->num_channels + 1),
GFP_KERNEL);
if (st->attrs == NULL) {
ret = -ENOMEM;
goto error_release_channels;
}
for (i = 0; i < st->num_channels; i++) {
a = kzalloc(sizeof(*a), GFP_KERNEL);
if (a == NULL) {
ret = -ENOMEM;
goto error_free_attrs;
}
sysfs_attr_init(&a->dev_attr.attr);
ret = iio_get_channel_type(&st->channels[i], &type);
if (ret < 0) {
kfree(a);
goto error_free_attrs;
}
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
kfree(a);
goto error_free_attrs;
}
if (a->dev_attr.attr.name == NULL) {
kfree(a);
ret = -ENOMEM;
goto error_free_attrs;
}
a->dev_attr.show = iio_hwmon_read_val;
a->dev_attr.attr.mode = S_IRUGO;
a->index = i;
st->attrs[i] = &a->dev_attr.attr;
}
st->attr_group.attrs = st->attrs;
platform_set_drvdata(pdev, st);
ret = sysfs_create_group(&pdev->dev.kobj, &st->attr_group);
if (ret < 0)
goto error_free_attrs;
st->hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(st->hwmon_dev)) {
ret = PTR_ERR(st->hwmon_dev);
goto error_remove_group;
}
return 0;
error_remove_group:
sysfs_remove_group(&pdev->dev.kobj, &st->attr_group);
error_free_attrs:
iio_hwmon_free_attrs(st);
kfree(st->attrs);
error_release_channels:
iio_channel_release_all(st->channels);
error_free_state:
kfree(st);
error_ret:
return ret;
}
static int __devexit iio_hwmon_remove(struct platform_device *pdev)
{
struct iio_hwmon_state *st = platform_get_drvdata(pdev);
hwmon_device_unregister(st->hwmon_dev);
sysfs_remove_group(&pdev->dev.kobj, &st->attr_group);
iio_hwmon_free_attrs(st);
kfree(st->attrs);
iio_channel_release_all(st->channels);
return 0;
}
