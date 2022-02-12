static void sbc8360_activate(void)
{
outb(0x0A, SBC8360_ENABLE);
msleep_interruptible(100);
outb(0x0B, SBC8360_ENABLE);
msleep_interruptible(100);
outb(wd_multiplier, SBC8360_ENABLE);
msleep_interruptible(100);
}
static void sbc8360_ping(void)
{
outb(wd_margin, SBC8360_BASETIME);
}
static void sbc8360_stop(void)
{
outb(0, SBC8360_ENABLE);
}
static ssize_t sbc8360_write(struct file *file, const char __user *buf,
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
sbc8360_ping();
}
return count;
}
static int sbc8360_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &sbc8360_is_open))
return -EBUSY;
if (nowayout)
__module_get(THIS_MODULE);
sbc8360_activate();
sbc8360_ping();
return nonseekable_open(inode, file);
}
static int sbc8360_close(struct inode *inode, struct file *file)
{
if (expect_close == 42)
sbc8360_stop();
else
pr_crit("SBC8360 device closed unexpectedly. SBC8360 will not stop!\n");
clear_bit(0, &sbc8360_is_open);
expect_close = 0;
return 0;
}
static int sbc8360_notify_sys(struct notifier_block *this, unsigned long code,
void *unused)
{
if (code == SYS_DOWN || code == SYS_HALT)
sbc8360_stop();
return NOTIFY_DONE;
}
static int __init sbc8360_init(void)
{
int res;
unsigned long int mseconds = 60000;
if (timeout < 0 || timeout > 63) {
pr_err("Invalid timeout index (must be 0-63)\n");
res = -EINVAL;
goto out;
}
if (!request_region(SBC8360_ENABLE, 1, "SBC8360")) {
pr_err("ENABLE method I/O %X is not available\n",
SBC8360_ENABLE);
res = -EIO;
goto out;
}
if (!request_region(SBC8360_BASETIME, 1, "SBC8360")) {
pr_err("BASETIME method I/O %X is not available\n",
SBC8360_BASETIME);
res = -EIO;
goto out_nobasetimereg;
}
res = register_reboot_notifier(&sbc8360_notifier);
if (res) {
pr_err("Failed to register reboot notifier\n");
goto out_noreboot;
}
res = misc_register(&sbc8360_miscdev);
if (res) {
pr_err("failed to register misc device\n");
goto out_nomisc;
}
wd_margin = wd_times[timeout][0];
wd_multiplier = wd_times[timeout][1];
if (wd_multiplier == 1)
mseconds = (wd_margin + 1) * 500;
else if (wd_multiplier == 2)
mseconds = (wd_margin + 1) * 5000;
else if (wd_multiplier == 3)
mseconds = (wd_margin + 1) * 50000;
else if (wd_multiplier == 4)
mseconds = (wd_margin + 1) * 100000;
pr_info("Timeout set at %ld ms\n", mseconds);
return 0;
out_nomisc:
unregister_reboot_notifier(&sbc8360_notifier);
out_noreboot:
release_region(SBC8360_BASETIME, 1);
out_nobasetimereg:
release_region(SBC8360_ENABLE, 1);
out:
return res;
}
static void __exit sbc8360_exit(void)
{
misc_deregister(&sbc8360_miscdev);
unregister_reboot_notifier(&sbc8360_notifier);
release_region(SBC8360_ENABLE, 1);
release_region(SBC8360_BASETIME, 1);
}
