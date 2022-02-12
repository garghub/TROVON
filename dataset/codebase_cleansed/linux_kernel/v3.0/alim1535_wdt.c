static void ali_start(void)
{
u32 val;
spin_lock(&ali_lock);
pci_read_config_dword(ali_pci, 0xCC, &val);
val &= ~0x3F;
val |= (1 << 25) | ali_timeout_bits;
pci_write_config_dword(ali_pci, 0xCC, val);
spin_unlock(&ali_lock);
}
static void ali_stop(void)
{
u32 val;
spin_lock(&ali_lock);
pci_read_config_dword(ali_pci, 0xCC, &val);
val &= ~0x3F;
val &= ~(1 << 25);
pci_write_config_dword(ali_pci, 0xCC, val);
spin_unlock(&ali_lock);
}
static void ali_keepalive(void)
{
ali_start();
}
static int ali_settimer(int t)
{
if (t < 0)
return -EINVAL;
else if (t < 60)
ali_timeout_bits = t|(1 << 6);
else if (t < 3600)
ali_timeout_bits = (t / 60)|(1 << 7);
else if (t < 18000)
ali_timeout_bits = (t / 300)|(1 << 6)|(1 << 7);
else
return -EINVAL;
timeout = t;
return 0;
}
static ssize_t ali_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
if (len) {
if (!nowayout) {
size_t i;
ali_expect_release = 0;
for (i = 0; i != len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
ali_expect_release = 42;
}
}
ali_start();
}
return len;
}
static long ali_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
static const struct watchdog_info ident = {
.options = WDIOF_KEEPALIVEPING |
WDIOF_SETTIMEOUT |
WDIOF_MAGICCLOSE,
.firmware_version = 0,
.identity = "ALi M1535 WatchDog Timer",
};
switch (cmd) {
case WDIOC_GETSUPPORT:
return copy_to_user(argp, &ident, sizeof(ident)) ? -EFAULT : 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_SETOPTIONS:
{
int new_options, retval = -EINVAL;
if (get_user(new_options, p))
return -EFAULT;
if (new_options & WDIOS_DISABLECARD) {
ali_stop();
retval = 0;
}
if (new_options & WDIOS_ENABLECARD) {
ali_start();
retval = 0;
}
return retval;
}
case WDIOC_KEEPALIVE:
ali_keepalive();
return 0;
case WDIOC_SETTIMEOUT:
{
int new_timeout;
if (get_user(new_timeout, p))
return -EFAULT;
if (ali_settimer(new_timeout))
return -EINVAL;
ali_keepalive();
}
case WDIOC_GETTIMEOUT:
return put_user(timeout, p);
default:
return -ENOTTY;
}
}
static int ali_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &ali_is_open))
return -EBUSY;
ali_start();
return nonseekable_open(inode, file);
}
static int ali_release(struct inode *inode, struct file *file)
{
if (ali_expect_release == 42)
ali_stop();
else {
printk(KERN_CRIT PFX
"Unexpected close, not stopping watchdog!\n");
ali_keepalive();
}
clear_bit(0, &ali_is_open);
ali_expect_release = 0;
return 0;
}
static int ali_notify_sys(struct notifier_block *this,
unsigned long code, void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
ali_stop();
return NOTIFY_DONE;
}
static int __init ali_find_watchdog(void)
{
struct pci_dev *pdev;
u32 wdog;
pdev = pci_get_device(PCI_VENDOR_ID_AL, 0x1535, NULL);
if (pdev == NULL)
pdev = pci_get_device(PCI_VENDOR_ID_AL, 0x1533, NULL);
if (pdev == NULL)
return -ENODEV;
pci_dev_put(pdev);
pdev = pci_get_device(PCI_VENDOR_ID_AL, 0x7101, NULL);
if (pdev == NULL)
return -ENODEV;
if (pci_enable_device(pdev)) {
pci_dev_put(pdev);
return -EIO;
}
ali_pci = pdev;
pci_read_config_dword(pdev, 0xCC, &wdog);
wdog &= ~0x3F;
wdog &= ~((1 << 27)|(1 << 26)|(1 << 25)|(1 << 24));
wdog &= ~((1 << 16)|(1 << 13)|(1 << 12)|(1 << 11)|(1 << 10)|(1 << 9));
pci_write_config_dword(pdev, 0xCC, wdog);
return 0;
}
static int __init watchdog_init(void)
{
int ret;
if (ali_find_watchdog() != 0)
return -ENODEV;
if (timeout < 1 || timeout >= 18000) {
timeout = WATCHDOG_TIMEOUT;
printk(KERN_INFO PFX
"timeout value must be 0 < timeout < 18000, using %d\n",
timeout);
}
ali_settimer(timeout);
ret = register_reboot_notifier(&ali_notifier);
if (ret != 0) {
printk(KERN_ERR PFX
"cannot register reboot notifier (err=%d)\n", ret);
goto out;
}
ret = misc_register(&ali_miscdev);
if (ret != 0) {
printk(KERN_ERR PFX
"cannot register miscdev on minor=%d (err=%d)\n",
WATCHDOG_MINOR, ret);
goto unreg_reboot;
}
printk(KERN_INFO PFX "initialized. timeout=%d sec (nowayout=%d)\n",
timeout, nowayout);
out:
return ret;
unreg_reboot:
unregister_reboot_notifier(&ali_notifier);
goto out;
}
static void __exit watchdog_exit(void)
{
ali_stop();
misc_deregister(&ali_miscdev);
unregister_reboot_notifier(&ali_notifier);
pci_dev_put(ali_pci);
}
