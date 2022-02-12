static int rmi_spi_manage_pools(struct rmi_spi_xport *rmi_spi, int len)
{
struct spi_device *spi = rmi_spi->spi;
int buf_size = rmi_spi->xfer_buf_size
? rmi_spi->xfer_buf_size : RMI_SPI_DEFAULT_XFER_BUF_SIZE;
struct spi_transfer *xfer_buf;
void *buf;
void *tmp;
while (buf_size < len)
buf_size *= 2;
if (buf_size > RMI_SPI_XFER_SIZE_LIMIT)
buf_size = RMI_SPI_XFER_SIZE_LIMIT;
tmp = rmi_spi->rx_buf;
buf = devm_kzalloc(&spi->dev, buf_size * 2,
GFP_KERNEL | GFP_DMA);
if (!buf)
return -ENOMEM;
rmi_spi->rx_buf = buf;
rmi_spi->tx_buf = &rmi_spi->rx_buf[buf_size];
rmi_spi->xfer_buf_size = buf_size;
if (tmp)
devm_kfree(&spi->dev, tmp);
if (rmi_spi->xport.pdata.spi_data.read_delay_us)
rmi_spi->rx_xfer_count = buf_size;
else
rmi_spi->rx_xfer_count = 1;
if (rmi_spi->xport.pdata.spi_data.write_delay_us)
rmi_spi->tx_xfer_count = buf_size;
else
rmi_spi->tx_xfer_count = 1;
tmp = rmi_spi->rx_xfers;
xfer_buf = devm_kzalloc(&spi->dev,
(rmi_spi->rx_xfer_count + rmi_spi->tx_xfer_count)
* sizeof(struct spi_transfer), GFP_KERNEL);
if (!xfer_buf)
return -ENOMEM;
rmi_spi->rx_xfers = xfer_buf;
rmi_spi->tx_xfers = &xfer_buf[rmi_spi->rx_xfer_count];
if (tmp)
devm_kfree(&spi->dev, tmp);
return 0;
}
static int rmi_spi_xfer(struct rmi_spi_xport *rmi_spi,
const struct rmi_spi_cmd *cmd, const u8 *tx_buf,
int tx_len, u8 *rx_buf, int rx_len)
{
struct spi_device *spi = rmi_spi->spi;
struct rmi_device_platform_data_spi *spi_data =
&rmi_spi->xport.pdata.spi_data;
struct spi_message msg;
struct spi_transfer *xfer;
int ret = 0;
int len;
int cmd_len = 0;
int total_tx_len;
int i;
u16 addr = cmd->addr;
spi_message_init(&msg);
switch (cmd->op) {
case RMI_SPI_WRITE:
case RMI_SPI_READ:
cmd_len += 2;
break;
case RMI_SPI_V2_READ_UNIFIED:
case RMI_SPI_V2_READ_SPLIT:
case RMI_SPI_V2_WRITE:
cmd_len += 4;
break;
}
total_tx_len = cmd_len + tx_len;
len = max(total_tx_len, rx_len);
if (len > RMI_SPI_XFER_SIZE_LIMIT)
return -EINVAL;
if (rmi_spi->xfer_buf_size < len)
rmi_spi_manage_pools(rmi_spi, len);
if (addr == 0)
addr = 0x7FF;
switch (cmd->op) {
case RMI_SPI_WRITE:
rmi_spi->tx_buf[0] = (addr >> 8);
rmi_spi->tx_buf[1] = addr & 0xFF;
break;
case RMI_SPI_READ:
rmi_spi->tx_buf[0] = (addr >> 8) | 0x80;
rmi_spi->tx_buf[1] = addr & 0xFF;
break;
case RMI_SPI_V2_READ_UNIFIED:
break;
case RMI_SPI_V2_READ_SPLIT:
break;
case RMI_SPI_V2_WRITE:
rmi_spi->tx_buf[0] = 0x40;
rmi_spi->tx_buf[1] = (addr >> 8) & 0xFF;
rmi_spi->tx_buf[2] = addr & 0xFF;
rmi_spi->tx_buf[3] = tx_len;
break;
}
if (tx_buf)
memcpy(&rmi_spi->tx_buf[cmd_len], tx_buf, tx_len);
if (rmi_spi->tx_xfer_count > 1) {
for (i = 0; i < total_tx_len; i++) {
xfer = &rmi_spi->tx_xfers[i];
memset(xfer, 0, sizeof(struct spi_transfer));
xfer->tx_buf = &rmi_spi->tx_buf[i];
xfer->len = 1;
xfer->delay_usecs = spi_data->write_delay_us;
spi_message_add_tail(xfer, &msg);
}
} else {
xfer = rmi_spi->tx_xfers;
memset(xfer, 0, sizeof(struct spi_transfer));
xfer->tx_buf = rmi_spi->tx_buf;
xfer->len = total_tx_len;
spi_message_add_tail(xfer, &msg);
}
rmi_dbg(RMI_DEBUG_XPORT, &spi->dev, "%s: cmd: %s tx_buf len: %d tx_buf: %*ph\n",
__func__, cmd->op == RMI_SPI_WRITE ? "WRITE" : "READ",
total_tx_len, total_tx_len, rmi_spi->tx_buf);
if (rx_buf) {
if (rmi_spi->rx_xfer_count > 1) {
for (i = 0; i < rx_len; i++) {
xfer = &rmi_spi->rx_xfers[i];
memset(xfer, 0, sizeof(struct spi_transfer));
xfer->rx_buf = &rmi_spi->rx_buf[i];
xfer->len = 1;
xfer->delay_usecs = spi_data->read_delay_us;
spi_message_add_tail(xfer, &msg);
}
} else {
xfer = rmi_spi->rx_xfers;
memset(xfer, 0, sizeof(struct spi_transfer));
xfer->rx_buf = rmi_spi->rx_buf;
xfer->len = rx_len;
spi_message_add_tail(xfer, &msg);
}
}
ret = spi_sync(spi, &msg);
if (ret < 0) {
dev_err(&spi->dev, "spi xfer failed: %d\n", ret);
return ret;
}
if (rx_buf) {
memcpy(rx_buf, rmi_spi->rx_buf, rx_len);
rmi_dbg(RMI_DEBUG_XPORT, &spi->dev, "%s: (%d) %*ph\n",
__func__, rx_len, rx_len, rx_buf);
}
return 0;
}
static int rmi_set_page(struct rmi_spi_xport *rmi_spi, u8 page)
{
struct rmi_spi_cmd cmd;
int ret;
cmd.op = RMI_SPI_WRITE;
cmd.addr = RMI_PAGE_SELECT_REGISTER;
ret = rmi_spi_xfer(rmi_spi, &cmd, &page, 1, NULL, 0);
if (ret)
rmi_spi->page = page;
return ret;
}
static int rmi_spi_write_block(struct rmi_transport_dev *xport, u16 addr,
const void *buf, size_t len)
{
struct rmi_spi_xport *rmi_spi =
container_of(xport, struct rmi_spi_xport, xport);
struct rmi_spi_cmd cmd;
int ret;
mutex_lock(&rmi_spi->page_mutex);
if (RMI_SPI_PAGE(addr) != rmi_spi->page) {
ret = rmi_set_page(rmi_spi, RMI_SPI_PAGE(addr));
if (ret)
goto exit;
}
cmd.op = RMI_SPI_WRITE;
cmd.addr = addr;
ret = rmi_spi_xfer(rmi_spi, &cmd, buf, len, NULL, 0);
exit:
mutex_unlock(&rmi_spi->page_mutex);
return ret;
}
static int rmi_spi_read_block(struct rmi_transport_dev *xport, u16 addr,
void *buf, size_t len)
{
struct rmi_spi_xport *rmi_spi =
container_of(xport, struct rmi_spi_xport, xport);
struct rmi_spi_cmd cmd;
int ret;
mutex_lock(&rmi_spi->page_mutex);
if (RMI_SPI_PAGE(addr) != rmi_spi->page) {
ret = rmi_set_page(rmi_spi, RMI_SPI_PAGE(addr));
if (ret)
goto exit;
}
cmd.op = RMI_SPI_READ;
cmd.addr = addr;
ret = rmi_spi_xfer(rmi_spi, &cmd, NULL, 0, buf, len);
exit:
mutex_unlock(&rmi_spi->page_mutex);
return ret;
}
static irqreturn_t rmi_spi_irq(int irq, void *dev_id)
{
struct rmi_spi_xport *rmi_spi = dev_id;
struct rmi_device *rmi_dev = rmi_spi->xport.rmi_dev;
int ret;
ret = rmi_process_interrupt_requests(rmi_dev);
if (ret)
rmi_dbg(RMI_DEBUG_XPORT, &rmi_dev->dev,
"Failed to process interrupt request: %d\n", ret);
return IRQ_HANDLED;
}
static int rmi_spi_init_irq(struct spi_device *spi)
{
struct rmi_spi_xport *rmi_spi = spi_get_drvdata(spi);
int irq_flags = irqd_get_trigger_type(irq_get_irq_data(rmi_spi->irq));
int ret;
if (!irq_flags)
irq_flags = IRQF_TRIGGER_LOW;
ret = devm_request_threaded_irq(&spi->dev, rmi_spi->irq, NULL,
rmi_spi_irq, irq_flags | IRQF_ONESHOT,
dev_name(&spi->dev), rmi_spi);
if (ret < 0) {
dev_warn(&spi->dev, "Failed to register interrupt %d\n",
rmi_spi->irq);
return ret;
}
return 0;
}
static int rmi_spi_of_probe(struct spi_device *spi,
struct rmi_device_platform_data *pdata)
{
struct device *dev = &spi->dev;
int retval;
retval = rmi_of_property_read_u32(dev,
&pdata->spi_data.read_delay_us,
"spi-rx-delay-us", 1);
if (retval)
return retval;
retval = rmi_of_property_read_u32(dev,
&pdata->spi_data.write_delay_us,
"spi-tx-delay-us", 1);
if (retval)
return retval;
return 0;
}
static inline int rmi_spi_of_probe(struct spi_device *spi,
struct rmi_device_platform_data *pdata)
{
return -ENODEV;
}
static int rmi_spi_probe(struct spi_device *spi)
{
struct rmi_spi_xport *rmi_spi;
struct rmi_device_platform_data *pdata;
struct rmi_device_platform_data *spi_pdata = spi->dev.platform_data;
int retval;
if (spi->master->flags & SPI_MASTER_HALF_DUPLEX)
return -EINVAL;
rmi_spi = devm_kzalloc(&spi->dev, sizeof(struct rmi_spi_xport),
GFP_KERNEL);
if (!rmi_spi)
return -ENOMEM;
pdata = &rmi_spi->xport.pdata;
if (spi->dev.of_node) {
retval = rmi_spi_of_probe(spi, pdata);
if (retval)
return retval;
} else if (spi_pdata) {
*pdata = *spi_pdata;
}
if (pdata->spi_data.bits_per_word)
spi->bits_per_word = pdata->spi_data.bits_per_word;
if (pdata->spi_data.mode)
spi->mode = pdata->spi_data.mode;
retval = spi_setup(spi);
if (retval < 0) {
dev_err(&spi->dev, "spi_setup failed!\n");
return retval;
}
if (spi->irq > 0)
rmi_spi->irq = spi->irq;
rmi_spi->spi = spi;
mutex_init(&rmi_spi->page_mutex);
rmi_spi->xport.dev = &spi->dev;
rmi_spi->xport.proto_name = "spi";
rmi_spi->xport.ops = &rmi_spi_ops;
spi_set_drvdata(spi, rmi_spi);
retval = rmi_spi_manage_pools(rmi_spi, RMI_SPI_DEFAULT_XFER_BUF_SIZE);
if (retval)
return retval;
retval = rmi_set_page(rmi_spi, 0);
if (retval) {
dev_err(&spi->dev, "Failed to set page select to 0.\n");
return retval;
}
retval = rmi_register_transport_device(&rmi_spi->xport);
if (retval) {
dev_err(&spi->dev, "failed to register transport.\n");
return retval;
}
retval = rmi_spi_init_irq(spi);
if (retval < 0)
return retval;
dev_info(&spi->dev, "registered RMI SPI driver\n");
return 0;
}
static int rmi_spi_remove(struct spi_device *spi)
{
struct rmi_spi_xport *rmi_spi = spi_get_drvdata(spi);
rmi_unregister_transport_device(&rmi_spi->xport);
return 0;
}
static int rmi_spi_suspend(struct device *dev)
{
struct spi_device *spi = to_spi_device(dev);
struct rmi_spi_xport *rmi_spi = spi_get_drvdata(spi);
int ret;
ret = rmi_driver_suspend(rmi_spi->xport.rmi_dev);
if (ret)
dev_warn(dev, "Failed to resume device: %d\n", ret);
disable_irq(rmi_spi->irq);
if (device_may_wakeup(&spi->dev)) {
ret = enable_irq_wake(rmi_spi->irq);
if (!ret)
dev_warn(dev, "Failed to enable irq for wake: %d\n",
ret);
}
return ret;
}
static int rmi_spi_resume(struct device *dev)
{
struct spi_device *spi = to_spi_device(dev);
struct rmi_spi_xport *rmi_spi = spi_get_drvdata(spi);
int ret;
enable_irq(rmi_spi->irq);
if (device_may_wakeup(&spi->dev)) {
ret = disable_irq_wake(rmi_spi->irq);
if (!ret)
dev_warn(dev, "Failed to disable irq for wake: %d\n",
ret);
}
ret = rmi_driver_resume(rmi_spi->xport.rmi_dev);
if (ret)
dev_warn(dev, "Failed to resume device: %d\n", ret);
return ret;
}
static int rmi_spi_runtime_suspend(struct device *dev)
{
struct spi_device *spi = to_spi_device(dev);
struct rmi_spi_xport *rmi_spi = spi_get_drvdata(spi);
int ret;
ret = rmi_driver_suspend(rmi_spi->xport.rmi_dev);
if (ret)
dev_warn(dev, "Failed to resume device: %d\n", ret);
disable_irq(rmi_spi->irq);
return 0;
}
static int rmi_spi_runtime_resume(struct device *dev)
{
struct spi_device *spi = to_spi_device(dev);
struct rmi_spi_xport *rmi_spi = spi_get_drvdata(spi);
int ret;
enable_irq(rmi_spi->irq);
ret = rmi_driver_resume(rmi_spi->xport.rmi_dev);
if (ret)
dev_warn(dev, "Failed to resume device: %d\n", ret);
return 0;
}
