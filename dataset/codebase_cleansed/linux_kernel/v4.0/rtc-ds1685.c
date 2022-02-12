static u8
ds1685_read(struct ds1685_priv *rtc, int reg)
{
return readb((u8 __iomem *)rtc->regs +
(reg * rtc->regstep));
}
static void
ds1685_write(struct ds1685_priv *rtc, int reg, u8 value)
{
writeb(value, ((u8 __iomem *)rtc->regs +
(reg * rtc->regstep)));
}
static inline u8
ds1685_rtc_bcd2bin(struct ds1685_priv *rtc, u8 val, u8 bcd_mask, u8 bin_mask)
{
if (rtc->bcd_mode)
return (bcd2bin(val) & bcd_mask);
return (val & bin_mask);
}
static inline u8
ds1685_rtc_bin2bcd(struct ds1685_priv *rtc, u8 val, u8 bin_mask, u8 bcd_mask)
{
if (rtc->bcd_mode)
return (bin2bcd(val) & bcd_mask);
return (val & bin_mask);
}
static inline void
ds1685_rtc_switch_to_bank0(struct ds1685_priv *rtc)
{
rtc->write(rtc, RTC_CTRL_A,
(rtc->read(rtc, RTC_CTRL_A) & ~(RTC_CTRL_A_DV0)));
}
static inline void
ds1685_rtc_switch_to_bank1(struct ds1685_priv *rtc)
{
rtc->write(rtc, RTC_CTRL_A,
(rtc->read(rtc, RTC_CTRL_A) | RTC_CTRL_A_DV0));
}
static inline void
ds1685_rtc_begin_data_access(struct ds1685_priv *rtc)
{
rtc->write(rtc, RTC_CTRL_B,
(rtc->read(rtc, RTC_CTRL_B) | RTC_CTRL_B_SET));
while (rtc->read(rtc, RTC_EXT_CTRL_4A) & RTC_CTRL_4A_INCR)
cpu_relax();
ds1685_rtc_switch_to_bank1(rtc);
}
static inline void
ds1685_rtc_end_data_access(struct ds1685_priv *rtc)
{
ds1685_rtc_switch_to_bank1(rtc);
rtc->write(rtc, RTC_CTRL_B,
(rtc->read(rtc, RTC_CTRL_B) & ~(RTC_CTRL_B_SET)));
}
static inline void
ds1685_rtc_begin_ctrl_access(struct ds1685_priv *rtc, unsigned long flags)
{
spin_lock_irqsave(&rtc->lock, flags);
ds1685_rtc_switch_to_bank1(rtc);
}
static inline void
ds1685_rtc_end_ctrl_access(struct ds1685_priv *rtc, unsigned long flags)
{
ds1685_rtc_switch_to_bank0(rtc);
spin_unlock_irqrestore(&rtc->lock, flags);
}
static inline void
ds1685_rtc_get_ssn(struct ds1685_priv *rtc, u8 *ssn)
{
ssn[0] = rtc->read(rtc, RTC_BANK1_SSN_MODEL);
ssn[1] = rtc->read(rtc, RTC_BANK1_SSN_BYTE_1);
ssn[2] = rtc->read(rtc, RTC_BANK1_SSN_BYTE_2);
ssn[3] = rtc->read(rtc, RTC_BANK1_SSN_BYTE_3);
ssn[4] = rtc->read(rtc, RTC_BANK1_SSN_BYTE_4);
ssn[5] = rtc->read(rtc, RTC_BANK1_SSN_BYTE_5);
ssn[6] = rtc->read(rtc, RTC_BANK1_SSN_BYTE_6);
ssn[7] = rtc->read(rtc, RTC_BANK1_SSN_CRC);
}
static int
ds1685_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
struct platform_device *pdev = to_platform_device(dev);
struct ds1685_priv *rtc = platform_get_drvdata(pdev);
u8 ctrlb, century;
u8 seconds, minutes, hours, wday, mday, month, years;
ds1685_rtc_begin_data_access(rtc);
seconds = rtc->read(rtc, RTC_SECS);
minutes = rtc->read(rtc, RTC_MINS);
hours = rtc->read(rtc, RTC_HRS);
wday = rtc->read(rtc, RTC_WDAY);
mday = rtc->read(rtc, RTC_MDAY);
month = rtc->read(rtc, RTC_MONTH);
years = rtc->read(rtc, RTC_YEAR);
century = rtc->read(rtc, RTC_CENTURY);
ctrlb = rtc->read(rtc, RTC_CTRL_B);
ds1685_rtc_end_data_access(rtc);
years = ds1685_rtc_bcd2bin(rtc, years, RTC_YEAR_BCD_MASK,
RTC_YEAR_BIN_MASK);
century = ds1685_rtc_bcd2bin(rtc, century, RTC_CENTURY_MASK,
RTC_CENTURY_MASK);
tm->tm_sec = ds1685_rtc_bcd2bin(rtc, seconds, RTC_SECS_BCD_MASK,
RTC_SECS_BIN_MASK);
tm->tm_min = ds1685_rtc_bcd2bin(rtc, minutes, RTC_MINS_BCD_MASK,
RTC_MINS_BIN_MASK);
tm->tm_hour = ds1685_rtc_bcd2bin(rtc, hours, RTC_HRS_24_BCD_MASK,
RTC_HRS_24_BIN_MASK);
tm->tm_wday = (ds1685_rtc_bcd2bin(rtc, wday, RTC_WDAY_MASK,
RTC_WDAY_MASK) - 1);
tm->tm_mday = ds1685_rtc_bcd2bin(rtc, mday, RTC_MDAY_BCD_MASK,
RTC_MDAY_BIN_MASK);
tm->tm_mon = (ds1685_rtc_bcd2bin(rtc, month, RTC_MONTH_BCD_MASK,
RTC_MONTH_BIN_MASK) - 1);
tm->tm_year = ((years + (century * 100)) - 1900);
tm->tm_yday = rtc_year_days(tm->tm_mday, tm->tm_mon, tm->tm_year);
tm->tm_isdst = 0;
return rtc_valid_tm(tm);
}
static int
ds1685_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
struct platform_device *pdev = to_platform_device(dev);
struct ds1685_priv *rtc = platform_get_drvdata(pdev);
u8 ctrlb, seconds, minutes, hours, wday, mday, month, years, century;
seconds = ds1685_rtc_bin2bcd(rtc, tm->tm_sec, RTC_SECS_BIN_MASK,
RTC_SECS_BCD_MASK);
minutes = ds1685_rtc_bin2bcd(rtc, tm->tm_min, RTC_MINS_BIN_MASK,
RTC_MINS_BCD_MASK);
hours = ds1685_rtc_bin2bcd(rtc, tm->tm_hour, RTC_HRS_24_BIN_MASK,
RTC_HRS_24_BCD_MASK);
wday = ds1685_rtc_bin2bcd(rtc, (tm->tm_wday + 1), RTC_WDAY_MASK,
RTC_WDAY_MASK);
mday = ds1685_rtc_bin2bcd(rtc, tm->tm_mday, RTC_MDAY_BIN_MASK,
RTC_MDAY_BCD_MASK);
month = ds1685_rtc_bin2bcd(rtc, (tm->tm_mon + 1), RTC_MONTH_BIN_MASK,
RTC_MONTH_BCD_MASK);
years = ds1685_rtc_bin2bcd(rtc, (tm->tm_year % 100),
RTC_YEAR_BIN_MASK, RTC_YEAR_BCD_MASK);
century = ds1685_rtc_bin2bcd(rtc, ((tm->tm_year + 1900) / 100),
RTC_CENTURY_MASK, RTC_CENTURY_MASK);
if ((tm->tm_mon > 11) || (mday == 0))
return -EDOM;
if (tm->tm_mday > rtc_month_days(tm->tm_mon, tm->tm_year))
return -EDOM;
if ((tm->tm_hour >= 24) || (tm->tm_min >= 60) ||
(tm->tm_sec >= 60) || (wday > 7))
return -EDOM;
ds1685_rtc_begin_data_access(rtc);
ctrlb = rtc->read(rtc, RTC_CTRL_B);
if (rtc->bcd_mode)
ctrlb &= ~(RTC_CTRL_B_DM);
else
ctrlb |= RTC_CTRL_B_DM;
rtc->write(rtc, RTC_CTRL_B, ctrlb);
rtc->write(rtc, RTC_SECS, seconds);
rtc->write(rtc, RTC_MINS, minutes);
rtc->write(rtc, RTC_HRS, hours);
rtc->write(rtc, RTC_WDAY, wday);
rtc->write(rtc, RTC_MDAY, mday);
rtc->write(rtc, RTC_MONTH, month);
rtc->write(rtc, RTC_YEAR, years);
rtc->write(rtc, RTC_CENTURY, century);
ds1685_rtc_end_data_access(rtc);
return 0;
}
static int
ds1685_rtc_read_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct platform_device *pdev = to_platform_device(dev);
struct ds1685_priv *rtc = platform_get_drvdata(pdev);
u8 seconds, minutes, hours, mday, ctrlb, ctrlc;
ds1685_rtc_begin_data_access(rtc);
seconds = rtc->read(rtc, RTC_SECS_ALARM);
minutes = rtc->read(rtc, RTC_MINS_ALARM);
hours = rtc->read(rtc, RTC_HRS_ALARM);
mday = rtc->read(rtc, RTC_MDAY_ALARM);
ctrlb = rtc->read(rtc, RTC_CTRL_B);
ctrlc = rtc->read(rtc, RTC_CTRL_C);
ds1685_rtc_end_data_access(rtc);
if (!(mday >= 1) && (mday <= 31))
return -EDOM;
if (unlikely(seconds >= 0xc0))
alrm->time.tm_sec = -1;
else
alrm->time.tm_sec = ds1685_rtc_bcd2bin(rtc, seconds,
RTC_SECS_BCD_MASK,
RTC_SECS_BIN_MASK);
if (unlikely(minutes >= 0xc0))
alrm->time.tm_min = -1;
else
alrm->time.tm_min = ds1685_rtc_bcd2bin(rtc, minutes,
RTC_MINS_BCD_MASK,
RTC_MINS_BIN_MASK);
if (unlikely(hours >= 0xc0))
alrm->time.tm_hour = -1;
else
alrm->time.tm_hour = ds1685_rtc_bcd2bin(rtc, hours,
RTC_HRS_24_BCD_MASK,
RTC_HRS_24_BIN_MASK);
alrm->time.tm_mday = ds1685_rtc_bcd2bin(rtc, mday, RTC_MDAY_BCD_MASK,
RTC_MDAY_BIN_MASK);
alrm->time.tm_mon = -1;
alrm->time.tm_year = -1;
alrm->time.tm_wday = -1;
alrm->time.tm_yday = -1;
alrm->time.tm_isdst = -1;
alrm->enabled = !!(ctrlb & RTC_CTRL_B_AIE);
alrm->pending = !!(ctrlc & RTC_CTRL_C_AF);
return 0;
}
static int
ds1685_rtc_set_alarm(struct device *dev, struct rtc_wkalrm *alrm)
{
struct platform_device *pdev = to_platform_device(dev);
struct ds1685_priv *rtc = platform_get_drvdata(pdev);
u8 ctrlb, seconds, minutes, hours, mday;
seconds = ds1685_rtc_bin2bcd(rtc, alrm->time.tm_sec,
RTC_SECS_BIN_MASK,
RTC_SECS_BCD_MASK);
minutes = ds1685_rtc_bin2bcd(rtc, alrm->time.tm_min,
RTC_MINS_BIN_MASK,
RTC_MINS_BCD_MASK);
hours = ds1685_rtc_bin2bcd(rtc, alrm->time.tm_hour,
RTC_HRS_24_BIN_MASK,
RTC_HRS_24_BCD_MASK);
mday = ds1685_rtc_bin2bcd(rtc, alrm->time.tm_mday,
RTC_MDAY_BIN_MASK,
RTC_MDAY_BCD_MASK);
if (!(mday >= 1) && (mday <= 31))
return -EDOM;
if (unlikely(seconds >= 0xc0))
seconds = 0xff;
if (unlikely(minutes >= 0xc0))
minutes = 0xff;
if (unlikely(hours >= 0xc0))
hours = 0xff;
alrm->time.tm_mon = -1;
alrm->time.tm_year = -1;
alrm->time.tm_wday = -1;
alrm->time.tm_yday = -1;
alrm->time.tm_isdst = -1;
ds1685_rtc_begin_data_access(rtc);
ctrlb = rtc->read(rtc, RTC_CTRL_B);
rtc->write(rtc, RTC_CTRL_B, (ctrlb & ~(RTC_CTRL_B_AIE)));
rtc->read(rtc, RTC_CTRL_C);
ctrlb = rtc->read(rtc, RTC_CTRL_B);
if (rtc->bcd_mode)
ctrlb &= ~(RTC_CTRL_B_DM);
else
ctrlb |= RTC_CTRL_B_DM;
rtc->write(rtc, RTC_CTRL_B, ctrlb);
rtc->write(rtc, RTC_SECS_ALARM, seconds);
rtc->write(rtc, RTC_MINS_ALARM, minutes);
rtc->write(rtc, RTC_HRS_ALARM, hours);
rtc->write(rtc, RTC_MDAY_ALARM, mday);
if (alrm->enabled) {
ctrlb = rtc->read(rtc, RTC_CTRL_B);
ctrlb |= RTC_CTRL_B_AIE;
rtc->write(rtc, RTC_CTRL_B, ctrlb);
}
ds1685_rtc_end_data_access(rtc);
return 0;
}
static int
ds1685_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
struct ds1685_priv *rtc = dev_get_drvdata(dev);
unsigned long flags = 0;
spin_lock_irqsave(&rtc->lock, flags);
if (enabled)
rtc->write(rtc, RTC_CTRL_B, (rtc->read(rtc, RTC_CTRL_B) |
RTC_CTRL_B_AIE));
else
rtc->write(rtc, RTC_CTRL_B, (rtc->read(rtc, RTC_CTRL_B) &
~(RTC_CTRL_B_AIE)));
rtc->read(rtc, RTC_CTRL_C);
spin_unlock_irqrestore(&rtc->lock, flags);
return 0;
}
static irqreturn_t
ds1685_rtc_irq_handler(int irq, void *dev_id)
{
struct platform_device *pdev = dev_id;
struct ds1685_priv *rtc = platform_get_drvdata(pdev);
u8 ctrlb, ctrlc;
unsigned long events = 0;
u8 num_irqs = 0;
if (unlikely(!rtc))
return IRQ_HANDLED;
spin_lock(&rtc->lock);
ctrlb = rtc->read(rtc, RTC_CTRL_B);
ctrlc = rtc->read(rtc, RTC_CTRL_C);
if (likely(ctrlc & RTC_CTRL_C_IRQF)) {
if (likely(ctrlc & RTC_CTRL_B_PAU_MASK)) {
events = RTC_IRQF;
if ((ctrlb & RTC_CTRL_B_PIE) &&
(ctrlc & RTC_CTRL_C_PF)) {
events |= RTC_PF;
num_irqs++;
}
if ((ctrlb & RTC_CTRL_B_AIE) &&
(ctrlc & RTC_CTRL_C_AF)) {
events |= RTC_AF;
num_irqs++;
}
if ((ctrlb & RTC_CTRL_B_UIE) &&
(ctrlc & RTC_CTRL_C_UF)) {
events |= RTC_UF;
num_irqs++;
}
rtc_update_irq(rtc->dev, num_irqs, events);
} else {
spin_unlock(&rtc->lock);
schedule_work(&rtc->work);
rtc_update_irq(rtc->dev, 0, 0);
return IRQ_HANDLED;
}
}
spin_unlock(&rtc->lock);
return events ? IRQ_HANDLED : IRQ_NONE;
}
static void
ds1685_rtc_work_queue(struct work_struct *work)
{
struct ds1685_priv *rtc = container_of(work,
struct ds1685_priv, work);
struct platform_device *pdev = to_platform_device(&rtc->dev->dev);
struct mutex *rtc_mutex = &rtc->dev->ops_lock;
u8 ctrl4a, ctrl4b;
mutex_lock(rtc_mutex);
ds1685_rtc_switch_to_bank1(rtc);
ctrl4a = rtc->read(rtc, RTC_EXT_CTRL_4A);
ctrl4b = rtc->read(rtc, RTC_EXT_CTRL_4B);
if ((ctrl4b & RTC_CTRL_4B_KSE) && (ctrl4a & RTC_CTRL_4A_KF)) {
rtc->write(rtc, RTC_EXT_CTRL_4B,
(rtc->read(rtc, RTC_EXT_CTRL_4B) &
~(RTC_CTRL_4B_KSE)));
rtc->write(rtc, RTC_EXT_CTRL_4A,
(ctrl4a & ~(RTC_CTRL_4A_KF)));
msleep(500);
rtc->write(rtc, RTC_EXT_CTRL_4B,
(rtc->read(rtc, RTC_EXT_CTRL_4B) |
RTC_CTRL_4B_KSE));
if (rtc->prepare_poweroff != NULL)
rtc->prepare_poweroff();
else
ds1685_rtc_poweroff(pdev);
}
if ((ctrl4b & RTC_CTRL_4B_WIE) && (ctrl4a & RTC_CTRL_4A_WF)) {
rtc->write(rtc, RTC_EXT_CTRL_4A,
(ctrl4a & ~(RTC_CTRL_4A_WF)));
if (rtc->wake_alarm != NULL)
rtc->wake_alarm();
else
dev_warn(&pdev->dev,
"Wake Alarm IRQ just occurred!\n");
}
if ((ctrl4b & RTC_CTRL_4B_RIE) && (ctrl4a & RTC_CTRL_4A_RF)) {
rtc->write(rtc, RTC_EXT_CTRL_4A,
(ctrl4a & ~(RTC_CTRL_4A_RF)));
msleep(150);
if (rtc->post_ram_clear != NULL)
rtc->post_ram_clear();
else
dev_warn(&pdev->dev,
"RAM-Clear IRQ just occurred!\n");
}
ds1685_rtc_switch_to_bank0(rtc);
mutex_unlock(rtc_mutex);
}
static char*
ds1685_rtc_print_regs(u8 hex, char *dest)
{
u32 i, j;
char *tmp = dest;
for (i = 0; i < NUM_BITS; i++) {
*tmp++ = ((hex & 0x80) != 0 ? '1' : '0');
for (j = 0; j < NUM_SPACES; j++)
*tmp++ = ' ';
hex <<= 1;
}
*tmp++ = '\0';
return dest;
}
static int
ds1685_rtc_proc(struct device *dev, struct seq_file *seq)
{
struct platform_device *pdev = to_platform_device(dev);
struct ds1685_priv *rtc = platform_get_drvdata(pdev);
u8 ctrla, ctrlb, ctrlc, ctrld, ctrl4a, ctrl4b, ssn[8];
char *model = '\0';
#ifdef CONFIG_RTC_DS1685_PROC_REGS
char bits[NUM_REGS][(NUM_BITS * NUM_SPACES) + NUM_BITS + 1];
#endif
ds1685_rtc_switch_to_bank1(rtc);
ds1685_rtc_get_ssn(rtc, ssn);
ctrla = rtc->read(rtc, RTC_CTRL_A);
ctrlb = rtc->read(rtc, RTC_CTRL_B);
ctrlc = rtc->read(rtc, RTC_CTRL_C);
ctrld = rtc->read(rtc, RTC_CTRL_D);
ctrl4a = rtc->read(rtc, RTC_EXT_CTRL_4A);
ctrl4b = rtc->read(rtc, RTC_EXT_CTRL_4B);
ds1685_rtc_switch_to_bank0(rtc);
switch (ssn[0]) {
case RTC_MODEL_DS1685:
model = "DS1685/DS1687\0";
break;
case RTC_MODEL_DS1689:
model = "DS1689/DS1693\0";
break;
case RTC_MODEL_DS17285:
model = "DS17285/DS17287\0";
break;
case RTC_MODEL_DS17485:
model = "DS17485/DS17487\0";
break;
case RTC_MODEL_DS17885:
model = "DS17885/DS17887\0";
break;
default:
model = "Unknown\0";
break;
}
seq_printf(seq,
"Model\t\t: %s\n"
"Oscillator\t: %s\n"
"12/24hr\t\t: %s\n"
"DST\t\t: %s\n"
"Data mode\t: %s\n"
"Battery\t\t: %s\n"
"Aux batt\t: %s\n"
"Update IRQ\t: %s\n"
"Periodic IRQ\t: %s\n"
"Periodic Rate\t: %s\n"
"SQW Freq\t: %s\n"
#ifdef CONFIG_RTC_DS1685_PROC_REGS
"Serial #\t: %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x\n"
"Register Status\t:\n"
" Ctrl A\t: UIP DV2 DV1 DV0 RS3 RS2 RS1 RS0\n"
"\t\t: %s\n"
" Ctrl B\t: SET PIE AIE UIE SQWE DM 2412 DSE\n"
"\t\t: %s\n"
" Ctrl C\t: IRQF PF AF UF --- --- --- ---\n"
"\t\t: %s\n"
" Ctrl D\t: VRT --- --- --- --- --- --- ---\n"
"\t\t: %s\n"
#if !defined(CONFIG_RTC_DRV_DS1685) && !defined(CONFIG_RTC_DRV_DS1689)
" Ctrl 4A\t: VRT2 INCR BME --- PAB RF WF KF\n"
#else
" Ctrl 4A\t: VRT2 INCR --- --- PAB RF WF KF\n"
#endif
"\t\t: %s\n"
" Ctrl 4B\t: ABE E32k CS RCE PRS RIE WIE KSE\n"
"\t\t: %s\n",
#else
"Serial #\t: %02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x\n",
#endif
model,
((ctrla & RTC_CTRL_A_DV1) ? "enabled" : "disabled"),
((ctrlb & RTC_CTRL_B_2412) ? "24-hour" : "12-hour"),
((ctrlb & RTC_CTRL_B_DSE) ? "enabled" : "disabled"),
((ctrlb & RTC_CTRL_B_DM) ? "binary" : "BCD"),
((ctrld & RTC_CTRL_D_VRT) ? "ok" : "exhausted or n/a"),
((ctrl4a & RTC_CTRL_4A_VRT2) ? "ok" : "exhausted or n/a"),
((ctrlb & RTC_CTRL_B_UIE) ? "yes" : "no"),
((ctrlb & RTC_CTRL_B_PIE) ? "yes" : "no"),
(!(ctrl4b & RTC_CTRL_4B_E32K) ?
ds1685_rtc_pirq_rate[(ctrla & RTC_CTRL_A_RS_MASK)] : "none"),
(!((ctrl4b & RTC_CTRL_4B_E32K)) ?
ds1685_rtc_sqw_freq[(ctrla & RTC_CTRL_A_RS_MASK)] : "32768Hz"),
#ifdef CONFIG_RTC_DS1685_PROC_REGS
ssn[0], ssn[1], ssn[2], ssn[3], ssn[4], ssn[5], ssn[6], ssn[7],
ds1685_rtc_print_regs(ctrla, bits[0]),
ds1685_rtc_print_regs(ctrlb, bits[1]),
ds1685_rtc_print_regs(ctrlc, bits[2]),
ds1685_rtc_print_regs(ctrld, bits[3]),
ds1685_rtc_print_regs(ctrl4a, bits[4]),
ds1685_rtc_print_regs(ctrl4b, bits[5]));
#else
ssn[0], ssn[1], ssn[2], ssn[3], ssn[4], ssn[5], ssn[6], ssn[7]);
static ssize_t
ds1685_rtc_sysfs_nvram_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t pos, size_t size)
{
struct platform_device *pdev =
to_platform_device(container_of(kobj, struct device, kobj));
struct ds1685_priv *rtc = platform_get_drvdata(pdev);
ssize_t count;
unsigned long flags = 0;
spin_lock_irqsave(&rtc->lock, flags);
ds1685_rtc_switch_to_bank0(rtc);
for (count = 0; size > 0 && pos < NVRAM_TOTAL_SZ_BANK0;
count++, size--) {
if (count < NVRAM_SZ_TIME)
*buf++ = rtc->read(rtc, (NVRAM_TIME_BASE + pos++));
else
*buf++ = rtc->read(rtc, (NVRAM_BANK0_BASE + pos++));
}
#ifndef CONFIG_RTC_DRV_DS1689
if (size > 0) {
ds1685_rtc_switch_to_bank1(rtc);
#ifndef CONFIG_RTC_DRV_DS1685
rtc->write(rtc, RTC_EXT_CTRL_4A,
(rtc->read(rtc, RTC_EXT_CTRL_4A) |
RTC_CTRL_4A_BME));
rtc->write(rtc, RTC_BANK1_RAM_ADDR_LSB,
(pos - NVRAM_TOTAL_SZ_BANK0));
#endif
for (count = 0; size > 0 && pos < NVRAM_TOTAL_SZ;
count++, size--) {
#ifdef CONFIG_RTC_DRV_DS1685
rtc->write(rtc, RTC_BANK1_RAM_ADDR,
(pos - NVRAM_TOTAL_SZ_BANK0));
#endif
*buf++ = rtc->read(rtc, RTC_BANK1_RAM_DATA_PORT);
pos++;
}
#ifndef CONFIG_RTC_DRV_DS1685
rtc->write(rtc, RTC_EXT_CTRL_4A,
(rtc->read(rtc, RTC_EXT_CTRL_4A) &
~(RTC_CTRL_4A_BME)));
#endif
ds1685_rtc_switch_to_bank0(rtc);
}
#endif
spin_unlock_irqrestore(&rtc->lock, flags);
return count;
}
static ssize_t
ds1685_rtc_sysfs_nvram_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t pos, size_t size)
{
struct platform_device *pdev =
to_platform_device(container_of(kobj, struct device, kobj));
struct ds1685_priv *rtc = platform_get_drvdata(pdev);
ssize_t count;
unsigned long flags = 0;
spin_lock_irqsave(&rtc->lock, flags);
ds1685_rtc_switch_to_bank0(rtc);
for (count = 0; size > 0 && pos < NVRAM_TOTAL_SZ_BANK0;
count++, size--)
if (count < NVRAM_SZ_TIME)
rtc->write(rtc, (NVRAM_TIME_BASE + pos++),
*buf++);
else
rtc->write(rtc, (NVRAM_BANK0_BASE), *buf++);
#ifndef CONFIG_RTC_DRV_DS1689
if (size > 0) {
ds1685_rtc_switch_to_bank1(rtc);
#ifndef CONFIG_RTC_DRV_DS1685
rtc->write(rtc, RTC_EXT_CTRL_4A,
(rtc->read(rtc, RTC_EXT_CTRL_4A) |
RTC_CTRL_4A_BME));
rtc->write(rtc, RTC_BANK1_RAM_ADDR_LSB,
(pos - NVRAM_TOTAL_SZ_BANK0));
#endif
for (count = 0; size > 0 && pos < NVRAM_TOTAL_SZ;
count++, size--) {
#ifdef CONFIG_RTC_DRV_DS1685
rtc->write(rtc, RTC_BANK1_RAM_ADDR,
(pos - NVRAM_TOTAL_SZ_BANK0));
#endif
rtc->write(rtc, RTC_BANK1_RAM_DATA_PORT, *buf++);
pos++;
}
#ifndef CONFIG_RTC_DRV_DS1685
rtc->write(rtc, RTC_EXT_CTRL_4A,
(rtc->read(rtc, RTC_EXT_CTRL_4A) &
~(RTC_CTRL_4A_BME)));
#endif
ds1685_rtc_switch_to_bank0(rtc);
}
#endif
spin_unlock_irqrestore(&rtc->lock, flags);
return count;
}
static ssize_t
ds1685_rtc_sysfs_battery_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct platform_device *pdev = to_platform_device(dev);
struct ds1685_priv *rtc = platform_get_drvdata(pdev);
u8 ctrld;
ctrld = rtc->read(rtc, RTC_CTRL_D);
return snprintf(buf, 13, "%s\n",
(ctrld & RTC_CTRL_D_VRT) ? "ok" : "not ok or N/A");
}
static ssize_t
ds1685_rtc_sysfs_auxbatt_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct platform_device *pdev = to_platform_device(dev);
struct ds1685_priv *rtc = platform_get_drvdata(pdev);
u8 ctrl4a;
ds1685_rtc_switch_to_bank1(rtc);
ctrl4a = rtc->read(rtc, RTC_EXT_CTRL_4A);
ds1685_rtc_switch_to_bank0(rtc);
return snprintf(buf, 13, "%s\n",
(ctrl4a & RTC_CTRL_4A_VRT2) ? "ok" : "not ok or N/A");
}
static ssize_t
ds1685_rtc_sysfs_serial_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct platform_device *pdev = to_platform_device(dev);
struct ds1685_priv *rtc = platform_get_drvdata(pdev);
u8 ssn[8];
ds1685_rtc_switch_to_bank1(rtc);
ds1685_rtc_get_ssn(rtc, ssn);
ds1685_rtc_switch_to_bank0(rtc);
return snprintf(buf, 24, "%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x\n",
ssn[0], ssn[1], ssn[2], ssn[3], ssn[4], ssn[5],
ssn[6], ssn[7]);
return 0;
}
static const struct ds1685_rtc_ctrl_regs*
ds1685_rtc_sysfs_ctrl_regs_lookup(const char *name)
{
const struct ds1685_rtc_ctrl_regs *p = ds1685_ctrl_regs_table;
for (; p->name != NULL; ++p)
if (strcmp(p->name, name) == 0)
return p;
return NULL;
}
static ssize_t
ds1685_rtc_sysfs_ctrl_regs_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
u8 tmp;
struct ds1685_priv *rtc = dev_get_drvdata(dev);
const struct ds1685_rtc_ctrl_regs *reg_info =
ds1685_rtc_sysfs_ctrl_regs_lookup(attr->attr.name);
if (!reg_info)
return -EINVAL;
ds1685_rtc_switch_to_bank1(rtc);
tmp = rtc->read(rtc, reg_info->reg) & reg_info->bit;
ds1685_rtc_switch_to_bank0(rtc);
return snprintf(buf, 2, "%d\n", (tmp ? 1 : 0));
}
static ssize_t
ds1685_rtc_sysfs_ctrl_regs_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ds1685_priv *rtc = dev_get_drvdata(dev);
u8 reg = 0, bit = 0, tmp;
unsigned long flags = 0;
long int val = 0;
const struct ds1685_rtc_ctrl_regs *reg_info =
ds1685_rtc_sysfs_ctrl_regs_lookup(attr->attr.name);
if (kstrtol(buf, 10, &val) < 0)
return -EINVAL;
if ((val != 0) && (val != 1))
return -ERANGE;
if (!reg_info)
return -EINVAL;
reg = reg_info->reg;
bit = reg_info->bit;
ds1685_rtc_begin_ctrl_access(rtc, flags);
tmp = rtc->read(rtc, reg);
rtc->write(rtc, reg, (val ? (tmp | bit) : (tmp & ~(bit))));
ds1685_rtc_end_ctrl_access(rtc, flags);
return count;
}
static const struct ds1685_rtc_time_regs*
ds1685_rtc_sysfs_time_regs_lookup(const char *name, bool bcd_mode)
{
const struct ds1685_rtc_time_regs *p;
if (bcd_mode)
p = ds1685_time_regs_bcd_table;
else
p = ds1685_time_regs_bin_table;
for (; p->name != NULL; ++p)
if (strcmp(p->name, name) == 0)
return p;
return NULL;
}
static ssize_t
ds1685_rtc_sysfs_time_regs_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
u8 tmp;
struct ds1685_priv *rtc = dev_get_drvdata(dev);
const struct ds1685_rtc_time_regs *bcd_reg_info =
ds1685_rtc_sysfs_time_regs_lookup(attr->attr.name, true);
const struct ds1685_rtc_time_regs *bin_reg_info =
ds1685_rtc_sysfs_time_regs_lookup(attr->attr.name, false);
if (!bcd_reg_info || !bin_reg_info)
return -EINVAL;
ds1685_rtc_begin_data_access(rtc);
tmp = rtc->read(rtc, bcd_reg_info->reg);
ds1685_rtc_end_data_access(rtc);
tmp = ds1685_rtc_bcd2bin(rtc, tmp, bcd_reg_info->mask,
bin_reg_info->mask);
return snprintf(buf, 4, "%d\n", tmp);
}
static ssize_t
ds1685_rtc_sysfs_time_regs_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
long int val = 0;
struct ds1685_priv *rtc = dev_get_drvdata(dev);
const struct ds1685_rtc_time_regs *bcd_reg_info =
ds1685_rtc_sysfs_time_regs_lookup(attr->attr.name, true);
const struct ds1685_rtc_time_regs *bin_reg_info =
ds1685_rtc_sysfs_time_regs_lookup(attr->attr.name, false);
if (kstrtol(buf, 10, &val) < 0)
return -EINVAL;
if (!bcd_reg_info || !bin_reg_info)
return -EINVAL;
if (rtc->bcd_mode) {
if ((val < bcd_reg_info->min) || (val > bcd_reg_info->max))
return -ERANGE;
} else {
if ((val < bin_reg_info->min) || (val > bin_reg_info->max))
return -ERANGE;
}
val = ds1685_rtc_bin2bcd(rtc, val, bin_reg_info->mask,
bcd_reg_info->mask);
ds1685_rtc_begin_data_access(rtc);
rtc->write(rtc, bcd_reg_info->reg, val);
ds1685_rtc_end_data_access(rtc);
return count;
}
static int
ds1685_rtc_sysfs_register(struct device *dev)
{
int ret = 0;
sysfs_bin_attr_init(&ds1685_rtc_sysfs_nvram_attr);
ret = sysfs_create_bin_file(&dev->kobj, &ds1685_rtc_sysfs_nvram_attr);
if (ret)
return ret;
ret = sysfs_create_group(&dev->kobj, &ds1685_rtc_sysfs_misc_grp);
if (ret)
return ret;
#ifdef CONFIG_RTC_DS1685_SYSFS_REGS
ret = sysfs_create_group(&dev->kobj, &ds1685_rtc_sysfs_ctrla_grp);
if (ret)
return ret;
ret = sysfs_create_group(&dev->kobj, &ds1685_rtc_sysfs_ctrlb_grp);
if (ret)
return ret;
ret = sysfs_create_group(&dev->kobj, &ds1685_rtc_sysfs_ctrlc_grp);
if (ret)
return ret;
ret = sysfs_create_group(&dev->kobj, &ds1685_rtc_sysfs_ctrld_grp);
if (ret)
return ret;
ret = sysfs_create_group(&dev->kobj, &ds1685_rtc_sysfs_ctrl4a_grp);
if (ret)
return ret;
ret = sysfs_create_group(&dev->kobj, &ds1685_rtc_sysfs_ctrl4b_grp);
if (ret)
return ret;
ret = sysfs_create_group(&dev->kobj, &ds1685_rtc_sysfs_time_grp);
if (ret)
return ret;
ret = sysfs_create_group(&dev->kobj, &ds1685_rtc_sysfs_alarm_grp);
if (ret)
return ret;
#endif
return 0;
}
static int
ds1685_rtc_sysfs_unregister(struct device *dev)
{
sysfs_remove_bin_file(&dev->kobj, &ds1685_rtc_sysfs_nvram_attr);
sysfs_remove_group(&dev->kobj, &ds1685_rtc_sysfs_misc_grp);
#ifdef CONFIG_RTC_DS1685_SYSFS_REGS
sysfs_remove_group(&dev->kobj, &ds1685_rtc_sysfs_ctrla_grp);
sysfs_remove_group(&dev->kobj, &ds1685_rtc_sysfs_ctrlb_grp);
sysfs_remove_group(&dev->kobj, &ds1685_rtc_sysfs_ctrlc_grp);
sysfs_remove_group(&dev->kobj, &ds1685_rtc_sysfs_ctrld_grp);
sysfs_remove_group(&dev->kobj, &ds1685_rtc_sysfs_ctrl4a_grp);
sysfs_remove_group(&dev->kobj, &ds1685_rtc_sysfs_ctrl4b_grp);
sysfs_remove_group(&dev->kobj, &ds1685_rtc_sysfs_time_grp);
sysfs_remove_group(&dev->kobj, &ds1685_rtc_sysfs_alarm_grp);
#endif
return 0;
}
static int
ds1685_rtc_probe(struct platform_device *pdev)
{
struct rtc_device *rtc_dev;
struct resource *res;
struct ds1685_priv *rtc;
struct ds1685_rtc_platform_data *pdata;
u8 ctrla, ctrlb, hours;
unsigned char am_pm;
int ret = 0;
pdata = (struct ds1685_rtc_platform_data *) pdev->dev.platform_data;
if (!pdata)
return -ENODEV;
rtc = devm_kzalloc(&pdev->dev, sizeof(*rtc), GFP_KERNEL);
if (!rtc)
return -ENOMEM;
if (pdata->alloc_io_resources) {
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENXIO;
rtc->size = resource_size(res);
if (!devm_request_mem_region(&pdev->dev, res->start, rtc->size,
pdev->name))
return -EBUSY;
rtc->baseaddr = res->start;
rtc->regs = devm_ioremap(&pdev->dev, res->start, rtc->size);
if (!rtc->regs)
return -ENOMEM;
}
rtc->alloc_io_resources = pdata->alloc_io_resources;
if (pdata->regstep > 0)
rtc->regstep = pdata->regstep;
else
rtc->regstep = 1;
if (pdata->plat_read)
rtc->read = pdata->plat_read;
else
if (pdata->alloc_io_resources)
rtc->read = ds1685_read;
else
return -ENXIO;
if (pdata->plat_write)
rtc->write = pdata->plat_write;
else
if (pdata->alloc_io_resources)
rtc->write = ds1685_write;
else
return -ENXIO;
if (pdata->plat_prepare_poweroff)
rtc->prepare_poweroff = pdata->plat_prepare_poweroff;
if (pdata->plat_wake_alarm)
rtc->wake_alarm = pdata->plat_wake_alarm;
if (pdata->plat_post_ram_clear)
rtc->post_ram_clear = pdata->plat_post_ram_clear;
spin_lock_init(&rtc->lock);
INIT_WORK(&rtc->work, ds1685_rtc_work_queue);
platform_set_drvdata(pdev, rtc);
ctrla = rtc->read(rtc, RTC_CTRL_A);
if (!(ctrla & RTC_CTRL_A_DV1))
ctrla |= RTC_CTRL_A_DV1;
ctrla &= ~(RTC_CTRL_A_DV2);
ctrla &= ~(RTC_CTRL_A_RS_MASK);
ctrla |= RTC_CTRL_A_DV0;
rtc->write(rtc, RTC_CTRL_A, ctrla);
rtc->write(rtc, RTC_EXT_CTRL_4B,
(rtc->read(rtc, RTC_EXT_CTRL_4B) | RTC_CTRL_4B_E32K));
rtc->write(rtc, RTC_CTRL_B,
(rtc->read(rtc, RTC_CTRL_B) | RTC_CTRL_B_SET));
while (rtc->read(rtc, RTC_EXT_CTRL_4A) & RTC_CTRL_4A_INCR)
cpu_relax();
ctrlb = rtc->read(rtc, RTC_CTRL_B);
if (pdata->bcd_mode)
ctrlb &= ~(RTC_CTRL_B_DM);
else
ctrlb |= RTC_CTRL_B_DM;
rtc->bcd_mode = pdata->bcd_mode;
if (ctrlb & RTC_CTRL_B_DSE)
ctrlb &= ~(RTC_CTRL_B_DSE);
if (!(ctrlb & RTC_CTRL_B_2412)) {
hours = rtc->read(rtc, RTC_HRS);
am_pm = hours & RTC_HRS_AMPM_MASK;
hours = ds1685_rtc_bcd2bin(rtc, hours, RTC_HRS_12_BCD_MASK,
RTC_HRS_12_BIN_MASK);
hours = ((hours == 12) ? 0 : ((am_pm) ? hours + 12 : hours));
ctrlb |= RTC_CTRL_B_2412;
rtc->write(rtc, RTC_CTRL_B, ctrlb);
rtc->write(rtc, RTC_HRS,
ds1685_rtc_bin2bcd(rtc, hours,
RTC_HRS_24_BIN_MASK,
RTC_HRS_24_BCD_MASK));
hours = rtc->read(rtc, RTC_HRS_ALARM);
am_pm = hours & RTC_HRS_AMPM_MASK;
hours = ds1685_rtc_bcd2bin(rtc, hours, RTC_HRS_12_BCD_MASK,
RTC_HRS_12_BIN_MASK);
hours = ((hours == 12) ? 0 : ((am_pm) ? hours + 12 : hours));
rtc->write(rtc, RTC_HRS_ALARM,
ds1685_rtc_bin2bcd(rtc, hours,
RTC_HRS_24_BIN_MASK,
RTC_HRS_24_BCD_MASK));
} else {
rtc->write(rtc, RTC_CTRL_B, ctrlb);
}
rtc->write(rtc, RTC_CTRL_B,
(rtc->read(rtc, RTC_CTRL_B) & ~(RTC_CTRL_B_SET)));
if (!(rtc->read(rtc, RTC_CTRL_D) & RTC_CTRL_D_VRT))
dev_warn(&pdev->dev,
"Main battery is exhausted! RTC may be invalid!\n");
if (!(rtc->read(rtc, RTC_EXT_CTRL_4A) & RTC_CTRL_4A_VRT2))
dev_warn(&pdev->dev,
"Aux battery is exhausted or not available.\n");
rtc->write(rtc, RTC_CTRL_B,
(rtc->read(rtc, RTC_CTRL_B) & ~(RTC_CTRL_B_PAU_MASK)));
rtc->read(rtc, RTC_CTRL_C);
rtc->write(rtc, RTC_EXT_CTRL_4B,
(rtc->read(rtc, RTC_EXT_CTRL_4B) & ~(RTC_CTRL_4B_RWK_MASK)));
rtc->write(rtc, RTC_EXT_CTRL_4A,
(rtc->read(rtc, RTC_EXT_CTRL_4A) & ~(RTC_CTRL_4A_RWK_MASK)));
rtc->write(rtc, RTC_EXT_CTRL_4B,
(rtc->read(rtc, RTC_EXT_CTRL_4B) | RTC_CTRL_4B_KSE));
if (!pdata->no_irq) {
ret = platform_get_irq(pdev, 0);
if (ret > 0) {
rtc->irq_num = ret;
ret = devm_request_irq(&pdev->dev, rtc->irq_num,
ds1685_rtc_irq_handler,
IRQF_SHARED, pdev->name, pdev);
if (unlikely(ret)) {
dev_warn(&pdev->dev,
"RTC interrupt not available\n");
rtc->irq_num = 0;
}
} else
return ret;
}
rtc->no_irq = pdata->no_irq;
ds1685_rtc_switch_to_bank0(rtc);
rtc_dev = rtc_device_register(pdev->name, &pdev->dev,
&ds1685_rtc_ops, THIS_MODULE);
if (IS_ERR(rtc_dev))
return PTR_ERR(rtc_dev);
rtc_dev->max_user_freq = RTC_MAX_USER_FREQ;
if (pdata->uie_unsupported)
rtc_dev->uie_unsupported = 1;
rtc->uie_unsupported = pdata->uie_unsupported;
rtc->dev = rtc_dev;
#ifdef CONFIG_SYSFS
ret = ds1685_rtc_sysfs_register(&pdev->dev);
if (ret)
rtc_device_unregister(rtc->dev);
#endif
return ret;
}
static int
ds1685_rtc_remove(struct platform_device *pdev)
{
struct ds1685_priv *rtc = platform_get_drvdata(pdev);
#ifdef CONFIG_SYSFS
ds1685_rtc_sysfs_unregister(&pdev->dev);
#endif
rtc_device_unregister(rtc->dev);
rtc->write(rtc, RTC_CTRL_B,
(rtc->read(rtc, RTC_CTRL_B) &
~(RTC_CTRL_B_PAU_MASK)));
rtc->read(rtc, RTC_CTRL_C);
rtc->write(rtc, RTC_EXT_CTRL_4B,
(rtc->read(rtc, RTC_EXT_CTRL_4B) &
~(RTC_CTRL_4B_RWK_MASK)));
rtc->write(rtc, RTC_EXT_CTRL_4A,
(rtc->read(rtc, RTC_EXT_CTRL_4A) &
~(RTC_CTRL_4A_RWK_MASK)));
cancel_work_sync(&rtc->work);
return 0;
}
static int __init
ds1685_rtc_init(void)
{
return platform_driver_register(&ds1685_rtc_driver);
}
static void __exit
ds1685_rtc_exit(void)
{
platform_driver_unregister(&ds1685_rtc_driver);
}
extern void __noreturn
ds1685_rtc_poweroff(struct platform_device *pdev)
{
u8 ctrla, ctrl4a, ctrl4b;
struct ds1685_priv *rtc;
if (unlikely(!pdev)) {
pr_emerg("rtc-ds1685: platform device data not available, spinning forever ...\n");
unreachable();
} else {
rtc = platform_get_drvdata(pdev);
if (!rtc->no_irq)
disable_irq_nosync(rtc->irq_num);
ctrla = rtc->read(rtc, RTC_CTRL_A);
ctrla |= RTC_CTRL_A_DV1;
ctrla &= ~(RTC_CTRL_A_DV2);
rtc->write(rtc, RTC_CTRL_A, ctrla);
ds1685_rtc_switch_to_bank1(rtc);
ctrl4a = rtc->read(rtc, RTC_EXT_CTRL_4A);
if (ctrl4a & RTC_CTRL_4A_VRT2) {
ctrl4a &= ~(RTC_CTRL_4A_RWK_MASK);
rtc->write(rtc, RTC_EXT_CTRL_4A, ctrl4a);
ctrl4b = rtc->read(rtc, RTC_EXT_CTRL_4B);
ctrl4b |= (RTC_CTRL_4B_ABE | RTC_CTRL_4B_WIE |
RTC_CTRL_4B_KSE);
rtc->write(rtc, RTC_EXT_CTRL_4B, ctrl4b);
}
dev_warn(&pdev->dev, "Powerdown.\n");
msleep(20);
rtc->write(rtc, RTC_EXT_CTRL_4A,
(ctrl4a | RTC_CTRL_4A_PAB));
unreachable();
}
}
