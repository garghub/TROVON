static inline void nuc900_i2c_master_complete(struct nuc900_i2c *i2c, int ret)
{
dev_dbg(i2c->dev, "master_complete %d\n", ret);
i2c->msg_ptr = 0;
i2c->msg = NULL;
i2c->msg_idx++;
i2c->msg_num = 0;
if (ret)
i2c->msg_idx = ret;
wake_up(&i2c->wait);
}
static inline void nuc900_i2c_disable_irq(struct nuc900_i2c *i2c)
{
unsigned long tmp;
tmp = readl(i2c->regs + CSR);
writel(tmp & ~IRQEN, i2c->regs + CSR);
}
static inline void nuc900_i2c_enable_irq(struct nuc900_i2c *i2c)
{
unsigned long tmp;
tmp = readl(i2c->regs + CSR);
writel(tmp | IRQEN, i2c->regs + CSR);
}
static void nuc900_i2c_message_start(struct nuc900_i2c *i2c,
struct i2c_msg *msg)
{
unsigned int addr = (msg->addr & 0x7f) << 1;
if (msg->flags & I2C_M_RD)
addr |= 0x1;
writel(addr & 0xff, i2c->regs + TXR);
writel(I2C_CMD_START | I2C_CMD_WRITE, i2c->regs + CMDR);
}
static inline void nuc900_i2c_stop(struct nuc900_i2c *i2c, int ret)
{
dev_dbg(i2c->dev, "STOP\n");
i2c->state = STATE_STOP;
writel(I2C_CMD_STOP, i2c->regs + CMDR);
nuc900_i2c_master_complete(i2c, ret);
nuc900_i2c_disable_irq(i2c);
}
static inline int is_lastmsg(struct nuc900_i2c *i2c)
{
return i2c->msg_idx >= (i2c->msg_num - 1);
}
static inline int is_msglast(struct nuc900_i2c *i2c)
{
return i2c->msg_ptr == i2c->msg->len-1;
}
static inline int is_msgend(struct nuc900_i2c *i2c)
{
return i2c->msg_ptr >= i2c->msg->len;
}
static void i2c_nuc900_irq_nextbyte(struct nuc900_i2c *i2c,
unsigned long iicstat)
{
unsigned char byte;
switch (i2c->state) {
case STATE_IDLE:
dev_err(i2c->dev, "%s: called in STATE_IDLE\n", __func__);
break;
case STATE_STOP:
dev_err(i2c->dev, "%s: called in STATE_STOP\n", __func__);
nuc900_i2c_disable_irq(i2c);
break;
case STATE_START:
if (iicstat & SLAVE_ACK &&
!(i2c->msg->flags & I2C_M_IGNORE_NAK)) {
dev_dbg(i2c->dev, "ack was not received\n");
nuc900_i2c_stop(i2c, -ENXIO);
break;
}
if (i2c->msg->flags & I2C_M_RD)
i2c->state = STATE_READ;
else
i2c->state = STATE_WRITE;
if (is_lastmsg(i2c) && i2c->msg->len == 0) {
nuc900_i2c_stop(i2c, 0);
break;
}
if (i2c->state == STATE_READ)
goto prepare_read;
case STATE_WRITE:
if (!(i2c->msg->flags & I2C_M_IGNORE_NAK)) {
if (iicstat & SLAVE_ACK) {
dev_dbg(i2c->dev, "WRITE: No Ack\n");
nuc900_i2c_stop(i2c, -ECONNREFUSED);
break;
}
}
retry_write:
if (!is_msgend(i2c)) {
byte = i2c->msg->buf[i2c->msg_ptr++];
writeb(byte, i2c->regs + TXR);
writel(I2C_CMD_WRITE, i2c->regs + CMDR);
} else if (!is_lastmsg(i2c)) {
dev_dbg(i2c->dev, "WRITE: Next Message\n");
i2c->msg_ptr = 0;
i2c->msg_idx++;
i2c->msg++;
if (i2c->msg->flags & I2C_M_NOSTART) {
if (i2c->msg->flags & I2C_M_RD) {
nuc900_i2c_stop(i2c, -EINVAL);
}
goto retry_write;
} else {
nuc900_i2c_message_start(i2c, i2c->msg);
i2c->state = STATE_START;
}
} else {
nuc900_i2c_stop(i2c, 0);
}
break;
case STATE_READ:
byte = readb(i2c->regs + RXR);
i2c->msg->buf[i2c->msg_ptr++] = byte;
prepare_read:
if (is_msglast(i2c)) {
if (is_lastmsg(i2c))
writel(I2C_CMD_READ | I2C_CMD_NACK,
i2c->regs + CMDR);
} else if (is_msgend(i2c)) {
if (is_lastmsg(i2c)) {
dev_dbg(i2c->dev, "READ: Send Stop\n");
nuc900_i2c_stop(i2c, 0);
} else {
dev_dbg(i2c->dev, "READ: Next Transfer\n");
i2c->msg_ptr = 0;
i2c->msg_idx++;
i2c->msg++;
writel(I2C_CMD_READ, i2c->regs + CMDR);
}
} else {
writel(I2C_CMD_READ, i2c->regs + CMDR);
}
break;
}
}
static irqreturn_t nuc900_i2c_irq(int irqno, void *dev_id)
{
struct nuc900_i2c *i2c = dev_id;
unsigned long status;
status = readl(i2c->regs + CSR);
writel(status | IRQFLAG, i2c->regs + CSR);
if (status & ARBIT_LOST) {
dev_err(i2c->dev, "deal with arbitration loss\n");
goto out;
}
if (i2c->state == STATE_IDLE) {
dev_dbg(i2c->dev, "IRQ: error i2c->state == IDLE\n");
goto out;
}
i2c_nuc900_irq_nextbyte(i2c, status);
out:
return IRQ_HANDLED;
}
static int nuc900_i2c_set_master(struct nuc900_i2c *i2c)
{
int timeout = 400;
while (timeout-- > 0) {
if (((readl(i2c->regs + SWR) & I2CSTART) == I2CSTART) &&
((readl(i2c->regs + CSR) & I2CBUSY) == 0)) {
return 0;
}
msleep(1);
}
return -ETIMEDOUT;
}
static int nuc900_i2c_doxfer(struct nuc900_i2c *i2c,
struct i2c_msg *msgs, int num)
{
unsigned long iicstat, timeout;
int spins = 20;
int ret;
ret = nuc900_i2c_set_master(i2c);
if (ret != 0) {
dev_err(i2c->dev, "cannot get bus (error %d)\n", ret);
ret = -EAGAIN;
goto out;
}
spin_lock_irq(&i2c->lock);
i2c->msg = msgs;
i2c->msg_num = num;
i2c->msg_ptr = 0;
i2c->msg_idx = 0;
i2c->state = STATE_START;
nuc900_i2c_message_start(i2c, msgs);
spin_unlock_irq(&i2c->lock);
timeout = wait_event_timeout(i2c->wait, i2c->msg_num == 0, HZ * 5);
ret = i2c->msg_idx;
if (timeout == 0)
dev_dbg(i2c->dev, "timeout\n");
else if (ret != num)
dev_dbg(i2c->dev, "incomplete xfer (%d)\n", ret);
dev_dbg(i2c->dev, "waiting for bus idle\n");
do {
iicstat = readl(i2c->regs + CSR);
} while ((iicstat & I2CBUSY) && --spins);
if (!spins) {
msleep(1);
iicstat = readl(i2c->regs + CSR);
}
if (iicstat & I2CBUSY)
dev_warn(i2c->dev, "timeout waiting for bus idle\n");
out:
return ret;
}
static int nuc900_i2c_xfer(struct i2c_adapter *adap,
struct i2c_msg *msgs, int num)
{
struct nuc900_i2c *i2c = (struct nuc900_i2c *)adap->algo_data;
int retry;
int ret;
nuc900_i2c_enable_irq(i2c);
for (retry = 0; retry < adap->retries; retry++) {
ret = nuc900_i2c_doxfer(i2c, msgs, num);
if (ret != -EAGAIN)
return ret;
dev_dbg(i2c->dev, "Retrying transmission (%d)\n", retry);
udelay(100);
}
return -EREMOTEIO;
}
static u32 nuc900_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL | I2C_FUNC_PROTOCOL_MANGLING;
}
static int __devinit nuc900_i2c_probe(struct platform_device *pdev)
{
struct nuc900_i2c *i2c;
struct nuc900_platform_i2c *pdata;
struct resource *res;
int ret;
pdata = pdev->dev.platform_data;
if (!pdata) {
dev_err(&pdev->dev, "no platform data\n");
return -EINVAL;
}
i2c = kzalloc(sizeof(struct nuc900_i2c), GFP_KERNEL);
if (!i2c) {
dev_err(&pdev->dev, "no memory for state\n");
return -ENOMEM;
}
strlcpy(i2c->adap.name, "nuc900-i2c0", sizeof(i2c->adap.name));
i2c->adap.owner = THIS_MODULE;
i2c->adap.algo = &nuc900_i2c_algorithm;
i2c->adap.retries = 2;
i2c->adap.class = I2C_CLASS_HWMON | I2C_CLASS_SPD;
spin_lock_init(&i2c->lock);
init_waitqueue_head(&i2c->wait);
i2c->dev = &pdev->dev;
i2c->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(i2c->clk)) {
dev_err(&pdev->dev, "cannot get clock\n");
ret = -ENOENT;
goto err_noclk;
}
dev_dbg(&pdev->dev, "clock source %p\n", i2c->clk);
clk_enable(i2c->clk);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(&pdev->dev, "cannot find IO resource\n");
ret = -ENOENT;
goto err_clk;
}
i2c->ioarea = request_mem_region(res->start, resource_size(res),
pdev->name);
if (i2c->ioarea == NULL) {
dev_err(&pdev->dev, "cannot request IO\n");
ret = -ENXIO;
goto err_clk;
}
i2c->regs = ioremap(res->start, resource_size(res));
if (i2c->regs == NULL) {
dev_err(&pdev->dev, "cannot map IO\n");
ret = -ENXIO;
goto err_ioarea;
}
dev_dbg(&pdev->dev, "registers %p (%p, %p)\n",
i2c->regs, i2c->ioarea, res);
i2c->adap.algo_data = i2c;
i2c->adap.dev.parent = &pdev->dev;
mfp_set_groupg(&pdev->dev, NULL);
clk_get_rate(i2c->clk);
ret = (i2c->clk.apbfreq)/(pdata->bus_freq * 5) - 1;
writel(ret & 0xffff, i2c->regs + DIVIDER);
i2c->irq = ret = platform_get_irq(pdev, 0);
if (ret <= 0) {
dev_err(&pdev->dev, "cannot find IRQ\n");
goto err_iomap;
}
ret = request_irq(i2c->irq, nuc900_i2c_irq, IRQF_SHARED,
dev_name(&pdev->dev), i2c);
if (ret != 0) {
dev_err(&pdev->dev, "cannot claim IRQ %d\n", i2c->irq);
goto err_iomap;
}
i2c->adap.nr = pdata->bus_num;
ret = i2c_add_numbered_adapter(&i2c->adap);
if (ret < 0) {
dev_err(&pdev->dev, "failed to add bus to i2c core\n");
goto err_irq;
}
platform_set_drvdata(pdev, i2c);
dev_info(&pdev->dev, "%s: NUC900 I2C adapter\n",
dev_name(&i2c->adap.dev));
return 0;
err_irq:
free_irq(i2c->irq, i2c);
err_iomap:
iounmap(i2c->regs);
err_ioarea:
release_resource(i2c->ioarea);
kfree(i2c->ioarea);
err_clk:
clk_disable(i2c->clk);
clk_put(i2c->clk);
err_noclk:
kfree(i2c);
return ret;
}
static int __devexit nuc900_i2c_remove(struct platform_device *pdev)
{
struct nuc900_i2c *i2c = platform_get_drvdata(pdev);
i2c_del_adapter(&i2c->adap);
free_irq(i2c->irq, i2c);
clk_disable(i2c->clk);
clk_put(i2c->clk);
iounmap(i2c->regs);
release_resource(i2c->ioarea);
kfree(i2c->ioarea);
kfree(i2c);
return 0;
}
static int __init i2c_adap_nuc900_init(void)
{
return platform_driver_register(&nuc900_i2c_driver);
}
static void __exit i2c_adap_nuc900_exit(void)
{
platform_driver_unregister(&nuc900_i2c_driver);
}
