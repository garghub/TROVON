static inline int meson_ao_cec_wait_busy(struct meson_ao_cec_device *ao_cec)
{
ktime_t timeout = ktime_add_us(ktime_get(), 5000);
while (readl_relaxed(ao_cec->base + CEC_RW_REG) & CEC_RW_BUS_BUSY) {
if (ktime_compare(ktime_get(), timeout) > 0)
return -ETIMEDOUT;
}
return 0;
}
static void meson_ao_cec_read(struct meson_ao_cec_device *ao_cec,
unsigned long address, u8 *data,
int *res)
{
unsigned long flags;
u32 reg = FIELD_PREP(CEC_RW_ADDR, address);
int ret = 0;
if (res && *res)
return;
spin_lock_irqsave(&ao_cec->cec_reg_lock, flags);
ret = meson_ao_cec_wait_busy(ao_cec);
if (ret)
goto read_out;
writel_relaxed(reg, ao_cec->base + CEC_RW_REG);
ret = meson_ao_cec_wait_busy(ao_cec);
if (ret)
goto read_out;
*data = FIELD_GET(CEC_RW_RD_DATA,
readl_relaxed(ao_cec->base + CEC_RW_REG));
read_out:
spin_unlock_irqrestore(&ao_cec->cec_reg_lock, flags);
if (res)
*res = ret;
}
static void meson_ao_cec_write(struct meson_ao_cec_device *ao_cec,
unsigned long address, u8 data,
int *res)
{
unsigned long flags;
u32 reg = FIELD_PREP(CEC_RW_ADDR, address) |
FIELD_PREP(CEC_RW_WR_DATA, data) |
CEC_RW_WRITE_EN;
int ret = 0;
if (res && *res)
return;
spin_lock_irqsave(&ao_cec->cec_reg_lock, flags);
ret = meson_ao_cec_wait_busy(ao_cec);
if (ret)
goto write_out;
writel_relaxed(reg, ao_cec->base + CEC_RW_REG);
write_out:
spin_unlock_irqrestore(&ao_cec->cec_reg_lock, flags);
if (res)
*res = ret;
}
static inline void meson_ao_cec_irq_setup(struct meson_ao_cec_device *ao_cec,
bool enable)
{
u32 cfg = CEC_INTR_TX | CEC_INTR_RX;
writel_bits_relaxed(cfg, enable ? cfg : 0,
ao_cec->base + CEC_INTR_MASKN_REG);
}
static inline int meson_ao_cec_clear(struct meson_ao_cec_device *ao_cec)
{
int ret = 0;
meson_ao_cec_write(ao_cec, CEC_RX_MSG_CMD, RX_DISABLE, &ret);
meson_ao_cec_write(ao_cec, CEC_TX_MSG_CMD, TX_ABORT, &ret);
meson_ao_cec_write(ao_cec, CEC_RX_CLEAR_BUF, 1, &ret);
meson_ao_cec_write(ao_cec, CEC_TX_CLEAR_BUF, 1, &ret);
if (ret)
return ret;
udelay(100);
meson_ao_cec_write(ao_cec, CEC_RX_CLEAR_BUF, 0, &ret);
meson_ao_cec_write(ao_cec, CEC_TX_CLEAR_BUF, 0, &ret);
if (ret)
return ret;
udelay(100);
meson_ao_cec_write(ao_cec, CEC_RX_MSG_CMD, RX_NO_OP, &ret);
meson_ao_cec_write(ao_cec, CEC_TX_MSG_CMD, TX_NO_OP, &ret);
return ret;
}
static int meson_ao_cec_arbit_bit_time_set(struct meson_ao_cec_device *ao_cec,
unsigned int bit_set,
unsigned int time_set)
{
int ret = 0;
switch (bit_set) {
case CEC_SIGNAL_FREE_TIME_RETRY:
meson_ao_cec_write(ao_cec, CEC_TXTIME_4BIT_BIT7_0,
time_set & 0xff, &ret);
meson_ao_cec_write(ao_cec, CEC_TXTIME_4BIT_BIT10_8,
(time_set >> 8) & 0x7, &ret);
break;
case CEC_SIGNAL_FREE_TIME_NEW_INITIATOR:
meson_ao_cec_write(ao_cec, CEC_TXTIME_2BIT_BIT7_0,
time_set & 0xff, &ret);
meson_ao_cec_write(ao_cec, CEC_TXTIME_2BIT_BIT10_8,
(time_set >> 8) & 0x7, &ret);
break;
case CEC_SIGNAL_FREE_TIME_NEXT_XFER:
meson_ao_cec_write(ao_cec, CEC_TXTIME_17MS_BIT7_0,
time_set & 0xff, &ret);
meson_ao_cec_write(ao_cec, CEC_TXTIME_17MS_BIT10_8,
(time_set >> 8) & 0x7, &ret);
break;
}
return ret;
}
static irqreturn_t meson_ao_cec_irq(int irq, void *data)
{
struct meson_ao_cec_device *ao_cec = data;
u32 stat = readl_relaxed(ao_cec->base + CEC_INTR_STAT_REG);
if (stat)
return IRQ_WAKE_THREAD;
return IRQ_NONE;
}
static void meson_ao_cec_irq_tx(struct meson_ao_cec_device *ao_cec)
{
unsigned long tx_status = 0;
u8 stat;
int ret = 0;
meson_ao_cec_read(ao_cec, CEC_TX_MSG_STATUS, &stat, &ret);
if (ret)
goto tx_reg_err;
switch (stat) {
case TX_DONE:
tx_status = CEC_TX_STATUS_OK;
break;
case TX_BUSY:
tx_status = CEC_TX_STATUS_ARB_LOST;
break;
case TX_IDLE:
tx_status = CEC_TX_STATUS_LOW_DRIVE;
break;
case TX_ERROR:
default:
tx_status = CEC_TX_STATUS_NACK;
break;
}
writel_relaxed(CEC_INTR_TX, ao_cec->base + CEC_INTR_CLR_REG);
meson_ao_cec_write(ao_cec, CEC_TX_MSG_CMD, TX_NO_OP, &ret);
if (ret)
goto tx_reg_err;
cec_transmit_attempt_done(ao_cec->adap, tx_status);
return;
tx_reg_err:
cec_transmit_attempt_done(ao_cec->adap, CEC_TX_STATUS_ERROR);
}
static void meson_ao_cec_irq_rx(struct meson_ao_cec_device *ao_cec)
{
int i, ret = 0;
u8 reg;
meson_ao_cec_read(ao_cec, CEC_RX_MSG_STATUS, &reg, &ret);
if (reg != RX_DONE)
goto rx_out;
meson_ao_cec_read(ao_cec, CEC_RX_NUM_MSG, &reg, &ret);
if (reg != 1)
goto rx_out;
meson_ao_cec_read(ao_cec, CEC_RX_MSG_LENGTH, &reg, &ret);
ao_cec->rx_msg.len = reg + 1;
if (ao_cec->rx_msg.len > CEC_MAX_MSG_SIZE)
ao_cec->rx_msg.len = CEC_MAX_MSG_SIZE;
for (i = 0; i < ao_cec->rx_msg.len; i++) {
u8 byte;
meson_ao_cec_read(ao_cec, CEC_RX_MSG_0_HEADER + i, &byte, &ret);
ao_cec->rx_msg.msg[i] = byte;
}
if (ret)
goto rx_out;
cec_received_msg(ao_cec->adap, &ao_cec->rx_msg);
rx_out:
writel_relaxed(CEC_INTR_RX, ao_cec->base + CEC_INTR_CLR_REG);
meson_ao_cec_write(ao_cec, CEC_RX_MSG_CMD, RX_ACK_CURRENT, &ret);
meson_ao_cec_write(ao_cec, CEC_RX_MSG_CMD, RX_NO_OP, &ret);
meson_ao_cec_write(ao_cec, CEC_RX_CLEAR_BUF, CLEAR_START, &ret);
meson_ao_cec_write(ao_cec, CEC_RX_CLEAR_BUF, CLEAR_STOP, &ret);
}
static irqreturn_t meson_ao_cec_irq_thread(int irq, void *data)
{
struct meson_ao_cec_device *ao_cec = data;
u32 stat = readl_relaxed(ao_cec->base + CEC_INTR_STAT_REG);
if (stat & CEC_INTR_TX)
meson_ao_cec_irq_tx(ao_cec);
meson_ao_cec_irq_rx(ao_cec);
return IRQ_HANDLED;
}
static int meson_ao_cec_set_log_addr(struct cec_adapter *adap, u8 logical_addr)
{
struct meson_ao_cec_device *ao_cec = adap->priv;
int ret = 0;
meson_ao_cec_write(ao_cec, CEC_LOGICAL_ADDR0,
LOGICAL_ADDR_DISABLE, &ret);
if (ret)
return ret;
ret = meson_ao_cec_clear(ao_cec);
if (ret)
return ret;
if (logical_addr == CEC_LOG_ADDR_INVALID)
return 0;
meson_ao_cec_write(ao_cec, CEC_LOGICAL_ADDR0,
logical_addr & LOGICAL_ADDR_MASK, &ret);
if (ret)
return ret;
udelay(100);
meson_ao_cec_write(ao_cec, CEC_LOGICAL_ADDR0,
(logical_addr & LOGICAL_ADDR_MASK) |
LOGICAL_ADDR_VALID, &ret);
return ret;
}
static int meson_ao_cec_transmit(struct cec_adapter *adap, u8 attempts,
u32 signal_free_time, struct cec_msg *msg)
{
struct meson_ao_cec_device *ao_cec = adap->priv;
int i, ret = 0;
u8 reg;
meson_ao_cec_read(ao_cec, CEC_TX_MSG_STATUS, &reg, &ret);
if (ret)
return ret;
if (reg == TX_BUSY) {
dev_err(&ao_cec->pdev->dev, "%s: busy TX: aborting\n",
__func__);
meson_ao_cec_write(ao_cec, CEC_TX_MSG_CMD, TX_ABORT, &ret);
}
for (i = 0; i < msg->len; i++) {
meson_ao_cec_write(ao_cec, CEC_TX_MSG_0_HEADER + i,
msg->msg[i], &ret);
}
meson_ao_cec_write(ao_cec, CEC_TX_MSG_LENGTH, msg->len - 1, &ret);
meson_ao_cec_write(ao_cec, CEC_TX_MSG_CMD, TX_REQ_CURRENT, &ret);
return ret;
}
static int meson_ao_cec_adap_enable(struct cec_adapter *adap, bool enable)
{
struct meson_ao_cec_device *ao_cec = adap->priv;
int ret;
meson_ao_cec_irq_setup(ao_cec, false);
writel_bits_relaxed(CEC_GEN_CNTL_RESET, CEC_GEN_CNTL_RESET,
ao_cec->base + CEC_GEN_CNTL_REG);
if (!enable)
return 0;
writel_bits_relaxed(CEC_GEN_CNTL_CLK_CTRL_MASK,
FIELD_PREP(CEC_GEN_CNTL_CLK_CTRL_MASK,
CEC_GEN_CNTL_CLK_ENABLE),
ao_cec->base + CEC_GEN_CNTL_REG);
udelay(100);
writel_bits_relaxed(CEC_GEN_CNTL_RESET, 0,
ao_cec->base + CEC_GEN_CNTL_REG);
ret = meson_ao_cec_clear(ao_cec);
if (ret)
return ret;
ret = meson_ao_cec_arbit_bit_time_set(ao_cec,
CEC_SIGNAL_FREE_TIME_RETRY,
0x118);
if (ret)
return ret;
ret = meson_ao_cec_arbit_bit_time_set(ao_cec,
CEC_SIGNAL_FREE_TIME_NEW_INITIATOR,
0x000);
if (ret)
return ret;
ret = meson_ao_cec_arbit_bit_time_set(ao_cec,
CEC_SIGNAL_FREE_TIME_NEXT_XFER,
0x2aa);
if (ret)
return ret;
meson_ao_cec_irq_setup(ao_cec, true);
return 0;
}
static int meson_ao_cec_probe(struct platform_device *pdev)
{
struct meson_ao_cec_device *ao_cec;
struct platform_device *hdmi_dev;
struct device_node *np;
struct resource *res;
int ret, irq;
np = of_parse_phandle(pdev->dev.of_node, "hdmi-phandle", 0);
if (!np) {
dev_err(&pdev->dev, "Failed to find hdmi node\n");
return -ENODEV;
}
hdmi_dev = of_find_device_by_node(np);
if (hdmi_dev == NULL)
return -EPROBE_DEFER;
ao_cec = devm_kzalloc(&pdev->dev, sizeof(*ao_cec), GFP_KERNEL);
if (!ao_cec)
return -ENOMEM;
spin_lock_init(&ao_cec->cec_reg_lock);
ao_cec->notify = cec_notifier_get(&hdmi_dev->dev);
if (!ao_cec->notify)
return -ENOMEM;
ao_cec->adap = cec_allocate_adapter(&meson_ao_cec_ops, ao_cec,
"meson_ao_cec",
CEC_CAP_LOG_ADDRS |
CEC_CAP_TRANSMIT |
CEC_CAP_RC |
CEC_CAP_PASSTHROUGH,
1);
if (IS_ERR(ao_cec->adap)) {
ret = PTR_ERR(ao_cec->adap);
goto out_probe_notify;
}
ao_cec->adap->owner = THIS_MODULE;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ao_cec->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ao_cec->base)) {
ret = PTR_ERR(ao_cec->base);
goto out_probe_adapter;
}
irq = platform_get_irq(pdev, 0);
ret = devm_request_threaded_irq(&pdev->dev, irq,
meson_ao_cec_irq,
meson_ao_cec_irq_thread,
0, NULL, ao_cec);
if (ret) {
dev_err(&pdev->dev, "irq request failed\n");
goto out_probe_adapter;
}
ao_cec->core = devm_clk_get(&pdev->dev, "core");
if (IS_ERR(ao_cec->core)) {
dev_err(&pdev->dev, "core clock request failed\n");
ret = PTR_ERR(ao_cec->core);
goto out_probe_adapter;
}
ret = clk_prepare_enable(ao_cec->core);
if (ret) {
dev_err(&pdev->dev, "core clock enable failed\n");
goto out_probe_adapter;
}
ret = clk_set_rate(ao_cec->core, CEC_CLK_RATE);
if (ret) {
dev_err(&pdev->dev, "core clock set rate failed\n");
goto out_probe_clk;
}
device_reset_optional(&pdev->dev);
ao_cec->pdev = pdev;
platform_set_drvdata(pdev, ao_cec);
ret = cec_register_adapter(ao_cec->adap, &pdev->dev);
if (ret < 0) {
cec_notifier_put(ao_cec->notify);
goto out_probe_clk;
}
writel_relaxed(CEC_GEN_CNTL_RESET,
ao_cec->base + CEC_GEN_CNTL_REG);
cec_register_cec_notifier(ao_cec->adap, ao_cec->notify);
return 0;
out_probe_clk:
clk_disable_unprepare(ao_cec->core);
out_probe_adapter:
cec_delete_adapter(ao_cec->adap);
out_probe_notify:
cec_notifier_put(ao_cec->notify);
dev_err(&pdev->dev, "CEC controller registration failed\n");
return ret;
}
static int meson_ao_cec_remove(struct platform_device *pdev)
{
struct meson_ao_cec_device *ao_cec = platform_get_drvdata(pdev);
clk_disable_unprepare(ao_cec->core);
cec_unregister_adapter(ao_cec->adap);
cec_notifier_put(ao_cec->notify);
return 0;
}
