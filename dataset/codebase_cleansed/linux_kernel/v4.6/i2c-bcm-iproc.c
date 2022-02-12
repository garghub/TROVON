static irqreturn_t bcm_iproc_i2c_isr(int irq, void *data)
{
struct bcm_iproc_i2c_dev *iproc_i2c = data;
u32 status = readl(iproc_i2c->base + IS_OFFSET);
status &= ISR_MASK;
if (!status)
return IRQ_NONE;
if (status & BIT(IS_M_TX_UNDERRUN_SHIFT)) {
struct i2c_msg *msg = iproc_i2c->msg;
unsigned int tx_bytes = msg->len - iproc_i2c->tx_bytes;
unsigned int i;
u32 val;
tx_bytes = min_t(unsigned int, tx_bytes, M_TX_RX_FIFO_SIZE);
for (i = 0; i < tx_bytes; i++) {
unsigned int idx = iproc_i2c->tx_bytes + i;
val = msg->buf[idx];
if (idx == msg->len - 1) {
u32 tmp;
val |= BIT(M_TX_WR_STATUS_SHIFT);
tmp = readl(iproc_i2c->base + IE_OFFSET);
tmp &= ~BIT(IE_M_TX_UNDERRUN_SHIFT);
writel(tmp, iproc_i2c->base + IE_OFFSET);
}
writel(val, iproc_i2c->base + M_TX_OFFSET);
}
iproc_i2c->tx_bytes += tx_bytes;
}
if (status & BIT(IS_M_START_BUSY_SHIFT)) {
iproc_i2c->xfer_is_done = 1;
complete_all(&iproc_i2c->done);
}
writel(status, iproc_i2c->base + IS_OFFSET);
return IRQ_HANDLED;
}
static int bcm_iproc_i2c_init(struct bcm_iproc_i2c_dev *iproc_i2c)
{
u32 val;
val = readl(iproc_i2c->base + CFG_OFFSET);
val |= 1 << CFG_RESET_SHIFT;
val &= ~(1 << CFG_EN_SHIFT);
writel(val, iproc_i2c->base + CFG_OFFSET);
udelay(100);
val &= ~(1 << CFG_RESET_SHIFT);
writel(val, iproc_i2c->base + CFG_OFFSET);
val = (1 << M_FIFO_RX_FLUSH_SHIFT) | (1 << M_FIFO_TX_FLUSH_SHIFT);
writel(val, iproc_i2c->base + M_FIFO_CTRL_OFFSET);
writel(0, iproc_i2c->base + IE_OFFSET);
writel(0xffffffff, iproc_i2c->base + IS_OFFSET);
return 0;
}
static void bcm_iproc_i2c_enable_disable(struct bcm_iproc_i2c_dev *iproc_i2c,
bool enable)
{
u32 val;
val = readl(iproc_i2c->base + CFG_OFFSET);
if (enable)
val |= BIT(CFG_EN_SHIFT);
else
val &= ~BIT(CFG_EN_SHIFT);
writel(val, iproc_i2c->base + CFG_OFFSET);
}
static int bcm_iproc_i2c_check_status(struct bcm_iproc_i2c_dev *iproc_i2c,
struct i2c_msg *msg)
{
u32 val;
val = readl(iproc_i2c->base + M_CMD_OFFSET);
val = (val >> M_CMD_STATUS_SHIFT) & M_CMD_STATUS_MASK;
switch (val) {
case M_CMD_STATUS_SUCCESS:
return 0;
case M_CMD_STATUS_LOST_ARB:
dev_dbg(iproc_i2c->device, "lost bus arbitration\n");
return -EAGAIN;
case M_CMD_STATUS_NACK_ADDR:
dev_dbg(iproc_i2c->device, "NAK addr:0x%02x\n", msg->addr);
return -ENXIO;
case M_CMD_STATUS_NACK_DATA:
dev_dbg(iproc_i2c->device, "NAK data\n");
return -ENXIO;
case M_CMD_STATUS_TIMEOUT:
dev_dbg(iproc_i2c->device, "bus timeout\n");
return -ETIMEDOUT;
default:
dev_dbg(iproc_i2c->device, "unknown error code=%d\n", val);
bcm_iproc_i2c_enable_disable(iproc_i2c, false);
bcm_iproc_i2c_init(iproc_i2c);
bcm_iproc_i2c_enable_disable(iproc_i2c, true);
return -EIO;
}
}
static int bcm_iproc_i2c_xfer_single_msg(struct bcm_iproc_i2c_dev *iproc_i2c,
struct i2c_msg *msg)
{
int ret, i;
u8 addr;
u32 val;
unsigned int tx_bytes;
unsigned long time_left = msecs_to_jiffies(I2C_TIMEOUT_MSEC);
if (!!(readl(iproc_i2c->base + M_CMD_OFFSET) &
BIT(M_CMD_START_BUSY_SHIFT))) {
dev_warn(iproc_i2c->device, "bus is busy\n");
return -EBUSY;
}
iproc_i2c->msg = msg;
addr = msg->addr << 1 | (msg->flags & I2C_M_RD ? 1 : 0);
writel(addr, iproc_i2c->base + M_TX_OFFSET);
tx_bytes = min_t(unsigned int, msg->len, M_TX_RX_FIFO_SIZE - 1);
if (!(msg->flags & I2C_M_RD)) {
for (i = 0; i < tx_bytes; i++) {
val = msg->buf[i];
if (i == msg->len - 1)
val |= 1 << M_TX_WR_STATUS_SHIFT;
writel(val, iproc_i2c->base + M_TX_OFFSET);
}
iproc_i2c->tx_bytes = tx_bytes;
}
reinit_completion(&iproc_i2c->done);
iproc_i2c->xfer_is_done = 0;
val = BIT(IE_M_START_BUSY_SHIFT);
if (!(msg->flags & I2C_M_RD) &&
msg->len > iproc_i2c->tx_bytes)
val |= BIT(IE_M_TX_UNDERRUN_SHIFT);
writel(val, iproc_i2c->base + IE_OFFSET);
val = BIT(M_CMD_START_BUSY_SHIFT);
if (msg->flags & I2C_M_RD) {
val |= (M_CMD_PROTOCOL_BLK_RD << M_CMD_PROTOCOL_SHIFT) |
(msg->len << M_CMD_RD_CNT_SHIFT);
} else {
val |= (M_CMD_PROTOCOL_BLK_WR << M_CMD_PROTOCOL_SHIFT);
}
writel(val, iproc_i2c->base + M_CMD_OFFSET);
time_left = wait_for_completion_timeout(&iproc_i2c->done, time_left);
writel(0, iproc_i2c->base + IE_OFFSET);
readl(iproc_i2c->base + IE_OFFSET);
synchronize_irq(iproc_i2c->irq);
if (!time_left && !iproc_i2c->xfer_is_done) {
dev_err(iproc_i2c->device, "transaction timed out\n");
val = (1 << M_FIFO_RX_FLUSH_SHIFT) |
(1 << M_FIFO_TX_FLUSH_SHIFT);
writel(val, iproc_i2c->base + M_FIFO_CTRL_OFFSET);
return -ETIMEDOUT;
}
ret = bcm_iproc_i2c_check_status(iproc_i2c, msg);
if (ret) {
val = (1 << M_FIFO_RX_FLUSH_SHIFT) |
(1 << M_FIFO_TX_FLUSH_SHIFT);
writel(val, iproc_i2c->base + M_FIFO_CTRL_OFFSET);
return ret;
}
if (msg->flags & I2C_M_RD) {
for (i = 0; i < msg->len; i++) {
msg->buf[i] = (readl(iproc_i2c->base + M_RX_OFFSET) >>
M_RX_DATA_SHIFT) & M_RX_DATA_MASK;
}
}
return 0;
}
static int bcm_iproc_i2c_xfer(struct i2c_adapter *adapter,
struct i2c_msg msgs[], int num)
{
struct bcm_iproc_i2c_dev *iproc_i2c = i2c_get_adapdata(adapter);
int ret, i;
for (i = 0; i < num; i++) {
ret = bcm_iproc_i2c_xfer_single_msg(iproc_i2c, &msgs[i]);
if (ret) {
dev_dbg(iproc_i2c->device, "xfer failed\n");
return ret;
}
}
return num;
}
static uint32_t bcm_iproc_i2c_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int bcm_iproc_i2c_cfg_speed(struct bcm_iproc_i2c_dev *iproc_i2c)
{
unsigned int bus_speed;
u32 val;
int ret = of_property_read_u32(iproc_i2c->device->of_node,
"clock-frequency", &bus_speed);
if (ret < 0) {
dev_info(iproc_i2c->device,
"unable to interpret clock-frequency DT property\n");
bus_speed = 100000;
}
if (bus_speed < 100000) {
dev_err(iproc_i2c->device, "%d Hz bus speed not supported\n",
bus_speed);
dev_err(iproc_i2c->device,
"valid speeds are 100khz and 400khz\n");
return -EINVAL;
} else if (bus_speed < 400000) {
bus_speed = 100000;
} else {
bus_speed = 400000;
}
iproc_i2c->bus_speed = bus_speed;
val = readl(iproc_i2c->base + TIM_CFG_OFFSET);
val &= ~(1 << TIM_CFG_MODE_400_SHIFT);
val |= (bus_speed == 400000) << TIM_CFG_MODE_400_SHIFT;
writel(val, iproc_i2c->base + TIM_CFG_OFFSET);
dev_info(iproc_i2c->device, "bus set to %u Hz\n", bus_speed);
return 0;
}
static int bcm_iproc_i2c_probe(struct platform_device *pdev)
{
int irq, ret = 0;
struct bcm_iproc_i2c_dev *iproc_i2c;
struct i2c_adapter *adap;
struct resource *res;
iproc_i2c = devm_kzalloc(&pdev->dev, sizeof(*iproc_i2c),
GFP_KERNEL);
if (!iproc_i2c)
return -ENOMEM;
platform_set_drvdata(pdev, iproc_i2c);
iproc_i2c->device = &pdev->dev;
init_completion(&iproc_i2c->done);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
iproc_i2c->base = devm_ioremap_resource(iproc_i2c->device, res);
if (IS_ERR(iproc_i2c->base))
return PTR_ERR(iproc_i2c->base);
ret = bcm_iproc_i2c_init(iproc_i2c);
if (ret)
return ret;
ret = bcm_iproc_i2c_cfg_speed(iproc_i2c);
if (ret)
return ret;
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(iproc_i2c->device, "no irq resource\n");
return irq;
}
iproc_i2c->irq = irq;
ret = devm_request_irq(iproc_i2c->device, irq, bcm_iproc_i2c_isr, 0,
pdev->name, iproc_i2c);
if (ret < 0) {
dev_err(iproc_i2c->device, "unable to request irq %i\n", irq);
return ret;
}
bcm_iproc_i2c_enable_disable(iproc_i2c, true);
adap = &iproc_i2c->adapter;
i2c_set_adapdata(adap, iproc_i2c);
strlcpy(adap->name, "Broadcom iProc I2C adapter", sizeof(adap->name));
adap->algo = &bcm_iproc_algo;
adap->quirks = &bcm_iproc_i2c_quirks;
adap->dev.parent = &pdev->dev;
adap->dev.of_node = pdev->dev.of_node;
ret = i2c_add_adapter(adap);
if (ret) {
dev_err(iproc_i2c->device, "failed to add adapter\n");
return ret;
}
return 0;
}
static int bcm_iproc_i2c_remove(struct platform_device *pdev)
{
struct bcm_iproc_i2c_dev *iproc_i2c = platform_get_drvdata(pdev);
writel(0, iproc_i2c->base + IE_OFFSET);
readl(iproc_i2c->base + IE_OFFSET);
synchronize_irq(iproc_i2c->irq);
i2c_del_adapter(&iproc_i2c->adapter);
bcm_iproc_i2c_enable_disable(iproc_i2c, false);
return 0;
}
static int bcm_iproc_i2c_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct bcm_iproc_i2c_dev *iproc_i2c = platform_get_drvdata(pdev);
writel(0, iproc_i2c->base + IE_OFFSET);
readl(iproc_i2c->base + IE_OFFSET);
synchronize_irq(iproc_i2c->irq);
bcm_iproc_i2c_enable_disable(iproc_i2c, false);
return 0;
}
static int bcm_iproc_i2c_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct bcm_iproc_i2c_dev *iproc_i2c = platform_get_drvdata(pdev);
int ret;
u32 val;
ret = bcm_iproc_i2c_init(iproc_i2c);
if (ret)
return ret;
val = readl(iproc_i2c->base + TIM_CFG_OFFSET);
val &= ~(1 << TIM_CFG_MODE_400_SHIFT);
val |= (iproc_i2c->bus_speed == 400000) << TIM_CFG_MODE_400_SHIFT;
writel(val, iproc_i2c->base + TIM_CFG_OFFSET);
bcm_iproc_i2c_enable_disable(iproc_i2c, true);
return 0;
}
