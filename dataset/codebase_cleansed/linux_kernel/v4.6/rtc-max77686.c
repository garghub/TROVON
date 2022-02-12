static void max77686_rtc_data_to_tm(u8 *data, struct rtc_time *tm,
struct max77686_rtc_info *info)
{
u8 mask = info->drv_data->mask;
tm->tm_sec = data[RTC_SEC] & mask;
tm->tm_min = data[RTC_MIN] & mask;
if (info->rtc_24hr_mode) {
tm->tm_hour = data[RTC_HOUR] & 0x1f;
} else {
tm->tm_hour = data[RTC_HOUR] & 0x0f;
if (data[RTC_HOUR] & HOUR_PM_MASK)
tm->tm_hour += 12;
}
tm->tm_wday = ffs(data[RTC_WEEKDAY] & mask) - 1;
tm->tm_mday = data[RTC_DATE] & 0x1f;
tm->tm_mon = (data[RTC_MONTH] & 0x0f) - 1;
tm->tm_year = data[RTC_YEAR] & mask;
tm->tm_yday = 0;
tm->tm_isdst = 0;
if (!info->drv_data->alarm_enable_reg)
tm->tm_year += 100;
}
static int max77686_rtc_tm_to_data(struct rtc_time *tm, u8 *data,
struct max77686_rtc_info *info)
{
data[RTC_SEC] = tm->tm_sec;
data[RTC_MIN] = tm->tm_min;
data[RTC_HOUR] = tm->tm_hour;
data[RTC_WEEKDAY] = 1 << tm->tm_wday;
data[RTC_DATE] = tm->tm_mday;
data[RTC_MONTH] = tm->tm_mon + 1;
if (info->drv_data->alarm_enable_reg) {
data[RTC_YEAR] = tm->tm_year;
return 0;
}
data[RTC_YEAR] = tm->tm_year > 100 ? (tm->tm_year - 100) : 0;
if (tm->tm_year < 100) {
dev_err(info->dev, "RTC cannot handle the year %d.\n",
1900 + tm->tm_year);
return -EINVAL;
}
return 0;
}
static int max77686_rtc_update(struct max77686_rtc_info *info,
enum MAX77686_RTC_OP op)
{
int ret;
unsigned int data;
unsigned long delay = info->drv_data->delay;
if (op == MAX77686_RTC_WRITE)
data = 1 << RTC_UDR_SHIFT;
else
data = 1 << RTC_RBUDR_SHIFT;
ret = regmap_update_bits(info->rtc_regmap,
info->drv_data->map[REG_RTC_UPDATE0],
data, data);
if (ret < 0)
dev_err(info->dev, "Fail to write update reg(ret=%d, data=0x%x)\n",
ret, data);
else {
usleep_range(delay, delay * 2);
}
return ret;
}
static int max77686_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct max77686_rtc_info *info = dev_get_drvdata(dev);
u8 data[RTC_NR_TIME];
int ret;
mutex_lock(&info->lock);
ret = max77686_rtc_update(info, MAX77686_RTC_READ);
if (ret < 0)
goto out;
ret = regmap_bulk_read(info->rtc_regmap,
info->drv_data->map[REG_RTC_SEC],
data, ARRAY_SIZE(data));
if (ret < 0) {
dev_err(info->dev, "Fail to read time reg(%d)\n", ret);
goto out;
}
max77686_rtc_data_to_tm(data, tm, info);
ret = rtc_valid_tm(tm);
out:
mutex_unlock(&info->lock);
return ret;
}
static int max77686_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct max77686_rtc_info *info = dev_get_drvdata(dev);
u8 data[RTC_NR_TIME];
int ret;
ret = max77686_rtc_tm_to_data(tm, data, info);
if (ret < 0)
return ret;
mutex_lock(&info->lock);
ret = regmap_bulk_write(info->rtc_regmap,
info->drv_data->map[REG_RTC_SEC],
data, ARRAY_SIZE(data));
if (ret < 0) {
dev_err(info->dev, "Fail to write time reg(%d)\n", ret);
goto out;
}
ret = max77686_rtc_update(info, MAX77686_RTC_WRITE);
out:
mutex_unlock(&info->lock);
return ret;
}
static int max77686_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct max77686_rtc_info *info = dev_get_drvdata(dev);
u8 data[RTC_NR_TIME];
unsigned int val;
const unsigned int *map = info->drv_data->map;
int i, ret;
mutex_lock(&info->lock);
ret = max77686_rtc_update(info, MAX77686_RTC_READ);
if (ret < 0)
goto out;
ret = regmap_bulk_read(info->rtc_regmap, map[REG_ALARM1_SEC],
data, ARRAY_SIZE(data));
if (ret < 0) {
dev_err(info->dev, "Fail to read alarm reg(%d)\n", ret);
goto out;
}
max77686_rtc_data_to_tm(data, &alrm->time, info);
alrm->enabled = 0;
if (info->drv_data->alarm_enable_reg) {
if (map[REG_RTC_AE1] == REG_RTC_NONE) {
ret = -EINVAL;
dev_err(info->dev,
"alarm enable register not set(%d)\n", ret);
goto out;
}
ret = regmap_read(info->rtc_regmap, map[REG_RTC_AE1], &val);
if (ret < 0) {
dev_err(info->dev,
"fail to read alarm enable(%d)\n", ret);
goto out;
}
if (val)
alrm->enabled = 1;
} else {
for (i = 0; i < ARRAY_SIZE(data); i++) {
if (data[i] & ALARM_ENABLE_MASK) {
alrm->enabled = 1;
break;
}
}
}
alrm->pending = 0;
if (info->drv_data->alarm_pending_status_reg == MAX77686_INVALID_REG)
goto out;
ret = regmap_read(info->regmap,
info->drv_data->alarm_pending_status_reg, &val);
if (ret < 0) {
dev_err(info->dev,
"Fail to read alarm pending status reg(%d)\n", ret);
goto out;
}
if (val & (1 << 4))
alrm->pending = 1;
out:
mutex_unlock(&info->lock);
return ret;
}
static int max77686_rtc_stop_alarm(struct max77686_rtc_info *info)
{
u8 data[RTC_NR_TIME];
int ret, i;
struct rtc_time tm;
const unsigned int *map = info->drv_data->map;
if (!mutex_is_locked(&info->lock))
dev_warn(info->dev, "%s: should have mutex locked\n", __func__);
ret = max77686_rtc_update(info, MAX77686_RTC_READ);
if (ret < 0)
goto out;
if (info->drv_data->alarm_enable_reg) {
if (map[REG_RTC_AE1] == REG_RTC_NONE) {
ret = -EINVAL;
dev_err(info->dev,
"alarm enable register not set(%d)\n", ret);
goto out;
}
ret = regmap_write(info->rtc_regmap, map[REG_RTC_AE1], 0);
} else {
ret = regmap_bulk_read(info->rtc_regmap, map[REG_ALARM1_SEC],
data, ARRAY_SIZE(data));
if (ret < 0) {
dev_err(info->dev, "Fail to read alarm reg(%d)\n", ret);
goto out;
}
max77686_rtc_data_to_tm(data, &tm, info);
for (i = 0; i < ARRAY_SIZE(data); i++)
data[i] &= ~ALARM_ENABLE_MASK;
ret = regmap_bulk_write(info->rtc_regmap, map[REG_ALARM1_SEC],
data, ARRAY_SIZE(data));
}
if (ret < 0) {
dev_err(info->dev, "Fail to write alarm reg(%d)\n", ret);
goto out;
}
ret = max77686_rtc_update(info, MAX77686_RTC_WRITE);
out:
return ret;
}
static int max77686_rtc_start_alarm(struct max77686_rtc_info *info)
{
u8 data[RTC_NR_TIME];
int ret;
struct rtc_time tm;
const unsigned int *map = info->drv_data->map;
if (!mutex_is_locked(&info->lock))
dev_warn(info->dev, "%s: should have mutex locked\n", __func__);
ret = max77686_rtc_update(info, MAX77686_RTC_READ);
if (ret < 0)
goto out;
if (info->drv_data->alarm_enable_reg) {
ret = regmap_write(info->rtc_regmap, map[REG_RTC_AE1],
MAX77802_ALARM_ENABLE_VALUE);
} else {
ret = regmap_bulk_read(info->rtc_regmap, map[REG_ALARM1_SEC],
data, ARRAY_SIZE(data));
if (ret < 0) {
dev_err(info->dev, "Fail to read alarm reg(%d)\n", ret);
goto out;
}
max77686_rtc_data_to_tm(data, &tm, info);
data[RTC_SEC] |= (1 << ALARM_ENABLE_SHIFT);
data[RTC_MIN] |= (1 << ALARM_ENABLE_SHIFT);
data[RTC_HOUR] |= (1 << ALARM_ENABLE_SHIFT);
data[RTC_WEEKDAY] &= ~ALARM_ENABLE_MASK;
if (data[RTC_MONTH] & 0xf)
data[RTC_MONTH] |= (1 << ALARM_ENABLE_SHIFT);
if (data[RTC_YEAR] & info->drv_data->mask)
data[RTC_YEAR] |= (1 << ALARM_ENABLE_SHIFT);
if (data[RTC_DATE] & 0x1f)
data[RTC_DATE] |= (1 << ALARM_ENABLE_SHIFT);
ret = regmap_bulk_write(info->rtc_regmap, map[REG_ALARM1_SEC],
data, ARRAY_SIZE(data));
}
if (ret < 0) {
dev_err(info->dev, "Fail to write alarm reg(%d)\n", ret);
goto out;
}
ret = max77686_rtc_update(info, MAX77686_RTC_WRITE);
out:
return ret;
}
static int max77686_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct max77686_rtc_info *info = dev_get_drvdata(dev);
u8 data[RTC_NR_TIME];
int ret;
ret = max77686_rtc_tm_to_data(&alrm->time, data, info);
if (ret < 0)
return ret;
mutex_lock(&info->lock);
ret = max77686_rtc_stop_alarm(info);
if (ret < 0)
goto out;
ret = regmap_bulk_write(info->rtc_regmap,
info->drv_data->map[REG_ALARM1_SEC],
data, ARRAY_SIZE(data));
if (ret < 0) {
dev_err(info->dev, "Fail to write alarm reg(%d)\n", ret);
goto out;
}
ret = max77686_rtc_update(info, MAX77686_RTC_WRITE);
if (ret < 0)
goto out;
if (alrm->enabled)
ret = max77686_rtc_start_alarm(info);
out:
mutex_unlock(&info->lock);
return ret;
}
static int max77686_rtc_alarm_irq_enable(struct device *dev,
unsigned int enabled)
{
struct max77686_rtc_info *info = dev_get_drvdata(dev);
int ret;
mutex_lock(&info->lock);
if (enabled)
ret = max77686_rtc_start_alarm(info);
else
ret = max77686_rtc_stop_alarm(info);
mutex_unlock(&info->lock);
return ret;
}
static irqreturn_t max77686_rtc_alarm_irq(int irq, void *data)
{
struct max77686_rtc_info *info = data;
dev_dbg(info->dev, "RTC alarm IRQ: %d\n", irq);
rtc_update_irq(info->rtc_dev, 1, RTC_IRQF | RTC_AF);
return IRQ_HANDLED;
}
static int max77686_rtc_init_reg(struct max77686_rtc_info *info)
{
u8 data[2];
int ret;
data[0] = (1 << BCD_EN_SHIFT) | (1 << MODEL24_SHIFT);
data[1] = (0 << BCD_EN_SHIFT) | (1 << MODEL24_SHIFT);
info->rtc_24hr_mode = 1;
ret = regmap_bulk_write(info->rtc_regmap,
info->drv_data->map[REG_RTC_CONTROLM],
data, ARRAY_SIZE(data));
if (ret < 0) {
dev_err(info->dev, "Fail to write controlm reg(%d)\n", ret);
return ret;
}
ret = max77686_rtc_update(info, MAX77686_RTC_WRITE);
return ret;
}
static int max77686_init_rtc_regmap(struct max77686_rtc_info *info)
{
struct device *parent = info->dev->parent;
struct i2c_client *parent_i2c = to_i2c_client(parent);
int ret;
if (info->drv_data->rtc_irq_from_platform) {
struct platform_device *pdev = to_platform_device(info->dev);
info->rtc_irq = platform_get_irq(pdev, 0);
if (info->rtc_irq < 0) {
dev_err(info->dev, "Failed to get rtc interrupts: %d\n",
info->rtc_irq);
return info->rtc_irq;
}
} else {
info->rtc_irq = parent_i2c->irq;
}
info->regmap = dev_get_regmap(parent, NULL);
if (!info->regmap) {
dev_err(info->dev, "Failed to get rtc regmap\n");
return -ENODEV;
}
if (info->drv_data->rtc_i2c_addr == MAX77686_INVALID_I2C_ADDR) {
info->rtc_regmap = info->regmap;
goto add_rtc_irq;
}
info->rtc = i2c_new_dummy(parent_i2c->adapter,
info->drv_data->rtc_i2c_addr);
if (!info->rtc) {
dev_err(info->dev, "Failed to allocate I2C device for RTC\n");
return -ENODEV;
}
info->rtc_regmap = devm_regmap_init_i2c(info->rtc,
&max77686_rtc_regmap_config);
if (IS_ERR(info->rtc_regmap)) {
ret = PTR_ERR(info->rtc_regmap);
dev_err(info->dev, "Failed to allocate RTC regmap: %d\n", ret);
goto err_unregister_i2c;
}
add_rtc_irq:
ret = regmap_add_irq_chip(info->rtc_regmap, info->rtc_irq,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT |
IRQF_SHARED, 0, info->drv_data->rtc_irq_chip,
&info->rtc_irq_data);
if (ret < 0) {
dev_err(info->dev, "Failed to add RTC irq chip: %d\n", ret);
goto err_unregister_i2c;
}
return 0;
err_unregister_i2c:
if (info->rtc)
i2c_unregister_device(info->rtc);
return ret;
}
static int max77686_rtc_probe(struct platform_device *pdev)
{
struct max77686_rtc_info *info;
const struct platform_device_id *id = platform_get_device_id(pdev);
int ret;
info = devm_kzalloc(&pdev->dev, sizeof(struct max77686_rtc_info),
GFP_KERNEL);
if (!info)
return -ENOMEM;
mutex_init(&info->lock);
info->dev = &pdev->dev;
info->drv_data = (const struct max77686_rtc_driver_data *)
id->driver_data;
ret = max77686_init_rtc_regmap(info);
if (ret < 0)
return ret;
platform_set_drvdata(pdev, info);
ret = max77686_rtc_init_reg(info);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to initialize RTC reg:%d\n", ret);
goto err_rtc;
}
device_init_wakeup(&pdev->dev, 1);
info->rtc_dev = devm_rtc_device_register(&pdev->dev, id->name,
&max77686_rtc_ops, THIS_MODULE);
if (IS_ERR(info->rtc_dev)) {
ret = PTR_ERR(info->rtc_dev);
dev_err(&pdev->dev, "Failed to register RTC device: %d\n", ret);
if (ret == 0)
ret = -EINVAL;
goto err_rtc;
}
info->virq = regmap_irq_get_virq(info->rtc_irq_data,
MAX77686_RTCIRQ_RTCA1);
if (info->virq <= 0) {
ret = -ENXIO;
goto err_rtc;
}
ret = request_threaded_irq(info->virq, NULL, max77686_rtc_alarm_irq, 0,
"rtc-alarm1", info);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to request alarm IRQ: %d: %d\n",
info->virq, ret);
goto err_rtc;
}
return 0;
err_rtc:
regmap_del_irq_chip(info->rtc_irq, info->rtc_irq_data);
if (info->rtc)
i2c_unregister_device(info->rtc);
return ret;
}
static int max77686_rtc_remove(struct platform_device *pdev)
{
struct max77686_rtc_info *info = platform_get_drvdata(pdev);
free_irq(info->virq, info);
regmap_del_irq_chip(info->rtc_irq, info->rtc_irq_data);
if (info->rtc)
i2c_unregister_device(info->rtc);
return 0;
}
static int max77686_rtc_suspend(struct device *dev)
{
if (device_may_wakeup(dev)) {
struct max77686_rtc_info *info = dev_get_drvdata(dev);
return enable_irq_wake(info->virq);
}
return 0;
}
static int max77686_rtc_resume(struct device *dev)
{
if (device_may_wakeup(dev)) {
struct max77686_rtc_info *info = dev_get_drvdata(dev);
return disable_irq_wake(info->virq);
}
return 0;
}
