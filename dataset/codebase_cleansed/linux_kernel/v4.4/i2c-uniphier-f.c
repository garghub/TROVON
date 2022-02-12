static void uniphier_fi2c_fill_txfifo(struct uniphier_fi2c_priv *priv,
bool first)
{
int fifo_space = UNIPHIER_FI2C_FIFO_SIZE;
if (first)
fifo_space--;
while (priv->len) {
if (fifo_space-- <= 0)
break;
dev_dbg(&priv->adap.dev, "write data: %02x\n", *priv->buf);
writel(*priv->buf++, priv->membase + UNIPHIER_FI2C_DTTX);
priv->len--;
}
}
static void uniphier_fi2c_drain_rxfifo(struct uniphier_fi2c_priv *priv)
{
int fifo_left = priv->flags & UNIPHIER_FI2C_BYTE_WISE ?
1 : UNIPHIER_FI2C_FIFO_SIZE;
while (priv->len) {
if (fifo_left-- <= 0)
break;
*priv->buf++ = readl(priv->membase + UNIPHIER_FI2C_DTRX);
dev_dbg(&priv->adap.dev, "read data: %02x\n", priv->buf[-1]);
priv->len--;
}
}
static void uniphier_fi2c_set_irqs(struct uniphier_fi2c_priv *priv)
{
writel(priv->enabled_irqs, priv->membase + UNIPHIER_FI2C_IE);
}
static void uniphier_fi2c_clear_irqs(struct uniphier_fi2c_priv *priv)
{
writel(-1, priv->membase + UNIPHIER_FI2C_IC);
}
static void uniphier_fi2c_stop(struct uniphier_fi2c_priv *priv)
{
dev_dbg(&priv->adap.dev, "stop condition\n");
priv->enabled_irqs |= UNIPHIER_FI2C_INT_STOP;
uniphier_fi2c_set_irqs(priv);
writel(UNIPHIER_FI2C_CR_MST | UNIPHIER_FI2C_CR_STO,
priv->membase + UNIPHIER_FI2C_CR);
}
static irqreturn_t uniphier_fi2c_interrupt(int irq, void *dev_id)
{
struct uniphier_fi2c_priv *priv = dev_id;
u32 irq_status;
irq_status = readl(priv->membase + UNIPHIER_FI2C_INT);
dev_dbg(&priv->adap.dev,
"interrupt: enabled_irqs=%04x, irq_status=%04x\n",
priv->enabled_irqs, irq_status);
if (irq_status & UNIPHIER_FI2C_INT_STOP)
goto complete;
if (unlikely(irq_status & UNIPHIER_FI2C_INT_AL)) {
dev_dbg(&priv->adap.dev, "arbitration lost\n");
priv->error = -EAGAIN;
goto complete;
}
if (unlikely(irq_status & UNIPHIER_FI2C_INT_NA)) {
dev_dbg(&priv->adap.dev, "could not get ACK\n");
priv->error = -ENXIO;
if (priv->flags & UNIPHIER_FI2C_RD) {
uniphier_fi2c_stop(priv);
priv->flags |= UNIPHIER_FI2C_DEFER_STOP_COMP;
goto complete;
}
goto stop;
}
if (irq_status & UNIPHIER_FI2C_INT_TE) {
if (!priv->len)
goto data_done;
uniphier_fi2c_fill_txfifo(priv, false);
goto handled;
}
if (irq_status & (UNIPHIER_FI2C_INT_RF | UNIPHIER_FI2C_INT_RB)) {
uniphier_fi2c_drain_rxfifo(priv);
if (!priv->len)
goto data_done;
if (unlikely(priv->flags & UNIPHIER_FI2C_MANUAL_NACK)) {
if (priv->len <= UNIPHIER_FI2C_FIFO_SIZE &&
!(priv->flags & UNIPHIER_FI2C_BYTE_WISE)) {
dev_dbg(&priv->adap.dev,
"enable read byte count IRQ\n");
priv->enabled_irqs |= UNIPHIER_FI2C_INT_RB;
uniphier_fi2c_set_irqs(priv);
priv->flags |= UNIPHIER_FI2C_BYTE_WISE;
}
if (priv->len <= 1) {
dev_dbg(&priv->adap.dev, "set NACK\n");
writel(UNIPHIER_FI2C_CR_MST |
UNIPHIER_FI2C_CR_NACK,
priv->membase + UNIPHIER_FI2C_CR);
}
}
goto handled;
}
return IRQ_NONE;
data_done:
if (priv->flags & UNIPHIER_FI2C_STOP) {
stop:
uniphier_fi2c_stop(priv);
} else {
complete:
priv->enabled_irqs = 0;
uniphier_fi2c_set_irqs(priv);
complete(&priv->comp);
}
handled:
uniphier_fi2c_clear_irqs(priv);
return IRQ_HANDLED;
}
static void uniphier_fi2c_tx_init(struct uniphier_fi2c_priv *priv, u16 addr)
{
priv->enabled_irqs |= UNIPHIER_FI2C_INT_TE;
writel(0, priv->membase + UNIPHIER_FI2C_TBC);
writel(UNIPHIER_FI2C_DTTX_CMD | addr << 1,
priv->membase + UNIPHIER_FI2C_DTTX);
uniphier_fi2c_fill_txfifo(priv, true);
}
static void uniphier_fi2c_rx_init(struct uniphier_fi2c_priv *priv, u16 addr)
{
priv->flags |= UNIPHIER_FI2C_RD;
if (likely(priv->len < 256)) {
writel(priv->len, priv->membase + UNIPHIER_FI2C_RBC);
priv->enabled_irqs |= UNIPHIER_FI2C_INT_RF |
UNIPHIER_FI2C_INT_RB;
} else {
writel(0, priv->membase + UNIPHIER_FI2C_RBC);
priv->flags |= UNIPHIER_FI2C_MANUAL_NACK;
priv->enabled_irqs |= UNIPHIER_FI2C_INT_RF;
}
writel(UNIPHIER_FI2C_DTTX_CMD | UNIPHIER_FI2C_DTTX_RD | addr << 1,
priv->membase + UNIPHIER_FI2C_DTTX);
}
static void uniphier_fi2c_reset(struct uniphier_fi2c_priv *priv)
{
writel(UNIPHIER_FI2C_RST_RST, priv->membase + UNIPHIER_FI2C_RST);
}
static void uniphier_fi2c_prepare_operation(struct uniphier_fi2c_priv *priv)
{
writel(UNIPHIER_FI2C_BRST_FOEN | UNIPHIER_FI2C_BRST_RSCL,
priv->membase + UNIPHIER_FI2C_BRST);
}
static void uniphier_fi2c_recover(struct uniphier_fi2c_priv *priv)
{
uniphier_fi2c_reset(priv);
i2c_recover_bus(&priv->adap);
}
static int uniphier_fi2c_master_xfer_one(struct i2c_adapter *adap,
struct i2c_msg *msg, bool stop)
{
struct uniphier_fi2c_priv *priv = i2c_get_adapdata(adap);
bool is_read = msg->flags & I2C_M_RD;
unsigned long time_left;
dev_dbg(&adap->dev, "%s: addr=0x%02x, len=%d, stop=%d\n",
is_read ? "receive" : "transmit", msg->addr, msg->len, stop);
priv->len = msg->len;
priv->buf = msg->buf;
priv->enabled_irqs = UNIPHIER_FI2C_INT_FAULTS;
priv->error = 0;
priv->flags = 0;
if (stop)
priv->flags |= UNIPHIER_FI2C_STOP;
reinit_completion(&priv->comp);
uniphier_fi2c_clear_irqs(priv);
writel(UNIPHIER_FI2C_RST_TBRST | UNIPHIER_FI2C_RST_RBRST,
priv->membase + UNIPHIER_FI2C_RST);
if (is_read)
uniphier_fi2c_rx_init(priv, msg->addr);
else
uniphier_fi2c_tx_init(priv, msg->addr);
uniphier_fi2c_set_irqs(priv);
dev_dbg(&adap->dev, "start condition\n");
writel(UNIPHIER_FI2C_CR_MST | UNIPHIER_FI2C_CR_STA,
priv->membase + UNIPHIER_FI2C_CR);
time_left = wait_for_completion_timeout(&priv->comp, adap->timeout);
if (!time_left) {
dev_err(&adap->dev, "transaction timeout.\n");
uniphier_fi2c_recover(priv);
return -ETIMEDOUT;
}
dev_dbg(&adap->dev, "complete\n");
if (unlikely(priv->flags & UNIPHIER_FI2C_DEFER_STOP_COMP)) {
u32 status = readl(priv->membase + UNIPHIER_FI2C_SR);
if (!(status & UNIPHIER_FI2C_SR_STS) ||
status & UNIPHIER_FI2C_SR_BB) {
dev_err(&adap->dev,
"stop condition was not completed.\n");
uniphier_fi2c_recover(priv);
return -EBUSY;
}
}
return priv->error;
}
static int uniphier_fi2c_check_bus_busy(struct i2c_adapter *adap)
{
struct uniphier_fi2c_priv *priv = i2c_get_adapdata(adap);
if (readl(priv->membase + UNIPHIER_FI2C_SR) & UNIPHIER_FI2C_SR_DB) {
if (priv->busy_cnt++ > 3) {
uniphier_fi2c_recover(priv);
priv->busy_cnt = 0;
}
return -EAGAIN;
}
priv->busy_cnt = 0;
return 0;
}
static int uniphier_fi2c_master_xfer(struct i2c_adapter *adap,
struct i2c_msg *msgs, int num)
{
struct i2c_msg *msg, *emsg = msgs + num;
int ret;
ret = uniphier_fi2c_check_bus_busy(adap);
if (ret)
return ret;
for (msg = msgs; msg < emsg; msg++) {
bool stop = !(msg + 1 < emsg && msg[1].flags & I2C_M_RD);
if (msg->flags & I2C_M_STOP)
stop = true;
ret = uniphier_fi2c_master_xfer_one(adap, msg, stop);
if (ret)
return ret;
}
return num;
}
static u32 uniphier_fi2c_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int uniphier_fi2c_get_scl(struct i2c_adapter *adap)
{
struct uniphier_fi2c_priv *priv = i2c_get_adapdata(adap);
return !!(readl(priv->membase + UNIPHIER_FI2C_BM) &
UNIPHIER_FI2C_BM_SCLS);
}
static void uniphier_fi2c_set_scl(struct i2c_adapter *adap, int val)
{
struct uniphier_fi2c_priv *priv = i2c_get_adapdata(adap);
writel(val ? UNIPHIER_FI2C_BRST_RSCL : 0,
priv->membase + UNIPHIER_FI2C_BRST);
}
static int uniphier_fi2c_get_sda(struct i2c_adapter *adap)
{
struct uniphier_fi2c_priv *priv = i2c_get_adapdata(adap);
return !!(readl(priv->membase + UNIPHIER_FI2C_BM) &
UNIPHIER_FI2C_BM_SDAS);
}
static void uniphier_fi2c_unprepare_recovery(struct i2c_adapter *adap)
{
uniphier_fi2c_prepare_operation(i2c_get_adapdata(adap));
}
static int uniphier_fi2c_clk_init(struct device *dev,
struct uniphier_fi2c_priv *priv)
{
struct device_node *np = dev->of_node;
unsigned long clk_rate;
u32 bus_speed, clk_count;
int ret;
if (of_property_read_u32(np, "clock-frequency", &bus_speed))
bus_speed = UNIPHIER_FI2C_DEFAULT_SPEED;
if (bus_speed > UNIPHIER_FI2C_MAX_SPEED)
bus_speed = UNIPHIER_FI2C_MAX_SPEED;
priv->clk = devm_clk_get(dev, NULL);
if (IS_ERR(priv->clk)) {
dev_err(dev, "failed to get clock\n");
return PTR_ERR(priv->clk);
}
ret = clk_prepare_enable(priv->clk);
if (ret)
return ret;
clk_rate = clk_get_rate(priv->clk);
uniphier_fi2c_reset(priv);
clk_count = clk_rate / bus_speed;
writel(clk_count, priv->membase + UNIPHIER_FI2C_CYC);
writel(clk_count / 2, priv->membase + UNIPHIER_FI2C_LCTL);
writel(clk_count / 2, priv->membase + UNIPHIER_FI2C_SSUT);
writel(clk_count / 16, priv->membase + UNIPHIER_FI2C_DSUT);
uniphier_fi2c_prepare_operation(priv);
return 0;
}
static int uniphier_fi2c_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct uniphier_fi2c_priv *priv;
struct resource *regs;
int irq;
int ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->membase = devm_ioremap_resource(dev, regs);
if (IS_ERR(priv->membase))
return PTR_ERR(priv->membase);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "failed to get IRQ number");
return irq;
}
init_completion(&priv->comp);
priv->adap.owner = THIS_MODULE;
priv->adap.algo = &uniphier_fi2c_algo;
priv->adap.dev.parent = dev;
priv->adap.dev.of_node = dev->of_node;
strlcpy(priv->adap.name, "UniPhier FI2C", sizeof(priv->adap.name));
priv->adap.bus_recovery_info = &uniphier_fi2c_bus_recovery_info;
i2c_set_adapdata(&priv->adap, priv);
platform_set_drvdata(pdev, priv);
ret = uniphier_fi2c_clk_init(dev, priv);
if (ret)
return ret;
ret = devm_request_irq(dev, irq, uniphier_fi2c_interrupt, 0,
pdev->name, priv);
if (ret) {
dev_err(dev, "failed to request irq %d\n", irq);
goto err;
}
ret = i2c_add_adapter(&priv->adap);
if (ret) {
dev_err(dev, "failed to add I2C adapter\n");
goto err;
}
err:
if (ret)
clk_disable_unprepare(priv->clk);
return ret;
}
static int uniphier_fi2c_remove(struct platform_device *pdev)
{
struct uniphier_fi2c_priv *priv = platform_get_drvdata(pdev);
i2c_del_adapter(&priv->adap);
clk_disable_unprepare(priv->clk);
return 0;
}
