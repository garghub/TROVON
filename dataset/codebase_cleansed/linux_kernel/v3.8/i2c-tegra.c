static void dvc_writel(struct tegra_i2c_dev *i2c_dev, u32 val, unsigned long reg)
{
writel(val, i2c_dev->base + reg);
}
static u32 dvc_readl(struct tegra_i2c_dev *i2c_dev, unsigned long reg)
{
return readl(i2c_dev->base + reg);
}
static unsigned long tegra_i2c_reg_addr(struct tegra_i2c_dev *i2c_dev,
unsigned long reg)
{
if (i2c_dev->is_dvc)
reg += (reg >= I2C_TX_FIFO) ? 0x10 : 0x40;
return reg;
}
static void i2c_writel(struct tegra_i2c_dev *i2c_dev, u32 val,
unsigned long reg)
{
writel(val, i2c_dev->base + tegra_i2c_reg_addr(i2c_dev, reg));
if (reg != I2C_TX_FIFO)
readl(i2c_dev->base + tegra_i2c_reg_addr(i2c_dev, reg));
}
static u32 i2c_readl(struct tegra_i2c_dev *i2c_dev, unsigned long reg)
{
return readl(i2c_dev->base + tegra_i2c_reg_addr(i2c_dev, reg));
}
static void i2c_writesl(struct tegra_i2c_dev *i2c_dev, void *data,
unsigned long reg, int len)
{
writesl(i2c_dev->base + tegra_i2c_reg_addr(i2c_dev, reg), data, len);
}
static void i2c_readsl(struct tegra_i2c_dev *i2c_dev, void *data,
unsigned long reg, int len)
{
readsl(i2c_dev->base + tegra_i2c_reg_addr(i2c_dev, reg), data, len);
}
static void tegra_i2c_mask_irq(struct tegra_i2c_dev *i2c_dev, u32 mask)
{
u32 int_mask = i2c_readl(i2c_dev, I2C_INT_MASK);
int_mask &= ~mask;
i2c_writel(i2c_dev, int_mask, I2C_INT_MASK);
}
static void tegra_i2c_unmask_irq(struct tegra_i2c_dev *i2c_dev, u32 mask)
{
u32 int_mask = i2c_readl(i2c_dev, I2C_INT_MASK);
int_mask |= mask;
i2c_writel(i2c_dev, int_mask, I2C_INT_MASK);
}
static int tegra_i2c_flush_fifos(struct tegra_i2c_dev *i2c_dev)
{
unsigned long timeout = jiffies + HZ;
u32 val = i2c_readl(i2c_dev, I2C_FIFO_CONTROL);
val |= I2C_FIFO_CONTROL_TX_FLUSH | I2C_FIFO_CONTROL_RX_FLUSH;
i2c_writel(i2c_dev, val, I2C_FIFO_CONTROL);
while (i2c_readl(i2c_dev, I2C_FIFO_CONTROL) &
(I2C_FIFO_CONTROL_TX_FLUSH | I2C_FIFO_CONTROL_RX_FLUSH)) {
if (time_after(jiffies, timeout)) {
dev_warn(i2c_dev->dev, "timeout waiting for fifo flush\n");
return -ETIMEDOUT;
}
msleep(1);
}
return 0;
}
static int tegra_i2c_empty_rx_fifo(struct tegra_i2c_dev *i2c_dev)
{
u32 val;
int rx_fifo_avail;
u8 *buf = i2c_dev->msg_buf;
size_t buf_remaining = i2c_dev->msg_buf_remaining;
int words_to_transfer;
val = i2c_readl(i2c_dev, I2C_FIFO_STATUS);
rx_fifo_avail = (val & I2C_FIFO_STATUS_RX_MASK) >>
I2C_FIFO_STATUS_RX_SHIFT;
words_to_transfer = buf_remaining / BYTES_PER_FIFO_WORD;
if (words_to_transfer > rx_fifo_avail)
words_to_transfer = rx_fifo_avail;
i2c_readsl(i2c_dev, buf, I2C_RX_FIFO, words_to_transfer);
buf += words_to_transfer * BYTES_PER_FIFO_WORD;
buf_remaining -= words_to_transfer * BYTES_PER_FIFO_WORD;
rx_fifo_avail -= words_to_transfer;
if (rx_fifo_avail > 0 && buf_remaining > 0) {
BUG_ON(buf_remaining > 3);
val = i2c_readl(i2c_dev, I2C_RX_FIFO);
memcpy(buf, &val, buf_remaining);
buf_remaining = 0;
rx_fifo_avail--;
}
BUG_ON(rx_fifo_avail > 0 && buf_remaining > 0);
i2c_dev->msg_buf_remaining = buf_remaining;
i2c_dev->msg_buf = buf;
return 0;
}
static int tegra_i2c_fill_tx_fifo(struct tegra_i2c_dev *i2c_dev)
{
u32 val;
int tx_fifo_avail;
u8 *buf = i2c_dev->msg_buf;
size_t buf_remaining = i2c_dev->msg_buf_remaining;
int words_to_transfer;
val = i2c_readl(i2c_dev, I2C_FIFO_STATUS);
tx_fifo_avail = (val & I2C_FIFO_STATUS_TX_MASK) >>
I2C_FIFO_STATUS_TX_SHIFT;
words_to_transfer = buf_remaining / BYTES_PER_FIFO_WORD;
if (words_to_transfer) {
if (words_to_transfer > tx_fifo_avail)
words_to_transfer = tx_fifo_avail;
buf_remaining -= words_to_transfer * BYTES_PER_FIFO_WORD;
tx_fifo_avail -= words_to_transfer;
i2c_dev->msg_buf_remaining = buf_remaining;
i2c_dev->msg_buf = buf +
words_to_transfer * BYTES_PER_FIFO_WORD;
barrier();
i2c_writesl(i2c_dev, buf, I2C_TX_FIFO, words_to_transfer);
buf += words_to_transfer * BYTES_PER_FIFO_WORD;
}
if (tx_fifo_avail > 0 && buf_remaining > 0) {
BUG_ON(buf_remaining > 3);
memcpy(&val, buf, buf_remaining);
i2c_dev->msg_buf_remaining = 0;
i2c_dev->msg_buf = NULL;
barrier();
i2c_writel(i2c_dev, val, I2C_TX_FIFO);
}
return 0;
}
static void tegra_dvc_init(struct tegra_i2c_dev *i2c_dev)
{
u32 val = 0;
val = dvc_readl(i2c_dev, DVC_CTRL_REG3);
val |= DVC_CTRL_REG3_SW_PROG;
val |= DVC_CTRL_REG3_I2C_DONE_INTR_EN;
dvc_writel(i2c_dev, val, DVC_CTRL_REG3);
val = dvc_readl(i2c_dev, DVC_CTRL_REG1);
val |= DVC_CTRL_REG1_INTR_EN;
dvc_writel(i2c_dev, val, DVC_CTRL_REG1);
}
static inline int tegra_i2c_clock_enable(struct tegra_i2c_dev *i2c_dev)
{
int ret;
ret = clk_prepare_enable(i2c_dev->fast_clk);
if (ret < 0) {
dev_err(i2c_dev->dev,
"Enabling fast clk failed, err %d\n", ret);
return ret;
}
ret = clk_prepare_enable(i2c_dev->div_clk);
if (ret < 0) {
dev_err(i2c_dev->dev,
"Enabling div clk failed, err %d\n", ret);
clk_disable_unprepare(i2c_dev->fast_clk);
}
return ret;
}
static inline void tegra_i2c_clock_disable(struct tegra_i2c_dev *i2c_dev)
{
clk_disable_unprepare(i2c_dev->div_clk);
clk_disable_unprepare(i2c_dev->fast_clk);
}
static int tegra_i2c_init(struct tegra_i2c_dev *i2c_dev)
{
u32 val;
int err = 0;
tegra_i2c_clock_enable(i2c_dev);
tegra_periph_reset_assert(i2c_dev->div_clk);
udelay(2);
tegra_periph_reset_deassert(i2c_dev->div_clk);
if (i2c_dev->is_dvc)
tegra_dvc_init(i2c_dev);
val = I2C_CNFG_NEW_MASTER_FSM | I2C_CNFG_PACKET_MODE_EN |
(0x2 << I2C_CNFG_DEBOUNCE_CNT_SHIFT);
i2c_writel(i2c_dev, val, I2C_CNFG);
i2c_writel(i2c_dev, 0, I2C_INT_MASK);
clk_set_rate(i2c_dev->div_clk, i2c_dev->bus_clk_rate * 8);
if (!i2c_dev->is_dvc) {
u32 sl_cfg = i2c_readl(i2c_dev, I2C_SL_CNFG);
sl_cfg |= I2C_SL_CNFG_NACK | I2C_SL_CNFG_NEWSL;
i2c_writel(i2c_dev, sl_cfg, I2C_SL_CNFG);
i2c_writel(i2c_dev, 0xfc, I2C_SL_ADDR1);
i2c_writel(i2c_dev, 0x00, I2C_SL_ADDR2);
}
val = 7 << I2C_FIFO_CONTROL_TX_TRIG_SHIFT |
0 << I2C_FIFO_CONTROL_RX_TRIG_SHIFT;
i2c_writel(i2c_dev, val, I2C_FIFO_CONTROL);
if (tegra_i2c_flush_fifos(i2c_dev))
err = -ETIMEDOUT;
tegra_i2c_clock_disable(i2c_dev);
if (i2c_dev->irq_disabled) {
i2c_dev->irq_disabled = 0;
enable_irq(i2c_dev->irq);
}
return err;
}
static irqreturn_t tegra_i2c_isr(int irq, void *dev_id)
{
u32 status;
const u32 status_err = I2C_INT_NO_ACK | I2C_INT_ARBITRATION_LOST;
struct tegra_i2c_dev *i2c_dev = dev_id;
status = i2c_readl(i2c_dev, I2C_INT_STATUS);
if (status == 0) {
dev_warn(i2c_dev->dev, "irq status 0 %08x %08x %08x\n",
i2c_readl(i2c_dev, I2C_PACKET_TRANSFER_STATUS),
i2c_readl(i2c_dev, I2C_STATUS),
i2c_readl(i2c_dev, I2C_CNFG));
i2c_dev->msg_err |= I2C_ERR_UNKNOWN_INTERRUPT;
if (!i2c_dev->irq_disabled) {
disable_irq_nosync(i2c_dev->irq);
i2c_dev->irq_disabled = 1;
}
goto err;
}
if (unlikely(status & status_err)) {
if (status & I2C_INT_NO_ACK)
i2c_dev->msg_err |= I2C_ERR_NO_ACK;
if (status & I2C_INT_ARBITRATION_LOST)
i2c_dev->msg_err |= I2C_ERR_ARBITRATION_LOST;
goto err;
}
if (i2c_dev->msg_read && (status & I2C_INT_RX_FIFO_DATA_REQ)) {
if (i2c_dev->msg_buf_remaining)
tegra_i2c_empty_rx_fifo(i2c_dev);
else
BUG();
}
if (!i2c_dev->msg_read && (status & I2C_INT_TX_FIFO_DATA_REQ)) {
if (i2c_dev->msg_buf_remaining)
tegra_i2c_fill_tx_fifo(i2c_dev);
else
tegra_i2c_mask_irq(i2c_dev, I2C_INT_TX_FIFO_DATA_REQ);
}
i2c_writel(i2c_dev, status, I2C_INT_STATUS);
if (i2c_dev->is_dvc)
dvc_writel(i2c_dev, DVC_STATUS_I2C_DONE_INTR, DVC_STATUS);
if (status & I2C_INT_PACKET_XFER_COMPLETE) {
BUG_ON(i2c_dev->msg_buf_remaining);
complete(&i2c_dev->msg_complete);
}
return IRQ_HANDLED;
err:
tegra_i2c_mask_irq(i2c_dev, I2C_INT_NO_ACK | I2C_INT_ARBITRATION_LOST |
I2C_INT_PACKET_XFER_COMPLETE | I2C_INT_TX_FIFO_DATA_REQ |
I2C_INT_RX_FIFO_DATA_REQ);
i2c_writel(i2c_dev, status, I2C_INT_STATUS);
if (i2c_dev->is_dvc)
dvc_writel(i2c_dev, DVC_STATUS_I2C_DONE_INTR, DVC_STATUS);
complete(&i2c_dev->msg_complete);
return IRQ_HANDLED;
}
static int tegra_i2c_xfer_msg(struct tegra_i2c_dev *i2c_dev,
struct i2c_msg *msg, enum msg_end_type end_state)
{
u32 packet_header;
u32 int_mask;
int ret;
tegra_i2c_flush_fifos(i2c_dev);
if (msg->len == 0)
return -EINVAL;
i2c_dev->msg_buf = msg->buf;
i2c_dev->msg_buf_remaining = msg->len;
i2c_dev->msg_err = I2C_ERR_NONE;
i2c_dev->msg_read = (msg->flags & I2C_M_RD);
INIT_COMPLETION(i2c_dev->msg_complete);
packet_header = (0 << PACKET_HEADER0_HEADER_SIZE_SHIFT) |
PACKET_HEADER0_PROTOCOL_I2C |
(i2c_dev->cont_id << PACKET_HEADER0_CONT_ID_SHIFT) |
(1 << PACKET_HEADER0_PACKET_ID_SHIFT);
i2c_writel(i2c_dev, packet_header, I2C_TX_FIFO);
packet_header = msg->len - 1;
i2c_writel(i2c_dev, packet_header, I2C_TX_FIFO);
packet_header = I2C_HEADER_IE_ENABLE;
if (end_state == MSG_END_CONTINUE)
packet_header |= I2C_HEADER_CONTINUE_XFER;
else if (end_state == MSG_END_REPEAT_START)
packet_header |= I2C_HEADER_REPEAT_START;
if (msg->flags & I2C_M_TEN) {
packet_header |= msg->addr;
packet_header |= I2C_HEADER_10BIT_ADDR;
} else {
packet_header |= msg->addr << I2C_HEADER_SLAVE_ADDR_SHIFT;
}
if (msg->flags & I2C_M_IGNORE_NAK)
packet_header |= I2C_HEADER_CONT_ON_NAK;
if (msg->flags & I2C_M_RD)
packet_header |= I2C_HEADER_READ;
i2c_writel(i2c_dev, packet_header, I2C_TX_FIFO);
if (!(msg->flags & I2C_M_RD))
tegra_i2c_fill_tx_fifo(i2c_dev);
int_mask = I2C_INT_NO_ACK | I2C_INT_ARBITRATION_LOST;
if (msg->flags & I2C_M_RD)
int_mask |= I2C_INT_RX_FIFO_DATA_REQ;
else if (i2c_dev->msg_buf_remaining)
int_mask |= I2C_INT_TX_FIFO_DATA_REQ;
tegra_i2c_unmask_irq(i2c_dev, int_mask);
dev_dbg(i2c_dev->dev, "unmasked irq: %02x\n",
i2c_readl(i2c_dev, I2C_INT_MASK));
ret = wait_for_completion_timeout(&i2c_dev->msg_complete, TEGRA_I2C_TIMEOUT);
tegra_i2c_mask_irq(i2c_dev, int_mask);
if (WARN_ON(ret == 0)) {
dev_err(i2c_dev->dev, "i2c transfer timed out\n");
tegra_i2c_init(i2c_dev);
return -ETIMEDOUT;
}
dev_dbg(i2c_dev->dev, "transfer complete: %d %d %d\n",
ret, completion_done(&i2c_dev->msg_complete), i2c_dev->msg_err);
if (likely(i2c_dev->msg_err == I2C_ERR_NONE))
return 0;
if (i2c_dev->msg_err == I2C_ERR_NO_ACK)
udelay(DIV_ROUND_UP(2 * 1000000, i2c_dev->bus_clk_rate));
tegra_i2c_init(i2c_dev);
if (i2c_dev->msg_err == I2C_ERR_NO_ACK) {
if (msg->flags & I2C_M_IGNORE_NAK)
return 0;
return -EREMOTEIO;
}
return -EIO;
}
static int tegra_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msgs[],
int num)
{
struct tegra_i2c_dev *i2c_dev = i2c_get_adapdata(adap);
int i;
int ret = 0;
if (i2c_dev->is_suspended)
return -EBUSY;
tegra_i2c_clock_enable(i2c_dev);
for (i = 0; i < num; i++) {
enum msg_end_type end_type = MSG_END_STOP;
if (i < (num - 1)) {
if (msgs[i + 1].flags & I2C_M_NOSTART)
end_type = MSG_END_CONTINUE;
else
end_type = MSG_END_REPEAT_START;
}
ret = tegra_i2c_xfer_msg(i2c_dev, &msgs[i], end_type);
if (ret)
break;
}
tegra_i2c_clock_disable(i2c_dev);
return ret ?: i;
}
static u32 tegra_i2c_func(struct i2c_adapter *adap)
{
struct tegra_i2c_dev *i2c_dev = i2c_get_adapdata(adap);
u32 ret = I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL | I2C_FUNC_10BIT_ADDR |
I2C_FUNC_PROTOCOL_MANGLING;
if (i2c_dev->hw->has_continue_xfer_support)
ret |= I2C_FUNC_NOSTART;
return ret;
}
static int tegra_i2c_probe(struct platform_device *pdev)
{
struct tegra_i2c_dev *i2c_dev;
struct tegra_i2c_platform_data *pdata = pdev->dev.platform_data;
struct resource *res;
struct clk *div_clk;
struct clk *fast_clk;
const unsigned int *prop;
void __iomem *base;
int irq;
int ret = 0;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "no mem resource\n");
return -EINVAL;
}
base = devm_request_and_ioremap(&pdev->dev, res);
if (!base) {
dev_err(&pdev->dev, "Cannot request/ioremap I2C registers\n");
return -EADDRNOTAVAIL;
}
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
dev_err(&pdev->dev, "no irq resource\n");
return -EINVAL;
}
irq = res->start;
div_clk = devm_clk_get(&pdev->dev, "div-clk");
if (IS_ERR(div_clk)) {
dev_err(&pdev->dev, "missing controller clock");
return PTR_ERR(div_clk);
}
fast_clk = devm_clk_get(&pdev->dev, "fast-clk");
if (IS_ERR(fast_clk)) {
dev_err(&pdev->dev, "missing bus clock");
return PTR_ERR(fast_clk);
}
i2c_dev = devm_kzalloc(&pdev->dev, sizeof(*i2c_dev), GFP_KERNEL);
if (!i2c_dev) {
dev_err(&pdev->dev, "Could not allocate struct tegra_i2c_dev");
return -ENOMEM;
}
i2c_dev->base = base;
i2c_dev->div_clk = div_clk;
i2c_dev->fast_clk = fast_clk;
i2c_dev->adapter.algo = &tegra_i2c_algo;
i2c_dev->irq = irq;
i2c_dev->cont_id = pdev->id;
i2c_dev->dev = &pdev->dev;
i2c_dev->bus_clk_rate = 100000;
if (pdata) {
i2c_dev->bus_clk_rate = pdata->bus_clk_rate;
} else if (i2c_dev->dev->of_node) {
prop = of_get_property(i2c_dev->dev->of_node,
"clock-frequency", NULL);
if (prop)
i2c_dev->bus_clk_rate = be32_to_cpup(prop);
}
i2c_dev->hw = &tegra20_i2c_hw;
if (pdev->dev.of_node) {
const struct of_device_id *match;
match = of_match_device(of_match_ptr(tegra_i2c_of_match),
&pdev->dev);
i2c_dev->hw = match->data;
i2c_dev->is_dvc = of_device_is_compatible(pdev->dev.of_node,
"nvidia,tegra20-i2c-dvc");
} else if (pdev->id == 3) {
i2c_dev->is_dvc = 1;
}
init_completion(&i2c_dev->msg_complete);
platform_set_drvdata(pdev, i2c_dev);
ret = tegra_i2c_init(i2c_dev);
if (ret) {
dev_err(&pdev->dev, "Failed to initialize i2c controller");
return ret;
}
ret = devm_request_irq(&pdev->dev, i2c_dev->irq,
tegra_i2c_isr, 0, dev_name(&pdev->dev), i2c_dev);
if (ret) {
dev_err(&pdev->dev, "Failed to request irq %i\n", i2c_dev->irq);
return ret;
}
i2c_set_adapdata(&i2c_dev->adapter, i2c_dev);
i2c_dev->adapter.owner = THIS_MODULE;
i2c_dev->adapter.class = I2C_CLASS_HWMON;
strlcpy(i2c_dev->adapter.name, "Tegra I2C adapter",
sizeof(i2c_dev->adapter.name));
i2c_dev->adapter.algo = &tegra_i2c_algo;
i2c_dev->adapter.dev.parent = &pdev->dev;
i2c_dev->adapter.nr = pdev->id;
i2c_dev->adapter.dev.of_node = pdev->dev.of_node;
ret = i2c_add_numbered_adapter(&i2c_dev->adapter);
if (ret) {
dev_err(&pdev->dev, "Failed to add I2C adapter\n");
return ret;
}
of_i2c_register_devices(&i2c_dev->adapter);
return 0;
}
static int tegra_i2c_remove(struct platform_device *pdev)
{
struct tegra_i2c_dev *i2c_dev = platform_get_drvdata(pdev);
i2c_del_adapter(&i2c_dev->adapter);
return 0;
}
static int tegra_i2c_suspend(struct device *dev)
{
struct tegra_i2c_dev *i2c_dev = dev_get_drvdata(dev);
i2c_lock_adapter(&i2c_dev->adapter);
i2c_dev->is_suspended = true;
i2c_unlock_adapter(&i2c_dev->adapter);
return 0;
}
static int tegra_i2c_resume(struct device *dev)
{
struct tegra_i2c_dev *i2c_dev = dev_get_drvdata(dev);
int ret;
i2c_lock_adapter(&i2c_dev->adapter);
ret = tegra_i2c_init(i2c_dev);
if (ret) {
i2c_unlock_adapter(&i2c_dev->adapter);
return ret;
}
i2c_dev->is_suspended = false;
i2c_unlock_adapter(&i2c_dev->adapter);
return 0;
}
static int __init tegra_i2c_init_driver(void)
{
return platform_driver_register(&tegra_i2c_driver);
}
static void __exit tegra_i2c_exit_driver(void)
{
platform_driver_unregister(&tegra_i2c_driver);
}
