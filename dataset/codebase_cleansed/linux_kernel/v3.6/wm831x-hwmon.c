static ssize_t show_name(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "wm831x\n");
}
static ssize_t show_voltage(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct wm831x_hwmon *hwmon = dev_get_drvdata(dev);
int channel = to_sensor_dev_attr(attr)->index;
int ret;
ret = wm831x_auxadc_read_uv(hwmon->wm831x, channel);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", DIV_ROUND_CLOSEST(ret, 1000));
}
static ssize_t show_chip_temp(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct wm831x_hwmon *hwmon = dev_get_drvdata(dev);
int channel = to_sensor_dev_attr(attr)->index;
int ret;
ret = wm831x_auxadc_read(hwmon->wm831x, channel);
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
static int __devinit wm831x_hwmon_probe(struct platform_device *pdev)
{
struct wm831x *wm831x = dev_get_drvdata(pdev->dev.parent);
struct wm831x_hwmon *hwmon;
int ret;
hwmon = devm_kzalloc(&pdev->dev, sizeof(struct wm831x_hwmon),
GFP_KERNEL);
if (!hwmon)
return -ENOMEM;
hwmon->wm831x = wm831x;
ret = sysfs_create_group(&pdev->dev.kobj, &wm831x_attr_group);
if (ret)
return ret;
hwmon->classdev = hwmon_device_register(&pdev->dev);
if (IS_ERR(hwmon->classdev)) {
ret = PTR_ERR(hwmon->classdev);
goto err_sysfs;
}
platform_set_drvdata(pdev, hwmon);
return 0;
err_sysfs:
sysfs_remove_group(&pdev->dev.kobj, &wm831x_attr_group);
return ret;
}
static int __devexit wm831x_hwmon_remove(struct platform_device *pdev)
{
struct wm831x_hwmon *hwmon = platform_get_drvdata(pdev);
hwmon_device_unregister(hwmon->classdev);
sysfs_remove_group(&pdev->dev.kobj, &wm831x_attr_group);
return 0;
}
