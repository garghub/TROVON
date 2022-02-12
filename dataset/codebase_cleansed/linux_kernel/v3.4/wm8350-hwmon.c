static ssize_t show_name(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "wm8350\n");
}
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
static int __devinit wm8350_hwmon_probe(struct platform_device *pdev)
{
struct wm8350 *wm8350 = platform_get_drvdata(pdev);
int ret;
ret = sysfs_create_group(&pdev->dev.kobj, &wm8350_attr_group);
if (ret)
goto err;
wm8350->hwmon.classdev = hwmon_device_register(&pdev->dev);
if (IS_ERR(wm8350->hwmon.classdev)) {
ret = PTR_ERR(wm8350->hwmon.classdev);
goto err_group;
}
return 0;
err_group:
sysfs_remove_group(&pdev->dev.kobj, &wm8350_attr_group);
err:
return ret;
}
static int __devexit wm8350_hwmon_remove(struct platform_device *pdev)
{
struct wm8350 *wm8350 = platform_get_drvdata(pdev);
hwmon_device_unregister(wm8350->hwmon.classdev);
sysfs_remove_group(&pdev->dev.kobj, &wm8350_attr_group);
return 0;
}
