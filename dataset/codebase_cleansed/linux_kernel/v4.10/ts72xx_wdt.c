static int timeout_to_regval(int new_timeout)
{
int i;
new_timeout = clamp_val(new_timeout, 1, 8);
for (i = 0; i < ARRAY_SIZE(ts72xx_wdt_map); i++) {
if (ts72xx_wdt_map[i].timeout >= new_timeout)
return ts72xx_wdt_map[i].regval;
}
return -EINVAL;
}
static int regval_to_timeout(int regval)
{
int i;
for (i = 0; i < ARRAY_SIZE(ts72xx_wdt_map); i++) {
if (ts72xx_wdt_map[i].regval == regval)
return ts72xx_wdt_map[i].timeout;
}
return -EINVAL;
}
static inline void ts72xx_wdt_kick(struct ts72xx_wdt *wdt)
{
__raw_writeb(TS72XX_WDT_FEED_VAL, wdt->feed_reg);
}
static void ts72xx_wdt_start(struct ts72xx_wdt *wdt)
{
ts72xx_wdt_kick(wdt);
__raw_writeb((u8)wdt->regval, wdt->control_reg);
}
static void ts72xx_wdt_stop(struct ts72xx_wdt *wdt)
{
ts72xx_wdt_kick(wdt);
__raw_writeb(0, wdt->control_reg);
}
static int ts72xx_wdt_open(struct inode *inode, struct file *file)
{
struct ts72xx_wdt *wdt = platform_get_drvdata(ts72xx_wdt_pdev);
int regval;
regval = timeout_to_regval(timeout);
if (regval < 0) {
dev_err(&wdt->pdev->dev,
"failed to convert timeout (%d) to register value\n",
timeout);
return regval;
}
if (mutex_lock_interruptible(&wdt->lock))
return -ERESTARTSYS;
if ((wdt->flags & TS72XX_WDT_BUSY_FLAG) != 0) {
mutex_unlock(&wdt->lock);
return -EBUSY;
}
wdt->flags = TS72XX_WDT_BUSY_FLAG;
wdt->regval = regval;
file->private_data = wdt;
ts72xx_wdt_start(wdt);
mutex_unlock(&wdt->lock);
return nonseekable_open(inode, file);
}
static int ts72xx_wdt_release(struct inode *inode, struct file *file)
{
struct ts72xx_wdt *wdt = file->private_data;
if (mutex_lock_interruptible(&wdt->lock))
return -ERESTARTSYS;
if ((wdt->flags & TS72XX_WDT_EXPECT_CLOSE_FLAG) != 0) {
ts72xx_wdt_stop(wdt);
} else {
dev_warn(&wdt->pdev->dev,
"TS-72XX WDT device closed unexpectly. "
"Watchdog timer will not stop!\n");
ts72xx_wdt_kick(wdt);
}
wdt->flags = 0;
mutex_unlock(&wdt->lock);
return 0;
}
static ssize_t ts72xx_wdt_write(struct file *file,
const char __user *data,
size_t len,
loff_t *ppos)
{
struct ts72xx_wdt *wdt = file->private_data;
if (!len)
return 0;
if (mutex_lock_interruptible(&wdt->lock))
return -ERESTARTSYS;
ts72xx_wdt_kick(wdt);
if (!nowayout) {
int i;
for (i = 0; i < len; i++) {
char c;
wdt->flags &= ~TS72XX_WDT_EXPECT_CLOSE_FLAG;
if (get_user(c, data + i)) {
mutex_unlock(&wdt->lock);
return -EFAULT;
}
if (c == 'V') {
wdt->flags |= TS72XX_WDT_EXPECT_CLOSE_FLAG;
break;
}
}
}
mutex_unlock(&wdt->lock);
return len;
}
static long ts72xx_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct ts72xx_wdt *wdt = file->private_data;
void __user *argp = (void __user *)arg;
int __user *p = (int __user *)argp;
int error = 0;
if (mutex_lock_interruptible(&wdt->lock))
return -ERESTARTSYS;
switch (cmd) {
case WDIOC_GETSUPPORT:
if (copy_to_user(argp, &winfo, sizeof(winfo)))
error = -EFAULT;
break;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
error = put_user(0, p);
break;
case WDIOC_KEEPALIVE:
ts72xx_wdt_kick(wdt);
break;
case WDIOC_SETOPTIONS: {
int options;
error = get_user(options, p);
if (error)
break;
error = -EINVAL;
if ((options & WDIOS_DISABLECARD) != 0) {
ts72xx_wdt_stop(wdt);
error = 0;
}
if ((options & WDIOS_ENABLECARD) != 0) {
ts72xx_wdt_start(wdt);
error = 0;
}
break;
}
case WDIOC_SETTIMEOUT: {
int new_timeout;
int regval;
error = get_user(new_timeout, p);
if (error)
break;
regval = timeout_to_regval(new_timeout);
if (regval < 0) {
error = regval;
break;
}
ts72xx_wdt_stop(wdt);
wdt->regval = regval;
ts72xx_wdt_start(wdt);
}
case WDIOC_GETTIMEOUT:
error = put_user(regval_to_timeout(wdt->regval), p);
break;
default:
error = -ENOTTY;
break;
}
mutex_unlock(&wdt->lock);
return error;
}
static int ts72xx_wdt_probe(struct platform_device *pdev)
{
struct ts72xx_wdt *wdt;
struct resource *r1, *r2;
int error = 0;
wdt = devm_kzalloc(&pdev->dev, sizeof(struct ts72xx_wdt), GFP_KERNEL);
if (!wdt)
return -ENOMEM;
r1 = platform_get_resource(pdev, IORESOURCE_MEM, 0);
wdt->control_reg = devm_ioremap_resource(&pdev->dev, r1);
if (IS_ERR(wdt->control_reg))
return PTR_ERR(wdt->control_reg);
r2 = platform_get_resource(pdev, IORESOURCE_MEM, 1);
wdt->feed_reg = devm_ioremap_resource(&pdev->dev, r2);
if (IS_ERR(wdt->feed_reg))
return PTR_ERR(wdt->feed_reg);
platform_set_drvdata(pdev, wdt);
ts72xx_wdt_pdev = pdev;
wdt->pdev = pdev;
mutex_init(&wdt->lock);
ts72xx_wdt_stop(wdt);
error = misc_register(&ts72xx_wdt_miscdev);
if (error) {
dev_err(&pdev->dev, "failed to register miscdev\n");
return error;
}
dev_info(&pdev->dev, "TS-72xx Watchdog driver\n");
return 0;
}
static int ts72xx_wdt_remove(struct platform_device *pdev)
{
misc_deregister(&ts72xx_wdt_miscdev);
return 0;
}
