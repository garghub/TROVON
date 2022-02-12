static void ltq_cputemp_enable(void)
{
ltq_cgu_w32(ltq_cgu_r32(CGU_GPHY1_CR) | CGU_TEMP_PD, CGU_GPHY1_CR);
}
static void ltq_cputemp_disable(void *data)
{
ltq_cgu_w32(ltq_cgu_r32(CGU_GPHY1_CR) & ~CGU_TEMP_PD, CGU_GPHY1_CR);
}
static int ltq_read(struct device *dev, enum hwmon_sensor_types type,
u32 attr, int channel, long *temp)
{
int value;
switch (attr) {
case hwmon_temp_input:
value = (ltq_cgu_r32(CGU_GPHY1_CR) >> 9) & 0x01FF;
value = value * 5;
value -= 380;
value = value * 100;
break;
default:
return -EOPNOTSUPP;
}
*temp = value;
return 0;
}
static umode_t ltq_is_visible(const void *_data, enum hwmon_sensor_types type,
u32 attr, int channel)
{
if (type != hwmon_temp)
return 0;
switch (attr) {
case hwmon_temp_input:
return 0444;
default:
return 0;
}
}
static int ltq_cputemp_probe(struct platform_device *pdev)
{
struct device *hwmon_dev;
int err = 0;
if (ltq_soc_type() != SOC_TYPE_VR9_2)
return -ENODEV;
err = devm_add_action(&pdev->dev, ltq_cputemp_disable, NULL);
if (err)
return err;
ltq_cputemp_enable();
hwmon_dev = devm_hwmon_device_register_with_info(&pdev->dev,
"ltq_cputemp",
NULL,
&ltq_chip_info,
NULL);
if (IS_ERR(hwmon_dev)) {
dev_err(&pdev->dev, "Failed to register as hwmon device");
return PTR_ERR(hwmon_dev);
}
return 0;
}
