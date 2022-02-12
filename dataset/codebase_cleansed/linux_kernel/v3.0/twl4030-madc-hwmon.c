static ssize_t madc_read(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct twl4030_madc_request req;
long val;
req.channels = (1 << attr->index);
req.method = TWL4030_MADC_SW2;
req.func_cb = NULL;
val = twl4030_madc_conversion(&req);
if (val < 0)
return val;
return sprintf(buf, "%d\n", req.rbuf[attr->index]);
}
static int __devinit twl4030_madc_hwmon_probe(struct platform_device *pdev)
{
int ret;
struct device *hwmon;
ret = sysfs_create_group(&pdev->dev.kobj, &twl4030_madc_group);
if (ret)
goto err_sysfs;
hwmon = hwmon_device_register(&pdev->dev);
if (IS_ERR(hwmon)) {
dev_err(&pdev->dev, "hwmon_device_register failed.\n");
ret = PTR_ERR(hwmon);
goto err_reg;
}
return 0;
err_reg:
sysfs_remove_group(&pdev->dev.kobj, &twl4030_madc_group);
err_sysfs:
return ret;
}
static int __devexit twl4030_madc_hwmon_remove(struct platform_device *pdev)
{
hwmon_device_unregister(&pdev->dev);
sysfs_remove_group(&pdev->dev.kobj, &twl4030_madc_group);
return 0;
}
static int __init twl4030_madc_hwmon_init(void)
{
return platform_driver_register(&twl4030_madc_hwmon_driver);
}
static void __exit twl4030_madc_hwmon_exit(void)
{
platform_driver_unregister(&twl4030_madc_hwmon_driver);
}
