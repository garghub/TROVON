static void wm831x_rtc_add_randomness(struct wm831x *wm831x)
{
int ret;
u16 reg;
ret = wm831x_reg_read(wm831x, WM831X_RTC_WRITE_COUNTER);
if (ret >= 0) {
reg = ret;
add_device_randomness(&reg, sizeof(reg));
} else {
dev_warn(wm831x->dev, "Failed to read RTC write counter: %d\n",
ret);
}
}
static int wm831x_rtc_readtime(struct device *dev, struct rtc_time *tm)
{
struct wm831x_rtc *wm831x_rtc = dev_get_drvdata(dev);
struct wm831x *wm831x = wm831x_rtc->wm831x;
u16 time1[2], time2[2];
int ret;
int count = 0;
ret = wm831x_reg_read(wm831x, WM831X_RTC_CONTROL);
if (ret < 0) {
dev_err(dev, "Failed to read RTC control: %d\n", ret);
return ret;
}
if (!(ret & WM831X_RTC_VALID)) {
dev_dbg(dev, "RTC not yet configured\n");
return -EINVAL;
}
do {
ret = wm831x_bulk_read(wm831x, WM831X_RTC_TIME_1,
2, time1);
if (ret != 0)
continue;
ret = wm831x_bulk_read(wm831x, WM831X_RTC_TIME_1,
2, time2);
if (ret != 0)
continue;
if (memcmp(time1, time2, sizeof(time1)) == 0) {
u32 time = (time1[0] << 16) | time1[1];
rtc_time_to_tm(time, tm);
return rtc_valid_tm(tm);
}
} while (++count < WM831X_GET_TIME_RETRIES);
dev_err(dev, "Timed out reading current time\n");
return -EIO;
}
static int wm831x_rtc_set_mmss(struct device *dev, unsigned long time)
{
struct wm831x_rtc *wm831x_rtc = dev_get_drvdata(dev);
struct wm831x *wm831x = wm831x_rtc->wm831x;
struct rtc_time new_tm;
unsigned long new_time;
int ret;
int count = 0;
ret = wm831x_reg_write(wm831x, WM831X_RTC_TIME_1,
(time >> 16) & 0xffff);
if (ret < 0) {
dev_err(dev, "Failed to write TIME_1: %d\n", ret);
return ret;
}
ret = wm831x_reg_write(wm831x, WM831X_RTC_TIME_2, time & 0xffff);
if (ret < 0) {
dev_err(dev, "Failed to write TIME_2: %d\n", ret);
return ret;
}
do {
msleep(1);
ret = wm831x_reg_read(wm831x, WM831X_RTC_CONTROL);
if (ret < 0)
ret = WM831X_RTC_SYNC_BUSY;
} while (!(ret & WM831X_RTC_SYNC_BUSY) &&
++count < WM831X_SET_TIME_RETRIES);
if (ret & WM831X_RTC_SYNC_BUSY) {
dev_err(dev, "Timed out writing RTC update\n");
return -EIO;
}
ret = wm831x_rtc_readtime(dev, &new_tm);
if (ret < 0)
return ret;
ret = rtc_tm_to_time(&new_tm, &new_time);
if (ret < 0) {
dev_err(dev, "Failed to convert time: %d\n", ret);
return ret;
}
if (new_time - time > 1) {
dev_err(dev, "RTC update not permitted by hardware\n");
return -EPERM;
}
return 0;
}
static int wm831x_rtc_readalarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct wm831x_rtc *wm831x_rtc = dev_get_drvdata(dev);
int ret;
u16 data[2];
u32 time;
ret = wm831x_bulk_read(wm831x_rtc->wm831x, WM831X_RTC_ALARM_1,
2, data);
if (ret != 0) {
dev_err(dev, "Failed to read alarm time: %d\n", ret);
return ret;
}
time = (data[0] << 16) | data[1];
rtc_time_to_tm(time, &alrm->time);
ret = wm831x_reg_read(wm831x_rtc->wm831x, WM831X_RTC_CONTROL);
if (ret < 0) {
dev_err(dev, "Failed to read RTC control: %d\n", ret);
return ret;
}
if (ret & WM831X_RTC_ALM_ENA)
alrm->enabled = 1;
else
alrm->enabled = 0;
return 0;
}
static int wm831x_rtc_stop_alarm(struct wm831x_rtc *wm831x_rtc)
{
wm831x_rtc->alarm_enabled = 0;
return wm831x_set_bits(wm831x_rtc->wm831x, WM831X_RTC_CONTROL,
WM831X_RTC_ALM_ENA, 0);
}
static int wm831x_rtc_start_alarm(struct wm831x_rtc *wm831x_rtc)
{
wm831x_rtc->alarm_enabled = 1;
return wm831x_set_bits(wm831x_rtc->wm831x, WM831X_RTC_CONTROL,
WM831X_RTC_ALM_ENA, WM831X_RTC_ALM_ENA);
}
static int wm831x_rtc_setalarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct wm831x_rtc *wm831x_rtc = dev_get_drvdata(dev);
struct wm831x *wm831x = wm831x_rtc->wm831x;
int ret;
unsigned long time;
ret = rtc_tm_to_time(&alrm->time, &time);
if (ret < 0) {
dev_err(dev, "Failed to convert time: %d\n", ret);
return ret;
}
ret = wm831x_rtc_stop_alarm(wm831x_rtc);
if (ret < 0) {
dev_err(dev, "Failed to stop alarm: %d\n", ret);
return ret;
}
ret = wm831x_reg_write(wm831x, WM831X_RTC_ALARM_1,
(time >> 16) & 0xffff);
if (ret < 0) {
dev_err(dev, "Failed to write ALARM_1: %d\n", ret);
return ret;
}
ret = wm831x_reg_write(wm831x, WM831X_RTC_ALARM_2, time & 0xffff);
if (ret < 0) {
dev_err(dev, "Failed to write ALARM_2: %d\n", ret);
return ret;
}
if (alrm->enabled) {
ret = wm831x_rtc_start_alarm(wm831x_rtc);
if (ret < 0) {
dev_err(dev, "Failed to start alarm: %d\n", ret);
return ret;
}
}
return 0;
}
static int wm831x_rtc_alarm_irq_enable(struct device *dev,
unsigned int enabled)
{
struct wm831x_rtc *wm831x_rtc = dev_get_drvdata(dev);
if (enabled)
return wm831x_rtc_start_alarm(wm831x_rtc);
else
return wm831x_rtc_stop_alarm(wm831x_rtc);
}
static irqreturn_t wm831x_alm_irq(int irq, void *data)
{
struct wm831x_rtc *wm831x_rtc = data;
rtc_update_irq(wm831x_rtc->rtc, 1, RTC_IRQF | RTC_AF);
return IRQ_HANDLED;
}
static int wm831x_rtc_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct wm831x_rtc *wm831x_rtc = dev_get_drvdata(&pdev->dev);
int ret, enable;
if (wm831x_rtc->alarm_enabled && device_may_wakeup(&pdev->dev))
enable = WM831X_RTC_ALM_ENA;
else
enable = 0;
ret = wm831x_set_bits(wm831x_rtc->wm831x, WM831X_RTC_CONTROL,
WM831X_RTC_ALM_ENA, enable);
if (ret != 0)
dev_err(&pdev->dev, "Failed to update RTC alarm: %d\n", ret);
return 0;
}
static int wm831x_rtc_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct wm831x_rtc *wm831x_rtc = dev_get_drvdata(&pdev->dev);
int ret;
if (wm831x_rtc->alarm_enabled) {
ret = wm831x_rtc_start_alarm(wm831x_rtc);
if (ret != 0)
dev_err(&pdev->dev,
"Failed to restart RTC alarm: %d\n", ret);
}
return 0;
}
static int wm831x_rtc_freeze(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct wm831x_rtc *wm831x_rtc = dev_get_drvdata(&pdev->dev);
int ret;
ret = wm831x_set_bits(wm831x_rtc->wm831x, WM831X_RTC_CONTROL,
WM831X_RTC_ALM_ENA, 0);
if (ret != 0)
dev_err(&pdev->dev, "Failed to stop RTC alarm: %d\n", ret);
return 0;
}
static int wm831x_rtc_probe(struct platform_device *pdev)
{
struct wm831x *wm831x = dev_get_drvdata(pdev->dev.parent);
struct wm831x_rtc *wm831x_rtc;
int alm_irq = wm831x_irq(wm831x, platform_get_irq_byname(pdev, "ALM"));
int ret = 0;
wm831x_rtc = devm_kzalloc(&pdev->dev, sizeof(*wm831x_rtc), GFP_KERNEL);
if (wm831x_rtc == NULL)
return -ENOMEM;
platform_set_drvdata(pdev, wm831x_rtc);
wm831x_rtc->wm831x = wm831x;
ret = wm831x_reg_read(wm831x, WM831X_RTC_CONTROL);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to read RTC control: %d\n", ret);
goto err;
}
if (ret & WM831X_RTC_ALM_ENA)
wm831x_rtc->alarm_enabled = 1;
device_init_wakeup(&pdev->dev, 1);
wm831x_rtc->rtc = devm_rtc_device_register(&pdev->dev, "wm831x",
&wm831x_rtc_ops, THIS_MODULE);
if (IS_ERR(wm831x_rtc->rtc)) {
ret = PTR_ERR(wm831x_rtc->rtc);
goto err;
}
ret = devm_request_threaded_irq(&pdev->dev, alm_irq, NULL,
wm831x_alm_irq,
IRQF_TRIGGER_RISING, "RTC alarm",
wm831x_rtc);
if (ret != 0) {
dev_err(&pdev->dev, "Failed to request alarm IRQ %d: %d\n",
alm_irq, ret);
}
wm831x_rtc_add_randomness(wm831x);
return 0;
err:
return ret;
}
