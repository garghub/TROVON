static int twl_rtc_read_u8(u8 *data, u8 reg)
{
int ret;
ret = twl_i2c_read_u8(TWL_MODULE_RTC, data, (rtc_reg_map[reg]));
if (ret < 0)
pr_err("twl_rtc: Could not read TWL"
"register %X - error %d\n", reg, ret);
return ret;
}
static int twl_rtc_write_u8(u8 data, u8 reg)
{
int ret;
ret = twl_i2c_write_u8(TWL_MODULE_RTC, data, (rtc_reg_map[reg]));
if (ret < 0)
pr_err("twl_rtc: Could not write TWL"
"register %X - error %d\n", reg, ret);
return ret;
}
static int set_rtc_irq_bit(unsigned char bit)
{
unsigned char val;
int ret;
if (rtc_irq_bits & bit)
return 0;
val = rtc_irq_bits | bit;
val &= ~BIT_RTC_INTERRUPTS_REG_EVERY_M;
ret = twl_rtc_write_u8(val, REG_RTC_INTERRUPTS_REG);
if (ret == 0)
rtc_irq_bits = val;
return ret;
}
static int mask_rtc_irq_bit(unsigned char bit)
{
unsigned char val;
int ret;
if (!(rtc_irq_bits & bit))
return 0;
val = rtc_irq_bits & ~bit;
ret = twl_rtc_write_u8(val, REG_RTC_INTERRUPTS_REG);
if (ret == 0)
rtc_irq_bits = val;
return ret;
}
static int twl_rtc_alarm_irq_enable(struct device *dev, unsigned enabled)
{
int ret;
if (enabled)
ret = set_rtc_irq_bit(BIT_RTC_INTERRUPTS_REG_IT_ALARM_M);
else
ret = mask_rtc_irq_bit(BIT_RTC_INTERRUPTS_REG_IT_ALARM_M);
return ret;
}
static int twl_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
unsigned char rtc_data[ALL_TIME_REGS + 1];
int ret;
u8 save_control;
u8 rtc_control;
ret = twl_rtc_read_u8(&save_control, REG_RTC_CTRL_REG);
if (ret < 0) {
dev_err(dev, "%s: reading CTRL_REG, error %d\n", __func__, ret);
return ret;
}
if (twl_class_is_6030()) {
if (save_control & BIT_RTC_CTRL_REG_GET_TIME_M) {
save_control &= ~BIT_RTC_CTRL_REG_GET_TIME_M;
ret = twl_rtc_write_u8(save_control, REG_RTC_CTRL_REG);
if (ret < 0) {
dev_err(dev, "%s clr GET_TIME, error %d\n",
__func__, ret);
return ret;
}
}
}
rtc_control = save_control | BIT_RTC_CTRL_REG_GET_TIME_M;
if (twl_class_is_6030())
rtc_control |= BIT_RTC_CTRL_REG_RTC_V_OPT;
ret = twl_rtc_write_u8(rtc_control, REG_RTC_CTRL_REG);
if (ret < 0) {
dev_err(dev, "%s: writing CTRL_REG, error %d\n", __func__, ret);
return ret;
}
ret = twl_i2c_read(TWL_MODULE_RTC, rtc_data,
(rtc_reg_map[REG_SECONDS_REG]), ALL_TIME_REGS);
if (ret < 0) {
dev_err(dev, "%s: reading data, error %d\n", __func__, ret);
return ret;
}
if (twl_class_is_6030()) {
ret = twl_rtc_write_u8(save_control, REG_RTC_CTRL_REG);
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
unsigned char save_control;
unsigned char rtc_data[ALL_TIME_REGS + 1];
int ret;
rtc_data[1] = bin2bcd(tm->tm_sec);
rtc_data[2] = bin2bcd(tm->tm_min);
rtc_data[3] = bin2bcd(tm->tm_hour);
rtc_data[4] = bin2bcd(tm->tm_mday);
rtc_data[5] = bin2bcd(tm->tm_mon + 1);
rtc_data[6] = bin2bcd(tm->tm_year - 100);
ret = twl_rtc_read_u8(&save_control, REG_RTC_CTRL_REG);
if (ret < 0)
goto out;
save_control &= ~BIT_RTC_CTRL_REG_STOP_RTC_M;
ret = twl_rtc_write_u8(save_control, REG_RTC_CTRL_REG);
if (ret < 0)
goto out;
ret = twl_i2c_write(TWL_MODULE_RTC, rtc_data,
(rtc_reg_map[REG_SECONDS_REG]), ALL_TIME_REGS);
if (ret < 0) {
dev_err(dev, "rtc_set_time error %d\n", ret);
goto out;
}
save_control |= BIT_RTC_CTRL_REG_STOP_RTC_M;
ret = twl_rtc_write_u8(save_control, REG_RTC_CTRL_REG);
out:
return ret;
}
static int twl_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
unsigned char rtc_data[ALL_TIME_REGS + 1];
int ret;
ret = twl_i2c_read(TWL_MODULE_RTC, rtc_data,
(rtc_reg_map[REG_ALARM_SECONDS_REG]), ALL_TIME_REGS);
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
if (rtc_irq_bits & BIT_RTC_INTERRUPTS_REG_IT_ALARM_M)
alm->enabled = 1;
return ret;
}
static int twl_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alm)
{
unsigned char alarm_data[ALL_TIME_REGS + 1];
int ret;
ret = twl_rtc_alarm_irq_enable(dev, 0);
if (ret)
goto out;
alarm_data[1] = bin2bcd(alm->time.tm_sec);
alarm_data[2] = bin2bcd(alm->time.tm_min);
alarm_data[3] = bin2bcd(alm->time.tm_hour);
alarm_data[4] = bin2bcd(alm->time.tm_mday);
alarm_data[5] = bin2bcd(alm->time.tm_mon + 1);
alarm_data[6] = bin2bcd(alm->time.tm_year - 100);
ret = twl_i2c_write(TWL_MODULE_RTC, alarm_data,
(rtc_reg_map[REG_ALARM_SECONDS_REG]), ALL_TIME_REGS);
if (ret) {
dev_err(dev, "rtc_set_alarm error %d\n", ret);
goto out;
}
if (alm->enabled)
ret = twl_rtc_alarm_irq_enable(dev, 1);
out:
return ret;
}
static irqreturn_t twl_rtc_interrupt(int irq, void *rtc)
{
unsigned long events;
int ret = IRQ_NONE;
int res;
u8 rd_reg;
res = twl_rtc_read_u8(&rd_reg, REG_RTC_STATUS_REG);
if (res)
goto out;
if (rd_reg & BIT_RTC_STATUS_REG_ALARM_M)
events = RTC_IRQF | RTC_AF;
else
events = RTC_IRQF | RTC_PF;
res = twl_rtc_write_u8(BIT_RTC_STATUS_REG_ALARM_M,
REG_RTC_STATUS_REG);
if (res)
goto out;
if (twl_class_is_4030()) {
res = twl_i2c_read_u8(TWL4030_MODULE_INT,
&rd_reg, TWL4030_INT_PWR_ISR1);
if (res)
goto out;
}
rtc_update_irq(rtc, 1, events);
ret = IRQ_HANDLED;
out:
return ret;
}
static int __devinit twl_rtc_probe(struct platform_device *pdev)
{
struct rtc_device *rtc;
int ret = -EINVAL;
int irq = platform_get_irq(pdev, 0);
u8 rd_reg;
if (irq <= 0)
goto out1;
ret = twl_rtc_read_u8(&rd_reg, REG_RTC_STATUS_REG);
if (ret < 0)
goto out1;
if (rd_reg & BIT_RTC_STATUS_REG_POWER_UP_M)
dev_warn(&pdev->dev, "Power up reset detected.\n");
if (rd_reg & BIT_RTC_STATUS_REG_ALARM_M)
dev_warn(&pdev->dev, "Pending Alarm interrupt detected.\n");
ret = twl_rtc_write_u8(rd_reg, REG_RTC_STATUS_REG);
if (ret < 0)
goto out1;
if (twl_class_is_6030()) {
twl6030_interrupt_unmask(TWL6030_RTC_INT_MASK,
REG_INT_MSK_LINE_A);
twl6030_interrupt_unmask(TWL6030_RTC_INT_MASK,
REG_INT_MSK_STS_A);
}
dev_info(&pdev->dev, "Enabling TWL-RTC\n");
ret = twl_rtc_write_u8(BIT_RTC_CTRL_REG_STOP_RTC_M, REG_RTC_CTRL_REG);
if (ret < 0)
goto out1;
ret = twl_rtc_write_u8(0, REG_RTC_INTERRUPTS_REG);
if (ret < 0)
dev_warn(&pdev->dev, "unable to disable interrupt\n");
ret = twl_rtc_read_u8(&rtc_irq_bits, REG_RTC_INTERRUPTS_REG);
if (ret < 0)
goto out1;
rtc = rtc_device_register(pdev->name,
&pdev->dev, &twl_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc)) {
ret = PTR_ERR(rtc);
dev_err(&pdev->dev, "can't register RTC device, err %ld\n",
PTR_ERR(rtc));
goto out1;
}
ret = request_threaded_irq(irq, NULL, twl_rtc_interrupt,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
dev_name(&rtc->dev), rtc);
if (ret < 0) {
dev_err(&pdev->dev, "IRQ is not free.\n");
goto out2;
}
platform_set_drvdata(pdev, rtc);
return 0;
out2:
rtc_device_unregister(rtc);
out1:
return ret;
}
static int __devexit twl_rtc_remove(struct platform_device *pdev)
{
struct rtc_device *rtc = platform_get_drvdata(pdev);
int irq = platform_get_irq(pdev, 0);
mask_rtc_irq_bit(BIT_RTC_INTERRUPTS_REG_IT_ALARM_M);
mask_rtc_irq_bit(BIT_RTC_INTERRUPTS_REG_IT_TIMER_M);
if (twl_class_is_6030()) {
twl6030_interrupt_mask(TWL6030_RTC_INT_MASK,
REG_INT_MSK_LINE_A);
twl6030_interrupt_mask(TWL6030_RTC_INT_MASK,
REG_INT_MSK_STS_A);
}
free_irq(irq, rtc);
rtc_device_unregister(rtc);
platform_set_drvdata(pdev, NULL);
return 0;
}
static void twl_rtc_shutdown(struct platform_device *pdev)
{
mask_rtc_irq_bit(BIT_RTC_INTERRUPTS_REG_IT_TIMER_M);
}
static int twl_rtc_suspend(struct platform_device *pdev, pm_message_t state)
{
irqstat = rtc_irq_bits;
mask_rtc_irq_bit(BIT_RTC_INTERRUPTS_REG_IT_TIMER_M);
return 0;
}
static int twl_rtc_resume(struct platform_device *pdev)
{
set_rtc_irq_bit(irqstat);
return 0;
}
static int __init twl_rtc_init(void)
{
if (twl_class_is_4030())
rtc_reg_map = (u8 *) twl4030_rtc_reg_map;
else
rtc_reg_map = (u8 *) twl6030_rtc_reg_map;
return platform_driver_register(&twl4030rtc_driver);
}
static void __exit twl_rtc_exit(void)
{
platform_driver_unregister(&twl4030rtc_driver);
}
