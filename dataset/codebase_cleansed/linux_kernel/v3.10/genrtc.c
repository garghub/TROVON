static void genrtc_troutine(struct work_struct *work)
{
unsigned int tmp = get_rtc_ss();
if (stop_rtc_timers) {
stask_active = 0;
return;
}
if (oldsecs != tmp){
oldsecs = tmp;
timer_task.function = gen_rtc_timer;
timer_task.expires = jiffies + HZ - (HZ/10);
tt_exp=timer_task.expires;
ttask_active=1;
stask_active=0;
add_timer(&timer_task);
gen_rtc_interrupt(0);
} else if (schedule_work(&genrtc_task) == 0)
stask_active = 0;
}
static void gen_rtc_timer(unsigned long data)
{
lostint = get_rtc_ss() - oldsecs ;
if (lostint<0)
lostint = 60 - lostint;
if (time_after(jiffies, tt_exp))
printk(KERN_INFO "genrtc: timer task delayed by %ld jiffies\n",
jiffies-tt_exp);
ttask_active=0;
stask_active=1;
if ((schedule_work(&genrtc_task) == 0))
stask_active = 0;
}
static void gen_rtc_interrupt(unsigned long arg)
{
gen_rtc_irq_data += 0x100;
gen_rtc_irq_data &= ~0xff;
gen_rtc_irq_data |= RTC_UIE;
if (lostint){
printk("genrtc: system delaying clock ticks?\n");
gen_rtc_irq_data += ((lostint-1)<<8);
lostint = 0;
}
wake_up_interruptible(&gen_rtc_wait);
}
static ssize_t gen_rtc_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
unsigned long data;
ssize_t retval;
if (count != sizeof (unsigned int) && count != sizeof (unsigned long))
return -EINVAL;
if (file->f_flags & O_NONBLOCK && !gen_rtc_irq_data)
return -EAGAIN;
retval = wait_event_interruptible(gen_rtc_wait,
(data = xchg(&gen_rtc_irq_data, 0)));
if (retval)
goto out;
if (sizeof (int) != sizeof (long) && count == sizeof (unsigned int)) {
unsigned int uidata = data;
retval = put_user(uidata, (unsigned int __user *)buf) ?:
sizeof(unsigned int);
}
else {
retval = put_user(data, (unsigned long __user *)buf) ?:
sizeof(unsigned long);
}
out:
return retval;
}
static unsigned int gen_rtc_poll(struct file *file,
struct poll_table_struct *wait)
{
poll_wait(file, &gen_rtc_wait, wait);
if (gen_rtc_irq_data != 0)
return POLLIN | POLLRDNORM;
return 0;
}
static inline void gen_clear_rtc_irq_bit(unsigned char bit)
{
#ifdef CONFIG_GEN_RTC_X
stop_rtc_timers = 1;
if (ttask_active){
del_timer_sync(&timer_task);
ttask_active = 0;
}
while (stask_active)
schedule();
spin_lock(&gen_rtc_lock);
irq_active = 0;
spin_unlock(&gen_rtc_lock);
#endif
}
static inline int gen_set_rtc_irq_bit(unsigned char bit)
{
#ifdef CONFIG_GEN_RTC_X
spin_lock(&gen_rtc_lock);
if ( !irq_active ) {
irq_active = 1;
stop_rtc_timers = 0;
lostint = 0;
INIT_WORK(&genrtc_task, genrtc_troutine);
oldsecs = get_rtc_ss();
init_timer(&timer_task);
stask_active = 1;
if (schedule_work(&genrtc_task) == 0){
stask_active = 0;
}
}
spin_unlock(&gen_rtc_lock);
gen_rtc_irq_data = 0;
return 0;
#else
return -EINVAL;
#endif
}
static int gen_rtc_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
struct rtc_time wtime;
struct rtc_pll_info pll;
void __user *argp = (void __user *)arg;
switch (cmd) {
case RTC_PLL_GET:
if (get_rtc_pll(&pll))
return -EINVAL;
else
return copy_to_user(argp, &pll, sizeof pll) ? -EFAULT : 0;
case RTC_PLL_SET:
if (!capable(CAP_SYS_TIME))
return -EACCES;
if (copy_from_user(&pll, argp, sizeof(pll)))
return -EFAULT;
return set_rtc_pll(&pll);
case RTC_UIE_OFF:
gen_clear_rtc_irq_bit(RTC_UIE);
return 0;
case RTC_UIE_ON:
return gen_set_rtc_irq_bit(RTC_UIE);
case RTC_RD_TIME:
memset(&wtime, 0, sizeof(wtime));
get_rtc_time(&wtime);
return copy_to_user(argp, &wtime, sizeof(wtime)) ? -EFAULT : 0;
case RTC_SET_TIME:
{
int year;
unsigned char leap_yr;
if (!capable(CAP_SYS_TIME))
return -EACCES;
if (copy_from_user(&wtime, argp, sizeof(wtime)))
return -EFAULT;
year = wtime.tm_year + 1900;
leap_yr = ((!(year % 4) && (year % 100)) ||
!(year % 400));
if ((wtime.tm_mon < 0 || wtime.tm_mon > 11) || (wtime.tm_mday < 1))
return -EINVAL;
if (wtime.tm_mday < 0 || wtime.tm_mday >
(days_in_mo[wtime.tm_mon] + ((wtime.tm_mon == 1) && leap_yr)))
return -EINVAL;
if (wtime.tm_hour < 0 || wtime.tm_hour >= 24 ||
wtime.tm_min < 0 || wtime.tm_min >= 60 ||
wtime.tm_sec < 0 || wtime.tm_sec >= 60)
return -EINVAL;
return set_rtc_time(&wtime);
}
}
return -EINVAL;
}
static long gen_rtc_unlocked_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int ret;
mutex_lock(&gen_rtc_mutex);
ret = gen_rtc_ioctl(file, cmd, arg);
mutex_unlock(&gen_rtc_mutex);
return ret;
}
static int gen_rtc_open(struct inode *inode, struct file *file)
{
mutex_lock(&gen_rtc_mutex);
if (gen_rtc_status & RTC_IS_OPEN) {
mutex_unlock(&gen_rtc_mutex);
return -EBUSY;
}
gen_rtc_status |= RTC_IS_OPEN;
gen_rtc_irq_data = 0;
irq_active = 0;
mutex_unlock(&gen_rtc_mutex);
return 0;
}
static int gen_rtc_release(struct inode *inode, struct file *file)
{
gen_clear_rtc_irq_bit(RTC_PIE|RTC_AIE|RTC_UIE);
gen_rtc_status &= ~RTC_IS_OPEN;
return 0;
}
static int gen_rtc_proc_show(struct seq_file *m, void *v)
{
struct rtc_time tm;
unsigned int flags;
struct rtc_pll_info pll;
flags = get_rtc_time(&tm);
seq_printf(m,
"rtc_time\t: %02d:%02d:%02d\n"
"rtc_date\t: %04d-%02d-%02d\n"
"rtc_epoch\t: %04u\n",
tm.tm_hour, tm.tm_min, tm.tm_sec,
tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, 1900);
tm.tm_hour = tm.tm_min = tm.tm_sec = 0;
seq_puts(m, "alarm\t\t: ");
if (tm.tm_hour <= 24)
seq_printf(m, "%02d:", tm.tm_hour);
else
seq_puts(m, "**:");
if (tm.tm_min <= 59)
seq_printf(m, "%02d:", tm.tm_min);
else
seq_puts(m, "**:");
if (tm.tm_sec <= 59)
seq_printf(m, "%02d\n", tm.tm_sec);
else
seq_puts(m, "**\n");
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
(flags & RTC_DST_EN) ? "yes" : "no",
(flags & RTC_DM_BINARY) ? "no" : "yes",
(flags & RTC_24H) ? "yes" : "no",
(flags & RTC_SQWE) ? "yes" : "no",
(flags & RTC_AIE) ? "yes" : "no",
irq_active ? "yes" : "no",
(flags & RTC_PIE) ? "yes" : "no",
0L ,
(flags & RTC_BATT_BAD) ? "bad" : "okay");
if (!get_rtc_pll(&pll))
seq_printf(m,
"PLL adjustment\t: %d\n"
"PLL max +ve adjustment\t: %d\n"
"PLL max -ve adjustment\t: %d\n"
"PLL +ve adjustment factor\t: %d\n"
"PLL -ve adjustment factor\t: %d\n"
"PLL frequency\t: %ld\n",
pll.pll_value,
pll.pll_max,
pll.pll_min,
pll.pll_posmult,
pll.pll_negmult,
pll.pll_clock);
return 0;
}
static int gen_rtc_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, gen_rtc_proc_show, NULL);
}
static int __init gen_rtc_proc_init(void)
{
struct proc_dir_entry *r;
r = proc_create("driver/rtc", 0, NULL, &gen_rtc_proc_fops);
if (!r)
return -ENOMEM;
return 0;
}
static inline int gen_rtc_proc_init(void) { return 0; }
static int __init rtc_generic_init(void)
{
int retval;
printk(KERN_INFO "Generic RTC Driver v%s\n", RTC_VERSION);
retval = misc_register(&rtc_gen_dev);
if (retval < 0)
return retval;
retval = gen_rtc_proc_init();
if (retval) {
misc_deregister(&rtc_gen_dev);
return retval;
}
return 0;
}
static void __exit rtc_generic_exit(void)
{
remove_proc_entry ("driver/rtc", NULL);
misc_deregister(&rtc_gen_dev);
}
