static u32 rtc_read_lp_counter(struct snvs_rtc_data *data)
{
u64 read1, read2;
u32 val;
do {
regmap_read(data->regmap, data->offset + SNVS_LPSRTCMR, &val);
read1 = val;
read1 <<= 32;
regmap_read(data->regmap, data->offset + SNVS_LPSRTCLR, &val);
read1 |= val;
regmap_read(data->regmap, data->offset + SNVS_LPSRTCMR, &val);
read2 = val;
read2 <<= 32;
regmap_read(data->regmap, data->offset + SNVS_LPSRTCLR, &val);
read2 |= val;
} while (read1 != read2);
return (u32) (read1 >> CNTR_TO_SECS_SH);
}
static void rtc_write_sync_lp(struct snvs_rtc_data *data)
{
u32 count1, count2, count3;
int i;
for (i = 0; i < 3; i++) {
do {
regmap_read(data->regmap, data->offset + SNVS_LPSRTCLR, &count1);
regmap_read(data->regmap, data->offset + SNVS_LPSRTCLR, &count2);
} while (count1 != count2);
do {
do {
regmap_read(data->regmap, data->offset + SNVS_LPSRTCLR, &count2);
regmap_read(data->regmap, data->offset + SNVS_LPSRTCLR, &count3);
} while (count2 != count3);
} while (count3 == count1);
}
}
static int snvs_rtc_enable(struct snvs_rtc_data *data, bool enable)
{
int timeout = 1000;
u32 lpcr;
regmap_update_bits(data->regmap, data->offset + SNVS_LPCR, SNVS_LPCR_SRTC_ENV,
enable ? SNVS_LPCR_SRTC_ENV : 0);
while (--timeout) {
regmap_read(data->regmap, data->offset + SNVS_LPCR, &lpcr);
if (enable) {
if (lpcr & SNVS_LPCR_SRTC_ENV)
break;
} else {
if (!(lpcr & SNVS_LPCR_SRTC_ENV))
break;
}
}
if (!timeout)
return -ETIMEDOUT;
return 0;
}
static int snvs_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct snvs_rtc_data *data = dev_get_drvdata(dev);
unsigned long time = rtc_read_lp_counter(data);
rtc_time_to_tm(time, tm);
return 0;
}
static int snvs_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct snvs_rtc_data *data = dev_get_drvdata(dev);
unsigned long time;
rtc_tm_to_time(tm, &time);
snvs_rtc_enable(data, false);
regmap_write(data->regmap, data->offset + SNVS_LPSRTCLR, time << CNTR_TO_SECS_SH);
regmap_write(data->regmap, data->offset + SNVS_LPSRTCMR, time >> (32 - CNTR_TO_SECS_SH));
snvs_rtc_enable(data, true);
return 0;
}
static int snvs_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct snvs_rtc_data *data = dev_get_drvdata(dev);
u32 lptar, lpsr;
regmap_read(data->regmap, data->offset + SNVS_LPTAR, &lptar);
rtc_time_to_tm(lptar, &alrm->time);
regmap_read(data->regmap, data->offset + SNVS_LPSR, &lpsr);
alrm->pending = (lpsr & SNVS_LPSR_LPTA) ? 1 : 0;
return 0;
}
static int snvs_rtc_alarm_irq_enable(struct device *dev, unsigned int enable)
{
struct snvs_rtc_data *data = dev_get_drvdata(dev);
regmap_update_bits(data->regmap, data->offset + SNVS_LPCR,
(SNVS_LPCR_LPTA_EN | SNVS_LPCR_LPWUI_EN),
enable ? (SNVS_LPCR_LPTA_EN | SNVS_LPCR_LPWUI_EN) : 0);
rtc_write_sync_lp(data);
return 0;
}
static int snvs_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct snvs_rtc_data *data = dev_get_drvdata(dev);
struct rtc_time *alrm_tm = &alrm->time;
unsigned long time;
rtc_tm_to_time(alrm_tm, &time);
regmap_update_bits(data->regmap, data->offset + SNVS_LPCR, SNVS_LPCR_LPTA_EN, 0);
rtc_write_sync_lp(data);
regmap_write(data->regmap, data->offset + SNVS_LPTAR, time);
regmap_write(data->regmap, data->offset + SNVS_LPSR, SNVS_LPSR_LPTA);
return snvs_rtc_alarm_irq_enable(dev, alrm->enabled);
}
static irqreturn_t snvs_rtc_irq_handler(int irq, void *dev_id)
{
struct device *dev = dev_id;
struct snvs_rtc_data *data = dev_get_drvdata(dev);
u32 lpsr;
u32 events = 0;
regmap_read(data->regmap, data->offset + SNVS_LPSR, &lpsr);
if (lpsr & SNVS_LPSR_LPTA) {
events |= (RTC_AF | RTC_IRQF);
snvs_rtc_alarm_irq_enable(dev, 0);
rtc_update_irq(data->rtc, 1, events);
}
regmap_write(data->regmap, data->offset + SNVS_LPSR, lpsr);
return events ? IRQ_HANDLED : IRQ_NONE;
}
static int snvs_rtc_probe(struct platform_device *pdev)
{
struct snvs_rtc_data *data;
struct resource *res;
int ret;
void __iomem *mmio;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->regmap = syscon_regmap_lookup_by_phandle(pdev->dev.of_node, "regmap");
if (IS_ERR(data->regmap)) {
dev_warn(&pdev->dev, "snvs rtc: you use old dts file, please update it\n");
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mmio = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mmio))
return PTR_ERR(mmio);
data->regmap = devm_regmap_init_mmio(&pdev->dev, mmio, &snvs_rtc_config);
} else {
data->offset = SNVS_LPREGISTER_OFFSET;
of_property_read_u32(pdev->dev.of_node, "offset", &data->offset);
}
if (!data->regmap) {
dev_err(&pdev->dev, "Can't find snvs syscon\n");
return -ENODEV;
}
data->irq = platform_get_irq(pdev, 0);
if (data->irq < 0)
return data->irq;
data->clk = devm_clk_get(&pdev->dev, "snvs-rtc");
if (IS_ERR(data->clk)) {
data->clk = NULL;
} else {
ret = clk_prepare_enable(data->clk);
if (ret) {
dev_err(&pdev->dev,
"Could not prepare or enable the snvs clock\n");
return ret;
}
}
platform_set_drvdata(pdev, data);
regmap_write(data->regmap, data->offset + SNVS_LPPGDR, SNVS_LPPGDR_INIT);
regmap_write(data->regmap, data->offset + SNVS_LPSR, 0xffffffff);
snvs_rtc_enable(data, true);
device_init_wakeup(&pdev->dev, true);
ret = devm_request_irq(&pdev->dev, data->irq, snvs_rtc_irq_handler,
IRQF_SHARED, "rtc alarm", &pdev->dev);
if (ret) {
dev_err(&pdev->dev, "failed to request irq %d: %d\n",
data->irq, ret);
goto error_rtc_device_register;
}
data->rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
&snvs_rtc_ops, THIS_MODULE);
if (IS_ERR(data->rtc)) {
ret = PTR_ERR(data->rtc);
dev_err(&pdev->dev, "failed to register rtc: %d\n", ret);
goto error_rtc_device_register;
}
return 0;
error_rtc_device_register:
if (data->clk)
clk_disable_unprepare(data->clk);
return ret;
}
static int snvs_rtc_suspend(struct device *dev)
{
struct snvs_rtc_data *data = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
return enable_irq_wake(data->irq);
return 0;
}
static int snvs_rtc_suspend_noirq(struct device *dev)
{
struct snvs_rtc_data *data = dev_get_drvdata(dev);
if (data->clk)
clk_disable_unprepare(data->clk);
return 0;
}
static int snvs_rtc_resume(struct device *dev)
{
struct snvs_rtc_data *data = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
return disable_irq_wake(data->irq);
return 0;
}
static int snvs_rtc_resume_noirq(struct device *dev)
{
struct snvs_rtc_data *data = dev_get_drvdata(dev);
if (data->clk)
return clk_prepare_enable(data->clk);
return 0;
}
