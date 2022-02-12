static ssize_t show_voltage(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct wm831x *wm831x = dev_get_drvdata(dev);
int channel = to_sensor_dev_attr(attr)->index;
int ret;
ret = wm831x_auxadc_read_uv(wm831x, channel);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", DIV_ROUND_CLOSEST(ret, 1000));
}
static ssize_t show_chip_temp(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct wm831x *wm831x = dev_get_drvdata(dev);
int channel = to_sensor_dev_attr(attr)->index;
int ret;
ret = wm831x_auxadc_read(wm831x, channel);
if (ret < 0)
return ret;
ret = 512180 - (ret * 1000);
ret = DIV_ROUND_CLOSEST(ret * 10000, 10983);
return sprintf(buf, "%d\n", ret);
}
static ssize_t show_label(struct device *dev,
struct device_attribute *attr, char *buf)
{
int channel = to_sensor_dev_attr(attr)->index;
return sprintf(buf, "%s\n", input_names[channel]);
}
static int wm831x_hwmon_probe(struct platform_device *pdev)
{
struct wm831x *wm831x = dev_get_drvdata(pdev->dev.parent);
struct device *hwmon_dev;
hwmon_dev = devm_hwmon_device_register_with_groups(&pdev->dev, "wm831x",
wm831x,
wm831x_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
