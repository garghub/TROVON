static unsigned at91_twi_read(struct at91_twi_dev *dev, unsigned reg)
{
return readl_relaxed(dev->base + reg);
}
static void at91_twi_write(struct at91_twi_dev *dev, unsigned reg, unsigned val)
{
writel_relaxed(val, dev->base + reg);
}
static void at91_disable_twi_interrupts(struct at91_twi_dev *dev)
{
at91_twi_write(dev, AT91_TWI_IDR,
AT91_TWI_TXCOMP | AT91_TWI_RXRDY | AT91_TWI_TXRDY);
}
static void at91_twi_irq_save(struct at91_twi_dev *dev)
{
dev->imr = at91_twi_read(dev, AT91_TWI_IMR) & 0x7;
at91_disable_twi_interrupts(dev);
}
static void at91_twi_irq_restore(struct at91_twi_dev *dev)
{
at91_twi_write(dev, AT91_TWI_IER, dev->imr);
}
static void at91_init_twi_bus(struct at91_twi_dev *dev)
{
at91_disable_twi_interrupts(dev);
at91_twi_write(dev, AT91_TWI_CR, AT91_TWI_SWRST);
at91_twi_write(dev, AT91_TWI_CR, AT91_TWI_MSEN);
at91_twi_write(dev, AT91_TWI_CR, AT91_TWI_SVDIS);
at91_twi_write(dev, AT91_TWI_CWGR, dev->twi_cwgr_reg);
}
static void at91_calc_twi_clock(struct at91_twi_dev *dev, int twi_clk)
{
int ckdiv, cdiv, div;
struct at91_twi_pdata *pdata = dev->pdata;
int offset = pdata->clk_offset;
int max_ckdiv = pdata->clk_max_div;
div = max(0, (int)DIV_ROUND_UP(clk_get_rate(dev->clk),
2 * twi_clk) - offset);
ckdiv = fls(div >> 8);
cdiv = div >> ckdiv;
if (ckdiv > max_ckdiv) {
dev_warn(dev->dev, "%d exceeds ckdiv max value which is %d.\n",
ckdiv, max_ckdiv);
ckdiv = max_ckdiv;
cdiv = 255;
}
dev->twi_cwgr_reg = (ckdiv << 16) | (cdiv << 8) | cdiv;
dev_dbg(dev->dev, "cdiv %d ckdiv %d\n", cdiv, ckdiv);
}
static void at91_twi_dma_cleanup(struct at91_twi_dev *dev)
{
struct at91_twi_dma *dma = &dev->dma;
at91_twi_irq_save(dev);
if (dma->xfer_in_progress) {
if (dma->direction == DMA_FROM_DEVICE)
dmaengine_terminate_all(dma->chan_rx);
else
dmaengine_terminate_all(dma->chan_tx);
dma->xfer_in_progress = false;
}
if (dma->buf_mapped) {
dma_unmap_single(dev->dev, sg_dma_address(&dma->sg),
dev->buf_len, dma->direction);
dma->buf_mapped = false;
}
at91_twi_irq_restore(dev);
}
static void at91_twi_write_next_byte(struct at91_twi_dev *dev)
{
if (dev->buf_len <= 0)
return;
at91_twi_write(dev, AT91_TWI_THR, *dev->buf);
if (--dev->buf_len == 0)
at91_twi_write(dev, AT91_TWI_CR, AT91_TWI_STOP);
dev_dbg(dev->dev, "wrote 0x%x, to go %d\n", *dev->buf, dev->buf_len);
++dev->buf;
}
static void at91_twi_write_data_dma_callback(void *data)
{
struct at91_twi_dev *dev = (struct at91_twi_dev *)data;
dma_unmap_single(dev->dev, sg_dma_address(&dev->dma.sg),
dev->buf_len, DMA_TO_DEVICE);
at91_twi_write(dev, AT91_TWI_CR, AT91_TWI_STOP);
}
static void at91_twi_write_data_dma(struct at91_twi_dev *dev)
{
dma_addr_t dma_addr;
struct dma_async_tx_descriptor *txdesc;
struct at91_twi_dma *dma = &dev->dma;
struct dma_chan *chan_tx = dma->chan_tx;
if (dev->buf_len <= 0)
return;
dma->direction = DMA_TO_DEVICE;
at91_twi_irq_save(dev);
dma_addr = dma_map_single(dev->dev, dev->buf, dev->buf_len,
DMA_TO_DEVICE);
if (dma_mapping_error(dev->dev, dma_addr)) {
dev_err(dev->dev, "dma map failed\n");
return;
}
dma->buf_mapped = true;
at91_twi_irq_restore(dev);
sg_dma_len(&dma->sg) = dev->buf_len;
sg_dma_address(&dma->sg) = dma_addr;
txdesc = dmaengine_prep_slave_sg(chan_tx, &dma->sg, 1, DMA_MEM_TO_DEV,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!txdesc) {
dev_err(dev->dev, "dma prep slave sg failed\n");
goto error;
}
txdesc->callback = at91_twi_write_data_dma_callback;
txdesc->callback_param = dev;
dma->xfer_in_progress = true;
dmaengine_submit(txdesc);
dma_async_issue_pending(chan_tx);
return;
error:
at91_twi_dma_cleanup(dev);
}
static void at91_twi_read_next_byte(struct at91_twi_dev *dev)
{
if (dev->buf_len <= 0)
return;
*dev->buf = at91_twi_read(dev, AT91_TWI_RHR) & 0xff;
--dev->buf_len;
if (dev->recv_len_abort)
return;
if (unlikely(dev->msg->flags & I2C_M_RECV_LEN)) {
if (*dev->buf <= I2C_SMBUS_BLOCK_MAX && *dev->buf > 0) {
dev->msg->flags &= ~I2C_M_RECV_LEN;
dev->buf_len += *dev->buf;
dev->msg->len = dev->buf_len + 1;
dev_dbg(dev->dev, "received block length %d\n",
dev->buf_len);
} else {
dev->recv_len_abort = true;
dev->buf_len = 1;
}
}
if (dev->buf_len == 1)
at91_twi_write(dev, AT91_TWI_CR, AT91_TWI_STOP);
dev_dbg(dev->dev, "read 0x%x, to go %d\n", *dev->buf, dev->buf_len);
++dev->buf;
}
static void at91_twi_read_data_dma_callback(void *data)
{
struct at91_twi_dev *dev = (struct at91_twi_dev *)data;
dma_unmap_single(dev->dev, sg_dma_address(&dev->dma.sg),
dev->buf_len, DMA_FROM_DEVICE);
dev->buf += dev->buf_len - 2;
dev->buf_len = 2;
at91_twi_write(dev, AT91_TWI_IER, AT91_TWI_RXRDY);
}
static void at91_twi_read_data_dma(struct at91_twi_dev *dev)
{
dma_addr_t dma_addr;
struct dma_async_tx_descriptor *rxdesc;
struct at91_twi_dma *dma = &dev->dma;
struct dma_chan *chan_rx = dma->chan_rx;
dma->direction = DMA_FROM_DEVICE;
at91_twi_irq_save(dev);
dma_addr = dma_map_single(dev->dev, dev->buf, dev->buf_len - 2,
DMA_FROM_DEVICE);
if (dma_mapping_error(dev->dev, dma_addr)) {
dev_err(dev->dev, "dma map failed\n");
return;
}
dma->buf_mapped = true;
at91_twi_irq_restore(dev);
dma->sg.dma_address = dma_addr;
sg_dma_len(&dma->sg) = dev->buf_len - 2;
rxdesc = dmaengine_prep_slave_sg(chan_rx, &dma->sg, 1, DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!rxdesc) {
dev_err(dev->dev, "dma prep slave sg failed\n");
goto error;
}
rxdesc->callback = at91_twi_read_data_dma_callback;
rxdesc->callback_param = dev;
dma->xfer_in_progress = true;
dmaengine_submit(rxdesc);
dma_async_issue_pending(dma->chan_rx);
return;
error:
at91_twi_dma_cleanup(dev);
}
static irqreturn_t atmel_twi_interrupt(int irq, void *dev_id)
{
struct at91_twi_dev *dev = dev_id;
const unsigned status = at91_twi_read(dev, AT91_TWI_SR);
const unsigned irqstatus = status & at91_twi_read(dev, AT91_TWI_IMR);
if (!irqstatus)
return IRQ_NONE;
else if (irqstatus & AT91_TWI_RXRDY)
at91_twi_read_next_byte(dev);
else if (irqstatus & AT91_TWI_TXRDY)
at91_twi_write_next_byte(dev);
dev->transfer_status |= status;
if (irqstatus & AT91_TWI_TXCOMP) {
at91_disable_twi_interrupts(dev);
complete(&dev->cmd_complete);
}
return IRQ_HANDLED;
}
static int at91_do_twi_transfer(struct at91_twi_dev *dev)
{
int ret;
bool has_unre_flag = dev->pdata->has_unre_flag;
dev_dbg(dev->dev, "transfer: %s %d bytes.\n",
(dev->msg->flags & I2C_M_RD) ? "read" : "write", dev->buf_len);
reinit_completion(&dev->cmd_complete);
dev->transfer_status = 0;
if (!dev->buf_len) {
at91_twi_write(dev, AT91_TWI_CR, AT91_TWI_QUICK);
at91_twi_write(dev, AT91_TWI_IER, AT91_TWI_TXCOMP);
} else if (dev->msg->flags & I2C_M_RD) {
unsigned start_flags = AT91_TWI_START;
if (at91_twi_read(dev, AT91_TWI_SR) & AT91_TWI_RXRDY) {
dev_err(dev->dev, "RXRDY still set!");
at91_twi_read(dev, AT91_TWI_RHR);
}
if (dev->buf_len <= 1 && !(dev->msg->flags & I2C_M_RECV_LEN))
start_flags |= AT91_TWI_STOP;
at91_twi_write(dev, AT91_TWI_CR, start_flags);
if (dev->use_dma && (dev->buf_len > AT91_I2C_DMA_THRESHOLD)) {
at91_twi_read_data_dma(dev);
at91_twi_write(dev, AT91_TWI_IER,
AT91_TWI_TXCOMP);
} else
at91_twi_write(dev, AT91_TWI_IER,
AT91_TWI_TXCOMP | AT91_TWI_RXRDY);
} else {
if (dev->use_dma && (dev->buf_len > AT91_I2C_DMA_THRESHOLD)) {
at91_twi_write_data_dma(dev);
at91_twi_write(dev, AT91_TWI_IER, AT91_TWI_TXCOMP);
} else {
at91_twi_write_next_byte(dev);
at91_twi_write(dev, AT91_TWI_IER,
AT91_TWI_TXCOMP | AT91_TWI_TXRDY);
}
}
ret = wait_for_completion_timeout(&dev->cmd_complete,
dev->adapter.timeout);
if (ret == 0) {
dev_err(dev->dev, "controller timed out\n");
at91_init_twi_bus(dev);
ret = -ETIMEDOUT;
goto error;
}
if (dev->transfer_status & AT91_TWI_NACK) {
dev_dbg(dev->dev, "received nack\n");
ret = -EREMOTEIO;
goto error;
}
if (dev->transfer_status & AT91_TWI_OVRE) {
dev_err(dev->dev, "overrun while reading\n");
ret = -EIO;
goto error;
}
if (has_unre_flag && dev->transfer_status & AT91_TWI_UNRE) {
dev_err(dev->dev, "underrun while writing\n");
ret = -EIO;
goto error;
}
if (dev->recv_len_abort) {
dev_err(dev->dev, "invalid smbus block length recvd\n");
ret = -EPROTO;
goto error;
}
dev_dbg(dev->dev, "transfer complete\n");
return 0;
error:
at91_twi_dma_cleanup(dev);
return ret;
}
static int at91_twi_xfer(struct i2c_adapter *adap, struct i2c_msg *msg, int num)
{
struct at91_twi_dev *dev = i2c_get_adapdata(adap);
int ret;
unsigned int_addr_flag = 0;
struct i2c_msg *m_start = msg;
dev_dbg(&adap->dev, "at91_xfer: processing %d messages:\n", num);
if (num > 2) {
dev_err(dev->dev,
"cannot handle more than two concatenated messages.\n");
return 0;
} else if (num == 2) {
int internal_address = 0;
int i;
if (msg->flags & I2C_M_RD) {
dev_err(dev->dev, "first transfer must be write.\n");
return -EINVAL;
}
if (msg->len > 3) {
dev_err(dev->dev, "first message size must be <= 3.\n");
return -EINVAL;
}
m_start = &msg[1];
for (i = 0; i < msg->len; ++i) {
const unsigned addr = msg->buf[msg->len - 1 - i];
internal_address |= addr << (8 * i);
int_addr_flag += AT91_TWI_IADRSZ_1;
}
at91_twi_write(dev, AT91_TWI_IADR, internal_address);
}
at91_twi_write(dev, AT91_TWI_MMR, (m_start->addr << 16) | int_addr_flag
| ((m_start->flags & I2C_M_RD) ? AT91_TWI_MREAD : 0));
dev->buf_len = m_start->len;
dev->buf = m_start->buf;
dev->msg = m_start;
dev->recv_len_abort = false;
ret = at91_do_twi_transfer(dev);
return (ret < 0) ? ret : num;
}
static u32 at91_twi_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL
| I2C_FUNC_SMBUS_READ_BLOCK_DATA;
}
static bool filter(struct dma_chan *chan, void *pdata)
{
struct at91_twi_pdata *sl_pdata = pdata;
struct at_dma_slave *sl;
if (!sl_pdata)
return false;
sl = &sl_pdata->dma_slave;
if (sl && (sl->dma_dev == chan->device->dev)) {
chan->private = sl;
return true;
} else {
return false;
}
}
static int at91_twi_configure_dma(struct at91_twi_dev *dev, u32 phy_addr)
{
int ret = 0;
struct at91_twi_pdata *pdata = dev->pdata;
struct dma_slave_config slave_config;
struct at91_twi_dma *dma = &dev->dma;
dma_cap_mask_t mask;
memset(&slave_config, 0, sizeof(slave_config));
slave_config.src_addr = (dma_addr_t)phy_addr + AT91_TWI_RHR;
slave_config.src_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
slave_config.src_maxburst = 1;
slave_config.dst_addr = (dma_addr_t)phy_addr + AT91_TWI_THR;
slave_config.dst_addr_width = DMA_SLAVE_BUSWIDTH_1_BYTE;
slave_config.dst_maxburst = 1;
slave_config.device_fc = false;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
dma->chan_tx = dma_request_slave_channel_compat(mask, filter, pdata,
dev->dev, "tx");
if (!dma->chan_tx) {
dev_err(dev->dev, "can't get a DMA channel for tx\n");
ret = -EBUSY;
goto error;
}
dma->chan_rx = dma_request_slave_channel_compat(mask, filter, pdata,
dev->dev, "rx");
if (!dma->chan_rx) {
dev_err(dev->dev, "can't get a DMA channel for rx\n");
ret = -EBUSY;
goto error;
}
slave_config.direction = DMA_MEM_TO_DEV;
if (dmaengine_slave_config(dma->chan_tx, &slave_config)) {
dev_err(dev->dev, "failed to configure tx channel\n");
ret = -EINVAL;
goto error;
}
slave_config.direction = DMA_DEV_TO_MEM;
if (dmaengine_slave_config(dma->chan_rx, &slave_config)) {
dev_err(dev->dev, "failed to configure rx channel\n");
ret = -EINVAL;
goto error;
}
sg_init_table(&dma->sg, 1);
dma->buf_mapped = false;
dma->xfer_in_progress = false;
dev_info(dev->dev, "using %s (tx) and %s (rx) for DMA transfers\n",
dma_chan_name(dma->chan_tx), dma_chan_name(dma->chan_rx));
return ret;
error:
dev_info(dev->dev, "can't use DMA\n");
if (dma->chan_rx)
dma_release_channel(dma->chan_rx);
if (dma->chan_tx)
dma_release_channel(dma->chan_tx);
return ret;
}
static struct at91_twi_pdata *at91_twi_get_driver_data(
struct platform_device *pdev)
{
if (pdev->dev.of_node) {
const struct of_device_id *match;
match = of_match_node(atmel_twi_dt_ids, pdev->dev.of_node);
if (!match)
return NULL;
return (struct at91_twi_pdata *)match->data;
}
return (struct at91_twi_pdata *) platform_get_device_id(pdev)->driver_data;
}
static int at91_twi_probe(struct platform_device *pdev)
{
struct at91_twi_dev *dev;
struct resource *mem;
int rc;
u32 phy_addr;
u32 bus_clk_rate;
dev = devm_kzalloc(&pdev->dev, sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
init_completion(&dev->cmd_complete);
dev->dev = &pdev->dev;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem)
return -ENODEV;
phy_addr = mem->start;
dev->pdata = at91_twi_get_driver_data(pdev);
if (!dev->pdata)
return -ENODEV;
dev->base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(dev->base))
return PTR_ERR(dev->base);
dev->irq = platform_get_irq(pdev, 0);
if (dev->irq < 0)
return dev->irq;
rc = devm_request_irq(&pdev->dev, dev->irq, atmel_twi_interrupt, 0,
dev_name(dev->dev), dev);
if (rc) {
dev_err(dev->dev, "Cannot get irq %d: %d\n", dev->irq, rc);
return rc;
}
platform_set_drvdata(pdev, dev);
dev->clk = devm_clk_get(dev->dev, NULL);
if (IS_ERR(dev->clk)) {
dev_err(dev->dev, "no clock defined\n");
return -ENODEV;
}
clk_prepare_enable(dev->clk);
if (dev->pdata->has_dma_support) {
if (at91_twi_configure_dma(dev, phy_addr) == 0)
dev->use_dma = true;
}
rc = of_property_read_u32(dev->dev->of_node, "clock-frequency",
&bus_clk_rate);
if (rc)
bus_clk_rate = DEFAULT_TWI_CLK_HZ;
at91_calc_twi_clock(dev, bus_clk_rate);
at91_init_twi_bus(dev);
snprintf(dev->adapter.name, sizeof(dev->adapter.name), "AT91");
i2c_set_adapdata(&dev->adapter, dev);
dev->adapter.owner = THIS_MODULE;
dev->adapter.class = I2C_CLASS_DEPRECATED;
dev->adapter.algo = &at91_twi_algorithm;
dev->adapter.dev.parent = dev->dev;
dev->adapter.nr = pdev->id;
dev->adapter.timeout = AT91_I2C_TIMEOUT;
dev->adapter.dev.of_node = pdev->dev.of_node;
rc = i2c_add_numbered_adapter(&dev->adapter);
if (rc) {
dev_err(dev->dev, "Adapter %s registration failed\n",
dev->adapter.name);
clk_disable_unprepare(dev->clk);
return rc;
}
dev_info(dev->dev, "AT91 i2c bus driver.\n");
return 0;
}
static int at91_twi_remove(struct platform_device *pdev)
{
struct at91_twi_dev *dev = platform_get_drvdata(pdev);
i2c_del_adapter(&dev->adapter);
clk_disable_unprepare(dev->clk);
return 0;
}
static int at91_twi_runtime_suspend(struct device *dev)
{
struct at91_twi_dev *twi_dev = dev_get_drvdata(dev);
clk_disable(twi_dev->clk);
return 0;
}
static int at91_twi_runtime_resume(struct device *dev)
{
struct at91_twi_dev *twi_dev = dev_get_drvdata(dev);
return clk_enable(twi_dev->clk);
}
static int __init at91_twi_init(void)
{
return platform_driver_register(&at91_twi_driver);
}
static void __exit at91_twi_exit(void)
{
platform_driver_unregister(&at91_twi_driver);
}
