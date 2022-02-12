static struct max63xx_timeout *
max63xx_select_timeout(struct max63xx_timeout *table, int value)
{
while (table->twd) {
if (value <= table->twd) {
if (nodelay && table->tdelay == 0)
return table;
if (!nodelay)
return table;
}
table++;
}
return NULL;
}
static void max63xx_wdt_ping(void)
{
u8 val;
spin_lock(&io_lock);
val = __raw_readb(wdt_base);
__raw_writeb(val | MAX6369_WDI, wdt_base);
__raw_writeb(val & ~MAX6369_WDI, wdt_base);
spin_unlock(&io_lock);
}
static void max63xx_wdt_enable(struct max63xx_timeout *entry)
{
u8 val;
if (test_and_set_bit(WDT_RUNNING, &wdt_status))
return;
spin_lock(&io_lock);
val = __raw_readb(wdt_base);
val &= ~MAX6369_WDSET;
val |= entry->wdset;
__raw_writeb(val, wdt_base);
spin_unlock(&io_lock);
if (entry->tdelay == 0)
max63xx_wdt_ping();
}
static void max63xx_wdt_disable(void)
{
u8 val;
spin_lock(&io_lock);
val = __raw_readb(wdt_base);
val &= ~MAX6369_WDSET;
val |= 3;
__raw_writeb(val, wdt_base);
spin_unlock(&io_lock);
clear_bit(WDT_RUNNING, &wdt_status);
}
static int max63xx_wdt_open(struct inode *inode, struct file *file)
{
if (test_and_set_bit(WDT_IN_USE, &wdt_status))
return -EBUSY;
max63xx_wdt_enable(current_timeout);
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
return nonseekable_open(inode, file);
}
static ssize_t max63xx_wdt_write(struct file *file, const char *data,
size_t len, loff_t *ppos)
{
if (len) {
if (!nowayout) {
size_t i;
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
for (i = 0; i != len; i++) {
char c;
if (get_user(c, data + i))
return -EFAULT;
if (c == 'V')
set_bit(WDT_OK_TO_CLOSE, &wdt_status);
}
}
max63xx_wdt_ping();
}
return len;
}
static long max63xx_wdt_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int ret = -ENOTTY;
switch (cmd) {
case WDIOC_GETSUPPORT:
ret = copy_to_user((struct watchdog_info *)arg, &ident,
sizeof(ident)) ? -EFAULT : 0;
break;
case WDIOC_GETSTATUS:
case WDIOC_GETBOOTSTATUS:
ret = put_user(0, (int *)arg);
break;
case WDIOC_KEEPALIVE:
max63xx_wdt_ping();
ret = 0;
break;
case WDIOC_GETTIMEOUT:
ret = put_user(heartbeat, (int *)arg);
break;
}
return ret;
}
static int max63xx_wdt_release(struct inode *inode, struct file *file)
{
if (test_bit(WDT_OK_TO_CLOSE, &wdt_status))
max63xx_wdt_disable();
else
dev_crit(&max63xx_pdev->dev,
"device closed unexpectedly - timer will not stop\n");
clear_bit(WDT_IN_USE, &wdt_status);
clear_bit(WDT_OK_TO_CLOSE, &wdt_status);
return 0;
}
static int __devinit max63xx_wdt_probe(struct platform_device *pdev)
{
int ret = 0;
int size;
struct device *dev = &pdev->dev;
struct max63xx_timeout *table;
table = (struct max63xx_timeout *)pdev->id_entry->driver_data;
if (heartbeat < 1 || heartbeat > MAX_HEARTBEAT)
heartbeat = DEFAULT_HEARTBEAT;
dev_info(dev, "requesting %ds heartbeat\n", heartbeat);
current_timeout = max63xx_select_timeout(table, heartbeat);
if (!current_timeout) {
dev_err(dev, "unable to satisfy heartbeat request\n");
return -EINVAL;
}
dev_info(dev, "using %ds heartbeat with %ds initial delay\n",
current_timeout->twd, current_timeout->tdelay);
heartbeat = current_timeout->twd;
max63xx_pdev = pdev;
wdt_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (wdt_mem == NULL) {
dev_err(dev, "failed to get memory region resource\n");
return -ENOENT;
}
size = resource_size(wdt_mem);
if (!request_mem_region(wdt_mem->start, size, pdev->name)) {
dev_err(dev, "failed to get memory region\n");
return -ENOENT;
}
wdt_base = ioremap(wdt_mem->start, size);
if (!wdt_base) {
dev_err(dev, "failed to map memory region\n");
ret = -ENOMEM;
goto out_request;
}
ret = misc_register(&max63xx_wdt_miscdev);
if (ret < 0) {
dev_err(dev, "cannot register misc device\n");
goto out_unmap;
}
return 0;
out_unmap:
iounmap(wdt_base);
out_request:
release_mem_region(wdt_mem->start, size);
wdt_mem = NULL;
return ret;
}
static int __devexit max63xx_wdt_remove(struct platform_device *pdev)
{
misc_deregister(&max63xx_wdt_miscdev);
if (wdt_mem) {
release_mem_region(wdt_mem->start, resource_size(wdt_mem));
wdt_mem = NULL;
}
if (wdt_base)
iounmap(wdt_base);
return 0;
}
static int __init max63xx_wdt_init(void)
{
return platform_driver_register(&max63xx_wdt_driver);
}
static void __exit max63xx_wdt_exit(void)
{
platform_driver_unregister(&max63xx_wdt_driver);
}
