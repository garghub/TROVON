static void cpu5wdt_trigger(unsigned long unused)
{
if (verbose > 2)
printk(KERN_DEBUG PFX "trigger at %i ticks\n", ticks);
if (cpu5wdt_device.running)
ticks--;
spin_lock(&cpu5wdt_lock);
outb(1, port + CPU5WDT_TRIGGER_REG);
if (cpu5wdt_device.queue && ticks)
mod_timer(&cpu5wdt_device.timer, jiffies + CPU5WDT_INTERVAL);
else {
complete(&cpu5wdt_device.stop);
}
spin_unlock(&cpu5wdt_lock);
}
static void cpu5wdt_reset(void)
{
ticks = cpu5wdt_device.default_ticks;
if (verbose)
printk(KERN_DEBUG PFX "reset (%i ticks)\n", (int) ticks);
}
static void cpu5wdt_start(void)
{
unsigned long flags;
spin_lock_irqsave(&cpu5wdt_lock, flags);
if (!cpu5wdt_device.queue) {
cpu5wdt_device.queue = 1;
outb(0, port + CPU5WDT_TIME_A_REG);
outb(0, port + CPU5WDT_TIME_B_REG);
outb(1, port + CPU5WDT_MODE_REG);
outb(0, port + CPU5WDT_RESET_REG);
outb(0, port + CPU5WDT_ENABLE_REG);
mod_timer(&cpu5wdt_device.timer, jiffies + CPU5WDT_INTERVAL);
}
cpu5wdt_device.running++;
spin_unlock_irqrestore(&cpu5wdt_lock, flags);
}
static int cpu5wdt_stop(void)
{
unsigned long flags;
spin_lock_irqsave(&cpu5wdt_lock, flags);
if (cpu5wdt_device.running)
cpu5wdt_device.running = 0;
ticks = cpu5wdt_device.default_ticks;
spin_unlock_irqrestore(&cpu5wdt_lock, flags);
if (verbose)
printk(KERN_CRIT PFX "stop not possible\n");
return -EIO;
}
static int cpu5wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &cpu5wdt_device.inuse))
return -EBUSY;
return nonseekable_open(inode, file);
}
static int cpu5wdt_release(struct inode *inode, struct file *file)
{
clear_bit(0, &cpu5wdt_device.inuse);
return 0;
}
static long cpu5wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
void __user *argp = (void __user *)arg;
int __user *p = argp;
unsigned int value;
static const struct watchdog_info ident = {
.options = WDIOF_CARDRESET,
.identity = "CPU5 WDT",
};
switch (cmd) {
case WDIOC_GETSUPPORT:
if (copy_to_user(argp, &ident, sizeof(ident)))
return -EFAULT;
break;
case WDIOC_GETSTATUS:
value = inb(port + CPU5WDT_STATUS_REG);
value = (value >> 2) & 1;
return put_user(value, p);
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_SETOPTIONS:
if (get_user(value, p))
return -EFAULT;
if (value & WDIOS_ENABLECARD)
cpu5wdt_start();
if (value & WDIOS_DISABLECARD)
cpu5wdt_stop();
break;
case WDIOC_KEEPALIVE:
cpu5wdt_reset();
break;
default:
return -ENOTTY;
}
return 0;
}
static ssize_t cpu5wdt_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
if (!count)
return -EIO;
cpu5wdt_reset();
return count;
}
static int __devinit cpu5wdt_init(void)
{
unsigned int val;
int err;
if (verbose)
printk(KERN_DEBUG PFX
"port=0x%x, verbose=%i\n", port, verbose);
init_completion(&cpu5wdt_device.stop);
cpu5wdt_device.queue = 0;
setup_timer(&cpu5wdt_device.timer, cpu5wdt_trigger, 0);
cpu5wdt_device.default_ticks = ticks;
if (!request_region(port, CPU5WDT_EXTENT, PFX)) {
printk(KERN_ERR PFX "request_region failed\n");
err = -EBUSY;
goto no_port;
}
val = inb(port + CPU5WDT_STATUS_REG);
val = (val >> 2) & 1;
if (!val)
printk(KERN_INFO PFX "sorry, was my fault\n");
err = misc_register(&cpu5wdt_misc);
if (err < 0) {
printk(KERN_ERR PFX "misc_register failed\n");
goto no_misc;
}
printk(KERN_INFO PFX "init success\n");
return 0;
no_misc:
release_region(port, CPU5WDT_EXTENT);
no_port:
return err;
}
static int __devinit cpu5wdt_init_module(void)
{
return cpu5wdt_init();
}
static void __devexit cpu5wdt_exit(void)
{
if (cpu5wdt_device.queue) {
cpu5wdt_device.queue = 0;
wait_for_completion(&cpu5wdt_device.stop);
}
misc_deregister(&cpu5wdt_misc);
release_region(port, CPU5WDT_EXTENT);
}
static void __devexit cpu5wdt_exit_module(void)
{
cpu5wdt_exit();
}
