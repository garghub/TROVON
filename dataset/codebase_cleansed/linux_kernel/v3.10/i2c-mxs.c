static void mxs_i2c_reset(struct mxs_i2c_dev *i2c)
{
stmp_reset_block(i2c->regs);
writel(i2c->timing0, i2c->regs + MXS_I2C_TIMING0);
writel(i2c->timing1, i2c->regs + MXS_I2C_TIMING1);
writel(0x00300030, i2c->regs + MXS_I2C_TIMING2);
writel(MXS_I2C_IRQ_MASK << 8, i2c->regs + MXS_I2C_CTRL1_SET);
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
static int mxs_i2c_pio_wait_dmareq(struct mxs_i2c_dev *i2c)
{
unsigned long timeout = jiffies + msecs_to_jiffies(1000);
while (!(readl(i2c->regs + MXS_I2C_DEBUG0) &
MXS_I2C_DEBUG0_DMAREQ)) {
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
cond_resched();
}
return 0;
}
static int mxs_i2c_pio_wait_cplt(struct mxs_i2c_dev *i2c, int last)
{
unsigned long timeout = jiffies + msecs_to_jiffies(1000);
while (!(readl(i2c->regs + MXS_I2C_CTRL1) &
MXS_I2C_CTRL1_DATA_ENGINE_CMPLT_IRQ)) {
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
cond_resched();
}
writel(MXS_I2C_CTRL1_DATA_ENGINE_CMPLT_IRQ,
i2c->regs + MXS_I2C_CTRL1_CLR);
while (last && (readl(i2c->regs + MXS_I2C_STAT) &
(MXS_I2C_STAT_BUS_BUSY | MXS_I2C_STAT_CLK_GEN_BUSY))) {
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
static int mxs_i2c_pio_setup_xfer(struct i2c_adapter *adap,
struct i2c_msg *msg, uint32_t flags)
{
struct mxs_i2c_dev *i2c = i2c_get_adapdata(adap);
uint32_t addr_data = msg->addr << 1;
uint32_t data = 0;
int i, shifts_left, ret;
writel(MXS_I2C_IRQ_MASK << 8, i2c->regs + MXS_I2C_CTRL1_CLR);
if (msg->flags & I2C_M_RD) {
addr_data |= I2C_SMBUS_READ;
mxs_i2c_pio_trigger_cmd(i2c, MXS_CMD_I2C_SELECT);
ret = mxs_i2c_pio_wait_dmareq(i2c);
if (ret)
return ret;
writel(addr_data, i2c->regs + MXS_I2C_DATA);
writel(MXS_I2C_DEBUG0_DMAREQ, i2c->regs + MXS_I2C_DEBUG0_CLR);
ret = mxs_i2c_pio_wait_cplt(i2c, 0);
if (ret)
return ret;
if (mxs_i2c_pio_check_error_state(i2c))
goto cleanup;
mxs_i2c_pio_trigger_cmd(i2c,
MXS_CMD_I2C_READ | flags |
MXS_I2C_CTRL0_XFER_COUNT(msg->len));
for (i = 0; i < msg->len; i++) {
if ((i & 3) == 0) {
ret = mxs_i2c_pio_wait_dmareq(i2c);
if (ret)
return ret;
data = readl(i2c->regs + MXS_I2C_DATA);
writel(MXS_I2C_DEBUG0_DMAREQ,
i2c->regs + MXS_I2C_DEBUG0_CLR);
}
msg->buf[i] = data & 0xff;
data >>= 8;
}
} else {
addr_data |= I2C_SMBUS_WRITE;
mxs_i2c_pio_trigger_cmd(i2c,
MXS_CMD_I2C_WRITE | flags |
MXS_I2C_CTRL0_XFER_COUNT(msg->len + 1));
data = addr_data << 24;
for (i = 0; i < msg->len; i++) {
data >>= 8;
data |= (msg->buf[i] << 24);
if ((i & 3) == 2) {
ret = mxs_i2c_pio_wait_dmareq(i2c);
if (ret)
return ret;
writel(data, i2c->regs + MXS_I2C_DATA);
writel(MXS_I2C_DEBUG0_DMAREQ,
i2c->regs + MXS_I2C_DEBUG0_CLR);
}
}
shifts_left = 24 - (i & 3) * 8;
if (shifts_left) {
data >>= shifts_left;
ret = mxs_i2c_pio_wait_dmareq(i2c);
if (ret)
return ret;
writel(data, i2c->regs + MXS_I2C_DATA);
writel(MXS_I2C_DEBUG0_DMAREQ,
i2c->regs + MXS_I2C_DEBUG0_CLR);
}
}
ret = mxs_i2c_pio_wait_cplt(i2c, flags & MXS_I2C_CTRL0_POST_SEND_STOP);
if (ret)
return ret;
mxs_i2c_pio_check_error_state(i2c);
cleanup:
writel(MXS_I2C_IRQ_MASK, i2c->regs + MXS_I2C_CTRL1_CLR);
writel(MXS_I2C_IRQ_MASK << 8, i2c->regs + MXS_I2C_CTRL1_SET);
return 0;
}
static int mxs_i2c_xfer_msg(struct i2c_adapter *adap, struct i2c_msg *msg,
int stop)
{
struct mxs_i2c_dev *i2c = i2c_get_adapdata(adap);
int ret;
int flags;
flags = stop ? MXS_I2C_CTRL0_POST_SEND_STOP : 0;
dev_dbg(i2c->dev, "addr: 0x%04x, len: %d, flags: 0x%x, stop: %d\n",
msg->addr, msg->len, msg->flags, stop);
if (msg->len == 0)
return -EINVAL;
i2c->cmd_err = 0;
if (msg->len < 8) {
ret = mxs_i2c_pio_setup_xfer(adap, msg, flags);
if (ret)
mxs_i2c_reset(i2c);
} else {
INIT_COMPLETION(i2c->cmd_complete);
ret = mxs_i2c_dma_setup_xfer(adap, msg, flags);
if (ret)
return ret;
ret = wait_for_completion_timeout(&i2c->cmd_complete,
msecs_to_jiffies(1000));
if (ret == 0)
goto timeout;
}
if (i2c->cmd_err == -ENXIO) {
writel(MXS_I2C_CTRL1_CLR_GOT_A_NAK,
i2c->regs + MXS_I2C_CTRL1_SET);
}
ret = i2c->cmd_err;
dev_dbg(i2c->dev, "Done with err=%d\n", ret);
return ret;
timeout:
dev_dbg(i2c->dev, "Timeout!\n");
mxs_i2c_dma_finish(i2c);
mxs_i2c_reset(i2c);
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
static void mxs_i2c_derive_timing(struct mxs_i2c_dev *i2c, int speed)
{
const uint32_t clk = 24000000;
uint32_t base;
uint16_t high_count, low_count, rcv_count, xmit_count;
struct device *dev = i2c->dev;
if (speed > 540000) {
dev_warn(dev, "Speed too high (%d Hz), using 540 kHz\n", speed);
speed = 540000;
} else if (speed < 12000) {
dev_warn(dev, "Speed too low (%d Hz), using 12 kHz\n", speed);
speed = 12000;
}
base = ((clk / speed) - 38) / 2;
high_count = base + 3;
low_count = base - 3;
rcv_count = (high_count * 3) / 4;
xmit_count = low_count / 4;
i2c->timing0 = (high_count << 16) | rcv_count;
i2c->timing1 = (low_count << 16) | xmit_count;
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
struct device *dev = &pdev->dev;
struct mxs_i2c_dev *i2c;
struct i2c_adapter *adap;
struct pinctrl *pinctrl;
struct resource *res;
resource_size_t res_size;
int err, irq;
pinctrl = devm_pinctrl_get_select_default(dev);
if (IS_ERR(pinctrl))
return PTR_ERR(pinctrl);
i2c = devm_kzalloc(dev, sizeof(struct mxs_i2c_dev), GFP_KERNEL);
if (!i2c)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (!res || irq < 0)
return -ENOENT;
res_size = resource_size(res);
if (!devm_request_mem_region(dev, res->start, res_size, res->name))
return -EBUSY;
i2c->regs = devm_ioremap_nocache(dev, res->start, res_size);
if (!i2c->regs)
return -EBUSY;
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
mxs_i2c_reset(i2c);
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
dev_err(dev, "Failed to add adapter (%d)\n", err);
writel(MXS_I2C_CTRL0_SFTRST,
i2c->regs + MXS_I2C_CTRL0_SET);
return err;
}
of_i2c_register_devices(adap);
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
return platform_driver_probe(&mxs_i2c_driver, mxs_i2c_probe);
}
static void __exit mxs_i2c_exit(void)
{
platform_driver_unregister(&mxs_i2c_driver);
}
