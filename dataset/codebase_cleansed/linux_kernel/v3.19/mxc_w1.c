static u8 mxc_w1_ds2_reset_bus(void *data)
{
struct mxc_w1_device *dev = data;
unsigned long timeout;
writeb(MXC_W1_CONTROL_RPP, dev->regs + MXC_W1_CONTROL);
timeout = jiffies + usecs_to_jiffies(1500);
udelay(511 + 512);
do {
u8 ctrl = readb(dev->regs + MXC_W1_CONTROL);
if (!(ctrl & MXC_W1_CONTROL_RPP))
return !(ctrl & MXC_W1_CONTROL_PST);
} while (time_is_after_jiffies(timeout));
return 1;
}
static u8 mxc_w1_ds2_touch_bit(void *data, u8 bit)
{
struct mxc_w1_device *dev = data;
unsigned long timeout;
writeb(MXC_W1_CONTROL_WR(bit), dev->regs + MXC_W1_CONTROL);
timeout = jiffies + usecs_to_jiffies(200);
udelay(60);
do {
u8 ctrl = readb(dev->regs + MXC_W1_CONTROL);
if (!(ctrl & MXC_W1_CONTROL_WR(bit)))
return !!(ctrl & MXC_W1_CONTROL_RDST);
} while (time_is_after_jiffies(timeout));
return 0;
}
static int mxc_w1_probe(struct platform_device *pdev)
{
struct mxc_w1_device *mdev;
unsigned long clkrate;
struct resource *res;
unsigned int clkdiv;
int err;
mdev = devm_kzalloc(&pdev->dev, sizeof(struct mxc_w1_device),
GFP_KERNEL);
if (!mdev)
return -ENOMEM;
mdev->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(mdev->clk))
return PTR_ERR(mdev->clk);
clkrate = clk_get_rate(mdev->clk);
if (clkrate < 10000000)
dev_warn(&pdev->dev,
"Low clock frequency causes improper function\n");
clkdiv = DIV_ROUND_CLOSEST(clkrate, 1000000);
clkrate /= clkdiv;
if ((clkrate < 980000) || (clkrate > 1020000))
dev_warn(&pdev->dev,
"Incorrect time base frequency %lu Hz\n", clkrate);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mdev->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mdev->regs))
return PTR_ERR(mdev->regs);
err = clk_prepare_enable(mdev->clk);
if (err)
return err;
writeb(MXC_W1_RESET_RST, mdev->regs + MXC_W1_RESET);
writeb(0, mdev->regs + MXC_W1_RESET);
writeb(clkdiv - 1, mdev->regs + MXC_W1_TIME_DIVIDER);
mdev->bus_master.data = mdev;
mdev->bus_master.reset_bus = mxc_w1_ds2_reset_bus;
mdev->bus_master.touch_bit = mxc_w1_ds2_touch_bit;
platform_set_drvdata(pdev, mdev);
err = w1_add_master_device(&mdev->bus_master);
if (err)
clk_disable_unprepare(mdev->clk);
return err;
}
static int mxc_w1_remove(struct platform_device *pdev)
{
struct mxc_w1_device *mdev = platform_get_drvdata(pdev);
w1_remove_master_device(&mdev->bus_master);
clk_disable_unprepare(mdev->clk);
return 0;
}
