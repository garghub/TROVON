static void debug_packet(struct device *dev, const char *name, u8 *ptr,
int len)
{
#ifdef DEBUG
int i;
dev_dbg(dev, "%s: ", name);
for (i = 0; i < len; i++)
pr_cont(" %02x", ptr[i]);
pr_cont("\n");
#endif
}
static int terminate_request(struct cros_ec_device *ec_dev)
{
struct cros_ec_spi *ec_spi = ec_dev->priv;
struct spi_message msg;
struct spi_transfer trans;
int ret;
spi_message_init(&msg);
memset(&trans, 0, sizeof(trans));
trans.delay_usecs = ec_spi->end_of_msg_delay;
spi_message_add_tail(&trans, &msg);
ret = spi_sync_locked(ec_spi->spi, &msg);
ec_spi->last_transfer_ns = ktime_get_ns();
if (ret < 0) {
dev_err(ec_dev->dev,
"cs-deassert spi transfer failed: %d\n",
ret);
}
return ret;
}
static int receive_n_bytes(struct cros_ec_device *ec_dev, u8 *buf, int n)
{
struct cros_ec_spi *ec_spi = ec_dev->priv;
struct spi_transfer trans;
struct spi_message msg;
int ret;
BUG_ON(buf - ec_dev->din + n > ec_dev->din_size);
memset(&trans, 0, sizeof(trans));
trans.cs_change = 1;
trans.rx_buf = buf;
trans.len = n;
spi_message_init(&msg);
spi_message_add_tail(&trans, &msg);
ret = spi_sync_locked(ec_spi->spi, &msg);
if (ret < 0)
dev_err(ec_dev->dev, "spi transfer failed: %d\n", ret);
return ret;
}
static int cros_ec_spi_receive_packet(struct cros_ec_device *ec_dev,
int need_len)
{
struct ec_host_response *response;
u8 *ptr, *end;
int ret;
unsigned long deadline;
int todo;
BUG_ON(ec_dev->din_size < EC_MSG_PREAMBLE_COUNT);
deadline = jiffies + msecs_to_jiffies(EC_MSG_DEADLINE_MS);
while (true) {
unsigned long start_jiffies = jiffies;
ret = receive_n_bytes(ec_dev,
ec_dev->din,
EC_MSG_PREAMBLE_COUNT);
if (ret < 0)
return ret;
ptr = ec_dev->din;
for (end = ptr + EC_MSG_PREAMBLE_COUNT; ptr != end; ptr++) {
if (*ptr == EC_SPI_FRAME_START) {
dev_dbg(ec_dev->dev, "msg found at %zd\n",
ptr - ec_dev->din);
break;
}
}
if (ptr != end)
break;
if (time_after(start_jiffies, deadline)) {
dev_warn(ec_dev->dev, "EC failed to respond in time\n");
return -ETIMEDOUT;
}
}
todo = end - ++ptr;
BUG_ON(todo < 0 || todo > ec_dev->din_size);
todo = min(todo, need_len);
memmove(ec_dev->din, ptr, todo);
ptr = ec_dev->din + todo;
dev_dbg(ec_dev->dev, "need %d, got %d bytes from preamble\n",
need_len, todo);
need_len -= todo;
if (todo < sizeof(*response)) {
ret = receive_n_bytes(ec_dev, ptr, sizeof(*response) - todo);
if (ret < 0)
return -EBADMSG;
ptr += (sizeof(*response) - todo);
todo = sizeof(*response);
}
response = (struct ec_host_response *)ec_dev->din;
if (response->data_len > ec_dev->din_size)
return -EMSGSIZE;
while (need_len > 0) {
todo = min(need_len, 256);
dev_dbg(ec_dev->dev, "loop, todo=%d, need_len=%d, ptr=%zd\n",
todo, need_len, ptr - ec_dev->din);
ret = receive_n_bytes(ec_dev, ptr, todo);
if (ret < 0)
return ret;
ptr += todo;
need_len -= todo;
}
dev_dbg(ec_dev->dev, "loop done, ptr=%zd\n", ptr - ec_dev->din);
return 0;
}
static int cros_ec_spi_receive_response(struct cros_ec_device *ec_dev,
int need_len)
{
u8 *ptr, *end;
int ret;
unsigned long deadline;
int todo;
BUG_ON(ec_dev->din_size < EC_MSG_PREAMBLE_COUNT);
deadline = jiffies + msecs_to_jiffies(EC_MSG_DEADLINE_MS);
while (true) {
unsigned long start_jiffies = jiffies;
ret = receive_n_bytes(ec_dev,
ec_dev->din,
EC_MSG_PREAMBLE_COUNT);
if (ret < 0)
return ret;
ptr = ec_dev->din;
for (end = ptr + EC_MSG_PREAMBLE_COUNT; ptr != end; ptr++) {
if (*ptr == EC_SPI_FRAME_START) {
dev_dbg(ec_dev->dev, "msg found at %zd\n",
ptr - ec_dev->din);
break;
}
}
if (ptr != end)
break;
if (time_after(start_jiffies, deadline)) {
dev_warn(ec_dev->dev, "EC failed to respond in time\n");
return -ETIMEDOUT;
}
}
todo = end - ++ptr;
BUG_ON(todo < 0 || todo > ec_dev->din_size);
todo = min(todo, need_len);
memmove(ec_dev->din, ptr, todo);
ptr = ec_dev->din + todo;
dev_dbg(ec_dev->dev, "need %d, got %d bytes from preamble\n",
need_len, todo);
need_len -= todo;
while (need_len > 0) {
todo = min(need_len, 256);
dev_dbg(ec_dev->dev, "loop, todo=%d, need_len=%d, ptr=%zd\n",
todo, need_len, ptr - ec_dev->din);
ret = receive_n_bytes(ec_dev, ptr, todo);
if (ret < 0)
return ret;
debug_packet(ec_dev->dev, "interim", ptr, todo);
ptr += todo;
need_len -= todo;
}
dev_dbg(ec_dev->dev, "loop done, ptr=%zd\n", ptr - ec_dev->din);
return 0;
}
static int cros_ec_pkt_xfer_spi(struct cros_ec_device *ec_dev,
struct cros_ec_command *ec_msg)
{
struct ec_host_response *response;
struct cros_ec_spi *ec_spi = ec_dev->priv;
struct spi_transfer trans, trans_delay;
struct spi_message msg;
int i, len;
u8 *ptr;
u8 *rx_buf;
u8 sum;
int ret = 0, final_ret;
len = cros_ec_prepare_tx(ec_dev, ec_msg);
dev_dbg(ec_dev->dev, "prepared, len=%d\n", len);
if (ec_spi->last_transfer_ns) {
unsigned long delay;
delay = ktime_get_ns() - ec_spi->last_transfer_ns;
if (delay < EC_SPI_RECOVERY_TIME_NS)
ndelay(EC_SPI_RECOVERY_TIME_NS - delay);
}
rx_buf = kzalloc(len, GFP_KERNEL);
if (!rx_buf)
return -ENOMEM;
spi_bus_lock(ec_spi->spi->master);
spi_message_init(&msg);
if (ec_spi->start_of_msg_delay) {
memset(&trans_delay, 0, sizeof(trans_delay));
trans_delay.delay_usecs = ec_spi->start_of_msg_delay;
spi_message_add_tail(&trans_delay, &msg);
}
memset(&trans, 0, sizeof(trans));
trans.tx_buf = ec_dev->dout;
trans.rx_buf = rx_buf;
trans.len = len;
trans.cs_change = 1;
spi_message_add_tail(&trans, &msg);
ret = spi_sync_locked(ec_spi->spi, &msg);
if (!ret) {
for (i = 0; i < len; i++) {
switch (rx_buf[i]) {
case EC_SPI_PAST_END:
case EC_SPI_RX_BAD_DATA:
case EC_SPI_NOT_READY:
ret = -EAGAIN;
ec_msg->result = EC_RES_IN_PROGRESS;
default:
break;
}
if (ret)
break;
}
if (!ret)
ret = cros_ec_spi_receive_packet(ec_dev,
ec_msg->insize + sizeof(*response));
} else {
dev_err(ec_dev->dev, "spi transfer failed: %d\n", ret);
}
final_ret = terminate_request(ec_dev);
spi_bus_unlock(ec_spi->spi->master);
if (!ret)
ret = final_ret;
if (ret < 0)
goto exit;
ptr = ec_dev->din;
response = (struct ec_host_response *)ptr;
ec_msg->result = response->result;
ret = cros_ec_check_result(ec_dev, ec_msg);
if (ret)
goto exit;
len = response->data_len;
sum = 0;
if (len > ec_msg->insize) {
dev_err(ec_dev->dev, "packet too long (%d bytes, expected %d)",
len, ec_msg->insize);
ret = -EMSGSIZE;
goto exit;
}
for (i = 0; i < sizeof(*response); i++)
sum += ptr[i];
memcpy(ec_msg->data, ptr + sizeof(*response), len);
for (i = 0; i < len; i++)
sum += ec_msg->data[i];
if (sum) {
dev_err(ec_dev->dev,
"bad packet checksum, calculated %x\n",
sum);
ret = -EBADMSG;
goto exit;
}
ret = len;
exit:
kfree(rx_buf);
if (ec_msg->command == EC_CMD_REBOOT_EC)
msleep(EC_REBOOT_DELAY_MS);
return ret;
}
static int cros_ec_cmd_xfer_spi(struct cros_ec_device *ec_dev,
struct cros_ec_command *ec_msg)
{
struct cros_ec_spi *ec_spi = ec_dev->priv;
struct spi_transfer trans;
struct spi_message msg;
int i, len;
u8 *ptr;
u8 *rx_buf;
int sum;
int ret = 0, final_ret;
len = cros_ec_prepare_tx(ec_dev, ec_msg);
dev_dbg(ec_dev->dev, "prepared, len=%d\n", len);
if (ec_spi->last_transfer_ns) {
unsigned long delay;
delay = ktime_get_ns() - ec_spi->last_transfer_ns;
if (delay < EC_SPI_RECOVERY_TIME_NS)
ndelay(EC_SPI_RECOVERY_TIME_NS - delay);
}
rx_buf = kzalloc(len, GFP_KERNEL);
if (!rx_buf)
return -ENOMEM;
spi_bus_lock(ec_spi->spi->master);
debug_packet(ec_dev->dev, "out", ec_dev->dout, len);
memset(&trans, 0, sizeof(trans));
trans.tx_buf = ec_dev->dout;
trans.rx_buf = rx_buf;
trans.len = len;
trans.cs_change = 1;
spi_message_init(&msg);
spi_message_add_tail(&trans, &msg);
ret = spi_sync_locked(ec_spi->spi, &msg);
if (!ret) {
for (i = 0; i < len; i++) {
switch (rx_buf[i]) {
case EC_SPI_PAST_END:
case EC_SPI_RX_BAD_DATA:
case EC_SPI_NOT_READY:
ret = -EAGAIN;
ec_msg->result = EC_RES_IN_PROGRESS;
default:
break;
}
if (ret)
break;
}
if (!ret)
ret = cros_ec_spi_receive_response(ec_dev,
ec_msg->insize + EC_MSG_TX_PROTO_BYTES);
} else {
dev_err(ec_dev->dev, "spi transfer failed: %d\n", ret);
}
final_ret = terminate_request(ec_dev);
spi_bus_unlock(ec_spi->spi->master);
if (!ret)
ret = final_ret;
if (ret < 0)
goto exit;
ptr = ec_dev->din;
ec_msg->result = ptr[0];
ret = cros_ec_check_result(ec_dev, ec_msg);
if (ret)
goto exit;
len = ptr[1];
sum = ptr[0] + ptr[1];
if (len > ec_msg->insize) {
dev_err(ec_dev->dev, "packet too long (%d bytes, expected %d)",
len, ec_msg->insize);
ret = -ENOSPC;
goto exit;
}
for (i = 0; i < len; i++) {
sum += ptr[i + 2];
if (ec_msg->insize)
ec_msg->data[i] = ptr[i + 2];
}
sum &= 0xff;
debug_packet(ec_dev->dev, "in", ptr, len + 3);
if (sum != ptr[len + 2]) {
dev_err(ec_dev->dev,
"bad packet checksum, expected %02x, got %02x\n",
sum, ptr[len + 2]);
ret = -EBADMSG;
goto exit;
}
ret = len;
exit:
kfree(rx_buf);
if (ec_msg->command == EC_CMD_REBOOT_EC)
msleep(EC_REBOOT_DELAY_MS);
return ret;
}
static void cros_ec_spi_dt_probe(struct cros_ec_spi *ec_spi, struct device *dev)
{
struct device_node *np = dev->of_node;
u32 val;
int ret;
ret = of_property_read_u32(np, "google,cros-ec-spi-pre-delay", &val);
if (!ret)
ec_spi->start_of_msg_delay = val;
ret = of_property_read_u32(np, "google,cros-ec-spi-msg-delay", &val);
if (!ret)
ec_spi->end_of_msg_delay = val;
}
static int cros_ec_spi_probe(struct spi_device *spi)
{
struct device *dev = &spi->dev;
struct cros_ec_device *ec_dev;
struct cros_ec_spi *ec_spi;
int err;
spi->bits_per_word = 8;
spi->mode = SPI_MODE_0;
err = spi_setup(spi);
if (err < 0)
return err;
ec_spi = devm_kzalloc(dev, sizeof(*ec_spi), GFP_KERNEL);
if (ec_spi == NULL)
return -ENOMEM;
ec_spi->spi = spi;
ec_dev = devm_kzalloc(dev, sizeof(*ec_dev), GFP_KERNEL);
if (!ec_dev)
return -ENOMEM;
cros_ec_spi_dt_probe(ec_spi, dev);
spi_set_drvdata(spi, ec_dev);
ec_dev->dev = dev;
ec_dev->priv = ec_spi;
ec_dev->irq = spi->irq;
ec_dev->cmd_xfer = cros_ec_cmd_xfer_spi;
ec_dev->pkt_xfer = cros_ec_pkt_xfer_spi;
ec_dev->phys_name = dev_name(&ec_spi->spi->dev);
ec_dev->din_size = EC_MSG_PREAMBLE_COUNT +
sizeof(struct ec_host_response) +
sizeof(struct ec_response_get_protocol_info);
ec_dev->dout_size = sizeof(struct ec_host_request);
err = cros_ec_register(ec_dev);
if (err) {
dev_err(dev, "cannot register EC\n");
return err;
}
device_init_wakeup(&spi->dev, true);
return 0;
}
static int cros_ec_spi_remove(struct spi_device *spi)
{
struct cros_ec_device *ec_dev;
ec_dev = spi_get_drvdata(spi);
cros_ec_remove(ec_dev);
return 0;
}
static int cros_ec_spi_suspend(struct device *dev)
{
struct cros_ec_device *ec_dev = dev_get_drvdata(dev);
return cros_ec_suspend(ec_dev);
}
static int cros_ec_spi_resume(struct device *dev)
{
struct cros_ec_device *ec_dev = dev_get_drvdata(dev);
return cros_ec_resume(ec_dev);
}
