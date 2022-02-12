static void
altr_i2c_int_enable(struct altr_i2c_dev *idev, u32 mask, bool enable)
{
unsigned long flags;
u32 int_en;
spin_lock_irqsave(&idev->lock, flags);
int_en = readl(idev->base + ALTR_I2C_ISER);
if (enable)
idev->isr_mask = int_en | mask;
else
idev->isr_mask = int_en & ~mask;
writel(idev->isr_mask, idev->base + ALTR_I2C_ISER);
spin_unlock_irqrestore(&idev->lock, flags);
}
static void altr_i2c_int_clear(struct altr_i2c_dev *idev, u32 mask)
{
u32 int_en = readl(idev->base + ALTR_I2C_ISR);
writel(int_en | mask, idev->base + ALTR_I2C_ISR);
}
static void altr_i2c_core_disable(struct altr_i2c_dev *idev)
{
u32 tmp = readl(idev->base + ALTR_I2C_CTRL);
writel(tmp & ~ALTR_I2C_CTRL_EN, idev->base + ALTR_I2C_CTRL);
}
static void altr_i2c_core_enable(struct altr_i2c_dev *idev)
{
u32 tmp = readl(idev->base + ALTR_I2C_CTRL);
writel(tmp | ALTR_I2C_CTRL_EN, idev->base + ALTR_I2C_CTRL);
}
static void altr_i2c_reset(struct altr_i2c_dev *idev)
{
altr_i2c_core_disable(idev);
altr_i2c_core_enable(idev);
}
static inline void altr_i2c_stop(struct altr_i2c_dev *idev)
{
writel(ALTR_I2C_TFR_CMD_STO, idev->base + ALTR_I2C_TFR_CMD);
}
static void altr_i2c_init(struct altr_i2c_dev *idev)
{
u32 divisor = clk_get_rate(idev->i2c_clk) / idev->bus_clk_rate;
u32 clk_mhz = clk_get_rate(idev->i2c_clk) / 1000000;
u32 tmp = (ALTR_I2C_THRESHOLD << ALTR_I2C_CTRL_RXT_SHFT) |
(ALTR_I2C_THRESHOLD << ALTR_I2C_CTRL_TCT_SHFT);
u32 t_high, t_low;
if (idev->bus_clk_rate <= 100000) {
tmp &= ~ALTR_I2C_CTRL_BSPEED;
t_high = divisor * 1 / 2;
t_low = divisor * 1 / 2;
} else {
tmp |= ALTR_I2C_CTRL_BSPEED;
t_high = divisor * 1 / 3;
t_low = divisor * 2 / 3;
}
writel(tmp, idev->base + ALTR_I2C_CTRL);
dev_dbg(idev->dev, "rate=%uHz per_clk=%uMHz -> ratio=1:%u\n",
idev->bus_clk_rate, clk_mhz, divisor);
altr_i2c_reset(idev);
writel(t_high, idev->base + ALTR_I2C_SCL_HIGH);
writel(t_low, idev->base + ALTR_I2C_SCL_LOW);
writel(div_u64(300 * clk_mhz, 1000), idev->base + ALTR_I2C_SDA_HOLD);
altr_i2c_int_enable(idev, ALTR_I2C_ALL_IRQ, false);
}
static void altr_i2c_transfer(struct altr_i2c_dev *idev, u32 data)
{
if (idev->msg_len == 1)
data |= ALTR_I2C_TFR_CMD_STO;
if (idev->msg_len > 0)
writel(data, idev->base + ALTR_I2C_TFR_CMD);
}
static void altr_i2c_empty_rx_fifo(struct altr_i2c_dev *idev)
{
size_t rx_fifo_avail = readl(idev->base + ALTR_I2C_RX_FIFO_LVL);
int bytes_to_transfer = min(rx_fifo_avail, idev->msg_len);
while (bytes_to_transfer-- > 0) {
*idev->buf++ = readl(idev->base + ALTR_I2C_RX_DATA);
idev->msg_len--;
altr_i2c_transfer(idev, 0);
}
}
static int altr_i2c_fill_tx_fifo(struct altr_i2c_dev *idev)
{
size_t tx_fifo_avail = idev->fifo_size - readl(idev->base +
ALTR_I2C_TC_FIFO_LVL);
int bytes_to_transfer = min(tx_fifo_avail, idev->msg_len);
int ret = idev->msg_len - bytes_to_transfer;
while (bytes_to_transfer-- > 0) {
altr_i2c_transfer(idev, *idev->buf++);
idev->msg_len--;
}
return ret;
}
static irqreturn_t altr_i2c_isr_quick(int irq, void *_dev)
{
struct altr_i2c_dev *idev = _dev;
irqreturn_t ret = IRQ_HANDLED;
idev->isr_status = readl(idev->base + ALTR_I2C_ISR) & idev->isr_mask;
if (idev->isr_status)
ret = IRQ_WAKE_THREAD;
return ret;
}
static irqreturn_t altr_i2c_isr(int irq, void *_dev)
{
int ret;
bool read, finish = false;
struct altr_i2c_dev *idev = _dev;
u32 status = idev->isr_status;
if (!idev->msg) {
dev_warn(idev->dev, "unexpected interrupt\n");
altr_i2c_int_clear(idev, ALTR_I2C_ALL_IRQ);
return IRQ_HANDLED;
}
read = (idev->msg->flags & I2C_M_RD) != 0;
if (unlikely(status & ALTR_I2C_ISR_ARB)) {
altr_i2c_int_clear(idev, ALTR_I2C_ISR_ARB);
idev->msg_err = -EAGAIN;
finish = true;
} else if (unlikely(status & ALTR_I2C_ISR_NACK)) {
dev_dbg(idev->dev, "Could not get ACK\n");
idev->msg_err = -ENXIO;
altr_i2c_int_clear(idev, ALTR_I2C_ISR_NACK);
altr_i2c_stop(idev);
finish = true;
} else if (read && unlikely(status & ALTR_I2C_ISR_RXOF)) {
altr_i2c_empty_rx_fifo(idev);
altr_i2c_int_clear(idev, ALTR_I2C_ISR_RXRDY);
altr_i2c_stop(idev);
dev_err(idev->dev, "RX FIFO Overflow\n");
finish = true;
} else if (read && (status & ALTR_I2C_ISR_RXRDY)) {
altr_i2c_empty_rx_fifo(idev);
altr_i2c_int_clear(idev, ALTR_I2C_ISR_RXRDY);
if (!idev->msg_len)
finish = true;
} else if (!read && (status & ALTR_I2C_ISR_TXRDY)) {
altr_i2c_int_clear(idev, ALTR_I2C_ISR_TXRDY);
if (idev->msg_len > 0)
altr_i2c_fill_tx_fifo(idev);
else
finish = true;
} else {
dev_warn(idev->dev, "Unexpected interrupt: 0x%x\n", status);
altr_i2c_int_clear(idev, ALTR_I2C_ALL_IRQ);
}
if (finish) {
ret = readl_poll_timeout_atomic(idev->base + ALTR_I2C_STATUS,
status,
!(status & ALTR_I2C_STAT_CORE),
1, ALTR_I2C_TIMEOUT);
if (ret)
dev_err(idev->dev, "message timeout\n");
altr_i2c_int_enable(idev, ALTR_I2C_ALL_IRQ, false);
altr_i2c_int_clear(idev, ALTR_I2C_ALL_IRQ);
complete(&idev->msg_complete);
dev_dbg(idev->dev, "Message Complete\n");
}
return IRQ_HANDLED;
}
static int altr_i2c_xfer_msg(struct altr_i2c_dev *idev, struct i2c_msg *msg)
{
u32 imask = ALTR_I2C_ISR_RXOF | ALTR_I2C_ISR_ARB | ALTR_I2C_ISR_NACK;
unsigned long time_left;
u32 value;
u8 addr = i2c_8bit_addr_from_msg(msg);
idev->msg = msg;
idev->msg_len = msg->len;
idev->buf = msg->buf;
idev->msg_err = 0;
reinit_completion(&idev->msg_complete);
altr_i2c_core_enable(idev);
do {
readl(idev->base + ALTR_I2C_RX_DATA);
} while (readl(idev->base + ALTR_I2C_RX_FIFO_LVL));
writel(ALTR_I2C_TFR_CMD_STA | addr, idev->base + ALTR_I2C_TFR_CMD);
if ((msg->flags & I2C_M_RD) != 0) {
imask |= ALTR_I2C_ISER_RXOF_EN | ALTR_I2C_ISER_RXRDY_EN;
altr_i2c_int_enable(idev, imask, true);
altr_i2c_transfer(idev, 0);
} else {
imask |= ALTR_I2C_ISR_TXRDY;
altr_i2c_int_enable(idev, imask, true);
altr_i2c_fill_tx_fifo(idev);
}
time_left = wait_for_completion_timeout(&idev->msg_complete,
ALTR_I2C_XFER_TIMEOUT);
altr_i2c_int_enable(idev, imask, false);
value = readl(idev->base + ALTR_I2C_STATUS) & ALTR_I2C_STAT_CORE;
if (value)
dev_err(idev->dev, "Core Status not IDLE...\n");
if (time_left == 0) {
idev->msg_err = -ETIMEDOUT;
dev_dbg(idev->dev, "Transaction timed out.\n");
}
altr_i2c_core_disable(idev);
return idev->msg_err;
}
static int
altr_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs, int num)
{
struct altr_i2c_dev *idev = i2c_get_adapdata(adap);
int i, ret;
for (i = 0; i < num; i++) {
ret = altr_i2c_xfer_msg(idev, msgs++);
if (ret)
return ret;
}
return num;
}
static u32 altr_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int altr_i2c_probe(struct platform_device *pdev)
{
struct altr_i2c_dev *idev = NULL;
struct resource *res;
int irq, ret;
u32 val;
idev = devm_kzalloc(&pdev->dev, sizeof(*idev), GFP_KERNEL);
if (!idev)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
idev->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(idev->base))
return PTR_ERR(idev->base);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "missing interrupt resource\n");
return irq;
}
idev->i2c_clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(idev->i2c_clk)) {
dev_err(&pdev->dev, "missing clock\n");
return PTR_ERR(idev->i2c_clk);
}
idev->dev = &pdev->dev;
init_completion(&idev->msg_complete);
spin_lock_init(&idev->lock);
val = device_property_read_u32(idev->dev, "fifo-size",
&idev->fifo_size);
if (val) {
dev_err(&pdev->dev, "FIFO size set to default of %d\n",
ALTR_I2C_DFLT_FIFO_SZ);
idev->fifo_size = ALTR_I2C_DFLT_FIFO_SZ;
}
val = device_property_read_u32(idev->dev, "clock-frequency",
&idev->bus_clk_rate);
if (val) {
dev_err(&pdev->dev, "Default to 100kHz\n");
idev->bus_clk_rate = 100000;
}
if (idev->bus_clk_rate > 400000) {
dev_err(&pdev->dev, "invalid clock-frequency %d\n",
idev->bus_clk_rate);
return -EINVAL;
}
ret = devm_request_threaded_irq(&pdev->dev, irq, altr_i2c_isr_quick,
altr_i2c_isr, IRQF_ONESHOT,
pdev->name, idev);
if (ret) {
dev_err(&pdev->dev, "failed to claim IRQ %d\n", irq);
return ret;
}
ret = clk_prepare_enable(idev->i2c_clk);
if (ret) {
dev_err(&pdev->dev, "failed to enable clock\n");
return ret;
}
altr_i2c_init(idev);
i2c_set_adapdata(&idev->adapter, idev);
strlcpy(idev->adapter.name, pdev->name, sizeof(idev->adapter.name));
idev->adapter.owner = THIS_MODULE;
idev->adapter.algo = &altr_i2c_algo;
idev->adapter.dev.parent = &pdev->dev;
idev->adapter.dev.of_node = pdev->dev.of_node;
platform_set_drvdata(pdev, idev);
ret = i2c_add_adapter(&idev->adapter);
if (ret) {
clk_disable_unprepare(idev->i2c_clk);
return ret;
}
dev_info(&pdev->dev, "Altera SoftIP I2C Probe Complete\n");
return 0;
}
static int altr_i2c_remove(struct platform_device *pdev)
{
struct altr_i2c_dev *idev = platform_get_drvdata(pdev);
clk_disable_unprepare(idev->i2c_clk);
i2c_del_adapter(&idev->adapter);
return 0;
}
