const u8 *hdmiphy_preset2conf(u32 preset)
{
int i;
for (i = 0; i < ARRAY_SIZE(hdmiphy_conf); ++i)
if (hdmiphy_conf[i].preset == preset)
return hdmiphy_conf[i].data;
return NULL;
}
static int hdmiphy_s_power(struct v4l2_subdev *sd, int on)
{
return 0;
}
static int hdmiphy_s_dv_preset(struct v4l2_subdev *sd,
struct v4l2_dv_preset *preset)
{
const u8 *data;
u8 buffer[32];
int ret;
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct device *dev = &client->dev;
dev_info(dev, "s_dv_preset(preset = %d)\n", preset->preset);
data = hdmiphy_preset2conf(preset->preset);
if (!data) {
dev_err(dev, "format not supported\n");
return -EINVAL;
}
memcpy(buffer, data, 32);
ret = i2c_master_send(client, buffer, 32);
if (ret != 32) {
dev_err(dev, "failed to configure HDMIPHY via I2C\n");
return -EIO;
}
return 0;
}
static int hdmiphy_s_stream(struct v4l2_subdev *sd, int enable)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct device *dev = &client->dev;
u8 buffer[2];
int ret;
dev_info(dev, "s_stream(%d)\n", enable);
buffer[0] = 0x1f;
buffer[1] = enable ? 0x80 : 0x00;
ret = i2c_master_send(client, buffer, 2);
if (ret != 2) {
dev_err(dev, "stream (%d) failed\n", enable);
return -EIO;
}
return 0;
}
static int __devinit hdmiphy_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
static struct v4l2_subdev sd;
v4l2_i2c_subdev_init(&sd, client, &hdmiphy_ops);
dev_info(&client->dev, "probe successful\n");
return 0;
}
static int __devexit hdmiphy_remove(struct i2c_client *client)
{
dev_info(&client->dev, "remove successful\n");
return 0;
}
static int __init hdmiphy_init(void)
{
return i2c_add_driver(&hdmiphy_driver);
}
static void __exit hdmiphy_exit(void)
{
i2c_del_driver(&hdmiphy_driver);
}
