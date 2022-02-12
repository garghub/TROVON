static u8 mxc_w1_ds2_reset_bus(void *data)
{
u8 reg_val;
unsigned int timeout_cnt = 0;
struct mxc_w1_device *dev = data;
writeb(MXC_W1_CONTROL_RPP, (dev->regs + MXC_W1_CONTROL));
while (1) {
reg_val = readb(dev->regs + MXC_W1_CONTROL);
if (!(reg_val & MXC_W1_CONTROL_RPP) ||
timeout_cnt > MXC_W1_RESET_TIMEOUT)
break;
else
timeout_cnt++;
udelay(100);
}
return !!(reg_val & MXC_W1_CONTROL_PST);
}
static u8 mxc_w1_ds2_touch_bit(void *data, u8 bit)
{
struct mxc_w1_device *mdev = data;
void __iomem *ctrl_addr = mdev->regs + MXC_W1_CONTROL;
unsigned int timeout_cnt = 400;
writeb(MXC_W1_CONTROL_WR(bit), ctrl_addr);
while (timeout_cnt--) {
if (!(readb(ctrl_addr) & MXC_W1_CONTROL_WR(bit)))
break;
udelay(1);
}
return !!(readb(ctrl_addr) & MXC_W1_CONTROL_RDST);
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
