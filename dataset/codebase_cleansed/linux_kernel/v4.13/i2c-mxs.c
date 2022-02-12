static int mxs_i2c_reset(struct mxs_i2c_dev *i2c)
{
int ret = stmp_reset_block(i2c->regs);
if (ret)
return ret;
writel(i2c->timing0, i2c->regs + MXS_I2C_TIMING0);
writel(i2c->timing1, i2c->regs + MXS_I2C_TIMING1);
writel(i2c->timing2, i2c->regs + MXS_I2C_TIMING2);
writel(MXS_I2C_IRQ_MASK << 8, i2c->regs + MXS_I2C_CTRL1_SET);
return 0;
}
static void mxs_i2c_dma_finish(struct mxs_i2c_dev *i2c)
{
if (i2c->dma_read) {
dma_unmap_sg(i2c->dev, &i2c->sg_io[0], 1, DMA_TO_DEVICE);
dma_unmap_sg(i2c->dev, &i2c->sg_io[1], 1, DMA_FROM_DEVICE);
} else {
dma_unmap_sg(i2c->dev, i2c->sg_io, 2, DMA_TO_DEVICE);
}
}
static void mxs_i2c_dma_irq_callback(void *param)
{
struct mxs_i2c_dev *i2c = param;
complete(&i2c->cmd_complete);
mxs_i2c_dma_finish(i2c);
}
static int mxs_i2c_dma_setup_xfer(struct i2c_adapter *adap,
struct i2c_msg *msg, uint32_t flags)
{
struct dma_async_tx_descriptor *desc;
struct mxs_i2c_dev *i2c = i2c_get_adapdata(adap);
if (msg->flags & I2C_M_RD) {
i2c->dma_read = 1;
i2c->addr_data = (msg->addr << 1) | I2C_SMBUS_READ;
i2c->pio_data[0] = MXS_CMD_I2C_SELECT;
desc = dmaengine_prep_slave_sg(i2c->dmach,
(struct scatterlist *)&i2c->pio_data[0],
1, DMA_TRANS_NONE, 0);
if (!desc) {
dev_err(i2c->dev,
"Failed to get PIO reg. write descriptor.\n");
goto select_init_pio_fail;
}
sg_init_one(&i2c->sg_io[0], &i2c->addr_data, 1);
dma_map_sg(i2c->dev, &i2c->sg_io[0], 1, DMA_TO_DEVICE);
desc = dmaengine_prep_slave_sg(i2c->dmach, &i2c->sg_io[0], 1,
DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
dev_err(i2c->dev,
"Failed to get DMA data write descriptor.\n");
goto select_init_dma_fail;
}
i2c->pio_data[1] = flags | MXS_CMD_I2C_READ |
MXS_I2C_CTRL0_XFER_COUNT(msg->len);
desc = dmaengine_prep_slave_sg(i2c->dmach,
(struct scatterlist *)&i2c->pio_data[1],
1, DMA_TRANS_NONE, DMA_PREP_INTERRUPT);
if (!desc) {
dev_err(i2c->dev,
"Failed to get PIO reg. write descriptor.\n");
goto select_init_dma_fail;
}
sg_init_one(&i2c->sg_io[1], msg->buf, msg->len);
dma_map_sg(i2c->dev, &i2c->sg_io[1], 1, DMA_FROM_DEVICE);
desc = dmaengine_prep_slave_sg(i2c->dmach, &i2c->sg_io[1], 1,
DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
dev_err(i2c->dev,
"Failed to get DMA data write descriptor.\n");
goto read_init_dma_fail;
}
} else {
i2c->dma_read = 0;
i2c->addr_data = (msg->addr << 1) | I2C_SMBUS_WRITE;
i2c->pio_data[0] = flags | MXS_CMD_I2C_WRITE |
MXS_I2C_CTRL0_XFER_COUNT(msg->len + 1);
desc = dmaengine_prep_slave_sg(i2c->dmach,
(struct scatterlist *)&i2c->pio_data[0],
1, DMA_TRANS_NONE, 0);
if (!desc) {
dev_err(i2c->dev,
"Failed to get PIO reg. write descriptor.\n");
goto write_init_pio_fail;
}
sg_init_table(i2c->sg_io, 2);
sg_set_buf(&i2c->sg_io[0], &i2c->addr_data, 1);
sg_set_buf(&i2c->sg_io[1], msg->buf, msg->len);
dma_map_sg(i2c->dev, i2c->sg_io, 2, DMA_TO_DEVICE);
desc = dmaengine_prep_slave_sg(i2c->dmach, i2c->sg_io, 2,
DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
dev_err(i2c->dev,
"Failed to get DMA data write descriptor.\n");
goto write_init_dma_fail;
}
}
desc->callback = mxs_i2c_dma_irq_callback;
desc->callback_param = i2c;
dmaengine_submit(desc);
dma_async_issue_pending(i2c->dmach);
return 0;
read_init_dma_fail:
dma_unmap_sg(i2c->dev, &i2c->sg_io[1], 1, DMA_FROM_DEVICE);
select_init_dma_fail:
dma_unmap_sg(i2c->dev, &i2c->sg_io[0], 1, DMA_TO_DEVICE);
select_init_pio_fail:
dmaengine_terminate_all(i2c->dmach);
return -EINVAL;
write_init_dma_fail:
dma_unmap_sg(i2c->dev, i2c->sg_io, 2, DMA_TO_DEVICE);
write_init_pio_fail:
dmaengine_terminate_all(i2c->dmach);
return -EINVAL;
}
static int mxs_i2c_pio_wait_xfer_end(struct mxs_i2c_dev *i2c)
{
unsigned long timeout = jiffies + msecs_to_jiffies(1000);
while (readl(i2c->regs + MXS_I2C_CTRL0) & MXS_I2C_CTRL0_RUN) {
if (readl(i2c->regs + MXS_I2C_CTRL1) &
MXS_I2C_CTRL1_NO_SLAVE_ACK_IRQ)
return -ENXIO;
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
cond_resched();
}
return 0;
}
static int mxs_i2c_pio_check_error_state(struct mxs_i2c_dev *i2c)
{
u32 state;
state = readl(i2c->regs + MXS_I2C_CTRL1_CLR) & MXS_I2C_IRQ_MASK;
if (state & MXS_I2C_CTRL1_NO_SLAVE_ACK_IRQ)
i2c->cmd_err = -ENXIO;
else if (state & (MXS_I2C_CTRL1_EARLY_TERM_IRQ |
MXS_I2C_CTRL1_MASTER_LOSS_IRQ |
MXS_I2C_CTRL1_SLAVE_STOP_IRQ |
MXS_I2C_CTRL1_SLAVE_IRQ))
i2c->cmd_err = -EIO;
return i2c->cmd_err;
}
static void mxs_i2c_pio_trigger_cmd(struct mxs_i2c_dev *i2c, u32 cmd)
{
u32 reg;
writel(cmd, i2c->regs + MXS_I2C_CTRL0);
reg = readl(i2c->regs + MXS_I2C_CTRL0);
reg |= MXS_I2C_CTRL0_RUN;
writel(reg, i2c->regs + MXS_I2C_CTRL0);
}
static void mxs_i2c_pio_trigger_write_cmd(struct mxs_i2c_dev *i2c, u32 cmd,
u32 data)
{
writel(cmd, i2c->regs + MXS_I2C_CTRL0);
if (i2c->dev_type == MXS_I2C_V1)
writel(MXS_I2C_CTRL0_PIO_MODE, i2c->regs + MXS_I2C_CTRL0_SET);
writel(data, i2c->regs + MXS_I2C_DATA(i2c));
writel(MXS_I2C_CTRL0_RUN, i2c->regs + MXS_I2C_CTRL0_SET);
}
static int mxs_i2c_pio_setup_xfer(struct i2c_adapter *adap,
struct i2c_msg *msg, uint32_t flags)
{
struct mxs_i2c_dev *i2c = i2c_get_adapdata(adap);
uint32_t addr_data = msg->addr << 1;
uint32_t data = 0;
int i, ret, xlen = 0, xmit = 0;
uint32_t start;
writel(MXS_I2C_IRQ_MASK << 8, i2c->regs + MXS_I2C_CTRL1_CLR);
if (msg->flags & I2C_M_RD) {
BUG_ON(msg->len > 4);
addr_data |= I2C_SMBUS_READ;
mxs_i2c_pio_trigger_write_cmd(i2c, MXS_CMD_I2C_SELECT,
addr_data);
ret = mxs_i2c_pio_wait_xfer_end(i2c);
if (ret) {
dev_dbg(i2c->dev,
"PIO: Failed to send SELECT command!\n");
goto cleanup;
}
mxs_i2c_pio_trigger_cmd(i2c,
MXS_CMD_I2C_READ | flags |
MXS_I2C_CTRL0_XFER_COUNT(msg->len));
ret = mxs_i2c_pio_wait_xfer_end(i2c);
if (ret) {
dev_dbg(i2c->dev,
"PIO: Failed to send READ command!\n");
goto cleanup;
}
data = readl(i2c->regs + MXS_I2C_DATA(i2c));
for (i = 0; i < msg->len; i++) {
msg->buf[i] = data & 0xff;
data >>= 8;
}
} else {
addr_data |= I2C_SMBUS_WRITE;
data = addr_data << 24;
start = MXS_I2C_CTRL0_PRE_SEND_START;
if (msg->len > 3)
start |= MXS_I2C_CTRL0_RETAIN_CLOCK;
for (i = 0; i < msg->len; i++) {
data >>= 8;
data |= (msg->buf[i] << 24);
xmit = 0;
if (i + 1 == msg->len) {
start |= flags;
start &= ~MXS_I2C_CTRL0_RETAIN_CLOCK;
xmit = 1;
}
if ((i & 3) == 2)
xmit = 1;
if (!xmit)
continue;
if ((i % 4) == 3)
xlen = 1;
else
xlen = (i % 4) + 2;
data >>= (4 - xlen) * 8;
dev_dbg(i2c->dev,
"PIO: len=%i pos=%i total=%i [W%s%s%s]\n",
xlen, i, msg->len,
start & MXS_I2C_CTRL0_PRE_SEND_START ? "S" : "",
start & MXS_I2C_CTRL0_POST_SEND_STOP ? "E" : "",
start & MXS_I2C_CTRL0_RETAIN_CLOCK ? "C" : "");
writel(MXS_I2C_DEBUG0_DMAREQ,
i2c->regs + MXS_I2C_DEBUG0_CLR(i2c));
mxs_i2c_pio_trigger_write_cmd(i2c,
start | MXS_I2C_CTRL0_MASTER_MODE |
MXS_I2C_CTRL0_DIRECTION |
MXS_I2C_CTRL0_XFER_COUNT(xlen), data);
start &= ~MXS_I2C_CTRL0_PRE_SEND_START;
ret = mxs_i2c_pio_wait_xfer_end(i2c);
if (ret) {
dev_dbg(i2c->dev,
"PIO: Failed to finish WRITE cmd!\n");
break;
}
ret = readl(i2c->regs + MXS_I2C_STAT) &
MXS_I2C_STAT_GOT_A_NAK;
if (ret) {
ret = -ENXIO;
goto cleanup;
}
}
}
ret = mxs_i2c_pio_check_error_state(i2c);
cleanup:
writel(MXS_I2C_IRQ_MASK, i2c->regs + MXS_I2C_CTRL1_CLR);
writel(MXS_I2C_IRQ_MASK << 8, i2c->regs + MXS_I2C_CTRL1_SET);
if (i2c->dev_type == MXS_I2C_V1)
writel(MXS_I2C_CTRL0_PIO_MODE, i2c->regs + MXS_I2C_CTRL0_CLR);
return ret;
}
static int mxs_i2c_xfer_msg(struct i2c_adapter *adap, struct i2c_msg *msg,
int stop)
{
struct mxs_i2c_dev *i2c = i2c_get_adapdata(adap);
int ret;
int flags;
int use_pio = 0;
unsigned long time_left;
flags = stop ? MXS_I2C_CTRL0_POST_SEND_STOP : 0;
dev_dbg(i2c->dev, "addr: 0x%04x, len: %d, flags: 0x%x, stop: %d\n",
msg->addr, msg->len, msg->flags, stop);
if (msg->len == 0)
return -EINVAL;
if ((msg->flags & I2C_M_RD) && (msg->len <= 4))
use_pio = 1;
if (!(msg->flags & I2C_M_RD) && (msg->len < 7))
use_pio = 1;
i2c->cmd_err = 0;
if (use_pio) {
ret = mxs_i2c_pio_setup_xfer(adap, msg, flags);
if (ret && (ret != -ENXIO))
mxs_i2c_reset(i2c);
} else {
reinit_completion(&i2c->cmd_complete);
ret = mxs_i2c_dma_setup_xfer(adap, msg, flags);
if (ret)
return ret;
time_left = wait_for_completion_timeout(&i2c->cmd_complete,
msecs_to_jiffies(1000));
if (!time_left)
goto timeout;
ret = i2c->cmd_err;
}
if (ret == -ENXIO) {
writel(MXS_I2C_CTRL1_CLR_GOT_A_NAK,
i2c->regs + MXS_I2C_CTRL1_SET);
}
if (i2c->dev_type == MXS_I2C_V1)
mxs_i2c_reset(i2c);
dev_dbg(i2c->dev, "Done with err=%d\n", ret);
return ret;
timeout:
dev_dbg(i2c->dev, "Timeout!\n");
mxs_i2c_dma_finish(i2c);
ret = mxs_i2c_reset(i2c);
if (ret)
return ret;
return -ETIMEDOUT;
}
static int mxs_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msgs[],
int num)
{
int i;
int err;
for (i = 0; i < num; i++) {
err = mxs_i2c_xfer_msg(adap, &msgs[i], i == (num - 1));
if (err)
return err;
}
return num;
}
static u32 mxs_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static irqreturn_t mxs_i2c_isr(int this_irq, void *dev_id)
{
struct mxs_i2c_dev *i2c = dev_id;
u32 stat = readl(i2c->regs + MXS_I2C_CTRL1) & MXS_I2C_IRQ_MASK;
if (!stat)
return IRQ_NONE;
if (stat & MXS_I2C_CTRL1_NO_SLAVE_ACK_IRQ)
i2c->cmd_err = -ENXIO;
else if (stat & (MXS_I2C_CTRL1_EARLY_TERM_IRQ |
MXS_I2C_CTRL1_MASTER_LOSS_IRQ |
MXS_I2C_CTRL1_SLAVE_STOP_IRQ | MXS_I2C_CTRL1_SLAVE_IRQ))
i2c->cmd_err = -EIO;
writel(stat, i2c->regs + MXS_I2C_CTRL1_CLR);
return IRQ_HANDLED;
}
static void mxs_i2c_derive_timing(struct mxs_i2c_dev *i2c, uint32_t speed)
{
const uint32_t clk = 24000000;
uint32_t divider;
uint16_t high_count, low_count, rcv_count, xmit_count;
uint32_t bus_free, leadin;
struct device *dev = i2c->dev;
divider = DIV_ROUND_UP(clk, speed);
if (divider < 25) {
divider = 25;
dev_warn(dev,
"Speed too high (%u.%03u kHz), using %u.%03u kHz\n",
speed / 1000, speed % 1000,
clk / divider / 1000, clk / divider % 1000);
} else if (divider > 1897) {
divider = 1897;
dev_warn(dev,
"Speed too low (%u.%03u kHz), using %u.%03u kHz\n",
speed / 1000, speed % 1000,
clk / divider / 1000, clk / divider % 1000);
}
if (speed > 100000) {
low_count = DIV_ROUND_CLOSEST(divider * 13, (13 + 6));
high_count = DIV_ROUND_CLOSEST(divider * 6, (13 + 6));
leadin = DIV_ROUND_UP(600 * (clk / 1000000), 1000);
bus_free = DIV_ROUND_UP(1300 * (clk / 1000000), 1000);
} else {
low_count = DIV_ROUND_CLOSEST(divider * 47, (47 + 40));
high_count = DIV_ROUND_CLOSEST(divider * 40, (47 + 40));
leadin = DIV_ROUND_UP(4700 * (clk / 1000000), 1000);
bus_free = DIV_ROUND_UP(4700 * (clk / 1000000), 1000);
}
rcv_count = high_count * 3 / 8;
xmit_count = low_count * 3 / 8;
dev_dbg(dev,
"speed=%u(actual %u) divider=%u low=%u high=%u xmit=%u rcv=%u leadin=%u bus_free=%u\n",
speed, clk / divider, divider, low_count, high_count,
xmit_count, rcv_count, leadin, bus_free);
low_count -= 2;
high_count -= 7;
i2c->timing0 = (high_count << 16) | rcv_count;
i2c->timing1 = (low_count << 16) | xmit_count;
i2c->timing2 = (bus_free << 16 | leadin);
}
static int mxs_i2c_get_ofdata(struct mxs_i2c_dev *i2c)
{
uint32_t speed;
struct device *dev = i2c->dev;
struct device_node *node = dev->of_node;
int ret;
ret = of_property_read_u32(node, "clock-frequency", &speed);
if (ret) {
dev_warn(dev, "No I2C speed selected, using 100kHz\n");
speed = 100000;
}
mxs_i2c_derive_timing(i2c, speed);
return 0;
}
static int mxs_i2c_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(mxs_i2c_dt_ids, &pdev->dev);
struct device *dev = &pdev->dev;
struct mxs_i2c_dev *i2c;
struct i2c_adapter *adap;
struct resource *res;
int err, irq;
i2c = devm_kzalloc(dev, sizeof(*i2c), GFP_KERNEL);
if (!i2c)
return -ENOMEM;
if (of_id) {
const struct platform_device_id *device_id = of_id->data;
i2c->dev_type = device_id->driver_data;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
i2c->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(i2c->regs))
return PTR_ERR(i2c->regs);
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
err = devm_request_irq(dev, irq, mxs_i2c_isr, 0, dev_name(dev), i2c);
if (err)
return err;
i2c->dev = dev;
init_completion(&i2c->cmd_complete);
if (dev->of_node) {
err = mxs_i2c_get_ofdata(i2c);
if (err)
return err;
}
i2c->dmach = dma_request_slave_channel(dev, "rx-tx");
if (!i2c->dmach) {
dev_err(dev, "Failed to request dma\n");
return -ENODEV;
}
platform_set_drvdata(pdev, i2c);
err = mxs_i2c_reset(i2c);
if (err)
return err;
adap = &i2c->adapter;
strlcpy(adap->name, "MXS I2C adapter", sizeof(adap->name));
adap->owner = THIS_MODULE;
adap->algo = &mxs_i2c_algo;
adap->dev.parent = dev;
adap->nr = pdev->id;
adap->dev.of_node = pdev->dev.of_node;
i2c_set_adapdata(adap, i2c);
err = i2c_add_numbered_adapter(adap);
if (err) {
writel(MXS_I2C_CTRL0_SFTRST,
i2c->regs + MXS_I2C_CTRL0_SET);
return err;
}
return 0;
}
static int mxs_i2c_remove(struct platform_device *pdev)
{
struct mxs_i2c_dev *i2c = platform_get_drvdata(pdev);
i2c_del_adapter(&i2c->adapter);
if (i2c->dmach)
dma_release_channel(i2c->dmach);
writel(MXS_I2C_CTRL0_SFTRST, i2c->regs + MXS_I2C_CTRL0_SET);
return 0;
}
static int __init mxs_i2c_init(void)
{
return platform_driver_register(&mxs_i2c_driver);
}
static void __exit mxs_i2c_exit(void)
{
platform_driver_unregister(&mxs_i2c_driver);
}
