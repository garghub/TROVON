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
return -EINVAL;
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
error = copy_to_user(argp, &winfo, sizeof(winfo));
break;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
return put_user(0, p);
case WDIOC_KEEPALIVE:
ts72xx_wdt_kick(wdt);
break;
case WDIOC_SETOPTIONS: {
int options;
if (get_user(options, p)) {
error = -EFAULT;
break;
}
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
if (get_user(new_timeout, p)) {
error = -EFAULT;
} else {
int regval;
regval = timeout_to_regval(new_timeout);
if (regval < 0) {
error = -EINVAL;
} else {
ts72xx_wdt_stop(wdt);
wdt->regval = regval;
ts72xx_wdt_start(wdt);
}
}
if (error)
break;
}
case WDIOC_GETTIMEOUT:
if (put_user(regval_to_timeout(wdt->regval), p))
error = -EFAULT;
break;
default:
error = -ENOTTY;
break;
}
mutex_unlock(&wdt->lock);
return error;
}
static __devinit int ts72xx_wdt_probe(struct platform_device *pdev)
{
struct ts72xx_wdt *wdt;
struct resource *r1, *r2;
int error = 0;
wdt = kzalloc(sizeof(struct ts72xx_wdt), GFP_KERNEL);
if (!wdt) {
dev_err(&pdev->dev, "failed to allocate memory\n");
return -ENOMEM;
}
r1 = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r1) {
dev_err(&pdev->dev, "failed to get memory resource\n");
error = -ENODEV;
goto fail;
}
r1 = request_mem_region(r1->start, resource_size(r1), pdev->name);
if (!r1) {
dev_err(&pdev->dev, "cannot request memory region\n");
error = -EBUSY;
goto fail;
}
wdt->control_reg = ioremap(r1->start, resource_size(r1));
if (!wdt->control_reg) {
dev_err(&pdev->dev, "failed to map memory\n");
error = -ENODEV;
goto fail_free_control;
}
r2 = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!r2) {
dev_err(&pdev->dev, "failed to get memory resource\n");
error = -ENODEV;
goto fail_unmap_control;
}
r2 = request_mem_region(r2->start, resource_size(r2), pdev->name);
if (!r2) {
dev_err(&pdev->dev, "cannot request memory region\n");
error = -EBUSY;
goto fail_unmap_control;
}
wdt->feed_reg = ioremap(r2->start, resource_size(r2));
if (!wdt->feed_reg) {
dev_err(&pdev->dev, "failed to map memory\n");
error = -ENODEV;
goto fail_free_feed;
}
platform_set_drvdata(pdev, wdt);
ts72xx_wdt_pdev = pdev;
wdt->pdev = pdev;
mutex_init(&wdt->lock);
ts72xx_wdt_stop(wdt);
error = misc_register(&ts72xx_wdt_miscdev);
if (error) {
dev_err(&pdev->dev, "failed to register miscdev\n");
goto fail_unmap_feed;
}
dev_info(&pdev->dev, "TS-72xx Watchdog driver\n");
return 0;
fail_unmap_feed:
platform_set_drvdata(pdev, NULL);
iounmap(wdt->feed_reg);
fail_free_feed:
release_mem_region(r2->start, resource_size(r2));
fail_unmap_control:
iounmap(wdt->control_reg);
fail_free_control:
release_mem_region(r1->start, resource_size(r1));
fail:
kfree(wdt);
return error;
}
static __devexit int ts72xx_wdt_remove(struct platform_device *pdev)
{
struct ts72xx_wdt *wdt = platform_get_drvdata(pdev);
struct resource *res;
int error;
error = misc_deregister(&ts72xx_wdt_miscdev);
platform_set_drvdata(pdev, NULL);
iounmap(wdt->feed_reg);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
release_mem_region(res->start, resource_size(res));
iounmap(wdt->control_reg);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
kfree(wdt);
return error;
}
