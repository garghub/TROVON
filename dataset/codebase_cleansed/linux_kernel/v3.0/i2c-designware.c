static u32
i2c_dw_scl_hcnt(u32 ic_clk, u32 tSYMBOL, u32 tf, int cond, int offset)
{
if (cond)
return (ic_clk * tSYMBOL + 5000) / 10000 - 8 + offset;
else
return (ic_clk * (tSYMBOL + tf) + 5000) / 10000 - 3 + offset;
}
static u32 i2c_dw_scl_lcnt(u32 ic_clk, u32 tLOW, u32 tf, int offset)
{
return ((ic_clk * (tLOW + tf) + 5000) / 10000) - 1 + offset;
}
static void i2c_dw_init(struct dw_i2c_dev *dev)
{
u32 input_clock_khz = clk_get_rate(dev->clk) / 1000;
u32 ic_con, hcnt, lcnt;
writel(0, dev->base + DW_IC_ENABLE);
hcnt = i2c_dw_scl_hcnt(input_clock_khz,
40,
3,
0,
0);
lcnt = i2c_dw_scl_lcnt(input_clock_khz,
47,
3,
0);
writel(hcnt, dev->base + DW_IC_SS_SCL_HCNT);
writel(lcnt, dev->base + DW_IC_SS_SCL_LCNT);
dev_dbg(dev->dev, "Standard-mode HCNT:LCNT = %d:%d\n", hcnt, lcnt);
hcnt = i2c_dw_scl_hcnt(input_clock_khz,
6,
3,
0,
0);
lcnt = i2c_dw_scl_lcnt(input_clock_khz,
13,
3,
0);
writel(hcnt, dev->base + DW_IC_FS_SCL_HCNT);
writel(lcnt, dev->base + DW_IC_FS_SCL_LCNT);
dev_dbg(dev->dev, "Fast-mode HCNT:LCNT = %d:%d\n", hcnt, lcnt);
writel(dev->tx_fifo_depth - 1, dev->base + DW_IC_TX_TL);
writel(0, dev->base + DW_IC_RX_TL);
ic_con = DW_IC_CON_MASTER | DW_IC_CON_SLAVE_DISABLE |
DW_IC_CON_RESTART_EN | DW_IC_CON_SPEED_FAST;
writel(ic_con, dev->base + DW_IC_CON);
}
static int i2c_dw_wait_bus_not_busy(struct dw_i2c_dev *dev)
{
int timeout = TIMEOUT;
while (readl(dev->base + DW_IC_STATUS) & DW_IC_STATUS_ACTIVITY) {
if (timeout <= 0) {
dev_warn(dev->dev, "timeout waiting for bus ready\n");
return -ETIMEDOUT;
}
timeout--;
mdelay(1);
}
return 0;
}
static void i2c_dw_xfer_init(struct dw_i2c_dev *dev)
{
struct i2c_msg *msgs = dev->msgs;
u32 ic_con;
writel(0, dev->base + DW_IC_ENABLE);
writel(msgs[dev->msg_write_idx].addr, dev->base + DW_IC_TAR);
ic_con = readl(dev->base + DW_IC_CON);
if (msgs[dev->msg_write_idx].flags & I2C_M_TEN)
ic_con |= DW_IC_CON_10BITADDR_MASTER;
else
ic_con &= ~DW_IC_CON_10BITADDR_MASTER;
writel(ic_con, dev->base + DW_IC_CON);
writel(1, dev->base + DW_IC_ENABLE);
writel(DW_IC_INTR_DEFAULT_MASK, dev->base + DW_IC_INTR_MASK);
}
static void
i2c_dw_xfer_msg(struct dw_i2c_dev *dev)
{
struct i2c_msg *msgs = dev->msgs;
u32 intr_mask;
int tx_limit, rx_limit;
u32 addr = msgs[dev->msg_write_idx].addr;
u32 buf_len = dev->tx_buf_len;
u8 *buf = dev->tx_buf;;
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
}
tx_limit = dev->tx_fifo_depth - readl(dev->base + DW_IC_TXFLR);
rx_limit = dev->rx_fifo_depth - readl(dev->base + DW_IC_RXFLR);
while (buf_len > 0 && tx_limit > 0 && rx_limit > 0) {
if (msgs[dev->msg_write_idx].flags & I2C_M_RD) {
writel(0x100, dev->base + DW_IC_DATA_CMD);
rx_limit--;
} else
writel(*buf++, dev->base + DW_IC_DATA_CMD);
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
writel(intr_mask, dev->base + DW_IC_INTR_MASK);
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
rx_valid = readl(dev->base + DW_IC_RXFLR);
for (; len > 0 && rx_valid > 0; len--, rx_valid--)
*buf++ = readl(dev->base + DW_IC_DATA_CMD);
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
static int
i2c_dw_xfer(struct i2c_adapter *adap, struct i2c_msg msgs[], int num)
{
struct dw_i2c_dev *dev = i2c_get_adapdata(adap);
int ret;
dev_dbg(dev->dev, "%s: msgs: %d\n", __func__, num);
mutex_lock(&dev->lock);
INIT_COMPLETION(dev->cmd_complete);
dev->msgs = msgs;
dev->msgs_num = num;
dev->cmd_err = 0;
dev->msg_write_idx = 0;
dev->msg_read_idx = 0;
dev->msg_err = 0;
dev->status = STATUS_IDLE;
dev->abort_source = 0;
ret = i2c_dw_wait_bus_not_busy(dev);
if (ret < 0)
goto done;
i2c_dw_xfer_init(dev);
ret = wait_for_completion_interruptible_timeout(&dev->cmd_complete, HZ);
if (ret == 0) {
dev_err(dev->dev, "controller timed out\n");
i2c_dw_init(dev);
ret = -ETIMEDOUT;
goto done;
} else if (ret < 0)
goto done;
if (dev->msg_err) {
ret = dev->msg_err;
goto done;
}
if (likely(!dev->cmd_err)) {
writel(0, dev->base + DW_IC_ENABLE);
ret = num;
goto done;
}
if (dev->cmd_err == DW_IC_ERR_TX_ABRT) {
ret = i2c_dw_handle_tx_abort(dev);
goto done;
}
ret = -EIO;
done:
mutex_unlock(&dev->lock);
return ret;
}
static u32 i2c_dw_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C |
I2C_FUNC_10BIT_ADDR |
I2C_FUNC_SMBUS_BYTE |
I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_I2C_BLOCK;
}
static u32 i2c_dw_read_clear_intrbits(struct dw_i2c_dev *dev)
{
u32 stat;
stat = readl(dev->base + DW_IC_INTR_STAT);
if (stat & DW_IC_INTR_RX_UNDER)
readl(dev->base + DW_IC_CLR_RX_UNDER);
if (stat & DW_IC_INTR_RX_OVER)
readl(dev->base + DW_IC_CLR_RX_OVER);
if (stat & DW_IC_INTR_TX_OVER)
readl(dev->base + DW_IC_CLR_TX_OVER);
if (stat & DW_IC_INTR_RD_REQ)
readl(dev->base + DW_IC_CLR_RD_REQ);
if (stat & DW_IC_INTR_TX_ABRT) {
dev->abort_source = readl(dev->base + DW_IC_TX_ABRT_SOURCE);
readl(dev->base + DW_IC_CLR_TX_ABRT);
}
if (stat & DW_IC_INTR_RX_DONE)
readl(dev->base + DW_IC_CLR_RX_DONE);
if (stat & DW_IC_INTR_ACTIVITY)
readl(dev->base + DW_IC_CLR_ACTIVITY);
if (stat & DW_IC_INTR_STOP_DET)
readl(dev->base + DW_IC_CLR_STOP_DET);
if (stat & DW_IC_INTR_START_DET)
readl(dev->base + DW_IC_CLR_START_DET);
if (stat & DW_IC_INTR_GEN_CALL)
readl(dev->base + DW_IC_CLR_GEN_CALL);
return stat;
}
static irqreturn_t i2c_dw_isr(int this_irq, void *dev_id)
{
struct dw_i2c_dev *dev = dev_id;
u32 stat;
stat = i2c_dw_read_clear_intrbits(dev);
dev_dbg(dev->dev, "%s: stat=0x%x\n", __func__, stat);
if (stat & DW_IC_INTR_TX_ABRT) {
dev->cmd_err |= DW_IC_ERR_TX_ABRT;
dev->status = STATUS_IDLE;
writel(0, dev->base + DW_IC_INTR_MASK);
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
static int __devinit dw_i2c_probe(struct platform_device *pdev)
{
struct dw_i2c_dev *dev;
struct i2c_adapter *adap;
struct resource *mem, *ioarea;
int irq, r;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "no mem resource?\n");
return -EINVAL;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no irq resource?\n");
return irq;
}
ioarea = request_mem_region(mem->start, resource_size(mem),
pdev->name);
if (!ioarea) {
dev_err(&pdev->dev, "I2C region already claimed\n");
return -EBUSY;
}
dev = kzalloc(sizeof(struct dw_i2c_dev), GFP_KERNEL);
if (!dev) {
r = -ENOMEM;
goto err_release_region;
}
init_completion(&dev->cmd_complete);
mutex_init(&dev->lock);
dev->dev = get_device(&pdev->dev);
dev->irq = irq;
platform_set_drvdata(pdev, dev);
dev->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(dev->clk)) {
r = -ENODEV;
goto err_free_mem;
}
clk_enable(dev->clk);
dev->base = ioremap(mem->start, resource_size(mem));
if (dev->base == NULL) {
dev_err(&pdev->dev, "failure mapping io resources\n");
r = -EBUSY;
goto err_unuse_clocks;
}
{
u32 param1 = readl(dev->base + DW_IC_COMP_PARAM_1);
dev->tx_fifo_depth = ((param1 >> 16) & 0xff) + 1;
dev->rx_fifo_depth = ((param1 >> 8) & 0xff) + 1;
}
i2c_dw_init(dev);
writel(0, dev->base + DW_IC_INTR_MASK);
r = request_irq(dev->irq, i2c_dw_isr, IRQF_DISABLED, pdev->name, dev);
if (r) {
dev_err(&pdev->dev, "failure requesting irq %i\n", dev->irq);
goto err_iounmap;
}
adap = &dev->adapter;
i2c_set_adapdata(adap, dev);
adap->owner = THIS_MODULE;
adap->class = I2C_CLASS_HWMON;
strlcpy(adap->name, "Synopsys DesignWare I2C adapter",
sizeof(adap->name));
adap->algo = &i2c_dw_algo;
adap->dev.parent = &pdev->dev;
adap->nr = pdev->id;
r = i2c_add_numbered_adapter(adap);
if (r) {
dev_err(&pdev->dev, "failure adding adapter\n");
goto err_free_irq;
}
return 0;
err_free_irq:
free_irq(dev->irq, dev);
err_iounmap:
iounmap(dev->base);
err_unuse_clocks:
clk_disable(dev->clk);
clk_put(dev->clk);
dev->clk = NULL;
err_free_mem:
platform_set_drvdata(pdev, NULL);
put_device(&pdev->dev);
kfree(dev);
err_release_region:
release_mem_region(mem->start, resource_size(mem));
return r;
}
static int __devexit dw_i2c_remove(struct platform_device *pdev)
{
struct dw_i2c_dev *dev = platform_get_drvdata(pdev);
struct resource *mem;
platform_set_drvdata(pdev, NULL);
i2c_del_adapter(&dev->adapter);
put_device(&pdev->dev);
clk_disable(dev->clk);
clk_put(dev->clk);
dev->clk = NULL;
writel(0, dev->base + DW_IC_ENABLE);
free_irq(dev->irq, dev);
kfree(dev);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(mem->start, resource_size(mem));
return 0;
}
static int __init dw_i2c_init_driver(void)
{
return platform_driver_probe(&dw_i2c_driver, dw_i2c_probe);
}
static void __exit dw_i2c_exit_driver(void)
{
platform_driver_unregister(&dw_i2c_driver);
}
