static u32 m5mols_swap_byte(u8 *data, u8 length)
{
if (length == 1)
return *data;
else if (length == 2)
return be16_to_cpu(*((u16 *)data));
else
return be32_to_cpu(*((u32 *)data));
}
static int m5mols_read(struct v4l2_subdev *sd, u32 size, u32 reg, u32 *val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct m5mols_info *info = to_m5mols(sd);
u8 rbuf[M5MOLS_I2C_MAX_SIZE + 1];
u8 category = I2C_CATEGORY(reg);
u8 cmd = I2C_COMMAND(reg);
struct i2c_msg msg[2];
u8 wbuf[5];
int ret;
if (!client->adapter)
return -ENODEV;
msg[0].addr = client->addr;
msg[0].flags = 0;
msg[0].len = 5;
msg[0].buf = wbuf;
wbuf[0] = 5;
wbuf[1] = M5MOLS_BYTE_READ;
wbuf[2] = category;
wbuf[3] = cmd;
wbuf[4] = size;
msg[1].addr = client->addr;
msg[1].flags = I2C_M_RD;
msg[1].len = size + 1;
msg[1].buf = rbuf;
usleep_range(200, 200);
ret = i2c_transfer(client->adapter, msg, 2);
if (ret == 2) {
*val = m5mols_swap_byte(&rbuf[1], size);
return 0;
}
if (info->isp_ready)
v4l2_err(sd, "read failed: size:%d cat:%02x cmd:%02x. %d\n",
size, category, cmd, ret);
return ret < 0 ? ret : -EIO;
}
int m5mols_read_u8(struct v4l2_subdev *sd, u32 reg, u8 *val)
{
u32 val_32;
int ret;
if (I2C_SIZE(reg) != 1) {
v4l2_err(sd, "Wrong data size\n");
return -EINVAL;
}
ret = m5mols_read(sd, I2C_SIZE(reg), reg, &val_32);
if (ret)
return ret;
*val = (u8)val_32;
return ret;
}
int m5mols_read_u16(struct v4l2_subdev *sd, u32 reg, u16 *val)
{
u32 val_32;
int ret;
if (I2C_SIZE(reg) != 2) {
v4l2_err(sd, "Wrong data size\n");
return -EINVAL;
}
ret = m5mols_read(sd, I2C_SIZE(reg), reg, &val_32);
if (ret)
return ret;
*val = (u16)val_32;
return ret;
}
int m5mols_read_u32(struct v4l2_subdev *sd, u32 reg, u32 *val)
{
if (I2C_SIZE(reg) != 4) {
v4l2_err(sd, "Wrong data size\n");
return -EINVAL;
}
return m5mols_read(sd, I2C_SIZE(reg), reg, val);
}
int m5mols_write(struct v4l2_subdev *sd, u32 reg, u32 val)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct m5mols_info *info = to_m5mols(sd);
u8 wbuf[M5MOLS_I2C_MAX_SIZE + 4];
u8 category = I2C_CATEGORY(reg);
u8 cmd = I2C_COMMAND(reg);
u8 size = I2C_SIZE(reg);
u32 *buf = (u32 *)&wbuf[4];
struct i2c_msg msg[1];
int ret;
if (!client->adapter)
return -ENODEV;
if (size != 1 && size != 2 && size != 4) {
v4l2_err(sd, "Wrong data size\n");
return -EINVAL;
}
msg->addr = client->addr;
msg->flags = 0;
msg->len = (u16)size + 4;
msg->buf = wbuf;
wbuf[0] = size + 4;
wbuf[1] = M5MOLS_BYTE_WRITE;
wbuf[2] = category;
wbuf[3] = cmd;
*buf = m5mols_swap_byte((u8 *)&val, size);
usleep_range(200, 200);
ret = i2c_transfer(client->adapter, msg, 1);
if (ret == 1)
return 0;
if (info->isp_ready)
v4l2_err(sd, "write failed: cat:%02x cmd:%02x ret:%d\n",
category, cmd, ret);
return ret < 0 ? ret : -EIO;
}
int m5mols_busy_wait(struct v4l2_subdev *sd, u32 reg, u32 value, u32 mask,
int timeout)
{
int ms = timeout < 0 ? M5MOLS_BUSY_WAIT_DEF_TIMEOUT : timeout;
unsigned long end = jiffies + msecs_to_jiffies(ms);
u8 status;
do {
int ret = m5mols_read_u8(sd, reg, &status);
if (ret < 0 && !(mask & M5MOLS_I2C_RDY_WAIT_FL))
return ret;
if (!ret && (status & mask & 0xff) == (value & 0xff))
return 0;
usleep_range(100, 250);
} while (ms > 0 && time_is_after_jiffies(end));
return -EBUSY;
}
int m5mols_enable_interrupt(struct v4l2_subdev *sd, u8 reg)
{
struct m5mols_info *info = to_m5mols(sd);
u8 mask = is_available_af(info) ? REG_INT_AF : 0;
u8 dummy;
int ret;
ret = m5mols_read_u8(sd, SYSTEM_INT_FACTOR, &dummy);
if (!ret)
ret = m5mols_write(sd, SYSTEM_INT_ENABLE, reg & ~mask);
return ret;
}
int m5mols_wait_interrupt(struct v4l2_subdev *sd, u8 irq_mask, u32 timeout)
{
struct m5mols_info *info = to_m5mols(sd);
int ret = wait_event_interruptible_timeout(info->irq_waitq,
atomic_add_unless(&info->irq_done, -1, 0),
msecs_to_jiffies(timeout));
if (ret <= 0)
return ret ? ret : -ETIMEDOUT;
return m5mols_busy_wait(sd, SYSTEM_INT_FACTOR, irq_mask,
M5MOLS_I2C_RDY_WAIT_FL | irq_mask, -1);
}
static int m5mols_reg_mode(struct v4l2_subdev *sd, u8 mode)
{
int ret = m5mols_write(sd, SYSTEM_SYSMODE, mode);
if (ret < 0)
return ret;
return m5mols_busy_wait(sd, SYSTEM_SYSMODE, mode, 0xff,
M5MOLS_MODE_CHANGE_TIMEOUT);
}
int m5mols_set_mode(struct m5mols_info *info, u8 mode)
{
struct v4l2_subdev *sd = &info->sd;
int ret = -EINVAL;
u8 reg;
if (mode < REG_PARAMETER || mode > REG_CAPTURE)
return ret;
ret = m5mols_read_u8(sd, SYSTEM_SYSMODE, &reg);
if (ret || reg == mode)
return ret;
switch (reg) {
case REG_PARAMETER:
ret = m5mols_reg_mode(sd, REG_MONITOR);
if (mode == REG_MONITOR)
break;
if (!ret)
ret = m5mols_reg_mode(sd, REG_CAPTURE);
break;
case REG_MONITOR:
if (mode == REG_PARAMETER) {
ret = m5mols_reg_mode(sd, REG_PARAMETER);
break;
}
ret = m5mols_reg_mode(sd, REG_CAPTURE);
break;
case REG_CAPTURE:
ret = m5mols_reg_mode(sd, REG_MONITOR);
if (mode == REG_MONITOR)
break;
if (!ret)
ret = m5mols_reg_mode(sd, REG_PARAMETER);
break;
default:
v4l2_warn(sd, "Wrong mode: %d\n", mode);
}
if (!ret)
info->mode = mode;
return ret;
}
static int m5mols_get_version(struct v4l2_subdev *sd)
{
struct m5mols_info *info = to_m5mols(sd);
struct m5mols_version *ver = &info->ver;
u8 *str = ver->str;
int i;
int ret;
ret = m5mols_read_u8(sd, SYSTEM_VER_CUSTOMER, &ver->customer);
if (!ret)
ret = m5mols_read_u8(sd, SYSTEM_VER_PROJECT, &ver->project);
if (!ret)
ret = m5mols_read_u16(sd, SYSTEM_VER_FIRMWARE, &ver->fw);
if (!ret)
ret = m5mols_read_u16(sd, SYSTEM_VER_HARDWARE, &ver->hw);
if (!ret)
ret = m5mols_read_u16(sd, SYSTEM_VER_PARAMETER, &ver->param);
if (!ret)
ret = m5mols_read_u16(sd, SYSTEM_VER_AWB, &ver->awb);
if (!ret)
ret = m5mols_read_u8(sd, AF_VERSION, &ver->af);
if (ret)
return ret;
for (i = 0; i < VERSION_STRING_SIZE; i++) {
ret = m5mols_read_u8(sd, SYSTEM_VER_STRING, &str[i]);
if (ret)
return ret;
}
ver->fw = be16_to_cpu(ver->fw);
ver->hw = be16_to_cpu(ver->hw);
ver->param = be16_to_cpu(ver->param);
ver->awb = be16_to_cpu(ver->awb);
v4l2_info(sd, "Manufacturer\t[%s]\n",
is_manufacturer(info, REG_SAMSUNG_ELECTRO) ?
"Samsung Electro-Machanics" :
is_manufacturer(info, REG_SAMSUNG_OPTICS) ?
"Samsung Fiber-Optics" :
is_manufacturer(info, REG_SAMSUNG_TECHWIN) ?
"Samsung Techwin" : "None");
v4l2_info(sd, "Customer/Project\t[0x%02x/0x%02x]\n",
info->ver.customer, info->ver.project);
if (!is_available_af(info))
v4l2_info(sd, "No support Auto Focus on this firmware\n");
return ret;
}
static enum m5mols_restype __find_restype(enum v4l2_mbus_pixelcode code)
{
enum m5mols_restype type = M5MOLS_RESTYPE_MONITOR;
do {
if (code == m5mols_default_ffmt[type].code)
return type;
} while (type++ != SIZE_DEFAULT_FFMT);
return 0;
}
static int __find_resolution(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf,
enum m5mols_restype *type,
u32 *resolution)
{
const struct m5mols_resolution *fsize = &m5mols_reg_res[0];
const struct m5mols_resolution *match = NULL;
enum m5mols_restype stype = __find_restype(mf->code);
int i = ARRAY_SIZE(m5mols_reg_res);
unsigned int min_err = ~0;
while (i--) {
int err;
if (stype == fsize->type) {
err = abs(fsize->width - mf->width)
+ abs(fsize->height - mf->height);
if (err < min_err) {
min_err = err;
match = fsize;
}
}
fsize++;
}
if (match) {
mf->width = match->width;
mf->height = match->height;
*resolution = match->reg;
*type = stype;
return 0;
}
return -EINVAL;
}
static struct v4l2_mbus_framefmt *__find_format(struct m5mols_info *info,
struct v4l2_subdev_fh *fh,
enum v4l2_subdev_format_whence which,
enum m5mols_restype type)
{
if (which == V4L2_SUBDEV_FORMAT_TRY)
return fh ? v4l2_subdev_get_try_format(fh, 0) : NULL;
return &info->ffmt[type];
}
static int m5mols_get_fmt(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct m5mols_info *info = to_m5mols(sd);
struct v4l2_mbus_framefmt *format;
int ret = 0;
mutex_lock(&info->lock);
format = __find_format(info, fh, fmt->which, info->res_type);
if (format)
fmt->format = *format;
else
ret = -EINVAL;
mutex_unlock(&info->lock);
return ret;
}
static int m5mols_set_fmt(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh,
struct v4l2_subdev_format *fmt)
{
struct m5mols_info *info = to_m5mols(sd);
struct v4l2_mbus_framefmt *format = &fmt->format;
struct v4l2_mbus_framefmt *sfmt;
enum m5mols_restype type;
u32 resolution = 0;
int ret;
ret = __find_resolution(sd, format, &type, &resolution);
if (ret < 0)
return ret;
sfmt = __find_format(info, fh, fmt->which, type);
if (!sfmt)
return 0;
mutex_lock(&info->lock);
format->code = m5mols_default_ffmt[type].code;
format->colorspace = V4L2_COLORSPACE_JPEG;
format->field = V4L2_FIELD_NONE;
if (fmt->which == V4L2_SUBDEV_FORMAT_ACTIVE) {
*sfmt = *format;
info->resolution = resolution;
info->res_type = type;
}
mutex_unlock(&info->lock);
return ret;
}
static int m5mols_get_frame_desc(struct v4l2_subdev *sd, unsigned int pad,
struct v4l2_mbus_frame_desc *fd)
{
struct m5mols_info *info = to_m5mols(sd);
if (pad != 0 || fd == NULL)
return -EINVAL;
mutex_lock(&info->lock);
fd->entry[0].length = info->cap.buf_size;
fd->entry[0].pixelcode = info->ffmt[M5MOLS_RESTYPE_CAPTURE].code;
mutex_unlock(&info->lock);
fd->entry[0].flags = V4L2_MBUS_FRAME_DESC_FL_LEN_MAX;
fd->num_entries = 1;
return 0;
}
static int m5mols_set_frame_desc(struct v4l2_subdev *sd, unsigned int pad,
struct v4l2_mbus_frame_desc *fd)
{
struct m5mols_info *info = to_m5mols(sd);
struct v4l2_mbus_framefmt *mf = &info->ffmt[M5MOLS_RESTYPE_CAPTURE];
if (pad != 0 || fd == NULL)
return -EINVAL;
fd->entry[0].flags = V4L2_MBUS_FRAME_DESC_FL_LEN_MAX;
fd->num_entries = 1;
fd->entry[0].length = clamp_t(u32, fd->entry[0].length,
mf->width * mf->height,
M5MOLS_MAIN_JPEG_SIZE_MAX);
mutex_lock(&info->lock);
info->cap.buf_size = fd->entry[0].length;
mutex_unlock(&info->lock);
return 0;
}
static int m5mols_enum_mbus_code(struct v4l2_subdev *sd,
struct v4l2_subdev_fh *fh,
struct v4l2_subdev_mbus_code_enum *code)
{
if (!code || code->index >= SIZE_DEFAULT_FFMT)
return -EINVAL;
code->code = m5mols_default_ffmt[code->index].code;
return 0;
}
int m5mols_restore_controls(struct m5mols_info *info)
{
int ret;
if (info->ctrl_sync)
return 0;
ret = m5mols_do_scenemode(info, REG_SCENE_NORMAL);
if (ret)
return ret;
ret = v4l2_ctrl_handler_setup(&info->handle);
info->ctrl_sync = !ret;
return ret;
}
static int m5mols_start_monitor(struct m5mols_info *info)
{
struct v4l2_subdev *sd = &info->sd;
int ret;
ret = m5mols_set_mode(info, REG_PARAMETER);
if (!ret)
ret = m5mols_write(sd, PARM_MON_SIZE, info->resolution);
if (!ret)
ret = m5mols_write(sd, PARM_MON_FPS, REG_FPS_30);
if (!ret)
ret = m5mols_set_mode(info, REG_MONITOR);
if (!ret)
ret = m5mols_restore_controls(info);
return ret;
}
static int m5mols_s_stream(struct v4l2_subdev *sd, int enable)
{
struct m5mols_info *info = to_m5mols(sd);
u32 code;
int ret;
mutex_lock(&info->lock);
code = info->ffmt[info->res_type].code;
if (enable) {
if (is_code(code, M5MOLS_RESTYPE_MONITOR))
ret = m5mols_start_monitor(info);
else if (is_code(code, M5MOLS_RESTYPE_CAPTURE))
ret = m5mols_start_capture(info);
else
ret = -EINVAL;
} else {
ret = m5mols_set_mode(info, REG_PARAMETER);
}
mutex_unlock(&info->lock);
return ret;
}
static int m5mols_sensor_power(struct m5mols_info *info, bool enable)
{
struct v4l2_subdev *sd = &info->sd;
struct i2c_client *client = v4l2_get_subdevdata(sd);
const struct m5mols_platform_data *pdata = info->pdata;
int ret;
if (info->power == enable)
return 0;
if (enable) {
if (info->set_power) {
ret = info->set_power(&client->dev, 1);
if (ret)
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(supplies), supplies);
if (ret) {
info->set_power(&client->dev, 0);
return ret;
}
gpio_set_value(pdata->gpio_reset, !pdata->reset_polarity);
info->power = 1;
return ret;
}
ret = regulator_bulk_disable(ARRAY_SIZE(supplies), supplies);
if (ret)
return ret;
if (info->set_power)
info->set_power(&client->dev, 0);
gpio_set_value(pdata->gpio_reset, pdata->reset_polarity);
info->isp_ready = 0;
info->power = 0;
return ret;
}
static int m5mols_fw_start(struct v4l2_subdev *sd)
{
struct m5mols_info *info = to_m5mols(sd);
int ret;
atomic_set(&info->irq_done, 0);
ret = m5mols_busy_wait(sd, FLASH_CAM_START, REG_IN_FLASH_MODE,
M5MOLS_I2C_RDY_WAIT_FL | 0xff, -1);
if (!ret)
ret = m5mols_write(sd, FLASH_CAM_START, REG_START_ARM_BOOT);
if (!ret)
ret = m5mols_wait_interrupt(sd, REG_INT_MODE, 2000);
if (ret < 0)
return ret;
info->isp_ready = 1;
ret = m5mols_get_version(sd);
if (!ret)
ret = m5mols_update_fw(sd, m5mols_sensor_power);
if (ret)
return ret;
v4l2_dbg(1, m5mols_debug, sd, "Success ARM Booting\n");
ret = m5mols_write(sd, PARM_INTERFACE, REG_INTERFACE_MIPI);
if (!ret)
ret = m5mols_enable_interrupt(sd,
REG_INT_AF | REG_INT_CAPTURE);
return ret;
}
static int m5mols_auto_focus_stop(struct m5mols_info *info)
{
int ret;
ret = m5mols_write(&info->sd, AF_EXECUTE, REG_AF_STOP);
if (!ret)
ret = m5mols_write(&info->sd, AF_MODE, REG_AF_POWEROFF);
if (!ret)
ret = m5mols_busy_wait(&info->sd, SYSTEM_STATUS, REG_AF_IDLE,
0xff, -1);
return ret;
}
static int m5mols_s_power(struct v4l2_subdev *sd, int on)
{
struct m5mols_info *info = to_m5mols(sd);
int ret;
mutex_lock(&info->lock);
if (on) {
ret = m5mols_sensor_power(info, true);
if (!ret)
ret = m5mols_fw_start(sd);
} else {
if (is_manufacturer(info, REG_SAMSUNG_TECHWIN)) {
ret = m5mols_set_mode(info, REG_MONITOR);
if (!ret)
ret = m5mols_auto_focus_stop(info);
if (ret < 0)
v4l2_warn(sd, "Soft landing lens failed\n");
}
ret = m5mols_sensor_power(info, false);
info->ctrl_sync = 0;
}
mutex_unlock(&info->lock);
return ret;
}
static int m5mols_log_status(struct v4l2_subdev *sd)
{
struct m5mols_info *info = to_m5mols(sd);
v4l2_ctrl_handler_log_status(&info->handle, sd->name);
return 0;
}
static int m5mols_open(struct v4l2_subdev *sd, struct v4l2_subdev_fh *fh)
{
struct v4l2_mbus_framefmt *format = v4l2_subdev_get_try_format(fh, 0);
*format = m5mols_default_ffmt[0];
return 0;
}
static irqreturn_t m5mols_irq_handler(int irq, void *data)
{
struct m5mols_info *info = to_m5mols(data);
atomic_set(&info->irq_done, 1);
wake_up_interruptible(&info->irq_waitq);
return IRQ_HANDLED;
}
static int m5mols_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct m5mols_platform_data *pdata = client->dev.platform_data;
unsigned long gpio_flags;
struct m5mols_info *info;
struct v4l2_subdev *sd;
int ret;
if (pdata == NULL) {
dev_err(&client->dev, "No platform data\n");
return -EINVAL;
}
if (!gpio_is_valid(pdata->gpio_reset)) {
dev_err(&client->dev, "No valid RESET GPIO specified\n");
return -EINVAL;
}
if (!client->irq) {
dev_err(&client->dev, "Interrupt not assigned\n");
return -EINVAL;
}
info = devm_kzalloc(&client->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->pdata = pdata;
info->set_power = pdata->set_power;
gpio_flags = pdata->reset_polarity
? GPIOF_OUT_INIT_HIGH : GPIOF_OUT_INIT_LOW;
ret = devm_gpio_request_one(&client->dev, pdata->gpio_reset, gpio_flags,
"M5MOLS_NRST");
if (ret) {
dev_err(&client->dev, "Failed to request gpio: %d\n", ret);
return ret;
}
ret = devm_regulator_bulk_get(&client->dev, ARRAY_SIZE(supplies),
supplies);
if (ret) {
dev_err(&client->dev, "Failed to get regulators: %d\n", ret);
return ret;
}
sd = &info->sd;
v4l2_i2c_subdev_init(sd, client, &m5mols_ops);
strlcpy(sd->name, MODULE_NAME, sizeof(sd->name));
sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
sd->internal_ops = &m5mols_subdev_internal_ops;
info->pad.flags = MEDIA_PAD_FL_SOURCE;
ret = media_entity_init(&sd->entity, 1, &info->pad, 0);
if (ret < 0)
return ret;
sd->entity.type = MEDIA_ENT_T_V4L2_SUBDEV_SENSOR;
init_waitqueue_head(&info->irq_waitq);
mutex_init(&info->lock);
ret = devm_request_irq(&client->dev, client->irq, m5mols_irq_handler,
IRQF_TRIGGER_RISING, MODULE_NAME, sd);
if (ret) {
dev_err(&client->dev, "Interrupt request failed: %d\n", ret);
goto error;
}
info->res_type = M5MOLS_RESTYPE_MONITOR;
info->ffmt[0] = m5mols_default_ffmt[0];
info->ffmt[1] = m5mols_default_ffmt[1];
ret = m5mols_sensor_power(info, true);
if (ret)
goto error;
ret = m5mols_fw_start(sd);
if (!ret)
ret = m5mols_init_controls(sd);
ret = m5mols_sensor_power(info, false);
if (!ret)
return 0;
error:
media_entity_cleanup(&sd->entity);
return ret;
}
static int m5mols_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
v4l2_device_unregister_subdev(sd);
v4l2_ctrl_handler_free(sd->ctrl_handler);
media_entity_cleanup(&sd->entity);
return 0;
}
