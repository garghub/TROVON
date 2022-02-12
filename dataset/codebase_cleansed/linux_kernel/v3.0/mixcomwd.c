static void mixcomwd_ping(void)
{
outb_p(55, watchdog_port);
return;
}
static void mixcomwd_timerfun(unsigned long d)
{
mixcomwd_ping();
mod_timer(&mixcomwd_timer, jiffies + 5 * HZ);
}
static int mixcomwd_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &mixcomwd_opened))
return -EBUSY;
mixcomwd_ping();
if (nowayout)
__module_get(THIS_MODULE);
else {
if (mixcomwd_timer_alive) {
del_timer(&mixcomwd_timer);
mixcomwd_timer_alive = 0;
}
}
return nonseekable_open(inode, file);
}
static int mixcomwd_release(struct inode *inode, struct file *file)
{
if (expect_close == 42) {
if (mixcomwd_timer_alive) {
printk(KERN_ERR PFX
"release called while internal timer alive");
return -EBUSY;
}
mixcomwd_timer_alive = 1;
mod_timer(&mixcomwd_timer, jiffies + 5 * HZ);
} else
printk(KERN_CRIT PFX
"WDT device closed unexpectedly. WDT will not stop!\n");
clear_bit(0, &mixcomwd_opened);
expect_close = 0;
return 0;
}
static ssize_t mixcomwd_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
if (len) {
if (!nowayout) {
size_t i;
expect_close = 0;
for (i = 0; i != len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
expect_close = 42;
}
}
mixcomwd_ping();
}
return len;
}
static long mixcomwd_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
int status;
static const struct watchdog_info ident = {
.options = WDIOF_KEEPALIVEPING | WDIOF_MAGICCLOSE,
.firmware_version = 1,
.identity = "MixCOM watchdog",
};
switch (cmd) {
case WDIOC_GETSUPPORT:
if (copy_to_user(argp, &ident, sizeof(ident)))
return -EFAULT;
break;
case WDIOC_GETSTATUS:
status = mixcomwd_opened;
if (!nowayout)
status |= mixcomwd_timer_alive;
return put_user(status, p);
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_KEEPALIVE:
mixcomwd_ping();
break;
default:
return -ENOTTY;
}
return 0;
}
static int __init checkcard(int port, int card_id)
{
int id;
if (!request_region(port, 1, "MixCOM watchdog"))
return 0;
id = inb_p(port);
if (card_id == MIXCOM_ID)
id &= 0x3f;
if (id != card_id) {
release_region(port, 1);
return 0;
}
return 1;
}
static int __init mixcomwd_init(void)
{
int i, ret, found = 0;
for (i = 0; !found && mixcomwd_io_info[i].ioport != 0; i++) {
if (checkcard(mixcomwd_io_info[i].ioport,
mixcomwd_io_info[i].id)) {
found = 1;
watchdog_port = mixcomwd_io_info[i].ioport;
}
}
if (!found) {
printk(KERN_ERR PFX
"No card detected, or port not available.\n");
return -ENODEV;
}
ret = misc_register(&mixcomwd_miscdev);
if (ret) {
printk(KERN_ERR PFX
"cannot register miscdev on minor=%d (err=%d)\n",
WATCHDOG_MINOR, ret);
goto error_misc_register_watchdog;
}
printk(KERN_INFO
"MixCOM watchdog driver v%s, watchdog port at 0x%3x\n",
VERSION, watchdog_port);
return 0;
error_misc_register_watchdog:
release_region(watchdog_port, 1);
watchdog_port = 0x0000;
return ret;
}
static void __exit mixcomwd_exit(void)
{
if (!nowayout) {
if (mixcomwd_timer_alive) {
printk(KERN_WARNING PFX "I quit now, hardware will"
" probably reboot!\n");
del_timer_sync(&mixcomwd_timer);
mixcomwd_timer_alive = 0;
}
}
misc_deregister(&mixcomwd_miscdev);
release_region(watchdog_port, 1);
}
