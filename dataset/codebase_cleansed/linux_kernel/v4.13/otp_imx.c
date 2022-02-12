static int
imx_read_otp_data(struct i2c_client *client, u16 len, u16 reg, void *val)
{
struct i2c_msg msg[2];
u16 data[IMX_SHORT_MAX] = { 0 };
int err;
if (len > IMX_BYTE_MAX) {
dev_err(&client->dev, "%s error, invalid data length\n",
__func__);
return -EINVAL;
}
memset(msg, 0 , sizeof(msg));
memset(data, 0 , sizeof(data));
msg[0].addr = client->addr;
msg[0].flags = 0;
msg[0].len = I2C_MSG_LENGTH;
msg[0].buf = (u8 *)data;
data[0] = cpu_to_be16(reg);
msg[1].addr = client->addr;
msg[1].len = len;
msg[1].flags = I2C_M_RD;
msg[1].buf = (u8 *)data;
err = i2c_transfer(client->adapter, msg, 2);
if (err != 2) {
if (err >= 0)
err = -EIO;
goto error;
}
memcpy(val, data, len);
return 0;
error:
dev_err(&client->dev, "read from offset 0x%x error %d", reg, err);
return err;
}
static int imx_read_otp_reg_array(struct i2c_client *client, u16 size, u16 addr,
u8 *buf)
{
u16 index;
int ret;
for (index = 0; index + IMX_OTP_READ_ONETIME <= size;
index += IMX_OTP_READ_ONETIME) {
ret = imx_read_otp_data(client, IMX_OTP_READ_ONETIME,
addr + index, &buf[index]);
if (ret)
return ret;
}
return 0;
}
void *imx_otp_read(struct v4l2_subdev *sd, u8 dev_addr,
u32 start_addr, u32 size)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 *buf;
int ret;
int i;
buf = devm_kzalloc(&client->dev, size, GFP_KERNEL);
if (!buf)
return ERR_PTR(-ENOMEM);
for (i = 0; i < IMX_OTP_PAGE_MAX; i++) {
ret = imx_write_reg(client, IMX_8BIT,
IMX_OTP_PAGE_REG, i & 0xff);
if (ret)
goto fail;
ret = imx_write_reg(client, IMX_8BIT,
IMX_OTP_MODE_REG, IMX_OTP_MODE_READ);
if (ret)
goto fail;
ret = imx_read_otp_reg_array(client, IMX_OTP_PAGE_SIZE,
IMX_OTP_START_ADDR, buf + i * IMX_OTP_PAGE_SIZE);
if (ret)
goto fail;
}
return buf;
fail:
dev_err(&client->dev, "sensor found no valid OTP data\n");
return ERR_PTR(ret);
}
void *imx227_otp_read(struct v4l2_subdev *sd, u8 dev_addr,
u32 start_addr, u32 size)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 *buf;
int ret;
int i;
buf = devm_kzalloc(&client->dev, size, GFP_KERNEL);
if (!buf)
return ERR_PTR(-ENOMEM);
for (i = 0; i < IMX_OTP_PAGE_MAX; i++) {
ret = imx_write_reg(client, IMX_8BIT,
IMX227_OTP_PAGE_REG, i & 0xff);
if (ret)
goto fail;
ret = imx_write_reg(client, IMX_8BIT,
IMX227_OTP_ENABLE_REG, IMX227_OTP_MODE_READ);
if (ret)
goto fail;
ret = imx_read_otp_reg_array(client, IMX_OTP_PAGE_SIZE,
IMX227_OTP_START_ADDR, buf + i * IMX_OTP_PAGE_SIZE);
if (ret)
goto fail;
}
return buf;
fail:
dev_err(&client->dev, "sensor found no valid OTP data\n");
return ERR_PTR(ret);
}
