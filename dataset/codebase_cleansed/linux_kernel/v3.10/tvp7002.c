static inline struct tvp7002 *to_tvp7002(struct v4l2_subdev *sd)
{
return container_of(sd, struct tvp7002, sd);
}
static inline struct v4l2_subdev *to_sd(struct v4l2_ctrl *ctrl)
{
return &container_of(ctrl->handler, struct tvp7002, hdl)->sd;
}
static int tvp7002_read(struct v4l2_subdev *sd, u8 addr, u8 *dst)
{
struct i2c_client *c = v4l2_get_subdevdata(sd);
int retry;
int error;
for (retry = 0; retry < I2C_RETRY_COUNT; retry++) {
error = i2c_smbus_read_byte_data(c, addr);
if (error >= 0) {
*dst = (u8)error;
return 0;
}
msleep_interruptible(10);
}
v4l2_err(sd, "TVP7002 read error %d\n", error);
return error;
}
static inline void tvp7002_read_err(struct v4l2_subdev *sd, u8 reg,
u8 *dst, int *err)
{
if (!*err)
*err = tvp7002_read(sd, reg, dst);
}
static int tvp7002_write(struct v4l2_subdev *sd, u8 addr, u8 value)
{
struct i2c_client *c;
int retry;
int error;
c = v4l2_get_subdevdata(sd);
for (retry = 0; retry < I2C_RETRY_COUNT; retry++) {
error = i2c_smbus_write_byte_data(c, addr, value);
if (error >= 0)
return 0;
v4l2_warn(sd, "Write: retry ... %d\n", retry);
msleep_interruptible(10);
}
v4l2_err(sd, "TVP7002 write error %d\n", error);
return error;
}
static inline void tvp7002_write_err(struct v4l2_subdev *sd, u8 reg,
u8 val, int *err)
{
if (!*err)
*err = tvp7002_write(sd, reg, val);
}
static int tvp7002_g_chip_ident(struct v4l2_subdev *sd,
struct v4l2_dbg_chip_ident *chip)
{
u8 rev;
int error;
struct i2c_client *client = v4l2_get_subdevdata(sd);
error = tvp7002_read(sd, TVP7002_CHIP_REV, &rev);
if (error < 0)
return error;
return v4l2_chip_ident_i2c_client(client, chip, V4L2_IDENT_TVP7002, rev);
}
static int tvp7002_write_inittab(struct v4l2_subdev *sd,
const struct i2c_reg_value *regs)
{
int error = 0;
while (TVP7002_EOR != regs->reg) {
if (TVP7002_WRITE == regs->type)
tvp7002_write_err(sd, regs->reg, regs->value, &error);
regs++;
}
return error;
}
static int tvp7002_s_dv_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *dv_timings)
{
struct tvp7002 *device = to_tvp7002(sd);
const struct v4l2_bt_timings *bt = &dv_timings->bt;
int i;
if (dv_timings->type != V4L2_DV_BT_656_1120)
return -EINVAL;
for (i = 0; i < NUM_TIMINGS; i++) {
const struct v4l2_bt_timings *t = &tvp7002_timings[i].timings.bt;
if (!memcmp(bt, t, &bt->standards - &bt->width)) {
device->current_timings = &tvp7002_timings[i];
return tvp7002_write_inittab(sd, tvp7002_timings[i].p_settings);
}
}
return -EINVAL;
}
static int tvp7002_g_dv_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *dv_timings)
{
struct tvp7002 *device = to_tvp7002(sd);
*dv_timings = device->current_timings->timings;
return 0;
}
static int tvp7002_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct v4l2_subdev *sd = to_sd(ctrl);
int error = 0;
switch (ctrl->id) {
case V4L2_CID_GAIN:
tvp7002_write_err(sd, TVP7002_R_FINE_GAIN, ctrl->val, &error);
tvp7002_write_err(sd, TVP7002_G_FINE_GAIN, ctrl->val, &error);
tvp7002_write_err(sd, TVP7002_B_FINE_GAIN, ctrl->val, &error);
return error;
}
return -EINVAL;
}
static int tvp7002_mbus_fmt(struct v4l2_subdev *sd, struct v4l2_mbus_framefmt *f)
{
struct tvp7002 *device = to_tvp7002(sd);
const struct v4l2_bt_timings *bt = &device->current_timings->timings.bt;
f->width = bt->width;
f->height = bt->height;
f->code = V4L2_MBUS_FMT_YUYV10_1X20;
f->field = device->current_timings->scanmode;
f->colorspace = device->current_timings->color_space;
v4l2_dbg(1, debug, sd, "MBUS_FMT: Width - %d, Height - %d",
f->width, f->height);
return 0;
}
static int tvp7002_query_dv(struct v4l2_subdev *sd, int *index)
{
const struct tvp7002_timings_definition *timings = tvp7002_timings;
u8 progressive;
u32 lpfr;
u32 cpln;
int error = 0;
u8 lpf_lsb;
u8 lpf_msb;
u8 cpl_lsb;
u8 cpl_msb;
*index = NUM_TIMINGS;
tvp7002_read_err(sd, TVP7002_L_FRAME_STAT_LSBS, &lpf_lsb, &error);
tvp7002_read_err(sd, TVP7002_L_FRAME_STAT_MSBS, &lpf_msb, &error);
if (error < 0)
return error;
tvp7002_read_err(sd, TVP7002_CLK_L_STAT_LSBS, &cpl_lsb, &error);
tvp7002_read_err(sd, TVP7002_CLK_L_STAT_MSBS, &cpl_msb, &error);
if (error < 0)
return error;
lpfr = lpf_lsb | ((TVP7002_CL_MASK & lpf_msb) << TVP7002_CL_SHIFT);
cpln = cpl_lsb | ((TVP7002_CL_MASK & cpl_msb) << TVP7002_CL_SHIFT);
progressive = (lpf_msb & TVP7002_INPR_MASK) >> TVP7002_IP_SHIFT;
for (*index = 0; *index < NUM_TIMINGS; (*index)++, timings++)
if (lpfr == timings->lines_per_frame &&
progressive == timings->progressive) {
if (timings->cpl_min == 0xffff)
break;
if (cpln >= timings->cpl_min && cpln <= timings->cpl_max)
break;
}
if (*index == NUM_TIMINGS) {
v4l2_dbg(1, debug, sd, "detection failed: lpf = %x, cpl = %x\n",
lpfr, cpln);
return -ENOLINK;
}
v4l2_dbg(1, debug, sd, "detected timings: %d\n", *index);
return 0;
}
static int tvp7002_query_dv_timings(struct v4l2_subdev *sd,
struct v4l2_dv_timings *timings)
{
int index;
int err = tvp7002_query_dv(sd, &index);
if (err)
return err;
*timings = tvp7002_timings[index].timings;
return 0;
}
static int tvp7002_g_register(struct v4l2_subdev *sd,
struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
u8 val;
int ret;
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
ret = tvp7002_read(sd, reg->reg & 0xff, &val);
reg->val = val;
return ret;
}
static int tvp7002_s_register(struct v4l2_subdev *sd,
const struct v4l2_dbg_register *reg)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
if (!v4l2_chip_match_i2c_client(client, &reg->match))
return -EINVAL;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
return tvp7002_write(sd, reg->reg & 0xff, reg->val & 0xff);
}
static int tvp7002_enum_mbus_fmt(struct v4l2_subdev *sd, unsigned index,
enum v4l2_mbus_pixelcode *code)
{
if (index)
return -EINVAL;
*code = V4L2_MBUS_FMT_YUYV10_1X20;
return 0;
}
static int tvp7002_s_stream(struct v4l2_subdev *sd, int enable)
{
struct tvp7002 *device = to_tvp7002(sd);
int error = 0;
if (device->streaming == enable)
return 0;
if (enable) {
error = tvp7002_write(sd, TVP7002_MISC_CTL_2, 0x00);
device->streaming = enable;
} else {
error = tvp7002_write(sd, TVP7002_MISC_CTL_2, 0x03);
if (error)
v4l2_dbg(1, debug, sd, "Unable to stop streaming\n");
device->streaming = enable;
}
return error;
}
static int tvp7002_log_status(struct v4l2_subdev *sd)
{
struct tvp7002 *device = to_tvp7002(sd);
const struct v4l2_bt_timings *bt;
int detected;
tvp7002_query_dv(sd, &detected);
bt = &device->current_timings->timings.bt;
v4l2_info(sd, "Selected DV Timings: %ux%u\n", bt->width, bt->height);
if (detected == NUM_TIMINGS) {
v4l2_info(sd, "Detected DV Timings: None\n");
} else {
bt = &tvp7002_timings[detected].timings.bt;
v4l2_info(sd, "Detected DV Timings: %ux%u\n",
bt->width, bt->height);
}
v4l2_info(sd, "Streaming enabled: %s\n",
device->streaming ? "yes" : "no");
v4l2_ctrl_handler_log_status(&device->hdl, sd->name);
return 0;
}
static int tvp7002_enum_dv_timings(struct v4l2_subdev *sd,
struct v4l2_enum_dv_timings *timings)
{
if (timings->index >= NUM_TIMINGS)
return -EINVAL;
timings->timings = tvp7002_timings[timings->index].timings;
return 0;
}
static int tvp7002_probe(struct i2c_client *c, const struct i2c_device_id *id)
{
struct v4l2_subdev *sd;
struct tvp7002 *device;
struct v4l2_dv_timings timings;
int polarity_a;
int polarity_b;
u8 revision;
int error;
if (!i2c_check_functionality(c->adapter,
I2C_FUNC_SMBUS_READ_BYTE | I2C_FUNC_SMBUS_WRITE_BYTE_DATA))
return -EIO;
if (!c->dev.platform_data) {
v4l_err(c, "No platform data!!\n");
return -ENODEV;
}
device = devm_kzalloc(&c->dev, sizeof(struct tvp7002), GFP_KERNEL);
if (!device)
return -ENOMEM;
sd = &device->sd;
device->pdata = c->dev.platform_data;
device->current_timings = tvp7002_timings;
v4l2_i2c_subdev_init(sd, c, &tvp7002_ops);
v4l_info(c, "tvp7002 found @ 0x%02x (%s)\n",
c->addr, c->adapter->name);
error = tvp7002_read(sd, TVP7002_CHIP_REV, &revision);
if (error < 0)
return error;
v4l2_info(sd, "Rev. %02x detected.\n", revision);
if (revision != 0x02)
v4l2_info(sd, "Unknown revision detected.\n");
error = tvp7002_write_inittab(sd, tvp7002_init_default);
if (error < 0)
return error;
polarity_a = 0x20 | device->pdata->hs_polarity << 5
| device->pdata->vs_polarity << 2;
error = tvp7002_write(sd, TVP7002_SYNC_CTL_1, polarity_a);
if (error < 0)
return error;
polarity_b = 0x01 | device->pdata->fid_polarity << 2
| device->pdata->sog_polarity << 1
| device->pdata->clk_polarity;
error = tvp7002_write(sd, TVP7002_MISC_CTL_3, polarity_b);
if (error < 0)
return error;
timings = device->current_timings->timings;
error = tvp7002_s_dv_timings(sd, &timings);
v4l2_ctrl_handler_init(&device->hdl, 1);
v4l2_ctrl_new_std(&device->hdl, &tvp7002_ctrl_ops,
V4L2_CID_GAIN, 0, 255, 1, 0);
sd->ctrl_handler = &device->hdl;
if (device->hdl.error) {
int err = device->hdl.error;
v4l2_ctrl_handler_free(&device->hdl);
return err;
}
v4l2_ctrl_handler_setup(&device->hdl);
return 0;
}
static int tvp7002_remove(struct i2c_client *c)
{
struct v4l2_subdev *sd = i2c_get_clientdata(c);
struct tvp7002 *device = to_tvp7002(sd);
v4l2_dbg(1, debug, sd, "Removing tvp7002 adapter"
"on address 0x%x\n", c->addr);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(&device->hdl);
return 0;
}
