static int da9055_adc_manual_read(struct da9055_hwmon *hwmon,
unsigned char channel)
{
int ret;
unsigned short calc_data;
unsigned short data;
unsigned char mux_sel;
struct da9055 *da9055 = hwmon->da9055;
if (channel > DA9055_ADC_TJUNC)
return -EINVAL;
mutex_lock(&hwmon->irq_lock);
mux_sel = chan_mux[channel] | DA9055_ADC_MAN_CONV;
ret = da9055_reg_write(da9055, DA9055_REG_ADC_MAN, mux_sel);
if (ret < 0)
goto err;
if (!wait_for_completion_timeout(&hwmon->done,
msecs_to_jiffies(500))) {
dev_err(da9055->dev,
"timeout waiting for ADC conversion interrupt\n");
ret = -ETIMEDOUT;
goto err;
}
ret = da9055_reg_read(da9055, DA9055_REG_ADC_RES_H);
if (ret < 0)
goto err;
calc_data = (unsigned short)ret;
data = calc_data << 2;
ret = da9055_reg_read(da9055, DA9055_REG_ADC_RES_L);
if (ret < 0)
goto err;
calc_data = (unsigned short)(ret & DA9055_ADC_LSB_MASK);
data |= calc_data;
ret = data;
err:
mutex_unlock(&hwmon->irq_lock);
return ret;
}
static irqreturn_t da9055_auxadc_irq(int irq, void *irq_data)
{
struct da9055_hwmon *hwmon = irq_data;
complete(&hwmon->done);
return IRQ_HANDLED;
}
static inline int volt_reg_to_mv(int value, int channel)
{
if (channel == DA9055_ADC_VSYS)
return DIV_ROUND_CLOSEST(value * 1000, DA9055_VSYS_DIV) + 2500;
else
return DIV_ROUND_CLOSEST(value * 1000, DA9055_ADCIN_DIV);
}
static int da9055_enable_auto_mode(struct da9055 *da9055, int channel)
{
return da9055_reg_update(da9055, DA9055_REG_ADC_CONT, 1 << channel,
1 << channel);
}
static int da9055_disable_auto_mode(struct da9055 *da9055, int channel)
{
return da9055_reg_update(da9055, DA9055_REG_ADC_CONT, 1 << channel, 0);
}
static ssize_t da9055_read_auto_ch(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct da9055_hwmon *hwmon = dev_get_drvdata(dev);
int ret, adc;
int channel = to_sensor_dev_attr(devattr)->index;
mutex_lock(&hwmon->hwmon_lock);
ret = da9055_enable_auto_mode(hwmon->da9055, channel);
if (ret < 0)
goto hwmon_err;
usleep_range(10000, 10500);
adc = da9055_reg_read(hwmon->da9055, DA9055_REG_VSYS_RES + channel);
if (adc < 0) {
ret = adc;
goto hwmon_err_release;
}
ret = da9055_disable_auto_mode(hwmon->da9055, channel);
if (ret < 0)
goto hwmon_err;
mutex_unlock(&hwmon->hwmon_lock);
return sprintf(buf, "%d\n", volt_reg_to_mv(adc, channel));
hwmon_err_release:
da9055_disable_auto_mode(hwmon->da9055, channel);
hwmon_err:
mutex_unlock(&hwmon->hwmon_lock);
return ret;
}
static ssize_t da9055_read_tjunc(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct da9055_hwmon *hwmon = dev_get_drvdata(dev);
int tjunc;
int toffset;
tjunc = da9055_adc_manual_read(hwmon, DA9055_ADC_TJUNC);
if (tjunc < 0)
return tjunc;
toffset = da9055_reg_read(hwmon->da9055, DA9055_REG_T_OFFSET);
if (toffset < 0)
return toffset;
return sprintf(buf, "%d\n", DIV_ROUND_CLOSEST(-4084 * (tjunc - toffset)
+ 3076332, 10000));
}
static ssize_t da9055_hwmon_show_name(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
return sprintf(buf, "da9055\n");
}
static ssize_t show_label(struct device *dev,
struct device_attribute *devattr, char *buf)
{
return sprintf(buf, "%s\n",
input_names[to_sensor_dev_attr(devattr)->index]);
}
static int da9055_hwmon_probe(struct platform_device *pdev)
{
struct da9055_hwmon *hwmon;
int hwmon_irq, ret;
hwmon = devm_kzalloc(&pdev->dev, sizeof(struct da9055_hwmon),
GFP_KERNEL);
if (!hwmon)
return -ENOMEM;
mutex_init(&hwmon->hwmon_lock);
mutex_init(&hwmon->irq_lock);
init_completion(&hwmon->done);
hwmon->da9055 = dev_get_drvdata(pdev->dev.parent);
platform_set_drvdata(pdev, hwmon);
hwmon_irq = platform_get_irq_byname(pdev, "HWMON");
if (hwmon_irq < 0)
return hwmon_irq;
ret = devm_request_threaded_irq(&pdev->dev, hwmon_irq,
NULL, da9055_auxadc_irq,
IRQF_TRIGGER_HIGH | IRQF_ONESHOT,
"adc-irq", hwmon);
if (ret != 0) {
dev_err(hwmon->da9055->dev, "DA9055 ADC IRQ failed ret=%d\n",
ret);
return ret;
}
ret = sysfs_create_group(&pdev->dev.kobj, &da9055_attr_group);
if (ret)
return ret;
hwmon->class_device = hwmon_device_register(&pdev->dev);
if (IS_ERR(hwmon->class_device)) {
ret = PTR_ERR(hwmon->class_device);
goto err;
}
return 0;
err:
sysfs_remove_group(&pdev->dev.kobj, &da9055_attr_group);
return ret;
}
static int da9055_hwmon_remove(struct platform_device *pdev)
{
struct da9055_hwmon *hwmon = platform_get_drvdata(pdev);
sysfs_remove_group(&pdev->dev.kobj, &da9055_attr_group);
hwmon_device_unregister(hwmon->class_device);
return 0;
}
