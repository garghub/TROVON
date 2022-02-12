static inline int volt_reg_to_mv(int value)
{
return DIV_ROUND_CLOSEST(value * 1000, 512) + 2500;
}
static inline int input_reg_to_mv(int value)
{
return DIV_ROUND_CLOSEST(value * 2500, 1023);
}
static inline int vbbat_reg_to_mv(int value)
{
return DIV_ROUND_CLOSEST(value * 2500, 512);
}
static inline int da9052_enable_vddout_channel(struct da9052 *da9052)
{
return da9052_reg_update(da9052, DA9052_ADC_CONT_REG,
DA9052_ADCCONT_AUTOVDDEN,
DA9052_ADCCONT_AUTOVDDEN);
}
static inline int da9052_disable_vddout_channel(struct da9052 *da9052)
{
return da9052_reg_update(da9052, DA9052_ADC_CONT_REG,
DA9052_ADCCONT_AUTOVDDEN, 0);
}
static ssize_t da9052_read_vddout(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct da9052_hwmon *hwmon = dev_get_drvdata(dev);
int ret, vdd;
mutex_lock(&hwmon->hwmon_lock);
ret = da9052_enable_vddout_channel(hwmon->da9052);
if (ret < 0)
goto hwmon_err;
vdd = da9052_reg_read(hwmon->da9052, DA9052_VDD_RES_REG);
if (vdd < 0) {
ret = vdd;
goto hwmon_err_release;
}
ret = da9052_disable_vddout_channel(hwmon->da9052);
if (ret < 0)
goto hwmon_err;
mutex_unlock(&hwmon->hwmon_lock);
return sprintf(buf, "%d\n", volt_reg_to_mv(vdd));
hwmon_err_release:
da9052_disable_vddout_channel(hwmon->da9052);
hwmon_err:
mutex_unlock(&hwmon->hwmon_lock);
return ret;
}
static ssize_t da9052_read_ich(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct da9052_hwmon *hwmon = dev_get_drvdata(dev);
int ret;
ret = da9052_reg_read(hwmon->da9052, DA9052_ICHG_AV_REG);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", DIV_ROUND_CLOSEST(ret * 39, 10));
}
static ssize_t da9052_read_tbat(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct da9052_hwmon *hwmon = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", da9052_adc_read_temp(hwmon->da9052));
}
static ssize_t da9052_read_vbat(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct da9052_hwmon *hwmon = dev_get_drvdata(dev);
int ret;
ret = da9052_adc_manual_read(hwmon->da9052, DA9052_ADC_VBAT);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", volt_reg_to_mv(ret));
}
static ssize_t da9052_read_misc_channel(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct da9052_hwmon *hwmon = dev_get_drvdata(dev);
int channel = to_sensor_dev_attr(devattr)->index;
int ret;
ret = da9052_adc_manual_read(hwmon->da9052, channel);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", input_reg_to_mv(ret));
}
static ssize_t da9052_read_tjunc(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct da9052_hwmon *hwmon = dev_get_drvdata(dev);
int tjunc;
int toffset;
tjunc = da9052_reg_read(hwmon->da9052, DA9052_TJUNC_RES_REG);
if (tjunc < 0)
return tjunc;
toffset = da9052_reg_read(hwmon->da9052, DA9052_T_OFFSET_REG);
if (toffset < 0)
return toffset;
return sprintf(buf, "%d\n", 1708 * (tjunc - toffset) - 108800);
}
static ssize_t da9052_read_vbbat(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct da9052_hwmon *hwmon = dev_get_drvdata(dev);
int ret;
ret = da9052_adc_manual_read(hwmon->da9052, DA9052_ADC_VBBAT);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", vbbat_reg_to_mv(ret));
}
static ssize_t da9052_hwmon_show_name(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
return sprintf(buf, "da9052-hwmon\n");
}
static ssize_t show_label(struct device *dev,
struct device_attribute *devattr, char *buf)
{
return sprintf(buf, "%s\n",
input_names[to_sensor_dev_attr(devattr)->index]);
}
static int da9052_hwmon_probe(struct platform_device *pdev)
{
struct da9052_hwmon *hwmon;
int ret;
hwmon = devm_kzalloc(&pdev->dev, sizeof(struct da9052_hwmon),
GFP_KERNEL);
if (!hwmon)
return -ENOMEM;
mutex_init(&hwmon->hwmon_lock);
hwmon->da9052 = dev_get_drvdata(pdev->dev.parent);
platform_set_drvdata(pdev, hwmon);
ret = sysfs_create_group(&pdev->dev.kobj, &da9052_attr_group);
if (ret)
goto err_mem;
hwmon->class_device = hwmon_device_register(&pdev->dev);
if (IS_ERR(hwmon->class_device)) {
ret = PTR_ERR(hwmon->class_device);
goto err_sysfs;
}
return 0;
err_sysfs:
sysfs_remove_group(&pdev->dev.kobj, &da9052_attr_group);
err_mem:
return ret;
}
static int da9052_hwmon_remove(struct platform_device *pdev)
{
struct da9052_hwmon *hwmon = platform_get_drvdata(pdev);
hwmon_device_unregister(hwmon->class_device);
sysfs_remove_group(&pdev->dev.kobj, &da9052_attr_group);
return 0;
}
