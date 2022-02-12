void *dummy_otp_read(struct v4l2_subdev *sd, u8 dev_addr,
u32 start_addr, u32 size)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 *buf;
buf = devm_kzalloc(&client->dev, size, GFP_KERNEL);
if (!buf)
return ERR_PTR(-ENOMEM);
return buf;
}
