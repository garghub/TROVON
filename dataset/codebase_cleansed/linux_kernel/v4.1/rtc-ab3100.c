static int ab3100_rtc_set_mmss(struct device *dev, time64_t secs)
{
u8 regs[] = {AB3100_TI0, AB3100_TI1, AB3100_TI2,
AB3100_TI3, AB3100_TI4, AB3100_TI5};
unsigned char buf[6];
u64 hw_counter = secs * AB3100_RTC_CLOCK_RATE * 2;
int err = 0;
int i;
buf[0] = (hw_counter) & 0xFF;
buf[1] = (hw_counter >> 8) & 0xFF;
buf[2] = (hw_counter >> 16) & 0xFF;
buf[3] = (hw_counter >> 24) & 0xFF;
buf[4] = (hw_counter >> 32) & 0xFF;
buf[5] = (hw_counter >> 40) & 0xFF;
for (i = 0; i < 6; i++) {
err = abx500_set_register_interruptible(dev, 0,
regs[i], buf[i]);
if (err)
return err;
}
return abx500_mask_and_set_register_interruptible(dev, 0,
AB3100_RTC,
0x01, 0x01);
}
static int ab3100_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
time64_t time;
u8 rtcval;
int err;
err = abx500_get_register_interruptible(dev, 0,
AB3100_RTC, &rtcval);
if (err)
return err;
if (!(rtcval & 0x01)) {
dev_info(dev, "clock not set (lost power)");
return -EINVAL;
} else {
u64 hw_counter;
u8 buf[6];
err = abx500_get_register_page_interruptible(dev, 0,
AB3100_TI0,
buf, 6);
if (err != 0)
return err;
hw_counter = ((u64) buf[5] << 40) | ((u64) buf[4] << 32) |
((u64) buf[3] << 24) | ((u64) buf[2] << 16) |
((u64) buf[1] << 8) | (u64) buf[0];
time = hw_counter / (u64) (AB3100_RTC_CLOCK_RATE * 2);
}
rtc_time64_to_tm(time, tm);
return rtc_valid_tm(tm);
}
static int ab3100_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
time64_t time;
u64 hw_counter;
u8 buf[6];
u8 rtcval;
int err;
err = abx500_get_register_interruptible(dev, 0,
AB3100_RTC, &rtcval);
if (err)
return err;
if (rtcval & 0x04)
alarm->enabled = 1;
else
alarm->enabled = 0;
alarm->pending = 0;
err = abx500_get_register_page_interruptible(dev, 0,
AB3100_AL0, buf, 4);
if (err)
return err;
hw_counter = ((u64) buf[3] << 40) | ((u64) buf[2] << 32) |
((u64) buf[1] << 24) | ((u64) buf[0] << 16);
time = hw_counter / (u64) (AB3100_RTC_CLOCK_RATE * 2);
rtc_time64_to_tm(time, &alarm->time);
return rtc_valid_tm(&alarm->time);
}
static int ab3100_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
u8 regs[] = {AB3100_AL0, AB3100_AL1, AB3100_AL2, AB3100_AL3};
unsigned char buf[4];
time64_t secs;
u64 hw_counter;
int err;
int i;
secs = rtc_tm_to_time64(&alarm->time);
hw_counter = secs * AB3100_RTC_CLOCK_RATE * 2;
buf[0] = (hw_counter >> 16) & 0xFF;
buf[1] = (hw_counter >> 24) & 0xFF;
buf[2] = (hw_counter >> 32) & 0xFF;
buf[3] = (hw_counter >> 40) & 0xFF;
for (i = 0; i < 4; i++) {
err = abx500_set_register_interruptible(dev, 0,
regs[i], buf[i]);
if (err)
return err;
}
return abx500_mask_and_set_register_interruptible(dev, 0,
AB3100_RTC, (1 << 2),
alarm->enabled << 2);
}
static int ab3100_rtc_irq_enable(struct device *dev, unsigned int enabled)
{
if (enabled)
return abx500_mask_and_set_register_interruptible(dev, 0,
AB3100_RTC, (1 << 2),
1 << 2);
else
return abx500_mask_and_set_register_interruptible(dev, 0,
AB3100_RTC, (1 << 2),
0);
}
static int __init ab3100_rtc_probe(struct platform_device *pdev)
{
int err;
u8 regval;
struct rtc_device *rtc;
err = abx500_get_register_interruptible(&pdev->dev, 0,
AB3100_RTC, &regval);
if (err) {
dev_err(&pdev->dev, "unable to read RTC register\n");
return -ENODEV;
}
if ((regval & 0xFE) != RTC_SETTING) {
dev_warn(&pdev->dev, "not default value in RTC reg 0x%x\n",
regval);
}
if ((regval & 1) == 0) {
regval = 1 | RTC_SETTING;
err = abx500_set_register_interruptible(&pdev->dev, 0,
AB3100_RTC, regval);
}
rtc = devm_rtc_device_register(&pdev->dev, "ab3100-rtc",
&ab3100_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc)) {
err = PTR_ERR(rtc);
return err;
}
platform_set_drvdata(pdev, rtc);
return 0;
}
