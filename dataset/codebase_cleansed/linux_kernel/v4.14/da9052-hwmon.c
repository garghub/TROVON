static inline int volt_reg_to_mv(int value)
{
return DIV_ROUND_CLOSEST(value * 2000, 1023) + 2500;
}
static inline int input_reg_to_mv(int value)
{
return DIV_ROUND_CLOSEST(value * 2500, 1023);
}
static inline int vbbat_reg_to_mv(int value)
{
return DIV_ROUND_CLOSEST(value * 5000, 1023);
}
static inline int input_tsireg_to_mv(struct da9052_hwmon *hwmon, int value)
{
return DIV_ROUND_CLOSEST(value * hwmon->tsiref_mv, 1023);
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
static int da9052_request_tsi_read(struct da9052_hwmon *hwmon, int channel)
{
u8 val = DA9052_TSICONTB_TSIMAN;
switch (channel) {
case DA9052_ADC_TSI_XP:
val |= DA9052_TSICONTB_TSIMUX_XP;
break;
case DA9052_ADC_TSI_YP:
val |= DA9052_TSICONTB_TSIMUX_YP;
break;
case DA9052_ADC_TSI_XN:
val |= DA9052_TSICONTB_TSIMUX_XN;
break;
case DA9052_ADC_TSI_YN:
val |= DA9052_TSICONTB_TSIMUX_YN;
break;
}
return da9052_reg_write(hwmon->da9052, DA9052_TSI_CONT_B_REG, val);
}
static int da9052_get_tsi_result(struct da9052_hwmon *hwmon, int channel)
{
u8 regs[3];
int msb, lsb, err;
err = da9052_group_read(hwmon->da9052, DA9052_TSI_X_MSB_REG,
ARRAY_SIZE(regs), regs);
if (err)
return err;
switch (channel) {
case DA9052_ADC_TSI_XP:
case DA9052_ADC_TSI_XN:
msb = regs[0] << DA9052_TSILSB_TSIXL_BITS;
lsb = regs[2] & DA9052_TSILSB_TSIXL;
lsb >>= DA9052_TSILSB_TSIXL_SHIFT;
break;
case DA9052_ADC_TSI_YP:
case DA9052_ADC_TSI_YN:
msb = regs[1] << DA9052_TSILSB_TSIYL_BITS;
lsb = regs[2] & DA9052_TSILSB_TSIYL;
lsb >>= DA9052_TSILSB_TSIYL_SHIFT;
break;
default:
return -EINVAL;
}
return msb | lsb;
}
static ssize_t __da9052_read_tsi(struct device *dev, int channel)
{
struct da9052_hwmon *hwmon = dev_get_drvdata(dev);
int ret;
reinit_completion(&hwmon->tsidone);
ret = da9052_request_tsi_read(hwmon, channel);
if (ret < 0)
return ret;
if (!wait_for_completion_timeout(&hwmon->tsidone,
msecs_to_jiffies(500)))
return -ETIMEDOUT;
return da9052_get_tsi_result(hwmon, channel);
}
static ssize_t da9052_read_tsi(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct da9052_hwmon *hwmon = dev_get_drvdata(dev);
int channel = to_sensor_dev_attr(devattr)->index;
int ret;
mutex_lock(&hwmon->hwmon_lock);
ret = __da9052_read_tsi(dev, channel);
mutex_unlock(&hwmon->hwmon_lock);
if (ret < 0)
return ret;
else
return sprintf(buf, "%d\n", input_tsireg_to_mv(hwmon, ret));
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
static ssize_t show_label(struct device *dev,
struct device_attribute *devattr, char *buf)
{
return sprintf(buf, "%s\n",
input_names[to_sensor_dev_attr(devattr)->index]);
}
static umode_t da9052_channel_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct da9052_hwmon *hwmon = dev_get_drvdata(dev);
struct device_attribute *dattr = container_of(attr,
struct device_attribute, attr);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(dattr);
if (!hwmon->tsi_as_adc) {
switch (sattr->index) {
case DA9052_ADC_TSI_XP:
case DA9052_ADC_TSI_YP:
case DA9052_ADC_TSI_XN:
case DA9052_ADC_TSI_YN:
return 0;
}
}
return attr->mode;
}
static irqreturn_t da9052_tsi_datardy_irq(int irq, void *data)
{
struct da9052_hwmon *hwmon = data;
complete(&hwmon->tsidone);
return IRQ_HANDLED;
}
static int da9052_hwmon_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct da9052_hwmon *hwmon;
struct device *hwmon_dev;
int err;
hwmon = devm_kzalloc(dev, sizeof(struct da9052_hwmon), GFP_KERNEL);
if (!hwmon)
return -ENOMEM;
platform_set_drvdata(pdev, hwmon);
mutex_init(&hwmon->hwmon_lock);
hwmon->da9052 = dev_get_drvdata(pdev->dev.parent);
init_completion(&hwmon->tsidone);
hwmon->tsi_as_adc =
device_property_read_bool(pdev->dev.parent, "dlg,tsi-as-adc");
if (hwmon->tsi_as_adc) {
hwmon->tsiref = devm_regulator_get(pdev->dev.parent, "tsiref");
if (IS_ERR(hwmon->tsiref)) {
err = PTR_ERR(hwmon->tsiref);
dev_err(&pdev->dev, "failed to get tsiref: %d", err);
return err;
}
err = regulator_enable(hwmon->tsiref);
if (err)
return err;
hwmon->tsiref_mv = regulator_get_voltage(hwmon->tsiref);
if (hwmon->tsiref_mv < 0) {
err = hwmon->tsiref_mv;
goto exit_regulator;
}
hwmon->tsiref_mv /= 1000;
if (hwmon->tsiref_mv < 1800 || hwmon->tsiref_mv > 2600) {
dev_err(hwmon->da9052->dev, "invalid TSIREF voltage: %d",
hwmon->tsiref_mv);
err = -ENXIO;
goto exit_regulator;
}
da9052_reg_write(hwmon->da9052, DA9052_TSI_CONT_A_REG, 0x00);
da9052_reg_update(hwmon->da9052, DA9052_ADC_CONT_REG,
DA9052_ADCCONT_ADCMODE,
DA9052_ADCCONT_ADCMODE);
err = da9052_request_irq(hwmon->da9052, DA9052_IRQ_TSIREADY,
"tsiready-irq", da9052_tsi_datardy_irq,
hwmon);
if (err) {
dev_err(&pdev->dev, "Failed to register TSIRDY IRQ: %d",
err);
goto exit_regulator;
}
}
hwmon_dev = devm_hwmon_device_register_with_groups(dev, "da9052",
hwmon,
da9052_groups);
err = PTR_ERR_OR_ZERO(hwmon_dev);
if (err)
goto exit_irq;
return 0;
exit_irq:
if (hwmon->tsi_as_adc)
da9052_free_irq(hwmon->da9052, DA9052_IRQ_TSIREADY, hwmon);
exit_regulator:
if (hwmon->tsiref)
regulator_disable(hwmon->tsiref);
return err;
}
static int da9052_hwmon_remove(struct platform_device *pdev)
{
struct da9052_hwmon *hwmon = platform_get_drvdata(pdev);
if (hwmon->tsi_as_adc) {
da9052_free_irq(hwmon->da9052, DA9052_IRQ_TSIREADY, hwmon);
regulator_disable(hwmon->tsiref);
}
return 0;
}
