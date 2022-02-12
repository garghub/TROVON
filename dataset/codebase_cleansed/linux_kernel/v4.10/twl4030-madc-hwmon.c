static ssize_t madc_read(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct twl4030_madc_request req = {
.channels = 1 << attr->index,
.method = TWL4030_MADC_SW2,
.type = TWL4030_MADC_WAIT,
};
long val;
val = twl4030_madc_conversion(&req);
if (val < 0)
return val;
return sprintf(buf, "%d\n", req.rbuf[attr->index]);
}
static int twl4030_madc_hwmon_probe(struct platform_device *pdev)
{
struct device *hwmon;
hwmon = devm_hwmon_device_register_with_groups(&pdev->dev,
"twl4030_madc", NULL,
twl4030_madc_groups);
return PTR_ERR_OR_ZERO(hwmon);
}
