static void ar7_wdt_kick(u32 value)
{
WRITE_REG(ar7_wdt->kick_lock, 0x5555);
if ((READ_REG(ar7_wdt->kick_lock) & 3) == 1) {
WRITE_REG(ar7_wdt->kick_lock, 0xaaaa);
if ((READ_REG(ar7_wdt->kick_lock) & 3) == 3) {
WRITE_REG(ar7_wdt->kick, value);
return;
}
}
pr_err("failed to unlock WDT kick reg\n");
}
static void ar7_wdt_prescale(u32 value)
{
WRITE_REG(ar7_wdt->prescale_lock, 0x5a5a);
if ((READ_REG(ar7_wdt->prescale_lock) & 3) == 1) {
WRITE_REG(ar7_wdt->prescale_lock, 0xa5a5);
if ((READ_REG(ar7_wdt->prescale_lock) & 3) == 3) {
WRITE_REG(ar7_wdt->prescale, value);
return;
}
}
pr_err("failed to unlock WDT prescale reg\n");
}
static void ar7_wdt_change(u32 value)
{
WRITE_REG(ar7_wdt->change_lock, 0x6666);
if ((READ_REG(ar7_wdt->change_lock) & 3) == 1) {
WRITE_REG(ar7_wdt->change_lock, 0xbbbb);
if ((READ_REG(ar7_wdt->change_lock) & 3) == 3) {
WRITE_REG(ar7_wdt->change, value);
return;
}
}
pr_err("failed to unlock WDT change reg\n");
}
static void ar7_wdt_disable(u32 value)
{
WRITE_REG(ar7_wdt->disable_lock, 0x7777);
if ((READ_REG(ar7_wdt->disable_lock) & 3) == 1) {
WRITE_REG(ar7_wdt->disable_lock, 0xcccc);
if ((READ_REG(ar7_wdt->disable_lock) & 3) == 2) {
WRITE_REG(ar7_wdt->disable_lock, 0xdddd);
if ((READ_REG(ar7_wdt->disable_lock) & 3) == 3) {
WRITE_REG(ar7_wdt->disable, value);
return;
}
}
}
pr_err("failed to unlock WDT disable reg\n");
}
static void ar7_wdt_update_margin(int new_margin)
{
u32 change;
u32 vbus_rate;
vbus_rate = clk_get_rate(vbus_clk);
change = new_margin * (vbus_rate / prescale_value);
if (change < 1)
change = 1;
if (change > 0xffff)
change = 0xffff;
ar7_wdt_change(change);
margin = change * prescale_value / vbus_rate;
pr_info("timer margin %d seconds (prescale %d, change %d, freq %d)\n",
margin, prescale_value, change, vbus_rate);
}
static void ar7_wdt_enable_wdt(void)
{
pr_debug("enabling watchdog timer\n");
ar7_wdt_disable(1);
ar7_wdt_kick(1);
}
static void ar7_wdt_disable_wdt(void)
{
pr_debug("disabling watchdog timer\n");
ar7_wdt_disable(0);
}
static int ar7_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(0, &wdt_is_open))
return -EBUSY;
ar7_wdt_enable_wdt();
expect_close = 0;
return nonseekable_open(inode, file);
}
static int ar7_wdt_release(struct inode *inode, struct file *file)
{
if (!expect_close)
pr_warn("watchdog device closed unexpectedly, will not disable the watchdog timer\n");
else if (!nowayout)
ar7_wdt_disable_wdt();
clear_bit(0, &wdt_is_open);
return 0;
}
static ssize_t ar7_wdt_write(struct file *file, const char *data,
size_t len, loff_t *ppos)
{
if (len) {
size_t i;
spin_lock(&wdt_lock);
ar7_wdt_kick(1);
spin_unlock(&wdt_lock);
expect_close = 0;
for (i = 0; i < len; ++i) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
expect_close = 1;
}
}
return len;
}
static long ar7_wdt_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
static const struct watchdog_info ident = {
.identity = LONGNAME,
.firmware_version = 1,
.options = (WDIOF_SETTIMEOUT | WDIOF_KEEPALIVEPING |
WDIOF_MAGICCLOSE),
};
int new_margin;
switch (cmd) {
case WDIOC_GETSUPPORT:
if (copy_to_user((struct watchdog_info *)arg, &ident,
sizeof(ident)))
return -EFAULT;
return 0;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
if (put_user(0, (int *)arg))
return -EFAULT;
return 0;
case WDIOC_KEEPALIVE:
ar7_wdt_kick(1);
return 0;
case WDIOC_SETTIMEOUT:
if (get_user(new_margin, (int *)arg))
return -EFAULT;
if (new_margin < 1)
return -EINVAL;
spin_lock(&wdt_lock);
ar7_wdt_update_margin(new_margin);
ar7_wdt_kick(1);
spin_unlock(&wdt_lock);
case WDIOC_GETTIMEOUT:
if (put_user(margin, (int *)arg))
return -EFAULT;
return 0;
default:
return -ENOTTY;
}
}
static int ar7_wdt_probe(struct platform_device *pdev)
{
int rc;
ar7_regs_wdt =
platform_get_resource_byname(pdev, IORESOURCE_MEM, "regs");
if (!ar7_regs_wdt) {
pr_err("could not get registers resource\n");
return -ENODEV;
}
ar7_wdt = devm_request_and_ioremap(&pdev->dev, ar7_regs_wdt);
if (!ar7_wdt) {
pr_err("could not ioremap registers\n");
return -ENXIO;
}
vbus_clk = clk_get(NULL, "vbus");
if (IS_ERR(vbus_clk)) {
pr_err("could not get vbus clock\n");
return PTR_ERR(vbus_clk);
}
ar7_wdt_disable_wdt();
ar7_wdt_prescale(prescale_value);
ar7_wdt_update_margin(margin);
rc = misc_register(&ar7_wdt_miscdev);
if (rc) {
pr_err("unable to register misc device\n");
goto out;
}
return 0;
out:
clk_put(vbus_clk);
vbus_clk = NULL;
return rc;
}
static int ar7_wdt_remove(struct platform_device *pdev)
{
misc_deregister(&ar7_wdt_miscdev);
clk_put(vbus_clk);
vbus_clk = NULL;
return 0;
}
static void ar7_wdt_shutdown(struct platform_device *pdev)
{
if (!nowayout)
ar7_wdt_disable_wdt();
}
