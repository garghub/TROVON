static void sprd_i2c_set_count(struct sprd_i2c *i2c_dev, u32 count)
{
writel(count, i2c_dev->base + I2C_COUNT);
}
static void sprd_i2c_send_stop(struct sprd_i2c *i2c_dev, int stop)
{
u32 tmp = readl(i2c_dev->base + I2C_CTL);
if (stop)
writel(tmp & ~STP_EN, i2c_dev->base + I2C_CTL);
else
writel(tmp | STP_EN, i2c_dev->base + I2C_CTL);
}
static void sprd_i2c_clear_start(struct sprd_i2c *i2c_dev)
{
u32 tmp = readl(i2c_dev->base + I2C_CTL);
writel(tmp & ~I2C_START, i2c_dev->base + I2C_CTL);
}
static void sprd_i2c_clear_ack(struct sprd_i2c *i2c_dev)
{
u32 tmp = readl(i2c_dev->base + I2C_STATUS);
writel(tmp & ~I2C_RX_ACK, i2c_dev->base + I2C_STATUS);
}
static void sprd_i2c_clear_irq(struct sprd_i2c *i2c_dev)
{
u32 tmp = readl(i2c_dev->base + I2C_STATUS);
writel(tmp & ~I2C_INT, i2c_dev->base + I2C_STATUS);
}
static void sprd_i2c_reset_fifo(struct sprd_i2c *i2c_dev)
{
writel(I2C_RST, i2c_dev->base + ADDR_RST);
}
static void sprd_i2c_set_devaddr(struct sprd_i2c *i2c_dev, struct i2c_msg *m)
{
writel(m->addr << 1, i2c_dev->base + I2C_ADDR_CFG);
}
static void sprd_i2c_write_bytes(struct sprd_i2c *i2c_dev, u8 *buf, u32 len)
{
u32 i;
for (i = 0; i < len; i++)
writeb(buf[i], i2c_dev->base + I2C_TX);
}
static void sprd_i2c_read_bytes(struct sprd_i2c *i2c_dev, u8 *buf, u32 len)
{
u32 i;
for (i = 0; i < len; i++)
buf[i] = readb(i2c_dev->base + I2C_RX);
}
static void sprd_i2c_set_full_thld(struct sprd_i2c *i2c_dev, u32 full_thld)
{
u32 tmp = readl(i2c_dev->base + I2C_CTL);
tmp &= ~FIFO_AF_LVL_MASK;
tmp |= full_thld << FIFO_AF_LVL;
writel(tmp, i2c_dev->base + I2C_CTL);
}
static void sprd_i2c_set_empty_thld(struct sprd_i2c *i2c_dev, u32 empty_thld)
{
u32 tmp = readl(i2c_dev->base + I2C_CTL);
tmp &= ~FIFO_AE_LVL_MASK;
tmp |= empty_thld << FIFO_AE_LVL;
writel(tmp, i2c_dev->base + I2C_CTL);
}
static void sprd_i2c_set_fifo_full_int(struct sprd_i2c *i2c_dev, int enable)
{
u32 tmp = readl(i2c_dev->base + I2C_CTL);
if (enable)
tmp |= FULL_INTEN;
else
tmp &= ~FULL_INTEN;
writel(tmp, i2c_dev->base + I2C_CTL);
}
static void sprd_i2c_set_fifo_empty_int(struct sprd_i2c *i2c_dev, int enable)
{
u32 tmp = readl(i2c_dev->base + I2C_CTL);
if (enable)
tmp |= EMPTY_INTEN;
else
tmp &= ~EMPTY_INTEN;
writel(tmp, i2c_dev->base + I2C_CTL);
}
static void sprd_i2c_opt_start(struct sprd_i2c *i2c_dev)
{
u32 tmp = readl(i2c_dev->base + I2C_CTL);
writel(tmp | I2C_START, i2c_dev->base + I2C_CTL);
}
static void sprd_i2c_opt_mode(struct sprd_i2c *i2c_dev, int rw)
{
u32 cmd = readl(i2c_dev->base + I2C_CTL) & ~I2C_MODE;
writel(cmd | rw << 3, i2c_dev->base + I2C_CTL);
}
static void sprd_i2c_data_transfer(struct sprd_i2c *i2c_dev)
{
u32 i2c_count = i2c_dev->count;
u32 need_tran = i2c_count <= I2C_FIFO_DEEP ? i2c_count : I2C_FIFO_DEEP;
struct i2c_msg *msg = i2c_dev->msg;
if (msg->flags & I2C_M_RD) {
sprd_i2c_read_bytes(i2c_dev, i2c_dev->buf, I2C_FIFO_FULL_THLD);
i2c_dev->count -= I2C_FIFO_FULL_THLD;
i2c_dev->buf += I2C_FIFO_FULL_THLD;
if (i2c_dev->count >= I2C_FIFO_FULL_THLD)
sprd_i2c_set_fifo_full_int(i2c_dev, 1);
} else {
sprd_i2c_write_bytes(i2c_dev, i2c_dev->buf, need_tran);
i2c_dev->buf += need_tran;
i2c_dev->count -= need_tran;
if (i2c_count > I2C_FIFO_DEEP)
sprd_i2c_set_fifo_empty_int(i2c_dev, 1);
}
}
static int sprd_i2c_handle_msg(struct i2c_adapter *i2c_adap,
struct i2c_msg *msg, bool is_last_msg)
{
struct sprd_i2c *i2c_dev = i2c_adap->algo_data;
i2c_dev->msg = msg;
i2c_dev->buf = msg->buf;
i2c_dev->count = msg->len;
reinit_completion(&i2c_dev->complete);
sprd_i2c_reset_fifo(i2c_dev);
sprd_i2c_set_devaddr(i2c_dev, msg);
sprd_i2c_set_count(i2c_dev, msg->len);
if (msg->flags & I2C_M_RD) {
sprd_i2c_opt_mode(i2c_dev, 1);
sprd_i2c_send_stop(i2c_dev, 1);
} else {
sprd_i2c_opt_mode(i2c_dev, 0);
sprd_i2c_send_stop(i2c_dev, !!is_last_msg);
}
if (msg->flags & I2C_M_RD)
sprd_i2c_set_fifo_full_int(i2c_dev, 1);
else
sprd_i2c_data_transfer(i2c_dev);
sprd_i2c_opt_start(i2c_dev);
wait_for_completion(&i2c_dev->complete);
return i2c_dev->err;
}
static int sprd_i2c_master_xfer(struct i2c_adapter *i2c_adap,
struct i2c_msg *msgs, int num)
{
struct sprd_i2c *i2c_dev = i2c_adap->algo_data;
int im, ret;
ret = pm_runtime_get_sync(i2c_dev->dev);
if (ret < 0)
return ret;
for (im = 0; im < num - 1; im++) {
ret = sprd_i2c_handle_msg(i2c_adap, &msgs[im], 0);
if (ret)
goto err_msg;
}
ret = sprd_i2c_handle_msg(i2c_adap, &msgs[im++], 1);
err_msg:
pm_runtime_mark_last_busy(i2c_dev->dev);
pm_runtime_put_autosuspend(i2c_dev->dev);
return ret < 0 ? ret : im;
}
static u32 sprd_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static void sprd_i2c_set_clk(struct sprd_i2c *i2c_dev, u32 freq)
{
u32 apb_clk = i2c_dev->src_clk;
u32 i2c_dvd = apb_clk / (4 * freq) - 1;
u32 high = ((i2c_dvd << 1) * 2) / 5;
u32 low = ((i2c_dvd << 1) * 3) / 5;
u32 div0 = I2C_ADDR_DVD0_CALC(high, low);
u32 div1 = I2C_ADDR_DVD1_CALC(high, low);
writel(div0, i2c_dev->base + ADDR_DVD0);
writel(div1, i2c_dev->base + ADDR_DVD1);
if (freq == 400000)
writel((6 * apb_clk) / 10000000, i2c_dev->base + ADDR_STA0_DVD);
else if (freq == 100000)
writel((4 * apb_clk) / 1000000, i2c_dev->base + ADDR_STA0_DVD);
}
static void sprd_i2c_enable(struct sprd_i2c *i2c_dev)
{
u32 tmp = I2C_DVD_OPT;
writel(tmp, i2c_dev->base + I2C_CTL);
sprd_i2c_set_full_thld(i2c_dev, I2C_FIFO_FULL_THLD);
sprd_i2c_set_empty_thld(i2c_dev, I2C_FIFO_EMPTY_THLD);
sprd_i2c_set_clk(i2c_dev, i2c_dev->bus_freq);
sprd_i2c_reset_fifo(i2c_dev);
sprd_i2c_clear_irq(i2c_dev);
tmp = readl(i2c_dev->base + I2C_CTL);
writel(tmp | I2C_EN | I2C_INT_EN, i2c_dev->base + I2C_CTL);
}
static irqreturn_t sprd_i2c_isr_thread(int irq, void *dev_id)
{
struct sprd_i2c *i2c_dev = dev_id;
struct i2c_msg *msg = i2c_dev->msg;
bool ack = !(readl(i2c_dev->base + I2C_STATUS) & I2C_RX_ACK);
u32 i2c_count = readl(i2c_dev->base + I2C_COUNT);
u32 i2c_tran;
if (msg->flags & I2C_M_RD)
i2c_tran = i2c_dev->count >= I2C_FIFO_FULL_THLD;
else
i2c_tran = i2c_count;
if (i2c_tran && ack) {
sprd_i2c_data_transfer(i2c_dev);
return IRQ_HANDLED;
}
i2c_dev->err = 0;
if (!ack)
i2c_dev->err = -EIO;
else if (msg->flags & I2C_M_RD && i2c_dev->count)
sprd_i2c_read_bytes(i2c_dev, i2c_dev->buf, i2c_dev->count);
sprd_i2c_clear_ack(i2c_dev);
sprd_i2c_clear_start(i2c_dev);
complete(&i2c_dev->complete);
return IRQ_HANDLED;
}
static irqreturn_t sprd_i2c_isr(int irq, void *dev_id)
{
struct sprd_i2c *i2c_dev = dev_id;
struct i2c_msg *msg = i2c_dev->msg;
u32 i2c_count = readl(i2c_dev->base + I2C_COUNT);
bool ack = !(readl(i2c_dev->base + I2C_STATUS) & I2C_RX_ACK);
u32 i2c_tran;
if (msg->flags & I2C_M_RD)
i2c_tran = i2c_dev->count >= I2C_FIFO_FULL_THLD;
else
i2c_tran = i2c_count;
if (!i2c_tran || !ack) {
sprd_i2c_clear_start(i2c_dev);
sprd_i2c_clear_irq(i2c_dev);
}
sprd_i2c_set_fifo_empty_int(i2c_dev, 0);
sprd_i2c_set_fifo_full_int(i2c_dev, 0);
return IRQ_WAKE_THREAD;
}
static int sprd_i2c_clk_init(struct sprd_i2c *i2c_dev)
{
struct clk *clk_i2c, *clk_parent;
clk_i2c = devm_clk_get(i2c_dev->dev, "i2c");
if (IS_ERR(clk_i2c)) {
dev_warn(i2c_dev->dev, "i2c%d can't get the i2c clock\n",
i2c_dev->adap.nr);
clk_i2c = NULL;
}
clk_parent = devm_clk_get(i2c_dev->dev, "source");
if (IS_ERR(clk_parent)) {
dev_warn(i2c_dev->dev, "i2c%d can't get the source clock\n",
i2c_dev->adap.nr);
clk_parent = NULL;
}
if (clk_set_parent(clk_i2c, clk_parent))
i2c_dev->src_clk = clk_get_rate(clk_i2c);
else
i2c_dev->src_clk = 26000000;
dev_dbg(i2c_dev->dev, "i2c%d set source clock is %d\n",
i2c_dev->adap.nr, i2c_dev->src_clk);
i2c_dev->clk = devm_clk_get(i2c_dev->dev, "enable");
if (IS_ERR(i2c_dev->clk)) {
dev_warn(i2c_dev->dev, "i2c%d can't get the enable clock\n",
i2c_dev->adap.nr);
i2c_dev->clk = NULL;
}
return 0;
}
static int sprd_i2c_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct sprd_i2c *i2c_dev;
struct resource *res;
u32 prop;
int ret;
pdev->id = of_alias_get_id(dev->of_node, "i2c");
i2c_dev = devm_kzalloc(dev, sizeof(struct sprd_i2c), GFP_KERNEL);
if (!i2c_dev)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
i2c_dev->base = devm_ioremap_resource(dev, res);
if (IS_ERR(i2c_dev->base))
return PTR_ERR(i2c_dev->base);
i2c_dev->irq = platform_get_irq(pdev, 0);
if (i2c_dev->irq < 0) {
dev_err(&pdev->dev, "failed to get irq resource\n");
return i2c_dev->irq;
}
i2c_set_adapdata(&i2c_dev->adap, i2c_dev);
init_completion(&i2c_dev->complete);
snprintf(i2c_dev->adap.name, sizeof(i2c_dev->adap.name),
"%s", "sprd-i2c");
i2c_dev->bus_freq = 100000;
i2c_dev->adap.owner = THIS_MODULE;
i2c_dev->dev = dev;
i2c_dev->adap.retries = 3;
i2c_dev->adap.algo = &sprd_i2c_algo;
i2c_dev->adap.algo_data = i2c_dev;
i2c_dev->adap.dev.parent = dev;
i2c_dev->adap.nr = pdev->id;
i2c_dev->adap.dev.of_node = dev->of_node;
if (!of_property_read_u32(dev->of_node, "clock-frequency", &prop))
i2c_dev->bus_freq = prop;
if (i2c_dev->bus_freq != 100000 && i2c_dev->bus_freq != 400000)
return -EINVAL;
sprd_i2c_clk_init(i2c_dev);
platform_set_drvdata(pdev, i2c_dev);
ret = clk_prepare_enable(i2c_dev->clk);
if (ret)
return ret;
sprd_i2c_enable(i2c_dev);
pm_runtime_set_autosuspend_delay(i2c_dev->dev, SPRD_I2C_PM_TIMEOUT);
pm_runtime_use_autosuspend(i2c_dev->dev);
pm_runtime_set_active(i2c_dev->dev);
pm_runtime_enable(i2c_dev->dev);
ret = pm_runtime_get_sync(i2c_dev->dev);
if (ret < 0)
goto err_rpm_put;
ret = devm_request_threaded_irq(dev, i2c_dev->irq,
sprd_i2c_isr, sprd_i2c_isr_thread,
IRQF_NO_SUSPEND | IRQF_ONESHOT,
pdev->name, i2c_dev);
if (ret) {
dev_err(&pdev->dev, "failed to request irq %d\n", i2c_dev->irq);
goto err_rpm_put;
}
ret = i2c_add_numbered_adapter(&i2c_dev->adap);
if (ret) {
dev_err(&pdev->dev, "add adapter failed\n");
goto err_rpm_put;
}
pm_runtime_mark_last_busy(i2c_dev->dev);
pm_runtime_put_autosuspend(i2c_dev->dev);
return 0;
err_rpm_put:
pm_runtime_put_noidle(i2c_dev->dev);
pm_runtime_disable(i2c_dev->dev);
clk_disable_unprepare(i2c_dev->clk);
return ret;
}
static int sprd_i2c_remove(struct platform_device *pdev)
{
struct sprd_i2c *i2c_dev = platform_get_drvdata(pdev);
int ret;
ret = pm_runtime_get_sync(i2c_dev->dev);
if (ret < 0)
return ret;
i2c_del_adapter(&i2c_dev->adap);
clk_disable_unprepare(i2c_dev->clk);
pm_runtime_put_noidle(i2c_dev->dev);
pm_runtime_disable(i2c_dev->dev);
return 0;
}
static int __maybe_unused sprd_i2c_suspend_noirq(struct device *pdev)
{
return pm_runtime_force_suspend(pdev);
}
static int __maybe_unused sprd_i2c_resume_noirq(struct device *pdev)
{
return pm_runtime_force_resume(pdev);
}
static int __maybe_unused sprd_i2c_runtime_suspend(struct device *pdev)
{
struct sprd_i2c *i2c_dev = dev_get_drvdata(pdev);
clk_disable_unprepare(i2c_dev->clk);
return 0;
}
static int __maybe_unused sprd_i2c_runtime_resume(struct device *pdev)
{
struct sprd_i2c *i2c_dev = dev_get_drvdata(pdev);
int ret;
ret = clk_prepare_enable(i2c_dev->clk);
if (ret)
return ret;
sprd_i2c_enable(i2c_dev);
return 0;
}
static int sprd_i2c_init(void)
{
return platform_driver_register(&sprd_i2c_driver);
}
