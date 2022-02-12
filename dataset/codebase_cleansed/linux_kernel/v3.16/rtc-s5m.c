static void s5m8767_data_to_tm(u8 *data, struct rtc_time *tm,
int rtc_24hr_mode)
{
tm->tm_sec = data[RTC_SEC] & 0x7f;
tm->tm_min = data[RTC_MIN] & 0x7f;
if (rtc_24hr_mode) {
tm->tm_hour = data[RTC_HOUR] & 0x1f;
} else {
tm->tm_hour = data[RTC_HOUR] & 0x0f;
if (data[RTC_HOUR] & HOUR_PM_MASK)
tm->tm_hour += 12;
}
tm->tm_wday = ffs(data[RTC_WEEKDAY] & 0x7f);
tm->tm_mday = data[RTC_DATE] & 0x1f;
tm->tm_mon = (data[RTC_MONTH] & 0x0f) - 1;
tm->tm_year = (data[RTC_YEAR1] & 0x7f) + 100;
tm->tm_yday = 0;
tm->tm_isdst = 0;
}
static int s5m8767_tm_to_data(struct rtc_time *tm, u8 *data)
{
data[RTC_SEC] = tm->tm_sec;
data[RTC_MIN] = tm->tm_min;
if (tm->tm_hour >= 12)
data[RTC_HOUR] = tm->tm_hour | HOUR_PM_MASK;
else
data[RTC_HOUR] = tm->tm_hour & ~HOUR_PM_MASK;
data[RTC_WEEKDAY] = 1 << tm->tm_wday;
data[RTC_DATE] = tm->tm_mday;
data[RTC_MONTH] = tm->tm_mon + 1;
data[RTC_YEAR1] = tm->tm_year > 100 ? (tm->tm_year - 100) : 0;
if (tm->tm_year < 100) {
pr_err("s5m8767 RTC cannot handle the year %d.\n",
1900 + tm->tm_year);
return -EINVAL;
} else {
return 0;
}
}
static inline int s5m8767_wait_for_udr_update(struct s5m_rtc_info *info)
{
int ret, retry = UDR_READ_RETRY_CNT;
unsigned int data;
do {
ret = regmap_read(info->regmap, info->regs->rtc_udr_update,
&data);
} while (--retry && (data & info->regs->rtc_udr_mask) && !ret);
if (!retry)
dev_err(info->dev, "waiting for UDR update, reached max number of retries\n");
return ret;
}
static inline int s5m_check_peding_alarm_interrupt(struct s5m_rtc_info *info,
struct rtc_wkalrm *alarm)
{
int ret;
unsigned int val;
switch (info->device_type) {
case S5M8767X:
case S5M8763X:
ret = regmap_read(info->regmap, S5M_RTC_STATUS, &val);
val &= S5M_ALARM0_STATUS;
break;
case S2MPS14X:
ret = regmap_read(info->s5m87xx->regmap_pmic, S2MPS14_REG_ST2,
&val);
val &= S2MPS_ALARM0_STATUS;
break;
default:
return -EINVAL;
}
if (ret < 0)
return ret;
if (val)
alarm->pending = 1;
else
alarm->pending = 0;
return 0;
}
static inline int s5m8767_rtc_set_time_reg(struct s5m_rtc_info *info)
{
int ret;
unsigned int data;
ret = regmap_read(info->regmap, info->regs->rtc_udr_update, &data);
if (ret < 0) {
dev_err(info->dev, "failed to read update reg(%d)\n", ret);
return ret;
}
data |= info->regs->rtc_udr_mask;
if (info->device_type == S5M8763X || info->device_type == S5M8767X)
data |= S5M_RTC_TIME_EN_MASK;
ret = regmap_write(info->regmap, info->regs->rtc_udr_update, data);
if (ret < 0) {
dev_err(info->dev, "failed to write update reg(%d)\n", ret);
return ret;
}
ret = s5m8767_wait_for_udr_update(info);
return ret;
}
static inline int s5m8767_rtc_set_alarm_reg(struct s5m_rtc_info *info)
{
int ret;
unsigned int data;
ret = regmap_read(info->regmap, info->regs->rtc_udr_update, &data);
if (ret < 0) {
dev_err(info->dev, "%s: fail to read update reg(%d)\n",
__func__, ret);
return ret;
}
data |= info->regs->rtc_udr_mask;
switch (info->device_type) {
case S5M8763X:
case S5M8767X:
data &= ~S5M_RTC_TIME_EN_MASK;
break;
case S2MPS14X:
data |= S2MPS_RTC_RUDR_MASK;
break;
default:
return -EINVAL;
}
ret = regmap_write(info->regmap, info->regs->rtc_udr_update, data);
if (ret < 0) {
dev_err(info->dev, "%s: fail to write update reg(%d)\n",
__func__, ret);
return ret;
}
ret = s5m8767_wait_for_udr_update(info);
return ret;
}
static void s5m8763_data_to_tm(u8 *data, struct rtc_time *tm)
{
tm->tm_sec = bcd2bin(data[RTC_SEC]);
tm->tm_min = bcd2bin(data[RTC_MIN]);
if (data[RTC_HOUR] & HOUR_12) {
tm->tm_hour = bcd2bin(data[RTC_HOUR] & 0x1f);
if (data[RTC_HOUR] & HOUR_PM)
tm->tm_hour += 12;
} else {
tm->tm_hour = bcd2bin(data[RTC_HOUR] & 0x3f);
}
tm->tm_wday = data[RTC_WEEKDAY] & 0x07;
tm->tm_mday = bcd2bin(data[RTC_DATE]);
tm->tm_mon = bcd2bin(data[RTC_MONTH]);
tm->tm_year = bcd2bin(data[RTC_YEAR1]) + bcd2bin(data[RTC_YEAR2]) * 100;
tm->tm_year -= 1900;
}
static void s5m8763_tm_to_data(struct rtc_time *tm, u8 *data)
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
static int s5m_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct s5m_rtc_info *info = dev_get_drvdata(dev);
u8 data[info->regs->regs_count];
int ret;
if (info->device_type == S2MPS14X) {
ret = regmap_update_bits(info->regmap,
info->regs->rtc_udr_update,
S2MPS_RTC_RUDR_MASK, S2MPS_RTC_RUDR_MASK);
if (ret) {
dev_err(dev,
"Failed to prepare registers for time reading: %d\n",
ret);
return ret;
}
}
ret = regmap_bulk_read(info->regmap, info->regs->time, data,
info->regs->regs_count);
if (ret < 0)
return ret;
switch (info->device_type) {
case S5M8763X:
s5m8763_data_to_tm(data, tm);
break;
case S5M8767X:
case S2MPS14X:
s5m8767_data_to_tm(data, tm, info->rtc_24hr_mode);
break;
default:
return -EINVAL;
}
dev_dbg(dev, "%s: %d/%d/%d %d:%d:%d(%d)\n", __func__,
1900 + tm->tm_year, 1 + tm->tm_mon, tm->tm_mday,
tm->tm_hour, tm->tm_min, tm->tm_sec, tm->tm_wday);
return rtc_valid_tm(tm);
}
static int s5m_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct s5m_rtc_info *info = dev_get_drvdata(dev);
u8 data[info->regs->regs_count];
int ret = 0;
switch (info->device_type) {
case S5M8763X:
s5m8763_tm_to_data(tm, data);
break;
case S5M8767X:
case S2MPS14X:
ret = s5m8767_tm_to_data(tm, data);
break;
default:
return -EINVAL;
}
if (ret < 0)
return ret;
dev_dbg(dev, "%s: %d/%d/%d %d:%d:%d(%d)\n", __func__,
1900 + tm->tm_year, 1 + tm->tm_mon, tm->tm_mday,
tm->tm_hour, tm->tm_min, tm->tm_sec, tm->tm_wday);
ret = regmap_raw_write(info->regmap, info->regs->time, data,
info->regs->regs_count);
if (ret < 0)
return ret;
ret = s5m8767_rtc_set_time_reg(info);
return ret;
}
static int s5m_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct s5m_rtc_info *info = dev_get_drvdata(dev);
u8 data[info->regs->regs_count];
unsigned int val;
int ret, i;
ret = regmap_bulk_read(info->regmap, info->regs->alarm0, data,
info->regs->regs_count);
if (ret < 0)
return ret;
switch (info->device_type) {
case S5M8763X:
s5m8763_data_to_tm(data, &alrm->time);
ret = regmap_read(info->regmap, S5M_ALARM0_CONF, &val);
if (ret < 0)
return ret;
alrm->enabled = !!val;
break;
case S5M8767X:
case S2MPS14X:
s5m8767_data_to_tm(data, &alrm->time, info->rtc_24hr_mode);
alrm->enabled = 0;
for (i = 0; i < info->regs->regs_count; i++) {
if (data[i] & ALARM_ENABLE_MASK) {
alrm->enabled = 1;
break;
}
}
break;
default:
return -EINVAL;
}
dev_dbg(dev, "%s: %d/%d/%d %d:%d:%d(%d)\n", __func__,
1900 + alrm->time.tm_year, 1 + alrm->time.tm_mon,
alrm->time.tm_mday, alrm->time.tm_hour,
alrm->time.tm_min, alrm->time.tm_sec,
alrm->time.tm_wday);
ret = s5m_check_peding_alarm_interrupt(info, alrm);
return 0;
}
static int s5m_rtc_stop_alarm(struct s5m_rtc_info *info)
{
u8 data[info->regs->regs_count];
int ret, i;
struct rtc_time tm;
ret = regmap_bulk_read(info->regmap, info->regs->alarm0, data,
info->regs->regs_count);
if (ret < 0)
return ret;
s5m8767_data_to_tm(data, &tm, info->rtc_24hr_mode);
dev_dbg(info->dev, "%s: %d/%d/%d %d:%d:%d(%d)\n", __func__,
1900 + tm.tm_year, 1 + tm.tm_mon, tm.tm_mday,
tm.tm_hour, tm.tm_min, tm.tm_sec, tm.tm_wday);
switch (info->device_type) {
case S5M8763X:
ret = regmap_write(info->regmap, S5M_ALARM0_CONF, 0);
break;
case S5M8767X:
case S2MPS14X:
for (i = 0; i < info->regs->regs_count; i++)
data[i] &= ~ALARM_ENABLE_MASK;
ret = regmap_raw_write(info->regmap, info->regs->alarm0, data,
info->regs->regs_count);
if (ret < 0)
return ret;
ret = s5m8767_rtc_set_alarm_reg(info);
break;
default:
return -EINVAL;
}
return ret;
}
static int s5m_rtc_start_alarm(struct s5m_rtc_info *info)
{
int ret;
u8 data[info->regs->regs_count];
u8 alarm0_conf;
struct rtc_time tm;
ret = regmap_bulk_read(info->regmap, info->regs->alarm0, data,
info->regs->regs_count);
if (ret < 0)
return ret;
s5m8767_data_to_tm(data, &tm, info->rtc_24hr_mode);
dev_dbg(info->dev, "%s: %d/%d/%d %d:%d:%d(%d)\n", __func__,
1900 + tm.tm_year, 1 + tm.tm_mon, tm.tm_mday,
tm.tm_hour, tm.tm_min, tm.tm_sec, tm.tm_wday);
switch (info->device_type) {
case S5M8763X:
alarm0_conf = 0x77;
ret = regmap_write(info->regmap, S5M_ALARM0_CONF, alarm0_conf);
break;
case S5M8767X:
case S2MPS14X:
data[RTC_SEC] |= ALARM_ENABLE_MASK;
data[RTC_MIN] |= ALARM_ENABLE_MASK;
data[RTC_HOUR] |= ALARM_ENABLE_MASK;
data[RTC_WEEKDAY] &= ~ALARM_ENABLE_MASK;
if (data[RTC_DATE] & 0x1f)
data[RTC_DATE] |= ALARM_ENABLE_MASK;
if (data[RTC_MONTH] & 0xf)
data[RTC_MONTH] |= ALARM_ENABLE_MASK;
if (data[RTC_YEAR1] & 0x7f)
data[RTC_YEAR1] |= ALARM_ENABLE_MASK;
ret = regmap_raw_write(info->regmap, info->regs->alarm0, data,
info->regs->regs_count);
if (ret < 0)
return ret;
ret = s5m8767_rtc_set_alarm_reg(info);
break;
default:
return -EINVAL;
}
return ret;
}
static int s5m_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct s5m_rtc_info *info = dev_get_drvdata(dev);
u8 data[info->regs->regs_count];
int ret;
switch (info->device_type) {
case S5M8763X:
s5m8763_tm_to_data(&alrm->time, data);
break;
case S5M8767X:
case S2MPS14X:
s5m8767_tm_to_data(&alrm->time, data);
break;
default:
return -EINVAL;
}
dev_dbg(dev, "%s: %d/%d/%d %d:%d:%d(%d)\n", __func__,
1900 + alrm->time.tm_year, 1 + alrm->time.tm_mon,
alrm->time.tm_mday, alrm->time.tm_hour, alrm->time.tm_min,
alrm->time.tm_sec, alrm->time.tm_wday);
ret = s5m_rtc_stop_alarm(info);
if (ret < 0)
return ret;
ret = regmap_raw_write(info->regmap, info->regs->alarm0, data,
info->regs->regs_count);
if (ret < 0)
return ret;
ret = s5m8767_rtc_set_alarm_reg(info);
if (ret < 0)
return ret;
if (alrm->enabled)
ret = s5m_rtc_start_alarm(info);
return ret;
}
static int s5m_rtc_alarm_irq_enable(struct device *dev,
unsigned int enabled)
{
struct s5m_rtc_info *info = dev_get_drvdata(dev);
if (enabled)
return s5m_rtc_start_alarm(info);
else
return s5m_rtc_stop_alarm(info);
}
static irqreturn_t s5m_rtc_alarm_irq(int irq, void *data)
{
struct s5m_rtc_info *info = data;
rtc_update_irq(info->rtc_dev, 1, RTC_IRQF | RTC_AF);
return IRQ_HANDLED;
}
static void s5m_rtc_enable_wtsr(struct s5m_rtc_info *info, bool enable)
{
int ret;
ret = regmap_update_bits(info->regmap, info->regs->smpl_wtsr,
WTSR_ENABLE_MASK,
enable ? WTSR_ENABLE_MASK : 0);
if (ret < 0)
dev_err(info->dev, "%s: fail to update WTSR reg(%d)\n",
__func__, ret);
}
static void s5m_rtc_enable_smpl(struct s5m_rtc_info *info, bool enable)
{
int ret;
ret = regmap_update_bits(info->regmap, info->regs->smpl_wtsr,
SMPL_ENABLE_MASK,
enable ? SMPL_ENABLE_MASK : 0);
if (ret < 0)
dev_err(info->dev, "%s: fail to update SMPL reg(%d)\n",
__func__, ret);
}
static int s5m8767_rtc_init_reg(struct s5m_rtc_info *info)
{
u8 data[2];
int ret;
switch (info->device_type) {
case S5M8763X:
case S5M8767X:
ret = regmap_update_bits(info->regmap, S5M_RTC_UDR_CON,
S5M_RTC_UDR_T_MASK, S5M_RTC_UDR_T_450_US);
if (ret < 0)
dev_err(info->dev, "%s: fail to change UDR time: %d\n",
__func__, ret);
data[0] = (1 << BCD_EN_SHIFT) | (1 << MODEL24_SHIFT);
data[1] = (0 << BCD_EN_SHIFT) | (1 << MODEL24_SHIFT);
ret = regmap_raw_write(info->regmap, S5M_ALARM0_CONF, data, 2);
break;
case S2MPS14X:
data[0] = (0 << BCD_EN_SHIFT) | (1 << MODEL24_SHIFT);
ret = regmap_write(info->regmap, info->regs->ctrl, data[0]);
break;
default:
return -EINVAL;
}
info->rtc_24hr_mode = 1;
if (ret < 0) {
dev_err(info->dev, "%s: fail to write controlm reg(%d)\n",
__func__, ret);
return ret;
}
return ret;
}
static int s5m_rtc_probe(struct platform_device *pdev)
{
struct sec_pmic_dev *s5m87xx = dev_get_drvdata(pdev->dev.parent);
struct sec_platform_data *pdata = s5m87xx->pdata;
struct s5m_rtc_info *info;
const struct regmap_config *regmap_cfg;
int ret, alarm_irq;
if (!pdata) {
dev_err(pdev->dev.parent, "Platform data not supplied\n");
return -ENODEV;
}
info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
switch (pdata->device_type) {
case S2MPS14X:
regmap_cfg = &s2mps14_rtc_regmap_config;
info->regs = &s2mps_rtc_regs;
alarm_irq = S2MPS14_IRQ_RTCA0;
break;
case S5M8763X:
regmap_cfg = &s5m_rtc_regmap_config;
info->regs = &s5m_rtc_regs;
alarm_irq = S5M8763_IRQ_ALARM0;
break;
case S5M8767X:
regmap_cfg = &s5m_rtc_regmap_config;
info->regs = &s5m_rtc_regs;
alarm_irq = S5M8767_IRQ_RTCA1;
break;
default:
dev_err(&pdev->dev, "Device type is not supported by RTC driver\n");
return -ENODEV;
}
info->i2c = i2c_new_dummy(s5m87xx->i2c->adapter, RTC_I2C_ADDR);
if (!info->i2c) {
dev_err(&pdev->dev, "Failed to allocate I2C for RTC\n");
return -ENODEV;
}
info->regmap = devm_regmap_init_i2c(info->i2c, regmap_cfg);
if (IS_ERR(info->regmap)) {
ret = PTR_ERR(info->regmap);
dev_err(&pdev->dev, "Failed to allocate RTC register map: %d\n",
ret);
goto err;
}
info->dev = &pdev->dev;
info->s5m87xx = s5m87xx;
info->device_type = s5m87xx->device_type;
info->wtsr_smpl = s5m87xx->wtsr_smpl;
info->irq = regmap_irq_get_virq(s5m87xx->irq_data, alarm_irq);
if (info->irq <= 0) {
ret = -EINVAL;
dev_err(&pdev->dev, "Failed to get virtual IRQ %d\n",
alarm_irq);
goto err;
}
platform_set_drvdata(pdev, info);
ret = s5m8767_rtc_init_reg(info);
if (info->wtsr_smpl) {
s5m_rtc_enable_wtsr(info, true);
s5m_rtc_enable_smpl(info, true);
}
device_init_wakeup(&pdev->dev, 1);
info->rtc_dev = devm_rtc_device_register(&pdev->dev, "s5m-rtc",
&s5m_rtc_ops, THIS_MODULE);
if (IS_ERR(info->rtc_dev)) {
ret = PTR_ERR(info->rtc_dev);
goto err;
}
ret = devm_request_threaded_irq(&pdev->dev, info->irq, NULL,
s5m_rtc_alarm_irq, 0, "rtc-alarm0",
info);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to request alarm IRQ: %d: %d\n",
info->irq, ret);
goto err;
}
return 0;
err:
i2c_unregister_device(info->i2c);
return ret;
}
static void s5m_rtc_shutdown(struct platform_device *pdev)
{
struct s5m_rtc_info *info = platform_get_drvdata(pdev);
int i;
unsigned int val = 0;
if (info->wtsr_smpl) {
for (i = 0; i < 3; i++) {
s5m_rtc_enable_wtsr(info, false);
regmap_read(info->regmap, info->regs->smpl_wtsr, &val);
pr_debug("%s: WTSR_SMPL reg(0x%02x)\n", __func__, val);
if (val & WTSR_ENABLE_MASK)
pr_emerg("%s: fail to disable WTSR\n",
__func__);
else {
pr_info("%s: success to disable WTSR\n",
__func__);
break;
}
}
}
s5m_rtc_enable_smpl(info, false);
}
static int s5m_rtc_remove(struct platform_device *pdev)
{
struct s5m_rtc_info *info = platform_get_drvdata(pdev);
s5m_rtc_shutdown(pdev);
i2c_unregister_device(info->i2c);
return 0;
}
static int s5m_rtc_resume(struct device *dev)
{
struct s5m_rtc_info *info = dev_get_drvdata(dev);
int ret = 0;
if (device_may_wakeup(dev))
ret = disable_irq_wake(info->irq);
return ret;
}
static int s5m_rtc_suspend(struct device *dev)
{
struct s5m_rtc_info *info = dev_get_drvdata(dev);
int ret = 0;
if (device_may_wakeup(dev))
ret = enable_irq_wake(info->irq);
return ret;
}
