static inline uint32_t jz4740_rtc_reg_read(struct jz4740_rtc *rtc, size_t reg)
{
return readl(rtc->base + reg);
}
static int jz4740_rtc_wait_write_ready(struct jz4740_rtc *rtc)
{
uint32_t ctrl;
int timeout = 1000;
do {
ctrl = jz4740_rtc_reg_read(rtc, JZ_REG_RTC_CTRL);
} while (!(ctrl & JZ_RTC_CTRL_WRDY) && --timeout);
return timeout ? 0 : -EIO;
}
static inline int jz4780_rtc_enable_write(struct jz4740_rtc *rtc)
{
uint32_t ctrl;
int ret, timeout = 1000;
ret = jz4740_rtc_wait_write_ready(rtc);
if (ret != 0)
return ret;
writel(JZ_RTC_WENR_MAGIC, rtc->base + JZ_REG_RTC_WENR);
do {
ctrl = readl(rtc->base + JZ_REG_RTC_WENR);
} while (!(ctrl & JZ_RTC_WENR_WEN) && --timeout);
return timeout ? 0 : -EIO;
}
static inline int jz4740_rtc_reg_write(struct jz4740_rtc *rtc, size_t reg,
uint32_t val)
{
int ret = 0;
if (rtc->type >= ID_JZ4780)
ret = jz4780_rtc_enable_write(rtc);
if (ret == 0)
ret = jz4740_rtc_wait_write_ready(rtc);
if (ret == 0)
writel(val, rtc->base + reg);
return ret;
}
static int jz4740_rtc_ctrl_set_bits(struct jz4740_rtc *rtc, uint32_t mask,
bool set)
{
int ret;
unsigned long flags;
uint32_t ctrl;
spin_lock_irqsave(&rtc->lock, flags);
ctrl = jz4740_rtc_reg_read(rtc, JZ_REG_RTC_CTRL);
ctrl |= JZ_RTC_CTRL_1HZ | JZ_RTC_CTRL_AF;
if (set)
ctrl |= mask;
else
ctrl &= ~mask;
ret = jz4740_rtc_reg_write(rtc, JZ_REG_RTC_CTRL, ctrl);
spin_unlock_irqrestore(&rtc->lock, flags);
return ret;
}
static int jz4740_rtc_read_time(struct device *dev, struct rtc_time *time)
{
struct jz4740_rtc *rtc = dev_get_drvdata(dev);
uint32_t secs, secs2;
int timeout = 5;
secs = jz4740_rtc_reg_read(rtc, JZ_REG_RTC_SEC);
secs2 = jz4740_rtc_reg_read(rtc, JZ_REG_RTC_SEC);
while (secs != secs2 && --timeout) {
secs = secs2;
secs2 = jz4740_rtc_reg_read(rtc, JZ_REG_RTC_SEC);
}
if (timeout == 0)
return -EIO;
rtc_time_to_tm(secs, time);
return rtc_valid_tm(time);
}
static int jz4740_rtc_set_mmss(struct device *dev, unsigned long secs)
{
struct jz4740_rtc *rtc = dev_get_drvdata(dev);
return jz4740_rtc_reg_write(rtc, JZ_REG_RTC_SEC, secs);
}
static int jz4740_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct jz4740_rtc *rtc = dev_get_drvdata(dev);
uint32_t secs;
uint32_t ctrl;
secs = jz4740_rtc_reg_read(rtc, JZ_REG_RTC_SEC_ALARM);
ctrl = jz4740_rtc_reg_read(rtc, JZ_REG_RTC_CTRL);
alrm->enabled = !!(ctrl & JZ_RTC_CTRL_AE);
alrm->pending = !!(ctrl & JZ_RTC_CTRL_AF);
rtc_time_to_tm(secs, &alrm->time);
return rtc_valid_tm(&alrm->time);
}
static int jz4740_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
int ret;
struct jz4740_rtc *rtc = dev_get_drvdata(dev);
unsigned long secs;
rtc_tm_to_time(&alrm->time, &secs);
ret = jz4740_rtc_reg_write(rtc, JZ_REG_RTC_SEC_ALARM, secs);
if (!ret)
ret = jz4740_rtc_ctrl_set_bits(rtc,
JZ_RTC_CTRL_AE | JZ_RTC_CTRL_AF_IRQ, alrm->enabled);
return ret;
}
static int jz4740_rtc_alarm_irq_enable(struct device *dev, unsigned int enable)
{
struct jz4740_rtc *rtc = dev_get_drvdata(dev);
return jz4740_rtc_ctrl_set_bits(rtc, JZ_RTC_CTRL_AF_IRQ, enable);
}
static irqreturn_t jz4740_rtc_irq(int irq, void *data)
{
struct jz4740_rtc *rtc = data;
uint32_t ctrl;
unsigned long events = 0;
ctrl = jz4740_rtc_reg_read(rtc, JZ_REG_RTC_CTRL);
if (ctrl & JZ_RTC_CTRL_1HZ)
events |= (RTC_UF | RTC_IRQF);
if (ctrl & JZ_RTC_CTRL_AF)
events |= (RTC_AF | RTC_IRQF);
rtc_update_irq(rtc->rtc, 1, events);
jz4740_rtc_ctrl_set_bits(rtc, JZ_RTC_CTRL_1HZ | JZ_RTC_CTRL_AF, false);
return IRQ_HANDLED;
}
static void jz4740_rtc_poweroff(struct device *dev)
{
struct jz4740_rtc *rtc = dev_get_drvdata(dev);
jz4740_rtc_reg_write(rtc, JZ_REG_RTC_HIBERNATE, 1);
}
static void jz4740_rtc_power_off(void)
{
struct jz4740_rtc *rtc = dev_get_drvdata(dev_for_power_off);
unsigned long rtc_rate;
unsigned long wakeup_filter_ticks;
unsigned long reset_counter_ticks;
clk_prepare_enable(rtc->clk);
rtc_rate = clk_get_rate(rtc->clk);
wakeup_filter_ticks =
(rtc->min_wakeup_pin_assert_time * rtc_rate) / 1000;
if (wakeup_filter_ticks < JZ_RTC_WAKEUP_FILTER_MASK)
wakeup_filter_ticks &= JZ_RTC_WAKEUP_FILTER_MASK;
else
wakeup_filter_ticks = JZ_RTC_WAKEUP_FILTER_MASK;
jz4740_rtc_reg_write(rtc,
JZ_REG_RTC_WAKEUP_FILTER, wakeup_filter_ticks);
reset_counter_ticks = (rtc->reset_pin_assert_time * rtc_rate) / 1000;
if (reset_counter_ticks < JZ_RTC_RESET_COUNTER_MASK)
reset_counter_ticks &= JZ_RTC_RESET_COUNTER_MASK;
else
reset_counter_ticks = JZ_RTC_RESET_COUNTER_MASK;
jz4740_rtc_reg_write(rtc,
JZ_REG_RTC_RESET_COUNTER, reset_counter_ticks);
jz4740_rtc_poweroff(dev_for_power_off);
kernel_halt();
}
static int jz4740_rtc_probe(struct platform_device *pdev)
{
int ret;
struct jz4740_rtc *rtc;
uint32_t scratchpad;
struct resource *mem;
const struct platform_device_id *id = platform_get_device_id(pdev);
const struct of_device_id *of_id = of_match_device(
jz4740_rtc_of_match, &pdev->dev);
struct device_node *np = pdev->dev.of_node;
rtc = devm_kzalloc(&pdev->dev, sizeof(*rtc), GFP_KERNEL);
if (!rtc)
return -ENOMEM;
if (of_id)
rtc->type = (enum jz4740_rtc_type)of_id->data;
else
rtc->type = id->driver_data;
rtc->irq = platform_get_irq(pdev, 0);
if (rtc->irq < 0) {
dev_err(&pdev->dev, "Failed to get platform irq\n");
return -ENOENT;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rtc->base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(rtc->base))
return PTR_ERR(rtc->base);
rtc->clk = devm_clk_get(&pdev->dev, "rtc");
if (IS_ERR(rtc->clk)) {
dev_err(&pdev->dev, "Failed to get RTC clock\n");
return PTR_ERR(rtc->clk);
}
spin_lock_init(&rtc->lock);
platform_set_drvdata(pdev, rtc);
device_init_wakeup(&pdev->dev, 1);
rtc->rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
&jz4740_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc->rtc)) {
ret = PTR_ERR(rtc->rtc);
dev_err(&pdev->dev, "Failed to register rtc device: %d\n", ret);
return ret;
}
ret = devm_request_irq(&pdev->dev, rtc->irq, jz4740_rtc_irq, 0,
pdev->name, rtc);
if (ret) {
dev_err(&pdev->dev, "Failed to request rtc irq: %d\n", ret);
return ret;
}
scratchpad = jz4740_rtc_reg_read(rtc, JZ_REG_RTC_SCRATCHPAD);
if (scratchpad != 0x12345678) {
ret = jz4740_rtc_reg_write(rtc, JZ_REG_RTC_SCRATCHPAD, 0x12345678);
ret = jz4740_rtc_reg_write(rtc, JZ_REG_RTC_SEC, 0);
if (ret) {
dev_err(&pdev->dev, "Could not write write to RTC registers\n");
return ret;
}
}
if (np && of_device_is_system_power_controller(np)) {
if (!pm_power_off) {
rtc->reset_pin_assert_time = 60;
of_property_read_u32(np, "reset-pin-assert-time-ms",
&rtc->reset_pin_assert_time);
rtc->min_wakeup_pin_assert_time = 100;
of_property_read_u32(np,
"min-wakeup-pin-assert-time-ms",
&rtc->min_wakeup_pin_assert_time);
dev_for_power_off = &pdev->dev;
pm_power_off = jz4740_rtc_power_off;
} else {
dev_warn(&pdev->dev,
"Poweroff handler already present!\n");
}
}
return 0;
}
static int jz4740_rtc_suspend(struct device *dev)
{
struct jz4740_rtc *rtc = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
enable_irq_wake(rtc->irq);
return 0;
}
static int jz4740_rtc_resume(struct device *dev)
{
struct jz4740_rtc *rtc = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
disable_irq_wake(rtc->irq);
return 0;
}
