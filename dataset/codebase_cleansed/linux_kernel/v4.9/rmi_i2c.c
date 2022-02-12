static int rmi_set_page(struct rmi_i2c_xport *rmi_i2c, u8 page)
{
struct i2c_client *client = rmi_i2c->client;
u8 txbuf[2] = {RMI_PAGE_SELECT_REGISTER, page};
int retval;
retval = i2c_master_send(client, txbuf, sizeof(txbuf));
if (retval != sizeof(txbuf)) {
dev_err(&client->dev,
"%s: set page failed: %d.", __func__, retval);
return (retval < 0) ? retval : -EIO;
}
rmi_i2c->page = page;
return 0;
}
static int rmi_i2c_write_block(struct rmi_transport_dev *xport, u16 addr,
const void *buf, size_t len)
{
struct rmi_i2c_xport *rmi_i2c =
container_of(xport, struct rmi_i2c_xport, xport);
struct i2c_client *client = rmi_i2c->client;
size_t tx_size = len + 1;
int retval;
mutex_lock(&rmi_i2c->page_mutex);
if (!rmi_i2c->tx_buf || rmi_i2c->tx_buf_size < tx_size) {
if (rmi_i2c->tx_buf)
devm_kfree(&client->dev, rmi_i2c->tx_buf);
rmi_i2c->tx_buf_size = tx_size + BUFFER_SIZE_INCREMENT;
rmi_i2c->tx_buf = devm_kzalloc(&client->dev,
rmi_i2c->tx_buf_size,
GFP_KERNEL);
if (!rmi_i2c->tx_buf) {
rmi_i2c->tx_buf_size = 0;
retval = -ENOMEM;
goto exit;
}
}
rmi_i2c->tx_buf[0] = addr & 0xff;
memcpy(rmi_i2c->tx_buf + 1, buf, len);
if (RMI_I2C_PAGE(addr) != rmi_i2c->page) {
retval = rmi_set_page(rmi_i2c, RMI_I2C_PAGE(addr));
if (retval)
goto exit;
}
retval = i2c_master_send(client, rmi_i2c->tx_buf, tx_size);
if (retval == tx_size)
retval = 0;
else if (retval >= 0)
retval = -EIO;
exit:
rmi_dbg(RMI_DEBUG_XPORT, &client->dev,
"write %zd bytes at %#06x: %d (%*ph)\n",
len, addr, retval, (int)len, buf);
mutex_unlock(&rmi_i2c->page_mutex);
return retval;
}
static int rmi_i2c_read_block(struct rmi_transport_dev *xport, u16 addr,
void *buf, size_t len)
{
struct rmi_i2c_xport *rmi_i2c =
container_of(xport, struct rmi_i2c_xport, xport);
struct i2c_client *client = rmi_i2c->client;
u8 addr_offset = addr & 0xff;
int retval;
struct i2c_msg msgs[] = {
{
.addr = client->addr,
.len = sizeof(addr_offset),
.buf = &addr_offset,
},
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = len,
.buf = buf,
},
};
mutex_lock(&rmi_i2c->page_mutex);
if (RMI_I2C_PAGE(addr) != rmi_i2c->page) {
retval = rmi_set_page(rmi_i2c, RMI_I2C_PAGE(addr));
if (retval)
goto exit;
}
retval = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
if (retval == ARRAY_SIZE(msgs))
retval = 0;
else if (retval >= 0)
retval = -EIO;
exit:
rmi_dbg(RMI_DEBUG_XPORT, &client->dev,
"read %zd bytes at %#06x: %d (%*ph)\n",
len, addr, retval, (int)len, buf);
mutex_unlock(&rmi_i2c->page_mutex);
return retval;
}
static irqreturn_t rmi_i2c_irq(int irq, void *dev_id)
{
struct rmi_i2c_xport *rmi_i2c = dev_id;
struct rmi_device *rmi_dev = rmi_i2c->xport.rmi_dev;
int ret;
ret = rmi_process_interrupt_requests(rmi_dev);
if (ret)
rmi_dbg(RMI_DEBUG_XPORT, &rmi_dev->dev,
"Failed to process interrupt request: %d\n", ret);
return IRQ_HANDLED;
}
static int rmi_i2c_init_irq(struct i2c_client *client)
{
struct rmi_i2c_xport *rmi_i2c = i2c_get_clientdata(client);
int irq_flags = irqd_get_trigger_type(irq_get_irq_data(rmi_i2c->irq));
int ret;
if (!irq_flags)
irq_flags = IRQF_TRIGGER_LOW;
ret = devm_request_threaded_irq(&client->dev, rmi_i2c->irq, NULL,
rmi_i2c_irq, irq_flags | IRQF_ONESHOT, client->name,
rmi_i2c);
if (ret < 0) {
dev_warn(&client->dev, "Failed to register interrupt %d\n",
rmi_i2c->irq);
return ret;
}
return 0;
}
static void rmi_i2c_regulator_bulk_disable(void *data)
{
struct rmi_i2c_xport *rmi_i2c = data;
regulator_bulk_disable(ARRAY_SIZE(rmi_i2c->supplies),
rmi_i2c->supplies);
}
static void rmi_i2c_unregister_transport(void *data)
{
struct rmi_i2c_xport *rmi_i2c = data;
rmi_unregister_transport_device(&rmi_i2c->xport);
}
static int rmi_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct rmi_device_platform_data *pdata;
struct rmi_device_platform_data *client_pdata =
dev_get_platdata(&client->dev);
struct rmi_i2c_xport *rmi_i2c;
int retval;
rmi_i2c = devm_kzalloc(&client->dev, sizeof(struct rmi_i2c_xport),
GFP_KERNEL);
if (!rmi_i2c)
return -ENOMEM;
pdata = &rmi_i2c->xport.pdata;
if (!client->dev.of_node && client_pdata)
*pdata = *client_pdata;
if (client->irq > 0)
rmi_i2c->irq = client->irq;
rmi_dbg(RMI_DEBUG_XPORT, &client->dev, "Probing %s.\n",
dev_name(&client->dev));
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_err(&client->dev,
"adapter does not support required functionality.\n");
return -ENODEV;
}
rmi_i2c->supplies[0].supply = "vdd";
rmi_i2c->supplies[1].supply = "vio";
retval = devm_regulator_bulk_get(&client->dev,
ARRAY_SIZE(rmi_i2c->supplies),
rmi_i2c->supplies);
if (retval < 0)
return retval;
retval = regulator_bulk_enable(ARRAY_SIZE(rmi_i2c->supplies),
rmi_i2c->supplies);
if (retval < 0)
return retval;
retval = devm_add_action_or_reset(&client->dev,
rmi_i2c_regulator_bulk_disable,
rmi_i2c);
if (retval)
return retval;
of_property_read_u32(client->dev.of_node, "syna,startup-delay-ms",
&rmi_i2c->startup_delay);
msleep(rmi_i2c->startup_delay);
rmi_i2c->client = client;
mutex_init(&rmi_i2c->page_mutex);
rmi_i2c->xport.dev = &client->dev;
rmi_i2c->xport.proto_name = "i2c";
rmi_i2c->xport.ops = &rmi_i2c_ops;
i2c_set_clientdata(client, rmi_i2c);
retval = rmi_set_page(rmi_i2c, 0);
if (retval) {
dev_err(&client->dev, "Failed to set page select to 0.\n");
return retval;
}
retval = rmi_register_transport_device(&rmi_i2c->xport);
if (retval) {
dev_err(&client->dev, "Failed to register transport driver at 0x%.2X.\n",
client->addr);
return retval;
}
retval = devm_add_action_or_reset(&client->dev,
rmi_i2c_unregister_transport,
rmi_i2c);
if (retval)
return retval;
retval = rmi_i2c_init_irq(client);
if (retval < 0)
return retval;
dev_info(&client->dev, "registered rmi i2c driver at %#04x.\n",
client->addr);
return 0;
}
static int rmi_i2c_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct rmi_i2c_xport *rmi_i2c = i2c_get_clientdata(client);
int ret;
ret = rmi_driver_suspend(rmi_i2c->xport.rmi_dev);
if (ret)
dev_warn(dev, "Failed to resume device: %d\n", ret);
disable_irq(rmi_i2c->irq);
if (device_may_wakeup(&client->dev)) {
ret = enable_irq_wake(rmi_i2c->irq);
if (!ret)
dev_warn(dev, "Failed to enable irq for wake: %d\n",
ret);
}
regulator_bulk_disable(ARRAY_SIZE(rmi_i2c->supplies),
rmi_i2c->supplies);
return ret;
}
static int rmi_i2c_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct rmi_i2c_xport *rmi_i2c = i2c_get_clientdata(client);
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(rmi_i2c->supplies),
rmi_i2c->supplies);
if (ret)
return ret;
msleep(rmi_i2c->startup_delay);
enable_irq(rmi_i2c->irq);
if (device_may_wakeup(&client->dev)) {
ret = disable_irq_wake(rmi_i2c->irq);
if (!ret)
dev_warn(dev, "Failed to disable irq for wake: %d\n",
ret);
}
ret = rmi_driver_resume(rmi_i2c->xport.rmi_dev);
if (ret)
dev_warn(dev, "Failed to resume device: %d\n", ret);
return ret;
}
static int rmi_i2c_runtime_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct rmi_i2c_xport *rmi_i2c = i2c_get_clientdata(client);
int ret;
ret = rmi_driver_suspend(rmi_i2c->xport.rmi_dev);
if (ret)
dev_warn(dev, "Failed to resume device: %d\n", ret);
disable_irq(rmi_i2c->irq);
regulator_bulk_disable(ARRAY_SIZE(rmi_i2c->supplies),
rmi_i2c->supplies);
return 0;
}
static int rmi_i2c_runtime_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct rmi_i2c_xport *rmi_i2c = i2c_get_clientdata(client);
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(rmi_i2c->supplies),
rmi_i2c->supplies);
if (ret)
return ret;
msleep(rmi_i2c->startup_delay);
enable_irq(rmi_i2c->irq);
ret = rmi_driver_resume(rmi_i2c->xport.rmi_dev);
if (ret)
dev_warn(dev, "Failed to resume device: %d\n", ret);
return 0;
}
