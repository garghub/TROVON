static ssize_t mc13783_adc_show_name(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct mc13783_adc_priv *priv = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", priv->name);
}
static int mc13783_adc_read(struct device *dev,
struct device_attribute *devattr, unsigned int *val)
{
struct mc13783_adc_priv *priv = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
unsigned int channel = attr->index;
unsigned int sample[4];
int ret;
ret = mc13xxx_adc_do_conversion(priv->mc13xxx,
MC13XXX_ADC_MODE_MULT_CHAN,
channel, 0, 0, sample);
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
struct platform_device *pdev = to_platform_device(dev);
kernel_ulong_t driver_data = platform_get_device_id(pdev)->driver_data;
int ret = mc13783_adc_read(dev, devattr, &val);
if (ret)
return ret;
if (driver_data & MC13783_ADC_BPDIV2)
val = DIV_ROUND_CLOSEST(val * 9, 2);
else
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
const struct platform_device_id *id = platform_get_device_id(pdev);
char *dash;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->mc13xxx = dev_get_drvdata(pdev->dev.parent);
snprintf(priv->name, ARRAY_SIZE(priv->name), "%s", id->name);
dash = strchr(priv->name, '-');
if (dash)
*dash = '\0';
platform_set_drvdata(pdev, priv);
ret = sysfs_create_group(&pdev->dev.kobj, &mc13783_group_base);
if (ret)
return ret;
if (id->driver_data & MC13783_ADC_16CHANS) {
ret = sysfs_create_group(&pdev->dev.kobj,
&mc13783_group_16chans);
if (ret)
goto out_err_create_16chans;
}
if (!mc13783_adc_use_touchscreen(pdev)) {
ret = sysfs_create_group(&pdev->dev.kobj, &mc13783_group_ts);
if (ret)
goto out_err_create_ts;
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
out_err_create_ts:
if (id->driver_data & MC13783_ADC_16CHANS)
sysfs_remove_group(&pdev->dev.kobj, &mc13783_group_16chans);
out_err_create_16chans:
sysfs_remove_group(&pdev->dev.kobj, &mc13783_group_base);
return ret;
}
static int mc13783_adc_remove(struct platform_device *pdev)
{
struct mc13783_adc_priv *priv = platform_get_drvdata(pdev);
kernel_ulong_t driver_data = platform_get_device_id(pdev)->driver_data;
hwmon_device_unregister(priv->hwmon_dev);
if (!mc13783_adc_use_touchscreen(pdev))
sysfs_remove_group(&pdev->dev.kobj, &mc13783_group_ts);
if (driver_data & MC13783_ADC_16CHANS)
sysfs_remove_group(&pdev->dev.kobj, &mc13783_group_16chans);
sysfs_remove_group(&pdev->dev.kobj, &mc13783_group_base);
return 0;
}
