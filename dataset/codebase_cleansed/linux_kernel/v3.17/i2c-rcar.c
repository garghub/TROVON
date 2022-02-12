static void rcar_i2c_write(struct rcar_i2c_priv *priv, int reg, u32 val)
{
writel(val, priv->io + reg);
}
static u32 rcar_i2c_read(struct rcar_i2c_priv *priv, int reg)
{
return readl(priv->io + reg);
}
static void rcar_i2c_init(struct rcar_i2c_priv *priv)
{
rcar_i2c_write(priv, ICSIER, 0);
rcar_i2c_write(priv, ICSAR, 0);
rcar_i2c_write(priv, ICSCR, 0);
rcar_i2c_write(priv, ICSSR, 0);
rcar_i2c_write(priv, ICMIER, 0);
rcar_i2c_write(priv, ICMCR, 0);
rcar_i2c_write(priv, ICMSR, 0);
rcar_i2c_write(priv, ICMAR, 0);
}
static int rcar_i2c_bus_barrier(struct rcar_i2c_priv *priv)
{
int i;
for (i = 0; i < LOOP_TIMEOUT; i++) {
if (!(rcar_i2c_read(priv, ICMCR) & FSDA))
return 0;
udelay(1);
}
return -EBUSY;
}
static int rcar_i2c_clock_calculate(struct rcar_i2c_priv *priv,
u32 bus_speed,
struct device *dev)
{
u32 scgd, cdf;
u32 round, ick;
u32 scl;
u32 cdf_width;
unsigned long rate;
switch (priv->devtype) {
case I2C_RCAR_GEN1:
cdf_width = 2;
break;
case I2C_RCAR_GEN2:
cdf_width = 3;
break;
default:
dev_err(dev, "device type error\n");
return -EIO;
}
rate = clk_get_rate(priv->clk);
cdf = rate / 20000000;
if (cdf >= 1 << cdf_width) {
dev_err(dev, "Input clock %lu too high\n", rate);
return -EIO;
}
ick = rate / (cdf + 1);
round = (ick + 500000) / 1000000 * 285;
round = (round + 500) / 1000;
for (scgd = 0; scgd < 0x40; scgd++) {
scl = ick / (20 + (scgd * 8) + round);
if (scl <= bus_speed)
goto scgd_find;
}
dev_err(dev, "it is impossible to calculate best SCL\n");
return -EIO;
scgd_find:
dev_dbg(dev, "clk %d/%d(%lu), round %u, CDF:0x%x, SCGD: 0x%x\n",
scl, bus_speed, clk_get_rate(priv->clk), round, cdf, scgd);
priv->icccr = scgd << cdf_width | cdf;
return 0;
}
static int rcar_i2c_prepare_msg(struct rcar_i2c_priv *priv)
{
int read = !!rcar_i2c_is_recv(priv);
rcar_i2c_write(priv, ICMAR, (priv->msg->addr << 1) | read);
rcar_i2c_write(priv, ICMSR, 0);
rcar_i2c_write(priv, ICMCR, RCAR_BUS_PHASE_START);
rcar_i2c_write(priv, ICMIER, read ? RCAR_IRQ_RECV : RCAR_IRQ_SEND);
return 0;
}
static int rcar_i2c_irq_send(struct rcar_i2c_priv *priv, u32 msr)
{
struct i2c_msg *msg = priv->msg;
if (!(msr & MDE))
return 0;
if (msr & MAT)
rcar_i2c_write(priv, ICMCR, RCAR_BUS_PHASE_DATA);
if (priv->pos < msg->len) {
rcar_i2c_write(priv, ICRXTX, msg->buf[priv->pos]);
priv->pos++;
} else {
if (priv->flags & ID_LAST_MSG)
rcar_i2c_write(priv, ICMCR, RCAR_BUS_PHASE_STOP);
else
return ID_DONE;
}
rcar_i2c_write(priv, ICMSR, RCAR_IRQ_ACK_SEND);
return 0;
}
static int rcar_i2c_irq_recv(struct rcar_i2c_priv *priv, u32 msr)
{
struct i2c_msg *msg = priv->msg;
if (!(msr & MDR))
return 0;
if (msr & MAT) {
} else if (priv->pos < msg->len) {
msg->buf[priv->pos] = rcar_i2c_read(priv, ICRXTX);
priv->pos++;
}
if (priv->pos + 1 >= msg->len)
rcar_i2c_write(priv, ICMCR, RCAR_BUS_PHASE_STOP);
else
rcar_i2c_write(priv, ICMCR, RCAR_BUS_PHASE_DATA);
rcar_i2c_write(priv, ICMSR, RCAR_IRQ_ACK_RECV);
return 0;
}
static irqreturn_t rcar_i2c_irq(int irq, void *ptr)
{
struct rcar_i2c_priv *priv = ptr;
u32 msr;
spin_lock(&priv->lock);
msr = rcar_i2c_read(priv, ICMSR);
msr &= rcar_i2c_read(priv, ICMIER);
if (msr & MAL) {
rcar_i2c_flags_set(priv, (ID_DONE | ID_ARBLOST));
goto out;
}
if (msr & MNR) {
rcar_i2c_write(priv, ICMCR, RCAR_BUS_PHASE_STOP);
rcar_i2c_write(priv, ICMIER, RCAR_IRQ_STOP);
rcar_i2c_flags_set(priv, ID_NACK);
goto out;
}
if (msr & MST) {
rcar_i2c_flags_set(priv, ID_DONE);
goto out;
}
if (rcar_i2c_is_recv(priv))
rcar_i2c_flags_set(priv, rcar_i2c_irq_recv(priv, msr));
else
rcar_i2c_flags_set(priv, rcar_i2c_irq_send(priv, msr));
out:
if (rcar_i2c_flags_has(priv, ID_DONE)) {
rcar_i2c_write(priv, ICMIER, 0);
rcar_i2c_write(priv, ICMSR, 0);
wake_up(&priv->wait);
}
spin_unlock(&priv->lock);
return IRQ_HANDLED;
}
static int rcar_i2c_master_xfer(struct i2c_adapter *adap,
struct i2c_msg *msgs,
int num)
{
struct rcar_i2c_priv *priv = i2c_get_adapdata(adap);
struct device *dev = rcar_i2c_priv_to_dev(priv);
unsigned long flags;
int i, ret, timeout;
pm_runtime_get_sync(dev);
spin_lock_irqsave(&priv->lock, flags);
rcar_i2c_init(priv);
rcar_i2c_write(priv, ICCCR, priv->icccr);
spin_unlock_irqrestore(&priv->lock, flags);
ret = rcar_i2c_bus_barrier(priv);
if (ret < 0)
goto out;
for (i = 0; i < num; i++) {
if (msgs[i].len == 0) {
ret = -EOPNOTSUPP;
break;
}
spin_lock_irqsave(&priv->lock, flags);
priv->msg = &msgs[i];
priv->pos = 0;
priv->flags = 0;
if (priv->msg == &msgs[num - 1])
rcar_i2c_flags_set(priv, ID_LAST_MSG);
ret = rcar_i2c_prepare_msg(priv);
spin_unlock_irqrestore(&priv->lock, flags);
if (ret < 0)
break;
timeout = wait_event_timeout(priv->wait,
rcar_i2c_flags_has(priv, ID_DONE),
5 * HZ);
if (!timeout) {
ret = -ETIMEDOUT;
break;
}
if (rcar_i2c_flags_has(priv, ID_NACK)) {
ret = -ENXIO;
break;
}
if (rcar_i2c_flags_has(priv, ID_ARBLOST)) {
ret = -EAGAIN;
break;
}
if (rcar_i2c_flags_has(priv, ID_IOERROR)) {
ret = -EIO;
break;
}
ret = i + 1;
}
out:
pm_runtime_put(dev);
if (ret < 0 && ret != -ENXIO)
dev_err(dev, "error %d : %x\n", ret, priv->flags);
return ret;
}
static u32 rcar_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | (I2C_FUNC_SMBUS_EMUL & ~I2C_FUNC_SMBUS_QUICK);
}
static int rcar_i2c_probe(struct platform_device *pdev)
{
struct i2c_rcar_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct rcar_i2c_priv *priv;
struct i2c_adapter *adap;
struct resource *res;
struct device *dev = &pdev->dev;
u32 bus_speed;
int irq, ret;
priv = devm_kzalloc(dev, sizeof(struct rcar_i2c_priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->clk = devm_clk_get(dev, NULL);
if (IS_ERR(priv->clk)) {
dev_err(dev, "cannot get clock\n");
return PTR_ERR(priv->clk);
}
bus_speed = 100000;
ret = of_property_read_u32(dev->of_node, "clock-frequency", &bus_speed);
if (ret < 0 && pdata && pdata->bus_speed)
bus_speed = pdata->bus_speed;
if (pdev->dev.of_node)
priv->devtype = (long)of_match_device(rcar_i2c_dt_ids,
dev)->data;
else
priv->devtype = platform_get_device_id(pdev)->driver_data;
ret = rcar_i2c_clock_calculate(priv, bus_speed, dev);
if (ret < 0)
return ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->io = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->io))
return PTR_ERR(priv->io);
irq = platform_get_irq(pdev, 0);
init_waitqueue_head(&priv->wait);
spin_lock_init(&priv->lock);
adap = &priv->adap;
adap->nr = pdev->id;
adap->algo = &rcar_i2c_algo;
adap->class = I2C_CLASS_DEPRECATED;
adap->retries = 3;
adap->dev.parent = dev;
adap->dev.of_node = dev->of_node;
i2c_set_adapdata(adap, priv);
strlcpy(adap->name, pdev->name, sizeof(adap->name));
ret = devm_request_irq(dev, irq, rcar_i2c_irq, 0,
dev_name(dev), priv);
if (ret < 0) {
dev_err(dev, "cannot get irq %d\n", irq);
return ret;
}
ret = i2c_add_numbered_adapter(adap);
if (ret < 0) {
dev_err(dev, "reg adap failed: %d\n", ret);
return ret;
}
pm_runtime_enable(dev);
platform_set_drvdata(pdev, priv);
dev_info(dev, "probed\n");
return 0;
}
static int rcar_i2c_remove(struct platform_device *pdev)
{
struct rcar_i2c_priv *priv = platform_get_drvdata(pdev);
struct device *dev = &pdev->dev;
i2c_del_adapter(&priv->adap);
pm_runtime_disable(dev);
return 0;
}
