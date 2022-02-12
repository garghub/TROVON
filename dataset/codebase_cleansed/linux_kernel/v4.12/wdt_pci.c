static void wdtpci_ctr_mode(int ctr, int mode)
{
ctr <<= 6;
ctr |= 0x30;
ctr |= (mode << 1);
outb(ctr, WDT_CR);
udelay(8);
}
static void wdtpci_ctr_load(int ctr, int val)
{
outb(val & 0xFF, WDT_COUNT0 + ctr);
udelay(8);
outb(val >> 8, WDT_COUNT0 + ctr);
udelay(8);
}
static int wdtpci_start(void)
{
unsigned long flags;
spin_lock_irqsave(&wdtpci_lock, flags);
inb(WDT_DC);
udelay(8);
wdtpci_ctr_mode(2, 0);
outb(0, WDT_DC);
udelay(8);
inb(WDT_DC);
udelay(8);
outb(0, WDT_CLOCK);
udelay(8);
inb(WDT_BUZZER);
udelay(8);
inb(WDT_OPTONOTRST);
udelay(8);
inb(WDT_OPTORST);
udelay(8);
inb(WDT_PROGOUT);
udelay(8);
wdtpci_ctr_mode(0, 3);
wdtpci_ctr_mode(1, 2);
wdtpci_ctr_mode(2, 1);
wdtpci_ctr_load(0, 20833);
wdtpci_ctr_load(1, wd_heartbeat);
outb(0, WDT_DC);
udelay(8);
spin_unlock_irqrestore(&wdtpci_lock, flags);
return 0;
}
static int wdtpci_stop(void)
{
unsigned long flags;
spin_lock_irqsave(&wdtpci_lock, flags);
inb(WDT_DC);
udelay(8);
wdtpci_ctr_load(2, 0);
spin_unlock_irqrestore(&wdtpci_lock, flags);
return 0;
}
static int wdtpci_ping(void)
{
unsigned long flags;
spin_lock_irqsave(&wdtpci_lock, flags);
inb(WDT_DC);
udelay(8);
wdtpci_ctr_mode(1, 2);
wdtpci_ctr_load(1, wd_heartbeat);
outb(0, WDT_DC);
udelay(8);
spin_unlock_irqrestore(&wdtpci_lock, flags);
return 0;
}
static int wdtpci_set_heartbeat(int t)
{
if (t < 1 || t > 65535)
return -EINVAL;
heartbeat = t;
wd_heartbeat = t * 100;
return 0;
}
static int wdtpci_get_status(int *status)
{
unsigned char new_status;
unsigned long flags;
spin_lock_irqsave(&wdtpci_lock, flags);
new_status = inb(WDT_SR);
spin_unlock_irqrestore(&wdtpci_lock, flags);
*status = 0;
if (new_status & WDC_SR_ISOI0)
*status |= WDIOF_EXTERN1;
if (new_status & WDC_SR_ISII1)
*status |= WDIOF_EXTERN2;
if (type == 501) {
if (!(new_status & WDC_SR_TGOOD))
*status |= WDIOF_OVERHEAT;
if (!(new_status & WDC_SR_PSUOVER))
*status |= WDIOF_POWEROVER;
if (!(new_status & WDC_SR_PSUUNDR))
*status |= WDIOF_POWERUNDER;
if (tachometer) {
if (!(new_status & WDC_SR_FANGOOD))
*status |= WDIOF_FANFAULT;
}
}
return 0;
}
static int wdtpci_get_temperature(int *temperature)
{
unsigned short c;
unsigned long flags;
spin_lock_irqsave(&wdtpci_lock, flags);
c = inb(WDT_RT);
udelay(8);
spin_unlock_irqrestore(&wdtpci_lock, flags);
*temperature = (c * 11 / 15) + 7;
return 0;
}
static irqreturn_t wdtpci_interrupt(int irq, void *dev_id)
{
unsigned char status;
spin_lock(&wdtpci_lock);
status = inb(WDT_SR);
udelay(8);
pr_crit("status %d\n", status);
if (type == 501) {
if (!(status & WDC_SR_TGOOD)) {
pr_crit("Overheat alarm (%d)\n", inb(WDT_RT));
udelay(8);
}
if (!(status & WDC_SR_PSUOVER))
pr_crit("PSU over voltage\n");
if (!(status & WDC_SR_PSUUNDR))
pr_crit("PSU under voltage\n");
if (tachometer) {
if (!(status & WDC_SR_FANGOOD))
pr_crit("Possible fan fault\n");
}
}
if (!(status & WDC_SR_WCCR)) {
#ifdef SOFTWARE_REBOOT
#ifdef ONLY_TESTING
pr_crit("Would Reboot\n");
#else
pr_crit("Initiating system reboot\n");
emergency_restart();
#endif
#else
pr_crit("Reset in 5ms\n");
#endif
}
spin_unlock(&wdtpci_lock);
return IRQ_HANDLED;
}
static ssize_t wdtpci_write(struct file *file, const char __user *buf,
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
wdtpci_ping();
}
return count;
}
static long wdtpci_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
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
.identity = "PCI-WDT500/501",
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
wdtpci_get_status(&status);
return put_user(status, p);
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_KEEPALIVE:
wdtpci_ping();
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(new_heartbeat, p))
return -EFAULT;
if (wdtpci_set_heartbeat(new_heartbeat))
return -EINVAL;
wdtpci_ping();
case WDIOC_GETTIMEOUT:
return put_user(heartbeat, p);
default:
return -ENOTTY;
}
}
static int wdtpci_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &open_lock))
return -EBUSY;
if (nowayout)
__module_get(THIS_MODULE);
wdtpci_start();
return nonseekable_open(inode, file);
}
static int wdtpci_release(struct inode *inode, struct file *file)
{
if (expect_close == 42) {
wdtpci_stop();
} else {
pr_crit("Unexpected close, not stopping timer!\n");
wdtpci_ping();
}
expect_close = 0;
clear_bit(0, &open_lock);
return 0;
}
static ssize_t wdtpci_temp_read(struct file *file, char __user *buf,
size_t count, loff_t *ptr)
{
int temperature;
if (wdtpci_get_temperature(&temperature))
return -EFAULT;
if (copy_to_user(buf, &temperature, 1))
return -EFAULT;
return 1;
}
static int wdtpci_temp_open(struct inode *inode, struct file *file)
{
return nonseekable_open(inode, file);
}
static int wdtpci_temp_release(struct inode *inode, struct file *file)
{
return 0;
}
static int wdtpci_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
wdtpci_stop();
return NOTIFY_DONE;
}
static int wdtpci_init_one(struct pci_dev *dev,
const struct pci_device_id *ent)
{
int ret = -EIO;
dev_count++;
if (dev_count > 1) {
pr_err("This driver only supports one device\n");
return -ENODEV;
}
if (type != 500 && type != 501) {
pr_err("unknown card type '%d'\n", type);
return -ENODEV;
}
if (pci_enable_device(dev)) {
pr_err("Not possible to enable PCI Device\n");
return -ENODEV;
}
if (pci_resource_start(dev, 2) == 0x0000) {
pr_err("No I/O-Address for card detected\n");
ret = -ENODEV;
goto out_pci;
}
if (pci_request_region(dev, 2, "wdt_pci")) {
pr_err("I/O address 0x%llx already in use\n",
(unsigned long long)pci_resource_start(dev, 2));
goto out_pci;
}
irq = dev->irq;
io = pci_resource_start(dev, 2);
if (request_irq(irq, wdtpci_interrupt, IRQF_SHARED,
"wdt_pci", &wdtpci_miscdev)) {
pr_err("IRQ %d is not free\n", irq);
goto out_reg;
}
pr_info("PCI-WDT500/501 (PCI-WDG-CSM) driver 0.10 at 0x%llx (Interrupt %d)\n",
(unsigned long long)io, irq);
if (wdtpci_set_heartbeat(heartbeat)) {
wdtpci_set_heartbeat(WD_TIMO);
pr_info("heartbeat value must be 0 < heartbeat < 65536, using %d\n",
WD_TIMO);
}
ret = register_reboot_notifier(&wdtpci_notifier);
if (ret) {
pr_err("cannot register reboot notifier (err=%d)\n", ret);
goto out_irq;
}
if (type == 501) {
ret = misc_register(&temp_miscdev);
if (ret) {
pr_err("cannot register miscdev on minor=%d (err=%d)\n",
TEMP_MINOR, ret);
goto out_rbt;
}
}
ret = misc_register(&wdtpci_miscdev);
if (ret) {
pr_err("cannot register miscdev on minor=%d (err=%d)\n",
WATCHDOG_MINOR, ret);
goto out_misc;
}
pr_info("initialized. heartbeat=%d sec (nowayout=%d)\n",
heartbeat, nowayout);
if (type == 501)
pr_info("Fan Tachometer is %s\n",
tachometer ? "Enabled" : "Disabled");
ret = 0;
out:
return ret;
out_misc:
if (type == 501)
misc_deregister(&temp_miscdev);
out_rbt:
unregister_reboot_notifier(&wdtpci_notifier);
out_irq:
free_irq(irq, &wdtpci_miscdev);
out_reg:
pci_release_region(dev, 2);
out_pci:
pci_disable_device(dev);
goto out;
}
static void wdtpci_remove_one(struct pci_dev *pdev)
{
misc_deregister(&wdtpci_miscdev);
if (type == 501)
misc_deregister(&temp_miscdev);
unregister_reboot_notifier(&wdtpci_notifier);
free_irq(irq, &wdtpci_miscdev);
pci_release_region(pdev, 2);
pci_disable_device(pdev);
dev_count--;
}
