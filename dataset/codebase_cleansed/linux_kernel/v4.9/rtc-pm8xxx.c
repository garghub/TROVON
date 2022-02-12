static int pm8xxx_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
int rc, i;
unsigned long secs, irq_flags;
u8 value[NUM_8_BIT_RTC_REGS], alarm_enabled = 0;
unsigned int ctrl_reg;
struct pm8xxx_rtc *rtc_dd = dev_get_drvdata(dev);
const struct pm8xxx_rtc_regs *regs = rtc_dd->regs;
if (!rtc_dd->allow_set_time)
return -EACCES;
rtc_tm_to_time(tm, &secs);
for (i = 0; i < NUM_8_BIT_RTC_REGS; i++) {
value[i] = secs & 0xFF;
secs >>= 8;
}
dev_dbg(dev, "Seconds value to be written to RTC = %lu\n", secs);
spin_lock_irqsave(&rtc_dd->ctrl_reg_lock, irq_flags);
rc = regmap_read(rtc_dd->regmap, regs->ctrl, &ctrl_reg);
if (rc)
goto rtc_rw_fail;
if (ctrl_reg & regs->alarm_en) {
alarm_enabled = 1;
ctrl_reg &= ~regs->alarm_en;
rc = regmap_write(rtc_dd->regmap, regs->ctrl, ctrl_reg);
if (rc) {
dev_err(dev, "Write to RTC control register failed\n");
goto rtc_rw_fail;
}
}
rc = regmap_write(rtc_dd->regmap, regs->write, 0);
if (rc) {
dev_err(dev, "Write to RTC write data register failed\n");
goto rtc_rw_fail;
}
rc = regmap_bulk_write(rtc_dd->regmap, regs->write + 1,
&value[1], sizeof(value) - 1);
if (rc) {
dev_err(dev, "Write to RTC write data register failed\n");
goto rtc_rw_fail;
}
rc = regmap_write(rtc_dd->regmap, regs->write, value[0]);
if (rc) {
dev_err(dev, "Write to RTC write data register failed\n");
goto rtc_rw_fail;
}
if (alarm_enabled) {
ctrl_reg |= regs->alarm_en;
rc = regmap_write(rtc_dd->regmap, regs->ctrl, ctrl_reg);
if (rc) {
dev_err(dev, "Write to RTC control register failed\n");
goto rtc_rw_fail;
}
}
rtc_rw_fail:
spin_unlock_irqrestore(&rtc_dd->ctrl_reg_lock, irq_flags);
return rc;
}
static int pm8xxx_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
int rc;
u8 value[NUM_8_BIT_RTC_REGS];
unsigned long secs;
unsigned int reg;
struct pm8xxx_rtc *rtc_dd = dev_get_drvdata(dev);
const struct pm8xxx_rtc_regs *regs = rtc_dd->regs;
rc = regmap_bulk_read(rtc_dd->regmap, regs->read, value, sizeof(value));
if (rc) {
dev_err(dev, "RTC read data register failed\n");
return rc;
}
rc = regmap_read(rtc_dd->regmap, regs->read, &reg);
if (rc < 0) {
dev_err(dev, "RTC read data register failed\n");
return rc;
}
if (unlikely(reg < value[0])) {
rc = regmap_bulk_read(rtc_dd->regmap, regs->read,
value, sizeof(value));
if (rc) {
dev_err(dev, "RTC read data register failed\n");
return rc;
}
}
secs = value[0] | (value[1] << 8) | (value[2] << 16) | (value[3] << 24);
rtc_time_to_tm(secs, tm);
rc = rtc_valid_tm(tm);
if (rc < 0) {
dev_err(dev, "Invalid time read from RTC\n");
return rc;
}
dev_dbg(dev, "secs = %lu, h:m:s == %d:%d:%d, d/m/y = %d/%d/%d\n",
secs, tm->tm_hour, tm->tm_min, tm->tm_sec,
tm->tm_mday, tm->tm_mon, tm->tm_year);
return 0;
}
static int pm8xxx_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
int rc, i;
u8 value[NUM_8_BIT_RTC_REGS];
unsigned int ctrl_reg;
unsigned long secs, irq_flags;
struct pm8xxx_rtc *rtc_dd = dev_get_drvdata(dev);
const struct pm8xxx_rtc_regs *regs = rtc_dd->regs;
rtc_tm_to_time(&alarm->time, &secs);
for (i = 0; i < NUM_8_BIT_RTC_REGS; i++) {
value[i] = secs & 0xFF;
secs >>= 8;
}
spin_lock_irqsave(&rtc_dd->ctrl_reg_lock, irq_flags);
rc = regmap_bulk_write(rtc_dd->regmap, regs->alarm_rw, value,
sizeof(value));
if (rc) {
dev_err(dev, "Write to RTC ALARM register failed\n");
goto rtc_rw_fail;
}
rc = regmap_read(rtc_dd->regmap, regs->alarm_ctrl, &ctrl_reg);
if (rc)
goto rtc_rw_fail;
if (alarm->enabled)
ctrl_reg |= regs->alarm_en;
else
ctrl_reg &= ~regs->alarm_en;
rc = regmap_write(rtc_dd->regmap, regs->alarm_ctrl, ctrl_reg);
if (rc) {
dev_err(dev, "Write to RTC alarm control register failed\n");
goto rtc_rw_fail;
}
dev_dbg(dev, "Alarm Set for h:r:s=%d:%d:%d, d/m/y=%d/%d/%d\n",
alarm->time.tm_hour, alarm->time.tm_min,
alarm->time.tm_sec, alarm->time.tm_mday,
alarm->time.tm_mon, alarm->time.tm_year);
rtc_rw_fail:
spin_unlock_irqrestore(&rtc_dd->ctrl_reg_lock, irq_flags);
return rc;
}
static int pm8xxx_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
int rc;
u8 value[NUM_8_BIT_RTC_REGS];
unsigned long secs;
struct pm8xxx_rtc *rtc_dd = dev_get_drvdata(dev);
const struct pm8xxx_rtc_regs *regs = rtc_dd->regs;
rc = regmap_bulk_read(rtc_dd->regmap, regs->alarm_rw, value,
sizeof(value));
if (rc) {
dev_err(dev, "RTC alarm time read failed\n");
return rc;
}
secs = value[0] | (value[1] << 8) | (value[2] << 16) | (value[3] << 24);
rtc_time_to_tm(secs, &alarm->time);
rc = rtc_valid_tm(&alarm->time);
if (rc < 0) {
dev_err(dev, "Invalid alarm time read from RTC\n");
return rc;
}
dev_dbg(dev, "Alarm set for - h:r:s=%d:%d:%d, d/m/y=%d/%d/%d\n",
alarm->time.tm_hour, alarm->time.tm_min,
alarm->time.tm_sec, alarm->time.tm_mday,
alarm->time.tm_mon, alarm->time.tm_year);
return 0;
}
static int pm8xxx_rtc_alarm_irq_enable(struct device *dev, unsigned int enable)
{
int rc;
unsigned long irq_flags;
struct pm8xxx_rtc *rtc_dd = dev_get_drvdata(dev);
const struct pm8xxx_rtc_regs *regs = rtc_dd->regs;
unsigned int ctrl_reg;
spin_lock_irqsave(&rtc_dd->ctrl_reg_lock, irq_flags);
rc = regmap_read(rtc_dd->regmap, regs->alarm_ctrl, &ctrl_reg);
if (rc)
goto rtc_rw_fail;
if (enable)
ctrl_reg |= regs->alarm_en;
else
ctrl_reg &= ~regs->alarm_en;
rc = regmap_write(rtc_dd->regmap, regs->alarm_ctrl, ctrl_reg);
if (rc) {
dev_err(dev, "Write to RTC control register failed\n");
goto rtc_rw_fail;
}
rtc_rw_fail:
spin_unlock_irqrestore(&rtc_dd->ctrl_reg_lock, irq_flags);
return rc;
}
static irqreturn_t pm8xxx_alarm_trigger(int irq, void *dev_id)
{
struct pm8xxx_rtc *rtc_dd = dev_id;
const struct pm8xxx_rtc_regs *regs = rtc_dd->regs;
unsigned int ctrl_reg;
int rc;
unsigned long irq_flags;
rtc_update_irq(rtc_dd->rtc, 1, RTC_IRQF | RTC_AF);
spin_lock_irqsave(&rtc_dd->ctrl_reg_lock, irq_flags);
rc = regmap_read(rtc_dd->regmap, regs->alarm_ctrl, &ctrl_reg);
if (rc) {
spin_unlock_irqrestore(&rtc_dd->ctrl_reg_lock, irq_flags);
goto rtc_alarm_handled;
}
ctrl_reg &= ~regs->alarm_en;
rc = regmap_write(rtc_dd->regmap, regs->alarm_ctrl, ctrl_reg);
if (rc) {
spin_unlock_irqrestore(&rtc_dd->ctrl_reg_lock, irq_flags);
dev_err(rtc_dd->rtc_dev,
"Write to alarm control register failed\n");
goto rtc_alarm_handled;
}
spin_unlock_irqrestore(&rtc_dd->ctrl_reg_lock, irq_flags);
rc = regmap_read(rtc_dd->regmap, regs->alarm_ctrl2, &ctrl_reg);
if (rc) {
dev_err(rtc_dd->rtc_dev,
"RTC Alarm control2 register read failed\n");
goto rtc_alarm_handled;
}
ctrl_reg |= PM8xxx_RTC_ALARM_CLEAR;
rc = regmap_write(rtc_dd->regmap, regs->alarm_ctrl2, ctrl_reg);
if (rc)
dev_err(rtc_dd->rtc_dev,
"Write to RTC Alarm control2 register failed\n");
rtc_alarm_handled:
return IRQ_HANDLED;
}
static int pm8xxx_rtc_enable(struct pm8xxx_rtc *rtc_dd)
{
const struct pm8xxx_rtc_regs *regs = rtc_dd->regs;
unsigned int ctrl_reg;
int rc;
rc = regmap_read(rtc_dd->regmap, regs->ctrl, &ctrl_reg);
if (rc)
return rc;
if (!(ctrl_reg & PM8xxx_RTC_ENABLE)) {
ctrl_reg |= PM8xxx_RTC_ENABLE;
rc = regmap_write(rtc_dd->regmap, regs->ctrl, ctrl_reg);
if (rc)
return rc;
}
return 0;
}
static int pm8xxx_rtc_probe(struct platform_device *pdev)
{
int rc;
struct pm8xxx_rtc *rtc_dd;
const struct of_device_id *match;
match = of_match_node(pm8xxx_id_table, pdev->dev.of_node);
if (!match)
return -ENXIO;
rtc_dd = devm_kzalloc(&pdev->dev, sizeof(*rtc_dd), GFP_KERNEL);
if (rtc_dd == NULL)
return -ENOMEM;
spin_lock_init(&rtc_dd->ctrl_reg_lock);
rtc_dd->regmap = dev_get_regmap(pdev->dev.parent, NULL);
if (!rtc_dd->regmap) {
dev_err(&pdev->dev, "Parent regmap unavailable.\n");
return -ENXIO;
}
rtc_dd->rtc_alarm_irq = platform_get_irq(pdev, 0);
if (rtc_dd->rtc_alarm_irq < 0) {
dev_err(&pdev->dev, "Alarm IRQ resource absent!\n");
return -ENXIO;
}
rtc_dd->allow_set_time = of_property_read_bool(pdev->dev.of_node,
"allow-set-time");
rtc_dd->regs = match->data;
rtc_dd->rtc_dev = &pdev->dev;
rc = pm8xxx_rtc_enable(rtc_dd);
if (rc)
return rc;
platform_set_drvdata(pdev, rtc_dd);
device_init_wakeup(&pdev->dev, 1);
rtc_dd->rtc = devm_rtc_device_register(&pdev->dev, "pm8xxx_rtc",
&pm8xxx_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc_dd->rtc)) {
dev_err(&pdev->dev, "%s: RTC registration failed (%ld)\n",
__func__, PTR_ERR(rtc_dd->rtc));
return PTR_ERR(rtc_dd->rtc);
}
rc = devm_request_any_context_irq(&pdev->dev, rtc_dd->rtc_alarm_irq,
pm8xxx_alarm_trigger,
IRQF_TRIGGER_RISING,
"pm8xxx_rtc_alarm", rtc_dd);
if (rc < 0) {
dev_err(&pdev->dev, "Request IRQ failed (%d)\n", rc);
return rc;
}
dev_dbg(&pdev->dev, "Probe success !!\n");
return 0;
}
static int pm8xxx_rtc_resume(struct device *dev)
{
struct pm8xxx_rtc *rtc_dd = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
disable_irq_wake(rtc_dd->rtc_alarm_irq);
return 0;
}
static int pm8xxx_rtc_suspend(struct device *dev)
{
struct pm8xxx_rtc *rtc_dd = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
enable_irq_wake(rtc_dd->rtc_alarm_irq);
return 0;
}
