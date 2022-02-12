u32 dw_readl(struct dw_i2c_dev *dev, int offset)
{
u32 value;
if (dev->accessor_flags & ACCESS_16BIT)
value = readw(dev->base + offset) |
(readw(dev->base + offset + 2) << 16);
else
value = readl(dev->base + offset);
if (dev->accessor_flags & ACCESS_SWAP)
return swab32(value);
else
return value;
}
void dw_writel(struct dw_i2c_dev *dev, u32 b, int offset)
{
if (dev->accessor_flags & ACCESS_SWAP)
b = swab32(b);
if (dev->accessor_flags & ACCESS_16BIT) {
writew((u16)b, dev->base + offset);
writew((u16)(b >> 16), dev->base + offset + 2);
} else {
writel(b, dev->base + offset);
}
}
static u32
i2c_dw_scl_hcnt(u32 ic_clk, u32 tSYMBOL, u32 tf, int cond, int offset)
{
if (cond)
return (ic_clk * tSYMBOL + 500000) / 1000000 - 8 + offset;
else
return (ic_clk * (tSYMBOL + tf) + 500000) / 1000000
- 3 + offset;
}
static u32 i2c_dw_scl_lcnt(u32 ic_clk, u32 tLOW, u32 tf, int offset)
{
return ((ic_clk * (tLOW + tf) + 500000) / 1000000) - 1 + offset;
}
static void __i2c_dw_enable(struct dw_i2c_dev *dev, bool enable)
{
int timeout = 100;
do {
dw_writel(dev, enable, DW_IC_ENABLE);
if ((dw_readl(dev, DW_IC_ENABLE_STATUS) & 1) == enable)
return;
usleep_range(25, 250);
} while (timeout--);
dev_warn(dev->dev, "timeout in %sabling adapter\n",
enable ? "en" : "dis");
}
int i2c_dw_init(struct dw_i2c_dev *dev)
{
u32 input_clock_khz;
u32 hcnt, lcnt;
u32 reg;
u32 sda_falling_time, scl_falling_time;
input_clock_khz = dev->get_clk_rate_khz(dev);
reg = dw_readl(dev, DW_IC_COMP_TYPE);
if (reg == ___constant_swab32(DW_IC_COMP_TYPE_VALUE)) {
dev->accessor_flags |= ACCESS_SWAP;
} else if (reg == (DW_IC_COMP_TYPE_VALUE & 0x0000ffff)) {
dev->accessor_flags |= ACCESS_16BIT;
} else if (reg != DW_IC_COMP_TYPE_VALUE) {
dev_err(dev->dev, "Unknown Synopsys component type: "
"0x%08x\n", reg);
return -ENODEV;
}
__i2c_dw_enable(dev, false);
sda_falling_time = dev->sda_falling_time ?: 300;
scl_falling_time = dev->scl_falling_time ?: 300;
hcnt = i2c_dw_scl_hcnt(input_clock_khz,
4000,
sda_falling_time,
0,
0);
lcnt = i2c_dw_scl_lcnt(input_clock_khz,
4700,
scl_falling_time,
0);
if (dev->ss_hcnt && dev->ss_lcnt) {
hcnt = dev->ss_hcnt;
lcnt = dev->ss_lcnt;
}
dw_writel(dev, hcnt, DW_IC_SS_SCL_HCNT);
dw_writel(dev, lcnt, DW_IC_SS_SCL_LCNT);
dev_dbg(dev->dev, "Standard-mode HCNT:LCNT = %d:%d\n", hcnt, lcnt);
hcnt = i2c_dw_scl_hcnt(input_clock_khz,
600,
sda_falling_time,
0,
0);
lcnt = i2c_dw_scl_lcnt(input_clock_khz,
1300,
scl_falling_time,
0);
if (dev->fs_hcnt && dev->fs_lcnt) {
hcnt = dev->fs_hcnt;
lcnt = dev->fs_lcnt;
}
dw_writel(dev, hcnt, DW_IC_FS_SCL_HCNT);
dw_writel(dev, lcnt, DW_IC_FS_SCL_LCNT);
dev_dbg(dev->dev, "Fast-mode HCNT:LCNT = %d:%d\n", hcnt, lcnt);
if (dev->sda_hold_time) {
reg = dw_readl(dev, DW_IC_COMP_VERSION);
if (reg >= DW_IC_SDA_HOLD_MIN_VERS)
dw_writel(dev, dev->sda_hold_time, DW_IC_SDA_HOLD);
else
dev_warn(dev->dev,
"Hardware too old to adjust SDA hold time.");
}
dw_writel(dev, dev->tx_fifo_depth - 1, DW_IC_TX_TL);
dw_writel(dev, 0, DW_IC_RX_TL);
dw_writel(dev, dev->master_cfg , DW_IC_CON);
return 0;
}
static int i2c_dw_wait_bus_not_busy(struct dw_i2c_dev *dev)
{
int timeout = TIMEOUT;
while (dw_readl(dev, DW_IC_STATUS) & DW_IC_STATUS_ACTIVITY) {
if (timeout <= 0) {
dev_warn(dev->dev, "timeout waiting for bus ready\n");
return -ETIMEDOUT;
}
timeout--;
usleep_range(1000, 1100);
}
return 0;
}
static void i2c_dw_xfer_init(struct dw_i2c_dev *dev)
{
struct i2c_msg *msgs = dev->msgs;
u32 ic_con, ic_tar = 0;
__i2c_dw_enable(dev, false);
ic_con = dw_readl(dev, DW_IC_CON);
if (msgs[dev->msg_write_idx].flags & I2C_M_TEN) {
ic_con |= DW_IC_CON_10BITADDR_MASTER;
ic_tar = DW_IC_TAR_10BITADDR_MASTER;
} else {
ic_con &= ~DW_IC_CON_10BITADDR_MASTER;
}
dw_writel(dev, ic_con, DW_IC_CON);
dw_writel(dev, msgs[dev->msg_write_idx].addr | ic_tar, DW_IC_TAR);
i2c_dw_disable_int(dev);
__i2c_dw_enable(dev, true);
i2c_dw_clear_int(dev);
dw_writel(dev, DW_IC_INTR_DEFAULT_MASK, DW_IC_INTR_MASK);
}
static void
i2c_dw_xfer_msg(struct dw_i2c_dev *dev)
{
struct i2c_msg *msgs = dev->msgs;
u32 intr_mask;
int tx_limit, rx_limit;
u32 addr = msgs[dev->msg_write_idx].addr;
u32 buf_len = dev->tx_buf_len;
u8 *buf = dev->tx_buf;
bool need_restart = false;
intr_mask = DW_IC_INTR_DEFAULT_MASK;
for (; dev->msg_write_idx < dev->msgs_num; dev->msg_write_idx++) {
if (msgs[dev->msg_write_idx].addr != addr) {
dev_err(dev->dev,
"%s: invalid target address\n", __func__);
dev->msg_err = -EINVAL;
break;
}
if (msgs[dev->msg_write_idx].len == 0) {
dev_err(dev->dev,
"%s: invalid message length\n", __func__);
dev->msg_err = -EINVAL;
break;
}
if (!(dev->status & STATUS_WRITE_IN_PROGRESS)) {
buf = msgs[dev->msg_write_idx].buf;
buf_len = msgs[dev->msg_write_idx].len;
if ((dev->master_cfg & DW_IC_CON_RESTART_EN) &&
(dev->msg_write_idx > 0))
need_restart = true;
}
tx_limit = dev->tx_fifo_depth - dw_readl(dev, DW_IC_TXFLR);
rx_limit = dev->rx_fifo_depth - dw_readl(dev, DW_IC_RXFLR);
while (buf_len > 0 && tx_limit > 0 && rx_limit > 0) {
u32 cmd = 0;
if (dev->msg_write_idx == dev->msgs_num - 1 &&
buf_len == 1)
cmd |= BIT(9);
if (need_restart) {
cmd |= BIT(10);
need_restart = false;
}
if (msgs[dev->msg_write_idx].flags & I2C_M_RD) {
if (rx_limit - dev->rx_outstanding <= 0)
break;
dw_writel(dev, cmd | 0x100, DW_IC_DATA_CMD);
rx_limit--;
dev->rx_outstanding++;
} else
dw_writel(dev, cmd | *buf++, DW_IC_DATA_CMD);
tx_limit--; buf_len--;
}
dev->tx_buf = buf;
dev->tx_buf_len = buf_len;
if (buf_len > 0) {
dev->status |= STATUS_WRITE_IN_PROGRESS;
break;
} else
dev->status &= ~STATUS_WRITE_IN_PROGRESS;
}
if (dev->msg_write_idx == dev->msgs_num)
intr_mask &= ~DW_IC_INTR_TX_EMPTY;
if (dev->msg_err)
intr_mask = 0;
dw_writel(dev, intr_mask, DW_IC_INTR_MASK);
}
static void
i2c_dw_read(struct dw_i2c_dev *dev)
{
struct i2c_msg *msgs = dev->msgs;
int rx_valid;
for (; dev->msg_read_idx < dev->msgs_num; dev->msg_read_idx++) {
u32 len;
u8 *buf;
if (!(msgs[dev->msg_read_idx].flags & I2C_M_RD))
continue;
if (!(dev->status & STATUS_READ_IN_PROGRESS)) {
len = msgs[dev->msg_read_idx].len;
buf = msgs[dev->msg_read_idx].buf;
} else {
len = dev->rx_buf_len;
buf = dev->rx_buf;
}
rx_valid = dw_readl(dev, DW_IC_RXFLR);
for (; len > 0 && rx_valid > 0; len--, rx_valid--) {
*buf++ = dw_readl(dev, DW_IC_DATA_CMD);
dev->rx_outstanding--;
}
if (len > 0) {
dev->status |= STATUS_READ_IN_PROGRESS;
dev->rx_buf_len = len;
dev->rx_buf = buf;
return;
} else
dev->status &= ~STATUS_READ_IN_PROGRESS;
}
}
static int i2c_dw_handle_tx_abort(struct dw_i2c_dev *dev)
{
unsigned long abort_source = dev->abort_source;
int i;
if (abort_source & DW_IC_TX_ABRT_NOACK) {
for_each_set_bit(i, &abort_source, ARRAY_SIZE(abort_sources))
dev_dbg(dev->dev,
"%s: %s\n", __func__, abort_sources[i]);
return -EREMOTEIO;
}
for_each_set_bit(i, &abort_source, ARRAY_SIZE(abort_sources))
dev_err(dev->dev, "%s: %s\n", __func__, abort_sources[i]);
if (abort_source & DW_IC_TX_ARB_LOST)
return -EAGAIN;
else if (abort_source & DW_IC_TX_ABRT_GCALL_READ)
return -EINVAL;
else
return -EIO;
}
int
i2c_dw_xfer(struct i2c_adapter *adap, struct i2c_msg msgs[], int num)
{
struct dw_i2c_dev *dev = i2c_get_adapdata(adap);
int ret;
dev_dbg(dev->dev, "%s: msgs: %d\n", __func__, num);
mutex_lock(&dev->lock);
pm_runtime_get_sync(dev->dev);
reinit_completion(&dev->cmd_complete);
dev->msgs = msgs;
dev->msgs_num = num;
dev->cmd_err = 0;
dev->msg_write_idx = 0;
dev->msg_read_idx = 0;
dev->msg_err = 0;
dev->status = STATUS_IDLE;
dev->abort_source = 0;
dev->rx_outstanding = 0;
ret = i2c_dw_wait_bus_not_busy(dev);
if (ret < 0)
goto done;
i2c_dw_xfer_init(dev);
ret = wait_for_completion_timeout(&dev->cmd_complete, HZ);
if (ret == 0) {
dev_err(dev->dev, "controller timed out\n");
i2c_dw_init(dev);
ret = -ETIMEDOUT;
goto done;
}
__i2c_dw_enable(dev, false);
if (dev->msg_err) {
ret = dev->msg_err;
goto done;
}
if (likely(!dev->cmd_err)) {
ret = num;
goto done;
}
if (dev->cmd_err == DW_IC_ERR_TX_ABRT) {
ret = i2c_dw_handle_tx_abort(dev);
goto done;
}
ret = -EIO;
done:
pm_runtime_mark_last_busy(dev->dev);
pm_runtime_put_autosuspend(dev->dev);
mutex_unlock(&dev->lock);
return ret;
}
u32 i2c_dw_func(struct i2c_adapter *adap)
{
struct dw_i2c_dev *dev = i2c_get_adapdata(adap);
return dev->functionality;
}
static u32 i2c_dw_read_clear_intrbits(struct dw_i2c_dev *dev)
{
u32 stat;
stat = dw_readl(dev, DW_IC_INTR_STAT);
if (stat & DW_IC_INTR_RX_UNDER)
dw_readl(dev, DW_IC_CLR_RX_UNDER);
if (stat & DW_IC_INTR_RX_OVER)
dw_readl(dev, DW_IC_CLR_RX_OVER);
if (stat & DW_IC_INTR_TX_OVER)
dw_readl(dev, DW_IC_CLR_TX_OVER);
if (stat & DW_IC_INTR_RD_REQ)
dw_readl(dev, DW_IC_CLR_RD_REQ);
if (stat & DW_IC_INTR_TX_ABRT) {
dev->abort_source = dw_readl(dev, DW_IC_TX_ABRT_SOURCE);
dw_readl(dev, DW_IC_CLR_TX_ABRT);
}
if (stat & DW_IC_INTR_RX_DONE)
dw_readl(dev, DW_IC_CLR_RX_DONE);
if (stat & DW_IC_INTR_ACTIVITY)
dw_readl(dev, DW_IC_CLR_ACTIVITY);
if (stat & DW_IC_INTR_STOP_DET)
dw_readl(dev, DW_IC_CLR_STOP_DET);
if (stat & DW_IC_INTR_START_DET)
dw_readl(dev, DW_IC_CLR_START_DET);
if (stat & DW_IC_INTR_GEN_CALL)
dw_readl(dev, DW_IC_CLR_GEN_CALL);
return stat;
}
irqreturn_t i2c_dw_isr(int this_irq, void *dev_id)
{
struct dw_i2c_dev *dev = dev_id;
u32 stat, enabled;
enabled = dw_readl(dev, DW_IC_ENABLE);
stat = dw_readl(dev, DW_IC_RAW_INTR_STAT);
dev_dbg(dev->dev, "%s: %s enabled= 0x%x stat=0x%x\n", __func__,
dev->adapter.name, enabled, stat);
if (!enabled || !(stat & ~DW_IC_INTR_ACTIVITY))
return IRQ_NONE;
stat = i2c_dw_read_clear_intrbits(dev);
if (stat & DW_IC_INTR_TX_ABRT) {
dev->cmd_err |= DW_IC_ERR_TX_ABRT;
dev->status = STATUS_IDLE;
dw_writel(dev, 0, DW_IC_INTR_MASK);
goto tx_aborted;
}
if (stat & DW_IC_INTR_RX_FULL)
i2c_dw_read(dev);
if (stat & DW_IC_INTR_TX_EMPTY)
i2c_dw_xfer_msg(dev);
tx_aborted:
if ((stat & (DW_IC_INTR_TX_ABRT | DW_IC_INTR_STOP_DET)) || dev->msg_err)
complete(&dev->cmd_complete);
return IRQ_HANDLED;
}
void i2c_dw_enable(struct dw_i2c_dev *dev)
{
__i2c_dw_enable(dev, true);
}
u32 i2c_dw_is_enabled(struct dw_i2c_dev *dev)
{
return dw_readl(dev, DW_IC_ENABLE);
}
void i2c_dw_disable(struct dw_i2c_dev *dev)
{
__i2c_dw_enable(dev, false);
dw_writel(dev, 0, DW_IC_INTR_MASK);
dw_readl(dev, DW_IC_CLR_INTR);
}
void i2c_dw_clear_int(struct dw_i2c_dev *dev)
{
dw_readl(dev, DW_IC_CLR_INTR);
}
void i2c_dw_disable_int(struct dw_i2c_dev *dev)
{
dw_writel(dev, 0, DW_IC_INTR_MASK);
}
u32 i2c_dw_read_comp_param(struct dw_i2c_dev *dev)
{
return dw_readl(dev, DW_IC_COMP_PARAM_1);
}
