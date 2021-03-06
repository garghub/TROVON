static inline int is_intr(u8 rtc_intr)
{
if (!(rtc_intr & RTC_IRQF))
return 0;
return rtc_intr & RTC_IRQMASK;
}
static inline int is_hpet_enabled(void)
{
return 0;
}
static inline int hpet_mask_rtc_irq_bit(unsigned long mask)
{
return 0;
}
static inline int hpet_set_rtc_irq_bit(unsigned long mask)
{
return 0;
}
static inline int
hpet_set_alarm_time(unsigned char hrs, unsigned char min, unsigned char sec)
{
return 0;
}
static inline int hpet_set_periodic_freq(unsigned long freq)
{
return 0;
}
static inline int hpet_rtc_dropped_irq(void)
{
return 0;
}
static inline int hpet_rtc_timer_init(void)
{
return 0;
}
static inline int hpet_register_irq_handler(irq_handler_t handler)
{
return 0;
}
static inline int hpet_unregister_irq_handler(irq_handler_t handler)
{
return 0;
}
static inline unsigned char cmos_read_bank2(unsigned char addr)
{
outb(addr, RTC_PORT(2));
return inb(RTC_PORT(3));
}
static inline void cmos_write_bank2(unsigned char val, unsigned char addr)
{
outb(addr, RTC_PORT(2));
outb(val, RTC_PORT(3));
}
static inline unsigned char cmos_read_bank2(unsigned char addr)
{
return 0;
}
static inline void cmos_write_bank2(unsigned char val, unsigned char addr)
{
}
static int cmos_read_time(struct device *dev, struct rtc_time *t)
{
get_rtc_time(t);
return 0;
}
static int cmos_set_time(struct device *dev, struct rtc_time *t)
{
return set_rtc_time(t);
}
static int cmos_read_alarm(struct device *dev, struct rtc_wkalrm *t)
{
struct cmos_rtc *cmos = dev_get_drvdata(dev);
unsigned char rtc_control;
if (!is_valid_irq(cmos->irq))
return -EIO;
t->time.tm_mday = -1;
t->time.tm_mon = -1;
spin_lock_irq(&rtc_lock);
t->time.tm_sec = CMOS_READ(RTC_SECONDS_ALARM);
t->time.tm_min = CMOS_READ(RTC_MINUTES_ALARM);
t->time.tm_hour = CMOS_READ(RTC_HOURS_ALARM);
if (cmos->day_alrm) {
t->time.tm_mday = CMOS_READ(cmos->day_alrm) & 0x3f;
if (!t->time.tm_mday)
t->time.tm_mday = -1;
if (cmos->mon_alrm) {
t->time.tm_mon = CMOS_READ(cmos->mon_alrm);
if (!t->time.tm_mon)
t->time.tm_mon = -1;
}
}
rtc_control = CMOS_READ(RTC_CONTROL);
spin_unlock_irq(&rtc_lock);
if (!(rtc_control & RTC_DM_BINARY) || RTC_ALWAYS_BCD) {
if (((unsigned)t->time.tm_sec) < 0x60)
t->time.tm_sec = bcd2bin(t->time.tm_sec);
else
t->time.tm_sec = -1;
if (((unsigned)t->time.tm_min) < 0x60)
t->time.tm_min = bcd2bin(t->time.tm_min);
else
t->time.tm_min = -1;
if (((unsigned)t->time.tm_hour) < 0x24)
t->time.tm_hour = bcd2bin(t->time.tm_hour);
else
t->time.tm_hour = -1;
if (cmos->day_alrm) {
if (((unsigned)t->time.tm_mday) <= 0x31)
t->time.tm_mday = bcd2bin(t->time.tm_mday);
else
t->time.tm_mday = -1;
if (cmos->mon_alrm) {
if (((unsigned)t->time.tm_mon) <= 0x12)
t->time.tm_mon = bcd2bin(t->time.tm_mon)-1;
else
t->time.tm_mon = -1;
}
}
}
t->time.tm_year = -1;
t->enabled = !!(rtc_control & RTC_AIE);
t->pending = 0;
return 0;
}
static void cmos_checkintr(struct cmos_rtc *cmos, unsigned char rtc_control)
{
unsigned char rtc_intr;
rtc_intr = CMOS_READ(RTC_INTR_FLAGS);
if (is_hpet_enabled())
return;
rtc_intr &= (rtc_control & RTC_IRQMASK) | RTC_IRQF;
if (is_intr(rtc_intr))
rtc_update_irq(cmos->rtc, 1, rtc_intr);
}
static void cmos_irq_enable(struct cmos_rtc *cmos, unsigned char mask)
{
unsigned char rtc_control;
rtc_control = CMOS_READ(RTC_CONTROL);
cmos_checkintr(cmos, rtc_control);
rtc_control |= mask;
CMOS_WRITE(rtc_control, RTC_CONTROL);
hpet_set_rtc_irq_bit(mask);
cmos_checkintr(cmos, rtc_control);
}
static void cmos_irq_disable(struct cmos_rtc *cmos, unsigned char mask)
{
unsigned char rtc_control;
rtc_control = CMOS_READ(RTC_CONTROL);
rtc_control &= ~mask;
CMOS_WRITE(rtc_control, RTC_CONTROL);
hpet_mask_rtc_irq_bit(mask);
cmos_checkintr(cmos, rtc_control);
}
static int cmos_set_alarm(struct device *dev, struct rtc_wkalrm *t)
{
struct cmos_rtc *cmos = dev_get_drvdata(dev);
unsigned char mon, mday, hrs, min, sec, rtc_control;
if (!is_valid_irq(cmos->irq))
return -EIO;
mon = t->time.tm_mon + 1;
mday = t->time.tm_mday;
hrs = t->time.tm_hour;
min = t->time.tm_min;
sec = t->time.tm_sec;
rtc_control = CMOS_READ(RTC_CONTROL);
if (!(rtc_control & RTC_DM_BINARY) || RTC_ALWAYS_BCD) {
mon = (mon <= 12) ? bin2bcd(mon) : 0xff;
mday = (mday >= 1 && mday <= 31) ? bin2bcd(mday) : 0xff;
hrs = (hrs < 24) ? bin2bcd(hrs) : 0xff;
min = (min < 60) ? bin2bcd(min) : 0xff;
sec = (sec < 60) ? bin2bcd(sec) : 0xff;
}
spin_lock_irq(&rtc_lock);
cmos_irq_disable(cmos, RTC_AIE);
CMOS_WRITE(hrs, RTC_HOURS_ALARM);
CMOS_WRITE(min, RTC_MINUTES_ALARM);
CMOS_WRITE(sec, RTC_SECONDS_ALARM);
if (cmos->day_alrm) {
CMOS_WRITE(mday, cmos->day_alrm);
if (cmos->mon_alrm)
CMOS_WRITE(mon, cmos->mon_alrm);
}
hpet_set_alarm_time(t->time.tm_hour, t->time.tm_min, t->time.tm_sec);
if (t->enabled)
cmos_irq_enable(cmos, RTC_AIE);
spin_unlock_irq(&rtc_lock);
cmos->alarm_expires = rtc_tm_to_time64(&t->time);
return 0;
}
static int cmos_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct cmos_rtc *cmos = dev_get_drvdata(dev);
unsigned long flags;
if (!is_valid_irq(cmos->irq))
return -EINVAL;
spin_lock_irqsave(&rtc_lock, flags);
if (enabled)
cmos_irq_enable(cmos, RTC_AIE);
else
cmos_irq_disable(cmos, RTC_AIE);
spin_unlock_irqrestore(&rtc_lock, flags);
return 0;
}
static int cmos_procfs(struct device *dev, struct seq_file *seq)
{
struct cmos_rtc *cmos = dev_get_drvdata(dev);
unsigned char rtc_control, valid;
spin_lock_irq(&rtc_lock);
rtc_control = CMOS_READ(RTC_CONTROL);
valid = CMOS_READ(RTC_VALID);
spin_unlock_irq(&rtc_lock);
seq_printf(seq,
"periodic_IRQ\t: %s\n"
"update_IRQ\t: %s\n"
"HPET_emulated\t: %s\n"
"BCD\t\t: %s\n"
"DST_enable\t: %s\n"
"periodic_freq\t: %d\n"
"batt_status\t: %s\n",
(rtc_control & RTC_PIE) ? "yes" : "no",
(rtc_control & RTC_UIE) ? "yes" : "no",
is_hpet_enabled() ? "yes" : "no",
(rtc_control & RTC_DM_BINARY) ? "no" : "yes",
(rtc_control & RTC_DST_EN) ? "yes" : "no",
cmos->rtc->irq_freq,
(valid & RTC_VRT) ? "okay" : "dead");
return 0;
}
static ssize_t
cmos_nvram_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t off, size_t count)
{
int retval;
off += NVRAM_OFFSET;
spin_lock_irq(&rtc_lock);
for (retval = 0; count; count--, off++, retval++) {
if (off < 128)
*buf++ = CMOS_READ(off);
else if (can_bank2)
*buf++ = cmos_read_bank2(off);
else
break;
}
spin_unlock_irq(&rtc_lock);
return retval;
}
static ssize_t
cmos_nvram_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *attr,
char *buf, loff_t off, size_t count)
{
struct cmos_rtc *cmos;
int retval;
cmos = dev_get_drvdata(container_of(kobj, struct device, kobj));
off += NVRAM_OFFSET;
spin_lock_irq(&rtc_lock);
for (retval = 0; count; count--, off++, retval++) {
if (off == cmos->day_alrm
|| off == cmos->mon_alrm
|| off == cmos->century)
buf++;
else if (off < 128)
CMOS_WRITE(*buf++, off);
else if (can_bank2)
cmos_write_bank2(*buf++, off);
else
break;
}
spin_unlock_irq(&rtc_lock);
return retval;
}
static irqreturn_t cmos_interrupt(int irq, void *p)
{
u8 irqstat;
u8 rtc_control;
spin_lock(&rtc_lock);
irqstat = CMOS_READ(RTC_INTR_FLAGS);
rtc_control = CMOS_READ(RTC_CONTROL);
if (is_hpet_enabled())
irqstat = (unsigned long)irq & 0xF0;
if (!cmos_rtc.suspend_ctrl)
irqstat &= (rtc_control & RTC_IRQMASK) | RTC_IRQF;
else
irqstat &= (cmos_rtc.suspend_ctrl & RTC_IRQMASK) | RTC_IRQF;
if (irqstat & RTC_AIE) {
cmos_rtc.suspend_ctrl &= ~RTC_AIE;
rtc_control &= ~RTC_AIE;
CMOS_WRITE(rtc_control, RTC_CONTROL);
hpet_mask_rtc_irq_bit(RTC_AIE);
CMOS_READ(RTC_INTR_FLAGS);
}
spin_unlock(&rtc_lock);
if (is_intr(irqstat)) {
rtc_update_irq(p, 1, irqstat);
return IRQ_HANDLED;
} else
return IRQ_NONE;
}
static int INITSECTION
cmos_do_probe(struct device *dev, struct resource *ports, int rtc_irq)
{
struct cmos_rtc_board_info *info = dev_get_platdata(dev);
int retval = 0;
unsigned char rtc_control;
unsigned address_space;
u32 flags = 0;
if (cmos_rtc.dev)
return -EBUSY;
if (!ports)
return -ENODEV;
if (RTC_IOMAPPED)
ports = request_region(ports->start, resource_size(ports),
driver_name);
else
ports = request_mem_region(ports->start, resource_size(ports),
driver_name);
if (!ports) {
dev_dbg(dev, "i/o registers already in use\n");
return -EBUSY;
}
cmos_rtc.irq = rtc_irq;
cmos_rtc.iomem = ports;
#if defined(CONFIG_ATARI)
address_space = 64;
#elif defined(__i386__) || defined(__x86_64__) || defined(__arm__) \
|| defined(__sparc__) || defined(__mips__) \
|| defined(__powerpc__)
address_space = 128;
#else
#warning Assuming 128 bytes of RTC+NVRAM address space, not 64 bytes.
address_space = 128;
#endif
if (can_bank2 && ports->end > (ports->start + 1))
address_space = 256;
if (info) {
if (info->flags)
flags = info->flags;
if (info->address_space)
address_space = info->address_space;
if (info->rtc_day_alarm && info->rtc_day_alarm < 128)
cmos_rtc.day_alrm = info->rtc_day_alarm;
if (info->rtc_mon_alarm && info->rtc_mon_alarm < 128)
cmos_rtc.mon_alrm = info->rtc_mon_alarm;
if (info->rtc_century && info->rtc_century < 128)
cmos_rtc.century = info->rtc_century;
if (info->wake_on && info->wake_off) {
cmos_rtc.wake_on = info->wake_on;
cmos_rtc.wake_off = info->wake_off;
}
}
cmos_rtc.dev = dev;
dev_set_drvdata(dev, &cmos_rtc);
cmos_rtc.rtc = rtc_device_register(driver_name, dev,
&cmos_rtc_ops, THIS_MODULE);
if (IS_ERR(cmos_rtc.rtc)) {
retval = PTR_ERR(cmos_rtc.rtc);
goto cleanup0;
}
rename_region(ports, dev_name(&cmos_rtc.rtc->dev));
spin_lock_irq(&rtc_lock);
if (!(flags & CMOS_RTC_FLAGS_NOFREQ)) {
cmos_rtc.rtc->irq_freq = 1024;
hpet_set_periodic_freq(cmos_rtc.rtc->irq_freq);
CMOS_WRITE(RTC_REF_CLCK_32KHZ | 0x06, RTC_FREQ_SELECT);
}
if (is_valid_irq(rtc_irq))
cmos_irq_disable(&cmos_rtc, RTC_PIE | RTC_AIE | RTC_UIE);
rtc_control = CMOS_READ(RTC_CONTROL);
spin_unlock_irq(&rtc_lock);
if (is_valid_irq(rtc_irq) && !(rtc_control & RTC_24H)) {
dev_warn(dev, "only 24-hr supported\n");
retval = -ENXIO;
goto cleanup1;
}
if (is_valid_irq(rtc_irq)) {
irq_handler_t rtc_cmos_int_handler;
if (is_hpet_enabled()) {
rtc_cmos_int_handler = hpet_rtc_interrupt;
retval = hpet_register_irq_handler(cmos_interrupt);
if (retval) {
dev_warn(dev, "hpet_register_irq_handler "
" failed in rtc_init().");
goto cleanup1;
}
} else
rtc_cmos_int_handler = cmos_interrupt;
retval = request_irq(rtc_irq, rtc_cmos_int_handler,
IRQF_SHARED, dev_name(&cmos_rtc.rtc->dev),
cmos_rtc.rtc);
if (retval < 0) {
dev_dbg(dev, "IRQ %d is already in use\n", rtc_irq);
goto cleanup1;
}
}
hpet_rtc_timer_init();
nvram.size = address_space - NVRAM_OFFSET;
retval = sysfs_create_bin_file(&dev->kobj, &nvram);
if (retval < 0) {
dev_dbg(dev, "can't create nvram file? %d\n", retval);
goto cleanup2;
}
dev_info(dev, "%s%s, %zd bytes nvram%s\n",
!is_valid_irq(rtc_irq) ? "no alarms" :
cmos_rtc.mon_alrm ? "alarms up to one year" :
cmos_rtc.day_alrm ? "alarms up to one month" :
"alarms up to one day",
cmos_rtc.century ? ", y3k" : "",
nvram.size,
is_hpet_enabled() ? ", hpet irqs" : "");
return 0;
cleanup2:
if (is_valid_irq(rtc_irq))
free_irq(rtc_irq, cmos_rtc.rtc);
cleanup1:
cmos_rtc.dev = NULL;
rtc_device_unregister(cmos_rtc.rtc);
cleanup0:
if (RTC_IOMAPPED)
release_region(ports->start, resource_size(ports));
else
release_mem_region(ports->start, resource_size(ports));
return retval;
}
static void cmos_do_shutdown(int rtc_irq)
{
spin_lock_irq(&rtc_lock);
if (is_valid_irq(rtc_irq))
cmos_irq_disable(&cmos_rtc, RTC_IRQMASK);
spin_unlock_irq(&rtc_lock);
}
static void __exit cmos_do_remove(struct device *dev)
{
struct cmos_rtc *cmos = dev_get_drvdata(dev);
struct resource *ports;
cmos_do_shutdown(cmos->irq);
sysfs_remove_bin_file(&dev->kobj, &nvram);
if (is_valid_irq(cmos->irq)) {
free_irq(cmos->irq, cmos->rtc);
hpet_unregister_irq_handler(cmos_interrupt);
}
rtc_device_unregister(cmos->rtc);
cmos->rtc = NULL;
ports = cmos->iomem;
if (RTC_IOMAPPED)
release_region(ports->start, resource_size(ports));
else
release_mem_region(ports->start, resource_size(ports));
cmos->iomem = NULL;
cmos->dev = NULL;
}
static int cmos_aie_poweroff(struct device *dev)
{
struct cmos_rtc *cmos = dev_get_drvdata(dev);
struct rtc_time now;
time64_t t_now;
int retval = 0;
unsigned char rtc_control;
if (!cmos->alarm_expires)
return -EINVAL;
spin_lock_irq(&rtc_lock);
rtc_control = CMOS_READ(RTC_CONTROL);
spin_unlock_irq(&rtc_lock);
if (rtc_control & RTC_AIE)
return -EBUSY;
cmos_read_time(dev, &now);
t_now = rtc_tm_to_time64(&now);
if (cmos->alarm_expires == t_now + 1) {
struct rtc_wkalrm alarm;
rtc_time64_to_tm(t_now - 1, &alarm.time);
alarm.enabled = 0;
retval = cmos_set_alarm(dev, &alarm);
} else if (cmos->alarm_expires > t_now + 1) {
retval = -EBUSY;
}
return retval;
}
static int cmos_suspend(struct device *dev)
{
struct cmos_rtc *cmos = dev_get_drvdata(dev);
unsigned char tmp;
spin_lock_irq(&rtc_lock);
cmos->suspend_ctrl = tmp = CMOS_READ(RTC_CONTROL);
if (tmp & (RTC_PIE|RTC_AIE|RTC_UIE)) {
unsigned char mask;
if (device_may_wakeup(dev))
mask = RTC_IRQMASK & ~RTC_AIE;
else
mask = RTC_IRQMASK;
tmp &= ~mask;
CMOS_WRITE(tmp, RTC_CONTROL);
hpet_mask_rtc_irq_bit(mask);
cmos_checkintr(cmos, tmp);
}
spin_unlock_irq(&rtc_lock);
if (tmp & RTC_AIE) {
cmos->enabled_wake = 1;
if (cmos->wake_on)
cmos->wake_on(dev);
else
enable_irq_wake(cmos->irq);
}
dev_dbg(dev, "suspend%s, ctrl %02x\n",
(tmp & RTC_AIE) ? ", alarm may wake" : "",
tmp);
return 0;
}
static inline int cmos_poweroff(struct device *dev)
{
return cmos_suspend(dev);
}
static int cmos_resume(struct device *dev)
{
struct cmos_rtc *cmos = dev_get_drvdata(dev);
unsigned char tmp;
if (cmos->enabled_wake) {
if (cmos->wake_off)
cmos->wake_off(dev);
else
disable_irq_wake(cmos->irq);
cmos->enabled_wake = 0;
}
spin_lock_irq(&rtc_lock);
tmp = cmos->suspend_ctrl;
cmos->suspend_ctrl = 0;
if (tmp & RTC_IRQMASK) {
unsigned char mask;
if (device_may_wakeup(dev))
hpet_rtc_timer_init();
do {
CMOS_WRITE(tmp, RTC_CONTROL);
hpet_set_rtc_irq_bit(tmp & RTC_IRQMASK);
mask = CMOS_READ(RTC_INTR_FLAGS);
mask &= (tmp & RTC_IRQMASK) | RTC_IRQF;
if (!is_hpet_enabled() || !is_intr(mask))
break;
rtc_update_irq(cmos->rtc, 1, mask);
tmp &= ~RTC_AIE;
hpet_mask_rtc_irq_bit(RTC_AIE);
} while (mask & RTC_AIE);
}
spin_unlock_irq(&rtc_lock);
dev_dbg(dev, "resume, ctrl %02x\n", tmp);
return 0;
}
static inline int cmos_poweroff(struct device *dev)
{
return -ENOSYS;
}
static u32 rtc_handler(void *context)
{
struct device *dev = context;
pm_wakeup_event(dev, 0);
acpi_clear_event(ACPI_EVENT_RTC);
acpi_disable_event(ACPI_EVENT_RTC, 0);
return ACPI_INTERRUPT_HANDLED;
}
static inline void rtc_wake_setup(struct device *dev)
{
acpi_install_fixed_event_handler(ACPI_EVENT_RTC, rtc_handler, dev);
acpi_clear_event(ACPI_EVENT_RTC);
acpi_disable_event(ACPI_EVENT_RTC, 0);
}
static void rtc_wake_on(struct device *dev)
{
acpi_clear_event(ACPI_EVENT_RTC);
acpi_enable_event(ACPI_EVENT_RTC, 0);
}
static void rtc_wake_off(struct device *dev)
{
acpi_disable_event(ACPI_EVENT_RTC, 0);
}
static void cmos_wake_setup(struct device *dev)
{
if (acpi_disabled)
return;
rtc_wake_setup(dev);
acpi_rtc_info.wake_on = rtc_wake_on;
acpi_rtc_info.wake_off = rtc_wake_off;
if (acpi_gbl_FADT.month_alarm && !acpi_gbl_FADT.day_alarm) {
dev_dbg(dev, "bogus FADT month_alarm (%d)\n",
acpi_gbl_FADT.month_alarm);
acpi_gbl_FADT.month_alarm = 0;
}
acpi_rtc_info.rtc_day_alarm = acpi_gbl_FADT.day_alarm;
acpi_rtc_info.rtc_mon_alarm = acpi_gbl_FADT.month_alarm;
acpi_rtc_info.rtc_century = acpi_gbl_FADT.century;
if (acpi_gbl_FADT.flags & ACPI_FADT_S4_RTC_WAKE)
dev_info(dev, "RTC can wake from S4\n");
dev->platform_data = &acpi_rtc_info;
device_init_wakeup(dev, 1);
}
static void cmos_wake_setup(struct device *dev)
{
}
static int cmos_pnp_probe(struct pnp_dev *pnp, const struct pnp_device_id *id)
{
cmos_wake_setup(&pnp->dev);
if (pnp_port_start(pnp, 0) == 0x70 && !pnp_irq_valid(pnp, 0))
return cmos_do_probe(&pnp->dev,
pnp_get_resource(pnp, IORESOURCE_IO, 0), 8);
else
return cmos_do_probe(&pnp->dev,
pnp_get_resource(pnp, IORESOURCE_IO, 0),
pnp_irq(pnp, 0));
}
static void __exit cmos_pnp_remove(struct pnp_dev *pnp)
{
cmos_do_remove(&pnp->dev);
}
static void cmos_pnp_shutdown(struct pnp_dev *pnp)
{
struct device *dev = &pnp->dev;
struct cmos_rtc *cmos = dev_get_drvdata(dev);
if (system_state == SYSTEM_POWER_OFF) {
int retval = cmos_poweroff(dev);
if (cmos_aie_poweroff(dev) < 0 && !retval)
return;
}
cmos_do_shutdown(cmos->irq);
}
static __init void cmos_of_init(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct rtc_time time;
int ret;
const __be32 *val;
if (!node)
return;
val = of_get_property(node, "ctrl-reg", NULL);
if (val)
CMOS_WRITE(be32_to_cpup(val), RTC_CONTROL);
val = of_get_property(node, "freq-reg", NULL);
if (val)
CMOS_WRITE(be32_to_cpup(val), RTC_FREQ_SELECT);
get_rtc_time(&time);
ret = rtc_valid_tm(&time);
if (ret) {
struct rtc_time def_time = {
.tm_year = 1,
.tm_mday = 1,
};
set_rtc_time(&def_time);
}
}
static inline void cmos_of_init(struct platform_device *pdev) {}
static int __init cmos_platform_probe(struct platform_device *pdev)
{
struct resource *resource;
int irq;
cmos_of_init(pdev);
cmos_wake_setup(&pdev->dev);
if (RTC_IOMAPPED)
resource = platform_get_resource(pdev, IORESOURCE_IO, 0);
else
resource = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (irq < 0)
irq = -1;
return cmos_do_probe(&pdev->dev, resource, irq);
}
static int __exit cmos_platform_remove(struct platform_device *pdev)
{
cmos_do_remove(&pdev->dev);
return 0;
}
static void cmos_platform_shutdown(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct cmos_rtc *cmos = dev_get_drvdata(dev);
if (system_state == SYSTEM_POWER_OFF) {
int retval = cmos_poweroff(dev);
if (cmos_aie_poweroff(dev) < 0 && !retval)
return;
}
cmos_do_shutdown(cmos->irq);
}
static int __init cmos_init(void)
{
int retval = 0;
#ifdef CONFIG_PNP
retval = pnp_register_driver(&cmos_pnp_driver);
if (retval == 0)
pnp_driver_registered = true;
#endif
if (!cmos_rtc.dev) {
retval = platform_driver_probe(&cmos_platform_driver,
cmos_platform_probe);
if (retval == 0)
platform_driver_registered = true;
}
if (retval == 0)
return 0;
#ifdef CONFIG_PNP
if (pnp_driver_registered)
pnp_unregister_driver(&cmos_pnp_driver);
#endif
return retval;
}
static void __exit cmos_exit(void)
{
#ifdef CONFIG_PNP
if (pnp_driver_registered)
pnp_unregister_driver(&cmos_pnp_driver);
#endif
if (platform_driver_registered)
platform_driver_unregister(&cmos_platform_driver);
}
