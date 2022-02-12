static void coh901327_enable(u16 timeout)
{
u16 val;
unsigned long freq;
unsigned long delay_ns;
clk_enable(clk);
val = readw(virtbase + U300_WDOG_D2R);
if (val == U300_WDOG_D2R_DISABLE_STATUS_DISABLED)
writew(U300_WDOG_RR_RESTART_VALUE_RESUME,
virtbase + U300_WDOG_RR);
writew(U300_WDOG_IER_WILL_BARK_IRQ_ACK_ENABLE,
virtbase + U300_WDOG_IER);
freq = clk_get_rate(clk);
delay_ns = DIV_ROUND_UP(1000000000, freq);
delay_ns = 3 * delay_ns;
ndelay(delay_ns);
writew(U300_WDOG_IMR_WILL_BARK_IRQ_ENABLE, virtbase + U300_WDOG_IMR);
writew(timeout, virtbase + U300_WDOG_TR);
writew(U300_WDOG_FR_FEED_RESTART_TIMER, virtbase + U300_WDOG_FR);
(void) readw(virtbase + U300_WDOG_CR);
val = readw(virtbase + U300_WDOG_D2R);
clk_disable(clk);
if (val != U300_WDOG_D2R_DISABLE_STATUS_ENABLED)
dev_err(parent,
"%s(): watchdog not enabled! D2R value %04x\n",
__func__, val);
}
static void coh901327_disable(void)
{
u16 val;
clk_enable(clk);
writew(0x0000U, virtbase + U300_WDOG_IMR);
val = readw(virtbase + U300_WDOG_D2R);
if (val != U300_WDOG_D2R_DISABLE_STATUS_DISABLED) {
writew(U300_WDOG_D1R_DISABLE1_DISABLE_TIMER,
virtbase + U300_WDOG_D1R);
writew(U300_WDOG_D2R_DISABLE2_DISABLE_TIMER,
virtbase + U300_WDOG_D2R);
writew(U300_WDOG_D2R_DISABLE2_DISABLE_TIMER,
virtbase + U300_WDOG_D2R);
}
val = readw(virtbase + U300_WDOG_D2R);
clk_disable(clk);
if (val != U300_WDOG_D2R_DISABLE_STATUS_DISABLED)
dev_err(parent,
"%s(): watchdog not disabled! D2R value %04x\n",
__func__, val);
}
static void coh901327_start(void)
{
coh901327_enable(margin * 100);
}
static void coh901327_keepalive(void)
{
clk_enable(clk);
writew(U300_WDOG_FR_FEED_RESTART_TIMER,
virtbase + U300_WDOG_FR);
clk_disable(clk);
}
static int coh901327_settimeout(int time)
{
if (time <= 0 || time > 327)
return -EINVAL;
margin = time;
clk_enable(clk);
writew(margin * 100, virtbase + U300_WDOG_TR);
writew(U300_WDOG_FR_FEED_RESTART_TIMER,
virtbase + U300_WDOG_FR);
clk_disable(clk);
return 0;
}
static irqreturn_t coh901327_interrupt(int irq, void *data)
{
u16 val;
clk_enable(clk);
val = readw(virtbase + U300_WDOG_IER);
if (val == U300_WDOG_IER_WILL_BARK_IRQ_EVENT_IND)
writew(U300_WDOG_IER_WILL_BARK_IRQ_ACK_ENABLE,
virtbase + U300_WDOG_IER);
writew(0x0000U, virtbase + U300_WDOG_IMR);
clk_disable(clk);
dev_crit(parent, "watchdog is barking!\n");
return IRQ_HANDLED;
}
static int coh901327_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(1, &coh901327_users))
return -EBUSY;
coh901327_start();
return nonseekable_open(inode, file);
}
static int coh901327_release(struct inode *inode, struct file *file)
{
clear_bit(1, &coh901327_users);
coh901327_disable();
return 0;
}
static ssize_t coh901327_write(struct file *file, const char __user *data,
size_t len, loff_t *ppos)
{
if (len)
coh901327_keepalive();
return len;
}
static long coh901327_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int ret = -ENOTTY;
u16 val;
int time;
int new_options;
union {
struct watchdog_info __user *ident;
int __user *i;
} uarg;
static const struct watchdog_info ident = {
.options = WDIOF_CARDRESET |
WDIOF_SETTIMEOUT |
WDIOF_KEEPALIVEPING,
.identity = "COH 901 327 Watchdog",
.firmware_version = 1,
};
uarg.i = (int __user *)arg;
switch (cmd) {
case WDIOC_GETSUPPORT:
ret = copy_to_user(uarg.ident, &ident,
sizeof(ident)) ? -EFAULT : 0;
break;
case WDIOC_GETSTATUS:
ret = put_user(0, uarg.i);
break;
case WDIOC_GETBOOTSTATUS:
ret = put_user(boot_status, uarg.i);
break;
case WDIOC_SETOPTIONS:
ret = get_user(new_options, uarg.i);
if (ret)
break;
if (new_options & WDIOS_DISABLECARD)
coh901327_disable();
if (new_options & WDIOS_ENABLECARD)
coh901327_start();
ret = 0;
break;
case WDIOC_KEEPALIVE:
coh901327_keepalive();
ret = 0;
break;
case WDIOC_SETTIMEOUT:
ret = get_user(time, uarg.i);
if (ret)
break;
ret = coh901327_settimeout(time);
if (ret)
break;
case WDIOC_GETTIMEOUT:
ret = put_user(margin, uarg.i);
break;
case WDIOC_GETTIMELEFT:
clk_enable(clk);
val = readw(virtbase + U300_WDOG_CR);
while (val & U300_WDOG_CR_VALID_IND)
val = readw(virtbase + U300_WDOG_CR);
val &= U300_WDOG_CR_COUNT_VALUE_MASK;
clk_disable(clk);
if (val != 0)
val /= 100;
ret = put_user(val, uarg.i);
break;
}
return ret;
}
static int __exit coh901327_remove(struct platform_device *pdev)
{
misc_deregister(&coh901327_miscdev);
coh901327_disable();
free_irq(irq, pdev);
clk_put(clk);
iounmap(virtbase);
release_mem_region(phybase, physize);
return 0;
}
static int __init coh901327_probe(struct platform_device *pdev)
{
int ret;
u16 val;
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENOENT;
parent = &pdev->dev;
physize = resource_size(res);
phybase = res->start;
if (request_mem_region(phybase, physize, DRV_NAME) == NULL) {
ret = -EBUSY;
goto out;
}
virtbase = ioremap(phybase, physize);
if (!virtbase) {
ret = -ENOMEM;
goto out_no_remap;
}
clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
ret = PTR_ERR(clk);
dev_err(&pdev->dev, "could not get clock\n");
goto out_no_clk;
}
ret = clk_enable(clk);
if (ret) {
dev_err(&pdev->dev, "could not enable clock\n");
goto out_no_clk_enable;
}
val = readw(virtbase + U300_WDOG_SR);
switch (val) {
case U300_WDOG_SR_STATUS_TIMED_OUT:
dev_info(&pdev->dev,
"watchdog timed out since last chip reset!\n");
boot_status = WDIOF_CARDRESET;
break;
case U300_WDOG_SR_STATUS_NORMAL:
dev_info(&pdev->dev,
"in normal status, no timeouts have occurred.\n");
break;
default:
dev_info(&pdev->dev,
"contains an illegal status code (%08x)\n", val);
break;
}
val = readw(virtbase + U300_WDOG_D2R);
switch (val) {
case U300_WDOG_D2R_DISABLE_STATUS_DISABLED:
dev_info(&pdev->dev, "currently disabled.\n");
break;
case U300_WDOG_D2R_DISABLE_STATUS_ENABLED:
dev_info(&pdev->dev,
"currently enabled! (disabling it now)\n");
coh901327_disable();
break;
default:
dev_err(&pdev->dev,
"contains an illegal enable/disable code (%08x)\n",
val);
break;
}
writew(U300_WDOG_SR_RESET_STATUS_RESET, virtbase + U300_WDOG_SR);
irq = platform_get_irq(pdev, 0);
if (request_irq(irq, coh901327_interrupt, 0,
DRV_NAME " Bark", pdev)) {
ret = -EIO;
goto out_no_irq;
}
clk_disable(clk);
ret = misc_register(&coh901327_miscdev);
if (ret == 0)
dev_info(&pdev->dev,
"initialized. timer margin=%d sec\n", margin);
else
goto out_no_wdog;
return 0;
out_no_wdog:
free_irq(irq, pdev);
out_no_irq:
clk_disable(clk);
out_no_clk_enable:
clk_put(clk);
out_no_clk:
iounmap(virtbase);
out_no_remap:
release_mem_region(phybase, SZ_4K);
out:
return ret;
}
static int coh901327_suspend(struct platform_device *pdev, pm_message_t state)
{
irqmaskstore = readw(virtbase + U300_WDOG_IMR) & 0x0001U;
wdogenablestore = readw(virtbase + U300_WDOG_D2R);
if (wdogenablestore == U300_WDOG_D2R_DISABLE_STATUS_ENABLED)
coh901327_disable();
return 0;
}
static int coh901327_resume(struct platform_device *pdev)
{
writew(irqmaskstore, virtbase + U300_WDOG_IMR);
if (wdogenablestore == U300_WDOG_D2R_DISABLE_STATUS_ENABLED) {
writew(U300_WDOG_RR_RESTART_VALUE_RESUME,
virtbase + U300_WDOG_RR);
writew(U300_WDOG_FR_FEED_RESTART_TIMER,
virtbase + U300_WDOG_FR);
}
return 0;
}
void coh901327_watchdog_reset(void)
{
writew(U300_WDOG_JOR_JTAG_WATCHDOG_ENABLE,
virtbase + U300_WDOG_JOR);
coh901327_enable(500);
}
static int __init coh901327_init(void)
{
return platform_driver_probe(&coh901327_driver, coh901327_probe);
}
static void __exit coh901327_exit(void)
{
platform_driver_unregister(&coh901327_driver);
}
