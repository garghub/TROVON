static inline struct hdmiphy_ctx *sd_to_ctx(struct v4l2_subdev *sd)
{
return container_of(sd, struct hdmiphy_ctx, sd);
}
static const u8 *hdmiphy_find_conf(unsigned long pixclk,
const struct hdmiphy_conf *conf)
{
for (; conf->pixclk; ++conf)
if (conf->pixclk == pixclk)
return conf->data;
return NULL;
}
static int hdmiphy_s_power(struct v4l2_subdev *sd, int on)
{
return 0;
}
static int hdmiphy_s_dv_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
const u8 *data;
u8 buffer[32];
int ret;
struct hdmiphy_ctx *ctx = sd_to_ctx(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct device *dev = &client->dev;
unsigned long pixclk = timings->bt.pixelclock;
dev_info(dev, "s_dv_timings\n");
if ((timings->bt.flags & V4L2_DV_FL_REDUCED_FPS) && pixclk == 74250000)
pixclk = 74176000;
data = hdmiphy_find_conf(pixclk, ctx->conf_tab);
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
static int hdmiphy_dv_timings_cap(struct v4l2_subdev *sd,
struct v4l2_dv_timings_cap *cap)
{
cap->type = V4L2_DV_BT_656_1120;
cap->bt.min_pixelclock = 27000000;
cap->bt.max_pixelclock = 148500000;
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
static int hdmiphy_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct hdmiphy_ctx *ctx;
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->conf_tab = (struct hdmiphy_conf *)id->driver_data;
v4l2_i2c_subdev_init(&ctx->sd, client, &hdmiphy_ops);
dev_info(&client->dev, "probe successful\n");
return 0;
}
static int hdmiphy_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct hdmiphy_ctx *ctx = sd_to_ctx(sd);
kfree(ctx);
dev_info(&client->dev, "remove successful\n");
return 0;
}
