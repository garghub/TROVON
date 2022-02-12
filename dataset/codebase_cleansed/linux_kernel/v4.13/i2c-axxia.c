static void i2c_int_disable(struct axxia_i2c_dev *idev, u32 mask)
{
u32 int_en;
int_en = readl(idev->base + MST_INT_ENABLE);
writel(int_en & ~mask, idev->base + MST_INT_ENABLE);
}
static void i2c_int_enable(struct axxia_i2c_dev *idev, u32 mask)
{
u32 int_en;
int_en = readl(idev->base + MST_INT_ENABLE);
writel(int_en | mask, idev->base + MST_INT_ENABLE);
}
static u32 ns_to_clk(u64 ns, u32 clk_mhz)
{
return div_u64(ns * clk_mhz, 1000);
}
static int axxia_i2c_init(struct axxia_i2c_dev *idev)
{
u32 divisor = clk_get_rate(idev->i2c_clk) / idev->bus_clk_rate;
u32 clk_mhz = clk_get_rate(idev->i2c_clk) / 1000000;
u32 t_setup;
u32 t_high, t_low;
u32 tmo_clk;
u32 prescale;
unsigned long timeout;
dev_dbg(idev->dev, "rate=%uHz per_clk=%uMHz -> ratio=1:%u\n",
idev->bus_clk_rate, clk_mhz, divisor);
writel(0x01, idev->base + SOFT_RESET);
timeout = jiffies + msecs_to_jiffies(100);
while (readl(idev->base + SOFT_RESET) & 1) {
if (time_after(jiffies, timeout)) {
dev_warn(idev->dev, "Soft reset failed\n");
break;
}
}
writel(0x1, idev->base + GLOBAL_CONTROL);
if (idev->bus_clk_rate <= 100000) {
t_high = divisor * 1 / 2;
t_low = divisor * 1 / 2;
t_setup = ns_to_clk(250, clk_mhz);
} else {
t_high = divisor * 1 / 3;
t_low = divisor * 2 / 3;
t_setup = ns_to_clk(100, clk_mhz);
}
writel(t_high, idev->base + SCL_HIGH_PERIOD);
writel(t_low, idev->base + SCL_LOW_PERIOD);
writel(t_setup, idev->base + SDA_SETUP_TIME);
writel(ns_to_clk(300, clk_mhz), idev->base + SDA_HOLD_TIME);
writel(ns_to_clk(50, clk_mhz), idev->base + SPIKE_FLTR_LEN);
tmo_clk = ns_to_clk(SCL_WAIT_TIMEOUT_NS, clk_mhz);
for (prescale = 0; prescale < 15; ++prescale) {
if (tmo_clk <= 0x7fff)
break;
tmo_clk >>= 1;
}
if (tmo_clk > 0x7fff)
tmo_clk = 0x7fff;
writel(prescale, idev->base + TIMER_CLOCK_DIV);
writel(WT_EN | WT_VALUE(tmo_clk), idev->base + WAIT_TIMER_CONTROL);
i2c_int_disable(idev, ~0);
writel(0x01, idev->base + INTERRUPT_ENABLE);
return 0;
}
static int i2c_m_rd(const struct i2c_msg *msg)
{
return (msg->flags & I2C_M_RD) != 0;
}
static int i2c_m_ten(const struct i2c_msg *msg)
{
return (msg->flags & I2C_M_TEN) != 0;
}
static int i2c_m_recv_len(const struct i2c_msg *msg)
{
return (msg->flags & I2C_M_RECV_LEN) != 0;
}
static int axxia_i2c_empty_rx_fifo(struct axxia_i2c_dev *idev)
{
struct i2c_msg *msg = idev->msg;
size_t rx_fifo_avail = readl(idev->base + MST_RX_FIFO);
int bytes_to_transfer = min(rx_fifo_avail, msg->len - idev->msg_xfrd);
while (bytes_to_transfer-- > 0) {
int c = readl(idev->base + MST_DATA);
if (idev->msg_xfrd == 0 && i2c_m_recv_len(msg)) {
if (c <= 0 || c > I2C_SMBUS_BLOCK_MAX) {
idev->msg_err = -EPROTO;
i2c_int_disable(idev, ~0);
complete(&idev->msg_complete);
break;
}
msg->len = 1 + c;
writel(msg->len, idev->base + MST_RX_XFER);
}
msg->buf[idev->msg_xfrd++] = c;
}
return 0;
}
static int axxia_i2c_fill_tx_fifo(struct axxia_i2c_dev *idev)
{
struct i2c_msg *msg = idev->msg;
size_t tx_fifo_avail = FIFO_SIZE - readl(idev->base + MST_TX_FIFO);
int bytes_to_transfer = min(tx_fifo_avail, msg->len - idev->msg_xfrd);
int ret = msg->len - idev->msg_xfrd - bytes_to_transfer;
while (bytes_to_transfer-- > 0)
writel(msg->buf[idev->msg_xfrd++], idev->base + MST_DATA);
return ret;
}
static irqreturn_t axxia_i2c_isr(int irq, void *_dev)
{
struct axxia_i2c_dev *idev = _dev;
u32 status;
if (!(readl(idev->base + INTERRUPT_STATUS) & INT_MST))
return IRQ_NONE;
status = readl(idev->base + MST_INT_STATUS);
if (!idev->msg) {
dev_warn(idev->dev, "unexpected interrupt\n");
goto out;
}
if (i2c_m_rd(idev->msg) && (status & MST_STATUS_RFL))
axxia_i2c_empty_rx_fifo(idev);
if (!i2c_m_rd(idev->msg) && (status & MST_STATUS_TFL)) {
if (axxia_i2c_fill_tx_fifo(idev) == 0)
i2c_int_disable(idev, MST_STATUS_TFL);
}
if (status & MST_STATUS_SCC) {
i2c_int_disable(idev, ~0);
complete(&idev->msg_complete);
} else if (status & MST_STATUS_SNS) {
i2c_int_disable(idev, ~0);
if (i2c_m_rd(idev->msg) && idev->msg_xfrd < idev->msg->len)
axxia_i2c_empty_rx_fifo(idev);
complete(&idev->msg_complete);
} else if (unlikely(status & MST_STATUS_ERR)) {
i2c_int_disable(idev, ~0);
if (status & MST_STATUS_AL)
idev->msg_err = -EAGAIN;
else if (status & MST_STATUS_NAK)
idev->msg_err = -ENXIO;
else
idev->msg_err = -EIO;
dev_dbg(idev->dev, "error %#x, addr=%#x rx=%u/%u tx=%u/%u\n",
status,
idev->msg->addr,
readl(idev->base + MST_RX_BYTES_XFRD),
readl(idev->base + MST_RX_XFER),
readl(idev->base + MST_TX_BYTES_XFRD),
readl(idev->base + MST_TX_XFER));
complete(&idev->msg_complete);
}
out:
writel(INT_MST, idev->base + INTERRUPT_STATUS);
return IRQ_HANDLED;
}
static int axxia_i2c_xfer_msg(struct axxia_i2c_dev *idev, struct i2c_msg *msg)
{
u32 int_mask = MST_STATUS_ERR | MST_STATUS_SNS;
u32 rx_xfer, tx_xfer;
u32 addr_1, addr_2;
unsigned long time_left;
idev->msg = msg;
idev->msg_xfrd = 0;
idev->msg_err = 0;
reinit_completion(&idev->msg_complete);
if (i2c_m_ten(msg)) {
addr_1 = 0xF0 | ((msg->addr >> 7) & 0x06);
addr_2 = msg->addr & 0xFF;
} else {
addr_1 = (msg->addr << 1) & 0xFF;
addr_2 = 0;
}
if (i2c_m_rd(msg)) {
rx_xfer = i2c_m_recv_len(msg) ? I2C_SMBUS_BLOCK_MAX : msg->len;
tx_xfer = 0;
addr_1 |= 1;
} else {
rx_xfer = 0;
tx_xfer = msg->len;
}
writel(rx_xfer, idev->base + MST_RX_XFER);
writel(tx_xfer, idev->base + MST_TX_XFER);
writel(addr_1, idev->base + MST_ADDR_1);
writel(addr_2, idev->base + MST_ADDR_2);
if (i2c_m_rd(msg))
int_mask |= MST_STATUS_RFL;
else if (axxia_i2c_fill_tx_fifo(idev) != 0)
int_mask |= MST_STATUS_TFL;
writel(CMD_MANUAL, idev->base + MST_COMMAND);
i2c_int_enable(idev, int_mask);
time_left = wait_for_completion_timeout(&idev->msg_complete,
I2C_XFER_TIMEOUT);
i2c_int_disable(idev, int_mask);
if (readl(idev->base + MST_COMMAND) & CMD_BUSY)
dev_warn(idev->dev, "busy after xfer\n");
if (time_left == 0)
idev->msg_err = -ETIMEDOUT;
if (idev->msg_err == -ETIMEDOUT)
i2c_recover_bus(&idev->adapter);
if (unlikely(idev->msg_err) && idev->msg_err != -ENXIO)
axxia_i2c_init(idev);
return idev->msg_err;
}
static int axxia_i2c_stop(struct axxia_i2c_dev *idev)
{
u32 int_mask = MST_STATUS_ERR | MST_STATUS_SCC;
unsigned long time_left;
reinit_completion(&idev->msg_complete);
writel(0xb, idev->base + MST_COMMAND);
i2c_int_enable(idev, int_mask);
time_left = wait_for_completion_timeout(&idev->msg_complete,
I2C_STOP_TIMEOUT);
i2c_int_disable(idev, int_mask);
if (time_left == 0)
return -ETIMEDOUT;
if (readl(idev->base + MST_COMMAND) & CMD_BUSY)
dev_warn(idev->dev, "busy after stop\n");
return 0;
}
static int
axxia_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msgs[], int num)
{
struct axxia_i2c_dev *idev = i2c_get_adapdata(adap);
int i;
int ret = 0;
for (i = 0; ret == 0 && i < num; ++i)
ret = axxia_i2c_xfer_msg(idev, &msgs[i]);
axxia_i2c_stop(idev);
return ret ? : i;
}
static int axxia_i2c_get_scl(struct i2c_adapter *adap)
{
struct axxia_i2c_dev *idev = i2c_get_adapdata(adap);
return !!(readl(idev->base + I2C_BUS_MONITOR) & BM_SCLS);
}
static void axxia_i2c_set_scl(struct i2c_adapter *adap, int val)
{
struct axxia_i2c_dev *idev = i2c_get_adapdata(adap);
u32 tmp;
tmp = readl(idev->base + I2C_BUS_MONITOR) & BM_SDAC;
if (!val)
tmp |= BM_SCLC;
writel(tmp, idev->base + I2C_BUS_MONITOR);
}
static int axxia_i2c_get_sda(struct i2c_adapter *adap)
{
struct axxia_i2c_dev *idev = i2c_get_adapdata(adap);
return !!(readl(idev->base + I2C_BUS_MONITOR) & BM_SDAS);
}
static u32 axxia_i2c_func(struct i2c_adapter *adap)
{
u32 caps = (I2C_FUNC_I2C | I2C_FUNC_10BIT_ADDR |
I2C_FUNC_SMBUS_EMUL | I2C_FUNC_SMBUS_BLOCK_DATA);
return caps;
}
static int axxia_i2c_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct axxia_i2c_dev *idev = NULL;
struct resource *res;
void __iomem *base;
int irq;
int ret = 0;
idev = devm_kzalloc(&pdev->dev, sizeof(*idev), GFP_KERNEL);
if (!idev)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "missing interrupt resource\n");
return irq;
}
idev->i2c_clk = devm_clk_get(&pdev->dev, "i2c");
if (IS_ERR(idev->i2c_clk)) {
dev_err(&pdev->dev, "missing clock\n");
return PTR_ERR(idev->i2c_clk);
}
idev->base = base;
idev->dev = &pdev->dev;
init_completion(&idev->msg_complete);
of_property_read_u32(np, "clock-frequency", &idev->bus_clk_rate);
if (idev->bus_clk_rate == 0)
idev->bus_clk_rate = 100000;
ret = axxia_i2c_init(idev);
if (ret) {
dev_err(&pdev->dev, "failed to initialize\n");
return ret;
}
ret = devm_request_irq(&pdev->dev, irq, axxia_i2c_isr, 0,
pdev->name, idev);
if (ret) {
dev_err(&pdev->dev, "failed to claim IRQ%d\n", irq);
return ret;
}
ret = clk_prepare_enable(idev->i2c_clk);
if (ret) {
dev_err(&pdev->dev, "failed to enable clock\n");
return ret;
}
i2c_set_adapdata(&idev->adapter, idev);
strlcpy(idev->adapter.name, pdev->name, sizeof(idev->adapter.name));
idev->adapter.owner = THIS_MODULE;
idev->adapter.algo = &axxia_i2c_algo;
idev->adapter.bus_recovery_info = &axxia_i2c_recovery_info;
idev->adapter.quirks = &axxia_i2c_quirks;
idev->adapter.dev.parent = &pdev->dev;
idev->adapter.dev.of_node = pdev->dev.of_node;
platform_set_drvdata(pdev, idev);
ret = i2c_add_adapter(&idev->adapter);
if (ret) {
clk_disable_unprepare(idev->i2c_clk);
return ret;
}
return 0;
}
static int axxia_i2c_remove(struct platform_device *pdev)
{
struct axxia_i2c_dev *idev = platform_get_drvdata(pdev);
clk_disable_unprepare(idev->i2c_clk);
i2c_del_adapter(&idev->adapter);
return 0;
}
