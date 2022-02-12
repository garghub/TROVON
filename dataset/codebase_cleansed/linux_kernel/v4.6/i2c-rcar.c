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
rcar_i2c_write(priv, ICMIER, 0);
rcar_i2c_write(priv, ICMCR, MDBS);
rcar_i2c_write(priv, ICMSR, 0);
rcar_i2c_write(priv, ICCCR, priv->icccr);
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
static int rcar_i2c_clock_calculate(struct rcar_i2c_priv *priv, struct i2c_timings *t)
{
u32 scgd, cdf, round, ick, sum, scl, cdf_width;
unsigned long rate;
struct device *dev = rcar_i2c_priv_to_dev(priv);
t->bus_freq_hz = t->bus_freq_hz ?: 100000;
t->scl_fall_ns = t->scl_fall_ns ?: 35;
t->scl_rise_ns = t->scl_rise_ns ?: 200;
t->scl_int_delay_ns = t->scl_int_delay_ns ?: 50;
switch (priv->devtype) {
case I2C_RCAR_GEN1:
cdf_width = 2;
break;
case I2C_RCAR_GEN2:
case I2C_RCAR_GEN3:
cdf_width = 3;
break;
default:
dev_err(dev, "device type error\n");
return -EIO;
}
rate = clk_get_rate(priv->clk);
cdf = rate / 20000000;
if (cdf >= 1U << cdf_width) {
dev_err(dev, "Input clock %lu too high\n", rate);
return -EIO;
}
ick = rate / (cdf + 1);
sum = t->scl_fall_ns + t->scl_rise_ns + t->scl_int_delay_ns;
round = (ick + 500000) / 1000000 * sum;
round = (round + 500) / 1000;
for (scgd = 0; scgd < 0x40; scgd++) {
scl = ick / (20 + (scgd * 8) + round);
if (scl <= t->bus_freq_hz)
goto scgd_find;
}
dev_err(dev, "it is impossible to calculate best SCL\n");
return -EIO;
scgd_find:
dev_dbg(dev, "clk %d/%d(%lu), round %u, CDF:0x%x, SCGD: 0x%x\n",
scl, t->bus_freq_hz, clk_get_rate(priv->clk), round, cdf, scgd);
priv->icccr = scgd << cdf_width | cdf;
return 0;
}
static void rcar_i2c_prepare_msg(struct rcar_i2c_priv *priv)
{
int read = !!rcar_i2c_is_recv(priv);
priv->pos = 0;
if (priv->msgs_left == 1)
priv->flags |= ID_LAST_MSG;
rcar_i2c_write(priv, ICMAR, (priv->msg->addr << 1) | read);
if (priv->flags & ID_FIRST_MSG) {
rcar_i2c_write(priv, ICMSR, 0);
rcar_i2c_write(priv, ICMCR, RCAR_BUS_PHASE_START);
} else {
rcar_i2c_write(priv, ICMCR, RCAR_BUS_PHASE_START);
rcar_i2c_write(priv, ICMSR, 0);
}
rcar_i2c_write(priv, ICMIER, read ? RCAR_IRQ_RECV : RCAR_IRQ_SEND);
}
static void rcar_i2c_next_msg(struct rcar_i2c_priv *priv)
{
priv->msg++;
priv->msgs_left--;
priv->flags &= ID_P_MASK;
rcar_i2c_prepare_msg(priv);
}
static void rcar_i2c_irq_send(struct rcar_i2c_priv *priv, u32 msr)
{
struct i2c_msg *msg = priv->msg;
if (!(msr & MDE))
return;
if (priv->pos < msg->len) {
rcar_i2c_write(priv, ICRXTX, msg->buf[priv->pos]);
priv->pos++;
} else {
if (priv->flags & ID_LAST_MSG) {
rcar_i2c_write(priv, ICMCR, RCAR_BUS_PHASE_STOP);
} else {
rcar_i2c_next_msg(priv);
return;
}
}
rcar_i2c_write(priv, ICMSR, RCAR_IRQ_ACK_SEND);
}
static void rcar_i2c_irq_recv(struct rcar_i2c_priv *priv, u32 msr)
{
struct i2c_msg *msg = priv->msg;
if (!(msr & MDR))
return;
if (msr & MAT) {
} else if (priv->pos < msg->len) {
msg->buf[priv->pos] = rcar_i2c_read(priv, ICRXTX);
priv->pos++;
}
if (priv->pos + 1 >= msg->len)
rcar_i2c_write(priv, ICMCR, RCAR_BUS_PHASE_STOP);
if (priv->pos == msg->len && !(priv->flags & ID_LAST_MSG))
rcar_i2c_next_msg(priv);
else
rcar_i2c_write(priv, ICMSR, RCAR_IRQ_ACK_RECV);
}
static bool rcar_i2c_slave_irq(struct rcar_i2c_priv *priv)
{
u32 ssr_raw, ssr_filtered;
u8 value;
ssr_raw = rcar_i2c_read(priv, ICSSR) & 0xff;
ssr_filtered = ssr_raw & rcar_i2c_read(priv, ICSIER);
if (!ssr_filtered)
return false;
if (ssr_filtered & SAR) {
if (ssr_raw & STM) {
i2c_slave_event(priv->slave, I2C_SLAVE_READ_REQUESTED, &value);
rcar_i2c_write(priv, ICRXTX, value);
rcar_i2c_write(priv, ICSIER, SDE | SSR | SAR);
} else {
i2c_slave_event(priv->slave, I2C_SLAVE_WRITE_REQUESTED, &value);
rcar_i2c_read(priv, ICRXTX);
rcar_i2c_write(priv, ICSIER, SDR | SSR | SAR);
}
rcar_i2c_write(priv, ICSSR, ~SAR & 0xff);
}
if (ssr_filtered & SSR) {
i2c_slave_event(priv->slave, I2C_SLAVE_STOP, &value);
rcar_i2c_write(priv, ICSIER, SAR | SSR);
rcar_i2c_write(priv, ICSSR, ~SSR & 0xff);
}
if (ssr_filtered & SDR) {
int ret;
value = rcar_i2c_read(priv, ICRXTX);
ret = i2c_slave_event(priv->slave, I2C_SLAVE_WRITE_RECEIVED, &value);
rcar_i2c_write(priv, ICSCR, SIE | SDBS | (ret < 0 ? FNA : 0));
rcar_i2c_write(priv, ICSSR, ~SDR & 0xff);
}
if (ssr_filtered & SDE) {
i2c_slave_event(priv->slave, I2C_SLAVE_READ_PROCESSED, &value);
rcar_i2c_write(priv, ICRXTX, value);
rcar_i2c_write(priv, ICSSR, ~SDE & 0xff);
}
return true;
}
static irqreturn_t rcar_i2c_irq(int irq, void *ptr)
{
struct rcar_i2c_priv *priv = ptr;
u32 msr, val;
val = rcar_i2c_read(priv, ICMCR);
rcar_i2c_write(priv, ICMCR, val & RCAR_BUS_MASK_DATA);
msr = rcar_i2c_read(priv, ICMSR);
msr &= rcar_i2c_read(priv, ICMIER);
if (!msr) {
if (rcar_i2c_slave_irq(priv))
return IRQ_HANDLED;
return IRQ_NONE;
}
if (msr & MAL) {
priv->flags |= ID_DONE | ID_ARBLOST;
goto out;
}
if (msr & MNR) {
rcar_i2c_write(priv, ICMIER, RCAR_IRQ_STOP);
priv->flags |= ID_NACK;
goto out;
}
if (msr & MST) {
priv->msgs_left--;
priv->flags |= ID_DONE;
goto out;
}
if (rcar_i2c_is_recv(priv))
rcar_i2c_irq_recv(priv, msr);
else
rcar_i2c_irq_send(priv, msr);
out:
if (priv->flags & ID_DONE) {
rcar_i2c_write(priv, ICMIER, 0);
rcar_i2c_write(priv, ICMSR, 0);
wake_up(&priv->wait);
}
return IRQ_HANDLED;
}
static int rcar_i2c_master_xfer(struct i2c_adapter *adap,
struct i2c_msg *msgs,
int num)
{
struct rcar_i2c_priv *priv = i2c_get_adapdata(adap);
struct device *dev = rcar_i2c_priv_to_dev(priv);
int i, ret;
long time_left;
pm_runtime_get_sync(dev);
ret = rcar_i2c_bus_barrier(priv);
if (ret < 0)
goto out;
for (i = 0; i < num; i++) {
if (msgs[i].len == 0) {
ret = -EOPNOTSUPP;
goto out;
}
}
priv->msg = msgs;
priv->msgs_left = num;
priv->flags = (priv->flags & ID_P_MASK) | ID_FIRST_MSG;
rcar_i2c_prepare_msg(priv);
time_left = wait_event_timeout(priv->wait, priv->flags & ID_DONE,
num * adap->timeout);
if (!time_left) {
rcar_i2c_init(priv);
ret = -ETIMEDOUT;
} else if (priv->flags & ID_NACK) {
ret = -ENXIO;
} else if (priv->flags & ID_ARBLOST) {
ret = -EAGAIN;
} else {
ret = num - priv->msgs_left;
}
out:
pm_runtime_put(dev);
if (ret < 0 && ret != -ENXIO)
dev_err(dev, "error %d : %x\n", ret, priv->flags);
return ret;
}
static int rcar_reg_slave(struct i2c_client *slave)
{
struct rcar_i2c_priv *priv = i2c_get_adapdata(slave->adapter);
if (priv->slave)
return -EBUSY;
if (slave->flags & I2C_CLIENT_TEN)
return -EAFNOSUPPORT;
pm_runtime_get_sync(rcar_i2c_priv_to_dev(priv));
priv->slave = slave;
rcar_i2c_write(priv, ICSAR, slave->addr);
rcar_i2c_write(priv, ICSSR, 0);
rcar_i2c_write(priv, ICSIER, SAR | SSR);
rcar_i2c_write(priv, ICSCR, SIE | SDBS);
return 0;
}
static int rcar_unreg_slave(struct i2c_client *slave)
{
struct rcar_i2c_priv *priv = i2c_get_adapdata(slave->adapter);
WARN_ON(!priv->slave);
rcar_i2c_write(priv, ICSIER, 0);
rcar_i2c_write(priv, ICSCR, 0);
priv->slave = NULL;
pm_runtime_put(rcar_i2c_priv_to_dev(priv));
return 0;
}
static u32 rcar_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SLAVE |
(I2C_FUNC_SMBUS_EMUL & ~I2C_FUNC_SMBUS_QUICK);
}
static int rcar_i2c_probe(struct platform_device *pdev)
{
struct rcar_i2c_priv *priv;
struct i2c_adapter *adap;
struct resource *res;
struct device *dev = &pdev->dev;
struct i2c_timings i2c_t;
int irq, ret;
priv = devm_kzalloc(dev, sizeof(struct rcar_i2c_priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->clk = devm_clk_get(dev, NULL);
if (IS_ERR(priv->clk)) {
dev_err(dev, "cannot get clock\n");
return PTR_ERR(priv->clk);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->io = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->io))
return PTR_ERR(priv->io);
priv->devtype = (enum rcar_i2c_type)of_device_get_match_data(dev);
init_waitqueue_head(&priv->wait);
adap = &priv->adap;
adap->nr = pdev->id;
adap->algo = &rcar_i2c_algo;
adap->class = I2C_CLASS_DEPRECATED;
adap->retries = 3;
adap->dev.parent = dev;
adap->dev.of_node = dev->of_node;
i2c_set_adapdata(adap, priv);
strlcpy(adap->name, pdev->name, sizeof(adap->name));
i2c_parse_fw_timings(dev, &i2c_t, false);
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
ret = rcar_i2c_clock_calculate(priv, &i2c_t);
if (ret < 0)
goto out_pm_put;
rcar_i2c_init(priv);
if (of_property_read_bool(dev->of_node, "multi-master"))
priv->flags |= ID_P_PM_BLOCKED;
else
pm_runtime_put(dev);
irq = platform_get_irq(pdev, 0);
ret = devm_request_irq(dev, irq, rcar_i2c_irq, 0, dev_name(dev), priv);
if (ret < 0) {
dev_err(dev, "cannot get irq %d\n", irq);
goto out_pm_disable;
}
platform_set_drvdata(pdev, priv);
ret = i2c_add_numbered_adapter(adap);
if (ret < 0) {
dev_err(dev, "reg adap failed: %d\n", ret);
goto out_pm_disable;
}
dev_info(dev, "probed\n");
return 0;
out_pm_put:
pm_runtime_put(dev);
out_pm_disable:
pm_runtime_disable(dev);
return ret;
}
static int rcar_i2c_remove(struct platform_device *pdev)
{
struct rcar_i2c_priv *priv = platform_get_drvdata(pdev);
struct device *dev = &pdev->dev;
i2c_del_adapter(&priv->adap);
if (priv->flags & ID_P_PM_BLOCKED)
pm_runtime_put(dev);
pm_runtime_disable(dev);
return 0;
}
