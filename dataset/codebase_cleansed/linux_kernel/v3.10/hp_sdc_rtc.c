static void hp_sdc_rtc_isr (int irq, void *dev_id,
uint8_t status, uint8_t data)
{
return;
}
static int hp_sdc_rtc_do_read_bbrtc (struct rtc_time *rtctm)
{
struct semaphore tsem;
hp_sdc_transaction t;
uint8_t tseq[91];
int i;
i = 0;
while (i < 91) {
tseq[i++] = HP_SDC_ACT_DATAREG |
HP_SDC_ACT_POSTCMD | HP_SDC_ACT_DATAIN;
tseq[i++] = 0x01;
tseq[i] = i / 7;
i++;
tseq[i++] = HP_SDC_CMD_DO_RTCR;
tseq[i++] = 2;
i++; i++;
}
tseq[84] |= HP_SDC_ACT_SEMAPHORE;
t.endidx = 91;
t.seq = tseq;
t.act.semaphore = &tsem;
sema_init(&tsem, 0);
if (hp_sdc_enqueue_transaction(&t)) return -1;
if (WARN_ON(down_interruptible(&tsem)))
return -1;
if (!((tseq[83] | tseq[90] | tseq[69] | tseq[76] |
tseq[55] | tseq[62] | tseq[34] | tseq[41] |
tseq[20] | tseq[27] | tseq[6] | tseq[13]) & 0x0f))
return -1;
memset(rtctm, 0, sizeof(struct rtc_time));
rtctm->tm_year = (tseq[83] & 0x0f) + (tseq[90] & 0x0f) * 10;
rtctm->tm_mon = (tseq[69] & 0x0f) + (tseq[76] & 0x0f) * 10;
rtctm->tm_mday = (tseq[55] & 0x0f) + (tseq[62] & 0x0f) * 10;
rtctm->tm_wday = (tseq[48] & 0x0f);
rtctm->tm_hour = (tseq[34] & 0x0f) + (tseq[41] & 0x0f) * 10;
rtctm->tm_min = (tseq[20] & 0x0f) + (tseq[27] & 0x0f) * 10;
rtctm->tm_sec = (tseq[6] & 0x0f) + (tseq[13] & 0x0f) * 10;
return 0;
}
static int hp_sdc_rtc_read_bbrtc (struct rtc_time *rtctm)
{
struct rtc_time tm, tm_last;
int i = 0;
if (hp_sdc_rtc_do_read_bbrtc(&tm_last)) return -1;
if (hp_sdc_rtc_do_read_bbrtc(&tm)) return -1;
while (memcmp(&tm, &tm_last, sizeof(struct rtc_time))) {
if (i++ > 4) return -1;
memcpy(&tm_last, &tm, sizeof(struct rtc_time));
if (hp_sdc_rtc_do_read_bbrtc(&tm)) return -1;
}
memcpy(rtctm, &tm, sizeof(struct rtc_time));
return 0;
}
static int64_t hp_sdc_rtc_read_i8042timer (uint8_t loadcmd, int numreg)
{
hp_sdc_transaction t;
uint8_t tseq[26] = {
HP_SDC_ACT_PRECMD | HP_SDC_ACT_POSTCMD | HP_SDC_ACT_DATAIN,
0,
HP_SDC_CMD_READ_T1, 2, 0, 0,
HP_SDC_ACT_POSTCMD | HP_SDC_ACT_DATAIN,
HP_SDC_CMD_READ_T2, 2, 0, 0,
HP_SDC_ACT_POSTCMD | HP_SDC_ACT_DATAIN,
HP_SDC_CMD_READ_T3, 2, 0, 0,
HP_SDC_ACT_POSTCMD | HP_SDC_ACT_DATAIN,
HP_SDC_CMD_READ_T4, 2, 0, 0,
HP_SDC_ACT_POSTCMD | HP_SDC_ACT_DATAIN,
HP_SDC_CMD_READ_T5, 2, 0, 0
};
t.endidx = numreg * 5;
tseq[1] = loadcmd;
tseq[t.endidx - 4] |= HP_SDC_ACT_SEMAPHORE;
t.seq = tseq;
t.act.semaphore = &i8042tregs;
if (WARN_ON(down_interruptible(&i8042tregs)))
return -1;
if (hp_sdc_enqueue_transaction(&t)) return -1;
if (WARN_ON(down_interruptible(&i8042tregs)))
return -1;
up(&i8042tregs);
return (tseq[5] |
((uint64_t)(tseq[10]) << 8) | ((uint64_t)(tseq[15]) << 16) |
((uint64_t)(tseq[20]) << 24) | ((uint64_t)(tseq[25]) << 32));
}
static inline int hp_sdc_rtc_read_rt(struct timeval *res) {
int64_t raw;
uint32_t tenms;
unsigned int days;
raw = hp_sdc_rtc_read_i8042timer(HP_SDC_CMD_LOAD_RT, 5);
if (raw < 0) return -1;
tenms = (uint32_t)raw & 0xffffff;
days = (unsigned int)(raw >> 24) & 0xffff;
res->tv_usec = (suseconds_t)(tenms % 100) * 10000;
res->tv_sec = (time_t)(tenms / 100) + days * 86400;
return 0;
}
static inline int hp_sdc_rtc_read_fhs(struct timeval *res) {
int64_t raw;
unsigned int tenms;
raw = hp_sdc_rtc_read_i8042timer(HP_SDC_CMD_LOAD_FHS, 2);
if (raw < 0) return -1;
tenms = (unsigned int)raw & 0xffff;
res->tv_usec = (suseconds_t)(tenms % 100) * 10000;
res->tv_sec = (time_t)(tenms / 100);
return 0;
}
static inline int hp_sdc_rtc_read_mt(struct timeval *res) {
int64_t raw;
uint32_t tenms;
raw = hp_sdc_rtc_read_i8042timer(HP_SDC_CMD_LOAD_MT, 3);
if (raw < 0) return -1;
tenms = (uint32_t)raw & 0xffffff;
res->tv_usec = (suseconds_t)(tenms % 100) * 10000;
res->tv_sec = (time_t)(tenms / 100);
return 0;
}
static inline int hp_sdc_rtc_read_dt(struct timeval *res) {
int64_t raw;
uint32_t tenms;
raw = hp_sdc_rtc_read_i8042timer(HP_SDC_CMD_LOAD_DT, 3);
if (raw < 0) return -1;
tenms = (uint32_t)raw & 0xffffff;
res->tv_usec = (suseconds_t)(tenms % 100) * 10000;
res->tv_sec = (time_t)(tenms / 100);
return 0;
}
static inline int hp_sdc_rtc_read_ct(struct timeval *res) {
int64_t raw;
uint32_t tenms;
raw = hp_sdc_rtc_read_i8042timer(HP_SDC_CMD_LOAD_CT, 3);
if (raw < 0) return -1;
tenms = (uint32_t)raw & 0xffffff;
res->tv_usec = (suseconds_t)(tenms % 100) * 10000;
res->tv_sec = (time_t)(tenms / 100);
return 0;
}
static ssize_t hp_sdc_rtc_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos) {
ssize_t retval;
if (count < sizeof(unsigned long))
return -EINVAL;
retval = put_user(68, (unsigned long __user *)buf);
return retval;
}
static unsigned int hp_sdc_rtc_poll(struct file *file, poll_table *wait)
{
unsigned long l;
l = 0;
if (l != 0)
return POLLIN | POLLRDNORM;
return 0;
}
static int hp_sdc_rtc_open(struct inode *inode, struct file *file)
{
return 0;
}
static int hp_sdc_rtc_fasync (int fd, struct file *filp, int on)
{
return fasync_helper (fd, filp, on, &hp_sdc_rtc_async_queue);
}
static int hp_sdc_rtc_proc_show(struct seq_file *m, void *v)
{
#define YN(bit) ("no")
#define NY(bit) ("yes")
struct rtc_time tm;
struct timeval tv;
memset(&tm, 0, sizeof(struct rtc_time));
if (hp_sdc_rtc_read_bbrtc(&tm)) {
seq_puts(m, "BBRTC\t\t: READ FAILED!\n");
} else {
seq_printf(m,
"rtc_time\t: %02d:%02d:%02d\n"
"rtc_date\t: %04d-%02d-%02d\n"
"rtc_epoch\t: %04lu\n",
tm.tm_hour, tm.tm_min, tm.tm_sec,
tm.tm_year + 1900, tm.tm_mon + 1,
tm.tm_mday, epoch);
}
if (hp_sdc_rtc_read_rt(&tv)) {
seq_puts(m, "i8042 rtc\t: READ FAILED!\n");
} else {
seq_printf(m, "i8042 rtc\t: %ld.%02d seconds\n",
tv.tv_sec, (int)tv.tv_usec/1000);
}
if (hp_sdc_rtc_read_fhs(&tv)) {
seq_puts(m, "handshake\t: READ FAILED!\n");
} else {
seq_printf(m, "handshake\t: %ld.%02d seconds\n",
tv.tv_sec, (int)tv.tv_usec/1000);
}
if (hp_sdc_rtc_read_mt(&tv)) {
seq_puts(m, "alarm\t\t: READ FAILED!\n");
} else {
seq_printf(m, "alarm\t\t: %ld.%02d seconds\n",
tv.tv_sec, (int)tv.tv_usec/1000);
}
if (hp_sdc_rtc_read_dt(&tv)) {
seq_puts(m, "delay\t\t: READ FAILED!\n");
} else {
seq_printf(m, "delay\t\t: %ld.%02d seconds\n",
tv.tv_sec, (int)tv.tv_usec/1000);
}
if (hp_sdc_rtc_read_ct(&tv)) {
seq_puts(m, "periodic\t: READ FAILED!\n");
} else {
seq_printf(m, "periodic\t: %ld.%02d seconds\n",
tv.tv_sec, (int)tv.tv_usec/1000);
}
seq_printf(m,
"DST_enable\t: %s\n"
"BCD\t\t: %s\n"
"24hr\t\t: %s\n"
"square_wave\t: %s\n"
"alarm_IRQ\t: %s\n"
"update_IRQ\t: %s\n"
"periodic_IRQ\t: %s\n"
"periodic_freq\t: %ld\n"
"batt_status\t: %s\n",
YN(RTC_DST_EN),
NY(RTC_DM_BINARY),
YN(RTC_24H),
YN(RTC_SQWE),
YN(RTC_AIE),
YN(RTC_UIE),
YN(RTC_PIE),
1UL,
1 ? "okay" : "dead");
return 0;
#undef YN
#undef NY
}
static int hp_sdc_rtc_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, hp_sdc_rtc_proc_show, NULL);
}
static int hp_sdc_rtc_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
#if 1
return -EINVAL;
#else
struct rtc_time wtime;
struct timeval ttime;
int use_wtime = 0;
switch (cmd) {
case RTC_AIE_OFF:
case RTC_AIE_ON:
case RTC_PIE_OFF:
case RTC_PIE_ON:
case RTC_UIE_ON:
case RTC_UIE_OFF:
{
return -EINVAL;
}
case RTC_ALM_READ:
{
if (hp_sdc_rtc_read_mt(&ttime)) return -EFAULT;
if (hp_sdc_rtc_read_bbrtc(&wtime)) return -EFAULT;
wtime.tm_hour = ttime.tv_sec / 3600; ttime.tv_sec %= 3600;
wtime.tm_min = ttime.tv_sec / 60; ttime.tv_sec %= 60;
wtime.tm_sec = ttime.tv_sec;
break;
}
case RTC_IRQP_READ:
{
return put_user(hp_sdc_rtc_freq, (unsigned long *)arg);
}
case RTC_IRQP_SET:
{
if ((arg < 1) || (arg > 100)) return -EINVAL;
ttime.tv_sec = 0;
ttime.tv_usec = 1000000 / arg;
if (hp_sdc_rtc_set_ct(&ttime)) return -EFAULT;
hp_sdc_rtc_freq = arg;
return 0;
}
case RTC_ALM_SET:
{
struct hp_sdc_rtc_time alm_tm;
if (copy_from_user(&alm_tm, (struct hp_sdc_rtc_time*)arg,
sizeof(struct hp_sdc_rtc_time)))
return -EFAULT;
if (alm_tm.tm_hour > 23) return -EINVAL;
if (alm_tm.tm_min > 59) return -EINVAL;
if (alm_tm.tm_sec > 59) return -EINVAL;
ttime.sec = alm_tm.tm_hour * 3600 +
alm_tm.tm_min * 60 + alm_tm.tm_sec;
ttime.usec = 0;
if (hp_sdc_rtc_set_mt(&ttime)) return -EFAULT;
return 0;
}
case RTC_RD_TIME:
{
if (hp_sdc_rtc_read_bbrtc(&wtime)) return -EFAULT;
break;
}
case RTC_SET_TIME:
{
struct rtc_time hp_sdc_rtc_tm;
unsigned char mon, day, hrs, min, sec, leap_yr;
unsigned int yrs;
if (!capable(CAP_SYS_TIME))
return -EACCES;
if (copy_from_user(&hp_sdc_rtc_tm, (struct rtc_time *)arg,
sizeof(struct rtc_time)))
return -EFAULT;
yrs = hp_sdc_rtc_tm.tm_year + 1900;
mon = hp_sdc_rtc_tm.tm_mon + 1;
day = hp_sdc_rtc_tm.tm_mday;
hrs = hp_sdc_rtc_tm.tm_hour;
min = hp_sdc_rtc_tm.tm_min;
sec = hp_sdc_rtc_tm.tm_sec;
if (yrs < 1970)
return -EINVAL;
leap_yr = ((!(yrs % 4) && (yrs % 100)) || !(yrs % 400));
if ((mon > 12) || (day == 0))
return -EINVAL;
if (day > (days_in_mo[mon] + ((mon == 2) && leap_yr)))
return -EINVAL;
if ((hrs >= 24) || (min >= 60) || (sec >= 60))
return -EINVAL;
if ((yrs -= eH) > 255)
return -EINVAL;
return 0;
}
case RTC_EPOCH_READ:
{
return put_user (epoch, (unsigned long *)arg);
}
case RTC_EPOCH_SET:
{
if (arg < 1900)
return -EINVAL;
if (!capable(CAP_SYS_TIME))
return -EACCES;
epoch = arg;
return 0;
}
default:
return -EINVAL;
}
return copy_to_user((void *)arg, &wtime, sizeof wtime) ? -EFAULT : 0;
#endif
}
static long hp_sdc_rtc_unlocked_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
int ret;
mutex_lock(&hp_sdc_rtc_mutex);
ret = hp_sdc_rtc_ioctl(file, cmd, arg);
mutex_unlock(&hp_sdc_rtc_mutex);
return ret;
}
static int __init hp_sdc_rtc_init(void)
{
int ret;
#ifdef __mc68000__
if (!MACH_IS_HP300)
return -ENODEV;
#endif
sema_init(&i8042tregs, 1);
if ((ret = hp_sdc_request_timer_irq(&hp_sdc_rtc_isr)))
return ret;
if (misc_register(&hp_sdc_rtc_dev) != 0)
printk(KERN_INFO "Could not register misc. dev for i8042 rtc\n");
proc_create("driver/rtc", 0, NULL, &hp_sdc_rtc_proc_fops);
printk(KERN_INFO "HP i8042 SDC + MSM-58321 RTC support loaded "
"(RTC v " RTC_VERSION ")\n");
return 0;
}
static void __exit hp_sdc_rtc_exit(void)
{
remove_proc_entry ("driver/rtc", NULL);
misc_deregister(&hp_sdc_rtc_dev);
hp_sdc_release_timer_irq(hp_sdc_rtc_isr);
printk(KERN_INFO "HP i8042 SDC + MSM-58321 RTC support unloaded\n");
}
