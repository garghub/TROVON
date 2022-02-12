u32 dw_readl(struct dw_i2c_dev *dev, int offset)
{
u32 value;
if (dev->flags & ACCESS_16BIT)
value = readw_relaxed(dev->base + offset) |
(readw_relaxed(dev->base + offset + 2) << 16);
else
value = readl_relaxed(dev->base + offset);
if (dev->flags & ACCESS_SWAP)
return swab32(value);
else
return value;
}
void dw_writel(struct dw_i2c_dev *dev, u32 b, int offset)
{
if (dev->flags & ACCESS_SWAP)
b = swab32(b);
if (dev->flags & ACCESS_16BIT) {
writew_relaxed((u16)b, dev->base + offset);
writew_relaxed((u16)(b >> 16), dev->base + offset + 2);
} else {
writel_relaxed(b, dev->base + offset);
}
}
u32 i2c_dw_scl_hcnt(u32 ic_clk, u32 tSYMBOL, u32 tf, int cond, int offset)
{
if (cond)
return (ic_clk * tSYMBOL + 500000) / 1000000 - 8 + offset;
else
return (ic_clk * (tSYMBOL + tf) + 500000) / 1000000
- 3 + offset;
}
u32 i2c_dw_scl_lcnt(u32 ic_clk, u32 tLOW, u32 tf, int offset)
{
return ((ic_clk * (tLOW + tf) + 500000) / 1000000) - 1 + offset;
}
void __i2c_dw_enable(struct dw_i2c_dev *dev, bool enable)
{
dw_writel(dev, enable, DW_IC_ENABLE);
}
void __i2c_dw_enable_and_wait(struct dw_i2c_dev *dev, bool enable)
{
int timeout = 100;
do {
__i2c_dw_enable(dev, enable);
if ((dw_readl(dev, DW_IC_ENABLE_STATUS) & 1) == enable)
return;
usleep_range(25, 250);
} while (timeout--);
dev_warn(dev->dev, "timeout in %sabling adapter\n",
enable ? "en" : "dis");
}
unsigned long i2c_dw_clk_rate(struct dw_i2c_dev *dev)
{
if (WARN_ON_ONCE(!dev->get_clk_rate_khz))
return 0;
return dev->get_clk_rate_khz(dev);
}
int i2c_dw_acquire_lock(struct dw_i2c_dev *dev)
{
int ret;
if (!dev->acquire_lock)
return 0;
ret = dev->acquire_lock(dev);
if (!ret)
return 0;
dev_err(dev->dev, "couldn't acquire bus ownership\n");
return ret;
}
void i2c_dw_release_lock(struct dw_i2c_dev *dev)
{
if (dev->release_lock)
dev->release_lock(dev);
}
int i2c_dw_wait_bus_not_busy(struct dw_i2c_dev *dev)
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
int i2c_dw_handle_tx_abort(struct dw_i2c_dev *dev)
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
u32 i2c_dw_func(struct i2c_adapter *adap)
{
struct dw_i2c_dev *dev = i2c_get_adapdata(adap);
return dev->functionality;
}
void i2c_dw_disable(struct dw_i2c_dev *dev)
{
__i2c_dw_enable_and_wait(dev, false);
dw_writel(dev, 0, DW_IC_INTR_MASK);
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
