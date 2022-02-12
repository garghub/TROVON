static int twl_rtc_read_u8(struct twl_rtc *twl_rtc, u8 *data, u8 reg)
{
int ret;
ret = twl_i2c_read_u8(TWL_MODULE_RTC, data, (twl_rtc->reg_map[reg]));
if (ret < 0)
pr_err("Could not read TWL register %X - error %d\n", reg, ret);
return ret;
}
static int twl_rtc_write_u8(struct twl_rtc *twl_rtc, u8 data, u8 reg)
{
int ret;
ret = twl_i2c_write_u8(TWL_MODULE_RTC, data, (twl_rtc->reg_map[reg]));
if (ret < 0)
pr_err("Could not write TWL register %X - error %d\n",
reg, ret);
return ret;
}
static int set_rtc_irq_bit(struct twl_rtc *twl_rtc, unsigned char bit)
{
unsigned char val;
int ret;
if (twl_rtc->rtc_irq_bits & bit)
return 0;
val = twl_rtc->rtc_irq_bits | bit;
val &= ~BIT_RTC_INTERRUPTS_REG_EVERY_M;
ret = twl_rtc_write_u8(twl_rtc, val, REG_RTC_INTERRUPTS_REG);
if (ret == 0)
twl_rtc->rtc_irq_bits = val;
return ret;
}
static int mask_rtc_irq_bit(struct twl_rtc *twl_rtc, unsigned char bit)
{
unsigned char val;
int ret;
if (!(twl_rtc->rtc_irq_bits & bit))
return 0;
val = twl_rtc->rtc_irq_bits & ~bit;
ret = twl_rtc_write_u8(twl_rtc, val, REG_RTC_INTERRUPTS_REG);
if (ret == 0)
twl_rtc->rtc_irq_bits = val;
return ret;
}
static int twl_rtc_alarm_irq_enable(struct device *dev, unsigned enabled)
{
struct platform_device *pdev = to_platform_device(dev);
struct twl_rtc *twl_rtc = dev_get_drvdata(dev);
int irq = platform_get_irq(pdev, 0);
int ret;
if (enabled) {
ret = set_rtc_irq_bit(twl_rtc,
BIT_RTC_INTERRUPTS_REG_IT_ALARM_M);
if (device_can_wakeup(dev) && !twl_rtc->wake_enabled) {
enable_irq_wake(irq);
twl_rtc->wake_enabled = true;
}
} else {
ret = mask_rtc_irq_bit(twl_rtc,
BIT_RTC_INTERRUPTS_REG_IT_ALARM_M);
if (twl_rtc->wake_enabled) {
disable_irq_wake(irq);
twl_rtc->wake_enabled = false;
}
}
return ret;
}
static int twl_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct twl_rtc *twl_rtc = dev_get_drvdata(dev);
unsigned char rtc_data[ALL_TIME_REGS];
int ret;
u8 save_control;
u8 rtc_control;
ret = twl_rtc_read_u8(twl_rtc, &save_control, REG_RTC_CTRL_REG);
if (ret < 0) {
dev_err(dev, "%s: reading CTRL_REG, error %d\n", __func__, ret);
return ret;
}
if (twl_rtc->class == TWL_6030) {
if (save_control & BIT_RTC_CTRL_REG_GET_TIME_M) {
save_control &= ~BIT_RTC_CTRL_REG_GET_TIME_M;
ret = twl_rtc_write_u8(twl_rtc, save_control,
REG_RTC_CTRL_REG);
if (ret < 0) {
dev_err(dev, "%s clr GET_TIME, error %d\n",
__func__, ret);
return ret;
}
}
}
rtc_control = save_control | BIT_RTC_CTRL_REG_GET_TIME_M;
if (twl_rtc->class == TWL_6030)
rtc_control |= BIT_RTC_CTRL_REG_RTC_V_OPT;
ret = twl_rtc_write_u8(twl_rtc, rtc_control, REG_RTC_CTRL_REG);
if (ret < 0) {
dev_err(dev, "%s: writing CTRL_REG, error %d\n", __func__, ret);
return ret;
}
ret = twl_i2c_read(TWL_MODULE_RTC, rtc_data,
(twl_rtc->reg_map[REG_SECONDS_REG]), ALL_TIME_REGS);
if (ret < 0) {
dev_err(dev, "%s: reading data, error %d\n", __func__, ret);
return ret;
}
if (twl_rtc->class == TWL_6030) {
ret = twl_rtc_write_u8(twl_rtc, save_control, REG_RTC_CTRL_REG);
if (ret < 0) {
dev_err(dev, "%s: restore CTRL_REG, error %d\n",
__func__, ret);
return ret;
}
}
tm->tm_sec = bcd2bin(rtc_data[0]);
tm->tm_min = bcd2bin(rtc_data[1]);
tm->tm_hour = bcd2bin(rtc_data[2]);
tm->tm_mday = bcd2bin(rtc_data[3]);
tm->tm_mon = bcd2bin(rtc_data[4]) - 1;
tm->tm_year = bcd2bin(rtc_data[5]) + 100;
return ret;
}
static int twl_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct twl_rtc *twl_rtc = dev_get_drvdata(dev);
unsigned char save_control;
unsigned char rtc_data[ALL_TIME_REGS];
int ret;
rtc_data[0] = bin2bcd(tm->tm_sec);
rtc_data[1] = bin2bcd(tm->tm_min);
rtc_data[2] = bin2bcd(tm->tm_hour);
rtc_data[3] = bin2bcd(tm->tm_mday);
rtc_data[4] = bin2bcd(tm->tm_mon + 1);
rtc_data[5] = bin2bcd(tm->tm_year - 100);
ret = twl_rtc_read_u8(twl_rtc, &save_control, REG_RTC_CTRL_REG);
if (ret < 0)
goto out;
save_control &= ~BIT_RTC_CTRL_REG_STOP_RTC_M;
ret = twl_rtc_write_u8(twl_rtc, save_control, REG_RTC_CTRL_REG);
if (ret < 0)
goto out;
ret = twl_i2c_write(TWL_MODULE_RTC, rtc_data,
(twl_rtc->reg_map[REG_SECONDS_REG]), ALL_TIME_REGS);
if (ret < 0) {
dev_err(dev, "rtc_set_time error %d\n", ret);
goto out;
}
save_control |= BIT_RTC_CTRL_REG_STOP_RTC_M;
ret = twl_rtc_write_u8(twl_rtc, save_control, REG_RTC_CTRL_REG);
out:
return ret;
}
static int twl_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
struct twl_rtc *twl_rtc = dev_get_drvdata(dev);
unsigned char rtc_data[ALL_TIME_REGS];
int ret;
ret = twl_i2c_read(TWL_MODULE_RTC, rtc_data,
twl_rtc->reg_map[REG_ALARM_SECONDS_REG], ALL_TIME_REGS);
if (ret < 0) {
dev_err(dev, "rtc_read_alarm error %d\n", ret);
return ret;
}
alm->time.tm_sec = bcd2bin(rtc_data[0]);
alm->time.tm_min = bcd2bin(rtc_data[1]);
alm->time.tm_hour = bcd2bin(rtc_data[2]);
alm->time.tm_mday = bcd2bin(rtc_data[3]);
alm->time.tm_mon = bcd2bin(rtc_data[4]) - 1;
alm->time.tm_year = bcd2bin(rtc_data[5]) + 100;
if (twl_rtc->rtc_irq_bits & BIT_RTC_INTERRUPTS_REG_IT_ALARM_M)
alm->enabled = 1;
return ret;
}
static int twl_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
struct twl_rtc *twl_rtc = dev_get_drvdata(dev);
unsigned char alarm_data[ALL_TIME_REGS];
int ret;
ret = twl_rtc_alarm_irq_enable(dev, 0);
if (ret)
goto out;
alarm_data[0] = bin2bcd(alm->time.tm_sec);
alarm_data[1] = bin2bcd(alm->time.tm_min);
alarm_data[2] = bin2bcd(alm->time.tm_hour);
alarm_data[3] = bin2bcd(alm->time.tm_mday);
alarm_data[4] = bin2bcd(alm->time.tm_mon + 1);
alarm_data[5] = bin2bcd(alm->time.tm_year - 100);
ret = twl_i2c_write(TWL_MODULE_RTC, alarm_data,
twl_rtc->reg_map[REG_ALARM_SECONDS_REG], ALL_TIME_REGS);
if (ret) {
dev_err(dev, "rtc_set_alarm error %d\n", ret);
goto out;
}
if (alm->enabled)
ret = twl_rtc_alarm_irq_enable(dev, 1);
out:
return ret;
}
static irqreturn_t twl_rtc_interrupt(int irq, void *data)
{
struct twl_rtc *twl_rtc = data;
unsigned long events;
int ret = IRQ_NONE;
int res;
u8 rd_reg;
res = twl_rtc_read_u8(twl_rtc, &rd_reg, REG_RTC_STATUS_REG);
if (res)
goto out;
if (rd_reg & BIT_RTC_STATUS_REG_ALARM_M)
events = RTC_IRQF | RTC_AF;
else
events = RTC_IRQF | RTC_PF;
res = twl_rtc_write_u8(twl_rtc, BIT_RTC_STATUS_REG_ALARM_M,
REG_RTC_STATUS_REG);
if (res)
goto out;
if (twl_rtc->class == TWL_4030) {
res = twl_i2c_read_u8(TWL4030_MODULE_INT,
&rd_reg, TWL4030_INT_PWR_ISR1);
if (res)
goto out;
}
rtc_update_irq(twl_rtc->rtc, 1, events);
ret = IRQ_HANDLED;
out:
return ret;
}
static int twl_rtc_probe(struct platform_device *pdev)
{
struct twl_rtc *twl_rtc;
struct device_node *np = pdev->dev.of_node;
int ret = -EINVAL;
int irq = platform_get_irq(pdev, 0);
u8 rd_reg;
if (!np) {
dev_err(&pdev->dev, "no DT info\n");
return -EINVAL;
}
if (irq <= 0)
return ret;
twl_rtc = devm_kzalloc(&pdev->dev, sizeof(*twl_rtc), GFP_KERNEL);
if (!twl_rtc)
return -ENOMEM;
if (twl_class_is_4030()) {
twl_rtc->class = TWL_4030;
twl_rtc->reg_map = (u8 *)twl4030_rtc_reg_map;
} else if (twl_class_is_6030()) {
twl_rtc->class = TWL_6030;
twl_rtc->reg_map = (u8 *)twl6030_rtc_reg_map;
} else {
dev_err(&pdev->dev, "TWL Class not supported.\n");
return -EINVAL;
}
ret = twl_rtc_read_u8(twl_rtc, &rd_reg, REG_RTC_STATUS_REG);
if (ret < 0)
return ret;
if (rd_reg & BIT_RTC_STATUS_REG_POWER_UP_M)
dev_warn(&pdev->dev, "Power up reset detected.\n");
if (rd_reg & BIT_RTC_STATUS_REG_ALARM_M)
dev_warn(&pdev->dev, "Pending Alarm interrupt detected.\n");
ret = twl_rtc_write_u8(twl_rtc, rd_reg, REG_RTC_STATUS_REG);
if (ret < 0)
return ret;
if (twl_rtc->class == TWL_6030) {
twl6030_interrupt_unmask(TWL6030_RTC_INT_MASK,
REG_INT_MSK_LINE_A);
twl6030_interrupt_unmask(TWL6030_RTC_INT_MASK,
REG_INT_MSK_STS_A);
}
dev_info(&pdev->dev, "Enabling TWL-RTC\n");
ret = twl_rtc_write_u8(twl_rtc, BIT_RTC_CTRL_REG_STOP_RTC_M,
REG_RTC_CTRL_REG);
if (ret < 0)
return ret;
ret = twl_rtc_write_u8(twl_rtc, 0, REG_RTC_INTERRUPTS_REG);
if (ret < 0)
dev_warn(&pdev->dev, "unable to disable interrupt\n");
ret = twl_rtc_read_u8(twl_rtc, &twl_rtc->rtc_irq_bits,
REG_RTC_INTERRUPTS_REG);
if (ret < 0)
return ret;
platform_set_drvdata(pdev, twl_rtc);
device_init_wakeup(&pdev->dev, 1);
twl_rtc->rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
&twl_rtc_ops, THIS_MODULE);
if (IS_ERR(twl_rtc->rtc)) {
dev_err(&pdev->dev, "can't register RTC device, err %ld\n",
PTR_ERR(twl_rtc->rtc));
return PTR_ERR(twl_rtc->rtc);
}
ret = devm_request_threaded_irq(&pdev->dev, irq, NULL,
twl_rtc_interrupt,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
dev_name(&twl_rtc->rtc->dev), twl_rtc);
if (ret < 0) {
dev_err(&pdev->dev, "IRQ is not free.\n");
return ret;
}
return 0;
}
static int twl_rtc_remove(struct platform_device *pdev)
{
struct twl_rtc *twl_rtc = platform_get_drvdata(pdev);
mask_rtc_irq_bit(twl_rtc, BIT_RTC_INTERRUPTS_REG_IT_ALARM_M);
mask_rtc_irq_bit(twl_rtc, BIT_RTC_INTERRUPTS_REG_IT_TIMER_M);
if (twl_rtc->class == TWL_6030) {
twl6030_interrupt_mask(TWL6030_RTC_INT_MASK,
REG_INT_MSK_LINE_A);
twl6030_interrupt_mask(TWL6030_RTC_INT_MASK,
REG_INT_MSK_STS_A);
}
return 0;
}
static void twl_rtc_shutdown(struct platform_device *pdev)
{
struct twl_rtc *twl_rtc = platform_get_drvdata(pdev);
mask_rtc_irq_bit(twl_rtc, BIT_RTC_INTERRUPTS_REG_IT_TIMER_M);
}
static int twl_rtc_suspend(struct device *dev)
{
struct twl_rtc *twl_rtc = dev_get_drvdata(dev);
twl_rtc->irqstat = twl_rtc->rtc_irq_bits;
mask_rtc_irq_bit(twl_rtc, BIT_RTC_INTERRUPTS_REG_IT_TIMER_M);
return 0;
}
static int twl_rtc_resume(struct device *dev)
{
struct twl_rtc *twl_rtc = dev_get_drvdata(dev);
set_rtc_irq_bit(twl_rtc, twl_rtc->irqstat);
return 0;
}
