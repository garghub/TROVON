static inline int is_intr(u8 rtc_intr)
{
if (!(rtc_intr & RTC_IRQF))
return 0;
return rtc_intr & RTC_IRQMASK;
}
static inline unsigned char vrtc_is_updating(void)
{
unsigned char uip;
unsigned long flags;
spin_lock_irqsave(&rtc_lock, flags);
uip = (vrtc_cmos_read(RTC_FREQ_SELECT) & RTC_UIP);
spin_unlock_irqrestore(&rtc_lock, flags);
return uip;
}
static int mrst_read_time(struct device *dev, struct rtc_time *time)
{
unsigned long flags;
if (vrtc_is_updating())
mdelay(20);
spin_lock_irqsave(&rtc_lock, flags);
time->tm_sec = vrtc_cmos_read(RTC_SECONDS);
time->tm_min = vrtc_cmos_read(RTC_MINUTES);
time->tm_hour = vrtc_cmos_read(RTC_HOURS);
time->tm_mday = vrtc_cmos_read(RTC_DAY_OF_MONTH);
time->tm_mon = vrtc_cmos_read(RTC_MONTH);
time->tm_year = vrtc_cmos_read(RTC_YEAR);
spin_unlock_irqrestore(&rtc_lock, flags);
time->tm_year += 72;
time->tm_mon--;
return rtc_valid_tm(time);
}
static int mrst_set_time(struct device *dev, struct rtc_time *time)
{
int ret;
unsigned long flags;
unsigned char mon, day, hrs, min, sec;
unsigned int yrs;
yrs = time->tm_year;
mon = time->tm_mon + 1;
day = time->tm_mday;
hrs = time->tm_hour;
min = time->tm_min;
sec = time->tm_sec;
if (yrs < 72 || yrs > 138)
return -EINVAL;
yrs -= 72;
spin_lock_irqsave(&rtc_lock, flags);
vrtc_cmos_write(yrs, RTC_YEAR);
vrtc_cmos_write(mon, RTC_MONTH);
vrtc_cmos_write(day, RTC_DAY_OF_MONTH);
vrtc_cmos_write(hrs, RTC_HOURS);
vrtc_cmos_write(min, RTC_MINUTES);
vrtc_cmos_write(sec, RTC_SECONDS);
spin_unlock_irqrestore(&rtc_lock, flags);
ret = intel_scu_ipc_simple_command(IPCMSG_VRTC, IPC_CMD_VRTC_SETTIME);
return ret;
}
static int mrst_read_alarm(struct device *dev, struct rtc_wkalrm *t)
{
struct mrst_rtc *mrst = dev_get_drvdata(dev);
unsigned char rtc_control;
if (mrst->irq <= 0)
return -EIO;
t->time.tm_mday = -1;
t->time.tm_mon = -1;
t->time.tm_year = -1;
spin_lock_irq(&rtc_lock);
t->time.tm_sec = vrtc_cmos_read(RTC_SECONDS_ALARM);
t->time.tm_min = vrtc_cmos_read(RTC_MINUTES_ALARM);
t->time.tm_hour = vrtc_cmos_read(RTC_HOURS_ALARM);
rtc_control = vrtc_cmos_read(RTC_CONTROL);
spin_unlock_irq(&rtc_lock);
t->enabled = !!(rtc_control & RTC_AIE);
t->pending = 0;
return 0;
}
static void mrst_checkintr(struct mrst_rtc *mrst, unsigned char rtc_control)
{
unsigned char rtc_intr;
rtc_intr = vrtc_cmos_read(RTC_INTR_FLAGS);
rtc_intr &= (rtc_control & RTC_IRQMASK) | RTC_IRQF;
if (is_intr(rtc_intr))
rtc_update_irq(mrst->rtc, 1, rtc_intr);
}
static void mrst_irq_enable(struct mrst_rtc *mrst, unsigned char mask)
{
unsigned char rtc_control;
rtc_control = vrtc_cmos_read(RTC_CONTROL);
mrst_checkintr(mrst, rtc_control);
rtc_control |= mask;
vrtc_cmos_write(rtc_control, RTC_CONTROL);
mrst_checkintr(mrst, rtc_control);
}
static void mrst_irq_disable(struct mrst_rtc *mrst, unsigned char mask)
{
unsigned char rtc_control;
rtc_control = vrtc_cmos_read(RTC_CONTROL);
rtc_control &= ~mask;
vrtc_cmos_write(rtc_control, RTC_CONTROL);
mrst_checkintr(mrst, rtc_control);
}
static int mrst_set_alarm(struct device *dev, struct rtc_wkalrm *t)
{
struct mrst_rtc *mrst = dev_get_drvdata(dev);
unsigned char hrs, min, sec;
int ret = 0;
if (!mrst->irq)
return -EIO;
hrs = t->time.tm_hour;
min = t->time.tm_min;
sec = t->time.tm_sec;
spin_lock_irq(&rtc_lock);
mrst_irq_disable(mrst, RTC_AIE);
vrtc_cmos_write(hrs, RTC_HOURS_ALARM);
vrtc_cmos_write(min, RTC_MINUTES_ALARM);
vrtc_cmos_write(sec, RTC_SECONDS_ALARM);
spin_unlock_irq(&rtc_lock);
ret = intel_scu_ipc_simple_command(IPCMSG_VRTC, IPC_CMD_VRTC_SETALARM);
if (ret)
return ret;
spin_lock_irq(&rtc_lock);
if (t->enabled)
mrst_irq_enable(mrst, RTC_AIE);
spin_unlock_irq(&rtc_lock);
return 0;
}
static int mrst_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct mrst_rtc *mrst = dev_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&rtc_lock, flags);
if (enabled)
mrst_irq_enable(mrst, RTC_AIE);
else
mrst_irq_disable(mrst, RTC_AIE);
spin_unlock_irqrestore(&rtc_lock, flags);
return 0;
}
static int mrst_procfs(struct device *dev, struct seq_file *seq)
{
unsigned char rtc_control, valid;
spin_lock_irq(&rtc_lock);
rtc_control = vrtc_cmos_read(RTC_CONTROL);
valid = vrtc_cmos_read(RTC_VALID);
spin_unlock_irq(&rtc_lock);
seq_printf(seq,
"periodic_IRQ\t: %s\n"
"alarm\t\t: %s\n"
"BCD\t\t: no\n"
"periodic_freq\t: daily (not adjustable)\n",
(rtc_control & RTC_PIE) ? "on" : "off",
(rtc_control & RTC_AIE) ? "on" : "off");
return 0;
}
static irqreturn_t mrst_rtc_irq(int irq, void *p)
{
u8 irqstat;
spin_lock(&rtc_lock);
irqstat = vrtc_cmos_read(RTC_INTR_FLAGS);
spin_unlock(&rtc_lock);
irqstat &= RTC_IRQMASK | RTC_IRQF;
if (is_intr(irqstat)) {
rtc_update_irq(p, 1, irqstat);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int vrtc_mrst_do_probe(struct device *dev, struct resource *iomem,
int rtc_irq)
{
int retval = 0;
unsigned char rtc_control;
if (mrst_rtc.dev)
return -EBUSY;
if (!iomem)
return -ENODEV;
iomem = request_mem_region(iomem->start, resource_size(iomem),
driver_name);
if (!iomem) {
dev_dbg(dev, "i/o mem already in use.\n");
return -EBUSY;
}
mrst_rtc.irq = rtc_irq;
mrst_rtc.iomem = iomem;
mrst_rtc.dev = dev;
dev_set_drvdata(dev, &mrst_rtc);
mrst_rtc.rtc = rtc_device_register(driver_name, dev,
&mrst_rtc_ops, THIS_MODULE);
if (IS_ERR(mrst_rtc.rtc)) {
retval = PTR_ERR(mrst_rtc.rtc);
goto cleanup0;
}
rename_region(iomem, dev_name(&mrst_rtc.rtc->dev));
spin_lock_irq(&rtc_lock);
mrst_irq_disable(&mrst_rtc, RTC_PIE | RTC_AIE);
rtc_control = vrtc_cmos_read(RTC_CONTROL);
spin_unlock_irq(&rtc_lock);
if (!(rtc_control & RTC_24H) || (rtc_control & (RTC_DM_BINARY)))
dev_dbg(dev, "TODO: support more than 24-hr BCD mode\n");
if (rtc_irq) {
retval = request_irq(rtc_irq, mrst_rtc_irq,
0, dev_name(&mrst_rtc.rtc->dev),
mrst_rtc.rtc);
if (retval < 0) {
dev_dbg(dev, "IRQ %d is already in use, err %d\n",
rtc_irq, retval);
goto cleanup1;
}
}
dev_dbg(dev, "initialised\n");
return 0;
cleanup1:
rtc_device_unregister(mrst_rtc.rtc);
cleanup0:
mrst_rtc.dev = NULL;
release_mem_region(iomem->start, resource_size(iomem));
dev_err(dev, "rtc-mrst: unable to initialise\n");
return retval;
}
static void rtc_mrst_do_shutdown(void)
{
spin_lock_irq(&rtc_lock);
mrst_irq_disable(&mrst_rtc, RTC_IRQMASK);
spin_unlock_irq(&rtc_lock);
}
static void rtc_mrst_do_remove(struct device *dev)
{
struct mrst_rtc *mrst = dev_get_drvdata(dev);
struct resource *iomem;
rtc_mrst_do_shutdown();
if (mrst->irq)
free_irq(mrst->irq, mrst->rtc);
rtc_device_unregister(mrst->rtc);
mrst->rtc = NULL;
iomem = mrst->iomem;
release_mem_region(iomem->start, resource_size(iomem));
mrst->iomem = NULL;
mrst->dev = NULL;
}
static int mrst_suspend(struct device *dev)
{
struct mrst_rtc *mrst = dev_get_drvdata(dev);
unsigned char tmp;
spin_lock_irq(&rtc_lock);
mrst->suspend_ctrl = tmp = vrtc_cmos_read(RTC_CONTROL);
if (tmp & (RTC_PIE | RTC_AIE)) {
unsigned char mask;
if (device_may_wakeup(dev))
mask = RTC_IRQMASK & ~RTC_AIE;
else
mask = RTC_IRQMASK;
tmp &= ~mask;
vrtc_cmos_write(tmp, RTC_CONTROL);
mrst_checkintr(mrst, tmp);
}
spin_unlock_irq(&rtc_lock);
if (tmp & RTC_AIE) {
mrst->enabled_wake = 1;
enable_irq_wake(mrst->irq);
}
dev_dbg(&mrst_rtc.rtc->dev, "suspend%s, ctrl %02x\n",
(tmp & RTC_AIE) ? ", alarm may wake" : "",
tmp);
return 0;
}
static inline int mrst_poweroff(struct device *dev)
{
return mrst_suspend(dev);
}
static int mrst_resume(struct device *dev)
{
struct mrst_rtc *mrst = dev_get_drvdata(dev);
unsigned char tmp = mrst->suspend_ctrl;
if (tmp & RTC_IRQMASK) {
unsigned char mask;
if (mrst->enabled_wake) {
disable_irq_wake(mrst->irq);
mrst->enabled_wake = 0;
}
spin_lock_irq(&rtc_lock);
do {
vrtc_cmos_write(tmp, RTC_CONTROL);
mask = vrtc_cmos_read(RTC_INTR_FLAGS);
mask &= (tmp & RTC_IRQMASK) | RTC_IRQF;
if (!is_intr(mask))
break;
rtc_update_irq(mrst->rtc, 1, mask);
tmp &= ~RTC_AIE;
} while (mask & RTC_AIE);
spin_unlock_irq(&rtc_lock);
}
dev_dbg(&mrst_rtc.rtc->dev, "resume, ctrl %02x\n", tmp);
return 0;
}
static inline int mrst_poweroff(struct device *dev)
{
return -ENOSYS;
}
static int vrtc_mrst_platform_probe(struct platform_device *pdev)
{
return vrtc_mrst_do_probe(&pdev->dev,
platform_get_resource(pdev, IORESOURCE_MEM, 0),
platform_get_irq(pdev, 0));
}
static int vrtc_mrst_platform_remove(struct platform_device *pdev)
{
rtc_mrst_do_remove(&pdev->dev);
return 0;
}
static void vrtc_mrst_platform_shutdown(struct platform_device *pdev)
{
if (system_state == SYSTEM_POWER_OFF && !mrst_poweroff(&pdev->dev))
return;
rtc_mrst_do_shutdown();
}
