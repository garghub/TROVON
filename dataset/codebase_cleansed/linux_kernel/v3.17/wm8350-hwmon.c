static ssize_t show_voltage(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct wm8350 *wm8350 = dev_get_drvdata(dev);
int channel = to_sensor_dev_attr(attr)->index;
int val;
val = wm8350_read_auxadc(wm8350, channel, 0, 0) * WM8350_AUX_COEFF;
val = DIV_ROUND_CLOSEST(val, 1000);
return sprintf(buf, "%d\n", val);
}
static ssize_t show_label(struct device *dev,
struct device_attribute *attr, char *buf)
{
int channel = to_sensor_dev_attr(attr)->index;
return sprintf(buf, "%s\n", input_names[channel]);
}
static int wm8350_hwmon_probe(struct platform_device *pdev)
{
struct wm8350 *wm8350 = platform_get_drvdata(pdev);
struct device *hwmon_dev;
hwmon_dev = devm_hwmon_device_register_with_groups(&pdev->dev, "wm8350",
wm8350,
wm8350_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
