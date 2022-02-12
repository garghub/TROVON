static void mlxcpld_i2c_lpc_write_buf(u8 *data, u8 len, u32 addr)
{
int i;
for (i = 0; i < len - len % 4; i += 4)
outl(*(u32 *)(data + i), addr + i);
for (; i < len; ++i)
outb(*(data + i), addr + i);
}
static void mlxcpld_i2c_lpc_read_buf(u8 *data, u8 len, u32 addr)
{
int i;
for (i = 0; i < len - len % 4; i += 4)
*(u32 *)(data + i) = inl(addr + i);
for (; i < len; ++i)
*(data + i) = inb(addr + i);
}
static void mlxcpld_i2c_read_comm(struct mlxcpld_i2c_priv *priv, u8 offs,
u8 *data, u8 datalen)
{
u32 addr = priv->base_addr + offs;
switch (datalen) {
case 1:
*(data) = inb(addr);
break;
case 2:
*((u16 *)data) = inw(addr);
break;
case 3:
*((u16 *)data) = inw(addr);
*(data + 2) = inb(addr + 2);
break;
case 4:
*((u32 *)data) = inl(addr);
break;
default:
mlxcpld_i2c_lpc_read_buf(data, datalen, addr);
break;
}
}
static void mlxcpld_i2c_write_comm(struct mlxcpld_i2c_priv *priv, u8 offs,
u8 *data, u8 datalen)
{
u32 addr = priv->base_addr + offs;
switch (datalen) {
case 1:
outb(*(data), addr);
break;
case 2:
outw(*((u16 *)data), addr);
break;
case 3:
outw(*((u16 *)data), addr);
outb(*(data + 2), addr + 2);
break;
case 4:
outl(*((u32 *)data), addr);
break;
default:
mlxcpld_i2c_lpc_write_buf(data, datalen, addr);
break;
}
}
static int mlxcpld_i2c_check_msg_params(struct mlxcpld_i2c_priv *priv,
struct i2c_msg *msgs, int num)
{
int i;
if (!num) {
dev_err(priv->dev, "Incorrect 0 num of messages\n");
return -EINVAL;
}
if (unlikely(msgs[0].addr > 0x7f)) {
dev_err(priv->dev, "Invalid address 0x%03x\n",
msgs[0].addr);
return -EINVAL;
}
for (i = 0; i < num; ++i) {
if (unlikely(!msgs[i].buf)) {
dev_err(priv->dev, "Invalid buf in msg[%d]\n",
i);
return -EINVAL;
}
if (unlikely(msgs[0].addr != msgs[i].addr)) {
dev_err(priv->dev, "Invalid addr in msg[%d]\n",
i);
return -EINVAL;
}
}
return 0;
}
static int mlxcpld_i2c_check_status(struct mlxcpld_i2c_priv *priv, int *status)
{
u8 val;
mlxcpld_i2c_read_comm(priv, MLXCPLD_LPCI2C_STATUS_REG, &val, 1);
if (val & MLXCPLD_LPCI2C_TRANS_END) {
if (val & MLXCPLD_LPCI2C_STATUS_NACK)
*status = MLXCPLD_LPCI2C_NACK_IND;
else
*status = MLXCPLD_LPCI2C_ACK_IND;
return 0;
}
*status = MLXCPLD_LPCI2C_NO_IND;
return -EIO;
}
static void mlxcpld_i2c_set_transf_data(struct mlxcpld_i2c_priv *priv,
struct i2c_msg *msgs, int num,
u8 comm_len)
{
priv->xfer.msg = msgs;
priv->xfer.msg_num = num;
priv->xfer.cmd = msgs[num - 1].flags & I2C_M_RD;
if (priv->xfer.cmd == I2C_M_RD && comm_len != msgs[0].len) {
priv->xfer.addr_width = msgs[0].len;
priv->xfer.data_len = comm_len - priv->xfer.addr_width;
} else {
priv->xfer.addr_width = 0;
priv->xfer.data_len = comm_len;
}
}
static void mlxcpld_i2c_reset(struct mlxcpld_i2c_priv *priv)
{
u8 val;
mutex_lock(&priv->lock);
mlxcpld_i2c_read_comm(priv, MLXCPLD_LPCI2C_CTRL_REG, &val, 1);
val &= ~MLXCPLD_LPCI2C_RST_SEL_MASK;
mlxcpld_i2c_write_comm(priv, MLXCPLD_LPCI2C_CTRL_REG, &val, 1);
mutex_unlock(&priv->lock);
}
static int mlxcpld_i2c_check_busy(struct mlxcpld_i2c_priv *priv)
{
u8 val;
mlxcpld_i2c_read_comm(priv, MLXCPLD_LPCI2C_STATUS_REG, &val, 1);
if (val & MLXCPLD_LPCI2C_TRANS_END)
return 0;
return -EIO;
}
static int mlxcpld_i2c_wait_for_free(struct mlxcpld_i2c_priv *priv)
{
int timeout = 0;
do {
if (!mlxcpld_i2c_check_busy(priv))
break;
usleep_range(MLXCPLD_I2C_POLL_TIME / 2, MLXCPLD_I2C_POLL_TIME);
timeout += MLXCPLD_I2C_POLL_TIME;
} while (timeout <= MLXCPLD_I2C_XFER_TO);
if (timeout > MLXCPLD_I2C_XFER_TO)
return -ETIMEDOUT;
return 0;
}
static int mlxcpld_i2c_wait_for_tc(struct mlxcpld_i2c_priv *priv)
{
int status, i, timeout = 0;
u8 datalen;
do {
usleep_range(MLXCPLD_I2C_POLL_TIME / 2, MLXCPLD_I2C_POLL_TIME);
if (!mlxcpld_i2c_check_status(priv, &status))
break;
timeout += MLXCPLD_I2C_POLL_TIME;
} while (status == 0 && timeout < MLXCPLD_I2C_XFER_TO);
switch (status) {
case MLXCPLD_LPCI2C_NO_IND:
return -ETIMEDOUT;
case MLXCPLD_LPCI2C_ACK_IND:
if (priv->xfer.cmd != I2C_M_RD)
return (priv->xfer.addr_width + priv->xfer.data_len);
if (priv->xfer.msg_num == 1)
i = 0;
else
i = 1;
if (!priv->xfer.msg[i].buf)
return -EINVAL;
datalen = priv->xfer.data_len;
mlxcpld_i2c_read_comm(priv, MLXCPLD_LPCI2C_DATA_REG,
priv->xfer.msg[i].buf, datalen);
return datalen;
case MLXCPLD_LPCI2C_NACK_IND:
return -ENXIO;
default:
return -EINVAL;
}
}
static void mlxcpld_i2c_xfer_msg(struct mlxcpld_i2c_priv *priv)
{
int i, len = 0;
u8 cmd;
mlxcpld_i2c_write_comm(priv, MLXCPLD_LPCI2C_NUM_DAT_REG,
&priv->xfer.data_len, 1);
mlxcpld_i2c_write_comm(priv, MLXCPLD_LPCI2C_NUM_ADDR_REG,
&priv->xfer.addr_width, 1);
for (i = 0; i < priv->xfer.msg_num; i++) {
if ((priv->xfer.msg[i].flags & I2C_M_RD) != I2C_M_RD) {
mlxcpld_i2c_write_comm(priv, MLXCPLD_LPCI2C_DATA_REG +
len, priv->xfer.msg[i].buf,
priv->xfer.msg[i].len);
len += priv->xfer.msg[i].len;
}
}
cmd = (priv->xfer.msg[0].addr << 1) | priv->xfer.cmd;
mlxcpld_i2c_write_comm(priv, MLXCPLD_LPCI2C_CMD_REG, &cmd, 1);
}
static int mlxcpld_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs,
int num)
{
struct mlxcpld_i2c_priv *priv = i2c_get_adapdata(adap);
u8 comm_len = 0;
int i, err;
err = mlxcpld_i2c_check_msg_params(priv, msgs, num);
if (err) {
dev_err(priv->dev, "Incorrect message\n");
return err;
}
for (i = 0; i < num; ++i)
comm_len += msgs[i].len;
if (mlxcpld_i2c_wait_for_free(priv)) {
dev_err(priv->dev, "LPCI2C bridge is busy\n");
mlxcpld_i2c_reset(priv);
if (mlxcpld_i2c_check_busy(priv)) {
dev_err(priv->dev, "LPCI2C bridge is busy after reset\n");
return -EIO;
}
}
mlxcpld_i2c_set_transf_data(priv, msgs, num, comm_len);
mutex_lock(&priv->lock);
mlxcpld_i2c_xfer_msg(priv);
err = mlxcpld_i2c_wait_for_tc(priv);
mutex_unlock(&priv->lock);
return err < 0 ? err : num;
}
static u32 mlxcpld_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL | I2C_FUNC_SMBUS_BLOCK_DATA;
}
static int mlxcpld_i2c_probe(struct platform_device *pdev)
{
struct mlxcpld_i2c_priv *priv;
int err;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
mutex_init(&priv->lock);
platform_set_drvdata(pdev, priv);
priv->dev = &pdev->dev;
mlxcpld_i2c_adapter.timeout = usecs_to_jiffies(MLXCPLD_I2C_XFER_TO);
priv->adap = mlxcpld_i2c_adapter;
priv->adap.dev.parent = &pdev->dev;
priv->base_addr = MLXPLAT_CPLD_LPC_I2C_BASE_ADDR;
i2c_set_adapdata(&priv->adap, priv);
err = i2c_add_numbered_adapter(&priv->adap);
if (err)
mutex_destroy(&priv->lock);
return err;
}
static int mlxcpld_i2c_remove(struct platform_device *pdev)
{
struct mlxcpld_i2c_priv *priv = platform_get_drvdata(pdev);
i2c_del_adapter(&priv->adap);
mutex_destroy(&priv->lock);
return 0;
}
