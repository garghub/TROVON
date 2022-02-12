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
static void rcar_i2c_irq_mask(struct rcar_i2c_priv *priv, int open)
{
u32 val = MNRE | MALE | MSTE | MATE;
switch (open) {
case RCAR_IRQ_OPEN_FOR_SEND:
val |= MDEE;
break;
case RCAR_IRQ_OPEN_FOR_RECV:
val |= MDRE;
break;
case RCAR_IRQ_OPEN_FOR_STOP:
val = MSTE;
break;
case RCAR_IRQ_CLOSE:
default:
val = 0;
break;
}
rcar_i2c_write(priv, ICMIER, val);
}
static void rcar_i2c_set_addr(struct rcar_i2c_priv *priv, u32 recv)
{
rcar_i2c_write(priv, ICMAR, (priv->msg->addr << 1) | recv);
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
static void rcar_i2c_bus_phase(struct rcar_i2c_priv *priv, int phase)
{
switch (phase) {
case RCAR_BUS_PHASE_ADDR:
rcar_i2c_write(priv, ICMCR, MDBS | MIE | ESG);
break;
case RCAR_BUS_PHASE_DATA:
rcar_i2c_write(priv, ICMCR, MDBS | MIE);
break;
case RCAR_BUS_PHASE_STOP:
rcar_i2c_write(priv, ICMCR, MDBS | MIE | FSB);
break;
}
}
static int rcar_i2c_clock_calculate(struct rcar_i2c_priv *priv,
u32 bus_speed,
struct device *dev)
{
struct clk *clkp = clk_get(NULL, "peripheral_clk");
u32 scgd, cdf;
u32 round, ick;
u32 scl;
u32 cdf_width;
if (!clkp) {
dev_err(dev, "there is no peripheral_clk\n");
return -EIO;
}
switch (priv->devtype) {
case I2C_RCAR_H1:
cdf_width = 2;
break;
case I2C_RCAR_H2:
cdf_width = 3;
break;
default:
dev_err(dev, "device type error\n");
return -EIO;
}
for (cdf = 0; cdf < (1 << cdf_width); cdf++) {
ick = clk_get_rate(clkp) / (1 + cdf);
if (ick < 20000000)
goto ick_find;
}
dev_err(dev, "there is no best CDF\n");
return -EIO;
ick_find:
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
scl, bus_speed, clk_get_rate(clkp), round, cdf, scgd);
priv->icccr = (scgd << (cdf_width) | cdf);
return 0;
}
static void rcar_i2c_clock_start(struct rcar_i2c_priv *priv)
{
rcar_i2c_write(priv, ICCCR, priv->icccr);
}
static u32 rcar_i2c_status_get(struct rcar_i2c_priv *priv)
{
return rcar_i2c_read(priv, ICMSR);
}
static void rcar_i2c_status_bit_clear(struct rcar_i2c_priv *priv, u32 bit)
{
rcar_i2c_write(priv, ICMSR, ~bit);
}
static int rcar_i2c_recv(struct rcar_i2c_priv *priv)
{
rcar_i2c_set_addr(priv, 1);
rcar_i2c_status_clear(priv);
rcar_i2c_bus_phase(priv, RCAR_BUS_PHASE_ADDR);
rcar_i2c_irq_mask(priv, RCAR_IRQ_OPEN_FOR_RECV);
return 0;
}
static int rcar_i2c_send(struct rcar_i2c_priv *priv)
{
int ret;
ret = rcar_i2c_bus_barrier(priv);
if (ret < 0)
return ret;
rcar_i2c_set_addr(priv, 0);
rcar_i2c_status_clear(priv);
rcar_i2c_bus_phase(priv, RCAR_BUS_PHASE_ADDR);
rcar_i2c_irq_mask(priv, RCAR_IRQ_OPEN_FOR_SEND);
return 0;
}
static int rcar_i2c_irq_send(struct rcar_i2c_priv *priv, u32 msr)
{
struct i2c_msg *msg = priv->msg;
if (!(msr & MDE))
return 0;
if (msr & MAT)
rcar_i2c_bus_phase(priv, RCAR_BUS_PHASE_DATA);
if (priv->pos < msg->len) {
rcar_i2c_write(priv, ICRXTX, msg->buf[priv->pos]);
priv->pos++;
} else {
if (priv->flags & ID_LAST_MSG)
rcar_i2c_bus_phase(priv, RCAR_BUS_PHASE_STOP);
else
return ID_DONE;
}
rcar_i2c_send_restart(priv);
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
rcar_i2c_bus_phase(priv, RCAR_BUS_PHASE_STOP);
else
rcar_i2c_bus_phase(priv, RCAR_BUS_PHASE_DATA);
rcar_i2c_recv_restart(priv);
return 0;
}
static irqreturn_t rcar_i2c_irq(int irq, void *ptr)
{
struct rcar_i2c_priv *priv = ptr;
struct device *dev = rcar_i2c_priv_to_dev(priv);
u32 msr;
spin_lock(&priv->lock);
msr = rcar_i2c_status_get(priv);
if (msr & MAL) {
dev_dbg(dev, "Arbitration Lost\n");
rcar_i2c_flags_set(priv, (ID_DONE | ID_ARBLOST));
goto out;
}
if (msr & MST) {
dev_dbg(dev, "Stop\n");
rcar_i2c_flags_set(priv, ID_DONE);
goto out;
}
if (msr & MNR) {
dev_dbg(dev, "Nack\n");
rcar_i2c_bus_phase(priv, RCAR_BUS_PHASE_STOP);
rcar_i2c_irq_mask(priv, RCAR_IRQ_OPEN_FOR_STOP);
rcar_i2c_flags_set(priv, ID_NACK);
goto out;
}
if (rcar_i2c_is_recv(priv))
rcar_i2c_flags_set(priv, rcar_i2c_irq_recv(priv, msr));
else
rcar_i2c_flags_set(priv, rcar_i2c_irq_send(priv, msr));
out:
if (rcar_i2c_flags_has(priv, ID_DONE)) {
rcar_i2c_irq_mask(priv, RCAR_IRQ_CLOSE);
rcar_i2c_status_clear(priv);
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
rcar_i2c_clock_start(priv);
spin_unlock_irqrestore(&priv->lock, flags);
ret = -EINVAL;
for (i = 0; i < num; i++) {
spin_lock_irqsave(&priv->lock, flags);
priv->msg = &msgs[i];
priv->pos = 0;
priv->flags = 0;
if (priv->msg == &msgs[num - 1])
rcar_i2c_flags_set(priv, ID_LAST_MSG);
if (rcar_i2c_is_recv(priv))
ret = rcar_i2c_recv(priv);
else
ret = rcar_i2c_send(priv);
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
ret = -EREMOTEIO;
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
pm_runtime_put(dev);
if (ret < 0)
dev_err(dev, "error %d : %x\n", ret, priv->flags);
return ret;
}
static u32 rcar_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int rcar_i2c_probe(struct platform_device *pdev)
{
struct i2c_rcar_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct rcar_i2c_priv *priv;
struct i2c_adapter *adap;
struct resource *res;
struct device *dev = &pdev->dev;
u32 bus_speed;
int ret;
priv = devm_kzalloc(dev, sizeof(struct rcar_i2c_priv), GFP_KERNEL);
if (!priv) {
dev_err(dev, "no mem for private data\n");
return -ENOMEM;
}
bus_speed = 100000;
if (pdata && pdata->bus_speed)
bus_speed = pdata->bus_speed;
priv->devtype = platform_get_device_id(pdev)->driver_data;
ret = rcar_i2c_clock_calculate(priv, bus_speed, dev);
if (ret < 0)
return ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->io = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->io))
return PTR_ERR(priv->io);
priv->irq = platform_get_irq(pdev, 0);
init_waitqueue_head(&priv->wait);
spin_lock_init(&priv->lock);
adap = &priv->adap;
adap->nr = pdev->id;
adap->algo = &rcar_i2c_algo;
adap->class = I2C_CLASS_HWMON | I2C_CLASS_SPD;
adap->retries = 3;
adap->dev.parent = dev;
i2c_set_adapdata(adap, priv);
strlcpy(adap->name, pdev->name, sizeof(adap->name));
ret = devm_request_irq(dev, priv->irq, rcar_i2c_irq, 0,
dev_name(dev), priv);
if (ret < 0) {
dev_err(dev, "cannot get irq %d\n", priv->irq);
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
