static inline struct ov5647 *to_state(struct v4l2_subdev *sd)
{
return container_of(sd, struct ov5647, sd);
}
static int ov5647_write(struct v4l2_subdev *sd, u16 reg, u8 val)
{
int ret;
unsigned char data[3] = { reg >> 8, reg & 0xff, val};
struct i2c_client *client = v4l2_get_subdevdata(sd);
ret = i2c_master_send(client, data, 3);
if (ret < 0)
dev_dbg(&client->dev, "%s: i2c write error, reg: %x\n",
__func__, reg);
return ret;
}
static int ov5647_read(struct v4l2_subdev *sd, u16 reg, u8 *val)
{
int ret;
unsigned char data_w[2] = { reg >> 8, reg & 0xff };
struct i2c_client *client = v4l2_get_subdevdata(sd);
ret = i2c_master_send(client, data_w, 2);
if (ret < 0) {
dev_dbg(&client->dev, "%s: i2c write error, reg: %x\n",
__func__, reg);
return ret;
}
ret = i2c_master_recv(client, val, 1);
if (ret < 0)
dev_dbg(&client->dev, "%s: i2c read error, reg: %x\n",
__func__, reg);
return ret;
}
static int ov5647_write_array(struct v4l2_subdev *sd,
struct regval_list *regs, int array_size)
{
int i, ret;
for (i = 0; i < array_size; i++) {
ret = ov5647_write(sd, regs[i].addr, regs[i].data);
if (ret < 0)
return ret;
}
return 0;
}
static int ov5647_set_virtual_channel(struct v4l2_subdev *sd, int channel)
{
u8 channel_id;
int ret;
ret = ov5647_read(sd, 0x4814, &channel_id);
if (ret < 0)
return ret;
channel_id &= ~(3 << 6);
return ov5647_write(sd, 0x4814, channel_id | (channel << 6));
}
static int ov5647_stream_on(struct v4l2_subdev *sd)
{
int ret;
ret = ov5647_write(sd, 0x4202, 0x00);
if (ret < 0)
return ret;
return ov5647_write(sd, 0x300D, 0x00);
}
static int ov5647_stream_off(struct v4l2_subdev *sd)
{
int ret;
ret = ov5647_write(sd, 0x4202, 0x0f);
if (ret < 0)
return ret;
return ov5647_write(sd, 0x300D, 0x01);
}
static int set_sw_standby(struct v4l2_subdev *sd, bool standby)
{
int ret;
u8 rdval;
ret = ov5647_read(sd, 0x0100, &rdval);
if (ret < 0)
return ret;
if (standby)
rdval &= ~0x01;
else
rdval |= 0x01;
return ov5647_write(sd, 0x0100, rdval);
}
static int __sensor_init(struct v4l2_subdev *sd)
{
int ret;
u8 resetval, rdval;
struct i2c_client *client = v4l2_get_subdevdata(sd);
ret = ov5647_read(sd, 0x0100, &rdval);
if (ret < 0)
return ret;
ret = ov5647_write_array(sd, ov5647_640x480,
ARRAY_SIZE(ov5647_640x480));
if (ret < 0) {
dev_err(&client->dev, "write sensor default regs error\n");
return ret;
}
ret = ov5647_set_virtual_channel(sd, 0);
if (ret < 0)
return ret;
ret = ov5647_read(sd, 0x0100, &resetval);
if (ret < 0)
return ret;
if (!(resetval & 0x01)) {
dev_err(&client->dev, "Device was in SW standby");
ret = ov5647_write(sd, 0x0100, 0x01);
if (ret < 0)
return ret;
}
return ov5647_write(sd, 0x4800, 0x04);
}
static int ov5647_sensor_power(struct v4l2_subdev *sd, int on)
{
int ret = 0;
struct ov5647 *ov5647 = to_state(sd);
struct i2c_client *client = v4l2_get_subdevdata(sd);
mutex_lock(&ov5647->lock);
if (on && !ov5647->power_count) {
dev_dbg(&client->dev, "OV5647 power on\n");
ret = clk_prepare_enable(ov5647->xclk);
if (ret < 0) {
dev_err(&client->dev, "clk prepare enable failed\n");
goto out;
}
ret = ov5647_write_array(sd, sensor_oe_enable_regs,
ARRAY_SIZE(sensor_oe_enable_regs));
if (ret < 0) {
clk_disable_unprepare(ov5647->xclk);
dev_err(&client->dev,
"write sensor_oe_enable_regs error\n");
goto out;
}
ret = __sensor_init(sd);
if (ret < 0) {
clk_disable_unprepare(ov5647->xclk);
dev_err(&client->dev,
"Camera not available, check Power\n");
goto out;
}
} else if (!on && ov5647->power_count == 1) {
dev_dbg(&client->dev, "OV5647 power off\n");
ret = ov5647_write_array(sd, sensor_oe_disable_regs,
ARRAY_SIZE(sensor_oe_disable_regs));
if (ret < 0)
dev_dbg(&client->dev, "disable oe failed\n");
ret = set_sw_standby(sd, true);
if (ret < 0)
dev_dbg(&client->dev, "soft stby failed\n");
clk_disable_unprepare(ov5647->xclk);
}
ov5647->power_count += on ? 1 : -1;
WARN_ON(ov5647->power_count < 0);
out:
mutex_unlock(&ov5647->lock);
return ret;
}
static int ov5647_sensor_get_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
u8 val;
int ret;
ret = ov5647_read(sd, reg->reg & 0xff, &val);
if (ret < 0)
return ret;
reg->val = val;
reg->size = 1;
return 0;
}
static int ov5647_sensor_set_register(struct v4l2_subdev *sd,
const struct v4l2_dbg_register *reg)
{
return ov5647_write(sd, reg->reg & 0xff, reg->val & 0xff);
}
static int ov5647_s_stream(struct v4l2_subdev *sd, int enable)
{
if (enable)
return ov5647_stream_on(sd);
else
return ov5647_stream_off(sd);
}
static int ov5647_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_mbus_code_enum *code)
{
if (code->index > 0)
return -EINVAL;
code->code = MEDIA_BUS_FMT_SBGGR8_1X8;
return 0;
}
static int ov5647_detect(struct v4l2_subdev *sd)
{
u8 read;
int ret;
struct i2c_client *client = v4l2_get_subdevdata(sd);
ret = ov5647_write(sd, OV5647_SW_RESET, 0x01);
if (ret < 0)
return ret;
ret = ov5647_read(sd, OV5647_REG_CHIPID_H, &read);
if (ret < 0)
return ret;
if (read != 0x56) {
dev_err(&client->dev, "ID High expected 0x56 got %x", read);
return -ENODEV;
}
ret = ov5647_read(sd, OV5647_REG_CHIPID_L, &read);
if (ret < 0)
return ret;
if (read != 0x47) {
dev_err(&client->dev, "ID Low expected 0x47 got %x", read);
return -ENODEV;
}
return ov5647_write(sd, OV5647_SW_RESET, 0x00);
}
static int ov5647_open(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh)
{
struct v4l2_mbus_framefmt *format =
v4l2_subdev_get_try_format(sd, fh->pad, 0);
struct v4l2_rect *crop =
v4l2_subdev_get_try_crop(sd, fh->pad, 0);
crop->left = OV5647_COLUMN_START_DEF;
crop->top = OV5647_ROW_START_DEF;
crop->width = OV5647_WINDOW_WIDTH_DEF;
crop->height = OV5647_WINDOW_HEIGHT_DEF;
format->code = MEDIA_BUS_FMT_SBGGR8_1X8;
format->width = OV5647_WINDOW_WIDTH_DEF;
format->height = OV5647_WINDOW_HEIGHT_DEF;
format->field = V4L2_FIELD_NONE;
format->colorspace = V4L2_COLORSPACE_SRGB;
return 0;
}
static int ov5647_parse_dt(struct device_node *np)
{
struct v4l2_fwnode_endpoint bus_cfg;
struct device_node *ep;
int ret;
ep = of_graph_get_next_endpoint(np, NULL);
if (!ep)
return -EINVAL;
ret = v4l2_fwnode_endpoint_parse(of_fwnode_handle(ep), &bus_cfg);
of_node_put(ep);
return ret;
}
static int ov5647_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct ov5647 *sensor;
int ret;
struct v4l2_subdev *sd;
struct device_node *np = client->dev.of_node;
u32 xclk_freq;
sensor = devm_kzalloc(dev, sizeof(*sensor), GFP_KERNEL);
if (!sensor)
return -ENOMEM;
if (IS_ENABLED(CONFIG_OF) && np) {
ret = ov5647_parse_dt(np);
if (ret) {
dev_err(dev, "DT parsing error: %d\n", ret);
return ret;
}
}
sensor->xclk = devm_clk_get(dev, NULL);
if (IS_ERR(sensor->xclk)) {
dev_err(dev, "could not get xclk");
return PTR_ERR(sensor->xclk);
}
xclk_freq = clk_get_rate(sensor->xclk);
if (xclk_freq != 25000000) {
dev_err(dev, "Unsupported clock frequency: %u\n", xclk_freq);
return -EINVAL;
}
mutex_init(&sensor->lock);
sd = &sensor->sd;
v4l2_i2c_subdev_init(sd, client, &ov5647_subdev_ops);
sensor->sd.internal_ops = &ov5647_subdev_internal_ops;
sensor->sd.flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
sensor->pad.flags = MEDIA_PAD_FL_SOURCE;
sd->entity.function = MEDIA_ENT_F_CAM_SENSOR;
ret = media_entity_pads_init(&sd->entity, 1, &sensor->pad);
if (ret < 0)
goto mutex_remove;
ret = ov5647_detect(sd);
if (ret < 0)
goto error;
ret = v4l2_async_register_subdev(sd);
if (ret < 0)
goto error;
dev_dbg(dev, "OmniVision OV5647 camera driver probed\n");
return 0;
error:
media_entity_cleanup(&sd->entity);
mutex_remove:
mutex_destroy(&sensor->lock);
return ret;
}
static int ov5647_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct ov5647 *ov5647 = to_state(sd);
v4l2_async_unregister_subdev(&ov5647->sd);
media_entity_cleanup(&ov5647->sd.entity);
v4l2_device_unregister_subdev(sd);
mutex_destroy(&ov5647->lock);
return 0;
}
