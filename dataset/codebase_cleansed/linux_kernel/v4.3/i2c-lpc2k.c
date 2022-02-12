static void i2c_lpc2k_reset(struct lpc2k_i2c *i2c)
{
writel(LPC24XX_CLEAR_ALL, i2c->base + LPC24XX_I2CONCLR);
writel(0, i2c->base + LPC24XX_I2ADDR);
writel(LPC24XX_I2EN, i2c->base + LPC24XX_I2CONSET);
}
static int i2c_lpc2k_clear_arb(struct lpc2k_i2c *i2c)
{
unsigned long timeout = jiffies + msecs_to_jiffies(1000);
writel(LPC24XX_STO, i2c->base + LPC24XX_I2CONSET);
while (readl(i2c->base + LPC24XX_I2STAT) != M_I2C_IDLE) {
if (time_after(jiffies, timeout)) {
i2c_lpc2k_reset(i2c);
return -EBUSY;
}
cpu_relax();
}
return 0;
}
static void i2c_lpc2k_pump_msg(struct lpc2k_i2c *i2c)
{
unsigned char data;
u32 status;
status = readl(i2c->base + LPC24XX_I2STAT);
switch (status) {
case M_START:
case M_REPSTART:
data = i2c->msg->addr << 1;
if (i2c->msg->flags & I2C_M_RD)
data |= 1;
writel(data, i2c->base + LPC24XX_I2DAT);
writel(LPC24XX_STA, i2c->base + LPC24XX_I2CONCLR);
break;
case MX_ADDR_W_ACK:
case MX_DATA_W_ACK:
if (i2c->msg_idx < i2c->msg->len) {
writel(i2c->msg->buf[i2c->msg_idx],
i2c->base + LPC24XX_I2DAT);
} else if (i2c->is_last) {
writel(LPC24XX_STO_AA, i2c->base + LPC24XX_I2CONSET);
writel(LPC24XX_SI, i2c->base + LPC24XX_I2CONCLR);
i2c->msg_status = 0;
disable_irq_nosync(i2c->irq);
} else {
i2c->msg_status = 0;
disable_irq_nosync(i2c->irq);
}
i2c->msg_idx++;
break;
case MR_ADDR_R_ACK:
if (i2c->msg->len == 1) {
writel(LPC24XX_AA, i2c->base + LPC24XX_I2CONCLR);
} else {
writel(LPC24XX_AA, i2c->base + LPC24XX_I2CONSET);
}
writel(LPC24XX_STA, i2c->base + LPC24XX_I2CONCLR);
break;
case MR_DATA_R_NACK:
case MR_DATA_R_ACK:
if (i2c->msg_idx < i2c->msg->len) {
i2c->msg->buf[i2c->msg_idx] =
readl(i2c->base + LPC24XX_I2DAT);
}
if (i2c->msg_idx >= i2c->msg->len - 1 && i2c->is_last) {
writel(LPC24XX_STO_AA, i2c->base + LPC24XX_I2CONSET);
writel(LPC24XX_SI, i2c->base + LPC24XX_I2CONCLR);
i2c->msg_status = 0;
}
if (i2c->msg_idx >= i2c->msg->len - 1) {
i2c->msg_status = 0;
disable_irq_nosync(i2c->irq);
}
if (i2c->msg_idx >= i2c->msg->len - 2) {
writel(LPC24XX_AA, i2c->base + LPC24XX_I2CONCLR);
} else {
writel(LPC24XX_AA, i2c->base + LPC24XX_I2CONSET);
}
writel(LPC24XX_STA, i2c->base + LPC24XX_I2CONCLR);
i2c->msg_idx++;
break;
case MX_ADDR_W_NACK:
case MX_DATA_W_NACK:
case MR_ADDR_R_NACK:
writel(LPC24XX_STO_AA, i2c->base + LPC24XX_I2CONSET);
i2c->msg_status = -ENXIO;
disable_irq_nosync(i2c->irq);
break;
case M_DATA_ARB_LOST:
i2c->msg_status = -EAGAIN;
writel(LPC24XX_STA | LPC24XX_STO, i2c->base + LPC24XX_I2CONCLR);
disable_irq_nosync(i2c->irq);
break;
default:
i2c->msg_status = -EIO;
disable_irq_nosync(i2c->irq);
break;
}
if (i2c->msg_status != -EBUSY)
wake_up(&i2c->wait);
if (i2c->msg_status != 0)
writel(LPC24XX_SI, i2c->base + LPC24XX_I2CONCLR);
}
static int lpc2k_process_msg(struct lpc2k_i2c *i2c, int msgidx)
{
if (!msgidx) {
writel(LPC24XX_STA, i2c->base + LPC24XX_I2CONSET);
} else {
if (unlikely(i2c->msg->flags & I2C_M_NOSTART)) {
WARN_ON(i2c->msg->len == 0);
if (!(i2c->msg->flags & I2C_M_RD)) {
writel(i2c->msg->buf[0],
i2c->base + LPC24XX_I2DAT);
i2c->msg_idx++;
}
} else {
writel(LPC24XX_STA, i2c->base + LPC24XX_I2CONSET);
}
writel(LPC24XX_SI, i2c->base + LPC24XX_I2CONCLR);
}
enable_irq(i2c->irq);
if (wait_event_timeout(i2c->wait, i2c->msg_status != -EBUSY,
msecs_to_jiffies(1000)) == 0) {
disable_irq_nosync(i2c->irq);
return -ETIMEDOUT;
}
return i2c->msg_status;
}
static int i2c_lpc2k_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs,
int msg_num)
{
struct lpc2k_i2c *i2c = i2c_get_adapdata(adap);
int ret, i;
u32 stat;
stat = readl(i2c->base + LPC24XX_I2STAT);
if (stat != M_I2C_IDLE) {
return i2c_lpc2k_clear_arb(i2c);
}
for (i = 0; i < msg_num; i++) {
i2c->msg = &msgs[i];
i2c->msg_idx = 0;
i2c->msg_status = -EBUSY;
i2c->is_last = (i == (msg_num - 1));
ret = lpc2k_process_msg(i2c, i);
if (ret)
return ret;
}
return msg_num;
}
static irqreturn_t i2c_lpc2k_handler(int irq, void *dev_id)
{
struct lpc2k_i2c *i2c = dev_id;
if (readl(i2c->base + LPC24XX_I2CONSET) & LPC24XX_SI) {
i2c_lpc2k_pump_msg(i2c);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static u32 i2c_lpc2k_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int i2c_lpc2k_probe(struct platform_device *pdev)
{
struct lpc2k_i2c *i2c;
struct resource *res;
u32 bus_clk_rate;
u32 scl_high;
u32 clkrate;
int ret;
i2c = devm_kzalloc(&pdev->dev, sizeof(*i2c), GFP_KERNEL);
if (!i2c)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
i2c->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(i2c->base))
return PTR_ERR(i2c->base);
i2c->irq = platform_get_irq(pdev, 0);
if (i2c->irq < 0) {
dev_err(&pdev->dev, "can't get interrupt resource\n");
return i2c->irq;
}
init_waitqueue_head(&i2c->wait);
i2c->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(i2c->clk)) {
dev_err(&pdev->dev, "error getting clock\n");
return PTR_ERR(i2c->clk);
}
ret = clk_prepare_enable(i2c->clk);
if (ret) {
dev_err(&pdev->dev, "unable to enable clock.\n");
return ret;
}
ret = devm_request_irq(&pdev->dev, i2c->irq, i2c_lpc2k_handler, 0,
dev_name(&pdev->dev), i2c);
if (ret < 0) {
dev_err(&pdev->dev, "can't request interrupt.\n");
goto fail_clk;
}
disable_irq_nosync(i2c->irq);
i2c_lpc2k_reset(i2c);
ret = of_property_read_u32(pdev->dev.of_node, "clock-frequency",
&bus_clk_rate);
if (ret)
bus_clk_rate = 100000;
clkrate = clk_get_rate(i2c->clk);
if (clkrate == 0) {
dev_err(&pdev->dev, "can't get I2C base clock\n");
ret = -EINVAL;
goto fail_clk;
}
clkrate = clkrate / bus_clk_rate;
if (bus_clk_rate <= 100000)
scl_high = (clkrate * I2C_STD_MODE_DUTY) / 100;
else if (bus_clk_rate <= 400000)
scl_high = (clkrate * I2C_FAST_MODE_DUTY) / 100;
else
scl_high = (clkrate * I2C_FAST_MODE_PLUS_DUTY) / 100;
writel(scl_high, i2c->base + LPC24XX_I2SCLH);
writel(clkrate - scl_high, i2c->base + LPC24XX_I2SCLL);
platform_set_drvdata(pdev, i2c);
i2c_set_adapdata(&i2c->adap, i2c);
i2c->adap.owner = THIS_MODULE;
strlcpy(i2c->adap.name, "LPC2K I2C adapter", sizeof(i2c->adap.name));
i2c->adap.algo = &i2c_lpc2k_algorithm;
i2c->adap.dev.parent = &pdev->dev;
i2c->adap.dev.of_node = pdev->dev.of_node;
ret = i2c_add_adapter(&i2c->adap);
if (ret < 0) {
dev_err(&pdev->dev, "failed to add adapter!\n");
goto fail_clk;
}
dev_info(&pdev->dev, "LPC2K I2C adapter\n");
return 0;
fail_clk:
clk_disable_unprepare(i2c->clk);
return ret;
}
static int i2c_lpc2k_remove(struct platform_device *dev)
{
struct lpc2k_i2c *i2c = platform_get_drvdata(dev);
i2c_del_adapter(&i2c->adap);
clk_disable_unprepare(i2c->clk);
return 0;
}
static int i2c_lpc2k_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct lpc2k_i2c *i2c = platform_get_drvdata(pdev);
clk_disable(i2c->clk);
return 0;
}
static int i2c_lpc2k_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct lpc2k_i2c *i2c = platform_get_drvdata(pdev);
clk_enable(i2c->clk);
i2c_lpc2k_reset(i2c);
return 0;
}
