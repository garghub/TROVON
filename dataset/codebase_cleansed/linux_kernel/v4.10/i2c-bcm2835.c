static inline void bcm2835_i2c_writel(struct bcm2835_i2c_dev *i2c_dev,
u32 reg, u32 val)
{
writel(val, i2c_dev->regs + reg);
}
static inline u32 bcm2835_i2c_readl(struct bcm2835_i2c_dev *i2c_dev, u32 reg)
{
return readl(i2c_dev->regs + reg);
}
static int bcm2835_i2c_set_divider(struct bcm2835_i2c_dev *i2c_dev)
{
u32 divider;
divider = DIV_ROUND_UP(clk_get_rate(i2c_dev->clk),
i2c_dev->bus_clk_rate);
if (divider & 1)
divider++;
if ((divider < BCM2835_I2C_CDIV_MIN) ||
(divider > BCM2835_I2C_CDIV_MAX)) {
dev_err_ratelimited(i2c_dev->dev, "Invalid clock-frequency\n");
return -EINVAL;
}
bcm2835_i2c_writel(i2c_dev, BCM2835_I2C_DIV, divider);
return 0;
}
static void bcm2835_fill_txfifo(struct bcm2835_i2c_dev *i2c_dev)
{
u32 val;
while (i2c_dev->msg_buf_remaining) {
val = bcm2835_i2c_readl(i2c_dev, BCM2835_I2C_S);
if (!(val & BCM2835_I2C_S_TXD))
break;
bcm2835_i2c_writel(i2c_dev, BCM2835_I2C_FIFO,
*i2c_dev->msg_buf);
i2c_dev->msg_buf++;
i2c_dev->msg_buf_remaining--;
}
}
static void bcm2835_drain_rxfifo(struct bcm2835_i2c_dev *i2c_dev)
{
u32 val;
while (i2c_dev->msg_buf_remaining) {
val = bcm2835_i2c_readl(i2c_dev, BCM2835_I2C_S);
if (!(val & BCM2835_I2C_S_RXD))
break;
*i2c_dev->msg_buf = bcm2835_i2c_readl(i2c_dev,
BCM2835_I2C_FIFO);
i2c_dev->msg_buf++;
i2c_dev->msg_buf_remaining--;
}
}
static void bcm2835_i2c_start_transfer(struct bcm2835_i2c_dev *i2c_dev)
{
u32 c = BCM2835_I2C_C_ST | BCM2835_I2C_C_I2CEN;
struct i2c_msg *msg = i2c_dev->curr_msg;
bool last_msg = (i2c_dev->num_msgs == 1);
if (!i2c_dev->num_msgs)
return;
i2c_dev->num_msgs--;
i2c_dev->msg_buf = msg->buf;
i2c_dev->msg_buf_remaining = msg->len;
if (msg->flags & I2C_M_RD)
c |= BCM2835_I2C_C_READ | BCM2835_I2C_C_INTR;
else
c |= BCM2835_I2C_C_INTT;
if (last_msg)
c |= BCM2835_I2C_C_INTD;
bcm2835_i2c_writel(i2c_dev, BCM2835_I2C_A, msg->addr);
bcm2835_i2c_writel(i2c_dev, BCM2835_I2C_DLEN, msg->len);
bcm2835_i2c_writel(i2c_dev, BCM2835_I2C_C, c);
}
static irqreturn_t bcm2835_i2c_isr(int this_irq, void *data)
{
struct bcm2835_i2c_dev *i2c_dev = data;
u32 val, err;
val = bcm2835_i2c_readl(i2c_dev, BCM2835_I2C_S);
err = val & (BCM2835_I2C_S_CLKT | BCM2835_I2C_S_ERR);
if (err) {
i2c_dev->msg_err = err;
goto complete;
}
if (val & BCM2835_I2C_S_DONE) {
if (i2c_dev->curr_msg->flags & I2C_M_RD) {
bcm2835_drain_rxfifo(i2c_dev);
val = bcm2835_i2c_readl(i2c_dev, BCM2835_I2C_S);
}
if ((val & BCM2835_I2C_S_RXD) || i2c_dev->msg_buf_remaining)
i2c_dev->msg_err = BCM2835_I2C_S_LEN;
else
i2c_dev->msg_err = 0;
goto complete;
}
if (val & BCM2835_I2C_S_TXW) {
if (!i2c_dev->msg_buf_remaining) {
i2c_dev->msg_err = val | BCM2835_I2C_S_LEN;
goto complete;
}
bcm2835_fill_txfifo(i2c_dev);
if (i2c_dev->num_msgs && !i2c_dev->msg_buf_remaining) {
i2c_dev->curr_msg++;
bcm2835_i2c_start_transfer(i2c_dev);
}
return IRQ_HANDLED;
}
if (val & BCM2835_I2C_S_RXR) {
if (!i2c_dev->msg_buf_remaining) {
i2c_dev->msg_err = val | BCM2835_I2C_S_LEN;
goto complete;
}
bcm2835_drain_rxfifo(i2c_dev);
return IRQ_HANDLED;
}
return IRQ_NONE;
complete:
bcm2835_i2c_writel(i2c_dev, BCM2835_I2C_C, BCM2835_I2C_C_CLEAR);
bcm2835_i2c_writel(i2c_dev, BCM2835_I2C_S, BCM2835_I2C_S_CLKT |
BCM2835_I2C_S_ERR | BCM2835_I2C_S_DONE);
complete(&i2c_dev->completion);
return IRQ_HANDLED;
}
static int bcm2835_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msgs[],
int num)
{
struct bcm2835_i2c_dev *i2c_dev = i2c_get_adapdata(adap);
unsigned long time_left;
int i, ret;
for (i = 0; i < (num - 1); i++)
if (msgs[i].flags & I2C_M_RD) {
dev_warn_once(i2c_dev->dev,
"only one read message supported, has to be last\n");
return -EOPNOTSUPP;
}
ret = bcm2835_i2c_set_divider(i2c_dev);
if (ret)
return ret;
i2c_dev->curr_msg = msgs;
i2c_dev->num_msgs = num;
reinit_completion(&i2c_dev->completion);
bcm2835_i2c_start_transfer(i2c_dev);
time_left = wait_for_completion_timeout(&i2c_dev->completion,
adap->timeout);
if (!time_left) {
bcm2835_i2c_writel(i2c_dev, BCM2835_I2C_C,
BCM2835_I2C_C_CLEAR);
dev_err(i2c_dev->dev, "i2c transfer timed out\n");
return -ETIMEDOUT;
}
if (!i2c_dev->msg_err)
return num;
dev_dbg(i2c_dev->dev, "i2c transfer failed: %x\n", i2c_dev->msg_err);
if (i2c_dev->msg_err & BCM2835_I2C_S_ERR)
return -EREMOTEIO;
return -EIO;
}
static u32 bcm2835_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int bcm2835_i2c_probe(struct platform_device *pdev)
{
struct bcm2835_i2c_dev *i2c_dev;
struct resource *mem, *irq;
int ret;
struct i2c_adapter *adap;
i2c_dev = devm_kzalloc(&pdev->dev, sizeof(*i2c_dev), GFP_KERNEL);
if (!i2c_dev)
return -ENOMEM;
platform_set_drvdata(pdev, i2c_dev);
i2c_dev->dev = &pdev->dev;
init_completion(&i2c_dev->completion);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
i2c_dev->regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(i2c_dev->regs))
return PTR_ERR(i2c_dev->regs);
i2c_dev->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(i2c_dev->clk)) {
if (PTR_ERR(i2c_dev->clk) != -EPROBE_DEFER)
dev_err(&pdev->dev, "Could not get clock\n");
return PTR_ERR(i2c_dev->clk);
}
ret = of_property_read_u32(pdev->dev.of_node, "clock-frequency",
&i2c_dev->bus_clk_rate);
if (ret < 0) {
dev_warn(&pdev->dev,
"Could not read clock-frequency property\n");
i2c_dev->bus_clk_rate = 100000;
}
irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!irq) {
dev_err(&pdev->dev, "No IRQ resource\n");
return -ENODEV;
}
i2c_dev->irq = irq->start;
ret = request_irq(i2c_dev->irq, bcm2835_i2c_isr, IRQF_SHARED,
dev_name(&pdev->dev), i2c_dev);
if (ret) {
dev_err(&pdev->dev, "Could not request IRQ\n");
return -ENODEV;
}
adap = &i2c_dev->adapter;
i2c_set_adapdata(adap, i2c_dev);
adap->owner = THIS_MODULE;
adap->class = I2C_CLASS_DEPRECATED;
strlcpy(adap->name, "bcm2835 I2C adapter", sizeof(adap->name));
adap->algo = &bcm2835_i2c_algo;
adap->dev.parent = &pdev->dev;
adap->dev.of_node = pdev->dev.of_node;
adap->quirks = &bcm2835_i2c_quirks;
bcm2835_i2c_writel(i2c_dev, BCM2835_I2C_C, 0);
ret = i2c_add_adapter(adap);
if (ret)
free_irq(i2c_dev->irq, i2c_dev);
return ret;
}
static int bcm2835_i2c_remove(struct platform_device *pdev)
{
struct bcm2835_i2c_dev *i2c_dev = platform_get_drvdata(pdev);
free_irq(i2c_dev->irq, i2c_dev);
i2c_del_adapter(&i2c_dev->adapter);
return 0;
}
