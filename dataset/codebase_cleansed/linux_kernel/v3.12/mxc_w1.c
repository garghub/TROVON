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
static int mxc_w1_probe(struct platform_device *pdev)
{
struct mxc_w1_device *mdev;
struct resource *res;
int err = 0;
mdev = devm_kzalloc(&pdev->dev, sizeof(struct mxc_w1_device),
GFP_KERNEL);
if (!mdev)
return -ENOMEM;
mdev->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(mdev->clk))
return PTR_ERR(mdev->clk);
mdev->clkdiv = (clk_get_rate(mdev->clk) / 1000000) - 1;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mdev->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mdev->regs))
return PTR_ERR(mdev->regs);
clk_prepare_enable(mdev->clk);
__raw_writeb(mdev->clkdiv, mdev->regs + MXC_W1_TIME_DIVIDER);
mdev->bus_master.data = mdev;
mdev->bus_master.reset_bus = mxc_w1_ds2_reset_bus;
mdev->bus_master.touch_bit = mxc_w1_ds2_touch_bit;
err = w1_add_master_device(&mdev->bus_master);
if (err)
return err;
platform_set_drvdata(pdev, mdev);
return 0;
}
static int mxc_w1_remove(struct platform_device *pdev)
{
struct mxc_w1_device *mdev = platform_get_drvdata(pdev);
w1_remove_master_device(&mdev->bus_master);
clk_disable_unprepare(mdev->clk);
return 0;
}
