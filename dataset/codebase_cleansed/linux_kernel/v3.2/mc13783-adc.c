static ssize_t mc13783_adc_show_name(struct device *dev, struct device_attribute
*devattr, char *buf)
{
return sprintf(buf, "mc13783_adc\n");
}
static int mc13783_adc_read(struct device *dev,
struct device_attribute *devattr, unsigned int *val)
{
struct platform_device *pdev = to_platform_device(dev);
struct mc13783_adc_priv *priv = platform_get_drvdata(pdev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
unsigned int channel = attr->index;
unsigned int sample[4];
int ret;
ret = mc13xxx_adc_do_conversion(priv->mc13xxx,
MC13XXX_ADC_MODE_MULT_CHAN,
channel, sample);
if (ret)
return ret;
channel &= 0x7;
*val = (sample[channel % 4] >> (channel > 3 ? 14 : 2)) & 0x3ff;
return 0;
}
static ssize_t mc13783_adc_read_bp(struct device *dev,
struct device_attribute *devattr, char *buf)
{
unsigned val;
int ret = mc13783_adc_read(dev, devattr, &val);
if (ret)
return ret;
val = DIV_ROUND_CLOSEST(val * 9, 4) + 2400;
return sprintf(buf, "%u\n", val);
}
static ssize_t mc13783_adc_read_gp(struct device *dev,
struct device_attribute *devattr, char *buf)
{
unsigned val;
int ret = mc13783_adc_read(dev, devattr, &val);
if (ret)
return ret;
val = DIV_ROUND_CLOSEST(val * 9, 4);
return sprintf(buf, "%u\n", val);
}
static int mc13783_adc_use_touchscreen(struct platform_device *pdev)
{
struct mc13783_adc_priv *priv = platform_get_drvdata(pdev);
unsigned flags = mc13xxx_get_flags(priv->mc13xxx);
return flags & MC13XXX_USE_TOUCHSCREEN;
}
static int __init mc13783_adc_probe(struct platform_device *pdev)
{
struct mc13783_adc_priv *priv;
int ret;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->mc13xxx = dev_get_drvdata(pdev->dev.parent);
platform_set_drvdata(pdev, priv);
ret = sysfs_create_group(&pdev->dev.kobj, &mc13783_group);
if (ret)
goto out_err_create1;
if (!mc13783_adc_use_touchscreen(pdev)) {
ret = sysfs_create_group(&pdev->dev.kobj, &mc13783_group_ts);
if (ret)
goto out_err_create2;
}
priv->hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(priv->hwmon_dev)) {
ret = PTR_ERR(priv->hwmon_dev);
dev_err(&pdev->dev,
"hwmon_device_register failed with %d.\n", ret);
goto out_err_register;
}
return 0;
out_err_register:
if (!mc13783_adc_use_touchscreen(pdev))
sysfs_remove_group(&pdev->dev.kobj, &mc13783_group_ts);
out_err_create2:
sysfs_remove_group(&pdev->dev.kobj, &mc13783_group);
out_err_create1:
platform_set_drvdata(pdev, NULL);
kfree(priv);
return ret;
}
static int __devexit mc13783_adc_remove(struct platform_device *pdev)
{
struct mc13783_adc_priv *priv = platform_get_drvdata(pdev);
hwmon_device_unregister(priv->hwmon_dev);
if (!mc13783_adc_use_touchscreen(pdev))
sysfs_remove_group(&pdev->dev.kobj, &mc13783_group_ts);
sysfs_remove_group(&pdev->dev.kobj, &mc13783_group);
platform_set_drvdata(pdev, NULL);
kfree(priv);
return 0;
}
static int __init mc13783_adc_init(void)
{
return platform_driver_probe(&mc13783_adc_driver, mc13783_adc_probe);
}
static void __exit mc13783_adc_exit(void)
{
platform_driver_unregister(&mc13783_adc_driver);
}
