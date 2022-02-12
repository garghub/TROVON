static void di_write_busy_wait(const struct imxdi_dev *imxdi, u32 val,
unsigned reg)
{
writel(val, imxdi->ioaddr + reg);
usleep_range(130, 200);
}
static void di_report_tamper_info(struct imxdi_dev *imxdi, u32 dsr)
{
u32 dtcr;
dtcr = readl(imxdi->ioaddr + DTCR);
dev_emerg(&imxdi->pdev->dev, "DryIce tamper event detected\n");
if (dsr & DSR_VTD)
dev_emerg(&imxdi->pdev->dev, "%sVoltage Tamper Event\n",
dtcr & DTCR_VTE ? "" : "Spurious ");
if (dsr & DSR_CTD)
dev_emerg(&imxdi->pdev->dev, "%s32768 Hz Clock Tamper Event\n",
dtcr & DTCR_CTE ? "" : "Spurious ");
if (dsr & DSR_TTD)
dev_emerg(&imxdi->pdev->dev, "%sTemperature Tamper Event\n",
dtcr & DTCR_TTE ? "" : "Spurious ");
if (dsr & DSR_SAD)
dev_emerg(&imxdi->pdev->dev,
"%sSecure Controller Alarm Event\n",
dtcr & DTCR_SAIE ? "" : "Spurious ");
if (dsr & DSR_EBD)
dev_emerg(&imxdi->pdev->dev, "%sExternal Boot Tamper Event\n",
dtcr & DTCR_EBE ? "" : "Spurious ");
if (dsr & DSR_ETAD)
dev_emerg(&imxdi->pdev->dev, "%sExternal Tamper A Event\n",
dtcr & DTCR_ETAE ? "" : "Spurious ");
if (dsr & DSR_ETBD)
dev_emerg(&imxdi->pdev->dev, "%sExternal Tamper B Event\n",
dtcr & DTCR_ETBE ? "" : "Spurious ");
if (dsr & DSR_WTD)
dev_emerg(&imxdi->pdev->dev, "%sWire-mesh Tamper Event\n",
dtcr & DTCR_WTE ? "" : "Spurious ");
if (dsr & DSR_MCO)
dev_emerg(&imxdi->pdev->dev,
"%sMonotonic-counter Overflow Event\n",
dtcr & DTCR_MOE ? "" : "Spurious ");
if (dsr & DSR_TCO)
dev_emerg(&imxdi->pdev->dev, "%sTimer-counter Overflow Event\n",
dtcr & DTCR_TOE ? "" : "Spurious ");
}
static void di_what_is_to_be_done(struct imxdi_dev *imxdi,
const char *power_supply)
{
dev_emerg(&imxdi->pdev->dev, "Please cycle the %s power supply in order to get the DryIce/RTC unit working again\n",
power_supply);
}
static int di_handle_failure_state(struct imxdi_dev *imxdi, u32 dsr)
{
u32 dcr;
dev_dbg(&imxdi->pdev->dev, "DSR register reports: %08X\n", dsr);
di_report_tamper_info(imxdi, dsr);
dcr = readl(imxdi->ioaddr + DCR);
if (dcr & DCR_FSHL) {
di_what_is_to_be_done(imxdi, "battery");
return -ENODEV;
}
di_what_is_to_be_done(imxdi, "main");
return -ENODEV;
}
static int di_handle_valid_state(struct imxdi_dev *imxdi, u32 dsr)
{
di_write_busy_wait(imxdi, DCAMR_UNSET, DCAMR);
di_write_busy_wait(imxdi, 0, DCALR);
if (dsr & DSR_CAF)
di_write_busy_wait(imxdi, DSR_CAF, DSR);
return 0;
}
static int di_handle_invalid_state(struct imxdi_dev *imxdi, u32 dsr)
{
u32 dcr, sec;
di_write_busy_wait(imxdi, 0x00000000, DTCR);
di_write_busy_wait(imxdi, DCR_TDCSL, DCR);
sec = readl(imxdi->ioaddr + DTCMR);
if (sec != 0)
dev_warn(&imxdi->pdev->dev,
"The security violation has happened at %u seconds\n",
sec);
dcr = readl(imxdi->ioaddr + DCR);
if (!(dcr & DCR_TCE)) {
if (dcr & DCR_TCHL) {
di_what_is_to_be_done(imxdi, "battery");
return -ENODEV;
}
if (dcr & DCR_TCSL) {
di_what_is_to_be_done(imxdi, "main");
return -ENODEV;
}
}
di_write_busy_wait(imxdi, DSR_NVF, DSR);
di_write_busy_wait(imxdi, DSR_TCO, DSR);
di_write_busy_wait(imxdi, dcr | DCR_TCE, DCR);
di_write_busy_wait(imxdi, sec, DTCMR);
return di_handle_valid_state(imxdi, __raw_readl(imxdi->ioaddr + DSR));
}
static int di_handle_invalid_and_failure_state(struct imxdi_dev *imxdi, u32 dsr)
{
u32 dcr;
if (dsr & (DSR_WTD | DSR_ETBD | DSR_ETAD | DSR_EBD | DSR_SAD |
DSR_TTD | DSR_CTD | DSR_VTD | DSR_MCO | DSR_TCO)) {
dcr = __raw_readl(imxdi->ioaddr + DCR);
if (dcr & DCR_TDCHL) {
di_what_is_to_be_done(imxdi, "battery");
return -ENODEV;
}
if (dcr & DCR_TDCSL) {
di_what_is_to_be_done(imxdi, "main");
return -ENODEV;
}
}
di_write_busy_wait(imxdi, 0x00000000, DTCR);
di_write_busy_wait(imxdi, dsr & (DSR_WTD | DSR_ETBD | DSR_ETAD |
DSR_EBD | DSR_SAD | DSR_TTD | DSR_CTD | DSR_VTD |
DSR_MCO | DSR_TCO), DSR);
dsr = readl(imxdi->ioaddr + DSR);
if ((dsr & ~(DSR_NVF | DSR_SVF | DSR_WBF | DSR_WNF |
DSR_WCF | DSR_WEF)) != 0)
dev_warn(&imxdi->pdev->dev,
"There are still some sources of pain in DSR: %08x!\n",
dsr & ~(DSR_NVF | DSR_SVF | DSR_WBF | DSR_WNF |
DSR_WCF | DSR_WEF));
di_write_busy_wait(imxdi, DSR_SVF, DSR);
dsr = readl(imxdi->ioaddr + DSR);
if (dsr & DSR_SVF) {
dev_crit(&imxdi->pdev->dev,
"Cannot clear the security violation flag. We are ending up in an endless loop!\n");
di_what_is_to_be_done(imxdi, "battery");
return -ENODEV;
}
return di_handle_invalid_state(imxdi, dsr);
}
static int di_handle_state(struct imxdi_dev *imxdi)
{
int rc;
u32 dsr;
dsr = readl(imxdi->ioaddr + DSR);
switch (dsr & (DSR_NVF | DSR_SVF)) {
case DSR_NVF:
dev_warn(&imxdi->pdev->dev, "Invalid stated unit detected\n");
rc = di_handle_invalid_state(imxdi, dsr);
break;
case DSR_SVF:
dev_warn(&imxdi->pdev->dev, "Failure stated unit detected\n");
rc = di_handle_failure_state(imxdi, dsr);
break;
case DSR_NVF | DSR_SVF:
dev_warn(&imxdi->pdev->dev,
"Failure+Invalid stated unit detected\n");
rc = di_handle_invalid_and_failure_state(imxdi, dsr);
break;
default:
dev_notice(&imxdi->pdev->dev, "Unlocked unit detected\n");
rc = di_handle_valid_state(imxdi, dsr);
}
return rc;
}
static void di_int_enable(struct imxdi_dev *imxdi, u32 intr)
{
unsigned long flags;
spin_lock_irqsave(&imxdi->irq_lock, flags);
writel(readl(imxdi->ioaddr + DIER) | intr,
imxdi->ioaddr + DIER);
spin_unlock_irqrestore(&imxdi->irq_lock, flags);
}
static void di_int_disable(struct imxdi_dev *imxdi, u32 intr)
{
unsigned long flags;
spin_lock_irqsave(&imxdi->irq_lock, flags);
writel(readl(imxdi->ioaddr + DIER) & ~intr,
imxdi->ioaddr + DIER);
spin_unlock_irqrestore(&imxdi->irq_lock, flags);
}
static void clear_write_error(struct imxdi_dev *imxdi)
{
int cnt;
dev_warn(&imxdi->pdev->dev, "WARNING: Register write error!\n");
writel(DSR_WEF, imxdi->ioaddr + DSR);
for (cnt = 0; cnt < 1000; cnt++) {
if ((readl(imxdi->ioaddr + DSR) & DSR_WEF) == 0)
return;
udelay(10);
}
dev_err(&imxdi->pdev->dev,
"ERROR: Cannot clear write-error flag!\n");
}
static int di_write_wait(struct imxdi_dev *imxdi, u32 val, int reg)
{
int ret;
int rc = 0;
mutex_lock(&imxdi->write_mutex);
di_int_enable(imxdi, DIER_WCIE);
imxdi->dsr = 0;
writel(val, imxdi->ioaddr + reg);
ret = wait_event_interruptible_timeout(imxdi->write_wait,
imxdi->dsr & (DSR_WCF | DSR_WEF), msecs_to_jiffies(1));
if (ret < 0) {
rc = ret;
goto out;
} else if (ret == 0) {
dev_warn(&imxdi->pdev->dev,
"Write-wait timeout "
"val = 0x%08x reg = 0x%08x\n", val, reg);
}
if (imxdi->dsr & DSR_WEF) {
clear_write_error(imxdi);
rc = -EIO;
}
out:
mutex_unlock(&imxdi->write_mutex);
return rc;
}
static int dryice_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct imxdi_dev *imxdi = dev_get_drvdata(dev);
unsigned long now;
now = readl(imxdi->ioaddr + DTCMR);
rtc_time_to_tm(now, tm);
return 0;
}
static int dryice_rtc_set_mmss(struct device *dev, unsigned long secs)
{
struct imxdi_dev *imxdi = dev_get_drvdata(dev);
u32 dcr, dsr;
int rc;
dcr = readl(imxdi->ioaddr + DCR);
dsr = readl(imxdi->ioaddr + DSR);
if (!(dcr & DCR_TCE) || (dsr & DSR_SVF)) {
if (dcr & DCR_TCHL) {
di_what_is_to_be_done(imxdi, "battery");
return -EPERM;
}
if ((dcr & DCR_TCSL) || (dsr & DSR_SVF)) {
di_what_is_to_be_done(imxdi, "main");
return -EPERM;
}
}
rc = di_write_wait(imxdi, 0, DTCLR);
if (rc != 0)
return rc;
rc = di_write_wait(imxdi, secs, DTCMR);
if (rc != 0)
return rc;
return di_write_wait(imxdi, readl(imxdi->ioaddr + DCR) | DCR_TCE, DCR);
}
static int dryice_rtc_alarm_irq_enable(struct device *dev,
unsigned int enabled)
{
struct imxdi_dev *imxdi = dev_get_drvdata(dev);
if (enabled)
di_int_enable(imxdi, DIER_CAIE);
else
di_int_disable(imxdi, DIER_CAIE);
return 0;
}
static int dryice_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct imxdi_dev *imxdi = dev_get_drvdata(dev);
u32 dcamr;
dcamr = readl(imxdi->ioaddr + DCAMR);
rtc_time_to_tm(dcamr, &alarm->time);
alarm->enabled = (readl(imxdi->ioaddr + DIER) & DIER_CAIE) != 0;
mutex_lock(&imxdi->write_mutex);
alarm->pending = (readl(imxdi->ioaddr + DSR) & DSR_CAF) != 0;
mutex_unlock(&imxdi->write_mutex);
return 0;
}
static int dryice_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alarm)
{
struct imxdi_dev *imxdi = dev_get_drvdata(dev);
unsigned long now;
unsigned long alarm_time;
int rc;
rc = rtc_tm_to_time(&alarm->time, &alarm_time);
if (rc)
return rc;
now = readl(imxdi->ioaddr + DTCMR);
if (alarm_time < now)
return -EINVAL;
rc = di_write_wait(imxdi, (u32)alarm_time, DCAMR);
if (rc)
return rc;
if (alarm->enabled)
di_int_enable(imxdi, DIER_CAIE);
else
di_int_disable(imxdi, DIER_CAIE);
return 0;
}
static irqreturn_t dryice_norm_irq(int irq, void *dev_id)
{
struct imxdi_dev *imxdi = dev_id;
u32 dsr, dier;
irqreturn_t rc = IRQ_NONE;
dier = readl(imxdi->ioaddr + DIER);
dsr = readl(imxdi->ioaddr + DSR);
if (dier & DIER_SVIE) {
if (dsr & DSR_SVF) {
di_int_disable(imxdi, DIER_SVIE);
di_report_tamper_info(imxdi, dsr);
rc = IRQ_HANDLED;
}
}
if (dier & DIER_WCIE) {
if (list_empty_careful(&imxdi->write_wait.task_list))
return rc;
if (dsr & (DSR_WCF | DSR_WEF)) {
di_int_disable(imxdi, DIER_WCIE);
imxdi->dsr |= dsr;
wake_up_interruptible(&imxdi->write_wait);
rc = IRQ_HANDLED;
}
}
if (dier & DIER_CAIE) {
if (dsr & DSR_CAF) {
di_int_disable(imxdi, DIER_CAIE);
schedule_work(&imxdi->work);
rc = IRQ_HANDLED;
}
}
return rc;
}
static void dryice_work(struct work_struct *work)
{
struct imxdi_dev *imxdi = container_of(work,
struct imxdi_dev, work);
di_write_wait(imxdi, DSR_CAF, DSR);
rtc_update_irq(imxdi->rtc, 1, RTC_AF | RTC_IRQF);
}
static int __init dryice_rtc_probe(struct platform_device *pdev)
{
struct resource *res;
struct imxdi_dev *imxdi;
int rc;
imxdi = devm_kzalloc(&pdev->dev, sizeof(*imxdi), GFP_KERNEL);
if (!imxdi)
return -ENOMEM;
imxdi->pdev = pdev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
imxdi->ioaddr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(imxdi->ioaddr))
return PTR_ERR(imxdi->ioaddr);
spin_lock_init(&imxdi->irq_lock);
imxdi->irq = platform_get_irq(pdev, 0);
if (imxdi->irq < 0)
return imxdi->irq;
init_waitqueue_head(&imxdi->write_wait);
INIT_WORK(&imxdi->work, dryice_work);
mutex_init(&imxdi->write_mutex);
imxdi->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(imxdi->clk))
return PTR_ERR(imxdi->clk);
rc = clk_prepare_enable(imxdi->clk);
if (rc)
return rc;
writel(0, imxdi->ioaddr + DIER);
rc = di_handle_state(imxdi);
if (rc != 0)
goto err;
rc = devm_request_irq(&pdev->dev, imxdi->irq, dryice_norm_irq,
IRQF_SHARED, pdev->name, imxdi);
if (rc) {
dev_warn(&pdev->dev, "interrupt not available.\n");
goto err;
}
platform_set_drvdata(pdev, imxdi);
imxdi->rtc = devm_rtc_device_register(&pdev->dev, pdev->name,
&dryice_rtc_ops, THIS_MODULE);
if (IS_ERR(imxdi->rtc)) {
rc = PTR_ERR(imxdi->rtc);
goto err;
}
return 0;
err:
clk_disable_unprepare(imxdi->clk);
return rc;
}
static int __exit dryice_rtc_remove(struct platform_device *pdev)
{
struct imxdi_dev *imxdi = platform_get_drvdata(pdev);
flush_work(&imxdi->work);
writel(0, imxdi->ioaddr + DIER);
clk_disable_unprepare(imxdi->clk);
return 0;
}
