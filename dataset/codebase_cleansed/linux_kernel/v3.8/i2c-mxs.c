static void mxs_i2c_reset(struct mxs_i2c_dev *i2c)
{
stmp_reset_block(i2c->regs);
writel(i2c->speed->timing0, i2c->regs + MXS_I2C_TIMING0);
writel(i2c->speed->timing1, i2c->regs + MXS_I2C_TIMING1);
writel(i2c->speed->timing2, i2c->regs + MXS_I2C_TIMING2);
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
INIT_COMPLETION(i2c->cmd_complete);
i2c->cmd_err = 0;
ret = mxs_i2c_dma_setup_xfer(adap, msg, flags);
if (ret)
return ret;
ret = wait_for_completion_timeout(&i2c->cmd_complete,
msecs_to_jiffies(1000));
if (ret == 0)
goto timeout;
if (i2c->cmd_err == -ENXIO)
mxs_i2c_reset(i2c);
dev_dbg(i2c->dev, "Done with err=%d\n", i2c->cmd_err);
return i2c->cmd_err;
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
static bool mxs_i2c_dma_filter(struct dma_chan *chan, void *param)
{
struct mxs_i2c_dev *i2c = param;
if (!mxs_dma_is_apbx(chan))
return false;
if (chan->chan_id != i2c->dma_channel)
return false;
chan->private = &i2c->dma_data;
return true;
}
static int mxs_i2c_get_ofdata(struct mxs_i2c_dev *i2c)
{
uint32_t speed;
struct device *dev = i2c->dev;
struct device_node *node = dev->of_node;
int ret;
ret = of_property_read_u32(node, "fsl,i2c-dma-channel",
&i2c->dma_channel);
if (ret) {
dev_err(dev, "Failed to get DMA channel!\n");
return -ENODEV;
}
ret = of_property_read_u32(node, "clock-frequency", &speed);
if (ret)
dev_warn(dev, "No I2C speed selected, using 100kHz\n");
else if (speed == 400000)
i2c->speed = &mxs_i2c_400kHz_config;
else if (speed != 100000)
dev_warn(dev, "Unsupported I2C speed selected, using 100kHz\n");
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
int err, irq, dmairq;
dma_cap_mask_t mask;
pinctrl = devm_pinctrl_get_select_default(dev);
if (IS_ERR(pinctrl))
return PTR_ERR(pinctrl);
i2c = devm_kzalloc(dev, sizeof(struct mxs_i2c_dev), GFP_KERNEL);
if (!i2c)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
dmairq = platform_get_irq(pdev, 1);
if (!res || irq < 0 || dmairq < 0)
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
i2c->speed = &mxs_i2c_95kHz_config;
init_completion(&i2c->cmd_complete);
if (dev->of_node) {
err = mxs_i2c_get_ofdata(i2c);
if (err)
return err;
}
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
i2c->dma_data.chan_irq = dmairq;
i2c->dmach = dma_request_channel(mask, mxs_i2c_dma_filter, i2c);
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
int ret;
ret = i2c_del_adapter(&i2c->adapter);
if (ret)
return -EBUSY;
if (i2c->dmach)
dma_release_channel(i2c->dmach);
writel(MXS_I2C_CTRL0_SFTRST, i2c->regs + MXS_I2C_CTRL0_SET);
platform_set_drvdata(pdev, NULL);
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
