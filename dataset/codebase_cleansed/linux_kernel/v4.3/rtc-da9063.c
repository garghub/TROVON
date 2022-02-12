static void da9063_data_to_tm(u8 *data, struct rtc_time *tm,
struct da9063_compatible_rtc *rtc)
{
const struct da9063_compatible_rtc_regmap *config = rtc->config;
tm->tm_sec = data[RTC_SEC] & config->rtc_count_sec_mask;
tm->tm_min = data[RTC_MIN] & config->rtc_count_min_mask;
tm->tm_hour = data[RTC_HOUR] & config->rtc_count_hour_mask;
tm->tm_mday = data[RTC_DAY] & config->rtc_count_day_mask;
tm->tm_mon = MONTHS_FROM_DA9063(data[RTC_MONTH] &
config->rtc_count_month_mask);
tm->tm_year = YEARS_FROM_DA9063(data[RTC_YEAR] &
config->rtc_count_year_mask);
}
static void da9063_tm_to_data(struct rtc_time *tm, u8 *data,
struct da9063_compatible_rtc *rtc)
{
const struct da9063_compatible_rtc_regmap *config = rtc->config;
data[RTC_SEC] &= ~config->rtc_count_sec_mask;
data[RTC_SEC] |= tm->tm_sec & config->rtc_count_sec_mask;
data[RTC_MIN] &= ~config->rtc_count_min_mask;
data[RTC_MIN] |= tm->tm_min & config->rtc_count_min_mask;
data[RTC_HOUR] &= ~config->rtc_count_hour_mask;
data[RTC_HOUR] |= tm->tm_hour & config->rtc_count_hour_mask;
data[RTC_DAY] &= ~config->rtc_count_day_mask;
data[RTC_DAY] |= tm->tm_mday & config->rtc_count_day_mask;
data[RTC_MONTH] &= ~config->rtc_count_month_mask;
data[RTC_MONTH] |= MONTHS_TO_DA9063(tm->tm_mon) &
config->rtc_count_month_mask;
data[RTC_YEAR] &= ~config->rtc_count_year_mask;
data[RTC_YEAR] |= YEARS_TO_DA9063(tm->tm_year) &
config->rtc_count_year_mask;
}
static int da9063_rtc_stop_alarm(struct device *dev)
{
struct da9063_compatible_rtc *rtc = dev_get_drvdata(dev);
const struct da9063_compatible_rtc_regmap *config = rtc->config;
return regmap_update_bits(rtc->regmap,
config->rtc_alarm_year_reg,
config->rtc_alarm_on_mask,
0);
}
static int da9063_rtc_start_alarm(struct device *dev)
{
struct da9063_compatible_rtc *rtc = dev_get_drvdata(dev);
const struct da9063_compatible_rtc_regmap *config = rtc->config;
return regmap_update_bits(rtc->regmap,
config->rtc_alarm_year_reg,
config->rtc_alarm_on_mask,
config->rtc_alarm_on_mask);
}
static int da9063_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct da9063_compatible_rtc *rtc = dev_get_drvdata(dev);
const struct da9063_compatible_rtc_regmap *config = rtc->config;
unsigned long tm_secs;
unsigned long al_secs;
u8 data[RTC_DATA_LEN];
int ret;
ret = regmap_bulk_read(rtc->regmap,
config->rtc_count_secs_reg,
data, RTC_DATA_LEN);
if (ret < 0) {
dev_err(dev, "Failed to read RTC time data: %d\n", ret);
return ret;
}
if (!(data[RTC_SEC] & config->rtc_ready_to_read_mask)) {
dev_dbg(dev, "RTC not yet ready to be read by the host\n");
return -EINVAL;
}
da9063_data_to_tm(data, tm, rtc);
rtc_tm_to_time(tm, &tm_secs);
rtc_tm_to_time(&rtc->alarm_time, &al_secs);
if (rtc->rtc_sync == true && al_secs - tm_secs == 1)
memcpy(tm, &rtc->alarm_time, sizeof(struct rtc_time));
else
rtc->rtc_sync = false;
return rtc_valid_tm(tm);
}
static int da9063_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct da9063_compatible_rtc *rtc = dev_get_drvdata(dev);
const struct da9063_compatible_rtc_regmap *config = rtc->config;
u8 data[RTC_DATA_LEN];
int ret;
da9063_tm_to_data(tm, data, rtc);
ret = regmap_bulk_write(rtc->regmap,
config->rtc_count_secs_reg,
data, RTC_DATA_LEN);
if (ret < 0)
dev_err(dev, "Failed to set RTC time data: %d\n", ret);
return ret;
}
static int da9063_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct da9063_compatible_rtc *rtc = dev_get_drvdata(dev);
const struct da9063_compatible_rtc_regmap *config = rtc->config;
u8 data[RTC_DATA_LEN];
int ret;
unsigned int val;
data[RTC_SEC] = 0;
ret = regmap_bulk_read(rtc->regmap,
config->rtc_alarm_secs_reg,
&data[config->rtc_data_start],
config->rtc_alarm_len);
if (ret < 0)
return ret;
da9063_data_to_tm(data, &alrm->time, rtc);
alrm->enabled = !!(data[RTC_YEAR] & config->rtc_alarm_on_mask);
ret = regmap_read(rtc->regmap,
config->rtc_event_reg,
&val);
if (ret < 0)
return ret;
if (val & config->rtc_event_alarm_mask)
alrm->pending = 1;
else
alrm->pending = 0;
return 0;
}
static int da9063_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct da9063_compatible_rtc *rtc = dev_get_drvdata(dev);
const struct da9063_compatible_rtc_regmap *config = rtc->config;
u8 data[RTC_DATA_LEN];
int ret;
da9063_tm_to_data(&alrm->time, data, rtc);
ret = da9063_rtc_stop_alarm(dev);
if (ret < 0) {
dev_err(dev, "Failed to stop alarm: %d\n", ret);
return ret;
}
ret = regmap_bulk_write(rtc->regmap,
config->rtc_alarm_secs_reg,
&data[config->rtc_data_start],
config->rtc_alarm_len);
if (ret < 0) {
dev_err(dev, "Failed to write alarm: %d\n", ret);
return ret;
}
da9063_data_to_tm(data, &rtc->alarm_time, rtc);
if (alrm->enabled) {
ret = da9063_rtc_start_alarm(dev);
if (ret < 0) {
dev_err(dev, "Failed to start alarm: %d\n", ret);
return ret;
}
}
return ret;
}
static int da9063_rtc_alarm_irq_enable(struct device *dev,
unsigned int enabled)
{
if (enabled)
return da9063_rtc_start_alarm(dev);
else
return da9063_rtc_stop_alarm(dev);
}
static irqreturn_t da9063_alarm_event(int irq, void *data)
{
struct da9063_compatible_rtc *rtc = data;
const struct da9063_compatible_rtc_regmap *config = rtc->config;
regmap_update_bits(rtc->regmap,
config->rtc_alarm_year_reg,
config->rtc_alarm_on_mask,
0);
rtc->rtc_sync = true;
rtc_update_irq(rtc->rtc_dev, 1, RTC_IRQF | RTC_AF);
return IRQ_HANDLED;
}
static int da9063_rtc_probe(struct platform_device *pdev)
{
struct da9063_compatible_rtc *rtc;
const struct da9063_compatible_rtc_regmap *config;
const struct of_device_id *match;
int irq_alarm;
u8 data[RTC_DATA_LEN];
int ret;
if (!pdev->dev.of_node)
return -ENXIO;
match = of_match_node(da9063_compatible_reg_id_table,
pdev->dev.of_node);
rtc = devm_kzalloc(&pdev->dev, sizeof(*rtc), GFP_KERNEL);
if (!rtc)
return -ENOMEM;
rtc->config = match->data;
if (of_device_is_compatible(pdev->dev.of_node, "dlg,da9063-rtc")) {
struct da9063 *chip = dev_get_drvdata(pdev->dev.parent);
if (chip->variant_code == PMIC_DA9063_AD)
rtc->config = &da9063_ad_regs;
}
rtc->regmap = dev_get_regmap(pdev->dev.parent, NULL);
if (!rtc->regmap) {
dev_warn(&pdev->dev, "Parent regmap unavailable.\n");
return -ENXIO;
}
config = rtc->config;
ret = regmap_update_bits(rtc->regmap,
config->rtc_enable_reg,
config->rtc_enable_mask,
config->rtc_enable_mask);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to enable RTC\n");
return ret;
}
ret = regmap_update_bits(rtc->regmap,
config->rtc_enable_32k_crystal_reg,
config->rtc_crystal_mask,
config->rtc_crystal_mask);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to run 32kHz oscillator\n");
return ret;
}
ret = regmap_update_bits(rtc->regmap,
config->rtc_alarm_secs_reg,
config->rtc_alarm_status_mask,
0);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to access RTC alarm register\n");
return ret;
}
ret = regmap_update_bits(rtc->regmap,
config->rtc_alarm_secs_reg,
DA9063_ALARM_STATUS_ALARM,
DA9063_ALARM_STATUS_ALARM);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to access RTC alarm register\n");
return ret;
}
ret = regmap_update_bits(rtc->regmap,
config->rtc_alarm_year_reg,
config->rtc_tick_on_mask,
0);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to disable TICKs\n");
return ret;
}
data[RTC_SEC] = 0;
ret = regmap_bulk_read(rtc->regmap,
config->rtc_alarm_secs_reg,
&data[config->rtc_data_start],
config->rtc_alarm_len);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to read initial alarm data: %d\n",
ret);
return ret;
}
platform_set_drvdata(pdev, rtc);
irq_alarm = platform_get_irq_byname(pdev, "ALARM");
ret = devm_request_threaded_irq(&pdev->dev, irq_alarm, NULL,
da9063_alarm_event,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"ALARM", rtc);
if (ret) {
dev_err(&pdev->dev, "Failed to request ALARM IRQ %d: %d\n",
irq_alarm, ret);
return ret;
}
rtc->rtc_dev = devm_rtc_device_register(&pdev->dev, DA9063_DRVNAME_RTC,
&da9063_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc->rtc_dev))
return PTR_ERR(rtc->rtc_dev);
da9063_data_to_tm(data, &rtc->alarm_time, rtc);
rtc->rtc_sync = false;
return ret;
}
