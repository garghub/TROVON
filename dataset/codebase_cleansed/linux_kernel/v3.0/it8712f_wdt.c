static int superio_inb(int reg)
{
outb(reg, REG);
return inb(VAL);
}
static void superio_outb(int val, int reg)
{
outb(reg, REG);
outb(val, VAL);
}
static int superio_inw(int reg)
{
int val;
outb(reg++, REG);
val = inb(VAL) << 8;
outb(reg, REG);
val |= inb(VAL);
return val;
}
static inline void superio_select(int ldn)
{
outb(LDN, REG);
outb(ldn, VAL);
}
static inline void superio_enter(void)
{
spin_lock(&io_lock);
outb(0x87, REG);
outb(0x01, REG);
outb(0x55, REG);
outb(0x55, REG);
}
static inline void superio_exit(void)
{
outb(0x02, REG);
outb(0x02, VAL);
spin_unlock(&io_lock);
}
static inline void it8712f_wdt_ping(void)
{
if (wdt_control_reg & WDT_RESET_GAME)
inb(address);
}
static void it8712f_wdt_update_margin(void)
{
int config = WDT_OUT_KRST | WDT_OUT_PWROK;
int units = margin;
if (units <= max_units) {
config |= WDT_UNIT_SEC;
printk(KERN_INFO NAME ": timer margin %d seconds\n", units);
} else {
units /= 60;
printk(KERN_INFO NAME ": timer margin %d minutes\n", units);
}
superio_outb(config, WDT_CONFIG);
if (revision >= 0x08)
superio_outb(units >> 8, WDT_TIMEOUT + 1);
superio_outb(units, WDT_TIMEOUT);
}
static int it8712f_wdt_get_status(void)
{
if (superio_inb(WDT_CONTROL) & 0x01)
return WDIOF_CARDRESET;
else
return 0;
}
static void it8712f_wdt_enable(void)
{
printk(KERN_DEBUG NAME ": enabling watchdog timer\n");
superio_enter();
superio_select(LDN_GPIO);
superio_outb(wdt_control_reg, WDT_CONTROL);
it8712f_wdt_update_margin();
superio_exit();
it8712f_wdt_ping();
}
static void it8712f_wdt_disable(void)
{
printk(KERN_DEBUG NAME ": disabling watchdog timer\n");
superio_enter();
superio_select(LDN_GPIO);
superio_outb(0, WDT_CONFIG);
superio_outb(0, WDT_CONTROL);
if (revision >= 0x08)
superio_outb(0, WDT_TIMEOUT + 1);
superio_outb(0, WDT_TIMEOUT);
superio_exit();
}
static int it8712f_wdt_notify(struct notifier_block *this,
unsigned long code, void *unused)
{
if (code == SYS_HALT || code == SYS_POWER_OFF)
if (!nowayout)
it8712f_wdt_disable();
return NOTIFY_DONE;
}
static ssize_t it8712f_wdt_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
if (len) {
size_t i;
it8712f_wdt_ping();
expect_close = 0;
for (i = 0; i < len; ++i) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
expect_close = 42;
}
}
return len;
}
static long it8712f_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
static const struct watchdog_info ident = {
.identity = "IT8712F Watchdog",
.firmware_version = 1,
.options = WDIOF_SETTIMEOUT | WDIOF_KEEPALIVEPING |
WDIOF_MAGICCLOSE,
};
int value;
switch (cmd) {
case WDIOC_GETSUPPORT:
if (copy_to_user(argp, &ident, sizeof(ident)))
return -EFAULT;
return 0;
case WDIOC_GETSTATUS:
superio_enter();
superio_select(LDN_GPIO);
value = it8712f_wdt_get_status();
superio_exit();
return put_user(value, p);
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_KEEPALIVE:
it8712f_wdt_ping();
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(value, p))
return -EFAULT;
if (value < 1)
return -EINVAL;
if (value > (max_units * 60))
return -EINVAL;
margin = value;
superio_enter();
superio_select(LDN_GPIO);
it8712f_wdt_update_margin();
superio_exit();
it8712f_wdt_ping();
case WDIOC_GETTIMEOUT:
if (put_user(margin, p))
return -EFAULT;
return 0;
default:
return -ENOTTY;
}
}
static int it8712f_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &wdt_open))
return -EBUSY;
it8712f_wdt_enable();
return nonseekable_open(inode, file);
}
static int it8712f_wdt_release(struct inode *inode, struct file *file)
{
if (expect_close != 42) {
printk(KERN_WARNING NAME
": watchdog device closed unexpectedly, will not"
" disable the watchdog timer\n");
} else if (!nowayout) {
it8712f_wdt_disable();
}
expect_close = 0;
clear_bit(0, &wdt_open);
return 0;
}
static int __init it8712f_wdt_find(unsigned short *address)
{
int err = -ENODEV;
int chip_type;
superio_enter();
chip_type = superio_inw(DEVID);
if (chip_type != IT8712F_DEVID)
goto exit;
superio_select(LDN_GAME);
superio_outb(1, ACT_REG);
if (!(superio_inb(ACT_REG) & 0x01)) {
printk(KERN_ERR NAME ": Device not activated, skipping\n");
goto exit;
}
*address = superio_inw(BASE_REG);
if (*address == 0) {
printk(KERN_ERR NAME ": Base address not set, skipping\n");
goto exit;
}
err = 0;
revision = superio_inb(DEVREV) & 0x0f;
if (revision >= 0x08)
max_units = 65535;
if (margin > (max_units * 60))
margin = (max_units * 60);
printk(KERN_INFO NAME ": Found IT%04xF chip revision %d - "
"using DogFood address 0x%x\n",
chip_type, revision, *address);
exit:
superio_exit();
return err;
}
static int __init it8712f_wdt_init(void)
{
int err = 0;
spin_lock_init(&io_lock);
if (it8712f_wdt_find(&address))
return -ENODEV;
if (!request_region(address, 1, "IT8712F Watchdog")) {
printk(KERN_WARNING NAME ": watchdog I/O region busy\n");
return -EBUSY;
}
it8712f_wdt_disable();
err = register_reboot_notifier(&it8712f_wdt_notifier);
if (err) {
printk(KERN_ERR NAME ": unable to register reboot notifier\n");
goto out;
}
err = misc_register(&it8712f_wdt_miscdev);
if (err) {
printk(KERN_ERR NAME
": cannot register miscdev on minor=%d (err=%d)\n",
WATCHDOG_MINOR, err);
goto reboot_out;
}
return 0;
reboot_out:
unregister_reboot_notifier(&it8712f_wdt_notifier);
out:
release_region(address, 1);
return err;
}
static void __exit it8712f_wdt_exit(void)
{
misc_deregister(&it8712f_wdt_miscdev);
unregister_reboot_notifier(&it8712f_wdt_notifier);
release_region(address, 1);
}
