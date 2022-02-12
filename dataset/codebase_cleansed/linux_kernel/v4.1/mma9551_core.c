static int mma9551_transfer(struct i2c_client *client,
u8 app_id, u8 command, u16 offset,
u8 *inbytes, int num_inbytes,
u8 *outbytes, int num_outbytes)
{
struct mma9551_mbox_request req;
struct mma9551_mbox_response rsp;
struct i2c_msg in, out;
u8 req_len, err_code;
int ret, retries;
if (offset >= 1 << 12) {
dev_err(&client->dev, "register offset too large\n");
return -EINVAL;
}
req_len = 1 + MMA9551_MAILBOX_CTRL_REGS + num_inbytes;
req.start_mbox = 0;
req.app_id = app_id;
req.cmd_off = command | (offset >> 8);
req.lower_off = offset;
if (command == MMA9551_CMD_WRITE_CONFIG)
req.nbytes = num_inbytes;
else
req.nbytes = num_outbytes;
if (num_inbytes)
memcpy(req.buf, inbytes, num_inbytes);
out.addr = client->addr;
out.flags = 0;
out.len = req_len;
out.buf = (u8 *)&req;
ret = i2c_transfer(client->adapter, &out, 1);
if (ret < 0) {
dev_err(&client->dev, "i2c write failed\n");
return ret;
}
retries = MMA9551_I2C_READ_RETRIES;
do {
udelay(MMA9551_I2C_READ_DELAY);
in.addr = client->addr;
in.flags = I2C_M_RD;
in.len = sizeof(rsp);
in.buf = (u8 *)&rsp;
ret = i2c_transfer(client->adapter, &in, 1);
if (ret < 0) {
dev_err(&client->dev, "i2c read failed\n");
return ret;
}
if (rsp.coco_err & MMA9551_RESPONSE_COCO)
break;
} while (--retries > 0);
if (retries == 0) {
dev_err(&client->dev,
"timed out while waiting for command response\n");
return -ETIMEDOUT;
}
if (rsp.app_id != app_id) {
dev_err(&client->dev,
"app_id mismatch in response got %02x expected %02x\n",
rsp.app_id, app_id);
return -EINVAL;
}
err_code = rsp.coco_err & ~MMA9551_RESPONSE_COCO;
if (err_code != MMA9551_MCI_ERROR_NONE) {
dev_err(&client->dev, "read returned error %x\n", err_code);
return -EINVAL;
}
if (rsp.nbytes != rsp.req_bytes) {
dev_err(&client->dev,
"output length mismatch got %d expected %d\n",
rsp.nbytes, rsp.req_bytes);
return -EINVAL;
}
if (num_outbytes)
memcpy(outbytes, rsp.buf, num_outbytes);
return 0;
}
int mma9551_read_config_byte(struct i2c_client *client, u8 app_id,
u16 reg, u8 *val)
{
return mma9551_transfer(client, app_id, MMA9551_CMD_READ_CONFIG,
reg, NULL, 0, val, 1);
}
int mma9551_write_config_byte(struct i2c_client *client, u8 app_id,
u16 reg, u8 val)
{
return mma9551_transfer(client, app_id, MMA9551_CMD_WRITE_CONFIG, reg,
&val, 1, NULL, 0);
}
int mma9551_read_status_byte(struct i2c_client *client, u8 app_id,
u16 reg, u8 *val)
{
return mma9551_transfer(client, app_id, MMA9551_CMD_READ_STATUS,
reg, NULL, 0, val, 1);
}
int mma9551_read_config_word(struct i2c_client *client, u8 app_id,
u16 reg, u16 *val)
{
int ret;
__be16 v;
ret = mma9551_transfer(client, app_id, MMA9551_CMD_READ_CONFIG,
reg, NULL, 0, (u8 *)&v, 2);
*val = be16_to_cpu(v);
return ret;
}
int mma9551_write_config_word(struct i2c_client *client, u8 app_id,
u16 reg, u16 val)
{
__be16 v = cpu_to_be16(val);
return mma9551_transfer(client, app_id, MMA9551_CMD_WRITE_CONFIG, reg,
(u8 *) &v, 2, NULL, 0);
}
int mma9551_read_status_word(struct i2c_client *client, u8 app_id,
u16 reg, u16 *val)
{
int ret;
__be16 v;
ret = mma9551_transfer(client, app_id, MMA9551_CMD_READ_STATUS,
reg, NULL, 0, (u8 *)&v, 2);
*val = be16_to_cpu(v);
return ret;
}
int mma9551_read_config_words(struct i2c_client *client, u8 app_id,
u16 reg, u8 len, u16 *buf)
{
int ret, i;
int len_words = len / sizeof(u16);
__be16 be_buf[MMA9551_MAX_MAILBOX_DATA_REGS / 2];
if (len_words > ARRAY_SIZE(be_buf)) {
dev_err(&client->dev, "Invalid buffer size %d\n", len);
return -EINVAL;
}
ret = mma9551_transfer(client, app_id, MMA9551_CMD_READ_CONFIG,
reg, NULL, 0, (u8 *) be_buf, len);
if (ret < 0)
return ret;
for (i = 0; i < len_words; i++)
buf[i] = be16_to_cpu(be_buf[i]);
return 0;
}
int mma9551_read_status_words(struct i2c_client *client, u8 app_id,
u16 reg, u8 len, u16 *buf)
{
int ret, i;
int len_words = len / sizeof(u16);
__be16 be_buf[MMA9551_MAX_MAILBOX_DATA_REGS / 2];
if (len_words > ARRAY_SIZE(be_buf)) {
dev_err(&client->dev, "Invalid buffer size %d\n", len);
return -EINVAL;
}
ret = mma9551_transfer(client, app_id, MMA9551_CMD_READ_STATUS,
reg, NULL, 0, (u8 *) be_buf, len);
if (ret < 0)
return ret;
for (i = 0; i < len_words; i++)
buf[i] = be16_to_cpu(be_buf[i]);
return 0;
}
int mma9551_write_config_words(struct i2c_client *client, u8 app_id,
u16 reg, u8 len, u16 *buf)
{
int i;
int len_words = len / sizeof(u16);
__be16 be_buf[(MMA9551_MAX_MAILBOX_DATA_REGS - 1) / 2];
if (len_words > ARRAY_SIZE(be_buf)) {
dev_err(&client->dev, "Invalid buffer size %d\n", len);
return -EINVAL;
}
for (i = 0; i < len_words; i++)
be_buf[i] = cpu_to_be16(buf[i]);
return mma9551_transfer(client, app_id, MMA9551_CMD_WRITE_CONFIG,
reg, (u8 *) be_buf, len, NULL, 0);
}
int mma9551_update_config_bits(struct i2c_client *client, u8 app_id,
u16 reg, u8 mask, u8 val)
{
int ret;
u8 tmp, orig;
ret = mma9551_read_config_byte(client, app_id, reg, &orig);
if (ret < 0)
return ret;
tmp = orig & ~mask;
tmp |= val & mask;
if (tmp == orig)
return 0;
return mma9551_write_config_byte(client, app_id, reg, tmp);
}
int mma9551_gpio_config(struct i2c_client *client, enum mma9551_gpio_pin pin,
u8 app_id, u8 bitnum, int polarity)
{
u8 reg, pol_mask, pol_val;
int ret;
if (pin > mma9551_gpio_max) {
dev_err(&client->dev, "bad GPIO pin\n");
return -EINVAL;
}
reg = pin * 2;
ret = mma9551_write_config_byte(client, MMA9551_APPID_GPIO,
reg, app_id);
if (ret < 0) {
dev_err(&client->dev, "error setting GPIO app_id\n");
return ret;
}
ret = mma9551_write_config_byte(client, MMA9551_APPID_GPIO,
reg + 1, bitnum);
if (ret < 0) {
dev_err(&client->dev, "error setting GPIO bit number\n");
return ret;
}
switch (pin) {
case mma9551_gpio6:
reg = MMA9551_GPIO_POL_LSB;
pol_mask = 1 << 6;
break;
case mma9551_gpio7:
reg = MMA9551_GPIO_POL_LSB;
pol_mask = 1 << 7;
break;
case mma9551_gpio8:
reg = MMA9551_GPIO_POL_MSB;
pol_mask = 1 << 0;
break;
case mma9551_gpio9:
reg = MMA9551_GPIO_POL_MSB;
pol_mask = 1 << 1;
break;
}
pol_val = polarity ? pol_mask : 0;
ret = mma9551_update_config_bits(client, MMA9551_APPID_GPIO, reg,
pol_mask, pol_val);
if (ret < 0)
dev_err(&client->dev, "error setting GPIO polarity\n");
return ret;
}
int mma9551_read_version(struct i2c_client *client)
{
struct mma9551_version_info info;
int ret;
ret = mma9551_transfer(client, MMA9551_APPID_VERSION, 0x00, 0x00,
NULL, 0, (u8 *)&info, sizeof(info));
if (ret < 0)
return ret;
dev_info(&client->dev, "device ID 0x%x, firmware version %02x.%02x\n",
be32_to_cpu(info.device_id), info.fw_version[0],
info.fw_version[1]);
return 0;
}
int mma9551_set_device_state(struct i2c_client *client, bool enable)
{
return mma9551_update_config_bits(client, MMA9551_APPID_SLEEP_WAKE,
MMA9551_SLEEP_CFG,
MMA9551_SLEEP_CFG_SNCEN |
MMA9551_SLEEP_CFG_FLEEN |
MMA9551_SLEEP_CFG_SCHEN,
enable ? MMA9551_SLEEP_CFG_SCHEN |
MMA9551_SLEEP_CFG_FLEEN :
MMA9551_SLEEP_CFG_SNCEN);
}
int mma9551_set_power_state(struct i2c_client *client, bool on)
{
#ifdef CONFIG_PM
int ret;
if (on)
ret = pm_runtime_get_sync(&client->dev);
else {
pm_runtime_mark_last_busy(&client->dev);
ret = pm_runtime_put_autosuspend(&client->dev);
}
if (ret < 0) {
dev_err(&client->dev,
"failed to change power state to %d\n", on);
if (on)
pm_runtime_put_noidle(&client->dev);
return ret;
}
#endif
return 0;
}
void mma9551_sleep(int freq)
{
int sleep_val = 1000 / freq;
if (sleep_val < 20)
usleep_range(sleep_val * 1000, 20000);
else
msleep_interruptible(sleep_val);
}
int mma9551_read_accel_chan(struct i2c_client *client,
const struct iio_chan_spec *chan,
int *val, int *val2)
{
u16 reg_addr;
s16 raw_accel;
int ret;
switch (chan->channel2) {
case IIO_MOD_X:
reg_addr = MMA9551_AFE_X_ACCEL_REG;
break;
case IIO_MOD_Y:
reg_addr = MMA9551_AFE_Y_ACCEL_REG;
break;
case IIO_MOD_Z:
reg_addr = MMA9551_AFE_Z_ACCEL_REG;
break;
default:
return -EINVAL;
}
ret = mma9551_set_power_state(client, true);
if (ret < 0)
return ret;
ret = mma9551_read_status_word(client, MMA9551_APPID_AFE,
reg_addr, &raw_accel);
if (ret < 0)
goto out_poweroff;
*val = raw_accel;
ret = IIO_VAL_INT;
out_poweroff:
mma9551_set_power_state(client, false);
return ret;
}
int mma9551_read_accel_scale(int *val, int *val2)
{
*val = 0;
*val2 = 2440;
return IIO_VAL_INT_PLUS_MICRO;
}
int mma9551_app_reset(struct i2c_client *client, u32 app_mask)
{
return mma9551_write_config_byte(client, MMA9551_APPID_RCS,
MMA9551_RSC_RESET +
MMA9551_RSC_OFFSET(app_mask),
MMA9551_RSC_VAL(app_mask));
}
