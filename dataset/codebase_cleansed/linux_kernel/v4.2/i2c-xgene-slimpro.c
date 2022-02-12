static void slimpro_i2c_rx_cb(struct mbox_client *cl, void *mssg)
{
struct slimpro_i2c_dev *ctx = to_slimpro_i2c_dev(cl);
if (ctx->resp_msg)
*ctx->resp_msg = ((u32 *)mssg)[1];
if (ctx->mbox_client.tx_block)
complete(&ctx->rd_complete);
}
static int start_i2c_msg_xfer(struct slimpro_i2c_dev *ctx)
{
if (ctx->mbox_client.tx_block) {
if (!wait_for_completion_timeout(&ctx->rd_complete,
msecs_to_jiffies(MAILBOX_OP_TIMEOUT)))
return -ETIMEDOUT;
}
if (*ctx->resp_msg == 0xffffffff)
return -ENODEV;
return 0;
}
static int slimpro_i2c_rd(struct slimpro_i2c_dev *ctx, u32 chip,
u32 addr, u32 addrlen, u32 protocol,
u32 readlen, u32 *data)
{
u32 msg[3];
int rc;
msg[0] = SLIMPRO_IIC_ENCODE_MSG(SLIMPRO_IIC_BUS, chip,
SLIMPRO_IIC_READ, protocol, addrlen, readlen);
msg[1] = SLIMPRO_IIC_ENCODE_ADDR(addr);
msg[2] = 0;
ctx->resp_msg = data;
rc = mbox_send_message(ctx->mbox_chan, &msg);
if (rc < 0)
goto err;
rc = start_i2c_msg_xfer(ctx);
err:
ctx->resp_msg = NULL;
return rc;
}
static int slimpro_i2c_wr(struct slimpro_i2c_dev *ctx, u32 chip,
u32 addr, u32 addrlen, u32 protocol, u32 writelen,
u32 data)
{
u32 msg[3];
int rc;
msg[0] = SLIMPRO_IIC_ENCODE_MSG(SLIMPRO_IIC_BUS, chip,
SLIMPRO_IIC_WRITE, protocol, addrlen, writelen);
msg[1] = SLIMPRO_IIC_ENCODE_ADDR(addr);
msg[2] = data;
ctx->resp_msg = msg;
rc = mbox_send_message(ctx->mbox_chan, &msg);
if (rc < 0)
goto err;
rc = start_i2c_msg_xfer(ctx);
err:
ctx->resp_msg = NULL;
return rc;
}
static int slimpro_i2c_blkrd(struct slimpro_i2c_dev *ctx, u32 chip, u32 addr,
u32 addrlen, u32 protocol, u32 readlen,
u32 with_data_len, void *data)
{
dma_addr_t paddr;
u32 msg[3];
int rc;
paddr = dma_map_single(ctx->dev, ctx->dma_buffer, readlen, DMA_FROM_DEVICE);
rc = dma_mapping_error(ctx->dev, paddr);
if (rc) {
dev_err(&ctx->adapter.dev, "Error in mapping dma buffer %p\n",
ctx->dma_buffer);
goto err;
}
msg[0] = SLIMPRO_IIC_ENCODE_MSG(SLIMPRO_IIC_BUS, chip, SLIMPRO_IIC_READ,
protocol, addrlen, readlen);
msg[1] = SLIMPRO_IIC_ENCODE_FLAG_BUFADDR |
SLIMPRO_IIC_ENCODE_FLAG_WITH_DATA_LEN(with_data_len) |
SLIMPRO_IIC_ENCODE_UPPER_BUFADDR(paddr) |
SLIMPRO_IIC_ENCODE_ADDR(addr);
msg[2] = (u32)paddr;
ctx->resp_msg = msg;
rc = mbox_send_message(ctx->mbox_chan, &msg);
if (rc < 0)
goto err_unmap;
rc = start_i2c_msg_xfer(ctx);
memcpy(data, ctx->dma_buffer, readlen);
err_unmap:
dma_unmap_single(ctx->dev, paddr, readlen, DMA_FROM_DEVICE);
err:
ctx->resp_msg = NULL;
return rc;
}
static int slimpro_i2c_blkwr(struct slimpro_i2c_dev *ctx, u32 chip,
u32 addr, u32 addrlen, u32 protocol, u32 writelen,
void *data)
{
dma_addr_t paddr;
u32 msg[3];
int rc;
memcpy(ctx->dma_buffer, data, writelen);
paddr = dma_map_single(ctx->dev, ctx->dma_buffer, writelen,
DMA_TO_DEVICE);
rc = dma_mapping_error(ctx->dev, paddr);
if (rc) {
dev_err(&ctx->adapter.dev, "Error in mapping dma buffer %p\n",
ctx->dma_buffer);
goto err;
}
msg[0] = SLIMPRO_IIC_ENCODE_MSG(SLIMPRO_IIC_BUS, chip, SLIMPRO_IIC_WRITE,
protocol, addrlen, writelen);
msg[1] = SLIMPRO_IIC_ENCODE_FLAG_BUFADDR |
SLIMPRO_IIC_ENCODE_UPPER_BUFADDR(paddr) |
SLIMPRO_IIC_ENCODE_ADDR(addr);
msg[2] = (u32)paddr;
ctx->resp_msg = msg;
if (ctx->mbox_client.tx_block)
reinit_completion(&ctx->rd_complete);
rc = mbox_send_message(ctx->mbox_chan, &msg);
if (rc < 0)
goto err_unmap;
rc = start_i2c_msg_xfer(ctx);
err_unmap:
dma_unmap_single(ctx->dev, paddr, writelen, DMA_TO_DEVICE);
err:
ctx->resp_msg = NULL;
return rc;
}
static int xgene_slimpro_i2c_xfer(struct i2c_adapter *adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size,
union i2c_smbus_data *data)
{
struct slimpro_i2c_dev *ctx = i2c_get_adapdata(adap);
int ret = -EOPNOTSUPP;
u32 val;
switch (size) {
case I2C_SMBUS_BYTE:
if (read_write == I2C_SMBUS_READ) {
ret = slimpro_i2c_rd(ctx, addr, 0, 0,
SLIMPRO_IIC_SMB_PROTOCOL,
BYTE_DATA, &val);
data->byte = val;
} else {
ret = slimpro_i2c_wr(ctx, addr, command, SMBUS_CMD_LEN,
SLIMPRO_IIC_SMB_PROTOCOL,
0, 0);
}
break;
case I2C_SMBUS_BYTE_DATA:
if (read_write == I2C_SMBUS_READ) {
ret = slimpro_i2c_rd(ctx, addr, command, SMBUS_CMD_LEN,
SLIMPRO_IIC_SMB_PROTOCOL,
BYTE_DATA, &val);
data->byte = val;
} else {
val = data->byte;
ret = slimpro_i2c_wr(ctx, addr, command, SMBUS_CMD_LEN,
SLIMPRO_IIC_SMB_PROTOCOL,
BYTE_DATA, val);
}
break;
case I2C_SMBUS_WORD_DATA:
if (read_write == I2C_SMBUS_READ) {
ret = slimpro_i2c_rd(ctx, addr, command, SMBUS_CMD_LEN,
SLIMPRO_IIC_SMB_PROTOCOL,
WORD_DATA, &val);
data->word = val;
} else {
val = data->word;
ret = slimpro_i2c_wr(ctx, addr, command, SMBUS_CMD_LEN,
SLIMPRO_IIC_SMB_PROTOCOL,
WORD_DATA, val);
}
break;
case I2C_SMBUS_BLOCK_DATA:
if (read_write == I2C_SMBUS_READ) {
ret = slimpro_i2c_blkrd(ctx, addr, command,
SMBUS_CMD_LEN,
SLIMPRO_IIC_SMB_PROTOCOL,
I2C_SMBUS_BLOCK_MAX + 1,
IIC_SMB_WITH_DATA_LEN,
&data->block[0]);
} else {
ret = slimpro_i2c_blkwr(ctx, addr, command,
SMBUS_CMD_LEN,
SLIMPRO_IIC_SMB_PROTOCOL,
data->block[0] + 1,
&data->block[0]);
}
break;
case I2C_SMBUS_I2C_BLOCK_DATA:
if (read_write == I2C_SMBUS_READ) {
ret = slimpro_i2c_blkrd(ctx, addr,
command,
SMBUS_CMD_LEN,
SLIMPRO_IIC_I2C_PROTOCOL,
I2C_SMBUS_BLOCK_MAX,
IIC_SMB_WITHOUT_DATA_LEN,
&data->block[1]);
} else {
ret = slimpro_i2c_blkwr(ctx, addr, command,
SMBUS_CMD_LEN,
SLIMPRO_IIC_I2C_PROTOCOL,
data->block[0],
&data->block[1]);
}
break;
default:
break;
}
return ret;
}
static u32 xgene_slimpro_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_SMBUS_BYTE |
I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_BLOCK_DATA |
I2C_FUNC_SMBUS_I2C_BLOCK;
}
static int xgene_slimpro_i2c_probe(struct platform_device *pdev)
{
struct slimpro_i2c_dev *ctx;
struct i2c_adapter *adapter;
struct mbox_client *cl;
int rc;
ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->dev = &pdev->dev;
platform_set_drvdata(pdev, ctx);
cl = &ctx->mbox_client;
cl->dev = &pdev->dev;
cl->rx_callback = slimpro_i2c_rx_cb;
cl->tx_block = true;
init_completion(&ctx->rd_complete);
cl->tx_tout = MAILBOX_OP_TIMEOUT;
cl->knows_txdone = false;
ctx->mbox_chan = mbox_request_channel(cl, MAILBOX_I2C_INDEX);
if (IS_ERR(ctx->mbox_chan)) {
dev_err(&pdev->dev, "i2c mailbox channel request failed\n");
return PTR_ERR(ctx->mbox_chan);
}
rc = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(64));
if (rc)
dev_warn(&pdev->dev, "Unable to set dma mask\n");
adapter = &ctx->adapter;
snprintf(adapter->name, sizeof(adapter->name), "MAILBOX I2C");
adapter->algo = &xgene_slimpro_i2c_algorithm;
adapter->class = I2C_CLASS_HWMON;
adapter->dev.parent = &pdev->dev;
i2c_set_adapdata(adapter, ctx);
rc = i2c_add_adapter(adapter);
if (rc) {
dev_err(&pdev->dev, "Adapter registeration failed\n");
mbox_free_channel(ctx->mbox_chan);
return rc;
}
dev_info(&pdev->dev, "Mailbox I2C Adapter registered\n");
return 0;
}
static int xgene_slimpro_i2c_remove(struct platform_device *pdev)
{
struct slimpro_i2c_dev *ctx = platform_get_drvdata(pdev);
i2c_del_adapter(&ctx->adapter);
mbox_free_channel(ctx->mbox_chan);
return 0;
}
