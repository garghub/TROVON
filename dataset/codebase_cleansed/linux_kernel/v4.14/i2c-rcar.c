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
static void rcar_i2c_dma_unmap(struct rcar_i2c_priv *priv)
{
struct dma_chan *chan = priv->dma_direction == DMA_FROM_DEVICE
? priv->dma_rx : priv->dma_tx;
rcar_i2c_write(priv, ICDMAER, 0);
rcar_i2c_write(priv, ICFBSCR, TCYC06);
dma_unmap_single(chan->device->dev, sg_dma_address(&priv->sg),
sg_dma_len(&priv->sg), priv->dma_direction);
priv->dma_direction = DMA_NONE;
}
static void rcar_i2c_cleanup_dma(struct rcar_i2c_priv *priv)
{
if (priv->dma_direction == DMA_NONE)
return;
else if (priv->dma_direction == DMA_FROM_DEVICE)
dmaengine_terminate_all(priv->dma_rx);
else if (priv->dma_direction == DMA_TO_DEVICE)
dmaengine_terminate_all(priv->dma_tx);
rcar_i2c_dma_unmap(priv);
}
static void rcar_i2c_dma_callback(void *data)
{
struct rcar_i2c_priv *priv = data;
priv->pos += sg_dma_len(&priv->sg);
rcar_i2c_dma_unmap(priv);
}
static void rcar_i2c_dma(struct rcar_i2c_priv *priv)
{
struct device *dev = rcar_i2c_priv_to_dev(priv);
struct i2c_msg *msg = priv->msg;
bool read = msg->flags & I2C_M_RD;
enum dma_data_direction dir = read ? DMA_FROM_DEVICE : DMA_TO_DEVICE;
struct dma_chan *chan = read ? priv->dma_rx : priv->dma_tx;
struct dma_async_tx_descriptor *txdesc;
dma_addr_t dma_addr;
dma_cookie_t cookie;
unsigned char *buf;
int len;
if (IS_ERR(chan) || msg->len < 8)
return;
if (read) {
buf = priv->msg->buf;
len = priv->msg->len - 2;
} else {
buf = priv->msg->buf + 1;
len = priv->msg->len - 1;
}
dma_addr = dma_map_single(chan->device->dev, buf, len, dir);
if (dma_mapping_error(chan->device->dev, dma_addr)) {
dev_dbg(dev, "dma map failed, using PIO\n");
return;
}
sg_dma_len(&priv->sg) = len;
sg_dma_address(&priv->sg) = dma_addr;
priv->dma_direction = dir;
txdesc = dmaengine_prep_slave_sg(chan, &priv->sg, 1,
read ? DMA_DEV_TO_MEM : DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!txdesc) {
dev_dbg(dev, "dma prep slave sg failed, using PIO\n");
rcar_i2c_cleanup_dma(priv);
return;
}
txdesc->callback = rcar_i2c_dma_callback;
txdesc->callback_param = priv;
cookie = dmaengine_submit(txdesc);
if (dma_submit_error(cookie)) {
dev_dbg(dev, "submitting dma failed, using PIO\n");
rcar_i2c_cleanup_dma(priv);
return;
}
rcar_i2c_write(priv, ICFBSCR, TCYC17);
if (read)
rcar_i2c_write(priv, ICDMAER, RMDMAE);
else
rcar_i2c_write(priv, ICDMAER, TMDMAE);
dma_async_issue_pending(chan);
}
static void rcar_i2c_irq_send(struct rcar_i2c_priv *priv, u32 msr)
{
struct i2c_msg *msg = priv->msg;
if (!(msr & MDE))
return;
if (priv->pos < msg->len) {
rcar_i2c_write(priv, ICRXTX, msg->buf[priv->pos]);
priv->pos++;
if (msr & MAT)
rcar_i2c_dma(priv);
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
rcar_i2c_dma(priv);
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
static struct dma_chan *rcar_i2c_request_dma_chan(struct device *dev,
enum dma_transfer_direction dir,
dma_addr_t port_addr)
{
struct dma_chan *chan;
struct dma_slave_config cfg;
char *chan_name = dir == DMA_MEM_TO_DEV ? "tx" : "rx";
int ret;
chan = dma_request_chan(dev, chan_name);
if (IS_ERR(chan)) {
dev_dbg(dev, "request_channel failed for %s (%ld)\n",
chan_name, PTR_ERR(chan));
return chan;
}
memset(&cfg, 0, sizeof(cfg));
cfg.direction = dir;
if (dir == DMA_MEM_TO_DEV) {
cfg.dst_addr = port_addr;
cfg.dst_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
} else {
cfg.src_addr = port_addr;
cfg.src_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
}
ret = dmaengine_slave_config(chan, &cfg);
if (ret) {
dev_dbg(dev, "slave_config failed for %s (%d)\n",
chan_name, ret);
dma_release_channel(chan);
return ERR_PTR(ret);
}
dev_dbg(dev, "got DMA channel for %s\n", chan_name);
return chan;
}
static void rcar_i2c_request_dma(struct rcar_i2c_priv *priv,
struct i2c_msg *msg)
{
struct device *dev = rcar_i2c_priv_to_dev(priv);
bool read;
struct dma_chan *chan;
enum dma_transfer_direction dir;
read = msg->flags & I2C_M_RD;
chan = read ? priv->dma_rx : priv->dma_tx;
if (PTR_ERR(chan) != -EPROBE_DEFER)
return;
dir = read ? DMA_DEV_TO_MEM : DMA_MEM_TO_DEV;
chan = rcar_i2c_request_dma_chan(dev, dir, priv->res->start + ICRXTX);
if (read)
priv->dma_rx = chan;
else
priv->dma_tx = chan;
}
static void rcar_i2c_release_dma(struct rcar_i2c_priv *priv)
{
if (!IS_ERR(priv->dma_tx)) {
dma_release_channel(priv->dma_tx);
priv->dma_tx = ERR_PTR(-EPROBE_DEFER);
}
if (!IS_ERR(priv->dma_rx)) {
dma_release_channel(priv->dma_rx);
priv->dma_rx = ERR_PTR(-EPROBE_DEFER);
}
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
rcar_i2c_init(priv);
ret = rcar_i2c_bus_barrier(priv);
if (ret < 0)
goto out;
for (i = 0; i < num; i++) {
if (msgs[i].len == 0) {
ret = -EOPNOTSUPP;
goto out;
}
rcar_i2c_request_dma(priv, msgs + i);
}
priv->msg = msgs;
priv->msgs_left = num;
priv->flags = (priv->flags & ID_P_MASK) | ID_FIRST_MSG;
rcar_i2c_prepare_msg(priv);
time_left = wait_event_timeout(priv->wait, priv->flags & ID_DONE,
num * adap->timeout);
if (!time_left) {
rcar_i2c_cleanup_dma(priv);
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
priv->res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->io = devm_ioremap_resource(dev, priv->res);
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
sg_init_table(&priv->sg, 1);
priv->dma_direction = DMA_NONE;
priv->dma_rx = priv->dma_tx = ERR_PTR(-EPROBE_DEFER);
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
ret = rcar_i2c_clock_calculate(priv, &i2c_t);
if (ret < 0)
goto out_pm_put;
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
if (ret < 0)
goto out_pm_disable;
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
rcar_i2c_release_dma(priv);
if (priv->flags & ID_P_PM_BLOCKED)
pm_runtime_put(dev);
pm_runtime_disable(dev);
return 0;
}
