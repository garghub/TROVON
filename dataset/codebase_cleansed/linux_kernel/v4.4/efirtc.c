static inline int
compute_yday(efi_time_t *eft)
{
return __mon_yday[is_leap(eft->year)][eft->month-1]+ eft->day -1;
}
static int
compute_wday(efi_time_t *eft)
{
int y;
int ndays = 0;
if ( eft->year < 1998 ) {
printk(KERN_ERR "efirtc: EFI year < 1998, invalid date\n");
return -1;
}
for(y=EFI_RTC_EPOCH; y < eft->year; y++ ) {
ndays += 365 + (is_leap(y) ? 1 : 0);
}
ndays += compute_yday(eft);
return (ndays + 4) % 7;
}
static void
convert_to_efi_time(struct rtc_time *wtime, efi_time_t *eft)
{
eft->year = wtime->tm_year + 1900;
eft->month = wtime->tm_mon + 1;
eft->day = wtime->tm_mday;
eft->hour = wtime->tm_hour;
eft->minute = wtime->tm_min;
eft->second = wtime->tm_sec;
eft->nanosecond = 0;
eft->daylight = wtime->tm_isdst ? EFI_ISDST: 0;
eft->timezone = EFI_UNSPECIFIED_TIMEZONE;
}
static void
convert_from_efi_time(efi_time_t *eft, struct rtc_time *wtime)
{
memset(wtime, 0, sizeof(*wtime));
wtime->tm_sec = eft->second;
wtime->tm_min = eft->minute;
wtime->tm_hour = eft->hour;
wtime->tm_mday = eft->day;
wtime->tm_mon = eft->month - 1;
wtime->tm_year = eft->year - 1900;
wtime->tm_wday = compute_wday(eft);
wtime->tm_yday = compute_yday(eft);
switch (eft->daylight & EFI_ISDST) {
case EFI_ISDST:
wtime->tm_isdst = 1;
break;
case EFI_TIME_ADJUST_DAYLIGHT:
wtime->tm_isdst = 0;
break;
default:
wtime->tm_isdst = -1;
}
}
static long efi_rtc_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
efi_status_t status;
unsigned long flags;
efi_time_t eft;
efi_time_cap_t cap;
struct rtc_time wtime;
struct rtc_wkalrm __user *ewp;
unsigned char enabled, pending;
switch (cmd) {
case RTC_UIE_ON:
case RTC_UIE_OFF:
case RTC_PIE_ON:
case RTC_PIE_OFF:
case RTC_AIE_ON:
case RTC_AIE_OFF:
case RTC_ALM_SET:
case RTC_ALM_READ:
case RTC_IRQP_READ:
case RTC_IRQP_SET:
case RTC_EPOCH_READ:
case RTC_EPOCH_SET:
return -EINVAL;
case RTC_RD_TIME:
spin_lock_irqsave(&efi_rtc_lock, flags);
status = efi.get_time(&eft, &cap);
spin_unlock_irqrestore(&efi_rtc_lock,flags);
if (status != EFI_SUCCESS) {
printk(KERN_ERR "efitime: can't read time\n");
return -EINVAL;
}
convert_from_efi_time(&eft, &wtime);
return copy_to_user((void __user *)arg, &wtime,
sizeof (struct rtc_time)) ? - EFAULT : 0;
case RTC_SET_TIME:
if (!capable(CAP_SYS_TIME)) return -EACCES;
if (copy_from_user(&wtime, (struct rtc_time __user *)arg,
sizeof(struct rtc_time)) )
return -EFAULT;
convert_to_efi_time(&wtime, &eft);
spin_lock_irqsave(&efi_rtc_lock, flags);
status = efi.set_time(&eft);
spin_unlock_irqrestore(&efi_rtc_lock,flags);
return status == EFI_SUCCESS ? 0 : -EINVAL;
case RTC_WKALM_SET:
if (!capable(CAP_SYS_TIME)) return -EACCES;
ewp = (struct rtc_wkalrm __user *)arg;
if ( get_user(enabled, &ewp->enabled)
|| copy_from_user(&wtime, &ewp->time, sizeof(struct rtc_time)) )
return -EFAULT;
convert_to_efi_time(&wtime, &eft);
spin_lock_irqsave(&efi_rtc_lock, flags);
status = efi.set_wakeup_time((efi_bool_t)enabled, &eft);
spin_unlock_irqrestore(&efi_rtc_lock,flags);
return status == EFI_SUCCESS ? 0 : -EINVAL;
case RTC_WKALM_RD:
spin_lock_irqsave(&efi_rtc_lock, flags);
status = efi.get_wakeup_time((efi_bool_t *)&enabled, (efi_bool_t *)&pending, &eft);
spin_unlock_irqrestore(&efi_rtc_lock,flags);
if (status != EFI_SUCCESS) return -EINVAL;
ewp = (struct rtc_wkalrm __user *)arg;
if ( put_user(enabled, &ewp->enabled)
|| put_user(pending, &ewp->pending)) return -EFAULT;
convert_from_efi_time(&eft, &wtime);
return copy_to_user(&ewp->time, &wtime,
sizeof(struct rtc_time)) ? -EFAULT : 0;
}
return -ENOTTY;
}
static int efi_rtc_open(struct inode *inode, struct file *file)
{
return 0;
}
static int efi_rtc_close(struct inode *inode, struct file *file)
{
return 0;
}
static int efi_rtc_proc_show(struct seq_file *m, void *v)
{
efi_time_t eft, alm;
efi_time_cap_t cap;
efi_bool_t enabled, pending;
unsigned long flags;
memset(&eft, 0, sizeof(eft));
memset(&alm, 0, sizeof(alm));
memset(&cap, 0, sizeof(cap));
spin_lock_irqsave(&efi_rtc_lock, flags);
efi.get_time(&eft, &cap);
efi.get_wakeup_time(&enabled, &pending, &alm);
spin_unlock_irqrestore(&efi_rtc_lock,flags);
seq_printf(m,
"Time : %u:%u:%u.%09u\n"
"Date : %u-%u-%u\n"
"Daylight : %u\n",
eft.hour, eft.minute, eft.second, eft.nanosecond,
eft.year, eft.month, eft.day,
eft.daylight);
if (eft.timezone == EFI_UNSPECIFIED_TIMEZONE)
seq_puts(m, "Timezone : unspecified\n");
else
seq_printf(m, "Timezone : %u\n", eft.timezone);
seq_printf(m,
"Alarm Time : %u:%u:%u.%09u\n"
"Alarm Date : %u-%u-%u\n"
"Alarm Daylight : %u\n"
"Enabled : %s\n"
"Pending : %s\n",
alm.hour, alm.minute, alm.second, alm.nanosecond,
alm.year, alm.month, alm.day,
alm.daylight,
enabled == 1 ? "yes" : "no",
pending == 1 ? "yes" : "no");
if (eft.timezone == EFI_UNSPECIFIED_TIMEZONE)
seq_puts(m, "Timezone : unspecified\n");
else
seq_printf(m, "Timezone : %u\n", alm.timezone);
seq_printf(m,
"Resolution : %u\n"
"Accuracy : %u\n"
"SetstoZero : %u\n",
cap.resolution, cap.accuracy, cap.sets_to_zero);
return 0;
}
static int efi_rtc_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, efi_rtc_proc_show, NULL);
}
static int __init
efi_rtc_init(void)
{
int ret;
struct proc_dir_entry *dir;
printk(KERN_INFO "EFI Time Services Driver v%s\n", EFI_RTC_VERSION);
ret = misc_register(&efi_rtc_dev);
if (ret) {
printk(KERN_ERR "efirtc: can't misc_register on minor=%d\n",
EFI_RTC_MINOR);
return ret;
}
dir = proc_create("driver/efirtc", 0, NULL, &efi_rtc_proc_fops);
if (dir == NULL) {
printk(KERN_ERR "efirtc: can't create /proc/driver/efirtc.\n");
misc_deregister(&efi_rtc_dev);
return -1;
}
return 0;
}
