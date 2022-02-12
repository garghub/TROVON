static void wdt_send_data(unsigned char command, unsigned char data)
{
outb(data, DATA_PORT);
msleep(200);
outb(command, COMMAND_PORT);
msleep(100);
}
static void wdt_enable(void)
{
mutex_lock(&wdt_lock);
wdt_send_data(IFACE_ON_COMMAND, 1);
wdt_send_data(REBOOT_COMMAND, margin);
mutex_unlock(&wdt_lock);
}
static void wdt_disable(void)
{
mutex_lock(&wdt_lock);
wdt_send_data(IFACE_ON_COMMAND, 0);
wdt_send_data(REBOOT_COMMAND, 0);
mutex_unlock(&wdt_lock);
}
static int fitpc2_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(WDT_IN_USE, &wdt_status))
return -EBUSY;
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
wdt_enable();
return nonseekable_open(inode, file);
}
static ssize_t fitpc2_wdt_write(struct file *file, const char *data,
size_t len, loff_t *ppos)
{
size_t i;
if (!len)
return 0;
if (nowayout) {
len = 0;
goto out;
}
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
for (i = 0; i != len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
set_bit(WDT_OK_TO_CLOSE, &wdt_status);
}
out:
wdt_enable();
return len;
}
static long fitpc2_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int ret = -ENOTTY;
int time;
switch (cmd) {
case WDIOC_GETSUPPORT:
ret = copy_to_user((struct watchdog_info *)arg, &ident,
sizeof(ident)) ? -EFAULT : 0;
break;
case WDIOC_GETSTATUS:
ret = put_user(0, (int *)arg);
break;
case WDIOC_GETBOOTSTATUS:
ret = put_user(0, (int *)arg);
break;
case WDIOC_KEEPALIVE:
wdt_enable();
ret = 0;
break;
case WDIOC_SETTIMEOUT:
ret = get_user(time, (int *)arg);
if (ret)
break;
if (time < 31 || time > 255) {
ret = -EINVAL;
break;
}
margin = time;
wdt_enable();
case WDIOC_GETTIMEOUT:
ret = put_user(margin, (int *)arg);
break;
}
return ret;
}
static int fitpc2_wdt_release(struct inode *inode, struct file *file)
{
if (test_bit(WDT_OK_TO_CLOSE, &wdt_status)) {
wdt_disable();
pr_info("Device disabled\n");
} else {
pr_warning("Device closed unexpectedly -"
" timer will not stop\n");
wdt_enable();
}
clear_bit(WDT_IN_USE, &wdt_status);
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
return 0;
}
static int __init fitpc2_wdt_init(void)
{
int err;
const char *brd_name;
brd_name = dmi_get_system_info(DMI_BOARD_NAME);
if (!brd_name || !strstr(brd_name, "SBC-FITPC2"))
return -ENODEV;
pr_info("%s found\n", brd_name);
if (!request_region(COMMAND_PORT, 1, WATCHDOG_NAME)) {
pr_err("I/O address 0x%04x already in use\n", COMMAND_PORT);
return -EIO;
}
if (!request_region(DATA_PORT, 1, WATCHDOG_NAME)) {
pr_err("I/O address 0x%04x already in use\n", DATA_PORT);
err = -EIO;
goto err_data_port;
}
if (margin < 31 || margin > 255) {
pr_err("margin must be in range 31 - 255"
" seconds, you tried to set %d\n", margin);
err = -EINVAL;
goto err_margin;
}
err = misc_register(&fitpc2_wdt_miscdev);
if (err) {
pr_err("cannot register miscdev on minor=%d (err=%d)\n",
WATCHDOG_MINOR, err);
goto err_margin;
}
return 0;
err_margin:
release_region(DATA_PORT, 1);
err_data_port:
release_region(COMMAND_PORT, 1);
return err;
}
static void __exit fitpc2_wdt_exit(void)
{
misc_deregister(&fitpc2_wdt_miscdev);
release_region(DATA_PORT, 1);
release_region(COMMAND_PORT, 1);
}
