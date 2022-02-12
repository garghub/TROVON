static u8 mxc_w1_ds2_reset_bus(void *data)
{
u8 reg_val;
unsigned int timeout_cnt = 0;
struct mxc_w1_device *dev = data;
__raw_writeb(0x80, (dev->regs + MXC_W1_CONTROL));
while (1) {
reg_val = __raw_readb(dev->regs + MXC_W1_CONTROL);
if (((reg_val >> 7) & 0x1) == 0 ||
timeout_cnt > MXC_W1_RESET_TIMEOUT)
break;
else
timeout_cnt++;
udelay(100);
}
return (reg_val >> 7) & 0x1;
}
static u8 mxc_w1_ds2_touch_bit(void *data, u8 bit)
{
struct mxc_w1_device *mdev = data;
void __iomem *ctrl_addr = mdev->regs + MXC_W1_CONTROL;
unsigned int timeout_cnt = 400;
__raw_writeb((1 << (5 - bit)), ctrl_addr);
while (timeout_cnt--) {
if (!((__raw_readb(ctrl_addr) >> (5 - bit)) & 0x1))
break;
udelay(1);
}
return ((__raw_readb(ctrl_addr)) >> 3) & 0x1;
}
static int __devinit mxc_w1_probe(struct platform_device *pdev)
{
struct mxc_w1_device *mdev;
struct resource *res;
int err = 0;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
mdev = kzalloc(sizeof(struct mxc_w1_device), GFP_KERNEL);
if (!mdev)
return -ENOMEM;
mdev->clk = clk_get(&pdev->dev, "owire");
if (!mdev->clk) {
err = -ENODEV;
goto failed_clk;
}
mdev->clkdiv = (clk_get_rate(mdev->clk) / 1000000) - 1;
res = request_mem_region(res->start, resource_size(res),
"mxc_w1");
if (!res) {
err = -EBUSY;
goto failed_req;
}
mdev->regs = ioremap(res->start, resource_size(res));
if (!mdev->regs) {
printk(KERN_ERR "Cannot map frame buffer registers\n");
goto failed_ioremap;
}
clk_prepare_enable(mdev->clk);
__raw_writeb(mdev->clkdiv, mdev->regs + MXC_W1_TIME_DIVIDER);
mdev->bus_master.data = mdev;
mdev->bus_master.reset_bus = mxc_w1_ds2_reset_bus;
mdev->bus_master.touch_bit = mxc_w1_ds2_touch_bit;
err = w1_add_master_device(&mdev->bus_master);
if (err)
goto failed_add;
platform_set_drvdata(pdev, mdev);
return 0;
failed_add:
iounmap(mdev->regs);
failed_ioremap:
release_mem_region(res->start, resource_size(res));
failed_req:
clk_put(mdev->clk);
failed_clk:
kfree(mdev);
return err;
}
static int __devexit mxc_w1_remove(struct platform_device *pdev)
{
struct mxc_w1_device *mdev = platform_get_drvdata(pdev);
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
w1_remove_master_device(&mdev->bus_master);
iounmap(mdev->regs);
release_mem_region(res->start, resource_size(res));
clk_disable_unprepare(mdev->clk);
clk_put(mdev->clk);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int __init mxc_w1_init(void)
{
return platform_driver_register(&mxc_w1_driver);
}
static void mxc_w1_exit(void)
{
platform_driver_unregister(&mxc_w1_driver);
}
