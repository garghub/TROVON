static void max8998_data_to_tm(u8 *data, struct rtc_time *tm)
{
tm->tm_sec = bcd2bin(data[RTC_SEC]);
tm->tm_min = bcd2bin(data[RTC_MIN]);
if (data[RTC_HOUR] & HOUR_12) {
tm->tm_hour = bcd2bin(data[RTC_HOUR] & 0x1f);
if (data[RTC_HOUR] & HOUR_PM)
tm->tm_hour += 12;
} else
tm->tm_hour = bcd2bin(data[RTC_HOUR] & 0x3f);
tm->tm_wday = data[RTC_WEEKDAY] & 0x07;
tm->tm_mday = bcd2bin(data[RTC_DATE]);
tm->tm_mon = bcd2bin(data[RTC_MONTH]);
tm->tm_year = bcd2bin(data[RTC_YEAR1]) + bcd2bin(data[RTC_YEAR2]) * 100;
tm->tm_year -= 1900;
}
static void max8998_tm_to_data(struct rtc_time *tm, u8 *data)
{
data[RTC_SEC] = bin2bcd(tm->tm_sec);
data[RTC_MIN] = bin2bcd(tm->tm_min);
data[RTC_HOUR] = bin2bcd(tm->tm_hour);
data[RTC_WEEKDAY] = tm->tm_wday;
data[RTC_DATE] = bin2bcd(tm->tm_mday);
data[RTC_MONTH] = bin2bcd(tm->tm_mon);
data[RTC_YEAR1] = bin2bcd(tm->tm_year % 100);
data[RTC_YEAR2] = bin2bcd((tm->tm_year + 1900) / 100);
}
static int max8998_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct max8998_rtc_info *info = dev_get_drvdata(dev);
u8 data[8];
int ret;
ret = max8998_bulk_read(info->rtc, MAX8998_RTC_SEC, 8, data);
if (ret < 0)
return ret;
max8998_data_to_tm(data, tm);
return rtc_valid_tm(tm);
}
static int max8998_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct max8998_rtc_info *info = dev_get_drvdata(dev);
u8 data[8];
int ret;
max8998_tm_to_data(tm, data);
ret = max8998_bulk_write(info->rtc, MAX8998_RTC_SEC, 8, data);
if (info->lp3974_bug_workaround)
msleep(2000);
return ret;
}
static int max8998_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct max8998_rtc_info *info = dev_get_drvdata(dev);
u8 data[8];
u8 val;
int ret;
ret = max8998_bulk_read(info->rtc, MAX8998_ALARM0_SEC, 8, data);
if (ret < 0)
return ret;
max8998_data_to_tm(data, &alrm->time);
ret = max8998_read_reg(info->rtc, MAX8998_ALARM0_CONF, &val);
if (ret < 0)
return ret;
alrm->enabled = !!val;
ret = max8998_read_reg(info->rtc, MAX8998_RTC_STATUS, &val);
if (ret < 0)
return ret;
if (val & ALARM0_STATUS)
alrm->pending = 1;
else
alrm->pending = 0;
return 0;
}
static int max8998_rtc_stop_alarm(struct max8998_rtc_info *info)
{
int ret = max8998_write_reg(info->rtc, MAX8998_ALARM0_CONF, 0);
if (info->lp3974_bug_workaround)
msleep(2000);
return ret;
}
static int max8998_rtc_start_alarm(struct max8998_rtc_info *info)
{
int ret;
u8 alarm0_conf = 0x77;
if (info->lp3974_bug_workaround)
alarm0_conf = 0x57;
ret = max8998_write_reg(info->rtc, MAX8998_ALARM0_CONF, alarm0_conf);
if (info->lp3974_bug_workaround)
msleep(2000);
return ret;
}
static int max8998_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct max8998_rtc_info *info = dev_get_drvdata(dev);
u8 data[8];
int ret;
max8998_tm_to_data(&alrm->time, data);
ret = max8998_rtc_stop_alarm(info);
if (ret < 0)
return ret;
ret = max8998_bulk_write(info->rtc, MAX8998_ALARM0_SEC, 8, data);
if (ret < 0)
return ret;
if (info->lp3974_bug_workaround)
msleep(2000);
if (alrm->enabled)
ret = max8998_rtc_start_alarm(info);
return ret;
}
static int max8998_rtc_alarm_irq_enable(struct device *dev,
unsigned int enabled)
{
struct max8998_rtc_info *info = dev_get_drvdata(dev);
if (enabled)
return max8998_rtc_start_alarm(info);
else
return max8998_rtc_stop_alarm(info);
}
static irqreturn_t max8998_rtc_alarm_irq(int irq, void *data)
{
struct max8998_rtc_info *info = data;
rtc_update_irq(info->rtc_dev, 1, RTC_IRQF | RTC_AF);
return IRQ_HANDLED;
}
static int max8998_rtc_probe(struct platform_device *pdev)
{
struct max8998_dev *max8998 = dev_get_drvdata(pdev->dev.parent);
struct max8998_platform_data *pdata = dev_get_platdata(max8998->dev);
struct max8998_rtc_info *info;
int ret;
info = devm_kzalloc(&pdev->dev, sizeof(struct max8998_rtc_info),
GFP_KERNEL);
if (!info)
return -ENOMEM;
info->dev = &pdev->dev;
info->max8998 = max8998;
info->rtc = max8998->rtc;
info->irq = max8998->irq_base + MAX8998_IRQ_ALARM0;
platform_set_drvdata(pdev, info);
info->rtc_dev = devm_rtc_device_register(&pdev->dev, "max8998-rtc",
&max8998_rtc_ops, THIS_MODULE);
if (IS_ERR(info->rtc_dev)) {
ret = PTR_ERR(info->rtc_dev);
dev_err(&pdev->dev, "Failed to register RTC device: %d\n", ret);
goto out_rtc;
}
ret = devm_request_threaded_irq(&pdev->dev, info->irq, NULL,
max8998_rtc_alarm_irq, 0, "rtc-alarm0", info);
if (ret < 0)
dev_err(&pdev->dev, "Failed to request alarm IRQ: %d: %d\n",
info->irq, ret);
dev_info(&pdev->dev, "RTC CHIP NAME: %s\n", pdev->id_entry->name);
if (pdata && pdata->rtc_delay) {
info->lp3974_bug_workaround = true;
dev_warn(&pdev->dev, "LP3974 with RTC REGERR option."
" RTC updates will be extremely slow.\n");
}
return 0;
out_rtc:
platform_set_drvdata(pdev, NULL);
return ret;
}
static int max8998_rtc_remove(struct platform_device *pdev)
{
return 0;
}
