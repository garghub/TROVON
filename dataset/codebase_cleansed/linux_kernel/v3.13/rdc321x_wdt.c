static void rdc321x_wdt_trigger(unsigned long unused)
{
unsigned long flags;
u32 val;
if (rdc321x_wdt_device.running)
ticks--;
spin_lock_irqsave(&rdc321x_wdt_device.lock, flags);
pci_read_config_dword(rdc321x_wdt_device.sb_pdev,
rdc321x_wdt_device.base_reg, &val);
val |= RDC_WDT_EN;
pci_write_config_dword(rdc321x_wdt_device.sb_pdev,
rdc321x_wdt_device.base_reg, val);
spin_unlock_irqrestore(&rdc321x_wdt_device.lock, flags);
if (rdc321x_wdt_device.queue && ticks)
mod_timer(&rdc321x_wdt_device.timer,
jiffies + RDC_WDT_INTERVAL);
else {
complete(&rdc321x_wdt_device.stop);
}
}
static void rdc321x_wdt_reset(void)
{
ticks = rdc321x_wdt_device.default_ticks;
}
static void rdc321x_wdt_start(void)
{
unsigned long flags;
if (!rdc321x_wdt_device.queue) {
rdc321x_wdt_device.queue = 1;
spin_lock_irqsave(&rdc321x_wdt_device.lock, flags);
pci_write_config_dword(rdc321x_wdt_device.sb_pdev,
rdc321x_wdt_device.base_reg, RDC_CLS_TMR);
pci_write_config_dword(rdc321x_wdt_device.sb_pdev,
rdc321x_wdt_device.base_reg,
RDC_WDT_EN | RDC_WDT_CNT);
spin_unlock_irqrestore(&rdc321x_wdt_device.lock, flags);
mod_timer(&rdc321x_wdt_device.timer,
jiffies + RDC_WDT_INTERVAL);
}
rdc321x_wdt_device.running++;
}
static int rdc321x_wdt_stop(void)
{
if (rdc321x_wdt_device.running)
rdc321x_wdt_device.running = 0;
ticks = rdc321x_wdt_device.default_ticks;
return -EIO;
}
static int rdc321x_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &rdc321x_wdt_device.inuse))
return -EBUSY;
return nonseekable_open(inode, file);
}
static int rdc321x_wdt_release(struct inode *inode, struct file *file)
{
clear_bit(0, &rdc321x_wdt_device.inuse);
return 0;
}
static long rdc321x_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
void __user *argp = (void __user *)arg;
u32 value;
static const struct watchdog_info ident = {
.options = WDIOF_CARDRESET,
.identity = "RDC321x WDT",
};
unsigned long flags;
switch (cmd) {
case WDIOC_KEEPALIVE:
rdc321x_wdt_reset();
break;
case WDIOC_GETSTATUS:
spin_lock_irqsave(&rdc321x_wdt_device.lock, flags);
pci_read_config_dword(rdc321x_wdt_device.sb_pdev,
rdc321x_wdt_device.base_reg, &value);
spin_unlock_irqrestore(&rdc321x_wdt_device.lock, flags);
if (copy_to_user(argp, &value, sizeof(u32)))
return -EFAULT;
break;
case WDIOC_GETSUPPORT:
if (copy_to_user(argp, &ident, sizeof(ident)))
return -EFAULT;
break;
case WDIOC_SETOPTIONS:
if (copy_from_user(&value, argp, sizeof(int)))
return -EFAULT;
switch (value) {
case WDIOS_ENABLECARD:
rdc321x_wdt_start();
break;
case WDIOS_DISABLECARD:
return rdc321x_wdt_stop();
default:
return -EINVAL;
}
break;
default:
return -ENOTTY;
}
return 0;
}
static ssize_t rdc321x_wdt_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
if (!count)
return -EIO;
rdc321x_wdt_reset();
return count;
}
static int rdc321x_wdt_probe(struct platform_device *pdev)
{
int err;
struct resource *r;
struct rdc321x_wdt_pdata *pdata;
pdata = dev_get_platdata(&pdev->dev);
if (!pdata) {
dev_err(&pdev->dev, "no platform data supplied\n");
return -ENODEV;
}
r = platform_get_resource_byname(pdev, IORESOURCE_IO, "wdt-reg");
if (!r) {
dev_err(&pdev->dev, "failed to get wdt-reg resource\n");
return -ENODEV;
}
rdc321x_wdt_device.sb_pdev = pdata->sb_pdev;
rdc321x_wdt_device.base_reg = r->start;
err = misc_register(&rdc321x_wdt_misc);
if (err < 0) {
dev_err(&pdev->dev, "misc_register failed\n");
return err;
}
spin_lock_init(&rdc321x_wdt_device.lock);
pci_write_config_dword(rdc321x_wdt_device.sb_pdev,
rdc321x_wdt_device.base_reg, RDC_WDT_RST);
init_completion(&rdc321x_wdt_device.stop);
rdc321x_wdt_device.queue = 0;
clear_bit(0, &rdc321x_wdt_device.inuse);
setup_timer(&rdc321x_wdt_device.timer, rdc321x_wdt_trigger, 0);
rdc321x_wdt_device.default_ticks = ticks;
dev_info(&pdev->dev, "watchdog init success\n");
return 0;
}
static int rdc321x_wdt_remove(struct platform_device *pdev)
{
if (rdc321x_wdt_device.queue) {
rdc321x_wdt_device.queue = 0;
wait_for_completion(&rdc321x_wdt_device.stop);
}
misc_deregister(&rdc321x_wdt_misc);
return 0;
}
