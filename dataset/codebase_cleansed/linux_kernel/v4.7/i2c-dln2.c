static int dln2_i2c_enable(struct dln2_i2c *dln2, bool enable)
{
u16 cmd;
struct {
u8 port;
} tx;
tx.port = dln2->port;
if (enable)
cmd = DLN2_I2C_ENABLE;
else
cmd = DLN2_I2C_DISABLE;
return dln2_transfer_tx(dln2->pdev, cmd, &tx, sizeof(tx));
}
static int dln2_i2c_write(struct dln2_i2c *dln2, u8 addr,
u8 *data, u16 data_len)
{
int ret;
struct {
u8 port;
u8 addr;
u8 mem_addr_len;
__le32 mem_addr;
__le16 buf_len;
u8 buf[DLN2_I2C_MAX_XFER_SIZE];
} __packed *tx = dln2->buf;
unsigned len;
BUILD_BUG_ON(sizeof(*tx) > DLN2_I2C_BUF_SIZE);
tx->port = dln2->port;
tx->addr = addr;
tx->mem_addr_len = 0;
tx->mem_addr = 0;
tx->buf_len = cpu_to_le16(data_len);
memcpy(tx->buf, data, data_len);
len = sizeof(*tx) + data_len - DLN2_I2C_MAX_XFER_SIZE;
ret = dln2_transfer_tx(dln2->pdev, DLN2_I2C_WRITE, tx, len);
if (ret < 0)
return ret;
return data_len;
}
static int dln2_i2c_read(struct dln2_i2c *dln2, u16 addr, u8 *data,
u16 data_len)
{
int ret;
struct {
u8 port;
u8 addr;
u8 mem_addr_len;
__le32 mem_addr;
__le16 buf_len;
} __packed tx;
struct {
__le16 buf_len;
u8 buf[DLN2_I2C_MAX_XFER_SIZE];
} __packed *rx = dln2->buf;
unsigned rx_len = sizeof(*rx);
BUILD_BUG_ON(sizeof(*rx) > DLN2_I2C_BUF_SIZE);
tx.port = dln2->port;
tx.addr = addr;
tx.mem_addr_len = 0;
tx.mem_addr = 0;
tx.buf_len = cpu_to_le16(data_len);
ret = dln2_transfer(dln2->pdev, DLN2_I2C_READ, &tx, sizeof(tx),
rx, &rx_len);
if (ret < 0)
return ret;
if (rx_len < sizeof(rx->buf_len) + data_len)
return -EPROTO;
if (le16_to_cpu(rx->buf_len) != data_len)
return -EPROTO;
memcpy(data, rx->buf, data_len);
return data_len;
}
static int dln2_i2c_xfer(struct i2c_adapter *adapter,
struct i2c_msg *msgs, int num)
{
struct dln2_i2c *dln2 = i2c_get_adapdata(adapter);
struct i2c_msg *pmsg;
int i;
for (i = 0; i < num; i++) {
int ret;
pmsg = &msgs[i];
if (pmsg->flags & I2C_M_RD) {
ret = dln2_i2c_read(dln2, pmsg->addr, pmsg->buf,
pmsg->len);
if (ret < 0)
return ret;
pmsg->len = ret;
} else {
ret = dln2_i2c_write(dln2, pmsg->addr, pmsg->buf,
pmsg->len);
if (ret != pmsg->len)
return -EPROTO;
}
}
return num;
}
static u32 dln2_i2c_func(struct i2c_adapter *a)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_BYTE | I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA | I2C_FUNC_SMBUS_BLOCK_PROC_CALL |
I2C_FUNC_SMBUS_I2C_BLOCK;
}
static int dln2_i2c_probe(struct platform_device *pdev)
{
int ret;
struct dln2_i2c *dln2;
struct device *dev = &pdev->dev;
struct dln2_platform_data *pdata = dev_get_platdata(&pdev->dev);
dln2 = devm_kzalloc(dev, sizeof(*dln2), GFP_KERNEL);
if (!dln2)
return -ENOMEM;
dln2->buf = devm_kmalloc(dev, DLN2_I2C_BUF_SIZE, GFP_KERNEL);
if (!dln2->buf)
return -ENOMEM;
dln2->pdev = pdev;
dln2->port = pdata->port;
dln2->adapter.owner = THIS_MODULE;
dln2->adapter.class = I2C_CLASS_HWMON;
dln2->adapter.algo = &dln2_i2c_usb_algorithm;
dln2->adapter.quirks = &dln2_i2c_quirks;
dln2->adapter.dev.parent = dev;
ACPI_COMPANION_SET(&dln2->adapter.dev, ACPI_COMPANION(&pdev->dev));
dln2->adapter.dev.of_node = dev->of_node;
i2c_set_adapdata(&dln2->adapter, dln2);
snprintf(dln2->adapter.name, sizeof(dln2->adapter.name), "%s-%s-%d",
"dln2-i2c", dev_name(pdev->dev.parent), dln2->port);
platform_set_drvdata(pdev, dln2);
ret = dln2_i2c_enable(dln2, true);
if (ret < 0) {
dev_err(dev, "failed to initialize adapter: %d\n", ret);
return ret;
}
ret = i2c_add_adapter(&dln2->adapter);
if (ret < 0) {
dev_err(dev, "failed to add I2C adapter: %d\n", ret);
goto out_disable;
}
return 0;
out_disable:
dln2_i2c_enable(dln2, false);
return ret;
}
static int dln2_i2c_remove(struct platform_device *pdev)
{
struct dln2_i2c *dln2 = platform_get_drvdata(pdev);
i2c_del_adapter(&dln2->adapter);
dln2_i2c_enable(dln2, false);
return 0;
}
