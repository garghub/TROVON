static void wdt_setload(unsigned int timeout)
{
u64 load, rate;
rate = clk_get_rate(wdt->clk);
load = div_u64(rate, 2) * timeout - 1;
load = (load > LOAD_MAX) ? LOAD_MAX : load;
load = (load < LOAD_MIN) ? LOAD_MIN : load;
spin_lock(&wdt->lock);
wdt->load_val = load;
wdt->timeout = div_u64((load + 1) * 2 + (rate / 2), rate);
spin_unlock(&wdt->lock);
}
static u32 wdt_timeleft(void)
{
u64 load, rate;
rate = clk_get_rate(wdt->clk);
spin_lock(&wdt->lock);
load = readl_relaxed(wdt->base + WDTVALUE);
if (!(readl_relaxed(wdt->base + WDTRIS) & INT_MASK))
load += wdt->load_val + 1;
spin_unlock(&wdt->lock);
return div_u64(load, rate);
}
static void wdt_enable(void)
{
spin_lock(&wdt->lock);
writel_relaxed(UNLOCK, wdt->base + WDTLOCK);
writel_relaxed(wdt->load_val, wdt->base + WDTLOAD);
writel_relaxed(INT_MASK, wdt->base + WDTINTCLR);
writel_relaxed(INT_ENABLE | RESET_ENABLE, wdt->base + WDTCONTROL);
writel_relaxed(LOCK, wdt->base + WDTLOCK);
readl_relaxed(wdt->base + WDTLOCK);
spin_unlock(&wdt->lock);
}
static void wdt_disable(void)
{
spin_lock(&wdt->lock);
writel_relaxed(UNLOCK, wdt->base + WDTLOCK);
writel_relaxed(0, wdt->base + WDTCONTROL);
writel_relaxed(LOCK, wdt->base + WDTLOCK);
readl_relaxed(wdt->base + WDTLOCK);
spin_unlock(&wdt->lock);
}
static ssize_t sp805_wdt_write(struct file *file, const char *data,
size_t len, loff_t *ppos)
{
if (len) {
if (!nowayout) {
size_t i;
clear_bit(WDT_CAN_BE_CLOSED, &wdt->status);
for (i = 0; i != len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V') {
set_bit(WDT_CAN_BE_CLOSED,
&wdt->status);
break;
}
}
}
wdt_enable();
}
return len;
}
static long sp805_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int ret = -ENOTTY;
unsigned int timeout;
switch (cmd) {
case WDIOC_GETSUPPORT:
ret = copy_to_user((struct watchdog_info *)arg, &ident,
sizeof(ident)) ? -EFAULT : 0;
break;
case WDIOC_GETSTATUS:
ret = put_user(0, (int *)arg);
break;
case WDIOC_KEEPALIVE:
wdt_enable();
ret = 0;
break;
case WDIOC_SETTIMEOUT:
ret = get_user(timeout, (unsigned int *)arg);
if (ret)
break;
wdt_setload(timeout);
wdt_enable();
case WDIOC_GETTIMEOUT:
ret = put_user(wdt->timeout, (unsigned int *)arg);
break;
case WDIOC_GETTIMELEFT:
ret = put_user(wdt_timeleft(), (unsigned int *)arg);
break;
}
return ret;
}
static int sp805_wdt_open(struct inode *inode, struct file *file)
{
int ret = 0;
if (test_and_set_bit(WDT_BUSY, &wdt->status))
return -EBUSY;
ret = clk_enable(wdt->clk);
if (ret) {
dev_err(&wdt->adev->dev, "clock enable fail");
goto err;
}
wdt_enable();
clear_bit(WDT_CAN_BE_CLOSED, &wdt->status);
return nonseekable_open(inode, file);
err:
clear_bit(WDT_BUSY, &wdt->status);
return ret;
}
static int sp805_wdt_release(struct inode *inode, struct file *file)
{
if (!test_bit(WDT_CAN_BE_CLOSED, &wdt->status)) {
clear_bit(WDT_BUSY, &wdt->status);
dev_warn(&wdt->adev->dev, "Device closed unexpectedly\n");
return 0;
}
wdt_disable();
clk_disable(wdt->clk);
clear_bit(WDT_BUSY, &wdt->status);
return 0;
}
static int __devinit
sp805_wdt_probe(struct amba_device *adev, const struct amba_id *id)
{
int ret = 0;
if (!devm_request_mem_region(&adev->dev, adev->res.start,
resource_size(&adev->res), "sp805_wdt")) {
dev_warn(&adev->dev, "Failed to get memory region resource\n");
ret = -ENOENT;
goto err;
}
wdt = devm_kzalloc(&adev->dev, sizeof(*wdt), GFP_KERNEL);
if (!wdt) {
dev_warn(&adev->dev, "Kzalloc failed\n");
ret = -ENOMEM;
goto err;
}
wdt->base = devm_ioremap(&adev->dev, adev->res.start,
resource_size(&adev->res));
if (!wdt->base) {
ret = -ENOMEM;
dev_warn(&adev->dev, "ioremap fail\n");
goto err;
}
wdt->clk = clk_get(&adev->dev, NULL);
if (IS_ERR(wdt->clk)) {
dev_warn(&adev->dev, "Clock not found\n");
ret = PTR_ERR(wdt->clk);
goto err;
}
wdt->adev = adev;
spin_lock_init(&wdt->lock);
wdt_setload(DEFAULT_TIMEOUT);
ret = misc_register(&sp805_wdt_miscdev);
if (ret < 0) {
dev_warn(&adev->dev, "cannot register misc device\n");
goto err_misc_register;
}
dev_info(&adev->dev, "registration successful\n");
return 0;
err_misc_register:
clk_put(wdt->clk);
err:
dev_err(&adev->dev, "Probe Failed!!!\n");
return ret;
}
static int __devexit sp805_wdt_remove(struct amba_device *adev)
{
misc_deregister(&sp805_wdt_miscdev);
clk_put(wdt->clk);
return 0;
}
static int sp805_wdt_suspend(struct device *dev)
{
if (test_bit(WDT_BUSY, &wdt->status)) {
wdt_disable();
clk_disable(wdt->clk);
}
return 0;
}
static int sp805_wdt_resume(struct device *dev)
{
int ret = 0;
if (test_bit(WDT_BUSY, &wdt->status)) {
ret = clk_enable(wdt->clk);
if (ret) {
dev_err(dev, "clock enable fail");
return ret;
}
wdt_enable();
}
return ret;
}
