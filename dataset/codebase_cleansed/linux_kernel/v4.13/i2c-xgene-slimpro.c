static u16 xgene_word_tst_and_clr(u16 *addr, u16 mask)
{
u16 ret, val;
val = le16_to_cpu(READ_ONCE(*addr));
ret = val & mask;
val &= ~mask;
WRITE_ONCE(*addr, cpu_to_le16(val));
return ret;
}
static void slimpro_i2c_rx_cb(struct mbox_client *cl, void *mssg)
{
struct slimpro_i2c_dev *ctx = to_slimpro_i2c_dev(cl);
if (ctx->resp_msg)
*ctx->resp_msg = ((u32 *)mssg)[1];
if (ctx->mbox_client.tx_block)
complete(&ctx->rd_complete);
}
static void slimpro_i2c_pcc_rx_cb(struct mbox_client *cl, void *msg)
{
struct slimpro_i2c_dev *ctx = to_slimpro_i2c_dev(cl);
struct acpi_pcct_shared_memory *generic_comm_base = ctx->pcc_comm_addr;
if (!xgene_word_tst_and_clr(&generic_comm_base->status,
PCC_STS_SCI_DOORBELL))
return;
if (xgene_word_tst_and_clr(&generic_comm_base->status,
PCC_STS_CMD_COMPLETE)) {
msg = generic_comm_base + 1;
if (ctx->resp_msg)
*ctx->resp_msg = ((u32 *)msg)[1];
complete(&ctx->rd_complete);
}
}
static void slimpro_i2c_pcc_tx_prepare(struct slimpro_i2c_dev *ctx, u32 *msg)
{
struct acpi_pcct_shared_memory *generic_comm_base = ctx->pcc_comm_addr;
u32 *ptr = (void *)(generic_comm_base + 1);
u16 status;
int i;
WRITE_ONCE(generic_comm_base->signature,
cpu_to_le32(PCC_SIGNATURE | ctx->mbox_idx));
WRITE_ONCE(generic_comm_base->command,
cpu_to_le16(SLIMPRO_MSG_TYPE(msg[0]) | PCC_CMD_GENERATE_DB_INT));
status = le16_to_cpu(READ_ONCE(generic_comm_base->status));
status &= ~PCC_STS_CMD_COMPLETE;
WRITE_ONCE(generic_comm_base->status, cpu_to_le16(status));
for (i = 0; i < SLIMPRO_IIC_MSG_DWORD_COUNT; i++)
WRITE_ONCE(ptr[i], cpu_to_le32(msg[i]));
}
static int start_i2c_msg_xfer(struct slimpro_i2c_dev *ctx)
{
if (ctx->mbox_client.tx_block || !acpi_disabled) {
if (!wait_for_completion_timeout(&ctx->rd_complete,
msecs_to_jiffies(MAILBOX_OP_TIMEOUT)))
return -ETIMEDOUT;
}
if (*ctx->resp_msg == 0xffffffff)
return -ENODEV;
return 0;
}
static int slimpro_i2c_send_msg(struct slimpro_i2c_dev *ctx,
u32 *msg,
u32 *data)
{
int rc;
ctx->resp_msg = data;
if (!acpi_disabled) {
reinit_completion(&ctx->rd_complete);
slimpro_i2c_pcc_tx_prepare(ctx, msg);
}
rc = mbox_send_message(ctx->mbox_chan, msg);
if (rc < 0)
goto err;
rc = start_i2c_msg_xfer(ctx);
err:
if (!acpi_disabled)
mbox_chan_txdone(ctx->mbox_chan, 0);
ctx->resp_msg = NULL;
return rc;
}
static int slimpro_i2c_rd(struct slimpro_i2c_dev *ctx, u32 chip,
u32 addr, u32 addrlen, u32 protocol,
u32 readlen, u32 *data)
{
u32 msg[3];
msg[0] = SLIMPRO_IIC_ENCODE_MSG(SLIMPRO_IIC_BUS, chip,
SLIMPRO_IIC_READ, protocol, addrlen, readlen);
msg[1] = SLIMPRO_IIC_ENCODE_ADDR(addr);
msg[2] = 0;
return slimpro_i2c_send_msg(ctx, msg, data);
}
static int slimpro_i2c_wr(struct slimpro_i2c_dev *ctx, u32 chip,
u32 addr, u32 addrlen, u32 protocol, u32 writelen,
u32 data)
{
u32 msg[3];
msg[0] = SLIMPRO_IIC_ENCODE_MSG(SLIMPRO_IIC_BUS, chip,
SLIMPRO_IIC_WRITE, protocol, addrlen, writelen);
msg[1] = SLIMPRO_IIC_ENCODE_ADDR(addr);
msg[2] = data;
return slimpro_i2c_send_msg(ctx, msg, msg);
}
static int slimpro_i2c_blkrd(struct slimpro_i2c_dev *ctx, u32 chip, u32 addr,
u32 addrlen, u32 protocol, u32 readlen,
u32 with_data_len, void *data)
{
dma_addr_t paddr;
u32 msg[3];
int rc;
paddr = dma_map_single(ctx->dev, ctx->dma_buffer, readlen, DMA_FROM_DEVICE);
if (dma_mapping_error(ctx->dev, paddr)) {
dev_err(&ctx->adapter.dev, "Error in mapping dma buffer %p\n",
ctx->dma_buffer);
return -ENOMEM;
}
msg[0] = SLIMPRO_IIC_ENCODE_MSG(SLIMPRO_IIC_BUS, chip, SLIMPRO_IIC_READ,
protocol, addrlen, readlen);
msg[1] = SLIMPRO_IIC_ENCODE_FLAG_BUFADDR |
SLIMPRO_IIC_ENCODE_FLAG_WITH_DATA_LEN(with_data_len) |
SLIMPRO_IIC_ENCODE_UPPER_BUFADDR(paddr) |
SLIMPRO_IIC_ENCODE_ADDR(addr);
msg[2] = (u32)paddr;
rc = slimpro_i2c_send_msg(ctx, msg, msg);
memcpy(data, ctx->dma_buffer, readlen);
dma_unmap_single(ctx->dev, paddr, readlen, DMA_FROM_DEVICE);
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
if (dma_mapping_error(ctx->dev, paddr)) {
dev_err(&ctx->adapter.dev, "Error in mapping dma buffer %p\n",
ctx->dma_buffer);
return -ENOMEM;
}
msg[0] = SLIMPRO_IIC_ENCODE_MSG(SLIMPRO_IIC_BUS, chip, SLIMPRO_IIC_WRITE,
protocol, addrlen, writelen);
msg[1] = SLIMPRO_IIC_ENCODE_FLAG_BUFADDR |
SLIMPRO_IIC_ENCODE_UPPER_BUFADDR(paddr) |
SLIMPRO_IIC_ENCODE_ADDR(addr);
msg[2] = (u32)paddr;
if (ctx->mbox_client.tx_block)
reinit_completion(&ctx->rd_complete);
rc = slimpro_i2c_send_msg(ctx, msg, msg);
dma_unmap_single(ctx->dev, paddr, writelen, DMA_TO_DEVICE);
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
init_completion(&ctx->rd_complete);
cl->tx_tout = MAILBOX_OP_TIMEOUT;
cl->knows_txdone = false;
if (acpi_disabled) {
cl->tx_block = true;
cl->rx_callback = slimpro_i2c_rx_cb;
ctx->mbox_chan = mbox_request_channel(cl, MAILBOX_I2C_INDEX);
if (IS_ERR(ctx->mbox_chan)) {
dev_err(&pdev->dev, "i2c mailbox channel request failed\n");
return PTR_ERR(ctx->mbox_chan);
}
} else {
struct acpi_pcct_hw_reduced *cppc_ss;
if (device_property_read_u32(&pdev->dev, "pcc-channel",
&ctx->mbox_idx))
ctx->mbox_idx = MAILBOX_I2C_INDEX;
cl->tx_block = false;
cl->rx_callback = slimpro_i2c_pcc_rx_cb;
ctx->mbox_chan = pcc_mbox_request_channel(cl, ctx->mbox_idx);
if (IS_ERR(ctx->mbox_chan)) {
dev_err(&pdev->dev, "PCC mailbox channel request failed\n");
return PTR_ERR(ctx->mbox_chan);
}
cppc_ss = ctx->mbox_chan->con_priv;
if (!cppc_ss) {
dev_err(&pdev->dev, "PPC subspace not found\n");
rc = -ENOENT;
goto mbox_err;
}
if (!ctx->mbox_chan->mbox->txdone_irq) {
dev_err(&pdev->dev, "PCC IRQ not supported\n");
rc = -ENOENT;
goto mbox_err;
}
ctx->comm_base_addr = cppc_ss->base_address;
if (ctx->comm_base_addr) {
ctx->pcc_comm_addr = memremap(ctx->comm_base_addr,
cppc_ss->length,
MEMREMAP_WB);
} else {
dev_err(&pdev->dev, "Failed to get PCC comm region\n");
rc = -ENOENT;
goto mbox_err;
}
if (!ctx->pcc_comm_addr) {
dev_err(&pdev->dev,
"Failed to ioremap PCC comm region\n");
rc = -ENOMEM;
goto mbox_err;
}
}
rc = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(64));
if (rc)
dev_warn(&pdev->dev, "Unable to set dma mask\n");
adapter = &ctx->adapter;
snprintf(adapter->name, sizeof(adapter->name), "MAILBOX I2C");
adapter->algo = &xgene_slimpro_i2c_algorithm;
adapter->class = I2C_CLASS_HWMON;
adapter->dev.parent = &pdev->dev;
adapter->dev.of_node = pdev->dev.of_node;
ACPI_COMPANION_SET(&adapter->dev, ACPI_COMPANION(&pdev->dev));
i2c_set_adapdata(adapter, ctx);
rc = i2c_add_adapter(adapter);
if (rc)
goto mbox_err;
dev_info(&pdev->dev, "Mailbox I2C Adapter registered\n");
return 0;
mbox_err:
if (acpi_disabled)
mbox_free_channel(ctx->mbox_chan);
else
pcc_mbox_free_channel(ctx->mbox_chan);
return rc;
}
static int xgene_slimpro_i2c_remove(struct platform_device *pdev)
{
struct slimpro_i2c_dev *ctx = platform_get_drvdata(pdev);
i2c_del_adapter(&ctx->adapter);
if (acpi_disabled)
mbox_free_channel(ctx->mbox_chan);
else
pcc_mbox_free_channel(ctx->mbox_chan);
return 0;
}
