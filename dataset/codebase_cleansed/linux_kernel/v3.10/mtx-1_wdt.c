static void mtx1_wdt_trigger(unsigned long unused)
{
spin_lock(&mtx1_wdt_device.lock);
if (mtx1_wdt_device.running)
ticks--;
mtx1_wdt_device.gstate = !mtx1_wdt_device.gstate;
gpio_set_value(mtx1_wdt_device.gpio, mtx1_wdt_device.gstate);
if (mtx1_wdt_device.queue && ticks)
mod_timer(&mtx1_wdt_device.timer, jiffies + MTX1_WDT_INTERVAL);
else
complete(&mtx1_wdt_device.stop);
spin_unlock(&mtx1_wdt_device.lock);
}
static void mtx1_wdt_reset(void)
{
ticks = mtx1_wdt_device.default_ticks;
}
static void mtx1_wdt_start(void)
{
unsigned long flags;
spin_lock_irqsave(&mtx1_wdt_device.lock, flags);
if (!mtx1_wdt_device.queue) {
mtx1_wdt_device.queue = 1;
mtx1_wdt_device.gstate = 1;
gpio_set_value(mtx1_wdt_device.gpio, 1);
mod_timer(&mtx1_wdt_device.timer, jiffies + MTX1_WDT_INTERVAL);
}
mtx1_wdt_device.running++;
spin_unlock_irqrestore(&mtx1_wdt_device.lock, flags);
}
static int mtx1_wdt_stop(void)
{
unsigned long flags;
spin_lock_irqsave(&mtx1_wdt_device.lock, flags);
if (mtx1_wdt_device.queue) {
mtx1_wdt_device.queue = 0;
mtx1_wdt_device.gstate = 0;
gpio_set_value(mtx1_wdt_device.gpio, 0);
}
ticks = mtx1_wdt_device.default_ticks;
spin_unlock_irqrestore(&mtx1_wdt_device.lock, flags);
return 0;
}
static int mtx1_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &mtx1_wdt_device.inuse))
return -EBUSY;
return nonseekable_open(inode, file);
}
static int mtx1_wdt_release(struct inode *inode, struct file *file)
{
clear_bit(0, &mtx1_wdt_device.inuse);
return 0;
}
static long mtx1_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = (int __user *)argp;
unsigned int value;
static const struct watchdog_info ident = {
.options = WDIOF_CARDRESET,
.identity = "MTX-1 WDT",
};
switch (cmd) {
case WDIOC_GETSUPPORT:
if (copy_to_user(argp, &ident, sizeof(ident)))
return -EFAULT;
break;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
put_user(0, p);
break;
case WDIOC_SETOPTIONS:
if (get_user(value, p))
return -EFAULT;
if (value & WDIOS_ENABLECARD)
mtx1_wdt_start();
else if (value & WDIOS_DISABLECARD)
mtx1_wdt_stop();
else
return -EINVAL;
return 0;
case WDIOC_KEEPALIVE:
mtx1_wdt_reset();
break;
default:
return -ENOTTY;
}
return 0;
}
static ssize_t mtx1_wdt_write(struct file *file, const char *buf,
size_t count, loff_t *ppos)
{
if (!count)
return -EIO;
mtx1_wdt_reset();
return count;
}
static int mtx1_wdt_probe(struct platform_device *pdev)
{
int ret;
mtx1_wdt_device.gpio = pdev->resource[0].start;
ret = gpio_request_one(mtx1_wdt_device.gpio,
GPIOF_OUT_INIT_HIGH, "mtx1-wdt");
if (ret < 0) {
dev_err(&pdev->dev, "failed to request gpio");
return ret;
}
spin_lock_init(&mtx1_wdt_device.lock);
init_completion(&mtx1_wdt_device.stop);
mtx1_wdt_device.queue = 0;
clear_bit(0, &mtx1_wdt_device.inuse);
setup_timer(&mtx1_wdt_device.timer, mtx1_wdt_trigger, 0L);
mtx1_wdt_device.default_ticks = ticks;
ret = misc_register(&mtx1_wdt_misc);
if (ret < 0) {
dev_err(&pdev->dev, "failed to register\n");
return ret;
}
mtx1_wdt_start();
dev_info(&pdev->dev, "MTX-1 Watchdog driver\n");
return 0;
}
static int mtx1_wdt_remove(struct platform_device *pdev)
{
if (mtx1_wdt_device.queue) {
mtx1_wdt_device.queue = 0;
wait_for_completion(&mtx1_wdt_device.stop);
}
gpio_free(mtx1_wdt_device.gpio);
misc_deregister(&mtx1_wdt_misc);
return 0;
}
