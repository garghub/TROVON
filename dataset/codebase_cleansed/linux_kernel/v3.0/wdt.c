static void wdt_ctr_mode(int ctr, int mode)
{
ctr <<= 6;
ctr |= 0x30;
ctr |= (mode << 1);
outb_p(ctr, WDT_CR);
}
static void wdt_ctr_load(int ctr, int val)
{
outb_p(val&0xFF, WDT_COUNT0+ctr);
outb_p(val>>8, WDT_COUNT0+ctr);
}
static int wdt_start(void)
{
unsigned long flags;
spin_lock_irqsave(&wdt_lock, flags);
inb_p(WDT_DC);
wdt_ctr_mode(0, 3);
wdt_ctr_mode(1, 2);
wdt_ctr_mode(2, 0);
wdt_ctr_load(0, 8948);
wdt_ctr_load(1, wd_heartbeat);
wdt_ctr_load(2, 65535);
outb_p(0, WDT_DC);
spin_unlock_irqrestore(&wdt_lock, flags);
return 0;
}
static int wdt_stop(void)
{
unsigned long flags;
spin_lock_irqsave(&wdt_lock, flags);
inb_p(WDT_DC);
wdt_ctr_load(2, 0);
spin_unlock_irqrestore(&wdt_lock, flags);
return 0;
}
static void wdt_ping(void)
{
unsigned long flags;
spin_lock_irqsave(&wdt_lock, flags);
inb_p(WDT_DC);
wdt_ctr_mode(1, 2);
wdt_ctr_load(1, wd_heartbeat);
outb_p(0, WDT_DC);
spin_unlock_irqrestore(&wdt_lock, flags);
}
static int wdt_set_heartbeat(int t)
{
if (t < 1 || t > 65535)
return -EINVAL;
heartbeat = t;
wd_heartbeat = t * 100;
return 0;
}
static int wdt_get_status(void)
{
unsigned char new_status;
int status = 0;
unsigned long flags;
spin_lock_irqsave(&wdt_lock, flags);
new_status = inb_p(WDT_SR);
spin_unlock_irqrestore(&wdt_lock, flags);
if (new_status & WDC_SR_ISOI0)
status |= WDIOF_EXTERN1;
if (new_status & WDC_SR_ISII1)
status |= WDIOF_EXTERN2;
if (type == 501) {
if (!(new_status & WDC_SR_TGOOD))
status |= WDIOF_OVERHEAT;
if (!(new_status & WDC_SR_PSUOVER))
status |= WDIOF_POWEROVER;
if (!(new_status & WDC_SR_PSUUNDR))
status |= WDIOF_POWERUNDER;
if (tachometer) {
if (!(new_status & WDC_SR_FANGOOD))
status |= WDIOF_FANFAULT;
}
}
return status;
}
static int wdt_get_temperature(void)
{
unsigned short c;
unsigned long flags;
spin_lock_irqsave(&wdt_lock, flags);
c = inb_p(WDT_RT);
spin_unlock_irqrestore(&wdt_lock, flags);
return (c * 11 / 15) + 7;
}
static void wdt_decode_501(int status)
{
if (!(status & WDC_SR_TGOOD))
printk(KERN_CRIT "Overheat alarm.(%d)\n", inb_p(WDT_RT));
if (!(status & WDC_SR_PSUOVER))
printk(KERN_CRIT "PSU over voltage.\n");
if (!(status & WDC_SR_PSUUNDR))
printk(KERN_CRIT "PSU under voltage.\n");
}
static irqreturn_t wdt_interrupt(int irq, void *dev_id)
{
unsigned char status;
spin_lock(&wdt_lock);
status = inb_p(WDT_SR);
printk(KERN_CRIT "WDT status %d\n", status);
if (type == 501) {
wdt_decode_501(status);
if (tachometer) {
if (!(status & WDC_SR_FANGOOD))
printk(KERN_CRIT "Possible fan fault.\n");
}
}
if (!(status & WDC_SR_WCCR)) {
#ifdef SOFTWARE_REBOOT
#ifdef ONLY_TESTING
printk(KERN_CRIT "Would Reboot.\n");
#else
printk(KERN_CRIT "Initiating system reboot.\n");
emergency_restart();
#endif
#else
printk(KERN_CRIT "Reset in 5ms.\n");
#endif
}
spin_unlock(&wdt_lock);
return IRQ_HANDLED;
}
static ssize_t wdt_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
if (count) {
if (!nowayout) {
size_t i;
expect_close = 0;
for (i = 0; i != count; i++) {
char c;
if (get_user(c, buf + i))
return -EFAULT;
if (c == 'V')
expect_close = 42;
}
}
wdt_ping();
}
return count;
}
static long wdt_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
int new_heartbeat;
int status;
struct watchdog_info ident = {
.options = WDIOF_SETTIMEOUT|
WDIOF_MAGICCLOSE|
WDIOF_KEEPALIVEPING,
.firmware_version = 1,
.identity = "WDT500/501",
};
ident.options |= (WDIOF_EXTERN1|WDIOF_EXTERN2);
if (type == 501) {
ident.options |= (WDIOF_OVERHEAT|WDIOF_POWERUNDER|
WDIOF_POWEROVER);
if (tachometer)
ident.options |= WDIOF_FANFAULT;
}
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp, &ident, sizeof(ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
status = wdt_get_status();
return put_user(status, p);
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_KEEPALIVE:
wdt_ping();
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(new_heartbeat, p))
return -EFAULT;
if (wdt_set_heartbeat(new_heartbeat))
return -EINVAL;
wdt_ping();
case WDIOC_GETTIMEOUT:
return put_user(heartbeat, p);
default:
return -ENOTTY;
}
}
static int wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &wdt_is_open))
return -EBUSY;
wdt_start();
return nonseekable_open(inode, file);
}
static int wdt_release(struct inode *inode, struct file *file)
{
if (expect_close == 42) {
wdt_stop();
clear_bit(0, &wdt_is_open);
} else {
printk(KERN_CRIT
"wdt: WDT device closed unexpectedly. WDT will not stop!\n");
wdt_ping();
}
expect_close = 0;
return 0;
}
static ssize_t wdt_temp_read(struct file *file, char __user *buf,
size_t count, loff_t *ptr)
{
int temperature = wdt_get_temperature();
if (copy_to_user(buf, &temperature, 1))
return -EFAULT;
return 1;
}
static int wdt_temp_open(struct inode *inode, struct file *file)
{
return nonseekable_open(inode, file);
}
static int wdt_temp_release(struct inode *inode, struct file *file)
{
return 0;
}
static int wdt_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
wdt_stop();
return NOTIFY_DONE;
}
static void __exit wdt_exit(void)
{
misc_deregister(&wdt_miscdev);
if (type == 501)
misc_deregister(&temp_miscdev);
unregister_reboot_notifier(&wdt_notifier);
free_irq(irq, NULL);
release_region(io, 8);
}
static int __init wdt_init(void)
{
int ret;
if (type != 500 && type != 501) {
printk(KERN_ERR "wdt: unknown card type '%d'.\n", type);
return -ENODEV;
}
if (wdt_set_heartbeat(heartbeat)) {
wdt_set_heartbeat(WD_TIMO);
printk(KERN_INFO "wdt: heartbeat value must be "
"0 < heartbeat < 65536, using %d\n", WD_TIMO);
}
if (!request_region(io, 8, "wdt501p")) {
printk(KERN_ERR
"wdt: I/O address 0x%04x already in use\n", io);
ret = -EBUSY;
goto out;
}
ret = request_irq(irq, wdt_interrupt, IRQF_DISABLED, "wdt501p", NULL);
if (ret) {
printk(KERN_ERR "wdt: IRQ %d is not free.\n", irq);
goto outreg;
}
ret = register_reboot_notifier(&wdt_notifier);
if (ret) {
printk(KERN_ERR
"wdt: cannot register reboot notifier (err=%d)\n", ret);
goto outirq;
}
if (type == 501) {
ret = misc_register(&temp_miscdev);
if (ret) {
printk(KERN_ERR "wdt: cannot register miscdev "
"on minor=%d (err=%d)\n", TEMP_MINOR, ret);
goto outrbt;
}
}
ret = misc_register(&wdt_miscdev);
if (ret) {
printk(KERN_ERR
"wdt: cannot register miscdev on minor=%d (err=%d)\n",
WATCHDOG_MINOR, ret);
goto outmisc;
}
printk(KERN_INFO "WDT500/501-P driver 0.10 "
"at 0x%04x (Interrupt %d). heartbeat=%d sec (nowayout=%d)\n",
io, irq, heartbeat, nowayout);
if (type == 501)
printk(KERN_INFO "wdt: Fan Tachometer is %s\n",
(tachometer ? "Enabled" : "Disabled"));
return 0;
outmisc:
if (type == 501)
misc_deregister(&temp_miscdev);
outrbt:
unregister_reboot_notifier(&wdt_notifier);
outirq:
free_irq(irq, NULL);
outreg:
release_region(io, 8);
out:
return ret;
}
