static inline void em_clear_set_bit(struct em_i2c_device *priv, u8 clear, u8 set, u8 reg)
{
writeb((readb(priv->base + reg) & ~clear) | set, priv->base + reg);
}
static int em_i2c_wait_for_event(struct em_i2c_device *priv)
{
unsigned long time_left;
int status;
reinit_completion(&priv->msg_done);
time_left = wait_for_completion_timeout(&priv->msg_done, priv->adap.timeout);
if (!time_left)
return -ETIMEDOUT;
status = readb(priv->base + I2C_OFS_IICSE0);
return status & I2C_BIT_ALD0 ? -EAGAIN : status;
}
static void em_i2c_stop(struct em_i2c_device *priv)
{
em_clear_set_bit(priv, 0, I2C_BIT_SPT0 | I2C_BIT_SPIE0, I2C_OFS_IICC0);
em_i2c_wait_for_event(priv);
}
static void em_i2c_reset(struct i2c_adapter *adap)
{
struct em_i2c_device *priv = i2c_get_adapdata(adap);
int retr;
if (readb(priv->base + I2C_OFS_IICACT0) & I2C_BIT_IICE0) {
writeb(0, priv->base + I2C_OFS_IICACT0);
retr = 1000;
while (readb(priv->base + I2C_OFS_IICACT0) == 1 && retr)
retr--;
WARN_ON(retr == 0);
}
writeb(I2C_BIT_DFC0, priv->base + I2C_OFS_IICCL0);
writeb(I2C_BIT_STCEN | I2C_BIT_IICRSV, priv->base + I2C_OFS_IICF0);
writeb(I2C_BIT_WTIM0, priv->base + I2C_OFS_IICC0);
writeb(I2C_BIT_IICE0, priv->base + I2C_OFS_IICACT0);
retr = 1000;
while (readb(priv->base + I2C_OFS_IICACT0) == 0 && retr)
retr--;
WARN_ON(retr == 0);
}
static int __em_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg *msg,
int stop)
{
struct em_i2c_device *priv = i2c_get_adapdata(adap);
int count, status, read = !!(msg->flags & I2C_M_RD);
em_clear_set_bit(priv, 0, I2C_BIT_ACKE0 | I2C_BIT_WTIM0, I2C_OFS_IICC0);
em_clear_set_bit(priv, 0, I2C_BIT_STT0, I2C_OFS_IICC0);
writeb((msg->addr << 1) | read, priv->base + I2C_OFS_IIC0);
status = em_i2c_wait_for_event(priv);
if (status < 0)
goto out_reset;
if (!(status & I2C_BIT_ACKD0)) {
em_i2c_stop(priv);
goto out;
}
if (read) {
em_clear_set_bit(priv, I2C_BIT_WTIM0, I2C_BIT_ACKE0, I2C_OFS_IICC0);
em_clear_set_bit(priv, I2C_BIT_WTIM0, I2C_BIT_WREL0, I2C_OFS_IICC0);
status = em_i2c_wait_for_event(priv);
if (status < 0)
goto out_reset;
}
for (count = 0; count < msg->len; count++) {
if (read) {
msg->buf[count] = readb(priv->base + I2C_OFS_IIC0);
em_clear_set_bit(priv, 0, I2C_BIT_WREL0, I2C_OFS_IICC0);
} else {
if (!(status & I2C_BIT_ACKD0)) {
em_i2c_stop(priv);
goto out;
}
writeb(msg->buf[count], priv->base + I2C_OFS_IIC0);
}
status = em_i2c_wait_for_event(priv);
if (status < 0)
goto out_reset;
}
if (stop)
em_i2c_stop(priv);
return count;
out_reset:
em_i2c_reset(adap);
out:
return status < 0 ? status : -ENXIO;
}
static int em_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs,
int num)
{
struct em_i2c_device *priv = i2c_get_adapdata(adap);
int ret, i;
if (readb(priv->base + I2C_OFS_IICF0) & I2C_BIT_IICBSY)
return -EAGAIN;
for (i = 0; i < num; i++) {
ret = __em_i2c_xfer(adap, &msgs[i], (i == (num - 1)));
if (ret < 0)
return ret;
}
return num;
}
static bool em_i2c_slave_irq(struct em_i2c_device *priv)
{
u8 status, value;
enum i2c_slave_event event;
int ret;
if (!priv->slave)
return false;
status = readb(priv->base + I2C_OFS_IICSE0);
if (status & I2C_BIT_EXC0) {
em_clear_set_bit(priv, 0, I2C_BIT_LREL0, I2C_OFS_IICC0);
return true;
}
if (status & I2C_BIT_SPD0) {
i2c_slave_event(priv->slave, I2C_SLAVE_STOP, &value);
return false;
}
if (!(status & I2C_BIT_COI0))
return false;
em_clear_set_bit(priv, 0, I2C_BIT_SPIE0, I2C_OFS_IICC0);
if (status & I2C_BIT_TRC0) {
if (status & I2C_BIT_ACKD0) {
em_clear_set_bit(priv, 0, I2C_BIT_WTIM0, I2C_OFS_IICC0);
event = status & I2C_BIT_STD0 ?
I2C_SLAVE_READ_REQUESTED :
I2C_SLAVE_READ_PROCESSED;
i2c_slave_event(priv->slave, event, &value);
writeb(value, priv->base + I2C_OFS_IIC0);
} else {
em_clear_set_bit(priv, 0, I2C_BIT_LREL0, I2C_OFS_IICC0);
}
} else {
em_clear_set_bit(priv, I2C_BIT_WTIM0, I2C_BIT_ACKE0,
I2C_OFS_IICC0);
em_clear_set_bit(priv, I2C_BIT_WTIM0, I2C_BIT_WREL0,
I2C_OFS_IICC0);
if (status & I2C_BIT_STD0) {
i2c_slave_event(priv->slave, I2C_SLAVE_WRITE_REQUESTED,
&value);
} else {
value = readb(priv->base + I2C_OFS_IIC0);
ret = i2c_slave_event(priv->slave,
I2C_SLAVE_WRITE_RECEIVED, &value);
if (ret < 0)
em_clear_set_bit(priv, I2C_BIT_ACKE0, 0,
I2C_OFS_IICC0);
}
}
return true;
}
static irqreturn_t em_i2c_irq_handler(int this_irq, void *dev_id)
{
struct em_i2c_device *priv = dev_id;
if (em_i2c_slave_irq(priv))
return IRQ_HANDLED;
complete(&priv->msg_done);
return IRQ_HANDLED;
}
static u32 em_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL | I2C_FUNC_SLAVE;
}
static int em_i2c_reg_slave(struct i2c_client *slave)
{
struct em_i2c_device *priv = i2c_get_adapdata(slave->adapter);
if (priv->slave)
return -EBUSY;
if (slave->flags & I2C_CLIENT_TEN)
return -EAFNOSUPPORT;
priv->slave = slave;
writeb(slave->addr << 1, priv->base + I2C_OFS_SVA0);
return 0;
}
static int em_i2c_unreg_slave(struct i2c_client *slave)
{
struct em_i2c_device *priv = i2c_get_adapdata(slave->adapter);
WARN_ON(!priv->slave);
writeb(0, priv->base + I2C_OFS_SVA0);
priv->slave = NULL;
return 0;
}
static int em_i2c_probe(struct platform_device *pdev)
{
struct em_i2c_device *priv;
struct resource *r;
int irq, ret;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(priv->base))
return PTR_ERR(priv->base);
strlcpy(priv->adap.name, "EMEV2 I2C", sizeof(priv->adap.name));
priv->sclk = devm_clk_get(&pdev->dev, "sclk");
if (IS_ERR(priv->sclk))
return PTR_ERR(priv->sclk);
ret = clk_prepare_enable(priv->sclk);
if (ret)
return ret;
priv->adap.timeout = msecs_to_jiffies(100);
priv->adap.retries = 5;
priv->adap.dev.parent = &pdev->dev;
priv->adap.algo = &em_i2c_algo;
priv->adap.owner = THIS_MODULE;
priv->adap.dev.of_node = pdev->dev.of_node;
init_completion(&priv->msg_done);
platform_set_drvdata(pdev, priv);
i2c_set_adapdata(&priv->adap, priv);
em_i2c_reset(&priv->adap);
irq = platform_get_irq(pdev, 0);
ret = devm_request_irq(&pdev->dev, irq, em_i2c_irq_handler, 0,
"em_i2c", priv);
if (ret)
goto err_clk;
ret = i2c_add_adapter(&priv->adap);
if (ret)
goto err_clk;
dev_info(&pdev->dev, "Added i2c controller %d, irq %d\n", priv->adap.nr, irq);
return 0;
err_clk:
clk_disable_unprepare(priv->sclk);
return ret;
}
static int em_i2c_remove(struct platform_device *dev)
{
struct em_i2c_device *priv = platform_get_drvdata(dev);
i2c_del_adapter(&priv->adap);
clk_disable_unprepare(priv->sclk);
return 0;
}
